# 会話58・59 — ファンクラブとコンテスト

開始時HEAD6673307502・クリーン、status/stats61,722 / 12,422 / 49,300一致。ファンクラブ176行とコンテストロビー68行/ホール129行、計373行を追加し12,795件。対象3ファイルはカタログpending0。ミナモ関連で残るカタログpendingはLilycoveCity/scripts.incの239行。全ストーリー/到達性/未抽出の網羅を意味しない。

参考再利用: reference_dialogue_drafts.pyの候補からFanClub17メッセージ66行、ContestHall20メッセージ67行を取得し、英語全文と意味を照合して編集した。初期参考訳はreference.tsvに保存。残る240行は英語から訳した。参考133行には参照JP b07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5efと英語Expansion b669d9ccf9c148070b99eba11cd65f6071be0741をprovenanceに記録。候補を無検証で適用したものではなく、人による承認を受けたという意味でもない。

ファンクラブ: 人気の変動、他トレーナーへ乗り換えるファンと一途なファン、トウキ/センリ、父との比較、強さを語りながら自分も分からないという落ちを維持。参考の「だたもの」を「ただもの」へ修正。原文にない「ついに」は削除し、勝利を望む台詞は単なる応援へ丸めない。センリのpower/charisma/showmanshipの3要素を「ちから/みりょく/みせかた」で表した。If I don't cheerの条件は「わたしが…おうえんしなきゃ」で維持。2箇所で初稿の変数が別の原文行へ移っていたのをcheckで検出し、元行へ戻した。map.jsonのLASS/MAN_4/POKEFAN_M/LITTLE_GIRL/NINJA_BOY/BOY_2/WOMAN_3/EXPERT_Fを確認し、人物別の口調を維持。英語原文に残る父センリの設定を、Wishesの他の家族設定へ勝手に統一していない。

コンテスト: 審査員/司会、カテゴリ別の案内、アピールやコンディション、絵を描く→展示の相談/承諾/辞退→リボンのイベントを保持。参考JPの「お茶」は英語ではcoffeeなので「コーヒー」へ修正。can't always winは「いつも勝てるとは限らない」として、ほとんど勝てないという意味にしない。pristine beauty、by a lotの程度も維持。司会/審査員の『形式はプロジェクトの「名前: 本文」へ統一。看板3種は英語のallured/charmed/impressedに合わせた。強さ/かわいさ等のアピールの意味や観客の反応を、実装の効果説明に勝手に差し替えない。きゅうけつ/みずあそび/はなびらのまいは既訳と照合。トウキ/センリをシリーズ用語へ追加し辞書115語。

yomiyasu scriptのrun（lint/diff/materials）→全候補確認→verify。FanClubは条件文を1回修正して再run。条件の検出件数が減った候補は「なったら」から「しなきゃ」の書換えで、条件そのものは保持。感嘆符の減少は参考の！！を英語原文の!へ合わせたもので、意味を弱めるためではない。指示語は同一人物/話題を受け、人物間の敬体/常体はそろえない。コーヒーの追加候補は英語coffeeを根拠に採用。句点はプロジェクト指定として維持。lint0/meaning_risk0は翻訳の正確性の保証ではない。

yomiyasu-check: executed via=verify run=20261026T202401Z-09429dd9 attempt=2 final=sha256:518a08bd81e9 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

yomiyasu-check: executed via=verify run=20261026T202402Z-f3628327 attempt=1 final=sha256:214519600439 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

script_batch→check bad0/width26マス超0→update_catalog dry-run/apply→catalog validate、audit推定超過0、78テスト成功。3ファイルの.string以外の行は開始時と完全一致。変数/改ページ/スクロール/終端は元行に保持。ゲームロジック・イベントフラグ・セーブ構造は変更していない。実画面・人気変動・コンテスト・リボン・絵の展示・進行・保存は未検証。
