#!/usr/bin/env python3
"""Find reference-Japanese drafts with identical English and control layouts.
Never modifies sources/catalog. Every suggested message needs semantic review.
"""
import bisect
import collections
import json
from pathlib import Path
import re
import subprocess
import catalog
from story_content_diff import LABEL, texts, normalize, BASE, REFERENCE

LAYOUT = re.compile(r'\\[npl]|\$')
JP_COMMIT = 'b07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5ef'


def align(members, japanese):
    """Only reuse exact layout shapes. Do not invent pages or split semantics."""
    english = ''.join(r['source'] for r in members)
    if LAYOUT.findall(english) != LAYOUT.findall(japanese): return None
    matches = list(LAYOUT.finditer(japanese)); cursor=0; start=0; result=[]
    for row in members:
        count = len(LAYOUT.findall(row['source']))
        if not count or not LAYOUT.search(row['source']) or not re.search(r'(?:\\[npl]|\$)$', row['source']): return None
        cursor += count; end=matches[cursor-1].end()
        candidate=japanese[start:end]; start=end
        if catalog.protected(row['source']) != catalog.protected(candidate): return None
        result.append(dict(id=row['id'], source=row['source'], draft=candidate))
    if start != len(japanese): return None
    return result


def main():
    root=catalog.ROOT
    jp=root.parent/'reference-jp'; en=root.parent/'artifacts/expansion-1.15.3-reference'
    for path,wanted in [(jp,JP_COMMIT),(en,REFERENCE)]:
        actual=subprocess.check_output(['git','rev-parse','HEAD'],cwd=path,text=True).strip()
        if actual!=wanted:raise ValueError('Reference commit mismatch: '+str(path))
    rows=json.loads((root/'localization/catalog.json').read_text())
    maps={m['map'] for m in json.loads((root/'localization/story-map-inventory.json').read_text())['maps']}
    files=collections.defaultdict(list)
    for r in rows:
        if r['file'].startswith('data/maps/') and r['file'].split('/')[2] in maps:files[r['file']].append(r)
    candidates=[]; reasons=collections.Counter()
    for file,members in sorted(files.items()):
        if not any(r['status']=='pending' for r in members):continue
        if not (jp/file).exists() or not (en/file).exists():reasons['missing_reference']+=1;continue
        source=subprocess.check_output(['git','show',BASE+':'+file],cwd=root,text=True)
        # Alternatives cannot be treated as one message without a branch audit.
        if re.search(r'^\s*#\s*(if|else|elif)',source,re.M):reasons['conditional_file']+=1;continue
        labels=list(LABEL.finditer(source));positions=[m.start() for m in labels]
        by_label=collections.defaultdict(list)
        for r in members:
            i=bisect.bisect_right(positions,r['start'])-1
            if i>=0:by_label[labels[i][1]].append(r)
        english=texts((en/file).read_text());japanese=texts((jp/file).read_text())
        for label,group in by_label.items():
            group.sort(key=lambda r:r['start'])
            if not any(r['status']=='pending' for r in group):continue
            if any(r['status']!='pending' for r in group):reasons['mixed_existing_translation']+=1;continue
            if label not in english or label not in japanese:reasons['missing_label']+=1;continue
            if normalize(''.join(r['source'] for r in group))!=normalize(english[label]):reasons['changed_english']+=1;continue
            result=align(group,japanese[label])
            if result is None:reasons['layout_or_control_difference']+=1;continue
            candidates.append(dict(file=file,label=label,rows=result,status='needs_semantic_review'))
    output=dict(wishes_snapshot=BASE,english_commit=REFERENCE,japanese_commit=JP_COMMIT,method='Identical concatenated English per label; exact newline/page/scroll/end shape; per-row protected tokens match',limitations=['No translation is applied. These are unreviewed drafts.', 'Reference Japanese can differ in meaning even when English labels match; compare every whole message.', 'Glyphs, Japanese mode, width and fixed UI budgets still need the normal checks.', 'Map graph does not prove reachability or play order.'],messages=len(candidates),rows=sum(len(c['rows']) for c in candidates),skipped=dict(reasons),candidates=candidates)
    dest=root/'localization/reference-dialogue-candidates.json';dest.write_text(json.dumps(output,ensure_ascii=False,indent=2)+'\n')
    print('Unreviewed reference candidates:',output['messages'],'messages /',output['rows'],'rows; no source edits')
    print('By file:',dict(collections.Counter(c['file'] for c in candidates).most_common(12)))

if __name__=='__main__':main()
