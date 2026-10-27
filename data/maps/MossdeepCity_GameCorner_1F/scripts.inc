MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "{JPN}わかい ころ わしは トレーナーとして\n"
	.string "せかいを たびして まわった。\p"
	.string "すっかり おいぼれた いまでは\n"
	.string "わかい トレーナーの しょうぶを みるのが\l"
	.string "ゆいいつの たのしみ じゃ。$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "{JPN}とびらには かぎが かかって いるようだ。$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN} という トレーナーが\n"
	.string "うちに あそびに きとる。\p"
	.string "どうじゃ ひとつ\n"
	.string "{ENG}{STR_VAR_1}{JPN}に いどんで みるかね?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "{JPN}しょうぶ せんのか? おまえさんの\n"
	.string "しょうぶが みられんとは ざんねんじゃ……$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "{JPN}おお よしよし!\p"
	.string "じゃが うちは あまり がんじょう でなくてな。\p"
	.string "しょうぶは 3たい3 までに\n"
	.string "して くれんか?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "{JPN}しょうぶの まえに\n"
	.string "レポートを かいて おくと いい。$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "{JPN}よい しょうぶを みせて おくれ!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "{JPN}ふむ ひきわけ に なったか。\p"
	.string "どちらも いっぽも ゆずらぬ\n"
	.string "みごとな しょうぶ じゃった!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "{JPN}じつに すばらしかった!\p"
	.string "まるで わかい ころの わしを\n"
	.string "みているようじゃったよ!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "{JPN}ああ ざんねんじゃったな!\p"
	.string "じゃが よい しょうぶ だった。\n"
	.string "つぎは かてると いいのう。$"
