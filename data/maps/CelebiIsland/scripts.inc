	.equ LOCALID_ISLAND_CELEBI, 1
	.equ LOCALID_ISLAND_UXIE, 5
	.equ LOCALID_ISLAND_MESPRIT, 6
	.equ LOCALID_ISLAND_AZELF, 7

	.equ LOCALID_ISLAND_CELEBI, 1

CelebiIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CelebiIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CelebiIsland_OnFrame
	.byte 0

@ The lake trio guards the shrine until the keepers' trial is done; then
@ they hold the island's ends forever and CELEBI appears at the shrine.
CelebiIsland_OnTransition::
	goto_if_set FLAG_WOT_FAIRY_TRIAL_DONE, CelebiIsland_OnTransition_Watch
	setflag FLAG_HIDE_WOT_CELEBI
	end
CelebiIsland_OnTransition_Watch::
	clearflag FLAG_HIDE_WOT_CELEBI
	setobjectxyperm LOCALID_ISLAND_UXIE, 4, 33
	setobjectxyperm LOCALID_ISLAND_MESPRIT, 25, 41
	setobjectxyperm LOCALID_ISLAND_AZELF, 46, 33
	end

@ First arrival = the first checkpoint of the Stop the Machine main quest.
CelebiIsland_OnFrame:
	map_script_2 VAR_TEMP_0, 0, CelebiIsland_EventScript_ArrivalCheckpoint
	.2byte 0

CelebiIsland_EventScript_ArrivalCheckpoint::
	lockall
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_WOT_ISLAND_CHECKPOINT, CelebiIsland_EventScript_ArrivalCheckpointDone
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_STOP_THE_MACHINE
	goto_if_eq VAR_RESULT, FALSE, CelebiIsland_EventScript_ArrivalCheckpointDone
	setflag FLAG_WOT_ISLAND_CHECKPOINT
	questtoast QUEST_TOAST_UPDATE, QUEST_STOP_THE_MACHINE
	msgbox CelebiIsland_Text_Checkpoint, MSGBOX_DEFAULT
	closemessage
CelebiIsland_EventScript_ArrivalCheckpointDone::
	releaseall
	end

@ Surfing off the island's south edge returns to the city's tide waters.
@ North (toward the city) now crosses Route 129's open sea. The old direct
@ warp target (19,28) was STALE -- a solid city tile in the repainted layout.
CelebiIsland_EventScript_SurfToCity::
	lockall
	@ (40,37) dropped the surfer outside Route 129's playable water --
	@ (78,20) is the open sea off the island.
	warp MAP_ROUTE129, 78, 20
	waitstate
	releaseall
	end

@ Surfing off the west edge crosses to Prototype Island's waters.
@ NORTH now, not west: Prototype Island sits directly north of the island.
CelebiIsland_EventScript_SurfToPrototype::
	lockall
	warp MAP_PROTOTYPE_ISLAND, 11, 26
	waitstate
	releaseall
	end

@ ============================================================================
@  CELEBI ISLAND -- THE PURIFICATION SHRINE (WoT_Act3_Canon.md §2.2)
@  First archipelago map: a small sacred island in the raised tides. Three
@  fairy keepers test visitors; their warden holds the only bridge to the
@  shrine islet until all three accept you (FLAG_WOT_FAIRY_TRIAL_DONE).
@  CELEBI itself performs purification: snag -> battle once ("opened") ->
@  present the mon here. Purify loop: choose a party mon, route on
@  GetMonShadowState (0 no shadow / 1 sealed / 2 ready), PurifyPartyMon.
@  NOT YET WIRED TO THE WORLD -- entry comes with Step 7 (tides drop ->
@  Surf opens the south water). Reach via debug warp for testing.
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================

@ --- The keepers (sight trainers; repurposed Mossdeep orphan ids) -----------
CelebiIsland_EventScript_KeeperSuzu::
	trainerbattle_single TRAINER_HANNAH, CelebiIsland_Text_SuzuIntro, CelebiIsland_Text_SuzuDefeat
	msgbox CelebiIsland_Text_SuzuPost, MSGBOX_AUTOCLOSE
	end

CelebiIsland_EventScript_KeeperKaede::
	trainerbattle_single TRAINER_SAMANTHA, CelebiIsland_Text_KaedeIntro, CelebiIsland_Text_KaedeDefeat
	msgbox CelebiIsland_Text_KaedePost, MSGBOX_AUTOCLOSE
	end

