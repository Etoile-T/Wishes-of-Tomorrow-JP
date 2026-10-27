PewterCity_Gym_Frlg_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Brock::
	famechecker FAMECHECKER_BROCK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrock, NO_MUSIC
	goto_if_unset FLAG_GOT_TM39_FROM_BROCK, PewterCity_Gym_EventScript_GiveTM39
	msgbox PewterCity_Gym_Text_BrockPostBattle
	release
	end

PewterCity_Gym_EventScript_DefeatedBrock::
	famechecker FAMECHECKER_BROCK, 1
	setflag FLAG_DEFEATED_BROCK
	setflag FLAG_BADGE01_GET
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_RUNNING_SHOES_GUY
	set_gym_trainers_frlg 1
	goto PewterCity_Gym_EventScript_GiveTM39
	end

PewterCity_Gym_EventScript_GiveTM39::
	msgbox PewterCity_Gym_Text_TakeThisWithYou
	checkitemspace ITEM_TM39
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM39
	giveitem_msg PewterCity_Gym_Text_ReceivedTM39FromBrock, ITEM_TM39
	setflag FLAG_GOT_TM39_FROM_BROCK
	msgbox PewterCity_Gym_Text_ExplainTM39
	release
	end

PewterCity_Gym_EventScript_NoRoomForTM39::
	msgbox PewterCity_Gym_Text_DontHaveRoomForThis
	release
	end

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BROCK, PewterCity_Gym_EventScript_GymGuyPostVictory
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial
	release
	end

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders
	release
	end

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_BrockIntro::
	.string "{JPN}きたな。 おれは タケシ。\n"
	.string "ニビの ジムリーダーだ。\p"
	.string "おれの いしのように かたい いしは\n"
	.string "ポケモンにも あらわれている。\p"
	.string "おれの ポケモンは みんな いわの ように\n"
	.string "かたく がまんづよい。\p"
	.string "そう おれの ポケモンは みんな\n"
	.string "いわタイプ だ!\p"
	.string "フハハ! まけると わかっていて\n"
	.string "おれに いどむのか?\p"
	.string "それが きみを たたかいに かりたてる\n"
	.string "トレーナーの ほこり なのだな。\p"
	.string "いいだろう!\n"
	.string "ほんきで こい!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

PewterCity_Gym_Text_BrockDefeat::
	.string "{JPN}きみを みくびって いた から\n"
	.string "まけたのだ。\p"
	.string "しょうりの あかしに\n"
	.string "これを…ポケモンリーグ こうにんの\l"
	.string "グレーバッジを わたそう。\p"
	.string "{FONT_NORMAL}{ENG}{PLAYER}{JPN}は タケシから\n"
	.string "グレーバッジを もらった!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
	.string "{FONT_MALE}グレーバッジを もっているだけで\n"
	.string "ポケモンが つよく なる。\p"
	.string "さらに せんとう いがいでも\n"
	.string "フラッシュが つかえるように なる。\p"
	.string "もちろん ポケモンが フラッシュを\n"
	.string "おぼえていなければ だめだがな。$"

PewterCity_Gym_Text_TakeThisWithYou::
	.string "{JPN}まて!\n"
	.string "これも もっていけ。$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
	.string "{JPN}{ENG}{PLAYER}{JPN}は タケシから\n"
	.string "わざマシン39を もらった!$"

PewterCity_Gym_Text_ExplainTM39::
	.string "{JPN}わざマシンには ポケモンの\n"
	.string "わざが はいっている。\p"
	.string "わざマシンを つかうと\n"
	.string "ポケモンに その わざを おしえられる。\p"
	.string "わざマシンは 1かい かぎりだ。\p"
	.string "だから つかうときは\n"
	.string "ポケモンを よく えらべよ。\p"
	.string "とにかく…\n"
	.string "わざマシン39は がんせきふうじ。\p"
	.string "いわを なげつけて あいての\n"
	.string "すばやさを さげる わざだ。$"

PewterCity_Gym_Text_BrockPostBattle::
	.string "{JPN}この ひろい せかいには\n"
	.string "いろんな トレーナーが いる。\p"
	.string "きみは ポケモントレーナーとして\n"
	.string "かなりの さいのうが ある ようだ。\p"
	.string "そこで ひとつ ていあんだ。\p"
	.string "ハナダの ジムへ いって\n"
	.string "じぶんの ちからを ためしてみろ。$"

PewterCity_Gym_Text_DontHaveRoomForThis::
	.string "{JPN}もちものが いっぱいの ようだな。$"

PewterCity_Gym_Text_LiamIntro::
	.string "{JPN}そこまでだ!\p"
	.string "タケシと たたかうなんて\n"
	.string "1まんこうねん はやいぜ!$"

PewterCity_Gym_Text_LiamDefeat::
	.string "{JPN}くそっ!\p"
	.string "こうねんは じかんじゃ なくて…\n"
	.string "きょりの たんいだった!$"

PewterCity_Gym_Text_LiamPostBattle::
	.string "{JPN}なかなか アツいな。\n"
	.string "…でも タケシほどじゃ ない!$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
	.string "{JPN}やあ!\n"
	.string "おおきな ゆめを みたいかい?\p"
	.string "ポケモンチャンピオンに なる ゆめを\n"
	.string "みる ゆうきは あるかい?\p"
	.string "わたしは トレーナーじゃ ないけど\n"
	.string "かつ ための アドバイスは できるよ。\p"
	.string "きみを トップに みちびいて あげよう!$"

PewterCity_Gym_Text_LetsGetHappening::
	.string "{JPN}よし!\n"
	.string "はじめよう!$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
	.string "{JPN}しょうぶで さいしょに でる ポケモンは\n"
	.string "ポケモンリストの いちばん ひだりだ。\p"
	.string "ポケモンの じゅんばんを かえると\n"
	.string "ゆうりに なる ことも ある。\p"
	.string "あいての パーティに あわせて\n"
	.string "いろんな じゅんばんを ためしてみて。$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
	.string "{JPN}むりょう サービスだよ!\n"
	.string "さあ はじめよう!$"

PewterCity_Gym_Text_YoureChampMaterial::
	.string "{JPN}おもった とおりだ!\n"
	.string "きみは チャンピオンの うつわだ!$"

PewterCity_Gym_Text_GymStatue::
	.string "{JPN}ニビ ポケモンジム\n"
	.string "ジムリーダー タケシ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
	.string "{JPN}ニビ ポケモンジム\n"
	.string "ジムリーダー タケシ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN} {ENG}{PLAYER}{JPN}$"

