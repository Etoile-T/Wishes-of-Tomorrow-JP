# Codex 引き継ぎ — Wishes of Tomorrow 日本語化

更新: 2026-10-26（日本時間）。Claude Code から Codex への引き継ぎ。
最初に `AGENTS.md`、この文書、`localization/status.json` を読むこと。過去の経緯の詳細は `HANDOFF_CLAUDE_CODE.md`（長い）にある。
**完全日本語化は未完了。調査で終わらず、既存の訳と仕組みを保ったまま翻訳・検証・成果物の出力を続ける。**

## 1. いまの状態

| 項目 | 値 |
| --- | --- |
| 作業場所 | `/Users/owner/Desktop/Wish/Wishes-Game`（git、ブランチ main、origin=Etoile-T/Wishes-of-Tomorrow-JP） |
| 最新の翻訳コミット | `bfdc0ef0261335888a31a8c9e9e4c83827009842`（この後に docs のコミットがある。`git log -5 --oneline` で確認） |
| カタログ | 61,722候補のうち翻訳済み 10,616、pending 51,106（未使用・重複・記号を含む。完成率ではない） |
| カタログ外 | トレーナー名（`src/data/trainers.party`、約500種）とマップ名（`region_map_sections.json`、229件）は翻訳済み |
| テスト | `python3 -m unittest discover -s tools/localization -p 'test_*.py'` で57件成功 |
| 最新ビルド | `pokeemerald-jp-names10616-final.gba`（ROM 29,871,720B / EWRAM 230,024B / IWRAM 28,600B） |
| ユーザー向けGBA | `/Users/owner/Desktop/Wish/outputs/gba/wishes-jp-10616-68a7f93e.gba`（README.txt 更新済み。ユーザーはkana1版・10511版の.savを持っている） |
| 配布パッチ | `../artifacts/wishes-jp-ui10616-68a7f93e-patch.zip`、追跡用 `localization/patch-manifest-ui10616.json` |
| Excel | `/Users/owner/Desktop/Wish/outputs/translation-all-10616/Wishes_全テキスト翻訳一覧.xlsx`（Git内コピー `localization/exports/all-texts-10616.xlsx`、62,429行：全61,722候補＋名称707件） |

ゲーム画面での表示・進行の確認は、ほぼ未実施。ビルド成功を「正常に遊べる」とは報告しない。

今回（種族名42件）の開始時: statusとcatalog statsは61,722 / 10,574 / 51,148で一致。mainの最新da1c0eeb55、作業ツリーはクリーン。

今回の追加: 独自メガ19件と通常／共通定義22件、アーマードミュウツー1件の計42件。カタログ内の未翻訳リテラルspeciesNameは0件（図鑑分類・説明やカタログ外の完全網羅を意味しない）。バッチ39/40、レビュー `localization/reviews/species-names-39-40.review.md`、棚卸し `localization/species-name-audit-39.json`。yomiyasu検証済み、アンノーンへのmetaphor_label指摘は固有名詞として維持。種族データ9ファイルの文字列以外の内容は不変。

ユーザーの選択に従い「アーマードミュウツー」を省略せず表示するため、既存の長さ指定日本語制御をJPN_NAME_1〜10へ拡張。入力上限は引き続き日本語5文字、セーブ構造は変更していない。既存12バイトの種族名／ニックネーム経路を使う。旧デフォルト名Armor Mewtwoは種族と12バイトが一致する場合のみ表示バッファで置換し、保存データは書き換えない。古い10バイト限定経路は8かなまでとなり、制御コードの長さを補正して後続の言語漏れを防ぐ。戦闘名欄は日本語FONT_SMALL_NARROWERのみ5pxへ縮小、長い種族名の名前入力見出しは既存の小さいフォントへ切替。**縮小字形の可読性・戦闘・保存・通信等は未実機検証。** エンジンのC文字列位置は元IDを維持してcode_offset補正済み。旧値へ戻さない。

