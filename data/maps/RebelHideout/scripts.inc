	.equ LOCALID_HIDEOUT_OPERATIVE, 1
	.equ LOCALID_HIDEOUT_DEFECTOR, 2
	.equ LOCALID_HIDEOUT_SCENE_ONI, 5
	.equ LOCALID_HIDEOUT_SCENE_OPERATIVE, 6
	.equ LOCALID_HIDEOUT_SCENE_ZOROARK, 7
	.equ LOCALID_HIDEOUT_JET, 9

RebelHideout_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RebelHideout_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RebelHideout_OnFrame
	.byte 0

@ ============================================================================
@  ACT 3, STEP 7 -- THE REBEL HIDEOUT (WoT_Act3_Canon.md)
@  The only heal + PC box in Shin-Tokyo (Blissey + Porygon). The Step-6
@  arrest DELIVERS the player here still "in custody": scripts don't survive
@  warps, so the street scene ends at the warp and the ON_FRAME scene below
@  plays the reveal -- THE ONI's outline drops, the operative and her ZOROARK
@  stand revealed -- then the defector's briefing and the main quest.
@  The static operative (object 1) stays hidden until the reveal introduces
@  her (FLAG_HIDE_REBEL_OPERATIVE, managed every transition).
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================

RebelHideout_OnTransition::
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	setflag FLAG_HIDE_ACT3_ARREST_NPCS
	@ Post-game: the whole rebellion gathers here (the jet only once Nessa
	@ has delivered it). Before the clear, all of it stays hidden.
	call_if_unset FLAG_SYS_GAME_CLEAR, RebelHideout_OnTransition_PreClear
	call_if_set FLAG_SYS_GAME_CLEAR, RebelHideout_OnTransition_PostClear
	goto_if_set FLAG_WOT_HIDEOUT_REVEAL_DONE, RebelHideout_OnTransition_ShowOperative
	setflag FLAG_HIDE_REBEL_OPERATIVE
	end
RebelHideout_OnTransition_ShowOperative::
	clearflag FLAG_HIDE_REBEL_OPERATIVE
	end
RebelHideout_OnTransition_PreClear::
	setflag FLAG_WOT_HIDE_POSTGAME_REBELS
	setflag FLAG_WOT_HIDE_POSTGAME_JET
	return
RebelHideout_OnTransition_PostClear::
	clearflag FLAG_WOT_HIDE_POSTGAME_REBELS
	call_if_set FLAG_WOT_POSTGAME_WELCOME_DONE, RebelHideout_OnTransition_ShowJet
	@ The hide flag MUST be set here, not only in the pre-clear branch: flags
	@ default to CLEAR, so a save that was already game-cleared before the jet
	@ existed never ran PreClear and spawned the jet parked on the crate.
	call_if_unset FLAG_WOT_POSTGAME_WELCOME_DONE, RebelHideout_OnTransition_HideJet
	return
RebelHideout_OnTransition_ShowJet::
	clearflag FLAG_WOT_HIDE_POSTGAME_JET
	return
RebelHideout_OnTransition_HideJet::
	setflag FLAG_WOT_HIDE_POSTGAME_JET
	return

RebelHideout_OnFrame:
	map_script_2 VAR_TEMP_1, 0, RebelHideout_EventScript_Reveal
	map_script_2 VAR_TEMP_2, 0, RebelHideout_EventScript_PostgameWelcome
	.2byte 0

