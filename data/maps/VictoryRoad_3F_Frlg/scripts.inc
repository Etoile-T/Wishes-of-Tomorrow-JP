VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
	.string "{JPN}ゆうかんに たたかいながら\n"
	.string "チャンピオンロードを\l"
	.string "ぬけてきた きみは りっぱだ。\p"
	.string "その こうせきを たたえて\n"
	.string "すてみタックルを おしえよう。\p"
	.string "この わざを おしえて\n"
	.string "ほしいかね?$"

Text_DoubleEdgeDeclined::
	.string "{JPN}わざは いつでも\n"
	.string "おしえて あげよう。$"

Text_DoubleEdgeWhichMon::
	.string "{JPN}どの ポケモンに すてみタックルを\n"
	.string "おしえる?$"

Text_DoubleEdgeTaught::
	.string "{JPN}その いきおいで ポケモンリーグも\n"
	.string "がんばるんだ!\p"
	.string "いきおい よく ぶつかって\n"
	.string "たおして こい!$"

VictoryRoad_3F_Text_GeorgeIntro::
	.string "{JPN}てんさいの うわさを きいたよ。$"

VictoryRoad_3F_Text_GeorgeDefeat::
	.string "{JPN}うわさは ほんとう だった!$"

VictoryRoad_3F_Text_GeorgePostBattle::
	.string "{JPN}ロケットだんの サカキを たおしたのは\n"
	.string "きみ だったのか?$"

VictoryRoad_3F_Text_AlexaIntro::
	.string "{JPN}トレーナーは より つよい あいてを\n"
	.string "もとめて いきるの。$"

VictoryRoad_3F_Text_AlexaDefeat::
	.string "{JPN}あっ!\n"
	.string "つよい!$"

VictoryRoad_3F_Text_AlexaPostBattle::
	.string "{JPN}きびしい たたかいを すれば\n"
	.string "つよく なれるのよ。$"

VictoryRoad_3F_Text_CarolineIntro::
	.string "{JPN}あなたの じつりょくを おしえて\n"
	.string "あげる。 なーんてね!$"

VictoryRoad_3F_Text_CarolineDefeat::
	.string "{JPN}あったまに きた!$"

VictoryRoad_3F_Text_CarolinePostBattle::
	.string "{JPN}わたしの じつりょくを おしえられた\n"
	.string "わね…$"

VictoryRoad_3F_Text_ColbyIntro::
	.string "{JPN}えらばれた ものしか ここは とおれん!$"

VictoryRoad_3F_Text_ColbyDefeat::
	.string "{JPN}しんじられん!$"

VictoryRoad_3F_Text_ColbyPostBattle::
	.string "{JPN}ここに いる トレーナーは みんな\n"
	.string "ポケモンリーグを めざしている。\p"
	.string "ゆだん するなよ。$"

VictoryRoad_3F_Text_RayIntro::
	.string "{JPN}レイ: ぼくたち ふたりは\n"
	.string "いだいに なる うんめいなのさ!$"

VictoryRoad_3F_Text_RayDefeat::
	.string "{JPN}レイ: ばかな!\n"
	.string "こんな はずは!$"

VictoryRoad_3F_Text_RayPostBattle::
	.string "{JPN}レイ: ぼくたちの まけだ。\n"
	.string "いだいさは まだ とおい…$"

VictoryRoad_3F_Text_RayNotEnoughMons::
	.string "{JPN}レイ: ぼくたち ふたりは\n"
	.string "ちょうてんを めざしてるんだ。\p"
	.string "ポケモンを 2ひき だして\n"
	.string "たたかって もらわないと。$"

VictoryRoad_3F_Text_TyraIntro::
	.string "{JPN}タイラ: わたしたち ふたりで\n"
	.string "チャンピオンを めざしてるの。$"

VictoryRoad_3F_Text_TyraDefeat::
	.string "{JPN}タイラ: そんな…$"

VictoryRoad_3F_Text_TyraPostBattle::
	.string "{JPN}タイラ: つよさの かたちは かぎりなく\n"
	.string "ある ことを おしえて もらったわ。$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
	.string "{JPN}タイラ: ポケモンが 1ぴきだけでは\n"
	.string "わたしたちとは たたかえないわ。$"

