# 会話バッチ50

開始時HEAD d402c37619・クリーン、status/stats61722/11228/50494一致。ユーザーのストーリー全訳目標を維持し再開。

研究所の未訳48メッセージ219行。初回ポケモン受取・図鑑受取／全国化・チャンピオン後・ジョウト御三家の報酬・電話・助手・調べる文言を含む。既訳のクラークソン博士に関する7行は維持し、原文に残るPROF.BIRCHをオダマキはかせとして訳す。人物や設定を勝手に入れ替えない。原文側で人物表記が混在している点は残る。助手はVAR_BIRCH_LAB_STATE>=3で旧原文の研究説明へ分岐する（270行付近）。実プレイの到達状態は未確認。
Scott/S.S.Tidalは参考JPの同じ会話からエニシダ／タイドリップごうと照合。図鑑UIのニックネーム確認は変数を元の2行目に保ったまま、日本語の語順を整えた。原文のloveは単なる「親子はいいもの」という評価に変えず、親子の愛情の描写として残した。

yomiyasu script lint/run/verify実施。原文と英日を読んで確認。指示語は同一メッセージの前後を指すため保持。meaning_risk=0は翻訳の正確性の保証とは扱わない。

yomiyasu-check: executed via=verify run=20261026T105420Z-4d6aab5c attempt=1 final=sha256:d03fef26d64e mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

script_batch→check bad0/width26マス超0→update_catalog dry-run/apply。校正後のバッジ文1件も小さなIDバッチで再適用し、元バッチと一致。catalog validate・audit推定超過0・59テスト成功。7スクリプトの.string以外は開始時と完全一致。名前・数字・変数・改ページ・スクロール・終端の行位置を保持。ゲームロジック・イベント・セーブ構造は不変。実画面・進行・電話・報酬は未検証。
