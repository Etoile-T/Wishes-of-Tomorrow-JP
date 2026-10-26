"""Exercise actual box-name repair with canaries around all 14 save fields."""
import ctypes
import json
import pathlib
import re
import subprocess
import tempfile
import unittest
ROOT=pathlib.Path(__file__).resolve().parents[2]
class StorageNames(unittest.TestCase):
    def test_all_defaults_fit_and_do_not_overwrite_adjacent_fields(self):
        header=(ROOT/'include/storage_name_localization.h').read_text()
        old=[int(v.strip(),16) for v in re.search(r'legacy\[8\] = \{([^}]+)',header)[1].split(',')]
        with tempfile.TemporaryDirectory() as folder:
            src=pathlib.Path(folder)/'box.c';lib=pathlib.Path(folder)/'box.so'
            src.write_text('typedef unsigned char u8;typedef unsigned char bool8;\n#define TRUE 1\n#define FALSE 0\n#include "storage_name_localization.h"\nvoid fix(u8*n,u8 b){NormalizeStorageBoxName(n,b);}')
            subprocess.run(['cc','-shared','-fPIC','-I',str(ROOT/'include'),str(src),'-o',str(lib)],check=True)
            fn=ctypes.CDLL(str(lib)).fix
            fn.argtypes=[ctypes.POINTER(ctypes.c_ubyte),ctypes.c_ubyte]
            for box in range(14):
                raw=(ctypes.c_ubyte*11)(0x77,*old,0xA2,0x66)
                ptr=ctypes.cast(ctypes.byref(raw,1),ctypes.POINTER(ctypes.c_ubyte));fn(ptr,box)
                self.assertEqual((raw[0],raw[10]),(0x77,0x66))
                expected=[252,32]+old[2:6]+[0xA1+int(c) for c in str(box+1)]+[255]
                self.assertEqual(list(raw)[1:1+len(expected)],expected)
                before=bytes(raw);fn(ptr,box);self.assertEqual(bytes(raw),before)
            custom=(ctypes.c_ubyte*9)(1,2,3,255,4,5,6,7,255)
            fn(custom,0);self.assertEqual(list(custom),[1,2,3,255,4,5,6,7,255])
        row=next(r for r in json.loads((ROOT/'localization/catalog.json').read_text()) if r['id']=='d6cf5724f5eba1ea')
        self.assertEqual(row['translation'],'{JPN_NAME_4}ボックス')
