	.equ LOCALID_DOJO_MOM, 2

@ The arrival walk. DOJO_ARRIVAL_Y is where MunenHomeAct2 warps the player in
@ (keep the two in step); Mom waits one tile ahead of them.
	.equ DOJO_PATH_X,      14
	.equ DOJO_ARRIVAL_Y,   25
	.equ DOJO_MOM_START_Y, DOJO_ARRIVAL_Y - 1

Dojo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Dojo_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Dojo_OnFrame
	.byte 0

@ The safehouse is the checkpoint for the whole Sennen assault: whiteouts in
@ SennenAct2 (which also setrespawns this) and in here come back to the cots
@ beside the Blissey healer.
Dojo_OnTransition::
	setrespawn HEAL_LOCATION_DOJO
	@ On the walk-in from Munen, Mom starts at the garden gate instead of at
	@ her post so she can lead the player up; the walk puts her template back.
	@ FLAG_ACT2_SAFEHOUSE_INTRO_DONE covers both halves of that first visit.
	goto_if_set FLAG_ACT2_SAFEHOUSE_INTRO_DONE, Dojo_OnTransition_End
	goto_if_set FLAG_HIDE_DOJO_REBELS, Dojo_OnTransition_End
	goto_if_unset FLAG_ACT2_HOME_CUTSCENE_DONE, Dojo_OnTransition_End
	setobjectxyperm LOCALID_DOJO_MOM, DOJO_PATH_X, DOJO_MOM_START_Y
	setvar VAR_TEMP_1, 1
Dojo_OnTransition_End::
	end

Dojo_OnFrame:
	map_script_2 VAR_TEMP_1, 1, Dojo_EventScript_Arrival
	map_script_2 VAR_TEMP_0, 0, Dojo_EventScript_RebellionIntro
	.2byte 0

@ ============================================================================
@  ARRIVAL (once): Mom walks the player up the garden path from the gate to
@  the temple steps, then takes her post, and the Rebellion intro follows on.
@  Both walks are the same 13 steps, so Mom stays exactly one tile ahead.
@ ============================================================================
Dojo_EventScript_Arrival::
	setvar VAR_TEMP_1, 0
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Dojo_Movement_PlayerLookUp
	waitmovement 0
	setspeaker SP_NAME_MOM
	msgbox Dojo_Text_MomThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOJO_MOM, Dojo_Movement_UpThePath
	applymovement OBJ_EVENT_ID_PLAYER, Dojo_Movement_UpThePath
	waitmovement 0
	applymovement LOCALID_DOJO_MOM, Dojo_Movement_MomToPost
	waitmovement 0
	@ put her template back, or she would respawn at the gate on every visit
	setobjectxyperm LOCALID_DOJO_MOM, 12, 10
	delay 20
	goto Dojo_EventScript_RebellionIntro
	end

Dojo_Movement_PlayerLookUp:
	face_up
	step_end

Dojo_Movement_UpThePath:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ (14,11) -> her post at (12,10), facing the room
Dojo_Movement_MomToPost:
	walk_left
	walk_left
	walk_up
	face_down
	step_end

Dojo_Text_MomThisWay:
	.string "{JPN}こっちよ。 はなの さいた\n"
	.string "みちを のぼって。\p"
	.string "わたしの そばを はなれないでね。$"

