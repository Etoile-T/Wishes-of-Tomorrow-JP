.equ REQUIRED_CAUGHT_MONS, 40

Route16_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE, Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin
	msgbox Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route16_NorthEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide, ITEM_AMULET_COIN
	setflag FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin::
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_AMULET_COIN
	return

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
	.string "{JPN}かのじょと あたらしい じてんしゃで\n"
	.string "のんびり サイクリング ちゅうさ$"

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
	.string "{JPN}あたらしい じてんしゃで\n"
	.string "いっしょに サイクリング するの$"

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
	.string "{JPN}ぼうえんきょうで\n"
	.string "なにが みえるかな…\p"
	.string "タマムシデパートだ!$"

Route16_NorthEntrance_2F_Text_LongPathOverWater::
	.string "{JPN}ぼうえんきょうで\n"
	.string "なにが みえるかな…\p"
	.string "とおくに うみの うえを とおる\n"
	.string "ながい みちが ある$"

Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40::
	.string "{JPN}こんにちは! おぼえてますか?\n"
	.string "オーキドはかせの じょしゅです\p"
	.string "ずかんに 40しゅるいの\n"
	.string "データが そろっていたら\l"
	.string "ごほうびを わたす ことに なってます\p"
	.string "はかせから あなたに わたす\n"
	.string "おまもりこばんを あずかっています\p"
	.string "では {ENG}{PLAYER}{JPN}さん おききします\p"
	.string "ポケモンを すくなくとも\n"
	.string "40しゅるい しらべましたか?$"

Route16_NorthEntrance_2F_Text_GreatHereYouGo::
	.string "{JPN}すばらしい! つかまえたり てにいれた\n"
	.string "ポケモンは {ENG}{STR_VAR_3}{JPN}しゅるいですね!\p"
	.string "おめでとう ございます!\n"
	.string "どうぞ!$"

Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide::
	.string "{JPN}{ENG}{PLAYER}{JPN}は じょしゅから\n"
	.string "おまもりこばんを もらった!$"

Route16_NorthEntrance_2F_Text_ExplainAmuletCoin::
	.string "{JPN}おまもりこばんは ポケモンに\n"
	.string "もたせる どうぐです\p"
	.string "もたせた ポケモンが でて しょうぶに かつと\n"
	.string "もらえる おかねが ふえるんです$"

