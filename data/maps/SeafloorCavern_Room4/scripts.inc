SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "{JPN}なんだ おまえは?\n"
	.string "どこから はいってきた?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "{JPN}まけちまった……$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "{JPN}でぐちが みつからねえ!\p"
	.string "こわくなんか ねえぞ! かんちがいすんな!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "{JPN}なんだ おまえは?\n"
	.string "どこへ いく つもりだ?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "{JPN}かてなかった!$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "{JPN}あいぼうが ちずを せんすいていに\n"
	.string "わすれて きやがった!\p"
	.string "まったく やくたたずだろ?$"

