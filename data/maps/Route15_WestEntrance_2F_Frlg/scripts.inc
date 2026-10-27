.equ REQUIRED_CAUGHT_MONS, 50

Route15_WestEntrance_2F_Frlg_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	lockall
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ARTICUNO
	special SetSeenMon
	releaseall
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE, Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare
	msgbox Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route15_WestEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route15_WestEntrance_2F_Text_ReceivedItemFromAide, ITEM_EXP_SHARE
	setflag FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare::
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_EXP_SHARE
	return

Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough::
	.string "{JPN}こんにちは! おぼえてますか?\n"
	.string "オーキドはかせの じょしゅです\p"
	.string "ずかんに ポケモンの データが\n"
	.string "{ENG}{STR_VAR_1}{JPN}しゅるい そろっていたら\l"
	.string "ごほうびを わたす ことに なってます\p"
	.string "はかせから あなたに わたす\n"
	.string "{ENG}{STR_VAR_2}{JPN}を あずかっています\p"
	.string "では {ENG}{PLAYER}{JPN}さん おききします\p"
	.string "ポケモンを すくなくとも\n"
	.string "{ENG}{STR_VAR_1}{JPN}しゅるい しらべましたか?$"

Route15_WestEntrance_2F_Text_GreatHereYouGo::
	.string "{JPN}すばらしい! つかまえたり てにいれた\n"
	.string "ポケモンは {ENG}{STR_VAR_3}{JPN}しゅるいですね!\p"
	.string "おめでとう ございます!\n"
	.string "どうぞ!$"

Route15_WestEntrance_2F_Text_ReceivedItemFromAide::
	.string "{JPN}{ENG}{PLAYER}{JPN}は {ENG}{STR_VAR_2}{JPN}を\n"
	.string "じょしゅから もらった!$"

Route15_WestEntrance_2F_Text_ExplainExpShare::
	.string "{JPN}がくしゅうそうちは ポケモンに\n"
	.string "もたせる どうぐです\p"
	.string "もたせた ポケモンは たたかわなくても\n"
	.string "けいけんちを\l"
	.string "わけて もらえるんです$"

Route15_WestEntrance_2F_Text_LargeShiningBird::
	.string "{JPN}ぼうえんきょうで\n"
	.string "なにが みえるかな…\p"
	.string "おおきな かがやく とりが\n"
	.string "うみの ほうへ とんでいく$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
	.string "{JPN}ぼうえんきょうで\n"
	.string "なにが みえるかな…\p"
	.string "すいへいせんに ちいさな しまが\n"
	.string "みえる!$"

