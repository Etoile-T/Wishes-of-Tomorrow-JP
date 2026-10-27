MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "{JPN}ここに いると……\n"
	.string "ふしぎな ちからが はいってくるの……$"

MtPyre_6F_Text_ValerieDefeat:
	.string "{JPN}ちからが ぬけていく……$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "{JPN}ここで ねむれずに いる ポケモンたちの\n"
	.string "ちからが はいって くるのかもよ……?$"

MtPyre_6F_Text_ValerieRegister:
	.string "{JPN}ふふふふ しょうぶには まけたけど\n"
	.string "わたし…… こんな ことが できるの……\p"
	.string "あなたの ポケナビに いっさい てを\n"
	.string "ふれなくても…… きえーいっ……!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "{JPN}あなたの うしろ……\n"
	.string "なにが いるの……$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "{JPN}なにかが きえたわ……$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "{JPN}ここに ねむっている ポケモンたち……\n"
	.string "ときどき あそんでいる みたいなの……$"

MtPyre_6F_Text_CedricIntro:
	.string "{JPN}きみ まいごなのか?\n"
	.string "おれが きた からには あんしんだ!$"

MtPyre_6F_Text_CedricDefeat:
	.string "{JPN}まいご じゃ なかったか?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "{JPN}まいごの トレーナーは あわてて いるから\n"
	.string "かんたんに かてる きが したんだよな\p"
	.string "ずるいから もう やめとくよ……$"

