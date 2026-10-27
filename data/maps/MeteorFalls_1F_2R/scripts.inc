MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas::
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas::
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay::
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay::
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT  @ John speaks for both during register
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay::
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro:
	.string "{JPN}ここは オレたち ドラゴンつかいの\n"
	.string "しゅぎょうの ばしょ!\p"
	.string "チャンピオンも くるほどだ。\n"
	.string "その すごさ わかるだろう!?$"

MeteorFalls_1F_2R_Text_NicolasDefeat:
	.string "{JPN}くっ!\n"
	.string "これほど つよいとは……!$"

MeteorFalls_1F_2R_Text_NicolasPostBattle:
	.string "{JPN}まだまだ みちは ながく けわしい。\p"
	.string "オレと オレの ポケモンが いちばんに\n"
	.string "なれるのは いつだろう……$"

MeteorFalls_1F_2R_Text_NicolasRegister:
	.string "{JPN}きみの つよさを もっと しりたい。\n"
	.string "ポケナビに とうろく させてくれ!$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro:
	.string "{JPN}あれから いちばんを めざして\n"
	.string "かなり じぶんたちを きたえた……\p"
	.string "どれほど つよくなったか\n"
	.string "きみで たしかめさせて もらおうッ!$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat:
	.string "{JPN}くっ!\n"
	.string "これほど つよいとは……!$"

MeteorFalls_1F_2R_Text_NicolasPostRematch:
	.string "{JPN}きみは ずっと ポケモンを\n"
	.string "きたえつづけて いるんだな。\p"
	.string "きみが つよい かぎり オレも\n"
	.string "もっと つよく なれる!$"

MeteorFalls_1F_2R_Text_JohnIntro:
	.string "{JPN}ゲン: わしらは いつも ふうふ ふたりで\n"
	.string "ポケモンしょうぶ してきたからのう。\l"
	.string "じしんが あるんじゃよ。$"

MeteorFalls_1F_2R_Text_JohnDefeat:
	.string "{JPN}ゲン: おやおや\n"
	.string "まけたよ ばあさん。$"

MeteorFalls_1F_2R_Text_JohnPostBattle:
	.string "{JPN}ゲン: わしらは けっこんして\n"
	.string "50ねんに なる。\p"
	.string "そういえば わしは ばあさんに しょうぶで\n"
	.string "いちども かったことが ないのう。$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons:
	.string "{JPN}ゲン: おやおや わかい トレーナーじゃな!\p"
	.string "わしらと しょうぶ するなら\n"
	.string "ポケモンを もっと つれておいで。$"

MeteorFalls_1F_2R_Text_JohnRegister:
	.string "{JPN}ゲン: わかい トレーナーさん きかいが\n"
	.string "あったら また しょうぶ してくれるかの?$"

MeteorFalls_1F_2R_Text_JayIntro:
	.string "{JPN}ハツ: わたしたち けっこんして\n"
	.string "50ねんに なりますの。\p"
	.string "ふうふの きずなは けっして\n"
	.string "こわれませんよ。$"

MeteorFalls_1F_2R_Text_JayDefeat:
	.string "{JPN}ハツ: おやおや\n"
	.string "まけましたよ じいさん。$"

MeteorFalls_1F_2R_Text_JayPostBattle:
	.string "{JPN}ハツ: けっこんして 50ねん……\p"
	.string "けんかを したときは いつも\n"
	.string "ポケモンしょうぶで きめてきましたねえ……$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons:
	.string "{JPN}ハツ: おやおや\n"
	.string "わかい トレーナーさん ですねえ。\p"
	.string "わたしたちと しょうぶ してくれるのなら\n"
	.string "ポケモンを もっと つれておいで。$"

MeteorFalls_1F_2R_Text_JohnRematchIntro:
	.string "{JPN}ゲン: わしらは いつも ふうふ ふたりで\n"
	.string "ポケモンしょうぶ してきたからのう。\l"
	.string "じしんが あるんじゃよ。$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat:
	.string "{JPN}ゲン: おやおや\n"
	.string "まけたよ ばあさん。$"

MeteorFalls_1F_2R_Text_JohnPostRematch:
	.string "{JPN}ゲン: けっこんして 50ねん……\p"
	.string "ふりかえれば ばあさんと わしは\n"
	.string "あけても くれても しょうぶ じゃった……$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons:
	.string "{JPN}ゲン: おやおや わかい トレーナーじゃな!\p"
	.string "わしらと しょうぶ するなら\n"
	.string "ポケモンを もっと つれておいで。$"

MeteorFalls_1F_2R_Text_JayRematchIntro:
	.string "{JPN}ハツ: わたしたち けっこんして\n"
	.string "50ねんに なりますの。\p"
	.string "ずっと ささえあって きたから\n"
	.string "ふたりとも つよく なれたんですよ。$"

MeteorFalls_1F_2R_Text_JayRematchDefeat:
	.string "{JPN}ハツ: おやおや\n"
	.string "まけましたよ じいさん。$"

MeteorFalls_1F_2R_Text_JayPostRematch:
	.string "{JPN}ハツ: けっこんして 50ねん……\n"
	.string "いろんなことが ありましたねえ。\p"
	.string "これからも じいさんと いっしょに\n"
	.string "たのしい おもいでを つくりたいですねえ。$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons:
	.string "{JPN}ハツ: おやおや\n"
	.string "わかい トレーナーさん ですねえ。\p"
	.string "わたしたちと しょうぶ してくれるのなら\n"
	.string "ポケモンを もっと つれておいで。$"

