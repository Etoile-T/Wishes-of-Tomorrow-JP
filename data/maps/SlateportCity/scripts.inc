SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_SLATEPORT_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_SLATEPORT_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_SLATEPORT_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_SLATEPORT_COOK, 27, 16
	setobjectxyperm LOCALID_SLATEPORT_GIRL, 28, 16
	setobjectxyperm LOCALID_SLATEPORT_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_SLATEPORT_MAN_1, 31, 14
	setobjectmovementtype LOCALID_SLATEPORT_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_SLATEPORT_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_SLATEPORT_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_SLATEPORT_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	setobjectxyperm LOCALID_SLATEPORT_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SLATEPORT_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	pokemartlistend

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_SLATEPORT_CITY_STATE, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_SLATEPORT_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	pokemartlistend

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	pokemartlistend

SlateportCity_EventScript_PowerTMClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	pokemartlistend

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_SLATEPORT_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_SLATEPORT_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_SLATEPORT_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_SLATEPORT_GABBY
	removeobject LOCALID_SLATEPORT_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_SLATEPORT_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_SLATEPORT_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_SLATEPORT_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_SLATEPORT_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SLATEPORT_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SLATEPORT_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_SLATEPORT_CAPT_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_CITY_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SLATEPORT_SCOTT
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SLATEPORT_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SLATEPORT_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "{JPN}わし がんばりや!\n"
	.string "がんばって ひつようなものを うりますよ!$"

SlateportCity_Text_OhYourPokemon:
	.string "{JPN}あら?\n"
	.string "きみの {ENG}{STR_VAR_1}{JPN}……$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "{JPN}ものすごく がんばったのね!\p"
	.string "ごほうびと して\n"
	.string "この がんばリボンを つけてあげて!$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{JPN}{ENG}{PLAYER}{JPN}は がんばリボンを もらった!$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{JPN}{ENG}{PLAYER}{JPN}は がんばリボンを\n"
	.string "{ENG}{STR_VAR_1}{JPN}に つけて あげた!$"

SlateportCity_Text_GoForItLittleHarder:
	.string "{JPN}あと すこし がんばってみて!\p"
	.string "がんばれば わたしが ポケモンに\n"
	.string "いいもの あげるから!$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "{JPN}あっ! きみの {ENG}{STR_VAR_1}{JPN}\n"
	.string "がんばリボン にあってるよ!$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "{JPN}とうだいの あかりは\n"
	.string "すうじゅうマイル さきまで とどくんだ。\p"
	.string "うみの なかの ポケモン\n"
	.string "まぶしくて おどろいて いないかな?$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "{JPN}おお これを みてごらん!\p"
	.string "この あたりで とれる かいそうは\n"
	.string "しんせんで いきが いいねえ。\p"
	.string "おきあがって おそってきても\n"
	.string "おかしく ないくらいだよ!$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "{JPN}みずの きれいな ところに\n"
	.string "たくさんの みのりが あつまり\p"
	.string "ひとびとが やってくる ところに\n"
	.string "いちばが できる……\p"
	.string "こうして まちは うまれ そだつのさ。$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "{JPN}うみの かおりが する ばしょで\n"
	.string "かいものが できるなんて……\p"
	.string "カイナって すてきな ところ!$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "{JPN}ぬいぐるみや クッションって\n"
	.string "ゆかに おくと よごれちゃうでしょ?\p"
	.string "だから きれいなまま かざれるように\n"
	.string "ぬいぐるみや クッションを おくための\l"
	.string "レンガを かいに きたの!$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "{JPN}うぉー! バトルテントに\n"
	.string "こっちも しゅつじょう するぞおー!\p"
	.string "と そのまえに!\n"
	.string "ポケモン つかまえて こなくちゃ!$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "{JPN}ふう… くたくただよ…\p"
	.string "キンセツシティから あるいてきたんだ。\n"
	.string "それにしても この まちは ひろいねえ。\p"
	.string "こんなことなら じてんしゃで\n"
	.string "くれば よかったよ。$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "{JPN}はくぶつかんを つくった クスノキさんは\n"
	.string "かいてい たんさチームの\l"
	.string "リーダーでも あるんだよ。\p"
	.string "だから みんな クスノキかんちょうってね。$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "{JPN}なんなのかしら\n"
	.string "あの ぎょうれつ?$"

