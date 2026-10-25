#!/usr/bin/env python3
"""Apply a documented Japanese BPS only to its exact SHA256-pinned base.

There is no force/ignore-checksum option. Output is an immutable hash-named ROM.
"""
import argparse
import hashlib
import json
from pathlib import Path

import bps
from export_play_rom import export_rom
import tempfile


def checked_apply(source, patch, manifest):
    for label, data in [('source', source), ('patch', patch)]:
        expected = manifest[label + '_sha256']
        actual = hashlib.sha256(data).hexdigest()
        if actual != expected:
            raise ValueError(label + ' SHA256 mismatch; no output written')
    result = bps.apply(source, patch)
    if hashlib.sha256(result).hexdigest() != manifest['target_sha256']:
        raise ValueError('target SHA256 mismatch; no output written')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source', type=Path)
    parser.add_argument('patch', type=Path)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('output_directory', type=Path)
    args = parser.parse_args()
    result = checked_apply(args.source.read_bytes(), args.patch.read_bytes(),
                           json.loads(args.manifest.read_text()))
    with tempfile.TemporaryDirectory() as temporary:
        staged = Path(temporary) / 'verified.gba'
        staged.write_bytes(result)
        target, digest = export_rom(staged, args.output_directory)
    print(target.resolve())
    print('SHA256 ' + digest)


if __name__ == '__main__':
    main()
