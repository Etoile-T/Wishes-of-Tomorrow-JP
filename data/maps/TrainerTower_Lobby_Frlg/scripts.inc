TrainerTower_Lobby_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_Lobby_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerTower_Lobby_OnReturnToField
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Lobby_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Lobby_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_Lobby_OnFrame
	.byte 0

TrainerTower_Lobby_OnResume::
	setvar VAR_TEMP_2, 0
	ttower_resumetimer
	ttower_shouldexit
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_OnResumeEnd
	@ Never reached, above always FALSE
	setvar VAR_TEMP_0, 0
	setobjectxy LOCALID_PLAYER, 9, 7
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
TrainerTower_Lobby_OnResumeEnd::
	end

TrainerTower_Lobby_OnReturnToField::
	addobject LOCALID_TOWER_NURSE
	addobject LOCALID_TOWER_MART_CLERK
	addobject LOCALID_TOWER_RECEPTIONIST
	addobject LOCALID_TOWER_COOLTRAINER_F
	addobject LOCALID_TOWER_BALDING_MAN
	end

TrainerTower_Lobby_OnLoad::
	call_if_eq VAR_TEMP_D, 17, TrainerTower_Lobby_OpenCounterBarrier
	end

TrainerTower_Lobby_OpenCounterBarrier::
	setmetatile 17, 10, METATILE_TrainerTower_Floor_ShadeBottomLeft, 0
	return

TrainerTower_Lobby_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerTower_Lobby_OnFrame::
	map_script_2 VAR_TEMP_0, 0, TrainerTower_Lobby_EventScript_Enter
	map_script_2 VAR_TEMP_D, 17, TrainerTower_Lobby_EventScript_ExitElevator
	.2byte 0

TrainerTower_Lobby_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_ExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerTower_CounterBarrier, 1
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerTower_Lobby_Movement_ExitElevator::
	walk_down
	walk_down
	step_end

TrainerTower_Lobby_EventScript_Enter::
	setvar VAR_TEMP_0, 1
	ttower_getchallengestatus
	switch VAR_RESULT
	case TT_CHALLENGE_STATUS_LOST, TrainerTower_Lobby_EventScript_LostChallenge
	case TT_CHALLENGE_STATUS_UNK, TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist
	case TT_CHALLENGE_STATUS_NORMAL, TrainerTower_Lobby_EventScript_EnterEnd

TrainerTower_Lobby_EventScript_LostChallenge::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_TooBadComeBackTryAgain
	goto TrainerTower_Lobby_EventScript_ExitChallenge

@ Presumably E-Reader related
TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch
TrainerTower_Lobby_EventScript_ExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	release
TrainerTower_Lobby_EventScript_EnterEnd::
	end

TrainerTower_Lobby_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

TrainerTower_Lobby_EventScript_Receptionist::
	lock
	faceplayer
	ttower_getbeatchallenge
	goto_if_eq VAR_RESULT, TRUE, TrainerTower_Lobby_EventScript_ThanksForCompeting
	msgbox TrainerTower_Lobby_Text_GiveItYourBest
	goto TrainerTower_Lobby_EventScript_ReceptionistEnd

TrainerTower_Lobby_EventScript_ThanksForCompeting::
	msgbox TrainerTower_Lobby_Text_ThanksForCompeting
TrainerTower_Lobby_EventScript_ReceptionistEnd::
	release
	end

TrainerTower_Lobby_EventScript_MartClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerTower_Lobby_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TrainerTower_Lobby_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

TrainerTower_Lobby_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_WelcomeToTrainerTower
	ttower_getnumfloors
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_AllFloorsUsed
	msgbox TrainerTower_Lobby_Text_TrainersUpToFloorNum
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge

TrainerTower_Lobby_EventScript_AllFloorsUsed::
	msgbox TrainerTower_Lobby_Text_TrainersUpEighthFloor
TrainerTower_Lobby_EventScript_AskEnterChallenge::
	message TrainerTower_Lobby_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_ChooseChallenge
	case 1, TrainerTower_Lobby_EventScript_DeclineChallenge
	case 2, TrainerTower_Lobby_EventScript_ChallengeInfo
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_ChallengeInfo::
	msgbox TrainerTower_Lobby_Text_ExplainTrainerTower
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge
	end

TrainerTower_Lobby_EventScript_ChooseChallenge::
	multichoice 13, 3, MULTI_TRAINER_TOWER_MODE, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_BeginChallenge
	case 1, TrainerTower_Lobby_EventScript_BeginChallenge
	case 2, TrainerTower_Lobby_EventScript_BeginChallenge
	case 3, TrainerTower_Lobby_EventScript_BeginChallenge
	case 4, TrainerTower_Lobby_EventScript_DeclineChallenge
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_BeginChallenge::
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 1
	special HealPlayerParty
	msgbox TrainerTower_Lobby_Text_StartClockGetSetGo
	ttower_startchallenge
	releaseall
	end

TrainerTower_Lobby_EventScript_DeclineChallenge::
	msgbox TrainerTower_Lobby_Text_PleaseVisitUsAgain
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	releaseall
	end

TrainerTower_Lobby_Movement_FaceReceptionist::
	face_right
	step_end

TrainerTower_Lobby_Movement_WalkDown::
	walk_down
	step_end

TrainerTower_Lobby_EventScript_ShowRecords::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	special ShowTrainerHillRecords
	waitstate
	releaseall
	end