SlateportCity_Text_VisitedMuseumOften:
	.string "{JPN}この はくぶつかん には\n"
	.string "こどもの ころ わたしも よく きました\p"
	.string "かんないの てんじひんを みて\n"
	.string "うみの しんぴに あこがれた ものです。$"

SlateportCity_Text_QuitPushing:
	.string "{JPN}ちょっと あんた! おさないでよ!\n"
	.string "じゅんばん なんだから!$"

SlateportCity_Text_AquaHasPolicy:
	.string "{JPN}おれたち アクアだんの ポリシーは\n"
	.string "「げんち しゅうごう」 そして\l"
	.string "「げんち かいさん」 なんだぜ!$"

SlateportCity_Text_BossIsBrilliant:
	.string "{JPN}うちの ボスは あたまが いいんだ。\p"
	.string "こんどは はくぶつかんで\n"
	.string "なにを したいんだろうな?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "{JPN}こんどの さくせんは なんだろう?\p"
	.string "リーダーを おこらせると こわいから\n"
	.string "しっぱい したくないぜ……$"

SlateportCity_Text_ShouldTakeItAll:
	.string "{JPN}はくぶつかんに ほしいもの あるなら\n"
	.string "まるごと うばっちゃえば いいのに……$"

SlateportCity_Text_DontButtIn:
	.string "{JPN}おい こら!\n"
	.string "じゅんばん ぬかすなよ!$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "{JPN}ながい ぎょうれつだな。\p"
	.string "だいにんきの ゲームを かうために\n"
	.string "ならんだ ときを おもいだすぜ…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "{JPN}なぜ ならんで おかねを はらうんだ?\n"
	.string "そのまま おしかければ いいじゃないか!$"

SlateportCity_Text_WhatDoYouWant:
	.string "{JPN}なんだ?\n"
	.string "なんの ようだ?$"

SlateportCity_Text_IllReadSignForYou:
	.string "{JPN}おまえ このカンバンが よみたいのか?\n"
	.string "なら オレが かわりに よんでやらぁ!$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "{JPN}ええと…\p"
	.string "たしか こんなことが かいてあるぞ。\n"
	.string "「うみの いのちは はてしない」ってな。\p"
	.string "うん きっと\n"
	.string "そう かいてあるはずだ。$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "{JPN}ぶつぶつぶつ……\p"
	.string "ゲームボーイアドバンスを もってくれば\n"
	.string "ならんでいても たいくつ しなかったのに…\p"
	.string "ぶつぶつぶつ……$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "{JPN}この さくせんが おわったら\n"
	.string "おんせんに つれていって やる!\p"
	.string "って リーダーが いってたんだ。\n"
	.string "まちきれないなあ!$"

SlateportCity_Text_SeaIsSoWet:
	.string "{JPN}うみは なんて ひろいんだろう…\p"
	.string "ポケモンの ながした なみだが\n"
	.string "うみを つくったのだろうか?$"

SlateportCity_Text_SinkOldBoats:
	.string "{JPN}ふるく なって のれない ふねは\n"
	.string "どうするか しって いるかね?\p"
	.string "うみの そこに しずめて\n"
	.string "ポケモンの すみかに してやるのだよ!$"

SlateportCity_Text_BuyTooMuch:
	.string "{JPN}ここに くると うれしくて\n"
	.string "つい たくさん かいもの しちゃう!$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "{JPN}ポケモンの ニックネームを かえたければ\n"
	.string "せいめいはんだんしに\l"
	.string "てつだって もらうんだよ。$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "{JPN}ひとと こうかんした ポケモンは\n"
	.string "ニックネームを かえられないわよ!\p"
	.string "もとの トレーナーの あいじょうが\n"
	.string "その ニックネームに こもってるのよ!$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "{JPN}さいきん カイナに バトルテントが\n"
	.string "できたんだ。\p"
	.string "ジムも たのしいけど バトルテントも\n"
	.string "また べつの おもしろさが あるよ。\p"
	.string "バトルテントに むけて\n"
	.string "つよい ポケモンを さがしておいで!$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "{JPN}ゆうめいな スターが きていたら\n"
	.string "サインを もらうつもり だったのに\p"
	.string "インタビュー されてるのは\n"
	.string "あれ…… クスノキさん でないかい?$"

