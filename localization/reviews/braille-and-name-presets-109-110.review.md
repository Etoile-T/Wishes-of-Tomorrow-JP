# 109/110: FRLG名前候補と点字（ストーリー範囲の最後の129行）

前回は「英語のまま」としていた129行を、仕組みを足して翻訳した。50,102/11,620。data/maps・data/text・data/scriptsのpendingは0。

## 109 FRLG名前候補（42行）
data/text/new_game_intro_frlg.inc。名前はinclude/naming_input.hの保存形式に合わせ `{JPN_NAME_n}`＋かな（5文字以内）で記述（例 `{JPN_NAME_3}サトシ$`）。最大でも2+5+EOS=8バイトでplayerName/rivalNameに収まる。「NEW NAME」はメニュー項目なので `{JPN}じぶんで きめる$`。catalog validateのJPN_NAMEスパン検査を通過。IS_FRLGが0のEmeraldビルドではこの経路は実行されない（実機未確認）。

## 110 点字（87行）
点字フォントは6点の全64セルを持つ（bit: 1=0x01 4=0x02 2=0x04 5=0x08 3=0x10 6=0x20）。tools/preproc の .braille がLatinのみだったので、かなを日本点字（カナ点字）に変換する ReadJapaneseBraille を追加。濁点(5)・半濁点(6)・拗音(4/4+5/4+6)の前置符号、や/ゆ/よ/わ/を/ん/っ/ー/。を扱う。対応表は tools/localization/braille_ja.py から tools/preproc/braille_ja.h を生成（テストで一致を確認）。英字・数字・既存記号の挙動は不変。
訳は点字の表記法に従い表音・分かち書き（助詞の「は」は「わ」、長音は「ー」）。封印の部屋の外壁10面（ABC…WXYZ・ピリオド・カンマ）は五十音の10行（あ行〜わ行）に置換。内壁・砂漠/島/古代塚の指示（ひだり ひだり / した した。/ そして / いわくだきを つかえ。等）とFRLGの遺跡の文は意味を保持。読点はcharmap外のため省略。
test_braille_ja.py: セルの規則、未対応かなの拒否、ヘッダの再生成一致、braille.inc全行でpreproc出力と参照実装の全バイト一致。ROMに日本語点字列が入り、英語の「GO UP HERE」列が無いことを確認。点字窓の実表示は未確認。

check bad0、validate成功、audit推定超過0、82テスト成功、ビルドexit0（build/emerald-jp-dlg50102-clean、ROM29,576,296B/EWRAM230,024/IWRAM28,600）。
