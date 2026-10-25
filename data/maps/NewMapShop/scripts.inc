NewMapShop_MapScripts::
	.byte 0

@ ============================================================================
@  CLIMBING SUPPLY SHOP -- last stock-up before Mt. Munen.
@ ============================================================================
NewMapShop_EventScript_Clerk::
	lock
	faceplayer
	message NewMapShop_Text_Greeting
	waitmessage
	pokemart NewMapShop_Pokemart
	msgbox NewMapShop_Text_Farewell, MSGBOX_DEFAULT
	release
	end

	.align 2
NewMapShop_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_ESCAPE_ROPE
	pokemartlistend

NewMapShop_EventScript_Shopper::
	lock
	faceplayer
	msgbox NewMapShop_Text_Shopper, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  Text
@ ============================================================================
NewMapShop_Text_Greeting::
	.string "{JPN}いらっしゃい！\p"
	.string "なにに する？ かわいこちゃん。$"

NewMapShop_Text_Farewell::
	.string "{JPN}ぶじに おりて くるんだよ？$"

NewMapShop_Text_Shopper::
	.string "{JPN}わたしなら あなぬけのヒモを\n"
	.string "かっておくね。\l"
	.string "こまった ときに\n"
	.string "たすけて くれるよ！$"
