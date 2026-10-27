FuchsiaCity_House1_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 2
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
	.string "{JPN}サファリゾーンの えんちょうは\n"
	.string "としよりだけど まだまだ げんきだよ。\p"
	.string "でも はは ぜんぶ いればなんだ。$"

FuchsiaCity_House1_Text_BillIsMyGrandson::
	.string "{JPN}ん?\n"
	.string "マサキに あったのかい?\p"
	.string "あの こは わしの まごじゃよ!\p"
	.string "こどもの ころから ものを\n"
	.string "あつめるのが すきでなあ!$"

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
	.string "{JPN}マサキは じぶんの パソコンに\n"
	.string "ポケモンの データを まとめておる。\p"
	.string "みせて もらったかい?$"

