# Codex 引き継ぎ — Wishes of Tomorrow 日本語化

更新: 2026-10-26（日本時間）。Claude Code から Codex への引き継ぎ。
最初に `AGENTS.md`、この文書、`localization/status.json` を読むこと。過去の経緯の詳細は `HANDOFF_CLAUDE_CODE.md`（長い）にある。
**完全日本語化は未完了。調査で終わらず、既存の訳と仕組みを保ったまま翻訳・検証・成果物の出力を続ける。**

## 1. いまの状態

| 項目 | 値 |
| --- | --- |
| 作業場所 | `/Users/owner/Desktop/Wish/Wishes-Game`（git、ブランチ main、origin=Etoile-T/Wishes-of-Tomorrow-JP） |
| 最新の翻訳コミット | `0a926a6abb24c5c62126f49eddfdeec5b6d406a2`（この後に docs のコミットがある。`git log -5 --oneline` で確認） |
| カタログ | 61,722候補のうち翻訳済み 11,228、pending 50,494（未使用・重複・記号を含む。完成率ではない） |
| カタログ外 | トレーナー名（`src/data/trainers.party`、約500種）とマップ名（`region_map_sections.json`、229件）は翻訳済み |
| テスト | `python3 -m unittest discover -s tools/localization -p 'test_*.py'` で59件成功 |
| 最新ビルド | `pokeemerald-jp-dlg11228.gba`（ROM 29,862,344B / EWRAM 230,024B / IWRAM 28,600B） |
| ユーザー向けGBA | `/Users/owner/Desktop/Wish/outputs/gba/wishes-jp-11228-5e8294d0.gba`（README.txt 更新済み。ユーザーはkana1版・10511版の.savを持っている） |
| 配布パッチ | `../artifacts/wishes-jp-ui11228-5e8294d0-patch.zip`、追跡用 `localization/patch-manifest-ui11228.json` |
| Excel | `/Users/owner/Desktop/Wish/outputs/translation-types-11228/Wishes_種類別翻訳一覧.xlsx`（Git内コピー `localization/exports/types-11228.xlsx`、62,429行：全61,722候補＋名称707件） |

ゲーム画面での表示・進行の確認は、ほぼ未実施。ビルド成功を「正常に遊べる」とは報告しない。

最新会話48/49とユーザー指定の中断: ユーザーは「育て屋終了後、ストーリー全訳まで継続。トークンが切れそうならpushして中断」と指定。作業履歴が長くなったこの区切りをpushして中断する。**ストーリー全訳は未完了。次の再開では研究所219行を訳し、その後もストーリー全訳の目標を維持する。** 図鑑全件は保留のまま。

今回290件: ホウエン／カントーの育て屋62メッセージ146行（3行は既存日本語の言語指定・表記対応）、ムネン村につながるLittlerootTown_MaysHouse_1F/2Fの17メッセージ142行、src/field_specials.cのson/daughter2件。変数・金額・改ページ・スクロール・終端は保持。ハルカ・ユウキ・オダマキはかせを辞書追加し94語。スクリプトの非.string行とfield_specials.cの文字列以外は不変。セーブ構造・フラグ・ゲームロジックは変更なし。

開始時HEADe5240a966f、クリーン、status/stats61722/10938/50784一致。今回は61722/11228/50494。チェックbad0・26マス超0・yomiyasu lint0/meaning_risk0・59テスト・audit超過0・catalog validate成功。GBA wishes-jp-11228-5e8294d0.gba、ROM29,862,344B/EWRAM230,024/IWRAM28,600。新規OBJ_DIR build/emerald-jp-dlg11228-clean、ログ../artifacts/build-dlg11228.log。SHA256 081853be950d488f331f325bab69229da0ef3b04cd52462d1838e058c1925711。BPS再適用バイト一致。種類別Excel11228版は14シート・全62,429件を保存後11列・ID・生文字列・状態・メモ・辞書94語・集計で照合。適用済み11,935（カタログ11,228＋名称707）、未翻訳50,494。実画面・イベント・タマゴ・保存再読み込みは未検証。

**次に必ず行うこと**: まずAGENTS.md・この文書・status/stats/git状態を照合。data/maps/LittlerootTown_ProfessorBirchsLab/scripts.incにpending219、translated7（50メッセージ、既訳と未訳の混在メッセージなし）を確認して翻訳。script_batch→check/width→レビュー→dry-run/applyを守る。

**ストーリー調査の重要な修正**: 「参考JPにない独自フォルダでpending0」だけでは完了ではない。MunenVillageの実map.jsonは元の名前の家・研究所へワープしている。story_inventory.pyとstory-map-inventory.jsonを追加し、出入口・接続・マップ内の静的warpのBFSを記録した。460候補マップでmap内pending14,591行。これはフラグ・通れる地形を未評価の過大推定で、共通/C/動的ワープ・飛行・未抽出文字列等も未網羅。全訳完了の証拠に使わない。元フォルダを流用したストーリー会話を追い、変数用C文字列も見逃さない。今回の詳細はreviews/dialogue-daycare-48.review.md、dialogue-munen-linked-house-49.review.md、story-inventory.review.md。

