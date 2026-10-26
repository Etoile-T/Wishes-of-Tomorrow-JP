MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_MAUVILLE_WALLY
	removeobject LOCALID_MAUVILLE_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_MAUVILLE_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_MAUVILLE_SCOTT, 12, 13
	addobject LOCALID_MAUVILLE_SCOTT
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_MAUVILLE_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "{JPN}おじさん: このこは ポケモンの おかげで\n"
	.string "げんきに なれたような もんだけど\l"
	.string "ちょっと げんきに なりすぎ なんだ……$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "{JPN}ミツル: おじさん おねがい だから!\p"
	.string "じぶんが どれくらい つよくなったか\n"
	.string "このジムで ためして みたいんだ!\p"
	.string "ね ね いいでしょう!?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "{JPN}おじさん: まあ まちなさい ミツル。\p"
	.string "ポケモンと くらすように なってから\n"
	.string "ずいぶん つよくなったのは たしかだ。\p"
	.string "でも いきなり ジムに ちょうせんするのは\n"
	.string "むりを していると おもわないかい?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "{JPN}ミツル: むり なんか してません\p"
	.string "ぼくと ラルトスが ちからを あわせれば\n"
	.string "だれにだって かてるんです!$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "{JPN}ミツル: あっ! {ENG}{PLAYER}{JPN}さん!\p"
	.string "ぼく であったころより\n"
	.string "ずっと つよくなったんです。\p"
	.string "{ENG}{PLAYER}{JPN}さんと おじさんに\n"
	.string "それを わかって ほしいんです。\p"
	.string "{ENG}{PLAYER}{JPN}さん おねがいです。\n"
	.string "ぼくと しょうぶ してくれませんか?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "{JPN}ミツル: ああ… しょうぶ してくれないと\n"
	.string "{ENG}{PLAYER}{JPN}さん ぼくが つよくなったことを\l"
	.string "おじさんに わかって もらえません。$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "{JPN}おじさん: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}とやら\n"
	.string "わるいけど ミツルくんと\l"
	.string "いちどだけ しょうぶ してくれないかな?\p"
	.string "このままだと なにを いっても\n"
	.string "きいて もらえそうに ないよ。$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "{JPN}ミツル: {ENG}{PLAYER}{JPN}さん おねがいです!\n"
	.string "ぼくと しょうぶ してください。$"

MauvilleCity_Text_WallyHereICome:
	.string "{JPN}ミツル: ありがとう {ENG}{PLAYER}{JPN}さん\p"
	.string "それでは…… いきますね!$"

MauvilleCity_Text_WallyDefeat:
	.string "{JPN}ミツル: … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "ぼくの まけ です……$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "{JPN}ミツル: おじさん……\n"
	.string "ぼく シダケに もどります。$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{JPN}{ENG}{PLAYER}{JPN}さん ありがとう\n"
	.string "トレーナーって むずかしいんですね。\p"
	.string "ただ ポケモンを もっていて\n"
	.string "たたかわせる だけじゃ ほんとうの いみで\l"
	.string "トレーナーには なれないんだ……$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "{JPN}おじさん: ミツルくん\n"
	.string "そんなに しょげることは ないよ\p"
	.string "これから もっともっと\n"
	.string "つよくなるのを じゃまするものは あるかい?\p"
	.string "さあ うちに かえろう\n"
	.string "みんな まってるよ。$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "{JPN}おじさん: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} そうか!\n"
	.string "きみが あの トレーナー なんだね。\l"
	.string "ミツルが ポケモンを つかまえるとき\l"
	.string "みまもって くれたという。\p"
	.string "いつか シダケの わたしたちの いえへ\n"
	.string "あそびに こないかい?\l"
	.string "ミツルも きっと よろこぶよ。$"


MauvilleCity_Text_WallyPokenavCall:
	.string "{JPN}… … … … … …\n"
	.string "… … … … … ピッ!\p"
	.string "ミツル: あっ {ENG}{PLAYER}{JPN}さん!\p"
	.string "おじさんが ポケナビを かってくれたんです!\n"
	.string "それを つたえたくて!\p"
	.string "これで いつでも れんらく できますね\n"
	.string "{ENG}{PLAYER}{JPN}さん!\p"
	.string "… … … … … …\n"
	.string "… … … … … プツッ!$"

