Debug_MessageEnd:
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	goto Debug_MessageEnd

Debug_CheatStart::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4 @ 4: Received Running Shoes
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ 7: Told to go meet rival
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2 @ 2: Met Rival's Mom (and is corresponding gender)
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4 @ 4: Received Pokedex
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_VISITED_OLDALE_TOWN
	setflag FLAG_VISITED_DEWFORD_TOWN
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	setflag FLAG_VISITED_PETALBURG_CITY
	setflag FLAG_VISITED_SLATEPORT_CITY
	setflag FLAG_VISITED_MAUVILLE_CITY
	setflag FLAG_VISITED_RUSTBORO_CITY
	setflag FLAG_VISITED_FORTREE_CITY
	setflag FLAG_VISITED_LILYCOVE_CITY
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	release
	end

Debug_CheatStartFrlg::
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
	setflag FLAG_OPENED_START_MENU
	setflag FLAG_VISITED_OAKS_LAB
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
	givemon SPECIES_BULBASAUR, 20, ITEM_NONE
	givemon SPECIES_CHARMANDER, 20, ITEM_NONE
	givemon SPECIES_SQUIRTLE, 20, ITEM_NONE
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	setflag FLAG_HIDE_RIVAL_IN_LAB
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1 @ prevents Oak scene when trying to enter Route 1
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6 @ state after handing in parcel and getting pokedex
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
	setvar VAR_MAP_SCENE_ROUTE22, 1
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1 @ end
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_SYS_B_DASH
	setflag FLAG_BADGE01_GET
	setflag FLAG_BADGE02_GET
	setflag FLAG_BADGE03_GET
	setflag FLAG_BADGE04_GET
	setflag FLAG_BADGE05_GET
	setflag FLAG_BADGE06_GET
	setflag FLAG_BADGE07_GET
	setflag FLAG_BADGE08_GET
	setflag FLAG_GOT_BIKE_VOUCHER
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	setflag FLAG_WORLD_MAP_PALLET_TOWN
	setflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	setflag FLAG_WORLD_MAP_PEWTER_CITY
	setflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_CERULEAN_CITY
	setflag FLAG_WORLD_MAP_VERMILION_CITY
	setflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setflag FLAG_WORLD_MAP_CELADON_CITY
	setflag FLAG_WORLD_MAP_FUCHSIA_CITY
	setflag FLAG_WORLD_MAP_SAFFRON_CITY
	setflag FLAG_WORLD_MAP_CINNABAR_ISLAND
	setflag FLAG_WORLD_MAP_INDIGO_PLATEAU_EXTERIOR
	setflag FLAG_WORLD_MAP_ONE_ISLAND
	setflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_WORLD_MAP_THREE_ISLAND
	setflag FLAG_WORLD_MAP_FOUR_ISLAND
	setflag FLAG_WORLD_MAP_FIVE_ISLAND
	setflag FLAG_WORLD_MAP_SIX_ISLAND
	setflag FLAG_WORLD_MAP_SEVEN_ISLAND
	release
	end

Debug_FlagsNotSetOverworldConfigMessage::
	message Debug_FlagsNotSetOverworldConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetOverworldConfigMessage_Text:
	.string "{JPN}この きのうは つかえません!\n"
	.string "つかえる フラグを ていぎしてください:\l"
	.string "include/config/overworld.h$"

Debug_FlagsNotSetBattleConfigMessage::
	message Debug_FlagsNotSetBattleConfigMessage_Text
	goto Debug_MessageEnd

Debug_FlagsNotSetBattleConfigMessage_Text:
	.string "{JPN}この きのうは つかえません!\n"
	.string "つかえる フラグを ていぎしてください:\l"
	.string "include/config/battle.h$"

Debug_VarsNotSetBattleConfigMessage::
	message Debug_VarsNotSetBattleConfigMessage_Text
	goto Debug_MessageEnd

Debug_VarsNotSetBattleConfigMessage_Text:
	.string "{JPN}この きのうは つかえません!\n"
	.string "つかえる へんすうを ていぎしてください:\l"
	.string "include/config/battle.h$"

Debug_BoxFilledMessage::
	message Debug_BoxFilledMessage_Text
	goto Debug_MessageEnd

Debug_BoxFilledMessage_Text:
	.string "{JPN}ボックスを うめました!$"

Debug_EventScript_CheckEVs::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckEVs_End
	callnative Script_GetChosenMonOffensiveEVs
	msgbox Debug_EventScript_Text_OffensiveEVs, MSGBOX_DEFAULT
	callnative Script_GetChosenMonDefensiveEVs
	msgbox Debug_EventScript_Text_DefensiveEVs, MSGBOX_DEFAULT
