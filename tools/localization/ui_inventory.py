#!/usr/bin/env python3
"""Inventory likely UI strings. Counts are candidates, not active-screen coverage."""
import collections
import json
import re

import catalog

UI = re.compile(r'(menu|screen|pokedex|pokenav|storage|shop|quest|trainer_card|item_use|text_input|save|trade|berry|contest|frontier|battle_message|hall_of_fame|roulette|slot_machine|diploma|union_room|script_menu)')
RETAIN = {'HP', 'PP', 'IVs', 'EVs', 'A', 'B', 'C', 'D', 'F', 'S', 'LR', 'L=A', 'ATK', 'DEF', 'SP.A', 'SP.D', 'SPE', 'BP'}


def language_candidate(row):
    text = re.sub(r'\{[^{}]*\}|\\[npl]|\$', '', row['source']).strip()
    return bool(re.search(r'[A-Za-zぁ-ゖァ-ヺ一-龯]', text)) and text not in RETAIN


def main():
    rows = json.loads((catalog.ROOT/'localization/catalog.json').read_text())
    by_file = collections.defaultdict(list)
    for row in rows:
        if row['file'] == 'src/strings.c' or (row['file'].startswith('src/') and UI.search(row['file'])) or row['file'] == 'data/text/save.inc':
            by_file[row['file']].append(row)
    files = []
    for name, entries in sorted(by_file.items()):
        pending = [r for r in entries if r['status'] == 'pending' and language_candidate(r)]
        files.append(dict(file=name, translated=sum(r['status']=='translated' for r in entries),
                          pending_language_candidates=len(pending),
                          pending=[dict(id=r['id'], source=r['source'], line=r['line']) for r in pending]))
    report = dict(scope='Likely UI source files; includes unused text. Not a complete UI census.',
                  limitations=['Embedded images, bare C strings and dynamic concatenation require separate review.',
                               'Abbreviations and control-only strings excluded from language candidates.',
                               'No runtime screen coverage inferred from translation counts.'], files=files)
    (catalog.ROOT/'localization/ui-inventory.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
    lines = ['# UI翻訳の残件候補', '', '名称・説明データとは別の、UIを含む可能性があるファイルの一覧。未使用文言も含み、全画面の網羅や完成率を示すものではありません。画像内文字・裸C文字列・動的な文の組み立ては別途確認が必要です。', '',
             '| ファイル | 翻訳適用 | 未翻訳の言語候補 |', '| --- | ---: | ---: |']
    for f in files:
        lines.append(f"| {f['file']} | {f['translated']} | {f['pending_language_candidates']} |")
    (catalog.ROOT/'localization/UI_PROGRESS.md').write_text('\n'.join(lines)+'\n')
    print(json.dumps(dict(files=len(files), pending_language_candidates=sum(f['pending_language_candidates'] for f in files))))


if __name__ == '__main__':
    main()
