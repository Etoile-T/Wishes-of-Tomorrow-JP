#!/usr/bin/env python3
"""Prioritize new text labels in reused map folders; never a completion test."""
import bisect
import collections
import json
import pathlib
import re
import subprocess
ROOT=pathlib.Path(__file__).resolve().parents[2]
BASE='23be896714'
LABEL=re.compile(r'(?m)^([A-Za-z0-9_]+):+')

def main():
    rows=json.loads((ROOT/'localization/catalog.json').read_text())
    graph=json.loads((ROOT/'localization/story-map-inventory.json').read_text())
    depths={m['map']:m['depth'] for m in graph['maps']}
    pending=collections.defaultdict(list)
    for row in rows:
        if row['status']=='pending' and row['file'].startswith('data/maps/'):
            pending[row['file']].append(row)
    groups=[]
    for file,entries in sorted(pending.items()):
        map_name=file.split('/')[2]
        ref=ROOT.parent/'reference-jp'/file
        if not ref.exists():
            continue
        ref_labels=set(LABEL.findall(ref.read_text()))
        source=subprocess.check_output(['git','show',BASE+':'+file],cwd=ROOT,text=True)
        labels=list(LABEL.finditer(source));offsets=[m.start() for m in labels]
        found=collections.defaultdict(list)
        for row in entries:
            i=bisect.bisect_right(offsets,row['start'])-1
            if i<0:continue
            label=labels[i][1]
            if label not in ref_labels:found[label].append(row)
        for label,items in found.items():
            groups.append(dict(map=map_name,label=label,pending=len(items),map_graph_depth=depths.get(map_name),ids=[r['id'] for r in items],source=''.join(r['source'] for r in items)))
    groups.sort(key=lambda g:(g['map_graph_depth'] is None,g['map_graph_depth'] if g['map_graph_depth'] is not None else 999,g['map'],g['label']))
    result=dict(method='Pending map rows whose original label is absent from same map file in local Japanese reference',
                reference_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT.parent/'reference-jp',text=True).strip(),
                limitations=['New labels may be upstream version differences, not Wishes story.','Overwritten English dialogue under unchanged labels is NOT detected.','Folders absent from reference, non-map scripts/C text and unextracted strings are NOT covered.','Map-graph membership is an over-approximation and omits dynamic/C/common-script travel.','This only prioritizes candidates; zero candidates cannot prove story completion.'],
                pending_rows=sum(g['pending'] for g in groups),groups=groups)
    (ROOT/'localization/story-new-label-candidates.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print('New-label candidates:',result['pending_rows'],'rows in',len(groups),'labels')
    for g in groups[:12]:print(g['map_graph_depth'],g['map'],g['label'],g['pending'])
if __name__=='__main__':main()
