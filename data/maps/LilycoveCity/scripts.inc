LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "{JPN}ハルカ: あら?\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}も おかいもの?\p"
	.string "あたしは ぬいぐるみや ポスターを\n"
	.string "いっぱい かっちゃった。\p"
	.string "もちろん ポケモンも たくさん\n"
	.string "つかまえて ちゃんと\l"
	.string "そだててるわよ。\p"
	.string "むしろ ちゃんと そだててるか\n"
	.string "しんぱいなのは {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}の ほうよ。\p"
	.string "しょうぶして ポケモンを みせてよ\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "{JPN}ハルカ: どうして? {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}は\n"
	.string "ポケモンを そだてて ないの?\p"
	.string "トレーナーとして それじゃ\n"
	.string "あんまり かっこよく ないわね…$"

LilycoveCity_Text_MayBattleMe:
	.string "{JPN}ハルカ: ねえ しょうぶして\n"
	.string "あなたの ポケモンを みせてよ!$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "{JPN}ハルカ: あたしが そだてた ポケモンは\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}の ポケモンには まけないわ!$"

LilycoveCity_Text_MayDefeat:
	.string "{JPN}… … … … … … … …\p"
	.string "あなたと しょうぶしたこと おぼえてるよ。\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}と 103ばんどうろでね。\p"
	.string "あの しょうぶが あったから\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}は こんなに つよく なれたのね?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "{JPN}ハルカ: あたし そろそろ\n"
	.string "ミシロタウンに かえる つもりなの\p"
	.string "いろいろ ポケモン つかまえて\n"
	.string "ずかんも けっこう できてきたから\l"
	.string "おとうさんに みせるんだ!$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{JPN}{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}は これから どうするの?\p"
	.string "ジムバッジを ぜんぶ あつめて\n"
	.string "ポケモンリーグに ちょうせんするの?\p"
	.string "バッジを あつめている あいだに\n"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}より さきに\l"
	.string "あたしは ずかんを かんせいさせるわ!\p"
	.string "それじゃ またね!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{JPN}{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}は これから どうするの?\p"
	.string "ポケモンリーグに\n"
	.string "ちょうせんするの?\p"
	.string "それとも ポケモンずかんを\n"
	.string "かんせいさせるの?\p"
	.string "しょうぶでは まけちゃったけど\n"
	.string "ずかんは あたしが さきに かんせいよ!\p"
	.string "それじゃ またね!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{JPN}{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}は これから どうするの?\p"
	.string "バトルフロンティアに\n"
	.string "ちょうせんするの?\p"
	.string "それとも ポケモンずかんを\n"
	.string "かんせいさせるの?\p"
	.string "しょうぶでは まけちゃったけど\n"
	.string "ずかんは あたしが さきに かんせいよ!\p"
	.string "それじゃ またね!$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "{JPN}ユウキ: おっ {ENG}{PLAYER}{JPN}か。\p"
	.string "とうさんの おつかいで きたんだよ。\n"
	.string "あ ぬいぐるみを かうんじゃ ないからな。\p"
	.string "それは そうと ひさしぶりだな。\p"
	.string "どっちが ポケモンを よく そだてたか\n"
	.string "しょうぶして たしかめようぜ?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "{JPN}ユウキ: なんだよ\n"
	.string "じしんが ないのかよ。$"

LilycoveCity_Text_BrendanBattleMe:
	.string "{JPN}ユウキ: どっちが ポケモンを よく\n"
	.string "そだてたか しょうぶで たしかめようぜ?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "{JPN}ユウキ: まあ オレが\n"
	.string "{ENG}{PLAYER}{JPN}に まけるわけ ないんだけど。$"

