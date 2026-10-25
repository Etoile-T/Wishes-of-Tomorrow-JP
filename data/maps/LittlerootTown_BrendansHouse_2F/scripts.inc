LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_Ret
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos

LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_BrendansHouse_2F_EventScript_Ret::
	return

LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
	return

LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth:
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest:
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest:
	delay_8
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast:
	walk_up
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

WotText_PCRandomizerAsk::
	.string "{JPN}いえの パソコンは まだ\n"
	.string "せっていがめんの ままだ。\p"
	.string "ランダマイザーの せっていを ひらく？$"

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	@ Wishes of Tomorrow: this is the player's bedroom (Munen's house warps
	@ here). Until the adventure actually starts -- i.e. before the starter is
	@ taken -- the PC offers the RANDOMIZER settings, so the choice can be
	@ revisited without starting a new file. Afterwards it is a normal PC.
	goto_if_set FLAG_RECEIVED_STARTER, LittlerootTown_BrendansHouse_2F_EventScript_PCNormal
	msgbox WotText_PCRandomizerAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_BrendansHouse_2F_EventScript_PCNormal
	closemessage
	fadescreen FADE_TO_BLACK
	special WotOpenRandomizerMenu
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_PCNormal::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Notebook::
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

PlayersHouse_2F_EventScript_GameCube::
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayersHouse_2F_Text_ClockIsStopped:
	.string "{JPN}とけいが とまっている…\p"
	.string "じかんを あわせて うごかそう！$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
	.string "{JPN}ママ: {ENG}{PLAYER}{JPN} あたらしい へやは\n"
	.string "どう？\p"
	.string "よかった！ ちゃんと かたづいてるわね！\p"
	.string "したの かいも ぜんぶ\n"
	.string "はこびおわったわ。\p"
	.string "ポケモンの ひっこしやさんって べんりね！\p"
	.string "そうだ つくえの うえの ものが\n"
	.string "ぜんぶ そろってるか たしかめてね。$"

PlayersHouse_2F_Text_Notebook:
	.string "{JPN}{ENG}{PLAYER}{JPN}は ノートを ひらいた。\p"
	.string "ぼうけんの こころえ その1\n"
	.string "STARTで メニューを ひらこう。\p"
	.string "ぼうけんの こころえ その2\n"
	.string "レポートで きろくを のこそう。\p"
	.string "あとの ページは まっしろだ…$"

Common_Text_LookCloserAtMap:
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "{ENG}{REGION}{JPN}ちほうの ちずを よく みた。$"

PlayersHouse_2F_Text_ItsAGameCube:
	.string "{JPN}ニンテンドー ゲームキューブだ。\p"
	.string "ゲームボーイアドバンスが\n"
	.string "コントローラーとして つながっている。$"

@==============================================================================
@ DEV TEST NPC -- hands the player one high-level MEWTWO for blitzing the build.
@==============================================================================
PlayersBedroom_EventScript_DevNpc::
	lock
	faceplayer
	goto_if_set FLAG_GOT_DEV_MEWTWO, PlayersBedroom_EventScript_DevAlready
	msgbox PlayersBedroom_Text_DevAsk, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PlayersBedroom_EventScript_DevNo
	@ Armored Mewtwo is the "special" quality on its own -- not shiny.
	givemon SPECIES_MEWTWO_ARMORED, 80, , , NATURE_MODEST, , , , , , , , , 31, 31, 31, 31, 31, 31, MOVE_PSYSTRIKE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM, MOVE_FLAMETHROWER
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq PlayersBedroom_EventScript_DevNoRoom
	setflag FLAG_GOT_DEV_MEWTWO
	playfanfare MUS_OBTAIN_ITEM
	msgbox PlayersBedroom_Text_DevGive, MSGBOX_DEFAULT
	waitfanfare
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq PlayersBedroom_EventScript_DevToPC
	release
	end

PlayersBedroom_EventScript_DevToPC::
	msgbox PlayersBedroom_Text_DevToPC, MSGBOX_DEFAULT
	release
	end

PlayersBedroom_EventScript_DevNoRoom::
	msgbox PlayersBedroom_Text_DevNoRoom, MSGBOX_DEFAULT
	release
	end

PlayersBedroom_EventScript_DevNo::
	msgbox PlayersBedroom_Text_DevNo, MSGBOX_DEFAULT
	release
	end

PlayersBedroom_EventScript_DevAlready::
	msgbox PlayersBedroom_Text_DevAlready, MSGBOX_DEFAULT
	release
	end

PlayersBedroom_Text_DevAsk:
	.string "{JPN}ねえ… でかける まえに。\p"
	.string "きみ かいはつしゃ？$"

PlayersBedroom_Text_DevGive:
	.string "{JPN}やっぱりね。 ほら これで ビルドを\n"
	.string "かけぬけて ぜんぶ テストして くれ。\p"
	.string "{ENG}{PLAYER}{JPN}は こうレベルの\n"
	.string "いろちがいの ミュウツーを もらった！$"

PlayersBedroom_Text_DevToPC:
	.string "{JPN}てもちが いっぱい だったので\n"
	.string "パソコンの ボックスに おくられた。$"

PlayersBedroom_Text_DevNoRoom:
	.string "{JPN}うわっ てもちも パソコンの\n"
	.string "ボックスも ぜんぶ いっぱいだ！\p"
	.string "あきを つくってから また\n"
	.string "はなしかけて。$"

PlayersBedroom_Text_DevNo:
	.string "{JPN}はは！ こだわりはか？ そんけいするよ。\n"
	.string "じゃあ じりきで てにいれて くれ。$"

PlayersBedroom_Text_DevAlready:
	.string "{JPN}あの ミュウツーで もう ゲームを\n"
	.string "まっぷたつに しちゃった？$"
