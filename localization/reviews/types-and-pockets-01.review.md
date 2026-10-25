# タイプ・バッグ分類と道具説明の見直し

2026-10-26。ゲーム内プレイヤー向けの名称と短い説明。文書種類manual。

タイプ情報41文字列（19タイプと「なし」の名称、21種別文）とバッグ分類12文字列を追加。謎タイプの名称「???」は維持。タイプ画像19枚は参考コミットb07a7ec5f798ebc4cf3641613bbd8ddbb9b6f5efから個別移植。すべて32×16、インデックス画像、既存パレット一致を確認し、左右比較画像で表記を確認した。mystery/none、戦闘アイコン、コンテスト画像は置換していない。

「フェアリー」は5グリフとJPN/ENG4バイト、EOSで10バイト必要。既存9バイト欄ではコンパイル時に超過したため、ROMのみのTypeInfo.nameに言語切替用4バイトを確保した。TYPE_NAME_LENGTH定数、種別ID、相性、セーブ用構造は変更していない。

道具説明の古代品7件は、参考訳にのみあった「3000年前」を削除し、英語原文にある「高く売れる」を復元。短文の意味を読み比べ、追加の修正不要と判断。全道具説明の意味レビューが済んだとは扱わない。

lint/manualの候補0件。runで日本語下書き・最終稿・英語資料を照合しverifyで最終稿一致を確認。名称と短文のため言い換えは加えなかった。検査件数は翻訳品質の点数ではない。

yomiyasu-check: executed via=verify run=20261025T195535Z-79122aad attempt=1 final=sha256:079eaf3acece mode=rewrite doc_type=manual checks=lint,diff,materials meaning_risk=0 replay=skipped

yomiyasu-check: executed via=verify run=20261025T195653Z-6d13cd12 attempt=1 final=sha256:e1731c1b651c mode=rewrite doc_type=manual checks=lint,diff,materials meaning_risk=0 replay=skipped

ソース検査ではitems.h/abilities.h/types_info.h/strings.cの非文字列トークンが英語スナップショットと一致。制御コード・未定義文字・固定長タイプ欄検査を実施。実ゲーム表示、タイプ画像を使用する全UI、戦闘文脈は未検証。
