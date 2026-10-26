# 技教えNPCの会話47

ユーザーが全ポケモン翻訳からセリフ優先へ変更。図鑑全件作業は調査だけで、今回ポケモンデータの翻訳は適用していない。開始時HEAD0e4e587e2d、クリーン、status/stats61722/10782/50940一致。

data/text/move_tutors.incの41メッセージ・156カタログ行を全件手訳。Swagger/Rollout/Fury Cutter/Mimic/Metronome/Sleep Talk/Substitute/Dynamic Punch/Double-Edge/Explosionの教える前・辞退・選択・習得後と共通確認。既存のホウエンの技教えスクリプトから参照されるが、Wishesの通しプレイでの到達性は未確認。独自マップのストーリーがすべて完了した意味ではない。

技名は公式日本語（いばる・ころがる・れんぞくぎり・ものまね・ゆびをふる・ねごと・みがわり・ばくれつパンチ・すてみタックル・だいばくはつ）。CHAIRMANは「かいちょう」、MOSSDEEP/SOOTOPOLISはトクサネ／ルネ。英語の語呂合わせは、いばる自慢、ころがる、だいばくはつの人気等を文脈ごと維持。Double-Edgeの「両刃」の比喩は「もろはのつるぎ」で保持し、技はすてみタックルとする。

Mimicの若者が老人を真似る口調と、辞退時に素へ戻る箇所を維持。原文の妻はかみさん、Sleep Talk側は老人男性（EXPERT_M）。SubstituteとDouble Edgeは元マップのWOMAN_3/WOMAN_1を確認して女性口調とした。RolloutのFAT_MANは中立の「わたし」。プレイヤーの性別は決めない。

コインの「てじなが当たる」は不自然なため「コインあて」へ修正。FortreeCity_House2の英語に、どちらの手にコインがあるか当てる遊びが記述されていることを確認。yomiyasu lint/script/run/verify実施、lint0・meaning_risk0。diffの指示語候補は同一会話の前後を指すため維持。最初の敬体は共通のシステム確認、他は各NPCの発話なので統一しない。

yomiyasu-check: executed via=verify run=20261026T050257Z-ff6a70cd attempt=2 final=sha256:97de80861007 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

script_batchで生成、check bad0・26マス超0、元の各行の改ページ／スクロール／終端を保持。catalog validate・audit推定超過0・59テスト成功。.string行以外のスクリプトは開始時HEADと完全一致。ラベル・イベント・フラグ・セーブ構造は変更なし。実画面・技習得・イベント進行は未検証。

最終成果物: ../outputs/gba/wishes-jp-10938-57fd012b.gba。BPS再適用はSHA256/CRC検査とバイト一致。種類別Excel10938版は14シート・全62,429件、全行11列・ID・原文・訳文・状態・メモ・91用語と目次集計を保存後照合し一致。旧ブック保存済みメモ0件、新版と一致。検証ログ../artifacts/logs/excel-types-10938-verify.log。実Excelアプリとゲーム画面は未確認。
