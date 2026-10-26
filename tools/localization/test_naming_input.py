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
                          'int encode(u8 *d, u8 c, const u8 *g, u8 n) { return NamingInputEncode(d,c,g,n); }\n'
                          'void decode(u8 *d, u8 c, const u8 *s) { NamingInputDecode(d,c,s); }\n'
                          'int limit(u8 c) { return NamingInputKanaLimit(c); }\n')
        text = (ROOT / 'src/text.c').read_text()
        width = text.split('s32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing)\n{', 1)[1].split('s32 GetStringLineWidth(', 1)[0]
        with source.open('a') as out:
            out.write('#include <stddef.h>\ntypedef unsigned int u32; typedef int s32; typedef short s16; typedef int bool32;\n'
                      '#define FONTATTR_LETTER_SPACING 0\n#define max(a,b) ((a)>(b)?(a):(b))\n'
                      'static const u8 empty[]={EOS}; const u8 *gStringVar1=empty,*gStringVar2=empty,*gStringVar3=empty;\n'
                      'static u32 fake(u16 g, bool32 j){return j?8:6;}\n'
                      'static u32 (*GetFontWidthFunc(u8 f))(u16,bool32){return fake;}\n'
                      'static int GetFontAttribute(u8 f,int a){return 0;}\n'
                      'static const u8 *DynamicPlaceholderTextUtil_GetPlaceholderPtr(u8 i){return gStringVar1;}\n'
                      'static int GetKeypadIconWidth(u8 i){return 8;}\n'
                      'static u8 GetExtCtrlCodeLength(u8 c){return 1;}\n'
                      's32 GetStringWidth(u8 fontId, const u8 *str, s16 letterSpacing)\n{' + width + '\n'
                      'int width(const u8 *s){return GetStringWidth(0,s,0);}\n'
                      'int widthvar(const u8 *s){const u8 t[]={PLACEHOLDER_BEGIN,PLACEHOLDER_ID_STRING_VAR_1,CHAR_A,EOS};gStringVar1=s;return width(t);}\n')
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
        success, data = self.call([1, 2, 3, 4, 5], 8)
        self.assertTrue(success)
        self.assertEqual(data[:8], bytes([0xFC, 0x21, 1, 2, 3, 4, 5, 0xFF]))
        self.assertEqual(data[8:], bytes([0x77] * 24))
        success, data = self.call([1, 2, 3, 4, 5, 6], 8)
        self.assertFalse(success)
        self.assertEqual(data, bytes([0x77] * 32))

    def test_nickname_boundary(self):
        success, data = self.call([1, 2, 3, 4, 5], 11)
        self.assertTrue(success)
        self.assertEqual(data[:8], bytes([0xFC, 0x21, 1, 2, 3, 4, 5, 0xFF]))
        self.assertEqual(data[8:], bytes([0x77] * 24))
        self.assertFalse(self.call([1] * 6, 11)[0])

    def test_english_capacity_preserved(self):
        glyphs = list(range(0xBB, 0xC2))
        success, data = self.call(glyphs, 8)
        self.assertTrue(success)
        self.assertEqual(data[:8], bytes(glyphs + [0xFF]))

    def test_mixed_names_and_vu(self):
        success, data = self.call([0xBB, 1, 0xA1], 8)
        self.assertTrue(success)
        self.assertEqual(data[:8], bytes([0xFC, 0x1F, 0xBB, 1, 0xA1, 0xFF, 0x77, 0x77]))
        self.assertEqual(self.call([0xF1], 6)[1][:4], bytes([0xFC, 0x1D, 0xF1, 0xFF]))

    def decode(self, data, capacity):
        dest = (ctypes.c_ubyte * 16)(*([0x77] * 16))
        source = (ctypes.c_ubyte * len(data))(*data)
        self.library.decode(dest, capacity, source)
        return bytes(dest)

    def test_decode_strips_span_and_legacy_codes(self):
        # Renaming copies the saved name into the editor; controls must not become glyphs.
        self.assertEqual(self.decode([0xFC, 0x21, 1, 2, 3, 4, 5, 0xFF], 11)[:6], bytes([1, 2, 3, 4, 5, 0xFF]))
        self.assertEqual(self.decode([0xFC, 0x15, 1, 2, 0xFC, 0x16, 0xFF], 11)[:3], bytes([1, 2, 0xFF]))
        self.assertEqual(self.decode([0xBB, 0xBC, 0xFF], 11)[:3], bytes([0xBB, 0xBC, 0xFF]))
        self.assertEqual(self.decode([1, 2, 3, 4], 3)[:3], bytes([1, 2, 0xFF]))

    def test_kana_limit_matches_save_fields(self):
        limit = self.library.limit
        limit.argtypes = [ctypes.c_ubyte]
        for chars, expected in [(7, 5), (8, 5), (10, 5), (5, 3)]:
            self.assertEqual(limit(chars), expected)

    def test_ambiguous_punctuation_rejected_without_writes(self):
        for ch in [0xB1, 0xB2, 0xB3, 0xB4, 0xB7, 0xB8]:
            success, data = self.call([1, ch], 8)
            self.assertFalse(success)
            self.assertEqual(data, bytes([0x77] * 32))
            self.assertTrue(self.call([ch], 8)[0])
        self.assertTrue(self.call([1, 0xB5, 0xB6], 8)[0])

    def test_actual_width_parser_restores_surrounding_language(self):
        width = self.library.width
        width.argtypes = [ctypes.POINTER(ctypes.c_ubyte)]
        width.restype = ctypes.c_int
        for count in range(1, 6):
            encoded = [0xFC, 0x1C + count] + [1] * count
            english = (ctypes.c_ubyte * (len(encoded) + 3))(*(encoded + [0xBB, 0xBC, 0xFF]))
            self.assertEqual(width(english), count * 8 + 12)
            japanese = (ctypes.c_ubyte * (len(encoded) + 4))(*([0xFC, 0x15] + encoded + [1, 0xFF]))
            self.assertEqual(width(japanese), (count + 1) * 8)

    def test_actual_width_parser_expanded_variable(self):
        width = self.library.widthvar
        width.argtypes = [ctypes.POINTER(ctypes.c_ubyte)]
        width.restype = ctypes.c_int
        name = (ctypes.c_ubyte * 8)(0xFC, 0x21, 1, 2, 3, 4, 5, 0xFF)
        self.assertEqual(width(name), 5 * 8 + 6)

    def test_keyboard_coverage_and_glyphs(self):
        source = (ROOT / 'src/naming_screen.c').read_text()
        table = source.split('static const u8 sJapaneseKeyboard', 1)[1].split('static u8 GetCharAtKeyboardPos', 1)[0]
        rows = re.findall(r'__\("([^"\n]+)"\)', table)
        self.assertEqual(len(rows), 8)
        mapped = set(re.findall(r"^'(.)'\s*=", (ROOT / 'charmap.txt').read_text(), re.M))
        for row in rows:
            self.assertEqual(len(row), 18)
            self.assertTrue(set(row) <= mapped)
        for letter in 'あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをん':
            self.assertIn(letter, ''.join(rows))
        for table in ['voiced', 'semi', 'small']:
            self.assertIn('const u8 ' + table, source)



if __name__ == '__main__':
    unittest.main()
