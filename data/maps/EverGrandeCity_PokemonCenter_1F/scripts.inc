EverGrandeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott
	end

EverGrandeCity_PokemonCenter_1F_EventScript_TryShowScott::
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	return

EverGrandeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_EVER_GRANDE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Woman::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon, MSGBOX_NPC
	end

EverGrandeCity_PokemonCenter_1F_EventScript_Scott::
	lock
	faceplayer
	msgbox EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	call_if_eq VAR_FACING, DIR_WEST, EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	playse SE_EXIT
	waitse
	removeobject LOCALID_EVER_GRANDE_SCOTT
	release
	end

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExitNorth::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_EventScript_ScottExit::
	applymovement LOCALID_EVER_GRANDE_SCOTT, EverGrandeCity_PokemonCenter_1F_Movement_ScottExit
	waitmovement 0
	return

EverGrandeCity_PokemonCenter_1F_Movement_ScottExitNorth:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Movement_ScottExit:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EverGrandeCity_PokemonCenter_1F_Text_LeagueAfterVictoryRoad:
	.string "{JPN}ポケモンリーグは\n"
	.string "チャンピオンロードを ぬけると すぐ!\p"
	.string "ここまで きたら\n"
	.string "まえに すすむしか ないでしょ?$"

EverGrandeCity_PokemonCenter_1F_Text_BelieveInYourPokemon:
	.string "{JPN}ながく けわしい チャンピオンロード……\p"
	.string "まるで じんせいの みちのりを\n"
	.string "もういちど あゆむ ようだ……\p"
	.string "ポケモンを しんじて\n"
	.string "ぜんりょくを つくしなさい!$"

EverGrandeCity_PokemonCenter_1F_Text_ScottHappyForYou:
	.string "{JPN}エニシダ: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} ついに\n"
	.string "ポケモンリーグまで のぼりつめたね!\p"
	.string "ボクも うれしいよ!\n"
	.string "おうえん した かいが あったよ!\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}が もし ポケモンリーグの\n"
	.string "チャンピオンに なったら……\p"
	.string "そのときは また れんらく するよ。\p"
	.string "じゃあ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}。\n"
	.string "ちょうてんを めざして がんばって!$"