Debug_EventScript_CheckEVs_End::
	releaseall
	end

Debug_EventScript_Text_OffensiveEVs:
	.string "{JPN}A{ENG}{STR_VAR_1}{JPN} C{ENG}{STR_VAR_2}{JPN}\nS{ENG}{STR_VAR_3}{JPN} (どりょくち)$"

Debug_EventScript_Text_DefensiveEVs:
	.string "{JPN}H{ENG}{STR_VAR_1}{JPN} B{ENG}{STR_VAR_2}{JPN}\nD{ENG}{STR_VAR_3}{JPN} (どりょくち)$"

Debug_EventScript_CheckIVs::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_CheckIVs_End
	callnative Script_GetChosenMonOffensiveIVs
	msgbox Debug_EventScript_Text_OffensiveIVs, MSGBOX_DEFAULT
	callnative Script_GetChosenMonDefensiveIVs
	msgbox Debug_EventScript_Text_DefensiveIVs, MSGBOX_DEFAULT
Debug_EventScript_CheckIVs_End::
	releaseall
	end

Debug_EventScript_Text_OffensiveIVs:
	.string "{JPN}A{ENG}{STR_VAR_1}{JPN} C{ENG}{STR_VAR_2}{JPN}\nS{ENG}{STR_VAR_3}{JPN} (こたいち)$"

Debug_EventScript_Text_DefensiveIVs:
	.string "{JPN}H{ENG}{STR_VAR_1}{JPN} B{ENG}{STR_VAR_2}{JPN}\nD{ENG}{STR_VAR_3}{JPN} (こたいち)$"

@ Quest menu smoke test: unlock the QUESTS start-menu entry and start a quest
Debug_EventScript_Script_1::
	setflag FLAG_SYS_QUEST_MENU_GET
	startquest QUEST_WAKING_MOUNTAIN
	release
	end

@ Quest menu smoke test: complete the quest started by Script 1
Debug_EventScript_Script_2::
	completequest QUEST_WAKING_MOUNTAIN
	release
	end

@ Quest menu smoke test: open the quest menu directly
Debug_EventScript_Script_3::
	openquestmenu
	release
	end

@ Namebox smoke test: one message per name-color tier
Debug_EventScript_Script_4::
	setspeaker SP_NAME_DRACO
	msgbox Debug_Text_NameboxVillain, MSGBOX_DEFAULT
	setspeaker SP_NAME_MASTER_GEN
	msgbox Debug_Text_NameboxQuest, MSGBOX_DEFAULT
	setspeaker SP_NAME_CLARKSON
	msgbox Debug_Text_NameboxDefault, MSGBOX_DEFAULT
	closemessage
	release
	end

Debug_Text_NameboxVillain:
	.string "{JPN}ドラコ ミュートリッドだん:\n"
	.string "なまえは あかいろの はず$"

Debug_Text_NameboxQuest:
	.string "{JPN}ゲンししょう いらいぬし:\n"
	.string "なまえは みどりいろの はず$"

Debug_Text_NameboxDefault:
	.string "{JPN}クラークソンはかせ: しろ\n"
	.string "ひろい プレートで$"

@ Portrait smoke test: Clarkson art (default = LEFT, flush on the plate),
@ compose with namebox, swap to the right, hide
Debug_EventScript_Script_5::
	showportrait PORTRAIT_CLARKSON_GENGAR
	setspeaker SP_NAME_CLARKSON
	msgbox Debug_Text_PortraitLeft, MSGBOX_DEFAULT
	showportrait PORTRAIT_COBRA, PORTRAIT_RIGHT
	setspeaker SP_NAME_COBRA
	msgbox Debug_Text_PortraitRight, MSGBOX_DEFAULT
	hideportrait
	closemessage
	release
	end

Debug_Text_PortraitLeft:
	.string "{JPN}クラークソンの かおえ きほんは\n"
	.string "ひだり プレートに ぴったり$"

Debug_Text_PortraitRight:
	.string "{JPN}かりの かおえを\n"
	.string "みぎに いれかえ$"

@ Quest toast queue test: complete + start back-to-back -> two toasts in
@ order (SE_SUCCESS then SE_PIN), no blocking, player can walk during both.
@ Boss intro card smoke test (was a stale Act-1 quest poke). Run 5x in a row
@ to check for VRAM/palette leaks -- mGBA's sprite viewer should look
@ identical after every run, and the tint must fully lift each time.
Debug_EventScript_Script_6::
	lockall
	bossintro BOSS_INTRO_EDWARDS
	releaseall
	end

