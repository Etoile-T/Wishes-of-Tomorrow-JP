SSAnne_2F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_LASS_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarIntro::
	.string "{JPN}つよい ポケモンと めずらしい ポケモン\n"
	.string "きみは どちらに かちが あると おもう?$"

SSAnne_2F_Room4_Text_LamarDefeat::
	.string "{JPN}けいい を ひょう しよう!$"

SSAnne_2F_Room4_Text_LamarPostBattle::
	.string "{JPN}わたしは つよくて めずらしい\n"
	.string "ポケモンが すきだがね。$"

SSAnne_2F_Room4_Text_DawnIntro::
	.string "{JPN}パーティで あなたを みかけなかった\n"
	.string "きが するけど?$"

SSAnne_2F_Room4_Text_DawnDefeat::
	.string "{JPN}おてやわらかに!$"

SSAnne_2F_Room4_Text_DawnPostBattle::
	.string "{JPN}まあ つよい ポケモンね! すてき!\n"
	.string "ほんとうに うらやましいわ!$"

