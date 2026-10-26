LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "{JPN}ミナモびじゅつかんへ ようこそ。\p"
	.string "ポケモンを だいざいにした\n"
	.string "すばらしい びじゅつひんの かずかずを\l"
	.string "どうぞ ごゆっくり おたのしみください。$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "{JPN}わたしは この びじゅつかんの\n"
	.string "かんちょうです。\p"
	.string "あなたのような わかいかたが きてくださり\n"
	.string "うれしく おもいます。\p"
	.string "てんじしている えは\n"
	.string "もう ごらんに なりましたか?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "{JPN}ああ それでは おじゃまは しません。\n"
	.string "どうぞ ごゆっくり。$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "{JPN}おや? あなたは どうやら\n"
	.string "ポケモントレーナーの ようですね。\p"
	.string "えにも きょうみを\n"
	.string "おもちなのですか?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "{JPN}そうですか…\p"
	.string "それでも きてくださるとは\n"
	.string "こうえいです。$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "{JPN}ああ すばらしい!\n"
	.string "えが おすきなのですね!\p"
	.string "それでは ついてきて いただけますか?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "{JPN}とても ふるい えだ。\n"
	.string "ところどころ えのぐが はがれている。$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "{JPN}きみょうで げんそうてきな けしきが\n"
	.string "えがかれた ふしぎな ふうけいがだ。$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "{JPN}ひざに ポケモンを のせて ほほえむ\n"
	.string "うつくしい おんなのひとの えだ。$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "{JPN}むかしの でんせつの ポケモンを\n"
	.string "えがいた えだ。\p"
	.string "がかが そうぞうして\n"
	.string "かいたものだ。$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "{JPN}そよかぜに ゆれる くさポケモンの\n"
	.string "えだ。\p"
	.string "やさしく なでるような かぜを\n"
	.string "たのしんでいるように みえる。$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "{JPN}おいしそうな きのみを\n"
	.string "えがいた えだ。\p"
	.string "みていると おなかが すいてきそう!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "{JPN}ゆうめいな ちょうこくの レプリカだ。\p"
	.string "こだいの とりポケモンを かたどっている。$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "{JPN}くろい いしを ほって つくった\n"
	.string "おおきな モンスターボールだ。\p"
	.string "むかしの おまつりで\n"
	.string "つかわれていたらしい。$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "{JPN}おおきな せきばんに ポケモンと\n"
	.string "ちいさな もじが びっしりと\l"
	.string "ほられている。むかしの ことばで\l"
	.string "なにが かいてあるのか よめない。$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "{JPN}うーむ…\n"
	.string "なんとも すばらしい さくひんたちだ…$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "{JPN}たしかに ポケモンで たたかうのは\n"
	.string "たのしいでしょう。\p"
	.string "でも びじゅつを あいする こころも\n"
	.string "わすれては いけませんよ。$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "{JPN}この びじゅつかんでは… そうだね\n"
	.string "すばらしい えを たくさん みられる。\p"
	.string "それに かんちょうも すてきな ひとだ。\p"
	.string "わたしのような げいじゅつかにとって\n"
	.string "この びじゅつかんは しげきに なるんだ。$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "{JPN}この おんなのひと きれい!\n"
	.string "ママみたい!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "{JPN}この ポケモン かわいいわね!\n"
	.string "うちの ぼうや みたい!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "{JPN}この びじゅつかんに あたらしい えが\n"
	.string "はいったと きいたんだ。\p"
	.string "それで さっそく かけつけたのさ。\p"
	.string "あたらしい えは\n"
	.string "2かいに あるのかな?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "{JPN}さいきん かんちょうは\n"
	.string "やけに ごきげんだね。\p"
	.string "きっと なにか いいことが あったんだ。\n"
	.string "まちがいないね。$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "{JPN}ここで すばらしい えを たくさん みて\n"
	.string "まなぼうと おもってるんだ。\p"
	.string "いつか じぶんの さくひんを ここに\n"
	.string "かざってもらうのが ゆめなんだ。$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "{JPN}この びじゅつかんは かんこうきゃくに\n"
	.string "にんきの ばしょに なった。\p"
	.string "ミナモに とって すばらしいことだ…\n"
	.string "いや ホウエンに とってだね!\p"
	.string "きいた はなしでは ひとりの トレーナーが\n"
	.string "2かいの えを ぜんぶ そろえたそうだよ。$"

