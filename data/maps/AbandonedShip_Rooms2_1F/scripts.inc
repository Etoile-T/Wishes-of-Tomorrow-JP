AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "{JPN}ダン: おたから さがしていたら\n"
	.string "トレーナー はっけん!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "{JPN}ダン: ふたりで ちからを あわせても\n"
	.string "かてなかったのか……$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "{JPN}ダン: おたから みつからないんだよね……\n"
	.string "もう だれかが もっていったのかな?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "{JPN}ダン: ポケモン 2ひきも いないんだね。\n"
	.string "それじゃ ぼくたちには かてないよ!$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "{JPN}キラ: あら?\n"
	.string "おたからを さがしていたのに\l"
	.string "トレーナーを みつけちゃった!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "{JPN}キラ: やだ つよいんだ!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "{JPN}キラ: おたからは どこに あるのかしら?\p"
	.string "おたからが みつかったら なにを かうか\n"
	.string "もう きめてるんだから!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "{JPN}キラ: あら ポケモン 2ひき いないの?\n"
	.string "じゃあ しょうぶは おあずけね!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "{JPN}キラ: もう くやしいな!\n"
	.string "あなたなんて とうろく しちゃうんだから!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "{JPN}ダン: ぼくたち ずっと\n"
	.string "おたからを さがしてたんだ。\p"
	.string "ポケモンも つよく なったんだよ。\n"
	.string "みせて あげるね!$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "{JPN}ダン: あいかわらず つよいな!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "{JPN}ダン: おたからは みつからないし\n"
	.string "ポケモンしょうぶには まけるし……\p"
	.string "もう かえりたいよ…… でも そう いうと\n"
	.string "かのじょ おこりだすからな……$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "{JPN}ダン: ポケモン 2ひきも いないんだね。\n"
	.string "それじゃ ぼくたちには かてないよ!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "{JPN}キラ: あら? また あったわね!\p"
	.string "わたしたちと おなじで あなたも まだ\n"
	.string "おたからを あきらめてないのね?\p"
	.string "まけたほうが さがすのを あきらめる\n"
	.string "ってことに しない?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "{JPN}キラ: また まけちゃった……$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "{JPN}キラ: ポケモンを もっと きたえて\n"
	.string "ここの おたからを みつけるまで\l"
	.string "ぜったい かえらないんだから!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "{JPN}キラ: あら ポケモン 2ひき いないの?\n"
	.string "じゃあ しょうぶは おあずけね!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "{JPN}およぐのは ヘタだけど\n"
	.string "しょうぶは とくい なんだから!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "{JPN}あらら。\n"
	.string "うまく いかなかったな。$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "{JPN}この ふねの なかを はだしで あるくと\n"
	.string "ちょっと きもちわるいなあ。$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "{JPN}つよさと やさしさ……\n"
	.string "それが トレーナーの たから!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "{JPN}おお あなたには\n"
	.string "キラリと ひかるものが あるな。$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "{JPN}ふねの どこかの へやで\n"
	.string "キラリと ひかるものを みたんだ。$"
