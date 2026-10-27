BattleFrontier_BattlePalaceLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePalaceLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePalaceLobby_OnWarp
	.byte 0

BattleFrontier_BattlePalaceLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePalaceLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePalaceLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePalaceLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	palace_set PALACE_DATA_WIN_STREAK, 0
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven
	msgbox BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePalaceLobby_EventScript_DefeatedMaven::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded
	waitmessage
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded
	waitmessage
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	palace_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattlePalaceLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattlePalaceLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	palace_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_DoublesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattlePalaceLobby_EventScript_Attendant
	end

BattleFrontier_BattlePalaceLobby_EventScript_Attendant::
	palace_get PALACE_DATA_PRIZE
	goto_if_ne VAR_RESULT, ITEM_NONE, BattleFrontier_BattlePalaceLobby_EventScript_WonChallenge
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_WhichChallenge
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	palace_init
	palace_set PALACE_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePalaceLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePalaceLobby_Text_FollowMe, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor
	warp MAP_BATTLE_FRONTIER_BATTLE_PALACE_CORRIDOR, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExplainChallenge::
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge

BattleFrontier_BattlePalaceLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative LoadPlayerParty
BattleFrontier_BattlePalaceLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified, MSGBOX_DEFAULT
BattleFrontier_BattlePalaceLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeSingleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_AskTakeDoubleBattleChallenge::
	message BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge
	return

BattleFrontier_BattlePalaceLobby_EventScript_WalkToDoor::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor
	waitdooranim
	applymovement VAR_LAST_TALKED, BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor
	waitmovement 0
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor
	waitdooranim
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_SINGLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_PALACE_ATTENDANT_DOUBLES
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenSinglesHallDoor::
	opendoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_OpenDoublesHallDoor::
	opendoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseSinglesHallDoor::
	closedoor 5, 4
	return

BattleFrontier_BattlePalaceLobby_EventScript_CloseDoublesHallDoor::
	closedoor 19, 4
	return

BattleFrontier_BattlePalaceLobby_Movement_WalkToDoor:
	walk_up
	step_end

BattleFrontier_BattlePalaceLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePalaceLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePalaceLobby_EventScript_BlackBelt::
	msgbox BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Man::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_Maniac::
	msgbox BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway, MSGBOX_NPC
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 0, MULTI_BATTLE_PALACE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattlePalaceLobby_EventScript_RulesNature
	case 2, BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves
	case 3, BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered
	case 4, BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger
	case 5, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePalaceLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePalaceLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePalaceLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePalaceLobby_Text_WelcomeForSingleBattle:
	.string "{JPN}トレーナーの こころが\n"
	.string "ためされる ばしょ……\p"
	.string "バトルパレスへ ようこそ……\p"
	.string "ここでは シングル バトルホールへの\n"
	.string "ちょうせんを うけつけて おる$"

BattleFrontier_BattlePalaceLobby_Text_TakeSingleBattleChallenge:
	.string "{JPN}シングル バトルホールに\n"
	.string "ちょうせん するか?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainSingleBattleChallenge:
	.string "{JPN}バトルパレスには シングルバトルを\n"
	.string "おこなう ホールが いくつか あり\l"
	.string "シングル バトルホールと よばれて おる\p"
	.string "シングルバトルは ふつうと おなじだが\n"
	.string "ひとつだけ まもらねば ならぬ\l"
	.string "たいせつな ルールが ある\p"
	.string "トレーナーに ゆるされるのは\n"
	.string "ポケモンの いれかえ だけじゃ\p"
	.string "それ いがいに トレーナーが\n"
	.string "ポケモンに めいれい することは できぬ\p"
	.string "ポケモンは じぶんの せいかくの ままに\n"
	.string "じぶんで かんがえ たたかうのじゃ\p"
	.string "おぬしは ポケモンを しんじて\n"
	.string "みまもるのじゃ\p"
	.string "みごと トレーナー 7にんに\n"
	.string "れんぞくで かちぬけば\l"
	.string "バトルポイントを さしあげよう\p"
	.string "ちょうせんを ちゅうだん するなら\n"
	.string "レポートを かかねば ならぬ\p"
	.string "レポートを かかずに ちゅうだん すれば\n"
	.string "しっかくと なるぞ$"

BattleFrontier_BattlePalaceLobby_Text_ReturnWhenFortified:
	.string "{JPN}おのれの こころと ポケモンを きたえたら\n"
	.string "また くるがよい……$"

BattleFrontier_BattlePalaceLobby_Text_WhichChallenge:
	.string "{JPN}バトルホールは レベル50と\n"
	.string "オープンレベルの ふたつが ある\l"
	.string "どちらに ちょうせん するかな?$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLv50:
	.string "{JPN}はあ……\p"
	.string "ちょうせんに ひつような ポケモンが\n"
	.string "3びき そろって おらぬな\p"
	.string "さんかするには ちがう しゅるいの\n"
	.string "ポケモンが 3びき ひつようじゃ\p"
	.string "その ポケモンは みな\n"
	.string "レベル50 いかで なければ ならぬ\p"
	.string "また おなじ しゅるいの どうぐを\n"
	.string "もたせては ならぬ\p"
	.string "タマゴ{ENG}{STR_VAR_1}{JPN}。$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsEnd:
	.string "{JPN}じゅんびが できたら\n"
	.string "また くるが よい$"

