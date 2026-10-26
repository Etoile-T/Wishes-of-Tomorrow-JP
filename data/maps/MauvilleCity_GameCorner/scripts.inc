MauvilleCity_GameCorner_MapScripts::
	.byte 0

	@ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1500
	.set TM_PSYCHIC_COINS, 3500
	.set TM_FLAMETHROWER_COINS, 4000
	.set TM_THUNDERBOLT_COINS, 4000
	.set TM_ICE_BEAM_COINS, 4000
	.set DOLL_COINS, 1000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

MauvilleCity_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50

MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
MauvilleCity_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

@ =============================================================================
@  WISHES OF TOMORROW -- GAME CORNER PRIZE COUNTERS
@
@  Two counters, both SCROLLING lists (dynmultichoice). A plain multichoice
@  window is sized count*2 tile rows, so anything past about six entries runs
@  off the bottom of the screen -- these tables are 15 and 13 long. Prices are
@  printed inside each row with {CLEAR_TO} so the player can see the whole
@  price list at a glance instead of picking blind.
@
@  Both lists run cheapest first. Coins come out only AFTER the prize is
@  actually handed over, so a full bag or a full party+PC can never charge for
@  nothing. Each purchase returns to the list rather than closing it.
@ =============================================================================

	@ Every prize Pokemon is handed over at this level. They are meant to be
	@ raised -- which is also why the three dragons here suit the 16/36 starter
	@ evolution cadence. Retune them all from this one line.
	.set GAME_CORNER_PRIZE_LEVEL, 5

@ ---- Counter 1: Pokemon ------------------------------------------------------

MauvilleCity_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_OpenMonPrizes
	release
	end

MauvilleCity_GameCorner_EventScript_OpenMonPrizes::
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseMonPrize

MauvilleCity_GameCorner_EventScript_ChooseMonPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, WotText_PrizeGimmighoul, WotText_PrizeCharcadet, WotText_PrizeHonedge, WotText_PrizeToxel, WotText_PrizeGoomy, WotText_PrizeJangmoO, WotText_PrizeGreavard, WotText_PrizeDuraludon, WotText_PrizeDreepy, WotText_PrizeFrigibax, WotText_PrizeGible, WotText_PrizeAxew, WotText_PrizeRotom, WotText_PrizeTypeNull, WotText_PrizePorygon, WotText_PrizeNoThanks
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_PrizeGimmighoul
	case 1, MauvilleCity_GameCorner_EventScript_PrizeCharcadet
	case 2, MauvilleCity_GameCorner_EventScript_PrizeHonedge
	case 3, MauvilleCity_GameCorner_EventScript_PrizeToxel
	case 4, MauvilleCity_GameCorner_EventScript_PrizeGoomy
	case 5, MauvilleCity_GameCorner_EventScript_PrizeJangmoO
	case 6, MauvilleCity_GameCorner_EventScript_PrizeGreavard
	case 7, MauvilleCity_GameCorner_EventScript_PrizeDuraludon
	case 8, MauvilleCity_GameCorner_EventScript_PrizeDreepy
	case 9, MauvilleCity_GameCorner_EventScript_PrizeFrigibax
	case 10, MauvilleCity_GameCorner_EventScript_PrizeGible
	case 11, MauvilleCity_GameCorner_EventScript_PrizeAxew
	case 12, MauvilleCity_GameCorner_EventScript_PrizeRotom
	case 13, MauvilleCity_GameCorner_EventScript_PrizeTypeNull
	case 14, MauvilleCity_GameCorner_EventScript_PrizePorygon
	case 15, MauvilleCity_GameCorner_EventScript_CancelMonSelect
	case MULTI_B_PRESSED, MauvilleCity_GameCorner_EventScript_CancelMonSelect
	end

