Route119_House_MapScripts::
	.byte 0

Route119_House_EventScript_Woman::
	msgbox Route119_House_Text_RumorAboutCaveOfOrigin, MSGBOX_NPC
	end

Route119_House_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route119_House_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route119_House_Text_RumorAboutCaveOfOrigin:
	.string "{JPN}めざめのほこら って いう\n"
	.string "どうくつが あるんですって\p"
	.string "そこでは ポケモンの たましいが\n"
	.string "よみがえるって うわさ だけど\l"
	.string "そんなこと ほんとうに あるのかしら?$"

Route119_House_Text_Wingull:
	.string "{JPN}キャモメ: ぴひょ!$"