CelebiIsland_EventScript_KeeperRan::
	trainerbattle_single TRAINER_MAURA, CelebiIsland_Text_RanIntro, CelebiIsland_Text_RanDefeat
	msgbox CelebiIsland_Text_RanPost, MSGBOX_AUTOCLOSE
	end

@ --- CELEBI: the purification -----------------------------------------------
CelebiIsland_EventScript_Celebi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	msgbox CelebiIsland_Text_CelebiGreet, MSGBOX_DEFAULT
	special CountShadowPartyMons
	goto_if_eq VAR_RESULT, 0, CelebiIsland_EventScript_NoShadows

CelebiIsland_EventScript_ChooseMon::
	msgbox CelebiIsland_Text_Present, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, CelebiIsland_EventScript_Farewell
	special GetMonShadowState
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	switch VAR_RESULT
	case 0, CelebiIsland_EventScript_NotShadow
	case 1, CelebiIsland_EventScript_NotOpened
	@ -- state 2: opened and ready --
	msgbox CelebiIsland_Text_Ready, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_WHITE
	playfanfare MUS_HEAL
	special PurifyPartyMon
	delay 40
	fadescreen FADE_FROM_WHITE
	waitfanfare
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_HIGH_PITCH
	waitmoncry
	msgbox CelebiIsland_Text_Purified, MSGBOX_DEFAULT
	special CountShadowPartyMons
	goto_if_eq VAR_RESULT, 0, CelebiIsland_EventScript_AllClear
	msgbox CelebiIsland_Text_Another, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CelebiIsland_EventScript_ChooseMon
	goto CelebiIsland_EventScript_Farewell

CelebiIsland_EventScript_NotShadow::
	msgbox CelebiIsland_Text_NotShadow, MSGBOX_DEFAULT
	goto CelebiIsland_EventScript_ChooseMon

CelebiIsland_EventScript_NotOpened::
	msgbox CelebiIsland_Text_NotOpened, MSGBOX_DEFAULT
	goto CelebiIsland_EventScript_ChooseMon

CelebiIsland_EventScript_NoShadows::
	msgbox CelebiIsland_Text_NoShadows, MSGBOX_DEFAULT
	release
	end

CelebiIsland_EventScript_AllClear::
	msgbox CelebiIsland_Text_AllClear, MSGBOX_DEFAULT
	release
	end

CelebiIsland_EventScript_Farewell::
	msgbox CelebiIsland_Text_Farewell, MSGBOX_DEFAULT
	release
	end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
CelebiIsland_Text_SuzuIntro:
	.string "{JPN}しおが あなたを とおしたの?\p"
	.string "それなら しまは もう あなたに\n"
	.string "きょうみを もっているのね。\p"
	.string "わたしは まだよ。 ちからを しめして!$"

CelebiIsland_Text_SuzuDefeat:
	.string "{JPN}…やさしくて つよい。$"

CelebiIsland_Text_SuzuPost:
	.string "{JPN}まもりてたちが はしを みはっているの。\n"
	.string "3にん ぜんいんの みとめが ひつようよ。$"

CelebiIsland_Text_KaedeIntro:
	.string "{JPN}うみの むこうの まちは\n"
	.string "やみを つくる。\p"
	.string "この しまは それを とりのぞく。\n"
	.string "あなたが どちらに ちからを かすか みせて!$"

CelebiIsland_Text_KaedeDefeat:
	.string "{JPN}あたたかい。 あなたの ひかりは。$"

CelebiIsland_Text_KaedePost:
	.string "{JPN}ゆがめられた かわいそうな こたちを\n"
	.string "ここへ つれてきて。 1ぴき のこらず。$"

CelebiIsland_Text_RanIntro:
	.string "{JPN}ケケケ… くらい まちの\n"
	.string "においが するね。\p"
	.string "でも その おくには…\n"
	.string "もっと ふるい なにかが。 みせてごらん!$"

CelebiIsland_Text_RanDefeat:
	.string "{JPN}そう… それ。 それだよ。$"

CelebiIsland_Text_RanPost:
	.string "{JPN}はしの おじいさんは\n"
	.string "みかけよりも やさしいよ。$"

