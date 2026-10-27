PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_HORSEA, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	msgbox PacifidlogTown_House3_Text_IsThatAPokedex, MSGBOX_NPC
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "{JPN}この {ENG}{STR_VAR_2}{JPN}を みてよ!\p"
	.string "きのう つかまえた {ENG}{STR_VAR_2}{JPN}なんだ!\n"
	.string "たんじょうびの きねんに ね!\p"
	.string "おっ ほしそうな かおしてるね!\n"
	.string "なにしろ かけがえのない ポケモンだもん!\p"
	.string "そうだなあ…… もしかしたら\n"
	.string "{ENG}{STR_VAR_1}{JPN}と こうかん してもいいかも。$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "{JPN}へえ これが {ENG}{STR_VAR_1}{JPN}?\p"
	.string "{ENG}{STR_VAR_2}{JPN}に にてるけど\n"
	.string "びみょうに ちがうんだね。\p"
	.string "ありがとう!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "{JPN}ちがう ちがう! ほんものの\n"
	.string "{ENG}{STR_VAR_1}{JPN}じゃないと だめだよ!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "{JPN}あれ? こうかん\n"
	.string "しないの?\p"
	.string "べつに いいよ。どうしても こうかん\n"
	.string "したい わけじゃ ないし。$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "{JPN}じぶんで さがしに いけば\n"
	.string "いいんだけど……\p"
	.string "ほかの トレーナーが つかまえた\n"
	.string "タツベイが ほしかったんだよね……$"

PacifidlogTown_House3_Text_IsThatAPokedex:
	.string "{JPN}それって ポケモンずかん?\p"
	.string "それって あなた たくさんの\n"
	.string "ポケモンと であった ってこと?\p"
	.string "それって すっごい うらやましい!$"

