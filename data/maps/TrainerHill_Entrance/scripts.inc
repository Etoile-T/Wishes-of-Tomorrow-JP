TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "{JPN}ここは さまざまな トレーナーさんとの\n"
	.string "タッグバトルが たのしめる\l"
	.string "トレーナーヒルです!\p"
	.string "ただいま じゅんびちゅうですので\n"
	.string "また おこしくださいませ!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "{JPN}ようこそ いらっしゃいました!\p"
	.string "ここは さまざまな トレーナーさんとの\n"
	.string "タッグバトルが たのしめる\l"
	.string "トレーナーヒルです!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "{JPN}こちらは はじめて ですか?\p"
	.string "はいる まえに レポートを\n"
	.string "かいて ください。$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "{JPN}ええと……\n"
	.string "ただいま あつまっている トレーナーさんは……\p"
	.string "{ENG}{STR_VAR_1}{JPN}かい までの ようですね。$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "{JPN}ええと……\n"
	.string "ただいま あつまっている トレーナーさんは……\p"
	.string "すべての へやに トレーナーさんが\n"
	.string "あつまっている みたいですね!$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "{JPN}まっている トレーナーさんたちと\n"
	.string "しょうぶ しますか?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "{JPN}それでは じかんを はかります。\n"
	.string "がんばってくださいね!\p"
	.string "いちについて……\p"
	.string "ようい……\p"
	.string "ドン!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "{JPN}また おこしくださいね!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "{JPN}ざんねん でしたね。\p"
	.string "とっても がんばって たたかわれたと\n"
	.string "おもいます。\p"
	.string "また ちょうせん しに きてくださいね!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "{JPN}がんばってくださいね!$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "{JPN}トレーナーさんたちが いれかわるとき\n"
	.string "とても あわただしく なるんです。\p"
	.string "こんざつを さけるため うけつけを\n"
	.string "こちらに うつしました。\p"
	.string "ごめいわくを おかけします!$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "{JPN}おつかれさまでした!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "{JPN}ここ トレーナーヒルでは\n"
	.string "タイムアタックを おこなっています。\p"
	.string "この うけつけから おくじょうの\n"
	.string "オーナーの ところまで たどりつく\l"
	.string "じかんを きそう レースです。\p"
	.string "はやい タイムは タイムボードに\n"
	.string "のります。おともだちと\l"
	.string "きそってみてくださいね。\p"
	.string "とちゅうの トレーナーとの しょうぶでは\n"
	.string "けいけんちも おかねも\l"
	.string "もらえません。$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "{JPN}もうしわけ ありませんが てもちが\n"
	.string "1ぴきしか いないようですね。\p"
	.string "この イベントには ポケモンが\n"
	.string "2ひき いじょう ひつようです。$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "{JPN}ムム!\p"
	.string "ついに きたね!\n"
	.string "きてしまったね!\p"
	.string "まって! いわなくて いいさー!\n"
	.string "なんで きみが こんなところまで\l"
	.string "ひとりで きたのか わかってるよ!\p"
	.string "トレーナーヒルの オーナーである\n"
	.string "この わたくしに あいにきたのは……\p"
	.string "タッグを くみたいからだろー!\n"
	.string "ワオ!\p"
	.string "……あれ?\n"
	.string "ちがうの?\p"
	.string "まあ きみの たたかい みせてもらったよ。\n"
	.string "じつに すばらしかった! ブラボー!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "{JPN}そんな すばらしい キミには\n"
	.string "すばらしい プレゼントだー!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "{JPN}オー もちものが いっぱいだねー!\n"
	.string "あとで とりにきてー!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "{JPN}オー! ちょっと まって! もしかして\n"
	.string "すごく はやく ここまで きたんじゃないー!?\p"
	.string "すてきだ! わたくしに あうために\n"
	.string "そんなに いそがなくても よかったのにー!\p"
	.string "うれしすぎるから うけつけの\n"
	.string "タイムボードに きろく しておくぜー!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "{JPN}でも オー……\n"
	.string "あんまり はやく なかったねー。$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "{JPN}つぎは もっと はやく この わたくしに\n"
	.string "あいにきてくれると うれしいなー!\p"
	.string "そしたら こんどこそ\n"
	.string "タッグを くもうなー!\p"
	.string "じゃあ またな! アミーゴ!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "{JPN}この トレーナーヒルを つくったのは\n"
	.string "ただ ひとつの りゆうの ためさ!\p"
	.string "この わたくしと タッグを くむのに\n"
	.string "ふさわしい パートナーを みつけるため!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}ふん\n{ENG}{STR_VAR_2}{JPN}.{ENG}{STR_VAR_3}{JPN}びょう$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "{JPN}どんな トレーナーと ポケモンの\n"
	.string "くみあわせが まっているのか!\p"
	.string "どんな やつが きても\n"
	.string "おれが たおしてみせるぜ!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "{JPN}この トレーナーヒルには あちこちから\n"
	.string "つよい トレーナーが あつまるそうだ!\p"
	.string "はやく うでだめしを したいぜ!\p"
	.string "どんな やつが たちはだかっても\n"
	.string "おれが たおしてみせるぜ!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "{JPN}あそこの タイムボード みえる?\p"
	.string "ともだちと だれが いちばん はやく\n"
	.string "てっぺんに つけるか きそってるんだ。$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "{JPN}ここが いつ オープンするか\n"
	.string "しってる?\p"
	.string "いちばん さいしょの チャレンジャーに\n"
	.string "なりたくて ここで まってるの!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "{JPN}うけつけに\n"
	.string "もどりますか?$"
