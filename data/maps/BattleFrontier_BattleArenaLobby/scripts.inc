BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ARENA_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "{JPN}トレーナーの とうしが\n"
	.string "ためされる ばしょ!\p"
	.string "バトルアリーナへ ようこそ!\p"
	.string "わたくしが かちぬきチームバトルを\nごあんない いたしますぞ!$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "{JPN}バトルアリーナに\n"
	.string "ちょうせん されますかな?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "{JPN}またの ちょうせんを\n"
	.string "おまちして おりますぞ!$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "{JPN}バトルアリーナでは\n"
	.string "かちぬきチームバトルを おこないます!\p"
	.string "さんかしゃは みな ポケモン\n"
	.string "3びきの チームで ちょうせん しますぞ!\p"
	.string "3びきの ポケモンは\n"
	.string "たたかいに でる じゅんばんに ならべてくだされ!\p"
	.string "たたかいでは ポケモンが ならべた\n"
	.string "じゅんばんに 1ぴきずつ でますぞ!\p"
	.string "いちど たたかいに でた ポケモンは\n"
	.string "しょうぶが つくまで ひっこめられませぬ!\p"
	.string "3ターンで しょうぶが\n"
	.string "つかないときは はんていと なりますぞ!\p"
	.string "ちょうせんを ちゅうだん するときは\n"
	.string "レポートを かいてくだされ!\p"
	.string "レポートを かかないと\n"
	.string "ちょうせんを つづけられませぬぞ!\p"
	.string "みごと トレーナー 7にんに\n"
	.string "れんぞくで かちぬかれたら\l"
	.string "バトルポイントを さしあげますぞ!$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "{JPN}バトルアリーナへ おつれする まえに\n"
	.string "レポートを かきますが よろしいですかな?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "{JPN}バトルアリーナには\n"
	.string "レベル50と オープンレベルと ありますが\l"
	.string "どちらに まいられますかな?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "{JPN}では さんかする ポケモンを\n"
	.string "3びき おえらび くだされ!$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "{JPN}ちょうせんしゃ どの!\p"
	.string "さんかに ひつような ポケモンが\n"
	.string "3びき そろって おりませぬぞ!\p"
	.string "さんかするには ちがう しゅるいの\n"
	.string "ポケモンが 3びき ひつようですぞ!\p"
	.string "また もたせる どうぐも\n"
	.string "おなじ しゅるいでは いけませぬ!\p"
	.string "タマゴ{ENG}{STR_VAR_1}{JPN}。$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsEnd:
	.string "{JPN}じゅんびが できましたら\n"
	.string "また おこし くだされ!$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "{JPN}ちょうせんしゃ どの!\p"
	.string "さんかに ひつような ポケモンが\n"
	.string "3びき そろって おりませぬぞ!\p"
	.string "さんかするには ちがう しゅるいの\n"
	.string "ポケモンが 3びき ひつようですぞ!\p"
	.string "3びきの ポケモンは みな\n"
	.string "レベル50 いかで なければなりませぬ!\p"
	.string "また もたせる どうぐも\n"
	.string "おなじ しゅるいでは いけませぬ!\p"
	.string "タマゴ{ENG}{STR_VAR_1}{JPN}。$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "{JPN}では バトルアリーナへ\n"
	.string "おつれいたしますぞ!$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "{JPN}ちょうせんしゃ どの!\p"
	.string "ぜんかい レポートを かかずに\n"
	.string "しゅうりょう されましたな?\p"
	.string "ざんねんですが そのため\n"
	.string "ちょうせんは しっかくと\l"
	.string "なりましたぞ!\p"
	.string "もちろん あらためて さいしょから\n"
	.string "ちょうせん できますぞ!$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "{JPN}トレーナー 7にんぬき たっせい\n"
	.string "まことに おみごとで ございました!$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "{JPN}せいせきを レポートに かきますので\n"
	.string "おまちくだされ!$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "{JPN}7にんぬきを たっせい されましたので\n"
	.string "この しょうひんを おうけとり くだされ!$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もらった!$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "{JPN}……おおっ!\n"
	.string "バッグが いっぱいの ようですな!\p"
	.string "バッグを せいりしてから\n"
	.string "しょうひんを うけとりに きてくだされ!$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "{JPN}さんか まことに ありがとう ございました!\p"
	.string "レポートを かきますので おまちくだされ!$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "{JPN}またの ちょうせんを\n"
	.string "おまちして おりますぞ!$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "{JPN}おこしを おまちして\n"
	.string "おりましたぞ!\p"
	.string "バトルアリーナへ おつれする まえに\n"
	.string "レポートを かきますので\l"
	.string "おまちくだされ!$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "{JPN}さいごの バトルアリーナの たたかいを\n"
	.string "フロンティアパスに きろく されますかな?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "{JPN}はんていで まけちゃった……\p"
	.string "まもる わざ ばっかりで\n"
	.string "せめなかったのが よくなかった みたい……$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "{JPN}はんていで かったぜ!\p"
	.string "あいての ポケモンに\n"
	.string "わざを かくじつに あてたのが よかったぜ!$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "{JPN}はんていで ひきわけ だったよ\p"
	.string "じかんぎれの とき こっちの ポケモンも\n"
	.string "あいての ポケモンも のこりの HPが\l"
	.string "おなじ くらい だったからねぇ……$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "{JPN}バトルアリーナでは ポケモンの\n"
	.string "じゅんばんが すっごく だいじなんだ!\p"
	.string "たとえば 1ばんめの ポケモンが\n"
	.string "ある タイプに よわいなら\l"
	.string "2ばんめには その あいてに\l"
	.string "こうかばつぐんの わざを もつ\l"
	.string "ポケモンを おいてみて!\p"
	.string "そうすれば つよい チームが\n"
	.string "つくれると おもうよ!$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "{JPN}かちぬきチームバトルの ルールが かかれている!$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "{JPN}どの せつめいを よみますか?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "{JPN}かちぬきチームバトルには ふつうの\n"
	.string "たたかいと ちがう とくべつな ルールが あります\p"
	.string "まず 1かいの たたかいは\n"
	.string "3ターンで しゅうりょうと なります\p"
	.string "3ターンで しょうぶが つかないときは\n"
	.string "しんぱんに よる はんていに なります\p"
	.string "はんていは ポケモンの たたかいかたを\n"
	.string "みて しょうしゃを けってい します\p"
	.string "また しょうぶの けっちゃくが つくまで\n"
	.string "ポケモンの こうたいは できません$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "{JPN}1つめの はんてい ポイントは「こころ」\n"
	.string "どれだけ せっきょくてきに せめたかを\l"
	.string "みます\p"
	.string "トレーナーが こうげきわざを\n"
	.string "どれだけ めいれい したかで\l"
	.string "ひょうかが きまります$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "{JPN}2つめの はんてい ポイントは「わざ」\n"
	.string "ポケモンの わざを どれだけ うまく\l"
	.string "つかえたかを みます\p"
	.string "わざが うまく きまれば\n"
	.string "「わざ」の ひょうかが あがります\p"
	.string "わざが しっぱい すると\n"
	.string "「わざ」の ひょうかが さがります\p"
	.string "こうげきわざの ばあいは「こうかは\n"
	.string "ばつぐんだ」なら ひょうかが あがり\l"
	.string "「いまひとつ」なら\l"
	.string "さがります\p"
	.string "まもる や みきり などの わざでは\n"
	.string "「わざ」の ひょうかは あがりません\p"
	.string "あいてが まもる や みきりを つかい\n"
	.string "じぶんの ポケモンの わざが\l"
	.string "あたらなかった ときは「わざ」の\l"
	.string "ひょうかは さがりません$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "{JPN}3つめの はんてい ポイントは「からだ」\n"
	.string "たたかいの おわりに HPが どれだけ\l"
	.string "のこっているかで きまります\p"
	.string "たたかいの はじめの HPと\n"
	.string "おわりに のこった HPを\l"
	.string "くらべて ひょうか されます$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "{JPN}アリーナタイクーンから しょうりを うばい\n"
	.string "トレーナー 7にんぬきも たっせい!\p"
	.string "まことに みごとな ちょうせんで\n"
	.string "ございました!$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "{JPN}ちょうせんしゃ どの その\n"
	.string "ふくつの とうしを たたえ\l"
	.string "バトルポイントを おうけとり くだされ!$"
