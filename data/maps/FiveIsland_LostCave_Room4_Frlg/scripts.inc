FiveIsland_LostCave_Room4_Frlg_MapScripts::
	.byte 0

FiveIsland_LostCave_Room4_EventScript_Laura::
	trainerbattle_single TRAINER_PSYCHIC_LAURA, FiveIsland_LostCave_Room4_Text_LauraIntro, FiveIsland_LostCave_Room4_Text_LauraDefeat
	msgbox FiveIsland_LostCave_Room4_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_LostCave_Room4_Text_LauraIntro::
	.string "{JPN}この どうくつには ふしぎな ちからが\n"
	.string "はたらいて いると おもうの。$"

FiveIsland_LostCave_Room4_Text_LauraDefeat::
	.string "{JPN}ただしい トンネルに はいらないと\n"
	.string "さきへは すすめないわよ。$"

FiveIsland_LostCave_Room4_Text_LauraPostBattle::
	.string "{JPN}さっき おんなのひとが どうくつの\n"
	.string "おくへ はいって いったわ。$"

