ThreeIsland_House1_Frlg_MapScripts::
	.byte 0

ThreeIsland_House1_EventScript_Lostelle::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_House1_Text_YoureAlwaysSoCool
	release
	end

ThreeIsland_House1_EventScript_DisplayCase::
	msgbox ThreeIsland_House1_Text_RareRocksGemsDisplayed, MSGBOX_SIGN
	end

ThreeIsland_House1_Text_YoureAlwaysSoCool::
	.string "{JPN}ロステル: こんにちは {ENG}{PLAYER}{JPN}!\n"
	.string "いつも かっこいいね!\p"
	.string "いつか おべんとう\n"
	.string "{ENG}{PLAYER}{JPN}にも つくって あげるね$"

ThreeIsland_House1_Text_RareRocksGemsDisplayed::
	.string "{JPN}めずらしい いしや ほうせきが かざってある$"

