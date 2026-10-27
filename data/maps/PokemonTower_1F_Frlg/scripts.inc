PokemonTower_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_1F_OnTransition
	.byte 0

PokemonTower_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	end

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PokemonTower_1F_EventScript_Woman2MalePlayer
	msgbox PokemonTower_1F_Text_ComeToPayRespectsGirl
	release
	end

PokemonTower_1F_EventScript_Woman2MalePlayer::
	msgbox PokemonTower_1F_Text_ComeToPayRespectsSon
	release
	end

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
	.string "{JPN}ポケモンタワーは なくなった\n"
	.string "ポケモンたちを とむらう ために たてられた。$"

PokemonTower_1F_Text_ComeToPayRespectsSon::
	.string "{JPN}おまいりに きたのかい?\p"
	.string "ポケモンを おもう やさしい こころだね\n"
	.string "ぼうや。$"

PokemonTower_1F_Text_ComeToPayRespectsGirl::
	.string "{JPN}おまいりに きたのかい?\p"
	.string "ポケモンを おもう やさしい こころだね\n"
	.string "おじょうちゃん。$"

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
	.string "{JPN}なくなった だいすきな ピッピの\n"
	.string "ために おいのりに きたの。\p"
	.string "ぐすっ!\n"
	.string "なみだが とまらない…$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
	.string "{JPN}わたしの ガーディ…\n"
	.string "どうして しんで しまったんだ?$"

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
	.string "{JPN}わたしは きとうしです。\p"
	.string "いたずらを する れいが いる。\n"
	.string "タワーの うえの ほうに けはいを かんじる。$"

