#!/usr/bin/env python3
"""Create the BPS patch folder, manifest, zip and LATEST-JP.json for an exported play ROM.

usage: make_release.py TRANSLATION_COMMIT TRANSLATED_COUNT PLAY_ROM [VARIANT]
  PLAY_ROM is the hash-named file printed by export_play_rom.py (under ../artifacts/play).
Refuses to overwrite an existing patch folder or zip. Verify afterwards with
apply_verified_patch.py and compare the output ROM byte for byte.
VARIANT keeps feature builds at the same translation count in separate files.
"""
import hashlib, json, pathlib, re, subprocess, sys, zipfile, zlib

REPO = pathlib.Path(__file__).resolve().parents[2]
ARTIFACTS = REPO.parent / 'artifacts'
SOURCE_ROM = ARTIFACTS / 'wishes-en-baseline.gba'
SOURCE_SHA256 = '93fb28460bb7348e327c97e217ecd50091fc01200e8d9cc41b871469c36c9db7'
GAME_SOURCE_COMMIT = 'efb1c880d0b486c1948763051b6c1bb8990a7353'

def info(path):
    data = path.read_bytes()
    return hashlib.sha256(data).hexdigest(), '%08x' % zlib.crc32(data), len(data)

def main():
    if len(sys.argv) not in (4, 5):
        sys.exit(__doc__)
    commit, count, rom = sys.argv[1], int(sys.argv[2]), pathlib.Path(sys.argv[3]).resolve()
    commit = subprocess.check_output(['git', 'rev-parse', '--verify', commit + '^{commit}'], cwd=REPO, text=True).strip()
    variant = sys.argv[4] if len(sys.argv) == 5 else ''
    if variant and not re.fullmatch(r'[a-z0-9-]+', variant):
        sys.exit('invalid variant')
    suffix = '-' + variant if variant else ''
    source_sha, source_crc, source_size = info(SOURCE_ROM)
    if source_sha != SOURCE_SHA256:
        sys.exit('unexpected English baseline ROM')
    target_sha, target_crc, target_size = info(rom)
    folder = ARTIFACTS / 'patches' / f'ui-{count}{suffix}-{target_crc}'
    folder.mkdir(parents=True, exist_ok=False)
    patch_name = f'wishes-jp-ui{count}{suffix}_from-{source_crc}_to-{target_crc}.bps'
    subprocess.run([sys.executable, str(REPO / 'tools/localization/bps.py'), str(SOURCE_ROM), str(rom), str(folder / patch_name)], check=True)
    patch_sha, patch_crc, patch_size = info(folder / patch_name)
    manifest = dict(format='BPS1', game_source_commit=GAME_SOURCE_COMMIT, translation_commit=commit,
                    translated_entries=count, complete_localization=False, patch_file=patch_name,
                    source_sha256=source_sha, source_crc32=source_crc, source_bytes=source_size,
                    target_sha256=target_sha, target_crc32=target_crc, target_bytes=target_size,
                    patch_sha256=patch_sha, patch_crc32=patch_crc, patch_bytes=patch_size)
    (folder / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    (folder / 'README.ja.txt').write_text(f"""日本語化途中版・{count:,}件適用
ソースコミット: {commit}
適用元: ソースから生成した英語Wishes、32MiB、CRC32 {source_crc}
適用元SHA256: {source_sha}
適用後CRC32: {target_crc}
適用後SHA256: {target_sha}
市販Emeraldや公式1.2.6適用後ROMには使わない。チェックサムを無視しない。
ローカルではartifacts/{rom.relative_to(ARTIFACTS)}をそのまま開く。追加BPS不要。
完全日本語版ではない。ゲーム画面・全進行は未検証。
ソース: https://github.com/Etoile-T/Wishes-of-Tomorrow-JP/tree/{commit}
""")
    archive = ARTIFACTS / f'wishes-jp-ui{count}{suffix}-{target_crc}-patch.zip'
    if archive.exists():
        sys.exit('zip already exists: ' + str(archive))
    with zipfile.ZipFile(archive, 'w', zipfile.ZIP_DEFLATED) as out:
        for name in (patch_name, 'manifest.json', 'README.ja.txt'):
            out.write(folder / name, name)
    (REPO / f'localization/patch-manifest-ui{count}{suffix}.json').write_text(json.dumps(manifest, indent=2) + '\n')
    latest = dict(rom=str(rom.relative_to(ARTIFACTS)), patch_directory=str(folder.relative_to(ARTIFACTS)), **manifest)
    (ARTIFACTS / 'LATEST-JP.json').write_text(json.dumps(latest, indent=2) + '\n')
    print(json.dumps(manifest, indent=1))

if __name__ == '__main__':
    main()
