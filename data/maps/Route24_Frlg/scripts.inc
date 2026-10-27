Route24_Frlg_MapScripts::
	.byte 0

Route24_EventScript_Rocket::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ROUTE24, 1, Route24_EventScript_RocketPostBattle
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	call Route24_EventScript_BattleRocket
	release
	end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom
	release
	end

Route24_EventScript_RocketPostBattle::
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	release
	end

Route24_EventScript_RocketTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto Route24_EventScript_RocketTrigger
	end

Route24_EventScript_RocketTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketApproachPlayer
	call_if_eq VAR_TEMP_1, 1, Route24_EventScript_RocketMotionToPlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox Route24_Text_JustEarnedFabulousPrize
	checkitemspace ITEM_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNuggetTrigger
	call Route24_EventScript_BattleRocket
	releaseall
	end

Route24_EventScript_BattleRocket::
	giveitem_msg Route24_Text_ReceivedNuggetFromMysteryTrainer, ITEM_NUGGET
	message Route24_Text_JoinTeamRocket
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_ROUTE24_ROCKET
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketDefeat
	msgbox Route24_Text_YoudBecomeTopRocketLeader
	setvar VAR_MAP_SCENE_ROUTE24, 1
	return

Route24_EventScript_RocketApproachPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketApproachPlayer
	waitmovement 0
	return

Route24_EventScript_RocketMotionToPlayer::
	applymovement LOCALID_ROUTE24_ROCKET, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route24_EventScript_NoRoomForNuggetTrigger::
	msgbox Route24_Text_YouDontHaveAnyRoom
	closemessage
	applymovement LOCALID_PLAYER, Route24_Movement_WalkDown
	waitmovement 0
	call_if_eq VAR_TEMP_1, 0, Route24_EventScript_RocketWalkBackToPos
	release
	end

Route24_EventScript_RocketWalkBackToPos::
	applymovement LOCALID_ROUTE24_ROCKET, Route24_Movement_RocketWalkBackToPos
	waitmovement 0
	return

Route24_Movement_RocketApproachPlayer::
	walk_left
	step_end

Route24_Movement_RocketWalkBackToPos::
	walk_right
	walk_in_place_faster_left
	step_end

Route24_Movement_WalkDown::
	walk_down
	step_end

Route24_Text_JustEarnedFabulousPrize::
	.string "{JPN}おめでとう! 5にんの\n"
	.string "コンテスト トレーナーに かちぬいたね!\p"
	.string "すてきな しょうひんを プレゼントだ!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
	.string "{JPN}{ENG}{PLAYER}{JPN}は なぞの トレーナーから\n"
	.string "きんのたまを もらった!$"

Route24_Text_YouDontHaveAnyRoom::
	.string "{JPN}もちものが いっぱいだな!$"

Route24_Text_JoinTeamRocket::
	.string "{JPN}ところで ものは そうだんだが\n"
	.string "ロケットだんに はいらないか?\p"
	.string "おれたちは ポケモンを つかって\n"
	.string "わるさを する プロの はんざいしゅうだんだ!\p"
	.string "はいりたいだろ?\p"
	.string "ほんとうに いいのか?\p"
	.string "いいから はいれよ!\p"
	.string "はいれって いってるんだ!\p"
	.string "……そうか ちからずくで わからせてやる!\p"
	.string "ことわれない ていあんを\n"
	.string "してやるぜ!$"

Route24_Text_RocketDefeat::
	.string "{JPN}ぐわーっ!\n"
	.string "おまえ やるな!$"

Route24_Text_YoudBecomeTopRocketLeader::
	.string "{JPN}おまえの じつりょくなら ロケットだんの\n"
	.string "かんぶにだって なれるぞ。\p"
	.string "なあ よく かんがえてみろ!\n"
	.string "この チャンスを むだにするなよ。$"

Route24_Text_ShaneIntro::
	.string "{JPN}くさむらから きみの かつやくを みてたよ!$"

Route24_Text_ShaneDefeat::
	.string "{JPN}やっぱりね!$"

Route24_Text_ShanePostBattle::
	.string "{JPN}はしの うえの ひとたちが こわくて\n"
	.string "かくれてたんだ。$"

Route24_Text_EthanIntro::
	.string "{JPN}よし! おれは 5にんめだ!\n"
	.string "ふみつぶしてやる!$"

Route24_Text_EthanDefeat::
	.string "{JPN}うわっ!\n"
	.string "つよすぎる!$"

Route24_Text_EthanPostBattle::
	.string "{JPN}ぜんりょくを つくした。 くいは ない!$"

Route24_Text_ReliIntro::
	.string "{JPN}わたしは 4にんめ!\n"
	.string "つかれてきた?$"

Route24_Text_ReliDefeat::
	.string "{JPN}わたしも まけちゃった!$"

Route24_Text_ReliPostBattle::
	.string "{JPN}ぜんりょくを つくしたから くいは ないわ!$"

Route24_Text_TimmyIntro::
	.string "{JPN}3にんめは ぼくだ!\n"
	.string "かんたんには いかないよ!$"

Route24_Text_TimmyDefeat::
	.string "{JPN}いてっ!\n"
	.string "ぺちゃんこに された!$"

Route24_Text_TimmyPostBattle::
	.string "{JPN}ぜんりょくを つくした。 くいは ない!$"

Route24_Text_AliIntro::
	.string "{JPN}わたしは 2にんめ!\n"
	.string "ここからが ほんばんよ!$"

Route24_Text_AliDefeat::
	.string "{JPN}どうして まけたの?$"

Route24_Text_AliPostBattle::
	.string "{JPN}ぜんりょくを つくした。 くいは ない!$"

Route24_Text_CaleIntro::
	.string "{JPN}ここは みんなに ゴールデン\n"
	.string "ボールブリッジと よばれてる!\p"
	.string "おれたち 5にんの トレーナーに かてば\n"
	.string "すてきな しょうひんが もらえるぞ!\p"
	.string "きみに できるかな?$"

Route24_Text_CaleDefeat::
	.string "{JPN}おおっ!\n"
	.string "やるねえ!$"

Route24_Text_CalePostBattle::
	.string "{JPN}ぜんりょくを つくした。 くいは ない!$"
