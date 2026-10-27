PokemonLeague_ChampionsRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander
	end

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle::
	goto_if_defeated TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur::
	goto_if_defeated TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander::
	goto_if_defeated TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_ChampionsRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	setflag FLAG_TEMP_2
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_Intro
	call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_VICTORY_GYM_LEADER
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Battle
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Rematch
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_DEFEATED_CHAMP
	setflag FLAG_TEMP_4
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
	playbgm MUS_RG_SLOW_PALLET, 0
	addobject LOCALID_CHAMPIONS_ROOM_PROF_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
	closemessage
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	delay 25
	specialvar VAR_RESULT, GetStarterPokemon
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
	closemessage
	delay 13
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 5, 12
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_QuestLogEnd::
	call PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_Battle::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_BattleCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Rematch::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_RematchCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Intro::
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
	return

PokemonLeague_ChampionsRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchIntro
	return

PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerExit::
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
	delay_8
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter::
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_faster_down
	delay_16
	step_end

PokemonLeague_ChampionsRoom_Movement_OakExit::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Text_Intro::
	.string "{JPN}{ENG}{RIVAL}{JPN}: よう {ENG}{PLAYER}{JPN}!\p"
	.string "くるのを たのしみに してたぜ\n"
	.string "{ENG}{PLAYER}{JPN}!\p"
	.string "おれの ライバルなら つよく なくちゃ\n"
	.string "はりあいが ないからな。\p"
	.string "おれは ずかんを つくりながら\n"
	.string "あちこちで ポケモンを さがした。\p"
	.string "それだけ じゃない。 どんな タイプにも\n"
	.string "かてる チームを つくりあげた!\p"
	.string "そして いま…\p"
	.string "おれが ポケモンリーグ チャンピオンだ!\p"
	.string "{ENG}{PLAYER}{JPN}!\n"
	.string "これが どういう ことか わかるか?\p"
	.string "おしえて やるよ。\p"
	.string "おれが せかいで いちばん\n"
	.string "つよい トレーナー って ことさ!$"

PokemonLeague_ChampionsRoom_Text_RematchIntro::
	.string "{JPN}{ENG}{RIVAL}{JPN}: よう {ENG}{PLAYER}{JPN}!\p"
	.string "{ENG}{PLAYER}{JPN} また きたのか!\n"
	.string "ハハッ そいつは さいこうだ!\p"
	.string "おれの ライバルなら つよく なくちゃ\n"
	.string "はりあいが ないからな。\p"
	.string "おれは ずかんを つくりながら\n"
	.string "あちこちで ポケモンを さがした。\p"
	.string "それだけ じゃない。 どんな タイプにも\n"
	.string "かてる チームを つくりあげた!\p"
	.string "そして いま…\p"
	.string "おれが ポケモンリーグ チャンピオンだ!\p"
	.string "{ENG}{PLAYER}{JPN}!\n"
	.string "これが どういう ことか わかるか?\p"
	.string "おしえて やるよ。\p"
	.string "おれが せかいで いちばん\n"
	.string "つよい トレーナー って ことさ!$"

PokemonLeague_ChampionsRoom_Text_Defeat::
	.string "{JPN}うそだ!\n"
	.string "そんな ばかな!\l"
	.string "ぜんりょくの おれが まけるなんて!\p"
	.string "リーグ チャンピオンに なるために\n"
	.string "あんなに がんばったのに?\p"
	.string "おれの じだいは もう おわりかよ?\n"
	.string "こんなの ずるいぜ!$"

PokemonLeague_ChampionsRoom_Text_Victory::
	.string "{JPN}はーはッ!\n"
	.string "かった! かった! かった!\p"
	.string "{ENG}{PLAYER}{JPN}に まける ような\n"
	.string "おれさま では なーい!\p"
	.string "ま! ポケモンの\n"
	.string "てんさい {ENG}{RIVAL}{JPN}さま あいてに\l"
	.string "ここまで よく がんばった!\p"
	.string "ほめて つかわす!\n"
	.string "はーッ! はーはッはッ!$"

PokemonLeague_ChampionsRoom_Text_PostBattle::
	.string "{JPN}なぜだ?\n"
	.string "なんで まけたんだ?\p"
	.string "おれは ポケモンを そだてるのに\n"
	.string "ミスなんか しなかった…\p"
	.string "くそっ! おまえが あたらしい\n"
	.string "ポケモンリーグ チャンピオンだ!\p"
	.string "みとめたく ないけどな…$"

PokemonLeague_ChampionsRoom_Text_OakPlayer::
	.string "{JPN}オーキド: {ENG}{PLAYER}{JPN}!$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations::
	.string "{JPN}オーキド: かったんじゃな!\n"
	.string "こころから おめでとう!\p"
	.string "きみが あたらしい ポケモンリーグ\n"
	.string "チャンピオンじゃ!\p"
	.string "ずかんを つくるため はじめて\n"
	.string "{ENG}{STR_VAR_1}{JPN}と たびだった ときから\l"
	.string "ほんとうに せいちょう したのう。\p"
	.string "{ENG}{PLAYER}{JPN} きみは りっぱに なった!$"

PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival::
	.string "{JPN}オーキド: {ENG}{RIVAL}{JPN}…\n"
	.string "わしは がっかり したぞ。\p"
	.string "おまえが してんのうを やぶったと\n"
	.string "きいて かけつけたのじゃが\p"
	.string "ついた ときには おまえは\n"
	.string "もう まけておった!\p"
	.string "{ENG}{RIVAL}{JPN} なぜ まけたのか\n"
	.string "わかるか?\p"
	.string "おまえは ポケモンへの あいじょうと\n"
	.string "しんらいを わすれて しまったのじゃ。\p"
	.string "それなしでは もう にどと\n"
	.string "チャンピオンには なれんぞ!$"

PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe::
	.string "{JPN}オーキド: {ENG}{PLAYER}{JPN}。\p"
	.string "きみは しょうりが じぶん ひとりの\n"
	.string "ちからでは ないと わかっておる。\p"
	.string "きみと ポケモンの きずなは\n"
	.string "すばらしい!\p"
	.string "{ENG}{PLAYER}{JPN}!\n"
	.string "ついて きなさい!$"

