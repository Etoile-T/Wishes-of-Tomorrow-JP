SaffronCity_PokemonTrainerFanClub_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_PokemonTrainerFanClub_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonTrainerFanClub_OnTransition
	.byte 0

SaffronCity_PokemonTrainerFanClub_OnFrame::
	map_script_2 VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans
	.2byte 0

SaffronCity_PokemonTrainerFanClub_EventScript_MeetFirstFans::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, Common_Movement_Delay48
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HuhYou
	closemessage
	applymovement LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow
	setvar VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2
	releaseall
	end

SaffronCity_PokemonTrainerFanClub_Movement_FanApproachPlayer::
	delay_16
	delay_8
	walk_down
	delay_16
	walk_down
	delay_8
	walk_left
	step_end

SaffronCity_PokemonTrainerFanClub_OnTransition::
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 1, SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 2, SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions
	end

SaffronCity_PokemonTrainerFanClub_EventScript_UpdateFanMemberPositions::
	special Script_TryLoseFansFromPlayTime
	setvar VAR_0x8004, FANCLUB_MEMBER1
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER2
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER3
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER4
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER5
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER6
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER7
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	setvar VAR_0x8004, FANCLUB_MEMBER8
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	call_if_eq VAR_RESULT, FALSE, SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember1ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, 5, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BATTLE_GIRL, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember2ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, 7, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_YOUNGSTER, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember3ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, 2, 2
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_GENTLEMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, 3, 4
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL, MOVEMENT_TYPE_FACE_RIGHT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_ROCKER, 4, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_ROCKER, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_WOMAN, 10, 3
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_WOMAN, MOVEMENT_TYPE_FACE_UP
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BEAUTY, 7, 5
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BEAUTY, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable::
	setobjectxyperm LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, 9, 6
	setobjectmovementtype LOCALID_TRAINER_FAN_CLUB_BLACK_BELT, MOVEMENT_TYPE_FACE_LEFT
	return

SaffronCity_PokemonTrainerFanClub_EventScript_SetMemberPosForFirstMeeting::
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember4ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember5ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember6ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember7ToFarTable
	call SaffronCity_PokemonTrainerFanClub_EventScript_MoveMember8ToFarTable
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER1
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BattleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirl::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER4
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_LittleGirlPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Youngster::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER2
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_YoungsterPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Gentleman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER3
	special Script_BufferFanClubTrainerName
	goto_if_eq VAR_MAP_SCENE_SAFFRON_CITY_POKEMON_TRAINER_FAN_CLUB, 0, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_GentlemanPlayerNotChampion::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Woman::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER6
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_WomanOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Rocker::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER5
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_RockerOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_Beauty::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER7
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BeautyOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBelt::
	lock
	faceplayer
	setvar VAR_0x8004, FANCLUB_MEMBER8
	special Script_BufferFanClubTrainerName
	specialvar VAR_RESULT, Script_IsFanClubMemberFanOfPlayer
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltPlayersFan::
	specialvar VAR_RESULT, Script_GetNumFansOfPlayerInTrainerFanClub
	goto_if_eq VAR_RESULT, 1, SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan
	msgbox SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan
	release
	end

SaffronCity_PokemonTrainerFanClub_EventScript_BlackBeltOnlyNonFan::
	msgbox SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster
	release
	end

SaffronCity_PokemonTrainerFanClub_Text_HuhYou::
	.string "{JPN}あれ?\n"
	.string "きみは…$"

SaffronCity_PokemonTrainerFanClub_Text_YourePlayerWereYourFansNow::
	.string "{JPN}もしかして…\n"
	.string "… …\p"
	.string "やっぱり!\n"
	.string "{ENG}{PLAYER}{JPN}だ!\p"
	.string "ちょうど きみの はなしを してたんだ!\p"
	.string "すごく つよい トレーナーが\n"
	.string "あらわれたって はなしてたんだ。\p"
	.string "それが きみ なんだ!\n"
	.string "かっこいい!\p"
	.string "だから みんなで きみの\n"
	.string "ファンクラブに なることに したんだ!\p"
	.string "これからも バトルを つづけて\n"
	.string "かっこいい ところを みせてね!\p"
	.string "そうすれば ほかの ひとも\n"
	.string "わたしみたいに ファンに なるかも!$"

SaffronCity_PokemonTrainerFanClub_Text_AlwaysCheerForYou::
	.string "{JPN}いつでも おうえん してるよ!\p"
	.string "がんばれ {ENG}{PLAYER}{JPN}!$"

