VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "{JPN}ポケモンを しんじられなければ\n"
	.string "ほんものの トレーナーとは\l"
	.string "いえないよ。\p"
	.string "たたかう ポケモンを しんじられる\n"
	.string "ひとだけが さいごまで\l"
	.string "かちぬけるんだ。$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "{JPN}シダケタウンに ひとが くる\n"
	.string "りゆうと いえば…\p"
	.string "もちろん バトルテントさ。\n"
	.string "いうまでも ないだろう。\p"
	.string "それとも ここに だれか\n"
	.string "あいたい ひとが いるのかい?$"

