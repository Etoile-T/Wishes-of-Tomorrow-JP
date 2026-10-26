MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_HARBOR_MAIL
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "{JPN}じてんしゃが あれば カイナまで\n"
	.string "かいものに いくのも らくなのに。\p"
	.string "そして カイナの フレンドリィショップで\n"
	.string "ハーバーメールを かえるのに……$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "{JPN}それ! ハーバーメールでしょ!\n"
	.string "コインケースと こうかん してくれない?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "{JPN}うれしい!\n"
	.string "じゃ コインケースと こうかんね!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "{JPN}その コインケースは\n"
	.string "ゲームコーナーで つかえるわ。$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "{JPN}あら ざんねんだわ。\p"
	.string "ゲームコーナーには\n"
	.string "コインケースが ひつようなのよ。$"

