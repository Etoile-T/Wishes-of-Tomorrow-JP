SafariZone_EventScript_OutOfBallsMidBattle::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 3
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	setwarp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#else
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	end

SafariZone_EventScript_Exit::
#if IS_FRLG
	setvar VAR_MAP_SCENE_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 1
#else
	setvar VAR_SAFARI_ZONE_STATE, 1
#endif
	special ExitSafariMode
#if IS_FRLG
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 4, 1
#else
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
#endif
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "{JPN}サファリゾーンから いますぐ\n"
	.string "でますか?$"

SafariZone_Text_TimesUp:
	.string "{JPN}ピンポーン! じかんぎれです!\n"
	.string "サファリゲームは おしまいです。$"

SafariZone_Text_OutOfBalls:
	.string "{JPN}サファリボールが なくなりました。\n"
	.string "サファリゲームは おしまいです。$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "{JPN}ポロックを\n"
	.string "ポロックおきばに おきますか?$"

SafariZone_Text_PokeblockStillHere:
	.string "{JPN}まえに おいた {ENG}{STR_VAR_1}{JPN}が\n"
	.string "まだ のこっている。$"

SafariZone_Text_PokeblockWasPlaced:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を\n"
	.string "ポロックおきばに おいた。$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "{JPN}サファリゾーンへ ようこそ!\p"
	.string "ここでは ホウエンでは めったに みられない\n"
	.string "いろんな ポケモンに であえます。\p"
	.string "しかも しぜんの なかで くらす\n"
	.string "ありのままの すがたが みられます。\p"
	.string "さらに ポケモントレーナーの みなさんにも\n"
	.string "もんを ひらいて おります。\p"
	.string "つかまえた ポケモンは\n"
	.string "そのまま つれかえって いいんですよ!\p"
	.string "サファリゾーンを たのしんでください!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "{JPN}サファリゾーンへ ようこそ!\n"
	.string "こちらは はじめてですか?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "{JPN}サファリゾーンを たのしんでください!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "{JPN}サファリゾーンに はいると まず\n"
	.string "ポケモンを つかまえるための\l"
	.string "サファリボールを 30こ おわたしします。\p"
	.string "サファリゲームは サファリボールが\n"
	.string "なくなるか 500ぽ あるくと\l"
	.string "おしまいです。\p"
	.string "サファリゾーンを たのしんでください!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "{JPN}サファリゾーンへ ようこそ!\p"
	.string "500円で つかまえほうだい!\n"
	.string "サファリゲームを あそびますか?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "{JPN}わかりました。\n"
	.string "また あそびに きてくださいね!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "{JPN}おかねが たりません。\n"
	.string "ごめんなさい。$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "{JPN}500円 いただきます。$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "{JPN}こちらが サファリボールです。$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{JPN}{ENG}{PLAYER}{JPN}は サファリボールを\n30こ うけとった!$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "{JPN}ゲームが おわったら\n"
	.string "おしらせします。\p"
	.string "それでは ぞんぶんに おたのしみください!\n"
	.string "ワイルドな たびへ いってらっしゃい!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "{JPN}あっ すみません!\n"
	.string "パソコンの ボックスが いっぱいです。$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "{JPN}あっ すみません!\n"
	.string "ポロックケースを おもちでないようですね。\p"
	.string "ポロックを つかうと サファリゲームが\n"
	.string "ずっと うまく いきますよ。\p"
	.string "ポロックケースを もって きてください。\p"
	.string "ポロックケースは ミナモシティの\n"
	.string "コンテストかいじょうで もらえますよ。$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "{JPN}まだ じかんが のこっていますが\n"
	.string "サファリゾーンを でますか?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "{JPN}ひきつづき ワイルドな ぼうけんを\n"
	.string "おたのしみください!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "{JPN}わかりました。\p"
	.string "のこりの サファリボールは\n"
	.string "おかえし いただきます。\p"
	.string "ごりよう ありがとうございました。\n"
	.string "また おこしくださいね。$"

SafariZone_South_Text_GoodLuck:
	.string "{JPN}がんばってくださいね!\p"
	.string "なにか あれば えんりょなく\n"
	.string "こえを かけてくださいね!$"

SafariZone_South_Text_Boy:
	.string "{JPN}しってる?\p"
	.string "あの しかくい はこに ポロックを いれると\n"
	.string "ポケモンが あつまってくるんだよ。$"

