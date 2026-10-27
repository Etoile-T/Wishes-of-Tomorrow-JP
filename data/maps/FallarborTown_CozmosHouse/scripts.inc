FallarborTown_CozmosHouse_MapScripts::
	.byte 0

FallarborTown_CozmosHouse_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
	checkitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_0x8004, ITEM_METEORITE
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_RECEIVED_TM_RETURN
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
	return

FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
	setflag FLAG_TEMP_2
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmosWife::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
	release
	end

FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
	.string "{JPN}ソライシはかせ: ああ……\n"
	.string "マグマだんに だまされて\l"
	.string "いんせきが みつかる ばしょを\l"
	.string "おしえるんじゃ なかった……\p"
	.string "りゅうせいのたき の あの いんせき……\n"
	.string "もう ぼくの ものには ならないよな……$"

FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
	.string "{JPN}あっ!\n"
	.string "はっ?\p"
	.string "その どうぐ……\p"
	.string "もしかして?\p"
	.string "マグマだんが りゅうせいのたき から\n"
	.string "もちさった いんせき かい?\p"
	.string "おねがい! それを ゆずって くれないか?\p"
	.string "ただで とは いわないよ。\n"
	.string "この わざマシンと こうかん でどう?$"

FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
	.string "{JPN}ソライシはかせ: この わざマシンは\n"
	.string "ぼくの かんしゃの きもち です。\l"
	.string "ぜひ つかってください!$"

FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
	.string "{JPN}ソライシはかせ: ああ しんじられない!\n"
	.string "ほんとに ほんとに すばらしいよ!\p"
	.string "これで けんきゅうが ぐっと すすむ!$"

FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
	.string "{JPN}ソライシはかせ: そんな……\n"
	.string "ものすごく がっかりだよ……$"

FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
	.string "{JPN}ソライシはかせ: おねがい! その\n"
	.string "いんせきを ゆずって くれないか?\p"
	.string "ただで とは いわないよ。\n"
	.string "この わざマシンと こうかん でどう?$"

FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
	.string "{JPN}ソライシはかせは マグマだんの ひとたちと\n"
	.string "114ばんどうろの\l"
	.string "りゅうせいのたき へ でかけたの。$"

FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
	.string "{JPN}かわいそうな ソライシはかせ……\n"
	.string "あんなに おちこんで きのどく だわ。$"

FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
	.string "{JPN}ソライシはかせ ったら……\n"
	.string "あんなに よろこんで かわいい!$"

