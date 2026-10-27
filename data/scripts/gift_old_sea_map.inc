MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございます。\p"
	.string "かくにんします。 {ENG}{PLAYER}{JPN}さま ですね?\p"
	.string "あなたあての ふるびたかいずを\n"
	.string "おあずかり しております。$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "{JPN}どうやら ミナモシティの\n"
	.string "みなとで つかう もののようです。\p"
	.string "どんな ものか ためしに\n"
	.string "いってみては いかがですか?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございました。$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "{JPN}もうしわけ ありません {ENG}{PLAYER}{JPN}さま。\n"
	.string "バッグの たいせつなものポケットが いっぱいです。\p"
	.string "なにかを パソコンに あずけてから\n"
	.string "また おこしください。$"
