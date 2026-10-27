SaffronCity_House_Frlg_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
	.string "{JPN}…おてがみ ありがとう。\n"
	.string "はやく あえると いいな!\p"
	.string "…ちょっと!\n"
	.string "てがみを みないでよ!$"

SaffronCity_House_Text_Pidgey::
	.string "{JPN}ポッポ: クルックー!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
	.string "{JPN}ものまねむすめって かわいい!\n"
	.string "ピッピにんぎょうを あげるんだ。$"

SaffronCity_House_Text_ExplainPPUp::
	.string "{JPN}ポイントアップを プレゼントで もらった。\p"
	.string "ポケモンの わざの PPを\n"
	.string "ふやす どうぐ なんだ。\p"
	.string "PPの すくない つよい わざに\n"
	.string "つかうと いいだろうね。$"

