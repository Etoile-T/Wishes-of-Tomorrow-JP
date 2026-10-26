"""Compile the actual battle substitution loop; spaces must not become kana."""
import ctypes
import pathlib
import subprocess
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[2]

class BattleDialogueSpaces(unittest.TestCase):
    def test_trainer_dialogue_and_name_substitutions(self):
        source = (ROOT / 'src/battle_message.c').read_text()
        loop = source.split('            if (toCpy != NULL)\n            {', 1)[1].split('\n            if (*src == B_TXT_TRAINER1_LOSE_TEXT', 1)[0]
        # The extracted block ends with the closing brace of the if.
        code = ('typedef unsigned char u8;\n#define EOS 255\n#define CHAR_SPACE 0\n#define CHAR_NBSP 57\n'
                '#define B_TXT_TRAINER1_LOSE_TEXT 1\n#define B_TXT_TRAINER2_LOSE_TEXT 2\n'
                '#define B_TXT_TRAINER1_WIN_TEXT 3\n#define B_TXT_TRAINER2_WIN_TEXT 4\n'
                'void copy(u8 *dst,const u8 *toCpy,const u8 *src){int dstID=0;{'+loop+';dst[dstID]=EOS;}')
        with tempfile.TemporaryDirectory() as folder:
            c = pathlib.Path(folder) / 'copy.c'; lib = pathlib.Path(folder) / 'copy.so'
            c.write_text(code)
            subprocess.run(['cc','-shared','-fPIC',str(c),'-o',str(lib)],check=True)
            fn = ctypes.CDLL(str(lib)).copy
            # {JPN}... SPACE ... actual ぐ ... {ENG} EOS
            raw = [252,21,1,0,2,57,252,22,255]
            for placeholder in range(1,6):
                dest=(ctypes.c_ubyte*32)(); data=(ctypes.c_ubyte*len(raw))(*raw)
                src=(ctypes.c_ubyte*1)(placeholder); fn(dest,data,src)
                expected=raw.copy()
                if placeholder==5: expected[3]=57
                self.assertEqual(bytes(dest[:len(raw)]),bytes(expected))
