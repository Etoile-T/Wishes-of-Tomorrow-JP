BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FRONTIER_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "{JPN}ここで みたことも ない\n"
	.string "ポケモンを つかってる ひとが いたの\p"
	.string "すくなくとも トレーナーズスクールでは\n"
	.string "ならわなかったよ\p"
	.string "ああいう ポケモンって\n"
	.string "どこで つかまえられるのかな$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "{JPN}よしっ! おつぎは バトルアリーナだ!\n"
	.string "パソコンから ぴったりの\l"
	.string "ポケモンを つれて いかなきゃ!$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "{JPN}うふふ… わたしは ぜーんぶの ちょうせんを\n"
	.string "この コ だけで がんばるんだ もんね!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "{JPN}エネコ: みゃ みゃーっ!$"

