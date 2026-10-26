# 会話バッチ52・53

開始時HEAD 1f63741fc1・クリーン。status/statsは61,722 / 11,646 / 50,076で一致。

338行を追加し11,984件にした。LilycoveCity_DepartmentStore_2F/4F、MtChimneyの225行とMauvilleCity_GameCornerの113行。対象4ファイルはカタログpending0。ただしWishesの全ストーリー・到達性・未抽出テキストの網羅を示さない。

百貨店ではMASTER BALLとWASTER BALLの取り違え、ルージュラとの成人向けの冗談、AMの不可逆な特性上書きの説明を維持。Waster Ballは既訳のウェイスターボールに統一。原文の古い「わざマシン50種類」はNPCが読んだカタログの内容なので、ゲームの総数に勝手に書き換えていない。

えんとつやまではマツブサの陸地拡張の主張と挑発、アオギリの警告、隕石を外す/残す分岐、フエンせんべい200円、対戦前後・再戦の会話を保持。「エネルギーをためているようだ」の不確かさも維持した。メリッサ・シーラ・シャーリーはtrainers.partyのFemale、シェルビーはExpert F、ソーヤーはMale/Hikerを確認。話者の性別を名前だけから推定していない。

ゲームコーナーではゴミ箱にコインケースがあるという独自の案内を翻訳（元Emeraldの隣家案内へ戻していない）。景品28件は既訳の種族・技・道具名と照合。価格・番号・CLEAR_TO/FONT_SMALLは変更せず、コイン表記を日本語にした。JPNでは英字も8pxなので、名前がCLEAR_TOの72px/112pxより前に収まり、価格の右端が208px以内になることをソース上で検査。動的リストは0,0からのdynmultichoice。確認文は変数2つを各10マスと見積もると31マスだったため、「ですね?」に短縮して26マス以内にした。表示時の実際の変数長・フォント切り替え・リスト操作は未確認。

辞書へAbility Machine/AM/Waster Ball/Mt. Chimney/Maxie/Archieの6件を暫定登録し107語。公式名と既訳は参照したが、独自用語の最終確定を意味しない。

yomiyasuはscript指定でrun（lint/diff/materials）とverify実施。バッチ52は初稿を原文と読み比べ、意味・口調を変える校正の必要を認めず維持。53は幅のため確認文を1箇所短縮。指示語は景品・同じ台のゲーム・直前の話題を指すため維持。店員の敬体、客の常体は人物が異なるので統一しない。句点はプロジェクト指定のため保持。リンターのmeaning_risk=0は正確性の保証ではない。

yomiyasu-check: executed via=verify run=20261026T170338Z-a480bcc6 attempt=1 final=sha256:159cb919b1bc mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

yomiyasu-check: executed via=verify run=20261026T170339Z-a3d3168a attempt=1 final=sha256:6797138b0522 mode=rewrite doc_type=script checks=lint,diff,materials meaning_risk=0 replay=skipped

script_batch → check（bad0）/width（26マス超0）→ update_catalog dry-run/apply → catalog validateを実施。4スクリプトの.string以外の行は開始時と完全一致。変数・改ページ・スクロール・終端を元の行に維持。ゲームロジック・イベントフラグ・セーブ構造は変更していない。75テスト成功、audit推定超過0。実画面・イベント進行・AM使用・購入・景品交換・対戦・保存再読み込みは未検証。

成果物: ../outputs/gba/wishes-jp-11984-a22b978a.gba（SHA256 b22b30ca900adb5810678685a15cde49e2ca8d4162c3119a3ac73c9811bb921d）。新規OBJ_DIR build/emerald-jp-dlg11984-cleanでビルド成功。ROM29,854,568B/EWRAM230,024B/IWRAM28,600B。BPS適用後のSHA/CRCとバイト列が一致。種類別Excelは14シート・全62,429行11列のID/原文/訳文/状態/メモ、用語107件、目次62,429/12,691/49,738を保存後照合。既存ブックの保存メモ0件も維持。Nodeの既定heap上限で初回出力が失敗したため、8192MiBへ引き上げて再生成し成功。検査ログ ../artifacts/logs/excel-types-11984-verify.log。Excel実アプリ・ゲーム実画面は未確認。