@ ============================================================================
@  POST-GAME -- THE MORNING AFTER (plays on the first hideout load after the
@  credits: GameClear continues the save at the hideout cots). Nessa crosses
@  the bar, hands over the SHINY CHARM, and the rebellion's parting gift --
@  a PRIVATE JET -- swoops in and parks over the back wall at (8,3).
@  One-shot via FLAG_WOT_POSTGAME_WELCOME_DONE.
@ ============================================================================
RebelHideout_EventScript_PostgameWelcome::
	lockall
	setvar VAR_TEMP_2, 1
	goto_if_unset FLAG_SYS_GAME_CLEAR, RebelHideout_EventScript_PostgameWelcomeDone
	goto_if_set FLAG_WOT_POSTGAME_WELCOME_DONE, RebelHideout_EventScript_PostgameWelcomeDone
	@ Belt and suspenders: the post-credits continue path must have Nessa at
	@ her post no matter which load path dropped her (addobject is a no-op if
	@ she already spawned).
	clearflag FLAG_HIDE_REBEL_OPERATIVE
	addobject LOCALID_HIDEOUT_OPERATIVE
	delay 30
	applymovement LOCALID_HIDEOUT_OPERATIVE, RebelHideout_Movement_NessaApproach
	waitmovement LOCALID_HIDEOUT_OPERATIVE
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_PostgameCongrats, MSGBOX_DEFAULT
	closemessage
	hideportrait
	giveitem ITEM_SHINY_CHARM
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_PostgameOnTheHouse, MSGBOX_DEFAULT
	closemessage
	hideportrait
	delay 50
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_PostgameAlmostForgot, MSGBOX_DEFAULT
	closemessage
	hideportrait
	@ -- the PJ swoops in from beyond the right edge (x=17 is fully outside
	@ the 15-wide viewport; scripted movement never collision-checks, so the
	@ flight over the wall row is safe) and parks on the green crate --
	applymovement OBJ_EVENT_ID_PLAYER, RebelHideout_Movement_FaceUp
	waitmovement 0
	@ Kill any copy already standing on the crate before repositioning: a
	@ spawned object ignores setobjectxyperm (that only edits the template)
	@ and makes addobject a no-op, which is how it ended up flying FROM the
	@ crate instead of TO it.
	removeobject LOCALID_HIDEOUT_JET
	clearflag FLAG_WOT_HIDE_POSTGAME_JET
	setobjectxyperm LOCALID_HIDEOUT_JET, 17, 3
	addobject LOCALID_HIDEOUT_JET
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_HIDEOUT_JET, RebelHideout_Movement_JetFlyIn
	waitmovement LOCALID_HIDEOUT_JET
	playse SE_TRUCK_UNLOAD
	delay 16
	copyobjectxytoperm LOCALID_HIDEOUT_JET
	applymovement OBJ_EVENT_ID_PLAYER, RebelHideout_Movement_FaceDown
	waitmovement 0
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_PostgameFly, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WOT_POSTGAME_WELCOME_DONE
	applymovement LOCALID_HIDEOUT_OPERATIVE, RebelHideout_Movement_NessaReturn
	waitmovement LOCALID_HIDEOUT_OPERATIVE
RebelHideout_EventScript_PostgameWelcomeDone::
	releaseall
	end

RebelHideout_Movement_NessaApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RebelHideout_Movement_NessaReturn:
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

RebelHideout_Movement_JetFlyIn:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

RebelHideout_Movement_FaceDown:
	face_down
	step_end