TrainerTower_Lobby_EventScript_CooltrainerF::
	msgbox TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers, MSGBOX_NPC
	end

TrainerTower_Lobby_EventScript_BaldingMan::
	msgbox TrainerTower_Lobby_Text_StairsTougherThanAnyBattle, MSGBOX_NPC
	end

@ All Trainer Tower text (Lobby and Roof) is interleaved here

TrainerTower_Lobby_Text_WelcomeToTrainerTower::
	.string "{JPN}こんにちは!\p"
	.string "トレーナーが せかいじゅうから あつまる\n"
	.string "トレーナータワーへ ようこそ!$"

TrainerTower_Lobby_Text_TrainersUpToFloorNum::
	.string "{JPN}せかいじゅうの トレーナーが\n"
	.string "ここに あつまって たたかいます\p"
	.string "えーと…\p"
	.string "いま トレーナーが いるのは\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいまで だけです$"

TrainerTower_Lobby_Text_TrainersUpEighthFloor::
	.string "{JPN}8かいまで トレーナーが\n"
	.string "あなたの ちょうせんを まっています$"

TrainerTower_Lobby_Text_LikeToChallengeTrainers::
	.string "{JPN}まちうける トレーナーに\n"
	.string "ちょうせん しますか?$"

TrainerTower_Lobby_Text_StartClockGetSetGo::
	.string "{JPN}では タイムを はかりはじめますので\n"
	.string "ぜんりょくを つくして ください\p"
	.string "いちについて…\p"
	.string "よーい…\p"
	.string "スタート!$"

TrainerTower_Lobby_Text_PleaseVisitUsAgain::
	.string "{JPN}また ぜひ おこし ください!$"

TrainerTower_Lobby_Text_TooBadComeBackTryAgain::
	.string "{JPN}ざんねんでしたね\p"
	.string "バトルでは とても よく\n"
	.string "がんばったと おもいますよ\p"
	.string "また ちょうせん しに きてください!$"

TrainerTower_Lobby_Text_GiveItYourBest::
	.string "{JPN}がんばって くださいね$"

TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch::
	.string "{JPN}トレーナーが いれかわる ときは\n"
	.string "ひとの うごきが あわただしいんです\p"
	.string "こんざつを さけるため うけつけを\n"
	.string "ここに うつしました\p"
	.string "ごめいわくを おかけします$"

TrainerTower_Roof_Text_ImOwnerBattledPerfectly::
	.string "{JPN}こんにちは…\p"
	.string "わたしは この タワーの オーナー…\p"
	.string "この おくじょうの うえに\n"
	.string "ひろがる そら…\p"
	.string "ここに ふく かぜの やさしさ…\p"
	.string "すべてが かんぺき…\p"
	.string "あなたの たたかいぶり…\n"
	.string "それも また かんぺきでした…$"

TrainerTower_Roof_Text_ThisIsForYou::
	.string "{JPN}これを あなたに…$"

TrainerTower_Roof_Text_DoneItInRecordTime::
	.string "{JPN}おお!\n"
	.string "すばらしい!\p"
	.string "こんなに はやく ここまで\n"
	.string "くるとは みごとです\p"
	.string "じつは あなたは\n"
	.string "きろくを こうしん したのです…\p"
	.string "あなたの きろくを うけつけに\n"
	.string "はりだして おきましょう$"

TrainerTower_Roof_Text_TookSweetTimeGettingHere::
	.string "{JPN}ここまで ずいぶん のんびり\n"
	.string "きたようですね…$"

TrainerTower_Roof_Text_IdLikeToSeeBetterTime::
	.string "{JPN}わたしが みたいのは\n"
	.string "あなたの もっと よい タイム…\p"
	.string "きたい していますよ\p"
	.string "それでは ごきげんよう…$"

TrainerTower_Text_XMinYZSec::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}ふん\n{ENG}{STR_VAR_2}{JPN}.{ENG}{STR_VAR_3}{JPN}びょう$"

TrainerTower_Lobby_Text_HereAreTheResults::
	.string "{JPN}せいせきひょうです$"

TrainerTower_Lobby_Text_NeedTwoMonsForDouble::
	.string "{JPN}これは 2たい2の バトルです\p"
	.string "ポケモンが 2ひき いじょう いないと\n"
	.string "ちょうせん できません$"

TrainerTower_Lobby_Text_ExplainTrainerTower::
	.string "{JPN}ここ トレーナータワーでは\n"
	.string "タイムアタックを おこなっています\p"
	.string "うけつけから おくじょうの オーナーまで\n"
	.string "どれだけ はやく たどりつけるか\l"
	.string "タイムを はかります\p"
	.string "よい タイムは タイムボードに\n"
	.string "きろく されます\p"
	.string "ともだちと だれが いちばん はやいか\n"
	.string "きそいあって みてください\p"
	.string "ここで トレーナーに かっても けいけんちや\n"
	.string "おかねは もらえません$"

TrainerTower_Lobby_Text_ThanksForCompeting::
	.string "{JPN}ちょうせん ありがとう ございました!$"

TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers::
	.string "{JPN}じぶんの じつりょくを ためしに きたんだ\p"
	.string "どんな トレーナーが\n"
	.string "まってるんだろう?\p"
	.string "きんちょう するなあ!$"

TrainerTower_Lobby_Text_StairsTougherThanAnyBattle::
	.string "{JPN}ハア ハア…\n"
	.string "ハア…\p"
	.string "バトルどころじゃ ない! この かいだん…\n"
	.string "どんな バトルより きついよ…$"

