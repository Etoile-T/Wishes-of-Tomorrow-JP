.equ PLAYER_X_POS, VAR_0x8004
.equ PLAYER_Y_POS, VAR_0x8005

FiveIsland_RocketWarehouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_RocketWarehouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_RocketWarehouse_OnTransition
	.byte 0

FiveIsland_RocketWarehouse_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND_ROCKET_WAREHOUSE
	end

FiveIsland_RocketWarehouse_OnLoad::
	call_if_defeated TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	end

FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry::
	setmetatile 26, 20, METATILE_SilphCo_Arrow_Up, 0
	setmetatile 27, 20, METATILE_SilphCo_Arrow_Up, 0
	return

FiveIsland_RocketWarehouse_EventScript_Cage::
	lockall
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FiveIsland_RocketWarehouse_EventScript_CageUnlocked
	msgbox FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_CageUnlocked::
	msgbox FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Computer::
	msgbox FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText, MSGBOX_SIGN
	end

FiveIsland_RocketWarehouse_EventScript_Admin2Trigger::
	lockall
	applymovement LOCALID_WAREHOUSE_ADMIN2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	releaseall
	end

FiveIsland_RocketWarehouse_EventScript_Gideon::
	trainerbattle_single TRAINER_SCIENTIST_GIDEON, FiveIsland_RocketWarehouse_Text_GideonIntro, FiveIsland_RocketWarehouse_Text_GideonDefeat, FiveIsland_RocketWarehouse_EventScript_DefeatedGideon
	goto_if_set FLAG_IS_CHAMPION, FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid
	msgbox FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_MentionGiovannisKid::
	famechecker FAMECHECKER_GIOVANNI, 5
	msgbox FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedGideon::
	msgbox FiveIsland_RocketWarehouse_Text_GideonPostBattle
	setflag FLAG_RECOVERED_SAPPHIRE
	giveitem ITEM_SAPPHIRE
	release
	end

FiveIsland_RocketWarehouse_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_47, FiveIsland_RocketWarehouse_Text_Grunt2Intro, FiveIsland_RocketWarehouse_Text_Grunt2Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_48, FiveIsland_RocketWarehouse_Text_Grunt3Intro, FiveIsland_RocketWarehouse_Text_Grunt3Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin2::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN_2, FiveIsland_RocketWarehouse_Text_Admin2Intro, FiveIsland_RocketWarehouse_Text_Admin2Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin2::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2
	msgbox FiveIsland_RocketWarehouse_Text_Admin2PostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_WAREHOUSE_GRUNT2
	removeobject LOCALID_WAREHOUSE_GRUNT3
	removeobject LOCALID_WAREHOUSE_ADMIN2
	removeobject LOCALID_WAREHOUSE_ADMIN1
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin2::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_42, FiveIsland_RocketWarehouse_Text_Grunt1Intro, FiveIsland_RocketWarehouse_Text_Grunt1Defeat
	msgbox FiveIsland_RocketWarehouse_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_Admin1::
	trainerbattle_single TRAINER_TEAM_ROCKET_ADMIN, FiveIsland_RocketWarehouse_Text_Admin1Intro, FiveIsland_RocketWarehouse_Text_Admin1Defeat, FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough, MSGBOX_AUTOCLOSE
	end

FiveIsland_RocketWarehouse_EventScript_DefeatedAdmin1::
	getplayerxy PLAYER_X_POS, PLAYER_Y_POS
	specialvar VAR_RESULT, GetPlayerFacingDirection
	call_if_eq VAR_RESULT, DIR_NORTH, FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1
	msgbox FiveIsland_RocketWarehouse_Text_Admin1PostBattle
	closemessage
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch
	playse SE_PIN
	call FiveIsland_RocketWarehouse_EventScript_SetArrowsForReEntry
	special DrawWholeMapView
	waitse
	call_if_le PLAYER_X_POS, 24, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 25, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 26, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft
	call_if_eq PLAYER_X_POS, 27, FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown
	msgbox FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough
	release
	end

FiveIsland_RocketWarehouse_EventScript_PlayerFaceAdmin1::
	goto_if_eq PLAYER_X_POS, 27, Common_EventScript_NopReturn
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitchFar::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminWalkToSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFaceSwitch::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerLeft::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_RocketWarehouse_EventScript_AdminFacePlayerDown::
	applymovement LOCALID_WAREHOUSE_ADMIN1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitchFar::
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Movement_AdminWalkToSwitch::
	walk_right
	walk_in_place_faster_up
	step_end

FiveIsland_RocketWarehouse_Text_ManyMonsLockedInPen::
	.string "{JPN}おりの なかに たくさんの ポケモンが\n"
	.string "とじこめられている…$"

FiveIsland_RocketWarehouse_Text_PenUnlockedMonsFled::
	.string "{JPN}おりの かぎが あいている。\n"
	.string "ポケモンたちは にげた ようだ。$"

FiveIsland_RocketWarehouse_Text_Grunt2Intro::
	.string "{JPN}ここが ロケットだんの そうこと\n"
	.string "しってて きたのか?$"

FiveIsland_RocketWarehouse_Text_Grunt2Defeat::
	.string "{JPN}なに しやがるんだ?!$"

FiveIsland_RocketWarehouse_Text_Grunt2PostBattle::
	.string "{JPN}ロケットだんが かいさん しただと?\n"
	.string "どこの わくせいから きたんだ?$"