LilycoveCity_Text_BrendanDefeat:
	.string "{JPN}ふん…\n"
	.string "ずいぶん そだてたんだな。\p"
	.string "ちょっと くやしいな。オレのほうが\n"
	.string "トレーナーとして さきに はじめたのに…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "{JPN}ユウキ: オレ……\n"
	.string "ミシロタウンに もどるつもり なんだ\p"
	.string "とうさんの てつだいで つくっている\n"
	.string "ポケモンずかんも けっこう できてきたし\l"
	.string "いちど とうさんに みせておかないと。$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{JPN}{ENG}{PLAYER}{JPN}は これから どうするんだ?\p"
	.string "ジムバッジを ぜんぶ あつめて\n"
	.string "ポケモンリーグに ちょうせんするのか?\p"
	.string "オレも そうしようかな…\p"
	.string "まあ とにかく がんばれよ!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{JPN}{ENG}{PLAYER}{JPN}は これから どうするんだ?\p"
	.string "それだけ つよいなら\n"
	.string "ポケモンリーグに ちょうせんするのか?\p"
	.string "へっ オレだって もうすこし\n"
	.string "ポケモンを きたえれば おまえより\l"
	.string "つよく なれるはずだぜ {ENG}{PLAYER}{JPN}。\p"
	.string "まあ とにかく がんばれよ!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{JPN}{ENG}{PLAYER}{JPN}は これから どうするんだ?\p"
	.string "バトルフロンティアに\n"
	.string "ちょうせんするのか?\p"
	.string "それとも ポケモンずかんを\n"
	.string "かんせいさせるのか?\p"
	.string "それだけ つよいなら\n"
	.string "バトルフロンティアも かんがえてみなよ。\p"
	.string "へっ オレも もうすこし きたえれば\n"
	.string "おまえより つよくなるぜ {ENG}{PLAYER}{JPN}。\p"
	.string "オレも バトルフロンティアに\n"
	.string "いってみようかな。\p"
	.string "まあ とにかく がんばれよ!$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "{JPN}ふふふ……\p"
	.string "きょうも うばった ブツを\n"
	.string "アジトに はこびこんだぞ……\p"
	.string "なっ なんだ おまえ!\n"
	.string "いっ いまのは ひとりごと だぞ!$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "{JPN}リーダーが なに かんがえてるのか\n"
	.string "したっぱの オレには わからんが\p"
	.string "アクアだんに いると\n"
	.string "おおきなことを やる チャンスが くる!\p"
	.string "なっ なんだ おまえ!\n"
	.string "いっ いまのは ひとりごと だぞ!$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "{JPN}おい おまえ!\p"
	.string "いりえの どうくつには ちかづくな!\p"
	.string "なぜだって? りゆうなんて いらん!\n"
	.string "おとなの いうことを おとなしく きけ!$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "{JPN}この ひろい せかい すべてが\n"
	.string "おれら アクアだんの ものに なったら\l"
	.string "ポケモンも もっと しあわせに なれる!$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "{JPN}それっ! ホエルコ!\n"
	.string "そこで すいめんから ジャンプするのだ!$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "{JPN}……ん? なんだ おまえは?\p"
	.string "トレーニングの じゃまに なるから\n"
	.string "あっちに いっててくれ!$"

LilycoveCity_Text_ContestHallInTown:
	.string "{JPN}この まちに ポケモンコンテストの\n"
	.string "かいじょうが あるんだな!\p"
	.string "ぜんこくから よく そだった ポケモンが\n"
	.string "ここに あつまってくるんだな!\p"
	.string "わしの ハートは わくわく なんだな!$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "{JPN}まちの はずれの いりえに\n"
	.string "おかしな どうくつが あるの みた?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "{JPN}コンテストに でるために\n"
	.string "ポケモンに あたらしい わざを おしえるの。\p"
	.string "だから わすれオヤジの ところで\n"
	.string "ひでんわざを わすれさせてくるわ。$"

LilycoveCity_Text_ImFromKanto:
	.string "{JPN}カントーから きました!\p"
	.string "ホウエン ちほうは みずと みどりに\n"
	.string "あふれた うつくしい ところ ですね!\p"
	.string "……ん? ということは?\p"
	.string "この とち だけに せいそくする\n"
	.string "めずらしい ポケモンが いるのかも?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "{JPN}アクアだんが いりえで\n"
	.string "ホエルコを くんれんしているんだ。\p"
	.string "あいつらが じゃまで われわれ ふなのりは\n"
	.string "ふねを うみに だせないんだよ!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "{JPN}あんた しってるかい?\p"
	.string "だれかが アクアだんを\n"
	.string "けちらして くれたんだ!\p"
	.string "おかげで ホエルコ いなくなって\n"
	.string "うみに でられるように なったよ!$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "{JPN}うみべの やどで なみの おとを きいて\n"
	.string "のんびり いねむりしてたら…\p"
	.string "だれかに ポケモンを ぬすまれたの!\p"
	.string "だれが さらったの?\n"
	.string "アクアだん? アクアだんなの?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "{JPN}いなくなってた わたしの ポケモン\n"
	.string "いつのまにか かえってきたの!$"