BattleFrontier_BattlePalaceLobby_Text_NotEnoughValidMonsLvOpen:
	.string "{JPN}はあ……\p"
	.string "ちょうせんに ひつような ポケモンが\n"
	.string "3びき そろって おらぬな\p"
	.string "さんかするには ちがう しゅるいの\n"
	.string "ポケモンが 3びき ひつようじゃ\p"
	.string "また おなじ しゅるいの どうぐを\n"
	.string "もたせては ならぬ\p"
	.string "タマゴ{ENG}{STR_VAR_1}{JPN}。$"

BattleFrontier_BattlePalaceLobby_Text_NowSelectThreeMons:
	.string "{JPN}よし では ちょうせんする ポケモンを\n"
	.string "3びき えらぶのじゃ$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge2:
	.string "{JPN}バトルホールへ むかうまえに\n"
	.string "レポートを かくが よろしいか?$"

BattleFrontier_BattlePalaceLobby_Text_FollowMe:
	.string "{JPN}よかろう\n"
	.string "わしに ついてこい……$"

BattleFrontier_BattlePalaceLobby_Text_ResultsWillBeRecorded:
	.string "{JPN}おぬしの ポケモンの かつやくを\n"
	.string "みられて こうえいじゃ\p"
	.string "せいせきを レポートに かくぞ\n"
	.string "しばし またれよ……$"

BattleFrontier_BattlePalaceLobby_Text_FirmTrueBondsFor7WinStreak:
	.string "{JPN}7にんぬき たっせい とは……\p"
	.string "おぬしと ポケモンの こころの きずなは\n"
	.string "まことの ようじゃな……$"

BattleFrontier_BattlePalaceLobby_Text_FeatWillBeRecorded:
	.string "{JPN}せいせきを レポートに かくぞ\n"
	.string "しばし またれよ……$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_BattlePointsFor7WinStreak:
	.string "{JPN}7にんぬきの あかしに\n"
	.string "バトルポイントを さしあげよう……$"

BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize:
	.string "{JPN}しょうひんを うけとる\n"
	.string "すきまが ないようじゃな\p"
	.string "バッグを せいり してから\n"
	.string "また くるが よい$"

BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting:
	.string "{JPN}まっておったぞ……$"

BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge:
	.string "{JPN}バトルホールへ むかうまえに\n"
	.string "レポートを かくが よろしいか?$"

BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge:
	.string "{JPN}はあ……\p"
	.string "ぜんかい ちゃんと レポートを かかずに\n"
	.string "ちょうせんを おえたな?\p"
	.string "そのため おぬしの ちょうせんは\n"
	.string "しっかくと なった まことに ざんねんじゃ$"

@ Unused
BattleFrontier_BattlePalaceLobby_Text_ReceivedPrize:
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もらった!$"

BattleFrontier_BattlePalaceLobby_Text_LadyCanTellWhatMonsThink:
	.string "{JPN}がんばりやの オレには\n"
	.string "がんばりやの ポケモンが いちばん!\p"
	.string "こうげきは さいだいの ぼうぎょ!\n"
	.string "ようしゃない こうげきこそ さいこうだ!\p"
	.string "…って はなしが したかったんじゃ\n"
	.string "なくてさ\p"
	.string "ときどき すごく かわいい おねえさんが\n"
	.string "ここに くるんだよ\p"
	.string "その ひと ポケモンの きもちが\n"
	.string "わかるんだって\p"
	.string "そっちは よく わからないけど\n"
	.string "ほんとに かわいいんだ\p"
	.string "ん?\n"
	.string "なんで そんな めで みてるんだ?$"

BattleFrontier_BattlePalaceLobby_Text_NatureAndMovesKeyHere:
	.string "{JPN}ふむ……\p"
	.string "ここでの たたかいは ポケモンの\n"
	.string "せいかくと おぼえている わざが\l"
	.string "カギに なる ようだ\p"
	.string "もっと くわしく いうと\n"
	.string "わざが ポケモンの せいかくに\l"
	.string "どれだけ あっているか だな\p"
	.string "ポケモンが ピンチで\n"
	.string "ちからを だしきれない ときは\l"
	.string "わざと せいかくが あっているか\l"
	.string "みなおす ひつようが あるかもな$"

BattleFrontier_BattlePalaceLobby_Text_MonDocileButTransforms:
	.string "{JPN}うちの ポケモンは ふだん とても おとなしい\p"
	.string "でも バトルホールに いると\n"
	.string "ときどき まるで\l"
	.string "わるい なにかに かわったように みえる!\p"
	.string "すっごく こわい かんじに なるし\n"
	.string "ショックな くらいだよ!$"

