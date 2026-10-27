RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "{JPN}わしが デボン コーポレーションの\n"
	.string "しゃちょう ツワブキ だ\p"
	.string "きみの ことは ちょうど きいたところだ!\p"
	.string "うちの しゃいんを いちど ならず\n"
	.string "にども たすけて くれたそうだね!\p"
	.string "そんな すばらしい きみに\n"
	.string "たのみたい ことが あるのだ\p"
	.string "きみは カイナの ぞうせんじょへ\n"
	.string "にもつを とどけて くれるそうだね\p"
	.string "では その とちゅうで\n"
	.string "ムロタウンに よって もらえないか?\p"
	.string "ムロに いる ダイゴに\n"
	.string "てがみを とどけて ほしいのだ$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "{JPN}ツワブキ: もちろん わしは\n"
	.string "すごーい しゃちょうで あるからな!\p"
	.string "ただで おねがいすると いうような\n"
	.string "ケチな まねは しないのだ!\p"
	.string "だから きみに こいつを プレゼントしよう!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{JPN}{ENG}{PLAYER}{JPN}は ポケナビを もらった!$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "{JPN}ツワブキ: その どうぐは……\p"
	.string "ポケモン ナビゲーター\n"
	.string "りゃくして ポケナビだ\p"
	.string "ぼうけんする トレーナーには\n"
	.string "かかせない どうぐだよ\p"
	.string "ホウエンちほうの マップが はいっている\p"
	.string "ムロや カイナの ばしょも\n"
	.string "かんたんに しらべられるぞ!\p"
	.string "ところで わるい やつら……\n"
	.string "たしか マグマだんと アクアだん だったか……\l"
	.string "あちこちで さわぎを おこしているそうだ\p"
	.string "でかける まえに\n"
	.string "しっかり やすんで おくと いいだろう$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "{JPN}ツワブキ: それでは {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}\n"
	.string "じゅうぶん きをつけて いくのだよ!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "{JPN}ツワブキ: よろしく たのむよ!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "{JPN}ツワブキ: てがみを とどけて くれたのか\n"
	.string "いやいや ありがとう!\p"
	.string "こいつは おれい だよ\n"
	.string "トレーナーの きみに やくだつ はずだ!$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "{JPN}ツワブキ: その がくしゅうそうちを\n"
	.string "もった ポケモンは せんとうの\l"
	.string "けいけんちを すこし もらえるのだ\p"
	.string "じっさいに たたかって いなくても\n"
	.string "けいけんちが もらえるんだよ\p"
	.string "よわい ポケモンを そだてるのに\n"
	.string "がくしゅうそうちは なかなか べんりだぞ$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "{JPN}ツワブキ: わかい ころから\n"
	.string "しごと ひとすじ だったからな\p"
	.string "そのせいで はやり などには\n"
	.string "うといのだよ\p"
	.string "いまの わかものは みんな ポケモンリーグの\n"
	.string "トレーナーに なりたいのかね?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "{JPN}ここは デボン コーポレーションの\n"
	.string "3がい です\p"
	.string "この フロアに\n"
	.string "しゃちょうしつが あります\p"
	.string "とにかく きみには\n"
	.string "かんしゃ しても しきれないよ\p"
	.string "えーと…… ところで とりかえして\n"
	.string "くれた あの にもつ なんだけど……\p"
	.string "それを カイナの ぞうせんじょまで\n"
	.string "とどけて もらえないかな?\p"
	.string "また あの どろぼうたちに\n"
	.string "ねらわれたら たいへんだからね\p"
	.string "えー…… へへへ それで……\n"
	.string "おねがい しても いいかな?\p"
	.string "あっ そうだ\n"
	.string "ちょっと ここで まっててくれる?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "{JPN}しゃちょうが ぜひ\n"
	.string "おはなし したいそうです\p"
	.string "わたしに ついて きてください$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "{JPN}ささ どうぞ!$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "{JPN}カイナの ぞうせんじょに いったら\n"
	.string "クスノキかんちょうに あうと いいよ$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "{JPN}デボンの しんせいひん\n"
	.string "リピートボールと タイマーボールは\l"
	.string "トレーナーに だいにんき なのよね!$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "{JPN}しゃちょうが あつめた\n"
	.string "めずらしい いしが かざってある!$"