SafariZone_South_Text_Man:
	.string "{JPN}もっと おくまで いきたいけど\n"
	.string "じてんしゃを わすれてきちゃった。\p"
	.string "なんとなく めずらしい ポケモンは\n"
	.string "はずれの ほうに いる きがするんだ。$"

SafariZone_Southwest_Text_Woman:
	.string "{JPN}ポケモンに ポロックを なげても\n"
	.string "むしされる ことが あるの。\p"
	.string "ポケモンにも たべものの\n"
	.string "すききらいが あるのかしら?$"

SafariZone_Northwest_Text_Man:
	.string "{JPN}ハァ… ハァ…\n"
	.string "ここまで…きたけど…\p"
	.string "もう くたくただ… ポケモンを\n"
	.string "つかまえる げんきが ない…$"

SafariZone_North_Text_Fisherman:
	.string "{JPN}ホウエンでは みられない みずポケモンを\n"
	.string "さがすのが しめいなんだ。\p"
	.string "みずうみが どこに あるか しらないかい?$"

SafariZone_North_Text_Man:
	.string "{JPN}ここで めずらしい ポケモンを たくさん\n"
	.string "つかまえて ともだちと こうかんするんだ!$"

SafariZone_South_Text_Youngster:
	.string "{JPN}ポロックおきばに ポロックを おいたんだ。\n"
	.string "でも なくなっちゃった みたい。\p"
	.string "きっと しらないうちに\n"
	.string "ポケモンが たべちゃったんだね。$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "{JPN}サファリゾーンの トレーナーズ ヒント!\p"
	.string "やせいの ポケモンに ポロックを なげると\n"
	.string "にげにくく なります!$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "{JPN}「つかれた あしを やすめよう」\n"
	.string "きゅうけいじょ$"

SafariZone_RestHouse_Text_Youngster:
	.string "{JPN}ポロックは もってないけど\n"
	.string "ポケモンは けっこう つかまえたよ。\p"
	.string "サファリボールを なげるまえに\n"
	.string "ポケモンに ちかづいておくと\l"
	.string "つかまえやすく なるんだ。$"

SafariZone_RestHouse_Text_PsychicM:
	.string "{JPN}ポロックを つかえば やせいの ポケモンは\n"
	.string "すぐには にげなく なるよ。\p"
	.string "でも にげにくい ポケモンに\n"
	.string "ポロックを あげても あまり いみはない。$"

SafariZone_RestHouse_Text_FatMan:
	.string "{JPN}ポロックおきばに ポロックを おくと\n"
	.string "ポケモンが よってくるんだ。\p"
	.string "おなじような せいかくの ポケモンは\n"
	.string "とくていの ポロックに ひかれると おもうな。$"

SafariZone_South_Text_AreaOffLimits1:
	.string "{JPN}ここは まだ こうじちゅうです。\n"
	.string "たちいりきんしです ごめんなさい!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "{JPN}サファリゾーンの かくちょうこうじは\n"
	.string "ぶじに おわりました。\p"
	.string "あたらしい エリアを おたのしみください。$"

SafariZone_South_Text_AreaOffLimits2:
	.string "{JPN}ここは まだ こうじちゅうです。\n"
	.string "たちいりきんしです ごめんなさい!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "{JPN}わあ! わーい! みたことない\n"
	.string "ポケモン ばっかり!$"

SafariZone_Southeast_Text_FatMan:
	.string "{JPN}この エリアの ポケモンは ぜんぶ\n"
	.string "はじめて みるよ。\p"
	.string "しかも この めずらしい ポケモンを\n"
	.string "つかまえて いいなんて! さいこう!$"

SafariZone_Southeast_Text_RichBoy:
	.string "{JPN}ここらへんの ポケモンは\n"
	.string "ホウエン いがいから きたみたいだね。$"

SafariZone_Northeast_Text_Boy:
	.string "{JPN}サファリボールが あと ふたつしか ないんだ。\p"
	.string "なにを つかまえるか\n"
	.string "なかなか きめられないよ。$"

SafariZone_Northeast_Text_Woman:
	.string "{JPN}ここで ピカチュウが みられるって きいたの。\n"
	.string "どこに いるのかしら?$"

SafariZone_Northeast_Text_Girl:
	.string "{JPN}もう!\n"
	.string "ぜんぜん つかまらない!\p"
	.string "なにか つかまえないと\n"
	.string "にゅうじょうりょうが むだに なっちゃう!$"
