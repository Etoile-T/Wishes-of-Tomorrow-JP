DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_DEWFORD_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "{JPN}この まちの はずれに\n"
	.string "いしの どうくつが あるの\p"
	.string "そこでは めずらしい いしが\n"
	.string "みつかるんですって$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "{JPN}ひんしで たたかうことの できない\n"
	.string "ポケモンでも ひでんマシンで おぼえた\l"
	.string "わざは つかうことが できるよ!$"

