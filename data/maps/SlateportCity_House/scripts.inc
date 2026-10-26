SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "{JPN}うちの ポケモンは せっかちな せいかくでね。\p"
	.string "ほかの ポケモンに くらべて\n"
	.string "すばやさが たかいんだ。\p"
	.string "せいかくは ポケモンの のうりょくの のびに\n"
	.string "かんけい しているのかも しれないね。$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "{JPN}きみは トレーナー だろう?\p"
	.string "カイナシティに きたってことは\n"
	.string "バトルテントに いくんだろうね。$"