BattleFrontier_BattlePalaceLobby_Text_WhatNatureFavorsChippingAway:
	.string "{JPN}あいてを よわらせたり……\n"
	.string "じわじわ せめて くれるのは\l"
	.string "どんな せいかくかな……\p"
	.string "…… いがいに のうてんき とか?\p"
	.string "…… まさかねぇ……$"

BattleFrontier_BattlePalaceLobby_Text_WelcomeForDoubleBattle:
	.string "{JPN}トレーナーの こころが\n"
	.string "ためされる ばしょ……\p"
	.string "バトルパレスへ ようこそ……\p"
	.string "ここでは ダブル バトルホールへの\n"
	.string "ちょうせんを うけつけて おる$"

BattleFrontier_BattlePalaceLobby_Text_TakeDoubleBattleChallenge:
	.string "{JPN}ダブル バトルホールに\n"
	.string "ちょうせん するか?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainDoubleBattleChallenge:
	.string "{JPN}バトルパレスには ダブルバトルを\n"
	.string "おこなう ホールが いくつか あり\l"
	.string "ダブル バトルホールと よばれて おる\p"
	.string "ダブルバトルは ふつうと おなじだが\n"
	.string "ひとつだけ まもらねば ならぬ\l"
	.string "たいせつな ルールが ある\p"
	.string "トレーナーに ゆるされるのは\n"
	.string "ポケモンの いれかえ だけじゃ\p"
	.string "それ いがいに トレーナーが\n"
	.string "ポケモンに めいれい することは できぬ\p"
	.string "ポケモンは じぶんの せいかくの ままに\n"
	.string "じぶんで かんがえ たたかうのじゃ\p"
	.string "おぬしは ポケモンを しんじて\n"
	.string "みまもるのじゃ\p"
	.string "みごと トレーナー 7にんに\n"
	.string "れんぞくで かちぬけば\l"
	.string "バトルポイントを さしあげよう\p"
	.string "ちょうせんを ちゅうだん するなら\n"
	.string "レポートを かいて おくのじゃ\p"
	.string "レポートを かかずに ちゅうだん すれば\n"
	.string "しっかくと なるぞ$"

BattleFrontier_BattlePalaceLobby_Text_ToDefeatMavenAnd7Trainers:
	.string "{JPN}パレスガーディアンを たおし\n"
	.string "7にんぬきを たっせいするとは……$"

BattleFrontier_BattlePalaceLobby_Text_PresentYouWithBattlePoints:
	.string "{JPN}おぬしと ポケモンの きずなを\n"
	.string "たたえ この\l"
	.string "バトルポイントを さしあげよう$"

BattleFrontier_BattlePalaceLobby_Text_LikeToRecordMatch:
	.string "{JPN}バトルパレスで\n"
	.string "さいごに おこなった たたかいを\l"
	.string "フロンティアパスに きろく するか?$"

BattleFrontier_BattlePalaceLobby_Text_RulesAreListed:
	.string "{JPN}バトルホールの ルールが かかれている!$"

BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading:
	.string "{JPN}どの せつめいを よみますか?$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics:
	.string "{JPN}ここでは ポケモンが じぶんで かんがえ\n"
	.string "たたかわなければ なりません\p"
	.string "やせいの ポケモンと ちがい ひとと\n"
	.string "くらす ポケモンは せいかくによって\l"
	.string "ふるまいが かわります$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature:
	.string "{JPN}せいかくに よっては ポケモンは\n"
	.string "なにが あっても こうげきを このみます\p"
	.string "また ある ポケモンは みを まもることを\n"
	.string "このみます\p"
	.string "さらに あいてを こまらせたり\n"
	.string "まどわせたりするのを このむ ものも います\p"
	.string "せいかくに よって ポケモンには\n"
	.string "すきで とくいな わざが\l"
	.string "あります\p"
	.string "また きらいで うまく つかえない\n"
	.string "わざも あります$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves:
	.string "{JPN}あいてに ちょくせつ ダメージを\n"
	.string "あたえる こうげきの わざ\p"
	.string "あいての こうげきに そなえたり\n"
	.string "HPを かいふく したり するための\l"
	.string "ぼうぎょの わざ\p"
	.string "そして どく や まひ などの\n"
	.string "じょうたいいじょうで あいてを\l"
	.string "よわらせる ちょっと かわった\l"
	.string "わざが あります\p"
	.string "ポケモンは この 3つの なかから\n"
	.string "わざを えらんで つかいます$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered:
	.string "{JPN}トレーナーの めいれいが ないと\n"
	.string "ポケモンは うまく つかえない\l"
	.string "わざが あります\p"
	.string "ポケモンは きらいな わざを\n"
	.string "うまく つかえません\p"
	.string "せいかくに あわない わざしか\n"
	.string "おぼえていないと ポケモンは\l"
	.string "ちからを はっきできない ことが おおいです$"

BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger:
	.string "{JPN}せいかくに よっては ピンチに なると\n"
	.string "せいかくに あわない わざを\l"
	.string "つかいはじめる ポケモンも います\p"
	.string "ピンチの とき ポケモンの ようすが\n"
	.string "おかしく なったら よく みてあげてください$"

