LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook::
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart1:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_WASTER_BALL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart2:
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_MECH_MAIL
	pokemartlistend

LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly:
	.string "{JPN}どうぐを ただしく つかうこと。\n"
	.string "それが きほんなんだよ。$"

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
	.string "{JPN}だんなが いえで まってるの。\n"
	.string "おみやげは なにが いいかしら?$"

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
	.string "{JPN}もうすぐ ながい たびに でるの。\n"
	.string "どうぐを かいこんで おかなくちゃ。$"

@ Wishes of Tomorrow: the Waster Ball couple (by the ball counter).
LilycoveCity_DepartmentStore_2F_EventScript_WasterHusband::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStore_2F_Text_WasterHusband, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_2F_EventScript_WasterWife::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStore_2F_Text_WasterWife, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_2F_Text_WasterHusband::
	.string "{JPN}なあ みたかい? ここでは\n"
	.string "マスターボールを うってるぞ!\p"
	.string "これで やっと きみの ほしがってた\n"
	.string "ルージュラを つかまえて あげられる!$"

LilycoveCity_DepartmentStore_2F_Text_WasterWife::
	.string "{JPN}ルージュラと エッチしたいのは\n"
	.string "あんたの ほうでしょ!\p"
	.string "それに「ウェイスターボール」って\n"
	.string "かいてあるわよ。おばかさん。$"

