RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "{JPN}わたしは じぶんの ポケモンに\n"
	.string "ぴったりの ニックネームを つけるの!\p"
	.string "それが わたしの えーと……\n"
	.string "こせいの ひょうげん! そう それよ!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "{JPN}でも ピカチュウに ペカチュウって\n"
	.string "なまえを つけるのは いみが ないような\p"
	.string "わかりやすい なまえを つけるのは\n"
	.string "いいこと だと おもうけど……$"

RustboroCity_House3_Text_Pekachu:
	.string "{JPN}ペカチュウ: ぺかー!$"