@ ===========================================================================
@  WoT Shadow system test harness (debug menu -> Scripts -> 7 / 8)
@  7 = SINGLE vs a Shadow patroller. Tests: violet tint, healthbox flame,
@      switch-in aura line, snag (trainer-block waiver), delivery + nickname
@      prompt, heart gauge on the snagged mon, Shadow Boost, EXP lock.
@  8 = the jail's PARTNER DOUBLE (Mikmanc, 2v1). Tests: half-party select,
@      the manual ball-target selector, snagging the RIGHT-slot Shadow, and
@      partner-battle snags landing in the PC.
@  Both hand out balls and the Snag Machine and clear the trainer flag, so
@  they can be re-run as often as you like.
@ ===========================================================================
Debug_EventScript_Script_7::
	call Debug_EventScript_ShadowTestKit
	cleartrainerflag TRAINER_NATE
	trainerbattle_no_intro TRAINER_NATE, Debug_Text_ShadowTestDefeat
	release
	end

Debug_EventScript_Script_8::
	call Debug_EventScript_ShadowTestKit
	cleartrainerflag TRAINER_PRESTON
Debug_EventScript_Script_8_Choose::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_ne VAR_RESULT, 0, Debug_EventScript_Script_8_Battle
	special LoadPlayerParty
	release
	end

Debug_EventScript_Script_8_Battle::
	multi_2_vs_1 TRAINER_PRESTON, Debug_Text_ShadowTestDefeat, PARTNER_MIKMANC
	release
	end

Debug_EventScript_ShadowTestKit::
	additem ITEM_ULTRA_BALL, 20
	checkitem ITEM_SNAG_MACHINE
	goto_if_eq VAR_RESULT, TRUE, Debug_EventScript_ShadowTestKitDone
	additem ITEM_SNAG_MACHINE, 1
Debug_EventScript_ShadowTestKitDone::
	return

Debug_Text_ShadowTestDefeat:
	.string "{JPN}(デバッグ) シャドウ テストバトル しゅうりょう$"

Debug_CheckSaveBlock::
	callnative CheckSaveBlock1Size
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock2Size
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock3Size
	msgbox Debug_SaveBlock3Size, MSGBOX_DEFAULT
	callnative CheckPokemonStorageSize
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
	release
	end

Debug_SaveBlock1Size::
	.string "{JPN}SB1 {ENG}{STR_VAR_1}{JPN}/{ENG}{STR_VAR_2}{JPN}b\n"
	.string "あき: {ENG}{STR_VAR_3}{JPN}b$"

Debug_SaveBlock2Size::
	.string "{JPN}SB2 {ENG}{STR_VAR_1}{JPN}/{ENG}{STR_VAR_2}{JPN}b\n"
	.string "あき: {ENG}{STR_VAR_3}{JPN}b$"

Debug_SaveBlock3Size::
	.string "{JPN}SB3 {ENG}{STR_VAR_1}{JPN}/{ENG}{STR_VAR_2}{JPN}b\n"
	.string "あき: {ENG}{STR_VAR_3}{JPN}b$"

Debug_PokemonStorageSize::
	.string "{JPN}BOX {ENG}{STR_VAR_1}{JPN}/{ENG}{STR_VAR_2}{JPN}b\n"
	.string "あき: {ENG}{STR_VAR_3}{JPN}b$"

Debug_CheckROMSpace::
	callnative CheckROMSize
	msgbox Debug_ROMSize, MSGBOX_DEFAULT
	release
	end

Debug_ROMSize::
	.string "{JPN}ROM: {ENG}{STR_VAR_1}{JPN}MB/32MB\n"
	.string "あき: {ENG}{STR_VAR_2}{JPN}MB$"

Debug_HatchAnEgg::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_HatchAnEgg_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_ne VAR_RESULT, SPECIES_EGG, DebugScript_HatchAnEgg_CantForceHatch
	special EggHatch
Debug_HatchAnEgg_End::
	releaseall
	end

Debug_NoPokemon::
	msgbox DebugScript_Text_EmptyParty, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_HatchAnEgg_CantForceHatch::
	msgbox DebugScript_HatchAnEgg_Text_NotAnEgg, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_Text_EmptyParty::
	.string "{JPN}ポケモンも タマゴも いません$"

DebugScript_HatchAnEgg_Text_NotAnEgg::
	.string "{JPN}それは ポケモンの タマゴでは ありません$"

DebugScript_ZeroDaycareMons::
	msgbox DebugText_DaycareNoPokemon, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_OneDaycareMons::
	msgbox DebugText_DaycareOnePokemon, MSGBOX_DEFAULT
	releaseall
	end

DebugScript_DaycareMonsNotCompatible::
	msgbox DebugText_DaycarePokemonNotCompatible, MSGBOX_DEFAULT
	releaseall
	end