FiveIsland_RocketWarehouse_Text_Grunt1Intro::
	.string "{JPN}おや つよそうな ポケモンだな。\n"
	.string "うって くれるのか?\p"
	.string "ん?\n"
	.string "しょうぶ したかったのか?$"

FiveIsland_RocketWarehouse_Text_Grunt1Defeat::
	.string "{JPN}うっ でも…\n"
	.string "つよすぎる!$"

FiveIsland_RocketWarehouse_Text_Grunt1PostBattle::
	.string "{JPN}たかく かいとって やるぜ。\n"
	.string "ポケモンを うって くれよ!$"

FiveIsland_RocketWarehouse_Text_Grunt3Intro::
	.string "{JPN}おまえの ことは なかまから\n"
	.string "きいてるぜ。\p"
	.string "だが おまえ みたいな ガキが ボスの\n"
	.string "サカキさまを しってる わけがない!$"

FiveIsland_RocketWarehouse_Text_Grunt3Defeat::
	.string "{JPN}わ…わらう…んじゃ…ねえ…$"

FiveIsland_RocketWarehouse_Text_Grunt3PostBattle::
	.string "{JPN}おとなの することに くちを だすな\n"
	.string "この なまいきな チビめ!$"

FiveIsland_RocketWarehouse_Text_Admin1Intro::
	.string "{JPN}じぶんの していることが ただしいか\n"
	.string "まちがってるかなんて しらないし どうでもいい…\p"
	.string "わたしは サカキさまを しんじて\n"
	.string "いわれた とおりに するだけだ。$"

FiveIsland_RocketWarehouse_Text_Admin1Defeat::
	.string "{JPN}わたしは…\n"
	.string "くだけちった…$"

FiveIsland_RocketWarehouse_Text_Admin1PostBattle::
	.string "{JPN}おまえは じぶんの しんねんと\n"
	.string "りんりに したがって うごいている。\p"
	.string "いまなら わかる…$"

FiveIsland_RocketWarehouse_Text_MadeItSoYouCanComeBackThrough::
	.string "{JPN}そこから また なかに はいれる\n"
	.string "ように しておいた。\p"
	.string "この さきに そなえて ゆっくり\n"
	.string "やすんで きたら どうだ?\p"
	.string "つぎの かんぶは トレーナーとして\n"
	.string "わたしより はるかに うえだ。\p"
	.string "きびしい たたかいに なるから\n"
	.string "かくごして おけ。$"

FiveIsland_RocketWarehouse_Text_Admin2Intro::
	.string "{JPN}ヒーローごっこは もう\n"
	.string "じゅうぶんだ ぼうず。\p"
	.string "ロケットだんが かいさん したなどと\n"
	.string "うそを ふれまわって…\p"
	.string "われわれを こんらん させようと\n"
	.string "しているのが みえみえだ。\p"
	.string "あいにく こどもの うそに\n"
	.string "だまされるほど われわれは バカじゃない!\p"
	.string "さあ おこった おとなが どれだけ\n"
	.string "こわいか おしえて やろう!$"

FiveIsland_RocketWarehouse_Text_Admin2Defeat::
	.string "{JPN}ぐっ…\n"
	.string "つよすぎた…\p"
	.string "…\n"
	.string "そ それは サカキさまの バッジ!\p"
	.string "では ほんとうなのか?\n"
	.string "ロケットだんは ほんとうに かいさん したのか?$"

FiveIsland_RocketWarehouse_Text_Admin2PostBattle::
	.string "{JPN}この そうこは すてる…\p"
	.string "だが これで おわりと おもうな。\n"
	.string "このままで おわらせは しない。\p"
	.string "わたしは サカキさまを さがしだす。\n"
	.string "そして ロケットだんを ふっかつさせる!\l"
	.string "かならず…\p"
	.string "それまで さらばだ!$"

FiveIsland_RocketWarehouse_Text_ReportWithGraphsAndText::
	.string "{JPN}パソコンの がめんに グラフと\n"
	.string "ぶんしょうの レポートが ある。\p"
	.string "「じきはが ポケモンの しんかに\n"
	.string "およぼす えいきょう」…\p"
	.string "… … … … … …\p"
	.string "むずかしすぎて よく わからない…$"

FiveIsland_RocketWarehouse_Text_GideonIntro::
	.string "{JPN}もうすこしで サファイアを\n"
	.string "たかく うれる ところだったのに…\p"
	.string "そこへ おまえが のこのこ やってきて\n"
	.string "とりひきを ぶちこわしたんだ!\p"
	.string "フフ… フフフフ…\n"
	.string "おまえは ぜったい ゆるさない!$"

FiveIsland_RocketWarehouse_Text_GideonDefeat::
	.string "{JPN}ぐわっ! くそっ!\n"
	.string "くそっ くそっ!$"

FiveIsland_RocketWarehouse_Text_GideonPostBattle::
	.string "{JPN}うれなきゃ なんの かちも ない!\n"
	.string "もっていけよ!$"

FiveIsland_RocketWarehouse_Text_GetLostLeaveMeBe::
	.string "{JPN}まだ なにか ようか?\n"
	.string "さっさと きえろ ほっといてくれ。$"

FiveIsland_RocketWarehouse_Text_GiovannisKidHasRedHair::
	.string "{JPN}なんだ また おまえか?\p"
	.string "おまえ… まさか サカキさまの\n"
	.string "こども じゃないよな?\p"
	.string "いや そんな はずはない!\n"
	.string "サカキさまの こどもは あかい かみだ。\p"
	.string "おれに からむ りゆうは ないだろ。\n"
	.string "ほっといて くれ!$"

