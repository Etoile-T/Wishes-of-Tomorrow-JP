CeruleanCity_House5_Frlg_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BerryPowderMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POWDER_JAR, CeruleanCity_House5_EventScript_AskToExchangePowder
	msgbox CeruleanCity_House1_Text_AnyInterestInBerries, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_NoInterestInBerries
	goto_if_unset FLAG_SYS_GOT_BERRY_POUCH, CeruleanCity_House5_EventScript_NoBerries
	msgbox CeruleanCity_House1_Text_HaveJustTheThing
	setflag FLAG_GOT_POWDER_JAR
	giveitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner
	release
	end

CeruleanCity_House5_EventScript_NoBerries::
	msgbox CeruleanCity_House1_Text_WhyMustYouLieNoBerries
	release
	end

CeruleanCity_House5_EventScript_NoInterestInBerries::
	msgbox CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings
	release
	end

CeruleanCity_House5_EventScript_AskToExchangePowder::
	special DisplayBerryPowderVendorMenu
	msgbox CeruleanCity_House1_Text_HaveYouBroughtBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_ChooseExchangeItem::
	message CeruleanCity_House5_Text_ExchangeWithWhat
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House5_EventScript_EnergyPowder
	case 1, CeruleanCity_House5_EventScript_EnergyRoot
	case 2, CeruleanCity_House5_EventScript_HealPowder
	case 3, CeruleanCity_House5_EventScript_RevivalHerb
	case 4, CeruleanCity_House5_EventScript_Protein
	case 5, CeruleanCity_House5_EventScript_Iron
	case 6, CeruleanCity_House5_EventScript_Carbos
	case 7, CeruleanCity_House5_EventScript_Calcium
	case 8, CeruleanCity_House5_EventScript_Zinc
	case 9, CeruleanCity_House5_EventScript_HPUp
	case 10, CeruleanCity_House5_EventScript_PPUp
	case 11, CeruleanCity_House5_EventScript_ExitMenu
	case 127, CeruleanCity_House5_EventScript_ExitMenu
	end

CeruleanCity_House5_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_ExitMenu::
	msgbox CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_ExchangePowderForItem::
	msgbox CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_ChooseExchangeItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_BagIsFull
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox CeruleanCity_House1_Text_TradeMoreBerryPowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeruleanCity_House5_EventScript_ChooseExchangeItem
	msgbox CeruleanCity_House1_Text_HopeToSeeYouAgain
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_BagIsFull::
	msgbox gText_TheBagIsFull
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_NotEnoughBerryPowder::
	msgbox CeruleanCity_House1_Text_DontHaveEnoughBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_BerryCrushRankings::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

CeruleanCity_House1_Text_AnyInterestInBerries::
	.string "{JPN}わしは きのみパウダーから\n"
	.string "いろんな くすりを つくっておる。\p"
	.string "よい きのみパウダーが あれば\n"
	.string "どんな くすりでも つくれるぞ。\p"
	.string "ところで おまえさん きのみに\n"
	.string "きょうみは あるかね?$"

CeruleanCity_House1_Text_HaveJustTheThing::
	.string "{JPN}おお よかった! では おまえさんに\n"
	.string "ぴったりの ものが あるぞ。$"

CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner::
	.string "{JPN}ポケモンセンターの 2かい\n"
	.string "ダイレクトコーナーに\l"
	.string "あたらしい ものが できたんじゃ。\p"
	.string "ワイヤレスアダプタで つかう\n"
	.string "きのみを くだく きかいじゃよ。\p"
	.string "そこで おまえさんの でばんじゃ。\p"
	.string "おまえさんにしか たのめない\n"
	.string "おねがいが あるんじゃ。\p"
	.string "その きかいで きのみパウダーを\n"
	.string "つくって きて くれんか?\p"
	.string "きかいは ポケモンセンターの\n"
	.string "ダイレクトコーナーに あるからの。\p"
	.string "きのみパウダーを もってきたら\n"
	.string "くすりを つくって あげよう。\p"
	.string "わすれるな きのみを くだいて\n"
	.string "きのみパウダーを もってくるんじゃ。$"

CeruleanCity_House1_Text_WhyMustYouLieNoBerries::
	.string "{JPN}なぜ うそを つくんじゃ?\p"
	.string "きのみを いくつ もっておる?\n"
	.string "ひとつも ないでは ないか!$"

CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings::
	.string "{JPN}きのみに きょうみが ないのかね?\p"
	.string "わかいの なんにでも きょうみを\n"
	.string "もつことが たいせつじゃぞ。$"

CeruleanCity_House1_Text_HaveYouBroughtBerryPowder::
	.string "{JPN}オホン! きのみパウダーを\n"
	.string "もってきて くれたかね?$"

CeruleanCity_House5_Text_ExchangeWithWhat::
	.string "{JPN}なにと\n"
	.string "こうかん するかね?$"

CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem::
	.string "{JPN}では きのみパウダーを\n"
	.string "{ENG}{STR_VAR_1}{JPN} 1こと こうかんじゃな?$"

CeruleanCity_House1_Text_DontHaveEnoughBerryPowder::
	.string "{JPN}ん? きのみパウダーが\n"
	.string "たりないようじゃな。$"

CeruleanCity_House1_Text_TradeMoreBerryPowder::
	.string "{JPN}じつに よい きのみパウダーじゃ。\n"
	.string "よい くすりが できるぞ。\p"
	.string "もっと きのみパウダーを ほかの\n"
	.string "ものと こうかん するかね?$"

CeruleanCity_House1_Text_HopeToSeeYouAgain::
	.string "{JPN}そうか では\n"
	.string "また きて くれるのを まっておるよ。$"

CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder::
	.string "{JPN}きのみパウダーを こうかん したく\n"
	.string "なったら また きなさい。$"

