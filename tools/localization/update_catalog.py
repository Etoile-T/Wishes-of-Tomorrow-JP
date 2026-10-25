#!/usr/bin/env python3
"""Apply an ID-keyed translation batch to an already translated checkout.
Checks existing translations and pending source slices before writing anything.
"""
import argparse,copy,json,pathlib
import catalog

def plan(rows, updates, cmap):
    by_id={r['id']:r for r in rows}
    requested={}
    for item in updates:
        key=item['id']
        if key in requested: raise ValueError('duplicate update: '+key)
        if key not in by_id: raise ValueError('unknown ID: '+key)
        requested[key]=item
    changed_files={by_id[key]['file'] for key in requested}
    outputs={}
    for name in changed_files:
        path=(catalog.ROOT/name).resolve()
        if not path.is_relative_to(catalog.ROOT.resolve()): raise ValueError('unsafe path')
        text=path.read_text()
        delta=0; edits=[]
        entries=sorted((r for r in rows if r['file']==name),key=lambda r:r['start'])
        for row in entries:
            current='"'+row['translation']+'"' if row['status']=='translated' else row['raw']
            start=row['start']+delta
            if row['status']=='translated' or row['id'] in requested:
                if text[start:start+len(current)]!=current:
                    raise ValueError(f"{name}:{row['line']}: stale source; no writes performed")
            if row['id'] in requested:
                updated={**row,**requested[row['id']], 'status':'translated'}
                # Batches cannot redirect source location or modify English text.
                for key in ('file','source','raw','start','end','kind'):
                    if updated[key]!=row[key]: raise ValueError('source metadata is immutable: '+key)
                catalog.validate(updated,cmap)
                edits.append((start,len(current),'"'+updated['translation']+'"'))
            delta+=len(current)-len(row['raw'])
        for start,size,replacement in reversed(edits):
            text=text[:start]+replacement+text[start+size:]
        outputs[path]=text
    result=copy.deepcopy(rows)
    for row in result:
        if row['id'] in requested:
            row.update(requested[row['id']]); row['status']='translated'
    return result,outputs

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('batch',type=pathlib.Path); ap.add_argument('--apply',action='store_true')
    args=ap.parse_args()
    path=catalog.ROOT/'localization/catalog.json'
    rows=json.loads(path.read_text()); updates=json.loads(args.batch.read_text())
    cmap=set(catalog.re.findall(r"^'(.)'\s*=",(catalog.ROOT/'charmap.txt').read_text(),catalog.re.M))|{'"',"'",'\\'}
    result,outputs=plan(rows,updates,cmap)
    if args.apply:
        for file,text in outputs.items(): file.write_text(text)
        path.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(dict(updates=len(updates),files=len(outputs),applied=args.apply)))
if __name__=='__main__': main()