以下は以前の記録。

最新会話47: ユーザーが全ポケモン・図鑑より「まずセリフ」を優先するよう変更したため、図鑑全件対応は調査だけで停止し、新しいポケモンデータ訳は適用していない。次の優先は会話。data/text/move_tutors.incの全41メッセージ・156カタログ行を訳した。いばる等10種類の教える前／辞退／選択／習得後と共通確認。元ホウエン側の参照スクリプトは存在するが、Wishesの実プレイ上の到達性は未確認。ストーリーが全訳済みという意味ではない。次は育て屋等の共通NPC・未抽出や流用マップの独自セリフを調べて進める。

開始時HEAD0e4e587e2d、クリーン、status/stats61722/10782/50940一致。今回は61722/10938/50784。script_batch・check bad0・26マス超0、yomiyasu scriptのlint0/meaning_risk0（コインの手品→コインあてを文脈照合で修正、指示語候補や共通確認の敬体は維持）。非.string行は開始時と完全一致、技習得フラグ・ラベル・ゲームロジック・セーブ構造は不変。59テスト・audit超過0・catalog validate成功。

GBA wishes-jp-10938-57fd012b.gba、ROM29,864,200B/EWRAM230,024/IWRAM28,600。新規OBJ_DIR build/emerald-jp-dlg10938-clean、ログ../artifacts/build-dlg10938.log。SHA256 bbfebb993b2489fad281ef71abef92221812a8f92f6efa9b4626308dbcf5681f。BPS再適用バイト一致。種類別Excel10938版は14シート・全62,429件、適用済み11,645（カタログ10,938＋名称707）、未翻訳50,784。実画面・技習得・進行・到達性は未検証。レビューdialogue-move-tutors-47.review.md。

以下は以前の記録。

最新図鑑46: 通常33種（gen_1内のニドキング〜コノヨザルの通常30種と関連進化、ピカチュウ・ニドラン♀♂）の分類・説明66件を追加。ピカチュウの本文は共有定義gPikachuPokedexTextを更新。ニドランは共有マクロではなく、定数名の_F/_Mが前回の抽出条件から除外された個別定義だった。前回の「共有マクロ」という推測を訂正。通常図鑑は未完了、次はガーディ以降とshared_dex_textの残り・別フォーム。

開始時HEAD cde0d01a88・クリーン。status/stats61722/10716/51006一致。今回は61722/10782/50940。英語と参考訳を照合し、ピィの夜露→朝露、ニドキングの送電塔を倒す描写、クロバットの進化と前後の翼、ニャイキングの戦いのスリル、クサイハナのcan/saidの確度のかかり先を修正。yomiyasu meaning_risk=1は参考訳「らしい」の変更指摘で、英語のcanを「ことがある」、saidを愛好家の節の「いわれている」として維持した判断をレビューに記録。

check bad0・26マス超0・分類12バイト以内・説明4行以内、59テスト・audit超過0・catalog validate成功。種族2ファイルの文字列・空白以外は開始時HEADと一致。GBA wishes-jp-10782-082d046d.gba、ROM29,866,120B/EWRAM230,024/IWRAM28,600。新規OBJ_DIR build/emerald-jp-dex10782-clean。ログ../artifacts/build-dex10782.log。SHA256 ff49a49229b190893733207f14bcac0a836ac6324239b3a41d1ab4072623e6ab。BPS再適用バイト一致。種類別Excel10782版は14シート・全62,429件、適用済み11,489（カタログ10,782＋別名称707）、未翻訳50,940。実画面・図鑑登録・フォーム・進行は未検証。

以下は以前の記録。

Excelの最新更新: ユーザーの指示で同じブック内の種類別シートへ分割。12データシート（ポケモン・図鑑・技・特性・道具・戦闘・ポケモンUI・メニュー・設定UI・クエスト・会話・看板・人名・地名・その他UI・要分類）＋目次・件数＋用語辞書の14シート。未翻訳を含む全62,429件を重複なく維持。目次の全件62,429／適用済み11,423（カタログ10,716＋別名称707）／未翻訳51,006を各データシートから計算。ゲームの翻訳数・ソース・最新GBAは不変、Excelだけの変更なのでROM再ビルドはしていない。

再生成にはexport_review.mjsの --all --by-type を使う。メモはID（用語は英語＋日本語）で引き継ぐ。先に review_notes.py INPUT.xlsx NOTES.json で保存済みメモを退避し、生成時に --notes=NOTES.json を渡す。旧全件ブック・新しい種類別ブックの両方を読める。今回は旧ブックの保存済みメモ0件、旧ブックは維持。種類別ブックの全行11列・元ID・生原文・生訳・状態・目次集計値を保存後照合し、14シートのプレビュー確認。実Excelアプリは未確認。検証ログ ../artifacts/logs/excel-types-10716-verify.log。共通文字列等の分類はファイル／定義に基づくため「その他UI・要分類」を残す。