MauvilleCity_GameCorner_EventScript_PrizeGimmighoul::
	setvar VAR_TEMP_1, SPECIES_GIMMIGHOUL
	setvar VAR_TEMP_2, 999
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeCharcadet::
	setvar VAR_TEMP_1, SPECIES_CHARCADET
	setvar VAR_TEMP_2, 2000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeHonedge::
	setvar VAR_TEMP_1, SPECIES_HONEDGE
	setvar VAR_TEMP_2, 2000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeToxel::
	setvar VAR_TEMP_1, SPECIES_TOXEL
	setvar VAR_TEMP_2, 2000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeGoomy::
	setvar VAR_TEMP_1, SPECIES_GOOMY
	setvar VAR_TEMP_2, 2500
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeJangmoO::
	setvar VAR_TEMP_1, SPECIES_JANGMO_O
	setvar VAR_TEMP_2, 3000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeGreavard::
	setvar VAR_TEMP_1, SPECIES_GREAVARD
	setvar VAR_TEMP_2, 3000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeDuraludon::
	setvar VAR_TEMP_1, SPECIES_DURALUDON
	setvar VAR_TEMP_2, 3000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeDreepy::
	setvar VAR_TEMP_1, SPECIES_DREEPY
	setvar VAR_TEMP_2, 4000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeFrigibax::
	setvar VAR_TEMP_1, SPECIES_FRIGIBAX
	setvar VAR_TEMP_2, 5000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeGible::
	setvar VAR_TEMP_1, SPECIES_GIBLE
	setvar VAR_TEMP_2, 5000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeAxew::
	setvar VAR_TEMP_1, SPECIES_AXEW
	setvar VAR_TEMP_2, 5000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeRotom::
	setvar VAR_TEMP_1, SPECIES_ROTOM
	setvar VAR_TEMP_2, 6500
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeTypeNull::
	setvar VAR_TEMP_1, SPECIES_TYPE_NULL
	setvar VAR_TEMP_2, 8000
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizePorygon::
	setvar VAR_TEMP_1, SPECIES_PORYGON
	setvar VAR_TEMP_2, 9999
	goto MauvilleCity_GameCorner_EventScript_ConfirmMonPrize
	end

MauvilleCity_GameCorner_EventScript_ConfirmMonPrize::
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	msgbox WotText_GameCornerConfirmPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_ChooseMonPrize
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForMon
	@ Porygon is the only prize that arrives holding something.
	goto_if_eq VAR_TEMP_1, SPECIES_PORYGON, MauvilleCity_GameCorner_EventScript_GivePorygonPrize
	givemon VAR_TEMP_1, GAME_CORNER_PRIZE_LEVEL
	goto MauvilleCity_GameCorner_EventScript_CheckReceivedPrizeMon
	end

MauvilleCity_GameCorner_EventScript_GivePorygonPrize::
	givemon SPECIES_PORYGON, GAME_CORNER_PRIZE_LEVEL, item=ITEM_DUBIOUS_DISC
	goto MauvilleCity_GameCorner_EventScript_CheckReceivedPrizeMon
	end

MauvilleCity_GameCorner_EventScript_CheckReceivedPrizeMon::
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_PrizeMonToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_PrizeMonToPC
	@ MON_CANT_GIVE: nothing was created, so charge nothing.
	msgbox gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeMonToParty::
	call MauvilleCity_GameCorner_EventScript_PayAndAnnounceMon
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	call Common_EventScript_NameReceivedPartyMon
	goto MauvilleCity_GameCorner_EventScript_ChooseMonPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeMonToPC::
	call MauvilleCity_GameCorner_EventScript_PayAndAnnounceMon
	msgbox gText_PkmnTransferredSomeonesPC, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseMonPrize
	end

MauvilleCity_GameCorner_EventScript_PayAndAnnounceMon::
	removecoins VAR_TEMP_2
	updatecoinsbox 0, 5
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_OBTAIN_ITEM
	message gText_PlayerObtainedTheMon
	waitmessage
	waitfanfare
	return

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForMon::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseMonPrize
	end

MauvilleCity_GameCorner_EventScript_CancelMonSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

@ ---- Counter 2: TMs and evolution items --------------------------------------

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_OpenGoodsPrizes
	release
	end

MauvilleCity_GameCorner_EventScript_OpenGoodsPrizes::
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseGoodsPrize

