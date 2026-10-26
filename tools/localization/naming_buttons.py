#!/usr/bin/env python3
"""Redraw the naming screen BACK/OK button labels in Japanese ("けす"/"おわり").

Glyphs come from graphics/fonts/japanese_small.png (7x7 strokes plus a one-pixel
shadow), which matches the size of the original Latin labels. The English
originals are read from the pinned source snapshot, so the output is reproducible.
Only the label panel is redrawn; the frame, palette and image size are unchanged.
"""
import io, pathlib, re, subprocess
from PIL import Image

ROOT = pathlib.Path(__file__).resolve().parents[2]
BASELINE = '23be896714'
STROKE, SHADOW = 1, 2  # palette indices in japanese_small.png

# name: (label, panel x0..x1 / y0..y1 inclusive, glyph top y, background, stroke, shadow)
BUTTONS = {
    'back_button': ('けす', (8, 32, 4, 12), 5, 0xC, 0x1, 0xD),
    'ok_button': ('おわり', (6, 32, 2, 10), 3, 0xD, 0x1, 0xC),
}

def charmap():
    codes = {}
    for line in (ROOT / 'charmap.txt').read_text().splitlines():
        match = re.match(r"^'(.)'\s*=\s*([0-9A-F]{2})\b", line)
        if match and match.group(1) not in codes:
            codes[match.group(1)] = int(match.group(2), 16)
    return codes

def glyph(font, code):
    """8x8 cell (rows 4..11 of the 8x16 font cell)."""
    x0, y0 = (code % 16) * 8, (code // 16) * 16 + 4
    return [[font.getpixel((x0 + x, y0 + y)) for x in range(8)] for y in range(8)]

def redraw(image, label, box, top, background, stroke, shadow, font, codes):
    x0, x1, y0, y1 = box
    for y in range(y0, y1 + 1):
        for x in range(x0, x1 + 1):
            image.putpixel((x, y), background)
    width = 8 * len(label)
    left = x0 + (x1 - x0 + 1 - width) // 2
    for i, char in enumerate(label):
        for y, row in enumerate(glyph(font, codes[char])):
            for x, value in enumerate(row):
                if value in (STROKE, SHADOW) and top + y <= y1:
                    image.putpixel((left + 8 * i + x, top + y), stroke if value == STROKE else shadow)

def main():
    font = Image.open(ROOT / 'graphics/fonts/japanese_small.png')
    codes = charmap()
    for name, (label, box, top, background, stroke, shadow) in BUTTONS.items():
        path = f'graphics/naming_screen/{name}.png'
        original = subprocess.run(['git', 'show', f'{BASELINE}:{path}'], cwd=ROOT, capture_output=True, check=True).stdout
        image = Image.open(io.BytesIO(original))
        redraw(image, label, box, top, background, stroke, shadow, font, codes)
        image.save(ROOT / path)
        print(path, label)

if __name__ == '__main__':
    main()
