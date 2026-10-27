BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement LOCALID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_RECEPTION_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_FRONTIER_RECEPTION_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "{JPN}はじめての おきゃくさまですね!\n"
	.string "こちらへ どうぞ!$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "{JPN}ポケモンバトルの さいぜんせん!\n"
	.string "バトルフロンティアへ ようこそ!$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "{JPN}はじめての かたには\n"
	.string "フロンティアパスを おわたし しています\p"
	.string "バトルフロンティアの すべての しせつで\n"
	.string "つかえる ものです\p"
	.string "どうぞ!$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "フロンティアパスを もらった!$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{JPN}{ENG}{PLAYER}{JPN}は トレーナーカードを\n"
	.string "フロンティアパスに いれかえた!$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "{JPN}それでは バトルフロンティアを\n"
	.string "ぞんぶんに おたのしみ ください!$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "{JPN}???: おや {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} じゃないか!\n"
	.string "きて くれたんだね!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "{JPN}あんないにん: あっ エニシダさま!\n"
	.string "おつかれさまです!$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "{JPN}エニシダ: ここで あえて ほんとうに\n"
	.string "うれしいよ!\p"
	.string "ゆっくり あちこち みてまわって\n"
	.string "ほしいな\p"
	.string "もちろん バトルの しんずいも\n"
	.string "あじわって もらいたい!\p"
	.string "ここには ぼくの へやも あるから\n"
	.string "ひまが あったら よって いってね$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "{JPN}こちらでは バトルフロンティアの\n"
	.string "しせつを ごあんない いたします$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "{JPN}どの せつめいが ききたいですか?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "{JPN}バトルタワーは バトルフロンティアの\n"
	.string "シンボルの きょだいな とうです\p"
	.string "とうの なかには シングル ダブル\n"
	.string "マルチ リンクマルチ バトルよう\l"
	.string "4しゅるいの バトルルームが あります$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "{JPN}バトルドームは たまごの ような\n"
	.string "かたちをした おおきな たてものです\p"
	.string "こちらでは バトルトーナメント という\n"
	.string "イベントが かいさいされて います\p"
	.string "なお バトルトーナメントには\n"
	.string "シングルバトルよう ダブルバトルようの\l"
	.string "2つの コースが あります!$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "{JPN}バトルパレスは バトルフロンティアの\n"
	.string "みぎがわに ある あかい たてものです\p"
	.string "シングルバトルよう ダブルバトルようの\n"
	.string "2しゅるいの バトルホールが あります$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "{JPN}バトルアリーナは バトルフロンティアの\n"
	.string "ちゅうおう みぎに いちする\l"
	.string "どうじょうの ような たてものです\p"
	.string "こちらでは かちぬきチームバトル という\n"
	.string "イベントを かいさい しております!$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "{JPN}バトルファクトリーは ここから いちばん\n"
	.string "ちかくにある おおきな たてものです\p"
	.string "こちらでは バトルトレード という\n"
	.string "イベントを かいさいして おります\p"
	.string "なお バトルトレードには\n"
	.string "シングルバトルよう ダブルバトルようの\l"
	.string "2つの コースが ようい されています!$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "{JPN}バトルチューブは バトルフロンティアの\n"
	.string "ちゅうおう ひだりに いちする\l"
	.string "ポケモンの かたちを した たてものです\p"
	.string "こちらでは バトルゲーム という\n"
	.string "イベントを かいさい しております!$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "{JPN}バトルピラミッドは きょだいな\n"
	.string "ピラミッドの かたちをした たてものです\p"
	.string "こちらでは バトルアドベンチャー という\n"
	.string "イベントを かいさい しております!$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "{JPN}ランキングホールは\n"
	.string "バトルタワーの ちかくに あります\p"
	.string "こちらでは バトルフロンティアで\n"
	.string "さまざまな ちょうせんに いどんだ\l"
	.string "トレーナーたちの もっとも すばらしい\l"
	.string "きろくを みることが できます$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "{JPN}こうかんサービス コーナーは\n"
	.string "バトルタワーの ちかくに あります\p"
	.string "バトルフロンティアで かせいだ\n"
	.string "バトルポイントを すてきな けいひんと\l"
	.string "こうかん できます$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "{JPN}こちらでは バトルフロンティアに ある\n"
	.string "すべての しせつに きょうつう した\l"
	.string "ちょうせんの ための きほんてきな\l"
	.string "ルールを せつめい いたします!$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "{JPN}どの せつめいが ききたいですか?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "{JPN}バトルフロンティアの しせつの\n"
	.string "ちょうせんには すべて\l"
	.string "レベル50と オープンレベルの 2コースが あります$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "{JPN}レベル50 コースは レベル50 いかの\n"
	.string "ポケモンで さんか できます\p"
	.string "ただし あいての トレーナーの\n"
	.string "ポケモンは すべて\l"
	.string "レベル50 です\p"
	.string "この コースは バトルフロンティアの\n"
	.string "にゅうもん コースです\p"
	.string "まずは この コースに\n"
	.string "ちょうせん して みてください$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "{JPN}オープンレベル コースは さんかする\n"
	.string "ポケモンの レベルに\l"
	.string "せいげんが ありません\p"
	.string "あいての レベルは\n"
	.string "あなたの ポケモンの レベルに\l"
	.string "あわせて ちょうせい されます\p"
	.string "ただし あいての ポケモンは\n"
	.string "すべて レベル60 いじょう です$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "{JPN}どの しせつの ちょうせんにも\n"
	.string "ほとんどの ポケモンが さんか できます\p"
	.string "ただし タマゴと いちぶの ポケモンは\n"
	.string "さんか できません\p"
	.string "ちょうせんに ひつような ポケモンの\n"
	.string "かずは しせつに よって ちがいます\p"
	.string "ただし どの しせつでも おなじ\n"
	.string "しゅるいの ポケモンを 2ひき いじょう\l"
	.string "さんか させる ことは できません$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "{JPN}バトルフロンティアの しせつの\n"
	.string "ちょうせんでは ポケモンに おなじ\l"
	.string "どうぐを もたせる ことは できません\p"
	.string "さんかする ポケモンには かならず\n"
	.string "それぞれ ちがう どうぐを\l"
	.string "もたせて ください$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "{JPN}こちらでは フロンティアパスを ごあんない します$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "{JPN}どの せつめいが ききたいですか?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "{JPN}バトルフロンティアには\n"
	.string "7つの しせつが あります\p"
	.string "じつりょくを みとめられた トレーナーは\n"
	.string "それぞれの しせつから\l"
	.string "シンボルを もらえる ことが あります\p"
	.string "シンボルを もらうには トレーナーに\n"
	.string "れんしょう したり イベントで\l"
	.string "くりかえし ゆうしょう する ひつようが あります\p"
	.string "シンボルを もらうのは たいへんです\n"
	.string "ごけんとうを おいのり します!$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "{JPN}フロンティアパスには バトルを\n"
	.string "1かい ぶん きろく できます\p"
	.string "ともだちと たたかった バトルを\n"
	.string "きろく することが できます\p"
	.string "また バトルチューブと\n"
	.string "バトルピラミッド いがいの\l"
	.string "バトルフロンティアで おこなった\l"
	.string "バトルも きろく できます\p"
	.string "バトルの きろくは バトルが おわった\n"
	.string "ときに えらぶ ことが できます$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "{JPN}バトルポイントは バトルフロンティアで\n"
	.string "すばらしい たたかいを した\l"
	.string "トレーナーに おくられる ほうびです\p"
	.string "バトルポイントは こうかんサービス\n"
	.string "コーナーで けいひんと\l"
	.string "こうかん できます$"

