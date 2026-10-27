SixIsland_WaterPath_House1_Frlg_MapScripts::
	.byte 0

SixIsland_WaterPath_House1_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, SPECIES_HERACROSS
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_MayIMeasureHeracross
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, SixIsland_WaterPath_House1_EventScript_DontShowMon
	special CompareHeracrossSize
	goto_if_eq VAR_RESULT, 1, SixIsland_WaterPath_House1_EventScript_ShownNonHeracross
	goto_if_eq VAR_RESULT, 2, SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross
	goto_if_eq VAR_RESULT, 3, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	goto_if_eq VAR_RESULT, 4, SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_NoHeracrossInParty::
	msgbox SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross
	release
	end

SixIsland_WaterPath_House1_EventScript_DontShowMon::
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownNonHeracross::
	msgbox SixIsland_WaterPath_House1_Text_ThisWontDo
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownSmallHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownTiedHeracross::
	goto_if_unset FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_ShownBigHeracross
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore
	release
	end

SixIsland_WaterPath_House1_EventScript_ShownBigHeracross::
	setflag FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1
	msgbox SixIsland_WaterPath_House1_Text_ItsXInchesDeserveReward
	giveitem ITEM_NEST_BALL
	goto_if_eq VAR_RESULT, FALSE, SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall
	msgbox SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne
	release
	end

SixIsland_WaterPath_House1_EventScript_NoRoomForNestBall::
	msgbox SixIsland_WaterPath_House1_Text_YourBagIsFull
	release
	end

SixIsland_WaterPath_House1_EventScript_SizeRecord::
	lockall
	goto_if_set FLAG_GOT_NEST_BALL_FROM_WATER_PATH_HOUSE_1, SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty
	msgbox SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort
	releaseall
	end

SixIsland_WaterPath_House1_EventScript_SizeRecordNonEmpty::
	special GetHeracrossSizeRecordInfo
	msgbox SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches
	releaseall
	end

SixIsland_WaterPath_House1_Text_LoveItNeedItHeracross::
	.string "{JPN}ヘラ ヘラ ヘラクロス!\n"
	.string "おおきく ひかる むしの ボス!\l"
	.string "だいすき ほしい ヘラクロス!$"

SixIsland_WaterPath_House1_Text_MayIMeasureHeracross::
	.string "{JPN}キャーッ!\n"
	.string "それ ヘラクロスじゃない!\p"
	.string "おねがい おねがい! おおきさを\n"
	.string "はからせて くれない?$"

SixIsland_WaterPath_House1_Text_ItsXInchesDeserveReward::
	.string "{JPN}キャーッ {ENG}{STR_VAR_2}{JPN}インチも ある!\n"
	.string "こんなの みたこと ないわ!\l"
	.string "ごほうびを あげなくちゃ!$"

SixIsland_WaterPath_House1_Text_WantToSeeBiggerOne::
	.string "{JPN}それより もっと もっと おおきい\n"
	.string "ヘラクロスが みたいの\p"
	.string "ああ だいすき おおきな\n"
	.string "ヘラクロス!$"

SixIsland_WaterPath_House1_Text_ItsXInchesSameAsBefore::
	.string "{JPN}あれ? {ENG}{STR_VAR_2}{JPN}インチ…\n"
	.string "もう! まえと おなじじゃない$"

SixIsland_WaterPath_House1_Text_ItsXInchesYInchesWasBiggest::
	.string "{JPN}あら {ENG}{STR_VAR_2}{JPN}インチしか ないわ\n"
	.string "まえの ヘラクロスの ほうが おおきかった\p"
	.string "それは {ENG}{STR_VAR_3}{JPN}インチで いままでに\n"
	.string "もってきた いちばん おおきい ヘラクロスよ$"

SixIsland_WaterPath_House1_Text_ThisWontDo::
	.string "{JPN}あーん! これじゃ だめ!\p"
	.string "ヘラクロスは もっと たくましくて\n"
	.string "かっこよくて すてきな ツノなの!$"

SixIsland_WaterPath_House1_Text_YourBagIsFull::
	.string "{JPN}バッグが いっぱいね\n"
	.string "ごほうびが はいらないわ$"

SixIsland_WaterPath_House1_Text_BiggestHeracrossIsXInches::
	.string "{JPN}わたしが いままでに はかった\n"
	.string "いちばん おおきい ヘラクロスは\p"
	.string "{ENG}{STR_VAR_3}{JPN}インチ!$"

SixIsland_WaterPath_House1_Text_BlankChartOfSomeSort::
	.string "{JPN}なにかの ひょうだ なにも かいてない\p"
	.string "なにかの きろくを かきこむ\n"
	.string "らんが ある$"

