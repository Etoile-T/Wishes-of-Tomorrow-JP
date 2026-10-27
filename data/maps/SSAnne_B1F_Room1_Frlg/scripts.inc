SSAnne_B1F_Room1_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
	.string "{JPN}おい! まけたら ふなばたから\n"
	.string "うみに つきおとすぞ!$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
	.string "{JPN}ぐわっ!\n"
	.string "こどもに まけるとは!$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
	.string "{JPN}おきに でると ときどき クラゲの\n"
	.string "ポケモンが ただよって くるんだ。$"

SSAnne_B1F_Room1_Text_BarnyIntro::
	.string "{JPN}よう みなれない かおだな!\p"
	.string "うみの もんか やまの もんか しらんが\n"
	.string "まあ よって はなして いけ。\p"
	.string "おれの ポケモンは みんな うみ そだちだ。$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
	.string "{JPN}くそっ!\n"
	.string "にがしちまった!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
	.string "{JPN}おまえを おれの じょしゅに\n"
	.string "してやろうと おもったのに!$"