今回の検証: catalog validate成功、audit推定超過0、57テスト成功。新規OBJ_DIR=build/emerald-jp10616-cleanでビルド。ログ `../artifacts/build-names10616-final.log`、ROM29,871,720B / EWRAM230,024B / IWRAM28,600B。SHA256 `baf29ca44ceeeed004dbb40e5a291a716f10fe676104057489e0c82627822c09`、CRC68a7f93e。BPSのSHA/CRC検査付き再適用結果はバイト一致（`../artifacts/logs/verify-10616.log`）。元ROMは32MiB・CRC62ba561eのソースビルド英語版。公式1.2.6 BPSやクリーンEmeraldとは別物。

今回のExcel: 全62,429行、カタログ61,722件＋別管理名称707件。カタログ翻訳済み10,616、未翻訳51,106。保存後の全行11列とエクスポートデータ、カタログID・生原文・生訳・状態を照合して一致（`../artifacts/logs/excel-all-10616-verify.log`）。従来の分類誤りも修正し、未翻訳の図鑑分類・説明を「ポケモン名」と表示しない。プレビュー確認済み、実Excelアプリは未確認。旧Excel・ROM・セーブは維持。

以下の10574版の記録は直前の会話翻訳の履歴。

今回の開始時: statusとcatalog statsは61,722 / 10,511 / 51,211で一致。mainの最新34301241c8、作業ツリーはクリーン。Claude Codeのkana3実装を確認して維持。旧全件Excel2ファイルの保存済みメモは0件。既存ROM・セーブ・Excelは変更していない。

今回の追加: DragonKeeper 34、MewtwoPostGame 29、計63件。両マップのpendingは0、会話以外のスクリプトは翻訳前と同一。レビューは `localization/reviews/dialogue-dragon-mewtwo-38.review.md`。残りタマゴの説明に加えていた推量と、鎧の説明に加えていた命令を原文どおりへ修正。yomiyasuのmeaning_risk=1は推量除去の指摘で、原文を照合して判断を記録した。

検証: check bad 0、width26マス超0、catalog validate成功、audit推定超過0、51テスト成功。**既存build/emeraldからのビルドはメモリ使用量が従来と異なったため不採用。新しいOBJ_DIR=build/emerald-jp10574-cleanで全再ビルドした版を採用した。次回も新しいOBJ_DIRで作ること。** ログは `../artifacts/build-dlg10574-clean.log`。ROM29,871,208B / EWRAM230,024B / IWRAM28,600B。SHA256 `544ab4a7efd3613035a8247ea3c32ed9cb4f994e6e98fc5aee1138f2fd88062c`。BPSをSHA/CRC検査付きで再適用しバイト一致。ログは `../artifacts/logs/verify-10574-clean.log`。一度作った既存キャッシュ由来の暫定BPS（CRC44ed807f）は不採用、ユーザー向けROMには出していない。

全件Excel: 62,429行（全61,722候補＋別管理名称707）。適用済み10,574、未翻訳51,148。K列が状態、F列がID、I/J列が制御付き訳／原文。全行のID・順番・原文・訳文・状態と91用語を保存後に照合し一致、プレビュー確認済み。`../artifacts/logs/excel-all-10574-verify.log`。実アプリExcelや新しい会話・進行の実機確認は未実施。

マップ棚卸し: `localization/custom-map-audit.json`。ローカルreference-jpにないフォルダ347件を比較するヒューリスティック。残る8,941候補はすべて*_Frlgマップ。非FRLGの比較対象フォルダではpending 0。ただし参照元の版差・元Emeraldフォルダ流用の独自会話・カタログ外・到達性は判定していない。独自テキストの完全網羅や完成の証拠にはしない。

