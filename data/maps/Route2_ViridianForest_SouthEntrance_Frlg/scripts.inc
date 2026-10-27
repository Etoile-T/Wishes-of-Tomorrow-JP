Route2_ViridianForest_SouthEntrance_Frlg_MapScripts::
	.byte 0

Route2_ViridianForest_SouthEntrance_EventScript_Woman1::
	msgbox Route2_ViridianForest_SouthEntrance_Text_ForestIsMaze, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_EventScript_Woman2::
	msgbox Route2_ViridianForest_SouthEntrance_Text_RattataHasWickedBite, MSGBOX_NPC
	end

Route2_ViridianForest_SouthEntrance_Text_ForestIsMaze::
	.string "{JPN}トキワのもりに いくの?\n"
	.string "あそこは しぜんの めいろだよ。\l"
	.string "まよわないように きをつけてね。$"

Route2_ViridianForest_SouthEntrance_Text_RattataHasWickedBite::
	.string "{JPN}コラッタは ちいさいけど かみつく\n"
	.string "ちからを あなどったら だめだよ。\p"
	.string "もう つかまえた?$"

