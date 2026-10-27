BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_BOY_1
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_BOY_1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_TOWER_PARTNER_ROOM_ATTENDANT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_TOWER_PARTNER_ROOM_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement LOCALID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "{JPN}ここに あつまった トレーナーから\n"
	.string "パートナーを さがしてください$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{JPN}{ENG}{PLAYER}{JPN}さんは タッグの\n"
	.string "パートナーを まだ みつけていません\p"
	.string "パートナーさがしを やめて\n"
	.string "うけつけへ もどりますか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "{JPN}それでは ここに あつまった\n"
	.string "トレーナーから パートナーを さがしてください$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "{JPN}パートナーを おえらびいただき ありがとうございます\p"
	.string "それでは\n"
	.string "マルチバトルルームへ ごあんない します$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし\n"
	.string "ぼく {ENG}{STR_VAR_3}{JPN}って よんでね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}の アドバイスで つれてきたのは\n"
	.string "{ENG}{STR_VAR_2}{JPN}を もつ {ENG}{STR_VAR_3}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "どうか タッグを くませてください$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "{JPN}ありがとうございます!\n"
	.string "さっそく とうろくしてきます$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "{JPN}ほんとうに タッグを\n"
	.string "くみたかったのに {ENG}{PLAYER}{JPN}さん……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし\n"
	.string "わたしは {ENG}{STR_VAR_3}{JPN}と いいます$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}に そうだんして えらんだのは\n"
	.string "{ENG}{STR_VAR_2}{JPN}を もつ {ENG}{STR_VAR_3}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "どうか タッグを くみましょう!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "{JPN}どうも ありがとうございます!\n"
	.string "すぐに とうろくを すませてきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{JPN}{ENG}{PLAYER}{JPN}さんと タッグを\n"
	.string "くめると おもったのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "{JPN}あの…… {ENG}{STR_VAR_3}{JPN}と いいます\n"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし\p"
	.string "ぐすっ……\p"
	.string "ごめんなさい!\n"
	.string "きんちょうして なみだが……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんの アドバイスで\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "ぐすっ……\n"
	.string "おねがい タッグを くんでください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "{JPN}えー ほんとですか? いいんですか?\n"
	.string "やった! うれしいよう! うぉぉーん!\p"
	.string "あ…… ごめんなさい……\n"
	.string "うれしくて なみだが……\p"
	.string "さっそく とうろくして きます\n"
	.string "どこにも いかないで くださいね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "{JPN}そ そんな……\n"
	.string "ぐすっ…… うわーん!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "{JPN}こんにちはっ ボクは {ENG}{STR_VAR_3}{JPN}!\n"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんの オススメの メンバーは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\n"
	.string "これが ボクの ポケモン! イカすでしょ?\p"
	.string "だから さあ!\n"
	.string "タッグを くもうよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "{JPN}わーい! やったね!\n"
	.string "じゃ とうろく してくるね いい?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "{JPN}えーっ どうして?\n"
	.string "{ENG}{PLAYER}{JPN}さんと くみたかったなー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}! {ENG}{STR_VAR_2}{JPN}ばんめの\n"
	.string "ゆうめいな {ENG}{STR_VAR_1}{JPN}の でしです!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんに アドバイスを もらって\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}も\n"
	.string "この 2ひきを つれているんです\p"
	.string "おねがいです!\n"
	.string "ぼくと タッグを くんでくれませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "{JPN}ありがとうございます!\n"
	.string "さっそく とうろくを すませてきますね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{JPN}{ENG}{PLAYER}{JPN}さんと\n"
	.string "ぜひ タッグを くみたかったです……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "{JPN}あの…… わたしなんかに こえを かけて\n"
	.string "いただいて ほんとうに うれしいです\p"
	.string "{ENG}{STR_VAR_3}{JPN}と もうします……\n"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんに アドバイスを いただいて\n"
	.string "とても かんしゃ しています\p"
	.string "わたしの チームは {ENG}{STR_VAR_2}{JPN}……\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もっています それと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\n"
	.string "おそれおおい おねがい なのですが……\p"
	.string "ムリだとは おもいますけど……\n"
	.string "わたしと タッグを くんでいただけますか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "{JPN}ほんとう ですか? しんじられない!\n"
	.string "わたしなんかと くんでもらえる なんて!\l"
	.string "が……がんばります!\p"
	.string "あのっ ほんとうに よろしければ\n"
	.string "いますぐ とうろく してきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "{JPN}あ……\n"
	.string "やっぱり わたしなんか ダメですよね……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "{JPN}こんにちは わたしは {ENG}{STR_VAR_3}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんが この チームが\n"
	.string "いいって おしえてくれたの\l"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_2}{JPN}も いるわ\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかえるのよ\p"
	.string "わるくないでしょ?\n"
	.string "わたしと タッグ くんであげよっか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "{JPN}うん じゃあ よろしくね\n"
	.string "わたしの あしを ひっぱらないでよね!\l"
	.string "さっそく とうろく してくるわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "{JPN}え? なんで ことわるの?\n"
	.string "ひとを みるめが ないんじゃない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}だ! トライアスリートさ\n"
	.string "まいにち ジョギングに トレーニングに\l"
	.string "ラップにと いそがしいんだ\p"
	.string "ついでに {ENG}{STR_VAR_1}{JPN}の\n"
	.string "{ENG}{STR_VAR_2}{JPN}ばんでし でもあるのさ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}の オススメは これ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n"
	.string "{ENG}{STR_VAR_2}{JPN}です\p"
	.string "いそがしい なかでも\n"
	.string "がんばって そだてたんだぜ\p"
	.string "タッグを くんで\n"
	.string "いっちょ やってみようぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "{JPN}サンキュー そう こなくっちゃ!\n"
	.string "オレが とうろく してくるから まってな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "{JPN}いそがしい なか きてやったのに\n"
	.string "そりゃ ないぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "{JPN}ハーイ!\n"
	.string "げんき?\p"
	.string "{ENG}{STR_VAR_3}{JPN}よ! {ENG}{STR_VAR_1}{JPN}の\n"
	.string "{ENG}{STR_VAR_2}{JPN}ばんでし よろしくね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "{JPN}きいて きいて! ぜひ きいてほしいの\n"
	.string "{ENG}{STR_VAR_3}{JPN}さんの オススメの ポケモン!\l"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\n"
	.string "もちろん バッチリ そだてたわ!\p"
	.string "というわけで わたしと くまない?\n"
	.string "きっと いいコンビに なるわよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "{JPN}わーい たのしく なりそうー!\n"
	.string "じゃ わたしが とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "{JPN}もー いじわる!\n"
	.string "わたし オススメなのに!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "{JPN}じこしょうかい させてくださいませ\n"
	.string "わたくし {ENG}{STR_VAR_3}{JPN}と もうします\p"
	.string "{ENG}{STR_VAR_1}{JPN}の\n"
	.string "{ENG}{STR_VAR_2}{JPN}ばんでしを つとめております$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "{JPN}ありがたい ごしどうを\n"
	.string "{ENG}{STR_VAR_3}{JPN}さまに いただき そだてたのは\l"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ\n{ENG}{STR_VAR_2}{JPN}ですわ\p"
	.string "どうか わたくしと タッグを!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "{JPN}うっ うれしい ですわ……\n"
	.string "わたくし ぜんりょくで つとめますわ!\p"
	.string "もちろん とうろくは わたくしが!\n"
	.string "すこし おまちくださいませ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "{JPN}ごいっしょ したかったのですが……\n"
	.string "{ENG}{PLAYER}{JPN}さま……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "{JPN}キャー! はなしかけて もらえた!\n"
	.string "か かんげきですっ!\p"
	.string "{ENG}{STR_VAR_3}{JPN}です! {ENG}{STR_VAR_1}{JPN}の\n"
	.string "{ENG}{STR_VAR_2}{JPN}ばんでし ですっ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}せんせいの アドバイスで\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n"
	.string "{ENG}{STR_VAR_2}{JPN}です\p"
	.string "おねがいです! ねがいを かなえて!\n"
	.string "あなたの パートナーに なりたいんです!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "{JPN}キャー! か かんげきっ……!\n"
	.string "おありがとう ございますう!\l"
	.string "すぐに とうろくして まいりますっ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "{JPN}うわあああ! ちも なみだも ないんですか!\n"
	.string "でも そこが ステキ……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "{JPN}イヤッホー! {ENG}{STR_VAR_1}{JPN}の\n"
	.string "{ENG}{STR_VAR_2}{JPN}ばんでし!\p"
	.string "{ENG}{STR_VAR_3}{JPN}って いうのさ ハロー ハロー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}ティーチャーの オススメは\n"
	.string "{ENG}{STR_VAR_1}{JPN}マスターの {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}マスターの\n"
	.string "{ENG}{STR_VAR_2}{JPN}!\p"
	.string "イケてるでしょ?\n"
	.string "パートナーに なってくれるよね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "{JPN}オーケイ エクセレント!\n"
	.string "じゃ バーっと とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "{JPN}ぐわーっ!\n"
	.string "{ENG}{PLAYER}{JPN}さんって ちゃっかりしてるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "{JPN}お おいっ たいへんだ! バトルタワーは\n"
	.string "きょうで おしまい らしいぞ!\p"
	.string "…… …… …… …… …… ……\n"
	.string "なんてね うそ うそ!\p"
	.string "おいらは {ENG}{STR_VAR_3}{JPN}って いうんだ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}の 1000ばんめの でしだ!\l"
	.string "うそ ほんとは {ENG}{STR_VAR_2}{JPN}ばん!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}が アドバイスを くれてね\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}を\n"
	.string "10ぴきずつ もって いまーす!\l"
	.string "うそ ほんとは 1ぴきずつだよ!\p"
	.string "ひとつ どうだろ?\n"
	.string "おいらと タッグバトル してみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "{JPN}やったー!\n"
	.string "おれいに ポケモン あげちゃおう!\p"
	.string "なんて じょうだん! でも とうろくは\n"
	.string "ほんとに してくるからね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "{JPN}そんな つめたい こと いうと\n"
	.string "バトルタワーを こわして しまうぞ!\p"
	.string "なんてね うそ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "{JPN}ヘイ ヨー! ロックンロールで ノリノリ!\n"
	.string "ポケモン あやつる オレ ギリギリ!\p"
	.string "オレは {ENG}{STR_VAR_3}{JPN} ラップする ふなのり\n"
	.string "なきむしと まちがえるな オレの ノリ!\p"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし\n"
	.string "オレを みくびったら シクジリ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}の アドバイス きいて\n"
	.string "くみあげた じまんの チーム みて!\l"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n"
	.string "{ENG}{STR_VAR_2}{JPN}!\p"
	.string "この であいを きねんして\n"
	.string "タッグで しょうりを いわおうぜ イエー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "{JPN}ヘイ ヘイ! キミの スタイル いいね!\n"
	.string "とうろくは オレに まかせな ヨロシクね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "{JPN}おいおい {ENG}{PLAYER}{JPN}さん つめたいぜ!\n"
	.string "ノリが わるいじゃ ないか ヘイ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "{JPN}イャァアッホオオォォウウ!\n"
	.string "あ にげないでェ ふざけてた だけだよォ!\p"
	.string "オスっ オレっ {ENG}{STR_VAR_3}{JPN}!\n"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんが おしえてくれた!\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n"
	.string "{ENG}{STR_VAR_2}{JPN}を えらんだぜ!\p"
	.string "さあ どうする?\n"
	.string "オレを ハッピーに してくれよ!\p"
	.string "たのむ このとおり!\n"
	.string "おいてかないで ブルーに させないで!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "{JPN}イェーイ! ツイてるぜ!\n"
	.string "ほんと うれしいぜ!\p"
	.string "バトルに とびこむ その まえに\n"
	.string "とうろく すませて くるからね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "{JPN}って ことわられてる オレっ!?\n"
	.string "{ENG}{PLAYER}{JPN}さん つれないよォ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "{JPN}ゴホッ!\p"
	.string "あ ごめん かぜ ひいてて\n"
	.string "でも ポケモンは げんきだよ\p"
	.string "{ENG}{STR_VAR_3}{JPN}だよ {ENG}{STR_VAR_1}{JPN}の\n"
	.string "{ENG}{STR_VAR_2}{JPN}ばんでし ゴホッ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんの アドバイスを むねに\n"
	.string "くみあげた チームは\l"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "まいにち きたえてたんだ\n"
	.string "かぜの ひも あめの ひも\p"
	.string "だから かぜを ひいたんだと\n"
	.string "おもう\p"
	.string "まあ そんな かんじ\n"
	.string "タッグの パートナーに ならない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "{JPN}ありがとう たすかるよ!\n"
	.string "ゴホッ ゴホッ!\l"
	.string "とうろく してくるから まってて$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "{JPN}え ダメなの?\n"
	.string "{ENG}{PLAYER}{JPN}さんと いい コンビに なれそうなのに$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "{JPN}あ こんにちは!\n"
	.string "きんちょう するなあ\p"
	.string "{ENG}{STR_VAR_3}{JPN}です\n"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}さんが いいって いうので\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "ちょっと はずかしいん だけど\n"
	.string "いっしょに くませて もらえる?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "{JPN}あ ありがとう!\n"
	.string "はずかしい けど がんばって みるよ!\p"
	.string "じゃ…… と とうろく してくるね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "{JPN}こ ことわらないで!\n"
	.string "ただでさえ はずかしいのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "{JPN}わしは {ENG}{STR_VAR_3}{JPN}じゃ うそは いわん\n"
	.string "{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}ばんでし$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}が チームを すすめてくれた\p"
	.string "まごころの こもった アドバイスゆえ\n"
	.string "つれて きたのは\l"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}\p"
	.string "できることなら わしを\n"
	.string "タッグの パートナーに みとめてほしい$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "{JPN}ほんとうに みとめて くれるのかね?\n"
	.string "うそだったら つらすぎる からな\p"
	.string "いや みとめて くれたなら よいのじゃ\n"
	.string "ふたりぶん とうろく してこよう$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "{JPN}む? なぜ ことわるのかね?\n"
	.string "わるい じょうだん では ないのかね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "{JPN}わたしは ミニスカートの {ENG}{STR_VAR_1}{JPN}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "{JPN}わたしが もってるのは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかうコよ それと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}\n"
	.string "この 2ひきを つれてるの\p"
	.string "わたしの パートナーに なってくれる?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "{JPN}ありがとうー!\n"
	.string "いまから とうろく してくるわね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "{JPN}わたしの パートナーに ならないの?\n"
	.string "きっと こうかい するから!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "{JPN}こんにちは!\p"
	.string "たんパンこぞうの {ENG}{STR_VAR_1}{JPN}だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "{JPN}ぼくの ポケモン しりたい?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "ぼくの タッグパートナーに\n"
	.string "なってくれるよね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "{JPN}やったー!\n"
	.string "とうろく してくるね いい?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "{JPN}えー! ぼくの ポケモンと タッグを くめば\n"
	.string "ぜったい むてき なのにー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "{JPN}ヤッホー!\n"
	.string "やまおとこの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "{JPN}わしが つれてる ポケモン しりたいか?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}!\p"
	.string "いいだろう?\n"
	.string "タッグを くまないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "{JPN}ヤッホー!\n"
	.string "それじゃ とうろく してくるぞ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "{JPN}きみと いっしょに ならんで\n"
	.string "バトル したかったです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "{JPN}こんにちは!\n"
	.string "おとなのおねえさんの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "{JPN}わたしが なにを そだててるか わかる?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "どう おもう?\n"
	.string "いっしょに タッグを くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "{JPN}すてき!\n"
	.string "いますぐ とうろく してくるわ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "{JPN}ざんねんね!\p"
	.string "あなたと わたしが くんだら\n"
	.string "さいこう だったのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "{JPN}よー!\p"
	.string "わしが だれだか わかるか?\n"
	.string "つりびとの {ENG}{STR_VAR_1}{JPN}じゃ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "{JPN}わしが つれとる チームは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}\p"
	.string "で どうじゃ?\n"
	.string "わしと ならんで たたかって くれんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "{JPN}よしよし!\n"
	.string "まかせとけー!\p"
	.string "いまから とうろくを してくるからな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "{JPN}いきも ピッタリ だったのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "{JPN}おめにかかれて うれしいですわ\n"
	.string "わたくし おじょうさまの {ENG}{STR_VAR_1}{JPN}ですの$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "{JPN}わたくしが つれているのは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "おめがねに かなうと いいのですけど\n"
	.string "あなたを パートナーに したいのですわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "{JPN}こころから かんしゃ いたしますわ\n"
	.string "とうろくは わたくしが いたします$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "{JPN}わたくしを パートナーに しないと\n"
	.string "きっと こうかい しますわよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "{JPN}トライアスリートの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "{JPN}わたしの ポケモンはね……\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\n"
	.string "この 2ひきなの!\p"
	.string "おねがい!\n"
	.string "いっしょに タッグを くんでよ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "{JPN}ありがとうー!\n"
	.string "うけつけで とうろく してくるー$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "{JPN}わたしと タッグを くんだら\n"
	.string "ぜったい つよかったのにー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "{JPN}やあ!\n"
	.string "むしとりしょうねんの {ENG}{STR_VAR_1}{JPN}だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "{JPN}ぼくの ポケモン みてよ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "ねえ きいて!\n"
	.string "タッグを くんで みない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "{JPN}やったね!\p"
	.string "じゃ いまから うけつけで\n"
	.string "とうろくを すませてくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "{JPN}ぼくの ポケモン さいこう なのに!\n"
	.string "こうかい しないでよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "{JPN}ごきげんよう!\n"
	.string "じゅくがえりの {ENG}{STR_VAR_1}{JPN}です!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "{JPN}ぼくが そだてているのは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "{JPN}もう1ぴきは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかいます\p"
	.string "なかなか わるくないと おもいませんか?\n"
	.string "タッグを くんで いただけますか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "{JPN}どうも ありがとうございます!\n"
	.string "とうろくを すませて きますね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "{JPN}ざんねんです……\p"
	.string "きみの パートナーとして いろいろ\n"
	.string "べんきょう したかったです……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "{JPN}よう! オレが だれか おしえてやる!\n"
	.string "おぼっちゃまの {ENG}{STR_VAR_1}{JPN}さ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "{JPN}オレの ポケモン なんだと おもう?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "とくべつに オレと タッグを\n"
	.string "くむ チャンスを やっても いいぜ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "{JPN}かしこい えらびだな!\p"
	.string "じゃあ いまから ちゃちゃっと\n"
	.string "とうろくを すませてくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "{JPN}よりによって オレを ことわるのか?\n"
	.string "ぜったい こうかい するぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "{JPN}ハイヤーッ!\n"
	.string "わたくし からておうの {ENG}{STR_VAR_1}{JPN}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "{JPN}わたくしの なかまは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "{JPN}もう1ぴきは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかいます\p"
	.string "おねがいです!\n"
	.string "タッグの パートナーに させてください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "{JPN}ハイヤーッ!\n"
	.string "ただちに とうろく してまいります!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "{JPN}そうですか…… つぎに あった ときに\n"
	.string "また チャンスが あれば……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "{JPN}こんにちは!\n"
	.string "うきわガールの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "{JPN}わたしの ポケモン おしえてあげる\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\n"
	.string "わたしと タッグを くんでくれる?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "{JPN}ありがとう!\n"
	.string "いますぐ とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "{JPN}わたしと パートナーに なったら\n"
	.string "とっても つよかったのにー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "{JPN}ごきげんよう……\n"
	.string "オカルトマニアの {ENG}{STR_VAR_1}{JPN}です……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "{JPN}つれているのは {ENG}{STR_VAR_1}{JPN}を つかう\n"
	.string "{ENG}{STR_VAR_2}{JPN}…… それから……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}……\p"
	.string "おねがい……\n"
	.string "わたしと タッグを……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "{JPN}ありがとうございます……\n"
	.string "とうろくを してきます……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "{JPN}ごいっしょ したかった……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "{JPN}はじめまして! {ENG}{STR_VAR_1}{JPN}です\n"
	.string "ポケモンブリーダーを してます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "{JPN}いい ポケモンを 2ひき そだててるんだ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "どうかな?\n"
	.string "ぼくと タッグを くんで みない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "{JPN}どうも ありがとう!\p"
	.string "では さっそく とうろくを してくるので\n"
	.string "ここで まってて くださいね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "{JPN}きみと パートナーに なれるのを\n"
	.string "たのしみに してたのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "{JPN}あら こんにちは!\n"
	.string "トライアスリートの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "{JPN}いっしょに はしる ポケモン しりたい?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "どう?\n"
	.string "わたしと タッグを くんでみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "{JPN}やったね!\p"
	.string "じゃ さっそく ちゃちゃっと\n"
	.string "とうろくを すませてくるわー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "{JPN}わたしと くんだら さいこう だったのに\n"
	.string "ざんねんね……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "{JPN}やあ! ぼくは {ENG}{STR_VAR_1}{JPN}!\n"
	.string "トライアスリートさ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "{JPN}いっしょに はしってる タフな チームは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "なかなか でしょ?\n"
	.string "いっしょに タッグを くもうよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "{JPN}よーし!\n"
	.string "ひとっぱしり とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "{JPN}きみの タッグパートナーとして\n"
	.string "いっしょに たたかいたかったよ……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "{JPN}バトルガールの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "{JPN}わたしが きたえてるのは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}!\p"
	.string "この コンビ どう?\n"
	.string "わたしと くんでみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "{JPN}ありがとう!\p"
	.string "いまから うけつけで\n"
	.string "とうろくを すませてくるからねー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "{JPN}あなたとなら さいきょうの タッグを\n"
	.string "くめると おもったのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "{JPN}トライアスリートの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "{JPN}いっしょに はしってるのは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかえるんだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を もつ\n{ENG}{STR_VAR_2}{JPN}!\p"
	.string "ぼくたち タッグを くめるよ\n"
	.string "さいこう だと おもわない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "{JPN}サンキュー!\p"
	.string "いまから うけつけで\n"
	.string "とうろくを すませてくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "{JPN}ざんねんだよ! ぼくたちなら\n"
	.string "さいきょうの タッグだったのに!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "{JPN}ぼく?\n"
	.string "うきわボーイの {ENG}{STR_VAR_1}{JPN}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "{JPN}ぼくの ポケモンは なーんだ?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "ねえ?\n"
	.string "ぼくと タッグ くんでくれるよね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "{JPN}やったねー!\p"
	.string "とうろく してくるよー!\n"
	.string "いっしょに がんばろうねー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "{JPN}ぼくの ポケモン ぜったい つよいのに……\n"
	.string "タッグに なれなくて ざんねん!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "{JPN}イェーイ!\n"
	.string "ギタリストの {ENG}{STR_VAR_1}{JPN}って よんでくれ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "{JPN}オレの なかまを みてくれ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "イェーイ! ワイルドだろ?\n"
	.string "タッグで デュエット きめようぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "{JPN}イェーイ! そうこなくちゃ!\n"
	.string "いまから とうろく してくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "{JPN}オレの ポケモン ガンガン つよいぜー!\n"
	.string "こうかい しても しらないぜー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "{JPN}はじめまして\n"
	.string "わたくし ジェントルマンの {ENG}{STR_VAR_1}{JPN}です$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "{JPN}わたくしが しんらい している なかまは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}\p"
	.string "わたくしと タッグを くんで\n"
	.string "いただけませんかな?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "{JPN}おお しんらい してくださり かんしゃします\n"
	.string "とうろくは わたくしが すませましょう$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "{JPN}まことに ざんねんです……\p"
	.string "つぎの きかいを たのしみに\n"
	.string "しておりますよ……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "{JPN}こんにちは {ENG}{STR_VAR_1}{JPN}です\n"
	.string "ポケモンだいすきクラブの かいいんです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "{JPN}いま つれているのは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を おぼえています それと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "いかがですかな?\n"
	.string "わたしの タッグパートナーに なりませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "{JPN}ありがとうございます!\n"
	.string "とうろくは おまかせください!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "{JPN}わたしの ポケモンは いっきゅうひん……\n"
	.string "その よさが わからないとは ざんねんです$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "{JPN}むん!\n"
	.string "わしは たつじんの {ENG}{STR_VAR_1}{JPN}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "{JPN}わしが きたえあげた ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "わしと タッグを くまんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "{JPN}むん!\n"
	.string "すぐに とうろく してこよう!\l"
	.string "ともに ぜんりょくを つくそうぞ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "{JPN}おぬしの せんたくが\n"
	.string "ただしい ことを いのっておるぞ……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "{JPN}はいはい こんにちは\n"
	.string "たつじんの {ENG}{STR_VAR_1}{JPN}ですよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "{JPN}わたしの ポケモンは しっかり そだてたの\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\n"
	.string "この コたちですよ\p"
	.string "わたしと タッグを くんで みませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "{JPN}はいはい\n"
	.string "いまから とうろくを してきますよ……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "{JPN}つぎに あったときには\n"
	.string "タッグを くみたいものですね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "{JPN}ドラゴンつかいの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "{JPN}オレが きたえあげた チームは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "どうだ?\n"
	.string "オレの パートナーに ならないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "{JPN}よし ぜんりょくで いくぜ!\n"
	.string "いまから とうろく してくるぞ いいな?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "{JPN}オレより つよい パートナーは\n"
	.string "そうそう いないぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "{JPN}とりつかいの {ENG}{STR_VAR_1}{JPN}だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "{JPN}ぼくの ポケモンは なにかって?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "ぼくたち なかなかの タッグに\n"
	.string "なれると おもわない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "{JPN}やった ありがとう!\n"
	.string "とうろくは まかせて!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "{JPN}ぼくも ポケモンも つよいのに\n"
	.string "ガッカリだよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "{JPN}にんじゃごっこの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "{JPN}ぼくの ポケモン チームは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "いっしょに タッグを くもうよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "{JPN}やったー!\n"
	.string "とうろく してくるねー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "{JPN}ぼくの つよい ポケモンが いなくて\n"
	.string "きっと こうかい するよー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "{JPN}こんにちは!\n"
	.string "パラソルおねえさんの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "{JPN}いま いっしょなのは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかいます$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "{JPN}もう1ぴきは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかいます\p"
	.string "すてきでしょ?\n"
	.string "わたしたちと タッグを くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "{JPN}ありがとうねー!\p"
	.string "うけつけで とうろく してくるわ\n"
	.string "おたがい がんばろうねー!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "{JPN}わたしの ポケモン とっても つよいのに\n"
	.string "ざんねんよ……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "{JPN}こんにちは\n"
	.string "むしマニアの {ENG}{STR_VAR_1}{JPN}です!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "{JPN}わたしが みつけた ポケモンは ですね\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\n"
	.string "この コたちを みつけたんです\p"
	.string "わたしと タッグを\n"
	.string "くんで みませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "{JPN}はい!\n"
	.string "りょうかい しました!\p"
	.string "すぐに とうろくを してきますからね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "{JPN}わたしが みつけた ポケモンと くめば\n"
	.string "まけなかったのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "{JPN}アホーイ!\n"
	.string "ふなのりの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "{JPN}オレの じまんの ポケモンを みせてやる!\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "まさか ことわったり しないよな\n"
	.string "オレと タッグを くむだろう?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "{JPN}とうぜん だよな!\n"
	.string "いまから とうろく してくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "{JPN}オレと くんだら あいてを\n"
	.string "けちらせたのに! ざんねん だぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "{JPN}やあ {ENG}{STR_VAR_1}{JPN}だよ\n"
	.string "コレクター なんだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "{JPN}ぼくの コレクションの たからは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "すごいでしょ?\n"
	.string "ぼくと タッグを くもうよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "{JPN}おおー!\p"
	.string "じゃあ さっそく\n"
	.string "ふたりぶん とうろく してくるよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "{JPN}ガッカリだよ\n"
	.string "ぼくの ポケモンの よさが わからないなんて$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "{JPN}やあ {ENG}{STR_VAR_1}{JPN}だ\n"
	.string "ポケモンレンジャーを してるんだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "{JPN}ぼくの なかまは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "ぼくたち すごい タッグに\n"
	.string "なれると おもわない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "{JPN}よーし!\n"
	.string "すぐ とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "{JPN}つぎは ぼくの ポケモン\n"
	.string "えらんでくれよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "{JPN}わたしは {ENG}{STR_VAR_1}{JPN}\n"
	.string "ポケモンレンジャーよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "{JPN}わたしの チームを しょうかい するわ\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "わたしたちと タッグを\n"
	.string "くんで みない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "{JPN}がんばるわよー!\n"
	.string "すぐ とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "{JPN}つぎこそ わたしの ポケモンを\n"
	.string "えらんでよね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "{JPN}はじめまして {ENG}{STR_VAR_1}{JPN}です\n"
	.string "アロマなおねえさん ですのよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "{JPN}たびの おともは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかいます$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "{JPN}もう1ぴきは {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかいます\p"
	.string "おきに めすと いいのですが\n"
	.string "わたしの パートナーに なりませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "{JPN}こうえいです\n"
	.string "すぐに とうろく してきますね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "{JPN}つぎに おあいした ときには\n"
	.string "タッグを くめると すてきですね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "{JPN}わしが だれか しりたいか?\n"
	.string "いせきマニアの {ENG}{STR_VAR_1}{JPN}じゃ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "{JPN}わしが つれておる ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "きょうみ ぶかいじゃろ?\n"
	.string "わしと タッグを くんでみないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "{JPN}かしこい はんだんじゃ!\n"
	.string "すぐ とうろく してくるぞい!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "{JPN}うーむ……\n"
	.string "わしの ポケモン つよいと おもうぞ……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "{JPN}エリートトレーナーの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "{JPN}ぼくが いま つれている ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\n"
	.string "クールだろ?\p"
	.string "ぼくたちが タッグを くんだら\n"
	.string "かなり クールだと おもわない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "{JPN}クール!\n"
	.string "すぐ とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "{JPN}きみとなら さいきょうの チームに\n"
	.string "なれると おもったんだけどな……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "{JPN}エリートトレーナーの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "{JPN}わたしが そだてた ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "どう?\n"
	.string "わたしと タッグを くんでみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "{JPN}バッチリね!\n"
	.string "とうろく してくるわね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "{JPN}あなたとなら つよい チームに\n"
	.string "なれると おもったのに……$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "{JPN}ヘイヨー!\n"
	.string "ポケモンマニアの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "{JPN}オレみたいな ヤツが もってるのは?\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\n"
	.string "ってわけさ!\p"
	.string "やろうぜ!\n"
	.string "タッグで あばれまわろうぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "{JPN}いい えらびだ!\n"
	.string "ふたりぶん とうろく してくるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "{JPN}オレの ポケモン つよいぞ!\n"
	.string "こうかい しても しらないぞ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "{JPN}よう!\n"
	.string "ひふきやろうの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "{JPN}オレが そだてあげた ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "どうだい?\n"
	.string "タッグを くんでみないか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "{JPN}よっしゃー!\n"
	.string "とうろく してくるからな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "{JPN}つぎに あったときには\n"
	.string "ぜったい タッグを くんでくれよな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "{JPN}キャンプボーイの {ENG}{STR_VAR_1}{JPN}だよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "{JPN}ぼくが そだててるのは {ENG}{STR_VAR_1}{JPN}を\n"
	.string "つかう {ENG}{STR_VAR_2}{JPN} それと$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}\p"
	.string "いっしょに くんだら たのしそうだよね?\n"
	.string "ぜったい たのしいよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "{JPN}やったね!\n"
	.string "とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "{JPN}つぎは たのむよ?\n"
	.string "きみの チームに はいりたいんだ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "{JPN}こんにちは!\n"
	.string "ピクニックガールの {ENG}{STR_VAR_1}{JPN}です!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "{JPN}わたしが つれている ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "わたしと タッグを\n"
	.string "くんでみませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "{JPN}ありがとうございます!\n"
	.string "すぐに とうろく してきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "{JPN}また いつか いっしょに\n"
	.string "くめると いいですね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "{JPN}サイキッカーの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "{JPN}ぼくが そだてた 2ひきは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "ぼくと タッグを\n"
	.string "くんでみない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "{JPN}もちろん!\n"
	.string "とうろくは まかせて!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "{JPN}また あえたら そのときは\n"
	.string "タッグを くみたいね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "{JPN}わたしは {ENG}{STR_VAR_1}{JPN}\n"
	.string "サイキッカーよ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\n"
	.string "わたしの しもべたちよ\p"
	.string "タッグを くむことに\n"
	.string "きょうみは ないかしら?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "{JPN}ありがとう\n"
	.string "とうろくを してくるわね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "{JPN}また てを くむ チャンスが\n"
	.string "あると いいわね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "{JPN}じゅくがえりの {ENG}{STR_VAR_1}{JPN}です!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n"
	.string "{ENG}{STR_VAR_2}{JPN}が わたしの ポケモンです\p"
	.string "わたしを タッグの パートナーに\n"
	.string "してもらえませんか?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "{JPN}わあ ありがとうございます!\n"
	.string "すぐ うけつけで とうろく してきます!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "{JPN}おねがい……\n"
	.string "つぎは いっしょに くませてくださいね$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "{JPN}ハーイ! わたしは {ENG}{STR_VAR_1}{JPN}!\n"
	.string "ポケモンブリーダーよ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "{JPN}わたしが そだてた ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n{ENG}{STR_VAR_2}{JPN}\p"
	.string "どう? おもしろそう?\n"
	.string "じゃあ わたしと タッグを くまない?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "{JPN}オッケー!\n"
	.string "とうろくは わたしに まかせて!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "{JPN}つぎは ぜったい わたしと くんでよね\n"
	.string "わかった?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "{JPN}わたくし {ENG}{STR_VAR_1}{JPN}と もうします\n"
	.string "ポケモンだいすきクラブの かいいんですの$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "{JPN}わたくしが そだてた ポケモンちゃんは\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}\p"
	.string "とっても かわいいでしょう?\n"
	.string "わたくしと タッグを くみましょう!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "{JPN}ありがとう!\n"
	.string "とうろくに いってまいりますわ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "{JPN}わたくしの ポケモンちゃんは さいこうなのに\n"
	.string "まったく くやしいですわ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "{JPN}ビキニのおねえさんの {ENG}{STR_VAR_1}{JPN}よ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を つかう {ENG}{STR_VAR_2}{JPN}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "{JPN}それと {ENG}{STR_VAR_1}{JPN}を つかう\n"
	.string "{ENG}{STR_VAR_2}{JPN}を きたえてるの\p"
	.string "わたしと タッグを くみましょ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "{JPN}やったねっ!\n"
	.string "ふたりぶん とうろく してくるねっ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "{JPN}こんど あったら\n"
	.string "タッグを くんでよねっ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "{JPN}よう げんき?\n"
	.string "オレは トライアスリートの {ENG}{STR_VAR_1}{JPN}!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "{JPN}なかなかの ポケモンが 2ひき いるぜ\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "オレたちで タッグを くんだら\n"
	.string "いいと おもうんだけど どう?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "{JPN}やったね!\n"
	.string "とうろく してくるから まってて!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "{JPN}つぎは いっしょに\n"
	.string "くませてくれよな!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "{JPN}トライアスリートの {ENG}{STR_VAR_1}{JPN}よ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "{JPN}もう1ぴきの {ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}を つかえるの この 2ひきよ\p"
	.string "どう おもう?\n"
	.string "いい チームに なれると おもうわ$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "{JPN}いい へんじね!\n"
	.string "すぐ とうろく してくるね!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "{JPN}つぎは また パートナーに なる\n"
	.string "チャンスを くれるわよね?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "{JPN}よう! こんにちは!\n"
	.string "かいパンやろうの {ENG}{STR_VAR_1}{JPN}だ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "{JPN}オレが そだててる ポケモン みてくれ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}と$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を もつ {ENG}{STR_VAR_2}{JPN}!\p"
	.string "イケてるだろ?\n"
	.string "タッグを くんだら もっと イケてるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "{JPN}ありがとな!\n"
	.string "とうろく すませて くるぜ!$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "{JPN}また あったら そのときは\n"
	.string "タッグを くんでくれよな?$"

