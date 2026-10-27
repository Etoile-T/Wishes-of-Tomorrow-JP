MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "{JPN}リーダーの いうことは ぜんぶ\n"
	.string "わかってる。 でもさ……\p"
	.string "ちょうこだいの ポケモンを ほりおこしたり\n"
	.string "ひとの いんせきを\l"
	.string "うばったり……\p"
	.string "ちょっと やりすぎ だと おもうんだ。\n"
	.string "おまえは どう おもう?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "{JPN}やっぱり オレたち なにか\n"
	.string "まちがってる きが する。$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "{JPN}まけて なんだか スッキリしたよ!\p"
	.string "こんど リーダーに あったら\n"
	.string "オレたちの やってること きいてみるよ!$"

