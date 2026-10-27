FuchsiaCity_Gym_Frlg_MapScripts::
	.byte 0

FuchsiaCity_Gym_EventScript_Koga::
	famechecker FAMECHECKER_KOGA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaIntro, FuchsiaCity_Gym_Text_KogaDefeat, FuchsiaCity_Gym_EventScript_DefeatedKoga, NO_MUSIC
	goto_if_unset FLAG_GOT_TM06_FROM_KOGA, FuchsiaCity_Gym_EventScript_GiveTM06
	msgbox FuchsiaCity_Gym_Text_KogaPostBattle
	release
	end

FuchsiaCity_Gym_EventScript_DefeatedKoga::
	famechecker FAMECHECKER_KOGA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	setflag FLAG_DEFEATED_KOGA
	setflag FLAG_BADGE05_GET
	set_gym_trainers_frlg 5
	goto FuchsiaCity_Gym_EventScript_GiveTM06
	end

FuchsiaCity_Gym_EventScript_GiveTM06::
	msgbox FuchsiaCity_Gym_Text_KogaExplainSoulBadge
	checkitemspace ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM06
	giveitem_msg FuchsiaCity_Gym_Text_ReceivedTM06FromKoga, ITEM_TM06
	setflag FLAG_GOT_TM06_FROM_KOGA
	msgbox FuchsiaCity_Gym_Text_KogaExplainTM06
	release
	end

FuchsiaCity_Gym_EventScript_NoRoomForTM06::
	msgbox FuchsiaCity_Gym_Text_MakeSpaceForThis
	release
	end

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	famechecker FAMECHECKER_KOGA, 2
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KOGA, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_KogaIntro::
	.string "{JPN}キョウ: ファッファッファッ!\p"
	.string "おまえの ような こどもが\n"
	.string "せっしゃに いどむ とな?\p"
	.string "かんがえた だけで\n"
	.string "わらいが とまらぬわ!\p"
	.string "よかろう! にんじゃ マスターの\n"
	.string "まことの きょうふを みせてやる!\p"
	.string "どくは じわじわと はめつを まねき\n"
	.string "ねむりは てきを むりょくに する。\p"
	.string "どくタイプ ポケモンの\n"
	.string "しのびよる きょうふに ぜつぼう せよ!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

FuchsiaCity_Gym_Text_KogaDefeat::
	.string "{JPN}むう!\n"
	.string "おまえの じつりょく みとめよう!\p"
	.string "さあ!\n"
	.string "ピンクバッジを うけとれ!$"

FuchsiaCity_Gym_Text_KogaPostBattle::
	.string "{JPN}どくどくを うけた ポケモンは\n"
	.string "どんどん くるしむ ことになる。\p"
	.string "たたかいが ながびくほど\n"
	.string "ダメージが ふえていくのだ!\p"
	.string "てきを きっと おびえさせるであろう!$"

FuchsiaCity_Gym_Text_KogaExplainSoulBadge::
	.string "{JPN}ピンクバッジを もっていれば\n"
	.string "ポケモンの ぼうぎょが あがる。\p"
	.string "さらに せんとう いがいでも\n"
	.string "なみのりが つかえるのだ。\p"
	.string "おお!\n"
	.string "これも もっていけ!$"

FuchsiaCity_Gym_Text_ReceivedTM06FromKoga::
	.string "{JPN}{ENG}{PLAYER}{JPN}は キョウから\n"
	.string "わざマシン06を もらった!$"

FuchsiaCity_Gym_Text_KogaExplainTM06::
	.string "{JPN}その わざマシン06には\n"
	.string "どくどくが ふうじこめてある!\p"
	.string "およそ 400ねん まえから つたわる\n"
	.string "ひでんの わざで ござる。$"

FuchsiaCity_Gym_Text_MakeSpaceForThis::
	.string "{JPN}にもつを あけておけ こどもよ!$"

