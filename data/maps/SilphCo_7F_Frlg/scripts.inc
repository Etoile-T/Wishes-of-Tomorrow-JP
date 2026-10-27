SilphCo_7F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
	.string "{JPN}あっ! きみは ロケットだんじゃ ないね!\n"
	.string "たすけに きてくれたの?\l"
	.string "いやあ ありがとう!\p"
	.string "たすけてくれた おれいに\n"
	.string "この ポケモンを あげるよ$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
	.string "{JPN}{ENG}{PLAYER}{JPN}は シルフの しゃいんから\n"
	.string "ラプラスを もらった!$"

SilphCo_7F_Text_ExplainLapras::
	.string "{JPN}それは ラプラス\n"
	.string "とても かしこい ポケモンだよ\p"
	.string "けんきゅうじょで かってたけど\n"
	.string "きみと いるほうが しあわせだ\p"
	.string "きみなら ラプラスの いい\n"
	.string "トレーナーに なれると おもう!\p"
	.string "およぎが とくいなんだ\n"
	.string "みずの うえを はこんでくれるよ!$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
	.string "{JPN}ロケットだんの ボスが\n"
	.string "じゅうやくしつに いったぞ!\p"
	.string "しゃちょうは ぶじだろうか?\n"
	.string "しんぱいだ$"

SilphCo_7F_Text_RocketsAfterMasterBall::
	.string "{JPN}ロケットだんの ねらいは\n"
	.string "なんでも つかまる マスターボールだった$"

SilphCo_7F_Text_CanceledMasterBallProject::
	.string "{JPN}ロケットだんの せいで\n"
	.string "マスターボールの けいかくは ちゅうしだ$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
	.string "{JPN}ロケットだんに シルフや ポケモンを\n"
	.string "のっとられたら たいへんだ$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
	.string "{JPN}すごい!\p"
	.string "ロケットだんを たった ひとりで\n"
	.string "おいはらったの?$"

SilphCo_7F_Text_ReallyDangerousHere::
	.string "{JPN}きみ!\n"
	.string "ここは ほんとに あぶないよ!\p"
	.string "たすけに きてくれたの?\n"
	.string "むりだよ!$"

SilphCo_7F_Text_ThankYouSoMuch::
	.string "{JPN}ほんとうに ありがとう!$"

SilphCo_7F_Text_Grunt3Intro::
	.string "{JPN}おっと!\n"
	.string "ネズミの においが するぜ!$"

SilphCo_7F_Text_Grunt3Defeat::
	.string "{JPN}めのまえが まっくらだ!$"

SilphCo_7F_Text_Grunt3PostBattle::
	.string "{JPN}ちょろちょろ うごきまわっても\n"
	.string "ボスは みつからねえぞ!$"

SilphCo_7F_Text_JoshuaIntro::
	.string "{JPN}ヘッヘッヘ!\p"
	.string "シルフの しゃいんと まちがえたか?$"

SilphCo_7F_Text_JoshuaDefeat::
	.string "{JPN}まいった!$"

SilphCo_7F_Text_JoshuaPostBattle::
	.string "{JPN}としの わりに\n"
	.string "うでの たつ トレーナーだな!$"

SilphCo_7F_Text_Grunt1Intro::
	.string "{JPN}おれは ロケットだん\n"
	.string "4きょうだいの ひとり!$"

SilphCo_7F_Text_Grunt1Defeat::
	.string "{JPN}ぐわっ!\n"
	.string "きょうだいたち まけちまった!$"

SilphCo_7F_Text_Grunt1PostBattle::
	.string "{JPN}かまわねえ\n"
	.string "きょうだいたちが しかえし するさ!$"

SilphCo_7F_Text_Grunt2Intro::
	.string "{JPN}こどもの しんにゅうしゃ?\n"
	.string "おまえの ことだな!$"

SilphCo_7F_Text_Grunt2Defeat::
	.string "{JPN}ちっ!\n"
	.string "まけたよ!$"

SilphCo_7F_Text_Grunt2PostBattle::
	.string "{JPN}ボスが キレる まえに\n"
	.string "とっとと かえりな!$"

SilphCo_7F_Text_RivalWhatKeptYou::
	.string "{JPN}{ENG}{RIVAL}{JPN}: おそかったな {ENG}{PLAYER}{JPN}!$"

SilphCo_7F_Text_RivalIntro::
	.string "{JPN}{ENG}{RIVAL}{JPN}: ハッハッハ! ここで まってりゃ\n"
	.string "くると おもってたぜ!\p"
	.string "ロケットだんに てこずったんだろ!\n"
	.string "ま おれには かんけい ないけどな!\p"
	.string "ヤマブキで みかけたからさ\n"
	.string "うでが あがったか みてやるよ!$"

SilphCo_7F_Text_RivalDefeat::
	.string "{JPN}ちぇっ!\n"
	.string "ロケットだんの ボスと やる\l"
	.string "じゅんびは できてるって わけか!$"

SilphCo_7F_Text_RivalPostBattle::
	.string "{JPN}じゃあな {ENG}{PLAYER}{JPN}!\n"
	.string "おれは どんどん さきへ いくぜ!\p"
	.string "ずかんを みてるとな\n"
	.string "なにが つよくて どう しんか\l"
	.string "するのか わかってくるんだ!\p"
	.string "おれって てんさいじゃ ねえか?\p"
	.string "おれは ポケモンリーグに いって\n"
	.string "してんのうを けちらしてやる\p"
	.string "そして せかいで いちばん\n"
	.string "つよい トレーナーに なるんだ!\p"
	.string "{ENG}{PLAYER}{JPN} ま せいぜい がんばれよ!\n"
	.string "きにすんなって!\l"
	.string "あばよ!$"

SilphCo_7F_Text_FloorSign::
	.string "{JPN}シルフカンパニー ほんしゃ\n"
	.string "7F$"

