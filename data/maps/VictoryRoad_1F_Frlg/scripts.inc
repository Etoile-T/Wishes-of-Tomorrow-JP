VictoryRoad_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_1F_Frlg_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_Frlg_OnTransition
	.byte 0

VictoryRoad_1F_Frlg_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_1F, 100, VictoryRoad_1F_EventScript_SetRockBarrier
	end

VictoryRoad_1F_EventScript_SetRockBarrier::
	setmetatile 12, 14, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 15, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_1F_Frlg_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VICTORY_ROAD_1F
	end

VictoryRoad_1F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_1F, 100, VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 14, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 15, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_1F_BOULDER
	setvar VAR_MAP_SCENE_VICTORY_ROAD_1F, 100
	releaseall
	end

VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_1F_EventScript_Naomi::
	trainerbattle_single TRAINER_COOLTRAINER_NAOMI, VictoryRoad_1F_Text_NaomiIntro, VictoryRoad_1F_Text_NaomiDefeat
	msgbox VictoryRoad_1F_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Rolando::
	trainerbattle_single TRAINER_COOLTRAINER_ROLANDO, VictoryRoad_1F_Text_RolandoIntro, VictoryRoad_1F_Text_RolandoDefeat
	msgbox VictoryRoad_1F_Text_RolandoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_NaomiIntro::
	.string "{JPN}あなた わたしの あいてに\n"
	.string "ふさわしいかしら?$"

VictoryRoad_1F_Text_NaomiDefeat::
	.string "{JPN}まけちゃった…$"

VictoryRoad_1F_Text_NaomiPostBattle::
	.string "{JPN}だれにも まけたく なかったのに\n"
	.string "ましてや としした なんかに…$"

VictoryRoad_1F_Text_RolandoIntro::
	.string "{JPN}きみが つよいのは わかる。\n"
	.string "どれほど つよいか みせて もらおう!$"

VictoryRoad_1F_Text_RolandoDefeat::
	.string "{JPN}かてる チャンスは あったのに…$"

VictoryRoad_1F_Text_RolandoPostBattle::
	.string "{JPN}ちっ!\n"
	.string "みとめるよ きみの ほうが うえだ!$"

