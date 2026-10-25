# Codex 引き継ぎ — Wishes of Tomorrow 日本語化

更新: 2026-10-26（日本時間）。Claude Code から Codex への引き継ぎ。
最初に `AGENTS.md`、この文書、`localization/status.json` を読むこと。過去の経緯の詳細は `HANDOFF_CLAUDE_CODE.md`（長い）にある。
**完全日本語化は未完了。調査で終わらず、既存の訳と仕組みを保ったまま翻訳・検証・成果物の出力を続ける。**

## 1. いまの状態

| 項目 | 値 |
| --- | --- |
| 作業場所 | `/Users/owner/Desktop/Wish/Wishes-Game`（git、ブランチ main、origin=Etoile-T/Wishes-of-Tomorrow-JP） |
| 最新の翻訳コミット | `50f0c034587667dc2464bf96591d86d6993d4a68`（この後に docs のコミットがある。`git log -5 --oneline` で確認） |
| カタログ | 61,722候補のうち翻訳済み 9,687、pending 52,035（未使用・重複・記号を含む。完成率ではない） |
| カタログ外 | トレーナー名（`src/data/trainers.party`、約500種）とマップ名（`region_map_sections.json`、229件）は翻訳済み |
| テスト | `python3 -m unittest discover -s tools/localization -p 'test_*.py'` で41件成功 |
| 最新ビルド | `pokeemerald-jp-dlg9687.gba`（ROM 29,874,216B / EWRAM 230,024B / IWRAM 28,600B） |
| ユーザー向けGBA | `/Users/owner/Desktop/Wish/outputs/gba/wishes-jp-9687-03f7d392.gba`（README.txt あり） |
| 配布パッチ | `../artifacts/wishes-jp-ui9687-03f7d392-patch.zip`、追跡用 `localization/patch-manifest-ui9687.json` |
| Excel | `/Users/owner/Desktop/Wish/outputs/translation-review-20261026/Wishes_日本語訳一覧.xlsx`（Git内コピー `localization/exports/translated-texts.xlsx`、10,394行） |

ゲーム画面での表示・進行の確認は、ほぼ未実施。ビルド成功を「正常に遊べる」とは報告しない。

## 2. ユーザーの指示（守ること）

- ゲーム内容・独自機能・セーブ形式を変えずに、ストーリーから独自UIまで完全日本語化する。
- GitHub（origin）への commit / push は許可済み。ROM・セーブはGitに入れない。
- **作業の区切りごとにGBAを `../outputs/gba/` へ版名付きで出力**し、README.txt の「最新」を更新する。既存ファイルは上書きしない（`cp -n`、読み取り専用にする）。
- ユーザーは `outputs/gba/` で版ごとの `.sav` を使ってプレイしている。**セーブやステートをコピー・移動・削除しない**（新しい版で続けるには名前を合わせてコピーする必要がある、と案内だけする）。
- 訳はExcel／表で確認できるようにし、区切りごとに更新する。
- 訳文の見直しには yomiyasu を使う（`.agents/skills/yomiyasu/`、導入済み）。
- 長いmGBA確認は延期。別ディスプレイのウィンドウを勝手に動かさない。
- クエストにっし後のグラフィック不具合は「エミュレータのバグ」とユーザーが確認済み。調査を再開しない。
- ユーザーへの返答は日本語。

## 3. 残りの作業（優先順）

ユーザーは「セリフ系」→「戦闘メッセージ」→「トレーナー名・マップ名」→「ストーリーの続き」の順に依頼してきた。今は**ストーリーの会話を、プレイ順に独自マップから**進めている。

1. 独自マップの残り（約800行）: RebelHideout 177、TradewindTown 180（＋TradewindLab 21 / TradewindGym 16 / TradewindHouse 7 / TradewindApartment_2 8）、CelebiIsland 114、UndergroundArena 102、DistortionWorld 系 131、PrototypeIsland 21 / PrototypeLab 47、DragonKeeper 34、MewtwoPostGame 29。件数は `dialogue_tools.py dump` で確認。
2. 勝敗時のトレーナーの台詞は、各マップの `scripts.inc` にある（独自マップ分は訳済み）。
3. `src/strings.c` の残り（約500件）: easy_chat 70、frontier_util 46、mystery_gift_menu 44、図鑑 33+、frontier_pass 31 など。外部参照のない約80件は未使用の可能性が高い。
4. 図鑑本文（species_info の description）、技の説明、残りの名称。
5. 元のホウエン／カントーの会話（`data/maps/` の元マップ、`data/text/*.inc`）。Wishes から到達する範囲は不明確で、量が多い（数万行）。
6. 道具・特性の説明の意味レビュー（参考フォークからの取り込みで、全件の意味確認は未了）。
7. 漢字、名前入力キーボード、画像内の文字、通しプレイ。

