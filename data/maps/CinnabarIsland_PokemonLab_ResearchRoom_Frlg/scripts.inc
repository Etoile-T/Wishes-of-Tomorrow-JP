CinnabarIsland_PokemonLab_ResearchRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MetronomeTutor::
	goto EventScript_MetronomeTutor
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
	.string "{JPN}イーブイは 3しゅるいの ポケモンの\n"
	.string "どれかに しんか できる。$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
	.string "{JPN}メールが とどいている。\p"
	.string "… … …\p"
	.string "でんせつの とりポケモンは\n"
	.string "3びき いる。\p"
	.string "フリーザー サンダー\n"
	.string "そして ファイヤー。\p"
	.string "その ゆくえは わかっていない。\p"
	.string "ハナダシティ ちかくの どうくつを\n"
	.string "しらべる よていだ。\p"
	.string "ポケモン けんきゅうチームより…$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
	.string "{JPN}こはくいろの パイプだ!$"

