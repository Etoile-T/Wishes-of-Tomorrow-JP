#!/usr/bin/env python3
"""Propose names by constant ID + field, never copy gameplay tables.

Only literal names inside balanced SPECIES/MOVE/ABILITY entries are eligible.
Names defined by shared macros, mismatched variants, unsupported characters and
names exceeding existing encoded-byte budgets remain pending.
"""
import argparse
import collections
import json
import pathlib
import re
import subprocess

import catalog

BASE = '23be896714'
REFERENCE_COMMIT = 'b07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5ef'
ENTRY = re.compile(r'(?m)^\s*\[((?:SPECIES|MOVE|ABILITY|ITEM)_\w+)\]\s*=\s*\{')
FIELD = re.compile(r'\.(speciesName|name)\s*=\s*$')


def fields(text, field_names=('speciesName', 'name')):
    """Return encoded literal names keyed by constant and field/variant."""
    field_pattern = re.compile(r'\.('+'|'.join(re.escape(x) for x in field_names)+r')\s*=\s*$')
    skeleton = catalog.COMMENTS.sub(lambda m: re.sub(r'[^\n]', ' ', m[0]), text)
    literals = list(catalog.MACRO.finditer(catalog.masked(text)))
    result = collections.defaultdict(list)
    for entry in ENTRY.finditer(skeleton):
        begin = entry.end() - 1
        depth = 1
        end = begin + 1
        while end < len(skeleton) and depth:
            depth += (skeleton[end] == '{') - (skeleton[end] == '}')
            end += 1
        if depth:
            raise ValueError('unbalanced entry: ' + entry[1])
        for literal in literals:
            if not begin < literal.start() < end:
                continue
            field = field_pattern.search(text[max(begin, literal.start()-80):literal.start()])
            if not field:
                continue
            value = ''.join(x[1:-1] for x in re.findall(catalog.LITERAL, literal[1]))
            result[(entry[1], field[1])].append(dict(
                source=value, start=literal.start(1), line=text.count('\n', 0, literal.start(1))+1,
                entry_begin=entry.start(), entry_end=end))
    return result


def scoped_name(text):
    # Leave explicit internal ENG/JPN transitions intact; reset after a name so
    # inserting it into an untranslated English message does not change its tail.
    if not text.startswith('{JPN}'):
        text = '{JPN}' + text
    if not text.endswith('{ENG}'):
        text += '{ENG}'
    return text


def encoded_length(text, charmap):
    size = 0
    pos = 0
    while pos < len(text):
        token = re.match(r'\{(?:JPN|ENG|JPN_NAME_(?:[1-9]|10))\}', text[pos:])
        if token:
            size += 2
            pos += len(token[0])
        elif text[pos] in charmap:
            size += 1
            pos += 1
        else:
            raise ValueError('unsupported name character/token: ' + text[pos:pos+12])
    return size


def propose(root, reference):
    actual = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=reference, text=True).strip()
    if actual != REFERENCE_COMMIT:
        raise ValueError('reference commit changed: ' + actual)
    rows = json.loads((root/'localization/catalog.json').read_text())
    by_position = {(r['file'], r['start']): r for r in rows}
    charmap = set(re.findall(r"^'(.)'\s*=", (root/'charmap.txt').read_text(), re.M))
    paths = ['src/data/abilities.h', 'src/data/moves_info.h']
    paths += sorted({r['file'] for r in rows if '/species_info/' in r['file']})
    updates = []
    skipped = []
    counts = collections.Counter()
    for name in paths:
        if not (reference/name).exists():
            skipped.append(dict(file=name, reason='reference_file_absent'))
            continue
        english = subprocess.check_output(['git', 'show', BASE+':'+name], cwd=root, text=True)
        source = fields(english)
        target = fields((reference/name).read_text())
        for key, variants in source.items():
            if key not in target or len(variants) != len(target[key]):
                skipped.append(dict(file=name, target='.'.join(key), reason='missing_or_mismatched_variants'))
                continue
            kind = key[0].split('_')[0].lower()
            # Species names may be copied into the existing 10-byte nickname.
            budget = {'species': 10, 'move': 16, 'ability': 16}[kind]
            for variant, (old, new) in enumerate(zip(variants, target[key])):
                row = by_position.get((name, old['start']))
                if row is None:
                    skipped.append(dict(file=name, target='.'.join(key), reason='not_in_catalog'))
                    continue
                if row['status'] == 'translated':
                    continue
                translation = scoped_name(new['source'])
                reason = None
                if not re.search(r'[ぁ-ゖァ-ヺ]', translation):
                    reason = 'no_japanese_name'
                try:
                    size = encoded_length(translation, charmap)
                    if size > budget:
                        reason = f'encoded_name_exceeds_budget:{size}>{budget}'
                except ValueError as exc:
                    reason = str(exc)
                if reason:
                    skipped.append(dict(id=row['id'], target='.'.join(key), reason=reason))
                    continue
                catalog.validate({**row, 'translation': translation}, charmap)
                updates.append(dict(id=row['id'], translation=translation,
                    target='.'.join(key)+f'[{variant}]',
                    provenance=dict(repository='https://github.com/koziyagoukei/PokeEm-expansion-CanuseJP',
                        commit=REFERENCE_COMMIT, file=name, line=new['line'],
                        method='constant_id_and_field', encoded_bytes=size, byte_budget=budget)))
                counts[kind] += 1
    return updates, dict(reference_commit=REFERENCE_COMMIT, by_kind=dict(counts),
                         proposed=len(updates), skipped=skipped,
                         scope='Names only. Descriptions, mechanics and data structures are not imported.')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--reference', type=pathlib.Path, required=True)
    args = ap.parse_args()
    updates, report = propose(catalog.ROOT, args.reference.resolve())
    (catalog.ROOT/'localization/batches/reference-names-01.json').write_text(json.dumps(updates, ensure_ascii=False, indent=2)+'\n')
    (catalog.ROOT/'localization/reference-names-report.json').write_text(json.dumps(report, ensure_ascii=False, indent=2)+'\n')
    print(json.dumps({k:v for k,v in report.items() if k != 'skipped'}, ensure_ascii=False))


if __name__ == '__main__':
    main()
