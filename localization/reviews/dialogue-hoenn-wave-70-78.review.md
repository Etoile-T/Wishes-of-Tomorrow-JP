# 会話70〜78: ホウエン本編マップの残り（一括）

開始HEAD（会話69適用後）15,497/46,225。9グループ6,486行をClaude Codeのサブエージェントが並列で下書きし、主セッションが英語と照合・検査して適用。21,983/39,739。参考訳（日本語版系の参照、計2,521行）は英語と全文照合し、Wishesで内容が違う箇所は英語へ合わせた（各グループの主な差分は下記）。ホウエンのホウエン本編（_Frlg・BattleFrontier以外）のマップscripts.incはpending0。

| バッチ | 範囲 | 行 | lint | meaning_risk |
|---|---|---|---|---|
| fallarbor-lavaridge-70 | ハジツゲ残り・りゅうせいのたき・デコボコさんどう・フエン・マグマ団アジト | 806 | 1 | 3 |
| petalburg-littleroot-71 | トウカ・ジム・ミツルの家・トウカのもり・ミシロ・コトキ | 673 | 1 | 4 |
| rustboro-72 | カナズミ全域 | 660 | 0 | 2 |
| dewford-routes-73 | 101〜106/109番道路・ハギ・ムロ・いしのどうくつ | 794 | 0 | 2 |
| fortree-routes-74 | 114〜119番道路・てんきけんきゅうじょ・ヒワマキ | 756 | 0 | 6 |
| mtpyre-aqua-75 | おくりびやま・アクア団アジト・120〜128番道路 | 554 | 0 | 0 |
| mossdeep-76 | トクサネ全域・うちゅうセンター | 591 | 0 | 4 |
| sootopolis-77 | ルネ・ジム・かいていどうくつ・めざめのほこら・そらのはしら | 789 | 2 | 3 |
| league-misc-78 | キナギ・サイユウ/四天王・チャンピオンロード・すてられぶね・タイドリップ号ほか | 863 | 1 | 2 |

lint候補はジム看板「〜 にんてい トレーナー:」の表札ラベル3件、実在の「しょうめん ゲート」、原文の否定対比（衣装ではなく〜）で、いずれも維持。

主な判断: 参考訳と英語が違う箇所（例: センリ再戦、ママの到着「ついたわよ」、マグマ団の「戻ってきた一人かと思った」、Wishes独自のトクサネ/ルネ台詞）は英語に合わせた。プレイヤーの性別を決める「ぼうや」は「おチビちゃん」へ修正。英語「SOOTOPOLIS SPACE CENTER」（f09c102b36720210）は原文どおり「ルネの うちゅうセンター」とした（Wishes側の記述をそのまま保持）。392 degrees（華氏）は参考訳の「200ど」（摂氏換算で同値）。トクサネの手紙署名前の空白42個は26マス制限のため12個へ短縮。ルネの記録「{STR_VAR_2}'s {STR_VAR_3} giant!」は幅のため「giant」を省略。かけら交換看板はCLEAR_TO位置を英語のまま、名前の幅が次の位置に収まることを計算で確認（実画面未確認）。新しい暫定表記はglossaryに追加（ワルダ、ペッパーけ、カセキ ふっかつマシン、ねがいの ふだ、ミスター・シー、カクタスごう、タイムボード、プー プヒャー）。

各verify行:
- fallarbor-lavaridge-70: yomiyasu-check: executed via=verify run=20261027T023055Z-088d7a47 attempt=1 final=sha256:cbe49f53cbb5 mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
- petalburg-littleroot-71: yomiyasu-check: executed via=verify run=20261027T023056Z-ffaf92b2 attempt=1 final=sha256:74b884e5d330 mode=compose doc_type=script checks=lint,materials meaning_risk=4 replay=skipped
- rustboro-72: yomiyasu-check: executed via=verify run=20261027T023056Z-fde2741f attempt=1 final=sha256:e40cf7abb968 mode=compose doc_type=script checks=lint,materials meaning_risk=2 replay=skipped
- dewford-routes-73: yomiyasu-check: executed via=verify run=20261027T023057Z-2641735d attempt=1 final=sha256:f95ba54d8922 mode=compose doc_type=script checks=lint,materials meaning_risk=2 replay=skipped
- fortree-routes-74: yomiyasu-check: executed via=verify run=20261027T023058Z-bc14d1d6 attempt=1 final=sha256:1b9e8542ef07 mode=compose doc_type=script checks=lint,materials meaning_risk=6 replay=skipped
- mtpyre-aqua-75: yomiyasu-check: executed via=verify run=20261027T023058Z-50b10101 attempt=1 final=sha256:edd74bc35225 mode=compose doc_type=script checks=lint,materials meaning_risk=0 replay=skipped
- mossdeep-76: yomiyasu-check: executed via=verify run=20261027T023059Z-6866b838 attempt=1 final=sha256:25d0f9793ee9 mode=compose doc_type=script checks=lint,materials meaning_risk=4 replay=skipped
- sootopolis-77: yomiyasu-check: executed via=verify run=20261027T023100Z-01f1391e attempt=1 final=sha256:816f664a4f14 mode=compose doc_type=script checks=lint,materials meaning_risk=3 replay=skipped
- league-misc-78: yomiyasu-check: executed via=verify run=20261027T023100Z-c467a649 attempt=1 final=sha256:25a482ef1b0a mode=compose doc_type=script checks=lint,materials meaning_risk=2 replay=skipped

check bad0・26マス超0（全9バッチ）、catalog validate成功、audit推定超過0、78テスト成功。ロジック/フラグ/セーブ構造は不変（.string行のみ）。自動検査は意味保持の合格証明ではない。実ゲームの画面・進行は未検証。
