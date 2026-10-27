VictoryRoad_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_2F_OnLoad
	.byte 0

VictoryRoad_2F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_SetRockBarrier1
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_SetRockBarrier2
	end

VictoryRoad_2F_EventScript_SetRockBarrier1::
	setmetatile 13, 10, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 13, 11, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_SetRockBarrier2::
	setmetatile 33, 16, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 33, 17, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_2F_EventScript_FloorSwitch1::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100, VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed
	setmetatile 13, 10, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 13, 11, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER1
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch1AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100, VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed
	setmetatile 33, 16, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 33, 17, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_2F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2, 100
	releaseall
	end

VictoryRoad_2F_EventScript_FloorSwitch2AlreadyPressed::
	releaseall
	end

VictoryRoad_2F_EventScript_Dawson::
	trainerbattle_single TRAINER_POKEMANIAC_DAWSON, VictoryRoad_2F_Text_DawsonIntro, VictoryRoad_2F_Text_DawsonDefeat
	msgbox VictoryRoad_2F_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Daisuke::
	trainerbattle_single TRAINER_BLACK_BELT_DAISUKE, VictoryRoad_2F_Text_DaisukeIntro, VictoryRoad_2F_Text_DaisukeDefeat
	msgbox VictoryRoad_2F_Text_DaisukePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Nelson::
	trainerbattle_single TRAINER_JUGGLER_NELSON, VictoryRoad_2F_Text_NelsonIntro, VictoryRoad_2F_Text_NelsonDefeat
	msgbox VictoryRoad_2F_Text_NelsonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Gregory::
	trainerbattle_single TRAINER_JUGGLER_GREGORY, VictoryRoad_2F_Text_GregoryIntro, VictoryRoad_2F_Text_GregoryDefeat
	msgbox VictoryRoad_2F_Text_GregoryPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_Vincent::
	trainerbattle_single TRAINER_TAMER_VINCENT, VictoryRoad_2F_Text_VincentIntro, VictoryRoad_2F_Text_VincentDefeat
	msgbox VictoryRoad_2F_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Text_DawsonIntro::
	.string "{JPN}ここを とおりぬけられたら\n"
	.string "してんのうに あいに いけるぞ。$"

VictoryRoad_2F_Text_DawsonDefeat::
	.string "{JPN}うそだ!\n"
	.string "しんじられない!$"

VictoryRoad_2F_Text_DawsonPostBattle::
	.string "{JPN}ポケモンの ちしき なら\n"
	.string "きみには まけないぞ!$"

VictoryRoad_2F_Text_DaisukeIntro::
	.string "{JPN}ここは チャンピオンロード。\n"
	.string "トレーナーの さいごの しれんだ!$"

VictoryRoad_2F_Text_DaisukeDefeat::
	.string "{JPN}あちゃー!$"

VictoryRoad_2F_Text_DaisukePostBattle::
	.string "{JPN}こまったら いわを うごかして\n"
	.string "みると いいよ。$"

VictoryRoad_2F_Text_NelsonIntro::
	.string "{JPN}ほう してんのうに\n"
	.string "ちょうせん したいと?$"

VictoryRoad_2F_Text_NelsonDefeat::
	.string "{JPN}やられた!$"

VictoryRoad_2F_Text_NelsonPostBattle::
	.string "{JPN}{ENG}{RIVAL}{JPN}も ここを とおって いったぞ。$"

VictoryRoad_2F_Text_VincentIntro::
	.string "{JPN}さあ こい!\n"
	.string "こてんぱんに してやる!$"

VictoryRoad_2F_Text_VincentDefeat::
	.string "{JPN}こてんぱんに された!$"

VictoryRoad_2F_Text_VincentPostBattle::
	.string "{JPN}きみは チャンピオンロードに\n"
	.string "いる しかくを えたんだ…$"

VictoryRoad_2F_Text_GregoryIntro::
	.string "{JPN}チャンピオンロードは きびしいかい?$"

VictoryRoad_2F_Text_GregoryDefeat::
	.string "{JPN}おみごと!$"

VictoryRoad_2F_Text_GregoryPostBattle::
	.string "{JPN}おおくの トレーナーが ここで\n"
	.string "ちょうせんを あきらめて かえるんだ。$"

@ Unused, old text for Moltres
VictoryRoad_2F_Text_Gyaoo::
	.string "{JPN}ギヤーオ!$"

