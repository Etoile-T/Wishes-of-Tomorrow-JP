MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	end

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MOSSDEEP_MAXIE
	removeobject LOCALID_MOSSDEEP_GRUNT_1
	removeobject LOCALID_MOSSDEEP_GRUNT_2
	removeobject LOCALID_MOSSDEEP_GRUNT_3
	removeobject LOCALID_MOSSDEEP_GRUNT_4
	delay 30
	setvar VAR_MOSSDEEP_CITY_STATE, 2
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_MOSSDEEP_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "{JPN}これ…… ダイゴさんに もらったけど\n"
	.string "なんに つかうのか わかんないや。\p"
	.string "おうじゃのしるし って いうらしいけど\n"
	.string "おまえ ほしい?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "{JPN}これが ほしいなんて\n"
	.string "おまえ かわってるな。\p"
	.string "やるけど そのかわり\n"
	.string "ダイゴさんには ないしょ だぜ。$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "{JPN}ダイゴさんの いえなら すぐそこだよ!$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "{JPN}だよな! おまえも そうおもうだろ!\n"
	.string "へんてこな いし もらっても こまるよな!$"

MossdeepCity_Text_WailmerWatching:
	.string "{JPN}この トクサネの まわりでは\n"
	.string "やせいの ホエルコが みられるんだ。\p"
	.string "そーいうのを えーと……\n"
	.string "なんて いったっけ かな……\p"
	.string "ホエ ホエ ホエ……\p"
	.string "ホエルコ ウオッチング だ!$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "{JPN}しまの うちゅうセンター では\n"
	.string "おっきな ロケットを とばしとるのよ。\p"
	.string "さいきん とどいた てがみの ことで\n"
	.string "なにやら おおさわぎ らしいわ。$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "{JPN}しまの うちゅうセンター では\n"
	.string "すんごい ロケット とばしとるのよ!$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "{JPN}ふなのり なかまに きいたんだが\n"
	.string "アクアだんが ミナモに いすわってたらしい。\p"
	.string "しかも だれかが やってきて\n"
	.string "あいつらを こてんぱんに したんだと!\p"
	.string "だが ここ トクサネは\n"
	.string "あの マグマだんに ねらわれてる。\p"
	.string "やつらの もくてきが しりたいなら\n"
	.string "うちゅうセンターに いってみな。$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "{JPN}おれは ふなのり だから\n"
	.string "やっぱり うみのほうが だいじさ。\p"
	.string "でも ながい こうかいの あとで\n"
	.string "りくに あがると ホッと するんだよな!$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "{JPN}すてきだと おもわない?\p"
	.string "せかいじゅうが この しまみたいに\n"
	.string "くさばなで いっぱいに なったら!$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "{JPN}いのちは りくで くらしていても\n"
	.string "うみが なければ いきられない。\p"
	.string "やくめを おえた いのちは\n"
	.string "つちと なって だいちに かえる。\p"
	.string "そして うみと だいちは\n"
	.string "いつでも つながって いる……\p"
	.string "そう この かいがんせんの ようにな。$"

MossdeepCity_Text_SurfExhilarating:
	.string "{JPN}ふねの たびも わるくない。\p"
	.string "だが ポケモンの なみのりで\n"
	.string "うみを わたるのは……\p"
	.string "じつに そうかいな たびじゃ!\n"
	.string "そう おもわんかね わかいの?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "{JPN}この いわは うちゅうセンターの\n"
	.string "ひとたちに とって とくべつなの。\p"
	.string "ロケットが ぶじに とぶように\n"
	.string "ねがいを こめて ここに おいたのよ。\p"
	.string "あなたは ねがいごとを するとき なにを つかう?\n"
	.string "おほしさまに ねがう?\p"
	.string "わたしは ねがいの ふだを つかうの。\n"
	.string "それが わたしの やりかた。$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "{JPN}しろい いわ だ。$"

MossdeepCity_Text_GymSign:
	.string "{JPN}トクサネ シティ ポケモンジム\n"
	.string "リーダー ラン & フウ\p"
	.string "「しんぴの コンビネーション!」$"

MossdeepCity_Text_CitySign:
	.string "{JPN}ここは トクサネ シティ\n"
	.string "「ポケモンを たいせつに!」が あいことば$"

MossdeepCity_Text_SpaceCenterSign:
	.string "{JPN}トクサネ うちゅうセンター\n"
	.string "「うちゅうに いちばん ちかい ばしょ」$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "{JPN}エニシダ: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} げんきかい?\n"
	.string "ぼくは げんき いっぱいさ!\p"
	.string "トクサネの ジムリーダーが\n"
	.string "かなり つよいと きいてね\l"
	.string "じぶんの めで みに きたんだよ。\p"
	.string "でも この まちは\n"
	.string "なんだか ようすが へんだね。\p"
	.string "みんな よこくじょう だの\n"
	.string "うちゅうセンター だの さわいでる……\p"
	.string "まあ ぼくには まったく\n"
	.string "かんけい ない はなし だけどね。$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "{JPN}あー なみが あしを あらって\n"
	.string "きもちが いい……\p"
	.string "なみ と いえば ほら\n"
	.string "しまの まち ルネシティ あるでしょ?\p"
	.string "あそこの ジムに あたらしい\n"
	.string "リーダーが きた らしいね。\p"
	.string "なんでも その リーダーって\n"
	.string "ミクリの おししょうさん だとか……$"

