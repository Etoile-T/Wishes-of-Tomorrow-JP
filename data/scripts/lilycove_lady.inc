LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady::
	special Script_GetLilycoveLadyId
	switch VAR_RESULT
	case LILYCOVE_LADY_QUIZ, LilycoveCity_PokemonCenter_1F_EventScript_QuizLady
	case LILYCOVE_LADY_FAVOR, LilycoveCity_PokemonCenter_1F_EventScript_FavorLady
	case LILYCOVE_LADY_CONTEST, LilycoveCity_PokemonCenter_1F_EventScript_ContestLady
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetFavorLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyCompleted::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyReady::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasAnotherPlayerGivenFavorLadyItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_TellAboutPlayersItem::
	special BufferFavorLadyItemName
	special BufferFavorLadyPlayerName
	specialvar VAR_RESULT, DidFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveBadThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerGaveGreatThing::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_RequestItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_RequestItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AcceptFavor::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_FavorLadyOpenBagMenu
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChooseFavorItem::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineFavor
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChooseFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_GiveFavorItem::
	specialvar VAR_RESULT, Script_DoesFavorLadyLikeItem
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_DidntLikeFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckLovedItem::
	specialvar VAR_RESULT, IsFavorLadyThresholdMet
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem
	end

LilycoveCity_PokemonCenter_1F_EventScript_LikedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_LovedFavorItem::
	special BufferFavorLadyRequest
	msgbox LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_FavorLadyPrize::
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, FavorLadyGetPrize
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn, MSGBOX_DEFAULT
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoRoomForFavorPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ReceivedFavorPrize::
	special SetFavorLadyState_Complete
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuizLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetQuizLadyState
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_READY, LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_COMPLETED, LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz
	goto_if_eq VAR_RESULT, LILYCOVE_LADY_STATE_PRIZE, LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_HasQuiz::
	specialvar VAR_RESULT, GetQuizAuthor
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_OTHER_PLAYER, LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady
	goto_if_eq VAR_RESULT, QUIZ_AUTHOR_LADY, LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckMadeQuiz::
	specialvar VAR_RESULT, IsQuizLadyWaitingForChallenger
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_WaitingToTakeYourQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_PlayerQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_LadyQuizReady::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskTakeQuiz::
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowBoringBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz::
	special ClearQuizLadyPlayerAnswer
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion
	goto_if_eq VAR_0x8004, EASY_CHAT_TYPE_QUIZ_ANSWER, LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer

LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState::
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowQuestion::
	special QuizLadyShowQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_GetAnswer::
	special QuizLadyGetPlayerAnswer
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_QuitTakingQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_SubmitQuizResponse::
	special SetQuizLadyState_Complete
	msgbox LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsQuizAnswerCorrect
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse
	end

LilycoveCity_PokemonCenter_1F_EventScript_CorrectResponse::
	playse SE_SUCCESS
	delay 10
	playse SE_SUCCESS
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRight, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_IncorrectResponse::
	special BufferQuizCorrectAnswer
	special BufferQuizPrizeName
	playse SE_FAILURE
	delay 10
	playse SE_FAILURE
	msgbox LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs, MSGBOX_DEFAULT
	msgbox LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

@ VAR_RESULT is essentially ignored, both jumps are identical
LilycoveCity_PokemonCenter_1F_EventScript_ReadyGivePrize::
	specialvar VAR_RESULT, BufferQuizAuthorNameAndCheckIfLady
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize1::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize0::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_GivePrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePrize::
	setvar VAR_0x8005, 0
	special BufferQuizPrizeItem
	special SetQuizLadyState_Complete
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize
	goto LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoSpaceForQuizPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp, MSGBOX_DEFAULT
	special SetQuizLadyState_GivePrize
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskMakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz::
	special QuizLadyPickNewQuestion
	msgbox LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_PickYourPrize, MSGBOX_DEFAULT
LilycoveCity_PokemonCenter_1F_EventScript_PickPrize::
	fadescreen FADE_TO_BLACK
	setvar VAR_RESULT, 0
	special Script_QuizLadyOpenBagMenu
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitChoosingPrize::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_PickPrize
	end

LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz, MSGBOX_DEFAULT
	special ClearQuizLadyQuestionAndAnswer
	special ClearQuizLadyPlayerAnswer
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUIZ_QUESTION
LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion::
	fadescreen FADE_TO_BLACK
	special QuizLadySetCustomQuestion
	goto_if_eq VAR_RESULT, 0, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitWritingQuizQuestion::
	msgbox LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineMakeQuiz
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion
	end

LilycoveCity_PokemonCenter_1F_EventScript_FinishMakingQuiz::
	special QuizLadyTakePrizeForCustomQuiz
	special QuizLadyRecordCustomQuizData
	special QuizLadySetWaitingForChallenger
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLady::
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasPlayerGivenContestLadyPokeblock
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

@ Redundant with above script, VAR_RESULT will always be FALSE here
LilycoveCity_PokemonCenter_1F_EventScript_NotGivenPokeblock::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivenPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskForPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality, MSGBOX_DEFAULT
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase
	msgbox LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseForContestLady
	goto_if_eq VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock
	goto_if_ne VAR_RESULT, 0xFFFF, LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_AskQuitGivingPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_1F_EventScript_DeclineGivePokeblock
	goto_if_eq VAR_RESULT, NO, LilycoveCity_PokemonCenter_1F_EventScript_ChoosePokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_GivePokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock, MSGBOX_DEFAULT
	special SetContestLadyGivenPokeblock
	special GetContestLadyMonSpecies
	goto LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_FeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon
	waitmovement 0
	delay 60
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	delay 120
	waitmoncry
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock
	goto LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock
	end

@ VAR_0x8004 here is the return value from GivePokeblockToContestLady
LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock::
	applymovement LOCALID_LILYCOVE_LADYS_MON, LilycoveCity_PokemonCenter_1F_Movement_MonJump
	waitmovement 0
	delay 60
LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock::
	applymovement LOCALID_LILYCOVE_LADY, LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer
	waitmovement 0
	delay 60
	goto_if_eq VAR_0x8004, 0, LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock
	goto_if_eq VAR_0x8004, 1, LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonDislikedPokeblock::
	msgbox LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_MonLikedPokeblock::
	special Script_BufferContestLadyCategoryAndMonName
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks, MSGBOX_DEFAULT
	goto LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow
	end

LilycoveCity_PokemonCenter_1F_EventScript_CheckAirContestLadyShow::
	specialvar VAR_RESULT, ShouldContestLadyShowGoOnAir
	goto_if_eq VAR_RESULT, 1, LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_AirContestLadyShow::
	msgbox LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests, MSGBOX_DEFAULT
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_NoPokeblockCase::
	msgbox LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Movement_LadyFaceMon:
	face_right
	delay_8
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonFaceLady:
	face_left
	delay_8
	step_end

@ Unused
LilycoveCity_PokemonCenter_1F_Movement_MonFaceDown:
	face_down
	step_end

LilycoveCity_PokemonCenter_1F_Movement_LadyFacePlayer:
	face_player
	step_end

LilycoveCity_PokemonCenter_1F_Movement_MonJump:
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_left
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon::
	specialvar VAR_RESULT, GetContestLadyCategory
	special Script_BufferContestLadyCategoryAndMonName
	special GetContestLadyMonSpecies
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_COOL, LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_BEAUTY, LilycoveCity_PokemonCenter_1F_EventScript_Skitty
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_CUTE, LilycoveCity_PokemonCenter_1F_EventScript_Poochyena
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_SMART, LilycoveCity_PokemonCenter_1F_EventScript_Kecleon
	goto_if_eq VAR_RESULT, CONTEST_CATEGORY_TOUGH, LilycoveCity_PokemonCenter_1F_EventScript_Pikachu
	end

LilycoveCity_PokemonCenter_1F_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox LilycoveCity_PokemonCenter_1F_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_Text_ImTheFavorLady:
	.string "{JPN}わたし おねだり おねえさん…$"

LilycoveCity_PokemonCenter_1F_Text_ObsessedWithThing:
	.string "{JPN}さいきん\n"
	.string "{ENG}{STR_VAR_1}{JPN} ものに むちゅうなの…$"

