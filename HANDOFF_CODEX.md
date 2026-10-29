# Codex 引き継ぎ — Wishes of Tomorrow 日本語化

更新: 2026-10-27（日本時間）。Claude Code から Codex への引き継ぎと、その後の作業記録。
最初に `AGENTS.md`、この文書、`localization/status.json` を読むこと。過去の経緯の詳細は `HANDOFF_CLAUDE_CODE.md`（長い）にある。
**完全日本語化は未完了。調査で終わらず、既存の訳と仕組みを保ったまま翻訳・検証・成果物の出力を続ける。**

## Lv表示の修正（2026-10-29）

手持ち一覧でLvが「ゃ」になるというユーザー報告。GitHub main4579067b65を取得して調査、文字コード0x34が英語LV/日本語ゃで共有され、gText_LevelSymbol/gText_LvのJPN指定が原因と確認。両文字列をENGへ修正、カタログ2件と既存バッチ118を同期。新バッチui-level-symbol-fix-143、レビューreviews/ui-level-symbol-fix-143.review.md、ソース86018632。かなフォント/描画エンジン/ゲーム内容/セーブ構造は変更なし。

83テストskip0、catalog validate、audit0、新規build/emerald-jp-lv143-cleanでビルド成功。ROM29,453,444B/EWRAM230,024B/IWRAM28,600B。ROMシンボルの英語モードを直接確認。以前の61722版との違いは2バイトのみ、旧値へ戻した検証用コピーが既知の旧SHA256と一致。

最新GBA ../outputs/gba/wishes-jp-61722-lv143-abd9b150.gba、SHA256 eb014715c59ba437b39c22a15795fb1ce77c2302b069ea2bbf697c502a5319f0。更新BPS ../outputs/patches/level-fix143/wishes-jp-level-fix143-update.zip、manifestはpatch-manifest-level-fix143.json。適用元は**以前の日本語61722版(CRC660ae8bf)**、英語版/市販ROM用ではない。BPS101B、SHA照合付き再適用結果が新ROMと全バイト一致。公開リリースへの添付・公開はしていない。

旧Desktop/Wishは見つからず、今回の作業は /Users/owner/Documents/Codex/Wish/Wishes-Game へ保存。既存ユーザーROM/セーブには触れていない。実ゲーム画面/操作は未検証。Excelは生訳2件のJPN→ENG変更が未同期、再生成が必要（表示上の訳文と件数は不変）。今回Excelを検証済みとは報告しない。

## 最新: 会話69〜108（2026-10-27、Claude Code）

Codexの会話69（111〜113番道路ほか258行、抽出済み・未適用だったもの）を照合して適用。続けて残りのストーリーを40バッチ・34,734行、サブエージェント並列で下書きし、主セッションで検査・表記統一・適用した。15,239→49,973、pending11,749。
**data/maps・data/text・data/scriptsのカタログ行はすべて翻訳済み（pending0）**。点字87行は preproc に日本点字（カナ点字）変換を追加して翻訳（tools/localization/braille_ja.py→tools/preproc/braille_ja.h、test_braille_ja.py）、FRLG名前候補42行は `{JPN_NAME_n}`＋かな5文字以内で翻訳（reviews/braille-and-name-presets-109-110.review.md）。最新成果物は ../outputs/gba/wishes-jp-50102-ae8e8da9.gba（source 8a948b74be）、Excel ../outputs/translation-types-50102/・exports/types-50102.xlsx。50,102/11,620。
レビュー: reviews/dialogue-northern-routes-69.review.md、dialogue-hoenn-wave-70-78.review.md、dialogue-frontier-kanto-text-79-108.review.md。下書きは reviews/drafts/、サブエージェント用の共通指示は reviews/drafts/BRIEF-subagents.md。
成果物: ../outputs/gba/wishes-jp-49973-08c39ad6.gba（SHA256 9bb0cdc0…2fec、source 5b6c415afe、ROM29,576,456B）。中間版 wishes-jp-21983-bc0b1220.gba。Excel ../outputs/translation-types-49973/、Git内 exports/types-49973.xlsx。BPS再適用一致。実ゲームの表示・進行・保存は未検証。

追記（会話111〜122）: エントリーコールのプロフィール（15マス/項目）、連れ歩き、strings.c、フロンティア/ドーム/field_specials等の進行文、エンディングのクレジット（人名は英字のまま）、カントーのトレーナー名（trainers_frlg.party）、フロンティア/テント/ヒル/タワー/弟子の名前（JPN_NAME）を翻訳。生成ファイル trainers.h・trainers_frlg.h・region_map_entries.h のカタログ行は再生成結果と照合して記録。EGGS{STR_VAR_1}はgText_FrontierFacilityAreInelegible「は さんか できません」に接続済み。最新 ../outputs/gba/wishes-jp-54527-822c4a5e.gba（source eb3544cb94）、Excel ../outputs/translation-types-54527/。54,527/7,195。レビュー reviews/c-dialogue-and-names-111-117.review.md、c-story-messages-118-122.review.md。
**注意**: C文字列の固定長配列（例 gText_123Dot[][3]）に{JPN}/{ENG}を入れるとビルドエラーになる。C側を訳すときは宣言のサイズを確認する。

追記（会話123〜142）: **カタログ61,722件すべて翻訳済み（pending0）**。図鑑の分類・説明、技の説明（2行×19マス）、かんたん会話の単語（7マス）、デバッグ、ユニオンルーム、コンテスト相手（公式名）、きのみ、もようがえ、交換、地名表示ほか。参考フォーク照合は tools/localization/reference_text.py、固定長フィールド用は tools/localization/direct_batch.py。レビュー reviews/ui-data-123-142.review.md。最新 ../outputs/gba/wishes-jp-61722-660ae8bf.gba（source 396f17e4e1）、Excel ../outputs/translation-types-61722/（全シート未翻訳0）。
残り: 実機での表示確認（図鑑・ステータス・かんたん会話・PokéNav・点字窓・クレジット等）、漢字、画像内の文字、戦闘画面の所有格部品（"'" "s"）のコード側対応、弟子の台詞の一人称の揺れとテレビの秘密基地グッズ名の統一確認、Z技など長い技名の短縮の確認。