## 4. 会話を訳す手順（いつもの流れ）

すべてリポジトリのルートで実行する（`dialogue_tools.py` だけは `tools/localization` から実行する）。

```sh
cd tools/localization
python3 dialogue_tools.py dump data/maps/RebelHideout/scripts.inc > /tmp/src.txt   # 未訳の行を ID<TAB>原文 で出す
python3 dialogue_tools.py lookup Pikachu "Escape Rope"                              # 既訳の名前を引く
cd ../..
# /tmp/src.txt を写して、各行の原文を日本語に置き換えた DRAFT.txt を作る（{JPN}/{ENG} は書かない）
python3 tools/localization/script_batch.py DRAFT.txt localization/batches/dialogue-NAME-NN.json
cd tools/localization && python3 dialogue_tools.py check ../../localization/batches/dialogue-NAME-NN.json \
  && python3 dialogue_tools.py width ../../localization/batches/dialogue-NAME-NN.json && cd ../..
python3 tools/localization/update_catalog.py localization/batches/dialogue-NAME-NN.json --apply
python3 tools/localization/catalog.py validate
```

`script_batch.py` の動き:
- `.string` は1行ずつカタログに入るが、ROMでは `$` までが1つの台詞として続く。台詞の先頭に `{JPN}` を付け、`{PLAYER}` `{STR_VAR_n}` `{REGION}` `{B_*}` `{PKMN}` などを `{ENG}…{JPN}` で囲む。`#if`/`#else` の直後の行にも `{JPN}` を付ける。
- **台詞の一部の行だけを訳すことは拒否する**（残りの英語がJPNモードで表示されてしまうため）。
- C文字列（`src/*.c` の `_("…")` / `COMPOUND_STRING`）は1項目が1メッセージで、末尾に `{ENG}` を付ける（他の文に差し込まれる部品にもなるため）。
- 既訳の行は受け付けない。既訳を直すときは、`{"id","translation","provenance"}` の小さなJSONを作って `update_catalog.py --apply` する（バッチファイル側も同じ値に直しておく）。

検査で落ちる典型と直し方:
- `control/placeholder mismatch`: その行の `\p` `\l` `$` と変数が原文の行と違う。**`\l` `\p` は保護対象なので増やせない**。`\n` だけは増減してよい。変数は原文と同じ行に置く。
- `unmapped characters`: 漢字や全角英数（ＰＰ）、「～」など。かなと、charmap にある記号だけを使う。
- 幅: 会話の枠は27マス（216px、日本語1文字8px）。`width` は変数を長めに見積もって26マス超を出す。はみ出す行は短くするか `\n` を入れる（2行の枠を超えないこと）。

## 5. 日本語表示の決まり（間違えやすい）

- JPN区間では、ラテン文字の `¥`→「円」、`,`→「.」、`“ ” ‘ ’ '`→『』「」として描かれる。`catalog.validate` がこれらを拒否する。金額は `{ENG}{STR_VAR_1}{JPN}円` や `10000円`、桁区切りの `,` は使わない。引用は「」（charmap に別名あり）。
- JPN区間でも英字・数字・`! ? : /` は同じ字形。ただし**英字も8px幅**になる（RedFatality などで行が長くなる）。`.` は「。」、`-` は「ー」と同じバイト。
- `…` は日本語フォントで「‥」になる。そのまま `…` を使う。
- `{PKMN}` `{POKEBLOCK}` はロゴ文字なので、日本語では「ポケモン」と書いて省いてよい（validator は許可）。残すなら `{ENG}` で囲む。
- 話者は既訳に合わせて「名前: 本文」。電話でも『』は使わない。
- プレイヤーの性別を決めつけない（kid→「ぼうず」にしない）。性別の分からないNPCに「ぼく」「〜ぜ」を付けない。原文が he/she で示す人物は従う（リョウコ＝男性の弟子、よげんしゃ＝女性、ミクマンク＝男性）。
- 口調は原文を保つ（罵り言葉、老人の「〜じゃ」、軍人口調など）。yomiyasu の候補を消すために台詞を削らない。
- 固有名詞は `localization/glossary.json` を先に見る。新しいものは `status: provisional` で追加する。ポケモン・道具・技は `dialogue_tools.py lookup`。

## 6. 固定長と特殊な仕組み

