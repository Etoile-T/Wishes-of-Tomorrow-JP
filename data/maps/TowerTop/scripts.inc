	.equ LOCALID_TOWER_JIRACHI, 1
	.equ LOCALID_TOWER_ONI, 2
	.equ LOCALID_TOWER_JET, 3
	.equ LOCALID_TOWER_RAYQUAZA, 4

TowerTop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TowerTop_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TowerTop_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, TowerTop_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TowerTop_OnFrame
	.byte 0

@ Shadow Jirachi floats in the machine's glass. ON_RESUME (not ON_FRAME) so
@ the bob also resumes after a battle return; the task no-ops itself once the
@ object is gone, and re-arming it while it runs is a no-op.
TowerTop_OnResume::
	setvar VAR_0x8004, LOCALID_TOWER_JIRACHI
	special WotStartObjectBob
	end

@ The jet + released legendaries only ever exist mid-cutscene.
TowerTop_OnTransition::
	setflag FLAG_WOT_TOWER_LEGENDS_AWAY
	@ Any loss inside the tower sends the player back to the Rebel Hideout: the
	@ tower has no healing of its own and the district below it is hostile.
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	end

@ Once Shadow Jirachi is caught the machine stays broken forever.
TowerTop_OnLoad::
	call_if_set FLAG_WOT_TOWER_JIRACHI_GONE, TowerTop_EventScript_SetBrokenMachine
	end

TowerTop_EventScript_SetBrokenMachine::
	setmetatile 7, 1, 0x3C8, TRUE
	setmetatile 8, 2, 0x3F2, TRUE
	setmetatile 7, 3, 0x3C8, TRUE
	return

@ ============================================================================
@  MUTRID TOWER -- THE SUMMIT (shell). The Shadow Core: the machine, powered
@  by SHADOW JIRACHI welded into its heart, and THE ONI beside it. Entering
@  plays his scene once (FLAG_WOT_ONI_MET): pure evil, finishing what his
@  father could not -- the perfect world. NO BATTLE YET -- Joe will author
@  his team in detail (Pic "Mutrid Leader" already exists for it).
@  Jirachi OW gfx = SPECIES(JIRACHI) placeholder until the custom Shadow
@  Jirachi sprites are imported. All dialogue PLACEHOLDER (Joe).
@ ============================================================================

TowerTop_OnFrame:
	map_script_2 VAR_TEMP_1, 0, TowerTop_EventScript_OniScene
	.2byte 0

TowerTop_EventScript_OniScene::
	lockall
	setvar VAR_TEMP_1, 1
	@ The stairs put the player in at (8,9) facing down, with the machine at
	@ their back. Turn them to it on every arrival, scene or not.
	applymovement OBJ_EVENT_ID_PLAYER, TowerTop_Movement_PlayerFaceCore
	waitmovement 0
	goto_if_set FLAG_WOT_ONI_MET, TowerTop_EventScript_OniSceneDone
	setflag FLAG_WOT_ONI_MET
	@ Ride the camera three tiles up so THE ONI (8,6) and Shadow Jirachi
	@ (7,6) hold the frame for the whole speech.
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, TowerTop_Movement_CameraToCore
	waitmovement 0
	delay 60
	@ The machine's hum; JIRACHI's faint, exhausted cry inside the glass.
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_WEAK
	waitmoncry
	delay 30
	applymovement LOCALID_TOWER_ONI, TowerTop_Movement_OniFacePlayer
	waitmovement LOCALID_TOWER_ONI
	setspeaker SP_NAME_THE_ONI
	msgbox TowerTop_Text_Oni1, MSGBOX_DEFAULT
	msgbox TowerTop_Text_Oni2, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_WEAK
	waitmoncry
	setspeaker SP_NAME_THE_ONI
	msgbox TowerTop_Text_Oni3, MSGBOX_DEFAULT
	msgbox TowerTop_Text_Oni4, MSGBOX_DEFAULT
	msgbox TowerTop_Text_Oni5, MSGBOX_DEFAULT
	closemessage
	@ back to the player before the battle -- a camera object must never
	@ survive into one
	applymovement LOCALID_CAMERA, TowerTop_Movement_CameraBackDownToPlayer
	waitmovement 0
	special RemoveCameraObject
	@ "...or prepare to die." -- the final battle, right here.
	call TowerTop_EventScript_OniBattle
