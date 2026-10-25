#!/usr/bin/env python3
"""mGBA debugger frame smoke test; keeps transcripts and state (no Lua required)."""
import argparse, hashlib, pathlib, subprocess
ap = argparse.ArgumentParser()
ap.add_argument('rom', type=pathlib.Path)
ap.add_argument('--frames', type=int, default=600)
ap.add_argument('--log', type=pathlib.Path, required=True)
a = ap.parse_args()
root = pathlib.Path(__file__).resolve().parents[2]
commands = 'frame\n' * a.frames + 'save 1\nstatus\nquit\n'
with a.log.open('w') as out:
    out.write('ROM SHA256: '+hashlib.sha256(a.rom.read_bytes()).hexdigest()+'\n')
    out.write('Requested frames: '+str(a.frames)+'; completion not inferred from request\n')
    out.flush()
    p = subprocess.run([str(root/'tools/mgba/mgba-rom-test-mac'), '-d', str(a.rom.resolve())], input=commands, text=True, stdout=out, stderr=subprocess.STDOUT, timeout=45)
    out.write('\nProcess exit: '+str(p.returncode)+'\n')
print('mGBA exit:', p.returncode, 'requested frames:', a.frames)
raise SystemExit(p.returncode)
