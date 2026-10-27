SilphCo_6F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_6F_OnLoad
	.byte 0

SilphCo_6F_OnLoad::
	call_if_unset FLAG_SILPH_6F_DOOR, EventScript_Close6FDoor
	end

SilphCo_6F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_6F_Text_TargetedSilphForOurMonProducts
	release
	end

SilphCo_6F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder
	release
	end

SilphCo_6F_EventScript_WorkerM3::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM3RocketsGone
	msgbox SilphCo_6F_Text_RocketsTookOverBuilding
	release
	end

SilphCo_6F_EventScript_WorkerM3RocketsGone::
	msgbox SilphCo_6F_Text_BetterGetBackToWork
	release
	end

SilphCo_6F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_6F_Text_HelpMePlease
	release
	end

SilphCo_6F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_6F_Text_WeGotEngaged
	release
	end

SilphCo_6F_EventScript_WorkerF1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF1RocketsGone
	msgbox SilphCo_6F_Text_ThatManIsSuchACoward
	release
	end

SilphCo_6F_EventScript_WorkerF1RocketsGone::
	msgbox SilphCo_6F_Text_NeedsMeToLookAfterHim
	release
	end

SilphCo_6F_EventScript_WorkerF2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_6F_EventScript_WorkerF2RocketsGone
	msgbox SilphCo_6F_Text_RocketsTryingToConquerWorld
	release
	end

SilphCo_6F_EventScript_WorkerF2RocketsGone::
	msgbox SilphCo_6F_Text_RocketsRanAwayBecauseOfYou
	release
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorIntro, SilphCo_6F_Text_TaylorDefeat
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_30, SilphCo_6F_Text_Grunt1Intro, SilphCo_6F_Text_Grunt1Defeat
	msgbox SilphCo_6F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_31, SilphCo_6F_Text_Grunt2Intro, SilphCo_6F_Text_Grunt2Defeat
	msgbox SilphCo_6F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_Text_RocketsTookOverBuilding::
	.string "{JPN}ロケットだんが きて\n"
	.string "ビルを のっとったんだ!$"

SilphCo_6F_Text_BetterGetBackToWork::
	.string "{JPN}さて しごとに もどるか。$"

SilphCo_6F_Text_HelpMePlease::
	.string "{JPN}ああ どうしよう どうしよう。\n"
	.string "たすけてください!$"

SilphCo_6F_Text_WeGotEngaged::
	.string "{JPN}わたしたち こんやく したの。\n"
	.string "えへへ!$"

SilphCo_6F_Text_ThatManIsSuchACoward::
	.string "{JPN}となりの あの ひと…\n"
	.string "ほんとに おくびょう なんだから!$"

SilphCo_6F_Text_NeedsMeToLookAfterHim::
	.string "{JPN}あの ひと たよりないから\n"
	.string "わたしが めんどう みてあげなきゃ。$"

SilphCo_6F_Text_RocketsTryingToConquerWorld::
	.string "{JPN}ロケットだんは ポケモンを つかって\n"
	.string "せかいせいふくを たくらんでいる。$"

SilphCo_6F_Text_RocketsRanAwayBecauseOfYou::
	.string "{JPN}ロケットだんが にげたのは\n"
	.string "ぜんぶ きみの おかげだ!$"

SilphCo_6F_Text_TargetedSilphForOurMonProducts::
	.string "{JPN}やつらは うちの ポケモンせいひんを\n"
	.string "ねらって シルフを おそったんだろう。$"

SilphCo_6F_Text_ComeWorkForSilphWhenYoureOlder::
	.string "{JPN}おとなに なったら\n"
	.string "シルフで はたらかないか。$"

SilphCo_6F_Text_Grunt1Intro::
	.string "{JPN}おれは ロケット 4きょうだいの\n"
	.string "ひとりだ!$"

SilphCo_6F_Text_Grunt1Defeat::
	.string "{JPN}もえつきた!$"

SilphCo_6F_Text_Grunt1PostBattle::
	.string "{JPN}かまわん!\n"
	.string "きょうだいが かたきを うつ!$"

SilphCo_6F_Text_TaylorIntro::
	.string "{JPN}あの くそ しゃちょうめ!\p"
	.string "おれを ティクシ してんに\n"
	.string "とばしやがって ざまあみろ!\p"
	.string "だから ロケットだんに\n"
	.string "ねらわれたんだ ぜったい そうだ!$"

SilphCo_6F_Text_TaylorDefeat::
	.string "{JPN}ちっ!$"

SilphCo_6F_Text_TaylorPostBattle::
	.string "{JPN}ティクシ してん?\n"
	.string "ロシアの さいはての ちだぞ!$"

SilphCo_6F_Text_Grunt2Intro::
	.string "{JPN}ロケットだんを うらぎる きか?$"

SilphCo_6F_Text_Grunt2Defeat::
	.string "{JPN}うらぎりものめ!$"

SilphCo_6F_Text_Grunt2PostBattle::
	.string "{JPN}せいぎの みかたって ことは\n"
	.string "わるものの おれたちを うらぎるって ことだ!$"

SilphCo_6F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "6かい$"