## 以前の会話68（2026-10-27）

開始HEAD27f2008281・クリーン、status/stats61,722/14,974/46,748一致。シダケ施設176/カナシダトンネル75/117番道路14、計265行61メッセージ追加し61,722/15,239/46,483。9ファイルpending0。参考113行を英語全文と照合し編集、残り152行は新訳。レビューreviews/dialogue-verdanturf-tunnel-68.review.md。ミツルの決意/ラルトス/再戦、叔父と弟の息子の家族関係、ミチルの信頼、恋人と住民のための工事、なつき7段階、テントの性格/技と旧コンテスト、救出/かいりき/育て屋を保持。海賊の船底引きの罵りは比喩のまま。辞書139語不変。

yomiyasu script lint0/meaning_risk3は花の疑問、uncomfortableの問い、only for one battleを英語で確認し維持。修正1回・再run/verify一致。check bad0/26マス超0、audit0、78テスト成功。9ファイル非.string行は開始HEADと一致。ロジック/フラグ/セーブ構造不変。英語のネストボール「weakened」と現在のBALL_NEST低レベル補正条件には差がある。「よわった」と原文を保持し記録、判定を翻訳で勝手に変えない。販売限定や旧施設の整合性全体は未検証。

GBA ../outputs/gba/wishes-jp-15239-256d909c.gba、SHA256 bb850ea9aa5ea181d5ee4cfeab67b17790d4ba2d44f4d63ff4af04939d4846be。source commit a92092b64baf4bd037634b6f47c9b1c3af14e20f。build/emerald-jp-dlg15239-cleanでビルドexit0、ROM29,819,240B/EWRAM230,024/IWRAM28,600。BPS再適用SHA/CRC・全バイト一致、../artifacts/wishes-jp-ui15239-256d909c-patch.zip。Excel14シート・62,429行11列・139語・全原文/訳文/ID/状態/メモと目次62,429/15,946/46,483を保存後照合。旧メモ0件維持。Git内exports/types-15239.xlsx、ユーザー版 ../outputs/translation-types-15239/Wishes_種類別翻訳一覧.xlsx。実Excelアプリ・ゲーム実画面/進行/保存は未検証。旧ROM・セーブ保持。

管理画面15239/46483へ再読込済み。次は **Route11194/OldLadysRestStop12/WinstrateFamilysHouse32→Route11218→Route11319/GlassWorkshop57→FallarborTown26、計258行**。次バッチ69の原文と未レビュー参考160行59メッセージは../artifacts/dialogue-northern-routes-69-source.txtと同.reference.tsvへ抽出済み（未適用）。残り参考1,780メッセージ/4,733行、mapグラフ460候補・pending10,608。全ストーリー未完了、C/共通/動的移動/未抽出を含む完成証明なし。トークンが戻ったら続きから再開。

## 以前の会話67（2026-10-27）

開始HEAD6e77e4f4e3、status/stats61,722/14,669/47,053一致。未追跡の参考TSV1件は前回の準備稿で継続利用。キンセツ自転車店100/ジム101/民家33/ショップ10/センター19とシダケタウン42、計305行77メッセージを追加し61,722/14,974/46,748。8ファイルpending0。参考139行はWishes英語全文に照合し編集、残り166行は新訳。レビューreviews/dialogue-mauville-verdanturf-67.review.md。自転車の操作条件/交換、電気とロックの比喩、いわくだきの呼び名、バッジ/技34、コインケース、通信データ/勝敗記録、シダケの工事と連勝を保持。参考の出生前→トレーナー以前、所有→運転能力、事実→伝聞のずれを原文へ戻した。ミチル/ダイナモバッジ追加で辞書139語。

yomiyasu script lint0/meaning_risk4を英語に照合して維持。check bad0/26マス超0、audit0、78テスト成功。8ファイルの非.string行は開始HEADと完全一致。ロジック/フラグ/セーブ構造不変。バッジの既存仕様や旧施設の到達性まで検証したものではない。

GBA ../outputs/gba/wishes-jp-14974-6ffe83ab.gba、SHA256 ca4d7f0da794b08fd045951cba2803c315509a410b5c9630e42f0c1b617ee040。source commit ebc5dfa87c93e46a21fc98222a8ca5f83f1a543f。build/emerald-jp-dlg14974-cleanでビルドexit0、ROM29,822,152B/EWRAM230,024/IWRAM28,600。BPS再適用SHA/CRC・全バイト一致、../artifacts/wishes-jp-ui14974-6ffe83ab-patch.zip。Excel14シート・62,429行11列・139語・全原文/訳文/ID/状態/メモと目次62,429/15,681/46,748を保存後照合。旧メモ0件維持。Git内exports/types-14974.xlsx、ユーザー版 ../outputs/translation-types-14974/Wishes_種類別翻訳一覧.xlsx。実Excelアプリ・ゲーム実画面/進行/保存は未検証。旧ROM・セーブ保持。

管理画面は14974/46748へ再読込済み。次は **VerdanturfTown_WandasHouse60/FriendshipRatersHouse22/House10/Mart12/PokemonCenter_1F12/BattleTentLobby41/BattleTentCorridor19（計176）→RusturfTunnel75→Route11714、計265行**。参考候補1,817メッセージ/4,846行は未レビュー/未適用。mapグラフ460候補・pending10,873。全ストーリー未完了、C/共通/動的移動/未抽出を含む完成証明はない。トークンが戻ったらこの続きから再開。

## 以前の会話66（2026-10-27）

