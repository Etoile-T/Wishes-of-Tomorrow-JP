.equ NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1

RocketHideout_B4F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
	.byte 0

RocketHideout_B4F_OnLoad::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_ne NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_SetBarrier
	end

RocketHideout_B4F_EventScript_CountGruntDefeated::
	addvar NUM_DOOR_GRUNTS_DEFEATED, 1
	return

RocketHideout_B4F_EventScript_Giovanni::
	lock
	faceplayer
	famechecker FAMECHECKER_GIOVANNI, 0
	message RocketHideout_B4F_Text_GiovanniIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
	msgbox RocketHideout_B4F_Text_GiovanniPostBattle
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject LOCALID_HIDEOUT_GIOVANNI
	addobject LOCALID_SILPH_SCOPE
	clearflag FLAG_HIDE_SILPH_SCOPE
	setflag FLAG_HIDE_CELADON_ROCKETS
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	fadescreen FADE_FROM_BLACK
	release
	end

RocketHideout_B4F_EventScript_SilphScope::
	lock
	faceplayer
	removeobject LOCALID_SILPH_SCOPE
	giveitem ITEM_SILPH_SCOPE
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_18, RocketHideout_B4F_Text_Grunt1Intro, RocketHideout_B4F_Text_Grunt1Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt1
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	release
	end

RocketHideout_B4F_EventScript_DefeatedGrunt1::
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	addobject LOCALID_LIFT_KEY
	clearflag FLAG_HIDE_LIFT_KEY
	release
	end

RocketHideout_B4F_EventScript_LiftKey::
	lock
	faceplayer
	setflag FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT
	removeobject LOCALID_LIFT_KEY
	giveitem ITEM_LIFT_KEY
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_Text_Grunt2Intro, RocketHideout_B4F_Text_Grunt2Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt2
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt2::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_RemoveBarrier
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_Text_Grunt3Intro, RocketHideout_B4F_Text_Grunt3Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt3::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_RemoveBarrier
	call_if_eq NUM_DOOR_GRUNTS_DEFEATED, 2, RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval::
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

RocketHideout_B4F_EventScript_SetBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 18, 12, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 17, 13, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 18, 13, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B4F_EventScript_RemoveBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 12, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 13, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 13, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor, 0
	return

RocketHideout_B4F_Text_GiovanniIntro::
	.string "{JPN}ほう! ここまで くるとは\n"
	.string "たいした ものだ\p"
	.string "ロケットだんは せかいじゅうの\n"
	.string "ポケモンを つかまえている\p"
	.string "ポケモンは われらの はんざいを\n"
	.string "ささえる だいじな どうぐなのだ\p"
	.string "わたしが リーダーの サカキだ!\p"
	.string "なまいきな おまえには\n"
	.string "いたい めに あって もらおう!$"

RocketHideout_B4F_Text_GiovanniDefeat::
	.string "{JPN}なんだと!\n"
	.string "そんな ばかな!$"

RocketHideout_B4F_Text_GiovanniPostBattle::
	.string "{JPN}おまえは ポケモンを\n"
	.string "たいせつに そだてているようだ\p"
	.string "おまえのような こどもに わたしの\n"
	.string "のぞみは わかるまい\p"
	.string "こんかいは ひいて やろう!\p"
	.string "また あいたい ものだな…$"

RocketHideout_B4F_Text_Grunt2Intro::
	.string "{JPN}おまえ しってるぞ!\n"
	.string "おつきみやまで じゃまを したな!$"

RocketHideout_B4F_Text_Grunt2Defeat::
	.string "{JPN}また やられた!$"

RocketHideout_B4F_Text_Grunt2PostBattle::
	.string "{JPN}ロケットだんに なにか\n"
	.string "うらみでも あるのか?$"

RocketHideout_B4F_Text_Grunt3Intro::
	.string "{JPN}われらの あくの うつくしさが\n"
	.string "なぜ わからない?$"

RocketHideout_B4F_Text_Grunt3Defeat::
	.string "{JPN}あややっ!$"

RocketHideout_B4F_Text_Grunt3PostBattle::
	.string "{JPN}ボス!\n"
	.string "しっぱいして すみません!$"

RocketHideout_B4F_Text_Grunt1Intro::
	.string "{JPN}エレベーターが うごかない?\n"
	.string "エレベータのカギは だれが もってる?$"

RocketHideout_B4F_Text_Grunt1Defeat::
	.string "{JPN}うわっ!$"

RocketHideout_B4F_Text_Grunt1PostBattle::
	.string "{JPN}しまった!\n"
	.string "エレベータのカギを おとしちまった!$"