TowerTop_EventScript_OniSceneDone::
	releaseall
	end

@ Shared by the intro scene and the rematch talk (after a whiteout). Returns
@ only on victory -- then the whole escape beat plays.
TowerTop_EventScript_OniBattle::
	special WotSuppressWeatherSE
	special WotStopSceneSE
	bossintro BOSS_INTRO_THE_ONI
	trainerbattle_no_intro TRAINER_WALLY_VR_5, TowerTop_Text_OniDefeat
	@ the storm's ambient SE would fight the scene audio (12ch or not)
	special WotSuppressWeatherSE
	setspeaker SP_NAME_THE_ONI
	msgbox TowerTop_Text_OniFlee, MSGBOX_DEFAULT
	closemessage
	@ Pan to the roofline FIRST -- the back edge (13,2) is off-camera from
	@ anywhere the player can stand, so without this the boarding happens
	@ where nobody can see it.
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, TowerTop_Movement_CameraUpToRoof
	waitmovement 0
	delay 12
	@ out the back along the repainted floor: right 5 to the east wall, then
	@ straight up the gap to the roofline at (13,2)
	applymovement LOCALID_TOWER_ONI, TowerTop_Movement_OniRunOut
	waitmovement LOCALID_TOWER_ONI
	delay 16
	@ the jet screams across the roofline and swallows him
	clearflag FLAG_WOT_TOWER_LEGENDS_AWAY
	addobject LOCALID_TOWER_JET
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_TOWER_JET, TowerTop_Movement_JetSwoopIn
	waitmovement LOCALID_TOWER_JET
	setflag FLAG_WOT_ONI_DEFEATED
	removeobject LOCALID_TOWER_ONI
	applymovement LOCALID_TOWER_JET, TowerTop_Movement_JetSwoopOut
	waitmovement LOCALID_TOWER_JET
	removeobject LOCALID_TOWER_JET
	setflag FLAG_WOT_TOWER_LEGENDS_AWAY
	delay 24
	applymovement LOCALID_CAMERA, TowerTop_Movement_CameraBackDown
	waitmovement 0
	special RemoveCameraObject
	return

TowerTop_EventScript_StairsDown::
	lockall
	warp MAP_TOWER_COMMAND, 7, 5
	waitstate
	releaseall
	end

@ Talking to him again after the scene (i.e. after a whiteout): straight back
@ into the fight.
TowerTop_EventScript_Oni::
	lock
	faceplayer
	setspeaker SP_NAME_THE_ONI
	msgbox TowerTop_Text_OniAgain, MSGBOX_DEFAULT
	closemessage
	call TowerTop_EventScript_OniBattle
	release
	end

TowerTop_EventScript_Jirachi::
	lockall
	goto_if_set FLAG_WOT_ONI_DEFEATED, TowerTop_EventScript_JirachiFree
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_WEAK
	waitmoncry
	msgbox TowerTop_Text_JirachiLook, MSGBOX_DEFAULT
	releaseall
	end

@ The Oni is gone; the wish-granter hangs unguarded in the dying machine.
TowerTop_EventScript_JirachiFree::
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox TowerTop_Text_JirachiUnbound, MSGBOX_DEFAULT
	closemessage
	@ The CUSTOM Shadow species (Steel/Dark, its own art), not plain Jirachi
	@ wearing the Shadow flag -- otherwise the caught mon reverts to an
	@ ordinary Jirachi everywhere outside this battle.
	setwildbattle SPECIES_JIRACHI_SHADOW, 70
	special WotMakeEventMonShadow
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TowerTop_EventScript_Overload
	releaseall
	end

