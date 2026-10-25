@ ============================================================================
@  HOTEL Z -- Team MZ's base (placeholder interior: a copy of the Slateport
@  Pokemon Fan Club layout with its raised stage flattened, LAYOUT_HOTEL_Z).
@  Two ways in, both once the Tradewind intro has played: Tradewind's
@  (23,17) building and the back door in the Rebel Hideout. The exits use
@  the dynamic warp, so you leave the way you came.
@  The first time the player walks in, Mable briefs them on rogue Mega
@  Evolution: Mega Doomsday completes and Two Minutes Is a Long Time starts
@  (bring her the stones of all 19 rogue Megas; she keeps a tally). Then her
@  calls start Primal Signatures and Sky-High Mega (data/scripts/mega_dimension.inc).
@ ============================================================================
HotelZ_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, HotelZ_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HotelZ_OnFrame
	.byte 0

HotelZ_OnTransition::
	special WotHotelZ_SetExit
	call_if_unset FLAG_WOT_MEGA_DOOMSDAY_INTRO, HotelZ_EventScript_HideTeam
	call_if_set FLAG_WOT_MEGA_DOOMSDAY_INTRO, HotelZ_EventScript_ShowTeam
	end

HotelZ_EventScript_HideTeam::
	setflag FLAG_HIDE_HOTEL_Z_TEAM
	return

HotelZ_EventScript_ShowTeam::
	clearflag FLAG_HIDE_HOTEL_Z_TEAM
	return

HotelZ_OnFrame:
	map_script_2 VAR_TEMP_1, 0, HotelZ_EventScript_Briefing
	.2byte 0

HotelZ_EventScript_Briefing::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_WOT_HOTEL_Z_MET, HotelZ_EventScript_BriefingDone
	goto_if_unset FLAG_WOT_MEGA_DOOMSDAY_INTRO, HotelZ_EventScript_BriefingDone
	applymovement LOCALID_HOTEL_Z_LIDA, Common_Movement_ExclamationMark
	waitmovement 0
	@ Whoever is talking hops (Lida, Canari) or steps up (Mable), so the
	@ player learns who's who; the nameplate colours match.
	applymovement LOCALID_HOTEL_Z_LIDA, HotelZ_Movement_Hop
	waitmovement 0
	setspeaker SP_NAME_LIDA
	msgbox HotelZ_Text_LidaWelcome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HOTEL_Z_CANARI, HotelZ_Movement_Hop
	waitmovement 0
	setspeaker SP_NAME_CANARI
	msgbox HotelZ_Text_CanariWelcome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HOTEL_Z_MABLE, Common_Movement_WalkDown
	waitmovement 0
	setspeaker SP_NAME_MABLE
	msgbox HotelZ_Text_MableResearch, MSGBOX_DEFAULT
	msgbox HotelZ_Text_MableOffer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HOTEL_Z_MABLE, HotelZ_Movement_MableStepBack
	waitmovement 0
	applymovement LOCALID_HOTEL_Z_LIDA, HotelZ_Movement_Hop
	waitmovement 0
	setspeaker SP_NAME_LIDA
	msgbox HotelZ_Text_LidaLongTime, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	setflag FLAG_WOT_HOTEL_Z_MET
	completequest QUEST_MEGA_DOOMSDAY
	startquest QUEST_TWO_MINUTES
HotelZ_EventScript_BriefingDone::
	releaseall
	end

HotelZ_Movement_Hop:
	jump_in_place_down
	step_end

HotelZ_Movement_MableStepBack:
	walk_up
	face_down
	step_end

