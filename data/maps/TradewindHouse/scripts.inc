@ Tradewind house -- the widow who stays for the market.
TradewindHouse_MapScripts::
	.byte 0

TradewindHouse_EventScript_Widow::
	lock
	faceplayer
	msgbox TradewindHouse_Text_Widow, MSGBOX_DEFAULT
	release
	end

TradewindHouse_Text_Widow::
	.string "{JPN}みんな きくのよ。 どうして\n"
	.string "こんな まちに すんでいるのかって。\p"
	.string "おっとが よいちで みせを だしているの。\n"
	.string "もう なんねんもね。\p"
	.string "…12ねん まえに\n"
	.string "なくなったんだけれどね。\p"
	.string "いちども ねあげを していないのよ。$"
