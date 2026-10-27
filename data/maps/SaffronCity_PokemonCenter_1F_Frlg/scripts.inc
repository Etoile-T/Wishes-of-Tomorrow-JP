SaffronCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SaffronCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_SILPH_CO_11F, 1, SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone
	msgbox SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone::
	msgbox SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff
	release
	end

SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies::
	.string "{JPN}ポケモンの そだつ はやさは\n"
	.string "しゅるいに よって ちがうんだ。$"

SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame::
	.string "{JPN}シルフカンパニーは だれもが しっている。\p"
	.string "ゆうめいすぎて ロケットだんに\n"
	.string "ねらわれて しまったのよ。$"

SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets::
	.string "{JPN}はあ…\n"
	.string "そうなったら いいのになあ。\p"
	.string "してんのうが やってきて\n"
	.string "ロケットだんを やっつけて くれたら。$"

SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff::
	.string "{JPN}ロケットだんが にげだしたぞ!\n"
	.string "また あんしんして でかけられる!\l"
	.string "よかったなあ!$"