@ ============================================================================
@  THE SAFEHOUSE (Act 2) -- the old dojo, where the Rebellion gathers.
@  Rebel objects are hidden by FLAG_HIDE_DOJO_REBELS (set at new game,
@  cleared by Mom in the MunenHomeAct2 cutscene).
@  ROSTER (the Frostwood Gym crew + Mom):
@    (Gen. Edwards removed 2026-07-28 -- the SNAG MACHINE now comes from
@     Mikmanc during the Act 3 jailbreak; Edwards is saved for later.)
@    REDFATALITY (GORDIE gfx)   -> TM13 ICE BEAM, a fighter's parting gift
@    MINISTER (SCOTT gfx)       -> IT expert: the SHINKANSEN KEY + he will
@                                  handle the NETWORK BREACH on assault day
@    YIFFER (HIKER gfx)          -> LEFTOVERS + keep-going encouragement
@    MIKMANC (YOUNGSTER gfx)    -> LIFE ORB + a word of courage
@    MOM                        -> the Soothe Bell + LEFTOVERS (because Mom)
@  INTRO CUTSCENE (once, ON_FRAME): camera pans up to the group, Mom:
@  "Welcome to the Rebellion." They will hold Sennen -- and some will die
@  for it -- so the player can board the Shinkansen to Shin-Tokyo.
@ ============================================================================
Dojo_EventScript_RebellionIntro::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_HIDE_DOJO_REBELS, Dojo_EventScript_RebellionIntroEnd
	goto_if_set FLAG_ACT2_SAFEHOUSE_INTRO_DONE, Dojo_EventScript_RebellionIntroEnd
	lockall
	playbgm MUS_HG_BELL_TOWER, FALSE
	delay 30
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Dojo_Movement_CameraPanUp
	waitmovement 0
	msgbox Dojo_Text_IntroWelcome, MSGBOX_DEFAULT
	msgbox Dojo_Text_IntroPlan, MSGBOX_DEFAULT
	msgbox Dojo_Text_IntroCost, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, Dojo_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setflag FLAG_ACT2_SAFEHOUSE_INTRO_DONE
	fadedefaultbgm
	releaseall
	end

Dojo_EventScript_RebellionIntroEnd::
	end

@ The pan was written for an entrance that no longer exists: from the temple
@ steps the group is four tiles up, and twelve would run off the top.
Dojo_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Dojo_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ --------------------------------------------------------------------------
@  Members
@ --------------------------------------------------------------------------
Dojo_EventScript_RebelMom::
	lock
	faceplayer
	goto_if_set FLAG_ACT2_REBEL_GIFT_MOM, Dojo_EventScript_RebelMomAfter
	msgbox Dojo_Text_MomGift1, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	setflag FLAG_ACT2_REBEL_GIFT_MOM
	msgbox Dojo_Text_MomGift2, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelMomAfter::
	msgbox Dojo_Text_MomAfter, MSGBOX_DEFAULT
	release
	end

@ (Gen. Edwards was removed from the safehouse roster 2026-07-28: the SNAG
@ MACHINE is now delivered solely by Mikmanc in the Act 3 jailbreak, per
@ WoT_Act3_Canon.md Step 4. Edwards is being saved for a later appearance.)

Dojo_EventScript_RebelRedFatality::
	lock
	faceplayer
	setspeaker SP_NAME_RED_FATALITY
	goto_if_set FLAG_ACT2_REBEL_GIFT_REDFATALITY, Dojo_EventScript_RebelRedFatalityAfter
	msgbox Dojo_Text_RedFatalityGift1, MSGBOX_DEFAULT
	giveitem ITEM_TM13
	setflag FLAG_ACT2_REBEL_GIFT_REDFATALITY
	msgbox Dojo_Text_RedFatalityGift2, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelRedFatalityAfter::
	msgbox Dojo_Text_RedFatalityAfter, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelMinister::
	lock
	faceplayer
	setspeaker SP_NAME_MINISTER
	checkitem ITEM_SHINKANSEN_KEY
	goto_if_eq VAR_RESULT, TRUE, Dojo_EventScript_RebelMinisterAfter
	msgbox Dojo_Text_MinisterGift1, MSGBOX_DEFAULT
	giveitem ITEM_SHINKANSEN_KEY
	msgbox Dojo_Text_MinisterGift2, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelMinisterAfter::
	msgbox Dojo_Text_MinisterAfter, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelMikmanc::
	lock
	faceplayer
	setspeaker SP_NAME_MIKMANC
	goto_if_set FLAG_ACT2_REBEL_GIFT_MIKMANC, Dojo_EventScript_RebelMikmancAfter
	msgbox Dojo_Text_MikmancGift1, MSGBOX_DEFAULT
	giveitem ITEM_LIFE_ORB
	setflag FLAG_ACT2_REBEL_GIFT_MIKMANC
	msgbox Dojo_Text_MikmancGift2, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelMikmancAfter::
	msgbox Dojo_Text_MikmancAfter, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelYiffer::
	lock
	faceplayer
	setspeaker SP_NAME_YIFFER
	goto_if_set FLAG_ACT2_REBEL_GIFT_YIFFER, Dojo_EventScript_RebelYifferAfter
	msgbox Dojo_Text_YifferGift1, MSGBOX_DEFAULT
	giveitem ITEM_LEFTOVERS
	setflag FLAG_ACT2_REBEL_GIFT_YIFFER
	msgbox Dojo_Text_YifferGift2, MSGBOX_DEFAULT
	release
	end

