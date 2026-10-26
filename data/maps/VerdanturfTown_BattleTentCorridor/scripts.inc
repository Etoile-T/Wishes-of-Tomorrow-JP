VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "{JPN}どの コンテストに でるんだい?\n"
	.string "ひとつ アドバイスを きくかい?\p"
	.string "たとえば かわいさの コンテストでも\n"
	.string "いちじしんさは かわいさだけで\l"
	.string "きめては いないと おもうんだ。\p"
	.string "どの コンテストでも もっと うまく\n"
	.string "ポケモンを そだてる くふうが いるよ。$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "{JPN}ポケモンを かわいく そだてたの。\p"
	.string "かわいさを くらべる コンテストに\n"
	.string "ポケモンを だせるって わかったの!\p"
	.string "あいじょう たっぷりに そだててきて\n"
	.string "ほんとうに よかったわ…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "{JPN}うちの ポケモンは さいこうさ!\p"
	.string "かっこよく たくましく うつくしく\n"
	.string "かわいく かしこい。かんぺきさ!\p"
	.string "いっそ すべての コンテストで\n"
	.string "ゆうしょうを ねらってみようかな。$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "{JPN}ポケモン コンテスト\n"
	.string "ノーマルランク ステージ!$"

