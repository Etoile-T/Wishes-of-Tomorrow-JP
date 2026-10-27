CeladonCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeladonCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeladonCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons::
	.string "{JPN}ポケモンのふえは ねむっている\n"
	.string "ポケモンを おこす。 しってるよね。\p"
	.string "ポケモンにしか きこえない\n"
	.string "おとで おこすんだよ。$"

CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia::
	.string "{JPN}セキチクから じてんしゃで きたんだ。\p"
	.string "サイクリングロードは のぼりざかだから\n"
	.string "もう へとへとだよ。$"

CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike::
	.string "{JPN}じてんしゃが あったら\n"
	.string "サイクリングロードに いくのに!$"

