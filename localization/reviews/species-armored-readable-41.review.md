# アーマードミュウツーの表示修正41

ユーザーの画面報告で5px圧縮による字形欠落を確認。種族名をARミュウツーへ変更し、FONT_SMALL_NARROWERの日本語は元の8px・12px高へ戻した。ARは英字、残り5文字だけJPN_NAME_5とする。かなを圧縮しない。会話の正式名は維持。

旧英語名・前版の日本語フル名・現短縮名は種族と全使用バイトが一致した場合のみ表示時に現名へ変換する。任意のニックネームは維持。前版から保存した個体も対象、セーブ書き換え・構造変更なし。

57テスト成功。全名照合・不一致名の保持と制御境界を確認。ARの実フォント幅＋かな5字は48pxで55px欄に収まる。画面・保存・通信は未実行。

yomiyasu lint候補0、名称はユーザー指定どおり維持。

yomiyasu-check: executed via=verify run=20261026T031728Z-4166ad92 attempt=1 final=sha256:16685e90a246 mode=rewrite doc_type=manual checks=lint,diff,materials meaning_risk=0 replay=skipped
