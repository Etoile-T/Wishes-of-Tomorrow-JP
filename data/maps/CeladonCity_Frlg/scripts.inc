CeladonCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GotMyKoffingInCinnabar::
	.string "{JPN}おれの ドガースは グレンじまで ゲットした。\p"
	.string "ふだんは おとなしいけど おこると\n"
	.string "どくガスを はくんだ。$"

CeladonCity_Text_GymIsGreatFullOfWomen::
	.string "{JPN}へへっ! この ジムは さいこう!\n"
	.string "おんなのこ ばっかりだ!$"

CeladonCity_Text_GameCornerIsBadForCitysImage::
	.string "{JPN}タマムシは まちを うつくしく たもつ\n"
	.string "どりょくを ほこりに しているの。\p"
	.string "だから あたらしい ゲームコーナーは\n"
	.string "まちの イメージを わるくするわ。$"

CeladonCity_Text_BlewItAllAtSlots::
	.string "{JPN}うう…\n"
	.string "スロットで ぜんぶ すっちまった!\p"
	.string "コインを けいひんに かえておけば\n"
	.string "よかったんだ!$"

CeladonCity_Text_MyTrustedPalPoliwrath::
	.string "{JPN}こいつは しんらいする あいぼう ニョロボン。\p"
	.string "みずのいしを つかったら\n"
	.string "ニョロゾから しんか したんだ。$"

CeladonCity_Text_Poliwrath::
	.string "{JPN}ニョロボン: ニョロ ニョロッ!$"

CeladonCity_Text_GetLostOrIllPunchYou::
	.string "{JPN}なに じろじろ みてんだ?\n"
	.string "うせろ! さもないと なぐるぞ。$"

CeladonCity_Text_KeepOutOfTeamRocketsWay::
	.string "{JPN}ロケットだんの じゃまを するなよ!$"

CeladonCity_Text_ExplainXAccuracyDireHit::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "ヨクアタールは わざの めいちゅうりつを\n"
	.string "あげる。\p"
	.string "クリティカッターは きゅうしょに\n"
	.string "あたる かくりつを ぐんと あげる。\p"
	.string "どうぐは タマムシデパートで\n"
	.string "かおう!$"

CeladonCity_Text_CitySign::
	.string "{JPN}タマムシシティ\n"
	.string "にじいろの ゆめの まち$"

CeladonCity_Text_GymSign::
	.string "{JPN}タマムシシティ ポケモンジム\n"
	.string "リーダー: エリカ\l"
	.string "しぜんを あいする おじょうさま!$"

CeladonCity_Text_MansionSign::
	.string "{JPN}タマムシマンション$"

CeladonCity_Text_DeptStoreSign::
	.string "{JPN}ほしいものは\n"
	.string "タマムシデパートで!$"

CeladonCity_Text_GuardSpecProtectsFromStatus::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "エフェクトガードは せんとうちゅう\n"
	.string "のうりょくを さげる わざから\l"
	.string "ポケモンを まもる。\p"
	.string "どうぐは\n"
	.string "タマムシデパートで かおう!$"

CeladonCity_Text_PrizeExchangeSign::
	.string "{JPN}コインを けいひんと こうかん!\n"
	.string "けいひん こうかんじょ$"

CeladonCity_Text_GameCornerSign::
	.string "{JPN}ロケット ゲームコーナー\n"
	.string "おとなの あそびば!$"

CeladonCity_Text_ScaldedTongueOnTea::
	.string "{JPN}あちちっ いてて…\n"
	.string "したを やけど しちゃった!\p"
	.string "マンションの やさしい おばあさんが\n"
	.string "おちゃを くれたんだ。\p"
	.string "でも すごく あつかった!\n"
	.string "さまさないと のめないよ。$"

Text_SoftboiledTeach::
	.string "{JPN}こんにちは!\p"
	.string "あなたの ことは みかけてたけど\n"
	.string "はなす きかいが なかったわ。\p"
	.string "やっと であえたのは きっと\n"
	.string "うんが よかったのね。\p"
	.string "おいわいに タマゴうみ という\n"
	.string "わざを おしえて あげたいわ。$"

Text_SoftboiledDeclined::
	.string "{JPN}これからも ずっと あなたを\n"
	.string "みまもって いるわ。\p"
	.string "また おはなし できると いいわね。$"

Text_SoftboiledWhichMon::
	.string "{JPN}それで タマゴうみを おぼえる\n"
	.string "チャンスを もらう ポケモンは どの こ?$"

Text_SoftboiledTaught::
	.string "{JPN}あなたの こううんを いのってるわ!$"

CeladonCity_Text_SomeoneStoleSilphScope::
	.string "{JPN}ああ どうしたら いいんだ…\p"
	.string "だれかに シルフスコープを ぬすまれた。\p"
	.string "どろぼうは こっちへ はしってきた\n"
	.string "それは たしかなんだ。\p"
	.string "でも みうしなって しまった!\n"
	.string "どこへ いったんだ?$"

