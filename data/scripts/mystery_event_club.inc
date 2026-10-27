.equ GAVE_PROFILE,  VAR_TEMP_1

MysteryEventClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq GAVE_PROFILE, TRUE, EventScript_AlreadyGaveProfile
	goto_if_set FLAG_SYS_SET_TRAINER_CARD_PROFILE, EventScript_GivenProfileBefore
	msgbox Text_IdLoveToHearYourProfile
	goto EventScript_AskForProfile
	end

EventScript_AlreadyGaveProfile:
	msgbox Text_TellMoreNextTime
	release
	end

EventScript_AskForProfile:
	message Text_TellMeWhatsYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveProfile
	case 1, EventScript_DeclineGiveProfile
	case 2, EventScript_ProfileInfo
	case MULTI_B_PRESSED, EventScript_DeclineGiveProfile
	end

EventScript_ProfileInfo:
	msgbox Text_ExplainProfile
	goto EventScript_AskForProfile
	end

EventScript_AcceptGiveProfile:
	msgbox Text_WhatsYourProfile
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_CancelGiveProfile:
	msgbox Text_DecidedNotTo
	release
	end

EventScript_GaveProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_ProfileSaysSomethingAboutYou
	release
	end

EventScript_DeclineGiveProfile:
	msgbox Text_DontBeLikeThat
	release
	end

EventScript_GivenProfileBefore:
	msgbox Text_HiWeMeetAgain
	goto EventScript_AskForNewProfile
	end

EventScript_AskForNewProfile:
	message Text_ChangeYourProfile
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveNewProfile
	case 1, EventScript_DeclineGiveNewProfile
	case 2, EventScript_ProfileInfo2
	@case MULTI_B_PRESSED, EventScript_DeclineGiveNewProfile
	end

EventScript_ProfileInfo2:
	msgbox Text_ExplainProfile
	goto EventScript_AskForNewProfile
	end

EventScript_AcceptGiveNewProfile:
	msgbox Text_WhatAreYouLikeNow
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_DeclineGiveNewProfile:
	msgbox Text_LikeProfileWayItIs
	release
	end

EventScript_GaveSpecialProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox Text_HeardThatBefore
	release
	end

EventScript_GiveProfile:
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_0x8004, 0, EventScript_GaveSpecialProfile
	goto_if_eq VAR_RESULT, FALSE, EventScript_CancelGiveProfile
	goto_if_eq VAR_RESULT, TRUE, EventScript_GaveProfile
	end

Text_IdLoveToHearYourProfile:
	.string "{JPN}やあ はじめまして!\p"
	.string "…つれないなあ。\n"
	.string "あいさつくらい かえしてよ。\p"
	.string "さあ さあ きみの ことを\n"
	.string "おしえて。\p"
	.string "きみの プロフィールが ききたいな!$"

Text_TellMeWhatsYourProfile:
	.string "{JPN}きみの いいところを おしえて。\n"
	.string "きみの プロフィールは?$"

Text_ExplainProfile:
	.string "{JPN}プロフィールは 4つの ことばで\n"
	.string "つくるんだ。\p"
	.string "プロフィールに つかえる ことばは\n"
	.string "たくさん あるよ。\p"
	.string "ことばは いくつかの べんりな\n"
	.string "グループに わけられているんだ。\p"
	.string "まず グループを えらんで それから\n"
	.string "ことばを えらぶんだ。\p"
	.string "…やってみると かんたんだよ。\n"
	.string "ためしに やってみない?$"

Text_WhatsYourProfile:
	.string "{JPN}きみの プロフィールは?$"

Text_DontBeLikeThat:
	.string "{JPN}えー… そんなこと いわないでよ。\n"
	.string "プロフィール おしえてくれても いいでしょ。$"

Text_DecidedNotTo:
	.string "{JPN}あれ やっぱり やめちゃうの?\n"
	.string "きまぐれだなあ。$"

Text_HiWeMeetAgain:
	.string "{JPN}やあ!\n"
	.string "また あったね!$"

Text_ChangeYourProfile:
	.string "{JPN}プロフィールを\n"
	.string "かえてみる?$"

Text_WhatAreYouLikeNow:
	.string "{JPN}いまの きみは どんな かんじ?\n"
	.string "すごく しりたいな。$"

Text_LikeProfileWayItIs:
	.string "{JPN}そっか いまの プロフィールが\n"
	.string "きにいってるんだね。\p"
	.string "わたしも そう おもうよ。$"

Text_ProfileSaysSomethingAboutYou:
	.string "{JPN}ふむふむ…\p"
	.string "その プロフィール きみらしさが\n"
	.string "よく でてるね。\p"
	.string "きみの ことが よく わかったから\n"
	.string "いままで いじょうに なかよしだね!$"

Text_HeardThatBefore:
	.string "{JPN}あれ それ まえにも きいたこと あるな…\p"
	.string "とおくに すんでる いとこが\n"
	.string "いつも そう いってた きがする。$"

Text_TellMoreNextTime:
	.string "{JPN}こんどは きみの ことを\n"
	.string "もっと おしえてね!$"
