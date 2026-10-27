DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "{JPN}いまの はやり? それは もちろん\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」!\p"
	.string "そうぞう できないよ\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」の ない せいかつ なんて!$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "{JPN}いまの はやり? それは もちろん\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」!\p"
	.string "でも ちょっと あきてきちゃった\p"
	.string "つぎの はやりを さがさなきゃ$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "{JPN}ポケモンに\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」を\l"
	.string "おしえてるけど うまく いかないの\p"
	.string "ちょっと むずかしすぎる みたい$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "{JPN}いま はやりの\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」を べんきょう ちゅうだ\p"
	.string "ほんとうに ふかい かんけいが あるのか\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」と\l"
	.string "「{ENG}{STR_VAR_2}{JPN}」には?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "{JPN}お!\n"
	.string "やっぱり そうなのか!\p"
	.string "これで おじさんも またいっぽ\n"
	.string "りゅうこうに ちかづいたぞ!$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "{JPN}なに!?\n"
	.string "そうなのか!?\p"
	.string "いやー おじさんが りゅうこうに\n"
	.string "ついて いくのは たいへんだ!$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "{JPN}この\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」って……\l"
	.string "テレビ ばんぐみに なって なかった?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "{JPN}うみの むこうでは……\p"
	.string "もっと 「{ENG}{STR_VAR_1}{JPN}」が\n"
	.string "はやってるのかな?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "{JPN}ぼくは こうしきの\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」\l"
	.string "グッズを あつめてるんだ\p"
	.string "こうしき\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」にんぎょう……\p"
	.string "こうしき 「{ENG}{STR_VAR_1}{JPN}」\n"
	.string "ブランドの ふく……\p"
	.string "それに こうしき ライセンスの\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」\l"
	.string "えほん\p"
	.string "へへっ ぜんぶ ぼくの もの!\n"
	.string "きみには なにも わけて あげないよ!$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "{JPN}みわけよう!\n"
	.string "よい 「{ENG}{STR_VAR_1}{JPN}」と\l"
	.string "わるい 「{ENG}{STR_VAR_1}{JPN}」……\p"
	.string "ふかい かんけい!\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」と\l"
	.string "ポケモン……\p"
	.string "やくに たつ\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」……\p"
	.string "ほんだなには ぎっしりと\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」の ほんが!$"

DewfordTown_Hall_Text_TrendsScream:
	.string "{JPN}「{ENG}{STR_VAR_1}{JPN}の\n"
	.string "さけび」 という タイトルだ$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "{JPN}「{ENG}{STR_VAR_1}{JPN}の\n"
	.string "ほほえみ」 という タイトルだ$"

DewfordTown_Hall_Text_LastTrend:
	.string "{JPN}「さいごの\n"
	.string "{ENG}{STR_VAR_1}{JPN}」 という タイトルだ$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "{JPN}「たんじょう!\n"
	.string "{ENG}{STR_VAR_1}{JPN}」 という タイトルだ$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "{JPN}「{ENG}{STR_VAR_1}{JPN}」 みたよ!\n"
	.string "すごいでしょ?\p"
	.string "いま いちばん イケてる ものだよ!\p"
	.string "さいこう だった!\n"
	.string "あれこそ ほんもの だよ!$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "{JPN}いやいや ちがう ちがう\p"
	.string "きみが みたという\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」は\l"
	.string "ほんものじゃ ない\p"
	.string "ほんものは もっと……\n"
	.string "なんて いうのかな\l"
	.string "するどくて それでいて まろやか!\p"
	.string "まあ いいや とにかく すごいんだ!$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "{JPN}ねえ きいて! テーマソングを つくったんだ\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」の!\p"
	.string "「{ENG}{STR_VAR_1}{JPN}」は\n"
	.string "いま すごい にんき だからね\p"
	.string "じゃあ きいてて!\n"
	.string "…… ……\p"
	.string "ああ!\n"
	.string "{ENG}{STR_VAR_1}{JPN}!\p"
	.string "すばらしき\n"
	.string "{ENG}{STR_VAR_1}{JPN}!$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "{JPN}…… ……\p"
	.string "きみ あえて いわせて もらうが\n"
	.string "まずは うたの れんしゅうを\l"
	.string "したまえ はなしは それから\l"
	.string "「{ENG}{STR_VAR_1}{JPN}」 だよ$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "{JPN}ともかく さっきの はなしの つづき\n"
	.string "だけど みんなで あつまって\l"
	.string "「{ENG}{STR_VAR_1}{JPN}」パーティーを\l"
	.string "しまで ひらこうよ$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "{JPN}おお すばらしい アイデア だ!\p"
	.string "これで はっきり するね\n"
	.string "だれが いちばん\l"
	.string "「{ENG}{STR_VAR_1}{JPN}」が うまいか\l"
	.string "じつに すばらしい!\p"
	.string "きょうから ぼくらの せいかつは\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」が ちゅうしんだ!$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "{JPN}でも おもったんだけど……\p"
	.string "きみも そう おもわないか?\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」は\l"
	.string "ただの はやりから\l"
	.string "まいにちの いちぶに なったって$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "{JPN}なんだって?\n"
	.string "そこまで って なにが?\p"
	.string "でも たしかに\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」は\l"
	.string "ねても さめても\l"
	.string "あたまから はなれない ものだ\p"
	.string "まちがいない きみこそ\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」\l"
	.string "はかせ だよ きみ!$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "{JPN}きみと ぼくが コンビを くめば\n"
	.string "むてき だね! なにが って\l"
	.string "「{ENG}{STR_VAR_1}{JPN}」の ことなら!$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "{JPN}そのとおり だよ きみ!\p"
	.string "ぼくらは\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」コンビ だ!\p"
	.string "いい ひびき だろう?\n"
	.string "ハハハハ!$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "{JPN}さいきん ぼくの なかでは\n"
	.string "「ヘドロばくだん」が だいブーム なのさ!\p"
	.string "えー きみ\n"
	.string "「ヘドロばくだん」 しらないの?\p"
	.string "それは かわいそうだな\n"
	.string "よし! ぼくが あげるよ!$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "{JPN}ぼくは ヘドロばくだんが だいすき\p"
	.string "でも わざ\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」を おぼえた\l"
	.string "ポケモンも はやってるんだよね$"

