MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "{JPN}この やまの こい くうきが\n"
	.string "わたしの サイコパワーを たかめた!\p"
	.string "きみの ような こどもが……\n"
	.string "かてると おもっているのか?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "{JPN}じぶんが なさけない……$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "{JPN}わたしの サイコパワーは かくじつに\n"
	.string "なんばいも つよく なったはず なのに……$"

MtPyre_3F_Text_KaylaIntro:
	.string "{JPN}おほほほほっ!\p"
	.string "ここは こどもの くる ばしょじゃ ないわ\n"
	.string "とくに あなたの ような こどもはね!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "{JPN}あっさり まけたわっ……!$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "{JPN}まだまだ しゅぎょうが\n"
	.string "たりない って ことね……\p"
	.string "ちょうじょうを めざして\n"
	.string "がんばらなきゃ……\p"
	.string "ファイト わたし!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "{JPN}あなたは なぜ ここへ……?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "{JPN}すごいわ!\n"
	.string "あなたは すてきな トレーナーさんね$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "{JPN}いまはもう いない ポケモン\n"
	.string "いま いっしょに いる ポケモン\p"
	.string "それに これから であう\n"
	.string "ポケモン……\p"
	.string "すべて ひとしく たいせつな ポケモン なのよ\n"
	.string "おぼえて おいて くださいね$"

MtPyre_3F_Text_GabrielleRegister:
	.string "{JPN}あなたの ポケモンが もっと そだったら\n"
	.string "また みせて ほしいわ……\p"
	.string "ポケナビを みせて もらえるかしら$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "{JPN}あら あなたね……\p"
	.string "そだった ポケモンを みせに\n"
	.string "きて くれたの?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "{JPN}ほんとうに すごいわ!\n"
	.string "あなたは すてきね$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "{JPN}いまはもう いない ポケモン\n"
	.string "いま いっしょに いる ポケモン\p"
	.string "それに これから であう\n"
	.string "ポケモン……\p"
	.string "すべて ひとしく たいせつな ポケモン なのよ\n"
	.string "おぼえて くれて いたのね$"

