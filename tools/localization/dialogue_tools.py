#!/usr/bin/env python3
"""Helpers for hand-translating dialogue batches (run from the repository root).

  dump FILE...         print untranslated catalog rows of FILE grouped under their labels
                       (input for script_batch.py: keep "ID<TAB>text", write Japanese)
  check BATCH.json     run catalog.validate on every entry of a batch, report failures
  width BATCH.json [N] report visual lines wider than N cells (default 26; box is 27)
  lookup NAME...       find existing translations of species/item/move names
"""
import json, re, subprocess, sys
import catalog

BASELINE = '23be896714'  # English snapshot; catalog line numbers refer to it
# Rough cell estimates for expanded placeholders. In {JPN} mode every glyph,
# Latin letters included, is 8px, i.e. one cell.
PLACEHOLDER_CELLS = {'PLAYER': 7, 'RIVAL': 7, 'B_PC_CREATOR_NAME': 7}

def load_rows():
    return json.loads((catalog.ROOT / 'localization/catalog.json').read_text())

def dump(files):
    rows = load_rows()
    for name in files:
        snapshot = subprocess.run(['git', 'show', f'{BASELINE}:{name}'], cwd=catalog.ROOT,
                                  capture_output=True, text=True, check=True).stdout.split('\n')
        print('#####', name)
        for row in sorted((r for r in rows if r['file'] == name), key=lambda r: r['start']):
            above = snapshot[row['line'] - 2].strip() if row['line'] >= 2 else ''
            if above.endswith(':'):
                print('##', above)
            if row['status'] == 'pending':
                print(row['id'] + '\t' + row['source'])

def charmap():
    text = (catalog.ROOT / 'charmap.txt').read_text()
    return set(re.findall(r"^'(.)'\s*=", text, re.M)) | {'"', "'", '\\'}

def check(batch_path):
    by_id = {r['id']: r for r in load_rows()}
    cmap, bad = charmap(), 0
    for item in json.loads(open(batch_path).read()):
        try:
            catalog.validate({**by_id[item['id']], 'translation': item['translation']}, cmap)
        except ValueError as error:
            bad += 1
            print(error, '|', by_id[item['id']]['source'], '=>', item['translation'])
    print('bad', bad)
    return bad

def cells(segment):
    width = 0
    for token in re.findall(r'\{[^}]*\}|.', segment):
        if not token.startswith('{'):
            width += 1
            continue
        name = token[1:-1]
        if name in PLACEHOLDER_CELLS:
            width += PLACEHOLDER_CELLS[name]
        elif name.startswith(('STR_VAR', 'STRING')):
            width += 10
    return width

def width(batch_path, limit=26):
    wide = 0
    for item in json.loads(open(batch_path).read()):
        for segment in re.split(r'\\[npl]|\$', item['translation']):
            if cells(segment) > limit:
                wide += 1
                print(cells(segment), item['id'], segment)
    return wide

def lookup(names):
    known = {}
    for row in load_rows():
        source = row['source']
        if row['status'] != 'translated' or len(source) > 24 or '\\n' in source:
            continue
        if row['file'].startswith(('src/data/pokemon/species_info', 'src/data/moves')) or row['file'] == 'src/data/items.h':
            known.setdefault(source.upper().replace('É', 'E'), set()).add(row['translation'])
    for name in names:
        key = name.upper().replace('É', 'E')
        print(name, '=>', known.get(key) or known.get(key.replace(' ', '')) or '??')

def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    command, args = sys.argv[1], sys.argv[2:]
    if command == 'dump':
        dump(args)
    elif command == 'check':
        sys.exit(1 if check(args[0]) else 0)
    elif command == 'width':
        width(args[0], int(args[1]) if len(args) > 1 else 26)
    elif command == 'lookup':
        lookup(args)
    else:
        sys.exit(__doc__)

if __name__ == '__main__':
    main()
