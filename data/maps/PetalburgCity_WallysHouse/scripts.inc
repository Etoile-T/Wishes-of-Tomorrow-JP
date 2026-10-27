PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "{JPN}あなたは……\n"
	.string "ああ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} ね?\p"
	.string "さっきは ミツルと あそんでくれて\n"
	.string "ありがとう\p"
	.string "あのこは あかちゃんの ころから\n"
	.string "からだが よわくて……\p"
	.string "しばらく シダケタウンの しんせきの\n"
	.string "いえに あずける ことに したの\p"
	.string "あっちは ここより ずっと\n"
	.string "くうきが きれいだから\p"
	.string "え? ミツルは どこかって?\n"
	.string "うちの ミツルは もう でかけたわ\p"
	.string "いまごろ どの あたりまで\n"
	.string "いったのかしら?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "{JPN}ミツルは どうしてるかなあ……$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{JPN}{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}! こんなふうに\n"
	.string "よびだして しまって すまないね\p"
	.string "でも うちの ミツルは シダケタウンに\n"
	.string "いってから とても げんきに なったんだ\p"
	.string "すべて きみの おかげだよ!\p"
	.string "ミツルが まちを でるとき ポケモンを\n"
	.string "つかまえるのを てつだって くれたろう?\p"
	.string "それが ミツルは ほんとうに\n"
	.string "うれしかった ようだ\p"
	.string "いや ミツル だけじゃない\n"
	.string "ちちおやの わたしも うれしかった\p"
	.string "きみの ような すばらしい ともだちが\n"
	.string "できた ことがね\p"
	.string "おれい という わけじゃないが\n"
	.string "ぜひ これを うけとって ほしい$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "{JPN}ポケモンが なみのりを つかえれば\n"
	.string "いろんな ばしょに いけるように なるよ!$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "{JPN}もうすぐ ミツルが かえってくるぞ!\n"
	.string "たのしみだなあ……!$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "{JPN}ええっ!? サイユウシティで\n"
	.string "ミツルと あった だって……?\p"
	.string "んもう {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}ってばー\p"
	.string "いくら あのこが げんきに なったからって\n"
	.string "そんな とおくの まち まで\l"
	.string "ひとりで いけるわけ ないよねえ……$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "{JPN}ポケモンを つかまえたって はなす\n"
	.string "ミツルは ほんとうに うれしそうだった\p"
	.string "あんなに わらう あのこを みたのは\n"
	.string "ほんとうに ひさしぶりだったわ$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "{JPN}しゅじんには ないしょに\n"
	.string "してほしいんだけど……\p"
	.string "うちの ミツル だれにも いわずに\n"
	.string "シダケタウンを でていったの\p"
	.string "ミツルは からだは よわいけど\n"
	.string "いがいと きが つよい こなのよ\p"
	.string "いつか きっと ぶじに\n"
	.string "かえってくると しんじてるわ!$"

