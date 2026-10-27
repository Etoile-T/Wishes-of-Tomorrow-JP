SSAnne_B1F_Room3_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanIntro::
	.string "{JPN}おまえ みたいな げんきな こどもは すきだぜ!$"

SSAnne_B1F_Room3_Text_DylanDefeat::
	.string "{JPN}ぐわっ!\n"
	.string "まけた!$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
	.string "{JPN}うみの ポケモンは ふかい ところに いる。\n"
	.string "つりざおが ないと つれないぜ!$"

