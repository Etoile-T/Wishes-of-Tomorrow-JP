	.set LOCALID_SHINKANSEN_GOON, 1

ShinkansenInterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShinkansenInterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ShinkansenInterior_OnResume
	.byte 0

ShinkansenInterior_OnResume::
	questindicator LOCALID_SHINKANSEN_GOON, SIDE_QUEST_FROZEN_TRACKS
	end

@ After the EMBER BADGE the train is gone from SennenVillage entirely (the cleared
@ track tile has no door behavior, so the door warp dies and this interior becomes
@ unreachable). Belt-and-braces: if it IS ever entered (debug warps, future edits),
@ make sure the goon is gone too. (Side effect: also marks the goon "defeated" for
@ the gym's re-talk dialogue branch -- harmless, since this can only run post-badge.)
ShinkansenInterior_OnTransition::
	call_if_set FLAG_BADGE01_GET, ShinkansenInterior_EventScript_HideGoon
	end

ShinkansenInterior_EventScript_HideGoon::
	setflag FLAG_HIDE_SHINKANSEN_GOON
	return

@ The masked goon (??? -- placeholder Team Rocket sprite/Magma-grunt battle pic; swap for the
@ oni-masked custom sprite later). Talk to him -> taunt -> battle (weak team) -> he flees.
ShinkansenInterior_EventScript_Goon::
	lock
	faceplayer
	setspeaker SP_NAME_GOON
	msgbox ShinkansenInterior_Text_GoonIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SHINKANSEN_GOON, ShinkansenInterior_Text_GoonDefeat
	setspeaker SP_NAME_GOON
	msgbox ShinkansenInterior_Text_GoonAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SHINKANSEN_GOON, ShinkansenInterior_Movement_GoonRunOff
	waitmovement 0
	setflag FLAG_HIDE_SHINKANSEN_GOON
	removeobject LOCALID_SHINKANSEN_GOON
	startquest SIDE_QUEST_FROZEN_TRACKS
	release
	end

ShinkansenInterior_Movement_GoonRunOff:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

@ Frozen control consoles. Locked until the EMBER BADGE thaws the system.
ShinkansenInterior_EventScript_Computer::
	lockall
	goto_if_set FLAG_BADGE01_GET, ShinkansenInterior_EventScript_ComputerFixed
	msgbox ShinkansenInterior_Text_ComputerFrozen, MSGBOX_DEFAULT
	releaseall
	end

ShinkansenInterior_EventScript_ComputerFixed::
	msgbox ShinkansenInterior_Text_ComputerFixed, MSGBOX_DEFAULT
	releaseall
	end

ShinkansenInterior_Text_GoonIntro:
	.string "{JPN}…おそかったな ガキ。\p"
	.string "この ふるい しんかんせんの はぐるまは\n"
	.string "こおりで かためてやった。 はがねみたいにな。\p"
	.string "もう だれも センネンせんで やまへは\n"
	.string "のぼれねえ。 ボスの めいれいだ。\p"
	.string "で おまえは？ くるべきじゃない ところに\n"
	.string "まよいこんだ ただの ガキだろ。\p"
	.string "うせろ。 さもなきゃ ぺしゃんこだ！$"

ShinkansenInterior_Text_GoonDefeat:
	.string "{JPN}ちっ…！ ガキに ぺしゃんこに されるとは…？$"

ShinkansenInterior_Text_GoonAfter:
	.string "{JPN}わかった わかったよ！ でていくって！\p"
	.string "だが はぐるまの こおりを とかすのは\n"
	.string "むりだぜ。 システムは がっちり とまってる。\p"
	.string "おまえは ぜったいに やまへは いけねえ！$"

ShinkansenInterior_Text_ComputerFrozen:
	.string "{JPN}せいぎょばんは こおりで おおわれている。\n"
	.string "ひょうじは ぜんぶ ERRORと てんめつしている。\p"
	.string "センネンせんの システムは こおりついていて\n"
	.string "でんしゃは 1ミリも うごかない。$"

ShinkansenInterior_Text_ComputerFixed:
	.string "{JPN}せいぎょばんが ふたたび うごきだした。\p"
	.string "センネンせん: シントウキョウゆき\n"
	.string "まもなく はっしゃ。 システム せいじょう。$"

@ ============================================================================
@  ACT 2 BOARDING (added): once the keycard door opens at Sennen
@  (FLAG_HIDE_SHINKANSEN_ACT2_GOONS cleared), the car is full of masked
@  passengers who do NOT battle -- just unsettling smalltalk.
@  Taking the seat at the far end (coord triggers at 12,2 / 12,3) departs
@  the train: shake, fade to black, "ACT III: COOKED".
@  Seat/passenger coords are best-guess vs the 14x5 car -- nudge in Porymap.
@ ============================================================================
ShinkansenInterior_EventScript_Passenger1::
	lock
	faceplayer
	msgbox ShinkansenInterior_Text_Passenger1, MSGBOX_DEFAULT
	release
	end

ShinkansenInterior_EventScript_Passenger2::
	lock
	faceplayer
	msgbox ShinkansenInterior_Text_Passenger2, MSGBOX_DEFAULT
	release
	end

ShinkansenInterior_EventScript_Passenger3::
	lock
	faceplayer
	msgbox ShinkansenInterior_Text_Passenger3, MSGBOX_DEFAULT
	release
	end

ShinkansenInterior_EventScript_TakeSeat::
	goto_if_set FLAG_HIDE_SHINKANSEN_ACT2_GOONS, ShinkansenInterior_EventScript_SeatInert
	goto_if_set FLAG_ACT3_STARTED, ShinkansenInterior_EventScript_SeatInert
	setvar VAR_TEMP_2, 1
	lockall
	msgbox ShinkansenInterior_Text_TakeSeat, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_TRUCK_DOOR
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 6  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox ShinkansenInterior_Text_Departing1, MSGBOX_DEFAULT
	closemessage
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 12 @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox ShinkansenInterior_Text_Departing2, MSGBOX_DEFAULT
	closemessage
	@ Act break staged to MIRROR the Act II card (StarSummit): a slow fade to
	@ blank, a long heavy hold, a silent beat, then the title.
	fadescreenspeed FADE_TO_BLACK, 12
	delay 150
	setflag FLAG_ACT3_STARTED
	msgbox ShinkansenInterior_Text_PreTitle, MSGBOX_DEFAULT
	closemessage
	delay 40
	msgbox ShinkansenInterior_Text_ActThree, MSGBOX_DEFAULT
	closemessage
	delay 40
	@ The ride is skipped: the title card holds on black while the train runs,
	@ then Act 3 opens on the rainy Shin-Tokyo platform (the arrival cutscene
	@ lives in ShinTokyoStation/scripts.inc).
	playse SE_TRUCK_MOVE
	delay 60
	warp MAP_SHIN_TOKYO_STATION, 6, 5
	waitstate
	releaseall
	end

ShinkansenInterior_EventScript_SeatInert::
	end

@ ============================================================================
@  Text (Act 2 boarding)
@ ============================================================================
ShinkansenInterior_Text_Passenger1::
	.string "{JPN}めんを つけた じょうきゃくは\n"
	.string "ふりむかない。\p"
	.string "「どこでも すわりな。 さいごには\n"
	.string "みんな いくべき ところへ つく」$"

ShinkansenInterior_Text_Passenger2::
	.string "{JPN}「ひがしへは はじめてか？ シントウキョウの\n"
	.string "あかりは けっして きえない。\p"
	.string "「マスターは いう。 ねむりなど もっと\n"
	.string "なまけた なにかの れんしゅうに すぎぬと」\p"
	.string "めんの うらで わらいでは ない\n"
	.string "なにかが わらった。$"

ShinkansenInterior_Text_Passenger3::
	.string "{JPN}きっぷ？ ケケケ。 もう だれも\n"
	.string "きっぷなんか しらべないよ。\p"
	.string "でんしゃは だれを はこんでいるか\n"
	.string "わかってるのさ。$"

ShinkansenInterior_Text_TakeSeat::
	.string "{JPN}{ENG}{PLAYER}{JPN}は しゃりょうの さいごの\n"
	.string "せきに しずみこんだ。\p"
	.string "まどの そと: センネンの うえの けむりと\n"
	.string "とおくで ちいさく ひかる\l"
	.string "まだ もえている たたかいの ひ。\p"
	.string "あいしてきた すべてが\n"
	.string "この ガラスの むこうがわに ある。$"

ShinkansenInterior_Text_Departing1::
	.string "{JPN}ドアが つぎつぎと しまっていく。\n"
	.string "しゃりょうの さいごまで。\p"
	.string "ずっと さきで せんろの しんごうが\n"
	.string "あおに かわる。 ひがしの はてまで。\p"
	.string "だいじんは やくそくを まもった。$"

ShinkansenInterior_Text_Departing2::
	.string "{JPN}しんかんせんが ガクンと ゆれ…\p"
	.string "…センネンの ホームの あかりが\n"
	.string "ながい しろい すじに なって\l"
	.string "とおざかっていく。\p"
	.string "この でんしゃで まどの そとを みている\n"
	.string "ものは いない。 あなたの ほかには。$"

ShinkansenInterior_Text_PreTitle::
	.string "{JPN}…$"

ShinkansenInterior_Text_ActThree::
	.string "{JPN}だい3まく: せんにゅう$"

ShinkansenInterior_Text_TrainHum::
	.string "{JPN}でんしゃは やみの なかを ひがしへ\n"
	.string "うなりながら はしる。\p"
	.string "つぎは シントウキョウ。$"