開始時HEAD198c1f03b3・クリーン、status/stats61,722/14,355/47,367一致。カラクリPuzzle1〜8/End計314行121メッセージ追加し61,722/14,669/47,053。9ファイルpending0。参考179行は英語全文に照合して編集、残り135行は新訳。レビューreviews/dialogue-trick-puzzles-66.review.md。合言葉8種類、各8個の沈黙、順位6/5/4/3/2/ほぼ同等/同等/超えたかも、人物の反復・煙の比喩・10回超などを保持。辞書137語。

yomiyasu script lint0/meaning_risk6を英語に照合して維持。check bad0/26マス超0、audit0、78テスト成功。9ファイル非.string行とsrc/data/script_menu.h全体は開始時と完全一致。クイズ15問の既訳選択肢・固定正解番号をquiz-audit.jsonに記録。3_Q3は現在価格400+300=700（いいキズぐすり700）なのに固定正解「やすくなる」という既存不整合がある。英語の問題/正解判定を勝手に直していない。価格/生息地/過去イベント/町の人数の全整合性は未検証。ゲームロジック/フラグ/セーブ構造不変。

GBA ../outputs/gba/wishes-jp-14669-4c03e995.gba、SHA256 386e84da3d7960ea12a85a754e381878516a7b28f595cd0cc079c30209114885。source commit 1d9d35dd14815dd4bfec0b3f47620f7954e9bf95。build/emerald-jp-dlg14669-cleanでビルドexit0、ROM29,825,480B/EWRAM230,024/IWRAM28,600。BPS再適用SHA/CRC・全バイト一致、../artifacts/wishes-jp-ui14669-4c03e995-patch.zip。Excel14シート・62,429行11列・137語・全原文/訳文/ID/状態/メモと目次62,429/15,376/47,053を保存後照合。旧メモ0件維持。Git内exports/types-14669.xlsx、ユーザー版 ../outputs/translation-types-14669/Wishes_種類別翻訳一覧.xlsx。実Excelアプリ・ゲーム実画面/進行/保存は未検証。旧ROM・セーブ保持。

管理画面は14669/47053へ再読込済み。次は **MauvilleCity_BikeShop100・Gym101・House1/2計33・Mart10・PokemonCenter1F/2F計19・VerdanturfTown42、計305行**。参考候補1,863メッセージ/4,985行は未レビュー/未適用。mapグラフ460候補・pending11,178。全ストーリー未完了、C/共通/動的移動/未抽出を含めた完成証明はまだない。トークンが戻ったらこの続きから再開。

## 以前の会話65（2026-10-27）

開始時HEAD8d75392931・クリーン、status/stats61,722/14,121/47,601一致。キンセツ141行/サイクリング入口各7行/カラクリ入口79行、計234行60メッセージ追加し61,722/14,355/47,367。4ファイルのカタログpending0。参考111行を全英語と照合して編集、残り123行は新訳。レビューreviews/dialogue-mauville-trick-65.review.md。ミツルのcanの能力とtoughの難しさ、叔父の励まし/家族関係、テッセンの発電装置停止依頼、電話/テレビ、8か所の隠れ場所と人形のロボット口調・報酬分岐を保持。人形の後を追えない主体は曖昧なので、日本語も主語を省略し断定しない。辞書137語。

yomiyasu script lint0、meaning_risk5は叔父の原文も疑問、It pleases meの喜び、赤/青テントの保持2件、ミツルのcanの断言を確認。宛名3件は「おじさん:」を宛名とした誤検出で話者は不変。勢い1は原文句点/疑問に対応。check bad0/26マス超0、audit0、78テスト成功。4ファイルの非.string行は開始時と完全一致。ロジック/フラグ/セーブ構造不変。

GBA ../outputs/gba/wishes-jp-14355-f64d32bf.gba、SHA256 7d5958c1ba5c1dd05b42b7edaba2c138ee29e9e5bd97bbaa34cb3ca4a458d9ca。source commit 641831f09c308878430a632e3b6d3db947e1c75f。build/emerald-jp-dlg14355-clean、ROM29,828,680B/EWRAM230,024/IWRAM28,600。BPS再適用全バイト一致、../artifacts/wishes-jp-ui14355-f64d32bf-patch.zip。実画面・対戦/電話/依頼/受領/隠れ場所/進行/保存は未検証。旧ROM・セーブ保持。

Excel14シート・62,429行11列、137語、全原文/訳文/ID/状態/メモと目次62,429/15,062/47,367を保存後照合し一致。旧メモ0件維持。Git内exports/types-14355.xlsx、ユーザー版 ../outputs/translation-types-14355/Wishes_種類別翻訳一覧.xlsx。Excel実アプリ未確認。管理画面は14355/47367へ再読込済み。

次は **Route110_TrickHousePuzzle1〜8計241行→TrickHouseEnd73行、計314行**。参考候補は1,945メッセージ/5,164行（未レビュー/未適用）。mapグラフ460候補・map内pending11,492。全ストーリー未完了。新ラベル/本文差分0でもC/共通/動的移動/未抽出を含む完成証明ではない。トークンが戻ったらこの続きから再開。

## 以前の会話64（2026-10-27）

開始時HEAD8327209c42・クリーン、status/stats61,722/13,803/47,919一致。カイナ残り155行＋Route110の163行、計318行78メッセージ追加し61,722/14,121/47,601。7ファイルとSlateportCity*の全スクリプトでカタログpending0。未抽出/実画面/到達性の網羅ではない。参考131行は全英語と照合して編集、残り187行は新訳。レビューreviews/dialogue-slateport-route110-64.review.md。

BattleTentCorridorには旧コンテストの会話がある。地名に合わせて内容を改稿しない。カゼノ45回の広告、衝突を避けつつ加速という助言、TM41/2連続、3歩右/2歩上、より多いselectionの要望を保持。参考の貸出男性の冗談や速すぎ注意は採用せず英語へ戻す。ハルカ/ユウキ/オダマキの親子関係・助言/登録、姓名判断、性格/道具/交換、旧コンテストの二次審査説明も原文を保持。辞書132語。