MauvilleCity_GameCorner_EventScript_ChooseGoodsPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, WotText_PrizePlayRough, WotText_PrizeScaleShot, WotText_PrizeKnockOff, WotText_PrizeLeadersCrest, WotText_PrizeScorchingSands, WotText_PrizeEarthPower, WotText_PrizeMetalAlloy, WotText_PrizeAuspiciousArmor, WotText_PrizeMaliciousArmor, WotText_PrizeSwordsDance, WotText_PrizeNastyPlot, WotText_PrizeDracoMeteor, WotText_PrizeCloseCombat, WotText_PrizeNoThanks
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_PrizePlayRough
	case 1, MauvilleCity_GameCorner_EventScript_PrizeScaleShot
	case 2, MauvilleCity_GameCorner_EventScript_PrizeKnockOff
	case 3, MauvilleCity_GameCorner_EventScript_PrizeLeadersCrest
	case 4, MauvilleCity_GameCorner_EventScript_PrizeScorchingSands
	case 5, MauvilleCity_GameCorner_EventScript_PrizeEarthPower
	case 6, MauvilleCity_GameCorner_EventScript_PrizeMetalAlloy
	case 7, MauvilleCity_GameCorner_EventScript_PrizeAuspiciousArmor
	case 8, MauvilleCity_GameCorner_EventScript_PrizeMaliciousArmor
	case 9, MauvilleCity_GameCorner_EventScript_PrizeSwordsDance
	case 10, MauvilleCity_GameCorner_EventScript_PrizeNastyPlot
	case 11, MauvilleCity_GameCorner_EventScript_PrizeDracoMeteor
	case 12, MauvilleCity_GameCorner_EventScript_PrizeCloseCombat
	case 13, MauvilleCity_GameCorner_EventScript_CancelGoodsSelect
	case MULTI_B_PRESSED, MauvilleCity_GameCorner_EventScript_CancelGoodsSelect
	end

MauvilleCity_GameCorner_EventScript_PrizePlayRough::
	setvar VAR_TEMP_1, ITEM_TM_PLAY_ROUGH
	setvar VAR_TEMP_2, 3000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeScaleShot::
	setvar VAR_TEMP_1, ITEM_TM_SCALE_SHOT
	setvar VAR_TEMP_2, 3500
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeKnockOff::
	setvar VAR_TEMP_1, ITEM_TM_KNOCK_OFF
	setvar VAR_TEMP_2, 3500
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeLeadersCrest::
	setvar VAR_TEMP_1, ITEM_LEADERS_CREST
	setvar VAR_TEMP_2, 3500
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeScorchingSands::
	setvar VAR_TEMP_1, ITEM_TM_SCORCHING_SANDS
	setvar VAR_TEMP_2, 4000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeEarthPower::
	setvar VAR_TEMP_1, ITEM_TM_EARTH_POWER
	setvar VAR_TEMP_2, 4000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeMetalAlloy::
	setvar VAR_TEMP_1, ITEM_METAL_ALLOY
	setvar VAR_TEMP_2, 4000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeAuspiciousArmor::
	setvar VAR_TEMP_1, ITEM_AUSPICIOUS_ARMOR
	setvar VAR_TEMP_2, 4000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeMaliciousArmor::
	setvar VAR_TEMP_1, ITEM_MALICIOUS_ARMOR
	setvar VAR_TEMP_2, 4000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeSwordsDance::
	setvar VAR_TEMP_1, ITEM_TM_SWORDS_DANCE
	setvar VAR_TEMP_2, 6000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeNastyPlot::
	setvar VAR_TEMP_1, ITEM_TM_NASTY_PLOT
	setvar VAR_TEMP_2, 6000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeDracoMeteor::
	setvar VAR_TEMP_1, ITEM_TM_DRACO_METEOR
	setvar VAR_TEMP_2, 8000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_PrizeCloseCombat::
	setvar VAR_TEMP_1, ITEM_TM_CLOSE_COMBAT
	setvar VAR_TEMP_2, 8000
	goto MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_ConfirmGoodsPrize::
	bufferitemname STR_VAR_1, VAR_TEMP_1
	msgbox WotText_GameCornerConfirmPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_ChooseGoodsPrize
	checkcoins VAR_RESULT
	goto_if_lt VAR_RESULT, VAR_TEMP_2, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForGoods
	checkitemspace VAR_TEMP_1, 1
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForGoods
	additem VAR_TEMP_1, 1
	removecoins VAR_TEMP_2
	updatecoinsbox 0, 5
	bufferitemname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_OBTAIN_ITEM
	message MauvilleCity_GameCorner_Text_HereYouGo
	waitmessage
	waitfanfare
	goto MauvilleCity_GameCorner_EventScript_ChooseGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForGoods::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ChooseGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForGoods::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ChooseGoodsPrize
	end

MauvilleCity_GameCorner_EventScript_CancelGoodsSelect::
	msgbox MauvilleCity_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

@ ---- Prize list rows ---------------------------------------------------------

WotText_PrizeGimmighoul:
	.string "{JPN}コレクレー{CLEAR_TO 0x48}{FONT_SMALL}999コイン$"
WotText_PrizeCharcadet:
	.string "{JPN}カルボウ{CLEAR_TO 0x48}{FONT_SMALL}2000コイン$"
