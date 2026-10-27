.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, Common_EventScript_NopReturn
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_LtSurge::
	famechecker FAMECHECKER_LTSURGE, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_LT_SURGE, VermilionCity_Gym_Text_LtSurgeIntro, VermilionCity_Gym_Text_LtSurgeDefeat, VermilionCity_Gym_EventScript_DefeatedLtSurge, NO_MUSIC
	goto_if_unset FLAG_GOT_TM34_FROM_SURGE, VermilionCity_Gym_EventScript_GiveTM34
	msgbox VermilionCity_Gym_Text_LtSurgePostBattle
	release
	end

VermilionCity_Gym_EventScript_DefeatedLtSurge::
	famechecker FAMECHECKER_LTSURGE, 1
	call_if_unset FLAG_GOT_HM05, VermilionCity_Gym_EventScript_ShowOaksAide
	clearflag FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL
	setflag FLAG_DEFEATED_LT_SURGE
	setflag FLAG_BADGE03_GET
	set_gym_trainers_frlg 3
	goto VermilionCity_Gym_EventScript_GiveTM34
	end

VermilionCity_Gym_EventScript_ShowOaksAide::
	clearflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_Gym_EventScript_GiveTM34::
	msgbox VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis
	checkitemspace ITEM_TM34
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM34
	giveitem_msg VermilionCity_Gym_Text_ReceivedTM34FromLtSurge, ITEM_TM34
	setflag FLAG_GOT_TM34_FROM_SURGE
	msgbox VermilionCity_Gym_Text_ExplainTM34
	release
	end

VermilionCity_Gym_EventScript_NoRoomForTM34::
	msgbox VermilionCity_Gym_Text_MakeRoomInYourBag
	release
	end

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	famechecker FAMECHECKER_LTSURGE, 4
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat, VermilionCity_Gym_EventScript_DefeatedTucker
	famechecker FAMECHECKER_LTSURGE, 3
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_DefeatedTucker::
	famechecker FAMECHECKER_LTSURGE, 2
	release
	end

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LT_SURGE, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_Text_LtSurgeIntro::
	.string "{JPN}ヘイ ボーイ! ここに なにしに\n"
	.string "きたんだ?\p"
	.string "せんじょう なら すぐ やられるぜ!\n"
	.string "そんな ちっぽけな パワーじゃな!\p"
	.string "いいか ボーイ! でんきポケモンは\n"
	.string "せんそうで ミーを すくって くれた!\p"
	.string "てきを ビリビリと\n"
	.string "まひ させたのさ!\p"
	.string "ユーも おなじ めに あわせてやる!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

VermilionCity_Gym_Text_LtSurgePostBattle::
	.string "{JPN}ボーイに ひとつ アドバイスだ!\p"
	.string "でんきは たしかに パワフルだ!\p"
	.string "だが じめんタイプの\n"
	.string "ポケモンには きかないぜ!$"

VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis::
	.string "{JPN}オレンジバッジは ポケモンの\n"
	.string "すばやさを あげるのさ!\p"
	.string "それに ポケモンが いつでも\n"
	.string "イナズマの ように そらを とべるぜ!\p"
	.string "ユーは とくべつだ ボーイ!\n"
	.string "こいつを やるぜ!$"

VermilionCity_Gym_Text_ReceivedTM34FromLtSurge::
	.string "{JPN}{ENG}{PLAYER}{JPN}は マチスから\n"
	.string "わざマシン34を もらった!$"

VermilionCity_Gym_Text_ExplainTM34::
	.string "{JPN}わざマシン34は でんげきはだ!\p"
	.string "でんきポケモンに おしえてやれ!$"

VermilionCity_Gym_Text_MakeRoomInYourBag::
	.string "{JPN}ヘイ ボーイ バッグを あけておけ!$"

VermilionCity_Gym_Text_LtSurgeDefeat::
	.string "{JPN}こいつは ショッキングだぜ!\p"
	.string "ユーは ほんものだ ボーイ!\p"
	.string "いいだろう オレンジバッジを やるぜ!$"

VermilionCity_Gym_Text_TuckerIntro::
	.string "{JPN}ぐんたいに いた ころ マチスは\n"
	.string "きびしい じょうかん だった。\p"
	.string "しごきの きつい ひと だったよ。$"

VermilionCity_Gym_Text_TuckerDefeat::
	.string "{JPN}まいった!\n"
	.string "きみ つよいな!$"

VermilionCity_Gym_Text_TuckerPostBattle::
	.string "{JPN}あの とびらを あけるのは たいへんだぞ。\p"
	.string "マチスは ぐんたいでも\n"
	.string "しんちょうな ことで ゆうめいだった。$"

VermilionCity_Gym_Text_BailyIntro::
	.string "{JPN}おれは けいりょうきゅう だけど\n"
	.string "でんきは とくい なんだ!\p"
	.string "だから この ジムに はいったのさ!$"

VermilionCity_Gym_Text_BailyDefeat::
	.string "{JPN}こげた!$"

VermilionCity_Gym_Text_BailyPostBattle::
	.string "{JPN}わかった はなすよ!\p"
	.string "マチスは とびらの スイッチを\n"
	.string "なにかの なかに かくしたって。$"

VermilionCity_Gym_Text_DwayneIntro::
	.string "{JPN}ここは こどもの くる ところじゃない!\n"
	.string "たとえ つよくてもな!$"

VermilionCity_Gym_Text_DwayneDefeat::
	.string "{JPN}うわっ!\n"
	.string "おどろいた!$"

VermilionCity_Gym_Text_DwaynePostBattle::
	.string "{JPN}ジムの しかけは マチスが\n"
	.string "じぶんで つくったんだ。\p"
	.string "どこも にじゅうロックに なってる。\n"
	.string "ヒントを やろう。\p"
	.string "1つめの ロックを あけたら\n"
	.string "2つめの ロックは すぐ となりだ。$"

VermilionCity_Gym_Text_GymGuyAdvice::
	.string "{JPN}オーッス!\n"
	.string "みらいの チャンピオン!\p"
	.string "マチスには あだなが あってな。\p"
	.string "みんなから イナズマ アメリカンと\n"
	.string "よばれてるんだ!\p"
	.string "でんきポケモンの\n"
	.string "エキスパートだぞ。\p"
	.string "とりや みずタイプの ポケモンは\n"
	.string "でんきタイプに よわいんだ。\p"
	.string "まひにも きを つけろよ。\p"
	.string "マチスは とても しんちょうだ。\p"
	.string "とじこもってるから かんたんには\n"
	.string "たどりつけないぞ。$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "{JPN}ふう!\n"
	.string "しびれる しあい だったな!$"

VermilionCity_Gym_Text_GymStatue::
	.string "{JPN}クチバ ポケモンジム\n"
	.string "リーダー マチス\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}$"

VermilionCity_Gym_Text_GymStatuePlayerWon::
	.string "{JPN}クチバ ポケモンジム\n"
	.string "リーダー マチス\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN} {ENG}{PLAYER}{JPN}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
	.string "{JPN}ざんねん!\n"
	.string "ゴミしか はいってない。$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
	.string "{JPN}おや! ゴミの したに スイッチが\n"
	.string "ある! おしてみよう!\p"
	.string "1つめの でんきロックが はずれた!$"

VermilionCity_Gym_Text_SecondLockOpened::
	.string "{JPN}2つめの でんきロックが はずれた!\n"
	.string "じどうドアが ひらいた!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
	.string "{JPN}ざんねん!\n"
	.string "ゴミしか はいってない。\p"
	.string "あっ!\n"
	.string "でんきロックが リセット された!$"

