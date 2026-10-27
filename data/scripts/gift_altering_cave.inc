MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございます。\p"
	.string "めずらしい ポケモンが みつかったという\n"
	.string "うわさが あるようです。\p"
	.string "もくげきじょうほうは 103ばんどうろの\n"
	.string "へんげの どうくつから とのことです。\p"
	.string "この うわさを しらべてみる\n"
	.string "かちは あるかも しれませんね。$"
