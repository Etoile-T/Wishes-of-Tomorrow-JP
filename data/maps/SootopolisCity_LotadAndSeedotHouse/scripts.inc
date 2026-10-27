SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_SEEDOT
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	setvar VAR_0x8009, SPECIES_LOTAD
	chooseboxmon SELECT_PC_MON_TRADE
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	goto_if_eq VAR_RESULT, COMPARE_SIZE_INCORRECT_SPECIES, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_SMALLER, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "{JPN}タネボーって ポケモン しってる?\n"
	.string "ルネでは めったに みかけないんだ。\p"
	.string "とにかく ぼく おおきい タネボーが すき。\n"
	.string "おおきければ おおきいほど いい。\p"
	.string "でも おとうとは ハスボーの ほうが\n"
	.string "おおきいって いうんだ。\p"
	.string "そんなの おかしいよ。\n"
	.string "タネボーの ほうが おおきいに きまってる!\p"
	.string "えっ? タネボー もってるの?\n"
	.string "み み み みせて!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{JPN}{ENG}{STR_VAR_2}{JPN}!\n"
	.string "うわあ これは おおきいね!\p"
	.string "おとうとが みた おおきい ハスボーにも\n"
	.string "かっちゃう かも!\p"
	.string "みせてくれて ありがとう。\n"
	.string "これは おれいだよ!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{JPN}{ENG}{PLAYER}{JPN}は キズぐすりを もらった!$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "{JPN}あれ?\n"
	.string "バッグが いっぱい だね。$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{JPN}{ENG}{STR_VAR_2}{JPN} かあ。\p"
	.string "うーん… これより おおきい タネボーを\n"
	.string "みたことが あるよ。$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "{JPN}へえ これは すごいね……\n"
	.string "でも タネボーじゃ ないよ!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "{JPN}おおきい タネボー もってないの?\n"
	.string "ざんねん……\p"
	.string "おおきい タネボーを つかまえたら\n"
	.string "みせに きてね。$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "{JPN}しじょう さいだいの タネボー!\n"
	.string "{ENG}{STR_VAR_2}{JPN}の {ENG}{STR_VAR_3}{JPN}!\p"
	.string "ずっと ほしかった ハスボーより\n"
	.string "おおきい タネボーだ!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "{JPN}ハスボーって ポケモン しってる?\n"
	.string "ルネでは めったに みかけないの。\p"
	.string "ぼく おおきい ハスボーが だーいすき!\p"
	.string "おにいちゃんは タネボーの ほうが\n"
	.string "おおきいって いうんだ。\p"
	.string "でも ちがうよ! ハスボーの ほうが\n"
	.string "ずっと おおきいに きまってる。\p"
	.string "えっ? ハスボー もってるの?\n"
	.string "み み み みせて!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{JPN}{ENG}{STR_VAR_2}{JPN}!\n"
	.string "わあ おおきい!\p"
	.string "おにいちゃんが みた おおきな タネボー\n"
	.string "よりも おおきい かもしれない。\p"
	.string "みせてくれて ありがとう!\n"
	.string "これは おれいだよ!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{JPN}{ENG}{PLAYER}{JPN}は キズぐすりを もらった!$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "{JPN}あれ?\n"
	.string "バッグが いっぱい だね。$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{JPN}{ENG}{STR_VAR_2}{JPN}?\p"
	.string "うーん… これより おおきい ハスボーを\n"
	.string "みたことが あるよ。$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "{JPN}へえ すごいね!\n"
	.string "でも ハスボーじゃ ないよ!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "{JPN}おおきい ハスボー もってないの?\n"
	.string "がっかり……\p"
	.string "おおきい ハスボーを つかまえたら\n"
	.string "みせに きてね!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "{JPN}しじょう さいだいの ハスボー!\n"
	.string "{ENG}{STR_VAR_2}{JPN}の {ENG}{STR_VAR_3}{JPN}!\p"
	.string "ずっと ほしかった タネボーより\n"
	.string "おおきい ハスボーだ!$"