CelebiIsland_Text_WardenNotYet:
	.string "{JPN}この はしを わたれるのは\n"
	.string "まもりてに みとめられた ものだけじゃ。\p"
	.string "3つの しれん。 すべてを こなせ。\n"
	.string "さすれば ほこらも むかえよう。$"

CelebiIsland_Text_WardenOpens:
	.string "{JPN}3にんの まもりてが そなたを みとめた。\p"
	.string "ならば わしが ここに\n"
	.string "たちはだかる いわれも ない。\p"
	.string "わたるがよい。 あの こじまに あるものは\n"
	.string "ながく まちつづけておる。$"

CelebiIsland_Text_CelebiGreet:
	.string "{JPN}くうきが しずまった。\p"
	.string "セレビィが だいの うえに うかび\n"
	.string "ときさえも みみを かたむけている。$"

CelebiIsland_Text_NoShadows:
	.string "{JPN}セレビィが てもちの まわりを\n"
	.string "1ど 2どと まわった。\p"
	.string "どの こにも やみは ない。\n"
	.string "セレビィが ほっとしたように さえずった。$"

CelebiIsland_Text_Present:
	.string "{JPN}セレビィが ひかりで いっぱいの\n"
	.string "ちいさな てを ひらいた。\p"
	.string "ポケモンを さしだそう。$"

CelebiIsland_Text_NotShadow:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}には やみが ない。\p"
	.string "それでも セレビィは\n"
	.string "あたまを なでてくれた。$"

CelebiIsland_Text_NotOpened:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}を つつむ やみは\n"
	.string "まだ かたく とざされている。\p"
	.string "ともに あるき 1どでも ともに たたかおう。\n"
	.string "それから もどってこよう。$"

CelebiIsland_Text_Ready:
	.string "{JPN}セレビィが {ENG}{STR_VAR_1}{JPN}の かおを\n"
	.string "りょうてで つつんだ。\p"
	.string "やみが あらがい…\n"
	.string "ひかりが あつまる…$"

CelebiIsland_Text_Purified:
	.string "{JPN}やみが はれた!\p"
	.string "{ENG}{STR_VAR_1}{JPN}は\n"
	.string "じぶんを とりもどした!\p"
	.string "…もちものに ナショナルリボンが\n"
	.string "しずかに くわわった。$"

CelebiIsland_Text_Another:
	.string "{JPN}ほかにも やみに つつまれた\n"
	.string "ポケモンが いる。\p"
	.string "その こも さしだしますか?$"

CelebiIsland_Text_AllClear:
	.string "{JPN}てもちに のこっていた\n"
	.string "さいごの やみが きえた。\p"
	.string "セレビィが ちゅうで くるりと まわる。\n"
	.string "あさのように あかるく。$"

CelebiIsland_Text_Farewell:
	.string "{JPN}セレビィが だいの うえに もどった。\n"
	.string "もりのように しずかに まっている。$"

CelebiIsland_Text_Checkpoint:
	.string "{JPN}ようせいたちが まもる しま。\p"
	.string "まちが やみに おちてから\n"
	.string "はじめて めにした ひかりだ。$"

@ --- the guardians and their trial -------------------------------------------
@ Each guardian gates the trial the same way, then teaches its own half of
@ how purification actually works.
CelebiIsland_EventScript_GuardianUxie::
	lockall
	goto_if_set FLAG_WOT_FAIRY_TRIAL_DONE, CelebiIsland_EventScript_LessonUxie
	goto_if_not_defeated TRAINER_HANNAH, CelebiIsland_EventScript_GuardianBlocked
	goto_if_not_defeated TRAINER_SAMANTHA, CelebiIsland_EventScript_GuardianBlocked
	goto_if_not_defeated TRAINER_MAURA, CelebiIsland_EventScript_GuardianBlocked
	goto CelebiIsland_EventScript_TrioYield

CelebiIsland_EventScript_GuardianMesprit::
	lockall
	goto_if_set FLAG_WOT_FAIRY_TRIAL_DONE, CelebiIsland_EventScript_LessonMesprit
	goto_if_not_defeated TRAINER_HANNAH, CelebiIsland_EventScript_GuardianBlocked
	goto_if_not_defeated TRAINER_SAMANTHA, CelebiIsland_EventScript_GuardianBlocked
	goto_if_not_defeated TRAINER_MAURA, CelebiIsland_EventScript_GuardianBlocked
	goto CelebiIsland_EventScript_TrioYield

