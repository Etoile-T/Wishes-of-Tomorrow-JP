PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "{JPN}この まちの あたらしい\n"
	.string "ジムリーダーに なった センリさん\p"
	.string "とおくに すんでいた ごかぞくを\n"
	.string "こっちに よびよせた らしいのよね$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "{JPN}まえに いちど しょうぶ してみたけど\n"
	.string "いやー センリさんは つよすぎたよ\p"
	.string "なんというか こう……\p"
	.string "「ポケモン ひとすじに いきる!」\n"
	.string "っていうのを ヒシヒシと かんじたよ!$"

