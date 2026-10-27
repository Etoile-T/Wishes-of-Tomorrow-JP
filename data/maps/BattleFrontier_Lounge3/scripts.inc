BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "{JPN}…… なんだぁ?\p"
	.string "おれたちゃ いま いそがしいの!\n"
	.string "また こんどに してくれや!$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "{JPN}…… ん?\n"
	.string "あんた つよそうな トレーナー だな。\p"
	.string "へへへ……\n"
	.string "ちょいと はなしが あるんだがな。\p"
	.string "おれたち ここで なかまを つくってな\n"
	.string "バトルフロンティアで おきることを\l"
	.string "ネタに ちょっとした ゲームを してるんだ。\p"
	.string "ルールは かんたん。\p"
	.string "まず バトルフロンティアの しせつを\n"
	.string "ひとつ えらぶ。\p"
	.string "つぎに その しせつに ちょうせんする\n"
	.string "トレーナーを それぞれ ひとりずつ えらんで\l"
	.string "バトルポイントを かけるんだ。\p"
	.string "いちばん いい せいせきの\n"
	.string "トレーナーに かけた やつが\l"
	.string "かけきんの バトルポイントを ぜんぶ いただきだ。\p"
	.string "かんたん だろ?\n"
	.string "で だな……$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "{JPN}おれが さがしてるのは バトルタワーの\n"
	.string "シングルバトルルームに\l"
	.string "ちょうせんする トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "{JPN}おれが さがしてるのは バトルタワーの\n"
	.string "ダブルバトルルームに\l"
	.string "ちょうせんする トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "{JPN}おれが さがしてるのは バトルタワーの\n"
	.string "マルチバトルルームに\l"
	.string "ちょうせんする トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "{JPN}おれが さがしてるのは バトルドームの\n"
	.string "シングルバトル トーナメントに\l"
	.string "でる トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "{JPN}おれが さがしてるのは バトルドームの\n"
	.string "ダブルバトル トーナメントに\l"
	.string "でる トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "{JPN}おれが さがしてるのは バトルファクトリーの\n"
	.string "バトルトレード シングルに\l"
	.string "でる トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "{JPN}おれが さがしてるのは バトルファクトリーの\n"
	.string "バトルトレード ダブルに\l"
	.string "でる トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "{JPN}おれが さがしてるのは バトルパレスの\n"
	.string "シングルバトルホールに\l"
	.string "ちょうせんする トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "{JPN}おれが さがしてるのは バトルパレスの\n"
	.string "ダブルバトルホールに\l"
	.string "ちょうせんする トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "{JPN}おれが さがしてるのは バトルアリーナの\n"
	.string "かちぬきチームバトルに\l"
	.string "でる トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "{JPN}おれが さがしてるのは バトルチューブの\n"
	.string "バトルゲームに\l"
	.string "でる トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "{JPN}おれが さがしてるのは バトルピラミッドの\n"
	.string "バトルアドベンチャーに\l"
	.string "でる トレーナー なんだ。\p"
	.string "でも いまのところ かちそうな\n"
	.string "トレーナーが みつからなくてな。$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "{JPN}あんたにも ちゃんと いいこと あるからさ。\n"
	.string "どうだい?\l"
	.string "おれの かわりに でて くれないか?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "{JPN}よし ばっちりだ。\n"
	.string "で…… あんたの バトルポイントを\l"
	.string "ちょっと かして くれないか?\p"
	.string "あとで ちゃんと おれいは\n"
	.string "するからさ。$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "{JPN}イイね! イイね!\n"
	.string "で? で? で? いくら かして くれます?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "{JPN}おいおいおい!\n"
	.string "バトルポイントが たりないじゃないか!\p"
	.string "ふざけて みんなの じかんを\n"
	.string "むだに しないで くれよな!$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "{JPN}へっへっへっ…… あんがとよ!\n"
	.string "そんじゃ いってきな!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "{JPN}バトルタワーの\n"
	.string "シングルバトルルームへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "{JPN}バトルタワーの\n"
	.string "ダブルバトルルームへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "{JPN}バトルタワーの\n"
	.string "マルチバトルルームへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "{JPN}バトルドームの\n"
	.string "シングルバトル トーナメントへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "{JPN}バトルドームの\n"
	.string "ダブルバトル トーナメントへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "{JPN}バトルファクトリーの\n"
	.string "バトルトレード シングルへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "{JPN}バトルファクトリーの\n"
	.string "バトルトレード ダブルへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "{JPN}バトルパレスの\n"
	.string "シングルバトルホールへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "{JPN}バトルパレスの\n"
	.string "ダブルバトルホールへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "{JPN}バトルアリーナの\n"
	.string "かちぬきチームバトルへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "{JPN}バトルチューブの\n"
	.string "バトルゲームへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "{JPN}バトルピラミッドの\n"
	.string "バトルアドベンチャーへ いそげ!\p"
	.string "ぜったい かたなきゃ いけないぞ!\n"
	.string "チャンスを むだに するなよ!\l"
	.string "おれたちの みらいは あんたに かかってる!$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "{JPN}ああ あんたか……\n"
	.string "ざんねん だったな……\p"
	.string "いいにくいんだが あずかった\n"
	.string "バトルポイントは かえせないんだ……\p"
	.string "つぎこそは もっと がんばろうって\n"
	.string "きもちを あらたに しようぜ!$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "{JPN}おお やったな!\n"
	.string "よう チャンピオン!\p"
	.string "できると おもってたぜ!\n"
	.string "やると おもってたぜ!\l"
	.string "おれたち ふたりとも おおもうけだ!\p"
	.string "あずかった バトルポイントと\n"
	.string "もちろん おれからの おまけも つけるぜ!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{JPN}{ENG}{PLAYER}{JPN}は バトルポイントを\n"
	.string "{ENG}{STR_VAR_1}{JPN}BP てにいれた!$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "{JPN}また なんか あったら\n"
	.string "よろしく たのみますよっ!!$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "{JPN}のらないって?! そりゃ ないぜー!\n"
	.string "チャンスを こわがってちゃ だめだろ!$"

BattleFrontier_Lounge3_Text_Oh::
	.string "{JPN}おっ……$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "{JPN}また はずれの トレーナーに かけちゃった!\p"
	.string "あたしも みんなみたいに\n"
	.string "ふつうに たたかった ほうが いいの かなぁ……$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "{JPN}あの トレーナー……\p"
	.string "つよいけど すぐ あわてる からな。\n"
	.string "あれじゃ バトルドームでは かちのこれないな……$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "{JPN}うふふっ!\n"
	.string "かつ ひとは ひとめで わかるのよ!$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "{JPN}あいつら トレーナーの くせに\n"
	.string "ちょうせんも しないで\l"
	.string "なに してるん だろうな?$"
