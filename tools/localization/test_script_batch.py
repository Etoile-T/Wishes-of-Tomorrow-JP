import importlib.util
import pathlib
import sys
import unittest
sys.path.insert(0, str(pathlib.Path(__file__).parent))
spec = importlib.util.spec_from_file_location('script_batch', pathlib.Path(__file__).with_name('script_batch.py'))
s = importlib.util.module_from_spec(spec)
spec.loader.exec_module(s)

def row(id_, source, start, file='data/x.inc'):
    return dict(id=id_, file=file, source=source, start=start, kind='script', status='pending')

class ScriptBatchTests(unittest.TestCase):
    def test_parse_skips_comments_and_labels(self):
        text = '## Label::\n# note\na1\tこんにちは\\n\n\na2\tさようなら$\n'
        self.assertEqual(s.parse(text), [('a1', 'こんにちは\\n'), ('a2', 'さようなら$')])

    def test_scopes_message_start_and_variables(self):
        rows = [row('a', 'Hi {PLAYER}\\n', 0), row('b', 'bye.$', 10), row('c', 'Next$', 20)]
        result = s.build(rows, [('a', '{PLAYER}、\\n'.replace('、', ' ')), ('b', 'またね。$'), ('c', 'つぎ$')], 'B')
        self.assertEqual([r['translation'] for r in result],
                         ['{JPN}{ENG}{PLAYER}{JPN} \\n', 'またね。$', '{JPN}つぎ$'])

    def test_directive_branch_gets_language_prefix(self):
        rows = [row('a', 'Hi$', 0), row('b', 'there$', 10)]
        result = s.build(rows, [('a', 'やあ$'), ('b', 'よう$')], 'B', after_directive={'b'})
        self.assertEqual(result[1]['translation'], '{JPN}よう$')

    def test_refuses_partial_message(self):
        rows = [row('a', 'Hi\\n', 0), row('b', 'there$', 10)]
        with self.assertRaisesRegex(ValueError, 'whole message'):
            s.build(rows, [('a', 'やあ\\n')], 'B')

    def test_refuses_unknown_or_translated_id(self):
        rows = [row('a', 'Hi$', 0)]
        with self.assertRaisesRegex(ValueError, 'unknown'):
            s.build(rows, [('z', 'やあ$')], 'B')
        rows[0]['status'] = 'translated'
        with self.assertRaisesRegex(ValueError, 'already translated'):
            s.build(rows, [('a', 'やあ$')], 'B')

if __name__ == '__main__':
    unittest.main()