LilycoveCity_PokemonCenter_1F_Text_ThankYouForLastTime:
	.string "{JPN}あ…\n"
	.string "このまえは ありがとう…$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeBadThing:
	.string "{JPN}まえに たしか {ENG}{STR_VAR_3}{JPN}が…\p"
	.string "{ENG}{STR_VAR_3}{JPN}が {ENG}{STR_VAR_2}{JPN}を\n"
	.string "{ENG}{STR_VAR_1}{JPN} ものだって ひとつ くれたの。\p"
	.string "でも {ENG}{STR_VAR_1}{JPN} ものじゃ なかった。\n"
	.string "ぜんぜん。$"

LilycoveCity_PokemonCenter_1F_Text_PlayerGaveMeGreatThing:
	.string "{JPN}まえに {ENG}{STR_VAR_3}{JPN}から とっても\n"
	.string "{ENG}{STR_VAR_1}{JPN} {ENG}{STR_VAR_2}{JPN}を\p"
	.string "もらったの。 いまも たいせつに してるの。$"

LilycoveCity_PokemonCenter_1F_Text_WillYouShareThing:
	.string "{JPN}ねえ もし なにか\n"
	.string "{ENG}{STR_VAR_1}{JPN} ものを もってたら\l"
	.string "わけてくれない?$"

LilycoveCity_PokemonCenter_1F_Text_WhatWillYouGiveMe:
	.string "{JPN}…ほんと?\n"
	.string "なにを くれるの?$"

LilycoveCity_PokemonCenter_1F_Text_IsThatSoGoodbye:
	.string "{JPN}そう?\n"
	.string "じゃあ さよなら…$"

LilycoveCity_PokemonCenter_1F_Text_NotWillingToShare:
	.string "{JPN}あ…\n"
	.string "わけて くれないの?$"

LilycoveCity_PokemonCenter_1F_Text_IllTryToCherishIt:
	.string "{JPN}え?\n"
	.string "その {ENG}{STR_VAR_2}{JPN}が {ENG}{STR_VAR_1}{JPN}?\p"
	.string "…そう なのかしら?\p"
	.string "でも とにかく おれいを いうわ。\n"
	.string "たいせつに してみる…$"

LilycoveCity_PokemonCenter_1F_Text_IWillCherishThis:
	.string "{JPN}あ…\p"
	.string "とっても {ENG}{STR_VAR_1}{JPN}\n"
	.string "{ENG}{STR_VAR_2}{JPN}…\p"
	.string "すてきじゃない?\n"
	.string "ゆめみたい…\p"
	.string "ありがとう…\n"
	.string "たいせつに するわ…$"

LilycoveCity_PokemonCenter_1F_Text_IWillTreasureThis:
	.string "{JPN}…まあ まあ まあ…\p"
	.string "すごいわ!\n"
	.string "ほんとうに {ENG}{STR_VAR_1}{JPN}!\p"
	.string "ひとつの {ENG}{STR_VAR_2}{JPN}が こんなに\n"
	.string "{ENG}{STR_VAR_1}{JPN} なんて しらなかった!\p"
	.string "ありがとう!\p"
	.string "いっしょう たからものに\n"
	.string "するわ!$"

LilycoveCity_PokemonCenter_1F_Text_IllGiveYouThisInReturn:
	.string "{JPN}すてきな おくりものの おれいに\n"
	.string "この すばらしい どうぐを あげる。\p"
	.string "たいせつに してね…$"

LilycoveCity_PokemonCenter_1F_Text_YouDontHaveSpaceForIt:
	.string "{JPN}あら もちものが いっぱいだと\n"
	.string "うけとれないわね。\p"
	.string "バッグを せいり してから\n"
	.string "また きてね…$"

LilycoveCity_PokemonCenter_1F_Text_ImTheQuizLady:
	.string "{JPN}わたし クイズ おねえさん!\n"
	.string "クイズが だいすきなの!$"

LilycoveCity_PokemonCenter_1F_Text_WaitingToTakeYourQuiz:
	.string "{JPN}あら?\p"
	.string "いま あなたの つくった クイズに\n"
	.string "こたえる ひとを まってるの。\p"
	.string "おはなしは また こんどね?$"

