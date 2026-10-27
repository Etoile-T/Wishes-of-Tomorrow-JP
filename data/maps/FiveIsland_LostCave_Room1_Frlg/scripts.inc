FiveIsland_LostCave_Room1_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room1_EventScript_Lawson::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAWSON, FiveIsland_LostCave_Room1_Text_LawsonIntro, FiveIsland_LostCave_Room1_Text_LawsonDefeat
	msgbox FiveIsland_LostCave_Room1_Text_LawsonPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room1_Text_LawsonIntro::
	.string "{JPN}ひいいいいっ!\p"
	.string "こだいの いせきだと おもったのに\n"
	.string "ゆうれいが うようよ してる!$"

FiveIsland_LostCave_Room1_Text_LawsonDefeat::
	.string "{JPN}ひいいいいっ!\n"
	.string "おたすけ!$"

FiveIsland_LostCave_Room1_Text_LawsonPostBattle::
	.string "{JPN}ここから でようと してるのに\n"
	.string "いつも おなじ ばしょに もどるんだ。\p"
	.string "いわの かずが ヒント\n"
	.string "なのかも…$"

