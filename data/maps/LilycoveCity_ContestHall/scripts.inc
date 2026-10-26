@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "{JPN}この ポケモンは まえに ここで\n"
	.string "うつくしさコンテストで かったの。\p"
	.string "ところが きょうは なんと\n"
	.string "かしこさコンテストで かたせちゃった!\p"
	.string "じぶんの さいのうが こわいわ…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "{JPN}なんども コンテストに でて\n"
	.string "しくみが わかってきたよ。\p"
	.string "かっこよさコンテストなら\n"
	.string "かっこいい わざの アピールが うける。\p"
	.string "でも かしこい わざや かわいい わざは\n"
	.string "うけが よくないんだ。たとえばね。$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "{JPN}さっき かった わかい おとこのひとは\n"
	.string "いろんな ポロックを たくさん もってたね。\p"
	.string "ああいうのを たくさん もっていれば\n"
	.string "かてるのかねえ?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "{JPN}うわあ なんて ひろいんだ!\p"
	.string "この きんちょうかん… いなかの\n"
	.string "コンテストかいじょうとは ちがうね。$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "{JPN}しかい: かしこい ポケモンと トレーナーの\n"
	.string "みなさん じゅんびは いいですか?!\p"
	.string "さいこうの すがたを みせてください!\n"
	.string "さあ アピールしましょう!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "{JPN}しんさいん: コンテスト たのしんでますか?\p"
	.string "おともだちを 3にん つれてくれば\n"
	.string "4にん いっしょに さんか できますよ！$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "{JPN}あわわわ……\n"
	.string "でる コンテスト まちがえた……\p"
	.string "たくましい ポケモンを\n"
	.string "かしこさ コンテストに……\p"
	.string "よ よしっ\n"
	.string "かしこそうな いわくだき たのむぞ！$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "{JPN}わしが ながねん\n"
	.string "ちしきの すべてを かけて\l"
	.string "かしこく そだてた ポケモン！\p"
	.string "わかい やつらの ポケモン なんぞに\n"
	.string "そう やすやすと まけたりは せんぞ！\p"
	.string "ばあさん みとるかー！?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "{JPN}それだ!\p"
	.string "つぎに かしこい わざを だせば\n"
	.string "かんきゃくの もりあがりは さいこうだ!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "{JPN}ああ そんな!\p"
	.string "かわいい ズバットの きゅうけつが\n"
	.string "あんまり かわいくて なんども つかったの!\p"
	.string "なのに この いじわるな ひとたちは\n"
	.string "ちっとも よさを わかってくれないの!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "{JPN}キャー！ おじいさん すてきー！$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "{JPN}おなじ しゅるいの ポケモンでも\n"
	.string "トレーナーごとに アピールの わざが\l"
	.string "ちがうみたいだね。\p"
	.string "ひとによって バトルの しかたが\n"
	.string "ちがうのと おなじだね。$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "{JPN}トレーナーより ポケモンの ほうが\n"
	.string "ずっと あたまが よさそうに みえるなあ。$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "{JPN}なんだかんだ いっても やっぱり\n"
	.string "かしこさコンテストが すきだな。\p"
	.string "あの ちてきな みどりいろ…\n"
	.string "とても… とても… すてきだ。$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "{JPN}しかい: あなたも うつくしさコンテストに\n"
	.string "でるんですか? がんばってくださいね!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "{JPN}しんさいん: ああ どの ポケモンも\n"
	.string "けがれない うつくしさの おてほんだ!\p"
	.string "おもわず さいてんを わすれますよ！$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "{JPN}こんなに うつくしい ポケモン…\n"
	.string "ほかには いないわ。\p"
	.string "みんな この うつくしい ポケモンに\n"
	.string "めが くぎづけに なるはずよ。$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "{JPN}うわーん！\p"
	.string "この コンテストの ために\n"
	.string "いっしょけんめい けづくろい したら\p"
	.string "やりすぎて あたしの ポケモン\n"
	.string "ボサボサに なっちゃった！\p"
	.string "どうしよう……$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "{JPN}この まぶしすぎる オーロラビームに\n"
	.string "しんさいんも めを あけられない！\p"
	.string "……あれ?\n"
	.string "それじゃ いみが ないのか?$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "{JPN}この きれいな ポケモン\n"
	.string "あたしの わかい ころに そっくり！\p"
	.string "って いったら…… とうちゃんが\n"
	.string "のんでた コーヒーを ふきだしたよ\p"
	.string "あたし なんか へんなこと いったかね?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "{JPN}うつくしさコンテストで かつと\n"
	.string "やっぱり うれしいよね。\l"
	.string "いつも いじょうに うれしいんだ。$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "{JPN}うわっはっは！\p"
	.string "べっぴんな ポケモンちゃん が\n"
	.string "いっぱいだ……\l"
	.string "こりゃ はなやかで ええのう！$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "{JPN}ただ うつくしい だけでは\n"
	.string "いつも かてるとは かぎらないわよ!\p"
	.string "あたしの ポケモンみたいに\n"
	.string "おていれして ツヤツヤ じゃなきゃ！$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "{JPN}しかい: あら あらー！\n"
	.string "いまは コンテスト ちゅう ですよー！\p"
	.string "うけつけで エントリー してから\n"
	.string "でて くださーい！ ねっ！$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "{JPN}しんさいん: おお\n"
	.string "みんな かわいい アピールだなあ！\p"
	.string "おおっ なんて かわいい\n"
	.string "みずあそびの アピールなんだろう！$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "{JPN}ああ かわいい ルリリちゃんが\n"
	.string "ほかの ポケモンに きを とられちゃった！$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "{JPN}この ポケモンは バトルで かったことが\n"
	.string "ないけど コンテストなら すごいんだよ!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "{JPN}この ポケモンの はなびらのまいは\n"
	.string "うっとりするほど ゆうがなの。\p"
	.string "だれにも アピールの じゃまは\n"
	.string "させないわ。$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "{JPN}みんなの ポケモンは とても かわいいね。\p"
	.string "でも この ポケモンが\n"
	.string "かわいい アピールを すれば…\p"
	.string "きっと ほかの ポケモンよりも\n"
	.string "ずっと かわいいはずさ。$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "{JPN}うちのこが コンテストに でてるんですよ。$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "{JPN}ほらっ がんばって！\n"
	.string "あなたの ポケモンが いちばんよっ！$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "{JPN}ワシは あの おんなのこが\n"
	.string "いちばん かわいいと おもうな……\p"
	.string "えっ? ポケモンの みためを\n"
	.string "くらべてるんか！?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "{JPN}ああ こんなに かわいい ポケモンを みると\n"
	.string "じぶんの ポケモンが ほしくなるよ!\p"
	.string "つかまえに いってこよう!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "{JPN}うつくしさコンテスト ステージ\n"
	.string "うつくしい ポケモンに うっとり!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "{JPN}かわいさコンテスト ステージ\n"
	.string "かわいい ポケモンに むちゅう!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "{JPN}かしこさコンテスト ステージ\n"
	.string "かしこい ポケモンに かんしん!$"

