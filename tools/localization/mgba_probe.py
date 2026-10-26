#!/usr/bin/env python3
"""Screenshot a GBA screen without a window, using mgba-headless's command-line debugger.

The bundled ../artifacts/mgba-headless has no Lua, so this drives the debugger over
stdin instead: run until FRAME_SYMBOL has been hit N times (one hit per frame),
optionally "press" keys by writing gMain's key fields at INPUT_SYMBOL, then dump
IO/palette/VRAM/OAM and render mode 0 (text BGs + sprites; no blending/scroll).

usage: mgba_probe.py ROM ELF OUT.png [--frame-symbol S] [--input-symbol S]
                     [--warmup N] [KEY ...]
  KEY is A B SELECT START RIGHT LEFT UP DOWN R L or WAIT; each press is followed
  by 10 idle frames. Run from anywhere; the ROM is copied nowhere (save files go
  next to the ROM, so pass a scratch copy, never a user's ROM).

To reach a screen directly, build a throwaway ROM (never commit it), e.g. call
DoNamingScreen(...) at the top of CB2_InitTitleScreen, then restore the source.
"""
import argparse, pathlib, re, subprocess
from PIL import Image

REPO = pathlib.Path(__file__).resolve().parents[2]
HEADLESS = REPO.parent / 'artifacts' / 'mgba-headless'
NM = '/opt/devkitpro/devkitARM/bin/arm-none-eabi-nm'
KEYS = dict(A=1, B=2, SELECT=4, START=8, RIGHT=16, LEFT=32, UP=64, DOWN=128, R=256, L=512, WAIT=0)
GMAIN_HELD, GMAIN_NEW, GMAIN_REPEAT = 0x2C, 0x2E, 0x30  # struct Main offsets (include/main.h)
OBJ_SIZES = [[(8, 8), (16, 16), (32, 32), (64, 64)], [(16, 8), (32, 8), (32, 16), (64, 32)], [(8, 16), (8, 32), (16, 32), (32, 64)]]

def symbols(elf):
    out = subprocess.run([NM, str(elf)], capture_output=True, text=True, check=True).stdout
    return {parts[2]: int(parts[0], 16) for parts in (line.split() for line in out.splitlines()) if len(parts) == 3}

def commands(sym, args):
    frame, task, gmain = sym[args.frame_symbol], sym[args.input_symbol], sym['gMain']
    cmds = [f'break 0x{frame:x}'] + ['continue'] * args.warmup + ['delete 1', f'break 0x{task:x}']
    for key in args.keys:
        cmds.append('continue')
        if KEYS[key]:
            cmds += [f'w/2 0x{gmain + offset:x} {KEYS[key]}' for offset in (GMAIN_HELD, GMAIN_NEW, GMAIN_REPEAT)]
        cmds += ['continue'] * 10
    cmds += ['delete 1', f'break 0x{frame:x}'] + ['continue'] * 30
    cmds += ['x/2 0x04000000 0x30', 'x/2 0x05000000 0x200', 'x/4 0x06000000 0x6000', 'x/4 0x07000000 0x100', 'quit']
    return '\n'.join(cmds) + '\n'

def parse(dump):
    mem = {}
    for line in dump.splitlines():
        match = re.match(r'0x([0-9A-Fa-f]{8}):\s+(.*)', line)
        if not match:
            continue
        address = int(match.group(1), 16)
        for value in match.group(2).split():
            if not re.fullmatch(r'[0-9A-Fa-f]+', value):
                break
            for i in range(len(value) // 2):
                mem[address + i] = int(value, 16) >> (8 * i) & 0xFF
            address += len(value) // 2
    return mem

def render(mem):
    r8 = lambda a: mem.get(a, 0)
    r16 = lambda a: r8(a) | r8(a + 1) << 8
    def color(i):
        c = r16(0x05000000 + i * 2)
        return ((c & 31) * 8, (c >> 5 & 31) * 8, (c >> 10 & 31) * 8)
    dispcnt = r16(0x04000000)
    image = Image.new('RGB', (240, 160), color(0))
    def draw_bg(cnt):
        chars = 0x06000000 + ((cnt >> 2) & 3) * 0x4000
        screen = 0x06000000 + ((cnt >> 8) & 31) * 0x800
        for ty in range(20):
            for tx in range(30):
                entry = r16(screen + (ty * 32 + tx) * 2)
                tile, hflip, vflip, pal = entry & 0x3FF, entry >> 10 & 1, entry >> 11 & 1, entry >> 12
                for y in range(8):
                    for x in range(8):
                        sx, sy = (7 - x if hflip else x), (7 - y if vflip else y)
                        byte = r8(chars + tile * 32 + sy * 4 + sx // 2)
                        value = byte >> 4 if sx & 1 else byte & 15
                        if value:
                            image.putpixel((tx * 8 + x, ty * 8 + y), color(pal * 16 + value))
    def draw_obj(index):
        a0, a1, a2 = (r16(0x07000000 + index * 8 + k) for k in (0, 2, 4))
        if (a0 >> 8) & 3 == 2 or a0 >> 14 == 3:
            return
        w, h = OBJ_SIZES[a0 >> 14][a1 >> 14]
        y, x = a0 & 255, a1 & 511
        y, x = (y - 256 if y >= 160 else y), (x - 512 if x >= 256 else x)
        for py in range(h):
            for px in range(w):
                sx, sy = (w - 1 - px if a1 >> 12 & 1 else px), (h - 1 - py if a1 >> 13 & 1 else py)
                tile = (a2 & 0x3FF) + (sy // 8) * (w // 8) + sx // 8
                byte = r8(0x06010000 + tile * 32 + (sy % 8) * 4 + (sx % 8) // 2)
                value = byte >> 4 if sx & 1 else byte & 15
                if value and 0 <= x + px < 240 and 0 <= y + py < 160:
                    image.putpixel((x + px, y + py), color(256 + (a2 >> 12) * 16 + value))
    layers = [(r16(0x04000008 + bg * 2) & 3, bg) for bg in range(4) if dispcnt & (1 << (8 + bg))]
    for priority in (3, 2, 1, 0):
        for _, bg in sorted((l for l in layers if l[0] == priority), key=lambda l: -l[1]):
            draw_bg(r16(0x04000008 + bg * 2))
        if dispcnt & 0x1000:
            for index in reversed(range(128)):
                if (r16(0x07000004 + index * 8) >> 10) & 3 == priority:
                    draw_obj(index)
    return image

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('rom', type=pathlib.Path)
    ap.add_argument('elf', type=pathlib.Path)
    ap.add_argument('out', type=pathlib.Path)
    ap.add_argument('--frame-symbol', default='VBlankCB_NamingScreen')
    ap.add_argument('--input-symbol', default='Task_HandleInput')
    ap.add_argument('--warmup', type=int, default=150)
    ap.add_argument('keys', nargs='*', choices=list(KEYS))
    args = ap.parse_args()
    script = commands(symbols(args.elf), args)
    dump = subprocess.run(['perl', '-e', 'alarm 600; exec @ARGV', str(HEADLESS), '-d', str(args.rom.resolve())],
                          input=script, capture_output=True, text=True).stdout
    render(parse(dump)).resize((480, 320), Image.NEAREST).save(args.out)
    print(args.out)

if __name__ == '__main__':
    main()