SaffronCity_PokemonTrainerFanClub_Text_IllAlwaysBelieveInYou::
	.string "{JPN}わたしは ずっと\n"
	.string "{ENG}{PLAYER}{JPN}を しんじてるよ。\p"
	.string "ほんきで バトルする きみの\n"
	.string "すがたを みんなに みせてあげて!$"

SaffronCity_PokemonTrainerFanClub_Text_WasYourFanNotAnymore::
	.string "{JPN}ごめんなさい。\n"
	.string "まえは きみの ファンだったの。\p"
	.string "でも いまの きみは まえみたいな\n"
	.string "いきおいが なくなったみたい。\p"
	.string "さいきんは {ENG}{STR_VAR_1}{JPN}の ほうが\n"
	.string "ずっと かっこいいと おもうな。$"

SaffronCity_PokemonTrainerFanClub_Text_EveryonesYourFanButICantBe::
	.string "{JPN}あっ!\n"
	.string "{ENG}{PLAYER}{JPN}!\p"
	.string "さいきん みんな きみに\n"
	.string "むちゅう なんだよね。\p"
	.string "その きもちも わかる。\n"
	.string "きみが つよいのは しってるよ。\p"
	.string "でもね…\p"
	.string "いちど {ENG}{STR_VAR_1}{JPN}の ファンに\n"
	.string "なったら かんたんには やめられないの。$"

SaffronCity_PokemonTrainerFanClub_Text_TrainersCoolWhenBattling::
	.string "{JPN}バトルしてる ときの トレーナーって\n"
	.string "ほんとうに かっこいいよね。\p"
	.string "きみも そう おもわない?$"

SaffronCity_PokemonTrainerFanClub_Text_CanYouAutographShorts::
	.string "{JPN}おっ! {ENG}{PLAYER}{JPN}だ!\n"
	.string "かっこよすぎ!\p"
	.string "あっ!\n"
	.string "そうだ!\p"
	.string "なにか サイン してくれない?\n"
	.string "ぼくの たんパンに とか どう?$"

SaffronCity_PokemonTrainerFanClub_Text_CountingOnYou::
	.string "{JPN}どんなに あつい ひも…\p"
	.string "どんなに さむい ひも…\p"
	.string "ぼくは たんパンを しんじて\n"
	.string "はきつづけてきた!\p"
	.string "これからも かちつづけて\n"
	.string "くれよな!\p"
	.string "たんパンと おなじくらい\n"
	.string "きみの ことを しんじてるぞ!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksMyHero::
	.string "{JPN}タケシは ぼくの ヒーロー!\n"
	.string "おとこの なかの おとこだ!\p"
	.string "へへっ ママに あることを\n"
	.string "たのんだんだ。\p"
	.string "ぼくの たんパンに 「タケシ」って\n"
	.string "ししゅう してもらったんだ!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksFanToBitterEnd::
	.string "{JPN}…  …\p"
	.string "…  …\n"
	.string "ぼくは タケシの ファンだ!\p"
	.string "たとえ ファンが ぼく ひとりでも\n"
	.string "いわのように かたい いしと\l"
	.string "この たんパンに かけて ちかう!\p"
	.string "さいごまで タケシの ファンで いるぞ!$"

SaffronCity_PokemonTrainerFanClub_Text_BrocksLastWordOnCool::
	.string "{JPN}かっこよさで いえば タケシが\n"
	.string "いちばん! それで おしまい!\p"
	.string "ぼくも ああいう おとこに\n"
	.string "なりたいんだ!$"

SaffronCity_PokemonTrainerFanClub_Text_HadPleasureOfWatchingYouBattle::
	.string "{JPN}{ENG}{PLAYER}{JPN}さんの バトルを\n"
	.string "はいけん させて もらいましたよ。\p"
	.string "とおい むかしの わかかりし ひびを\n"
	.string "なつかしく おもいだしました。\p"
	.string "これからも ごかつやくを。\n"
	.string "わたしも あなたの ファンですぞ!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverSeenTrainerOfYourMagnificence::
	.string "{JPN}わしは せかいじゅうを\n"
	.string "たびして きた。\p"
	.string "だが きみほど すばらしい\n"
	.string "トレーナーは みたことが ない。\p"
	.string "じぶんの ちからに じしんを もって\n"
	.string "バトルを つづけるのじゃ!\p"
	.string "わしと やくそく してくれ\n"
	.string "わかき アイドルよ!$"

SaffronCity_PokemonTrainerFanClub_Text_HmmAndYouAre::
	.string "{JPN}ふむ…\n"
	.string "きみは?\p"
	.string "わたしたちの ファンクラブに\n"
	.string "にゅうかい したいのかね?$"

