ViridianCity_School_Frlg_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes
	closemessage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
	closemessage
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
	releaseall
	end

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadSleep
	case 1, ViridianCity_School_EventScript_ReadPoison
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case 127, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ExitBlackboard::
	releaseall
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
	.string "{JPN}ふう! ノートを ぜんぶ\n"
	.string "おぼえようと してるの。$"

ViridianCity_School_Text_ReadBlackboardCarefully::
	.string "{JPN}はい!\p"
	.string "こくばんに かいてある ことを\n"
	.string "しっかり よんでね!$"

ViridianCity_School_Text_NotebookFirstPage::
	.string "{JPN}ノートを みてみよう。\p"
	.string "1ページめ…\p"
	.string "モンスターボールは ポケモンを\n"
	.string "つかまえる ために つかう。\p"
	.string "てもちに つれて あるける\n"
	.string "ポケモンは 6ぴきまで。\p"
	.string "ポケモンを そだてて たたかう\n"
	.string "ひとを トレーナーと よぶ。$"

ViridianCity_School_Text_NotebookSecondPage::
	.string "{JPN}2ページめ…\p"
	.string "げんきな ポケモンは\n"
	.string "つかまえにくい。 まず よわらせよう。\p"
	.string "どくや やけど などの じょうたい\n"
	.string "いじょうに して よわらせよう。$"

ViridianCity_School_Text_NotebookThirdPage::
	.string "{JPN}3ページめ…\p"
	.string "ポケモントレーナーは ポケモン\n"
	.string "しょうぶの あいてを さがしている。\p"
	.string "トレーナーに とって しょうりの\n"
	.string "あじは まさに あまい ものだ。\p"
	.string "かくちの ポケモンジムでは\n"
	.string "いつも しょうぶが おこなわれている。$"

ViridianCity_School_Text_NotebookFourthPage::
	.string "{JPN}4ページめ…\p"
	.string "すべての ポケモントレーナーの\n"
	.string "さいしゅう もくひょうは かんたん。\p"
	.string "トップの 8にんの\n"
	.string "ジムリーダーを たおすこと。\p"
	.string "そうすれば いどむ けんりが…\p"
	.string "ポケモンリーグの\n"
	.string "してんのうに!$"

ViridianCity_School_Text_TurnThePage::
	.string "{JPN}ページを めくる?$"

ViridianCity_School_Text_HeyDontLookAtMyNotes::
	.string "{JPN}おんなのこ: ちょっと!\n"
	.string "わたしの ノート みないでよ!$"

ViridianCity_School_Text_BlackboardListsStatusProblems::
	.string "{JPN}こくばんに しょうぶちゅうの\n"
	.string "ポケモンの じょうたいいじょうが!$"

ViridianCity_School_Text_ReadWhichTopic::
	.string "{JPN}どの こうもくを よむ?$"

ViridianCity_School_Text_ExplainSleep::
	.string "{JPN}ポケモンは ねむっていると\n"
	.string "こうげき できない。\p"
	.string "しょうぶが おわっても\n"
	.string "ねむった ままだ。\p"
	.string "ねむけざましを つかえば\n"
	.string "めを さます。$"

ViridianCity_School_Text_ExplainBurn::
	.string "{JPN}やけどは こうげきが さがる。\n"
	.string "さらに HPが へりつづける。\p"
	.string "やけどは しょうぶの あとも のこる。\n"
	.string "やけどなおしで なおそう。$"

ViridianCity_School_Text_ExplainPoison::
	.string "{JPN}どくを うけた ポケモンは\n"
	.string "たいりょくが どんどん へる。\p"
	.string "どくは しょうぶの あとも のこる。\n"
	.string "どくけしで なおそう!$"

ViridianCity_School_Text_ExplainFreeze::
	.string "{JPN}こおった ポケモンは\n"
	.string "まったく うごけなくなる。\p"
	.string "しょうぶが おわっても\n"
	.string "こおった ままだ。\p"
	.string "こおりなおしで くるしむ\n"
	.string "ポケモンを とかして あげよう。$"

ViridianCity_School_Text_ExplainParalysis::
	.string "{JPN}まひは すばやさが さがり\n"
	.string "うごけない ことも ある。\p"
	.string "まひは しょうぶの あとも のこる。\n"
	.string "まひなおしで なおそう。$"