MauvilleCity_Text_RegisteredWally:
	.string "{JPN}ミツルを\n"
	.string "ポケナビに とうろく した!$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "{JPN}エニシダ: ふふ…\n"
	.string "さっきの しょうぶを みていたよ!\p"
	.string "ミツルくんとは ともだち\n"
	.string "なんだろう?\p"
	.string "それでも いっさい てかげんせず\n"
	.string "みごとに かって みせたね。\p"
	.string "そう! それこそが ほんとうの\n"
	.string "ポケモンしょうぶと いうものだ!\p"
	.string "わたしは そういう トレーナーに あこがれるよ!\p"
	.string "… … … … … …\n"
	.string "きみを おうえん しているよ!$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "{JPN}テッセン: おお {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "げんき いっぱいの ようじゃな!\l"
	.string "いいことじゃ わっはははは!\p"
	.string "よし! きめた!\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}に おねがいが あるぞい!\p"
	.string "キンセツシティには ニューキンセツという\n"
	.string "ちかの くかくが あるんじゃ。\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}に そこへ いって\n"
	.string "はつでんそうちを とめてきて ほしいのじゃ。\p"
	.string "はつでんそうちが すこし ぼうそうぎみで\n"
	.string "あぶなく なってきて おるんじゃよ。\p"
	.string "ほら これが ニューキンセツに\n"
	.string "はいるための カギじゃ。$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "{JPN}テッセン: なあに しんぱいは いらん。\n"
	.string "きみなら なんてこと ないじゃろう。\p"
	.string "ニューキンセツの いりぐちは 110ばんどうろから\n"
	.string "すこし なみのりした ところじゃ。\p"
	.string "それじゃ しんらい しておるぞ!\n"
	.string "わっはははは!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "{JPN}テッセン: わっはははは!\p"
	.string "やはりな {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "きみに たのんで せいかいじゃった!\p"
	.string "おれいに 10まんボルトの\n"
	.string "はいった わざマシンを やろう!\p"
	.string "えんりょ するな! きみの てがらじゃ!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "{JPN}テッセン: わっはははは!\p"
	.string "わかものが みずから すすんで\n"
	.string "ひっぱっていくのは なんとも うれしいのう!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "{JPN}ポケモンしょうぶ なんかを するのは\n"
	.string "いいこと だけどさ…\p"
	.string "ポケモンが きずついたら\n"
	.string "げんきに なるまで かんびょう しなくちゃね。$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "{JPN}この まちの みちは きたと みなみ\n"
	.string "ひがしと にしへ のびている。\p"
	.string "だから いろんな ひとが\n"
	.string "とおって いくんだよ。$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "{JPN}カゼノの じてんしゃやには もう いった?\p"
	.string "てんしゅの カゼノさんは\n"
	.string "とても きまえの いい ひとだよ。$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "{JPN}じてんしゃに のっていても\n"
	.string "やせいの ポケモンは とびだしてくるよ!$"

MauvilleCity_Text_CitySign:
	.string "{JPN}ここは キンセツ シティ\n"
	.string "あかるく かがやく たのしい まち。$"

MauvilleCity_Text_GymSign:
	.string "{JPN}キンセツ シティ ポケモンジム\n"
	.string "リーダー テッセン\l"
	.string "あっかるい でんげき オヤジ!$"

MauvilleCity_Text_BikeShopSign:
	.string "{JPN}「じゃりみちを はしって\n"
	.string "たましいを ゆさぶれ!」\l"
	.string "カゼノの じてんしゃや$"

MauvilleCity_Text_GameCornerSign:
	.string "{JPN}だれもが あそべる すてきな スポット!\n"
	.string "「キンセツ ゲームコーナー」$"

MauvilleCity_Text_ExplainTV:
	.string "{JPN}やあ テレビは みてるかい?\p"
	.string "さいきん おもしろい あたらしい ばんぐみが\n"
	.string "たくさん ふえたんだ。\p"
	.string "テレビって いいよね。いきなり ともだちが\n"
	.string "うつっていたことも あるよ。\p"
	.string "それに ほんにんに しらせずに テレビに\n"
	.string "うつしちゃうことも あるんだ。\p"
	.string "いつか テレビに でられたらなあ。\p"
	.string "だから できるだけ テレビを\n"
	.string "みておくと いいと おもうよ。$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "{JPN}やあ テレビは みてるかい?$"
