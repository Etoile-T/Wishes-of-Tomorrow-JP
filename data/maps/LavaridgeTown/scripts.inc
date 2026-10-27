LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "{JPN}ハルカ: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}! ひさしぶり!\p"
	.string "あれ? あたしが おんせんに いるあいだに\n"
	.string "フエンの ジムバッジを もらったのね。\p"
	.string "きっと つよい ポケモンを\n"
	.string "あつめたのね……\l"
	.string "ううん そだてたんだと おもう。\p"
	.string "これなら あなたに あげても\n"
	.string "いいかな。$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "{JPN}ハルカ: その ゴーゴーゴーグルが あれば\n"
	.string "111ばんどうろの ちかくの さばくも\l"
	.string "らくに とおりぬけ られるわ。\p"
	.string "それにしても {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}……\n"
	.string "ジムに ちょうせん してるなんて……\p"
	.string "あたしに まけたくないから\n"
	.string "がんばってるのね きっと!\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} あたしも トウカジムの\n"
	.string "あなたの おとうさんに いどんでみる!\p"
	.string "じゃあ またね!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "{JPN}ユウキ: よう {ENG}{PLAYER}{JPN} ひさしぶり だな。\n"
	.string "ちょうしは どう?\p"
	.string "ふうん……\n"
	.string "バッジは けっこう あつめてるんだな。\p"
	.string "じゃ\n"
	.string "こいつを やるよ。$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "{JPN}ユウキ: 111ばんどうろの ちかくの\n"
	.string "さばくに いくなら それを\l"
	.string "もっていきな。\p"
	.string "さばくにしか すんでない\n"
	.string "ポケモンも いるはずだ。\l"
	.string "さがしてみたら どうだ?\p"
	.string "オレは……\n"
	.string "トウカの ジムリーダー\l"
	.string "センリさんに いどもうかと おもってる。\p"
	.string "{ENG}{PLAYER}{JPN}と ちがって おまえの おやじは\n"
	.string "ほんとに つよそう だからな。\p"
	.string "じゃあ またな!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "{JPN}ここに タマゴが ひとつ あってのう。\p"
	.string "おんせんの あつい すなに うめて\n"
	.string "かえそうと おもったんじゃが\l"
	.string "それだけでは たりんようでな……\p"
	.string "ポケモンと いっしょに つれて\n"
	.string "あるくのが いちばん よいと\l"
	.string "きいたんじゃ。\p"
	.string "おまえさん トレーナーじゃな?\n"
	.string "ポケモンも げんき いっぱいじゃ。\p"
	.string "どうじゃ?\n"
	.string "この タマゴを かえして くれんか?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "{JPN}よし! タマゴと いっしょに\n"
	.string "たーっぷり あるいて おくれ!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{JPN}{ENG}{PLAYER}{JPN}は タマゴを もらった!$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "{JPN}おや? ポケモンが いっぱいじゃな。\n"
	.string "タマゴを もてる よゆうが ないぞ……$"

LavaridgeTown_Text_AsYouWishThen:
	.string "{JPN}そうかね……\p"
	.string "タマゴを かえしたく なったら\n"
	.string "わしは ここに おるからのう。$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "{JPN}ポケモンの タマゴは ときどき\n"
	.string "そだてやで みつかる……\p"
	.string "そんな うわさを きいたよ。$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "{JPN}ひつような だけ おゆを くみあげても\n"
	.string "おんせんは けっして かれないの。\p"
	.string "ふしぎ でしょ?\p"
	.string "おんせんは かつどう している\n"
	.string "かざんの ちかくに わくの。 ちかの\l"
	.string "みずが マグマで あたためられて\l"
	.string "おんせんとして わきでるのよ。$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "{JPN}こうして あつい すなに うまっていると\n"
	.string "はあぁ……\p"
	.string "あたたかくって イイキモチ……\p"
	.string "……ん? ぎゃっ! イテテッ!\p"
	.string "しりを ポケモンに かまれた!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "{JPN}おや おんせんが すきなのかい?\p"
	.string "わかいのに\n"
	.string "めずらしいねえ。$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "{JPN}あたし まいにち おんせんに はいってるの。\p"
	.string "アスナさん みたいな きれいで つよい\n"
	.string "ジムリーダーに なりたいの。$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "{JPN}おんせんに ポケモンを いれたら\n"
	.string "とんでもない ことに なるかもね。\p"
	.string "でんきぶろ とか あわぶろ とか\n"
	.string "ようがんぶろ とか……$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "{JPN}この おんせんの ききめは\n"
	.string "きんちょうを ほぐして\l"
	.string "きんにくの いたみを やわらげ\l"
	.string "れんあいの なやみを かいけつして\l"
	.string "きんうんも アップ…… だって。$"

LavaridgeTown_Text_TownSign:
	.string "{JPN}フエンタウン\p"
	.string "「ポケモンセンター おんせん\n"
	.string "くつろぐには さいこうの ばしょ!」$"

LavaridgeTown_Text_GymSign:
	.string "{JPN}フエンタウン ポケモンジム\n"
	.string "リーダー アスナ\l"
	.string "「やけど しそうな じょうねつの ひと!」$"

LavaridgeTown_Text_HerbShopSign:
	.string "{JPN}ポケモン かんぽうやく\n"
	.string "「りょうやく くちに にがし!」$"

