#!/usr/bin/env python3
"""Lossless CSV interchange export; never edits the localization catalog."""
import argparse
import collections
import csv
import hashlib
import json
from pathlib import Path
import shutil
import zipfile

ROOT = Path(__file__).resolve().parents[2]
FIELDS = ['id', 'file', 'line', 'kind', 'symbol', 'source', 'translation', 'status', 'notes']


def write_csv(path, rows, fields=FIELDS):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('w', encoding='utf-8-sig', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, extrasaction='ignore')
        writer.writeheader()
        writer.writerows(rows)
    # Check round trip including quotes, literal backslashes and actual newlines.
    with path.open(encoding='utf-8-sig', newline='') as stream:
        actual = list(csv.DictReader(stream))
    expected = [{key: str(row.get(key, '')) for key in fields} for row in rows]
    assert actual == expected, path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('output', type=Path)
    parser.add_argument('--batch-size', type=int, default=500)
    args = parser.parse_args()
    if args.batch_size < 1:
        parser.error('batch-size must be positive')
    out = args.output.resolve()
    if out.exists():
        parser.error('output must be a new directory (protect returned translations)')
    out.mkdir(parents=True)
    catalog_path = ROOT / 'localization/catalog.json'
    rows = json.loads(catalog_path.read_text())
    assert len({row['id'] for row in rows}) == len(rows)
    translated = [r for r in rows if r['status'] == 'translated']
    pending = [r for r in rows if r['status'] != 'translated']
    write_csv(out / 'all-texts.csv', rows)
    write_csv(out / 'pending-texts.csv', pending)
    write_csv(out / 'translated-reference.csv', translated)
    glossary = json.loads((ROOT / 'localization/glossary.json').read_text())
    write_csv(out / 'glossary.csv', glossary['terms'], ['source', 'translation', 'status'])
    # Preserve source/file order; duplicate text stays distinct for contextual translation.
    batches = []
    for index, start in enumerate(range(0, len(pending), args.batch_size), 1):
        subset = pending[start:start + args.batch_size]
        name = f'batches/pending-{index:03d}.csv'
        write_csv(out / name, subset)
        batches.append({'file': name, 'rows': len(subset)})
    for name in ['CHATGPT_PROMPT.ja.md', 'CSV_README.ja.md']:
        shutil.copyfile(ROOT / 'localization' / name, out / name)
    manifest = {
        'catalog_sha256': hashlib.sha256(catalog_path.read_bytes()).hexdigest(),
        'counts': dict(collections.Counter(r['status'] for r in rows)),
        'total_candidates': len(rows), 'batch_size': args.batch_size,
        'batches': batches,
        'scope': 'Existing catalog candidates only; not an exhaustive audit of images, bare C or structured data.',
        'csv_encoding': 'UTF-8 BOM', 'deduplicated': False,
    }
    manifest['sha256'] = {
        str(p.relative_to(out)): hashlib.sha256(p.read_bytes()).hexdigest()
        for p in sorted(out.rglob('*')) if p.is_file()
    }
    (out / 'manifest.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=2) + '\n')
    archive = out.with_suffix('.zip')
    if archive.exists():
        raise FileExistsError(archive)
    with zipfile.ZipFile(archive, 'w', zipfile.ZIP_DEFLATED) as bundle:
        for path in sorted(out.rglob('*')):
            if path.is_file():
                bundle.write(path, path.relative_to(out))
    print(json.dumps({'all': len(rows), 'translated': len(translated),
                      'pending': len(pending), 'batches': len(batches),
                      'archive': str(archive)}, ensure_ascii=False))


if __name__ == '__main__':
    main()
