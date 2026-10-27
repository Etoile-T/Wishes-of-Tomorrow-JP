SevenIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SevenIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SEVEN_ISLAND
	end

SevenIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SevenIsland_PokemonCenter_1F_EventScript_OldMan::
	msgbox SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Beauty::
	msgbox SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections::
	.string "{JPN}この しまでは つながりによって\n"
	.string "いろいろな できごとが おこる。\p"
	.string "つながりって なにかって?\p"
	.string "それは じぶんで\n"
	.string "みつけて ごらん。$"

SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere::
	.string "{JPN}シーギャロップに のって\n"
	.string "ここまで きたの?\p"
	.string "あの こうそくせんは すくなくとも\n"
	.string "10せきは あるんだって。\p"
	.string "どこに いくのかは ぜんぶは\n"
	.string "しらないけど。$"

SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower::
	.string "{JPN}じしんが あるなら\n"
	.string "トレーナータワーに いってみたら?$"

