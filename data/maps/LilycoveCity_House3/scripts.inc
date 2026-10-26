LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "{JPN}あらあら! ひとりで たびを してるの?\n"
	.string "まだ わかいのに! えらいわねえ!\p"
	.string "うちの こたちも あなたを\n"
	.string "すこしは みならって ほしいわ!\p"
	.string "わたし? ポロックめいじんなの。\p"
	.string "ちょっと ほんきを だせば\n"
	.string "すごい ポロックを つくれるのよ。\p"
	.string "ポロックめいじんの わたしに\n"
	.string "おしえて もらいたい?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "{JPN}あら? ほんとうに いいの?\p"
	.string "なんでも じぶんだけで やろうと\n"
	.string "しちゃ いけないわよ!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "{JPN}あら いいこね! かしこいわ!\n"
	.string "すこし ながくなるから よく きいてね!\p"
	.string "いいかしら?\p"
	.string "ポロックを みると\n"
	.string "なめらかさが かいてあるでしょう。\p"
	.string "なめらかさの すうじは ひくいほど\n"
	.string "いいのよ。わすれないでね!\p"
	.string "いい ポロックは なめらかさが ひくくて\n"
	.string "レベルが たかいものなの。\p"
	.string "ポケモンは いい ポロックなら\n"
	.string "ふつうのより たくさん たべられるのよ。\p"
	.string "それから ここが だいじ。\p"
	.string "なめらかな ポロックを つくりたければ\n"
	.string "ちがう しゅるいの きのみを つかうのよ。\p"
	.string "けちっちゃ だめ。きのみの しゅるいで\n"
	.string "ポロックの なめらかさが かわるんだから。\p"
	.string "それに もうひとつ。\p"
	.string "たくさんの ひとで きのみを まぜるほど\n"
	.string "ポロックは なめらかに なるの。\p"
	.string "だから ほかの ひとに こえを かけて\n"
	.string "いっしょに ポロックを つくると いいわ。\p"
	.string "いい ポロックを つくるには\n"
	.string "だいたい これで じゅうぶんよ。\p"
	.string "みんなに だいすきな ポケモンと\n"
	.string "なめらかな ポロックと やさしい かぞくが\l"
	.string "いれば せかいは もっと しあわせなのにね。\p"
	.string "あきらめずに がんばってね!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "{JPN}つまが よつごを うんだときは\n"
	.string "そりゃあ びっくりしたよ。\p"
	.string "でも いまは いっしょに あそぶのを\n"
	.string "みていると しあわせに なるんだ。$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "{JPN}マルチバトルを してるんだけど\n"
	.string "ぜったい かつよ。$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "{JPN}レコードコーナーで まぜるのが\n"
	.string "すきなんだ。\p"
	.string "でも なにを まぜてるの?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "{JPN}きのみブレンダーで すごい ポロックを\n"
	.string "つくるんだ!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "{JPN}ポケモンの たくましさを じまんしたいから\n"
	.string "いっしょに コンテストに\l"
	.string "でるんだ!$"

