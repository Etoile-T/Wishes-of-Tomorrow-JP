MtMoon_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_MOON_1F
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatIsABloodsucker, MSGBOX_SIGN
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_HIKER_MARCOS, MtMoon_1F_Text_MarcosIntro, MtMoon_1F_Text_MarcosDefeat
	msgbox MtMoon_1F_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshIntro, MtMoon_1F_Text_JoshDefeat
	msgbox MtMoon_1F_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_LASS_MIRIAM, MtMoon_1F_Text_MiriamIntro, MtMoon_1F_Text_MiriamDefeat
	msgbox MtMoon_1F_Text_MiriamPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_LASS_IRIS, MtMoon_1F_Text_IrisIntro, MtMoon_1F_Text_IrisDefeat
	msgbox MtMoon_1F_Text_IrisPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanIntro, MtMoon_1F_Text_JovanDefeat
	msgbox MtMoon_1F_Text_JovanPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_BUG_CATCHER_KENT, MtMoon_1F_Text_KentIntro, MtMoon_1F_Text_KentDefeat
	msgbox MtMoon_1F_Text_KentPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbyIntro, MtMoon_1F_Text_RobbyDefeat
	msgbox MtMoon_1F_Text_RobbyPostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_Text_MarcosIntro::
	.string "{JPN}うわっ!\n"
	.string "びっくりした!\l"
	.string "……なんだ こどもか!$"

MtMoon_1F_Text_MarcosDefeat::
	.string "{JPN}うわっ!\n"
	.string "また びっくりした!$"

MtMoon_1F_Text_MarcosPostBattle::
	.string "{JPN}きみ みたいな こどもが こんな\n"
	.string "くらい ところを うろつくもんじゃない。$"

MtMoon_1F_Text_JoshIntro::
	.string "{JPN}きみも どうくつを たんけんしに\n"
	.string "きたの?$"

MtMoon_1F_Text_JoshDefeat::
	.string "{JPN}まけるって さいあく!\n"
	.string "かっこわるい。$"

MtMoon_1F_Text_JoshPostBattle::
	.string "{JPN}おんなのこに かっこいい ところを\n"
	.string "みせたくて ここまで きたのに。$"

MtMoon_1F_Text_MiriamIntro::
	.string "{JPN}わあ! おもってたより\n"
	.string "ずっと ひろーい!$"

MtMoon_1F_Text_MiriamDefeat::
	.string "{JPN}あっ!\n"
	.string "まけちゃった!$"

MtMoon_1F_Text_MiriamPostBattle::
	.string "{JPN}ここって どうやって でるの?\n"
	.string "ひろすぎて まよいそう。$"

MtMoon_1F_Text_JovanIntro::
	.string "{JPN}なんだ!\n"
	.string "こっそり ちかづくなよ!$"

MtMoon_1F_Text_JovanDefeat::
	.string "{JPN}おれの ポケモンじゃ だめだ!$"

MtMoon_1F_Text_JovanPostBattle::
	.string "{JPN}もっと つよい ポケモンを さがさないと。\n"
	.string "どこに いるんだろう?$"

MtMoon_1F_Text_IrisIntro::
	.string "{JPN}なに?\n"
	.string "ともだちが みつけて くれるのを\l"
	.string "ここで まってるの。$"

MtMoon_1F_Text_IrisDefeat::
	.string "{JPN}まけたの?$"

MtMoon_1F_Text_IrisPostBattle::
	.string "{JPN}ここに とても めずらしい かせきが\n"
	.string "あるって きいて きたの。$"

MtMoon_1F_Text_KentIntro::
	.string "{JPN}どうくつに あやしい おとこたちが いる。\n"
	.string "きみは どうなんだ?$"

MtMoon_1F_Text_KentDefeat::
	.string "{JPN}やられた!$"

MtMoon_1F_Text_KentPostBattle::
	.string "{JPN}おれは みたんだ!\n"
	.string "あれは ぜったい ロケットだんだ!$"

MtMoon_1F_Text_RobbyIntro::
	.string "{JPN}ハナダシティへ いくには\n"
	.string "この どうくつを ぬけないと いけない。$"

MtMoon_1F_Text_RobbyDefeat::
	.string "{JPN}まけた。$"

MtMoon_1F_Text_RobbyPostBattle::
	.string "{JPN}ズバットは てごわいぞ!\n"
	.string "でも つかまえられたら\l"
	.string "たよりに なるぜ。$"

MtMoon_1F_Text_ZubatIsABloodsucker::
	.string "{JPN}きをつけて!\n"
	.string "ズバットは ちを すうよ!$"

MtMoon_1F_Text_BrockHelpsExcavateFossils::
	.string "{JPN}やあ! ぼくは この おつきみやまの\n"
	.string "したで かせきを ほってるんだ。\p"
	.string "ときどき ニビジムの タケシが\n"
	.string "てつだって くれるんだよ。$"
