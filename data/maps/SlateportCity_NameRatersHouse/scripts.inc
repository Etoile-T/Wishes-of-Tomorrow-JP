SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "{JPN}やあ やあ! わしは せいめいはんだんし!\n"
	.string "なまえの うらないし じゃ!\p"
	.string "きみの ポケモンの ニックネームを\n"
	.string "よろこんで みてあげよう。$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "{JPN}どの ポケモンの\n"
	.string "ニックネームを うらなうかね?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "{JPN}ふむふむ… {ENG}{STR_VAR_1}{JPN}かね?\n"
	.string "なかなか いい なまえを つけたな。\p"
	.string "だが! もうすこし いい なまえを\n"
	.string "わしが かんがえて みるのは どうかね?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "{JPN}そうか では\n"
	.string "あたらしい ニックネームは なにに するかね?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "{JPN}よし これから\n"
	.string "この ポケモンは {ENG}{STR_VAR_1}{JPN}だ!\p"
	.string "まえより いい なまえ じゃないか\n"
	.string "よかったな!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "{JPN}そうか\n"
	.string "わかった また きなさいよ。$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "{JPN}よし! これから この ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}と よぶことに しよう!\p"
	.string "まえと おなじに みえても\n"
	.string "はるかに よくなったぞ!\p"
	.string "よかったな!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "{JPN}ふむふむ… {ENG}{STR_VAR_1}{JPN}か!\p"
	.string "すばらしい ニックネームじゃ!\n"
	.string "もんくの つけようも ないぞ!\p"
	.string "いまも これからも きみの\n"
	.string "{ENG}{STR_VAR_1}{JPN}を だいじに するが いい。$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "{JPN}おいおい……\n"
	.string "それは タマゴ じゃないか!$"