@ ============================================================================
@  THE OVERLOAD -- Shadow Jirachi is caught, the machine loses its heart.
@  Shakes, breaking tiles (0x3C8/0x3F2), the captive legendaries burst free
@  and scatter, then the credits. GameClear saves via the Hall of Fame and
@  chains into CB2_StartCreditsSequence; Continue resumes at the hideout.
@ ============================================================================
TowerTop_EventScript_Overload::
	setflag FLAG_WOT_TOWER_JIRACHI_GONE
	@ The machine has lost its heart: the Act-3 main line closes here, and
	@ every earlier main quest is defensively closed with it -- the post-game
	@ log must show all MAIN quests complete (toasts defer past the scene).
	completequest QUEST_STOP_THE_MACHINE
	completequest QUEST_WAKING_MOUNTAIN
	completequest QUEST_GRANDFATHERS_WISH
	completequest QUEST_LIFES_WORK
	special WotSuppressWeatherSE
	msgbox TowerTop_Text_MachineOverload, MSGBOX_DEFAULT
	closemessage
	@ Pan up: the machine's upper housing (rows 1-3) is off-camera from the
	@ Jirachi tile, and that is exactly where it tears itself apart.
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, TowerTop_Movement_CameraUpToMachine
	waitmovement 0
	delay 20
	@ -- the housing bursts open, one panel at a time --
	playse SE_BREAKABLE_DOOR
	setmetatile 7, 1, 0x3C8, TRUE
	special DrawWholeMapView
	delay 22
	playse SE_MUD_BALL
	setmetatile 8, 2, 0x3F2, TRUE
	special DrawWholeMapView
	delay 22
	playse SE_BREAKABLE_DOOR
	setmetatile 7, 3, 0x3C8, TRUE
	special DrawWholeMapView
	delay 26
	@ -- and then the whole core lets go --
	playse SE_M_EXPLOSION
	setvar VAR_0x8004, 8  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 12 @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special WotShakeCameraSilent
	waitstate
	delay 20
	@ -- the greatest of the caged things tears free --
	clearflag FLAG_WOT_TOWER_LEGENDS_AWAY
	addobject LOCALID_TOWER_RAYQUAZA
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	applymovement LOCALID_TOWER_RAYQUAZA, TowerTop_Movement_RayquazaScatter
	waitmovement LOCALID_TOWER_RAYQUAZA
	removeobject LOCALID_TOWER_RAYQUAZA
	setflag FLAG_WOT_TOWER_LEGENDS_AWAY
	removeobject LOCALID_TOWER_JIRACHI
	@ ...a beat of empty sky...
	delay 70
	applymovement LOCALID_CAMERA, TowerTop_Movement_CameraBackFromMachine
	waitmovement 0
	special RemoveCameraObject
	msgbox TowerTop_Text_TheEnd, MSGBOX_DEFAULT
	closemessage
	@ -- confetti over the freed city, then the credits --
	special WotStartFieldConfetti
	playse SE_APPLAUSE
	delay 180
	fadescreenspeed FADE_TO_BLACK, 8
	special WotStopFieldConfetti
	special GameClear
	releaseall
	end

TowerTop_Movement_PlayerFaceCore:
	face_up
	step_end

TowerTop_Movement_CameraToCore:
	walk_up
	walk_up
	walk_up
	step_end

TowerTop_Movement_CameraBackDownToPlayer:
	walk_down
	walk_down
	walk_down
	step_end

TowerTop_Movement_OniFacePlayer:
	face_down
	step_end

TowerTop_Movement_OniFaceMachine:
	face_up
	step_end

@ From (8,6): right 5, up 4 -> (13,2), the back edge of the roof.
@ Round the pillar, not through it. He is making for the jet at (15,2), but
@ rows 6 and 7 are walled at x=12-13 so running straight east crossed them.
@ Row 8 is open the full width, and column 14 climbs cleanly from there to the
@ top -- same destination, a route that exists.
TowerTop_Movement_OniRunOut:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ Jet template (15,2): two tiles left puts it over the Oni at (13,2).
TowerTop_Movement_JetSwoopIn:
	walk_faster_left
	walk_faster_left
	step_end

TowerTop_Movement_JetSwoopOut:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

@ Rayquaza climbs straight up out of the broken tower into open sky.
TowerTop_Movement_RayquazaScatter:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

@ Camera work. The player can only ever stand around y=6-11, so both the
@ jet boarding (y=2) and the machine housing (y=1-3) need a lift.
TowerTop_Movement_CameraUpToRoof:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TowerTop_Movement_CameraBackDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

