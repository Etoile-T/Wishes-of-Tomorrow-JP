SSAnne_Deck_Frlg_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_ShipDepartingSoon, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_FeelSeasick, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_ScrubbingDecksHardWork, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondIntro, SSAnne_Deck_Text_EdmondDefeat
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorIntro, SSAnne_Deck_Text_TrevorDefeat
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_Text_ShipDepartingSoon::
	.string "{JPN}パーティは おわったよ。\n"
	.string "ふねは もうすぐ しゅっこうだ。$"

SSAnne_Deck_Text_ScrubbingDecksHardWork::
	.string "{JPN}ふう!\n"
	.string "かんぱんみがきは おおしごとだ!$"

SSAnne_Deck_Text_FeelSeasick::
	.string "{JPN}うぅ… きもちわるい…\p"
	.string "ふなよい したから そとの くうきを\n"
	.string "すいに でて きたんだ…$"

SSAnne_Deck_Text_EdmondIntro::
	.string "{JPN}よう あいぼう!\p"
	.string "ちょいと おどろうぜ!$"

SSAnne_Deck_Text_EdmondDefeat::
	.string "{JPN}やるじゃねえか!$"

SSAnne_Deck_Text_EdmondPostBattle::
	.string "{JPN}この ひろい せかいに ポケモンは\n"
	.string "なんしゅるい いると おもう?$"

SSAnne_Deck_Text_TrevorIntro::
	.string "{JPN}おーい!\n"
	.string "ふなよい してないか?$"

SSAnne_Deck_Text_TrevorDefeat::
	.string "{JPN}ちょっと ゆだん しただけだ!$"

SSAnne_Deck_Text_TrevorPostBattle::
	.string "{JPN}おやじは ポケモンは 100しゅるい\n"
	.string "いるって いうけど もっと いると おもう。$"

