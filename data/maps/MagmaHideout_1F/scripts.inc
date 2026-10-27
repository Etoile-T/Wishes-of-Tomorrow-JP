MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "{JPN}マグマだんでは てんこの とき\n"
	.string "ならんだ じゅんに だいじな\l"
	.string "みはりの もちばが きまるんだ。\p"
	.string "だから オレは こんな すみっこに……\n"
	.string "いつも てんこに ちこく するからな!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "{JPN}トレーニングにも いつも\n"
	.string "ちこく するし!\p"
	.string "いいたく ないけど オレって よわい……$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "{JPN}わかったよ こんどから もうすこし\n"
	.string "がんばって みるよ……$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "{JPN}リーダーに えんとつやまを ほれって\n"
	.string "いわれて ほって ほって ほりまくった。\p"
	.string "そしたら ほってる とちゅうで\n"
	.string "とんでもない ものを みつけたんだ!\p"
	.string "なにを みつけたか って?\p"
	.string "ふはははは!\n"
	.string "オレに かったら おしえてやる!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "{JPN}ぐわっ!\n"
	.string "やられた!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "{JPN}やっぱり おしえるの やーめた!\n"
	.string "おくまで いけば わかることさ!\p"
	.string "おたのしみは あとに のこして\n"
	.string "おいたほうが いいだろ?$"

