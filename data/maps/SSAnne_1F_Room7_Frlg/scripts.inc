SSAnne_1F_Room7_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasIntro::
	.string "{JPN}わたしは こどくな たびびと…\p"
	.string "ともと よべるのは たびの とちゅうで\n"
	.string "つかまえた ポケモンたち だけ…$"

SSAnne_1F_Room7_Text_ThomasDefeat::
	.string "{JPN}ああ わが ともよ…$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
	.string "{JPN}ともだちは たいせつに しなさい!$"

