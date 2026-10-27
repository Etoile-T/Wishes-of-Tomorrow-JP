MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "{JPN}やあ わたしは トレーダー。\n"
	.string "わたしと もようがえグッズを こうかんしない?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "{JPN}そう…\n"
	.string "なんだか ブルーな きぶんに なったよ…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "{JPN}でも きみとは もう\n"
	.string "グッズを こうかんしたよね。$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "{JPN}わたしの グッズで ほしいものが\n"
	.string "あったら えんりょなく いってね。$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "{JPN}なにも いらないの?\n"
	.string "さみしいなあ…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "{JPN}その グッズは もともと\n"
	.string "{ENG}{STR_VAR_1}{JPN}の ものだったんだ。\p"
	.string "ほしい?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "{JPN}あれ… ちょっと まって。 きみ\n"
	.string "グッズを ひとつも もってないよ!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "{JPN}じゃあ わたしに くれる\n"
	.string "グッズを えらんでね。$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "{JPN}こうかん してくれないの?\n"
	.string "さみしいなあ…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "{JPN}{ENG}{STR_VAR_2}{JPN}は もう いっぱいで\n"
	.string "これいじょう おいておけないよ。$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "{JPN}じゃあ わたしの {ENG}{STR_VAR_3}{JPN}と\n"
	.string "きみの {ENG}{STR_VAR_2}{JPN}を こうかんだね?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "{JPN}その グッズは いま つかってるよ。\n"
	.string "こうかん できないね。$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "{JPN}じゃあ こうかんだ!\n"
	.string "わたしの グッズは きみの パソコンに おくるね。$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "{JPN}おっと! ごめん! それは とっても\n"
	.string "めずらしい グッズなんだ。\l"
	.string "それは こうかん できないよ!\p"
	.string "ほかの ものは どうかな?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "{JPN}わたしは かたりべ。\n"
	.string "でんせつの トレーナーの はなしを\l"
	.string "かたって きかせよう。\p"
	.string "わたしの はなしを きくかね?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "{JPN}そうか…\n"
	.string "なんだか ブルーな きぶんに なったよ…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "{JPN}わたしが しっている でんせつは これだ。\n"
	.string "どの はなしを きかせようか?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "{JPN}だが でんせつの トレーナーを しらない。\n"
	.string "ゆえに かたる はなしも ないのだ。\p"
	.string "でんせつに ふさわしい トレーナーは\n"
	.string "どこに いるのだろう?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "{JPN}なんだって!?\n"
	.string "きみ… きみは…\p"
	.string "{ENG}{STR_VAR_2}{JPN}\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも!?\p"
	.string "それは じつに すばらしい!\n"
	.string "あたらしい でんせつの たんじょうだ!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "{JPN}ほかにも もっと すごい でんせつを\n"
	.string "もつ トレーナーが みつけられるのを\l"
	.string "まっているのでは ないかと おもうよ。$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "{JPN}きみは トレーナーかね?\p"
	.string "では おしえてくれ。 すこしでも\n"
	.string "でんせつに なりそうな はなしは あるかね?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "{JPN}ところで… ほかの でんせつの\n"
	.string "はなしも きいて みないかね?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "{JPN}うーむ…\n"
	.string "ものたりない…\p"
	.string "でんせつと よぶに ふさわしい\n"
	.string "はなしを もってきて ほしいものだ。$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "{JPN}でんせつの トレーナーの だいかつげきに\n"
	.string "もっと たくさんの ひとが きょうみを\l"
	.string "もって くれると いいのだが。$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "{JPN}セーブずきな トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "{JPN}ゲームを セーブした$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ゲームを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも セーブした!\p"
	.string "これほど しんちょうな トレーナーは\n"
	.string "{ENG}{STR_VAR_3}{JPN}の ほかに いないだろう!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "{JPN}はやりを つくる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "{JPN}はやりを つくった$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは あたらしい はやりを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも つくった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は ホウエン ちほう ぜんたいの\n"
	.string "はやりを つくっているのだ!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "{JPN}きのみを うえる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "{JPN}きのみを うえた$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは きのみを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも うえた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は でんせつの\n"
	.string "きのみ だいすき トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "{JPN}じてんしゃ だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "{JPN}じてんしゃを とりかえた$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは じてんしゃを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも とりかえた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は じてんしゃを こころから\n"
	.string "ねっしんに あいして いるのだろう!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "{JPN}インタビューされた トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "{JPN}インタビューを うけた$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは インタビューを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも うけた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は きっと おおくの\n"
	.string "ちゅうもくを あつめる トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "{JPN}バトルずきな トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "{JPN}バトルした$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは {ENG}{STR_VAR_1}{JPN}かい\nバトルした!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は バトルの チャンスを\n"
	.string "ぜったいに ことわらない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "{JPN}ポケモンを つかまえる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "{JPN}ポケモンを つかまえた$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ポケモンを\n"
	.string "{ENG}{STR_VAR_1}{JPN}ひきも つかまえた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は やせいの ポケモンを\n"
	.string "つかまえる でんせつの めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "{JPN}つりびと トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "{JPN}つりざおで ポケモンを つった$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは つりで ポケモンを\n"
	.string "{ENG}{STR_VAR_1}{JPN}ひきも つかまえた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は でんせつの\n"
	.string "つりの めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "{JPN}タマゴを あたためる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "{JPN}タマゴを かえした$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは {ENG}{STR_VAR_1}{JPN}ひきの\n"
	.string "ポケモンを タマゴから かえした!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は タマゴを あたためる\n"
	.string "でんせつの めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "{JPN}しんかさせる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "{JPN}ポケモンを しんかさせた$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは {ENG}{STR_VAR_1}{JPN}ひきの\n"
	.string "ポケモンを しんかさせた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は ポケモンを しんかさせる\n"
	.string "きゅうきょくの めいじんだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "{JPN}ポケモンセンター だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "{JPN}ポケモンセンターを つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ポケモンセンターで\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも かいふくした!\p"
	.string "これほど ポケモンセンターを あいする\n"
	.string "ひとは {ENG}{STR_VAR_3}{JPN}の ほかに いない!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "{JPN}いえが だいすきな トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "{JPN}いえで ポケモンを やすませた$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは いえで ポケモンを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも かいふくした!\p"
	.string "これほど いえが すきな ひとは\n"
	.string "{ENG}{STR_VAR_3}{JPN}の ほかに いないだろう!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "{JPN}サファリ だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "{JPN}サファリゾーンに はいった$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは サファリゾーンに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも はいった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は サファリゾーンで\n"
	.string "やせいの ちが さわぐ トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "{JPN}いあいぎり むちゅう トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "{JPN}いあいぎりを つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは いあいぎりを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも つかった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は きっと いあいぎりが\n"
	.string "だいすきな トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "{JPN}いわを くだく トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "{JPN}いわを くだいた$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは いわくだきを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも つかった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は いわを みたら\n"
	.string "くだかずには いられない トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "{JPN}ひっこし だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "{JPN}ひみつきちを ひっこした$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ひみつきちを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも ひっこした!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は しょっちゅう\n"
	.string "ひっこしするのが すきな トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "{JPN}はねる だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "{JPN}はねるを つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは はねるを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも つかった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は きっと ピチピチ\n"
	.string "はねるのが だいすきな トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "{JPN}ねばりづよい トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "{JPN}わるあがきに たよった$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは わるあがきに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも たよった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は ぎゃっきょうに まけない\n"
	.string "ねばりづよい トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "{JPN}スロットの チャンピオン$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "{JPN}スロットで おおあたりした$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは スロットで\n"
	.string "{ENG}{STR_VAR_1}{JPN}かい おおあたりした。\p"
	.string "{ENG}{STR_VAR_3}{JPN}は スロットで\n"
	.string "ツキに めぐまれた トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "{JPN}ルーレットの チャンピオン$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "{JPN}ルーレットで れんしょうした$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ルーレットで\n"
	.string "{ENG}{STR_VAR_1}{JPN}かい れんぞくで かった。\p"
	.string "{ENG}{STR_VAR_3}{JPN}は ルーレットの たまが\n"
	.string "はねる とき ツキが あったのだ!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "{JPN}バトルタワーの ちょうせんしゃ$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "{JPN}バトルタワーに ちょうせんした$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは バトルタワーに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも ちょうせんした!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は バトルタワーで\n"
	.string "ちょうてんを めざす トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "{JPN}ブレンド だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "{JPN}{ENG}{POKEBLOCK}{JPN}を つくった$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは {ENG}{POKEBLOCK}{JPN}を\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも つくった!\p"
	.string "きのみブレンダーを これほど うまく\n"
	.string "つかえる ひとは {ENG}{STR_VAR_3}{JPN}だけだ!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "{JPN}コンテスト だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "{JPN}コンテストに でた$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは コンテストに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも でた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は ポケモンを みんなに\n"
	.string "みせるのが だいすきなのだろう!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "{JPN}コンテストの マスター$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "{JPN}コンテストで ゆうしょうした$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは コンテストで\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも ゆうしょうした!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は きっと すばらしい\n"
	.string "コンテストの マスターだ!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "{JPN}かいもの だいすき$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "{JPN}かいものを した$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは おみせで どうぐを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも かった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は かいものを するために\n"
	.string "うまれてきた ひとに ちがいない。$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "{JPN}どうぐを さがす トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "{JPN}ダウジングマシンを つかった$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ダウジングマシンを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも つかった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は かくれた どうぐを\n"
	.string "さがしまわるのが すきなのだろう!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "{JPN}あめに ぬれた トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "{JPN}あめに ふられた$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは あめに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも ずぶぬれに された!\p"
	.string "{ENG}{STR_VAR_3}{JPN}の カリスマは きっと\n"
	.string "あめまで よびよせるのだ!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "{JPN}ポケモンずかん マニア$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "{JPN}ポケモンずかんを みた$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ポケモンずかんを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも みた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は ずかんで ポケモンを\n"
	.string "しらべるのが だいすきなのだろう!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "{JPN}リボン コレクター$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "{JPN}リボンを もらった$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは リボンを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも もらった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は きっと リボンを\n"
	.string "あつめるのが だいすきな トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "{JPN}だんさを とびおりる トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "{JPN}だんさを とびおりた$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは だんさを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも とびおりた!\p"
	.string "とびおりられる だんさが あれば\n"
	.string "{ENG}{STR_VAR_3}{JPN}は ほうっておけないのだ!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "{JPN}でんせつの テレビ しちょうしゃ$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "{JPN}テレビを みた$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは テレビを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも みた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は テレビが だいすきなのだ!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "{JPN}じかんに うるさい トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "{JPN}じかんを たしかめた$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは じかんを\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも たしかめた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は じかんを きにする\n"
	.string "きちょうめんな トレーナーなのだろう。$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "{JPN}ポケモンくじの たつじん$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "{JPN}ポケモンくじに あたった$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ポケモンくじに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも あたった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}には ポケモンを こうかんする\n"
	.string "ともだちが たくさん いるのだろう!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "{JPN}そだてや ごようたし トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "{JPN}そだてやに ポケモンを あずけた$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは そだてやに\n"
	.string "ポケモンを {ENG}{STR_VAR_1}{JPN}かいも あずけた!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は ポケモンを どんどん\n"
	.string "そだてる やりての トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "{JPN}ロープウェイ だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "{JPN}ロープウェイに のった$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは ロープウェイに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも のった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は いつも のぼったり\n"
	.string "おりたりの いそがしい トレーナーだ!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "{JPN}おんせん だいすき トレーナー$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "{JPN}おんせんに つかった$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "{JPN}これは ある トレーナー\n"
	.string "{ENG}{STR_VAR_3}{JPN}の はなし。\p"
	.string "この トレーナーは おんせんに\n"
	.string "{ENG}{STR_VAR_1}{JPN}かいも つかった!\p"
	.string "{ENG}{STR_VAR_3}{JPN}は きっと あかちゃんみたいな\n"
	.string "すべすべの はだの トレーナーだ!$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "{JPN}わたし はなしたがり!\n"
	.string "とびきり すてきな はなしが あるの!\p"
	.string "わたしの はなし きいてくれる?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "{JPN}そう…\n"
	.string "なんだか ブルーな きぶんに なったわ…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "{JPN}それとね わたし おもったんだけど…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "{JPN}それくらい かな…\p"
	.string "また おしゃべり しようね!\n"
	.string "バイバーイ!$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "{JPN}やあ ぼくは うたうおとこ。\n"
	.string "ぼくの うたを きいて みない?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "{JPN}そう…\n"
	.string "なんだか ブルーな きぶんに なったよ…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "{JPN}ああ なんて こころに しみる うた…\n"
	.string "ほかの ひとにも きかせて あげたいな…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "{JPN}どう?\n"
	.string "ぼくの うた どうだった?\p"
	.string "でも ぼく かしが あんまり\n"
	.string "きに いって ないんだ。\p"
	.string "きみ ぼくの ために あたらしい\n"
	.string "かしを かいて くれない?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "{JPN}そう…\n"
	.string "なんだか ブルーな きぶんに なったよ…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "{JPN}どうも ありがとう!\n"
	.string "じゃあ うたって みるね。$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "{JPN}きみの おもってた とおりの\n"
	.string "うたに なった?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "{JPN}よし! じゃあ これで きまり。\n"
	.string "しばらく この うたを うたうよ。$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "{JPN}ヘイ ヨー! オレは ヒップスター。\n"
	.string "いま はやりの イケてるもんを おしえるぜ。$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "{JPN}でも ヘイ はやりの イケてるもんは\n"
	.string "もう おしえたよな。\p"
	.string "ほかの みんなにも\n"
	.string "ひろめたいんだよ。$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "{JPN}でも ヘイ きみは もう はやりの\n"
	.string "イケてるもんに くわしいな。\p"
	.string "おしえる ことは なにも ないぜ!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "{JPN}ヘイ きみは\n"
	.string "「{ENG}{STR_VAR_1}{JPN}」って しってるかい?\p"
	.string "どういう いみかって? そりゃ…\n"
	.string "パパか ママに きいてみな?$"
