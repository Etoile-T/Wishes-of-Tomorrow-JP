RocketHideout_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0

RocketHideout_B1F_OnLoad::
	call_if_not_defeated TRAINER_TEAM_ROCKET_GRUNT_12 RocketHideout_B1F_EventScript_SetBarrier
	end

RocketHideout_B1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCKET_HIDEOUT_B1F
	end

RocketHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, RocketHideout_B1F_Text_Grunt1Intro, RocketHideout_B1F_Text_Grunt1Defeat
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, RocketHideout_B1F_Text_Grunt2Intro, RocketHideout_B1F_Text_Grunt2Defeat
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_10, RocketHideout_B1F_Text_Grunt3Intro, RocketHideout_B1F_Text_Grunt3Defeat
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, RocketHideout_B1F_Text_Grunt4Intro, RocketHideout_B1F_Text_Grunt4Defeat
	msgbox RocketHideout_B1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_Text_Grunt5Intro, RocketHideout_B1F_Text_Grunt5Defeat, RocketHideout_B1F_EventScript_DefeatedGrunt5
	msgbox RocketHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_DefeatedGrunt5::
	call RocketHideout_B1F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

RocketHideout_B1F_EventScript_SetBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 21, 19, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 20, 20, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 21, 20, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B1F_EventScript_RemoveBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 19, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 20, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 20, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor, 0
	return

RocketHideout_B1F_Text_Grunt1Intro::
	.string "{JPN}だれだ?\n"
	.string "どうやって ここに はいった?$"

RocketHideout_B1F_Text_Grunt1Defeat::
	.string "{JPN}いてて!\n"
	.string "やられた!$"

RocketHideout_B1F_Text_Grunt1PostBattle::
	.string "{JPN}くそっ… ロケットだんを\n"
	.string "なめてる だろう?$"

RocketHideout_B1F_Text_Grunt2Intro::
	.string "{JPN}ロケットだんの アジトに\n"
	.string "しのびこむ とは? いい どきょうだ!$"

RocketHideout_B1F_Text_Grunt2Defeat::
	.string "{JPN}ドカーン!$"

RocketHideout_B1F_Text_Grunt2PostBattle::
	.string "{JPN}このままで すむと おもうなよ\n"
	.string "ガキめ!$"

RocketHideout_B1F_Text_Grunt3Intro::
	.string "{JPN}しんにゅうしゃ はっけん!$"

RocketHideout_B1F_Text_Grunt3Defeat::
	.string "{JPN}かなわない!$"

RocketHideout_B1F_Text_Grunt3PostBattle::
	.string "{JPN}シルフスコープ? ふん!\n"
	.string "どこに あるかなんて しらないね。$"

RocketHideout_B1F_Text_Grunt4Intro::
	.string "{JPN}なんで ここに きた?$"

RocketHideout_B1F_Text_Grunt4Defeat::
	.string "{JPN}こりゃ だめだ!$"

RocketHideout_B1F_Text_Grunt4PostBattle::
	.string "{JPN}わかった はなすよ…\n"
	.string "エレベーターで ボスの ところへ いけ。$"

RocketHideout_B1F_Text_Grunt5Intro::
	.string "{JPN}まいごかい? ちびネズミちゃん?$"

RocketHideout_B1F_Text_Grunt5Defeat::
	.string "{JPN}なぜ…?$"

RocketHideout_B1F_Text_Grunt5PostBattle::
	.string "{JPN}あれ? いまの さわぎで なぜか\n"
	.string "ドアが ひらいたぞ!$"