RebelHideout_EventScript_Reveal::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_unset FLAG_ACT3_ARREST_DONE, RebelHideout_EventScript_RevealDone
	goto_if_set FLAG_WOT_HIDEOUT_REVEAL_DONE, RebelHideout_EventScript_RevealDone
	applymovement OBJ_EVENT_ID_PLAYER, RebelHideout_Movement_FaceUp
	waitmovement 0
	setobjectxyperm LOCALID_HIDEOUT_SCENE_ONI, 7, 7
	addobject LOCALID_HIDEOUT_SCENE_ONI
	delay 30
	setspeaker SP_NAME_THE_ONI
	msgbox RebelHideout_Text_PreReveal, MSGBOX_DEFAULT
	closemessage
	@ -- the illusion drops: operative + ZOROARK side by side --
	playse SE_M_TELEPORT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_HIDEOUT_SCENE_ONI
	setobjectxyperm LOCALID_HIDEOUT_SCENE_OPERATIVE, 7, 7
	addobject LOCALID_HIDEOUT_SCENE_OPERATIVE
	setobjectxyperm LOCALID_HIDEOUT_SCENE_ZOROARK, 8, 7
	addobject LOCALID_HIDEOUT_SCENE_ZOROARK
	fadescreen FADE_FROM_BLACK
	waitse
	playmoncry SPECIES_ZOROARK, CRY_MODE_NORMAL
	waitmoncry
	msgbox RebelHideout_Text_IllusionDrops, MSGBOX_DEFAULT
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_OperativeReveal, MSGBOX_DEFAULT
	closemessage
	@ -- her own reveal beat: the archipelago chart --
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_NessaMapGift, MSGBOX_DEFAULT
	closemessage
	hideportrait
	playfanfare MUS_OBTAIN_ITEM
	message RebelHideout_Text_ReceivedPostgameMap
	waitmessage
	waitfanfare
	closemessage
	setflag FLAG_WOT_POSTGAME_MAP_GET
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_NessaMapHowTo, MSGBOX_DEFAULT
	closemessage
	hideportrait
	@ -- the defector crosses the room for the briefing --
	applymovement LOCALID_HIDEOUT_DEFECTOR, RebelHideout_Movement_DefectorApproach
	waitmovement LOCALID_HIDEOUT_DEFECTOR
	setspeaker SP_NAME_DEFECTOR
	msgbox RebelHideout_Text_Briefing1, MSGBOX_DEFAULT
	msgbox RebelHideout_Text_Briefing2, MSGBOX_DEFAULT
	msgbox RebelHideout_Text_Briefing3, MSGBOX_DEFAULT
	goto_if_unset FLAG_ACT3_RESEARCH_STOLEN, RebelHideout_EventScript_BriefingMission
	@ Kept-then-stolen path only: the operative knows whose research it was.
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_BriefingStolen, MSGBOX_DEFAULT
RebelHideout_EventScript_BriefingMission::
	setspeaker SP_NAME_DEFECTOR
	msgbox RebelHideout_Text_BriefingMission, MSGBOX_DEFAULT
	closemessage
	startquest QUEST_STOP_THE_MACHINE
	@ -- and the ledger to track the hunt with --
	setspeaker SP_NAME_DEFECTOR
	msgbox RebelHideout_Text_BriefingLogGift, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message RebelHideout_Text_ReceivedShadowLog
	waitmessage
	waitfanfare
	closemessage
	setflag FLAG_WOT_SHADOW_LOG_GET
	applymovement LOCALID_HIDEOUT_DEFECTOR, RebelHideout_Movement_DefectorReturn
	waitmovement LOCALID_HIDEOUT_DEFECTOR
	setflag FLAG_WOT_HIDEOUT_REVEAL_DONE
RebelHideout_EventScript_RevealDone::
	releaseall
	end

RebelHideout_Movement_FaceUp:
	face_up
	step_end

RebelHideout_Movement_DefectorApproach:
	walk_right
	walk_right
	walk_right
	face_right
	step_end

@ Step down first: (2,8) and everything west of it on row 8 is wall, so all
@ three of the old steps were inside it. Row 9 is open from x=0, which is where
@ he was trying to get back to.
RebelHideout_Movement_DefectorReturn:
	walk_down
	walk_left
	walk_left
	walk_left
	face_right
	step_end

RebelHideout_EventScript_Operative::
	lock
	faceplayer
	setspeaker SP_NAME_OPERATIVE
	msgbox RebelHideout_Text_Operative, MSGBOX_DEFAULT
	release
	end

@ Prof. Assistant's line advances with the hunt: purified analysis once the
@ first shrine visit lands, snag analysis once the first Shadow is caught,
@ else the standing briefing line.
RebelHideout_EventScript_Defector::
	lock
	faceplayer
	setspeaker SP_NAME_DEFECTOR
	special WotShadowLogPurifiedCount
	goto_if_ge VAR_RESULT, 1, RebelHideout_EventScript_DefectorPurified
	special WotShadowLogSnaggedCount
	goto_if_ge VAR_RESULT, 1, RebelHideout_EventScript_DefectorAnalysis
	msgbox RebelHideout_Text_Defector, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_DefectorAnalysis::
	msgbox RebelHideout_Text_DefectorAnalysis, MSGBOX_DEFAULT
	release
	end

@ Harness Darkness, part 1: the first purification buys the sky. He works out
@ where CELEBI actually is, and FLY comes with the coordinates.
RebelHideout_EventScript_DefectorPurified::
	goto_if_unset FLAG_WOT_FLY_GRANTED, RebelHideout_EventScript_DefectorGrantFly
	goto_if_set FLAG_WOT_HARNESS_PART2_DONE, RebelHideout_EventScript_DefectorAllDone
	special WotShadowLogPurifiedCount
	goto_if_ge VAR_RESULT, 5, RebelHideout_EventScript_DefectorPartTwoReward
	msgbox RebelHideout_Text_DefectorPurified, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_DefectorGrantFly::
	msgbox RebelHideout_Text_DefectorPurified, MSGBOX_DEFAULT
	closemessage
	hideportrait
	msgbox RebelHideout_Text_DefectorTriangulated, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message RebelHideout_Text_ReceivedFly
	waitmessage
	waitfanfare
	closemessage
	setflag FLAG_WOT_FLY_GRANTED
	questtoast QUEST_TOAST_UPDATE, SIDE_QUEST_HARNESS_DARKNESS
	setspeaker SP_NAME_DEFECTOR
	msgbox RebelHideout_Text_DefectorAssignFive, MSGBOX_DEFAULT
	release
	end

