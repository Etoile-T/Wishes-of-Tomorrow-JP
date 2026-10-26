SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "{JPN}えっへん! わたしが\n"
	.string "ポケモンだいすきクラブの かいちょうですぞ!\p"
	.string "かいちょう なのだから とうぜん\n"
	.string "わたしが いちばん えらいのです!\p"
	.string "ポケモンを そだてることでは\n"
	.string "だれにも まけませんぞ! だれにも!\p"
	.string "では ポケモンコンテストに ついて\n"
	.string "おはなし しましょう。\p"
	.string "ポケモンを せかいじゅうの ひとに\n"
	.string "じまん できる イベントですぞ!\p"
	.string "ただ とおくの まちで ひらかれるので\n"
	.string "なかなか さんか できないのです。\p"
	.string "だから ここに あつまって\n"
	.string "じぶんの ポケモンを じまんしたり\l"
	.string "ほかの ひとのを みせて もらうのですぞ。$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "{JPN}ポケモンコンテストに でた ことが\n"
	.string "ある トレーナーの ポケモン…\l"
	.string "ぜひとも みて みたい ものですな。$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "{JPN}えっへん! きみは\n"
	.string "ポケモンコンテストに さんかしたようですな!\p"
	.string "ぜひ! どのように ポケモンを そだてたのか\n"
	.string "はいけん させて ください。\p"
	.string "ほかの トレーナーが そだてた ポケモンを\n"
	.string "みるのは このうえなく うれしいのです。\p"
	.string "だいじに そだてられた ポケモンの\n"
	.string "しあわせそうな ひょうじょう…\p"
	.string "ポケモンを いつくしみ そだてた\n"
	.string "トレーナーの やさしい まなざし…\p"
	.string "かんがえるだけで むねが\n"
	.string "よろこびで いっぱいに なるのですぞ。\p"
	.string "おっと! しつれい しました!\n"
	.string "ながながと しゃべって しまいましたな!\p"
	.string "ぜひ! きみの ポケモンが どれだけ\n"
	.string "そだったのか みせて ください!$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "{JPN}きみの ポケモン そだって ますかな?\n"
	.string "ちょっと はいけん させて もらいますぞ!$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "{JPN}ふむふむ……\n"
	.string "なるほど……$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "{JPN}ふむう……\n"
	.string "わるくは ないんだが よくもない……\p"
	.string "おやの トレーナーである きみの\n"
	.string "どりょくが ひつよう ですな!\p"
	.string "たとえば もっと たくさん\n"
	.string "ポロックを あげるのは どうですかな?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "{JPN}おやおや…\p"
	.string "ポケモンが なかなか よく そだっているので\n"
	.string "ごほうびを もらうに ふさわしいですぞ。\p"
	.string "ざんねんながら バッグに\n"
	.string "これを いれる あきが ありませんな。$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "{JPN}きみの {ENG}{STR_VAR_1}{JPN} ですが\n"
	.string "じつに みごとに そだって おりますな!\l"
	.string "いやー たいした ものです!\p"
	.string "だが! これを あげれば\n"
	.string "もっと よく そだちますぞ! そうですとも!$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "{JPN}その あかいバンダナを もたせなさい。\p"
	.string "ポケモンの かっこよさを\n"
	.string "みんなが みとめる ことでしょう!$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "{JPN}その あおいバンダナを もたせなさい。\p"
	.string "ポケモンの うつくしさが いまより\n"
	.string "ずっと ひきたちますぞ!$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "{JPN}その ピンクのバンダナを もたせなさい。\p"
	.string "ポケモンの かわいさが\n"
	.string "もっと ひきだされますぞ!$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "{JPN}その みどりのバンダナを もたせなさい。\p"
	.string "ポケモンの かしこさが\n"
	.string "たかまりますぞ!$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "{JPN}その きいろのバンダナを もたせなさい。\p"
	.string "ポケモンの たくましさが\n"
	.string "いっそう たかまりますぞ!$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "{JPN}すまないが きみに あげられるものは\n"
	.string "もう なにも ないですぞ! ひとつも!\p"
	.string "なにしろ どうぐに たよらんでも\n"
	.string "きみの ポケモンを そだてる\l"
	.string "さいのうは バツグン ですからな!$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "{JPN}わたし ポケモンが なついている\n"
	.string "すがたを みるのが すき\p"
	.string "トレーナーの きもちに\n"
	.string "ポケモンは とても びんかん なの!\p"
	.string "ポケモンを あいじょうこめて だいじに すれば\n"
	.string "ポケモンも あなたに なついてくれるわ!\p"
	.string "あなたの ポケモンが あなたに なついたら\n"
	.string "わたしにも みせてね。$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "{JPN}あなたの ポケモン とても なついてるわね。\p"
	.string "とても おもいやりの ある トレーナーの\n"
	.string "あなたに クラブからの プレゼントよ!$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "{JPN}トレーナーの きもちに\n"
	.string "ポケモンは とても びんかん なの!\p"
	.string "ポケモンを あいじょうこめて だいじに すれば\n"
	.string "ポケモンも あなたに なついてくれるわ!$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "{JPN}しょうぶで ポケモンを なんども\n"
	.string "ひんしに すると いやがるように なります。\p"
	.string "やがて トレーナーを しんじる きもちも\n"
	.string "うすれて しまいます。\p"
	.string "つまり あなたのことを\n"
	.string "あまり すきでは なくなるのです。$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "{JPN}ポケモンって どうぐ\n"
	.string "つかってもらうのが すきなのかな?\p"
	.string "うちの ポケモンは タウリンを あげたら\n"
	.string "とても うれしそうに していたわ。$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "{JPN}エネコ: ふにゃあーあ…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "{JPN}ジグザグマ: キュウウ…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "{JPN}マリルリ: マリマリ?$"

