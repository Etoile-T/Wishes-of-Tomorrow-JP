ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
	.string "{JPN}ファファファ!\n"
	.string "わたしの かくれがへ ようこそ!\p"
	.string "ロケットだんを かつての すがたに\n"
	.string "たてなおすまで ここに いる つもりだ。\p"
	.string "だが きみは また わたしを みつけた。\n"
	.string "よかろう。\l"
	.string "こんどは てかげん しないぞ!\p"
	.string "ふたたび あいまみえよう\n"
	.string "さいきょうの トレーナー サカキと!{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"

ViridianCity_Gym_Text_GiovanniDefeat::
	.string "{JPN}ふっ!\n"
	.string "じつに はげしい たたかい だった。\l"
	.string "きみの かちだ!\p"
	.string "その あかしに グリーンバッジを やろう!\n"
	.string "{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}$"

ViridianCity_Gym_Text_GiovanniPostBattle::
	.string "{JPN}こんな まけかたを しては\n"
	.string "ぶかたちに あわせる かおが ない。\l"
	.string "かれらの しんらいを うらぎった。\p"
	.string "きょうを かぎりに ロケットだんは\n"
	.string "えいえんに かいさん する!\p"
	.string "わたしは ふたたび しゅぎょうに\n"
	.string "じんせいを ささげる つもりだ。\p"
	.string "いつか また あおう!\n"
	.string "さらばだ!$"

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
	.string "{JPN}グリーンバッジが あれば どんな\n"
	.string "レベルの ポケモンも したがう。\p"
	.string "ポケモントレーナーとして\n"
	.string "きわめた ものの あかしだ。\p"
	.string "それが あれば ポケモンリーグに\n"
	.string "ちょうせん できる。\p"
	.string "それと この わざマシンも やろう。\p"
	.string "ポケモンリーグへの ちょうせんへの\n"
	.string "はなむけだ。$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
	.string "{JPN}{ENG}{PLAYER}{JPN}は サカキから\n"
	.string "わざマシン26を もらった!$"

ViridianCity_Gym_Text_ExplainTM26::
	.string "{JPN}わざマシン26は じしん。\p"
	.string "おおきな ゆれを おこす\n"
	.string "きょうりょくな こうげきだ。\p"
	.string "わたしが ここで ジムを していた\n"
	.string "ずっと むかしに つくった ものだ… $"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
	.string "{JPN}きみには これを もつ よゆうが ないな!$"

ViridianCity_Gym_Text_YujiIntro::
	.string "{JPN}へっ!\n"
	.string "そろそろ ばてて きた\l"
	.string "ころだろう!$"

ViridianCity_Gym_Text_YujiDefeat::
	.string "{JPN}ガスけつだ!$"

ViridianCity_Gym_Text_YujiPostBattle::
	.string "{JPN}うちの ジムリーダーに ついていくには\n"
	.string "パワーが いるぞ。$"

ViridianCity_Gym_Text_AtsushiIntro::
	.string "{JPN}ぐおおお!\n"
	.string "いかりが こみあげて きたぞ!$"

ViridianCity_Gym_Text_AtsushiDefeat::
	.string "{JPN}ぐはっ!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
	.string "{JPN}おれは まだまだ だ!$"

ViridianCity_Gym_Text_JasonIntro::
	.string "{JPN}ポケモンと ぼくは すばらしい\n"
	.string "おんがくを かなでるのさ!$"

ViridianCity_Gym_Text_JasonDefeat::
	.string "{JPN}きみは かんぺきな ハーモニーだ!$"

ViridianCity_Gym_Text_JasonPostBattle::
	.string "{JPN}うちの ジムリーダーの しょうたいを\n"
	.string "しってるかい?$"

ViridianCity_Gym_Text_KiyoIntro::
	.string "{JPN}カラテこそ さいこうの\n"
	.string "ぶじゅつ なのだ!$"

ViridianCity_Gym_Text_KiyoDefeat::
	.string "{JPN}アイヤー!$"

ViridianCity_Gym_Text_KiyoPostBattle::
	.string "{JPN}おれの ポケモンが おれほど\n"
	.string "カラテが うまければ…$"

ViridianCity_Gym_Text_WarrenIntro::
	.string "{JPN}ほんとうの てんさいは かっこよく かつ。$"

ViridianCity_Gym_Text_WarrenDefeat::
	.string "{JPN}てが すべった!$"

ViridianCity_Gym_Text_WarrenPostBattle::
	.string "{JPN}こんな まけかたをしたら\n"
	.string "リーダーに しかられる…$"

ViridianCity_Gym_Text_TakashiIntro::
	.string "{JPN}おれは カラテおう!\n"
	.string "きさまの うんめいは おれ しだい!$"

ViridianCity_Gym_Text_TakashiDefeat::
	.string "{JPN}アイヤー!$"

ViridianCity_Gym_Text_TakashiPostBattle::
	.string "{JPN}ポケモンリーグ だと?\n"
	.string "おまえが? ちょうしに のるなよ!$"

ViridianCity_Gym_Text_ColeIntro::
	.string "{JPN}おれの ムチの おとで おまえの\n"
	.string "ポケモンは すくみあがるぞ!$"

ViridianCity_Gym_Text_ColeDefeat::
	.string "{JPN}いてて!\n"
	.string "ムチが はねかえった!$"

ViridianCity_Gym_Text_ColePostBattle::
	.string "{JPN}まて!\n"
	.string "ちょっと ゆだん しただけだ!$"

ViridianCity_Gym_Text_SamuelIntro::
	.string "{JPN}トキワジムは ながい あいだ\n"
	.string "しまって いたんだ。\p"
	.string "でも いまは リーダーが もどってきた!$"

ViridianCity_Gym_Text_SamuelDefeat::
	.string "{JPN}まけた のか?$"

ViridianCity_Gym_Text_SamuelPostBattle::
	.string "{JPN}うちの ジムリーダーを たおさないと\n"
	.string "ポケモンリーグには\l"
	.string "すすめないぞ!$"

ViridianCity_Gym_Text_GymGuyAdvice::
	.string "{JPN}オーッス!\n"
	.string "みらいの チャンピオン!\p"
	.string "おれでも トキワの リーダーの\n"
	.string "しょうたいは しらないんだ。\p"
	.string "でも ひとつ たしかな ことがある。\n"
	.string "ここの リーダーは ジムリーダーの\l"
	.string "なかで いちばん てごわいぞ。\p"
	.string "それと ここの トレーナーは\n"
	.string "じめんタイプが すきらしい。$"

ViridianCity_Gym_Text_GymGuyPostVictory::
	.string "{JPN}おどろいた! サカキが トキワの\n"
	.string "ジムリーダー だったなんて!$"

ViridianCity_Gym_Text_GymStatue::
	.string "{JPN}トキワ ポケモンジム\n"
	.string "リーダー ?\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "{JPN}トキワ ポケモンジム\n"
	.string "リーダー サカキ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN} {ENG}{PLAYER}{JPN}$"