TowerTop_Movement_CameraUpToMachine:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

TowerTop_Movement_CameraBackFromMachine:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
TowerTop_Text_Oni1::
	.string "{JPN}ここまで のぼってきたか。\p"
	.string "わたしの まちを ぬけ わたしの\n"
	.string "たいちょうを こえ わたしの タワーを。\p"
	.string "よい。 かんぺきな ものは わかちあう\n"
	.string "まえに みとどけられる べきだ。$"

TowerTop_Text_Oni2::
	.string "{JPN}ちちは よりよい せかいを ゆめみた。\n"
	.string "そして ひるんだ。 ちいさく\l"
	.string "しんでいった。\p"
	.string "わたしは ひるまない。\p"
	.string "ちちが なしえなかった ものを かんせいさせる。\n"
	.string "かんぺきな せかいを。$"

TowerTop_Text_Oni3::
	.string "{JPN}きくがいい。 ねがいを かなえる ものが\n"
	.string "わたしの きかいに つながれている。\p"
	.string "それが さけぶ ねがいの ひとつひとつが\n"
	.string "あらたな かんぺきな たましいに なる。\p"
	.string "それは ねがいを かなえたかった。\n"
	.string "わたしは ただ… とめさせなかった だけだ。$"

TowerTop_Text_Oni4::
	.string "{JPN}ポケモンは ふかんぜんだ。\p"
	.string "ためらう。 あいする。\n"
	.string "じゃくてんが ある。\p"
	.string "ダークポケモンは ためらわない。\n"
	.string "なみだも ながさない。\p"
	.string "ダークポケモンは つよい。$"

TowerTop_Text_Oni5::
	.string "{JPN}さあ えらべ {ENG}{PLAYER}{JPN}。\p"
	.string "やみに くだるか…\p"
	.string "…しぬ かくごを するか。$"

TowerTop_Text_OniAgain::
	.string "{JPN}まだ いきているか。 まだ\n"
	.string "ぐずぐずと まよっているか。\p"
	.string "きかいは きながだ\n"
	.string "{ENG}{PLAYER}{JPN}。 わたしは そうでもない。$"

TowerTop_Text_JirachiLook::
	.string "{JPN}ガラスの なかで ジラーチの めは\n"
	.string "かろうじて ひらいている。\p"
	.string "うばわれた せんの ねがいが\n"
	.string "ふういんを おしている。\p"
	.string "その どれひとつ ジラーチ じしんの ものではない。$"

TowerTop_Text_OniDefeat::
	.string "{JPN}…ふかんぜんだ。\p"
	.string "なぜ おまえたちは よわい ままで\n"
	.string "こんなにも つよいのだ？$"

TowerTop_Text_OniFlee::
	.string "{JPN}タワーは くれてやる。 まちもだ。\p"
	.string "かんぺきな せかいに ぎょくざは いらぬ。\n"
	.string "ひつようなのは たね ひとつだ。\p"
	.string "けりは かならず つけるぞ {ENG}{PLAYER}{JPN}。$"

TowerTop_Text_JirachiUnbound::
	.string "{JPN}オニが さり ふういんは いきほどに\n"
	.string "うすく なった。\p"
	.string "ダークジラーチが ふりむいた。 はじめて\n"
	.string "あなたを まっすぐ みつめている。\p"
	.string "のこる ねがいは ひとつ。\n"
	.string "つかまえて ほしいと ねがっている。$"

TowerTop_Text_MachineOverload::
	.string "{JPN}きかいが ひめいを あげた！\p"
	.string "うばわれた せんの ねがいが\n"
	.string "いきばを なくしている！$"

TowerTop_Text_TheEnd::
	.string "{JPN}はつでんきが たねの さやのように\n"
	.string "はじけた。\p"
	.string "つばさ。 つめ。 ひかり。 タワーが\n"
	.string "のみこんだ すべてが せかいへ\l"
	.string "あふれだしていく。\p"
	.string "シントウキョウの あらしが\n"
	.string "はれていく。 どこか したで\l"
	.string "レジスタンスが かんせいを あげている。\p"
	.string "すべての ねがいが もちぬしの もとへ かえった。$"
