SSAnne_1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurIntro::
	.string "{JPN}ぶれいな こぞうめ!\n"
	.string "かってに はいって くるとは!$"

SSAnne_1F_Room5_Text_ArthurDefeat::
	.string "{JPN}ふん! しつれいな こどもだ!\n"
	.string "れいぎと いうものを しらんのか!$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
	.string "{JPN}ひとりに して くれたまえ!\n"
	.string "でていけ!$"

