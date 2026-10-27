MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございます。\p"
	.string "バトルカウントカードには おなじ\n"
	.string "カードを もつ トレーナーとの\l"
	.string "たいせんせいせきが きろくされます。\p"
	.string "おなじ カードを もつ トレーナーを\n"
	.string "さがして たいせん してください。\p"
	.string "ぜんたいの ランキングは\n"
	.string "ニュースで かくにん できます。\p"
	.string "ぜひ ためしてみてください!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございます。\p"
	.string "おめでとう ございます!\p"
	.string "3かい バトルに かったので\n"
	.string "けいひんを さしあげます!\p"
	.string "これからも どんどん\n"
	.string "バトルを おたのしみください。$"
