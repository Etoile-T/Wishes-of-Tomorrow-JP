VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnTransition:
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 2, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, 3, 24
	setobjectmovementtype LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	applymovement LOCALID_VICTORY_ROAD_ENTRANCE_WALLY, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	copyobjectxytoperm LOCALID_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "{JPN}ミツル: あっ! {ENG}{PLAYER}{JPN}さん!\p"
	.string "ぼくが ここに いて びっくりしたでしょ!\p"
	.string "ここまで これたのは ぜんぶ\n"
	.string "みんな あなたの おかげです!\p"
	.string "{ENG}{PLAYER}{JPN}さん あのとき まけたから\n"
	.string "ぼくは つよく なれたんです!\p"
	.string "でも もう まけません!\p"
	.string "かってみせる! ぼくに ゆうきと\n"
	.string "ちからを くれた ポケモンの ために!\p"
	.string "じゃあ…… いきます!$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "{JPN}うわぁ!\n"
	.string "やっぱり {ENG}{PLAYER}{JPN}さんは つよいよ!$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "{JPN}ミツル: …… こんかいは\n"
	.string "{ENG}{PLAYER}{JPN}さんに かてなかった けど\l"
	.string "いつか きっと おいついて みせるからね!$"

VictoryRoad_1F_Text_WallyIntro:
	.string "{JPN}ミツル: あっ! {ENG}{PLAYER}{JPN}さん!\p"
	.string "ぼく あのときより つよく なったんです!\n"
	.string "{ENG}{PLAYER}{JPN}さんに みてほしくて!\p"
	.string "じゃあ…… いきます!$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "{JPN}うわぁ!\n"
	.string "やっぱり {ENG}{PLAYER}{JPN}さんは つよいよ!$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "{JPN}ミツル: …… こんかいも\n"
	.string "{ENG}{PLAYER}{JPN}さんに かてなかった けど\l"
	.string "いつか きっと おいついて……\p"
	.string "ポケモンリーグに ちょうせん するんだ!$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "{JPN}ここまでは なんどか これたが\n"
	.string "さいごの みちのりが ながすぎるよ……$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "{JPN}また ここで ゆめが おわったか……$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "{JPN}ここまで きたなら その\n"
	.string "いきおいで チャンピオンに なれよ!\l"
	.string "きみなら できるさ!$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "{JPN}せっかく ここまで きたんだ。\n"
	.string "いまさら まけるなんて ありえないよ!$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "{JPN}まさか……\n"
	.string "まけたのか……?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "{JPN}ここで まけた……\p"
	.string "ということは まだ チャンピオンに なる\n"
	.string "しかくが ないと いうことか……$"

VictoryRoad_1F_Text_HopeIntro:
	.string "{JPN}この はてしなく けわしい みち こそ\n"
	.string "まさに チャンピオンへの みち なのよ!$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "{JPN}すばらしい たたかいかた ね……$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "{JPN}あなたには チャンピオンに なれる\n"
	.string "かのうせいが あるみたいね。$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "{JPN}チャンピオンロード とは なにか?\n"
	.string "かてたら おしえてやろう!$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "{JPN}よし!\n"
	.string "みごとだ!$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "{JPN}ここを ぶじに ぬけきることが\n"
	.string "ポケモンチャンピオンを めざす\l"
	.string "トレーナーの さいごの しれん なんだ。\p"
	.string "だから チャンピオンロードと\n"
	.string "よばれて いるのさ。$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "{JPN}ここまで きた ひとに\n"
	.string "いうことは なにも ないわ。いくわよ!$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "{JPN}なんて ぶざまな……$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "{JPN}ふん…… どうぞ さきへ いけば?\n"
	.string "わたしは べつに かまわないわ。$"
