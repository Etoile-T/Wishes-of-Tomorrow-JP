# ムネン村からつながる流用マップの会話

元フォルダ名のままの建物へのワープを調査し、MunenVillage→LittlerootTown_MaysHouse_1F（直接）→2F（階段）を確認。両階の17メッセージ142行を翻訳。母親の変数が英語son/daughterのままになる依存箇所もsrc/field_specials.cで2件翻訳し、計144件。ハルカ・ユウキ・オダマキはかせを公式表記として辞書に追加（94語）。PLAYER・KUN・RIVAL・STR_VAR_1を元と同じ行に保持。英語で明示された女性主人公の分岐はそのまま訳し、性別判定は変えない。原文のMay/Brendan/BirchをWishesの別人物名へ置換せず、既存のストーリー内容を保持する。

開始時HEAD e5240a966f、クリーン、status/stats61722/10938/50784一致。script_batch→check bad0→26マス超0→update_catalog dry-run/apply。yomiyasu scriptのlint0・meaning_risk0。原文と英日を照合、制御・ページ・スクロール・終端は元の行を維持。

yomiyasu-check: executed via=verify run=20261026T102623Z-3059f941 attempt=1 final=sha256:578f88b63783 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

全59テスト・catalog validate・audit推定超過0成功。.string以外のスクリプトと、field_specials.cの文字列／空白以外のコードは開始時HEADと一致。実画面・イベント進行・タマゴ処理・保存再読み込みは未検証。

最終成果物: ../outputs/gba/wishes-jp-11228-5e8294d0.gba。BPS再適用のSHA256/CRC・バイト一致成功。14シートの全件Excel11228版を保存後に62,429行11列・94用語・メモ・目次集計まで照合。../artifacts/logs/excel-types-11228-verify.log。実Excelアプリ・ゲーム画面未検証。
