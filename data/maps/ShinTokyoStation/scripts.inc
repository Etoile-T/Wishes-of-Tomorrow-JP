ShinTokyoStation_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShinTokyoStation_OnFrame
	.byte 0

@ ============================================================================
@  ACT 3, STEP 1 -- ARRIVAL AT SHIN-TOKYO CENTRAL (WoT_Act3_Canon.md)
@  Canon staging: a train enters the city in the rain. No music (map music is
@  MUS_NONE) -- only train sounds. No welcoming NPCs. The player remembers the
@  allies lost at Sennen station, steps off, and the city feels wrong.
@  The player is warped here from the Act-2 seat cutscene
@  (ShinkansenInterior_EventScript_TakeSeat) into the WEST gate at (6,5) and
@  steps down onto the concourse. Rows 0-4 are solid track band; row 5 has
@  exactly two gaps, x=6 and x=10, and those are the gates.
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================
ShinTokyoStation_OnFrame:
	map_script_2 VAR_TEMP_1, 0, ShinTokyoStation_EventScript_Arrival
	.2byte 0

ShinTokyoStation_EventScript_Arrival::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_ACT3_ARRIVED_SHIN_TOKYO, ShinTokyoStation_EventScript_ArrivalDone
	delay 30
	@ The doors hiss; the train sits at the player's back (train art is a
	@ placeholder gap for now -- the track band is the two wall rows north).
	playse SE_TRUCK_DOOR
	delay 40
	msgbox ShinTokyoStation_Text_Arrival1, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox ShinTokyoStation_Text_Arrival2, MSGBOX_DEFAULT
	closemessage
	@ The train pulls away behind them. There is no going back.
	playse SE_TRUCK_MOVE
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyoStation_Movement_StepOff
	waitmovement 0
	msgbox ShinTokyoStation_Text_Arrival3, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ACT3_ARRIVED_SHIN_TOKYO
ShinTokyoStation_EventScript_ArrivalDone::
	releaseall
	end

ShinTokyoStation_Movement_StepOff:
	walk_down
	walk_down
	step_end

ShinTokyoStation_EventScript_DepartureBoard::
	msgbox ShinTokyoStation_Text_DepartureBoard, MSGBOX_SIGN
	end

@ Both gates (6,5) and (10,5) run this. A walk-on trigger rather than a sign:
@ the point is to turn the player around when they head back up, and a sign
@ would only talk to someone who chose to press A at it.
@ Guarded on the arrival flag because the player is warped in ONTO (6,5), and
@ the trigger would otherwise fire underneath the arrival cutscene.
ShinTokyoStation_EventScript_NoTurningBack::
	goto_if_unset FLAG_ACT3_ARRIVED_SHIN_TOKYO, ShinTokyoStation_EventScript_NoTurningBackEnd
	lockall
	msgbox ShinTokyoStation_Text_NoTurningBack, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyoStation_Movement_BackToConcourse
	waitmovement 0
	releaseall
ShinTokyoStation_EventScript_NoTurningBackEnd::
	end

ShinTokyoStation_Movement_BackToConcourse:
	walk_down
	step_end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
ShinTokyoStation_Text_Arrival1::
	.string "{JPN}ドアが ひらいた。\p"
	.string "アナウンスも ひとごみも ない。\n"
	.string "ホームに あめが ふっている だけ。$"

ShinTokyoStation_Text_Arrival2::
	.string "{JPN}Yiffer。 RedFatality。\p"
	.string "センネンの ホームが いまも\n"
	.string "まぶたの うらに うかぶ。$"

ShinTokyoStation_Text_Arrival3::
	.string "{JPN}シントウキョウ。\p"
	.string "あしたの まち。\n"
	.string "まちは あなたを ふりかえらない。$"

ShinTokyoStation_Text_NoTurningBack::
	.string "{JPN}もう ひきかえせない。$"

ShinTokyoStation_Text_DepartureBoard::
	.string "{JPN}しゅっぱつ:\p"
	.string "すべての びん うんきゅう…\n"
	.string "しせいきょくの めいれいに よる。$"