Dojo_EventScript_RebelYifferAfter::
	msgbox Dojo_Text_YifferAfter, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  Text
@ ============================================================================
Dojo_Text_IntroWelcome::
	.string "{JPN}レジスタンスへ ようこそ\n"
	.string "{ENG}{PLAYER}{JPN}。$"

Dojo_Text_IntroBrief::
	.string "{JPN}ミュートリッドが この ちほうを\n"
	.string "のっとった。 やつらは ポケモンを\l"
	.string "けがし ひとを せんのう する\l"
	.string "きかいを つくっている。\p"
	.string "とめなければ ならない。\p"
	.string "さくせんは かんたんよ。\n"
	.string "センネンで やつらと たたかい\l"
	.string "えきを とりもどす。\p"
	.string "あなたは しんかんせんに のって\n"
	.string "ミュートリッドの あくの ほんきょち\l"
	.string "シントウキョウへ むかう。\p"
	.string "あの きかいを とめる ほうほうを みつけて。$"

Dojo_Text_IntroPlan::
	.string "{JPN}この ちほうの すみずみから\n"
	.string "トレーナーが あつまった。\p"
	.string "そして みんな あなたが\n"
	.string "したことの ために ここに いる。\p"
	.string "だれも おりてこない やまから あなたは\n"
	.string "おりてきた。 ベールの むこうへ いき\l"
	.string "もどってきた。\p"
	.string "シントウキョウに のりこんで あの きかいを\n"
	.string "とめられる ものが いるとしたら\l"
	.string "それは あなたよ。$"

Dojo_Text_IntroCost::
	.string "{JPN}{ENG}{PLAYER}{JPN}。 わたしを みて。\p"
	.string "この へやの なかには もどれない\n"
	.string "ひとも いる。\p"
	.string "みんな わかっている。 じぶんで えらんだの。\n"
	.string "だから でんしゃが うごきだしたら\l"
	.string "ふりかえっては だめ。\p"
	.string "まえを むいて。\n"
	.string "そして おわらせるのよ。$"

Dojo_Text_MomGift1::
	.string "{JPN}ママ: たたかいが はじまる まえに\n"
	.string "わたしたい ものが あるの。\p"
	.string "あなたの ベビーベッドの うえに さげていた\n"
	.string "ちいさな すずよ。 あなたが うまれた ひに\l"
	.string "おとうさんが むすびつけたの。\p"
	.string "この ねいろが わるい ゆめを\n"
	.string "よせつけないって いってたわ。$"

Dojo_Text_MomGift2::
	.string "{JPN}ママ: バッグに むすんでおいて。 それか\n"
	.string "しんぱいしょうな ポケモンに。\p"
	.string "そして すずが なるのが きこえたら\n"
	.string "そとの さわがしい やみの\l"
	.string "どこかで…\p"
	.string "それは わたしよ。\n"
	.string "わたしだからね。$"

