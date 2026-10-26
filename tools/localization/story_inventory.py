#!/usr/bin/env python3
"""Conservative map-graph inventory from the Wishes starting village.
This is an over-approximation, not proof of in-game reachability or completeness.
"""
import collections
import json
import pathlib
import re
ROOT=pathlib.Path(__file__).resolve().parents[2]

def main():
    maps={p.parent.name:json.loads(p.read_text()) for p in (ROOT/'data/maps').glob('*/map.json')}
    by_id={d['id']:name for name,d in maps.items()}
    edges=collections.defaultdict(set)
    for name,data in maps.items():
        for item in data.get('connections') or []:
            if item['map'] in by_id:edges[name].add(by_id[item['map']])
        for item in data.get('warp_events',[]):
            if item.get('dest_map') in by_id:edges[name].add(by_id[item['dest_map']])
        script=ROOT/'data/maps'/name/'scripts.inc'
        if script.exists():
            text=re.sub(r'(?m)@.*$','',script.read_text())
            for match in re.finditer(r'(?m)^\s*(?:warp\w*|setwarp\w*)\s+(MAP_\w+)',text):
                if match[1] in by_id:edges[name].add(by_id[match[1]])
    distance={'MunenVillage':0};parents={};queue=collections.deque(distance)
    while queue:
        name=queue.popleft()
        for dest in sorted(edges[name]):
            if dest not in distance:distance[dest]=distance[name]+1;parents[dest]=name;queue.append(dest)
    rows=json.loads((ROOT/'localization/catalog.json').read_text())
    counts=collections.defaultdict(collections.Counter)
    for row in rows:
        if row['file'].startswith('data/maps/'):
            counts[row['file'].split('/')[2]][row['status']]+=1
    ordered=[]
    for name,depth in sorted(distance.items(),key=lambda item:(item[1],item[0])):
        ordered.append({'map':name,'depth':depth,'via':parents.get(name),'pending':counts[name]['pending'],'translated':counts[name]['translated'],'outgoing':sorted(edges[name])})
    result={'start':'MunenVillage','method':'BFS of map connections/warps and literal map-local warp commands','limitations':['Flags, tile access and map-script control flow are not evaluated: this over-approximates reachability.','Common/C-script warps, dynamic warps, fly/teleport and script-label cross references are not fully followed.','Only existing catalog map rows are counted; this is not an extraction or full story-completion test.'], 'maps':ordered,'reachable_map_count':len(ordered),'pending_map_rows':sum(m['pending'] for m in ordered),'translated_map_rows':sum(m['translated'] for m in ordered)}
    (ROOT/'localization/story-map-inventory.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k not in ('maps','limitations')},ensure_ascii=False))
    for item in ordered:
        if item['pending'] and item['depth']<=2:print(item['depth'],item['map'],item['pending'],'via',item['via'])
if __name__=='__main__':main()
