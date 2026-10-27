# 111〜117: セリフ系C文字列とトレーナー名

- 111 src/data/text/match_call_messages.h 312行: PokéNavエントリーコールのチェック画面（さくせん/つかうポケモン/じこしょうかい2行）。表示枠は幅16タイルなので各項目15マス以内・1行で訳した（自前スクリプトで確認）。収めるために一部の語を省略（例「スタイルは じゅうなんに」）。
- 112 src/data/text/follower_messages.h 138行: 連れ歩きの様子。会話枠26マス・2行まで。
- 113/116 フロンティア・バトルテント・トレーナーヒル・トレーナータワーの対戦相手名とポケモンのニックネーム1,036行: `{JPN_NAME_n}`＋かなで記述。名前はフィールドサイズ内（フロンティア/テント trainerName[8]→5字、タワー name[11]→8字、ヒル name[13]→10字）、ニックネームは既訳の種族名（nickname[11]→8字以内）。タワーの仮データ2行（空・$詰め）は非テキストとして原文どおり確定。
- 114 カントーのトレーナー名: src/data/trainers_frlg.party の Name: 624行を `{JPN}名前{ENG}`（12バイト以内）に。ジムリーダー・四天王・サカキは公式名、バイカーのGOONは「ごろつき」。対訳は localization/trainer-names.json に追加。
- 115 弟子の名前 96行: 各弟子の公式日本語名（言語配列の先頭）を全言語欄に `{JPN_NAME_n}` で。
- 117 生成ファイル src/data/trainers.h / trainers_frlg.h 1,519行: trainerprocが .party から生成（gitignore）。再生成後の内容とカタログ行を順に照合して記録（書き込みはしない）。trainers.party の4件は以前からの方針で英字のまま。

check bad0、validate成功、audit推定超過0、82テスト成功、ビルドexit0（build/emerald-jp-dlg51700-clean）。PokéNav・連れ歩き・対戦画面の実表示は未確認。