DebugText_DaycareNoPokemon:
	.string "{JPN}あずかりやに ポケモンが いません$"

DebugText_DaycareOnePokemon:
	.string "{JPN}あずかりやに ポケモンが 1ぴきだけです$"

DebugText_DaycarePokemonNotCompatible:
	.string "{JPN}あずかりやの ポケモンどうしでは\nタマゴが できません!$"

Debug_ShowExpansionVersion::
	callnative BufferExpansionVersion
	msgbox Debug_ExpansionVersion, MSGBOX_DEFAULT
	release
	end

Debug_ExpansionVersion:
	.string "{JPN}pokeemerald-expansion\n{ENG}{STR_VAR_1}{JPN}$"

Debug_Follower_NPC_Not_Enabled::
	msgbox Debug_Enable_To_Use_Follower_NPCs, MSGBOX_DEFAULT
	release
	end

Debug_Enable_To_Use_Follower_NPCs:
	.string "{JPN}つかえません: follower_npc.hの\nFNPC_ENABLE_NPC_FOLLOWERS\lを TRUEに してください$"

Debug_Follower_NPC_Event_Script::
	lock
	facefollowernpc
	msgbox Debug_Follower_NPC_Test_Message, MSGBOX_DEFAULT
	releaseall
	end

Debug_Follower_NPC_Test_Message:
	.string "{JPN}つれあるき NPCの テストです$"

Debug_EventScript_Steven_Multi::
	call MossdeepCity_SpaceCenter_2F_EventScript_ChoosePartyForMultiBattle
	release
	end

Debug_EventScript_WallyTutorial::
	special SavePlayerParty
	special LoadWallyZigzagoon
	special StartWallyTutorialBattle
	special LoadPlayerParty
	release
	end

Debug_BerryPestsDisabled::
	msgbox DebugText_BerryPestsDisabled, MSGBOX_DEFAULT
	release
	end

DebugText_BerryPestsDisabled:
	.string "{JPN}OW_BERRY_PESTSが オフです\n"
	.string "きのみの きに むしを だせません$"

Debug_BerryWeedsDisabled::
	msgbox DebugText_BerryWeedsDisabled, MSGBOX_DEFAULT
	release
	end

DebugText_BerryWeedsDisabled:
	.string "{JPN}OW_BERRY_WEEDSが オフです\n"
	.string "きのみの きに ざっそうを だせません$"

Debug_EventScript_InflictStatus1::
	lockall
	getpartysize
	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Single
	case 1, Debug_EventScript_InflictStatus1_Party
	case 2, Debug_EventScript_InflictStatus1_Close
Debug_EventScript_InflictStatus1_Close:
	releaseall
	end

Debug_EventScript_InflictStatus1_Single:
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Single_Poison
	case 1, Debug_EventScript_InflictStatus1_Single_Paralysis
	case 2, Debug_EventScript_InflictStatus1_Single_Sleep
	case 3, Debug_EventScript_InflictStatus1_Single_Burn
	case 4, Debug_EventScript_InflictStatus1_Single_Freeze
	case 5, Debug_EventScript_InflictStatus1_Single_Frostbite
	case 6, Debug_EventScript_InflictStatus1_Close
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	releaseall
	end

Debug_EventScript_KoPokemon::
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	setko VAR_0x8004
	releaseall
	end

Debug_EventScript_SetHiddenNature::
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, Debug_EventScript_InflictStatus1_Close
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, Debug_EventScript_InflictStatus1_Close
	dynmultipush Debug_EventScript_ChangeNature_Text_Hardy, 0
	dynmultipush Debug_EventScript_ChangeNature_Text_Lonely, 1
	dynmultipush Debug_EventScript_ChangeNature_Text_Brave, 2
	dynmultipush Debug_EventScript_ChangeNature_Text_Adamant, 3
	dynmultipush Debug_EventScript_ChangeNature_Text_Naughty, 4
	dynmultipush Debug_EventScript_ChangeNature_Text_Bold, 5
	dynmultipush Debug_EventScript_ChangeNature_Text_Docile, 6
	dynmultipush Debug_EventScript_ChangeNature_Text_Relaxed, 7
	dynmultipush Debug_EventScript_ChangeNature_Text_Impish, 8
	dynmultipush Debug_EventScript_ChangeNature_Text_Lax, 9
	dynmultipush Debug_EventScript_ChangeNature_Text_Timid, 10
	dynmultipush Debug_EventScript_ChangeNature_Text_Hasty, 11
	dynmultipush Debug_EventScript_ChangeNature_Text_Serious, 12
	dynmultipush Debug_EventScript_ChangeNature_Text_Jolly, 13
	dynmultipush Debug_EventScript_ChangeNature_Text_Naive, 14
	dynmultipush Debug_EventScript_ChangeNature_Text_Modest, 15
	dynmultipush Debug_EventScript_ChangeNature_Text_Mild, 16
	dynmultipush Debug_EventScript_ChangeNature_Text_Quiet, 17
	dynmultipush Debug_EventScript_ChangeNature_Text_Bashful, 18
	dynmultipush Debug_EventScript_ChangeNature_Text_Rash, 19
	dynmultipush Debug_EventScript_ChangeNature_Text_Calm, 20
	dynmultipush Debug_EventScript_ChangeNature_Text_Gentle, 21
	dynmultipush Debug_EventScript_ChangeNature_Text_Sassy, 22
	dynmultipush Debug_EventScript_ChangeNature_Text_Careful, 23
	dynmultipush Debug_EventScript_ChangeNature_Text_Quirky, 24
	dynmultistack 0, 0, TRUE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	special SetHiddenNature
	releaseall
	end

