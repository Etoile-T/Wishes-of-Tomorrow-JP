DistortionWorld_3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DistortionWorld_3_OnTransition
	.byte 0

@ Inverted-gravity state: FLAG_DW_INVERT_PENDING carries the upside-down state
@ through intra-map warps (a warp reloads the map, which would otherwise clear
@ it here). Fresh entries from anywhere else always land right-side-up.
DistortionWorld_3_OnTransition::
	setrespawn HEAL_LOCATION_NATIONAL_PARK_ACT2
	goto_if_set FLAG_DW_INVERT_PENDING, DistortionWorld_3_OnTransition_StayInverted
	clearflag FLAG_DW_INVERTED
	end
DistortionWorld_3_OnTransition_StayInverted::
	clearflag FLAG_DW_INVERT_PENDING
	setflag FLAG_DW_INVERTED
	end

@ Right-edge portal: lower corridor (30,20) <-> ceiling corridor (30,12).
@ Going UP flips the player (arrive inverted); coming back DOWN restores.
DistortionWorld_3_EventScript_PortalUp::
	lockall
	playse SE_WARP_IN
	setflag FLAG_DW_INVERT_PENDING
	warp MAP_DISTORTION_WORLD_3, 30, 12
	waitstate
	releaseall
	end

DistortionWorld_3_EventScript_PortalDown::
	lockall
	playse SE_WARP_IN
	warp MAP_DISTORTION_WORLD_3, 30, 20
	waitstate
	releaseall
	end

@ Rift Shard ball (placeholder spot 29,15 -- move it when the layer is
@ painted). Taking it deepens the rift: VAR_DISTORTION_RIFT_DEPTH -> 2, so
@ the DistortionWorld_2 cave re-aims at DistortionWorld_4, and Gengar
@ collapses this visit the same way the first Distortion World ended.
@ Std_FindItem clobbers VAR_RESULT internally, so success is re-checked with
@ checkitem; if the bag was somehow full the ball stays and nothing advances.
DistortionWorld_3_EventScript_RiftShard::
	finditem ITEM_RIFT_SHARD
	checkitem ITEM_RIFT_SHARD
	goto_if_eq VAR_RESULT, FALSE, DistortionWorld_3_EventScript_ShardLeftBehind
	setvar VAR_DISTORTION_RIFT_DEPTH, 2
	goto DistortionRift_EventScript_GengarCollapse

DistortionWorld_3_EventScript_ShardLeftBehind::
	end

@ The rift's first keeper -- a stranger who has been down here too long.
DistortionWorld_3_EventScript_Warden::
	trainerbattle_single TRAINER_RIFT_WARDEN, DistortionWorld_3_Text_WardenIntro, DistortionWorld_3_Text_WardenDefeat
	msgbox DistortionWorld_3_Text_WardenPost, MSGBOX_AUTOCLOSE
	end

DistortionWorld_3_Text_WardenIntro::
	.string "{JPN}いきたものの あるきかただ。\p"
	.string "さけめには てばなせぬものが のこる。\n"
	.string "なぜ じぶんが のこされたか しるために\l"
	.string "ここに とどまった。\p"
	.string "せかいを つかむ ちからを みせてみろ。$"

DistortionWorld_3_Text_WardenDefeat::
	.string "{JPN}…つよく つかんでいる。 わたし いじょうに。$"

DistortionWorld_3_Text_WardenPost::
	.string "{JPN}おくへ いくほど いしの あいだは ひろがる。\n"
	.string "おもいきって とべ。 ためらえば\l"
	.string "どこまでも おちるぞ。$"