@ Mable keeps a tally of the rogue Megas' stones (the player keeps the
@ stones). Only the dimension's own claims count. At 19 she runs her tests;
@ after that she has a line for each stage of her quest chain.
HotelZ_EventScript_Mable::
	lock
	faceplayer
	setspeaker SP_NAME_MABLE
	specialvar VAR_RESULT, WotMegaDim_MableReport
	buffernumberstring STR_VAR_1, VAR_0x8004
	goto_if_eq VAR_RESULT, 3, HotelZ_EventScript_MableStage
	goto_if_eq VAR_RESULT, 2, HotelZ_EventScript_MableAllStones
	goto_if_eq VAR_RESULT, 1, HotelZ_EventScript_MableRecorded
	goto_if_eq VAR_0x8004, 0, HotelZ_EventScript_MableWaiting
	msgbox HotelZ_Text_MableTally, MSGBOX_DEFAULT
	goto HotelZ_EventScript_MableEnd

HotelZ_EventScript_MableWaiting::
	msgbox HotelZ_Text_MableWaiting, MSGBOX_DEFAULT
	goto HotelZ_EventScript_MableEnd

HotelZ_EventScript_MableRecorded::
	call_if_eq VAR_0x8004, 1, HotelZ_EventScript_MableFirstSample
	msgbox HotelZ_Text_MableRecorded, MSGBOX_DEFAULT
	closemessage
	questtoast QUEST_TOAST_UPDATE, QUEST_TWO_MINUTES
	goto HotelZ_EventScript_MableEnd

HotelZ_EventScript_MableFirstSample::
	msgbox HotelZ_Text_MableSample, MSGBOX_DEFAULT
	return

HotelZ_EventScript_MableAllStones::
	msgbox HotelZ_Text_MableAllStones, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	goto_if_quest_complete QUEST_TWO_MINUTES, HotelZ_EventScript_MableEnd
	completequest QUEST_TWO_MINUTES
	goto HotelZ_EventScript_MableEnd

@ VAR_0x8005 = her stage (WotMegaDim MABLE_STAGE_*).
HotelZ_EventScript_MableStage::
	goto_if_eq VAR_0x8005, 1, HotelZ_EventScript_MableTesting
	goto_if_eq VAR_0x8005, 2, HotelZ_EventScript_MablePrimals
	goto_if_eq VAR_0x8005, 3, HotelZ_EventScript_MableTesting
	goto_if_eq VAR_0x8005, 4, HotelZ_EventScript_MableRayquaza
	msgbox HotelZ_Text_MableAfter, MSGBOX_DEFAULT
	goto HotelZ_EventScript_MableEnd

HotelZ_EventScript_MableTesting::
	msgbox HotelZ_Text_MableTesting, MSGBOX_DEFAULT
	goto HotelZ_EventScript_MableEnd

HotelZ_EventScript_MablePrimals::
	msgbox HotelZ_Text_MablePrimals, MSGBOX_DEFAULT
	goto HotelZ_EventScript_MableEnd

HotelZ_EventScript_MableRayquaza::
	msgbox HotelZ_Text_MableRayquaza, MSGBOX_DEFAULT
	goto HotelZ_EventScript_MableEnd

HotelZ_EventScript_MableEnd::
	closemessage
	setspeaker SP_NAME_NONE
	release
	end

HotelZ_EventScript_Lida::
	lock
	faceplayer
	setspeaker SP_NAME_LIDA
	msgbox HotelZ_Text_LidaIdle, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

HotelZ_EventScript_Canari::
	lock
	faceplayer
	setspeaker SP_NAME_CANARI
	msgbox HotelZ_Text_CanariIdle, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	release
	end

HotelZ_Text_LidaWelcome:
	.string "{JPN}{ENG}{PLAYER}{JPN}！ ほんとに きてくれたんだ！\p"
	.string "ホテルZへ ようこそ。 おもてむきは\n"
	.string "ホテル。 うらでは…\l"
	.string "チームMZの きちなの。$"

HotelZ_Text_CanariWelcome:
	.string "{JPN}うらの おもてむき かな。 ちゃんと\n"
	.string "ロゴも あるんだから。$"