FuchsiaCity_Gym_Text_KaydenIntro::
	.string "{JPN}ポケモンは ちからが すべてじゃない。\n"
	.string "わかるかい?\p"
	.string "ポケモンは さくせんが だいじなんだ!\p"
	.string "さくせんで ちからずくに かてると\n"
	.string "みせてやろう。$"

FuchsiaCity_Gym_Text_KaydenDefeat::
	.string "{JPN}なに?\n"
	.string "おみごと!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
	.string "{JPN}ちからと あたまを くみあわせるか?\n"
	.string "いい さくせんだ!\p"
	.string "こどもの トレーナーにしては\n"
	.string "たいしたものだ。$"

FuchsiaCity_Gym_Text_KirkIntro::
	.string "{JPN}むかしは てじなしだったんだ。\p"
	.string "でも にんじゃに あこがれて\n"
	.string "この ジムに はいったのさ。$"

FuchsiaCity_Gym_Text_KirkDefeat::
	.string "{JPN}もう だめだ!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
	.string "{JPN}まけても わたしは にんじゃの ししょう\n"
	.string "キョウさまの おしえを まもって\l"
	.string "しゅぎょうを つづけるぞ。$"

FuchsiaCity_Gym_Text_NateIntro::
	.string "{JPN}わたしの とくい わざを\n"
	.string "やぶれるかな!$"

FuchsiaCity_Gym_Text_NateDefeat::
	.string "{JPN}すっかり だまされたよ!$"

FuchsiaCity_Gym_Text_NatePostBattle::
	.string "{JPN}どくや ねむりの わざが すきだ。\n"
	.string "たたかいの あとも のこるからな!$"

FuchsiaCity_Gym_Text_PhilIntro::
	.string "{JPN}そこまでだ!\p"
	.string "セキチクジム じまんの みえない かべに\n"
	.string "イライラ してるだろう?$"

FuchsiaCity_Gym_Text_PhilDefeat::
	.string "{JPN}うおっ!\n"
	.string "やるじゃないか!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
	.string "{JPN}かんしんしたよ!\n"
	.string "ヒントを やろう!\p"
	.string "みえない かべの すきまを\n"
	.string "よーく さがして みるんだ!$"

FuchsiaCity_Gym_Text_EdgarIntro::
	.string "{JPN}わたしも キョウさまの もとで\n"
	.string "にんじゃの みちを まなんでいる!\p"
	.string "にんじゃは むかしから\n"
	.string "どうぶつを つかって きたのだ!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
	.string "{JPN}アオーン!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
	.string "{JPN}まだまだ まなぶことが おおいな。$"

FuchsiaCity_Gym_Text_ShawnIntro::
	.string "{JPN}キョウさまは だいだい つづく\n"
	.string "にんじゃの いえがら なのだ。\p"
	.string "おまえは なにの しそん だ?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
	.string "{JPN}おもって いたより\n"
	.string "うでが たつな!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
	.string "{JPN}ひかり ある ところに\n"
	.string "かげ あり!\p"
	.string "ひかりと かげ!\n"
	.string "おまえは どちらを えらぶ?$"

FuchsiaCity_Gym_Text_GymGuyAdvice::
	.string "{JPN}よう!\n"
	.string "みらいの チャンピオン!\p"
	.string "セキチクジムは しかけだらけ。\n"
	.string "みえない かべが いっぱいなんだ!\p"
	.string "キョウは ちかくに みえても\n"
	.string "かべで さえぎられてる。\p"
	.string "かべの すきまを みつけないと\n"
	.string "たどりつけないぞ。$"

FuchsiaCity_Gym_Text_GymGuyPostVictory::
	.string "{JPN}いまの じだいでも にんじゃって\n"
	.string "すごく こわいもんだな!$"

FuchsiaCity_Gym_Text_GymStatue::
	.string "{JPN}セキチク ポケモンジム\n"
	.string "ジムリーダー キョウ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
	.string "{JPN}セキチク ポケモンジム\n"
	.string "ジムリーダー キョウ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN} {ENG}{PLAYER}{JPN}$"

