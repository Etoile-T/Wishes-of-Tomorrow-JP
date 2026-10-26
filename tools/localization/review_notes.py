#!/usr/bin/env python3
"""Read saved Excel review notes by stable ID, without modifying the workbook.
Usage: review_notes.py INPUT.xlsx OUTPUT.json
Supports both the old all-in-one and the categorized review workbooks.
"""
import argparse
import json
import pathlib
import zipfile
import xml.etree.ElementTree as ET

NS = {'s': 'http://schemas.openxmlformats.org/spreadsheetml/2006/main'}

def extract(path):
    notes = {'rows': {}, 'terms': {}}
    with zipfile.ZipFile(path) as archive:
        shared = []
        if 'xl/sharedStrings.xml' in archive.namelist():
            shared = [''.join(x.itertext()) for x in ET.fromstring(archive.read('xl/sharedStrings.xml'))]
        for file in archive.namelist():
            if not file.startswith('xl/worksheets/sheet') or not file.endswith('.xml'):
                continue
            headers = {}
            for row in ET.fromstring(archive.read(file)).findall('.//s:sheetData/s:row', NS):
                number = int(row.attrib['r'])
                values = {}
                for cell in row:
                    col = ''.join(c for c in cell.attrib['r'] if c.isalpha())
                    node = cell.find('s:v', NS)
                    value = node.text if node is not None else ''
                    if cell.attrib.get('t') == 's':
                        value = shared[int(value)]
                    elif cell.attrib.get('t') == 'inlineStr':
                        value = ''.join(cell.find('s:is', NS).itertext())
                    values[col] = value or ''
                if number == 7:
                    headers = {v: k for k, v in values.items()}
                elif number > 7 and '確認メモ' in headers:
                    note = values.get(headers['確認メモ'], '')
                    if not note:
                        continue
                    if 'ID' in headers:
                        key = values[headers['ID']]
                        if key in notes['rows'] and notes['rows'][key] != note:
                            raise ValueError('Conflicting notes for ID: ' + key)
                        notes['rows'][key] = note
                    elif '英語' in headers and '日本語' in headers:
                        key = values[headers['英語']] + '\0' + values[headers['日本語']]
                        notes['terms'][key] = note
    return notes

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input', type=pathlib.Path)
    parser.add_argument('output', type=pathlib.Path)
    args = parser.parse_args()
    notes = extract(args.input)
    args.output.write_text(json.dumps(notes, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps({kind: len(values) for kind, values in notes.items()}))

if __name__ == '__main__':
    main()
