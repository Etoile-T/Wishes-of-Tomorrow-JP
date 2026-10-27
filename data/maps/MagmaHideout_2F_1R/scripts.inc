MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "{JPN}なに なに なに?\p"
	.string "ここに はいって これるのは\n"
	.string "マグマだんの メンバー だけのはず!\p"
	.string "なのに あなたは\n"
	.string "マグマだんの ふくを きていない……\p"
	.string "えーい あやしい やつめ!\n"
	.string "わたしと しょうぶ しなさい!$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "{JPN}あわわわ……\n"
	.string "マグマだんの プライドが……$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "{JPN}さむがりの ひとは\n"
	.string "マグマだんに はいると いいわよ。$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "{JPN}こらこら! そこで とまれ!\p"
	.string "オレが だまって みのがして\n"
	.string "すどおり させると おもってんのか?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "{JPN}うおっ すげえ!\n"
	.string "まいった!$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "{JPN}こんなことなら だまって すどおり\n"
	.string "させたほうが よかったかも……$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "{JPN}あはっ!\n"
	.string "しんにゅうしゃ だ!$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "{JPN}ぬおお……$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "{JPN}もう まけちゃったし。\p"
	.string "これ いじょう ぐるぐる\n"
	.string "はしりまわる ひつよう あるのか?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "{JPN}おっ おっ!\n"
	.string "しんにゅうしゃ だ!$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "{JPN}うぬぬ……$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "{JPN}じつは オレ バトルは にがて なんだ……$"

