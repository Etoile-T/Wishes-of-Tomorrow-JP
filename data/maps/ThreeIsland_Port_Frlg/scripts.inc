ThreeIsland_Port_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_Port_OnTransition
	.byte 0

ThreeIsland_Port_OnTransition::
	clearflag FLAG_SYS_PC_STORAGE_DISABLED
	setflag FLAG_SEVII_DETOUR_FINISHED
	end

ThreeIsland_Port_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, ThreeIsland_Port_EventScript_WomanLostelleFound
	goto_if_ge VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_Port_EventScript_WomanBikersGone
	msgbox ThreeIsland_Port_Text_IllCallThePolice
	release
	end

ThreeIsland_Port_EventScript_WomanLostelleFound::
	msgbox ThreeIsland_Port_Text_EverythingTurnedOutForBest
	release
	end

ThreeIsland_Port_EventScript_WomanBikersGone::
	msgbox ThreeIsland_Port_Text_ThankGoodnessBikersGone
	release
	end

ThreeIsland_Port_EventScript_Biker1::
	msgbox ThreeIsland_Port_Text_WereKantoRiderFederation, MSGBOX_NPC
	end

ThreeIsland_Port_EventScript_Biker2::
	lock
	msgbox ThreeIsland_Port_Text_ForkOverMoney
	release
	end

ThreeIsland_Port_Text_WereKantoRiderFederation::
	.string "{JPN}おれたちゃ カントー ライダーれんごうだ!\n"
	.string "ブロロ! バババババーン! ブロロ!\p"
	.string "おれの バイクは しょぼいから\n"
	.string "エンジンおとは じぶんで だすんだ!$"

ThreeIsland_Port_Text_ForkOverMoney::
	.string "{JPN}おい おい ねえちゃん!\n"
	.string "こづかいを よこしな!$"

ThreeIsland_Port_Text_IllCallThePolice::
	.string "{JPN}ひいいっ!\p"
	.string "あ あなた だれ!?\n"
	.string "け… けいさつを よぶわよ!$"

ThreeIsland_Port_Text_ThankGoodnessBikersGone::
	.string "{JPN}あの ぼうそうぞく…\n"
	.string "いなくなったの?\p"
	.string "ああ よかった!\n"
	.string "ほんとうに こわかったわ!$"

ThreeIsland_Port_Text_EverythingTurnedOutForBest::
	.string "{JPN}ぼうそうぞくは にげだして\n"
	.string "ロステルも ぶじに みつかった\p"
	.string "なにもかも まるく おさまったわ!$"

