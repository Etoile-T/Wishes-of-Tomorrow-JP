MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "{JPN}よう トレーナー!\n"
	.string "すごいつりざおは ほんとに すごいぞ!\p"
	.string "なんと いわれようと こいつなら\n"
	.string "うみの そこの ポケモンも つれるんだ!\p"
	.string "どうだい?\n"
	.string "ほしいだろ?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "{JPN}そうだろ そうだろ!\n"
	.string "すごいつりざおは ほんとうに すごいからの!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "{JPN}みずの ある ところなら つりざおを\n"
	.string "たらして なにが かかるか ためしてみな!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "{JPN}あら?\n"
	.string "つりは きらい なのかね?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "{JPN}すごいつりざおで\n"
	.string "うみの そこの ポケモンを ねらえ!$"