最新図鑑44/45: ユーザーが図鑑翻訳を依頼し通常種も追加指定。独自メガ19種＋アーマードミュウツーの分類・説明40件、通常30種の分類・説明60件、計100件を適用。通常種は同一種族・同一フィールドで日本語参考を再利用して英語と照合。共有マクロのピカチュウ・ニドラン等は今回の候補に含まれず、全国番号1〜30の完了ではない。wot_families独自7種は既訳を維持。次は共有マクロの図鑑説明・分類とgen_1の残り通常種（ニドキング以降など）を継続。通常図鑑全体は未完了。

チェック100件bad0、26マス超0、分類12バイト以内、説明4行以内、59テスト、audit超過0、クリーンビルド成功。種族2ファイルの文字列・空白以外のコードは開始時HEADと一致。レビューpokedex-44-45.review.md、棚卸しpokedex-batch-44-45-audit.json。開始時HEAD6914180e9f・クリーン、status/stats61722/10616/51106一致。今回は61722/10716/51006。

最新GBA wishes-jp-10716-ae4fa5d9.gba。ROM29,868,616B/EWRAM230,024/IWRAM28,600。build/emerald-jp-dex10716-cleanで作成、ログ../artifacts/build-dex10716.log。SHA256 b73c0c25b3be82fd5756e0ce234ce18170fc520d3fa647158765d32bcc9413d7。BPS再適用バイト一致。全件Excel10716版は62,429行、カタログ翻訳10,716＋別管理名称707、未翻訳51,006。実機・図鑑登録画面・独自メガ説明への到達性は未検証。

以下は旧版の記録。

最新修正42/43: 勝敗台詞の空白が「ぐ」になる原因はBattleStringExpandPlaceholdersのNBSP変換。トレーナー1/2の勝ち・負け台詞では変換しない。別件のボックス不具合はgText_Boxが制御付き8バイト＋番号＋EOSでboxNames[][9]を超え、次の名前が前のEOSを消し、タイトル用40バイトの作業領域を超えて読み書きし得る。接頭辞をJPN_NAME_4（6バイト）に変更。GetBoxNamePtrで厳密一致した旧既定名だけ番号を再構成、全名称の8バイト末尾を終端。不正壁紙IDは表示時に既定値を使用。セーブ構造は不変。名称はRAMで補正され、通常ゲーム内セーブ時には補正名も保存される。ホストの.savは未変更。全59テスト・catalog validate・audit・ビルド・BPS再適用バイト一致成功。A操作・アイコン・実画面の復旧は未確認。レビューはbattle-dialogue-spaces-42 / storage-default-name-43。

最新GBA: wishes-jp-10616-storage-1895cd6a.gba、ROM29,872,008B、EWRAM230,024/IWRAM28,600。ビルドログ ../artifacts/build-storage10616.log。新規OBJ_DIR=build/emerald-jp-storage10616-clean。SHA256 f24fdb9f081ba2e0edaf26f6cc8d65f1719da91a92376fc9ac6ce4ef43343272。翻訳件数10616は不変。Excelは制御付き生訳が1件変わるため10616-storage版へ更新。

以下は旧版の記録。

最新の修正41: ユーザーの画面報告で5px圧縮の文字欠落を確認。「ARミュウツー」へ短縮し、日本語FONT_SMALL_NARROWERを元の8px幅に戻した。英字AR＋かな5字は48pxで55px欄に収まる。会話は正式名のまま。旧英語・前版の日本語フル名は種族と全バイトが一致するデフォルト名だけ表示時変換。セーブは書き換えない。57テスト、audit、ビルド、BPS照合成功。実画面・通信・保存は未検証。レビュー species-armored-readable-41.review.md。最新GBAは wishes-jp-10616-ar-b4237eaf.gba。ROM29,871,752B。今回開始時 status/stats一致、HEAD e68ca7fae7・作業ツリークリーン。

以下は前版の履歴。5px圧縮を再導入しない。

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

ユーザーは「セリフ系」→「戦闘メッセージ」→「トレーナー名・マップ名」→「ストーリーの続き」の順に依頼してきた。現在はユーザーの最新指示で**セリフを優先**する。ポケモン・図鑑の全件対応は保留。既知独自マップから始め、共通NPC会話も進めている。

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
node ../artifacts/translation-review-build/build_review.mjs "$PWD" ../outputs/translation-review-NNNN '会話・看板（対象マップ名）' --all --by-type
cp ../outputs/translation-review-NNNN/Wishes_種類別翻訳一覧.xlsx localization/exports/all-texts-NNNN.xlsx
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