CelebiIsland_EventScript_GuardianAzelf::
	lockall
	goto_if_set FLAG_WOT_FAIRY_TRIAL_DONE, CelebiIsland_EventScript_LessonAzelf
	goto_if_not_defeated TRAINER_HANNAH, CelebiIsland_EventScript_GuardianBlocked
	goto_if_not_defeated TRAINER_SAMANTHA, CelebiIsland_EventScript_GuardianBlocked
	goto_if_not_defeated TRAINER_MAURA, CelebiIsland_EventScript_GuardianBlocked
	goto CelebiIsland_EventScript_TrioYield

CelebiIsland_EventScript_GuardianBlocked::
	waitse
	playmoncry SPECIES_UXIE, CRY_MODE_NORMAL
	waitmoncry
	msgbox CelebiIsland_Text_GuardianBlocks, MSGBOX_DEFAULT
	releaseall
	end

@ UXIE (knowledge): how to open a sealed heart.
CelebiIsland_EventScript_LessonUxie::
	waitse
	playmoncry SPECIES_UXIE, CRY_MODE_NORMAL
	waitmoncry
	msgbox CelebiIsland_Text_LessonUxie, MSGBOX_DEFAULT
	releaseall
	end

@ MESPRIT (emotion): what purification is worth.
CelebiIsland_EventScript_LessonMesprit::
	waitse
	playmoncry SPECIES_MESPRIT, CRY_MODE_NORMAL
	waitmoncry
	msgbox CelebiIsland_Text_LessonMesprit, MSGBOX_DEFAULT
	releaseall
	end

@ AZELF (willpower): wondering how far it could be pushed.
CelebiIsland_EventScript_LessonAzelf::
	waitse
	playmoncry SPECIES_AZELF, CRY_MODE_NORMAL
	waitmoncry
	msgbox CelebiIsland_Text_LessonAzelf, MSGBOX_DEFAULT
	releaseall
	end

CelebiIsland_EventScript_TrioTrial::
	lockall
	setvar VAR_TEMP_4, 1
	goto_if_set FLAG_WOT_FAIRY_TRIAL_DONE, CelebiIsland_EventScript_TrioTrialDone
	goto_if_not_defeated TRAINER_HANNAH, CelebiIsland_EventScript_TrioNotYet
	goto_if_not_defeated TRAINER_SAMANTHA, CelebiIsland_EventScript_TrioNotYet
	goto_if_not_defeated TRAINER_MAURA, CelebiIsland_EventScript_TrioNotYet
	goto CelebiIsland_EventScript_TrioYield

@ The yield + scatter + CELEBI descent. Entered either by stepping on the
@ shrine approach or by talking to a guardian once the keepers are beaten.
CelebiIsland_EventScript_TrioYield::
	waitse
	playmoncry SPECIES_UXIE, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_MESPRIT, CRY_MODE_NORMAL
	waitmoncry
	playmoncry SPECIES_AZELF, CRY_MODE_NORMAL
	waitmoncry
	msgbox CelebiIsland_Text_TrioYield, MSGBOX_DEFAULT
	closemessage
	@ --- the scatter: three guardians burst apart in three directions ---
	playse SE_FLEE
	applymovement LOCALID_ISLAND_UXIE, CelebiIsland_Movement_UxieScatterWest
	applymovement LOCALID_ISLAND_AZELF, CelebiIsland_Movement_AzelfScatterEast
	applymovement LOCALID_ISLAND_MESPRIT, CelebiIsland_Movement_MespritScatterSouth
	waitmovement LOCALID_ISLAND_UXIE
	waitmovement LOCALID_ISLAND_AZELF
	waitmovement LOCALID_ISLAND_MESPRIT
	@ relocate to their watch posts (off-camera; OnTransition re-applies)
	setobjectxyperm LOCALID_ISLAND_UXIE, 4, 33
	removeobject LOCALID_ISLAND_UXIE
	addobject LOCALID_ISLAND_UXIE
	setobjectxyperm LOCALID_ISLAND_MESPRIT, 25, 41
	removeobject LOCALID_ISLAND_MESPRIT
	addobject LOCALID_ISLAND_MESPRIT
	setobjectxyperm LOCALID_ISLAND_AZELF, 46, 33
	removeobject LOCALID_ISLAND_AZELF
	addobject LOCALID_ISLAND_AZELF
	@ --- Celebi lowers from the sky onto the altar ---
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, CelebiIsland_Movement_CameraToShrine
	waitmovement 0
	delay 16
	setflag FLAG_WOT_FAIRY_TRIAL_DONE
	clearflag FLAG_HIDE_WOT_CELEBI
	addobject LOCALID_ISLAND_CELEBI
	setobjectxy LOCALID_ISLAND_CELEBI, 25, 17
	playse SE_M_TELEPORT
	applymovement LOCALID_ISLAND_CELEBI, CelebiIsland_Movement_CelebiDescend
	waitmovement 0
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	waitmoncry
	delay 30
	applymovement LOCALID_CAMERA, CelebiIsland_Movement_CameraBackToPlayer
	waitmovement 0
	special RemoveCameraObject
	msgbox CelebiIsland_Text_TrioWatch, MSGBOX_DEFAULT
