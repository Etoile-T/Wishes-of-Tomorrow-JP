import pathlib, re, subprocess, tempfile, unittest
import braille_ja as b

ROOT = pathlib.Path(__file__).resolve().parents[2]
PREPROC = ROOT / 'tools/preproc/preproc'

class BrailleJaTest(unittest.TestCase):
    def test_cells_follow_japanese_braille(self):
        # う=1,4 へ=1,2,3,4,6 ジャ=yoon-dakuten(4,5)+さ プ=handakuten(6)+ふ っ=2 ー=2,5
        self.assertEqual(b.encode('う'), [0x03])
        self.assertEqual(b.encode('へ'), [0x37])
        self.assertEqual(b.encode('ジャ'), [0x0A, 0x29])
        self.assertEqual(b.encode('プ'), [0x20, 0x33])
        self.assertEqual(b.encode('っー'), [0x04, 0x0C])

    def test_rejects_unsupported_kana(self):
        with self.assertRaises(ValueError):
            b.encode('ティ')

    def test_header_is_current(self):
        self.assertEqual((ROOT / 'tools/preproc/braille_ja.h').read_text(), b.header())

    @unittest.skipUnless(PREPROC.exists(), 'preproc not built')
    def test_preproc_matches_reference_for_game_braille(self):
        lines = re.findall(r'^\t\.braille "(.*)"$', (ROOT / 'data/text/braille.inc').read_text(), re.M)
        self.assertTrue(lines)
        with tempfile.TemporaryDirectory() as tmp:
            src = pathlib.Path(tmp, 'b.s')
            src.write_text(''.join(f'\t.braille "{line}"\n' for line in lines))
            out = subprocess.run([str(PREPROC), str(src), str(ROOT / 'charmap.txt')],
                                 capture_output=True, text=True, check=True).stdout
        encoded = [[int(x, 16) for x in m.split(', ')] for m in re.findall(r'\.byte (.*)', out)]
        for line, cells in zip(lines, encoded):
            text = line.replace('\\n', '\n').replace('$', '')
            expected = []
            for i, part in enumerate(text.split('\n')):
                expected += ([0xFE] if i else []) + b.encode(part)
            self.assertEqual(cells, expected + ([0xFF] if line.endswith('$') else []), line)

if __name__ == '__main__':
    unittest.main()
