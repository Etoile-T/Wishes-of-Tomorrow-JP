ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
	.string "{JPN}すみの パソコンは じゆうに\n"
	.string "つかって いいんだって。\p"
	.string "うけつけの ひとが そう いってた。\n"
	.string "やさしいよね!$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
	.string "{JPN}この さきの まちには どこにも\n"
	.string "ポケモンセンターが あるよ。\p"
	.string "おかねは かからないから\n"
	.string "えんりょなく かいふく させてね。$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
	.string "{JPN}ポケモンセンターは つかれたり\n"
	.string "きずついたり ひんしの ポケモンを\p"
	.string "すっかり げんきに\n"
	.string "してくれるんだ。$"

