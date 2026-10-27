SaffronCity_MrPsychicsHouse_Frlg_MapScripts::
	.byte 0

SaffronCity_MrPsychicsHouse_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM29_FROM_MR_PSYCHIC, SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29
	msgbox SaffronCity_MrPsychicsHouse_Text_YouWantedThis
	checkitemspace ITEM_TM29
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29
	giveitem_msg SaffronCity_MrPsychicsHouse_Text_ReceivedTM29FromMrPsychic, ITEM_TM29
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	setflag FLAG_GOT_TM29_FROM_MR_PSYCHIC
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_NoRoomForTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_YouveNoRoom
	release
	end

SaffronCity_MrPsychicsHouse_EventScript_AlreadyGotTM29::
	msgbox SaffronCity_MrPsychicsHouse_Text_ExplainTM29
	release
	end

SaffronCity_MrPsychicsHouse_Text_YouWantedThis::
	.string "{JPN}…まて! なにも いうな!\p"
	.string "これが ほしかったんだろう!$"

SaffronCity_MrPsychicsHouse_Text_ReceivedTM29FromMrPsychic::
	.string "{JPN}{ENG}{PLAYER}{JPN}は エスパーおやじから\n"
	.string "わざマシン29を もらった!$"

SaffronCity_MrPsychicsHouse_Text_ExplainTM29::
	.string "{JPN}もう わかって いるだろう?\n"
	.string "わざマシン29は サイコキネシス。\p"
	.string "あいての とくぼうを さげる\n"
	.string "ことも ある こうげきだ。$"

SaffronCity_MrPsychicsHouse_Text_YouveNoRoom::
	.string "{JPN}どこに しまう つもりだ?\n"
	.string "もう いっぱいじゃないか。$"

