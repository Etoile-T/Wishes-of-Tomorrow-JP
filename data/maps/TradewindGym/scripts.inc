@ Tradewind Gym -- the Lantern Gym hall (Dewford gym layout). Madam Tsuji and
@ her procession hold the trial inside: Goro, the Lantern Bearer, and the
@ Apprentice stand along the winding path, Tsuji waits at the far shrine.
@ Their battle scripts live in TradewindTown/scripts.inc (labels are global);
@ Tsuji requires all three defeated before she will fight.
TradewindGym_MapScripts::
	.byte 0

TradewindGym_EventScript_Acolyte::
	lock
	faceplayer
	msgbox TradewindGym_Text_Acolyte, MSGBOX_DEFAULT
	release
	end

TradewindGym_EventScript_Meditant::
	lock
	faceplayer
	msgbox TradewindGym_Text_Meditant, MSGBOX_DEFAULT
	release
	end

TradewindGym_Text_Acolyte::
	.string "{JPN}ランタンジムへ ようこそ。\n"
	.string "ちょうせんしゃよ。\p"
	.string "みちの ほのおを まもるのは 3にん。\n"
	.string "こぶしに ランタン\l"
	.string "そして でし。\p"
	.string "3つとも けせば ツジふじんが\n"
	.string "おくの ほこらで\l"
	.string "しれんを あたえてくださる。\p"
	.string "あかりの あいだの やみに きをつけよ。\n"
	.string "やみも おまえに きを むけている。$"

TradewindGym_Text_Meditant::
	.string "{JPN}…この ひろまの ランタンには それぞれ\n"
	.string "なまえが ある。 ひが きえたら\l"
	.string "1じかん いないに ともしなおす。\p"
	.string "いちどだけ 1つ みおとした。\p"
	.string "109ばんめの ランタンについては\n"
	.string "くちに しないことに なっている。$"
