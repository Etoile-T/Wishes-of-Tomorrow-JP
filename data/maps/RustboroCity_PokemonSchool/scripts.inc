RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "{JPN}こくばんには せんとうちゅうの ポケモンに\n"
	.string "おこる じょうたい へんかが かいてある$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "{JPN}どの こうもくを みますか?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "{JPN}どくを うけた ポケモンは\n"
	.string "HPが どんどん へっていきます\p"
	.string "どくは せんとうが おわっても\n"
	.string "なおりません\p"
	.string "どくを うけた ポケモンは\n"
	.string "あるいている あいだも HPが へります\p"
	.string "どくけしで なおしましょう$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "{JPN}まひ すると ポケモンの\n"
	.string "すばやさが さがります\p"
	.string "せんとうちゅうに うごけなく\n"
	.string "なることも あります\p"
	.string "まひは せんとうが おわっても なおりません\n"
	.string "まひなおしで なおしましょう$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "{JPN}ねむって しまうと\n"
	.string "その あいだ こうげき できません\p"
	.string "じぶんで めざめることも ありますが\n"
	.string "ねむったまま せんとうが おわると\l"
	.string "ずっと ねむっています\p"
	.string "ねむけざましで おこして あげましょう$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "{JPN}やけどは こうげきりょくが さがるだけでなく\n"
	.string "HPも どんどん へっていきます\p"
	.string "せんとうが おわっても やけどの ままです\n"
	.string "やけどなおしで なおしましょう$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "{JPN}こおって しまった ポケモンは\n"
	.string "まったく なにも できなくなります\p"
	.string "せんとうが おわっても こおったままです\n"
	.string "こおりなおしで とかしましょう$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "{JPN}べんきょう しない せいとには\n"
	.string "わたしの せんせいのツメを おみまいよ\p"
	.string "あなたが いい せいとか どうかは \n"
	.string "この どうぐの つかいかたで\l"
	.string "わかるわ$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "{JPN}せんせいのツメを もった ポケモンは\n"
	.string "ときどき すばやく なって あいてより\l"
	.string "さきに うごけるのよ\p"
	.string "ほかにも ポケモンに もたせる\n"
	.string "どうぐは たくさん あるわ\p"
	.string "それだけでも べんきょうする ことが\n"
	.string "たくさん あるわよ!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "{JPN}いま ともだちと\n"
	.string "ポケモンを こうかん してるんだ!$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "{JPN}ずっと ほしかった タネボーが\n"
	.string "やっと てに はいるよ!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "{JPN}ポケモンは どうぐを もてるけど\n"
	.string "キズぐすりや どくけしみたいな\l"
	.string "ひとの つくった どうぐは つかえないんだ$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "{JPN}ポケモンの わざで\n"
	.string "こんらん することが あるでしょ?\p"
	.string "こんらん すると たまに まちがえて\n"
	.string "じぶんを こうげき しちゃうの……\p"
	.string "でも せんとうから はなれると\n"
	.string "もとに もどるわよ!$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "{JPN}……ポケモンに きのみを もたせると\n"
	.string "じぶんで HPを かいふくする……\p"
	.string "ポケモンが もてる どうぐは\n"
	.string "ほかにも たくさん……\p"
	.string "ノートを とるのって\n"
	.string "ほんとうに たいへんだなあ……$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "{JPN}せいとの ノートだ……\p"
	.string "ポケモンは モンスターボールで\n"
	.string "つかまえる\p"
	.string "トレーナーが つれあるける ポケモンは\n"
	.string "6ぴきまで\p"
	.string "トレーナーとは ポケモンを つかまえ\n"
	.string "そだて いっしょに たたかう\l"
	.string "ひとの こと\p"
	.string "トレーナーの もくひょうは ポケモンジムで\n"
	.string "ちょうせんしゃを まちうける\l"
	.string "つよい トレーナーを たおすこと$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "{JPN}おや? まえに あったこと ないかい?\n"
	.string "たしか トウカシティで\p"
	.string "じこしょうかい させてもらうよ\n"
	.string "ぼくは エニシダ\p"
	.string "すぐれた トレーナーを さがして\n"
	.string "あちこち たびを してるんだ\p"
	.string "もっと いうと ポケモンバトルの\n"
	.string "たつじんを さがしているんだよ\p"
	.string "それで きみは なぜ この スクールに?\n"
	.string "きみも トレーナー なのかい?\p"
	.string "まずは ポケモンに いあいぎりを\n"
	.string "おぼえさせると いいよ\p"
	.string "たしか この まちの だれかが\n"
	.string "いあいぎりを もっていたはずだ$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "{JPN}エニシダ: ふむ……\p"
	.string "ここの せいとたちの さいのうは\n"
	.string "まだ みちすう だけど のびしろは あるね$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "{JPN}エニシダ: おや それは?\p"
	.string "ストーンバッジ じゃないか!\n"
	.string "なかなか たいしたもんだね\p"
	.string "でも きみが たたかう ところを\n"
	.string "ぜひ みてみたかったなあ\p"
	.string "バッジ だけじゃ トレーナーとしての\n"
	.string "きみの じつりょくは わからないからね$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "{JPN}おや? まえに あったこと ないかい?\n"
	.string "たしか トウカシティで\p"
	.string "じこしょうかい させてもらうよ\n"
	.string "ぼくは エニシダ\p"
	.string "すぐれた トレーナーを さがして\n"
	.string "あちこち たびを してるんだ\p"
	.string "もっと いうと ポケモンバトルの\n"
	.string "たつじんを さがしているんだよ\p"
	.string "おや それは?\n"
	.string "ストーンバッジ じゃないか!\p"
	.string "かけだしの トレーナーに しては\n"
	.string "なかなか たいしたもんだね\p"
	.string "でも きみが たたかう ところを\n"
	.string "ぜひ みてみたかったなあ\p"
	.string "バッジ だけじゃ トレーナーとしての\n"
	.string "きみの じつりょくは わからないからね$"