Debug_EventScript_SetAbility::
	special ChoosePartyMon
	callnative DebugNative_GetAbilityNames
	dynmultipush gStringVar1, 0
	dynmultipush gStringVar2, 1
	dynmultipush gStringVar3, 2
	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
	switch VAR_RESULT
	case MULTI_B_PRESSED, Debug_EventScript_SetAbilityClose
	special SetAbility
Debug_EventScript_SetAbilityClose:
	releaseall
	end

Debug_EventScript_SetFriendship::
	special ChoosePartyMon
	callnative DebugNative_Party_SetFriendship
	releaseall
	end

Debug_EventScript_GivePokerus::
	special ChoosePartyMon
	callnative DebugNative_Party_SetPokerus
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Poison:
	setstatus1 STATUS1_POISON, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Paralysis:
	setstatus1 STATUS1_PARALYSIS, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Sleep:
	setstatus1 STATUS1_SLEEP, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Burn:
	setstatus1 STATUS1_BURN, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Freeze:
	setstatus1 STATUS1_FREEZE, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Single_Frostbite:
	setstatus1 STATUS1_FROSTBITE, VAR_0x8004
	releaseall
	end

Debug_EventScript_InflictStatus1_Party:
	dynmultipush Debug_EventScript_InflictStatus1_Text_Poison, 0
	dynmultipush Debug_EventScript_InflictStatus1_Text_Paralysis, 1
	dynmultipush Debug_EventScript_InflictStatus1_Text_Sleep, 2
	dynmultipush Debug_EventScript_InflictStatus1_Text_Burn, 3
	dynmultipush Debug_EventScript_InflictStatus1_Text_Freeze, 4
	dynmultipush Debug_EventScript_InflictStatus1_Text_Frostbite, 5
	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 6
	dynmultistack 0, 0, FALSE, 7, FALSE, 0, NULL
	switch VAR_RESULT
	case 0, Debug_EventScript_InflictStatus1_Party_Poison
	case 1, Debug_EventScript_InflictStatus1_Party_Paralysis
	case 2, Debug_EventScript_InflictStatus1_Party_Sleep
	case 3, Debug_EventScript_InflictStatus1_Party_Burn
	case 4, Debug_EventScript_InflictStatus1_Party_Freeze
	case 5, Debug_EventScript_InflictStatus1_Party_Frostbite
	case 6, Debug_EventScript_InflictStatus1_Close
	case MULTI_B_PRESSED, Debug_EventScript_InflictStatus1_Close
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Poison:
	setstatus1 STATUS1_POISON, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Paralysis:
	setstatus1 STATUS1_PARALYSIS, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Sleep:
	setstatus1 STATUS1_SLEEP, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Burn:
	setstatus1 STATUS1_BURN, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Freeze:
	setstatus1 STATUS1_FREEZE, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Party_Frostbite:
	setstatus1 STATUS1_FROSTBITE, PARTY_SIZE
	releaseall
	end

Debug_EventScript_InflictStatus1_Text_Single:
	.string "{JPN}1ぴき$"

Debug_EventScript_InflictStatus1_Text_PartyWide:
	.string "{JPN}てもち ぜんいん$"

Debug_EventScript_InflictStatus1_Text_Close:
	.string "{JPN}とじる$"

Debug_EventScript_InflictStatus1_Text_Poison:
	.string "{JPN}どく$"

Debug_EventScript_InflictStatus1_Text_Paralysis:
	.string "{JPN}まひ$"

Debug_EventScript_InflictStatus1_Text_Sleep:
	.string "{JPN}ねむり$"

