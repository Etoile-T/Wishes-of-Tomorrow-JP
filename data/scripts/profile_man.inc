ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "{JPN}やあ トレーナーさん!\n"
	.string "すてきな えがおを してるね。\p"
	.string "わたしの しゅみは ポケモントレーナーの\n"
	.string "プロフィールを あつめる ことなんだ。$"

ProfileMan_Text_MayISeeYourProfile:
	.string "{JPN}それで どうかな?\n"
	.string "きみの プロフィールを みせてくれる?$"

ProfileMan_Text_EasyChatExplanation:
	.string "{JPN}プロフィールは 4つの ことばを\n"
	.string "くみあわせて つくるんだ。\p"
	.string "では 4つの ことばを つかった\n"
	.string "プロフィールの れいを みせよう。\p"
	.string "この 4つの ことばを ほかの ことばと\n"
	.string "すきなように いれかえて\l"
	.string "じぶんの プロフィールを つくってね。\p"
	.string "つかえる ことばは\n"
	.string "たくさん あるよ。\p"
	.string "ことばは ポケモン せいかつ しゅみ などの\n"
	.string "グループに わかれているから\l"
	.string "さがしやすいよ。\p"
	.string "まず ことばの グループを えらんで\n"
	.string "ことばの リストを だしてね。\p"
	.string "そして つかいたい ことばを えらぶ。\p"
	.string "のこりの ことばも おなじように えらべば\n"
	.string "きみだけの プロフィールの できあがり!$"

ProfileMan_Text_LetsSeeItThen:
	.string "{JPN}やった! ありがとう!\n"
	.string "では みせてもらおうかな。$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "{JPN}ええっ だめなの?\p"
	.string "きみみたいな ひとなら きっと\n"
	.string "すてきな プロフィールだろうに…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "{JPN}おや? いまは そんな きぶんじゃない?\p"
	.string "まあ いつでも かまわないよ!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "{JPN}やあ トレーナーさん!\n"
	.string "すてきな えがおだね。$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "{JPN}あたらしい プロフィールを みせてくれる?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "{JPN}やった! ありがとう!\p"
	.string "まえに みせてもらった プロフィールより\n"
	.string "もっと いいと いいな。$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "{JPN}そうか いまの プロフィールが すきなんだね。\p"
	.string "むりもないよ いまの ままでも\n"
	.string "すてきな プロフィールだからね。$"

ProfileMan_Text_FantasticProfile:
	.string "{JPN}す すばらしい!\p"
	.string "きみの プロフィール すてきだよ!\n"
	.string "きみらしさが よく でてる。\p"
	.string "この プロフィールを きいた ひとは\n"
	.string "みんな きみに むちゅうに なるよ!\p"
	.string "ありがとう!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "{JPN}おや?\n"
	.string "ひみつの あいことばを しってるんだね!\p"
	.string "つまり きみも これで\n"
	.string "ふしぎな できごとクラブの なかまだ!$"
