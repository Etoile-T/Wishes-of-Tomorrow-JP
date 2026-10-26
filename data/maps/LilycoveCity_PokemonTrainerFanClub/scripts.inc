LilycoveCity_PokemonTrainerFanClub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_OnTransition
	.byte 0

	@ See field_specials.c for a breakdown of the Fan Club and its variables

LilycoveCity_PokemonTrainerFanClub_OnFrame:
	map_script_2 VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	applymovement LOCALID_TRAINER_FAN_CLUB_LASS, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer
	applymovement LOCALID_TRAINER_FAN_CLUB_MAN, LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan, MSGBOX_DEFAULT
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer
	waitmovement 0
	setvar VAR_LILYCOVE_FAN_CLUB_STATE, 2
	releaseall
	end

LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer:
	delay_8
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer:
	walk_down
	walk_in_place_faster_right
	step_end

LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer:
	jump_in_place_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_in_place_faster_down
	step_end

LilycoveCity_PokemonTrainerFanClub_OnTransition:
	call LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 2, LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special TryLoseFansFromPlayTime
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_HideOrShowInterviewer::
	specialvar VAR_RESULT, ShouldHideFanClubInterviewer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer
	clearflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	clearflag FLAG_FAN_CLUB_STRENGTH_SHARED
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_HideInterviewer::
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	return

@ Set up the fan club TV show, if the player has at least 5 fans in the club
@ Rather than counting up, 1 is subtracted from the total for each member not a fan of the players
LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow::
	setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan
	goto_if_ge VAR_0x8005, 5, LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_CountNotPlayersFan::
	subvar VAR_0x8005, 1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow::
	special TryPutTrainerFanClubOnAir
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LASS, 7, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_POKEFAN_M, 3, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, 7, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_NINJA_BOY, 5, 5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BOY, 5, 2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_MAN, 8, 4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_WOMAN, 3, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_EXPERT_F, 8, 3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_SetFanMemberPositionsForFirstFanMeeting::
	call LilycoveCity_PokemonTrainerFanClub_EventScript_CheckSetUpTVShow
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call LilycoveCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Man::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ManPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Lass::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LassPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanM::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_PokefanMPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special BufferFanClubTrainerName
	goto_if_eq VAR_LILYCOVE_FAN_CLUB_STATE, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_NinjaBoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Boy::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_BoyOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertF::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special BufferFanClubTrainerName
	specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFPlayersFan::
	specialvar VAR_RESULT, GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ExpertFOnlyNonFan::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_Interviewer::
	lock
	faceplayer
	goto_if_set FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed
	goto_if_unset FLAG_FAN_CLUB_STRENGTH_SHARED, LilycoveCity_PokemonTrainerFanClub_EventScript_Interview
	end

@ The interviewer doesnt count as an individual fan club member
@ Instead they always ask about whoever the Lass would be interested in, if not the player
LilycoveCity_PokemonTrainerFanClub_EventScript_Interview::
	setvar VAR_0x8005, TVSHOW_FAN_CLUB_SPECIAL
	special InterviewBefore
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2
	copyvar VAR_0x800A, VAR_0x8006
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion::
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AskForOpinion::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_QUESTION
	copyvar VAR_0x8005, VAR_0x800A
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonTrainerFanClub_EventScript_SubmitOpinion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelGiveOpinion
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	message LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_POKEMON_FAN_CLUB_RATER
	special ShowScrollableMultichoice
	setvar VAR_0x8004, FANCLUB_MEMBER1
	switch VAR_RESULT
	case 11, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	case MULTI_B_PRESSED, LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	copyvar VAR_0x8006, VAR_0x800A
	copyvar VAR_0x8005, VAR_RESULT
	special PutFanClubSpecialOnTheAir
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CancelRateTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonTrainerFanClub_EventScript_RateTrainer
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_ForgetTrainer::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_CompleteInterview::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo, MSGBOX_DEFAULT
	setflag FLAG_FAN_CLUB_STRENGTH_SHARED
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed::
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special BufferFanClubTrainerName
	msgbox LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial, MSGBOX_DEFAULT
	release
	end

@ Shouldnt be reached
LilycoveCity_PokemonTrainerFanClub_EventScript_AlreadyInterviewed2::
	end

LilycoveCity_PokemonTrainerFanClub_Text_OhWowItsPlayer:
	.string "{JPN}あ!\n"
	.string "{ENG}{PLAYER}{JPN}だ!!$"

