Route12_FishingHouse_Frlg_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	additem ITEM_SUPER_ROD
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	msgreceiveditem Route12_FishingHouse_Text_ReceivedSuperRod, ITEM_SUPER_ROD
	setflag FLAG_GOT_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXInchesTakeThis
	giveitem ITEM_NET_BALL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXInches
	releaseall
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
	.string "{JPN}わたしは つりめいじんの\n"
	.string "おとうとだ\p"
	.string "とにかく つりが だいすきでね!\n"
	.string "つりなしでは いられないのだ\p"
	.string "ところで きみは つりは すきかね?$"

Route12_FishingHouse_Text_TakeThisAndFish::
	.string "{JPN}すばらしい! きにいったぞ\n"
	.string "わたしたち なかよく なれそうだ\p"
	.string "これで つりを したまえ わかき ともよ!$"

Route12_FishingHouse_Text_ReceivedSuperRod::
	.string "{JPN}{ENG}{PLAYER}{JPN}は つりめいじんの おとうとから\n"
	.string "すごいつりざおを もらった!$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
	.string "{JPN}つりとは いきかた そのもの!\n"
	.string "さいこうの しの ようなものだ\p"
	.string "うみから かわまで でかけて\n"
	.string "おおものを つりあげたまえ ともよ\p"
	.string "ところで たのみが あるのだ\p"
	.string "その つりざおで おおきな コイキングを\n"
	.string "つったら ぜひ みせてくれ\p"
	.string "わたしは つりも すきだが\n"
	.string "でっかい コイキングを みるのも すきでね$"

Route12_FishingHouse_Text_OhThatsDisappointing::
	.string "{JPN}そうか…\n"
	.string "それは ざんねんだ…$"

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
	.string "{JPN}やあ {ENG}{PLAYER}{JPN}!\n"
	.string "つりは しているかね?\p"
	.string "すごいつりざおで いろんな\n"
	.string "みずべで つって みたまえ\p"
	.string "ばしょに よって ちがう ポケモンが\n"
	.string "つれるからね\p"
	.string "そうそう でっかい コイキングを\n"
	.string "もってくるのを わすれずにな$"

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
	.string "{JPN}おや? {ENG}{PLAYER}{JPN}?\n"
	.string "なんと コイキングじゃないか!\p"
	.string "はやく みせてくれ!$"

Route12_FishingHouse_Text_WhoaXInchesTakeThis::
	.string "{JPN}… … …おおっ!\n"
	.string "{ENG}{STR_VAR_2}{JPN}インチ!\p"
	.string "きみは つりの すばらしい しじょうを\n"
	.string "あじわえる めずらしい ひとだ!\p"
	.string "これを うけとって くれ\n"
	.string "ぜひとも!$"

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
	.string "{JPN}もっと すごい きろくを\n"
	.string "たのしみに しているよ!$"

Route12_FishingHouse_Text_HuhXInchesSameSizeAsLast::
	.string "{JPN}ん?\n"
	.string "{ENG}{STR_VAR_2}{JPN}インチ?\p"
	.string "まえに みた ものと\n"
	.string "おなじ おおきさだな$"

Route12_FishingHouse_Text_HmmXInchesDoesntMeasureUp::
	.string "{JPN}うーむ…\n"
	.string "こいつは {ENG}{STR_VAR_2}{JPN}インチか\p"
	.string "まえに もってきた ものには\n"
	.string "{ENG}{STR_VAR_3}{JPN}インチの ほうに およばないな$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
	.string "{JPN}うーん… それは あまり\n"
	.string "コイキングには みえないな$"

Route12_FishingHouse_Text_NoRoomForGift::
	.string "{JPN}おや!\p"
	.string "おくりものが あったのだが\n"
	.string "もちきれない ようだね$"

Route12_FishingHouse_Text_MostGiganticMagikarpXInches::
	.string "{JPN}わたしが これまでに みた\n"
	.string "いちばん でっかい コイキング…\p"
	.string "{ENG}{STR_VAR_3}{JPN}インチ!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
	.string "{JPN}なにかの ひょうだが なにも かいてない\p"
	.string "なにかの きろくを かきこむ\n"
	.string "らんが ある$"