名前入力（kana3、表示修正）: コミット `be9aa0de55f34af6c726f55c2ab8da3fd96207c3`。kana2ではキーボード盤面・入力欄・背景が出なかった（1文字ずつの描画命令でDMA待ち行列があふれ、BG配置データの転送が捨てられていた）。1行1回の描画に直し、BACK/OKの画像を「けす」「おわり」に描き直し（`tools/localization/naming_buttons.py`）、カーソル位置を `x*8+28` に修正。レビューは `localization/reviews/naming-kana-03.review.md`。**画面確認は `tools/localization/mgba_probe.py`**（headless mGBAのデバッガでキー入力を再現し、VRAMから画面を再構成する。試験用ROMの作り方は同ファイルの説明を参照。試験用の仕掛けはコミットしない）。

名前入力（kana2、Claude Codeが引き継ぎ）: 実装コミット `a3d34bf057eab697f4eb6ab503b8b8b948d84439`。日本語版エメラルドと同じキー配列（濁点・半濁点・小文字・かな/カナ切替キー）。日本語を含む名前は全項目5文字。保存は新しい制御コード `EXT_CTRL_CODE_JPN_NAME_1`〜`_5`（FC 1D〜21、「次のn文字を日本語で描いて元の言語に戻す」2バイト）で、セーブ構造は不変。`RenderText`・`GetStringWidth`・`StringExpandPlaceholders`が対応。英字だけの名前は従来の長さ（`NamingInputKanaLimit`）。付け直しは `NamingInputDecode` で新旧形式の制御コードを除いてから編集欄へ写す。kana1版の旧形式（FC 15…FC 16）の名前も表示・付け直し可能。naming_screen.c の後ろ5項目のcode_offsetは8907。レビューは `localization/reviews/naming-kana-02.review.md`。キー操作・保存後表示・通信等は未検証。

旧・名前入力の追加（kana1）: 実装コミット `2c0a68d5a6729604e342045c9cbd0beb884bb3fd`。L/Rでひらがな・カタカナ・英字、SELECTで各3ページ。日本語を含む名前は主人公／ライバル3、ポケモン6、ボックス4文字（既存保存領域からJPN/ENGの4バイトを差し引く）。英字のみは従来の長さ。コード／ことば入力は英字維持。47テスト成功、ARMビルド成功、BPS完全一致。実際のキー操作・保存後表示・通信等は未検証。レビューは `localization/reviews/naming-kana-01.review.md`。名前入力の追加UI文言3件はカタログ外。既存の対訳は変えていないため全件Excelは10511版を継続使用。naming_screen.c / pokemon.cの既存項目の位置は、元IDを保ったまま一致区間の位置差をcode_offsetへ反映した。従来の+98だけへ戻さない。

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

1. 把握済みの独自イベントはDragonKeeper / MewtwoPostGameまで適用済み。次はsrc/strings.cなど残りUI、または図鑑・技説明。並行して、元Emeraldフォルダを流用した独自会話と未抽出テキストを調べる。簡易棚卸しの限界は上記を参照。
2. 勝敗時のトレーナーの台詞は、各マップの `scripts.inc` にある（独自マップ分は訳済み）。
3. `src/strings.c` の残り（約500件）: easy_chat 70、frontier_util 46、mystery_gift_menu 44、図鑑 33+、frontier_pass 31 など。外部参照のない約80件は未使用の可能性が高い。
4. 図鑑本文（species_info の description）、技の説明、残りの名称。
5. 元のホウエン／カントーの会話（`data/maps/` の元マップ、`data/text/*.inc`）。Wishes から到達する範囲は不明確で、量が多い（数万行）。
6. 道具・特性の説明の意味レビュー（参考フォークからの取り込みで、全件の意味確認は未了）。
7. 漢字、名前入力と長い種族名の実動作・縮小字形の可読性・通信、画像内の文字、通しプレイ。

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
| 種族名 | 最大12バイト（既存speciesName[13]） | JPN_NAME_10ならかな10文字。旧10バイト限定経路は8文字まで。入力欄は5文字のまま |
| 技・特性名 | 16バイト | |
| トレーナー名 | 12バイト＋EOS（`trainerName[13]`） | `trainers.party` の `Name:` を直接編集。対訳は `localization/trainer-names.json` |
| 肩書き | 13バイト＋EOS（`name[14]`） | カタログの `src/battle_main.c` |
| マップ名 | 16バイト | `region_map_sections.json` の `name` を直接編集。対訳は `localization/map-names.json` |
| 話者名 | 12マス | `src/data/speaker_names.h` |

