DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "{JPN}よう! チャンピオンを めざす\n"
	.string "{ENG}{PLAYER}{JPN} ちょうしは どうだい?\p"
	.string "ムロの ジムリーダー トウキは\n"
	.string "かくとうタイプの ポケモンの つかいてだ\p"
	.string "ノーマルタイプの ポケモンで\n"
	.string "いどむのは むぼう ってもんだ\p"
	.string "かくとうポケモンは ノーマルポケモンを\n"
	.string "こてんぱんに しちまうからな\l"
	.string "きを つけろよ!\p"
	.string "しかも この ジムは うみの そこ\n"
	.string "みたいに まっくら なんだ\p"
	.string "でも とちゅうの トレーナーを\n"
	.string "たおすと あかるく なっていくぞ\p"
	.string "よし いってこい!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "{JPN}うおォ! あかるく なりすぎだな!\p"
	.string "きみの みらいも あかるいぞ!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "{JPN}ちから こそ せいぎっ!\n"
	.string "こいっ!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "{JPN}ちからぶそく だった……$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "{JPN}じゅう よく ごうを せいす!\n"
	.string "みごとな わざ だった!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "{JPN}トウキさまが でるまでも\n"
	.string "ないわ!\p"
	.string "あたしが たおして あげる!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "{JPN}まさか…… どうして?\n"
	.string "こんなに かんたんに まけるなんて$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "{JPN}この まけを むだには しない\n"
	.string "これを ばねに とっくん する!\p"
	.string "そして いつかは ジムリーダーに……\p"
	.string "いえ ポケモンリーグの\n"
	.string "チャンピオンに なるわよ!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "{JPN}あたしを あまく みない ことね!\n"
	.string "ないても しらないわよ!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "{JPN}わぁーーーん!\n"
	.string "まけたーーーっ!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "{JPN}くらやみの なかで たたかうことで\n"
	.string "こころを きたえるの\p"
	.string "でも まっくら だから\n"
	.string "トウキさまの おかおが みられない……$"

DewfordTown_Gym_Text_LilithIntro:
	.string "{JPN}うふふ……\n"
	.string "くらくて まよっているの かな?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "{JPN}なによ もう……\n"
	.string "あなたなんか しらない!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "{JPN}あなた なんて このまま まよって\n"
	.string "いりぐちに もどっちゃえば いいのよ!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "{JPN}うみの おとこの いじを\n"
	.string "みせつけて やるぜぃ!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "{JPN}どうしたぃ!\n"
	.string "おれが こんな まけかた するなんて!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "{JPN}おう! あんたなら うちの\n"
	.string "ジムリーダーに あう しかくが あるぜぃ$"

DewfordTown_Gym_Text_CristianIntro:
	.string "{JPN}ここを とおる なら\n"
	.string "わしを たおしてから じゃ!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "{JPN}むうーん!\n"
	.string "まるで かなわん……!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "{JPN}わしの まけじゃ!\n"
	.string "その バッジを とりに いけい!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "{JPN}ボクは トウキ!\n"
	.string "ムロの ジムリーダーさ!\p"
	.string "この あたりの あらなみに もまれ\n"
	.string "まっくらな どうくつで\l"
	.string "たくましく そだったんだ!\p"
	.string "ボクに ちょうせん したいって?\n"
	.string "キミの じつりょく みせてもらうよ!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "{JPN}わーお! おもってたより ずっと\n"
	.string "おおきな なみを おこしたね!\p"
	.string "のみこまれちゃったよ!\p"
	.string "オーケー ボクの まけだ\n"
	.string "この ジムバッジを うけとって!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{JPN}{ENG}{PLAYER}{JPN}は トウキから\n"
	.string "ナックルバッジを もらった!$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "{JPN}ナックルバッジが あれば レベル30\n"
	.string "までの ポケモンは こうかんで\l"
	.string "もらった ポケモンも いうことを きく\p"
	.string "それに ひでんわざ フラッシュを\n"
	.string "せんとう いがいで つかえるように なる\p"
	.string "よかったら この わざ\n"
	.string "マシンも つかってよ$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "{JPN}その わざマシン08は ビルドアップ\p"
	.string "こうげきと ぼうぎょの のうりょくを\n"
	.string "どちらも あげる わざ なんだ\p"
	.string "…… …… …… …… …… ……$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "{JPN}ジムリーダー トウキを\n"
	.string "ポケナビに とうろく した!$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "{JPN}キミの さいのうは いつか きょだいな\n"
	.string "なみに なって トレーナーたちを\l"
	.string "おどろかせる あらしを おこすだろうね!$"

DewfordTown_Gym_Text_GymStatue:
	.string "{JPN}ムロタウン ポケモンジム$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "{JPN}ムロタウン ポケモンジム\p"
	.string "トウキ にんてい トレーナー!\n"
	.string "{ENG}{PLAYER}{JPN}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "{JPN}トウキ: なみというのは いちど ひいても\n"
	.string "かならず はまべに もどってくる\p"
	.string "キミほどの ビッグウェーブだ……\n"
	.string "きっと もどってくると おもってたよ!\p"
	.string "さあ どれほど たかさを ましたのか\n"
	.string "ボクに みせてくれ!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "{JPN}わーおっ!\n"
	.string "また のみこまれちゃった!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "{JPN}トウキ: ポケモン しょうぶは ひろくて ふかい\n"
	.string "そこが みえないんだ\l"
	.string "まるで ホウエンの うみの ようだね!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "{JPN}トウキ: なみというのは いちど ひいても\n"
	.string "かならず はまべに もどってくる\p"
	.string "キミほどの ビッグウェーブだ……\n"
	.string "きっと もどってくると おもってたよ!\p"
	.string "……あれ? たたかえる ポケモンを\n"
	.string "1ぴきしか もっていないんだね\p"
	.string "すまないけど 2ひき いじょうの\n"
	.string "ポケモンを もって また きてくれよ$"
