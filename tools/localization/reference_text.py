#!/usr/bin/env python3
"""Propose reference Japanese for pending C strings by declaration key.

A string's key is the enclosing `[CONSTANT] = {` entry plus the `.field` it is
assigned to, or the declared variable name, plus its ordinal under that key.
The same key in the Japanese reference fork gives the candidate. Candidates are
review material only: Wishes text can differ, and widths still need checking.

usage: reference_text.py OUT.json [FILE...]   (default: every file with pending rows)
"""
import json, pathlib, re, subprocess, sys
import catalog

BASE = '23be896714'
REFERENCE = catalog.ROOT.parent / 'reference-jp'
REFERENCE_COMMIT = 'b07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5ef'
ENTRY = re.compile(r'\[(\w+)\]\s*=\s*\{')
FIELD = re.compile(r'\.(\w+)\s*=\s*$')
DECL = re.compile(r'(\w+)\s*(?:\[[^\]]*\])*\s*=\s*\{?\s*$')

def keyed_literals(text):
    """Map (context, field, ordinal) -> decoded literal for every string macro."""
    skeleton = catalog.masked(text)
    blank = catalog.COMMENTS.sub(lambda m: re.sub(r'[^\n]', ' ', m[0]), text)
    entries = []
    for entry in ENTRY.finditer(blank):
        depth, end = 1, entry.end()
        while end < len(blank) and depth:
            depth += (blank[end] == '{') - (blank[end] == '}')
            end += 1
        entries.append((entry.start(), end, entry[1]))
    seen, result = {}, {}
    for match in catalog.MACRO.finditer(skeleton):
        start = match.start()
        inside = [e for e in entries if e[0] < start < e[1]]
        before = blank[max(0, start - 200):start]
        field = FIELD.search(before)
        if inside:
            context = min(inside, key=lambda e: e[1] - e[0])[2]
            name = field[1] if field else ''
        else:
            decl = None
            for decl in re.finditer(r'(\w+)\s*(?:\[[^\]]*\])*\s*=', blank[:start]):
                pass
            context, name = (decl[1] if decl else ''), (field[1] if field else '')
        key = (context, name)
        seen[key] = seen.get(key, -1) + 1
        literal = ''.join(x[1:-1] for x in re.findall(catalog.LITERAL, text[match.start(1):match.end(1)]))
        result[key + (seen[key],)] = (match.start(1), literal)
    return result

def main():
    out = pathlib.Path(sys.argv[1])
    actual = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=REFERENCE, text=True).strip()
    if actual != REFERENCE_COMMIT:
        sys.exit('reference commit changed: ' + actual)
    rows = json.loads((catalog.ROOT / 'localization/catalog.json').read_text())
    files = sys.argv[2:] or sorted({r['file'] for r in rows if r['status'] == 'pending' and r['kind'] == 'encoded_c'})
    proposals = {}
    for name in files:
        ref_path = REFERENCE / name
        if not ref_path.exists():
            continue
        english = subprocess.check_output(['git', 'show', BASE + ':' + name], cwd=catalog.ROOT, text=True)
        by_start = {start: key for key, (start, _) in keyed_literals(english).items()}
        reference = keyed_literals(ref_path.read_text(encoding='utf-8'))
        for row in rows:
            if row['file'] != name or row['status'] != 'pending':
                continue
            key = by_start.get(int(row['start']))
            if key and key in reference and re.search(r'[ぁ-ヿ]', reference[key][1]):
                proposals[row['id']] = reference[key][1]
    out.write_text(json.dumps(proposals, ensure_ascii=False, indent=1) + '\n')
    print(json.dumps(dict(files=len(files), proposals=len(proposals))))

if __name__ == '__main__':
    main()
