MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "{JPN}おやおや? これは また\n"
	.string "ずいぶん げんきな おきゃくさんだ!\p"
	.string "わたし? ミスターカゼノと よんでくれ。\n"
	.string "この サイクルショップの オーナーさ。$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "{JPN}カゼノ: きみの ランニングシューズ…\n"
	.string "ずいぶん よごれているね。\p"
	.string "とおくから やってきたのかい?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "{JPN}カゼノ: そうなのかい?\p"
	.string "それなら うちの じてんしゃは\n"
	.string "ひつよう なさそうだね。$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "{JPN}カゼノ: ふむ ふむ… … … … …\p"
	.string "ミシロから はるばる\n"
	.string "ここまで きたというのかい?\p"
	.string "なんと!\n"
	.string "とんでもなく とおいじゃないか!\p"
	.string "うちの じてんしゃが あれば\n"
	.string "やさしく なでる かぜを かんじながら\l"
	.string "どこへでも らくに いけるよ!\p"
	.string "よし こうしよう!\n"
	.string "きみに じてんしゃを あげよう!\p"
	.string "おっと ちょっと まった!\p"
	.string "じてんしゃは 2しゅるい あると\n"
	.string "いいわすれて いたね!\p"
	.string "マッハじてんしゃと\n"
	.string "ダートじてんしゃ だよ!\p"
	.string "マッハじてんしゃは からだいっぱいに\n"
	.string "かぜを かんじたい ひと むき!\p"
	.string "そして ダートじてんしゃは\n"
	.string "テクニックを たのしみたい ひと むき!\p"
	.string "わたしは とっても やさしいから\n"
	.string "すきな ほうを あげるよ!\p"
	.string "どっちに するかい?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{JPN}{ENG}{PLAYER}{JPN}は\nマッハじてんしゃを えらんだ。$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{JPN}{ENG}{PLAYER}{JPN}は\nダートじてんしゃを えらんだ。$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "{JPN}カゼノ: じてんしゃを かえたく なったら\n"
	.string "わたしに あいに きてくれ!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "{JPN}カゼノ: おや? ちがう タイプの\n"
	.string "じてんしゃに のりかえたく なったのかな?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "{JPN}カゼノ: よし おやすい ごようだ!\n"
	.string "じてんしゃを こうかん してあげよう!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{JPN}{ENG}{PLAYER}{JPN}は マッハじてんしゃを\n"
	.string "ダートじてんしゃに かえてもらった!$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{JPN}{ENG}{PLAYER}{JPN}は ダートじてんしゃを\n"
	.string "マッハじてんしゃに かえてもらった!$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "{JPN}カゼノ: そうか そうか!\n"
	.string "きにいってくれて うれしいぞ!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "{JPN}……おや?\n"
	.string "きみに あげた じてんしゃ どうした?\p"
	.string "そうか パソコンに あずけてあるのか\p"
	.string "パソコンから とりだして もってきたら\n"
	.string "こうかんして あげる からな!\p"
	.string "きみの ぼうけんに……\n"
	.string "おいかぜが ふくことを いのってるよ!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "{JPN}ここで はたらきながら\n"
	.string "じてんしゃの べんきょうを してるんだ。\p"
	.string "じてんしゃの のりかたを しりたかったら\n"
	.string "おくに せつめいしょが\l"
	.string "2さつ あるよ。$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "{JPN}マッハじてんしゃの せつめいしょだ。\p"
	.string "どの ページを よみますか?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "{JPN}じてんしゃは じゅうじキーを\n"
	.string "おした ほうこうに すすみます。\p"
	.string "はしりだすと スピードが あがります。\p"
	.string "とまるには じゅうじキーを はなします。\n"
	.string "スピードが おちて とまります。\p"
	.string "べつの ページを よみますか?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "{JPN}マッハじてんしゃは はやいですが\n"
	.string "すぐには とまれません。\p"
	.string "そのため カーブを まがるには\n"
	.string "すこし コツが いります。\p"
	.string "カーブの すこし てまえで\n"
	.string "じゅうじキーを はなし げんそくします。\p"
	.string "べつの ページを よみますか?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "{JPN}ホウエンちほうには ところどころに\n"
	.string "ちいさな すなのさかが あります!\p"
	.string "そこは すなが くずれやすい ために\n"
	.string "ふつうは のぼることが できませんが\p"
	.string "マッハじてんしゃに のっていれば\n"
	.string "のぼることが できるのです!\p"
	.string "……べつの ページを よみますか?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "{JPN}ダートじてんしゃの せつめいしょだ。\p"
	.string "どの ページを よみますか?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "{JPN}はしりながら Bボタンを おすと\n"
	.string "まえの タイヤが もちあがります。\p"
	.string "じゅうじキーを つかえば そのまま\n"
	.string "タイヤを あげて はしれます。\p"
	.string "この わざを ウィリーと いいます。\p"
	.string "べつの ページを よみますか?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "{JPN}Bボタンを おしつづけると\n"
	.string "そのばで ホッピングが できます。\p"
	.string "この わざを バニーホップと いいます。\p"
	.string "ホッピングしながら すすむことも できます。\p"
	.string "べつの ページを よみますか?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "{JPN}Bボタンと じゅうじキーを\n"
	.string "どうじに おすと ジャンプします。\p"
	.string "じゅうじキーを よこに おせば\n"
	.string "よこに ジャンプします。\p"
	.string "うしろに おすと ジャンプしながら\n"
	.string "じてんしゃの むきを かえられます。\p"
	.string "べつの ページを よみますか?$"

