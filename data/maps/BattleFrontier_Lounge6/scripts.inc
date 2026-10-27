BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_MEOWTH, BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, BattleFrontier_Lounge6_EventScript_DeclineTrade, BattleFrontier_Lounge6_EventScript_NotRequestedMon, BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "{JPN}わたしの ポケモンは {ENG}{STR_VAR_2}{JPN}です。\n"
	.string "しってますか?\l"
	.string "とても かわいくて いいこなんですよ。\p"
	.string "このこなら じしんを もって\n"
	.string "こうかん できます!\p"
	.string "あなたの {ENG}{STR_VAR_1}{JPN}と わたしの\n"
	.string "{ENG}{STR_VAR_2}{JPN}を こうかん しませんか?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "{JPN}まあ かわいい!\n"
	.string "ありがとう!\l"
	.string "だいじに しますね!\p"
	.string "あなたも わたしの\n"
	.string "{ENG}{STR_VAR_2}{JPN}を だいじに してくださいね!$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "{JPN}あ ごめんなさい!\n"
	.string "わたしが こうかん したいのは\l"
	.string "{ENG}{STR_VAR_1}{JPN}だけ なんです。$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "{JPN}あ やめますか!\n"
	.string "べつに いいですよ\l"
	.string "また こんど きてくださいー$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "{JPN}うふふ!\n"
	.string "エネコが おもってたより ずっと\l"
	.string "かわいくて ほんと うれしいですー$"
