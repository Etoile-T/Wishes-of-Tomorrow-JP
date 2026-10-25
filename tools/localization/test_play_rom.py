import mmap
from pathlib import Path
import tempfile
import unittest

from export_play_rom import export_rom


class PlayRomTests(unittest.TestCase):
    def test_exports_preserve_open_rom_mapping_and_save(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            source = root / 'build.gba'
            data = bytearray(32 * 1024 * 1024)
            data[0xB2] = 0x96
            source.write_bytes(data)
            first, _ = export_rom(source, root / 'play')
            save = first.with_suffix('.sav')
            save.write_bytes(b'keep this save')
            with first.open('rb') as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_COPY) as mapping:
                inode = first.stat().st_ino
                # Publishing the same build must not rewrite/truncate the inode.
                same, _ = export_rom(source, root / 'play')
                self.assertEqual(first, same)
                self.assertEqual(first.stat().st_ino, inode)
                data[1024] = 42
                source.write_bytes(data)
                second, _ = export_rom(source, root / 'play')
                self.assertNotEqual(first, second)
                self.assertEqual(mapping[1024], 0)
                self.assertEqual(second.read_bytes()[1024], 42)
            self.assertEqual(save.read_bytes(), b'keep this save')

    def test_bad_header_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            source = Path(temp) / 'bad.gba'
            source.write_bytes(b'not a ROM')
            with self.assertRaises(ValueError):
                export_rom(source, Path(temp) / 'play')
