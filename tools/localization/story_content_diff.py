#!/usr/bin/env python3
"""Prioritize pending Wishes map text changed from pinned expansion English.
This is a textual comparison, never a reachability or completion test.
"""
import argparse
import bisect
import collections
import json
from pathlib import Path
import re
import subprocess
import catalog

LABEL = re.compile(r'^([A-Za-z0-9_]+):+', re.M)
BASE = '23be896714'
REFERENCE = 'b669d9ccf9c148070b99eba11cd65f6071be0741'


def normalize(text):
    # Ignore only layout/whitespace; keep names, numbers, controls and meaning.
    return re.sub(r'\s+', ' ', re.sub(r'\\[npl]', ' ', text)).strip()


def texts(source):
    labels = list(LABEL.finditer(source)); positions = [m.start() for m in labels]
    result = collections.defaultdict(str)
    for m in catalog.SCRIPT.finditer(source):
        i = bisect.bisect_right(positions, m.start())-1
        if i >= 0: result[labels[i][1]] += m[1][1:-1]
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference', type=Path, required=True)
    args = parser.parse_args()
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=args.reference, text=True).strip()
    if commit != REFERENCE: raise ValueError('Expected expansion/1.15.3: '+REFERENCE)
    rows = json.loads((catalog.ROOT / 'localization/catalog.json').read_text())
    graph = json.loads((catalog.ROOT / 'localization/story-map-inventory.json').read_text())
    depths = {m['map']:m['depth'] for m in graph['maps']}
    files = collections.defaultdict(list)
    for row in rows:
        if row['status']=='pending' and row['file'].startswith('data/maps/'):
            files[row['file']].append(row)
    groups = []; unavailable = []
    for file, pending in sorted(files.items()):
        reference_file = args.reference/file
        if not reference_file.exists():
            unavailable.append(file); continue
        source = subprocess.check_output(['git', 'show', BASE+':'+file], cwd=catalog.ROOT, text=True)
        labels = list(LABEL.finditer(source)); positions = [m.start() for m in labels]
        original = texts(source); reference = texts(reference_file.read_text())
        by_label = collections.defaultdict(list)
        for row in pending:
            i = bisect.bisect_right(positions, row['start'])-1
            if i >= 0: by_label[labels[i][1]].append(row)
        for label, members in by_label.items():
            ref = reference.get(label)
            if ref is not None and normalize(original[label]) == normalize(ref): continue
            map_name = file.split('/')[2]
            groups.append(dict(map=map_name, file=file, label=label, reason='changed_body' if ref is not None else 'label_absent', pending=len(members), map_graph_depth=depths.get(map_name), ids=[r['id'] for r in members], wishes_english=original[label], expansion_english=ref))
    groups.sort(key=lambda g:(g['map_graph_depth'] is None, g['map_graph_depth'] or 0, g['map'], g['label']))
    report = dict(wishes_snapshot=BASE, reference_repository='https://github.com/rh-hideout/pokeemerald-expansion', reference_tag='expansion/1.15.3', reference_commit=commit, method='Compare concatenated English text per label, ignoring layout and whitespace only', limitations=['Changed text can be upstream/version noise, not necessarily Wishes story.', 'Unchanged expansion dialogue can still be used by Wishes and still needs translation.', 'Files missing from reference are listed separately, not classified.', 'This omits non-map, dynamic, C and unextracted text and cannot prove story completion.', 'Map depth is an over-approximation, not verified play order.'], pending_rows=sum(g['pending'] for g in groups), groups=groups, files_absent_from_reference=unavailable)
    path = catalog.ROOT/'localization/story-content-differences.json'
    path.write_text(json.dumps(report, ensure_ascii=False, indent=2)+'\n')
    print('Changed-body/absent-label candidates:',report['pending_rows'],'rows,',len(groups),'labels; absent files:',len(unavailable))
    for g in groups[:20]: print(g['map_graph_depth'],g['map'],g['label'],g['pending'],g['reason'])

if __name__ == '__main__': main()
