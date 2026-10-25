Route2LifeguardShack_MapScripts::
	.byte 0

Route2LifeguardShack_EventScript_Lifeguard::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE2_GOT_SOFT_SAND, Route2LifeguardShack_EventScript_LifeguardAgain
	msgbox Route2LifeguardShack_Text_Lifeguard, MSGBOX_DEFAULT
	giveitem ITEM_SOFT_SAND
	setflag FLAG_ROUTE2_GOT_SOFT_SAND
	release
	end

Route2LifeguardShack_EventScript_LifeguardAgain::
	msgbox Route2LifeguardShack_Text_LifeguardAgain, MSGBOX_DEFAULT
	release
	end

Route2LifeguardShack_Text_Lifeguard::
	.string "{JPN}おい！ ここに はいっちゃ\n"
	.string "だめだぞ。\p"
	.string "…いや ここに いちゃ いけないのは\n"
	.string "おれの ほうか？\p"
	.string "わけが わからなくなってきた。\p"
	.string "はい これ どうぞ！$"

Route2LifeguardShack_Text_LifeguardAgain::
	.string "{JPN}どっちが ここに いるべきなのか\n"
	.string "まだ わからないんだ。$"
