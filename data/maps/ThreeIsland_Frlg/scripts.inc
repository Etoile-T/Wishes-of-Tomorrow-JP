ThreeIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_OnTransition
	.byte 0

ThreeIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND
	call_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_EventScript_HideAntiBikers
	call_if_eq VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_EventScript_SetAntiBikersMovementAfterBikers
	end

ThreeIsland_EventScript_HideAntiBikers::
	setflag FLAG_HIDE_THREE_ISLAND_ANTIBIKERS
	return

ThreeIsland_EventScript_SetAntiBikersMovementAfterBikers::
	setobjectmovementtype LOCALID_THREE_ISLAND_ANTIBIKER1, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LOCALID_THREE_ISLAND_ANTIBIKER2, MOVEMENT_TYPE_LOOK_AROUND
	return

ThreeIsland_EventScript_Biker::
	lock
	setvar VAR_TEMP_1, 2
	call ThreeIsland_EventScript_BikerArgumentScene
	release
	end

ThreeIsland_EventScript_AntiBiker1::
	lock
	goto_if_set FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER, ThreeIsland_EventScript_AntiBiker1GotFullRestore
	goto_if_eq VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_EventScript_GiveFullRestore
	setvar VAR_TEMP_1, 0
	call ThreeIsland_EventScript_BikerArgumentScene
	release
	end

ThreeIsland_EventScript_AntiBiker1GotFullRestore::
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_Text_YouveGotImpressiveMons
	release
	end

ThreeIsland_EventScript_GiveFullRestore::
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_Text_ThankYouOhYourMonGotHurt
	checkitemspace ITEM_FULL_RESTORE
	goto_if_eq VAR_RESULT, FALSE, ThreeIsland_EventScript_NoRoomForFullRestore
	msgreceiveditem ThreeIsland_Text_GivenFullRestore, ITEM_FULL_RESTORE
	additem ITEM_FULL_RESTORE
	setflag FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER
	msgbox ThreeIsland_Text_YouveGotImpressiveMons
	release
	end

ThreeIsland_EventScript_NoRoomForFullRestore::
	msgbox ThreeIsland_Text_OhYourBagIsFull
	release
	end

ThreeIsland_EventScript_BikerArgumentScene::
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceLeft
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceLeft
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_GoBackToKanto
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceBiker
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_BossIsOnHisWay
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PlayerFaceUp
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceUp
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceAntiBiker
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER2, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_GetOffIslandNow
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceBiker
	applymovement LOCALID_THREE_ISLAND_BIKER3, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_WhosGonnaMakeMe
	return

ThreeIsland_EventScript_PlayerFaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

@ Unused
ThreeIsland_EventScript_PlayerFaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

ThreeIsland_EventScript_PlayerFaceLeft::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

ThreeIsland_EventScript_PlayerFaceRight::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

ThreeIsland_EventScript_PlayerFaceBiker::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ge VAR_0x8004, 9, ThreeIsland_EventScript_PlayerFaceUp
	goto ThreeIsland_EventScript_PlayerFaceRight
	end

ThreeIsland_EventScript_PlayerFaceAntiBiker::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ge VAR_0x8004, 9, ThreeIsland_EventScript_PlayerFaceLeft
	goto ThreeIsland_EventScript_PlayerFaceUp
	end

ThreeIsland_EventScript_AntiBiker2::
	lock
	goto_if_eq VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_EventScript_AntiBiker2BikersGone
	setvar VAR_TEMP_1, 1
	call ThreeIsland_EventScript_BikerArgumentScene
	release
	end

ThreeIsland_EventScript_AntiBiker2BikersGone::
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_Text_LostelleWentOffTowardsBondBridge
	release
	end

ThreeIsland_EventScript_BikerBossIntroTrigger::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_AreYouBossGoBackToKanto
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_JustGotHerePal
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_FollowersRaisingHavoc
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_OughtToBeThankingUs
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_YouCowardsToughInPack
	setvar VAR_MAP_SCENE_THREE_ISLAND, 3
	releaseall
	end

ThreeIsland_Movement_SpeakLeft::
	walk_in_place_left
	step_end

