SafariZone_SecretHouse_Frlg_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM03, SafariZone_SecretHouse_EventScript_ExplainSurf
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	giveitem_msg SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant, ITEM_HM03
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_GOT_HM03
	release
	end

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_EventScript_ExplainSurf::
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
	.string "{JPN}ああ! ついに!\p"
	.string "かくれやに たどりついたのは\n"
	.string "あなたが はじめてです!\p"
	.string "グランドオープンの きねんに\n"
	.string "キャンペーンを はじめたのに\p"
	.string "だれも けいひんを もらいに\n"
	.string "こないかと しんぱい してたんです。\p"
	.string "おめでとう ございます!\n"
	.string "あなたの かちです!$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
	.string "{JPN}{ENG}{PLAYER}{JPN}は かかりいんから\n"
	.string "ひでんマシン03を もらった!$"

SafariZone_SecretHouse_Text_ExplainSurf::
	.string "{JPN}ひでんマシン03は なみのり です。\p"
	.string "ポケモンが あなたを のせて\n"
	.string "みずの うえを わたって くれます。\p"
	.string "それに ひでんマシンは なくならないので\n"
	.string "なんどでも つかえますよ。\p"
	.string "こんな すてきな けいひんを もらえて\n"
	.string "とっても ラッキーですね!$"

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
	.string "{JPN}すてきな けいひんを いれる\n"
	.string "ばしょが ありませんよ!$"