@ Harness Darkness, part 2: five PURIFIED, reported back. The reward is a GOLD
@ BOTTLE CAP -- what the shrine left behind in the machine room.
RebelHideout_EventScript_DefectorPartTwoReward::
	msgbox RebelHideout_Text_DefectorFiveDone, MSGBOX_DEFAULT
	closemessage
	hideportrait
	@ giveitem prints its own "obtained"/"no room" message and leaves the
	@ outcome in VAR_0x8007 (VAR_RESULT is clobbered by the calls it makes).
	giveitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_0x8007, FALSE, RebelHideout_EventScript_DefectorNoRoom
	setflag FLAG_WOT_HARNESS_PART2_DONE
	completequest SIDE_QUEST_HARNESS_DARKNESS
	questtoast QUEST_TOAST_COMPLETE, SIDE_QUEST_HARNESS_DARKNESS
	setspeaker SP_NAME_DEFECTOR
	msgbox RebelHideout_Text_DefectorAfterFive, MSGBOX_DEFAULT
	release
	end

@ Bag full. The quest is deliberately NOT completed here, so coming back once
@ there is room still hands the cap over.
RebelHideout_EventScript_DefectorNoRoom::
	setspeaker SP_NAME_DEFECTOR
	msgbox RebelHideout_Text_DefectorCapNoRoom, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_DefectorAllDone::
	msgbox RebelHideout_Text_DefectorAfterFive, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_Zoroark::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZOROARK, CRY_MODE_NORMAL
	waitmoncry
	msgbox RebelHideout_Text_Zoroark, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_Blissey::
	lock
	faceplayer
	msgbox RebelHideout_Text_BlisseyOffer, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	msgbox RebelHideout_Text_BlisseyDone, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_Porygon::
	lock
	faceplayer
	playse SE_PC_ON
	msgbox RebelHideout_Text_Porygon, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	special ShowPokemonStorageSystemPC
	release
	end

RebelHideout_EventScript_ExitDoor::
	lockall
	closemessage
	fadescreen FADE_TO_BLACK
	warp MAP_SHIN_TOKYO, 16, 15
	waitstate
	releaseall
	end

@ --- post-game: the gathered rebellion --------------------------------------
RebelHideout_EventScript_PrivateJet::
	lockall
	msgbox RebelHideout_Text_PrivateJet, MSGBOX_SIGN
	releaseall
	end

RebelHideout_EventScript_PostgameFatality::
	lock
	faceplayer
	setspeaker SP_NAME_RED_FATALITY
	msgbox RebelHideout_Text_PostgameFatality, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameYiffer::
	lock
	faceplayer
	setspeaker SP_NAME_YIFFER
	msgbox RebelHideout_Text_PostgameYiffer, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameMasterGen::
	lock
	faceplayer
	setspeaker SP_NAME_MASTER_GEN
	msgbox RebelHideout_Text_PostgameMasterGen, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameMom::
	lock
	faceplayer
	setspeaker SP_NAME_MOM
	msgbox RebelHideout_Text_PostgameMom, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameMikmanc::
	lock
	faceplayer
	setspeaker SP_NAME_MIKMANC
	msgbox RebelHideout_Text_PostgameMikmanc, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameMinister::
	lock
	faceplayer
	setspeaker SP_NAME_MINISTER
	msgbox RebelHideout_Text_PostgameMinister, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameClarkson::
	lock
	faceplayer
	setspeaker SP_NAME_CLARKSON
	msgbox RebelHideout_Text_PostgameClarkson, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameEdwards::
	lock
	faceplayer
	setspeaker SP_NAME_EDWARDS
	msgbox RebelHideout_Text_PostgameEdwards, MSGBOX_DEFAULT
	release
	end

RebelHideout_EventScript_PostgameAllison::
	lock
	faceplayer
	setspeaker SP_NAME_ALLISON
	msgbox RebelHideout_Text_PostgameAllison, MSGBOX_DEFAULT
	release
	end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
