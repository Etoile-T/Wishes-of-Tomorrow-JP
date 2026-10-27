PacifidlogTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PACIFIDLOG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Girl::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_Woman::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_EventScript_OldMan::
	msgbox PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats, MSGBOX_NPC
	end

PacifidlogTown_PokemonCenter_1F_Text_WhatColorTrainerCard:
	.string "{JPN}きみの トレーナーカードは なにいろ?\n"
	.string "あたしのは カッパー なんだよ!$"

PacifidlogTown_PokemonCenter_1F_Text_OnColonyOfCorsola:
	.string "{JPN}キナギタウンって サニーゴたちの\n"
	.string "むれの うえに うかんでいるの。\p"
	.string "……なんて いったら\n"
	.string "あなたは しんじるかしら?$"

PacifidlogTown_PokemonCenter_1F_Text_AncestorsLivedOnBoats:
	.string "{JPN}キナギの ひとびとの せんぞは\n"
	.string "ふねの うえで うまれ\l"
	.string "ふねの うえで くらし しんでいった\l"
	.string "と いわれているの。\p"
	.string "そんな くらしを していたのは\n"
	.string "なにかを さがしていたからだと\l"
	.string "きいているわ。$"

