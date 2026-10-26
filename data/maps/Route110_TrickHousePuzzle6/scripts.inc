Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{JPN}{ENG}{PLAYER}{JPN}は あいことばを\n"
	.string "とびらに かきつけた。\p"
	.string "「カラクリだいおうが いのち」\n"
	.string "… … … … … … … …\p"
	.string "カチッと カギが あいた!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "{JPN}へんな やしきが あると きいたら\n"
	.string "たしかめずには いられなかったの。$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "{JPN}つよい トレーナーを はっけん!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "{JPN}ここを しらべるのは\n"
	.string "ほんとうに たのしいわ。\p"
	.string "くりかえし ちょうせんする かちが\n"
	.string "あるって わかったの!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "{JPN}とりポケモンに かべを とびこえさせれば\n"
	.string "いけるかも しれないな…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "{JPN}わわっ しまった!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "{JPN}てへへ… ズルしようと したから\n"
	.string "まけちゃったの かな……$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "{JPN}かいてん する とびらで\n"
	.string "めが まわってきた……$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "{JPN}くーるくる くーるくる\n"
	.string "おれは もう ダメだ……$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "{JPN}キミは ぜんぜん へいき みたいだね\n"
	.string "それとも ポーカーフェイス なの?$"

