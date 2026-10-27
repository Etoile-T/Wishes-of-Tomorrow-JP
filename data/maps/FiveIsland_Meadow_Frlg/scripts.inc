FiveIsland_Meadow_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
	.byte 0

FiveIsland_Meadow_OnLoad::
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	end

FiveIsland_Meadow_EventScript_WarehouseDoor::
	lockall
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
	releaseall
	end

FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
	waitmessage
	delay 60
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	special DrawWholeMapView
	playse SE_PIN
	waitse
	releaseall
	end

FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
	releaseall
	end

FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
	return

FiveIsland_Meadow_EventScript_Rocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

@ Unused
FiveIsland_Meadow_Text_DoorNeedsTwoPasswords::
	.string "{JPN}とびらを あけるには\n"
	.string "パスワードが 2つ いるようだ$"

FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded::
	.string "{JPN}{ENG}{PLAYER}{JPN}は パスワードを いれた。\p"
	.string "「トサキントには まるたが いる」\p"
	.string "… …  … …  … …\p"
	.string "とびらを あけるには もうひとつ\n"
	.string "パスワードが いるようだ…$"

FiveIsland_Meadow_Text_EnteredPasswordDoorOpened::
	.string "{JPN}{ENG}{PLAYER}{JPN}は パスワードを 2つ いれた。\p"
	.string "「トサキントには まるたが いる」\n"
	.string "「うん いや ラッキー」\p"
	.string "… …  … …  … …\p"
	.string "そうこの とびらが ひらいた!$"

FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen::
	.string "{JPN}そうこの とびらは もう\n"
	.string "ひらいている。$"

FiveIsland_Meadow_Text_Rocket1Intro::
	.string "{JPN}ここは たちいり きんしだ!\n"
	.string "でていけ でていけ!$"

FiveIsland_Meadow_Text_Rocket1Defeat::
	.string "{JPN}うそだろ?$"

FiveIsland_Meadow_Text_Rocket1PostBattle::
	.string "{JPN}おまえに ここでの ようは ない!\n"
	.string "かえれ!$"

FiveIsland_Meadow_Text_Rocket2Intro::
	.string "{JPN}この さきには おれたちの\n"
	.string "そうこしか ないぜ。\p"
	.string "なんの ようで きたんだ?$"

FiveIsland_Meadow_Text_Rocket2Defeat::
	.string "{JPN}こんな はずじゃ…$"

FiveIsland_Meadow_Text_Rocket2PostBattle::
	.string "{JPN}この そうこの なかみが\n"
	.string "しりたいのか?\p"
	.string "しらない ほうが いいぜ。\n"
	.string "おまえの ためを おもってな。$"

FiveIsland_Meadow_Text_Rocket3Intro::
	.string "{JPN}おれを たおして とおっても\n"
	.string "じかんの むだだぜ。$"

FiveIsland_Meadow_Text_Rocket3Defeat::
	.string "{JPN}くそっ はらが たつ!$"

FiveIsland_Meadow_Text_Rocket3PostBattle::
	.string "{JPN}どうせ パスワードが なきゃ\n"
	.string "なかには はいれないぜ。$"

