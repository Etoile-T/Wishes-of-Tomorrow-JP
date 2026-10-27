PewterCity_Mart_Frlg_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Boy::
	msgbox PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart PewterCity_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
PewterCity_Mart_Items::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy::
	.string "{JPN}あやしい おじさんに のせられて\n"
	.string "へんな さかなの ポケモンを かっちゃった!\p"
	.string "ぜんぜん よわいのに 500円も したんだ!$"

PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently::
	.string "{JPN}ポケモンを ねっしんに そだてると\n"
	.string "いい ことが あるかもね。\p"
	.string "よわい ポケモンでも みすてなければ\n"
	.string "おどろく ほど かわる かもしれない。$"

