# 118〜122: 進行中に表示されるC文字列（strings.c・フロンティア/ドーム・クレジットほか）

- 118 src/strings.c 532項目、119 field_specials/frontier_util/battle_dome/lilycove_lady/mystery_event_msg/follower_helper/pokenav_match_call_data/battle_message/player_pc/field_weather 416項目、120 エンディングのクレジット146項目。
- 幅の規則: 会話枠に出る文は26マス2行、ラベルは英語の文字数×0.75以内（英字は日本語より幅が狭い）。公式名を優先して上限をわずかに超えたラベル（あかいビードロ、さいだいHP、いりょく/ 等）がある。{CLEAR_TO}で列を揃える61項目は日本語8px/字で次の列に食い込まないことを計算で確認。widthの残り3件（変数のみの行、通算成績、クリアタイム）は中身が数字のため26マス内。
- クレジットの人名・社名・作品名78項目は英語のまま（日本語版のスタッフロールは漢字表記）で、{JPN}も付けない。役職はディレクター/プログラム等。
- battle_message.c の差し込み部品 "are"/" is"/"'s" は「は」「は」「の」。
- 121: バトルチューブ受付の「タマゴ{STR_VAR_1}は さんか できません」を「タマゴ{STR_VAR_1}。」に修正（STR_VAR_1が gText_FrontierFacilityAreInelegible「は さんか できません」で終わるため二重になる）。バトルテントは STR_VAR_1 が「と〜は」で終わる別経路なので「 さんか できません。」のまま。
- 122: gText_123Dot[][3] は固定長3バイトで {JPN}/{ENG} が入らずビルドエラーになったため「1.」「2.」「3.」を英語のままに戻した。
- 新しい暫定表記: エントリーコール登録名（しゃちょう、たよれるひと ほか）、ミナモのおねえさんのポケモン名・形容詞、バトルビデオ、おおもじ/こもじ/きごう。

check bad0、validate成功、audit推定超過0、83テスト成功、ビルドexit0（build/emerald-jp-dlg54527-clean、ROM29,570,376B）。メニュー・PokéNav・フロンティア記録画面・クレジットの実表示は未確認。
