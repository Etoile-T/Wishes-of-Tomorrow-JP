SSTidalLowerDeck_MapScripts::
	.byte 0

SSTidalLowerDeck_EventScript_Phillip::
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard::
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro:
	.string "{JPN}ああーっ! こんな ひろい ところの\n"
	.string "そうじは もう うんざりだ くたくただ!\p"
	.string "ちょいと しょうぶ しようぜ!$"

SSTidalLowerDeck_Text_PhillipDefeat:
	.string "{JPN}おとうと まけちまったよ!$"

SSTidalLowerDeck_Text_PhillipPostBattle:
	.string "{JPN}おれたち おそうじ ブラザーズ!\p"
	.string "あにきが せんざい ぶちまけてー\n"
	.string "おとうと せっせと みがくのさー!$"

SSTidalLowerDeck_Text_LeonardIntro:
	.string "{JPN}ここは ふねの いちばん そこ。\n"
	.string "ひろさは じゅうぶん あるから\l"
	.string "ポケモンしょうぶ しても だいじょうぶだろ?$"

SSTidalLowerDeck_Text_LeonardDefeat:
	.string "{JPN}あにき まけちまったよ!$"

SSTidalLowerDeck_Text_LeonardPostBattle:
	.string "{JPN}おれたち おそうじ ブラザーズ!\p"
	.string "あにきが せんざい ぶちまけてー\n"
	.string "おとうと せっせと みがくのさー!$"

