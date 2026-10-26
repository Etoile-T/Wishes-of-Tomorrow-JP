#!/usr/bin/env python3
"""Extract encoded C/event strings; validate and reinsert reviewed translations.
JSON and .party strings are inventoried separately for manual schema review.
Offsets are Unicode character offsets. Apply validates every source before writing.
"""
import argparse, collections, hashlib, json, pathlib, re
ROOT = pathlib.Path(__file__).resolve().parents[2]
LITERAL = r'"(?:\\.|[^"\\])*"'
MACRO = re.compile(r'\b(?:_|COMPOUND_STRING|COMPOUND_STRING_SIZE_LIMIT|ITEM_NAME|ITEM_PLURAL_NAME)\s*\(\s*(' + LITERAL + r'(?:\s*' + LITERAL + r')*)(?:\s*,\s*[A-Za-z_0-9 +\-]+)?\s*\)')
SCRIPT = re.compile(r'(?m)^\s*\.(?:string|braille)\s+(' + LITERAL + r')')
COMMENTS = re.compile(r'//[^\n]*|/\*[\s\S]*?\*/|' + LITERAL)
TOKENS = re.compile(r'\{[^{}]*\}|\\(?:[nplr]|x[0-9a-fA-F]{2}|[0-7]{1,3})|\$')

def masked(text):
    return COMMENTS.sub(lambda m: m[0] if m[0].startswith('"') else re.sub(r'[^\n]', ' ', m[0]), text)

def extract():
    rows = []
    for base in ('src', 'data', 'include'):
        for path in sorted((ROOT / base).rglob('*')):
            if path.suffix not in ('.c', '.h', '.inc') or not path.is_file():
                continue
            text = path.read_text(encoding='utf-8')
            search = masked(text) if path.suffix in ('.c', '.h') else text
            pattern = SCRIPT if path.suffix == '.inc' else MACRO
            for match in pattern.finditer(search):
                start, end = match.span(1)
                raw = text[start:end]
                source = ''.join(x[1:-1] for x in re.findall(LITERAL, raw))
                rel = path.relative_to(ROOT).as_posix()
                digest = hashlib.sha256((rel + '\0' + str(start) + '\0' + source).encode()).hexdigest()[:16]
                rows.append(dict(id=digest, file=rel, line=text.count('\n', 0, start)+1,
                                 start=start, end=end, raw=raw, source=source,
                                 translation='', status='pending', kind='script' if path.suffix == '.inc' else 'encoded_c'))
    return rows

def protected(text):
    # {PKMN}/{POKEBLOCK} are Latin logo glyphs, so a translation may spell them out.
    return collections.Counter(t for t in TOKENS.findall(text) if t not in ('{JPN}', '{ENG}', r'\n', '{PKMN}', '{POKEBLOCK}') and not re.fullmatch(r'\{JPN_NAME_(?:[1-9]|10)\}', t))

def validate(row, cmap):
    source, target = row['source'], row['translation']
    if protected(source) != protected(target):
        raise ValueError(f"{row['id']}: control/placeholder mismatch")
    if '"' in target.replace('\\"', '') or '\n' in target or '\r' in target:
        raise ValueError(f"{row['id']}: use escaped quotes/newlines")
    for span in re.finditer(r'\{JPN_NAME_([1-9]|10)\}', target):
        glyphs = target[span.end():span.end() + int(span[1])]
        if len(glyphs) != int(span[1]) or any(c in '{}\\$' for c in glyphs):
            raise ValueError(f"{row['id']}: incomplete Japanese name span")
    plain = TOKENS.sub('', target)
    plain = re.sub(r'\\.', '', plain)
    missing = sorted(set(plain) - cmap)
    if missing:
        raise ValueError(f"{row['id']}: unmapped characters: {missing}")
    misrendered = sorted(set(japanese_mode_text(target)) & JAPANESE_MODE_MISRENDERED)
    if misrendered:
        raise ValueError(f"{row['id']}: Latin punctuation renders differently in Japanese mode: {misrendered}")

# These Latin bytes are 円 . 『 』 「 」 in the Japanese font; use 円 or {ENG}.
JAPANESE_MODE_MISRENDERED = frozenset('¥,“”‘’\'')

def japanese_mode_text(text):
    japanese, parts = False, []
    remaining, previous = 0, False
    for token in re.findall(r'\{[^{}]*\}|\\.|.', text, re.S):
        if token in ('{JPN}', '{ENG}'):
            japanese = token == '{JPN}'
        elif re.fullmatch(r'\{JPN_NAME_(?:[1-9]|10)\}', token):
            previous, japanese = japanese, True
            remaining = int(token[10:-1])
        elif len(token) == 1:
            if japanese:
                parts.append(token)
            if remaining:
                remaining -= 1
                if remaining == 0:
                    japanese = previous
    return ''.join(parts)

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('command', choices=['extract', 'stats', 'validate', 'apply'])
    ap.add_argument('--catalog', type=pathlib.Path, default=ROOT/'localization/catalog.json')
    args = ap.parse_args()
    if args.command == 'extract':
        rows = extract()
        args.catalog.write_text(json.dumps(rows, ensure_ascii=False, indent=2)+'\n')
    else:
        rows = json.loads(args.catalog.read_text())
    if args.command in ('validate', 'apply'):
        cmap = set(re.findall(r"^'(.)'\s*=", (ROOT/'charmap.txt').read_text(), re.M)) | {'"', "'", '\\'}
        changes = collections.defaultdict(list)
        for row in rows:
            if row['status'] != 'translated':
                continue
            validate(row, cmap)
            changes[row['file']].append(row)
        outputs = {}
        for name, entries in changes.items():
            path = ROOT/name
            text = path.read_text()
            ordered = sorted(entries, key=lambda x:x['start'])
            original = all(text[r['start']+r.get('code_offset',0):r['end']+r.get('code_offset',0)] == r['raw'] for r in ordered)
            if not original:
                delta = 0
                for row in ordered:
                    replacement = '"' + row['translation'] + '"'
                    start = row['start'] + row.get('code_offset',0) + delta
                    if text[start:start + len(replacement)] != replacement:
                        raise ValueError(f"{name}:{row['line']}: stale source; no writes performed")
                    delta += len(replacement) - len(row['raw'])
                continue  # Already applied and verified; idempotent.
            for row in reversed(ordered):
                shift = row.get('code_offset',0)
                text = text[:row['start']+shift] + '"' + row['translation'] + '"' + text[row['end']+shift:]
            outputs[path] = text
        if args.command == 'apply':
            for path, text in outputs.items():
                path.write_text(text)
    print(json.dumps(dict(total=len(rows), statuses=dict(collections.Counter(r['status'] for r in rows))), ensure_ascii=False))

if __name__ == '__main__':
    main()
