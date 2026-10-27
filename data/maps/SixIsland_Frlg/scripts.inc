SixIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
	.byte 0

SixIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND
	end

SixIsland_EventScript_Hiker::
	msgbox SixIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
	end

SixIsland_EventScript_Boy::
	msgbox SixIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
	end

SixIsland_EventScript_IslandSign::
	msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
	end

SixIsland_Text_IslandSign::
	.string "{JPN}6のしま\n"
	.string "ちえある としよりの しあわせのしま$"

SixIsland_Text_ThatWayToWaterPathRuinValley::
	.string "{JPN}こっちへ すすむと\n"
	.string "みずのさんぽみちに でるよ\p"
	.string "そのまま すすめば\n"
	.string "いせきのたにに つくよ$"

SixIsland_Text_SkyAtNightIsFantastic::
	.string "{JPN}これだけ まちから はなれてると\n"
	.string "よるの そらが すばらしいんだ$"

