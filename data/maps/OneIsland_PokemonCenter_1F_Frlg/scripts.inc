OneIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, OneIsland_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_PokemonCenter_1F_OnFrame
	.byte 0

OneIsland_PokemonCenter_1F_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	call_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	end

OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile::
	setmetatile 13, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Ruby, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile::
	setmetatile 16, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Sapphire, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn::
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	setmetatile 14, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenLeft_On, 1
	setmetatile 15, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenRight_On, 1
	return

OneIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ONE_ISLAND
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos
	end

OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone::
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 9, 8
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_CELIO, 15, 6
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_UP
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 14, 7
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_CELIO, 14, 8
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_LEFT
	return

OneIsland_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene
	.2byte 0

OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CELIO, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_Delay48
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut
	msgbox OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_set FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp
	call_if_unset FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive
	msgbox OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer
	msgreceiveditem OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill, ITEM_METEORITE, 1, MUS_RG_OBTAIN_KEY_ITEM
	additem ITEM_METEORITE
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ObtainedTriPass, ITEM_TRI_PASS, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap
	setflag FLAG_SYS_SEVII_MAP_123
	msgbox OneIsland_PokemonCenter_1F_Text_BillCatchYouLater
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_SYS_PC_STORAGE_DISABLED
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap::
	setflag FLAG_HIDE_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ReceivedTownMap, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkUp:
	walk_up
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_StepAsideLeft::
	walk_left
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Bill::
	lock
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll
	msgbox OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll::
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Celio::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7, OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire
	goto_if_set FLAG_RECOVERED_SAPPHIRE, OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	goto_if_set FLAG_GOT_RUBY, OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3, OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex
	msgbox OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost
	closemessage
	applymovement LOCALID_CELIO, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou
	random 3
	goto_if_eq VAR_RESULT, 0, OneIsland_PokemonCenter_1F_EventScript_BillFact1
	goto_if_eq VAR_RESULT, 1, OneIsland_PokemonCenter_1F_EventScript_BillFact2
	famechecker FAMECHECKER_BILL, 5
	msgbox OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact1::
	famechecker FAMECHECKER_BILL, 3
	msgbox OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact2::
	famechecker FAMECHECKER_BILL, 4
	msgbox OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire::
	msgbox OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_SAPPHIRE
	msgbox OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_OkayThisIsGood
	closemessage
	delay 60
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 30
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 40
	playse SE_PC_ON
	call OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou
	special SetPostgameFlags
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
	special InitRoamer
	release
	end

OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_OhThats
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	special DrawWholeMapView
	delay 30
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio::
	msgbox OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands
	removeitem ITEM_RUBY
	removeitem ITEM_TRI_PASS
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
	additem ITEM_RAINBOW_PASS
	setflag FLAG_SYS_SEVII_MAP_4567
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass
	waitmessage
	waitfanfare
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	goto OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_TryingToFindGem
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 1
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine
	release
	end

OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine::
	walk_in_place_up
	delay_8
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine::
	walk_in_place_faster_up
	walk_in_place_up
	delay_16
	walk_in_place_up
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_EventScript_LittleBoy::
	msgbox OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_Hiker::
	msgbox OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked
	msgbox OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked::
	msgbox OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachine::
	lockall
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto
	msgbox OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerTop::
	lockall
	setvar VAR_TEMP_1, 1
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidTop::
	lockall
	setvar VAR_TEMP_1, 2
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidBottom::
	lockall
	setvar VAR_TEMP_1, 3
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 4
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer
	closemessage
	call_if_eq VAR_TEMP_1, 1, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop
	call_if_eq VAR_TEMP_1, 2, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop
	call_if_eq VAR_TEMP_1, 3, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom
	call_if_eq VAR_TEMP_1, 4, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom
	delay 10
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeGotItDone
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot
	msgbox OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 15
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 15
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime
	closemessage
	delay 25
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerExit
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillExit
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3
	clearflag FLAG_HIDE_CINNABAR_BILL
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 3
	setvar VAR_0x8004, SEAGALLOP_ONE_ISLAND
	setvar VAR_0x8006, SEAGALLOP_CINNABAR_ISLAND
	goto EventScript_SetSail
	end

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop::
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop::
	walk_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom::
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom::
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_DelayWalkInPlaceLeft::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_left
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkInPlaceDown::
	walk_in_place_fast_down
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Movement_BillExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio::
	.string "{JPN}マサキ: よう!\n"
	.string "ニシキ!$"

OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut::
	.string "{JPN}ニシキ: マサキさん!\n"
	.string "まさか ここまで きてくれるなんて。$"

OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing::
	.string "{JPN}マサキ: そら もちろんや!\n"
	.string "けんきゅうの ほうは どないや?\p"
	.string "……あ ちょい まってや。$"

OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio::
	.string "{JPN}{ENG}{PLAYER}{JPN} こいつは わいの ダチの ニシキ。\n"
	.string "こてこての パソコンマニアや!$"

OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp::
	.string "{JPN}ニシキ こっちは {ENG}{PLAYER}{JPN}。 ポケモン\n"
	.string "チャンピオンを ねらう ホープや!$"

OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp::
	.string "{JPN}ニシキ こっちは {ENG}{PLAYER}{JPN}。 いまの\n"
	.string "ポケモン チャンピオンや!$"

OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive::
	.string "{JPN}ニシキ: それは すごいですね。\p"
	.string "いいにくいんですが ぼくは バトルの\n"
	.string "さいのうが まったく なくて。\p"
	.string "とにかく あえて うれしいです。$"

OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed::
	.string "{JPN}マサキ: ほな いまの ようす きかせてや。\n"
	.string "マシンの ちょうしは どないや?$"

OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours::
	.string "{JPN}ニシキ: うごいては いるんですが\n"
	.string "ここは とおすぎて……\p"
	.string "この しまの パソコンは マサキさんの\n"
	.string "パソコンと つながらないんです。$"

OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou::
	.string "{JPN}マサキ: ほう そうか?\n"
	.string "よっしゃ ちょっと みせてみ。\p"
	.string "……ちょい まちや……\n"
	.string "なんとか なりそうやで。\l"
	.string "わいが てつだったる ええな?$"

OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer::
	.string "{JPN}{ENG}{PLAYER}{JPN} ちょっとだけ\n"
	.string "まっててくれへんか?\p"
	.string "……いや それより ひとつ\n"
	.string "たのまれて くれへんか?\p"
	.string "この となりの しまは\n"
	.string "2のしま いうねん。\p"
	.string "そこに ゲームコーナーを\n"
	.string "やってる おとこが おるんや。\p"
	.string "そいつ めずらしい いしや\n"
	.string "ほうせきに めが なくてな。\p"
	.string "マニア どうしやから\n"
	.string "ずっと れんらく とりおうてんねん。\p"
	.string "そんで この いんせきを そいつに\n"
	.string "とどけて もらえへんか?$"

OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill::
	.string "{JPN}{ENG}{PLAYER}{JPN}は マサキから\n"
	.string "いんせきを あずかった!$"

OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis::
	.string "{JPN}ニシキ: {ENG}{PLAYER}{JPN}さん 2のしまに\n"
	.string "いくなら これを もっていって ください。$"

OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands::
	.string "{JPN}この あたりの しまを むすぶ\n"
	.string "ふねの パスです。\p"
	.string "これで 1のしま 2のしま 3のしまを\n"
	.string "いききできます。\p"
	.string "あ これも もっていって ください。$"

OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap::
	.string "{JPN}{ENG}{PLAYER}{JPN}は タウンマップの\n"
	.string "ついかページを もらった!$"

OneIsland_PokemonCenter_1F_Text_ReceivedTownMap::
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "タウンマップを もらった!$"

OneIsland_PokemonCenter_1F_Text_BillCatchYouLater::
	.string "{JPN}マサキ: ほな また あとでな!\n"
	.string "あいつに よろしゅう いうといてや!$"

OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis::
	.string "{JPN}うーん……\p"
	.string "ここを こう してみたら どうや……$"

OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore::
	.string "{JPN}お {ENG}{PLAYER}{JPN}!\p"
	.string "みたか?\n"
	.string "パソコン うごいたで!\p"
	.string "ニシキに みせたい もんが\n"
	.string "いくつか あんねん。\p"
	.string "もうちょい そのへんを\n"
	.string "ぶらぶら しててくれへんか?$"

OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost::
	.string "{JPN}マサキさんの じかんを こんなに\n"
	.string "とってしまって すみません。\p"
	.string "せっかく きてくれたのに なんの\n"
	.string "おかまいも できなくて すみません。$"

OneIsland_PokemonCenter_1F_Text_UsualPCServicesUnavailable::
	.string "{JPN}いつもの パソコンの サービスは\n"
	.string "つかえない……$"

OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer::
	.string "{JPN}マサキ: お!\n"
	.string "{ENG}{PLAYER}{JPN}!$"

OneIsland_PokemonCenter_1F_Text_BillWeGotItDone::
	.string "{JPN}マサキ: えらい おそかったな。\n"
	.string "たのしんで きたんか?\p"
	.string "こっちは かたづいたで。\n"
	.string "パソコンは ばっちり うごいとる!$"

OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick::
	.string "{JPN}ニシキ: さぎょうが あっというまに\n"
	.string "おわりました。\p"
	.string "マサキさんって ほんとに すごい……$"

OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot::
	.string "{JPN}マサキ: ちゃうちゃう! わいの やることは\n"
	.string "ほとんど のこってへんかった。\p"
	.string "ニシキ たいしたもんや。\n"
	.string "ようけ べんきょう したんやな。$"

OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe::
	.string "{JPN}ニシキ: え ほんとですか?\n"
	.string "えへへ……$"

OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto::
	.string "{JPN}マサキ: ま そういう わけや。\n"
	.string "わいの しごとは おわった。\l"
	.string "カントーに もどろか。\p"
	.string "ニシキ ほな また あおな。$"

OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime::
	.string "{JPN}ニシキ: {ENG}{PLAYER}{JPN}さん きょうは\n"
	.string "ひとりに させて ごめんなさい。\p"
	.string "いつか かならず この しまじまを\n"
	.string "あんない しますね。$"

OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine::
	.string "{JPN}ニシキ: こんにちは!\n"
	.string "あいかわらず いそがしそうですね。\p"
	.string "ぼくですか?\p"
	.string "いま ネットワークマシンを\n"
	.string "かいぞう してるんです。\p"
	.string "マシンが できあがったら\n"
	.string "さいしょに つかって ほしいです\l"
	.string "{ENG}{PLAYER}{JPN}さん。$"

OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful::
	.string "{JPN}ニシキ: {ENG}{PLAYER}{JPN}さん\n"
	.string "ちょうしは どうですか?\p"
	.string "へえ そうなんですか?\n"
	.string "ポケモンが ふえたんですね。\p"
	.string "そうだ!\n"
	.string "ぼく おやくに たてるかも。$"

OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway::
	.string "{JPN}いま ネットワークマシンを\n"
	.string "かいぞう してるんです。\p"
	.string "とおくの ひととも こうかん\n"
	.string "できるように してるんですよ。\p"
	.string "かんせいしたら とおくの トレーナーと\n"
	.string "めずらしい ポケモンを\l"
	.string "こうかん できるように なります。$"

OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone::
	.string "{JPN}でも ひとつ もんだいが あって。\p"
	.string "つなぐ ためには マシンに\n"
	.string "とくべつな ほうせきが いるんです。\p"
	.string "1のしまに あるはず なんですが\n"
	.string "まだ みつけられなくて。\p"
	.string "いったい どこに あるんだろう。$"

OneIsland_PokemonCenter_1F_Text_TryingToFindGem::
	.string "{JPN}べんきょうの あいまにも\n"
	.string "ほうせきを さがしていたんです。\p"
	.string "その けっか さがしものも べんきょうも\n"
	.string "どっちも すすまなくて……\p"
	.string "マサキさんに たよれば きっと\n"
	.string "けんきゅうは すすむでしょう。\p"
	.string "でも こんどは じぶんの ちからで\n"
	.string "やってみたいんです。$"

OneIsland_PokemonCenter_1F_Text_OhThats::
	.string "{JPN}あっ!\n"
	.string "そ それは……$"

OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ルビーを\n"
	.string "ニシキに わたした。$"

OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor::
	.string "{JPN}ありがとう!\n"
	.string "{ENG}{PLAYER}{JPN}さん ほんとに すごいです。\p"
	.string "…… …… ……  …… …… ……\p"
	.string "あの…… もうひとつ おおきな おねがいを\n"
	.string "しても いいですか?$"

OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp::
	.string "{JPN}へ へんな ことじゃ ないんです。\n"
	.string "おねがい ちからを かしてください。$"

OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands::
	.string "{JPN}ほうせきを しらべていて\n"
	.string "だいじな ことに きづいたんです。\p"
	.string "この ルビーと ついに なる\n"
	.string "ほうせきが もうひとつ あるんです。\p"
	.string "その ほうせきは ナナシマの\n"
	.string "どこかに あるはず なんです。\p"
	.string "{ENG}{PLAYER}{JPN}さん おねがいです\n"
	.string "その ほうせきを さがしてきて ください。\p"
	.string "{ENG}{PLAYER}{JPN}さん ふねの パスと\n"
	.string "タウンマップを かしてもらえますか?$"

OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass::
	.string "{JPN}{ENG}{PLAYER}{JPN}は トライパスを かえして\n"
	.string "レインボーパスを もらった。$"

OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage::
	.string "{JPN}タウンマップの ついかページを\n"
	.string "てにいれた!$"

OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands::
	.string "{JPN}これは ぼくの ふねの パスです。\p"
	.string "これが あれば ナナシマの\n"
	.string "すべての しまに いけます。\p"
	.string "{ENG}{PLAYER}{JPN}さん おねがいです。 あなたの\n"
	.string "ちからが ないと できないんです。$"

OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio::
	.string "{JPN}{ENG}{PLAYER}{JPN}は サファイアを\n"
	.string "ニシキに わたした。$"

OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime::
	.string "{JPN}ニシキ: これが ルビーと ついに なる\n"
	.string "ほうせき なんですね……\p"
	.string "{ENG}{PLAYER}{JPN}さん これを てにいれるのに\n"
	.string "たいへんな おもいを したんでしょう?\p"
	.string "いわなくても わかります。\n"
	.string "かんたんじゃ なかった はずです。\p"
	.string "ほんとうに ありがとう!\p"
	.string "こんどは ぼくが がんばる ばんです!\n"
	.string "すこし じかんを ください。$"

OneIsland_PokemonCenter_1F_Text_OkayThisIsGood::
	.string "{JPN}よし これで いい……$"

OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette::
	.string "{JPN}やった!\n"
	.string "マユミさんと つながった!$"

OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou::
	.string "{JPN}{ENG}{PLAYER}{JPN}さん……\n"
	.string "{ENG}{PLAYER}{JPN}さん やりました!\p"
	.string "ホウエンちほうの トレーナーと\n"
	.string "つながることが できたんです!\p"
	.string "ついに ネットワークマシンが\n"
	.string "かんぜんに うごきだしました!\p"
	.string "{ENG}{PLAYER}{JPN}さん ぜんぶ あなたの おかげです!\p"
	.string "あなたの おかげで ぼくの ゆめが\n"
	.string "かなったんです……$"

OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck::
	.string "{JPN}ぼ……\n"
	.string "ぼく ないてなんか いませんよ。\p"
	.string "ぼくの はなしは もう いいんです!\p"
	.string "{ENG}{PLAYER}{JPN}さんは これからも\n"
	.string "めずらしい ポケモンを さがすんですよね?\p"
	.string "がんばって くださいね!$"

OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou::
	.string "{JPN}ニシキ: こんにちは!\p"
	.string "{ENG}{PLAYER}{JPN}さんの うわさ\n"
	.string "いろいろ きいてますよ。$"

OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra::
	.string "{JPN}{ENG}{PLAYER}{JPN}さんは どんな ポケモンが\n"
	.string "すきですか?\p"
	.string "マサキさんは ポケモンマニアだから\n"
	.string "どんな ポケモンも だいすきなんです。\p"
	.string "さいしょに つかまえたのは\n"
	.string "ケーシィ だったそうですよ。$"

OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod::
	.string "{JPN}ところで {ENG}{PLAYER}{JPN}さんは\n"
	.string "マサラタウンの しゅっしんですよね?\p"
	.string "しずかで すごしやすい ところだと\n"
	.string "ききました。\p"
	.string "マサキさんの ふるさとは コガネシティで\n"
	.string "いまも ごりょうしんが すんでるそうです。\p"
	.string "とても にぎやかで かっきの ある\n"
	.string "まちだと ききました。\p"
	.string "いつか いってみたいです。$"

OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk::
	.string "{JPN}{ENG}{PLAYER}{JPN}さんは なにか にがてな\n"
	.string "ものって ありますか?\p"
	.string "マサキさんは ぎゅうにゅうが\n"
	.string "まったく だめ なんだそうです。$"

OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt::
	.string "{JPN}あら みない かおね!\n"
	.string "こんにちは! どこから きたの?\p"
	.string "……マサラタウン?\n"
	.string "しらないわ!$"

OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland::
	.string "{JPN}この しまには とても おおきな\n"
	.string "かざんが あるのよ。\p"
	.string "さいきんは ふんかしてないから\n"
	.string "ハイキングでも どう?$"

OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend::
	.string "{JPN}とおくに すんでる かれしと\n"
	.string "ポケモンを こうかん できたらなあ……$"

OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend::
	.string "{JPN}とおくに いる かれしと ポケモンを\n"
	.string "こうかん できたの!\p"
	.string "あなたと ニシキさんの おかげだって\n"
	.string "みんな いってるわ。\p"
	.string "だから ありがとう!$"

OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment::
	.string "{JPN}ネットワークマシン\n"
	.string "リンクレベル 0\p"
	.string "……ポケモン あずかりシステム\n"
	.string "ちょうせいちゅう……$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto::
	.string "{JPN}ネットワークマシン\n"
	.string "リンクレベル 1\p"
	.string "カントーちほうと\n"
	.string "リンク かんりょう。$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn::
	.string "{JPN}ネットワークマシン\n"
	.string "リンクレベル 2\p"
	.string "カントーちほう および\n"
	.string "ホウエンちほうと リンク かんりょう。$"

OneIsland_PokemonCenter_1F_Text_ObtainedTriPass::
	.string "{JPN}トライパスを てにいれた!$"

