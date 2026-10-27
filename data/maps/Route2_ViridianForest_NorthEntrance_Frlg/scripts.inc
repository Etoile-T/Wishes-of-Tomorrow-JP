Route2_ViridianForest_NorthEntrance_Frlg_MapScripts::
	.byte 0

Route2_ViridianForest_NorthEntrance_EventScript_Youngster::
	msgbox Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests, MSGBOX_NPC
	end

Route2_ViridianForest_NorthEntrance_EventScript_OldMan::
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees, MSGBOX_NPC
	end

Route2_ViridianForest_NorthEntrance_EventScript_CooltrainerF::
	msgbox Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution, MSGBOX_NPC
	end

Route2_ViridianForest_NorthEntrance_Text_ManyMonsOnlyInForests::
	.string "{JPN}もりや どうくつにしか いない\n"
	.string "ポケモンも たくさん いるんだ。\p"
	.string "いろんな しゅるいを あつめるなら\n"
	.string "ねばりづよく あちこち さがさないとね。$"

Route2_ViridianForest_NorthEntrance_Text_CanCutSkinnyTrees::
	.string "{JPN}みちばたの ほそい きに\n"
	.string "きづいた?\p"
	.string "ポケモンの とくべつな わざで\n"
	.string "きりたおせるって きいたよ。$"

Route2_ViridianForest_NorthEntrance_Text_CanCancelEvolution::
	.string "{JPN}しんかを キャンセルする\n"
	.string "テクニックを しってる?\p"
	.string "ポケモンが しんか している ときに\n"
	.string "とちゅうで とめられるんだ。\p"
	.string "ポケモンを そのままの すがたで\n"
	.string "そだてるための テクニックだよ。$"