RebelHideout_Text_PreReveal::
	.string "{JPN}ふるい まちの ほねぐみを くぐって\n"
	.string "おりてきたのが ここ。\p"
	.string "どの カメラにも うつらない。$"

RebelHideout_Text_IllusionDrops::
	.string "{JPN}オニの りんかくが ゆらめき\n"
	.string "あまみずのように ながれおちた。\p"
	.string "フードを かぶった おんな。 その わきで\n"
	.string "ゾロアークが にやりと わらっている。$"

RebelHideout_Text_OperativeReveal::
	.string "{JPN}ケケケ。 てじょうの しばいは\n"
	.string "わるかったね。\p"
	.string "ようこそ レジスタンスへ。\n"
	.string "だつごくしゃさん。\p"
	.string "あんたに あいたいって ひとたちが\n"
	.string "いるんだ。$"

RebelHideout_Text_Briefing1::
	.string "{JPN}どの がめんにも うつる あの おとこは\n"
	.string "じぶんを オニと よんでいる。\p"
	.string "3ねん あいつの くすりを つくっていた。\n"
	.string "うえに なにが あるか しっている。\p"
	.string "あいつが つくったのは\n"
	.string "たましいを くらう きかいだ。$"

RebelHideout_Text_Briefing2::
	.string "{JPN}あいつには しぬことのない\n"
	.string "エネルギーげんが ひつようだった。\p"
	.string "それで ジラーチを… ねがいを かなえる\n"
	.string "この ちほうで うまれた なかで\l"
	.string "もっとも やさしい いきものを\l"
	.string "そらから ひきずりおろした。\p"
	.string "そして めざめたままの ジラーチを\n"
	.string "タワーの かくしんぶに ようせつした。$"

RebelHideout_Text_Briefing3::
	.string "{JPN}うばわれた ねがいが\n"
	.string "ダークそうちを うごかしている。\p"
	.string "この まちの ダークポケモンは すべて\n"
	.string "あの きかいに とおされた。\l"
	.string "いきた たましいを とじこめられ\l"
	.string "いまも さけびつづけている。\p"
	.string "それが そとに みえる あかりを\n"
	.string "ともしているんだ。$"

RebelHideout_Text_BriefingStolen::
	.string "{JPN}「しかも じたいは あっかした。\p"
	.string "「だれかが クラークソンの けんきゅうを\n"
	.string "やつらに うばわせた。\p"
	.string "「やつらは かそくしている。\n"
	.string "いままで かこうに ていこうした しゅも\l"
	.string "もう ていこうできない。\p"
	.string "「あたらしい ダークポケモンは…\n"
	.string "つよい。」$"

RebelHideout_Text_BriefingMission::
	.string "{JPN}こんやは しおが ひく。\p"
	.string "シントウキョウから みなみへ なみのりしろ。\n"
	.string "ようせいたちが まもる しまを さがせ。\l"
	.string "あいつが ゆがめたものを リライブする\l"
	.string "すべを まなぶんだ。\p"
	.string "それから タワーを のぼれ…\p"
	.string "…そして あの きかいの しんぞうを\n"
	.string "ひきずりだせ。$"

RebelHideout_Text_Operative::
	.string "{JPN}あたしを 2ど おえる やつは いないよ。\p"
	.string "やすみな。 つれていけない こは ボックスへ。\n"
	.string "ここは この まちに のこる\l"
	.string "さいごの あんぜんな へやだ。\p"
	.string "こんやは しおが ひく。\n"
	.string "みなみの うみは あんたの ものさ。$"

RebelHideout_Text_Defector::
	.string "{JPN}スナッチしろ。 リライブするんだ。\p"
	.string "ダークポケモンを 1ぴき とりもどせば\n"
	.string "あいつに やかれる たましいが 1つ へる。$"

RebelHideout_Text_DefectorAnalysis::
	.string "{JPN}きみが やすむ あいだに ダークポケモンを\n"
	.string "ぶんせきさせて もらった。\p"
	.string "あたえる ダメージが 20パーセント ふえ…\n"
	.string "ぼうぎょは 20パーセント さがる。\p"
	.string "そして すうちに できない きけんが ある。\n"
	.string "ハイパーモードだ。\p"
	.string "むりを させすぎると たたかいの なかで\n"
	.string "きもちが ふあんていに なる。\p"
	.string "やさしく あつかってくれ。 かつては\n"
	.string "だれかの パートナーだったんだ。$"