LilycoveCity_PokemonTrainerFanClub_Text_HeardAboutYouImYourFan:
	.string "{JPN}うわさは きいたよ!\n"
	.string "きみ ほんとうに つよいんだってね?\p"
	.string "ここでは いつも だれが いちばん\n"
	.string "つよい トレーナーか いいあってるんだ。\p"
	.string "それで きみの うわさを きいて\n"
	.string "ファンに なろうって きめたんだ!\p"
	.string "これからも ほかの つよい トレーナーと\n"
	.string "どんどん しょうぶして ほしいな。\p"
	.string "そうすれば きみの あつい あつい バトルを\n"
	.string "もっと たくさん みられるからね。\p"
	.string "そうしたら ここの みんなにも\n"
	.string "きみの すごさが はっきり わかるはずさ。\p"
	.string "おうえん してるのを わすれないでね\n"
	.string "{ENG}{PLAYER}{JPN}!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureOneWeWantToWin:
	.string "{JPN}おう {ENG}{PLAYER}{JPN}！！\n"
	.string "きみの しょうりを ねがってるぞ!$"

LilycoveCity_PokemonTrainerFanClub_Text_OthersDontKnowYoureTheBest:
	.string "{JPN}あいつらは しらないんだ\n"
	.string "きみが いちばん すごいって ことをさ！\p"
	.string "そうだろ {ENG}{PLAYER}{JPN}！\n"
	.string "こんじょう みせてくれ！$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainersPowerIsOutOfTheOrdinary:
	.string "{JPN}きみには わるいけど いま いちばん\n"
	.string "ちゅうもくの トレーナーは\l"
	.string "まちがいなく {ENG}{STR_VAR_1}{JPN} だね！\p"
	.string "あの つよさは\n"
	.string "ただものじゃ ないよ。$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsBestNoOneWantsToListen:
	.string "{JPN}くそっ… みんなに いってるのに\n"
	.string "いまは {ENG}{STR_VAR_1}{JPN}が いちばんだって…\p"
	.string "だれも きいて くれないんだ…$"

LilycoveCity_PokemonTrainerFanClub_Text_HearingAboutToughNewTrainer:
	.string "{JPN}つよい あたらしい トレーナーの\n"
	.string "うわさを きくの。\p"
	.string "ジムリーダーにまで\n"
	.string "かってるらしいわよ。\p"
	.string "その あたらしい トレーナーのこと\n"
	.string "なにか しってる?$"

LilycoveCity_PokemonTrainerFanClub_Text_ImPullingForYou:
	.string "{JPN}あ！\n"
	.string "{ENG}{PLAYER}{JPN}！！\p"
	.string "がんばってね\n"
	.string "おうえん してるから！$"

LilycoveCity_PokemonTrainerFanClub_Text_BrawlyNoImYourFan:
	.string "{JPN}はあ…\n"
	.string "トウキさま…\p"
	.string "あっ ちがうの! まって!\n"
	.string "そうじゃなくて! ちがう ちがう ちがう!\p"
	.string "わたしは ずっと あなたの ファンよ!\p"
	.string "ほこりに おもわせてね!\n"
	.string "がんばって!$"

LilycoveCity_PokemonTrainerFanClub_Text_ICantHelpLikingBrawly:
	.string "{JPN}やっぱり わたしは トウキさま しか\n"
	.string "すきに なれないのよねー。$"

LilycoveCity_PokemonTrainerFanClub_Text_NobodyUnderstandsBrawly:
	.string "{JPN}だれも トウキさまの\n"
	.string "みりょくを わかって くれないの……\p"
	.string "いいわ！\p"
	.string "わたし ひとりでも トウキさまの ことを\n"
	.string "おうえん しつづけるから！$"

LilycoveCity_PokemonTrainerFanClub_Text_MyFavoriteTrainerIsBrawly:
	.string "{JPN}だれが なんと いっても すきなのは\n"
	.string "ムロの ジムリーダー\l"
	.string "トウキさまよ!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouveSurpassedYourFather:
	.string "{JPN}きみは あらゆる めんで\n"
	.string "きみの おとうさんを こえたな！\p"
	.string "この わしが いって いるんだから\n"
	.string "まちがいない！$"