HotelZ_Text_MableResearch:
	.string "{JPN}あなたが オニに たちむかった\n"
	.string "トレーナーね。 わたしは モミジ。 チームMZの\l"
	.string "けんきゅういんよ。 ほうこくは わたしに。\p"
	.string "メガシンカを けんきゅうしているの。 さいきんは\n"
	.string "おかしく なってしまった メガシンカをね。\p"
	.string "はぐれメガ。 トレーナーも\n"
	.string "メガリングも ないのに\l"
	.string "メガシンカしたままの ポケモン。\p"
	.string "わたしたちの せかいを うつした はいいろの\n"
	.string "かがみ メガじげんから さけめを\l"
	.string "とおって ひきずりこまれているの。$"

HotelZ_Text_MableOffer:
	.string "{JPN}さけめを あけて おけるのは 2ふんだけ。\n"
	.string "1びょうも のばせない。\p"
	.string "なかに はいって はぐれメガを みつけ\n"
	.string "おとなしく させて。 サンプルとして\l"
	.string "メガストーンを もちかえってね。\p"
	.string "はぐれメガは 19ひき いるわ。\n"
	.string "ぜんぶの データが ほしいの。\p"
	.string "さけめは まいあさ 8じに ひらくわ。\n"
	.string "ひかりを めじるしに してね。$"

HotelZ_Text_LidaLongTime:
	.string "{JPN}2ふんって ながいよ…\n"
	.string "すばやければ ね！$"

HotelZ_Text_MableSample:
	.string "{JPN}それって… はぐれメガの いし？\n"
	.string "ほんとうに やったのね。\p"
	.string "まさに ほしかった サンプルよ。\n"
	.string "ありがとう {ENG}{PLAYER}{JPN}。$"

HotelZ_Text_MableRecorded:
	.string "{JPN}データを とらせて… はい おしまい。\n"
	.string "いしは あなたが もっていて。\p"
	.string "きろく かんりょう！ これで {ENG}{STR_VAR_1}{JPN}\n"
	.string "/ 19よ。$"

HotelZ_Text_MableTally:
	.string "{JPN}いまの ところ {ENG}{STR_VAR_1}{JPN} / 19。\n"
	.string "さけめを さがして つづけてね！$"

HotelZ_Text_MableAllStones:
	.string "{JPN}これで さいご。 19 / 19。\n"
	.string "はぐれメガの いしが ぜんぶ そろった。\p"
	.string "これで テストが できるわ。\n"
	.string "1にち ちょうだい。 れんらく するから。$"

HotelZ_Text_MableTesting:
	.string "{JPN}テストは まだ つづいているわ。\n"
	.string "なにか わかったら すぐに\l"
	.string "れんらく するわね。$"

HotelZ_Text_MablePrimals:
	.string "{JPN}ゲンシグラードンと ゲンシカイオーガ。\n"
	.string "ポータルの なかで まっているわ。\p"
	.string "どちらも つかまえて {ENG}{PLAYER}{JPN}。\n"
	.string "たおすだけじゃ だめなの。$"

HotelZ_Text_MableRayquaza:
	.string "{JPN}メガレックウザが ポータルに いるわ。\n"
	.string "さけめを ひきさいて しまう まえに\l"
	.string "つかまえて。$"

HotelZ_Text_MableWaiting:
	.string "{JPN}さけめを みつけて はぐれメガを たおし\n"
	.string "いしを もってきて。\l"
	.string "じかんは 2ふん。 いって！$"

HotelZ_Text_MableAfter:
	.string "{JPN}さけめは おさまりつつ あるわ。\n"
	.string "{ENG}{PLAYER}{JPN}の おかげで チームMZは\l"
	.string "ほしかった データを ぜんぶ てにいれた。$"

HotelZ_Text_LidaIdle:
	.string "{JPN}チームMZは いつも ひとでぶそくなの。\n"
	.string "なかまに なって くれて うれしい！$"

HotelZ_Text_CanariIdle:
	.string "{JPN}カメラは きに しないで。 うーん\n"
	.string "ちょっとは きに してね。$"
