Route16_House_Frlg_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02
	goto_if_eq VAR_RESULT, FALSE, Route16_House_EventScript_NoRoomForHM02
	giveitem_msg Route16_House_Text_ReceivedHM02FromGirl, ITEM_HM02
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_GOT_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Fearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FEAROW, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Fearow
	waitmoncry
	release
	end

Route16_House_Text_FoundMySecretRetreat::
	.string "{JPN}あら まあ\n"
	.string "わたしの かくれがを みつけたのね\p"
	.string "わたしが ここに いること ないしょにしてね\n"
	.string "おわびに これを あげるわ!$"

Route16_House_Text_ReceivedHM02FromGirl::
	.string "{JPN}{ENG}{PLAYER}{JPN}は おんなのこから\n"
	.string "ひでんマシン02を もらった!$"

Route16_House_Text_ExplainHM02::
	.string "{JPN}ひでんマシン02は そらをとぶ\n"
	.string "とっても べんりな わざなの\p"
	.string "ぜひ やくだててね$"

Route16_House_Text_DontHaveAnyRoomForThis::
	.string "{JPN}もちきれない みたいね$"

Route16_House_Text_Fearow::
	.string "{JPN}オニドリル: キュエーン!$"

