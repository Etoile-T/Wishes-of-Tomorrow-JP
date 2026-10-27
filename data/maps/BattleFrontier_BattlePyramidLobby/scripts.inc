BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	call BattleFrontier_ShowCaughtBannedSpecies
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_PYRAMID_LOBBY_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PYRAMID_LOBBY_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement LOCALID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "{JPN}トレーナーの ゆうきが\n"
	.string "ためされる ばしょ!\p"
	.string "バトルピラミッドへ ようこそ!\p"
	.string "わたしは バトルアドベンチャーの\n"
	.string "あんないやく ですぞ。$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "{JPN}バトルアドベンチャーに いどむ\n"
	.string "ゆうきは おありですかな?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "{JPN}また ちょうせんを おまちしてますぞ!$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "{JPN}バトルアドベンチャーとは\n"
	.string "ピラミッドを たんけんし\l"
	.string "ちょうじょうを めざす しょうぶです。\p"
	.string "ピラミッドの なかは 7だんの\n"
	.string "めいろに なっており うでききの\l"
	.string "トレーナーと やせいの ポケモンが います。\p"
	.string "はいるときは ポケモン 3びきを\n"
	.string "どうぐを もたせずに つれていきます。\p"
	.string "のぼっている あいだは どうぐようの\n"
	.string "バトルバッグを おわたし します。\p"
	.string "ちょうせんに しっぱいすると\n"
	.string "バトルバッグの どうぐは きえます。\p"
	.string "ちょうせんを ちゅうだん するときは\n"
	.string "「やすむ」を えらんで\l"
	.string "レポートを かいて ください。\p"
	.string "レポートを かかずに ちゅうだんすると\n"
	.string "しっかく と なりますぞ。$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "{JPN}ピラミッドには レベル50と\n"
	.string "オープンレベルの 2コースが あります。\l"
	.string "どちらに はいられますかな?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "{JPN}よろしい。 では つれていく\n"
	.string "ポケモンを 3びき おえらびくだされ!$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "{JPN}ぼうけんしゃよ すこし もんだいが!\p"
	.string "ちょうせんに さんか できる\n"
	.string "ポケモンが 3びき いないようですな。\p"
	.string "ポケモンの どうぐも ぜんぶ\n"
	.string "はずしておいて くだされ。\p"
	.string "タマゴ{ENG}{STR_VAR_1}{JPN}。$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "{JPN}ぼうけんしゃよ すこし もんだいが!\p"
	.string "ちょうせんに さんか できる\n"
	.string "ポケモンが 3びき いないようですな。\p"
	.string "ポケモンは ちがう しゅるいで\n"
	.string "レベル50いかの 3びきが ひつようです。\p"
	.string "ポケモンの どうぐも ぜんぶ\n"
	.string "はずしておいて くだされ。\p"
	.string "タマゴ{ENG}{STR_VAR_1}{JPN}。$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsEnd:
	.string "{JPN}じゅんびが できましたら\n"
	.string "また こえを おかけ くだされ!$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "{JPN}バトルピラミッドへ はいる まえに\n"
	.string "レポートを かきますが よろしいかな?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "{JPN}では バトルピラミッドの なかへ\n"
	.string "おつれいたしますぞ!$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "{JPN}たんけんの あいだ バッグは\n"
	.string "{ENG}{PLAYER}{JPN}さまから おあずかりします。$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "{JPN}かわりに ぜんかい おつかいになった\n"
	.string "この バトルバッグを おもちくだされ!$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "{JPN}かわりに こちらの\n"
	.string "バトルバッグを おもちくだされ!$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{JPN}{ENG}{PLAYER}{JPN}は バッグを あずけて\n"
	.string "バトルバッグを うけとった!$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "{JPN}こちらの ゆかを ふんで いただくと\n"
	.string "ピラミッドの うえの だんへと\l"
	.string "すすむことが できますぞ!\p"
	.string "ぶじ ぼうけんが すすむことを\n"
	.string "いのって おりますぞ!$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "{JPN}たんけんしゃよ たいへんな もんだいが!\p"
	.string "ぜんかい レポートを かかずに\n"
	.string "ちょうせんを おえられましたな。\p"
	.string "ざんねん ですが そのため\n"
	.string "ちょうせんは しっかく と なりました。\p"
	.string "おあずかりしていた バッグを\n"
	.string "おかえし しますぞ。\p"
	.string "{ENG}{PLAYER}{JPN}は バッグを かえしてもらった!$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "{JPN}おかえりなさいませ!\p"
	.string "みごとに ピラミッドを せいは!\n"
	.string "すばらしい ですな!$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "{JPN}おっと すこし もんだいが。\p"
	.string "どうぐを もっている ポケモンが\n"
	.string "いるようですな。\p"
	.string "ざんねんながら ピラミッドで えた\n"
	.string "どうぐは もちだせないのです。$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "{JPN}ポケモンが もつ どうぐは ぜんぶ\n"
	.string "{ENG}{PLAYER}{JPN}さまの バトルバッグへ うつします。$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "{JPN}ざんねんながら バトルバッグに\n"
	.string "どうぐが ぜんぶ はいりきりません。\p"
	.string "バトルバッグと ポケモンに のこす\n"
	.string "どうぐを えらんで くだされ。$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "{JPN}ポケモンに\n"
	.string "まだ どうぐを もたせていますぞ!$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "{JPN}バトルバッグと ポケモンに のこす\n"
	.string "どうぐを えらんで くだされ。$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{JPN}{ENG}{PLAYER}{JPN}は ポケモンに もたせている\n"
	.string "どうぐを ぜんぶ かえした!$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "{JPN}つかった バトルバッグは つぎの\n"
	.string "ちょうせんまで おあずかりしますぞ。\p"
	.string "{ENG}{PLAYER}{JPN}は バトルバッグを わたして\n"
	.string "バッグを かえしてもらった!$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "{JPN}せいせきを レポートに かきますので\n"
	.string "おまちくだされ!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "{JPN}バトルピラミッド せいはの きねんに\n"
	.string "この しょうひんを おうけとりくだされ!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{JPN}{ENG}{PLAYER}{JPN}は しょうひんの\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もらった!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "{JPN}……おや……\n"
	.string "バッグが いっぱいの ようですな。\p"
	.string "バッグの なかみを せいりしてから\n"
	.string "また おこしくだされ!$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "{JPN}ざんねん でしたな……\p"
	.string "おあずかりしていた バッグを\n"
	.string "おかえし しますぞ。\p"
	.string "{ENG}{PLAYER}{JPN}は バッグを かえしてもらった!$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "{JPN}またの ちょうせんを\n"
	.string "おまちして おりますぞ!$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "{JPN}おこしを おまちして\n"
	.string "おりましたぞ!\p"
	.string "こちらが ピラミッドを せいはした\n"
	.string "しょうひん ですぞ。$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "{JPN}ようこそ……\p"
	.string "ピラミッドで まちうける わざわいを\n"
	.string "うらなって さしあげましょう……$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "{JPN}… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "はっ!$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "{JPN}とびちる ひばなが みえます……\p"
	.string "……そして まひに くるしむ\n"
	.string "あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "{JPN}どくが みえます……\p"
	.string "……そして どくに くるしむ\n"
	.string "あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "{JPN}まっかな ほのおが みえます……\p"
	.string "……そして やけどに くるしむ\n"
	.string "あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "{JPN}むくわれぬ いかりの すさまじい\n"
	.string "プレッシャーを かんじます……\p"
	.string "これは のろい……\p"
	.string "……そして PPを うばわれ\n"
	.string "なすすべもなく わるあがきを\l"
	.string "する あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "{JPN}そらたかく うかぶ ポケモンが みえます……\p"
	.string "……そして じめんの わざが きかず\n"
	.string "くやしがる あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "{JPN}あしもとの じめんから わきあがる\n"
	.string "すさまじい ちからを かんじます……\p"
	.string "……そして その ちからから\n"
	.string "にげられない ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "{JPN}こおりタイプの ポケモンが みえます……\p"
	.string "……そして こおりの ちからと\n"
	.string "たたかう あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "{JPN}つかうものを きけんに さらす\n"
	.string "わざの あらしが みえます……\p"
	.string "……そして それに たおれる\n"
	.string "あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "{JPN}エスパータイプの ポケモンが みえます……\p"
	.string "……そして エスパーの わざに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "{JPN}いわタイプの ポケモンが みえます……\p"
	.string "……そして いわの わざに くるしむ\n"
	.string "あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "{JPN}かくとうタイプの ポケモンが みえます……\p"
	.string "……そして かくとうの わざに うちのめされる\n"
	.string "あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "{JPN}あまごい…… にほんばれ……\n"
	.string "すなあらし…… あられ……\p"
	.string "てんきで つよくなる\n"
	.string "ポケモンが みえます……\p"
	.string "……そして さまざまな わざに\n"
	.string "まどわされる ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "{JPN}むしタイプの ポケモンが みえます……\p"
	.string "……そして さまざまな こうげきに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "{JPN}あくタイプの ポケモンが みえます……\p"
	.string "……そして あくタイプの わざに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "{JPN}みずタイプの ポケモンが みえます……\p"
	.string "……そして みずタイプの わざに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "{JPN}ゴーストタイプの ポケモンが みえます……\p"
	.string "……そして ゴーストタイプの わざに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "{JPN}はがねタイプの ポケモンが みえます……\p"
	.string "……そして すさまじく つよい わざに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "{JPN}そらを とぶ ポケモンが みえます……\p"
	.string "……そして すさまじく つよい わざに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "{JPN}いしの ちからにより\n"
	.string "しんかした ものたちが みえます……\p"
	.string "ほのお…… みず……\n"
	.string "でんきも かんじます……\p"
	.string "……そして 3つの ちからに くるしむ\n"
	.string "あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "{JPN}ノーマルタイプの ポケモンが みえます……\p"
	.string "……そして すさまじく つよい わざに\n"
	.string "くるしむ あなたの ポケモンの すがたも……$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "{JPN}うらないを しんじるも しんじないも\n"
	.string "あなた しだい……\p"
	.string "みらいは いつでも かえられます……\n"
	.string "どうぞ ごぶじで……$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "{JPN}しってる?\p"
	.string "はしると トレーナーに きづかれて\n"
	.string "しょうぶを しかけられる ことが あるんだ。\p"
	.string "だから トレーナーを さけたいなら\n"
	.string "めを つけられないように\l"
	.string "そっと しずかに とおりすぎるんだ。$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "{JPN}うおおおおーーーーーーん!\p"
	.string "どうぐを いっぱい もってたのに\n"
	.string "まけたら ぜんぶ なくなっちゃった!\p"
	.string "うおおおおーーーーーーん!$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "{JPN}おかえりなさいませ!\n"
	.string "とんでもない ことを なされた!\p"
	.string "ピラミッドキングを たおし\n"
	.string "バトルピラミッドを せいは されるとは!$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "{JPN}わかき ぼうけんしゃよ!\n"
	.string "あなたの ゆうきを たたえ\l"
	.string "バトルポイントを おおくり しましょう!$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "{JPN}バトルアドベンチャーの ルールが かいてある。$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "{JPN}どの せつめいを よみますか?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "{JPN}ピラミッドを せいはすると\n"
	.string "なかに でてくる やせいの ポケモンは\l"
	.string "べつの しゅるいに かわります。\p"
	.string "どんな やせいの ポケモンが でるかは\n"
	.string "たんけんして たしかめて おぼえましょう。$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "{JPN}ピラミッドの なかでは\n"
	.string "トレーナーが まちぶせしています。\p"
	.string "それぞれの フロアには さいだい\n"
	.string "8にんの トレーナーが います。\p"
	.string "トレーナーに かつと ぼうけんに\n"
	.string "やくだつ ヒントが もらえます。$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "{JPN}ピラミッドの めいろは はいるたびに\n"
	.string "かたちが かわります。\p"
	.string "めいろの なかは うすぐらいので\n"
	.string "ちゅういして すすみましょう。\p"
	.string "やせいの ポケモンや トレーナーに\n"
	.string "かつたびに あかりが ひろがります。$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "{JPN}ピラミッドの なかでは バトルバッグを\n"
	.string "バッグとして つかいます。\p"
	.string "バトルバッグは レベル50と\n"
	.string "オープンレベルの ぼうけんように\l"
	.string "べつべつに 1つずつ あります。\p"
	.string "それぞれ 10しゅるいの どうぐを\n"
	.string "99こまで いれられます。\p"
	.string "ぼうけんに しっぱいすると\n"
	.string "バトルバッグの なかみは なくなります。$"

