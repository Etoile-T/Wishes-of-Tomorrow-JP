CeruleanCity_BikeShop_Frlg_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
	goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
	waitmessage
	multichoice 11, 0, MULTI_BIKE_SHOP, FALSE
	hidemoneybox
	showmoneybox 0, 0
	switch VAR_RESULT
	case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
	case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	case 127, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

@ The Bicycle price / players money is never actually checked
CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
	msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt
	goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	hidemoneybox
	release
	end

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
	msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo
	msgreceiveditem CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle, ITEM_BICYCLE, 1, MUS_RG_OBTAIN_KEY_ITEM
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	removeitem ITEM_BIKE_VOUCHER
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	release
	end

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle
	release
	end

@ Unused
CeruleanCity_BikeShop_EventScript_NoRoomForBicycle::
	msgbox CeruleanCity_BikeShop_Text_MakeRoomForBicycle
	release
	end

CeruleanCity_BikeShop_EventScript_Woman::
	msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
	end

CeruleanCity_BikeShop_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
	msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive
	release
	end

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
	msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool
	release
	end

CeruleanCity_BikeShop_EventScript_Bicycle::
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
	.string "{JPN}いらっしゃい!\n"
	.string "じてんしゃやへ ようこそ。\p"
	.string "あなたに ぴったりの じてんしゃが\n"
	.string "ありますよ!$"

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
	.string "{JPN}ごめんなさい!\n"
	.string "おかねが たりませんね!$"

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
	.string "{JPN}おや それは…\p"
	.string "ひきかえけん!\p"
	.string "わかりました!\n"
	.string "どうぞ!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ひきかえけんを\n"
	.string "じてんしゃと こうかん した!$"

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
	.string "{JPN}ありがとう ございました!\n"
	.string "また きてくださいね!$"

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
	.string "{JPN}あたらしい じてんしゃは どうですか?\n"
	.string "のりごこちは いいですか?\p"
	.string "サイクリングロードにも どうくつにも\n"
	.string "のって いけますよ!$"

CeruleanCity_BikeShop_Text_MakeRoomForBicycle::
	.string "{JPN}じてんしゃを もつ よゆうを\n"
	.string "つくって くださいね!$"

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
	.string "{JPN}わたしには ふつうの ママチャリで\n"
	.string "じゅうぶん。\p"
	.string "だって マウンテンバイクには\n"
	.string "かいものかごが つけられないもの。$"

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
	.string "{JPN}この じてんしゃ かっこいいけど\n"
	.string "めちゃくちゃ たかい!$"

CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
	.string "{JPN}うわあ。\n"
	.string "きみの じてんしゃ かっこいいね!$"

@ Unused
CeruleanCity_BikeShop_Text_GermanFoldableBicyleFinallyOnMarket::
	.string "{JPN}ついに はつばい!\p"
	.string "ドイツ せい さいこうきゅう\n"
	.string "おりたたみ じてんしゃ!$"

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
	.string "{JPN}ピカピカの しんぴんの じてんしゃだ!$"