yomiyasu script lint0、meaning_risk6はlittle scary/市場interesting、居場所/新名の疑問、Magma rulesの引用、seemsの推量を英語で確認して維持。勢い候補1は英語の句点/省略記号へ合わせたもの。check bad0/26マス超0、audit0、78テスト成功。7ファイルの非.string行は開始時と完全一致。ロジック/フラグ/セーブ構造不変。

GBA ../outputs/gba/wishes-jp-14121-ecf33154.gba、SHA256 da4038b6bb265fa625b468590d75f3d3ca438abb0472191d1db7c17a60a3ef1c。source commit 08826ced1dd18dcb01985b00f76185eb74c22d0c。build/emerald-jp-dlg14121-clean、ROM29,831,048B/EWRAM230,024/IWRAM28,600。BPS再適用全バイト一致、../artifacts/wishes-jp-ui14121-ecf33154-patch.zip。実画面・旧コンテスト到達性/対戦/受領/評価/命名/交換/進行/保存は未検証。旧ROM・セーブ保持。

Excel14シート・62,429行11列、132語、全原文/訳文/ID/状態/メモと目次62,429/14,828/47,601を保存後照合し一致。旧メモ0件維持。Git内exports/types-14121.xlsx、ユーザー版 ../outputs/translation-types-14121/Wishes_種類別翻訳一覧.xlsx。Excel実アプリ未確認。管理画面は14121/47601へ再読込済み。

次は **MauvilleCity/scripts.inc141行→Route110_SeasideCyclingRoadNorthEntrance/SouthEntrance各7行→Route110_TrickHouseEntrance79行、計234行**。その後カラクリの各Puzzle1〜8計241行とTrickHouseEnd73行。参考候補は1,983メッセージ/5,275行（未レビュー/未適用）。mapグラフ460候補・map内pending11,726。全ストーリー未完了。新ラベル/本文差分0でもC/共通/動的移動/未抽出を含めた完成証明ではない。トークンが戻ったらこの続きから再開。

## 以前の会話63（2026-10-27）

開始時HEAD1e2d9487cf・クリーン、status/stats61,722/13,528/48,194一致。カイナ造船所1F59行/2F7行、港107行、ファンクラブ102行、計275行59メッセージ追加し61,722/13,803/47,919。4ファイルのカタログpending0。参考107行は英語全文と照合して編集、残り168行は新訳。レビューreviews/dialogue-slateport-facilities-63.review.md。技術の進歩と造船の芸術、ハギの決定/能力/確信、船旅の勧め、Most peopleの範囲、道具交換/バンダナを持たせる指示、会長の反復と感情、なつき度・タウリンを与えた過去の体験を保持。ツガ/ハギろうじん/てんきけんきゅうじょを追加し辞書127語。

yomiyasu script lint0、meaning_risk3は原文も受付の疑問（文種2候補）と「つくれるはずじゃ」の能力/確信を確認して維持。硬化/勢い候補なし。check bad0/26マス超0、audit0、78テスト成功。4ファイルの非.string行は開始時と完全一致。ロジック/フラグ/セーブ構造不変。

GBA ../outputs/gba/wishes-jp-13803-ac863b7a.gba、SHA256 470d0691502940322023f7f551d2135069b57147d841377e6cdfea256199ccb1。source commit ba05c63bff3cd5601c92290bc629134803c48b34。build/emerald-jp-dlg13803-clean、ROM29,834,568B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、../artifacts/wishes-jp-ui13803-ac863b7a-patch.zip。実画面・引渡し/乗船/潜水艇/交換/コンテスト/なつき度/進行/保存は未検証。旧ROM・セーブ保持。

Excel14シート・62,429行11列、127語、全原文/訳文/ID/状態/メモと目次62,429/14,510/47,919を保存後照合し一致。旧メモ0件維持。Git内exports/types-13803.xlsx、ユーザー版 ../outputs/translation-types-13803/Wishes_種類別翻訳一覧.xlsx。Excel実アプリ未確認。管理画面は13803/47919へ再読込済み。

次は **カイナの残り155行（BattleTentCorridor76/Lobby23・House8・Mart8・NameRatersHouse30・PokemonCenter1F10）→Route110の163行、合計318行**。参考候補は2,026メッセージ/5,406行（未レビュー/未適用）。mapグラフ460候補・map内pending12,044。全ストーリー未完了。新ラベル/本文差分0を完成根拠にせず、C/共通/動的移動/未抽出も継続調査する。トークンが戻ったらこの続きから再開。

## 以前の会話62（2026-10-27）

開始時HEAD1a00e8a997・クリーン、status/stats61,722/13,312/48,410一致。海の科学博物館1F102行・2F114行、計216行52メッセージ追加し61,722/13,528/48,194。2ファイルのカタログpending0。参考89行は全英語に照合して編集し残り127行は新訳。レビューreviews/dialogue-slateport-museum-62.review.md。滝の実験を「たきのぼり」に変えない。生命は海に依存というアオギリの主張、出航の義務、50円/約70%/2倍超/小面積に数万トン、液体/塩分濃度/地層/雨などの説明を保持。原文の科学説明は勝手に改稿しない。名称4件追加し124語。

yomiyasu script lint0、meaning_risk6は英語で全て確認し保持（円の表記、30%補足削除、否定保持、よさそうの推量、砂のできる=生成、ボスの不在）。勢い候補1は英語も説明文句点。check bad0/width超0、audit0、78テスト成功。非.string行は2ファイルとも開始時と完全一致。ロジック・フラグ・セーブ構造不変。

GBA ../outputs/gba/wishes-jp-13528-e052d444.gba、SHA256 8ef23afe7a0e09ed5defd1ebbf02afcf8999638d5dfa4fa659d143f8a8412e0b。source commit 9255a74a5c10b20c962ed55b19b13db3fd3ce5e1。build/emerald-jp-dlg13528-clean、ROM29,837,544B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、../artifacts/wishes-jp-ui13528-e052d444-patch.zip。実画面・入館/支払/わざマシン受領/戦闘/引渡し/展示/進行/保存は未検証。旧ROM・セーブ保持。

