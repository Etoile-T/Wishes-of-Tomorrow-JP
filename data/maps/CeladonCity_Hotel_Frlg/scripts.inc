CeladonCity_Hotel_Frlg_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_ThisHotelIsForPeople, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_WhyDidSheBringBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_SisBroughtMeOnVacation, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_ThisHotelIsForPeople::
	.string "{JPN}ポケモン?\n"
	.string "いいえ ここは ひとの ための ホテルです。\p"
	.string "あいにく まんしつで ございます。$"

CeladonCity_Hotel_Text_OnVacationWithBrotherAndBoyfriend::
	.string "{JPN}おとうとと かれしと いっしょに\n"
	.string "りょこうに きてるの。\p"
	.string "タマムシって ほんとに きれいな まちね!$"

CeladonCity_Hotel_Text_WhyDidSheBringBrother::
	.string "{JPN}なんで?\n"
	.string "なんで おとうとを つれてきたんだ?$"

CeladonCity_Hotel_Text_SisBroughtMeOnVacation::
	.string "{JPN}やったー! りょこうだ!\n"
	.string "ねえちゃんが つれてきてくれた! さいこう!$"