LilycoveCity_PokemonTrainerFanClub_Text_YourFatherNeverGaveUpSoKeepOnBattling:
	.string "{JPN}どんなに くるしい ときでも\n"
	.string "きみの ちちは あきらめなかった。\p"
	.string "それは よく しっている。\p"
	.string "きみも まけたって あきらめるな!\n"
	.string "しょうぶを つづけるんだ!$"

LilycoveCity_PokemonTrainerFanClub_Text_LongWayToGoComparedToNorman:
	.string "{JPN}センリさんの バトルは ちからも みりょくも\n"
	.string "みせかたも きみより すぐれていたよ。\p"
	.string "つよいと いわれている\n"
	.string "きみだって…\p"
	.string "おとうさんに くらべたら\n"
	.string "まだまだ さきは ながいよ。$"

LilycoveCity_PokemonTrainerFanClub_Text_YouAndNormanAreDifferent:
	.string "{JPN}きみも センリさんと おなじ ふんいき\n"
	.string "というか はくりょくが でてきたね\p"
	.string "しかし センリさん とは けっていてきに\n"
	.string "ちがう ものが ある！\p"
	.string "……それは わたしからは いえない\n"
	.string "じぶんで さがして みるんだな。$"

LilycoveCity_PokemonTrainerFanClub_Text_WeDiscussStrongestTrainers:
	.string "{JPN}ここにいる みんなは\n"
	.string "ポケモンしょうぶが だいすきでね\p"
	.string "だれが いちばん つよい トレーナーか\n"
	.string "はなしを して いるんだ！\p"
	.string "きみも ゆうめいに なれば\n"
	.string "みんな ファンに なるかもな！$"

LilycoveCity_PokemonTrainerFanClub_Text_OhWoweeItsPlayer:
	.string "{JPN}うわあ! {ENG}{PLAYER}{JPN}だ!\n"
	.string "ほんものだあ!\p"
	.string "おねがい あくしゅ あくしゅ して!$"

LilycoveCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou:
	.string "{JPN}ずっと おうえんしてるよ {ENG}{PLAYER}{JPN}!\n"
	.string "ずっと ずっとね!\p"
	.string "まけるところなんて みたくないよ\n"
	.string "{ENG}{PLAYER}{JPN}。\p"
	.string "だって ほんとうに ほんとうに つよいって\n"
	.string "しってるもん {ENG}{PLAYER}{JPN}!$"

LilycoveCity_PokemonTrainerFanClub_Text_EveryoneThinksTrainerIsCool:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}って ほんと かっこいい…\p"
	.string "みんなも そう おもうよね? ね?$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsReallyCoolItsJustMe:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}さん って ほんとうに\n"
	.string "かっこいい よねぇ……\p"
	.string "わたし ひとりに なっても\n"
	.string "ずうっと おうえん するんだー！$"

LilycoveCity_PokemonTrainerFanClub_Text_WishThereWasTrainerLikeThat:
	.string "{JPN}すきな トレーナーはね…\p"
	.string "かっこよくて…\p"
	.string "つよくて…\p"
	.string "とっても やさしい ひと…\p"
	.string "そんな トレーナーが いたらなあ…$"

LilycoveCity_PokemonTrainerFanClub_Text_WantToBeStrongLikeYou:
	.string "{JPN}あ！ {ENG}{PLAYER}{JPN}だー！\n"
	.string "すげー！\p"
	.string "ぼくも おおきく なったら\n"
	.string "{ENG}{PLAYER}{JPN} みたいに つよく なりたいよ！$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyOneWhoCheersForYou:
	.string "{JPN}たとえ ひとりに なっても…\p"
	.string "おうえんするのは ずっと\n"
	.string "{ENG}{PLAYER}{JPN}だけだからね!\p"
	.string "{ENG}{PLAYER}{JPN}を しんじてるから!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsWickedlyCool:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}って かっこいいよねー\n"
	.string "ぼく あくしゅ してほしいなー。$"

LilycoveCity_PokemonTrainerFanClub_Text_NeverGoingToStopBeingTrainersFan:
	.string "{JPN}たとえ ひとりに なっても…\p"
	.string "ぜったい ファンを やめないよ\n"
	.string "{ENG}{STR_VAR_1}{JPN}のね!\p"
	.string "だって {ENG}{STR_VAR_1}{JPN}は\n"
	.string "ぜったいに まけないって きいたもん!$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureAmazingAfterAll:
	.string "{JPN}{ENG}{PLAYER}{JPN}!\n"
	.string "やっぱり すごいね!\p"
	.string "はじめて みたときから\n"
	.string "すごいひとだって わかってたよ。\p"
	.string "めに くるいは なかったみたいね。$"

