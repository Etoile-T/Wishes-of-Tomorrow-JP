SSAnne_1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
	.string "{JPN}ポケモン だいすき!\n"
	.string "きみは?$"

SSAnne_1F_Room2_Text_TylerDefeat::
	.string "{JPN}わあ! \n"
	.string "すごいや!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
	.string "{JPN}ねえ ねえ!\n"
	.string "ともだちに なってよ いいでしょ?\p"
	.string "そしたら ポケモンを こうかん したり\n"
	.string "いろいろ できるよ。$"

SSAnne_1F_Room2_Text_AnnIntro::
	.string "{JPN}この ポケモンたちは\n"
	.string "せかいじゅうで あつめたのよ!$"

SSAnne_1F_Room2_Text_AnnDefeat::
	.string "{JPN}そんな!\n"
	.string "せかいじゅう まわって あつめたのに!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
	.string "{JPN}わたしの ポケモンを きずつけたわね!\p"
	.string "ポケモンセンターで ちゃんと\n"
	.string "かいふく させて ちょうだい!$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
	.string "{JPN}わたしと こどもたちで\n"
	.string "せかいいっしゅう している のです。$"