CelebiIsland_EventScript_TrioTrialDone::
	releaseall
	end

CelebiIsland_Movement_UxieScatterWest:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

CelebiIsland_Movement_AzelfScatterEast:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

CelebiIsland_Movement_MespritScatterSouth:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

CelebiIsland_Movement_CameraToShrine:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CelebiIsland_Movement_CameraBackToPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ Slow float down out of the sky onto the altar tile (25,21).
CelebiIsland_Movement_CelebiDescend:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CelebiIsland_EventScript_TrioNotYet::
	msgbox CelebiIsland_Text_TrioNotYet, MSGBOX_DEFAULT
	releaseall
	end

CelebiIsland_Text_GuardianBlocks::
	.string "{JPN}ちいさな ポケモンが あなたと ほこらの\n"
	.string "あいだに うかんでいる。\p"
	.string "とじた めが あなたの してきたことを\n"
	.string "すべて みとおしている。$"

CelebiIsland_Text_LessonUxie::
	.string "{JPN}ユクシーが あなたの あたまへ\n"
	.string "ねばりづよく おもいを おくりこむ。\p"
	.string "とざされた こころには\n"
	.string "そとから ては とどかない。\p"
	.string "ダークポケモンと ともに たたかいなさい。\n"
	.string "たたかう あいだ そばに いれば\l"
	.string "こころの ふういんが ゆるむ。\p"
	.string "そうして はじめて ほこらで\n"
	.string "しあげを することが できる。$"

CelebiIsland_Text_LessonMesprit::
	.string "{JPN}エムリットが ゆっくりと まわる。\n"
	.string "じぶんで たのしんでいるようだ。\p"
	.string "やみに さずけられた ちからを\n"
	.string "うしなうのを おそれているのですね。\p"
	.string "その しんぱいは いりません。 リライブしても\n"
	.string "ちからは すべて のこります…\l"
	.string "だいしょうは いっさい ありません。\p"
	.string "ぼうぎょの よわさも ハイパーモードも なく\n"
	.string "ダークポケモンだった ときより\l"
	.string "つよくなるのです。$"

CelebiIsland_Text_LessonAzelf::
	.string "{JPN}アグノムは おちつかない。\p"
	.string "あの いし… メガストーンについて\n"
	.string "かんがえていたようだ。\p"
	.string "リライブした こころを\n"
	.string "メガシンカの きずなに とおしたら…?\p"
	.string "まだ だれも ためしていない。\n"
	.string "アグノムは だれかに ためしてほしくて\l"
	.string "たまらないようだ。$"

CelebiIsland_Text_TrioNotYet::
	.string "{JPN}3つの けはいが\n"
	.string "こころに かたりかける。\p"
	.string "「まもりてを。 すべての まもりてを。\n"
	.string "それから ほこらへ。」$"

CelebiIsland_Text_TrioYield::
	.string "{JPN}3びきが いっせいに まいあがる。\p"
	.string "「ちしき。 かんじょう。 いし。\n"
	.string "まもりてたちは あなたの それを みとめた。\p"
	.string "「ほこらは ひらかれた。\n"
	.string "ねがいを になうものよ。 われらは\l"
	.string "しまの きしを まもろう。」$"

CelebiIsland_Text_TrioWatch::
	.string "{JPN}3びきは しまの はしばしへ わかれた。\n"
	.string "ねむることのない\l"
	.string "3びきの みはりだ。\p"
	.string "ほこらでは… みどりいろの なにかが\n"
	.string "またたくように すがたを あらわした。$"
