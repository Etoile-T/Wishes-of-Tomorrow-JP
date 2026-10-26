SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SLATEPORT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "{JPN}しょうぶの コツを ききたいかい?\p"
	.string "いろんな ポケモンを バランスよく\n"
	.string "そだてること だと おもうよ。\p"
	.string "1ぴきだけ つよくしても\n"
	.string "だめなんだ。\p"
	.string "タイプの あいしょうが わるかったら\n"
	.string "まったく かなわないかも しれないからね。$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "{JPN}ともだちと ポケモンを こうかん してるんだ。\p"
	.string "こうかんした ポケモンが どうぐを もっていると\n"
	.string "2ばい うれしく なるよねー!!$"