Excel14シート・62,429行11列、124語、全原文/訳文/ID/状態/メモと目次62,429/14,235/48,194を保存後照合し一致。旧メモ0件維持。Git内exports/types-13528.xlsx、ユーザー版 ../outputs/translation-types-13528/Wishes_種類別翻訳一覧.xlsx。Excel実アプリ未確認。管理画面は13528/48194へ再読込済み。

次は **SternsShipyard_1F/2F（59+7）→Harbor（107）→PokemonFanClub（102）、計275行**。参考候補は2,056メッセージ/5,513行（未レビュー/未適用）。mapグラフ460候補・map内pending12,319。全ストーリー未完了。新ラベル/本文差分0でも未抽出/共通/C/動的移動を含めた完成証明にならない。全ストーリー目標を維持して継続する。

## 以前の会話61（2026-10-27）

開始時HEAD4eac53441e、status/stats61,722/13,034/48,688一致。SlateportCity/scripts.incの278行・78メッセージを追加し61,722/13,312/48,410。対象ファイルのカタログpending0。参考155行は全英語と照合し編集、残り123行は新訳。レビューreviews/dialogue-slateport-city-61.review.md。マイルをキロへ変えない、Game Boy Advanceを省略しない、船のカイナ〜ミナモ区間と海が全生命を支える意味を保持。アクア団の要求や疑問・エニシダの反復、伝聞/推測の強さを英語に照合。人名3件追加し辞書120語。

yomiyasu script lint0、meaning_risk2は原文へ戻した距離単位/支払い理由の疑問として確認して保持。check bad0/width超0、audit0、78テスト成功。非.string行は開始時と完全一致。ロジック・フラグ・セーブ構造は不変。

GBA ../outputs/gba/wishes-jp-13312-5ff7ff21.gba、SHA256 ccfb80edf15508343462fe4ab5913a639c90075960a7351013b2d8369871cc92。source commit 8e11b2cd9d0a22af2fa5d4bd62d590721d3ce803。build/emerald-jp-dlg13312-clean、ROM29,839,784B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、../artifacts/wishes-jp-ui13312-5ff7ff21-patch.zip。実画面・潜水艇強奪/取材/エニシダ分岐・きのみ交換・進行・保存は未検証。旧ROMとセーブ保持。

Excel14シート・62,429行11列の原文/訳文/ID/状態/メモ、120語、目次62,429/14,019/48,410を保存後照合し一致。旧メモ0件維持。Git内exports/types-13312.xlsx、ユーザー版 ../outputs/translation-types-13312/Wishes_種類別翻訳一覧.xlsx。Excel実アプリ未確認。

次は **SlateportCity_OceanicMuseum_1F/2F（102+114=216行、参考45+44行）**。参考候補は2,087メッセージ/5,602行（未レビュー、未適用）、mapグラフ460候補・map内pending12,535。新ラベル/本文差分0でも全ストーリー完成ではない。C/共通/動的移動/未抽出は未網羅。全ストーリー目標は継続。管理画面のローカル版は http://127.0.0.1:8766 （13,312/48,410へカタログ再読込済み）。

## 以前の会話60（2026-10-27）

f453861b4b・クリーン、status/stats61,722/12,795/48,927一致から継続。LilycoveCity/scripts.incの239行を追加し61,722/13,034/48,688。LilycoveCity*の全スクリプトでカタログpending0（未抽出/到達性/実画面の網羅ではない）。参考74行を英語と照合して編集、残り165行は新訳。レビューreviews/dialogue-lilycove-city-60.review.md。原文のハルカ/ユウキ・ミシロ等を勝手にWishesの別設定へ統一しない。宿は参考JPで「みんしゅく モナミ」を確認、そらのはしらも辞書へ入れ117語。画商の売買の誤字、参考の弱い確度や余分な伝聞、ぜんこくからという範囲を校正。PLAYER/KUNは元行維持、KUNは現実装で空と確認し幅ツールは変更せず。

yomiyasu script lint0、meaning_risk2はI know I'll get the chanceとIf world becomes ours, it will be happierの英語へ戻した確度を指すため、確認して維持した（警告を消すために意味を弱めない）。check bad0/width超0、audit0、78テスト成功。対象の非.string行は開始時と完全一致。イベント・フラグ・セーブ構造は不変。

GBA ../outputs/gba/wishes-jp-13034-334b895d.gba、SHA256 357b8032d2b6cd6e49633aa076a6afb49718e62c33957d8bfc836f79b46b9735。source commit 4b6026448e87593e2660ef54699f74ef8f124a78。build/emerald-jp-dlg13034-clean、ROM29,842,792B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、../artifacts/wishes-jp-ui13034-334b895d-patch.zip。実画面・ライバル・アクア団封鎖・街/施設・進行・保存は未検証。旧ROM・セーブ保持。

Excel14シート・62,429行11列の原文/訳文/ID/状態/メモ、117語、目次62,429/13,741/48,688を保存後照合し一致。旧メモ0件維持。Git内exports/types-13034.xlsx、ユーザー版 ../outputs/translation-types-13034/Wishes_種類別翻訳一覧.xlsx。Excel実アプリは未確認。

次は **data/maps/SlateportCity/scripts.inc（278行、参考同形155行）**、続いて **SlateportCity_OceanicMuseum_1F/2F（102+114=216行、参考45+44行）**。参考候補は2,139メッセージ/5,757行へ再生成（未レビュー、未適用）。mapグラフ460候補・map内pending12,813。新ラベル/本文差分0でもストーリー完成ではない。C/共通/動的移動/未抽出の網羅は未確認。

## 以前の会話58/59（2026-10-27）

