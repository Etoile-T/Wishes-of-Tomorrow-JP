SilphCo_8F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	end

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_Text_WonderIfSilphIsFinished::
	.string "{JPN}シルフは もう おしまいかなあ…$"

SilphCo_8F_Text_ThanksForSavingUs::
	.string "{JPN}たすけてくれて ありがとう!$"

SilphCo_8F_Text_Grunt1Intro::
	.string "{JPN}ここから さきへは いかせねえ!$"

SilphCo_8F_Text_Grunt1Defeat::
	.string "{JPN}こんじょうが たりねえ!$"

SilphCo_8F_Text_Grunt1PostBattle::
	.string "{JPN}ひきかえさないと…\n"
	.string "おうえんを よぶぞ!$"

SilphCo_8F_Text_ParkerIntro::
	.string "{JPN}じゃまを してくれるな!$"

SilphCo_8F_Text_ParkerDefeat::
	.string "{JPN}あれ?\n"
	.string "まけた?$"

SilphCo_8F_Text_ParkerPostBattle::
	.string "{JPN}で シルフビルの めいろは\n"
	.string "どうだい?$"

SilphCo_8F_Text_Grunt2Intro::
	.string "{JPN}おれは ロケットだん\n"
	.string "4きょうだいの ひとり!$"

SilphCo_8F_Text_Grunt2Defeat::
	.string "{JPN}うおっ!\n"
	.string "ああ きょうだいたち!$"

SilphCo_8F_Text_Grunt2PostBattle::
	.string "{JPN}あとは きょうだいたちに まかせた$"

SilphCo_8F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "8F$"

SilphCo_8F_Text_ToRocketBossMonsAreTools::
	.string "{JPN}ロケットだんの ボスは\n"
	.string "ひどく ざんこくなんだ!\p"
	.string "あいつにとって ポケモンは\n"
	.string "ただの どうぐなんだ\p"
	.string "あんな ぼうくんに かいしゃを\n"
	.string "のっとられたら どうなるか…$"
