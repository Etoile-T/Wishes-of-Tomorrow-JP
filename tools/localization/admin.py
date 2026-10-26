#!/usr/bin/env python3
"""Loopback-only translation workbench. Drafts are separate from game sources."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import secrets
import sqlite3
import subprocess
import threading
import time
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, urlparse

import catalog
import dialogue_tools
import script_batch
import update_catalog

ROOT = Path(__file__).resolve().parents[2]
UI = Path(__file__).with_name('admin_ui')
GROUPS = ['会話・看板', 'ポケモン', '図鑑', '技', '特性', '道具', '戦闘', 'ポケモンUI', 'メニュー・設定UI', 'クエスト', '人名・地名', 'その他UI・要分類']


def group(row):
    """Mirror the categorized workbook's file/field rules."""
    f, target = row['file'], row.get('target', '')
    if '/pokemon/species_info/' in f:
        return '図鑑' if row.get('_field') in ('description', 'categoryName') else 'ポケモン'
    if f == 'src/data/moves_info.h': return '技'
    if f == 'src/data/abilities.h': return '特性'
    if f in ('src/data/items.h', 'src/item_menu.c', 'src/item_use.c'): return '道具'
    if f == 'src/data/types_info.h': return 'ポケモン'
    if f in ('src/option_menu.c', 'src/wot_randomizer_menu.c'): return 'メニュー・設定UI'
    if f in ('src/pokemon_storage_system.c', 'src/naming_screen.c', 'src/party_menu.c', 'src/data/party_menu.h', 'src/pokemon_summary_screen.c'): return 'ポケモンUI'
    if 'pokedex' in f: return '図鑑'
    if f == 'src/data/speaker_names.h': return '人名・地名'
    if f == 'src/battle_message.c': return '戦闘'
    if f.startswith(('data/maps/', 'data/scripts/')) or (f.startswith('data/text/') and f != 'data/text/save.inc'): return '会話・看板'
    if f in ('src/main_menu.c', 'src/main_menu_bw.c', 'src/start_menu.c', 'src/data/script_menu.h') or target.startswith('gText_Menu'): return 'メニュー・設定UI'
    if f in ('src/quest_toast.c', 'src/quests.c'): return 'クエスト'
    if target.startswith('gText_QuestLoc_'): return '人名・地名'
    if 'Quest' in target: return 'クエスト'
    if f.startswith('src/battle_'): return '戦闘'
    return 'その他UI・要分類'


def digest(data):
    return hashlib.sha256(data).hexdigest()


