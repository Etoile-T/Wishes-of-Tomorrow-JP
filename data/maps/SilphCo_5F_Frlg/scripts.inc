SilphCo_5F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_5F_OnLoad
	.byte 0

SilphCo_5F_OnLoad::
	call_if_unset FLAG_SILPH_5F_DOOR_1, EventScript_Close5FDoor1
	call_if_unset FLAG_SILPH_5F_DOOR_2, EventScript_Close5FDoor2
	call_if_unset FLAG_SILPH_5F_DOOR_3, EventScript_Close5FDoor3
	end

SilphCo_5F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_5F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_5F_Text_RocketsInUproarAboutIntruder
	release
	end

SilphCo_5F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_5F_Text_YoureOurHeroThankYou
	release
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PorygonFirstVRMon, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_Over350TechniquesConfirmed, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_SomeMonsEvolveWhenTraded, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_SCIENTIST_BEAU, SilphCo_5F_Text_BeauIntro, SilphCo_5F_Text_BeauDefeat
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_28, SilphCo_5F_Text_Grunt1Intro, SilphCo_5F_Text_Grunt1Defeat
	msgbox SilphCo_5F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_29, SilphCo_5F_Text_Grunt2Intro, SilphCo_5F_Text_Grunt2Defeat
	msgbox SilphCo_5F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_JUGGLER_DALTON, SilphCo_5F_Text_DaltonIntro, SilphCo_5F_Text_DaltonDefeat
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_Text_RocketsInUproarAboutIntruder::
	.string "{JPN}ロケットだんが しんにゅうしゃが\n"
	.string "いるって おおさわぎ してる。\p"
	.string "それ きみの ことでしょ?$"

SilphCo_5F_Text_YoureOurHeroThankYou::
	.string "{JPN}ロケットだんが にげていった!\n"
	.string "きみは ヒーローだ! ありがとう!$"

SilphCo_5F_Text_Grunt1Intro::
	.string "{JPN}ガキが うろついてると\n"
	.string "きいたが。$"

SilphCo_5F_Text_Grunt1Defeat::
	.string "{JPN}ドカーン!$"

SilphCo_5F_Text_Grunt1PostBattle::
	.string "{JPN}ロケットだんに けんかを うるのは\n"
	.string "かしこく ないぜ!$"

SilphCo_5F_Text_BeauIntro::
	.string "{JPN}この フロアでは モンスターボールの\n"
	.string "ぎじゅつを けんきゅうしている。$"

SilphCo_5F_Text_BeauDefeat::
	.string "{JPN}くそう!\n"
	.string "ちくしょう!$"

SilphCo_5F_Text_BeauPostBattle::
	.string "{JPN}なんでも つかまえられる きゅうきょくの\n"
	.string "モンスターボールを つくっていたんだ。$"

SilphCo_5F_Text_DaltonIntro::
	.string "{JPN}なにぃ?\p"
	.string "こどもが いる はずは\n"
	.string "ないのに!$"

SilphCo_5F_Text_DaltonDefeat::
	.string "{JPN}な なんと!$"

SilphCo_5F_Text_DaltonPostBattle::
	.string "{JPN}まだ 5かいだぞ。\n"
	.string "ボスまでは とおいぜ!$"

SilphCo_5F_Text_Grunt2Intro::
	.string "{JPN}ロケットだんを なめるなよ!$"

SilphCo_5F_Text_Grunt2Defeat::
	.string "{JPN}ゴホッ…\n"
	.string "ゴホッ…$"

SilphCo_5F_Text_Grunt2PostBattle::
	.string "{JPN}そういえば。\p"
	.string "ドガースは マタドガスに しんかするぞ!$"

SilphCo_5F_Text_PorygonFirstVRMon::
	.string "{JPN}ポケモン レポートだ!\p"
	.string "ポケモン けんきゅうじょは さいしょの\n"
	.string "バーチャル ポケモン ポリゴンを つくった。$"

SilphCo_5F_Text_Over350TechniquesConfirmed::
	.string "{JPN}ポケモン レポートだ!\p"
	.string "ポケモンの わざは 350しゅるい いじょう\n"
	.string "かくにん されている。$"

SilphCo_5F_Text_SomeMonsEvolveWhenTraded::
	.string "{JPN}ポケモン レポートだ!\p"
	.string "こうかんすると しんかする\n"
	.string "ポケモンが かくにん された。$"

SilphCo_5F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "5かい$"

SilphCo_5F_Text_RocketBossLookingForStrongMons::
	.string "{JPN}ビルを のっとった\n"
	.string "あの ならずものたち…\p"
	.string "ボスは つよい ポケモンを\n"
	.string "さがしてると いっていた。\p"
	.string "しゃちょうが ぶじだと\n"
	.string "いいんだけど…$"
