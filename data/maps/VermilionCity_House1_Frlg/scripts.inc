VermilionCity_House1_Frlg_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
	release
	end

VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
	.string "{JPN}わしは つりの めいじん!\p"
	.string "つりが だーいすき なんじゃ!\n"
	.string "つりなしでは いられん。\p"
	.string "ところで おまえさん つりは すきか?$"

VermilionCity_House1_Text_TakeThisAndFish::
	.string "{JPN}すばらしい! きにいった!\n"
	.string "わしらは なかよく なれそうじゃ。\p"
	.string "これで つりを するが よい!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
	.string "{JPN}{ENG}{PLAYER}{JPN}は つりの めいじんから\n"
	.string "ボロのつりざおを もらった!$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
	.string "{JPN}つりは じんせい そのもの!\n"
	.string "さいこうの しの ようなものじゃ。\p"
	.string "うみでも かわでも でかけて いって\n"
	.string "おおものを つりあげるのじゃぞ。$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
	.string "{JPN}そうか…\n"
	.string "ざんねんじゃのう…$"

VermilionCity_House1_Text_HowAreTheFishBiting::
	.string "{JPN}おお {ENG}{PLAYER}{JPN}!\p"
	.string "つりの ちょうしは どうじゃ?$"

VermilionCity_House1_Text_NoRoomForNiceGift::
	.string "{JPN}おや!\p"
	.string "いい ものを やろうと おもったが\n"
	.string "もちきれん ようじゃな!$"

