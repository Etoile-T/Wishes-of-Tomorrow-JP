ViridianCity_House_Frlg_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
	end

ViridianCity_House_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House_Text_Speary
	waitmoncry
	release
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
	end

ViridianCity_House_Text_NicknamingIsFun::
	.string "{JPN}ニックネームを かんがえるのは\n"
	.string "たのしいけど かんたん じゃないわ。\p"
	.string "かっこいい なまえも いいけど\n"
	.string "かんたんな ほうが おぼえやすいの。$"

ViridianCity_House_Text_MyDaddyLovesMonsToo::
	.string "{JPN}パパも ポケモンが だいすきなの。$"

ViridianCity_House_Text_Speary::
	.string "{JPN}スピーちゃん: チュンチュン!$"

ViridianCity_House_Text_SpearowNameSpeary::
	.string "{JPN}オニスズメ\n"
	.string "なまえ: スピーちゃん$"

