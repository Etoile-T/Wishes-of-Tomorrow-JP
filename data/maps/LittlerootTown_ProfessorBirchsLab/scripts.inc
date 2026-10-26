LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
	@ 1: Beat Elite Four, Dex upgrade ready
	@ 2: Received National Dex
	@ 3: Left lab after receiving National Dex
	@ 4: Entered lab after catching all Hoenn mons
	@ 5: Birch told player to choose Johto starter
	@ 6: Chose Johto starter

	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout

LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_OnWarp:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade::
	turnobject LOCALID_PLAYER, DIR_NORTH
	addobject LOCALID_BIRCHS_LAB_BIRCH
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_NORTH
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
	turnobject LOCALID_BIRCHS_LAB_AIDE, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_AIDE, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject::
	addobject LOCALID_BIRCHS_LAB_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters::
	addobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	addobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	addobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, 8, 4
	turnobject LOCALID_BIRCHS_LAB_TOTODILE_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_TOTODILE_BALL, 9, 4
	turnobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CHIKORITA_BALL, 10, 4
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 6, 4
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
	.2byte 0

@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent::
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex::
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
	waitmovement 0
	delay 20
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
	playse SE_PC_ON
	waitse
	delay 20
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
	waitmovement 0
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter::
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_ge VAR_BIRCH_LAB_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Totodile::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita::
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil::
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile::
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita::
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC::
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita::
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_BIRCH_LAB_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Rival::
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Book::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork:
	.string "{JPN}え？ クラークソンはかせ？\p"
	.string "いないよ。\p"
	.string "どうせ どこかで レベルあげ してるんでしょ。\p"
	.string "…きみには わからないだろうけど。$"

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork:
	.string "{JPN}クラークソンはかせは まだ\n"
	.string "レベルあげ ちゅうだよ。\p"
	.string "きみには わからないだろうけど。$"

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo:
	.string "{JPN}オダマキはかせは ポケモンの すむばしょや\n"
	.string "ぶんぷを しらべているんです。\p"
	.string "{ENG}{RIVAL}{JPN}さんの てつだいも うれしそうで\n"
	.string "おやこの あいじょうを かんじますね。$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon:
	.string "{JPN}オダマキ: さて {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}。\p"
	.string "きみのことは おとうさんから\n"
	.string "いろいろ きいているよ。\p"
	.string "まだ じぶんの ポケモンを\n"
	.string "もっていないそうだね。\p"
	.string "でも さっきの たたかいは\n"
	.string "みごとな おちつきぶり だったよ!\p"
	.string "やっぱり おとうさんの ちを\n"
	.string "ひいているんだね!\p"
	.string "そうそう! たすけてくれた おれいに\n"
	.string "さっき つかっていた ポケモンを\l"
	.string "きみに あげようと おもうんだ。\p"
	.string "{ENG}{PLAYER}{JPN}は {ENG}{STR_VAR_1}{JPN}を もらった!$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon:
	.string "{JPN}オダマキ: せっかくだから\n"
	.string "その {ENG}{STR_VAR_1}{JPN}に なまえを つけるかい？$"

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival:
	.string "{JPN}オダマキ: ポケモンと がんばって\n"
	.string "けいけんを つめば きっと\l"
	.string "すばらしい トレーナーに なれるよ。\p"
	.string "うちのこ {ENG}{RIVAL}{JPN}も わたしを てつだって\n"
	.string "ポケモンの べんきょうを しているんだ。\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} どうだろう。\n"
	.string "{ENG}{RIVAL}{JPN}に あってみるのは？$"

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou:
	.string "{JPN}オダマキ: そうか!\n"
	.string "{ENG}{RIVAL}{JPN}も よろこぶと おもうよ。\p"
	.string "{ENG}{RIVAL}{JPN}から トレーナーの ことを\n"
	.string "おしえてもらうと いいよ。$"

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay:
	.string "{JPN}オダマキ: まあ そう いわずに。\n"
	.string "うちのこに あってみると いいよ。$"

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome:
	.string "{JPN}オダマキ: {ENG}{RIVAL}{JPN}かい？\n"
	.string "うちに かえったと おもうよ。\p"
	.string "それとも また どこかの くさむらを\n"
	.string "かけまわっているのかな…\p"
	.string "きみも ポケモンも つかれたら\n"
	.string "うちで ゆっくり やすむと いいよ。$"

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex:
	.string "{JPN}オダマキ: やあ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\p"
	.string "はじめての しょうぶで {ENG}{RIVAL}{JPN}に\n"
	.string "かったんだって？ すばらしいね!\p"
	.string "{ENG}{RIVAL}{JPN}は ずいぶん まえから\n"
	.string "わたしの けんきゅうを てつだっている。\p"
	.string "{ENG}{RIVAL}{JPN}は もう トレーナーとしても\n"
	.string "ながい けいけんを つんでいるんだ。\p"
	.string "さて {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}。 けんきゅうのために\n"
	.string "とりよせたもの だけど きみに\l"
	.string "この ポケモンずかんを あげよう。$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
	.string "{JPN}{ENG}{PLAYER}{JPN}は ポケモンずかんを もらった!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
	.string "{JPN}オダマキ: ポケモンずかんは\n"
	.string "であったり つかまえたりした ポケモンを\l"
	.string "じどうで きろくする ハイテクな どうぐさ。\p"
	.string "うちのこ {ENG}{RIVAL}{JPN}も いつも\n"
	.string "もって あるいているよ。\p"
	.string "めずらしい ポケモンを つかまえて\n"
	.string "ずかんに きろくすると\l"
	.string "{ENG}{RIVAL}{JPN}は そとで ちょうさする わたしを\l"
	.string "さがして みせに きてくれるんだ。$"

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait:
	.string "{JPN}オダマキ: かぞえきれない ポケモンが\n"
	.string "きみを まっているよ!\p"
	.string "ああ また フィールドワークに\n"
	.string "でかけたく なってきたなあ!$"

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese:
	.string "{JPN}ハルカ: わあ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "ポケモンずかんを もらったんだ!\p"
	.string "よかったね! わたしと おそろいだ!\n"
	.string "わたしからも あげたいものが あるの!$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls:
	.string "{JPN}ハルカ: ポケモンを たくさん\n"
	.string "つかまえられると たのしいよね!\p"
	.string "いろんな ポケモンが ほしいから\n"
	.string "あちこち さがしてみるんだ。\p"
	.string "かわいい ポケモンを みつけたら\n"
	.string "モンスターボールで つかまえるの!$"

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull:
	.string "{JPN}あら？ バッグが いっぱいだね。$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext:
	.string "{JPN}ハルカ: つぎは どこへ ポケモンを\n"
	.string "さがしに いこうかな？$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese:
	.string "{JPN}ユウキ: へえ…\n"
	.string "きみも ポケモンずかんを もらったんだ。\p"
	.string "それなら ほら。\n"
	.string "これを あげるよ。$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls:
	.string "{JPN}ユウキ: ポケモンは たくさん\n"
	.string "もっているほうが たのしいよね。\p"
	.string "いろんな ポケモンを さがして\n"
	.string "あちこち たんけん するつもりさ。\p"
	.string "かっこいい ポケモンを みつけたら\n"
	.string "モンスターボールで つかまえてみるよ!$"

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull:
	.string "{JPN}おいおい バッグが いっぱいだよ。$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext:
	.string "{JPN}ユウキ: つぎは どこで ポケモンを\n"
	.string "さがそうかな…$"

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine:
	.string "{JPN}たいそうな きかいだ。\n"
	.string "きっと はかせが けんきゅうに つかうのだろう。$"

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch:
	.string "{JPN}けんきゅうに つかう パソコンだ。\n"
	.string "いじらないほうが よさそうだ。$"

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon:
	.string "{JPN}ポケモンの ほんが ぎっしり つまっている。$"

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead:
	.string "{JPN}むずかしくて よめない ほんだ。$"

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational:
	.string "{JPN}オダマキ: さて…\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}と {ENG}{RIVAL}{JPN}には\n"
	.string "ポケモンの ちょうさを てつだってもらったね。\p"
	.string "おかげで あたらしいことが\n"
	.string "いろいろ わかってきたよ。\p"
	.string "ホウエンには どうやら\n"
	.string "ほかの ちほうの ポケモンも\l"
	.string "すんでいるよう なんだ。\p"
	.string "それだけ ホウエンの しぜんが\n"
	.string "ゆたかで さまざまな かんきょうに\l"
	.string "めぐまれている しょうこだね。\p"
	.string "だから きみたちの ずかんも\n"
	.string "ぜんこくモードに かきかえる\l"
	.string "ひつようが あると おもうんだ。\p"
	.string "さあ ふたりの ずかんを みせておくれ。$"

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool:
	.string "{JPN}ハルカ: えへへ!\p"
	.string "わたしの ずかんまで\n"
	.string "あたらしく なっちゃうなんて すごいね!\p"
	.string "ポケモンを たくさん つかまえてくれた\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}の おかげだよ!$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe:
	.string "{JPN}ユウキ: ぼくが ホウエンじゅうを\n"
	.string "あるいて ポケモンを しらべたんだ。\p"
	.string "ずかんが ぜんこくモードに なったのは\n"
	.string "ぼくの おかげだよ。\p"
	.string "ほんと {ENG}{PLAYER}{JPN}は うんが いいね!$"

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone:
	.string "{JPN}オダマキ: よし できたよ!$"

LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational:
	.string "{JPN}{ENG}{PLAYER}{JPN}の ポケモンずかんが\n"
	.string "ぜんこくモードに パワーアップした!$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2:
	.string "{JPN}オダマキ: でも いいかい。\n"
	.string "チャンピオンに なったからといって\l"
	.string "ポケモンの たびが おわるわけじゃない。\p"
	.string "ポケモンと あるく みちに\n"
	.string "おわりは ないんだ。\p"
	.string "どこかに きみを まっている\n"
	.string "くさむらが あるんだよ!$"

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork:
	.string "{JPN}ハルカ: しばらく フィールドワークを\n"
	.string "おやすみ しようかな。\p"
	.string "ここで はかせの おてつだいを\n"
	.string "していようと おもうんだ。$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork:
	.string "{JPN}ユウキ: しばらくは\n"
	.string "フィールドワークを おやすみするよ。\p"
	.string "ここで はかせを\n"
	.string "てつだうことに するつもりさ。$"

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon:
	.string "{JPN}オダマキ: おや {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "ずかんを みせてもらおうかな。\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "うん まちがいないね。\p"
	.string "ほんとうに ホウエンちほうの\n"
	.string "ポケモンずかんを かんせいさせたんだ。\p"
	.string "すごいなんて ことばじゃ たりないよ。\p"
	.string "きみに おくりものが あるんだ。\p"
	.string "すばらしい せいかを あげてくれた\n"
	.string "きみへの おれいと おもってほしい。\p"
	.string "ほかの ちほうでしか みつからない\n"
	.string "めずらしい ポケモンだよ!\p"
	.string "この 3びきの なかから すきな\n"
	.string "1ぴきを えらんで いいんだよ!$"

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon:
	.string "{JPN}オダマキ: ほかの ちほうでしか\n"
	.string "みつからない めずらしい ポケモンだよ!\p"
	.string "この 3びきの なかから すきな\n"
	.string "1ぴきを えらんで いいんだよ!$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil:
	.string "{JPN}オダマキ: ほのおポケモンの\n"
	.string "ヒノアラシに めが とまったんだね!\p"
	.string "やっぱり おめが たかいね!\p"
	.string "それじゃ ヒノアラシに するかい？$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile:
	.string "{JPN}オダマキ: みずポケモンの\n"
	.string "ワニノコを えらんだんだね!\p"
	.string "いい ポケモンを えらぶね。\p"
	.string "それじゃ ワニノコに するかい？$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita:
	.string "{JPN}オダマキ: くさポケモンの\n"
	.string "チコリータを えらんだんだね!\p"
	.string "よく わかっているじゃないか。\p"
	.string "それじゃ チコリータに するかい？$"

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable:
	.string "{JPN}オダマキ: えらぶまえに\n"
	.string "ゆっくり かんがえると いいよ。\p"
	.string "どれも かけがえのない ポケモンだからね。$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon:
	.string "{JPN}オダマキ: なるほど!\n"
	.string "いい ポケモンを えらんだね!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter:
	.string "{JPN}{ENG}{PLAYER}{JPN}は {ENG}{STR_VAR_1}{JPN}を\n"
	.string "オダマキはかせから もらった!$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter:
	.string "{JPN}もらった\n"
	.string "{ENG}{STR_VAR_1}{JPN}に なまえを つけますか？$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting:
	.string "{JPN}オダマキ: いいかい {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}。\n"
	.string "ホウエンずかんを かんせいさせたからといって\l"
	.string "ポケモンの たびが おわるわけじゃない。\p"
	.string "ポケモンと あるく みちに\n"
	.string "おわりは ないんだ。\p"
	.string "どこかに きみを まっている\n"
	.string "くさむらが あるんだよ!$"

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone:
	.string "{JPN}やくそくの ポケモンは もらった。\n"
	.string "ほかの ポケモンは そのままに しておこう。$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon:
	.string "{JPN}おや この ポケモンを\n"
	.string "うけとる あきが ないようだね。$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere:
	.string "{JPN}ハルカ: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} このあとは…\n"
	.string "どうする つもり？\p"
	.string "たたかい つづけて\n"
	.string "うでを みがくのかな？\p"
	.string "それとも ぜんこくずかんの\n"
	.string "かんせいを めざすのかな？\p"
	.string "わたしは ここで はかせを てつだうよ。$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly:
	.string "{JPN}ユウキ: ポケモンを あつめるよりも\n"
	.string "ぼくは じぶんの えらんだ ポケモンを\l"
	.string "じっくり ゆっくり そだてるほうが すきだな。$"

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier:
	.string "{JPN}ハルカ: やあ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "あの ばしょに いってみた？\l"
	.string "バトルフロンティアに。$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier:
	.string "{JPN}ユウキ: よう {ENG}{PLAYER}{JPN}!\n"
	.string "あの ばしょに いってみたかい？\l"
	.string "バトルフロンティアに。$"

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
	.string "{JPN}… … … … … …\n"
	.string "… … … … … ピッ!\p"
	.string "エニシダ: やあやあ {ENG}{PLAYER}{JPN}!\n"
	.string "わたしだよ エニシダだよ。\p"
	.string "いま タイドリップごうに のっているんだ。\n"
	.string "うみの うえは きもちが いいねえ!\p"
	.string "ところで…\p"
	.string "きみを しょうたいしたい ばしょが\n"
	.string "あるんだけど どうかな？\p"
	.string "きょうみが あるなら ふねに\n"
	.string "のっておくれ。 カイナか ミナモからね。\p"
	.string "くわしい はなしは\n"
	.string "あったときに するよ。 まっているぞ!\p"
	.string "… … … … … …\n"
	.string "… … … … … ツー!$"