6673307502・クリーン、status/stats61,722/12,422/49,300一致から継続。FanClub176行、ContestLobby68行/ContestHall129行、計373行追加し61,722/12,795/48,927。3ファイルのカタログpending0。レビューreviews/dialogue-fanclub-contest-58-59.review.md。参考候補から37メッセージ133行を取得し英語と照合、残り240行は新訳。参考初期値はreference.tsv、採用した133行はprovenanceへJP/英語参照コミットを明記。参考の誤字「だたもの」、英語にない「ついに」、coffeeがお茶になっていた箇所、can't alwaysの確度、父センリのpower/charisma/showmanshipの3要素を修正。変数の原文行位置はcheckで確認し移動していた初稿を戻した。原文に残る家族設定を勝手にWishesの別設定へ統一していない。辞書115語。

yomiyasu script lint0/meaning_risk0（保証ではない）、check bad0/width超0、audit0、78テスト成功。3スクリプトの非.string行は開始時と完全一致。イベント・フラグ・セーブ構造は不変。

GBA ../outputs/gba/wishes-jp-12795-50c0023a.gba、SHA256 c00abbe204acfc1b32fdf29cd321e24c79af9c901f358f98f8793e50eecb69dd。source commit b20d2dc3ba277fd4460bc95a98ddf1119df12626。build/emerald-jp-dlg12795-clean、ROM29,845,544B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、../artifacts/wishes-jp-ui12795-50c0023a-patch.zip。実画面・人気変動・コンテスト・リボン・展示・進行・保存は未検証。旧ROM・セーブ保持。

Excel14シート・62,429行11列の原文/訳文/ID/状態/メモ、115語、目次62,429/13,502/48,927を保存後照合し一致。旧メモ0件も維持。Git内exports/types-12795.xlsx。管理画面カタログも12,795/48,927へ再読込済み。Excel実アプリ未確認。

次は **data/maps/LilycoveCity/scripts.inc（239行）**。ミナモ関連でここだけカタログpendingが残る。参考同形候補74行があるので全文意味レビューして活用し、通常の手順を通す。候補一覧を再生成し残り2,160メッセージ/5,831行（未レビュー、未適用）。mapグラフ460候補・map内pending13,052。新ラベル/本文差分0や参考候補0だけで全ストーリー完成とは判断しない。

## 以前の会話57（2026-10-27）

b400dde3e2・クリーン、status/stats61,722/12,212/49,510一致から継続。美術館1F83行・2F74行、House3の53行、計210行を追加し、61,722/12,422/49,300。3スクリプトのカタログpending0。レビューreviews/dialogue-museum-house-57.review.md。現代作品の修飾先と子どもの不明な性別を校正。絵の比喩・限定/否定・伝聞・館長の願いと報酬、ポロックの低いなめらかさ数値/高いレベル等を保持。参考JPの語彙を照合し辞書113語。yomiyasu script lint0/meaning_risk0、check bad0/26マス超0、audit0。3ファイルの非.string行は開始時と完全一致。ソース適用時75テスト、参考抽出3テスト追加後78テスト成功。

GBA ../outputs/gba/wishes-jp-12422-8d1e7738.gba、SHA256 6590e809d18326fbb5a25f9bffdf8de91b09f99baefd30532748d2170c3af585。source commit 975eb39549698f68a1c7a048e5aaee537ad55775。build/emerald-jp-dlg12422-clean、ROM29,849,576B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、../artifacts/wishes-jp-ui12422-8d1e7738-patch.zip。実画面・展示/報酬・ポロック・コンテスト・進行・保存は未検証。旧ROM・セーブ保持。

Excel14シート・全62,429行11列と113語、原文/訳文/ID/状態/メモ、目次62,429/13,129/49,300を保存後照合し一致。Git内exports/types-12422.xlsx、ユーザー版 ../outputs/translation-types-12422/Wishes_種類別翻訳一覧.xlsx。旧メモ0件も維持。Excel実アプリは未確認。

次は **LilycoveCity_PokemonTrainerFanClub（176行）→ContestLobby（68行）/ContestHall（129行）** など残る流用マップ/共通会話。mapグラフ460候補・map内pending13,425。新ラベル/本文差分候補0でも全ストーリー完了ではない。

省力化のため `reference_dialogue_drafts.py` と `reference-dialogue-candidates.json` を追加。英語本文がExpansion1.15.3と一致し、参考JPの改行/改ページ/スクロール/終端が同形で、変数・制御の行位置も同じものだけを抽出。2,197メッセージ/5,964行は **未レビューの候補** で、ソース適用も翻訳数への加算もしていない。FanClubは17メッセージ66行、ContestHallは20メッセージ67行が候補。条件分岐ファイルや既訳混在等は除外。日本語参考の意味が英語と一致する保証はないので必ず全文レビューし、通常のscript_batch/check/width/yomiyasu/update_catalog手順を通す。候補は次のカタログ更新後に再生成する。

## 以前の会話54〜56（2026-10-27）

ユーザーが「トークンが戻ってきたら再開」を追記。全ストーリー目標を維持し、331aa609ea・クリーン、status/stats61,722/11,984/49,738一致から再開。百貨店3F10行、百貨店案内/屋上/港/技忘れ/センター/民家128行、宿90行の計228行を追加。今回は61,722/12,212/49,510。12ファイルのカタログpending0。レビューreviews/dialogue-lilycove-54-56.review.md。辞書110語。

PAWの補正上限は実装のPAW_MOD_CAP=12、正負clampを確認。原文BOONは恩恵だが実装は別能力低下も伴う。原文を勝手に「のろい」へ変えず「おんけい」と訳し、相違をレビューへ記録。wtfの苛立ちも保持。わすれオヤジの2変数は各10マスを見積もり、「か」だけ省いて26マス、感嘆符を維持。確度・否定対比・エニシダ/タイドリップごう等既訳を保持。yomiyasu script lint0/meaning_risk0（保証ではない）、check bad0/width超0、audit0、75テスト成功。非.string行は12スクリプトすべて開始時と完全一致。イベント・フラグ・セーブ構造は不変。