SaffronCity_PokemonTrainerFanClub_Text_YouveStillAWaysToGo::
	.string "{JPN}ほう きみが うわさの\n"
	.string "{ENG}{PLAYER}{JPN}か。\p"
	.string "たしかに しょうしゃの\n"
	.string "かおつきを しておる。\p"
	.string "だが わたしが きみを ほんものの\n"
	.string "ポケモンの たつじんと みとめるには…\p"
	.string "… …\p"
	.string "まだまだ だな!$"

SaffronCity_PokemonTrainerFanClub_Text_YoullBeTalkedAboutIfYouKeepWinning::
	.string "{JPN}ここに あつまった ものは みな\n"
	.string "ポケモントレーナーの ファンなのだ。\p"
	.string "バトルの ときの あの すがた…\n"
	.string "まさに かっこよさ そのもの。\p"
	.string "きみも かちつづければ ここで\n"
	.string "うわさに なるかもしれんな。$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeYouOneDay::
	.string "{JPN}{ENG}{PLAYER}{JPN}だ!\n"
	.string "{ENG}{PLAYER}{JPN}だ!\p"
	.string "いつか {ENG}{PLAYER}{JPN}みたいに なりたい!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneButMeStoppedBeingYourFan::
	.string "{JPN}みんな {ENG}{PLAYER}{JPN}の ファンを\n"
	.string "やめちゃった…\p"
	.string "でも これで {ENG}{PLAYER}{JPN}を\n"
	.string "ひとりじめ できる!\p"
	.string "やった! がんばって!\n"
	.string "わたしだけの {ENG}{PLAYER}{JPN}!$"

SaffronCity_PokemonTrainerFanClub_Text_WantToBeLikeSabrina::
	.string "{JPN}ねえ しってる?\n"
	.string "わたし ナツメみたいに なりたいの!\p"
	.string "ナツメみたいな エスパー\n"
	.string "しょうじょに なりたいの!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingSabrinasFan::
	.string "{JPN}わたし ひとりに なっても\n"
	.string "ナツメの ファンは やめないわ。\p"
	.string "ゆめは ナツメみたいに\n"
	.string "かわいくて かっこよく なること。\p"
	.string "ナツメみたいな エスパー\n"
	.string "しょうじょに なりたいの!$"

SaffronCity_PokemonTrainerFanClub_Text_CanIBecomeCoolTrainerOneDay::
	.string "{JPN}いつか かっこいい\n"
	.string "トレーナーに なれるかなあ?$"

SaffronCity_PokemonTrainerFanClub_Text_TheWayYouBattleIsCool::
	.string "{JPN}うわー うわー!\n"
	.string "かっこいい! かっこよすぎ!\p"
	.string "…え?\n"
	.string "ちがう きみじゃ ないよ。\p"
	.string "きみの バトルの しかたが\n"
	.string "かっこいいって こと。$"

SaffronCity_PokemonTrainerFanClub_Text_ImOnlyOneLeftOfYourFans::
	.string "{JPN}よう {ENG}{PLAYER}{JPN}!\p"
	.string "きみの ファンで のこってるのは\n"
	.string "じぶん だけ みたいだな。\p"
	.string "でもさ ひとりだけの ファンって\n"
	.string "いいもんだよ… きが らくで。\p"
	.string "その ちょうしで がんばれ!$"

SaffronCity_PokemonTrainerFanClub_Text_LoveWayTrainerTalks::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}って かっこいいよね?\n"
	.string "あの はなしかたが だいすき。\p"
	.string "いちどで いいから ちょくせつ\n"
	.string "あって みたいなあ。$"

SaffronCity_PokemonTrainerFanClub_Text_ImLoneTrainerFan::
	.string "{JPN}ねえ しんじられる?\n"
	.string "みんな きみの ファンに なっちゃった。\p"
	.string "いろいろ あったのに けっきょく\n"
	.string "{ENG}{STR_VAR_1}{JPN}の ファンは ひとりだけ?\p"
	.string "まあ ただ ひとりの\n"
	.string "{ENG}{STR_VAR_1}{JPN}ファンが しょうに あってるし。$"

