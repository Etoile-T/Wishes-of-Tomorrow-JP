ViridianCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	return

ViridianCity_EventScript_SetOldManStandingByRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_JumpDownLedge::
	jump_2_down
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful::
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful::
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted::
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart::
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

@ Unused
ViridianCity_EventScript_WatchToLearnBasics::
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	release
	end

@ Unused. Starts battle after the post battle text, which is odd.
ViridianCity_EventScript_TutorialUnused::
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	special StartOldManTutorialBattle
	waitstate
	release
	end

ViridianCity_EventScript_TutorialNotReady::
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked::
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	goto EventScript_DreamEaterTutor
	end

ViridianCity_EventScript_RoadBlocked::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown::
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle::
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	closemessage
	special StartOldManTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	giveitem ITEM_TEACHY_TV
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	return

ViridianCity_Text_CanCarryMonsAnywhere::
	.string "{JPN}こしに モンスターボール!\n"
	.string "ポケモンを もってるんだね?\p"
	.string "いつでも どこでも ポケモンを\n"
	.string "つれあるけるって すばらしいよね。$"

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
	.string "{JPN}この ポケモンジムは いつも しまってる。\p"
	.string "リーダーは だれ なんだろう?$"

ViridianCity_Text_ViridiansGymLeaderReturned::
	.string "{JPN}トキワジムの リーダーが もどった!$"

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
	.string "{JPN}2しゅるいの いもむしポケモンの\n"
	.string "ことを しりたいかい?$"

ViridianCity_Text_OhOkayThen::
	.string "{JPN}そう じゃあ いいや!$"

ViridianCity_Text_ExplainCaterpieWeedle::
	.string "{JPN}キャタピーには どくは ないけど\n"
	.string "ビードルには あるんだ。\p"
	.string "ビードルの どくばりに さされない\n"
	.string "ように きを つけてね。$"

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
	.string "{JPN}もう おじいちゃん!\n"
	.string "いじわる しないの!\p"
	.string "ごめんなさいね。\n"
	.string "まだ コーヒーを のんでないのよ。$"

ViridianCity_Text_GoShoppingInPewterOccasionally::
	.string "{JPN}ときどき ニビシティへ\n"
	.string "かいものに いくの。\p"
	.string "そのときは トキワのもりの\n"
	.string "まがりくねった みちを とおるのよ。$"

ViridianCity_Text_ThisIsPrivateProperty::
	.string "{JPN}ここを とおる ことは\n"
	.string "ぜったいに ゆるさん!\p"
	.string "ここは わしの しゆうち じゃ!$"

ViridianCity_Text_ShowYouHowToCatchMons::
	.string "{JPN}さてと コーヒーを のんだし\n"
	.string "これで しゃきっと したわい!\p"
	.string "む?\n"
	.string "その あかい はこは なんじゃ?\p"
	.string "ほう ポケモンずかんを\n"
	.string "つくって おるのか。\p"
	.string "では ひとつ アドバイスを\n"
	.string "してやろう。\p"
	.string "ポケモンを つかまえると\n"
	.string "ポケモンずかんの データが\l"
	.string "じどうで ふえるんじゃ。\p"
	.string "…ポケモンの つかまえかたを\n"
	.string "しらんのか?\p"
	.string "しかたない わしが みせて\n"
	.string "やろう!$"

ViridianCity_Text_ThatWasEducationalTakeThis::
	.string "{JPN}どうじゃ! べんきょうに\n"
	.string "なったじゃろう?\p"
	.string "それと これも もっていけ。$"

ViridianCity_Text_WatchThatToLearnBasics::
	.string "{JPN}わからない ことが あったら\n"
	.string "それを みると いい。\p"
	.string "ポケモントレーナーの きほんを\n"
	.string "おしえて くれるぞ。$"

ViridianCity_Text_WeakenMonsFirstToCatch::
	.string "{JPN}さてと コーヒーを のんだし\n"
	.string "これで しゃきっと したわい!\p"
	.string "じゃが こく いれすぎて\n"
	.string "あたまが いたく なった…\p"
	.string "ところで ポケモンずかんは\n"
	.string "うまって おるか?\p"
	.string "まずは ポケモンを よわらせてから\n"
	.string "つかまえる ことを こころがけよ。$"

ViridianCity_Text_HowsTeachyTVHelping::
	.string "{JPN}さてと コーヒーを のんだし\n"
	.string "これで しゃきっと したわい!\p"
	.string "じゃが こく いれすぎて\n"
	.string "あたまが いたく なった…\p"
	.string "ところで わしの おさがりの\n"
	.string "おしえテレビは やくに たっとるか?$"

ViridianCity_Text_MyGrandsonOnTheShow::
	.string "{JPN}わはは!\n"
	.string "ばんぐみに でとるのは わしの まごじゃ!\p"
	.string "あいつが おしえとるんじゃから\n"
	.string "しっかり まなべる はずじゃ。$"

ViridianCity_Text_TooBusyForTeachyTV::
	.string "{JPN}む… おしえテレビを みる じかんも\n"
	.string "ない ほど いそがしいのか…\p"
	.string "ときは かねなり。 どちらも\n"
	.string "むだに つかっては ならんぞ…$"

ViridianCity_Text_CitySign::
	.string "{JPN}トキワシティ\n"
	.string "トキワは みどり えいえんの いろ$"

ViridianCity_Text_CatchMonsForEasierBattles::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "ポケモンを つかまえて\n"
	.string "なかまを ふやそう!\p"
	.string "おおければ おおいほど\n"
	.string "たたかいが らくに なるぞ!$"

ViridianCity_Text_MovesLimitedByPP::
	.string "{JPN}おとくな けいじばん!!\p"
	.string "ポケモンの わざは わざポイント\n"
	.string "つまり PPの ぶんしか つかえない。\p"
	.string "PPを かいふく するには\n"
	.string "ポケモンセンターで やすませよう!$"

ViridianCity_Text_GymSign::
	.string "{JPN}トキワシティ ポケモンジム$"

ViridianCity_Text_GymDoorsAreLocked::
	.string "{JPN}トキワジムの ドアは しまっている…$"