Debug_EventScript_InflictStatus1_Text_Burn:
	.string "{JPN}やけど$"

Debug_EventScript_InflictStatus1_Text_Freeze:
	.string "{JPN}こおり$"

Debug_EventScript_InflictStatus1_Text_Frostbite:
	.string "{JPN}しもやけ$"

Debug_EventScript_InflictStatus1_Text_KO:
	.string "{JPN}ひんし$"

Debug_EventScript_ChangeNature_Text_Hardy:
	.string "{JPN}がんばりや$"
Debug_EventScript_ChangeNature_Text_Lonely:
	.string "{JPN}さみしがり$"
Debug_EventScript_ChangeNature_Text_Brave:
	.string "{JPN}ゆうかん$"
Debug_EventScript_ChangeNature_Text_Adamant:
	.string "{JPN}いじっぱり$"
Debug_EventScript_ChangeNature_Text_Naughty:
	.string "{JPN}やんちゃ$"
Debug_EventScript_ChangeNature_Text_Bold:
	.string "{JPN}ずぶとい$"
Debug_EventScript_ChangeNature_Text_Docile:
	.string "{JPN}すなお$"
Debug_EventScript_ChangeNature_Text_Relaxed:
	.string "{JPN}のんき$"
Debug_EventScript_ChangeNature_Text_Impish:
	.string "{JPN}わんぱく$"
Debug_EventScript_ChangeNature_Text_Lax:
	.string "{JPN}のうてんき$"
Debug_EventScript_ChangeNature_Text_Timid:
	.string "{JPN}おくびょう$"
Debug_EventScript_ChangeNature_Text_Hasty:
	.string "{JPN}せっかち$"
Debug_EventScript_ChangeNature_Text_Serious:
	.string "{JPN}まじめ$"
Debug_EventScript_ChangeNature_Text_Jolly:
	.string "{JPN}ようき$"
Debug_EventScript_ChangeNature_Text_Naive:
	.string "{JPN}むじゃき$"
Debug_EventScript_ChangeNature_Text_Modest:
	.string "{JPN}ひかえめ$"
Debug_EventScript_ChangeNature_Text_Mild:
	.string "{JPN}おっとり$"
Debug_EventScript_ChangeNature_Text_Quiet:
	.string "{JPN}れいせい$"
Debug_EventScript_ChangeNature_Text_Bashful:
	.string "{JPN}てれや$"
Debug_EventScript_ChangeNature_Text_Rash:
	.string "{JPN}うっかりや$"
Debug_EventScript_ChangeNature_Text_Calm:
	.string "{JPN}おだやか$"
Debug_EventScript_ChangeNature_Text_Gentle:
	.string "{JPN}おとなしい$"
Debug_EventScript_ChangeNature_Text_Sassy:
	.string "{JPN}なまいき$"
Debug_EventScript_ChangeNature_Text_Careful:
	.string "{JPN}しんちょう$"
Debug_EventScript_ChangeNature_Text_Quirky:
	.string "{JPN}きまぐれ$"

Debug_EventScript_EWRAMCounters::
	callnative CheckEWRAMCounters
	msgbox Debug_EventScript_EWRAMCounters_Text, MSGBOX_DEFAULT
	release
	end

Debug_EventScript_EWRAMCounters_Text::
	.string "{JPN}つれあるき ほすう: {ENG}{STR_VAR_1}{JPN}\n"
	.string "つりの れんさ: {ENG}{STR_VAR_2}{JPN}$"

Debug_EventScript_FontTest_Text_1::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "あいうえお かきくけこ さしすせそ\n"
	.string "たちつてと なにぬねの はひふへほ\l"
	.string "まみむめも やゆよ らりるれろ\l"
	.string "わをん がぎぐげご ざじずぜぞ\l"
	.string "だぢづでど ばびぶべぼ ぱぴぷぺぽ\l"
	.string "ぁぃぅぇぉ っゃゅょ\l"
	.string "アイウエオ カキクケコ サシスセソ\l"
	.string "タチツテト ナニヌネノ ハヒフヘホ\l"
	.string "マミムメモ ヤユヨ ラリルレロ\l"
	.string "ワヲン ガギグゲゴ パピプペポ\l"
	.string "ァィゥェォ ッャュョ ヴ$"

Debug_EventScript_FontTest_Text_2::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "いろはにほへと ちりぬるを\n"
	.string "わかよたれそ つねならむ\l"
	.string "ういのおくやま けふこえて\l"
	.string "あさきゆめみし えひもせす\l"
	.string "とりなくこえす ゆめさませ\l"
	.string "みよあけわたる ひんかしを\l"
	.string "そらいろはえて おきつへに\l"
	.string "ほふねむれいぬ もやのうち$"

