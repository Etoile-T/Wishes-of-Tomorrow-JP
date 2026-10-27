# 翻訳サブタスクの共通指示（Wishes of Tomorrow 日本語化）

リポジトリ: /Users/owner/Desktop/Wish/Wishes-Game （以下ROOT）。GBA ポケモンエメラルド改造作品の英語セリフを、かなの日本語に手作業で訳す。
外部翻訳APIは使わない。**あなたは下書きバッチを作るだけ**。catalog.json の編集、`update_catalog.py --apply`、git 操作、他ファイルの変更は禁止。

## 入力と出力
- 入力: `/Users/owner/Desktop/Wish/artifacts/work70/NAME.txt`
  - `##### ファイル` / `## ラベル:` 行と `ID<TAB>英語原文` の行。`#REF<TAB>日本語` は直後のIDの参考訳（日本語版エメラルド系の参照訳。Wishes で英語が変わっている場合があるので、必ず英語と意味を照合し、合っていれば活用、違えば英語に合わせて直す）。
- 出力: `/Users/owner/Desktop/Wish/artifacts/work70/NAME.draft.txt`
  - 入力と同じ並びで、**全IDの行**を `ID<TAB>日本語` にする（英語を日本語に置き換える）。`#` で始まる行は無視されるので残してよい。
  - 1メッセージ（`$` で終わるまでの連続行）は全行まとめて訳すこと。一部だけは拒否される。
- 大きいファイルは数回に分けて Write/Edit してよい（最後に1ファイルにまとまっていればよい）。

## 書き方の決まり
- **使える字**: ひらがな・カタカナ・英数字・半角スペース・`! ? … ‥ ・ ー 「 」 『 』 ( ) : / ~ ♂ ♀ 円` など charmap にあるもの。**漢字・全角英数・「～」は不可**。不明なら `ROOT/charmap.txt` を確認。
- 文節ごとに**半角スペース**で区切る（例: `なにか おきてるみたいで`）。既訳の文体（ひらがな中心、カタカナ語）に合わせる。
- **制御コード**: 各行の末尾の `\n` `\l` `\p` `$` は英語の同じ行と同じにする。`\l` `\p` `$` は増減・移動禁止。`\n` のみ増減可（ただし2行の枠を超えない）。
- **変数** `{PLAYER}` `{STR_VAR_1}` `{RIVAL}` `{KUN}` `{B_...}` 等は英語と**同じ行**に残す。`{JPN}` `{ENG}` は書かない（自動付与）。`{PKMN}` は「ポケモン」と書いて省いてよい。矢印 `{UP_ARROW}` 等や `{COLOR ...}` 系も残す。
- **幅**: 1行（\n/\l/\p/$の区切り単位）は**26マス以内**（かな・英字・数字・記号すべて1マス）。
- 金額は `{STR_VAR_1}円` / `3000円`。`¥` と桁区切り `,` と `“ ” ' "` は不可。引用は「」『』。
- 話者付きの行は `ハルカ: …` のように `名前: 本文`。
- プレイヤーの性別を決めつけない。性別不明のNPCに「ぼく」「〜ぜ」等を勝手に付けない。原文の口調（老人の「〜じゃ」、乱暴な言い方、口癖、ジョーク、反復）を保つ。意味・不確かさ・出来事の順序を変えない。
- 文末の「。」はゲームの表記として使ってよい（台詞では自然な範囲で）。
- 固有名詞: `ROOT/localization/glossary.json`（独自名称）、`ROOT/localization/map-names.json`（地名）、`ROOT/localization/trainer-names.json`。ポケモン・道具・技名は
  `cd ROOT/tools/localization && python3 dialogue_tools.py lookup "Escape Rope" Pikachu` で既訳を引く。公式日本語名（ハルカ、ユウキ、オダマキはかせ、センリ、ミツル、ダイゴ、マグマ団=マグマだん、アクア団=アクアだん 等）は既訳と揃える。迷ったら既訳を `grep` で確認（`ROOT/localization/catalog.json` の translation）。

## 検査（必ず通す）
```sh
cd /Users/owner/Desktop/Wish/Wishes-Game
python3 tools/localization/script_batch.py ../artifacts/work70/NAME.draft.txt localization/batches/dialogue-NAME.json
cd tools/localization
python3 dialogue_tools.py check ../../localization/batches/dialogue-NAME.json     # "bad 0" になるまで直す
python3 dialogue_tools.py width ../../localization/batches/dialogue-NAME.json     # 何も出なければOK（出た行を短く/\n）
```
エラーが出たら draft を直して script_batch から再実行。`already translated` が出たらその行を draft から除く。

## 完了報告（最終メッセージ）
訳した行数、check/width の結果、英語と参考訳が食い違った箇所や判断に迷った箇所（ID付きで数件まで）、新しく決めた固有名詞の表記。長い説明は不要。

## カントー（_Frlg マップ）の補足
- 参考訳（#REF）は無い。ファイアレッド・リーフグリーン日本語版の公式名に合わせる（オーキドはかせ、サカキ、ロケットだん、タケシ、カスミ、マチス、エリカ、キョウ、ナツメ、カツラ、四天王 カンナ・シバ・キクコ・ワタル、ニビシティ、ハナダシティ、クチバシティ、ヤマブキシティ、タマムシシティ、セキチクシティ、グレンじま、トキワシティ、マサラタウン、シオンタウン、セキエイこうげん、シルフカンパニー、サント・アンヌごう、ナナシマ（1のしま〜7のしま）等）。まず `map-names.json` と catalog の既訳を確認し、既訳があればそれを優先。
- ライバルは `{RIVAL}` 変数のまま残す。
## バトルフロンティア（BattleFrontier_* マップ）の補足
- 施設名は既訳・map-names.json を優先（バトルタワー、バトルドーム、バトルファクトリー、バトルパレス、バトルアリーナ、バトルチューブ、バトルピラミッド、フロンティアブレーン、バトルポイント=BP 等）。受付の定型文は同じ英語なら同じ訳に揃える。

## data/text・data/scripts（共通テキスト）の補足
- trainers.inc: トレーナーの対戦前（Intro）・負け（Defeat）・戦闘後（PostBattle）・再戦（Rematch）の台詞。トレーナー名・肩書きは表示されないので台詞だけ訳す。台詞は短く口語的に。
- match_call.inc: エントリーコール（電話）の会話。『』を使わない。{STR_VAR_n} は ポケモン名・場所名などが入る。
- tv.inc / apprentice.inc / pokemon_news.inc: {STR_VAR_n} 等にプレイヤー名・ポケモン名・技名・数字が入る。ソースで何が入るか不明な場合は、文脈から推測し、助詞を付けても不自然でない語順にする。
- 1つの作業ファイルが複数ファイル（##### 行）を含むことがある。NAME が `text-xxx-a` のようにハイフン付きでも、そのまま NAME として使う。