ThreeIsland_Movement_SpeakRight::
	walk_in_place_right
	step_end

ThreeIsland_EventScript_BattleBikersTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerMidLeft::
	lockall
	setvar VAR_TEMP_1, 1
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerMid::
	lockall
	setvar VAR_TEMP_1, 2
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerMidRight::
	lockall
	setvar VAR_TEMP_1, 3
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerRight::
	lockall
	setvar VAR_TEMP_1, 4
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersScene::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_THREE_ISLAND_BIKER1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_THREE_ISLAND_BIKER1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_WannaMakeSomethingOfYourStaring, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ThreeIsland_EventScript_LeaveBikersAlone
	msgbox ThreeIsland_Text_Biker1Intro
	setvar VAR_LAST_TALKED, LOCALID_THREE_ISLAND_BIKER1
	trainerbattle_no_intro TRAINER_BIKER_GOON, ThreeIsland_Text_Biker1Defeat
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_BikerSpeak
	waitmovement 0
	msgbox ThreeIsland_Text_Biker1PostBattle
	closemessage
	applymovement LOCALID_THREE_ISLAND_BIKER2, ThreeIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_Biker2Intro
	setvar VAR_LAST_TALKED, LOCALID_THREE_ISLAND_BIKER2
	trainerbattle_no_intro TRAINER_BIKER_GOON_2, ThreeIsland_Text_Biker2Defeat
	applymovement LOCALID_THREE_ISLAND_BIKER2, ThreeIsland_Movement_BikerSpeak
	waitmovement 0
	msgbox ThreeIsland_Text_Biker2PostBattle
	closemessage
	applymovement LOCALID_THREE_ISLAND_BIKER3, ThreeIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_Biker3Intro
	setvar VAR_LAST_TALKED, LOCALID_THREE_ISLAND_BIKER3
	trainerbattle_no_intro TRAINER_BIKER_GOON_3, ThreeIsland_Text_Biker3Defeat
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER4, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_THREE_ISLAND_BIKER5, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox ThreeIsland_Text_Biker3PostBattle
	closemessage
	delay 45
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PaxtonApproachLeft
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PaxtonApproachMidLeft
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PaxtonApproachMid
	call_if_eq VAR_TEMP_1, 3, ThreeIsland_EventScript_PaxtonApproachMidRight
	call_if_eq VAR_TEMP_1, 4, ThreeIsland_EventScript_PaxtonApproachRight
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_PaxtonIntro
	setvar VAR_LAST_TALKED, LOCALID_PAXTON
	trainerbattle_no_intro TRAINER_CUE_BALL_PAXTON, ThreeIsland_Text_PaxtonDefeat
	msgbox ThreeIsland_Text_PaxtonPostBattle
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_PAXTON
	removeobject LOCALID_THREE_ISLAND_BIKER1
	removeobject LOCALID_THREE_ISLAND_BIKER2
	removeobject LOCALID_THREE_ISLAND_BIKER3
	removeobject LOCALID_THREE_ISLAND_BIKER4
	removeobject LOCALID_THREE_ISLAND_BIKER5
	removeobject LOCALID_THREE_ISLAND_BIKER6
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_THREE_ISLAND, 4
	releaseall
	end

ThreeIsland_EventScript_PaxtonApproachLeft::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachLeft
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachMidLeft::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMidLeft
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachMid::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMid
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachMidRight::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMidRight
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachRight::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachRight
	waitmovement 0
	return

ThreeIsland_EventScript_LeaveBikersAlone::
	msgbox ThreeIsland_Text_ThatsSmart
	closemessage
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerLeaveBikers
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_Biker1ReturnToPack
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

ThreeIsland_Movement_PlayerLeaveBikers::
	walk_down
	step_end

ThreeIsland_Movement_BikerApproach::
	walk_down
	step_end

ThreeIsland_Movement_Biker1ReturnToPack::
	walk_up
	walk_in_place_faster_left
	step_end

ThreeIsland_Movement_BikerSpeak::
	walk_in_place_down
	step_end

ThreeIsland_Movement_PaxtonApproachLeft::
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

ThreeIsland_Movement_PaxtonApproachMidLeft::
	walk_down
	step_end

