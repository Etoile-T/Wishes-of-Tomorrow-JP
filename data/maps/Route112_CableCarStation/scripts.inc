@ WoT: the valley station of the Frostwood gondola; its door opens onto Route_2.
@ Emerald's Mt. Chimney cable car ride is gone. VAR_CABLE_CAR_STATION_STATE 2
@ means the player just rode down from Frostwood (FrostwoodTown_EventScript_GondolaDoor
@ sets it before warping onto 6,4, the spot in front of the car).
Route112_CableCarStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_CableCarStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route112_CableCarStation_OnFrame
	.byte 0

Route112_CableCarStation_OnTransition:
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_MoveAttendantAside
	end

@ She stands in the one-tile walkway, so she waits beside the car while the
@ player walks out.
Route112_CableCarStation_EventScript_MoveAttendantAside::
	setobjectxyperm LOCALID_ROUTE112_CABLE_CAR_ATTENDANT, 7, 4
	setobjectmovementtype LOCALID_ROUTE112_CABLE_CAR_ATTENDANT, MOVEMENT_TYPE_FACE_LEFT
	return

Route112_CableCarStation_OnFrame:
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, Route112_CableCarStation_EventScript_ArriveFromFrostwood
	.2byte 0

Route112_CableCarStation_EventScript_ArriveFromFrostwood::
	lockall
	applymovement LOCALID_PLAYER, Route112_CableCarStation_Movement_ExitGondola
	applymovement LOCALID_ROUTE112_CABLE_CAR_ATTENDANT, Route112_CableCarStation_Movement_AttendantBackToPost
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCALID_ROUTE112_CABLE_CAR_ATTENDANT, 6, 6
	setobjectmovementtype LOCALID_ROUTE112_CABLE_CAR_ATTENDANT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

Route112_CableCarStation_EventScript_Attendant::
	lock
	faceplayer
	msgbox Route112_CableCarStation_Text_GondolaReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route112_CableCarStation_EventScript_DeclineRide
	msgbox Route112_CableCarStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	hidefollower
	applymovement LOCALID_ROUTE112_CABLE_CAR_ATTENDANT, Route112_CableCarStation_Movement_LeadPlayerToGondola
	applymovement LOCALID_PLAYER, Route112_CableCarStation_Movement_BoardGondola
	waitmovement 0
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	@ Frostwood's station door, the same tile the player walked in on.
	warp MAP_FROSTWOOD_TOWN, 45, 9
	waitstate
	release
	end

Route112_CableCarStation_EventScript_DeclineRide::
	msgbox Route112_CableCarStation_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

Route112_CableCarStation_EventScript_BoardGuy::
	lock
	faceplayer
	msgbox Route112_CableCarStation_Text_BoardGuy, MSGBOX_DEFAULT
	release
	end

Route112_CableCarStation_Movement_LeadPlayerToGondola:
	walk_up
	walk_up
	walk_right
	walk_in_place_faster_left
	step_end

Route112_CableCarStation_Movement_BoardGondola:
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

Route112_CableCarStation_Movement_ExitGondola:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

Route112_CableCarStation_Movement_AttendantBackToPost:
	delay_16
	walk_left
	walk_down
	walk_down
	step_end

Route112_CableCarStation_Text_GondolaReady:
	.string "{JPN}フロストウッドタウンへ のぼる\n"
	.string "ゴンドラが しゅっぱつします。\p"
	.string "おのりに なりますか？$"

Route112_CableCarStation_Text_StepThisWay:
	.string "{JPN}こちらへ どうぞ。$"

Route112_CableCarStation_Text_RideAnotherTime:
	.string "{JPN}またの ごりようを おまちしています。$"

Route112_CableCarStation_Text_BoardGuy:
	.string "{JPN}スノーボード… サーフボード… スノーボード…\p"
	.string "フロストウッドには ふかふかの こなゆき…\n"
	.string "センネンには おおきな なみ…\p"
	.string "あさ いちばんの ゴンドラが でてから\n"
	.string "ずっと ここに たっているんだ。\p"
	.string "どうして だれも りょうほう できる\n"
	.string "ボードを つくってくれないんだ？!$"
