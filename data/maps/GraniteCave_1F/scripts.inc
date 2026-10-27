GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "{JPN}おい きみ\n"
	.string "この さきは ひどく くらいぞ\l"
	.string "たんけんするのは たいへんだ\p"
	.string "さっき きた あの おとこ……\n"
	.string "たしか ダイゴ とか いったな\p"
	.string "あいつは フラッシュを つかえたから\n"
	.string "だいじょうぶ だろうが……\p"
	.string "まあ であった ひとを たすけるのが\n"
	.string "おれたち やまおとこの モットーだ\p"
	.string "ほら これを きみに ゆずろう$"

GraniteCave_1F_Text_ExplainFlash:
	.string "{JPN}ひでん フラッシュを\n"
	.string "ポケモンに おぼえさせて つかうとだな\p"
	.string "まっくらな どうくつも\n"
	.string "あかるく てらせるんだぞ!\p"
	.string "まあ つかうには ムロ ポケモンジムの\n"
	.string "ジムバッジが ひつよう だがな$"

