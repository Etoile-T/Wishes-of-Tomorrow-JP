CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "{JPN}ほう きみが {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} かい?\n"
	.string "きみの かつやくは きいているよ。\p"
	.string "わたしの なまえは ミクリ。\p"
	.string "かつては ルネの ジムリーダー\n"
	.string "だったが ある じじょうでね。\p"
	.string "いまは ジムの うんえいを\n"
	.string "ししょうの アダンさんに まかせている。\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "ここで あばれている ポケモン\n"
	.string "グラードンと カイオーガは\l"
	.string "ちょうこだい ポケモンと よばれる。\p"
	.string "だが ちょうこだい ポケモンは\n"
	.string "2ひき だけでは ない。\p"
	.string "どこかに もう 1ぴき いるのだ。\p"
	.string "どこかに レックウザという\n"
	.string "ちょうこだい ポケモンが いる。\p"
	.string "はるか むかし あらそう 2ひきを\n"
	.string "しずめたのは その レックウザだと\l"
	.string "いわれているんだ。\p"
	.string "だが わたしにも レックウザの\n"
	.string "いばしょは けんとうが つかない……$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "{JPN}ミクリ: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} もしかして\n"
	.string "レックウザの いばしょを しってるかい?\p"
	.string "しっているなら おしえてくれ。$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "{JPN}ミクリ: めざめのほこら だって?\p"
	.string "それは まさに ここじゃないか!\n"
	.string "もっと しっかり たのむよ!\p"
	.string "たのむ いま レックウザが どこに\n"
	.string "いるのか よく かんがえてみてくれ。$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "{JPN}ミクリ: おくりびやま だって?\p"
	.string "だが さっき あそこの おばあさんに\n"
	.string "あったときは なにも いってなかった。\p"
	.string "あの おばあさんが わたしに\n"
	.string "かくしごとを するとは おもえない……\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} もう すこし\n"
	.string "よく かんがえてみて くれないか?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "{JPN}ミクリ: えっ? おぼえてないのかい?\n"
	.string "うーん…… それは こまったな……\p"
	.string "なんとか おもいだせないかい?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "{JPN}ミクリ: そらのはしら だって?\p"
	.string "それだ!\n"
	.string "そらのはしらに ちがいない!\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} いっこくを あらそう!\n"
	.string "すぐに そらのはしらへ むかおう!$"