WotText_PrizeHonedge:
	.string "{JPN}ヒトツキ{CLEAR_TO 0x48}{FONT_SMALL}2000コイン$"
WotText_PrizeToxel:
	.string "{JPN}エレズン{CLEAR_TO 0x48}{FONT_SMALL}2000コイン$"
WotText_PrizeGoomy:
	.string "{JPN}ヌメラ{CLEAR_TO 0x48}{FONT_SMALL}2500コイン$"
WotText_PrizeJangmoO:
	.string "{JPN}ジャラコ{CLEAR_TO 0x48}{FONT_SMALL}3000コイン$"
WotText_PrizeGreavard:
	.string "{JPN}ボチ{CLEAR_TO 0x48}{FONT_SMALL}3000コイン$"
WotText_PrizeDuraludon:
	.string "{JPN}ジュラルドン{CLEAR_TO 0x48}{FONT_SMALL}3000コイン$"
WotText_PrizeDreepy:
	.string "{JPN}ドラメシヤ{CLEAR_TO 0x48}{FONT_SMALL}4000コイン$"
WotText_PrizeFrigibax:
	.string "{JPN}セビエ{CLEAR_TO 0x48}{FONT_SMALL}5000コイン$"
WotText_PrizeGible:
	.string "{JPN}フカマル{CLEAR_TO 0x48}{FONT_SMALL}5000コイン$"
WotText_PrizeAxew:
	.string "{JPN}キバゴ{CLEAR_TO 0x48}{FONT_SMALL}5000コイン$"
WotText_PrizeRotom:
	.string "{JPN}ロトム{CLEAR_TO 0x48}{FONT_SMALL}6500コイン$"
WotText_PrizeTypeNull:
	.string "{JPN}タイプ:ヌル{CLEAR_TO 0x48}{FONT_SMALL}8000コイン$"
WotText_PrizePorygon:
	.string "{JPN}ポリゴン{CLEAR_TO 0x48}{FONT_SMALL}9999コイン$"
WotText_PrizePlayRough:
	.string "{JPN}TM54 じゃれつく{CLEAR_TO 0x70}{FONT_SMALL}3000コイン$"
WotText_PrizeScaleShot:
	.string "{JPN}TM53 スケイルショット{CLEAR_TO 0x70}{FONT_SMALL}3500コイン$"
WotText_PrizeKnockOff:
	.string "{JPN}TM59 はたきおとす{CLEAR_TO 0x70}{FONT_SMALL}3500コイン$"
WotText_PrizeLeadersCrest:
	.string "{JPN}かしらのしるし{CLEAR_TO 0x70}{FONT_SMALL}3500コイン$"
WotText_PrizeScorchingSands:
	.string "{JPN}TM57 ねっさのだいち{CLEAR_TO 0x70}{FONT_SMALL}4000コイン$"
WotText_PrizeEarthPower:
	.string "{JPN}TM58 だいちのちから{CLEAR_TO 0x70}{FONT_SMALL}4000コイン$"
WotText_PrizeMetalAlloy:
	.string "{JPN}ふくごうきんぞく{CLEAR_TO 0x70}{FONT_SMALL}4000コイン$"
WotText_PrizeAuspiciousArmor:
	.string "{JPN}イワイノヨロイ{CLEAR_TO 0x70}{FONT_SMALL}4000コイン$"
WotText_PrizeMaliciousArmor:
	.string "{JPN}ノロイノヨロイ{CLEAR_TO 0x70}{FONT_SMALL}4000コイン$"
WotText_PrizeSwordsDance:
	.string "{JPN}TM55 つるぎのまい{CLEAR_TO 0x70}{FONT_SMALL}6000コイン$"
WotText_PrizeNastyPlot:
	.string "{JPN}TM56 わるだくみ{CLEAR_TO 0x70}{FONT_SMALL}6000コイン$"
WotText_PrizeDracoMeteor:
	.string "{JPN}TM51 りゅうせいぐん{CLEAR_TO 0x70}{FONT_SMALL}8000コイン$"
WotText_PrizeCloseCombat:
	.string "{JPN}TM52 インファイト{CLEAR_TO 0x70}{FONT_SMALL}8000コイン$"
WotText_PrizeNoThanks:
	.string "{JPN}やめる$"