GBA ../outputs/gba/wishes-jp-12212-b632ef42.gba、SHA256 db0bb183feb169ff3ae6793b184a9a5b02ea0f8456a42ebbe952aac92cbf4c66。source commit 7851df5ad8a1a4637858192f08afd4e07a22494c。build/emerald-jp-dlg12212-clean、ROM29,852,136B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、../artifacts/wishes-jp-ui12212-b632ef42-patch.zip。実画面・船・技忘れ・PAW・図鑑報酬・進行・保存は未検証。旧ROM・セーブ保持。

Excelは14シート・全62,429行11列、原文・訳文・ID・状態・メモ、110語、目次62,429/12,919/49,510を保存後照合し一致。旧保存メモ0件も維持。Git内 localization/exports/types-12212.xlsx。管理画面カタログも再読み込みし12,212/49,510を確認。Excel実アプリは未確認。

次は **LilycoveCity_LilycoveMuseum_1F/2F（83+74=157行）とLilycoveCity_House3（53行）** を候補に、残る流用マップ・共通会話を続ける。新ラベル/Expansion本文差分候補は両方0だが、元の本文をそのまま使う未訳も対象。mapグラフは460候補・map内pending13,635。深さを実プレイ順と誤認しない。最も浅いpendingのBattleFrontier_OutsideWest（143行）はShinTokyoからの船だが、ShinTokyo/scripts.incに「post-game only」と明記されるので、メイン進行より先に行ける証拠ではない。C/共通/動的移動/未抽出を含めた全ストーリー完了の証拠はまだない。

## 以前の会話52/53（2026-10-27・ユーザー指定の区切り）

ストーリー全訳目標を維持して338行追加し、61,722 / 11,984 / 49,738。百貨店2F/4Fとえんとつやま225行、ゲームコーナー113行。4ファイルのカタログpending0。旧ラベルの独自会話、AMの不可逆な説明、WASTER BALLとMASTER BALLの取り違え・ルージュラの成人向け冗談、隕石分岐、NPCと景品28件を訳した。非.string行は開始時HEAD1f63741fc1と完全一致。制御・変数・価格・番号を保持。意味レビュー記録はreviews/dialogue-stores-gamecorner-52-53.review.md。yomiyasu lint0/meaning_risk0、check bad0/26マス超0、audit0、75テスト成功。用語107件。

GBA `../outputs/gba/wishes-jp-11984-a22b978a.gba`。SHA256 b22b30ca900adb5810678685a15cde49e2ca8d4162c3119a3ac73c9811bb921d。source commit ba882ed501。新規OBJ_DIR build/emerald-jp-dlg11984-clean、ROM29,854,568B/EWRAM230,024/IWRAM28,600。BPS再適用バイト一致、パッチ ../artifacts/wishes-jp-ui11984-a22b978a-patch.zip。実画面・購入・AM・景品交換・隕石・進行・保存は未検証。旧ROM・セーブ不変。

Excelは14シート・全62,429行11列、用語107件、メモ、目次62,429/12,691/49,738を保存後照合し一致。旧版メモ0件も維持。Git内コピー localization/exports/types-11984.xlsx、表更新済み。初回はNodeのheap上限で失敗し、--max-old-space-size=8192で再出力成功。管理画面のカタログも再読み込み済み。実Excelアプリ未確認。

次に必ず行うこと: **LilycoveCity_DepartmentStore_3F** の独自10行。旧ラベルGaveCarbosToSpeedUpMonは実際には「HM/TMは使ったがAMって何だ？」、ItemsBestForTougheningPokemonはMANKEY'S PAWでポケモンが暴走する話、WantMoreEnduranceはPAW補正の重複/±12制限とWISH/BOONのリスク。元Emeraldの栄養ドリンク会話に戻さない。どうぐの既訳と仕様を調べてから訳す。その後、到達する流用マップ・共通会話も継続する。

新ラベル候補0でもストーリー完成ではない。`story_content_diff.py --reference ../artifacts/expansion-1.15.3-reference` を追加。英語タグ expansion/1.15.3（b669d9ccf9c148070b99eba11cd65f6071be0741）とラベル内本文を比較し、上記10行/3ラベルを検出。`story-content-differences.json` に原文双方を保持。改行・空白だけを無視し、本文が同じ元Expansionの会話もWishesで使われるため翻訳は必要。mapグラフ460候補・map内pending13,835は過大推定で、実プレイ順や完成率ではない。C/共通/動的移動/未抽出は未網羅。比較用参照はGit外、同じタグで再取得可能。

作業履歴が長くなったため、成果物をpushし、ユーザー指定どおりこの区切りで中断する。全ストーリー・全日本語化は未完了。再開時はAGENTS/status/stats/Gitを照合し、上記3Fから進める。

## ローカル翻訳管理画面（2026-10-27）

ユーザー指定で、このMac専用の翻訳管理画面を追加。起動は `python3 tools/localization/admin.py` または `tools/localization/start-admin.command`。URL http://127.0.0.1:8766 。説明は `tools/localization/ADMIN_README.ja.md`。

全カタログ61,722行の種類・マップ・状態別閲覧、全文検索、訳稿・メモのSQLite保存、用語辞書、ID付きJSON出力、静的検査を実装。保存だけではゲームソースを変更しない。ソースへの反映は、レビュー済みの未翻訳通常会話の全行に限定。固定長UI/C/既訳混在/条件分岐/点字はJSON経由で既存手順に戻す。反映時のバックアップ・stale検査・失敗時復元を実装。DB・バックアップは `../artifacts/translation-admin`（Git外）。別CLIで翻訳を進める場合は管理画面の元データを再読み込みする。同時にソースを編集しない。