| 対象 | 制限 | 備考 |
| --- | --- | --- |
| 種族名 | 10バイト（JPN/ENG各2バイト込み） | かな6文字まで |
| 技・特性名 | 16バイト | |
| トレーナー名 | 12バイト＋EOS（`trainerName[13]`） | `trainers.party` の `Name:` を直接編集。対訳は `localization/trainer-names.json` |
| 肩書き | 13バイト＋EOS（`name[14]`） | カタログの `src/battle_main.c` |
| マップ名 | 16バイト | `region_map_sections.json` の `name` を直接編集。対訳は `localization/map-names.json` |
| 話者名 | 12マス | `src/data/speaker_names.h` |

- 戦闘文の自動改行 `BreakStringAutomatic`（`src/line_break.c`）は、JPN/ENG を考慮して幅を測るように直してある。日本語の戦闘文は**空白で文節を区切る**こと（区切りがないと改行できない）。
- 道具の複数形: `src/item.c` は名前が `{JPN}` で始まれば英語の「s」を付けない。
- Cコードを編集してカタログ項目の位置がずれる場合は `code_offset` が必要（現在 naming_screen.c に +98）。項目より後ろに挿入しないよう注意する。

## 7. 区切りごとの成果物（毎回の手順）

```sh
python3 -m unittest discover -s tools/localization -p 'test_*.py'
make -j8 FILE_NAME=pokeemerald-jp-dlgNNNN TOOLCHAIN=/opt/devkitpro/devkitARM > ../artifacts/build-dlgNNNN.log 2>&1
# yomiyasu（会話は --doc-type script、UIは manual）。資料・下書き・最終稿を localization/reviews/ に保存し、
# lint → run → verify。verify の出力行と判断を NAME.review.md に書く（既存のレビューを手本に）。
git add ... && git commit -m "feat: ..."         # 翻訳コミット（コミットメッセージは英語の conventional commits）
python3 tools/localization/export_play_rom.py pokeemerald-jp-dlgNNNN.gba ../artifacts/play
python3 tools/localization/make_release.py <翻訳コミット> <翻訳件数> ../artifacts/play/wishes-jp-<hash>.gba
python3 tools/localization/apply_verified_patch.py ../artifacts/wishes-en-baseline.gba \
  ../artifacts/patches/ui-<件数>-<crc>/<bps> ../artifacts/patches/ui-<件数>-<crc>/manifest.json /tmp/verify
cmp /tmp/verify/*.gba ../artifacts/play/wishes-jp-<hash>.gba
cp -n ../artifacts/play/wishes-jp-<hash>.gba ../outputs/gba/wishes-jp-<件数>-<crc>.gba && chmod a-w 同ファイル
# ../outputs/gba/README.txt の「最新」と「以前の版」を更新（存在するファイルだけ列挙）
python3 tools/localization/ui_inventory.py && python3 tools/localization/export_table.py
# Excel: ../artifacts/translation-review-build で node build_review.mjs、生成後に Git 内へコピー
cp ../outputs/translation-review-20261026/Wishes_日本語訳一覧.xlsx localization/exports/translated-texts.xlsx
# localization/status.json と HANDOFF_CODEX.md の数値・最新成果物を更新し、docs コミットして push
```

- Excel生成は `../artifacts/translation-review-build/build_review.mjs`（Git内の `tools/localization/export_review.mjs` と同じ内容に保つ）。依存は Codex キャッシュの `@oai/artifact-tool`（node_modules はシンボリックリンク済み）。トレーナー名・マップ名のJSONからも行を作る。ユーザーのメモ欄は自動では引き継がないので、編集済みのExcelがあれば先にIDで退避する。
- `patch_crc32` が毎回 `2144df1c` になるのは、自身のCRCを末尾に持つBPSの性質。異常ではない。

## 8. やってはいけないこと

- `catalog.json` を再抽出で上書きしない（`catalog.py extract` を実行しない）。
- `seed_*.py`、`ui_common.py`、`ui_messages.py` など当時のバッチ生成スクリプトを再実行しない（適用済みバッチを上書きしうる）。
- `git stash` でカタログだけ退避しない（ソースと不一致になる。過去に一度起き、すぐ戻した）。
- 読み込み中かもしれないROMを上書きしない。ビルドは毎回新しい `FILE_NAME` で行う。
- 市販Emeraldや公式1.2.6のROMにパッチを当てない（BPSは32MiBの英語Wishes基準ROM用）。
- 完了していない作業を完了と報告しない。外部の翻訳APIは使っていない（すべて手作業の訳と検証ツール）。