Debug_EventScript_FontTest_Text_3::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "あめつち ほし そら やま かは\n"
	.string "みね たに くも きり むろ こけ\l"
	.string "ひと いぬ うへ すえ ゆわ さる\l"
	.string "おふせよ えのえを なれいて\l"
	.string "ガラガラ ゴロゴロ ザブザブ\l"
	.string "ズンズン ダダダッ ドドドド\l"
	.string "バリバリ ピカピカ ブルブル\l"
	.string "ベタベタ ポカポカ パタパタ\l"
	.string "ヴァ ヴィ ヴ ヴェ ヴォ$"

Debug_EventScript_FontTest_Text_4::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "キャ キュ キョ シャ シュ ショ\n"
	.string "チャ チュ チョ ニャ ニュ ニョ\l"
	.string "ヒャ ヒュ ヒョ ミャ ミュ ミョ\l"
	.string "リャ リュ リョ ギャ ギュ ギョ\l"
	.string "ジャ ジュ ジョ ビャ ビュ ビョ\l"
	.string "ピャ ピュ ピョ ティ ディ トゥ\l"
	.string "ファ フィ フェ フォ ウィ ウェ\l"
	.string "シェ ジェ チェ ツァ ツォ デュ\l"
	.string "イェ クァ グァ$"

Debug_EventScript_FontTest_Text_5::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "ABCDEFGHIJKLM\n"
	.string "NOPQRSTUVWXYZ\l"
	.string "abcdefghijklm\l"
	.string "nopqrstuvwxyz\l"
	.string "0123456789\l"
	.string "! ? … ・ ー 「 」 『 』\l"
	.string "( ) : / ~ ♂ ♀ 円\l"
	.string "ピカチュウ フシギダネ ヒトカゲ\l"
	.string "ゼニガメ ポッチャマ ナエトル$"

Debug_EventScript_FontTest_Text_6::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "きょうは いい てんきですね\n"
	.string "あしたも はれると いいな\l"
	.string "ポケモンセンターで ひとやすみ\l"
	.string "フレンドリィショップで かいもの\l"
	.string "くさむらから やせいの ポケモン\l"
	.string "モンスターボールを なげた!\l"
	.string "やったー! ポケモンを\l"
	.string "つかまえたぞ!$"

Debug_EventScript_FontTest_Text_7::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "すもももももももものうち\n"
	.string "なまむぎ なまごめ なまたまご\l"
	.string "となりの きゃくは よく\l"
	.string "かきくう きゃくだ\l"
	.string "あかまきがみ あおまきがみ\l"
	.string "きまきがみ\l"
	.string "ぼうずが びょうぶに じょうずに\l"
	.string "ぼうずの えを かいた\l"
	.string "おしまい$"

Debug_EventScript_FontTest_Text_8::
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "とうきょう とっきょ きょかきょく\n"
	.string "バスガス ばくはつ\l"
	.string "かえるぴょこぴょこ みぴょこぴょこ\l"
	.string "あわせて ぴょこぴょこ むぴょこぴょこ$"


Debug_EventScript_FontTest_Text_9::                 @ Special thanks to Nintendo for this nice pangram to test other glyphs
	.string "{JPN}{FONT_SMALL_NARROWER}"                 @ Edit this to test your font
	.string "42 × 138 = 5796\n"
	.string "テレビ クイズの はかせ いわく\l"
	.string "カフェで みた ヤマネコは 2わり へり\l"
	.string "♂1/♀1 = 1円 10 + 9 - 8 = 11\l"
	.string "ゲームボーイアドバンスは\l"
	.string "ゲームキューブと つながる! と\l"
	.string "かれは いうけど めを つぶって\l"
	.string "やったって ほんとかな…?$"

Debug_PrintFontTest::
	msgbox Debug_EventScript_FontTest_Text_1, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_2, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_3, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_4, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_5, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_6, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_7, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_8, MSGBOX_DEFAULT
	msgbox Debug_EventScript_FontTest_Text_9, MSGBOX_DEFAULT
	releaseall
	end

Debug_EventScript_FontTest::
	lockall
	goto Debug_PrintFontTest
@	goto_if_eq VAR_RESULT, 0, Debug_NoPokemon
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Single, 0
@	dynmultipush Debug_EventScript_InflictStatus1_Text_PartyWide, 1
@	dynmultipush Debug_EventScript_InflictStatus1_Text_Close, 2
@	dynmultistack 0, 0, FALSE, 3 FALSE, 0, NULL
@	switch VAR_RESULT
@	case 0, Debug_EventScript_InflictStatus1_Single
@	case 1, Debug_EventScript_InflictStatus1_Party
@	case 2, Debug_EventScript_InflictStatus1_Close
@Debug_EventScript_InflictStatus1_Close:
@	releaseall
@	end