SlateportCity_Text_InterviewerSoCool:
	.string "{JPN}あの インタビュアーの おねえさん\n"
	.string "かっこよくて びじん!\p"
	.string "あたしも おおきく なったら\n"
	.string "こくさい ジャーナリストに なるわ!$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "{JPN}クスノキかんちょうが うみの そこで\n"
	.string "なにかを みつけたって。\p"
	.string "なんだろうね?\n"
	.string "いったい なんなのかな?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "{JPN}なんだ なんだ!?\p"
	.string "かんちょうは うみの そこから\n"
	.string "おおもの でも つりあげたのか?$"

SlateportCity_Text_AmIOnTV:
	.string "{JPN}みんなー! みてるかー!\n"
	.string "おれも テレビに うつってるかー?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "{JPN}テレビが しゅざいに くる なんて\n"
	.string "かんちょうも ゆうめいじん ですなあ!$"

SlateportCity_Text_BigSmileForCamera:
	.string "{JPN}ダイ: はい クスノキさん\n"
	.string "カメラに とびきりの えがおを!$"

SlateportCity_Text_MostInvaluableExperience:
	.string "{JPN}マリ: なるほど なるほど それは\n"
	.string "きちょうな たいけんを なさいましたね……$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "{JPN}クスノキ: ええ これからも\n"
	.string "ちょうさは つづけて いきますよ!$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "{JPN}マリ: そうですか いやあ クスノキさん!\n"
	.string "きょうは おいそがしい ところ\l"
	.string "どうも ありがとう ございました!\p"
	.string "また なにか はっけんが ありましたら\n"
	.string "ぜひ しゅざい させて くださいね!$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "{JPN}クスノキ: ふう……\p"
	.string "テレビカメラに うつされる なんて\n"
	.string "はじめて だったから きんちょう したよ!$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "{JPN}やあ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "げんきそうだね!\p"
	.string "このまえの かいてい たんさで\n"
	.string "だいはっけんを したんだ。\p"
	.string "128ばんすいどうで\n"
	.string "かいていの どうくつを みつけたんだよ。\p"
	.string "ずっと むかしに ほろんだと いわれている\n"
	.string "ポケモンの すみかでは ないかと おもう。$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "{JPN}フフフ……\n"
	.string "クスノキかんちょう とやら\p"
	.string "きみの せんすいていは\n"
	.string "われわれ アクアだんが いただく!\p"
	.string "はんろんなど むだだ!\n"
	.string "ぜんめんてきに きょうりょく したまえ!\p"
	.string "フフフ……\n"
	.string "アクアだんの けいかくを\l"
	.string "よく みて まなぶが いい!$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "{JPN}クスノキ: いまのは いったい なんだ?\p"
	.string "だれかが メガホンを\n"
	.string "つかっているようだったが…\p"
	.string "どこから きこえたんだろう?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "{JPN}ふねのりばからだ!\p"
	.string "せんすいていが!\n"
	.string "うばわれようと している!$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{JPN}{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "いっしょに きてくれ!$"

SlateportCity_Text_BattleTentSign:
	.string "{JPN}バトルテント カイナシティ かいじょう\n"
	.string "さがせ! さいきょう ポケモン!$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "{JPN}「クスノキ ぞうせんじょ」\p"
	.string "どんな ながれも のりこなす ふなのり\n"
	.string "ぼしゅうちゅう!$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "{JPN}「クスノキ ぞうせんじょ」\p"
	.string "カイナと ミナモを むすぶ\n"
	.string "れんらくせん タイドリップごうは\l"
	.string "かんせい まで あと わずか!$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "{JPN}「クスノキ ぞうせんじょ」\p"
	.string "カイナと ミナモを むすぶ\n"
	.string "れんらくせん タイドリップごうの じょうせんは\l"
	.string "ふねのりばで うけつけて います。$"

SlateportCity_Text_PokemonFanClubSign:
	.string "{JPN}「ポケモン だいすきクラブ」\n"
	.string "ポケモンが すきなひと みんな あつまれ!$"

SlateportCity_Text_OceanicMuseumSign:
	.string "{JPN}はてしない うみは\n"
	.string "すべての いのちを ささえている。\p"
	.string "「うみの かがく はくぶつかん」$"

SlateportCity_Text_CitySign:
	.string "{JPN}カイナシティ\p"
	.string "ひとと ポケモンが\n"
	.string "いきかう みなと。$"

