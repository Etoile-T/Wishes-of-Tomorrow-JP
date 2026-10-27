FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PLUSLE, FortreeCity_House1_Text_YouWillTradeWontYou, FortreeCity_House1_EventScript_DeclineTrade, FortreeCity_House1_EventScript_NotRequestedMon, FortreeCity_House1_Text_MonYouTakeCare
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "{JPN}うおおおおー! ほしいー!\n"
	.string "{ENG}{STR_VAR_1}{JPN}が どうしても ほしいー!\l"
	.string "そのためなら なんでも するぞー!\p"
	.string "……あ…… いまの きいた?\n"
	.string "おれの こころの そこからの さけび\p"
	.string "それを きいたからには\n"
	.string "{ENG}{STR_VAR_1}{JPN}と {ENG}{STR_VAR_2}{JPN}の\l"
	.string "こうかん してくれるよね?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "{JPN}おー やったー!\p"
	.string "{ENG}{STR_VAR_1}{JPN} よくきたなー!\n"
	.string "{ENG}{STR_VAR_2}{JPN} げんきで やれよー!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "{JPN}いや ちがうでしょ\n"
	.string "それ {ENG}{STR_VAR_1}{JPN}じゃないでしょ$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "{JPN}え? こうかん しないの?\n"
	.string "こころの さけびを きいたくせに……$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "{JPN}これから バルビートを\n"
	.string "めちゃくちゃ つよく するぞ!\p"
	.string "きみも プラスルを つよくしてね!$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "{JPN}ひとと ポケモンを こうかん する……\p"
	.string "つまりは じぶんの おもいでを\n"
	.string "ひとと こうかん しているのじゃな$"

FortreeCity_House1_Text_Zigzagoon:
	.string "{JPN}ジグザグマ: グモモォ?$"

