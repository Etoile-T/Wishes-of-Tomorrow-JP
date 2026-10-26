LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos

LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return

LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	return

LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_MaysHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
	@ WoT: the bedroom was remapped and its rival object removed, so this
	@ cutscene has no actor and LOCALID_RIVALS_HOUSE_2F_RIVAL no longer
	@ exists. Unreachable -- kept as a stub so every label still resolves.
	return

LittlerootTown_MaysHouse_2F_Movement_MayEnters:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
	walk_up
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RivalsHouse_2F_EventScript_Rival::
	lockall
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_Brendan
	end

RivalsHouse_2F_EventScript_May::
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_Brendan::
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_RivalPostLilycove::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_MayPostLilycove
	call_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_BrendanPostLilycove
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	releaseall
	end

RivalsHouse_2F_EventScript_MayPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_MaysHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

RivalsHouse_2F_Text_MayWhoAreYou:
	.string "{JPN}えっ？\n"
	.string "だ… だれ？\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "ああ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}ね。\n"
	.string "おひっこしは きょう だったんだ。\p"
	.string "ええと… わたしは ハルカ。\n"
	.string "よろしくね!\p"
	.string "わたし…\n"
	.string "せかいじゅうの ポケモンと ともだちに\l"
	.string "なるのが ゆめ なんだ。\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}のことは\n"
	.string "パパの オダマキはかせから きいてたの。\p"
	.string "やさしい ひとだと いいなって。\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}と ともだちに なれたらって。\p"
	.string "あっ おかしいよね。\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}とは はじめて あったのに。\p"
	.string "えへへ…\p"
	.string "あっ いけない! わすれてた!\p"
	.string "やせいの ポケモンを つかまえる\n"
	.string "パパの おてつだいを するんだった!\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} また あとでね!$"

RivalsHouse_2F_Text_MayGettingReady:
	.string "{JPN}ポケモンは げんき いっぱい!\n"
	.string "どうぐも じゅんび できたし…$"

RivalsHouse_2F_Text_BrendanWhoAreYou:
	.string "{JPN}おっ!\n"
	.string "きみ…\p"
	.string "だれ？\p"
	.string "ああ {ENG}{PLAYER}{JPN}だろ？\n"
	.string "となりに こしてきたんだよな？\p"
	.string "おんなのこ だったなんて しらなかったよ。\p"
	.string "オダマキはかせの とうさんから\n"
	.string "おとなりに こしてくるのは ジムリーダーの\l"
	.string "こだって きいて おとこのこだと おもってた。\p"
	.string "ぼくは ユウキ。\n"
	.string "よろしくな おとなりさん!\p"
	.string "あれ？ {ENG}{PLAYER}{JPN} ポケモンを\n"
	.string "もっていないのかい？\p"
	.string "ぼくが つかまえて きてあげようか？\p"
	.string "ああ しまった わすれてた…\p"
	.string "やせいの ポケモンを つかまえる\n"
	.string "とうさんの てつだいを するんだった。\p"
	.string "また こんどな!$"

RivalsHouse_2F_Text_BrendanGettingReady:
	.string "{JPN}ポケモンは げんき いっぱい…\n"
	.string "どうぐも つめこんだし…$"

RivalsHouse_2F_Text_ItsRivalsPokeBall:
	.string "{JPN}{ENG}{RIVAL}{JPN}の モンスターボールだ!\p"
	.string "そのままに しておこう。$"

RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
	.string "{JPN}ハルカ: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\p"
	.string "いま ポケモンずかんを みていたの。\p"
	.string "みたことは あっても まだ つかまえていない\n"
	.string "ポケモンが たくさん いるんだ。\p"
	.string "しんかしそうな ポケモンも\n"
	.string "たくさん いるしね。\p"
	.string "つぎは どこへ ポケモンを\n"
	.string "つかまえに いこうかな？$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext:
	.string "{JPN}ハルカ: つぎは どこへ ポケモンを\n"
	.string "つかまえに いこうかな？\p"
	.string "ばったり あったら おもしろいと おもわない？\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}？$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
	.string "{JPN}ユウキ: やあ {ENG}{PLAYER}{JPN}。\p"
	.string "いま ポケモンずかんを みていたんだ。\p"
	.string "まだ つかまえなきゃ いけない\n"
	.string "ポケモンは たくさん いるけど\l"
	.string "なかなか いい かんじだよ。\p"
	.string "ずかんを みていると\n"
	.string "また たびに でたくなってくるね。$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
	.string "{JPN}ユウキ: つぎは どこで ポケモンを\n"
	.string "つかまえようか まよってるんだ。\p"
	.string "{ENG}{PLAYER}{JPN} ポケモンを つかまえに いって\n"
	.string "もし きみに あったら よかったら\l"
	.string "ポケモンしょうぶを しかけるよ。$"
