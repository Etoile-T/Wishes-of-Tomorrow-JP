#!/usr/bin/env python3
"""Build a batch from ID<TAB>exact-translation lines (no automatic {JPN}/{ENG}).
For fixed-size fields (names) written as {JPN_NAME_n}カナ, or text kept as in English.
usage (repo root): python3 ../artifacts/work70/direct_batch.py IN.tsv localization/batches/OUT.json
"""
import json, sys, pathlib
src, out = sys.argv[1], pathlib.Path(sys.argv[2])
rows = {r['id']: r for r in json.load(open('localization/catalog.json'))}
result = []
for line in open(src, encoding='utf-8'):
    if not line.strip() or line.startswith('#'):
        continue
    key, _, value = line.rstrip('\n').partition('\t')
    if key not in rows or rows[key]['status'] != 'pending':
        sys.exit('unknown or already translated ID: ' + key)
    result.append(dict(id=key, translation=value, provenance=dict(batch=out.stem, method='Exact translation for fixed-size field or kept text (no automatic JPN/ENG scope)')))
out.write_text(json.dumps(result, ensure_ascii=False, indent=1) + '\n')
print(json.dumps(dict(entries=len(result), batch=str(out))))