- 戦闘文の自動改行 `BreakStringAutomatic`（`src/line_break.c`）は、JPN/ENG を考慮して幅を測るように直してある。日本語の戦闘文は**空白で文節を区切る**こと（区切りがないと改行できない）。
- 道具の複数形: `src/item.c` は名前が `{JPN}` で始まれば英語の「s」を付けない。
- Cコードを編集してカタログ項目の位置がずれる場合は `code_offset` が必要（現在値はcatalog.jsonを参照。naming_screen.cはkana実装による複数の値がある）。項目より後ろに挿入しないよう注意する。

## 7. 区切りごとの成果物（毎回の手順）

```sh
python3 -m unittest discover -s tools/localization -p 'test_*.py'
make -j8 FILE_NAME=pokeemerald-jp-dlgNNNN OBJ_DIR=build/emerald-jpNNNN-clean TOOLCHAIN=/opt/devkitpro/devkitARM > ../artifacts/build-dlgNNNN.log 2>&1
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
# Excel: 下記の版別出力で生成し、開いている既存ブックは上書きしない
cp tools/localization/export_review.mjs ../artifacts/translation-review-build/build_review.mjs
node ../artifacts/translation-review-build/build_review.mjs "$PWD" ../outputs/translation-review-NNNN '会話・看板（対象マップ名）' --all
cp ../outputs/translation-review-NNNN/Wishes_全テキスト翻訳一覧.xlsx localization/exports/all-texts-NNNN.xlsx
# status.json の review_workbook を exports/all-texts-NNNN.xlsx に更新して export_table.py を再実行
# localization/status.json と HANDOFF_CODEX.md の数値・最新成果物を更新し、docs コミットして push
```

- Excel生成は `../artifacts/translation-review-build/build_review.mjs`（Git内の `tools/localization/export_review.mjs` と同じ内容に保つ）。依存は Codex キャッシュの `@oai/artifact-tool`（node_modules はシンボリックリンク済み）。引数はリポジトリ、出力先、会話プレビューの区分名。今後は末尾に `--all` を付け、未翻訳を含む全件一覧を生成する（付けないと従来の翻訳済みだけになる）。トレーナー名・マップ名のJSONからも行を作る。ユーザーのメモ欄は自動では引き継がないので、編集済みのExcelがあれば先にIDで退避して新版へ復元する。ロック中の旧ブック・ロックファイルは触らない。
- `patch_crc32` が毎回 `2144df1c` になるのは、自身のCRCを末尾に持つBPSの性質。異常ではない。

## 8. やってはいけないこと

- `catalog.json` を再抽出で上書きしない（`catalog.py extract` を実行しない）。
- `seed_*.py`、`ui_common.py`、`ui_messages.py` など当時のバッチ生成スクリプトを再実行しない（適用済みバッチを上書きしうる）。
- `git stash` でカタログだけ退避しない（ソースと不一致になる。過去に一度起き、すぐ戻した）。
- 読み込み中かもしれないROMを上書きしない。ビルドは毎回新しい `FILE_NAME` で行う。
- 市販Emeraldや公式1.2.6のROMにパッチを当てない（BPSは32MiBの英語Wishes基準ROM用）。
- 完了していない作業を完了と報告しない。外部の翻訳APIは使っていない（すべて手作業の訳と検証ツール）。
