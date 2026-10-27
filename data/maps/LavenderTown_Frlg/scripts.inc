LavenderTown_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_DoYouBelieveInGhosts::
	.string "{JPN}ゆうれいって しんじる?$"

LavenderTown_Text_SoThereAreBelievers::
	.string "{JPN}ほんと?\n"
	.string "しんじてる ひとも いるんだ……$"

LavenderTown_Text_JustImaginingWhiteHand::
	.string "{JPN}ははは そうだよね。\p"
	.string "きみの かたに のってる しろい て……\n"
	.string "きっと ぼくの きのせいだよね。$"

LavenderTown_Text_TownKnownAsMonGraveSite::
	.string "{JPN}この まちは ポケモンの\n"
	.string "はかばとして しられてるの。\p"
	.string "ポケモンタワーで\n"
	.string "くようが おこなわれて いるのよ。$"

LavenderTown_Text_GhostsAppearedInTower::
	.string "{JPN}ポケモンタワーに ゆうれいが でたんだ。\p"
	.string "ロケットだんに ころされた\n"
	.string "ポケモンの たましい だと おもう。$"

LavenderTown_Text_TownSign::
	.string "{JPN}シオンタウン\n"
	.string "けだかき むらさきの まち$"

LavenderTown_Text_SilphScopeNotice::
	.string "{JPN}しんがた シルフスコープ!\n"
	.string "みえない ものが はっきり みえる!\p"
	.string "シルフカンパニー$"

LavenderTown_Text_VolunteerPokemonHouse::
	.string "{JPN}シオン ボランティア\n"
	.string "ポケモンハウス$"

LavenderTown_Text_PokemonTowerSign::
	.string "{JPN}ポケモンタワー\n"
	.string "ポケモンの たましいを しずめる ばしょ$"