RebelHideout_Text_DefectorPurified::
	.string "{JPN}きみが リライブした ポケモンの すうちは\n"
	.string "3かい けいさんしなおした。\p"
	.string "こうげきの 20パーセントの じょうしょうは\n"
	.string "そのまま。 ぼうぎょは さがらず\l"
	.string "ハイパーモードも ふくさようも ない。\p"
	.string "すばらしい!$"

RebelHideout_Text_DefectorTriangulated::
	.string "{JPN}そして そくていで もう 1つ\n"
	.string "わかったことが ある。\p"
	.string "あの ポケモンを リライブした なにかが\n"
	.string "くうきに とくゆうの あとを のこした。\p"
	.string "さんかくそくりょうで つきとめた。\n"
	.string "セレビィの ばしょが わかったんだ。\p"
	.string "だが この ざひょうは あるいていく ものには\n"
	.string "なんの やくにも たたない。$"

RebelHideout_Text_ReceivedFly::
	.string "{JPN}{ENG}{PLAYER}{JPN}は たたかいの そとでも\n"
	.string "そらをとぶを つかえるように なった!$"

RebelHideout_Text_DefectorAssignFive::
	.string "{JPN}もう そらは きみの ものだ。 かつようしろ。\p"
	.string "ダークポケモンを 5ひき スナッチして\n"
	.string "そくていデータを もってきてくれ。\p"
	.string "あいつから 1ぴき とりもどすたび\n"
	.string "やかれる たましいが 1つ へるんだ。$"

RebelHideout_Text_DefectorFiveDone::
	.string "{JPN}5つの たましいが とりもどされた。\p"
	.string "きみが はたらいている あいだに\n"
	.string "あることが おきた。\p"
	.string "ほこらの すうちが はねあがるたびに\n"
	.string "したの きかいしつに ある きんぞくが\l"
	.string "すこしずつ あかるく\l"
	.string "かがやいていった。\p"
	.string "そこから これが できたんだ。\p"
	.string "ポケモンの なかに あるものを\n"
	.string "よみとれる ひとを さがせ。$"

RebelHideout_Text_DefectorCapNoRoom::
	.string "{JPN}バッグが いっぱいだ。\p"
	.string "あきを つくれ。 こんなものを\n"
	.string "もちあるく つもりは ない。$"

RebelHideout_Text_DefectorAfterFive::
	.string "{JPN}すうちは すべて きみに たくした。\p"
	.string "いって あの きかいを とめてくれ。$"

RebelHideout_Text_NessaMapGift::
	.string "{JPN}かがくの はなしを はじめるまえに\n"
	.string "もう 1つ。$"

RebelHideout_Text_ReceivedPostgameMap::
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "ぐんとうの かいずを うけとった!$"

RebelHideout_Text_NessaMapHowTo::
	.string "{JPN}ちほうマップを ひらいて Rを おせば\n"
	.string "きりかえられるよ。\p"
	.string "うみの むこうは ぜんぶ\n"
	.string "2まいめに のってる。$"

RebelHideout_Text_BriefingLogGift::
	.string "{JPN}もう 1つ。 あいつが つくった\n"
	.string "ダークポケモンを すべて きろくした。\p"
	.string "もっていけ。 やつらを さがしだせ。$"

RebelHideout_Text_ReceivedShadowLog::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ダークにっしを\n"
	.string "はかせの じょしゅから うけとった!$"

RebelHideout_Text_Zoroark::
	.string "{JPN}ゾロアークは にやにやしたままだ。\p"
	.string "てじょうの しばいを たのしんでいた\n"
	.string "ような きがする。$"

RebelHideout_Text_BlisseyOffer::
	.string "{JPN}ハピナスは シントウキョウで ゆいいつの\n"
	.string "あたたかな ひかりを はなっている。$"

RebelHideout_Text_BlisseyDone::
	.string "{JPN}ポケモンたちは すっかり げんきに なった!$"

RebelHideout_Text_Porygon::
	.string "{JPN}ポリゴンは ぬすんだ かいせんで\n"
	.string "ボックスの ネットワークに つないでいる。$"

@ --- post-game text ----------------------------------------------------------
RebelHideout_Text_PostgameCongrats::
	.string "{JPN}ほんとうに やりとげたんだね。\p"
	.string "せかいを すくっちまったんだ。\n"
	.string "だつごくしゃさん。$"