Debug_EventScript_TellTheTime::
	callnative DebugMenu_CalculateTime
	msgbox Debug_EventScript_TellTheTime_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Debug_EventScript_PrintTimeOfDay::
	callnative DebugMenu_CalculateTimeOfDay
	msgbox DebugEventScript_PrintWeekday_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Debug_EventScript_FakeRTCNotEnabled::
	msgbox Debug_EventScript_FakeRTCNotEnabled_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	return

Debug_EventScript_FakeRTCNotEnabled_Text_0:
	.string "{JPN}Fake RTCが ゆうこうに なっていません\ninclude/config/overworld.h\lで ゆうこうに してください$"


Debug_EventScript_TellTheTime_Text_0:
	.string "{JPN}にちじ: "
	.string "{ENG}{STR_VAR_1}{JPN}\n{ENG}{STR_VAR_2}{JPN}:{ENG}{STR_VAR_3}{JPN}$"

DebugEventScript_PrintWeekday_Text_0:
	.string "{JPN}じかんたい: {ENG}{STR_VAR_1}{JPN}$"

@ ===========================================================================
@  WoT Mega Dimension (debug menu -> Scripts -> Mega Dim)
@  "portal": opens a freshly rolled portal on the first portal spot of the
@  map you're standing on (Tradewind Town, National Park Act 2, the Ashlands
@  or Shin Tokyo; anywhere else = Tradewind's), unlocks the DLC (skips the
@  Tradewind intro), and drops you in front of it.
@  "10s left": inside the dimension, cuts the countdown to see the collapse.
@ ===========================================================================
Debug_EventScript_MegaDimPortal::
	special WotMegaDim_DebugOpenPortal
	release
	end

Debug_EventScript_MegaDimShortTimer::
	special WotMegaDim_DebugShortTimer
	release
	end

@ "rival": the next portal entered has a rival instead of the Mega, for as
@ long as it stays open (cycles Canari, Lida, Emma, Taunie, Tulip, Jacinthe
@ on each use).
Debug_EventScript_MegaDimRival::
	special WotMegaDim_DebugForceRival
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox Debug_Text_MegaDimRival, MSGBOX_DEFAULT
	release
	end

Debug_Text_MegaDimRival:
	.string "{JPN}つぎの ポータル: ライバル {ENG}{STR_VAR_1}{JPN}\n"
	.string "(1 カナリィ … 6 ジャサント)$"

@ "shiny": the next trip in deals its first wild Pokemon shiny, to check it
@ stays shiny (and put) when you leave and come back through the same portal.
Debug_EventScript_MegaDimShiny::
	special WotMegaDim_DebugForceShiny
	msgbox Debug_Text_MegaDimShiny, MSGBOX_DEFAULT
	release
	end

Debug_Text_MegaDimShiny:
	.string "{JPN}つぎの ポータル: さいしょの\n"
	.string "やせいの ポケモンが いろちがい$"

@ "Mable next": jumps Mable's quest chain to its next call, as if earned.
@ Collecting -> all 19 stones claimed and reported (Two Minutes completes) and
@ the Primal call rings within a second; Primals -> both caught and the
@ Rayquaza call rings. Use it on the field, outside the dimension.
Debug_EventScript_MegaDimMableNext::
	special WotMegaDim_DebugMableNext
	goto_if_ne VAR_RESULT, 1, Debug_EventScript_MegaDimMableNextDone
	goto_if_quest_complete QUEST_TWO_MINUTES, Debug_EventScript_MegaDimMableNextDone
	completequest QUEST_TWO_MINUTES
Debug_EventScript_MegaDimMableNextDone::
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox Debug_Text_MegaDimMableNext, MSGBOX_DEFAULT
	release
	end

Debug_Text_MegaDimMableNext:
	.string "{JPN}モミジ だんかい{ENG}{STR_VAR_1}{JPN} (1テスト\n"
	.string "3レックウザ でんわ) あいてると でんわが なる$"

@ "intro": forget the Mega Doomsday intro, so walking down Tradewind's
@ arrival corridor (y=6) replays it. Portals stay shut until it has played.
Debug_EventScript_MegaDimIntro::
	clearflag FLAG_WOT_MEGA_DOOMSDAY_INTRO
	msgbox Debug_Text_MegaDimIntro, MSGBOX_DEFAULT
	release
	end

Debug_Text_MegaDimIntro:
	.string "{JPN}メガの しゅうまつ イントロを リセット\n"
	.string "トレードウィンドへ おりると さいせい$"
