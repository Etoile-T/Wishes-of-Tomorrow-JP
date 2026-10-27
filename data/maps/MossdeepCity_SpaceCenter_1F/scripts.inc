MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	.byte 0

MossdeepCity_SpaceCenter_1F_OnTransition:
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SAILOR, 1, 9
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_WOMAN, 0, 8
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_OLD_MAN, 1, 6
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SPACE_CENTER_1F_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SPACE_CENTER_1F_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 13, 3
	end

@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
	setobjectxyperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, 14, 2
	end

MossdeepCity_SpaceCenter_1F_OnLoad:
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_SPACE_CENTER_1F_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
#ifdef BUGFIX
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#else
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#endif
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	release
	end

@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
	applymovement LOCALID_SPACE_CENTER_1F_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

@ Functionally unused. See above
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
	.string "{JPN}まもなく ロケット はっしゃです!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
	.string "{JPN}ロケットは ぶじ はっしゃ しました!\n"
	.string "これで {ENG}{STR_VAR_1}{JPN}かいめの せいこうです!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
	.string "{JPN}いまは ちょっと たいへんな\n"
	.string "じょうきょう ですが……\p"
	.string "まもなく ロケット はっしゃです!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
	.string "{JPN}いまは ちょっと たいへんな\n"
	.string "じょうきょう ですが……\p"
	.string "ロケットは ぶじ はっしゃ しました!\n"
	.string "これで {ENG}{STR_VAR_1}{JPN}かいめの せいこうです!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
	.string "{JPN}ロケットの はっしゃには かんぺきが ひつよう。\n"
	.string "1パーセントの ミスも ゆるされない。\p"
	.string "99パーセント だいじょうぶでも\n"
	.string "1パーセント ダメなら すべて むだになる。\p"
	.string "それでも わたしたちは あきらめない。\n"
	.string "なぜって? おわらない ゆめ だからさ。$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
	.string "{JPN}マグマだんの ならずものが\n"
	.string "うちゅうセンターを ねらっている。\p"
	.string "だが そんな ささいな ことで\n"
	.string "ロケットの はっしゃを じゃまさせない!$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
	.string "{JPN}はまべを さんぽ していたら\n"
	.string "これを みつけたんだ。\p"
	.string "わたしには ひつよう ないから\n"
	.string "きみに あげるよ。$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
	.string "{JPN}ホウエン ちほうは むかしから\n"
	.string "りゅうせいぐんで ゆうめい なんだ。$"

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
	.string "{JPN}マグマだんに ロケットねんりょうを\n"
	.string "ぬすませる わけには いかない。\p"
	.string "ああ そうだ はまべで ひろった\n"
	.string "この いしを きみに あげよう。$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
	.string "{JPN}マグマだんが うろついてちゃ\n"
	.string "はまべの さんぽも あぶない かな。$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
	.string "{JPN}ポケモンは うちゅうから きたって いう\n"
	.string "ひとも いる。 ほんとう かしら?$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
	.string "{JPN}アクアだんが マグマだんを\n"
	.string "やっつけて くれれば いいのに!\p"
	.string "でも そうしたら こんどは アクアだんが\n"
	.string "ちょうしに のっちゃう わよね?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
	.string "{JPN}おおきな きんぞくの かたまりが\n"
	.string "そらを つきやぶって うちゅうへ とぶ……\p"
	.string "まったく おどろき だよ!$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
	.string "{JPN}おおきな きんぞくの かたまりが\n"
	.string "そらを つきやぶって うちゅうへ とぶ……\p"
	.string "なのに マグマだんは そんな\n"
	.string "ぼくの ゆめを こわそうと している!\p"
	.string "そんなこと させるもんか!$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
	.string "{JPN}ダイゴ: {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN} あの こくちは\n"
	.string "もう よんだかい?\p"
	.string "マグマだんは この しまの\n"
	.string "ロケットねんりょうを ねらっている。\p"
	.string "なにに つかうのか わからないが\n"
	.string "わたす わけには いかない。\p"
	.string "ぼくは もうしばらく\n"
	.string "ようすを みているよ。\p"
	.string "そのあいだ きみは まちを\n"
	.string "みて まわったら どうだい?$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
	.string "{JPN}よこくどおり\n"
	.string "ロケットねんりょうを いただきに きたぞ!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
	.string "{JPN}ねんりょう ぎれ……$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
	.string "{JPN}おれに かったくらいで\n"
	.string "ちょうしに のるなよ!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
	.string "{JPN}ちゃんと よこく しただろ!\n"
	.string "おれたちは こそこそ しないんだ!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
	.string "{JPN}ぐぬぬ……\n"
	.string "こそこそ やれば よかった……$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
	.string "{JPN}わかったよ もう! つぎは\n"
	.string "よこく なしで くるからな。$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
	.string "{JPN}うちゅうセンターに ためてある\n"
	.string "ロケットねんりょう それが ねらいさ。\p"
	.string "ひとしずく のこらず いただくぜ!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
	.string "{JPN}たのむ ねんりょう わけてくれ!\n"
	.string "ちょっぴり でも いいから!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
	.string "{JPN}ロケットねんりょうを なにに\n"
	.string "つかうのか だって?\p"
	.string "おれが しるかよ!\n"
	.string "うえに いる リーダーに きけ!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
	.string "{JPN}リーダーの めいれいだ! だれひとり\n"
	.string "ここは とおさないぞ!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
	.string "{JPN}うっ! うっ! うわあっ!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
	.string "{JPN}たのむ リーダーに つたえてくれ。\n"
	.string "おれは もちばを はなれなかった……\l"
	.string "さいごまで ふみとどまった と……$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
	.string "{JPN}これは……\n"
	.string "はんこう よこくじょう?\p"
	.string "「うちゅうセンターの みなさま\n"
	.string "おげんき ですか? わたしたちは げんきです。\p"
	.string "「ちかいうちに ロケットねんりょうを\n"
	.string "いただきに まいります。\p"
	.string "「じゃまは しないで ください。\n"
	.string "なにが あっても いただきます。\p"
	.string "「りくちに さらなる ひろがりを!\n"
	.string "            マグマだん」$"