RebelHideout_Text_PostgameOnTheHouse::
	.string "{JPN}あたしの おごりさ。\n"
	.string "これで いいもんでも かいな。$"

RebelHideout_Text_PostgameAlmostForgot::
	.string "{JPN}わすれる とこだった…\p"
	.string "みんなで かねを だしあって\n"
	.string "プライベートジェットを かったんだ!$"

RebelHideout_Text_PostgameFly::
	.string "{JPN}そらをとぶを つかえば ジェットで\n"
	.string "この ちほうの いきたい ところへ\l"
	.string "どこへでも いけるよ。\p"
	.string "さあ どこに する?\p"
	.string "スターサミット? しぜんこうえん?\n"
	.string "ムネン?$"

RebelHideout_Text_PrivateJet::
	.string "{JPN}じぶんの プライベートジェットだ。\p"
	.string "ねんりょうも みがきあげも ばっちり。\n"
	.string "いきたい ばしょへ むかえる。$"

RebelHideout_Text_PostgameFatality::
	.string "{JPN}こんやは ちかの みんなが\n"
	.string "おまえの なを よんでるぜ。\p"
	.string "さいせんは いつでも うけるぞ。 おうじゃ。$"

RebelHideout_Text_PostgameYiffer::
	.string "{JPN}へっ。 ミュートリッドの ふいうち ていどで\n"
	.string "おれが くたばるもんか。\p"
	.string "…ぎりぎりだったがな。$"

RebelHideout_Text_PostgameMasterGen::
	.string "{JPN}つよさとは ひとの ために ある。\n"
	.string "それが どうじょうの おしえじゃ。\p"
	.string "おぬしこそ その あかしじゃ。 だつごくしゃ。$"

RebelHideout_Text_PostgameMom::
	.string "{JPN}{ENG}{PLAYER}{JPN}! せかいを すくったのね!\p"
	.string "ジェットに おやつを つんでおいたわ。\n"
	.string "はやく かえってきてね?$"

RebelHideout_Text_PostgameMikmanc::
	.string "{JPN}ろうやから そらへ。 あいぼう。\p"
	.string "もう だれにも この まちを\n"
	.string "かべで かこませない。$"

RebelHideout_Text_PostgameMinister::
	.string "{JPN}せんきょを ひらく。\n"
	.string "こんどこそ ほんものの せんきょだ。\p"
	.string "だれかが きみの なまえを かきそうな\n"
	.string "そんな きが するよ。$"

RebelHideout_Text_PostgameClarkson::
	.string "{JPN}ジラーチの すうちは あんていしておる。\p"
	.string "おまえが すくった ダークポケモンは\n"
	.string "また じぶんを とりもどしておる。\l"
	.string "1ぴき のこらずな。\p"
	.string "みごとな はたらきじゃ。$"

RebelHideout_Text_PostgameEdwards::
	.string "{JPN}きさまを たおすため そらから\n"
	.string "まいおりた。 2どもな。\p"
	.string "なのに きさまは きかいを こわした。\p"
	.string "…しょうぐんとして けいいを はらおう。$"

RebelHideout_Text_PostgameAllison::
	.string "{JPN}いまは わんの うたも ちがう。\n"
	.string "もっと すんで かろやかに。\p"
	.string "あなたが そうしたのよ。$"

@ Back door to Hotel Z (coord trigger (9,0), placeholder: paint a door there
@ in porymap). Open once the Mega Doomsday intro has played; Hotel Z sends
@ the player back here on the way out (WotHotelZ_SetExit).
RebelHideout_EventScript_HotelZDoor::
	lockall
	goto_if_unset FLAG_WOT_MEGA_DOOMSDAY_INTRO, RebelHideout_EventScript_HotelZDoorLocked
	playse SE_EXIT
	warp MAP_HOTEL_Z, 0
	waitstate
	releaseall
	end

RebelHideout_EventScript_HotelZDoorLocked::
	msgbox RebelHideout_Text_HotelZDoorLocked, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RebelHideout_Movement_HotelZDoorBack
	waitmovement 0
	releaseall
	end

RebelHideout_Movement_HotelZDoorBack:
	walk_down
	step_end

RebelHideout_Text_HotelZDoorLocked:
	.string "{JPN}(ホテルZの うらぐち。 この エリアは\n"
	.string "メガじげんDLCの いちぶです。)$"
