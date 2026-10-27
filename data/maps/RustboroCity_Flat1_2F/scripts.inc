RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "{JPN}ああ まいにち たいへん……\p"
	.string "なにが たいへんかって?\n"
	.string "きくまでも ないでしょ?\p"
	.string "まいにちの ごはんを なにに するか\n"
	.string "かんがえる ことよ\p"
	.string "まいにち こんだてを かんがえるのは\n"
	.string "ほんとうに たいへんなのよ$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "{JPN}やあ こんにちは!\n"
	.string "ペッパーけへ ようこそ\p"
	.string "ちょっと ききたいんだけど\n"
	.string "こもりを したことは ある?\p"
	.string "じつは ちちおやに なったばかりで\n"
	.string "こそだては はじめて なんだ\p"
	.string "それで なやみが あってね むすめの\n"
	.string "ワルダが あまり わらわないんだ\p"
	.string "なにか おもしろいことを いえば\n"
	.string "わらって くれると おもうんだ\p"
	.string "なにか おもしろい ことばを\n"
	.string "しらないかな?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "{JPN}いまは 「{ENG}{STR_VAR_1}{JPN}」って\n"
	.string "ことばで あやしてるんだけど\p"
	.string "もっと いい ことばを\n"
	.string "しらないかな?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "{JPN}そうか そうか それは うれしい\n"
	.string "じゃあ さっそく おしえて くれよ$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "{JPN}おや そうかい?\p"
	.string "いい ことばを おもいついたら\n"
	.string "いつでも おしえてね$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "{JPN}なるほどー\n"
	.string "じゃあ ためして みようかな$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}\p"
	.string "わらってる わらってる!\n"
	.string "ぼくまで うれしく なっちゃうよ!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "{JPN}なるほどー\n"
	.string "じゃあ ためして みようかな$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}\p"
	.string "うーん…… ぜんぜん わらわないなあ\n"
	.string "ワルダは まじめな こ なのかな……$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "{JPN}いい ことば しらないかー\n"
	.string "じゃあ じぶんで かんがえるかー\p"
	.string "うーん……\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」とか どうかな\l"
	.string "よし! ためしてみよう$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}\p"
	.string "うーん…… ぜんぜん わらわないなあ\n"
	.string "ワルダは まじめな こ なのかな……$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "{JPN}いい ことば しらないかー\n"
	.string "じゃあ まえの ことばで\l"
	.string "がんばって あやすかー\p"
	.string "とにかく いい ことばを みつけたら\n"
	.string "えんりょ なく おしえてね$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "{JPN}ありがとう!\p"
	.string "きみの おかげで かわいい ワルダが\n"
	.string "わらって くれたよ!\p"
	.string "じつは こう みえても わたし\n"
	.string "デボン コーポレーションの\l"
	.string "トップクラスの けんきゅういん なんだ\p"
	.string "そこで きみに なにか\n"
	.string "おれいを したいんだけど……\p"
	.string "そうだ パソコンの ポケモンあずかり\n"
	.string "システムの ボックスに あたらしい\l"
	.string "かべがみの もようを ふやして あげよう\p"
	.string "かべがみの メニューで\n"
	.string "「ともだち」を えらんでね\p"
	.string "そうすれば あたらしい\n"
	.string "かべがみが つかえるよ$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "{JPN}ポケモンの ぬいぐるみ だ!$"

