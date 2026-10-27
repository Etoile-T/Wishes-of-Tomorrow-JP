CinnabarIsland_PokemonLab_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonLab_Entrance_OnTransition
	.byte 0

CinnabarIsland_PokemonLab_Entrance_OnTransition::
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil::
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
	return

CinnabarIsland_PokemonLab_Entrance_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_DrFujiPhoto::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_MeetingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_RAndDRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TestingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji::
	.string "{JPN}カツラと フジろうじんの\n"
	.string "しゃしんだ。\p"
	.string "ふたりで かたを ならべて\n"
	.string "にっこり わらっている。$"

CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively::
	.string "{JPN}わたしたちは まいにち ポケモンを\n"
	.string "くわしく けんきゅう しています。\p"
	.string "めずらしい ポケモンを しらべて ほしいと\n"
	.string "もちこむ ひとも おおいんですよ。$"

CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji::
	.string "{JPN}けんきゅうじょの そうせつしゃ…\n"
	.string "フジはかせの しゃしん?!$"

CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign::
	.string "{JPN}ポケモン けんきゅうじょ\n"
	.string "かいぎしつ$"

CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign::
	.string "{JPN}ポケモン けんきゅうじょ\n"
	.string "けんきゅう かいはつしつ$"

CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign::
	.string "{JPN}ポケモン けんきゅうじょ\n"
	.string "じっけんしつ$"

