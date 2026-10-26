# 竜の番人・ミュウツーのクリア後イベント

2026-10-26。DragonKeeper 34件、MewtwoPostGame 29件、計63件（カタログの行単位）。

- DragonKeeper: 2人の番人の挑戦、勝敗の台詞、3つから1つのタマゴを選ぶ会話、残りのタマゴ、フライゴンとタツベイの描写。いにしえの血筋、空の蛇、屋根を覚える竜などの比喩を維持。
- MewtwoPostGame: 船小屋の施錠、ドラコの挑戦・敗北・譲渡・空き不足・後日談。アーマードミュウツーを兵器ではなくパートナーとして扱う主張を保持。名前・台詞以外の戦闘・贈与処理は変更していない。
- タマゴは3つから1つ、残り2つという数値を照合。残りのタマゴが他の人に約束されている原文は断定なので、下書きの「だろう」を除いた。「よろいは はずすな」は命令を追加していたため、原文の説明どおり「よろいは そのままだ」に修正。
- ドラコの最後の「Maybe」は「かも しれない」として残した。主人公の性別は指定しない。アーマードミュウツー、ドラゴンのタマゴを暫定辞書へ追加。

## yomiyasu

script / essayの指針で原文資料と読み比べ、lint → run → verify。lint候補0件。意味変化の候補1件は、上記「だろう」の除去による断定化。英語原文の `promised to other hands` に戻すための修正と確認した。下書きの誤った推量を維持しない。句点・口調・比喩・制御文字はプロジェクト指定どおり保持。

`yomiyasu-check: executed via=verify run=20261026T022317Z-1653b3fd attempt=1 final=sha256:22d7d98b4c39 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=1 replay=skipped`

検査記録は自動合格や人間の承認ではない。

## 検査

dialogue_tools check: bad 0、width:26マス超0。catalog validate成功、audit推定幅超過0、51テスト成功。対象2マップのpendingは0、会話以外のスクリプト内容は翻訳前と一致。Claude Codeの名前入力（kana3）には変更を加えていない。ビルド・パッチ・全件Excelの最新結果はstatus.jsonとHANDOFF_CODEX.mdに記録。今回の会話・進行は実機未検証。