開始時HEAD e7a88d7db4・クリーン、status/stats61,722/11,646/50,076一致。会話・看板pending38,317行。分類件数は既存種類別Excelと一致。カタログ外名称707件は管理画面では対象外、既存Excel参照。既存59＋管理画面16テストの計75件成功。適用・復元は一時チェックアウトで検証、実ゲームソースへの適用は行っていない。Safariで表示・検索・編集画面を確認。本文付きの保存/JSON/エラー検査はHTTPで確認（ネイティブUIの本文入力は確認できず）。テスト訳稿は除去済み。

ゲームの翻訳、カタログ、status数値、ROM、セーブはこの追加では不変。新しいGBAは出していない。最新GBAは引き続き `../outputs/gba/wishes-jp-11646-c6f4a737.gba`。ストーリー全訳・図鑑全訳は未完了、以前の翻訳再開候補は以下を維持。

## 1. いまの状態

| 項目 | 値 |
| --- | --- |
| 作業場所 | `/Users/owner/Desktop/Wish/Wishes-Game`（git、ブランチ main、origin=Etoile-T/Wishes-of-Tomorrow-JP） |
| 最新の翻訳コミット | `a92092b64baf4bd037634b6f47c9b1c3af14e20f`（この後にdocsコミットあり） |
| カタログ | 61,722候補のうち翻訳済み15,239、pending46,483（完成率ではない） |
| カタログ外 | トレーナー名（`src/data/trainers.party`、約500種）とマップ名（`region_map_sections.json`、229件）は翻訳済み |
| テスト | python3 -m unittest discover -s tools/localization -p 'test_*.py' で78件成功 |
| 最新ビルド | pokeemerald-jp-dlg15239.gba（ROM29,819,240B / EWRAM230,024B / IWRAM28,600B） |
| ユーザー向けGBA | ../outputs/gba/wishes-jp-15239-256d909c.gba（旧ROM・セーブ保持） |
| 配布パッチ | ../artifacts/wishes-jp-ui15239-256d909c-patch.zip / localization/patch-manifest-ui15239.json |
| Excel | ../outputs/translation-types-15239/Wishes_種類別翻訳一覧.xlsx（Git内exports/types-15239.xlsx、全62,429行） |

ゲーム画面での表示・進行の確認は、ほぼ未実施。ビルド成功を「正常に遊べる」とは報告しない。

最新会話50/51: ストーリー全訳を維持して再開し、418行・96メッセージを翻訳。研究所219行（既訳7行は維持）、赤いギャラドス／Frostwoodの家族・店・センター／ゴンドラ／初ジムRedFatalityの199行。旧フォルダ名・旧ラベルだけで原作の台詞と判断しない。RustboroCity_GymのRoxanneという旧ラベルでも本文はWishesのRedFatalityなので、JP参考のツツジの台詞をコピーしてはいけない。今回7マップのカタログpendingは0になったが、ストーリー全訳は未完了。

開始時HEADd402c37619・クリーン、status/stats61722/11228/50494一致。今回は61722/11646/50076。7スクリプトの非.string行は開始時と完全一致。変数・改ページ・スクロール・終端は元行を維持。check bad0/26マス超0、catalog validate、audit超過0、59テスト成功。yomiyasuは研究所lint0、Frostwoodは一覧見出し末尾コロン警告1を機能上必要として維持、meaning_riskは両方0。辞書101語。エニシダ／タイドリップごうは参照JPと照合。Yiffは「イフ」の暫定音写。乱暴な口調、スキー用語、Halo 3/MLG/Instagram等は原文に沿って残した。

GBA wishes-jp-11646-c6f4a737.gba、ROM29,858,024B/EWRAM230,024/IWRAM28,600。新規OBJ_DIR build/emerald-jp-dlg11646-clean、ログ../artifacts/build-dlg11646.log。SHA256 196deb34ff6fb239a74289e0b0672961948265d27efa94be0f210368cf4e5518。BPS再適用バイト一致。種類別Excel11646版は14シート・全62,429件、適用済み12,353（カタログ11,646＋名称707）、未翻訳50,076。保存後の全行11列・ID・生文字列・状態・メモ・辞書101語・目次集計を照合。実画面・ジム・バッジ・列車解放・家族イベント・図鑑報酬・保存再読み込みは未検証。

次の候補: story_candidates.pyで新ラベルを調査。story-new-label-candidates.jsonは51行・34ラベル（主にMauvilleCity_GameCornerのWotText景品メニューと確認、LilycoveCity_DepartmentStore_2FのWASTER BALL／ルージュラの夫婦会話8行、4FのAM説明9行、MtChimneyの隕石説明4行）。これらを優先しつつ、同じ旧ラベルのまま上書きされた本文も必ず調べる。新ラベルがゼロでも完了ではない。

マップグラフは460候補・map内pending14,173。条件・地形・C/共通/動的ワープ・未抽出文字列は未網羅。必要なら同バージョンの英語expansionを調べ、元の英語をラベルと本文の両方で比較してWishesの書き換えを識別する。参照JPでは英語本文の比較はできない。研究所でもクラークソンの独自7行とオダマキ由来の219行が混在するため、原文の人物名を勝手に統一しない。

ユーザーのストーリー全訳目標は保持。作業履歴の長いこの区切りをpushして指定の中断とし、再開時は上記から継続。図鑑全件は保留。

以下は以前の記録。

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

1. 把握済みの独自イベントはDragonKeeper / MewtwoPostGameまで適用済み。ミナモ関連のカタログ会話は適用済み。次は111/112/113番道路/ハジツゲ等、流用マップのストーリー／NPC会話。図鑑はユーザー指定で保留。並行して、元Emeraldフォルダを流用した独自会話と未抽出テキストを調べる。簡易棚卸しの限界は上記を参照。
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
node --max-old-space-size=8192 ../artifacts/translation-review-build/build_review.mjs "$PWD" ../outputs/translation-review-NNNN '会話・看板（対象マップ名）' --all --by-type
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
