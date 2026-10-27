TwoIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

TwoIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_TWO_ISLAND
	end

TwoIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

TwoIsland_PokemonCenter_1F_EventScript_GBAKid::
	msgbox TwoIsland_PokemonCenter_1F_Text_HaveYouVisitedGameCorner, MSGBOX_NPC
	end

TwoIsland_PokemonCenter_1F_EventScript_BugCatcher::
	msgbox TwoIsland_PokemonCenter_1F_Text_OldLadyLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_PokemonCenter_1F_Text_HaveYouVisitedGameCorner::
	.string "{JPN}もう ゲームコーナーには\n"
	.string "いってみた?\p"
	.string "ひとりで いっても だめよ。\n"
	.string "ともだちを つれて いかなくちゃ。$"

TwoIsland_PokemonCenter_1F_Text_OldLadyLivesOutOnCape::
	.string "{JPN}2のしまに すんでる ひとは\n"
	.string "あまり いないの。\p"
	.string "みさきの ほうに おばあさんが\n"
	.string "ひとり すんでるわ。\p"
	.string "いつから いるのか わからない\n"
	.string "くらい むかしからよ。$"

