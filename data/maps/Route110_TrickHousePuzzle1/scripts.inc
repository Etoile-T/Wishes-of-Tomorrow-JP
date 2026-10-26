Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{JPN}{ENG}{PLAYER}{JPN}は あいことばを\n"
	.string "とびらに かきつけた。\p"
	.string "「カラクリだいおうは すばらしい」\n"
	.string "… … … … … … … …\p"
	.string "カチッと カギが あいた!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "{JPN}おぼえたての いあいぎりで\n"
	.string "きって きって かちすすむわ!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "{JPN}どうして そんなに ほんきなの?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "{JPN}きって きって きりまくっても\n"
	.string "ちっとも あきないわ!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "{JPN}へんな やしきに\n"
	.string "まよいこんじゃった……$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "{JPN}おまけに まけちゃった……$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "{JPN}みちに まよって しょうぶにも まけて\n"
	.string "さらに まよった… でられない…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "{JPN}カラクリだいおうって いったい なにもの?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "{JPN}かんがえごとを していたら まけちゃった!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "{JPN}つよいわ!\n"
	.string "あなたも なにもの なの?$"

