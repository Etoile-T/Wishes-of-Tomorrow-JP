# Japanese localization workflow

**Start here:** read `HANDOFF_CODEX.md` (current state, user instructions,
step-by-step dialogue and release workflow) before doing anything else.

## Scope and current state

This is a source-based localization of Wishes of Tomorrow. Read
`localization/README.ja.md` and `localization/status.json` before continuing.
A successful build is not evidence of successful gameplay. Never describe this
work as complete until all text, graphics, UI and gameplay checks are finished.

## Translation and yomiyasu

The user requested yomiyasu for this project. Use
`.agents/skills/yomiyasu/SKILL.md` when reviewing newly generated Japanese
translations. Read the script/essay guidance for narrative text. The skill is
vendored with its MIT/Unicode notices and pinned in `localization/yomiyasu.lock.json`.

- Preserve English meaning, uncertainty, speaker voice, deliberate repetition,
  jokes, fantasy metaphors, and the order of events.
- Game dialogue uses sentence-final `。` as part of the established typography.
  Keep it where natural; do not remove it solely to satisfy dialogue_period.
- Menus and quest objectives need a separate review from character dialogue.
- Preserve placeholders and non-layout controls. Keep dialogue boxes and page
  transitions in the same order. Do not replace game tokens with Japanese prose.
- Rendered Japanese/English mode must be explicit with `{JPN}` and `{ENG}`.
- yomiyasu candidates are review suggestions, not automatic edits or evidence
  that a translation is semantically correct. Record decisions and verify the
  final review text. Do not claim unperformed reviews or human approval.
- The skill does not implement fonts, machine translation, wrapping or emulation.

## Applying changes

Do not overwrite `localization/catalog.json` with a fresh extraction.
Use ID-keyed batches and `tools/localization/update_catalog.py` for incremental
changes. The original catalog offsets refer to the pinned English snapshot.

```sh
python3 tools/localization/update_catalog.py localization/batches/BATCH.json
python3 tools/localization/update_catalog.py localization/batches/BATCH.json --apply
python3 tools/localization/catalog.py validate
python3 tools/localization/audit.py
python3 -m unittest discover -s tools/localization -p 'test_*.py' -v
make -j8 FILE_NAME=pokeemerald-jp-VERSION OBJ_DIR=build/emerald-jp-VERSION-clean TOOLCHAIN=/opt/devkitpro/devkitARM
```

The default update command is a dry run. Validate all slices before writing.
Do not change game logic, save layouts, species IDs or event flags to simplify
translation. Audit fixed-length strings before adding language-control bytes.
Unsupported glyphs must not enter the ROM.

## Git and artifacts

`origin` is Etoile-T/Wishes-of-Tomorrow-JP; `upstream` is jmaloney95/Wishes-Game.
Keep source, catalogs, tools and accurate progress records in Git. Keep built
game ROMs, ELF files, save data, local emulator states and check caches out of Git.
The upstream `data/mb_*.gba` build inputs remain tracked as documented in
`docs/UPSTREAM_SOURCE.md`. A patch must name its exact English source checksum.

## Play ROM exports

Never overwrite a ROM that the user may have open. Keep pokeemerald.gba and
artifacts/wishes-jp-wip.gba as build/legacy outputs only. Export playable builds
with tools/localization/export_play_rom.py to artifacts/play; its hash-named
outputs are immutable. Do not copy or overwrite save RAM or emulator states.
A new ROM needs a cold load; a state from another build is not regression proof.

## Fresh build objects

Use a new OBJ_DIR as well as a new FILE_NAME for each release. On 2026-10-26,
the existing build/emerald cache and a fresh build produced different RAM/ROM
usage from the same source; the fresh build matched the expected layout. Do not
release the existing cache result. Keep old ROMs and saves untouched.
