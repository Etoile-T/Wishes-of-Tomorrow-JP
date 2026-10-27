SilphCo_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
	.string "{JPN}たすけて!\n"
	.string "わたしは シルフの しゃいんです。$"

SilphCo_2F_Text_ConnorDefeat::
	.string "{JPN}どうして ロケットだんだって\n"
	.string "わかったんだ?$"

SilphCo_2F_Text_ConnorPostBattle::
	.string "{JPN}わたしは シルフと ロケットだん\n"
	.string "りょうほうで はたらいてるんだ。$"

SilphCo_2F_Text_JerryIntro::
	.string "{JPN}ここは たちいり きんしだ!\n"
	.string "かえれ!$"

SilphCo_2F_Text_JerryDefeat::
	.string "{JPN}やるな。$"

SilphCo_2F_Text_JerryPostBattle::
	.string "{JPN}ここの めいろが とけるかな?\n"
	.string "かんたんじゃ ないぞ!$"

SilphCo_2F_Text_Grunt1Intro::
	.string "{JPN}こどもは たちいり きんしだ!$"

SilphCo_2F_Text_Grunt1Defeat::
	.string "{JPN}つよい!$"

SilphCo_2F_Text_Grunt1PostBattle::
	.string "{JPN}ひしがたの ゆかは ワープ\n"
	.string "ブロックだ。\p"
	.string "この ハイテクビルの\n"
	.string "いどう そうちなのさ。$"

SilphCo_2F_Text_Grunt2Intro::
	.string "{JPN}おい ガキ!\n"
	.string "こんな ところで なに うろついてる?$"

SilphCo_2F_Text_Grunt2Defeat::
	.string "{JPN}しくじった!$"

SilphCo_2F_Text_Grunt2PostBattle::
	.string "{JPN}シルフカンパニーは\n"
	.string "ロケットだんと てを くむのだ!$"

Text_ThunderWaveTeach::
	.string "{JPN}きゃあ!\n"
	.string "やめて! たすけて!\p"
	.string "あ ロケットだんじゃ ないのね。\n"
	.string "ごめんなさい てっきり…\p"
	.string "おわびに でんじはを\n"
	.string "おしえるから ゆるしてくれる?$"

Text_ThunderWaveDeclined::
	.string "{JPN}そう…\n"
	.string "でんじはって べんりなのに…$"

Text_ThunderWaveWhichMon::
	.string "{JPN}どの ポケモンに\n"
	.string "でんじはを おしえる?$"

Text_ThunderWaveTaught::
	.string "{JPN}でんじはは あいての ポケモンを\n"
	.string "まひ させるの。\p"
	.string "まひした ポケモンは バトルで\n"
	.string "うごけない ことが あるわ。\p"
	.string "でんきタイプの わざだから\n"
	.string "きかない ポケモンも いるの。$"

SilphCo_2F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "2かい$"

