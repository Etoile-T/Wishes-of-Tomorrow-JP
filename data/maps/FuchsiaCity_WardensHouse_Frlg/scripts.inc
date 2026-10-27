FuchsiaCity_WardensHouse_Frlg_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	call EventScript_RestorePrevTextColor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksMale
	call_if_eq VAR_RESULT, FEMALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale
	giveitem_msg FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden, ITEM_HM04
	setflag FLAG_GOT_HM04
	removeitem ITEM_GOLD_TEETH
	release
	end

FuchsiaCity_WardensHouse_EventScript_WardenThanksMale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
	.string "{JPN}えんちょう: ふぁふ ふふ ふぇふぃふー!\p"
	.string "ふぁ ほふ ふぁ ふぃーふ ふぁふぁひ ほ。\n"
	.string "ふぇっふ ひー ふぃー!$"

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
	.string "{JPN}ふぁ ほうふぃ ほ ほー!\n"
	.string "いーふ い ふぁふぁひ ほ!$"

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
	.string "{JPN}ふぁ?\n"
	.string "ふぇ おふぇい ふぇ ふぁ ふー い ふぁふぇ!$"

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
	.string "{JPN}{ENG}{PLAYER}{JPN}は えんちょうに\n"
	.string "きんのいればを わたした!$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
	.string "{JPN}えんちょうは いればを はめた!$"

FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething::
	.string "{JPN}えんちょう: ありがとうよ ぼうず!\n"
	.string "ほんとうに たすかったわい!\p"
	.string "わしの いうことが だーれも\n"
	.string "ひとことも わからんかったんじゃ!\p"
	.string "はずかしくて じむしょにも\n"
	.string "かおを だせんかった くらいじゃ。\p"
	.string "おれいに いいものを\n"
	.string "あげよう。$"

FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething::
	.string "{JPN}えんちょう: ありがとうよ おじょうちゃん!\n"
	.string "ほんとうに たすかったわい!\p"
	.string "わしの いうことが だーれも\n"
	.string "ひとことも わからんかったんじゃ!\p"
	.string "はずかしくて じむしょにも\n"
	.string "かおを だせんかった くらいじゃ。\p"
	.string "おれいに いいものを\n"
	.string "あげよう。$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
	.string "{JPN}{ENG}{PLAYER}{JPN}は えんちょうから\n"
	.string "ひでんマシン04を もらった!$"

FuchsiaCity_WardensHouse_Text_ExplainStrength::
	.string "{JPN}えんちょう: ひでんマシン04の なかみは\n"
	.string "かいりきじゃ。\p"
	.string "せんとう いがいで ポケモンが\n"
	.string "おおきな いわを うごかせるぞ。\p"
	.string "そうそう サファリゾーンの\n"
	.string "ひみつのいえは みつけたかね?$"

@ Unused
FuchsiaCity_WardensHouse_Text_YouHaveTooMuchStuff::
	.string "{JPN}なんや にもつ\n"
	.string "いっぱいやんけ!$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
	.string "{JPN}ポケモンの しゃしんと かせきが\n"
	.string "かざってある。$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
	.string "{JPN}むかしの ポケモングッズが\n"
	.string "かざってある。$"

