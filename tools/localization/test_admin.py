"""Source mutation tests use a disposable miniature checkout, never the live ROM."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import admin
import catalog


class WorkbenchTest(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = Path(self.tmp.name) / 'repo'
        (self.root / 'localization').mkdir(parents=True)
        (self.root / 'data/maps/Test').mkdir(parents=True)
        self.file = self.root / 'data/maps/Test/scripts.inc'
        self.file.write_text('Text::\n    .string "Hello.\\n"\n    .string "Bye.$"\n')
        (self.root / 'charmap.txt').write_bytes((admin.ROOT / 'charmap.txt').read_bytes())
        self.root_patch = patch.object(catalog, 'ROOT', self.root)
        self.root_patch.start()
        rows = catalog.extract()
        (self.root / 'localization/catalog.json').write_text(json.dumps(rows))
        (self.root / 'localization/status.json').write_text(json.dumps(dict(total_candidates=2, translated=0, pending=2, user_output_rom='keep.gba')))
        self.app = admin.Workbench(self.root, Path(self.tmp.name) / 'drafts')
        self.keys = [r['id'] for r in self.app.rows]

    def tearDown(self):
        self.app.db.close(); self.root_patch.stop(); self.tmp.cleanup()

    def draft(self, index, text, review='reviewed'):
        row = self.app.by_id[self.keys[index]]
        self.app.save(dict(id=row['id'], base=self.app.base(row), translation=text, note='テスト', review=review))

    def ready(self):
        self.draft(0, '{JPN}こんにちは。\\n')
        self.draft(1, 'さようなら。{ENG}$')

    def test_counts_and_search(self):
        self.assertEqual(self.app.summary()['pending'], 2)
        self.assertEqual(self.app.entries(dict(q='bye'))['total'], 1)
        self.assertEqual(self.app.entry(self.keys[0])['message'][1]['row']['id'], self.keys[1])

    def test_draft_is_not_source_apply(self):
        before = self.file.read_bytes(); cat = self.app.catalog_path.read_bytes()
        self.ready()
        self.assertEqual(self.file.read_bytes(), before)
        self.assertEqual(self.app.catalog_path.read_bytes(), cat)
        self.assertEqual(self.app.summary()['drafts'], 2)

    def test_partial_message_blocked(self):
        self.ready()
        report = self.app.validate([self.keys[0]])[0]
        self.assertFalse(report['applicable'])
        self.assertTrue(any('全行' in x for x in report['apply_errors']))

    def test_bad_control_blocked(self):
        self.ready(); self.draft(1, 'さようなら。{PLAYER}{ENG}$')
        self.assertFalse(self.app.validate(self.keys)[0]['valid'])

    def test_japanese_scope_blocked(self):
        self.ready(); self.draft(0, 'こんにちは。\\n')
        self.assertFalse(self.app.validate(self.keys)[0]['valid'])

    def test_inherited_punctuation_blocked(self):
        self.ready(); self.draft(1, "'さようなら。{ENG}$")
        self.assertFalse(self.app.validate(self.keys)[0]['valid'])

    def test_width_blocked(self):
        self.ready(); self.draft(1, 'あ'*27+'{ENG}$')
        self.assertFalse(self.app.validate(self.keys)[0]['applicable'])

    def test_unreviewed_blocked(self):
        self.ready(); self.draft(1, 'さようなら。{ENG}$', 'draft')
        self.assertFalse(self.app.validate(self.keys)[0]['applicable'])

    def test_dry_run_and_apply_backup(self):
        self.ready(); original = self.file.read_bytes()
        report, _, _ = self.app.validate(self.keys)
        self.assertTrue(report['applicable'], report)
        self.assertEqual(self.file.read_bytes(), original)
        result = self.app.apply(self.keys, report['fingerprint'])
        self.assertIn('こんにちは', self.file.read_text())
        self.assertEqual((Path(result['backup']) / self.file.relative_to(self.root)).read_bytes(), original)
        self.assertEqual(self.app.summary()['translated'], 2)
        self.assertEqual(self.app.summary()['drafts'], 0)
        status = json.loads((self.root / 'localization/status.json').read_text())
        self.assertEqual(status['user_output_rom'], 'keep.gba')
        self.assertIn('stale', status['jp_build'])

    def test_stale_fingerprint_blocked(self):
        self.ready(); report = self.app.validate(self.keys)[0]
        self.draft(1, 'またね。{ENG}$')
        with self.assertRaises(ValueError): self.app.apply(self.keys, report['fingerprint'])

    def test_stale_catalog_blocked(self):
        self.ready(); self.app.catalog_path.write_text('[]')
        with self.assertRaises(ValueError): self.app.validate(self.keys)

    def test_stale_source_blocked(self):
        self.ready(); self.file.write_text('changed')
        self.assertFalse(self.app.validate(self.keys)[0]['valid'])

    def test_write_failure_rolls_back(self):
        self.ready(); report = self.app.validate(self.keys)[0]
        paths = [self.file, self.app.catalog_path, self.root / 'localization/status.json']
        before = {p:p.read_bytes() for p in paths}
        atomic = self.app.atomic; count = 0
        def fail_once(path, raw):
            nonlocal count
            count += 1
            if count == 2: raise OSError('simulated write failure')
            atomic(path, raw)
        with patch.object(self.app, 'atomic', side_effect=fail_once):
            with self.assertRaises(OSError): self.app.apply(self.keys, report['fingerprint'])
        for p in paths: self.assertEqual(p.read_bytes(), before[p])
        self.assertEqual(self.app.summary()['drafts'], 2)

    def test_draft_survives_restart(self):
        self.ready(); self.app.db.close()
        self.app = admin.Workbench(self.root, Path(self.tmp.name) / 'drafts')
        self.assertEqual(self.app.summary()['drafts'], 2)

    def test_duplicate_unknown_and_unmapped(self):
        self.ready()
        with self.assertRaises(ValueError): self.app.batch([self.keys[0]]*2)
        with self.assertRaises(KeyError): self.app.batch(['unknown'])
        self.draft(1, '翻訳漢字{ENG}$')
        self.assertFalse(self.app.validate(self.keys)[0]['valid'])

    def test_http_routes_and_mutation_guards(self):
        import threading
        import urllib.request
        import urllib.error
        server = admin.ThreadingHTTPServer(('127.0.0.1', 0), admin.Handler)
        server.app = self.app; server.token = 'test-token'
        server.authority = '127.0.0.1:'+str(server.server_port)
        thread = threading.Thread(target=server.serve_forever, daemon=True); thread.start()
        base = 'http://'+server.authority
        def post(path, data, token='test-token', origin=None):
            headers = {'Content-Type':'application/json', 'X-Workbench-Token':token}
            if origin: headers['Origin'] = origin
            req = urllib.request.Request(base+path, json.dumps(data).encode(), headers)
            return urllib.request.urlopen(req)
        try:
            with urllib.request.urlopen(base+'/api/summary') as response:
                self.assertEqual(json.load(response)['pending'], 2)
            for token, origin in [('bad', None), ('test-token', 'https://foreign.example')]:
                with self.assertRaises(urllib.error.HTTPError) as error:
                    post('/api/reload', {}, token, origin)
                self.assertEqual(error.exception.code, 403)
            self.ready()
            with post('/api/export', {'ids':self.keys}) as response:
                self.assertEqual(len(json.load(response)['batch']), 2)
            with post('/api/validate', {'ids':self.keys}) as response:
                self.assertTrue(json.load(response)['applicable'])
            self.assertNotIn('こんにちは', self.file.read_text())
        finally:
            server.shutdown(); server.server_close(); thread.join()


if __name__ == '__main__': unittest.main()