SlateportCity_Text_MarketSign:
	.string "{JPN}「カイナ いちば」\n"
	.string "ここでしか かえない もの たくさん!$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "{JPN}カイナの ふねのりば\p"
	.string "れんらくせん タイドリップごうは\n"
	.string "ぞうせんじょで けんぞうちゅうです。\p"
	.string "まもなく うんこうを はじめる\n"
	.string "よていです。$"

SlateportCity_Text_HarborSign:
	.string "{JPN}「カイナ シティ ふねのりば」\p"
	.string "れんらくせん タイドリップごうで\n"
	.string "ふねの たびを おたのしみ ください!$"

SlateportCity_Text_NameRatersHouseSign:
	.string "{JPN}「せいめい はんだんし の いえ」\n"
	.string "ポケモンの ニックネームを みたてます。$"

SlateportCity_Text_ExplainBerries:
	.string "{JPN}やせいの ポケモンは きずつくと\n"
	.string "きのみを かじって じぶんで なおすんだ。\p"
	.string "しってたかい?\p"
	.string "それを みた だれかが きのみから\n"
	.string "くすりを つくることを おもいついた。\p"
	.string "しってたかい?\p"
	.string "きのみを くすりに するには\n"
	.string "こなに つぶさなくちゃ いけない。\p"
	.string "しってたかい?\p"
	.string "きみは どうやら きのみに\n"
	.string "きょうみが あるようだね!\p"
	.string "そんな きみに\n"
	.string "いいものが あるんだよ。$"

SlateportCity_Text_ExplainBerryPowder:
	.string "{JPN}さいきん ポケモンセンターに\n"
	.string "きのみを つぶす きかいを せっちしたんだ。\p"
	.string "きのみクラッシュの きかいは\n"
	.string "2かいの ダイレクトコーナーに あるよ。\p"
	.string "しってたかい?\p"
	.string "その きかいを つかって\n"
	.string "きのみのこなを つくって くれないかい?\p"
	.string "きのみのこなを たくさん もってくれば\n"
	.string "いろんな くすりを つくって あげるよ。$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "{JPN}きのみのこなを\n"
	.string "もってきて くれたかい?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "{JPN}なにと\n"
	.string "こうかん したいんだい?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "{JPN}きのみのこなと\n"
	.string "{ENG}{STR_VAR_1}{JPN}を 1つ こうかんだね?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "{JPN}あれま!?\n"
	.string "こなが たりない じゃないの!$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "{JPN}いい きのみのこなだね。\n"
	.string "すばらしい くすりが できるよ。\p"
	.string "もっと きのみのこなを\n"
	.string "べつのものと こうかんするかい?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "{JPN}わかった!\n"
	.string "また きのみのこなが できたら もってきてね!$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "{JPN}きのみのこなを くすりと こうかんするなら\n"
	.string "また おいで。\p"
	.string "いつも ここで バザーを ひらいているよ。\p"
	.string "しってたかい?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "{JPN}エニシダ: おや?\n"
	.string "たしか どこかで あったね。\p"
	.string "じこしょうかいは したかな?\n"
	.string "まだなら わたしは エニシダ。\p"
	.string "さっき アクアだんが なにかに さされたように\n"
	.string "あわてて にげていくのを みたよ。\p"
	.string "ひょっとして きみが おいはらったのかい?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "{JPN}エニシダ: うーむ…\n"
	.string "ひょっとして ひょっとすると この トレーナー…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "{JPN}エニシダ: よし! きみとは\n"
	.string "いい ともだちに なれそうだね。\p"
	.string "それじゃ おたがいの ポケナビに\n"
	.string "とうろくしよう。\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "{JPN}エニシダ という ひとを\n"
	.string "ポケナビに とうろく した!$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "{JPN}エニシダ: ホントは きみに\n"
	.string "くっついて いきたい ところ だけど\l"
	.string "ほかのひとの さいのうも きになるし\p"
	.string "もうすこし いろんな まちを\n"
	.string "たずね あるいて みるよ!\p"
	.string "じゃあね {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "{JPN}エニシダ: やあ!\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}じゃないか!\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} ひょっとして\n"
	.string "バトルテントに ちょうせんするのかい?\p"
	.string "うん! いい かんがえだ!\n"
	.string "ほんとうに すばらしい かんがえだよ!\p"
	.string "つよい トレーナーに こそ\n"
	.string "バトルテントは ぴったりだからね!\p"
	.string "せいいっぱい がんばってくれ!$"
