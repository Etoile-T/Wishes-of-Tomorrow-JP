PokemonTower_6F_Frlg_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_MarowakGhost::
	lockall
	textcolor NPC_TEXT_COLOR_MON
	msgbox PokemonTower_6F_Text_BeGoneIntruders
	setwildbattle SPECIES_MAROWAK, 30
	special StartMarowakBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, PokemonTower_6F_EventScript_DefeatedMarowakGhost  @ VAR_RESULT set by CB2_EndMarowakBattle
	applymovement LOCALID_PLAYER, PokemonTower_6F_Movement_ForcePlayerUp
	waitmovement 0
	releaseall
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	message PokemonTower_6F_Text_GhostWasCubonesMother
	waitmessage
	waitse
	playmoncry SPECIES_MAROWAK, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox PokemonTower_6F_Text_MothersSpiritWasCalmed
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	releaseall
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
	.string "{JPN}ちを…\n"
	.string "よこせ…$"

PokemonTower_6F_Text_AngelicaDefeat::
	.string "{JPN}うう…!$"

PokemonTower_6F_Text_AngelicaPostBattle::
	.string "{JPN}ひんけつで ふらふら…$"

PokemonTower_6F_Text_EmiliaIntro::
	.string "{JPN}うぐう…\n"
	.string "キエーッ!$"

PokemonTower_6F_Text_EmiliaDefeat::
	.string "{JPN}なにか ぬけおちた!$"

PokemonTower_6F_Text_EmiliaPostBattle::
	.string "{JPN}かみのけが ぬけたんじゃ ないわ!\n"
	.string "あくりょうが ぬけたのよ!$"

PokemonTower_6F_Text_JenniferIntro::
	.string "{JPN}ケ…ケ…ケ…\n"
	.string "ケ…ケ…ケ!$"

PokemonTower_6F_Text_JenniferDefeat::
	.string "{JPN}キーッ!$"

PokemonTower_6F_Text_JenniferPostBattle::
	.string "{JPN}いったい なにが おきてるの?$"

PokemonTower_6F_Text_BeGoneIntruders::
	.string "{JPN}たちされ…\n"
	.string "しんにゅうしゃ…$"

PokemonTower_6F_Text_GhostWasCubonesMother::
	.string "{JPN}ゆうれいの しょうたいは カラカラの\n"
	.string "ははおやの うかばれない たましい だった!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
	.string "{JPN}ははおやの たましいは しずまった。\p"
	.string "あのよへ たびだって いった…$"

