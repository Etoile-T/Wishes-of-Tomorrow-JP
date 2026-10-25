> 最新の状況（2026-10-26）: 61,722候補中5,693件を翻訳適用。以下の初期記録には古い件数を含む。最新値はstatus.jsonとUI_PROGRESS.mdを参照。ユーザーの指定によりソース検査・ビルドを優先し、画面操作は延期。ExcelとMarkdown表を5,693件へ更新済み。

# Wishes of Tomorrow 日本語化・途中成果

2026-10-26。**完全日本語版ではない。** かな表示の既存機能を再利用した初期実装である。

## 現在の成果

- 英語版の未変更ソースをビルドし、比較用ROMとビルドログを保存した。
- 翻訳候補60,597件を抽出。2,709件を翻訳・ソースへ適用、57,888件はpending。
  未使用文言、空文字、制御だけの文字列、標準Emerald/FRLGの文言も含むため、これは会話数や完成率ではない。
- 翻訳範囲：メインメニュー、スタートメニュー項目、クエスト日誌の見出し・目的・完了文、
  クエスト通知、ムネン村の冒頭伝承と母・博士・ライバルの一部会話。
- 既存の日本語フォントを使用し、拡張記号・数字について描画と幅計算の参照先を一致させた。
- 日本語クエスト文の字間とフォント、フィルター表示位置、状態表記を調整した。
- 日本語版の途中ROMをビルドした。BPSパッチを作成し、再適用結果がROMと完全一致することを確認した。

## フェーズ1：調査

