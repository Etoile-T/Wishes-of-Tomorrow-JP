MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "{JPN}ダイゴ: おや {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}。\n"
	.string "よく ぼくの いばしょが わかったね。\p"
	.string "もしかして ぼくのこと ただの\n"
	.string "いしマニア だと おもってる?\p"
	.string "いや そんな はずは ないか。\p"
	.string "ぼくたちは ルネの うちゅうセンターで\n"
	.string "ともに たたかった なかだ。\p"
	.string "ぼくの じつりょくは よく\n"
	.string "わかっている はずだよね。\p"
	.string "よし {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} ほんきで いどむなら\n"
	.string "かくごして おくんだね!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "{JPN}きみは……\n"
	.string "これほどまでに つよくなって いたのか……$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "{JPN}ダイゴ: そういえば ムロの いしのどうくつで\n"
	.string "はじめて であった ときから\l"
	.string "ぼくは こんな よかんが していた。\p"
	.string "きみは いつか きっと\n"
	.string "チャンピオンに なるって。\p"
	.string "ぼくの よそうは たいてい あたるんだ。\p"
	.string "さて きみは これから どこへ いくのかな?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "ふふふ それは ぼくにも わからないや。$"

