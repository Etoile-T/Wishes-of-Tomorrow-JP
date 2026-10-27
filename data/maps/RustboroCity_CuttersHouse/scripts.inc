RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "{JPN}その きりっとした かおつき……\n"
	.string "その しなやかな みのこなし……\l"
	.string "そして よく きたえられた ポケモン……\p"
	.string "どう みても うでの たつ トレーナーだ!\p"
	.string "いや まて なにも いうな\n"
	.string "みれば わかる\p"
	.string "きみなら この ひでんマシンを\n"
	.string "うまく つかいこなせる はずだ\p"
	.string "えんりょ しなくて いい\n"
	.string "さあ もっていけ!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "{JPN}その ひでんマシン……\n"
	.string "なかみは いあいぎりだ\p"
	.string "ひでんわざは せんとう いがいでも\n"
	.string "ポケモンが つかえる わざだ\p"
	.string "いあいぎりを おぼえた ポケモンは\n"
	.string "トレーナーが ストーンバッジを もっていれば\l"
	.string "ほそい きを きりたおせるぞ\p"
	.string "それに わざマシンと ちがって\n"
	.string "ひでんマシンは なんどでも つかえる$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "{JPN}カナズミの まちを ひろげる とき\n"
	.string "おやじも てつだったんだ\p"
	.string "ポケモンに いあいぎりを つかわせて\n"
	.string "きを きりひらいたのさ$"

