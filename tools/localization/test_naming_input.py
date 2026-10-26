"""Exercise the actual C encoder against fixed save-field boundaries."""
import ctypes
import pathlib
import re
import subprocess
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[2]


class NamingInputTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.TemporaryDirectory()
        folder = pathlib.Path(cls.tmp.name)
        source = folder / 'encoder.c'
        source.write_text('typedef unsigned char u8; typedef unsigned short u16; typedef unsigned char bool8;\n'
                          '#define TRUE 1\n#define FALSE 0\n#include "naming_input.h"\n'
                          'int encode(u8 *d, u8 c, const u8 *g, u8 n) { return NamingInputEncode(d,c,g,n); }\n')
        library = folder / 'encoder.so'
        subprocess.run(['cc', '-shared', '-fPIC', '-I', str(ROOT / 'include'), str(source), '-o', str(library)], check=True)
        cls.library = ctypes.CDLL(str(library))
        cls.encode = cls.library.encode
        cls.encode.argtypes = [ctypes.POINTER(ctypes.c_ubyte), ctypes.c_ubyte,
                              ctypes.POINTER(ctypes.c_ubyte), ctypes.c_ubyte]
        cls.encode.restype = ctypes.c_int

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    def call(self, glyphs, capacity):
        dest = (ctypes.c_ubyte * 32)(*([0x77] * 32))
        source = (ctypes.c_ubyte * len(glyphs))(*glyphs)
        success = self.encode(dest, capacity, source, len(glyphs))
        return success, bytes(dest)

    def test_player_boundary_and_no_partial_write(self):
        success, data = self.call([1, 2, 3], 8)
        self.assertTrue(success)
        self.assertEqual(data[:8], bytes([0xFC, 0x15, 1, 2, 3, 0xFC, 0x16, 0xFF]))
        self.assertEqual(data[8:], bytes([0x77] * 24))
        success, data = self.call([1, 2, 3, 4], 8)
        self.assertFalse(success)
        self.assertEqual(data, bytes([0x77] * 32))

    def test_nickname_boundary(self):
        success, data = self.call([1, 2, 3, 4, 5, 6], 11)
        self.assertTrue(success)
        self.assertEqual(data[8:11], bytes([0xFC, 0x16, 0xFF]))
        self.assertEqual(data[11:], bytes([0x77] * 21))
        self.assertFalse(self.call([1] * 7, 11)[0])

    def test_english_capacity_preserved(self):
        glyphs = list(range(0xBB, 0xC2))
        success, data = self.call(glyphs, 8)
        self.assertTrue(success)
        self.assertEqual(data[:8], bytes(glyphs + [0xFF]))

    def test_mixed_names_and_vu(self):
        success, data = self.call([0xBB, 1, 0xA1], 8)
        self.assertTrue(success)
        self.assertEqual(data[:8], bytes([0xFC, 0x15, 0xBB, 1, 0xA1, 0xFC, 0x16, 0xFF]))
        self.assertEqual(self.call([0xF1], 6)[1][:6], bytes([0xFC, 0x15, 0xF1, 0xFC, 0x16, 0xFF]))

    def test_ambiguous_punctuation_rejected_without_writes(self):
        for ch in [0xB1, 0xB2, 0xB3, 0xB4, 0xB7, 0xB8]:
            success, data = self.call([1, ch], 8)
            self.assertFalse(success)
            self.assertEqual(data, bytes([0x77] * 32))
            self.assertTrue(self.call([ch], 8)[0])
        self.assertTrue(self.call([1, 0xB5, 0xB6], 8)[0])

    def test_keyboard_coverage_and_glyphs(self):
        source = (ROOT / 'src/naming_screen.c').read_text()
        table = source.split('static const u8 sJapaneseKeyboard', 1)[1].split('static u8 GetCharAtKeyboardPos', 1)[0]
        rows = re.findall(r'__\("([^"\n]+)"\)', table)
        self.assertEqual(len(rows), 24)
        mapped = set(re.findall(r"^'(.)'\s*=", (ROOT / 'charmap.txt').read_text(), re.M))
        for row in rows:
            self.assertEqual(len(row), 8)
            self.assertTrue(set(row) <= mapped)
        for letter in 'あいうえおんがぎぐげござじずぜぞぱぴぷぺぽぁぃぅぇぉゃゅょっ':
            self.assertIn(letter, ''.join(rows))
        self.assertIn('ヴ', ''.join(rows))


if __name__ == '__main__':
    unittest.main()