SaffronCity_PokemonTrainerFanClub_Text_AdoreWayYouBattle::
	.string "{JPN}まあ たいへん!\n"
	.string "ほんとうに {ENG}{PLAYER}{JPN}なの?\p"
	.string "いわせて ちょうだい わたし\n"
	.string "あなたの バトルが だいすきなの。\p"
	.string "これからも がんばってね。\n"
	.string "わたしが ファン だいいちごうよ!$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourNumberOneFan::
	.string "{JPN}まあ たいへん!\n"
	.string "{ENG}{PLAYER}{JPN}じゃ ないの!\p"
	.string "ほんとに ざんねん… わたしが\n"
	.string "あなたの ゆいいつの ファンだなんて!\p"
	.string "まあ しかたないわね!\n"
	.string "せめて おうえん させてね!\p"
	.string "フレー フレー {ENG}{PLAYER}{JPN}!$"

SaffronCity_PokemonTrainerFanClub_Text_TrainerHasBeenOnFire::
	.string "{JPN}さいきん {ENG}{STR_VAR_1}{JPN}が\n"
	.string "のりに のってるの。\p"
	.string "あの バトルの しかた… まさに\n"
	.string "わたし ごのみ なのよ!$"

SaffronCity_PokemonTrainerFanClub_Text_EveryoneTalksAboutYou::
	.string "{JPN}あら こんにちは!\n"
	.string "{ENG}{PLAYER}{JPN}じゃ ないの!\p"
	.string "さいきん みんな あなたの\n"
	.string "はなしばかり。\p"
	.string "わたしは ちょっと さみしいわ。\n"
	.string "{ENG}{STR_VAR_1}{JPN}の ほうが すきだから。$"

SaffronCity_PokemonTrainerFanClub_Text_YouReallyAreAmazing::
	.string "{JPN}すごい!\n"
	.string "{ENG}{PLAYER}{JPN} ほんとに すごいよ!\p"
	.string "みてる だけじゃ なくて\n"
	.string "わたしも トレーナーに なろうかな。$"

SaffronCity_PokemonTrainerFanClub_Text_ImYourOnlyFan::
	.string "{JPN}きみの ファンは わたし だけ…\n"
	.string "はあ… さみしいなあ…\p"
	.string "もっと がんばって ほかの ひとにも\n"
	.string "ちゅうもく させてよ?$"

SaffronCity_PokemonTrainerFanClub_Text_WhyCantOthersSeeMastersDignity::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}さまは いげんが あって…\n"
	.string "ほんとに わたしの タイプ。\p"
	.string "あふれでる あの いげんが\n"
	.string "どうして みんなには わからないの?$"

SaffronCity_PokemonTrainerFanClub_Text_BelieveInMasterWithAllMyHeart::
	.string "{JPN}わたしは {ENG}{STR_VAR_1}{JPN}さまを\n"
	.string "こころから しんじてるわ。\p"
	.string "たとえ しんじてるのが\n"
	.string "わたし ひとりでも。\p"
	.string "でも さみしくなんか ないわ。\p"
	.string "ずっと おもいつづけて いれば…\n"
	.string "{ENG}{STR_VAR_1}{JPN}さまの ことを。$"

SaffronCity_PokemonTrainerFanClub_Text_YourBattleStyleIsEducational::
	.string "{JPN}ハイヤーッ!\p"
	.string "きみの バトルの スタイルは\n"
	.string "じつに べんきょうに なる。\p"
	.string "これからも せいこうを めざして\n"
	.string "がんばって くれ! ハイヤーッ!$"

SaffronCity_PokemonTrainerFanClub_Text_WontStopBeingYourFan::
	.string "{JPN}ひとの バトルを みてる ひまが\n"
	.string "あったら じぶんで たたかえ!\p"
	.string "…と どうじょうの しはんに\n"
	.string "しかられた…\p"
	.string "でも だからって きみの ファンを\n"
	.string "やめたり しないぞ!\p"
	.string "きみの ファンは やめられない!$"

SaffronCity_PokemonTrainerFanClub_Text_OnlyMasterHasMyRespect::
	.string "{JPN}ハイヤーッ! わたしが そんけいする\n"
	.string "トレーナーは ただ ひとり。\p"
	.string "それは ほかでもない\n"
	.string "かくとう どうじょうの しはんだ!\p"
	.string "きみも わたしのように\n"
	.string "しはんの ファンに なれ! ハイヤーッ!$"

SaffronCity_PokemonTrainerFanClub_Text_NeverBeFanOfAnyoneButMaster::
	.string "{JPN}ハイヤーッ! わたしは かくとう\n"
	.string "どうじょうの しはんを そんけいしている。\p"
	.string "しはん いがいの ひとの ファンには\n"
	.string "ぜったいに ならない!\p"
	.string "どうじょうを こっそり ぬけだしてでも\n"
	.string "しはんの すばらしさを ひろめるのだ。\p"
	.string "ハイヤーッ!$"