| 項目 | 確認結果 |
|---|---|
| ゲームの取得コミット | `efb1c880d0b486c1948763051b6c1bb8990a7353` |
| 参考実装の取得コミット | `b07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5ef` |
| ベース | ゲームREADMEはExpansion 1.15.3と明記。浅いcloneのため上流タグとの全履歴照合は未実施 |
| 独自機能 | quests.c/quest_toast.c/quest_indicator.c、field_name_box.c、npc_portrait.c、boss_intro.c、field_move.c、Shadow関連処理、独自map/event |
| 文字コード | charmap.txtにかなと日本語句読点が既存。英字拡張文字とコードが重複。JPN=`FC 15`、ENG=`FC 16` |
| 描画 | src/text.cにsmall/normal/short等の日本語分岐が既存。JPNモードを文字列側で指定可能 |
| フォント | graphics/fonts/japanese_{small,normal,short,bold}.png等。参考側の同名画像とはバイナリ不一致。font-comparison.jsonに記録 |
| text.h設定 | 元のinclude/config/text.hには日本語既定設定なし。参考側にはTEXT_JAPANESE_BY_DEFAULTとAUTO切替あり |
| テキスト格納 | src/strings.c、battle_message.c、各UIのstatic定義、src/data/pokemon/species_info、moves_info、items、abilities等、data/maps/*/scripts.inc、data/text、data/scripts、.party、JSON |
| クエスト | src/quests.cのロスターがsrc/strings.cの目的文を参照。フラグに応じた段階別文言あり。保存bitfieldは変更していない |
| 名前欄 | field_name_box.cはGetStringWidthで幅を算出。名前バッファ32バイト。人物名の全面翻訳は未着手 |
| 名前入力 | naming_screen.cに英字大文字・小文字・記号のキーボード。かな入力は未実装 |

参考側text.cとの比較差分は作業フォルダの`artifacts/text-reference.diff`に保存。
参考側の自動言語判定、半角化、フォント差し替え、他UI変更は依存が大きく、無条件には移植していない。
今回移植した考え方はShouldUseJapaneseGlyphの参照先選択のみ。Wishesの話者制御等は残した。
未翻訳英語を維持するため、日本語を全体の既定にはせず翻訳文字列に明示的な{JPN}を付けた。
英字を表示する区間は{ENG}で切り替える。翻訳済み導入部のプレイヤー名・未翻訳ポケモン名も明示切替する。

## フェーズ2：残作業と漢字の設計候補

かなは既存フォントを再利用。漢字グリフ・エンコーダ・デコーダは**未実装**。
参考側にも今回確認した範囲では汎用漢字実装はない。既存の1バイト領域を漢字に流用するとかな・英字・制御が衝突する。

- 全JIS字形の常駐展開：ROMとRAMを無駄に使うため避ける。
- 翻訳コーパスからのサブセット：第一候補。12×12・2bppなら2,000字で約72KBの生字形。
  small用8×12を別に持つ場合は約48KB追加。実際の必要字数・可読性は未計測。
- 新しい拡張制御に続く複数バイトの字形ID：既存1バイト名やセーブ構造を維持できるよう設計する。
  コピー・比較・文字数計算・placeholder展開・名前入力・通信・固定長配列も含めて監査が必要。
  payloadにEOSや既存制御先頭を出さない符号化を検討する。まだコード番号を確保していない。
- glyph単位で既存gCurGlyphへ展開すれば大型RAMキャッシュは不要。CPU時間とVRAM転送量は実機相当環境で計測する。
- 自動改行・禁則処理・変数展開後の折返しは未実装。現在の翻訳は手動改行。

## フェーズ3・4：ツールと翻訳

`catalog.json`は元英語版の位置、原文、翻訳、状態、定義名を保持。
IDはファイル・元オフセット・原文から生成する。元ソースの版が変われば再照合が必要で、汎用の永続IDではない。

```sh
python3 tools/localization/catalog.py stats
python3 tools/localization/catalog.py validate
python3 tools/localization/catalog.py apply
python3 tools/localization/audit.py
python3 -m unittest discover -s tools/localization -p 'test_*.py' -v
```

applyは全対象の照合後に書き込む。同じ翻訳の再適用は変更しない。ソース不一致は拒否する。
{PLAYER}等の変数、ページ送り・スクロール等は個数を保護する。翻訳に合わせた改行`\n`の変更と言語切替タグは許可する。
文字コードにない文字（漢字等）は拒否する。字形が実際に描画されるかの確認は別途必要。
制御トークンの個数照合は順序や意味の完全な検証ではないため、翻訳レビューが必要。

新規の原文抽出は`catalog.py extract --catalog 別ファイル.json`で行う。
**既存catalogを再抽出で上書きしないこと。** seed_translation.py/seed_story.pyは今回の翻訳バッチの記録であり、
通常の再ビルドには不要。取り込み元スナップショットの原文に依存するため、版変更後の無条件実行は不可。

`structured-inventory.json`にはJSON/.partyの文字列と`__()`の要確認箇所を記録した。
158,045件の大半はspecies/mapなどの構造ID。翻訳対象件数には加算していない。
これらのschema別抽出・安全な再挿入は未実装。Cの通常の裸文字列、生成画像内の文字、タイトル画像等も別途監査する。
`glossary.json`は初期辞書。公式ポケモン・技・特性・道具名の全辞書はまだない。
独自固有名詞と一人称は暫定方針で、全シナリオとの照合が必要。

## フェーズ5・6：検証

| 検査 | 結果 |
|---|---|
| 英語基準ビルド | 成功。ROM 29,912,184B、EWRAM 230,024B、IWRAM 28,600B |
| 日本語途中ビルド | 成功。ROM 29,911,000B、EWRAM 230,024B、IWRAM 28,600B |
| 配布用ROMの物理サイズ | 32MiB（ビルド後のpaddingを含む） |
| 抽出・制御保護・未定義文字テスト等 | 16件成功（BPS・追加翻訳・名称照合テストを含む） |
| 対象会話・クエスト説明文の静的幅検査 | 推定はみ出し0。8pxの概算。変数展開後の幅・全UIは未検証 |
| BPS再適用 | 生成ROMとバイト一致、source/target/patch CRC検証成功 |
| git diff --check | 成功 |
| mGBA Lua | 同梱バイナリがスクリプト読み込みに失敗 |
| mGBA debugger frame smoke | 英語版・日本語版とも終了コード-11。要求した600frameの完走は確認できず。エミュレータ環境側の調査が必要 |
| 日本語画面目視・実プレイ | 未実施。文字化けしない／クラッシュしないとはまだ断定しない |
| 全戦闘回帰・クエスト進行・終盤・セーブ互換 | 未検証 |

リンカのRWX segment警告は英語版・日本語版の双方で発生。ビルド成功とは別に記録する。
一部取得処理ではDNS失敗も発生。外部翻訳APIは使用していない。

## 再現方法と成果物

ソース全体は作業フォルダのWishes-Game。取得元のコミット上に変更を置いている。
既に翻訳が適用済みなので、通常はビルドのみでよい。

```sh
cd Wishes-Game
make -j8 TOOLCHAIN=/opt/devkitpro/devkitARM
```

macOSの既存devkitARM GCC 16.1.0、libpng、clang等を利用。初期ツールビルドを含めて成功した。
元の英語ソースから再現する場合は上記コミットをcheckoutし、
`git apply /path/to/artifacts/localization-source.patch`を実行して同じコマンドでビルドする。
このソース差分はゲームの変更7ファイルのみ。翻訳ツール・catalog・辞書は本ディレクトリとtools/localizationを別途コピーする。

- `artifacts/wishes-jp-wip.gba`：ローカル検証用の途中ROM。完全日本語版と称して配布しない。
- `artifacts/wishes-jp-wip.bps`：**今回ソースから生成した英語基準ROM用**差分。市販Emerald ROM用ではない。
- `artifacts/wishes-en-baseline.gba`：ローカル比較用。SHA256はartifacts/SHA256SUMS。
- `artifacts/logs/`：英語・日本語ビルド、ツールテスト、エミュレータ試行記録。

BPSは[byuuの仕様](https://floating.muncher.se/byuu/bps/bps_spec.html)に従う。公開は行っていない。
ROMそのものの公開は避け、基準ハッシュを明記した差分とソース変更を扱う。パッチ化だけで権利上の問題がすべて解消するとは限らない。

## 次に着手する作業

1. 正常動作するmGBAビルドを用意し、英語版・日本語版の開始メニューと導入部を同じ入力で比較。
2. 漢字サブセットと複数バイトIDを試作し、文字列util全体・固定長配列・描画テストを先に整える。
3. JSON/.partyのschema別抽出、裸C文字列と画像内テキストの監査、公式用語辞書を追加。
4. ムネン村の未翻訳会話から地域別に翻訳。人名・地名・口調を確定し、イベント単位で進行検証。
5. 種族名・技・特性・道具・戦闘・図鑑・全独自UIを順次対応。名前入力のかな／漢字表示と保存長を検証。
6. 最後までの通しプレイ、クリア後・戦闘回帰・セーブ互換を検証してから完成判定。

## yomiyasu導入後の追記

yomiyasu 2.4.0をプロジェクトに導入し、ムネン村の残り21件を翻訳した。
同マップのscripts.incに含まれる文字列38件は翻訳適用済み。関連する別マップ、共通取得文、話者名、画像、進行の確認は別作業。
[導入・レビュー手順](yomiyasu.md)と[今回のレビュー記録](reviews/munen-village-02.review.md)を参照。
最新のメモリ使用量と件数はstatus.jsonに記録する。

## 名称データの取り込み

参考実装の名称を定数IDごとに照合し、ポケモン名1,321件、技名923件、特性名316件を追加した。
詳しくは[取り込み記録](reviews/reference-names-01.review.md)と[保留一覧](reference-names-report.json)を参照。
全名称の対応や、説明文・図鑑・道具の翻訳完了を意味しない。最新の件数と使用量はstatus.jsonに記録する。

## UI対応の追加

ユーザーの追加指示により、対象を全UIへ拡大した。今回680件を追加適用し、開始・設定・バッグ・ボックス・手持ち・ステータス・セーブ・名前入力案内・ランダマイザー・図鑑UIの一部を翻訳した。全UIの完了ではない。

[UI残件候補](UI_PROGRESS.md)と[レビュー・検証記録](reviews/ui-01.review.md)を参照。画面内画像、動的な文の組み立て、狭い図鑑欄などは別途調整が必要。日本語の名前入力キーボードは未実装。

コード編集で後続の原文位置が変わった場合、元のID/start/endは変えず、レビューした差分長だけを`code_offset`へ記録する。今回のnaming_screen.cでは、タイトル展開処理の変更より後の5文字列が+98文字。翻訳の長さ差とは別に検証・再挿入時へ加算する。バッチからの位置変更は拒否する。将来のコード変更では無条件に値を流用しない。

Excelの再生成には`@oai/artifact-tool`が必要。依存が利用できる作業用ディレクトリへ`tools/localization/export_review.mjs`をコピーし、`node export_review.mjs /path/to/Wishes-Game /path/to/output`を実行する。Markdown表は`python3 tools/localization/export_table.py`で生成する。既にExcelへ確認メモを書いた場合は、再生成前にIDで退避・照合すること。現在の書き出しツールはメモの自動引き継ぎを行わない。

## 確認用ROMの扱い

読み込み中の可能性があるROMを上書きしない。ビルド後は以下でSHA256に対応する別名の確認用ファイルを作る。既存ファイル・セーブ・ステートは上書きしない。

```sh
python3 tools/localization/export_play_rom.py pokeemerald.gba ../artifacts/play
```

クエストにっし使用後のスプライト崩れが報告されている。[調査記録](issues/quest-log-sprite-corruption.md)を参照。修正済みとはしていない。
