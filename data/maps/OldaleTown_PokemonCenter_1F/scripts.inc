OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

@ WoT: this is Frostwood Town's POKéMON CENTER. The nurse stands behind the
@ counter at (8,5); the counter-front metatile (FrostwoodPC 0x2AE) is MB_COUNTER
@ so talking to the counter from (8,7)/(9,7) reaches her. The PC at (11,3) is a
@ bg_event on EventScript_PC.
OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_GoonMuk::
	msgbox OldaleTown_PokemonCenter_1F_Text_GoonMuk, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_GoonBud::
	msgbox OldaleTown_PokemonCenter_1F_Text_GoonBud, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_GondolaToSennen, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	msgbox OldaleTown_PokemonCenter_1F_Text_SickOfTheSnow, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_Text_GoonMuk:
	.string "{JPN}めのまえから とっとと うせろ クソが。\n"
	.string "ベトベトンくせえんだよ。$"

OldaleTown_PokemonCenter_1F_Text_GoonBud:
	.string "{JPN}おい ほかに やることは\n"
	.string "ないのかよ？$"

OldaleTown_PokemonCenter_1F_Text_GondolaToSennen:
	.string "{JPN}ゴンドラで やまを くだれば\n"
	.string "センネンに つくよ。\p"
	.string "あそこの うみべは\n"
	.string "ずっと あたたかいんだ!$"

OldaleTown_PokemonCenter_1F_Text_SickOfTheSnow:
	.string "{JPN}ゆきには うんざり？ ゴンドラの\n"
	.string "えきは まちの ほくとうの\l"
	.string "すみに あるよ。\p"
	.string "センネンまで くだれば\n"
	.string "あっというまに ビーチだよ!$"
