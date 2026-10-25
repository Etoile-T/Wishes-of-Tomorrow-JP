#!/usr/bin/env python3
"""Append newly supported literals from the pinned English source; keep all IDs."""
import hashlib
import json
import subprocess

import catalog

BASE = '23be896714'


def main():
    path = catalog.ROOT/'localization/catalog.json'
    rows = json.loads(path.read_text())
    known = {(r['file'], r['start']) for r in rows}
    added = []
    for name in ['src/data/items.h']:
        text = subprocess.check_output(['git', 'show', BASE+':'+name], cwd=catalog.ROOT, text=True)
        for match in catalog.MACRO.finditer(catalog.masked(text)):
            start, end = match.span(1)
            if (name, start) in known:
                continue
            raw = text[start:end]
            source = ''.join(x[1:-1] for x in catalog.re.findall(catalog.LITERAL, raw))
            key = hashlib.sha256((name+'\0'+str(start)+'\0'+source).encode()).hexdigest()[:16]
            added.append(dict(id=key, file=name, line=text.count('\n', 0, start)+1,
                              start=start, end=end, raw=raw, source=source,
                              translation='', status='pending', kind='encoded_c'))
    rows.extend(added)
    if len({r['id'] for r in rows}) != len(rows):
        raise ValueError('ID collision')
    path.write_text(json.dumps(rows, ensure_ascii=False, indent=2)+'\n')
    print(json.dumps(dict(added=len(added), total=len(rows))))


if __name__ == '__main__':
    main()
