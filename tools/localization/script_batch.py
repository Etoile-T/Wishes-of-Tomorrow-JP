#!/usr/bin/env python3
"""Build an ID-keyed batch from hand-written Japanese script lines.

Input lines are `ID<TAB>japanese` (blank lines and lines starting with # ignored).
Write the visible Japanese only: {JPN} is added at each message start and
variables are wrapped as {ENG}{VAR}{JPN}. Every line of a message must be
translated together, because consecutive .string lines share one language mode.
"""
import argparse, json, pathlib, re, subprocess
import catalog

BASELINE = '23be896714'  # English source snapshot; catalog line numbers refer to it
VARIABLE = re.compile(r'\{(?:PLAYER|RIVAL|STR_VAR_[123]|STRING \d+|B_[A-Z_0-9]+)\}')

def parse(text):
    pairs = []
    for line in text.splitlines():
        if not line.strip() or line.startswith('#'):
            continue
        key, _, value = line.partition('\t')
        pairs.append((key.strip(), value))
    return pairs

def messages(rows):
    """Map each script row id to the ids of its whole message (rows end at '$')."""
    groups, current = {}, []
    for row in sorted(rows, key=lambda r: (r['file'], r['start'])):
        if current and current[-1]['file'] != row['file']:
            current = []
        current.append(row)
        if row['source'].endswith('$'):
            for member in current:
                groups[member['id']] = [m['id'] for m in current]
            current = []
    for member in current:
        groups[member['id']] = [m['id'] for m in current]
    return groups

def scope(text, starts_message):
    text = VARIABLE.sub(lambda m: '{ENG}' + m[0] + '{JPN}', text)
    return ('{JPN}' if starts_message else '') + text

def build(rows, pairs, batch, after_directive=frozenset()):
    by_id = {r['id']: r for r in rows}
    wanted = dict(pairs)
    for key in wanted:
        if key not in by_id:
            raise ValueError('unknown ID: ' + key)
        if by_id[key]['status'] != 'pending':
            raise ValueError('already translated: ' + key)
    script_rows = [r for r in rows if r['kind'] == 'script' and r['file'] in {by_id[k]['file'] for k in wanted}]
    groups = messages(script_rows)
    for key in wanted:
        missing = [m for m in groups[key] if m not in wanted]
        if missing:
            raise ValueError(f'{key}: translate the whole message; missing {missing}')
    result = []
    for key, value in pairs:
        # A row right after #if/#else may begin the message in one build variant.
        first = groups[key][0] == key or key in after_directive
        result.append(dict(id=key, translation=scope(value, first),
                           provenance=dict(batch=batch, method='Hand-translated dialogue; whole message, variables scoped ENG/JPN')))
    return result

def directive_rows(rows, files):
    """IDs of rows whose previous source line in the English snapshot is a directive."""
    found = set()
    for name in files:
        lines = subprocess.run(['git', 'show', BASELINE + ':' + name], cwd=catalog.ROOT,
                               capture_output=True, text=True, check=True).stdout.split('\n')
        for row in rows:
            if row['file'] == name and row['line'] >= 2 and lines[row['line'] - 2].lstrip().startswith('#'):
                found.add(row['id'])
    return found

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('source', type=pathlib.Path)
    ap.add_argument('batch', type=pathlib.Path)
    args = ap.parse_args()
    rows = json.loads((catalog.ROOT / 'localization/catalog.json').read_text())
    pairs = parse(args.source.read_text())
    by_id = {r['id']: r for r in rows}
    files = {by_id[k]['file'] for k, _ in pairs if k in by_id}
    result = build(rows, pairs, args.batch.stem, directive_rows(rows, files))
    args.batch.write_text(json.dumps(result, ensure_ascii=False, indent=1) + '\n')
    print(json.dumps(dict(entries=len(result), batch=str(args.batch))))

if __name__ == '__main__':
    main()
