OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	goto OldaleTown_Mart_EventScript_Shop

@ The bar's menu card at (5,3). The bartender stands walled in behind the bar
@ with no counter tile to talk across, so the card is how the player shops.
OldaleTown_Mart_EventScript_MenuCard::
	lockall
	turnobject LOCALID_OLDALE_MART_CLERK, DIR_EAST
	goto OldaleTown_Mart_EventScript_Shop

@ The bar sells Poke Balls and pours drinks: DOMESTIC (a Potion) and CRAFT (a Super Potion).
OldaleTown_Mart_EventScript_Shop::
	message gText_HowMayIServeYou
	waitmessage
	pokemart OldaleTown_Mart_Pokemart_Drinks
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Drinks:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_DOMESTIC
	.2byte ITEM_CRAFT
	pokemartlistend

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_EventScript_TwigsSkier::
	msgbox OldaleTown_Mart_Text_TwigsSkier, MSGBOX_NPC
	end

OldaleTown_Mart_EventScript_ApresGirl::
	msgbox OldaleTown_Mart_Text_ApresGirl, MSGBOX_NPC
	end

OldaleTown_Mart_EventScript_NervousGuy::
	msgbox OldaleTown_Mart_Text_NervousGuy, MSGBOX_NPC
	end

OldaleTown_Mart_EventScript_BoardOrSki::
	msgbox OldaleTown_Mart_Text_BoardOrSki, MSGBOX_NPC
	end

OldaleTown_Mart_EventScript_Draco::
	lock
	faceplayer
	setspeaker SP_NAME_DRACO
	msgbox OldaleTown_Mart_Text_Draco, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_Text_Draco:
	.string "{JPN}{ENG}{PLAYER}{JPN}か。 ここを みつけるとは\n"
	.string "やっぱり おまえらしいな。\p"
	.string "いいきに なるなよ。 ジムバッジを\n"
	.string "うばうまえに こごえた からだを\l"
	.string "あたためているだけだ。\p"
	.string "…それと おまえに のみものを\n"
	.string "おごるつもりは ないからな。$"

OldaleTown_Mart_Text_TwigsSkier:
	.string "{JPN}パイプを すべっていたら\n"
	.string "えぐい コブに エッジを とられてさ…\p"
	.string "スイスアルプスより ふかい パウダーに\n"
	.string "スイッチ540で ちゃくち したんだ。\p"
	.string "2ほんの ぼっきれで やったなかで\n"
	.string "いちばん むちゃな わざだったよ。$"

OldaleTown_Mart_Text_ApresGirl:
	.string "{JPN}アフタースキーだけが おめあてなの。$"

OldaleTown_Mart_Text_NervousGuy:
	.string "{JPN}きんちょうして あのこに はなしかけられない…\p"
	.string "Instagramで DMを おくろうっと。$"

OldaleTown_Mart_Text_BoardOrSki:
	.string "{JPN}ボードか スキーか？\p"
	.string "ただしい こたえは ひとつだけだ。$"

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "{JPN}おみせの ひとが うりきれだって。\n"
	.string "モンスターボールが かえないよ。$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "{JPN}モンスターボールを たくさん かって\n"
	.string "ポケモンを たくさん つかまえるんだ!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "{JPN}ポケモンが きずついて HPを うしない\n"
	.string "ひんしに なると たたかえなくなる。\p"
	.string "ひんしに ならないよう\n"
	.string "キズぐすりで HPを かいふくしてね。$"

