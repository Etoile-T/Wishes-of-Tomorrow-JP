LavenderTown_House2_Frlg_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseMon
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	goto_if_lt VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_CheckCanRateMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseNewNickname
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
	.string "{JPN}やあ やあ!\n"
	.string "わしは せいめいはんだんし!\p"
	.string "きみの ポケモンの ニックネームを\n"
	.string "うらなって あげようか?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
	.string "{JPN}どの ポケモンの ニックネームを\n"
	.string "みて あげようか?$"

LavenderTown_House2_Text_GiveItANicerName::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN} というのか?\n"
	.string "なかなか いい ニックネームだ!\p"
	.string "だが もっと いい なまえを\n"
	.string "つけて あげようか?\p"
	.string "どうする?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
	.string "{JPN}よし。 では あたらしい\n"
	.string "ニックネームは なんに する?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
	.string "{JPN}よし! これから この ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}と なのるのだ!\p"
	.string "まえよりも いい なまえだ!\n"
	.string "よかったな!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
	.string "{JPN}そうか。\n"
	.string "また おいで。$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
	.string "{JPN}よし! これから この ポケモンは\n"
	.string "{ENG}{STR_VAR_1}{JPN}と なのるのだ!\p"
	.string "まえと かわらない ように みえるが\n"
	.string "じつは はるかに すばらしい!\p"
	.string "よかったな!$"

LavenderTown_House2_Text_TrulyImpeccableName::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN} というのか?\n"
	.string "じつに かんぺきな なまえだ!\p"
	.string "{ENG}{STR_VAR_1}{JPN}を だいじに するんだぞ!$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
	.string "{JPN}これこれ。\n"
	.string "それは ただの タマゴじゃ!$"

