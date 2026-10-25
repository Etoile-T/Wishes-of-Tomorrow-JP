	.set LOCALID_MUNEN_LAKE_FISHERMAN, 1

MunenLake_MapScripts::
	.byte 0

MunenLake_EventScript_Fisherman::
	lock
	faceplayer
	msgbox MunenLake_Text_Fisherman, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, MunenLake_EventScript_FishermanNoRoom
	setflag FLAG_MUNEN_LAKE_GOT_SUPER_ROD
	msgbox MunenLake_Text_FishermanFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUNEN_LAKE_FISHERMAN, MunenLake_Movement_FishermanRunOff
	waitmovement 0
	removeobject LOCALID_MUNEN_LAKE_FISHERMAN
	release
	end

MunenLake_EventScript_FishermanNoRoom::
	msgbox MunenLake_Text_FishermanNoRoom, MSGBOX_DEFAULT
	release
	end

@ Up two, THEN west. He starts at (22,6) and row 6 is walled at x=16, so the
@ old straight-west run took him through it -- applymovement does not collision
@ check. (22,5) and (22,4) are both open and row 4 is clear all the way west,
@ so climbing two tiles first gives him a lane that exists.
@ Ten steps west reaches x=12, comfortably past the screen edge (~x=15).
MunenLake_Movement_FishermanRunOff:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MunenLake_Text_Fisherman:
	.string "{JPN}マジかよ！ あいつ クソ\n"
	.string "こおりを ぶちぬいて おちやがった！\p"
	.string "やってらんねえ。\n"
	.string "こんな つり もう やめだ！\p"
	.string "ほら これ やるよ！$"

MunenLake_Text_FishermanFarewell:
	.string "{JPN}おれには むいてねえんだよ。$"

MunenLake_Text_FishermanNoRoom:
	.string "{JPN}バッグが パンパンじゃねえか。\p"
	.string "あきを つくってから おれが\n"
	.string "いなくなる まえに こいよ！$"

MunenLake_EventScript_Cameraman::
	lock
	faceplayer
	msgbox MunenLake_Text_Cameraman, MSGBOX_DEFAULT
	release
	end

MunenLake_Text_Cameraman:
	.string "{JPN}しーっ！ しずかに しな。\p"
	.string "うわさじゃ この こおった みずうみの\n"
	.string "したに でかい あかい けものが ねむってる。\p"
	.string "そいつが こおりを つきやぶった しゅんかん\n"
	.string "いっせいちだいの いちまいを とるのさ…\l"
	.string "フロストウッドしんぶんの いちめんだ！\p"
	.string "…そろそろ だな。\p"
	.string "…そろそろ だぞぉ。$"
