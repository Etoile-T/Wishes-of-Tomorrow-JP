LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad:
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting::
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting::
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting::
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting::
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting::
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting::
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting::
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting::
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting::
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame:
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall::
	lockall
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
#ifdef UBFIX
	setvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1
#else
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE
#endif
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator::
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer::
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament::
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament::
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting::
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting::
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting::
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting::
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting::
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting::
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall:
	.string "{JPN}ここは とくべつてんじしつです。$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall:
	.string "{JPN}ごらんのとおり ここには\n"
	.string "えが いちまいも かざられていません。\p"
	.string "ここには いわゆる こてんびじゅつを\n"
	.string "てんじする つもりは ありません。\p"
	.string "そうした こてんさくひんは\n"
	.string "1かいで ごらんに なれます。\p"
	.string "ここでは こてんとは まったく ちがう\n"
	.string "さくひんを てんじしたいのです。\p"
	.string "げいじゅつは ふるく ゆうめいな\n"
	.string "さくひんだけでは ありませんからね!\p"
	.string "この てんじしつを うめたいのです…\p"
	.string "ポケモンを えがいた げんだいの\n"
	.string "いまにも とびだしてきそうな\l"
	.string "いきいきとした さくひんで!$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit:
	.string "{JPN}しつれいしました。ひとりで\n"
	.string "しゃべりつづける つもりは なかったのです。\p"
	.string "さて あなたは わかいのに\n"
	.string "ずいぶん たびを しているようですね…\p"
	.string "きっと いきいきとした ポケモンや\n"
	.string "それを えがいた えにも であうでしょう。\p"
	.string "そんな えを みつけたら\n"
	.string "ここで てんじしても いいか\l"
	.string "がかの きょかを とって\l"
	.string "いただけませんか?$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit:
	.string "{JPN}この てんじしつを ポケモンの\n"
	.string "あたらしく いきいきとした えで\l"
	.string "いっぱいに したいのです。$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting:
	.string "{JPN}あなたの おかげで あたらしい えを\n"
	.string "かざることが できました!\p"
	.string "あなたの ポケモンを えがいたそうですね。\n"
	.string "ほんとうに すばらしい!\p"
	.string "ほんとうに ほんとうに ありがとう!$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer:
	.string "{JPN}ああ! あなたですか!\n"
	.string "{ENG}{PLAYER}{JPN}!$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests:
	.string "{JPN}すばらしいでしょう?\n"
	.string "この えの コレクション!\p"
	.string "どれも かんぺきです!\n"
	.string "どれが うえとも いえません!\p"
	.string "この えの おかげで びじゅつかんに\n"
	.string "くる おきゃくが ふえました。\p"
	.string "こころから ありがとう {ENG}{PLAYER}{JPN}。\n"
	.string "わたしの ゆめが かなったのです!$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude:
	.string "{JPN}ほんの おれいの しるしです。$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou:
	.string "{JPN}また おあいする ときまで\n"
	.string "これは あずかって おきます。$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit:
	.string "{JPN}ああ よく きてくれました {ENG}{PLAYER}{JPN}!\p"
	.string "いそがしい たびの あいまに\n"
	.string "おこしいただき こうえいです。\p"
	.string "どうぞ おくつろぎに なって\n"
	.string "たのしんで いってください。$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame:
	.string "{JPN}ピンクいろの かざりが ついた\n"
	.string "がくぶちだ。$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame:
	.string "{JPN}きいろい かざりが\n"
	.string "ついた がくぶちだ。$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame:
	.string "{JPN}あおい かざりが\n"
	.string "ついた がくぶちだ。$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame:
	.string "{JPN}あかい かざりが\n"
	.string "ついた がくぶちだ。$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame:
	.string "{JPN}みどりいろの かざりが\n"
	.string "ついた がくぶちだ。$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon:
	.string "{JPN}ポケモンの えだ。$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe:
	.string "{JPN}しばらく こないうちに あたらしい えが\n"
	.string "かざられていて びっくりしたよ。\p"
	.string "うちの ポケモンも こんなに きれいに\n"
	.string "だれかに かいてもらいたいな。$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing:
	.string "{JPN}ほう… わだいの ポケモンの えは\n"
	.string "ここで てんじしているのか。\p"
	.string "なるほど この あたらしい えは\n"
	.string "たしかに なかなか おもしろい。$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon:
	.string "{JPN}へえ そうなの?\n"
	.string "この えは あなたの ポケモンなんだ。\p"
	.string "トレーナーに とって\n"
	.string "これほど うれしいことは ないよね?$"