ThreeIsland_Movement_PaxtonApproachMid::
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

ThreeIsland_Movement_PlayerFacePaxton::
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

ThreeIsland_Movement_PaxtonApproachMidRight::
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_right
	step_end

ThreeIsland_Movement_PaxtonApproachRight::
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_faster_right
	step_end

ThreeIsland_EventScript_Woman::
	msgbox ThreeIsland_Text_WouldntWantToSeeBikersHereAgain, MSGBOX_NPC
	end

ThreeIsland_EventScript_LittleBoy::
	msgbox ThreeIsland_Text_WhenDodouEvolvesGoingToPlayGame, MSGBOX_NPC
	end

ThreeIsland_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox ThreeIsland_Text_Doduo
	waitmoncry
	release
	end

ThreeIsland_EventScript_IslandSign::
	msgbox ThreeIsland_Text_IslandSign, MSGBOX_SIGN
	end

ThreeIsland_EventScript_Biker6::
	msgbox ThreeIsland_Text_IslandBelongsToUs, MSGBOX_NPC
	end

ThreeIsland_Text_IslandSign::
	.string "{JPN}3のしま\n"
	.string "かぞくの きずなの しま$"

ThreeIsland_Text_IslandBelongsToUs::
	.string "{JPN}ヒャッホー!\p"
	.string "きょうから この しまは\n"
	.string "おれたちの ものだ!$"

ThreeIsland_Text_GoBackToKanto::
	.string "{JPN}あんたらに そうおんや めいわくを\n"
	.string "もちこまれても こまるんだ!\p"
	.string "カントーに かえって\n"
	.string "くれないか!$"

ThreeIsland_Text_BossIsOnHisWay::
	.string "{JPN}おい なくなら よそで なきな\n"
	.string "もうすぐ ボスが くるんだ\p"
	.string "ボスが きたら わすれられない\n"
	.string "イカした バイクショーを\l"
	.string "みせてやるぜ!$"

ThreeIsland_Text_GetOffIslandNow::
	.string "{JPN}な なに!? じょうだんじゃない!\n"
	.string "いますぐ しまから でていけ!$"

ThreeIsland_Text_WhosGonnaMakeMe::
	.string "{JPN}だれが おいだすって?$"

ThreeIsland_Text_AreYouBossGoBackToKanto::
	.string "{JPN}あんたが ボスか?\n"
	.string "いますぐ カントーに かえれ!$"

ThreeIsland_Text_JustGotHerePal::
	.string "{JPN}はあ?\p"
	.string "おれは いま きたとこだぜ\p"
	.string "なんだよ その けんかごしの たいどは\n"
	.string "ずいぶん つめてえじゃねえか!$"

ThreeIsland_Text_FollowersRaisingHavoc::
	.string "{JPN}あんたの てしたどもが バイクで\n"
	.string "あばれまわってるんだ\p"
	.string "あいつらが この しまで どれだけ\n"
	.string "めいわくを かけてるか\l"
	.string "わかってるのか?$"

ThreeIsland_Text_OughtToBeThankingUs::
	.string "{JPN}いや ぜんぜん わかんねえな\p"
	.string "この ばしょを みてみろよ\n"
	.string "なにを たのしみに してるんだ?\p"
	.string "こんな ねむたい むらを もりあげてる\n"
	.string "おれたちに かんしゃ してほしいね\p"
	.string "でも まあ どうしてもって いうなら\n"
	.string "おれたちを おいだして みな$"

ThreeIsland_Text_YouCowardsToughInPack::
	.string "{JPN}ぐぬぬ… ひきょうものめ…\n"
	.string "むれると いきがりやがって…$"

ThreeIsland_Text_WannaMakeSomethingOfYourStaring::
	.string "{JPN}おまえ なに じろじろ みてんだ?\n"
	.string "しつれいだって しらねえのか?\p"
	.string "なんか もんくでも\n"
	.string "あんのか?$"

ThreeIsland_Text_ThatsSmart::
	.string "{JPN}かしこいな\n"
	.string "よけいな くちを だすんじゃねえ$"

