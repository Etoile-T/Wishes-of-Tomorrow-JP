#!/usr/bin/env python3
"""Align item descriptions by constant/shared symbol; enforce text/numeric budgets.

No gameplay fields are copied. Proposals with missing references, unsupported
tokens, lost numeric values or more than three 13-cell lines remain pending.
"""
import collections
import json
import re
import subprocess

import catalog
import reference_names


def shared(text):
    result = collections.defaultdict(list)
    for match in catalog.MACRO.finditer(catalog.masked(text)):
        prefix = re.search(r'\b(\w+)\s*\[\s*\]\s*=\s*$', text[max(0, match.start()-120):match.start()])
        if prefix:
            result[(prefix[1], 'shared')].append(dict(start=match.start(1),
                source=''.join(s[1:-1] for s in re.findall(catalog.LITERAL, match[1])),
                line=text.count('\n', 0, match.start(1))+1))
    return result


def wrap(text, columns=13, lines=3):
    # Existing breaks are preserved when they fit. Languages remain explicit.
    text = text.strip()
    def token_width(token):
        if token in ('{JPN}', '{ENG}'):
            return 0
        if token.startswith('{'):
            if token not in ('{PKMN}', '{POKEBLOCK}'):
                raise ValueError('unknown_rendered_token_width: '+token)
            return {'{PKMN}': 2, '{POKEBLOCK}': 5}[token]
        return 1
    def width(part):
        return sum(token_width(t) for t in re.findall(r'\{[^{}]*\}|.', part))
    original = text.split(r'\n')
    if len(original) <= lines and all(width(s) <= columns for s in original):
        return text
    plain = text.replace(r'\n', ' ')
    # Reflow whole words first; Japanese without spaces may wrap between glyphs.
    for compact in (False, True):
        candidate = plain.replace(' ', '') if compact else plain
        parts=[]; current=''; used=0
        for token in re.findall(r'\{[^{}]*\}|.', candidate):
            w = token_width(token)
            if used+w > columns:
                parts.append(current.rstrip()); current=''; used=0
            if token == ' ' and used == 0:
                continue
            current += token; used += w
        if current:
            parts.append(current.rstrip())
        if len(parts) <= lines:
            return r'\n'.join(parts)
    raise ValueError('description_exceeds_13x3')


def main():
    root = catalog.ROOT
    name = 'src/data/items.h'
    english = subprocess.check_output(['git', 'show', '23be896714:'+name], cwd=root, text=True)
    reference = (root.parent/'reference-jp'/name).read_text()
    source = dict(reference_names.fields(english, ('description',)))
    source.update(shared(english))
    target = dict(reference_names.fields(reference, ('description',)))
    target.update(shared(reference))
    rows = json.loads((root/'localization/catalog.json').read_text())
    by_pos = {(r['file'],r['start']):r for r in rows}
    cmap = set(re.findall(r"^'(.)'\s*=", (root/'charmap.txt').read_text(), re.M))
    batch=[]; skipped=[]
    for key, entries in source.items():
        if len(target.get(key, [])) != len(entries):
            skipped.append(dict(target='.'.join(key), reason='missing_or_mismatched_variants'))
            continue
        for variant, (old, new) in enumerate(zip(entries,target[key])):
            row = by_pos.get((name,old['start']))
            if row is None or row['status']=='translated':
                continue
            try:
                if not re.search(r'[ぁ-ゖァ-ヺ]',new['source']):
                    raise ValueError('not_japanese')
                source_numbers=set(re.findall(r'\d+',old['source']))
                target_numbers=set(re.findall(r'\d+',new['source']))
                if not source_numbers.issubset(target_numbers):
                    raise ValueError('numeric_values_changed')
                text=reference_names.scoped_name(wrap(new['source']))
                catalog.validate({**row,'translation':text},cmap)
            except ValueError as exc:
                skipped.append(dict(id=row['id'],target='.'.join(key),source=old['source'],candidate=new['source'],reason=str(exc)))
                continue
            batch.append(dict(id=row['id'],translation=text,target='.'.join(key)+f'[{variant}]',
                provenance=dict(reference_commit=reference_names.REFERENCE_COMMIT,method='constant/shared-symbol alignment, numeric and glyph guards',reference_line=new['line'],columns=13,max_lines=3)))
    (root/'localization/batches/item-descriptions-01.json').write_text(json.dumps(batch,ensure_ascii=False,indent=2)+'\n')
    (root/'localization/item-descriptions-report.json').write_text(json.dumps(dict(proposed=len(batch),skipped=skipped),ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(dict(proposed=len(batch),skipped=len(skipped),reasons=dict(collections.Counter(x['reason'] for x in skipped)))))


if __name__=='__main__':
    main()
