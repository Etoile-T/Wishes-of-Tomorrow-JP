#!/usr/bin/env python3
"""Conservative static layout checks for the translated batch, not emulator QA."""
import collections,json,pathlib,re
ROOT=pathlib.Path(__file__).resolve().parents[2]
rows=json.loads((ROOT/'localization/catalog.json').read_text())
issues=[]
for row in rows:
    if row['status']!='translated': continue
    # Normal/small Japanese advances are 8px. Variables need runtime validation.
    if row['file']=='src/strings.c' and '_Quest_' in row.get('target','') and ('Desc' in row['target']): limit=200
    elif row['file'].endswith('.inc'): limit=216
    else: continue
    for index,line in enumerate(re.split(r'\\[npl]',row['translation'])):
        tokens=re.findall(r'\{[^{}]*\}',line)
        plain=re.sub(r'\{[^{}]*\}|\$', '',line)
        width=len(plain)*8
        if width>limit:
            issues.append(dict(id=row['id'],target=row.get('target'),line=index+1,estimate_px=width,limit=limit,text=plain))
report=dict(translated=sum(r['status']=='translated' for r in rows),estimated_overflows=issues,
            limitations=['8px conservative estimate; Latin widths may be narrower', 'Substituted variables, remaining UI and runtime rendering not verified'])
(ROOT/'localization/layout-report.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n')
print(json.dumps(report,ensure_ascii=False,indent=2))