ThreeIsland_Text_Biker1Intro::
	.string "{JPN}へっ その どきょう きにいったぜ\n"
	.string "おまえが かねを はらう はめに なるがな…$"

ThreeIsland_Text_Biker1Defeat::
	.string "{JPN}な…\n"
	.string "なんなんだ この ガキは!?$"

ThreeIsland_Text_Biker1PostBattle::
	.string "{JPN}ちくしょう…\n"
	.string "わらうんじゃねえぞ!$"

ThreeIsland_Text_Biker2Intro::
	.string "{JPN}おまえ カントーから きたんだろ?\n"
	.string "おれたちの みかた しろよ!$"

ThreeIsland_Text_Biker2Defeat::
	.string "{JPN}ふざけんな!$"

ThreeIsland_Text_Biker2PostBattle::
	.string "{JPN}なんなんだよ おまえ\n"
	.string "そんなに あつく なって\p"
	.string "ぜんぜん イケてねえぜ!$"

ThreeIsland_Text_Biker3Intro::
	.string "{JPN}せっかく ボスを よんだのに\n"
	.string "おまえが ぶちこわしやがって!\p"
	.string "はじ かかせやがって!$"

ThreeIsland_Text_Biker3Defeat::
	.string "{JPN}… … …   … … …$"

ThreeIsland_Text_Biker3PostBattle::
	.string "{JPN}ボス たのむから この ガキ\n"
	.string "なんとか してくださいよ!$"

ThreeIsland_Text_PaxtonIntro::
	.string "{JPN}みてたけどよ もう それくらいに\n"
	.string "しときな\p"
	.string "なんだ おまえ こいつらの\n"
	.string "なかまか なんかか?\p"
	.string "だったら こいつらの かわりに\n"
	.string "おれが あいてを してもらうぜ$"

ThreeIsland_Text_PaxtonDefeat::
	.string "{JPN}わかった もう いい!\n"
	.string "おのぞみどおり でてってやるよ!\p"
	.string "こんな たいくつな しまとは\n"
	.string "せいせい するぜ!$"

ThreeIsland_Text_PaxtonPostBattle::
	.string "{JPN}ふん! せいぜい その いなかもんと\n"
	.string "つるんでるが いいさ!$"

ThreeIsland_Text_ThankYouOhYourMonGotHurt::
	.string "{JPN}ありがとう! あいつらには\n"
	.string "ほんとに めいわく してたんだ\p"
	.string "あっ わたしの せいで きみの\n"
	.string "ポケモンが きずついて しまったね$"

ThreeIsland_Text_GivenFullRestore::
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "かいふくのくすりを もらった!$"

ThreeIsland_Text_OhYourBagIsFull::
	.string "{JPN}あれ?\n"
	.string "バッグが いっぱいだね$"

ThreeIsland_Text_YouveGotImpressiveMons::
	.string "{JPN}きみは ほんとに すごい\n"
	.string "ポケモンを つれてるね$"

ThreeIsland_Text_LostelleWentOffTowardsBondBridge::
	.string "{JPN}きみみたいに つよい ひとが\n"
	.string "ここに すんでくれたら いいのに\p"
	.string "せめて しばらくは ここに\n"
	.string "いてほしいな\p"
	.string "…え? なんだって?\n"
	.string "ロステルを さがしてるの?\p"
	.string "ロステルなら すこし まえに\n"
	.string "きずなばしの ほうへ いったよ$"

ThreeIsland_Text_WouldntWantToSeeBikersHereAgain::
	.string "{JPN}3のしまは じつは この あたりの\n"
	.string "しまで いちばん ひとが おおいんだ\p"
	.string "それでも もうすこし にぎやかでも いい\p"
	.string "でも あの ぼうそうぞくみたいな\n"
	.string "れんちゅうは もう ごめんだね$"

ThreeIsland_Text_WhenDodouEvolvesGoingToPlayGame::
	.string "{JPN}きのみのもりで ドードーを\n"
	.string "きたえるんだ\p"
	.string "しんかしたら 2のしまで\n"
	.string "ゲームを するんだ$"

ThreeIsland_Text_Doduo::
	.string "{JPN}ドードー: ギギーッ!$"

