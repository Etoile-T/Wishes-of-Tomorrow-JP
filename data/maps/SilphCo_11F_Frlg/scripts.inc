SilphCo_11F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SilphCo_11F_EventScript_PresidentThanksMale
	call_if_eq VAR_RESULT, FEMALE, SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_MASTER_BALL, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SILPH_CO_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_GIOVANNI
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	removeobject LOCALID_SILPH_CO_11F_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMeDearBoy::
	.string "{JPN}しゃちょう: おお ぼうや!\n"
	.string "シルフを すくってくれて ありがとう。\p"
	.string "ききから すくってくれた ことは\n"
	.string "けっして わすれない。\p"
	.string "なにか おれいを しなくては。\p"
	.string "わたしは かねもち だから\n"
	.string "なんでも あげられるぞ。\p"
	.string "そうだ これなんか どうかな。$"

SilphCo_11F_Text_ThanksForSavingMeDearGirl::
	.string "{JPN}しゃちょう: おお おじょうちゃん!\n"
	.string "シルフを すくってくれて ありがとう。\p"
	.string "ききから すくってくれた ことは\n"
	.string "けっして わすれない。\p"
	.string "なにか おれいを しなくては。\p"
	.string "わたしは かねもち だから\n"
	.string "なんでも あげられるぞ。\p"
	.string "そうだ これなんか どうかな。$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
	.string "{JPN}{ENG}{PLAYER}{JPN}は しゃちょうから\n"
	.string "マスターボールを もらった!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
	.string "{JPN}しゃちょう: それは どこにも\n"
	.string "うっていない。\p"
	.string "わが しゃの ひみつの しさくひん\n"
	.string "マスターボールだ。\p"
	.string "どんな ポケモンでも かならず\n"
	.string "つかまえられる!\p"
	.string "でも つかうときは\n"
	.string "ないしょに してくれよ。$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
	.string "{JPN}もちものが いっぱいの ようだ。$"

SilphCo_11F_Text_ThanksForRescuingUs::
	.string "{JPN}ひしょ: みんなを たすけてくれて\n"
	.string "ありがとう ございます。\p"
	.string "しゃちょう いか ぜんいん\n"
	.string "あなたに かんしゃしています。$"

SilphCo_11F_Text_GiovanniIntro::
	.string "{JPN}ほう {ENG}{PLAYER}{JPN}!\n"
	.string "また あったな!\p"
	.string "いま しゃちょうと だいじな\n"
	.string "ビジネスの はなしを している ところだ。\p"
	.string "こどもは おとなの はなしに\n"
	.string "くちを だすな…\p"
	.string "さもなくば いたい めに あうぞ!$"

SilphCo_11F_Text_GiovanniDefeat::
	.string "{JPN}ぐうっ!!\n"
	.string "また まけたのか!?$"

SilphCo_11F_Text_GiovanniPostBattle::
	.string "{JPN}くそっ!\n"
	.string "シルフの けいかくが だいなしだ!\p"
	.string "だが ロケットだんは ほろびぬ!\p"
	.string "{ENG}{PLAYER}{JPN}! わすれるな\n"
	.string "ポケモンは ロケットだんの ために いるのだ!\p"
	.string "ここは ひくが また もどって くるぞ!$"

SilphCo_11F_Text_Grunt2Intro::
	.string "{JPN}そこまでだ!\n"
	.string "うごくな!$"

SilphCo_11F_Text_Grunt2Defeat::
	.string "{JPN}や やめて…\n"
	.string "たのむ!$"

SilphCo_11F_Text_Grunt2PostBattle::
	.string "{JPN}ボスに あいたいって わけか?$"

SilphCo_11F_Text_Grunt1Intro::
	.string "{JPN}とまれ! ボスと あう やくそくは\n"
	.string "あるのか?$"

SilphCo_11F_Text_Grunt1Defeat::
	.string "{JPN}ぐはっ!\n"
	.string "こてんぱんだ!$"

SilphCo_11F_Text_Grunt1PostBattle::
	.string "{JPN}きを つけろ…\n"
	.string "ボスは つよい ポケモンが すきなんだ!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
	.string "{JPN}モニターに ポケモンが うつっている!$"

SilphCo_11F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "11かい$"

