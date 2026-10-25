#!/usr/bin/env python3
"""Export an immutable, hash-named play ROM; never rewrite an emulator's ROM.

The mutable build output and wishes-jp-wip.gba are not suitable play paths.
Save RAM/state files are deliberately never copied, changed or overwritten here.
"""
import argparse
import hashlib
import os
from pathlib import Path
import tempfile


def export_rom(source, directory):
    data = Path(source).read_bytes()
    if len(data) != 32 * 1024 * 1024 or data[0xB2] != 0x96:
        raise ValueError('expected a padded 32 MiB GBA build with a valid fixed header byte')
    digest = hashlib.sha256(data).hexdigest()
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    target = directory / ('wishes-jp-' + digest[:16] + '.gba')
    if target.exists():
        if target.read_bytes() != data:
            raise ValueError('existing export differs; refusing to overwrite: ' + str(target))
        return target, digest
    # Finish and fsync a separate inode before publishing. link() atomically
    # creates a new name and refuses to replace an existing file, including one
    # that an emulator might currently have memory-mapped.
    fd, temporary = tempfile.mkstemp(prefix='.rom-export-', dir=directory)
    try:
        with os.fdopen(fd, 'wb') as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        try:
            os.link(temporary, target)
        except FileExistsError:
            if target.read_bytes() != data:
                raise ValueError('concurrent export differs; refusing to overwrite')
    finally:
        os.unlink(temporary)
    return target, digest


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    target, digest = export_rom(args.rom, args.output)
    print(target.resolve())
    print('SHA256 ' + digest)
