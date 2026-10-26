# Imported source provenance

- Repository: https://github.com/jmaloney95/Wishes-Game
- Commit: efb1c880d0b486c1948763051b6c1bb8990a7353
- Source snapshot imported without upstream Git history.
- Original upstream README: [pinned upstream README](https://github.com/jmaloney95/Wishes-Game/blob/efb1c880d0b486c1948763051b6c1bb8990a7353/README.md)
- Existing credits and asset notices are retained in the repository.

The Japanese localization is recorded in subsequent commits. Built game ROMs,
ELF files, build caches and local save files are not tracked. Three upstream
`data/mb_*.gba` files are build-input multiboot assets, retained unchanged because
the source build depends on them; they are not the built Wishes game ROM.

## 英語本文の追加比較（2026-10-27）

Expansionの公開タグ `expansion/1.15.3`（b669d9ccf9c148070b99eba11cd65f6071be0741）を、Git外の `../artifacts/expansion-1.15.3-reference` に取得。Wishesの英語スナップショット23be896714とマップ内ラベルの本文を比較した。`story_content_diff.py` と `localization/story-content-differences.json` を参照。これは全エンジン互換性や到達性の検証ではなく、独自会話の優先順位付けである。本文が同じ元の会話も翻訳対象になり得る。