LilycoveCity_PokemonCenter_1F_Text_WaitingForChallenger:
	.string "{JPN}クイズの ちょうせんしゃを まってるの!\n"
	.string "{ENG}{STR_VAR_1}{JPN}が かんがえた クイズよ!$"

LilycoveCity_PokemonCenter_1F_Text_TakeQuizChallenge:
	.string "{JPN}せいかい したら すてきな\n"
	.string "しょうひんが もらえるわ!\p"
	.string "クイズに ちょうせん\n"
	.string "してみる?$"

LilycoveCity_PokemonCenter_1F_Text_WaitForAnswer:
	.string "{JPN}… … … … … …\n"
	.string "… … … … … …$"

LilycoveCity_PokemonCenter_1F_Text_HowBoringBye:
	.string "{JPN}あら つまんない!\n"
	.string "バイバイ!$"

LilycoveCity_PokemonCenter_1F_Text_YoureGoingToQuit:
	.string "{JPN}えーっ!\n"
	.string "やめちゃうの?$"

LilycoveCity_PokemonCenter_1F_Text_TakeTheQuizAnotherTime:
	.string "{JPN}また こんど クイズに\n"
	.string "ちょうせん してね!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRight:
	.string "{JPN}すごい! せいかいよ!\n"
	.string "あなた なかなか するどいわね!$"

LilycoveCity_PokemonCenter_1F_Text_YouGotItRightYouveWonPersonsPrize:
	.string "{JPN}おめでとう!\n"
	.string "クイズ せいかいよ!\p"
	.string "しょうひんを ゲットよ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}が よういした ものよ!$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_XReceivedOneY:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}は\n"
	.string "{ENG}{STR_VAR_2}{JPN}を ひとつ もらった!$"

LilycoveCity_PokemonCenter_1F_Text_YourBagIsFilledUp:
	.string "{JPN}あら? バッグが いっぱいね!\n"
	.string "あきが できたら また きてね。$"

LilycoveCity_PokemonCenter_1F_Text_WrongTheCorrectAnswerIs:
	.string "{JPN}うーん… ざんねん!\n"
	.string "せいかいは 「{ENG}{STR_VAR_3}{JPN}」でした!$"

LilycoveCity_PokemonCenter_1F_Text_IGetToKeepPrize:
	.string "{JPN}ざんねん!\p"
	.string "クイズの しょうひん\n"
	.string "{ENG}{STR_VAR_1}{JPN}は わたしが もらうわね!$"

LilycoveCity_PokemonCenter_1F_Text_MakeYourOwnQuiz:
	.string "{JPN}ねえ ねえ!\n"
	.string "じぶんで クイズを つくってみない?$"

LilycoveCity_PokemonCenter_1F_Text_MaybeNextTime:
	.string "{JPN}あら そう…\n"
	.string "じゃあ また こんどね!$"

LilycoveCity_PokemonCenter_1F_Text_PickYourPrize:
	.string "{JPN}まずは あなたの クイズに\n"
	.string "せいかい した ひとに あげる\l"
	.string "しょうひんを えらんでね。\p"
	.string "でも きをつけて。 こたえる ひとが\n"
	.string "せいかい できなかったら\l"
	.string "しょうひんは わたしの ものよ!$"

LilycoveCity_PokemonCenter_1F_Text_QuitChoosingPrize:
	.string "{JPN}しょうひんを えらばないと\n"
	.string "クイズは つくれないわ。\p"
	.string "クイズづくりを\n"
	.string "やめちゃう?$"

LilycoveCity_PokemonCenter_1F_Text_WriteYourQuiz:
	.string "{JPN}まあ すてき!\n"
	.string "すばらしい しょうひんね!\p"
	.string "つぎは クイズの もんだいと\n"
	.string "こたえを かいてね。$"

LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizQuestion:
	.string "{JPN}クイズの もんだいを かくのを\n"
	.string "やめちゃう?$"

@ Unused
LilycoveCity_PokemonCenter_1F_Text_QuitWritingQuizAnswer:
	.string "{JPN}クイズの こたえを えらぶのを\n"
	.string "やめちゃう?$"

