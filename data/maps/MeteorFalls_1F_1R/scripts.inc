MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_METEOR_FALLS_ARCHIE
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_METEOR_FALLS_ARCHIE
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "{JPN}ウヒョヒョ……!\p"
	.string "この いんせきが あれば\n"
	.string "えんとつやまの アイツが……$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "{JPN}ウヒョ?\p"
	.string "だれだか しらないが\n"
	.string "マグマだんの ジャマを するきなら\l"
	.string "ようしゃ しないぜ!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "{JPN}まてっ! マグマだん!\p"
	.string "せかいを おまえらの おもいどおりに\n"
	.string "できるなんて おおまちがいだ!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "{JPN}ウヒョヒョ!\n"
	.string "アクアだん まで おでましか!\p"
	.string "だが おまえら ぜんいんの あいては\n"
	.string "めんどう だぜ……\p"
	.string "ヘッ まあ いいさ!\p"
	.string "いんせきは てにいれた! さあ\n"
	.string "えんとつやまへ いくぞ!\p"
	.string "ウヒョヒョ! あばよ\n"
	.string "アクアだんの マヌケども!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "{JPN}アオギリ: おまえ まえにも あったな?\n"
	.string "カイナの はくぶつかんで。\p"
	.string "ほう {ENG}{PLAYER}{JPN} というのか。\p"
	.string "あのときは おまえを マグマだんの\n"
	.string "てしたかと おもったが。\p"
	.string "ふん……\n"
	.string "かわった ガキだ。\p"
	.string "マグマだんは きけんな\n"
	.string "ねっきょう しゃ どもの あつまりだ。\p"
	.string "りくちを ひろげる などと いって\n"
	.string "はかいを くりかえしている。\p"
	.string "やつらは うみを あいする おれたち\n"
	.string "アクアだんの ライバルなのだ!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "{JPN}アオギリさま\n"
	.string "マグマだんを おいかけないと……$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "{JPN}アオギリ: うむ そうだな!\n"
	.string "いそぐぞ。\p"
	.string "マグマだんが えんとつやまで なにを\n"
	.string "しでかすか わからん!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "{JPN}アオギリ: {ENG}{PLAYER}{JPN} おまえも\n"
	.string "マグマだんには ようじん するんだな。\p"
	.string "では さらばだ!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "{JPN}ぼ ぼくは ソライシ……\n"
	.string "はかせ です……\p"
	.string "マグマだんに りゅうせいのたき まで\n"
	.string "あんない してくれと たのまれて……\p"
	.string "でも だまされたんだ。\n"
	.string "いんせきまで とられて しまって……\p"
	.string "そしたら にたような れんちゅう\n"
	.string "アクアだんが あらわれて。\p"
	.string "それから……\n"
	.string "もう なにが なんだか わからないよ。\p"
	.string "でも あの マグマだん……\p"
	.string "えんとつやまで あの いんせきを\n"
	.string "どうする つもり なんだろう?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "{JPN}ソライシはかせ: でも あの マグマだん……\p"
	.string "えんとつやまで あの いんせきを\n"
	.string "どうする つもり なんだろう?$"
