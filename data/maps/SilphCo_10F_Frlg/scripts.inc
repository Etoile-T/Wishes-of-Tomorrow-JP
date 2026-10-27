SilphCo_10F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
	.string "{JPN}10かいへ ようこそ!\n"
	.string "よく きてくれたな!$"

SilphCo_10F_Text_GruntDefeat::
	.string "{JPN}あぜん…!$"

SilphCo_10F_Text_GruntPostBattle::
	.string "{JPN}おしかったな! じゅうやくしつは\n"
	.string "もう ひとつ うえの かいだ。$"

SilphCo_10F_Text_TravisIntro::
	.string "{JPN}おあそびは そこまでだ!$"

SilphCo_10F_Text_TravisDefeat::
	.string "{JPN}コンティニューは もう ない!$"

SilphCo_10F_Text_TravisPostBattle::
	.string "{JPN}わたしを たおして まんぞくか?\n"
	.string "なら さっさと かえれ!$"

SilphCo_10F_Text_WaaaImScared::
	.string "{JPN}うえーん!\n"
	.string "こわいよう!$"

SilphCo_10F_Text_KeepMeCryingASecret::
	.string "{JPN}ないてた ことは…\n"
	.string "ないしょに してね。$"

SilphCo_10F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "10かい$"

