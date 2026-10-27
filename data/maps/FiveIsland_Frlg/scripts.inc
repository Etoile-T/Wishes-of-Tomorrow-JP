FiveIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_OnTransition
	.byte 0

FiveIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND
	end

FiveIsland_EventScript_IslandSign::
	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
	end

FiveIsland_EventScript_BugCatcher::
	msgbox FiveIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end

FiveIsland_EventScript_Fisher::
	msgbox FiveIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end

FiveIsland_Text_IslandSign::
	.string "{JPN}ここは 5のしま\n"
	.string "ときの ながれる しま$"

FiveIsland_Text_WeirdBuildingInMeadow::
	.string "{JPN}もう つまんない! みずべのはらで\n"
	.string "あそびたかったのに。\p"
	.string "でも へんな たてものが できて\n"
	.string "あそべなく なっちゃったの。$"

FiveIsland_Text_BeenGettingBusierAroundHere::
	.string "{JPN}さいきん この あたりは\n"
	.string "さわがしく なってきたな。\p"
	.string "いい さかなも あんまり\n"
	.string "つれなく なったし。$"