LilycoveCity_Text_ImArtDealer:
	.string "{JPN}わたしは がしょうです。\p"
	.string "びじゅつひん とくに えを\n"
	.string "かったり うったり しています。\p"
	.string "この びじゅつかんには すばらしい さくひんが\n"
	.string "てんじして あると ききました…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "{JPN}わしらが しわくちゃに なっても\n"
	.string "このうみは いつまでも わかわかしく\l"
	.string "いのちの かがやきに あふれとる\p"
	.string "ふほほ ふほほほほ……$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "{JPN}60ねんまえ ここで おじいしゃんが\n"
	.string "わしに プロポーズ してくれた ときから\l"
	.string "このうみは うつくしいまま ですのじゃ\p"
	.string "むふふ むふふふふ……$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "{JPN}あの いりえの かわった どうくつを\n"
	.string "しっているかね?\p"
	.string "もともと しぜんに できたものだが\n"
	.string "アクアだんの やつらが やってきて\l"
	.string "かいぞうして しまったんだ。\p"
	.string "「しぜんを あいする アクアだん」と\n"
	.string "なのっている くせにね!\p"
	.string "やることと いうことが\n"
	.string "まるで ちがっているじゃないか!$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "{JPN}いりえの あの どうくつ…\p"
	.string "すぐには きづかなかったが\n"
	.string "いまでは もぬけの からだ。\p"
	.string "アクアだんの やつらも\n"
	.string "もう かえってこない つもりなんだろう。$"

LilycoveCity_Text_CitySign:
	.string "{JPN}ミナモシティ\p"
	.string "りくが おわり\n"
	.string "うみが はじまる ところ。$"

LilycoveCity_Text_ContestHallSign:
	.string "{JPN}ポケモンコンテスト かいじょう\n"
	.string "あつまれ! ポケモン トレーナー。$"

LilycoveCity_Text_MotelSign:
	.string "{JPN}みんしゅく モナミ\p"
	.string "ミナモの モナミと\n"
	.string "おぼえてください。$"

LilycoveCity_Text_MuseumSign:
	.string "{JPN}ミナモびじゅつかん\p"
	.string "ポケモンの めいさく コレクションを\n"
	.string "てんじちゅう!$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "{JPN}「ミナモ びじゅつかん」\p"
	.string "{ENG}{PLAYER}{JPN}の ポケモン コレクション\n"
	.string "かいさい ちゅう!$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "{JPN}ミナモシティ ふねのりば\p"
	.string "れんらくせん タイドリップごうは\n"
	.string "カイナシティで けんぞうちゅうです。\p"
	.string "まもなく うんこうを はじめる\n"
	.string "よていです。$"

LilycoveCity_Text_HarborSign:
	.string "{JPN}「ミナモ シティ ふねのりば」\p"
	.string "れんらくせん タイドリップごうで\n"
	.string "ふねの たびを おたのしみ ください!$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "{JPN}「ポケモン トレーナー ファンクラブ」\p"
	.string "かんばんに いろんな トレーナーの\n"
	.string "なまえが らくがき されている……$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "{JPN}ミナモデパート\p"
	.string "すてきな しなものと わくわくが\n"
	.string "あふれています!\p"
	.string "あなたの ほしいものが\n"
	.string "みつかる おみせです!$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "{JPN}わすれオヤジの いえ\p"
	.string "いらない ポケモンの わざ わすれさせます。$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "{JPN}きのみブレンダー っていう\n"
	.string "マシンを しってるかい?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "{JPN}みんなで ちからを あわせると\n"
	.string "はやく まわせるんだ。\p"
	.string "はやく まわせるほど いい ポロックが\n"
	.string "できるって きいたよ。$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "{JPN}ポロックっていう おかしを\n"
	.string "つくるための ものだよ。\p"
	.string "いい ポロックを ポケモンに あげると\n"
	.string "コンディションが ぐんと よくなるんだ。$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "{JPN}どこかの すいどうに とうが あるって\n"
	.string "きいたの。\p"
	.string "そらのはしら っていうらしいわ。$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "{JPN}131ばんすいどうの あたりで\n"
	.string "たかい とうを みたんだ。\p"
	.string "もしかして あれが…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "{JPN}しんこんりょこうで\n"
	.string "ついた ばかりなんだ。\p"
	.string "たまたま そらの たかい ところを とぶ\n"
	.string "ドラゴンタイプの ポケモンを みたよ。\p"
	.string "ホウエンには あんな かっこいい\n"
	.string "ポケモンが すんでるのかい?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "{JPN}しんこんりょこうでは めずらしい ポケモンを\n"
	.string "できるだけ たくさん みようと ちかったの。\p"
	.string "だから ついて すぐに めずらしい\n"
	.string "ポケモンを みられて うれしかったわ。\p"
	.string "もう ほんとうに しあわせ!$"