class Workbench:
    def __init__(self, root=ROOT, storage=None):
        self.root = Path(root).resolve()
        self.storage = Path(storage or self.root.parent / 'artifacts/translation-admin').resolve()
        self.storage.mkdir(parents=True, exist_ok=True)
        self.lock = threading.RLock()
        self.db = sqlite3.connect(self.storage / 'drafts.sqlite3', check_same_thread=False)
        self.db.row_factory = sqlite3.Row
        self.db.execute('CREATE TABLE IF NOT EXISTS drafts (id TEXT PRIMARY KEY, translation TEXT NOT NULL, note TEXT NOT NULL, review TEXT NOT NULL, base TEXT NOT NULL, updated TEXT NOT NULL)')
        self.db.commit()
        self.reload()

    def reload(self):
        with self.lock:
            self.catalog_path = self.root / 'localization/catalog.json'
            raw = self.catalog_path.read_bytes()
            self.catalog_hash = digest(raw)
            self.rows = json.loads(raw)
            self.by_id = {r['id']: r for r in self.rows}
            self.groups = script_batch.messages([r for r in self.rows if r['kind'] == 'script'])
            self.cmap = set(re.findall(r"^'(.)'\s*=", (self.root / 'charmap.txt').read_text(), re.M)) | {'"', "'", '\\'}
            self.meta = {}
            snapshots = {}
            for r in self.rows:
                parts = r['file'].split('/')
                field = re.search(r'(?:^|\.)(speciesName|categoryName|description)(?:\.|\[|$)', r.get('target', ''))
                field = field[1] if field else ''
                if '/pokemon/species_info/' in r['file'] and not field:
                    if r['file'] not in snapshots:
                        proc = subprocess.run(['git', 'show', '23be896714:'+r['file']], cwd=self.root, capture_output=True, text=True)
                        snapshots[r['file']] = proc.stdout if proc.returncode == 0 else ''
                    prefix = snapshots[r['file']][max(0, r['start']-180):r['start']]
                    found = re.search(r'\.(speciesName|categoryName|description)\s*=\s*(?:_|COMPOUND_STRING)\(\s*$', prefix)
                    if found: field = found[1]
                    elif re.search(r'\b\w*Description\w*\s*\[\s*\]\s*=\s*(?:_|COMPOUND_STRING)\(\s*$', prefix): field = 'description'
                self.meta[r['id']] = dict(category=group({**r, '_field':field}), map=parts[2] if r['file'].startswith('data/maps/') else '', search=(' '.join([r['id'], r['file'], r['source'], r['translation'], r.get('target', '')])).casefold())

    def base(self, row):
        return digest(json.dumps(row, ensure_ascii=False, sort_keys=True).encode())

    def drafts(self):
        return {r['id']: dict(r) for r in self.db.execute('SELECT * FROM drafts')}

    def summary(self):
        with self.lock:
            drafts = self.drafts()
            cats = {g: dict(total=0, translated=0, pending=0) for g in GROUPS}
            for r in self.rows:
                c = cats[self.meta[r['id']]['category']]
                c['total'] += 1
                c[r['status']] += 1
            return dict(total=len(self.rows), translated=sum(r['status'] == 'translated' for r in self.rows), pending=sum(r['status'] == 'pending' for r in self.rows), drafts=len(drafts), reviewed=sum(d['review'] == 'reviewed' for d in drafts.values()), categories=cats, maps=sorted({m['map'] for m in self.meta.values() if m['map']}), storage=str(self.storage))

    def entries(self, query):
        with self.lock:
            drafts = self.drafts()
            q = query.get('q', '').casefold()
            category, status, map_name = (query.get(k, '') for k in ('category', 'status', 'map'))
            result = []
            for row in self.rows:
                key = row['id']; meta = self.meta[key]; d = drafts.get(key)
                if category and meta['category'] != category: continue
                if map_name and meta['map'] != map_name: continue
                if status in ('pending', 'translated') and row['status'] != status: continue
                if status == 'draft' and not d: continue
                if status == 'reviewed' and (not d or d['review'] != 'reviewed'): continue
                if q and q not in meta['search'] and (not d or q not in (d['translation'] + d['note']).casefold()): continue
                result.append(dict(id=key, file=row['file'], line=row['line'], source=row['source'], translation=row['translation'], status=row['status'], category=meta['category'], draft=d))
            page = max(1, int(query.get('page', 1))); size = 60
            return dict(total=len(result), page=page, pages=max(1, (len(result)+size-1)//size), rows=result[(page-1)*size:page*size])

    def entry(self, key):
        with self.lock:
            row = self.by_id[key]
            ids = self.groups.get(key, [key])
            drafts = self.drafts()
            return dict(row=row, meta=self.meta[key], base=self.base(row), draft=drafts.get(key), message=[dict(row=self.by_id[k], draft=drafts.get(k)) for k in ids])

    def save(self, data):
        with self.lock:
            row = self.by_id[data['id']]
            if data.get('base') != self.base(row): raise ValueError('元データが更新されています。再読み込みしてください。')
            if data.get('review') not in ('draft', 'reviewed'): raise ValueError('不正なレビュー状態')
            for k in ('translation', 'note'):
                if not isinstance(data.get(k), str) or len(data[k]) > 20000: raise ValueError('訳稿・メモは各20,000文字以内です。')
            self.db.execute('INSERT OR REPLACE INTO drafts VALUES (?,?,?,?,?,?)', (row['id'], data['translation'], data['note'], data['review'], data['base'], time.strftime('%Y-%m-%d %H:%M:%S')))
            self.db.commit()
            return dict(saved=True)

    def delete(self, key):
        with self.lock:
            self.db.execute('DELETE FROM drafts WHERE id=?', (key,)); self.db.commit()
            return dict(deleted=True)

    def batch(self, ids):
        if not isinstance(ids, list) or not ids or len(ids) > 500 or len(ids) != len(set(ids)): raise ValueError('1〜500件の異なるIDを選択してください。')
        drafts = self.drafts(); batch = []
        for key in ids:
            row = self.by_id[key]; d = drafts.get(key)
            if not d or not d['translation']: raise ValueError(key + ': 保存された訳稿がありません。')
            if d['base'] != self.base(row): raise ValueError(key + ': 元データと訳稿が競合しています。')
            batch.append(dict(id=key, translation=d['translation']))
        return batch

    def validate(self, ids):
        """General export checks plus stricter, pending-script-only apply checks."""
        with self.lock:
            if digest(self.catalog_path.read_bytes()) != self.catalog_hash: raise ValueError('カタログが外部で更新されています。「元データを再読み込み」を押してください。')
            batch = self.batch(ids); drafts = self.drafts(); errors = []; apply_errors = []
            for item in batch:
                row = self.by_id[item['id']]
                try: catalog.validate({**row, **item}, self.cmap)
                except ValueError as exc: errors.append(f"{row['id']}: {exc}")
                if drafts[row['id']]['review'] != 'reviewed': apply_errors.append(row['id'] + ': レビュー済みにしてください。')
                if row['kind'] != 'script' or not row['file'].startswith(('data/maps/', 'data/text/')):
                    apply_errors.append(row['id'] + ': この種類はJSON出力後、既存の個別UI・固定長検査の手順で反映してください。')
                if row['status'] != 'pending': apply_errors.append(row['id'] + ': 既存翻訳の変更はJSON出力して確認してください。')
            wanted = {i['id']: i['translation'] for i in batch}; seen = set()
            for key in ids:
                row = self.by_id[key]
                members = self.groups.get(key, [key])
                if members[0] in seen: continue
                seen.add(members[0])
                missing = [k for k in members if k not in wanted]
                if row['kind'] == 'script' and missing:
                    apply_errors.append(f'{key}: 同じメッセージの全行が必要です（未選択 {len(missing)}行）。')
                    continue
                text = ''.join(wanted.get(k, self.by_id[k]['translation']) for k in members)
                # Inherit language mode across consecutive script rows.
                mode = False
                for tok in re.findall(r'\{[^}]*\}|\\.|.', text):
                    if tok == '{JPN}': mode = True
                    elif tok == '{ENG}': mode = False
                    elif script_batch.VARIABLE.fullmatch(tok):
                        if mode: apply_errors.append(key + ': 名前変数は{ENG}と{JPN}で囲んでください。')
                    elif tok.startswith('{'): continue
                    elif re.search(r'[ぁ-ヿ一-鿿]', tok) and not mode:
                        errors.append(key + ': 日本語の前に{JPN}が必要です。'); break
                try:
                    catalog.validate(dict(id=key, source=''.join(self.by_id[k]['source'] for k in members), translation=text), self.cmap)
                except ValueError as exc:
                    errors.append(str(exc))
                if row['kind'] == 'script':
                    if not text.endswith('$'): apply_errors.append(key + ': メッセージ終端が確認できません。')
                    if mode: apply_errors.append(key + ': 終端前の{ENG}が必要です。')
                    for segment in re.split(r'\\[npl]|\$', text):
                        if dialogue_tools.cells(segment) > 26: apply_errors.append(key + ': 26マスを超える表示行があります。')
                    source = (self.root / row['file']).read_text()
                    if re.search(r'^\s*#\s*(if|else|elif)', source, re.M):
                        apply_errors.append(key + ': 条件分岐を含むファイルは既存のscript_batch手順で確認してください。')
                    if re.search(r'^\s*\.braille', source, re.M):
                        apply_errors.append(key + ': 点字を含むファイルは個別に確認してください。')
            outputs = {}; result = None
            if not errors:
                try: result, outputs = update_catalog.plan(self.rows, batch, self.cmap)
                except ValueError as exc: errors.append(str(exc))
            fingerprint = digest(json.dumps(dict(batch=batch, catalog=self.catalog_hash, sources={str(p): digest(p.read_bytes()) for p in outputs}, reviews={k: drafts[k]['review'] for k in ids}), sort_keys=True).encode())
            errors = list(dict.fromkeys(errors))
            return dict(valid=not errors, applicable=not errors and not apply_errors, errors=errors, apply_errors=list(dict.fromkeys(apply_errors)), fingerprint=fingerprint, count=len(batch), files=len(outputs), note='静的検査です。意味・口調のレビュー、yomiyasu、ビルド、実画面確認は別途必要です。'), result, outputs

    def apply(self, ids, fingerprint):
        with self.lock:
            report, result, outputs = self.validate(ids)
            if not report['applicable'] or report['fingerprint'] != fingerprint: raise ValueError('検査結果が古いか、反映条件を満たしていません。再検査してください。')
            batch = self.batch(ids)
            status_path = self.root / 'localization/status.json'
            status = json.loads(status_path.read_text())
            count = sum(r['status'] == 'translated' for r in result)
            status.update(total_candidates=len(result), translated=count, pending=len(result)-count, jp_build='stale: local admin edited source; rebuild required', work_state='local_admin_source_changed', admin_last_apply=time.strftime('%Y-%m-%d %H:%M:%S'), admin_checks='static checks only; yomiyasu/build/runtime not run for this batch', excel_refresh_required=True)
            outputs[self.catalog_path] = json.dumps(result, ensure_ascii=False, indent=2)+'\n'
            outputs[status_path] = json.dumps(status, ensure_ascii=False, indent=2)+'\n'
            original = {p: p.read_bytes() for p in outputs}
            checkpoint = self.storage / 'backups' / (time.strftime('%Y%m%d-%H%M%S')+'-'+secrets.token_hex(3))
            checkpoint.mkdir(parents=True)
            for p, raw in original.items():
                dest = checkpoint / p.relative_to(self.root)
                dest.parent.mkdir(parents=True, exist_ok=True); dest.write_bytes(raw)
            (checkpoint / 'batch.json').write_text(json.dumps(batch, ensure_ascii=False, indent=2)+'\n')
            changed = []
            try:
                for p, value in outputs.items():
                    self.atomic(p, value.encode()); changed.append(p)
                self.db.executemany('DELETE FROM drafts WHERE id=?', [(k,) for k in ids]); self.db.commit()
            except Exception:
                self.db.rollback()
                for p in reversed(changed): self.atomic(p, original[p])
                raise
            self.reload()
            return dict(applied=len(ids), backup=str(checkpoint), message='ソースへ反映しました。ROM・Excelは未更新です。yomiyasuレビューと既存のビルド手順へ進んでください。')

    @staticmethod
    def atomic(path, raw):
        tmp = path.with_name(path.name + '.admin-tmp')
        try:
            tmp.write_bytes(raw); os.replace(tmp, path)
        finally:
            tmp.unlink(missing_ok=True)


class Handler(BaseHTTPRequestHandler):
    def log_message(self, fmt, *args):
        pass

    def send(self, value, code=200):
        raw = json.dumps(value, ensure_ascii=False).encode()
        self.send_response(code); self.send_header('Content-Type', 'application/json; charset=utf-8')
        self.send_header('Content-Length', str(len(raw))); self.send_header('Cache-Control', 'no-store'); self.end_headers(); self.wfile.write(raw)

    def do_GET(self):
        try:
            if self.headers.get('Host') != self.server.authority:
                return self.send(dict(error='Invalid Host'), 403)
            url = urlparse(self.path); path = url.path; app = self.server.app
            if path == '/api/summary': return self.send({**app.summary(), 'token': self.server.token})
            if path == '/api/entries': return self.send(app.entries({k: v[0] for k, v in parse_qs(url.query).items()}))
            if path.startswith('/api/entry/'): return self.send(app.entry(path.rsplit('/', 1)[-1]))
            if path == '/api/terms': return self.send(json.loads((app.root / 'localization/glossary.json').read_text()))
            files = {'/': 'index.html', '/app.js': 'app.js', '/style.css': 'style.css'}
            if path not in files: return self.send(dict(error='Not found'), 404)
            filename = files[path]; raw = (UI / filename).read_bytes()
            self.send_response(200); self.send_header('Content-Type', {'index.html':'text/html; charset=utf-8','app.js':'text/javascript; charset=utf-8','style.css':'text/css; charset=utf-8'}[filename])
            self.send_header('Content-Length', str(len(raw))); self.send_header('Cache-Control', 'no-store'); self.send_header('X-Content-Type-Options', 'nosniff')
            self.send_header('Content-Security-Policy', "default-src 'self'; style-src 'self'; script-src 'self'; connect-src 'self'; frame-ancestors 'none'")
            self.end_headers(); self.wfile.write(raw)
        except (ValueError, KeyError) as exc: self.send(dict(error=str(exc)), 400)
        except Exception as exc: self.send(dict(error='処理に失敗しました: '+str(exc)), 500)

    def do_POST(self):
        if self.headers.get('Host') != self.server.authority or self.headers.get('Origin') not in (None, 'http://'+self.server.authority) or not secrets.compare_digest(self.headers.get('X-Workbench-Token', ''), self.server.token):
            return self.send(dict(error='この管理画面から操作してください。'), 403)
        try:
            length = int(self.headers.get('Content-Length', '0'))
            if length <= 0 or length > 2000000: raise ValueError('Request too large or empty')
            data = json.loads(self.rfile.read(length)); app = self.server.app
            with app.lock:
                if self.path == '/api/draft': result = app.save(data)
                elif self.path == '/api/delete': result = app.delete(data['id'])
                elif self.path == '/api/validate': result = app.validate(data['ids'])[0]
                elif self.path == '/api/export': result = dict(batch=app.batch(data['ids']))
                elif self.path == '/api/apply': result = app.apply(data['ids'], data['fingerprint'])
                elif self.path == '/api/reload': app.reload(); result = dict(reloaded=True)
                else: return self.send(dict(error='Not found'), 404)
            self.send(result)
        except (ValueError, KeyError, TypeError) as exc: self.send(dict(error=str(exc)), 400)
        except Exception as exc: self.send(dict(error='処理に失敗しました: '+str(exc)), 500)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--port', type=int, default=8766)
    parser.add_argument('--storage', type=Path)
    args = parser.parse_args()
    app = Workbench(storage=args.storage)
    server = ThreadingHTTPServer(('127.0.0.1', args.port), Handler)
    server.app = app; server.token = secrets.token_urlsafe(32)
    server.authority = f'127.0.0.1:{server.server_port}'
    print(f'翻訳管理画面: http://{server.authority}\n訳稿保存: {app.storage}', flush=True)
    try: server.serve_forever()
    except KeyboardInterrupt: pass
    finally: server.server_close(); app.db.close()

if __name__ == '__main__': main()