WotText_GameCornerConfirmPrize:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}で よろしいですか?$"

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_TryGive20Coins
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, MauvilleCity_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_PokefanMNormal
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "{JPN}ここは キンセツ ゲームコーナーです。$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "{JPN}ゲームで あそぶための コインを\n"
	.string "おもとめですか?\p"
	.string "でも コインを いれるための\n"
	.string "コインケースを おもちで ないですね。$"

MauvilleCity_GameCorner_Text_WereYouLookingForCoins:
	.string "{JPN}コインを おもとめですか?\p"
	.string "50まいで 1000円に なります。\n"
	.string "いかがですか?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "{JPN}ありがとうございます!\n"
	.string "こちらが コインです!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "{JPN}あの… おかねが\n"
	.string "たりないようですが…$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull:
	.string "{JPN}おや?\n"
	.string "コインケースが いっぱいですよ。$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "{JPN}あら… コインは いらないのですか?\n"
	.string "ぼうけん がんばってくださいね!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "{JPN}いらっしゃいませ。\p"
	.string "こちらでは コインを けいひんと\n"
	.string "こうかん できます。$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "{JPN}どの けいひんに なさいますか?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "{JPN}では こちらの\n"
	.string "{ENG}{STR_VAR_1}{JPN} {ENG}{STR_VAR_2}{JPN}ですね?$"

MauvilleCity_GameCorner_Text_SendToYourHomePC:
	.string "{JPN}ありがとうございます!\n"
	.string "ごじたくの パソコンに おおくりします。$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "{JPN}コインが たりません。$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "{JPN}もう おける ばしょが ありません。\n"
	.string "{ENG}{STR_VAR_1}{JPN}は おけません。$"

MauvilleCity_GameCorner_Text_OhIsThatSo:
	.string "{JPN}そうですか。\n"
	.string "コインを ためてから\l"
	.string "また おこしください。$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}で よろしいですか?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "{JPN}どうぞ おうけとりください!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "{JPN}おや これいじょう もてませんよ。$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "{JPN}まちがえて おなじ ぬいぐるみを\n"
	.string "2つ もらっちゃったの。\p"
	.string "ひとつ いらない?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "{JPN}はい どうぞ!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "{JPN}あれ?\n"
	.string "ほしいけど いまは いらないの?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "{JPN}そんな えんりょ しないで!\n"
	.string "これ あげるわ!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "{JPN}ほしい けいひんが あるのに\n"
	.string "おおあたりが でないんだ。$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "{JPN}やあ ここで あそびたいなら\n"
	.string "コインケースが いるぞ。\p"
	.string "ゴミばこを あさってみなよ。\n"
	.string "だれかが すてたのが あるかもな。\p"
	.string "きっと ツキが なかったんだろうな。$"

MauvilleCity_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "{JPN}この ツキも いつまでもは つづかないよ。\n"
	.string "こんなに あっても つかいきれない。\l"
	.string "ほら コインを わけてあげる!$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "{JPN}キンセツには だれでも たのしめる\n"
	.string "なにかが あるの。\p"
	.string "わたしには ゲームコーナーね。$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "{JPN}ルーレットは だいによって\n"
	.string "かける まいすうが ちがうんだ。\p"
	.string "だいを えらぶなら じぶんの コインを\n"
	.string "たしかめて おくといいよ。$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "{JPN}ここに いると つい じかんを わすれるね。\n"
	.string "しごとに もどらなくちゃ。$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "{JPN}この ゲームコーナーで あそぶには\n"
	.string "コインが ひつようだよ。$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "{JPN}この ルーレットって…\n"
	.string "なかなか むずかしいね。\p"
	.string "かつも まけるも うん しだいだよ。$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "{JPN}スロットでは コインを\n"
	.string "3まいまで かけられるよ。$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "{JPN}ぴったり「7」で とめるのって\n"
	.string "すごく むずかしいの。\p"
	.string "リールタイムの ボーナスゲームで\n"
	.string "「7」に とまると コインが ふえるのよ。$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "{JPN}スロットの ことを\n"
	.string "すこし おしえてあげよう。\p"
	.string "カミナリマークを ためるほど\n"
	.string "リールタイムの チャンスが ふえるんだ。\p"
	.string "リールタイムの チャンスが\n"
	.string "さいだいの 5かい ある ゲームなら…\p"
	.string "レギュラーボーナスが 4かいの あとに\n"
	.string "ビッグボーナスが でることも ある。\p"
	.string "あわせて コイン 660まいだが\n"
	.string "ねらうのは とても むずかしいぞ。$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "{JPN}コインケースが ないと\n"
	.string "あそべません。$"

