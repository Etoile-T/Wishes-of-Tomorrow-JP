#!/usr/bin/env python3
"""Inventory JSON/.party literals without treating structural IDs as prose."""
import collections,json,pathlib,re
ROOT=pathlib.Path(__file__).resolve().parents[2]
rows=[]
def walk(value,pointer,file):
    if isinstance(value,dict):
        for key,child in value.items(): walk(child,pointer+'/'+str(key).replace('~','~0').replace('/','~1'),file)
    elif isinstance(value,list):
        for index,child in enumerate(value): walk(child,pointer+'/'+str(index),file)
    elif isinstance(value,str):
        rows.append(dict(file=file,pointer=pointer,source=value,status='needs_schema_review'))
for base in ('data','src','include'):
    for path in sorted((ROOT/base).rglob('*')):
        if path.suffix=='.json':
            walk(json.loads(path.read_text()),'',str(path.relative_to(ROOT)))
        elif path.suffix=='.party':
            for i,line in enumerate(path.read_text().splitlines(),1):
                for m in re.finditer(r'"(?:\\.|[^"\\])*"',line):
                    rows.append(dict(file=str(path.relative_to(ROOT)),line=i,source=m[0][1:-1],status='needs_schema_review'))
# Keyboard/raw strings are not safe to prefix with language controls.
for path in sorted((ROOT/'src').rglob('*')):
    if path.suffix in ('.h','.c'):
        for i,line in enumerate(path.read_text().splitlines(),1):
            if '__(' in line:
                rows.append(dict(file=str(path.relative_to(ROOT)),line=i,source=line.strip(),status='raw_encoded_review'))
(ROOT/'localization/structured-inventory.json').write_text(json.dumps(rows,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(dict(total=len(rows),by_status=dict(collections.Counter(r['status'] for r in rows)))))