LilycoveCity_PokemonCenter_1F_Text_IllLookForAChallenger:
	.string "{JPN}ありがとう!\n"
	.string "いい クイズが できたわね。\p"
	.string "さっそく ちょうせん してくれる\n"
	.string "ひとを さがしてくるわ。$"

LilycoveCity_PokemonCenter_1F_Text_ImTheContestLady:
	.string "{JPN}わたし コンテスト おねえさん!\n"
	.string "コンテストが だいすきなの!$"

LilycoveCity_PokemonCenter_1F_Text_ThankForPokeblock:
	.string "{JPN}このまえは {ENG}{POKEBLOCK}{JPN} ありがとう!$"

LilycoveCity_PokemonCenter_1F_Text_MyFriendDisplaysQuality:
	.string "{JPN}この こは ともだちの {ENG}{STR_VAR_1}{JPN}!\n"
	.string "{ENG}{STR_VAR_2}{JPN}の かたまりなの!\p"
	.string "でも この こなら\n"
	.string "もっと {ENG}{STR_VAR_2}{JPN}を みせられるはず!$"

LilycoveCity_PokemonCenter_1F_Text_DontHaveAPokeblockCase:
	.string "{JPN}だから おねがい!\p"
	.string "{ENG}{POKEBLOCK}{JPN}を ひとつ くれない?\n"
	.string "ひとつだけで いいの!\p"
	.string "…あ でも…\n"
	.string "{ENG}{POKEBLOCK}{JPN}ケースを もってないの?\l"
	.string "それじゃ だめね。 また こんど!$"

LilycoveCity_PokemonCenter_1F_Text_AskingForOnePokeblock:
	.string "{JPN}だから おねがい!\p"
	.string "{ENG}{POKEBLOCK}{JPN}を ひとつ くれない?\n"
	.string "ひとつだけで いいの!$"

LilycoveCity_PokemonCenter_1F_Text_ICantHaveOnePokeblock:
	.string "{JPN}えーっ!\n"
	.string "{ENG}{POKEBLOCK}{JPN} ひとつも くれないの?!$"

LilycoveCity_PokemonCenter_1F_Text_WhatACheapskate:
	.string "{JPN}もう!\n"
	.string "けちんぼ!$"

LilycoveCity_PokemonCenter_1F_Text_IllUseYourPokeblock:
	.string "{JPN}やったー!\n"
	.string "ありがとう!\p"
	.string "さっそく ポケモンに {ENG}{POKEBLOCK}{JPN}を\n"
	.string "たべさせるわ。$"

LilycoveCity_PokemonCenter_1F_Text_NoChangeThanks:
	.string "{JPN}…ぜんぜん かわった\n"
	.string "ようすが ないわね…\p"
	.string "うーん…\p"
	.string "まあ いいわ!\n"
	.string "どうも ありがとう!$"

LilycoveCity_PokemonCenter_1F_Text_ReallyImprovedThanks:
	.string "{JPN}わあ やったー!\n"
	.string "とっても よろこんでる!\p"
	.string "{ENG}{STR_VAR_1}{JPN}の\n"
	.string "{ENG}{STR_VAR_2}{JPN}も よく なったみたい。\p"
	.string "ほんとうに ありがとう!$"

LilycoveCity_PokemonCenter_1F_Text_ReadyToEnterContests:
	.string "{JPN}うーん…\p"
	.string "そろそろ コンテストに\n"
	.string "でられそうな きがするわ。\p"
	.string "どこかで わたしたちを みかけたら\n"
	.string "おうえん してね。$"

LilycoveCity_PokemonCenter_1F_Text_Zigzagoon:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}: ググゥ!$"

LilycoveCity_PokemonCenter_1F_Text_Kecleon:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}: イギギギィー!$"

LilycoveCity_PokemonCenter_1F_Text_Poochyena:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}: バァールン…$"

LilycoveCity_PokemonCenter_1F_Text_Pikachu:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}: ピッカ!$"

LilycoveCity_PokemonCenter_1F_Text_Skitty:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}: ウミャーン!$"
