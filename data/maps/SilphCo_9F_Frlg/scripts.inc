SilphCo_9F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_9F_OnLoad
	.byte 0

SilphCo_9F_OnLoad::
	call_if_unset FLAG_SILPH_9F_DOOR_1, EventScript_Close9FDoor1
	call_if_unset FLAG_SILPH_9F_DOOR_2, EventScript_Close9FDoor2
	call_if_unset FLAG_SILPH_9F_DOOR_3, EventScript_Close9FDoor3
	call_if_unset FLAG_SILPH_9F_DOOR_4, EventScript_Close9FDoor4
	end

SilphCo_9F_EventScript_HealWoman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_9F_EventScript_HealWomanRocketsGone
	msgbox SilphCo_9F_Text_YouShouldTakeQuickNap
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SilphCo_9F_Text_DontGiveUp
	release
	end

SilphCo_9F_EventScript_HealWomanRocketsGone::
	msgbox SilphCo_9F_Text_ThankYouSoMuch
	release
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat
	msgbox SilphCo_9F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat
	msgbox SilphCo_9F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_Text_YouShouldTakeQuickNap::
	.string "{JPN}つかれてるみたいだね\n"
	.string "すこし ひとやすみ したら?$"

SilphCo_9F_Text_DontGiveUp::
	.string "{JPN}あきらめないで!$"

SilphCo_9F_Text_ThankYouSoMuch::
	.string "{JPN}ほんとうに ありがとう$"

SilphCo_9F_Text_Grunt1Intro::
	.string "{JPN}おまえの ポケモン ずいぶん\n"
	.string "なついてるな ぼうず!$"

SilphCo_9F_Text_Grunt1Defeat::
	.string "{JPN}ぐはあっ!$"

SilphCo_9F_Text_Grunt1PostBattle::
	.string "{JPN}おれも おまえぐらいの としで\n"
	.string "トレーナーに なってたら…$"

SilphCo_9F_Text_EdIntro::
	.string "{JPN}おまえの ポケモンには じゃくてんが\n"
	.string "ある! そこを つくぜ!$"

SilphCo_9F_Text_EdDefeat::
	.string "{JPN}こてんぱんに やられた!$"

SilphCo_9F_Text_EdPostBattle::
	.string "{JPN}じゃくてんを つくのは ききめが ある\n"
	.string "タイプの あいしょうを かんがえな$"

SilphCo_9F_Text_Grunt2Intro::
	.string "{JPN}おれは ロケットだん\n"
	.string "4きょうだいの ひとり!$"

SilphCo_9F_Text_Grunt2Defeat::
	.string "{JPN}ぐおっ!\n"
	.string "きょうだいたち まけちまった!$"

SilphCo_9F_Text_Grunt2PostBattle::
	.string "{JPN}きょうだいたちが かたきを うつぜ!$"

SilphCo_9F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "9F$"

