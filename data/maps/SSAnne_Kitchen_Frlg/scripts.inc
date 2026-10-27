SSAnne_Kitchen_Frlg_MapScripts::
	.byte 0

SSAnne_Kitchen_EventScript_Chef1::
	msgbox SSAnne_Kitchen_Text_BusyOutOfTheWay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef2::
	msgbox SSAnne_Kitchen_Text_SawOddBerryInTrash, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef3::
	msgbox SSAnne_Kitchen_Text_SoBusyImDizzy, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef4::
	lock
	faceplayer
	msgbox SSAnne_Kitchen_Text_IAmLeChefMainCourseIs
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, SSAnne_Kitchen_EventScript_SalmonDuSalad
	call_if_eq VAR_0x8008, 1, SSAnne_Kitchen_EventScript_EelsAuBarbecue
	call_if_eq VAR_0x8008, 2, SSAnne_Kitchen_EventScript_PrimeBeefsteak
	release
	end

SSAnne_Kitchen_EventScript_SalmonDuSalad::
	msgbox SSAnne_Kitchen_Text_SalmonDuSalad
	return

SSAnne_Kitchen_EventScript_EelsAuBarbecue::
	msgbox SSAnne_Kitchen_Text_EelsAuBarbecue
	return

SSAnne_Kitchen_EventScript_PrimeBeefsteak::
	msgbox SSAnne_Kitchen_Text_PrimeBeefsteak
	return

SSAnne_Kitchen_EventScript_Chef5::
	msgbox SSAnne_Kitchen_Text_PeelSpudsEveryDay, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef6::
	msgbox SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton, MSGBOX_NPC
	end

SSAnne_Kitchen_EventScript_Chef7::
	msgbox SSAnne_Kitchen_Text_OnlyGetToPeelOnions, MSGBOX_NPC
	end

SSAnne_Kitchen_Text_BusyOutOfTheWay::
	.string "{JPN}そこの モン・プチ!\n"
	.string "こっちは いそがしいんだ!\l"
	.string "どいた どいた!$"

SSAnne_Kitchen_Text_SawOddBerryInTrash::
	.string "{JPN}ゴミばこに へんな きのみが あったよ。\n"
	.string "あれは なんだったんだろう?$"

SSAnne_Kitchen_Text_SoBusyImDizzy::
	.string "{JPN}いそがしすぎて めが まわりそうだ!\n"
	.string "そこを あけて くれよ!$"

SSAnne_Kitchen_Text_PeelSpudsEveryDay::
	.string "{JPN}ふん ふふん ふーん…\p"
	.string "まいにち じゃがいもの かわむきさ!\n"
	.string "ふん ふーん…$"

SSAnne_Kitchen_Text_HearAboutSnorlaxItsAGlutton::
	.string "{JPN}カビゴンの はなしを しってるかい?\n"
	.string "とんでもない くいしんぼう なんだ。\p"
	.string "カビゴンほど たべて ねる ポケモンは\n"
	.string "ほかに いないよ!$"

SSAnne_Kitchen_Text_OnlyGetToPeelOnions::
	.string "{JPN}グスッ… ズズッ…\p"
	.string "ぼくは たまねぎの かわむき ばっかり…\n"
	.string "グスッ…$"

SSAnne_Kitchen_Text_IAmLeChefMainCourseIs::
	.string "{JPN}ウォッホン!\n"
	.string "いかにも ワタクシが シェフ!\p"
	.string "きょうの メインディッシュは$"

SSAnne_Kitchen_Text_SalmonDuSalad::
	.string "{JPN}サーモン・ド・サラダ!\p"
	.string "また さかなかと おきゃくさまに\n"
	.string "もんくを いわれそう ですが!$"

SSAnne_Kitchen_Text_EelsAuBarbecue::
	.string "{JPN}ウナギの バーベキュー・オ・ソース!\p"
	.string "おきゃくさまが はんらん しそうで こわい。$"

SSAnne_Kitchen_Text_PrimeBeefsteak::
	.string "{JPN}とくせん ビーフステーキ!\p"
	.string "でも フィレ・ド・ビーフは\n"
	.string "たりて いるかな?$"

