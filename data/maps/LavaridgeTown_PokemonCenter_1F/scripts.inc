LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_LAVARIDGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "{JPN}ポケモンは トレーナーと いっしょに\n"
	.string "すごすほど なかよく なると おもう。\p"
	.string "ながければ ながいほど いい。\n"
	.string "わたしは そう おもうな。$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "{JPN}おんせんに つかってる だけで\n"
	.string "げんきが でるなんて ふしぎだよね。\p"
	.string "ぼくの ポケモンも おゆに\n"
	.string "つからせて あげたいな。$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "{JPN}ほっほっほ! おわかいの\n"
	.string "ここから おんせんに いけますぞ!\p"
	.string "ポケモンが ここで やすむのなら\n"
	.string "トレーナーも ゆっくり しませんと!$"

