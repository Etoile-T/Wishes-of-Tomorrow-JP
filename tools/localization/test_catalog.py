import importlib.util
import pathlib
import tempfile
import unittest
spec = importlib.util.spec_from_file_location('catalog', pathlib.Path(__file__).with_name('catalog.py'))
c = importlib.util.module_from_spec(spec)
spec.loader.exec_module(c)

class CatalogTests(unittest.TestCase):
    def test_comments_and_adjacent_literals(self):
        text = '// _("comment")\n_("Hello "\n"world\\n") /* _("hidden") */'
        matches = list(c.MACRO.finditer(c.masked(text)))
        self.assertEqual(len(matches), 1)
        self.assertEqual(''.join(x[1:-1] for x in c.re.findall(c.LITERAL, matches[0][1])), 'Hello world\\n')

    def test_protected_control_multiset(self):
        row = dict(id='x', source='{PLAYER} {STR_VAR_1}\\n$', translation='{JPN}{STR_VAR_1} {PLAYER}\\n$')
        c.validate(row, {' '})
        row['translation'] = '{JPN}{PLAYER}\\n$'
        with self.assertRaises(ValueError):
            c.validate(row, {' '})

    def test_logo_glyphs_may_be_spelled_out(self):
        # {PKMN}/{POKEBLOCK} are Latin logo glyphs, not controls.
        c.validate(dict(id='x', source='{PKMN} TRAINER', translation='{JPN}ポケモントレーナー{ENG}'), set('ポケモントレーナー'))

    def test_unmapped_kanji_refused(self):
        with self.assertRaisesRegex(ValueError, 'unmapped'):
            c.validate(dict(id='x', source='Hi', translation='{JPN}願い'), {'い'})

    def test_latin_punctuation_refused_in_japanese_mode(self):
        # B7/B8/B1-B4 render as 円 . 『』「」 in the Japanese font.
        for text in ('{JPN}¥200', '{JPN}9,999まい', "{JPN}いや'", '{JPN}“あ”'):
            with self.assertRaisesRegex(ValueError, 'Japanese mode'):
                c.validate(dict(id='x', source='a', translation=text), set(text))
        c.validate(dict(id='x', source='a', translation='{ENG}¥9,999{JPN}200円'), set('¥9,2円0'))

    def test_extract_positions_and_script(self):
        original = c.ROOT
        try:
            with tempfile.TemporaryDirectory() as directory:
                c.ROOT = pathlib.Path(directory)
                (c.ROOT/'src').mkdir()
                (c.ROOT/'data').mkdir()
                (c.ROOT/'src/a.c').write_text('const u8 a[] = _("one" "two"); // _("hidden")')
                (c.ROOT/'data/a.inc').write_text('Text::\n\t.string "Hi!\\p"\n\t.string "$"\n')
                rows = c.extract()
                self.assertEqual(len(rows), 3)
                for row in rows:
                    text = (c.ROOT/row['file']).read_text()
                    self.assertEqual(text[row['start']:row['end']], row['raw'])
        finally:
            c.ROOT = original

if __name__ == '__main__':
    unittest.main()
