SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "{JPN}こどもなんか ようは ねえんだ!\n"
	.string "さっさと うちに かえりな!$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "{JPN}うちに かえりたい……$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "{JPN}しゅっせして したっぱたちを\n"
	.string "あごで つかいたいんだよ……$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "{JPN}あの せんすいてい… なかが せまくて\n"
	.string "からだじゅう いてえんだよ!$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "{JPN}まけると よけい いてえ!$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "{JPN}うばった せんすいてい だけどよ\n"
	.string "のりごこちが さいあくでさ。\l"
	.string "なかが きゅうくつ すぎるんだ!$"