LilycoveCity_PokemonTrainerFanClub_Text_ImInYourCorner:
	.string "{JPN}ほかの ひとなんて どうでも いいよ。\n"
	.string "きみの みかただからね!\p"
	.string "しんぱいは いらない。いつもどおり\n"
	.string "しょうぶして おいで。$"

LilycoveCity_PokemonTrainerFanClub_Text_ThinkTrainerIsNumberOne:
	.string "{JPN}きみも なかなか\n"
	.string "いい トレーナーだと おもうけど\p"
	.string "いまは やっぱり {ENG}{STR_VAR_1}{JPN}が\n"
	.string "いちばんだと おもうんだ\p"
	.string "まあ ぼくが おもっている だけだから\n"
	.string "あまり きにしなくて いいよ。$"

LilycoveCity_PokemonTrainerFanClub_Text_YoureMaybeStrongerThanTrainer:
	.string "{JPN}ほんとうに つよいんだね。\n"
	.string "{ENG}{STR_VAR_1}{JPN}より つよいのかも。\p"
	.string "でも {ENG}{STR_VAR_1}{JPN}には わたしが ひつよう。\p"
	.string "わたしが {ENG}{STR_VAR_1}{JPN}を おうえんしなきゃ\n"
	.string "だれが おうえんするの?$"

LilycoveCity_PokemonTrainerFanClub_Text_YouChangedMyMind:
	.string "{JPN}みなおしたわ！\n"
	.string "あなたって ほんとうに つよいのね！\p"
	.string "どうしたら そんなに つよく なれるのか\n"
	.string "おしえて もらいたいわ。$"

LilycoveCity_PokemonTrainerFanClub_Text_YouBattleAttractivelyInToughSituation:
	.string "{JPN}くるしい ときほど\n"
	.string "すてきな バトルを するんだね。\p"
	.string "つぎの バトルが まちきれないよ!$"

LilycoveCity_PokemonTrainerFanClub_Text_TrainerIsStandout:
	.string "{JPN}さいきん わだいの トレーナーの なかでも\n"
	.string "{ENG}{STR_VAR_1}{JPN}は とびぬけてるね。\p"
	.string "あの つよさは ふつうじゃないよ。\p"
	.string "きみも がんばってるけど\n"
	.string "{ENG}{STR_VAR_1}{JPN}とは かくが ちがうね。$"

LilycoveCity_PokemonTrainerFanClub_Text_NoOneCanKnockYouButTrainerStronger:
	.string "{JPN}きみは ほんとうに にんきが あるね…\p"
	.string "つよくて ポケモンにも やさしい。\n"
	.string "だれも もんくを いえないよ。\p"
	.string "でも {ENG}{STR_VAR_1}{JPN}を しんじてるんだ。\p"
	.string "{ENG}{STR_VAR_1}{JPN}の ほうが ぜったい つよい!\n"
	.string "まちがいないよ!$"

LilycoveCity_PokemonTrainerFanClub_Text_YouImpressive:
	.string "{JPN}おぬし……\p"
	.string "やるな！$"

LilycoveCity_PokemonTrainerFanClub_Text_OnlyIRecognizeYourTrueWorth:
	.string "{JPN}おぬしの しんの ちからは\n"
	.string "この わしだけが しっていれば よいのじゃ\p"
	.string "みなには その ひめられた ちから\n"
	.string "わかるまい……$"

LilycoveCity_PokemonTrainerFanClub_Text_HaventRealizedPotential:
	.string "{JPN}うむ。ひとみに つよさが みえる。\p"
	.string "だが!\p"
	.string "おぬしは まだ ひめられた ちからを\n"
	.string "だしきって おらぬ。$"

LilycoveCity_PokemonTrainerFanClub_Text_YourePowerfulButNotTrueStrength:
	.string "{JPN}おぬしが とほうもなく つよいのは\n"
	.string "たしかだ。\p"
	.string "だが!\n"
	.string "わしには わかる…\p"
	.string "その つよさは まだ\n"
	.string "しんの つよさとは いえぬ!\p"
	.string "しんの つよさ とは…!\n"
	.string "… …\p"
	.string "じつは わしにも わからぬ。$"
