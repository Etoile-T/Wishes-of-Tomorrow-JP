#!/usr/bin/env python3
"""Export translated catalog entries as a readable GitHub Markdown table."""
import json
import pathlib
import re
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[2]


def readable(text):
    text = re.sub(r'\{(?:JPN|ENG)\}', '', text)
    text = re.sub(r'\{(?:COLOR|SHADOW|BACKGROUND|TEXT_COLORS) [^}]*\}', '', text)
    text = re.sub(r'\$$', '', text)
    return text.replace(r'\n', '\n').replace(r'\p', '\n［改ページ］\n').replace(r'\l', '\n［スクロール］\n')


def cell(text):
    return readable(text).replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;').replace('|', '&#124;').replace('\n', '<br>')


def main():
    rows = json.loads((ROOT / 'localization/catalog.json').read_text())
    rows = [r for r in rows if r['status'] == 'translated']
    status = json.loads((ROOT / 'localization/status.json').read_text())
    workbook = status.get('review_workbook', 'exports/translated-texts.xlsx')
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip()
    lines = [
        '# 日本語訳一覧', '',
        f'翻訳適用済み {len(rows)}件。表示確認・通しプレイは未完了です。', '',
        f'[Excel版]({workbook})では区分の絞り込みとメモの記入ができます。', '',
        '出典: [同じ版の翻訳カタログ](catalog.json)。',
        '言語切替コードと終端記号は非表示にし、改ページとスクロールは明示しています。', '',
        '| No. | 英語原文 | 日本語訳 | ID・出典 |',
        '| ---: | --- | --- | --- |',
    ]
    for index, row in enumerate(rows, 1):
        source_url = f"https://github.com/Etoile-T/Wishes-of-Tomorrow-JP/blob/23be896714/{row['file']}#L{row['line']}"
        lines.append(f"| {index} | {cell(row['source'])} | {cell(row['translation'])} | `{row['id']}`<br>[{row['file']}:{row['line']}]({source_url}) |")
    out = ROOT / 'localization/translated-texts.md'
    out.write_text('\n'.join(lines) + '\n')
    print(f'Exported {len(rows)} translated entries: {out}')


if __name__ == '__main__':
    main()
