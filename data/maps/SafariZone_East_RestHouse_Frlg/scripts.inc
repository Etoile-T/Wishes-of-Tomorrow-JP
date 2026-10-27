SafariZone_East_RestHouse_Frlg_MapScripts::
	.byte 0

SafariZone_East_RestHouse_EventScript_Rocker::
	msgbox SafariZone_East_Text_CaughtChanseyAllWorthwhile, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_HowManyDidYouCatch, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_BaldingMan::
	msgbox SafariZone_East_Text_TiredFromAllTheFun, MSGBOX_NPC
	end

SafariZone_East_Text_HowManyDidYouCatch::
	.string "{JPN}なんびき つかまえた?\n"
	.string "ぼくは もう へとへとだよ!$"

SafariZone_East_Text_CaughtChanseyAllWorthwhile::
	.string "{JPN}ラッキーを つかまえたぞ!\p"
	.string "これで くろうが むくわれたよ。$"

SafariZone_East_Text_TiredFromAllTheFun::
	.string "{JPN}ふう!\n"
	.string "たのしすぎて つかれちゃった!$"

