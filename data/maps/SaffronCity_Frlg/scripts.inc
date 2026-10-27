SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_WhatDoYouWantGetLost::
	.string "{JPN}なんだ おまえ?\n"
	.string "とっとと うせろ!$"

SaffronCity_Text_BossTakeTownForTeamRocket::
	.string "{JPN}ボスは この まちを ロケットだんの\n"
	.string "ものに すると いったのさ!$"

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
	.string "{JPN}さからうんじゃ ねえぞ!\n"
	.string "いたい めに あいたく なければな!$"

SaffronCity_Text_SaffronBelongsToTeamRocket::
	.string "{JPN}ヤマブキは ロケットだんの ものだ!$"

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
	.string "{JPN}わるいことを してると\n"
	.string "いきてるって かんじが するぜ!$"

SaffronCity_Text_WatchWhereYoureWalking::
	.string "{JPN}いてっ!\n"
	.string "どこ みて あるいてんだ!$"

SaffronCity_Text_WeCanExploitMonsAroundWorld::
	.string "{JPN}シルフを てに いれれば\n"
	.string "せかいじゅうの ポケモンを りよう できる!\p"
	.string "おれたち だいがねもちだぜ イエーイ!$"

SaffronCity_Text_YouBeatTeamRocket::
	.string "{JPN}ひとりで ロケットだんを やっつけたの?\n"
	.string "すごいわ!$"

SaffronCity_Text_SafeToGoOutAgain::
	.string "{JPN}やった! ロケットだんが いなくなった!\n"
	.string "これで あんしんして そとに でられる!$"

SaffronCity_Text_PeopleComingBackToSaffron::
	.string "{JPN}ロケットだんが きたとき\n"
	.string "おおぜいの ひとが にげだしたんだ。\p"
	.string "これからは みんな ヤマブキに\n"
	.string "もどって くるだろうね。$"

SaffronCity_Text_FlewHereOnPidgeot::
	.string "{JPN}シルフの きじを よんで ピジョットで\n"
	.string "とんで きたんだけど。\p"
	.string "もう おわっちゃったの?\n"
	.string "しゅざいに まにあわなかった…$"

SaffronCity_Text_Pidgeot::
	.string "{JPN}ピジョット: ピピピィー!$"

SaffronCity_Text_SawRocketBossEscaping::
	.string "{JPN}ロケットだんの ボスが シルフの\n"
	.string "ビルから にげていくのを みたよ。$"

SaffronCity_Text_ImASecurityGuard::
	.string "{JPN}わたしは けいびいん です。\p"
	.string "あやしい こどもは いれませんよ!$"

SaffronCity_Text_HesTakingASnooze::
	.string "{JPN}…\n"
	.string "グーグー…\p"
	.string "ははっ! いねむり してるぞ!$"

SaffronCity_Text_CitySign::
	.string "{JPN}ヤマブキシティ\n"
	.string "こがねいろに かがやく しょうぎょうの まち$"

SaffronCity_Text_FightingDojo::
	.string "{JPN}かくとう どうじょう$"

SaffronCity_Text_GymSign::
	.string "{JPN}ヤマブキシティ ポケモンジム\n"
	.string "ジムリーダー: ナツメ\l"
	.string "エスパー ポケモンの つかいて!$"

SaffronCity_Text_FullHealCuresStatus::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "なんでもなおしは やけど まひ\n"
	.string "どく こおり ねむりなど\l"
	.string "すべての じょうたいいじょうを なおす。\p"
	.string "すこし たかいけど ほかの どうぐを\n"
	.string "かうより べんりです。$"

SaffronCity_Text_GreatBallImprovedCatchRate::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "あたらしい スーパーボールは\n"
	.string "つかまえやすさが アップ!\p"
	.string "つかまえにくい ポケモンに\n"
	.string "つかって みましょう。$"

SaffronCity_Text_SilphCoSign::
	.string "{JPN}シルフカンパニー ほんしゃビル$"

SaffronCity_Text_MrPsychicsHouse::
	.string "{JPN}エスパーおやじの いえ$"

SaffronCity_Text_SilphsLatestProduct::
	.string "{JPN}シルフの さいしん しょうひん!\n"
	.string "はつばいび みてい…$"

SaffronCity_Text_TrainerFanClubSign::
	.string "{JPN}ポケモン トレーナー ファンクラブ\p"
	.string "たくさんの トレーナーが\n"
	.string "かんばんに なまえを かきこんでいる。$"

SaffronCity_Text_HowCanClubNotRecognizeLance::
	.string "{JPN}この ファンクラブ…\n"
	.string "だれも わかって ない!\p"
	.string "ワタルの すばらしさに\n"
	.string "なぜ きづかないんだ?\p"
	.string "かれは せいぎの みかた!\n"
	.string "クールで しかも あつい!\l"
	.string "さいこうだ ワタル!$"