Dojo_Text_YifferGift1::
	.string "{JPN}あしたは おおしごとだ。 めしは くったか？\p"
	.string "だろうな。 たたかう やつは のこりものと\n"
	.string "いじで うごくもんだ。\p"
	.string "ほら おれのを やる。$"

Dojo_Text_YifferGift2::
	.string "{JPN}たべのこし。 さいこうの\n"
	.string "どうぐだ。 あいぼうが ひとくち ずつ\l"
	.string "ねばりつづける。\p"
	.string "ホームで あおうぜ。$"

Dojo_Text_YifferAfter::
	.string "{JPN}よく かんで もっと ゆっくり いきを しろ。\p"
	.string "ほんとうの めしは いじ だからな。$"

Dojo_Text_MomAfter::
	.string "{JPN}ママ: あなたなら できるわ。$"

Dojo_Text_RedFatalityGift1::
	.string "{JPN}よう {ENG}{PLAYER}{JPN}。\n"
	.string "おぼえてるか？ フロストウッドの。\p"
	.string "おじけづいて おれの ジムに きて\n"
	.string "おれの バッジを もって かえってった\l"
	.string "やつだ。 ジムは いまは こおりついてる。$"

Dojo_Text_RedFatalityGift2::
	.string "{JPN}わざマシン13。 れいとうビーム。\n"
	.string "おれの おはこだ。\p"
	.string "せんべつだ。\n"
	.string "むこうがわで また あおうぜ\n"
	.string "あいぼう。$"

Dojo_Text_RedFatalityAfter::
	.string "{JPN}むこうがわで また あおうぜ ファイター。$"

Dojo_Text_MinisterGift1::
	.string "{JPN}はんらんって いうと みんな ちからだと\n"
	.string "おもう。 ちがう。 かどうじかんだ。\p"
	.string "ミュートリッドは せんろの ぜんぶを ひとつの\n"
	.string "ネットワークで うごかしてる。 カメラ\l"
	.string "ドアの ロック しんごう なにもかもな。\p"
	.string "おれは なんにちも やつらの システムに\n"
	.string "もぐりこんでる。 やつらは まだ おれを\l"
	.string "センネンの じはんきだと おもってるよ。$"

Dojo_Text_MinisterGift2::
	.string "{JPN}それが しんかんせんの カードキーだ。\n"
	.string "やつらの システムかんりしゃから\l"
	.string "コピーした。\p"
	.string "あしたは こう なる:\p"
	.string "ホームに ついた しゅんかん おれが\n"
	.string "ネットワークに しんにゅうする。 カメラは\l"
	.string "ループ。 ドアの ロックは おまえを\l"
	.string "わすれる。 しんごうは あおに かわる\l"
	.string "ひがしの はてまでな。\p"
	.string "カードを とおして のりこめば おまえは\n"
	.string "やつらの せんろの ゆうれいだ。\p"
	.string "しんにゅうは おれの しごと。 でんしゃは\n"
	.string "おまえの しごとだ。$"

Dojo_Text_MinisterAfter::
	.string "{JPN}あした なにもかも まっくらに なる。$"

Dojo_Text_MikmancGift1::
	.string "{JPN}{ENG}{PLAYER}{JPN}！！ おれだよ\n"
	.string "ミクマンク！ ジムで あった！\p"
	.string "わたしたい ものが あるんだ。$"

Dojo_Text_MikmancGift2::
	.string "{JPN}いのちのたま。 すこし けずれるけど\n"
	.string "ずっと つよく なぐれる。\p"
	.string "…そとに でられたら\n"
	.string "もっと つよく なぐれよ {ENG}{PLAYER}{JPN}。\p"
	.string "おれたち みんなの ぶんまで。$"

Dojo_Text_MikmancAfter::
	.string "{JPN}こわくなんか ない。\p"
	.string "いや。 ちょっとだけ こわい。$"
