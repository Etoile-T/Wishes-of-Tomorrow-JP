SixIsland_RuinValley_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SixIsland_RuinValley_OnLoad
	.byte 0

SixIsland_RuinValley_OnLoad::
	call_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_OpenDottedHoleDoor
	end

SixIsland_RuinValley_EventScript_OpenDottedHoleDoor::
	setmetatile 24, 24, METATILE_SeviiIslands67_DottedHoleDoor_Open, 0
	return

SixIsland_RuinValley_EventScript_Scientist::
	lock
	msgbox SixIsland_RuinValley_Text_CantFigureOutHowToGetInside
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SixIsland_RuinValley_Text_IFoundThisPlace
	applymovement LOCALID_RUIN_VALLEY_SCIENTIST, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SixIsland_RuinValley_EventScript_DottedHoleDoor::
	lockall
	goto_if_set FLAG_USED_CUT_ON_RUIN_VALLEY_BRAILLE, SixIsland_RuinValley_EventScript_DottedHoleDoorOpen
	msgbox SixIsland_RuinValley_Text_CheckDoorMoreThoroughly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor
	msgbox SixIsland_RuinValley_Text_SeveralDotsOnTheDoor
	braillemsgbox Braille_Text_Cut
	releaseall
	end

SixIsland_RuinValley_EventScript_DottedHoleDoorOpen::
	msgbox SixIsland_RuinValley_Text_DoorIsOpen
	releaseall
	end

SixIsland_RuinValley_EventScript_IgnoreDottedHoleDoor::
	msgbox SixIsland_RuinValley_Text_LeftDoorAlone
	releaseall
	end

SixIsland_RuinValley_Text_CantFigureOutHowToGetInside::
	.string "{JPN}どうやって なかに はいれば いいのか\n"
	.string "わからないんだ$"

SixIsland_RuinValley_Text_IFoundThisPlace::
	.string "{JPN}いっとくけど ここを みつけたのは\n"
	.string "ぼくだからね\p"
	.string "そんな うらやましそうな かお しないでよ$"

SixIsland_RuinValley_Text_CheckDoorMoreThoroughly::
	.string "{JPN}とびらは びくとも しない\n"
	.string "もっと よく しらべますか?$"

SixIsland_RuinValley_Text_LeftDoorAlone::
	.string "{JPN}{ENG}{PLAYER}{JPN}は とびらから はなれた$"

SixIsland_RuinValley_Text_SeveralDotsOnTheDoor::
	.string "{JPN}よく みると とびらに\n"
	.string "いくつかの てんが ある…$"

SixIsland_RuinValley_Text_DoorIsOpen::
	.string "{JPN}とびらが ひらいている$"

SixIsland_RuinValley_Text_StanlyIntro::
	.string "{JPN}この せかいには まだ とかれていない\n"
	.string "なぞが たくさん あるようだ$"

SixIsland_RuinValley_Text_StanlyDefeat::
	.string "{JPN}ふむ…$"

SixIsland_RuinValley_Text_StanlyPostBattle::
	.string "{JPN}きみも 1にち 1かいは\n"
	.string "この せかいの なぞや ふしぎについて\l"
	.string "かんがえて みることを すすめるよ$"

SixIsland_RuinValley_Text_FosterIntro::
	.string "{JPN}ねえ どうして きみは\n"
	.string "ここに きたんだい?$"

SixIsland_RuinValley_Text_FosterDefeat::
	.string "{JPN}ひさしぶりの バトルだから\n"
	.string "かんが にぶってるな$"

SixIsland_RuinValley_Text_FosterPostBattle::
	.string "{JPN}ナナシマには いせきが\n"
	.string "いくつか あるんだ\p"
	.string "その ほとんどは ずっと むかしの\n"
	.string "ものなんだよ$"

SixIsland_RuinValley_Text_LarryIntro::
	.string "{JPN}この しまには ふしぎな いしが\n"
	.string "あると いわれてるんだ\p"
	.string "ここの いせきと なにか\n"
	.string "かんけいが ありそうだな$"

SixIsland_RuinValley_Text_LarryDefeat::
	.string "{JPN}ほう おもしろい$"

SixIsland_RuinValley_Text_LarryPostBattle::
	.string "{JPN}あそこの いせき…\p"
	.string "どうすれば なかに はいれるのか\n"
	.string "さっぱり わからないんだ$"

SixIsland_RuinValley_Text_DarylIntro::
	.string "{JPN}こんな たかい ところで バトルとは!$"

SixIsland_RuinValley_Text_DarylDefeat::
	.string "{JPN}ああ こんなに あっさり まけるなんて\n"
	.string "かなしいなあ!$"

SixIsland_RuinValley_Text_DarylPostBattle::
	.string "{JPN}やまのぼりの よろこびを あじわおう!$"

SixIsland_RuinValley_Text_HectorIntro::
	.string "{JPN}この あたりの ちりには\n"
	.string "けっこう くわしいんだ$"

SixIsland_RuinValley_Text_HectorDefeat::
	.string "{JPN}そんなに がっつかなくても\n"
	.string "よろこんで おしえて あげるよ$"

SixIsland_RuinValley_Text_HectorPostBattle::
	.string "{JPN}いせきの とびら…\n"
	.string "そとがわに へんな もようが\l"
	.string "ほられて いるんだ\p"
	.string "なにを いみしてるのかは\n"
	.string "わからないけどね$"
