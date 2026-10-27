SevenIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
	.byte 0

SevenIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND
	end

SevenIsland_EventScript_IslandSign::
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end

SevenIsland_EventScript_OldWoman::
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

SevenIsland_EventScript_Scientist::
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end

Text_SwordsDanceTeach::
	.string "{JPN}ここには あまり ひとが こない。\p"
	.string "ここで しゅぎょうすれば きっと\n"
	.string "どんどん つよく なれると おもう。\p"
	.string "そう どんどん つよく…\p"
	.string "そんな わざを おぼえて みない?\n"
	.string "つるぎのまい って いうんだ。$"

Text_SwordsDanceDeclined::
	.string "{JPN}まあ それも いいさ。$"

Text_SwordsDanceWhichMon::
	.string "{JPN}じゃあ どの ポケモンに\n"
	.string "おしえるか えらんで。$"

Text_SwordsDanceTaught::
	.string "{JPN}ずっと どんどん つよく\n"
	.string "なれたら いいよな?$"

SevenIsland_Text_IslandSign::
	.string "{JPN}7のしま\n"
	.string "はてしない ちょうせんの しま$"

SevenIsland_Text_IslandsMadeInSevenDays::
	.string "{JPN}この しまじまが ナナシマと\n"
	.string "よばれるのは 7つ あるからだ。\p"
	.string "…と わかい ひとたちは\n"
	.string "おもっているようだが。\p"
	.string "ほんとうは この しまじまは\n"
	.string "7かで つくられたと いわれている\l"
	.string "ことから そう よばれて いるんだ。$"

SevenIsland_Text_IslandVirtuallyUntouched::
	.string "{JPN}この しまは しぜんの ままの\n"
	.string "すがたが ほとんど のこっている。\p"
	.string "だから あるきまわるのは\n"
	.string "ちょっと たいへん かもしれない。$"

