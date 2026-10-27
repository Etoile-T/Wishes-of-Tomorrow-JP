CeladonCity_Condominiums_1F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_AFTER_HOF, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	famechecker FAMECHECKER_DAISY, 4
	setflag FLAG_TALKED_TO_TEA_LADY_AFTER_HOF
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_Meowth::
	.string "{JPN}ニャース: ニャーン!$"

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
	.string "{JPN}のみもので おかねを つかいすぎちゃ\n"
	.string "いけないよ。\p"
	.string "かわりに これを ためして ごらん。$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
	.string "{JPN}のどの かわきには あつい\n"
	.string "おちゃが いちばん。\p"
	.string "ほんとうに さいこうなのよ。$"

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
	.string "{JPN}かわいい ポケモンたちが そばに\n"
	.string "いてくれるの。 ニャースは おかねまで!$"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
	.string "{JPN}あら こんにちは。\n"
	.string "わたしの おちゃは おいしかった?\p"
	.string "ところで あなた ひょっとして\n"
	.string "マサラタウンから きたの?\p"
	.string "マサラタウンの ナナミちゃんって こも\n"
	.string "まいにち おちゃを たのしんでるのよ。\p"
	.string "タマムシデパートに おちゃを\n"
	.string "かいに きているわ。$"

CeladonCity_Condominiums_1F_Text_Clefairy::
	.string "{JPN}ピッピ: ピッ ピッピッピ!$"

CeladonCity_Condominiums_1F_Text_Nidoran::
	.string "{JPN}ニドラン♀: キャ キャオー!$"

CeladonCity_Condominiums_1F_Text_ManagersSuite::
	.string "{JPN}タマムシマンション\n"
	.string "かんりにんしつ$"

