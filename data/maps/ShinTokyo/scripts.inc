	.equ LOCALID_ACT3_CAPTAIN, 5

	@ Flat price of any Mega Stone from the Minister.
	.set MINISTER_MEGA_STONE_PRICE, 10000
	.equ LOCALID_ARREST_OFFICER, 6
	.equ LOCALID_ARREST_OPERATIVE, 7
	.equ LOCALID_JAIL_GUARD_A, 8
	.equ LOCALID_JAIL_GUARD_B, 9
	.equ LOCALID_ARREST_ZOROARK, 10
	.equ LOCALID_ARREST_GOON_A, 11
	.equ LOCALID_ARREST_GOON_B, 12
	.equ LOCALID_ARREST_GOON_C, 13
	@ Local ids are map.json order, so a porymap pass that adds or deletes an
	@ object shifts them -- deleting the billboard light moved Lugia 45 -> 44.
	@ Re-check these two against the object list after any porymap edit.
	.equ LOCALID_SHINTOKYO_LUGIA, 44
	.equ LOCALID_SHINTOKYO_FERRY, 39

ShinTokyo_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShinTokyo_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ShinTokyo_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ShinTokyo_OnFrame
	.byte 0

ShinTokyo_OnFrame:
	map_script_2 VAR_TEMP_4, 0, ShinTokyo_EventScript_DracoCall
	.2byte 0

@ ============================================================================
@  POST-GAME HOOK -- DRACO'S CALL (fires on the first city entry after the
@  hideout welcome scene: "you think it's over?"). Unlocks the dockhouse
@  (warps 9/10 -> MewtwoPostGame) where he waits with ARMORED MEWTWO.
@ ============================================================================
ShinTokyo_EventScript_HideFerry::
	setflag FLAG_WOT_HIDE_FRONTIER_FERRY
	return

@ ============================================================================
@  THE FRONTIER FERRY -- post-game only. Docks at the Shin-Tokyo waterfront
@  and runs to the Battle Frontier, arriving at the same harbour tile the
@  vanilla SS Tidal uses (BattleFrontier_OutsideWest 19,67).
@ ============================================================================
@ The deckhand on the quay (and the ship herself) run the crossing. The
@ departure is the gondola trick: WotShipDepart slides the ship's SPRITE out
@ east while the object stays on its tile, so nothing despawns mid-animation.
ShinTokyo_EventScript_FerryHand::
	lock
	faceplayer
	msgbox ShinTokyo_Text_FerryAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShinTokyo_EventScript_FerryDeclined
	msgbox ShinTokyo_Text_FerryBoard, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyo_Movement_WatchFerry
	waitmovement 0
	delay 20
	playse SE_SHIP
	setvar VAR_0x8004, LOCALID_SHINTOKYO_FERRY
	special WotShipDepart
	waitstate
	delay 40
	fadescreen FADE_TO_BLACK
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

ShinTokyo_Movement_WatchFerry:
	face_down
	step_end

ShinTokyo_EventScript_FerryDeclined::
	msgbox ShinTokyo_Text_FerryDeclined, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_DracoCall::
	lockall
	setvar VAR_TEMP_4, 1
	goto_if_unset FLAG_SYS_GAME_CLEAR, ShinTokyo_EventScript_DracoCallSkip
	goto_if_unset FLAG_WOT_POSTGAME_WELCOME_DONE, ShinTokyo_EventScript_DracoCallSkip
	goto_if_set FLAG_WOT_DRACO_CALL_DONE, ShinTokyo_EventScript_DracoCallSkip
	delay 20
	pokenavcall ShinTokyo_Text_DracoCall
	waitmessage
	closemessage
	setflag FLAG_WOT_DRACO_CALL_DONE
ShinTokyo_EventScript_DracoCallSkip::
	releaseall
	end

@ Tile edits must run in ON_LOAD -- ON_TRANSITION fires before the map layout
@ is loaded, so a setmetatile there is thrown away (the fence never opened).
ShinTokyo_OnLoad::
	call_if_set FLAG_ACT3_RED_ALERT, ShinTokyo_OnLoad_RedAlert
	end

@ the rebels kick a panel out of the lattice fence: the broken-panel
@ metatile with DOOR behavior lands on the hideout warp at (16,12).
ShinTokyo_OnLoad_RedAlert::
	setmetatile 16, 12, 0x1F0, FALSE
	return

@ Scene-only NPCs (the Captain, the arrest cast) stay hidden on every load;
@ their cutscenes addobject/removeobject them. Red alert reveals the Shadow
@ patrols.
@ NOTE: there is deliberately NO layout swap here any more. A second copied
@ layout went stale the moment the map was repainted in Porymap (the city
@ reverted to the pre-edit version after the jailbreak). ONE layout --
@ LAYOUT_SHIN_TOKYO, the one Porymap edits -- is the source of truth. The
@ tide beat is gated in script instead (see ShinTokyo_EventScript_SurfToIsland).
ShinTokyo_OnTransition::
	setflag FLAG_HIDE_ACT3_CAPTAIN
	@ Lugia is only ever on the water during its own scene (hide-flags default
	@ CLEAR, so this has to be re-set on every load, ferry-style).
	setflag FLAG_HIDE_SHINTOKYO_LUGIA
	setflag FLAG_HIDE_ACT3_ARREST_NPCS
	@ Hide-flags default CLEAR, so the ferry must be hidden explicitly on every
	@ pre-clear load (see the round-6 jet bug for why this matters).
	call_if_unset FLAG_SYS_GAME_CLEAR, ShinTokyo_EventScript_HideFerry
	goto_if_set FLAG_SYS_GAME_CLEAR, ShinTokyo_OnTransition_PostGame
	goto_if_set FLAG_ACT3_RED_ALERT, ShinTokyo_OnTransition_RedAlert
	setflag FLAG_HIDE_ACT3_PATROLS
	@ jumbotron: the Leader smiles down until the city turns on you
	clearflag FLAG_HIDE_WOT_LEADER_SCREEN
	setflag FLAG_HIDE_WOT_WANTED_POSTER
	end
@ The liberated city: the storm breaks, every screen goes dark, and not one
@ Mutrid uniform is left on the streets.
ShinTokyo_OnTransition_PostGame::
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	setweather WEATHER_SUNNY
	@ the trade lanes reopen: the Frontier ferry starts calling at the docks
	clearflag FLAG_WOT_HIDE_FRONTIER_FERRY
	setflag FLAG_HIDE_ACT3_JAIL_GUARDS
	setflag FLAG_WOT_HIDE_POSTGAME_MUTRIDS
	setflag FLAG_HIDE_WOT_LEADER_SCREEN
	setflag FLAG_HIDE_WOT_WANTED_POSTER
	@ The patrols are the exception to the empty streets: three hold-outs who
	@ never got the memo, left standing as the post-game Shadow hunting ground.
	@ They only fight when spoken to (sight 0) and their teams re-roll from the
	@ whole Shadow roster now that the Oni is gone, so the defeat flags clear
	@ on every visit exactly as they do under red alert.
	clearflag FLAG_HIDE_ACT3_PATROLS
	cleartrainerflag TRAINER_NATE
	cleartrainerflag TRAINER_MACEY
	cleartrainerflag TRAINER_CLIFFORD
	end
ShinTokyo_OnTransition_RedAlert::
	@ Any red-alert street whiteout comes back to the hideout cots -- never
	@ the jail cell (whiting out there walked the player straight back into
	@ the sight guards: the "respawns into battle" loop).
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	clearflag FLAG_HIDE_ACT3_PATROLS
	@ The patrols re-form every time the city is re-entered: defeat flags
	@ clear here, and their teams re-roll from the pool at battle start
	@ (WotTryRandomizeShadowPatrol in battle_main.c).
	cleartrainerflag TRAINER_NATE
	cleartrainerflag TRAINER_MACEY
	cleartrainerflag TRAINER_CLIFFORD
	@ jumbotron swaps to the bounty
	setflag FLAG_HIDE_WOT_LEADER_SCREEN
	clearflag FLAG_HIDE_WOT_WANTED_POSTER
	end

@ ============================================================================
@  ACT 3, STEP 1 -- NEON DISTRICT SHELL (WoT_Act3_Canon.md)
@  Placeholder layout: Night Market tileset stands in for the neon city until
@  real art lands. Building shells (gym / black market / battle cafe / blocks)
@  are painted but their doors are signs -- interiors come later. The south
@  water is VISIBLE AND LOCKED (mirror-water tiles, collision 1): Surf is
@  unlocked by the Distortion Badge but the tides are up until Step 5/7.
@  The lone goon teaches the mask system in safety (shared GoonNod script:
@  masked = deferential, unmasked = suspicious). All text PLACEHOLDER (Joe).
@ ============================================================================

ShinTokyo_EventScript_Citizen1::
	lock
	faceplayer
	goto_if_set FLAG_ACT3_RED_ALERT, ShinTokyo_EventScript_CitizenRedAlert
	msgbox ShinTokyo_Text_Citizen1, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_Citizen2::
	lock
	faceplayer
	goto_if_set FLAG_ACT3_RED_ALERT, ShinTokyo_EventScript_CitizenRedAlert
	msgbox ShinTokyo_Text_Citizen2, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_Citizen3::
	lock
	faceplayer
	goto_if_set FLAG_ACT3_RED_ALERT, ShinTokyo_EventScript_CitizenRedAlert
	msgbox ShinTokyo_Text_Citizen3, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_CitizenRedAlert::
	goto_if_set FLAG_SYS_GAME_CLEAR, ShinTokyo_EventScript_CitizenFree
	msgbox ShinTokyo_Text_CitizenRedAlert, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_CitizenFree::
	msgbox ShinTokyo_Text_CitizenFree, MSGBOX_DEFAULT
	release
	end

@ At red alert every enemy engages regardless of the mask (Step 5). The full
@ hostile-patrol conversion is a later pass -- this goon at least stops
@ being fooled.
ShinTokyo_EventScript_StreetGoon::
	lock
	faceplayer
	goto_if_set FLAG_ACT3_RED_ALERT, ShinTokyo_EventScript_StreetGoonHostile
	goto OniMask_EventScript_GoonNod

ShinTokyo_EventScript_StreetGoonHostile::
	msgbox ShinTokyo_Text_GoonRedAlert, MSGBOX_DEFAULT
	release
	end

@ --- Red-alert Shadow patrols (the city as snag grounds, v1) ----------------
@ Sight trainers fielding snaggable Shadow mons; they appear the moment the
@ red alert is up (FLAG_HIDE_ACT3_PATROLS cleared in ON_TRANSITION).
ShinTokyo_EventScript_Patrol1::
	goto_if_set FLAG_SYS_GAME_CLEAR, ShinTokyo_EventScript_PatrolHoldout1
	trainerbattle_single TRAINER_NATE, ShinTokyo_Text_Patrol1Intro, ShinTokyo_Text_Patrol1Defeat
	msgbox ShinTokyo_Text_PatrolPost, MSGBOX_AUTOCLOSE
	call Wot_EventScript_SnagProgress
	end

ShinTokyo_EventScript_Patrol2::
	goto_if_set FLAG_SYS_GAME_CLEAR, ShinTokyo_EventScript_PatrolHoldout2
	trainerbattle_single TRAINER_MACEY, ShinTokyo_Text_Patrol2Intro, ShinTokyo_Text_Patrol2Defeat
	msgbox ShinTokyo_Text_PatrolPost, MSGBOX_AUTOCLOSE
	call Wot_EventScript_SnagProgress
	end

ShinTokyo_EventScript_Patrol3::
	goto_if_set FLAG_SYS_GAME_CLEAR, ShinTokyo_EventScript_PatrolHoldout3
	trainerbattle_single TRAINER_CLIFFORD, ShinTokyo_Text_Patrol3Intro, ShinTokyo_Text_Patrol3Defeat
	msgbox ShinTokyo_Text_PatrolPost, MSGBOX_AUTOCLOSE
	call Wot_EventScript_SnagProgress
	end

@ ---------------------------------------------------------------------------
@  POST-CREDITS: the hold-outs. The uniforms lost, the Leader is gone and
@  nobody has told them what to do next -- so they stand on their corners
@  with whatever the program left them and fight anyone who asks. Beating
@  one is not final: trainerbattle_no_intro ignores the defeat flag, so the
@  team re-rolls from the whole Shadow roster every single time.
@ ---------------------------------------------------------------------------
ShinTokyo_EventScript_PatrolHoldout1::
	lock
	faceplayer
	msgbox ShinTokyo_Text_Holdout1, MSGBOX_DEFAULT
	goto ShinTokyo_EventScript_HoldoutBattle1
	end

ShinTokyo_EventScript_HoldoutBattle1::
	closemessage
	trainerbattle_no_intro TRAINER_NATE, ShinTokyo_Text_Patrol1Defeat
	msgbox ShinTokyo_Text_HoldoutPost, MSGBOX_DEFAULT
	call Wot_EventScript_SnagProgress
	release
	end

ShinTokyo_EventScript_PatrolHoldout2::
	lock
	faceplayer
	msgbox ShinTokyo_Text_Holdout2, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MACEY, ShinTokyo_Text_Patrol2Defeat
	msgbox ShinTokyo_Text_HoldoutPost, MSGBOX_DEFAULT
	call Wot_EventScript_SnagProgress
	release
	end

ShinTokyo_EventScript_PatrolHoldout3::
	lock
	faceplayer
	msgbox ShinTokyo_Text_Holdout3, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_CLIFFORD, ShinTokyo_Text_Patrol3Defeat
	msgbox ShinTokyo_Text_HoldoutPost, MSGBOX_DEFAULT
	call Wot_EventScript_SnagProgress
	release
	end

@ ===========================================================================
@  SHADOW LUGIA -- the harbour.
@  The last thing the program made, still down there. Walk to the seaward end
@  of the Minister's jetty and it comes up under the pier -- postgame only:
@  nothing stirs until the credits have rolled (FLAG_SYS_GAME_CLEAR).
@  Repeatable on purpose: only a capture sets FLAG_WOT_LUGIA_CAUGHT, and
@  VAR_TEMP_B (a temp var, cleared on every map load) keeps it to one rise
@  per visit so a lost fight cannot loop straight back into itself.
@  NOT VAR_TEMP_4: the ON_FRAME table above watches that one for the Draco
@  call, which sets it on every map load -- a trigger gated on it is dead.
@ ===========================================================================
ShinTokyo_EventScript_LugiaRise::
	setvar VAR_TEMP_B, 1
	goto_if_unset FLAG_SYS_GAME_CLEAR, ShinTokyo_EventScript_LugiaRiseEnd
	goto_if_set FLAG_WOT_LUGIA_CAUGHT, ShinTokyo_EventScript_LugiaRiseEnd
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyo_Movement_LugiaFaceSea
	waitmovement 0
	delay 20
	playse SE_M_WHIRLPOOL
	msgbox ShinTokyo_Text_LugiaWater, MSGBOX_DEFAULT
	closemessage
	@ Spawn it while (68,46) is still off the bottom of the screen -- the
	@ camera pan below brings it into frame instead of popping it in.
	clearflag FLAG_HIDE_SHINTOKYO_LUGIA
	addobject LOCALID_SHINTOKYO_LUGIA
	@ the violet silhouette the Shadow follower wears, on the map object too
	setvar VAR_0x8004, LOCALID_SHINTOKYO_LUGIA
	special WotMakeObjectEventShadow
	@ out over the open water, or the rise happens below the frame
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, ShinTokyo_Movement_LugiaCameraOut
	waitmovement 0
	playse SE_M_DIVE
	applymovement LOCALID_SHINTOKYO_LUGIA, ShinTokyo_Movement_LugiaSurfaces
	waitmovement 0
	delay 24
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	applymovement LOCALID_CAMERA, ShinTokyo_Movement_LugiaCameraBack
	waitmovement 0
	special RemoveCameraObject
	setwildbattle SPECIES_LUGIA, 70
	special WotMakeEventMonShadow
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, ShinTokyo_EventScript_LugiaCaught
	removeobject LOCALID_SHINTOKYO_LUGIA
	setflag FLAG_HIDE_SHINTOKYO_LUGIA
	msgbox ShinTokyo_Text_LugiaSinks, MSGBOX_DEFAULT
	releaseall
	end

ShinTokyo_EventScript_LugiaCaught::
	setflag FLAG_WOT_LUGIA_CAUGHT
	removeobject LOCALID_SHINTOKYO_LUGIA
	setflag FLAG_HIDE_SHINTOKYO_LUGIA
	msgbox ShinTokyo_Text_LugiaCaught, MSGBOX_DEFAULT
	releaseall
	end

ShinTokyo_EventScript_LugiaRiseEnd::
	end

@ Talking to it mid-scene is not possible, but the object needs a script.
ShinTokyo_EventScript_LugiaLook::
	lockall
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_WEAK
	waitmoncry
	releaseall
	end

ShinTokyo_Movement_LugiaFaceSea:
	face_down
	step_end

@ four tiles out over the harbour and back
ShinTokyo_Movement_LugiaCameraOut:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ShinTokyo_Movement_LugiaCameraBack:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ (68,46) -> (68,42): up out of the dark water, slowly.
ShinTokyo_Movement_LugiaSurfaces:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

ShinTokyo_Text_LugiaWater::
	.string "{JPN}みなとの みずが しずまりかえった。\p"
	.string "さんばしの したで なにかが\n"
	.string "みずを おしのけている。$"

ShinTokyo_Text_LugiaSinks::
	.string "{JPN}それは ふたたび みずの したへ すべりこみ\n"
	.string "みなとの みずが その うえを とざした。\p"
	.string "まだ その したに いる。$"

ShinTokyo_Text_LugiaCaught::
	.string "{JPN}その けいかくが さいごに\n"
	.string "うみだした ものは いま あなたの もの。\p"
	.string "みなとは しずかだ。$"

@ Surf route: crossing the southern edge carries the player to Celebi Island
@ (trigger row -- plain warps don't fire on ordinary water tiles). The TIDE
@ is the gate: until the red alert (Step 5) the crossing is closed, so the
@ player can paddle the harbour but not leave.
ShinTokyo_EventScript_SurfToIsland::
	lockall
	goto_if_unset FLAG_ACT3_RED_ALERT, ShinTokyo_EventScript_TideTooHigh
	@ (26,1) put the surfer outside Route 129's playable water -- (37,1) is
	@ the open channel below the city.
	warp MAP_ROUTE129, 37, 1
	waitstate
	releaseall
	end

ShinTokyo_EventScript_TideTooHigh::
	msgbox ShinTokyo_Text_TideTooHigh, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyo_Movement_StepBackUp
	waitmovement 0
	setvar VAR_TEMP_7, 0
	releaseall
	end

ShinTokyo_Movement_StepBackUp:
	walk_up
	step_end

@ The tower's executive entrance (door tile 24,4). Sealed until the shrine
@ trial is complete -- the rebellion's plan needs purification first.
ShinTokyo_EventScript_TowerDoor::
	lockall
	goto_if_set FLAG_WOT_FAIRY_TRIAL_DONE, ShinTokyo_EventScript_TowerDoorOpen
	msgbox ShinTokyo_Text_TowerSealed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyo_Movement_StepBackDown
	waitmovement 0
	setvar VAR_TEMP_9, 0
	releaseall
	end

ShinTokyo_EventScript_TowerDoorOpen::
	warp MAP_TOWER_STREET, 4, 8
	waitstate
	releaseall
	end

ShinTokyo_Movement_StepBackDown:
	walk_down
	step_end

ShinTokyo_EventScript_GymDoor::
	msgbox ShinTokyo_Text_GymDoor, MSGBOX_SIGN
	end

ShinTokyo_EventScript_BlackMarketDoor::
	msgbox ShinTokyo_Text_BlackMarketDoor, MSGBOX_SIGN
	end

ShinTokyo_EventScript_CafeDoor::
	msgbox ShinTokyo_Text_CafeDoor, MSGBOX_SIGN
	end

@ Canon Step 5: at red alert the building screens swap the Leader's face for
@ the player's and a bounty. (A real conditional GRAPHIC needs art; the sign
@ text carries the beat for now.)
ShinTokyo_EventScript_PropagandaScreen::
	lockall
	goto_if_set FLAG_ACT3_RED_ALERT, ShinTokyo_EventScript_BountyScreen
	msgbox ShinTokyo_Text_PropagandaScreen, MSGBOX_SIGN
	releaseall
	end

ShinTokyo_EventScript_BountyScreen::
	msgbox ShinTokyo_Text_BountyScreen, MSGBOX_SIGN
	releaseall
	end

ShinTokyo_EventScript_TideSign::
	msgbox ShinTokyo_Text_TideSign, MSGBOX_SIGN
	end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
ShinTokyo_Text_Citizen1::
	.string "{JPN}すてきな まちでしょう？\p"
	.string "すてきです。\n"
	.string "まいあさ そう おしえられています。$"

ShinTokyo_Text_Citizen2::
	.string "{JPN}うちの カイリキー せんげつ つよく なったんだ。\p"
	.string "そしたら かいしゅう された。\n"
	.string "いいんだ。 いいんだよ。$"

ShinTokyo_Text_Citizen3::
	.string "{JPN}ここでは ひとは きえたりしない！\p"
	.string "しょうしん するのよ。\n"
	.string "うえの かいへ。 えいえんに。$"

ShinTokyo_Text_GymDoor::
	.string "{JPN}ボルテンジム: 「まちの ひばな」$"

ShinTokyo_Text_BlackMarketDoor::
	.string "{JPN}シャッターが はんぶん あいている。\p"
	.string "なかの だれかが あなたが ノックするか\n"
	.string "まよっているのを みている。\p"
	.string "(やみいちは あとで じっそう よてい)$"

ShinTokyo_Text_CafeDoor::
	.string "{JPN}バトルカフェ: よどおし えいぎょう\p"
	.string "(カフェの なかは あとで じっそう よてい)$"

ShinTokyo_Text_PropagandaScreen::
	.string "{JPN}スクリーンが あたまの うえに そびえ\n"
	.string "とおりを ひかりで そめている。\p"
	.string "10かいだての たかさの かおが ほほえみ\n"
	.string "まばたきも しない。\p"
	.string "「せいさんせいこそ へいわ。\n"
	.string "リーダーが すべてを あたえる」$"

ShinTokyo_Text_TideTooHigh::
	.string "{JPN}ぼうはていの そとの ながれは\n"
	.string "まっくろな みずの かべだ。\p"
	.string "タワーが でんりょくを すいあげている\n"
	.string "あいだは なにも わたれない。$"

ShinTokyo_Text_TideSign::
	.string "{JPN}ちょうい ちゅういほう:\p"
	.string "タワーが でんりょくを すいあげている\n"
	.string "あいだ すいいが あがります。\p"
	.string "すべての わたしば へいさ。$"

@ ============================================================================
@  STEP 2 -- THE RESEARCH INSPECTION (trigger row y=10; movable)
@  The Mutrid Captain descends for a public inspection. Officer class: sees
@  through the carved mask. KEPT path: the Shadow Dossier is taken by
@  authority, not force -- no battle. DESTROY path: nothing to find.
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================
ShinTokyo_EventScript_Inspection::
	lockall
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_ACT3_INSPECTION_DONE, ShinTokyo_EventScript_InspectionDone
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyo_Movement_PlayerFaceLeft
	waitmovement 0
	addobject LOCALID_ACT3_CAPTAIN
	applymovement LOCALID_ACT3_CAPTAIN, ShinTokyo_Movement_CaptainApproach
	waitmovement 0
	setspeaker SP_NAME_MUTRID_CAPTAIN
	goto_if_unset FLAG_ONI_MASK_WORN, ShinTokyo_EventScript_InspectionHalt
	@ Officers see through the mask -- and say so.
	msgbox ShinTokyo_Text_CaptainMask, MSGBOX_DEFAULT
ShinTokyo_EventScript_InspectionHalt::
	msgbox ShinTokyo_Text_CaptainHalt, MSGBOX_DEFAULT
	checkitem ITEM_SHADOW_DOSSIER
	goto_if_eq VAR_RESULT, TRUE, ShinTokyo_EventScript_InspectionKept
	@ --- destroy path: a pat-down finds nothing. Small, quiet satisfaction.
	msgbox ShinTokyo_Text_CaptainNothing, MSGBOX_DEFAULT
	closemessage
	goto ShinTokyo_EventScript_InspectionLeave

ShinTokyo_EventScript_InspectionKept::
	msgbox ShinTokyo_Text_CaptainTakes, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	removeitem ITEM_SHADOW_DOSSIER, 1
	msgbox ShinTokyo_Text_DossierTaken, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ACT3_RESEARCH_STOLEN
	setspeaker SP_NAME_MUTRID_CAPTAIN
	msgbox ShinTokyo_Text_CaptainGloat, MSGBOX_DEFAULT
	closemessage
	goto ShinTokyo_EventScript_InspectionLeave

ShinTokyo_EventScript_InspectionLeave::
	applymovement LOCALID_ACT3_CAPTAIN, ShinTokyo_Movement_CaptainLeave
	waitmovement 0
	removeobject LOCALID_ACT3_CAPTAIN
	setflag FLAG_ACT3_INSPECTION_DONE
	goto_if_unset FLAG_ACT3_RESEARCH_STOLEN, ShinTokyo_EventScript_InspectionDone
	@ Gengar State C begins here (canon dialogue states).
	waitse
	playmoncry SPECIES_GENGAR, CRY_MODE_NORMAL
	waitmoncry
	setspeaker SP_NAME_GENGAR
	showportrait PORTRAIT_CLARKSON_GENGAR
	msgbox ShinTokyo_Text_GengarStateC, MSGBOX_DEFAULT
	closemessage
	hideportrait
ShinTokyo_EventScript_InspectionDone::
	releaseall
	end

@ ============================================================================
@  STEP 3 -- MINISTER'S CALL (trigger row y=16; movable). Fires only after
@  the inspection so the beats stay ordered. Opens the jail.
@ ============================================================================
ShinTokyo_EventScript_MinisterCall::
	lockall
	setvar VAR_TEMP_2, 1
	goto_if_unset FLAG_ACT3_INSPECTION_DONE, ShinTokyo_EventScript_MinisterCallSkip
	goto_if_set FLAG_ACT3_MINISTER_CALLED, ShinTokyo_EventScript_MinisterCallSkip
	pokenavcall ShinTokyo_Text_MinisterCall
	waitmessage
	closemessage
	setflag FLAG_ACT3_MINISTER_CALLED
	startquest SIDE_QUEST_MINISTERS_FAVOR
	@ The Minister makes good on it immediately: the two sentries posted at
	@ the detention door get pulled off (they're offscreen from the trigger
	@ row, so despawning is the scatter -- the text sells it).
	setflag FLAG_HIDE_ACT3_JAIL_GUARDS
	removeobject LOCALID_JAIL_GUARD_A
	removeobject LOCALID_JAIL_GUARD_B
	msgbox ShinTokyo_Text_GuardsScatter, MSGBOX_DEFAULT
	closemessage
ShinTokyo_EventScript_MinisterCallSkip::
	releaseall
	end

@ The two sentries walling off the detention door (32,18) until the call.
ShinTokyo_EventScript_JailGuard::
	lock
	faceplayer
	msgbox ShinTokyo_Text_JailGuard, MSGBOX_DEFAULT
	release
	end

@ The detention-block plaque beside the door (31,18). The door itself is a
@ real warp at (32,18) -- physically blocked by the sentries until the
@ Minister's call scatters them.
ShinTokyo_EventScript_JailDoor::
	lockall
	goto_if_set FLAG_ACT3_MINISTER_CALLED, ShinTokyo_EventScript_JailDoorOpen
	msgbox ShinTokyo_Text_JailDoorSealed, MSGBOX_DEFAULT
	releaseall
	end

ShinTokyo_EventScript_JailDoorOpen::
	msgbox ShinTokyo_Text_JailDoorOpens, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@  STEPS 5+6 -- RED ALERT AND THE ARREST (coord-trigger ring around the alley
@  pocket: the player gets a few free steps outside the prison, then any way
@  out of the pocket springs the scene). Choreography-first staging:
@  3 goons converge and surround the player wherever they stand (positions
@  computed from getplayerxy), THE ONI arrives from the north, claims the
@  escort personally, the goons defer and run offscreen -- then a cut, a
@  marched walk to the hideout door with the player in tow, and the ZOROARK
@  illusion drops with the operative and her ZOROARK side by side.
@  Script continues INTO the hideout for the briefing (Shadow Generator lore
@  + the Stop the Machine main quest).
@ ============================================================================
ShinTokyo_EventScript_TryArrest::
	lockall
	setvar VAR_TEMP_3, 1
	goto_if_unset FLAG_ACT3_RED_ALERT, ShinTokyo_EventScript_TryArrestDone
	goto_if_set FLAG_ACT3_ARREST_DONE, ShinTokyo_EventScript_TryArrestDone
	playse SE_EXIT
	msgbox ShinTokyo_Text_RedAlertWail, MSGBOX_DEFAULT
	closemessage
	@ -- the surround: three goons converge on the player's actual tile --
	getplayerxy VAR_0x8004, VAR_0x8005
	copyvar VAR_0x8006, VAR_0x8004
	subvar VAR_0x8006, 3
	setobjectxyperm LOCALID_ARREST_GOON_A, VAR_0x8006, VAR_0x8005
	addobject LOCALID_ARREST_GOON_A
	copyvar VAR_0x8006, VAR_0x8004
	addvar VAR_0x8006, 3
	setobjectxyperm LOCALID_ARREST_GOON_B, VAR_0x8006, VAR_0x8005
	addobject LOCALID_ARREST_GOON_B
	copyvar VAR_0x8007, VAR_0x8005
	addvar VAR_0x8007, 3
	setobjectxyperm LOCALID_ARREST_GOON_C, VAR_0x8004, VAR_0x8007
	addobject LOCALID_ARREST_GOON_C
	applymovement LOCALID_ARREST_GOON_A, ShinTokyo_Movement_GoonConvergeRight
	applymovement LOCALID_ARREST_GOON_B, ShinTokyo_Movement_GoonConvergeLeft
	applymovement LOCALID_ARREST_GOON_C, ShinTokyo_Movement_GoonConvergeUp
	waitmovement LOCALID_ARREST_GOON_A
	waitmovement LOCALID_ARREST_GOON_B
	waitmovement LOCALID_ARREST_GOON_C
	setspeaker SP_NAME_GOON
	msgbox ShinTokyo_Text_GoonsBoxIn, MSGBOX_DEFAULT
	closemessage
	@ -- THE ONI arrives from the north --
	copyvar VAR_0x8007, VAR_0x8005
	subvar VAR_0x8007, 4
	setobjectxyperm LOCALID_ARREST_OFFICER, VAR_0x8004, VAR_0x8007
	addobject LOCALID_ARREST_OFFICER
	applymovement LOCALID_ARREST_OFFICER, ShinTokyo_Movement_OniApproach
	waitmovement LOCALID_ARREST_OFFICER
	applymovement OBJ_EVENT_ID_PLAYER, ShinTokyo_Movement_PlayerFaceUp
	waitmovement 0
	setspeaker SP_NAME_THE_ONI
	msgbox ShinTokyo_Text_ArrestAnnounce, MSGBOX_DEFAULT
	closemessage
	@ -- the goons defer and run offscreen --
	applymovement LOCALID_ARREST_GOON_A, ShinTokyo_Movement_GoonDeferRunLeft
	applymovement LOCALID_ARREST_GOON_B, ShinTokyo_Movement_GoonDeferRunRight
	applymovement LOCALID_ARREST_GOON_C, ShinTokyo_Movement_GoonDeferRunDown
	waitmovement LOCALID_ARREST_GOON_A
	waitmovement LOCALID_ARREST_GOON_B
	waitmovement LOCALID_ARREST_GOON_C
	removeobject LOCALID_ARREST_GOON_A
	removeobject LOCALID_ARREST_GOON_B
	removeobject LOCALID_ARREST_GOON_C
	@ -- the Save Face payoff, compact: the mask comes off on screen --
	checkitem ITEM_CARVED_MASK
	goto_if_eq VAR_RESULT, FALSE, ShinTokyo_EventScript_ArrestNoMask
	setspeaker SP_NAME_THE_ONI
	msgbox ShinTokyo_Text_MaskStripped, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	clearflag FLAG_ONI_MASK_WORN
	special RefreshPlayerAvatarGraphicsIfOnFoot
	delay 20
ShinTokyo_EventScript_ArrestNoMask::
	@ -- cut: THE ONI marches the player to the hideout. Scripts do NOT
	@ survive warps, so this scene ENDS at the warp with the flag already
	@ set; the illusion-drop reveal + briefing replay as the RebelHideout
	@ ON_FRAME scene (gated on FLAG_WOT_HIDEOUT_REVEAL_DONE).
	fadescreen FADE_TO_BLACK
	msgbox ShinTokyo_Text_EscortMarch, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ACT3_ARREST_DONE
	warp MAP_REBEL_HIDEOUT, 7, 8
	waitstate
ShinTokyo_EventScript_TryArrestDone::
	releaseall
	end

@ --- Movement ----------------------------------------------------------------
@ The captain now closes in FROM THE LEFT along the y=24 row (the object was
@ stranded at its pre-MiddleDistrict coords (10,41) -- the whole approach
@ played off-camera, hence "nobody appears").
ShinTokyo_Movement_PlayerFaceLeft:
	face_left
	step_end

ShinTokyo_Movement_PlayerFaceUp:
	face_up
	step_end

ShinTokyo_Movement_CaptainApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ShinTokyo_Movement_CaptainLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

ShinTokyo_Movement_GoonConvergeRight:
	walk_fast_right
	walk_fast_right
	step_end

ShinTokyo_Movement_GoonConvergeLeft:
	walk_fast_left
	walk_fast_left
	step_end

ShinTokyo_Movement_GoonConvergeUp:
	walk_fast_up
	walk_fast_up
	step_end

ShinTokyo_Movement_OniApproach:
	walk_down
	walk_down
	walk_down
	step_end

ShinTokyo_Movement_GoonDeferRunLeft:
	face_up
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

@ Two south, THEN east. He stands at (35,44) with the block at x=36..41 filling
@ rows 42-45, so every step of the old run east was inside a building. Row 46
@ is open right across, so he drops to it first and leaves along the street.
ShinTokyo_Movement_GoonDeferRunRight:
	face_up
	delay_16
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

ShinTokyo_Movement_GoonDeferRunDown:
	delay_16
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
ShinTokyo_Text_CitizenRedAlert::
	.string "{JPN}ちかよらないで！\p"
	.string "まちじゅうの スクリーンに\n"
	.string "あなたの かおが うつってる！$"

ShinTokyo_Text_FerryAsk::
	.string "{JPN}フェリーが さんばしで\n"
	.string "エンジンを かけたまま まっている。\l"
	.string "ここに ふねが くるのは なんねんぶりだ。\p"
	.string "せんいん: こうろが ひらいたので\n"
	.string "いまは バトルフロンティアまで\l"
	.string "でています。\p"
	.string "のっていきますか？$"

ShinTokyo_Text_FerryBoard::
	.string "{JPN}せんいん: あしもとに おきをつけて。\p"
	.string "あそびで この まちから ふねを だす\n"
	.string "ものは いなかった。 あなたが はじめてだ。$"

ShinTokyo_Text_FerryDeclined::
	.string "{JPN}せんいん: いまは まいにち\n"
	.string "ここに います。 うみと きもちが\l"
	.string "あったら また きてください。$"

ShinTokyo_Text_DracoCall::
	.string "{JPN}ドラコ: これで おわりだと おもったか？\n"
	.string "はっ！\p"
	.string "おまえは まだ ミュートリッドの\n"
	.string "ひみつへいきを みてもいない。\p"
	.string "ほんとうの ちからの かいほうを\n"
	.string "みたと おもってるのか？\p"
	.string "げんしの せいめいたいと\n"
	.string "たいめんする じゅんびを しておけ。\p"
	.string "その なも… アーマードミュウツー。\p"
	.string "…\p"
	.string "ゆうぐれに ドックの こやで まってるぜ。$"

ShinTokyo_Text_CitizenFree::
	.string "{JPN}スクリーンは まっくら。\n"
	.string "パトロールも いなくなった。\p"
	.string "それに たいようを みた？\p"
	.string "じゆうだ。 ほんとうに\n"
	.string "じゆうなんだ。$"

ShinTokyo_Text_GoonRedAlert::
	.string "{JPN}そいつは… けんしょうきんの\n"
	.string "スクリーンの かおだ！\p"
	.string "ぜんいん！ ぜんいん しゅうごう！$"

ShinTokyo_Text_Holdout1::
	.string "{JPN}おれたちは まけた。 わかってる。\p"
	.string "けんしょうきんの けいじばんは きえ\n"
	.string "リーダーも いない。 この まちかどが\l"
	.string "おれの すべて だったんだ。\p"
	.string "もう ひとしょうぶ。 この せいふくの ために。$"

ShinTokyo_Text_Holdout2::
	.string "{JPN}そんな めで みるなよ。\p"
	.string "あんたが かった。 かった がわで\n"
	.string "いられるんだ。\p"
	.string "こっちには まだ こいつらが いる。 こいよ。$"

ShinTokyo_Text_Holdout3::
	.string "{JPN}ほかの やつらは みんな バッジを\n"
	.string "かえして いえに かえった。\p"
	.string "かえって なにが ある？ いまでも\n"
	.string "おれに こたえて くれるのは こいつらだけだ。\p"
	.string "なら うばってみろ。$"

ShinTokyo_Text_HoldoutPost::
	.string "{JPN}もっていけ。 ぜんぶ スナッチしろ。\p"
	.string "はじめから おれの ものじゃ なかった。\p"
	.string "あしたも おれは ここに いる。 また\n"
	.string "こいつらが くる。 いつだって そうだ。$"

ShinTokyo_Text_Patrol1Intro::
	.string "{JPN}だつごくしゃ はっけん！\p"
	.string "こいつの たましいは とっくに\n"
	.string "うられてる。 けんしょうきんを いただけ！$"

ShinTokyo_Text_Patrol1Defeat::
	.string "{JPN}けんしょうきんが… にげた…$"

ShinTokyo_Text_Patrol2Intro::
	.string "{JPN}おまえにも きこえるだろ？\p"
	.string "あいつら いま すごく しずかなんだ。\n"
	.string "きかいは しずかなのが すきなんだよ。$"

ShinTokyo_Text_Patrol2Defeat::
	.string "{JPN}うるさい… なんで おまえは そんなに\n"
	.string "うるさいんだ…$"

ShinTokyo_Text_Patrol3Intro::
	.string "{JPN}もんげんだ しみん。\p"
	.string "えいえんにな。$"

ShinTokyo_Text_Patrol3Defeat::
	.string "{JPN}ありえない。 あいつらは もう\n"
	.string "いたみさえ かんじないのに…$"

ShinTokyo_Text_PatrolPost::
	.string "{JPN}パトロールいんは こしの\n"
	.string "からっぽの ボールを みつめている。$"

ShinTokyo_Text_TowerSealed::
	.string "{JPN}ミュートリッドタワー: かんぶよう\n"
	.string "いりぐち。\p"
	.string "ふうさされている。 うえで まつ ものは\n"
	.string "ふれた ものを すべて むに かえす。\p"
	.string "それを うちけす やしろの ちからが\n"
	.string "なければ この とびらは はかばだ。$"

ShinTokyo_Text_BountyScreen::
	.string "{JPN}10かいぶんの ガラスから じぶんの\n"
	.string "かおが みおろしている。\p"
	.string "「しめいてはい: だつごくしゃ。\n"
	.string "けんしょうきん はかりしれず」$"

ShinTokyo_Text_CaptainMask::
	.string "{JPN}その まつりの こどうぐを はずせ。\p"
	.string "「めんは したっぱの\n"
	.string "ための ものだ。$"

ShinTokyo_Text_CaptainHalt::
	.string "{JPN}とおりから あっというまに ひとが きえた。\p"
	.string "ていきけんさだ しみん。\n"
	.string "りょううでを ひろげろ。 バッグを あけろ。$"

ShinTokyo_Text_CaptainNothing::
	.string "{JPN}てぶくろの てが ポケットを\n"
	.string "ひとつずつ ひっくりかえす。 2どずつ。\p"
	.string "…なにも なしか。 ちっ。\p"
	.string "いけ しみん。 まちは きさまの\n"
	.string "じゅうじゅんさに かんしゃする。$"

ShinTokyo_Text_CaptainTakes::
	.string "{JPN}てぶくろの ゆびが すりきれた\n"
	.string "ダークちょうさしりょうの ひょうしで とまった。\p"
	.string "…ほう。 しんだ はかせの\n"
	.string "ひっせきか。\p"
	.string "いまから これは まちの ものだ。\n"
	.string "わたしの けんげんでな。$"

ShinTokyo_Text_DossierTaken::
	.string "{JPN}ダークちょうさしりょうを うばわれた！$"

ShinTokyo_Text_CaptainGloat::
	.string "{JPN}わざわざ ここまで はこんできて\n"
	.string "じきじきに とどけて くれたわけだ。\p"
	.string "タワーは この おんを わすれまい。\n"
	.string "わたしは わすれるがな。$"

ShinTokyo_Text_GengarStateC::
	.string "{JPN}…なくなった。\p"
	.string "あれだけの ことが あったのに。\n"
	.string "いまは あいつの てのなかだ。$"

ShinTokyo_Text_MinisterCall::
	.string "{JPN}だいじん: {ENG}{PLAYER}{JPN}。 しゃべるな\n"
	.string "あるけ。 さりげなくな。\p"
	.string "ミクマンクが つかまった。 ひがしの\n"
	.string "ブロックに いれられている。 あいつは\l"
	.string "やつらに みつかっては いけない ものを\l"
	.string "もっているんだ。\p"
	.string "カメラは おれが のっとった。 しょうめんの\n"
	.string "とびらは おまえが いたことを わすれる。\p"
	.string "あいつを たすけだせ。$"

ShinTokyo_Text_JailDoorSealed::
	.string "{JPN}ひがしブロック こうちしょ。\p"
	.string "ふうさされている。 カメラが\n"
	.string "ウィーンと こちらを むいた。$"

ShinTokyo_Text_JailDoorOpens::
	.string "{JPN}ひがしブロック こうちしょ。\p"
	.string "カメラの ランプは きえている。\n"
	.string "かんぬきは はずれたままだ。$"

ShinTokyo_Text_JailGuard::
	.string "{JPN}こうちしょ。 かんけいしゃ\n"
	.string "いがい たちいり きんし。\p"
	.string "たちどまるな しみん。 まちは\n"
	.string "おまえが あるくのを みているぞ。$"

ShinTokyo_Text_GuardsScatter::
	.string "{JPN}とおりの むこうで ふたつの むせんが\n"
	.string "どうじに ガリガリと なった。\p"
	.string "こうちしょの とびらの みはりたちが\n"
	.string "かおを みあわせ…\p"
	.string "あめの なかへ はなれていった。$"

ShinTokyo_Text_RedAlertWail::
	.string "{JPN}サイレン。\p"
	.string "とおりの スクリーンが いっせいに\n"
	.string "あなたの かおに きりかわった。$"

ShinTokyo_Text_GoonsBoxIn::
	.string "{JPN}しょうきんくびを ほういした！\p"
	.string "えものに さわるな…\n"
	.string "めいれいを まて！$"

ShinTokyo_Text_ArrestAnnounce::
	.string "{JPN}タワーの けんげんに より\n"
	.string "おまえを たいほする。\p"
	.string "しゅうじんは わたしが\n"
	.string "じきじきに れんこうする。$"

ShinTokyo_Text_MaskStripped::
	.string "{JPN}その ハロウィンの かそう。\n"
	.string "はずせ。$"

ShinTokyo_Text_EscortMarch::
	.string "{JPN}オニは ネオンの あめの なかを\n"
	.string "あなたを ひきたてていく。\p"
	.string "とおりの だれも あなたと\n"
	.string "めを あわせない。$"

@ --- The briefing (all PLACEHOLDER (Joe)) -----------------------------------

@ ============================================================================
@  THE BLACK MARKET (alleyway) -- three vendors moving Tradewind department
@  store stock at street prices, plus everything Mutrid outlawed.
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================
ShinTokyo_EventScript_BlackMarketAM::
	lock
	faceplayer
	message ShinTokyo_Text_BlackMarketAM
	waitmessage
	pokemart ShinTokyo_Pokemart_BlackMarketAMs
	msgbox ShinTokyo_Text_BlackMarketBye, MSGBOX_DEFAULT
	release
	end

	.align 2
ShinTokyo_Pokemart_BlackMarketAMs:
	.2byte ITEM_AM_INTIMIDATE
	.2byte ITEM_AM_GUTS
	.2byte ITEM_AM_TECHNICIAN
	.2byte ITEM_AM_MOXIE
	.2byte ITEM_AM_ADAPTABILITY
	.2byte ITEM_AM_SHEER_FORCE
	.2byte ITEM_AM_TOUGH_CLAWS
	.2byte ITEM_AM_IRON_FIST
	.2byte ITEM_AM_TINTED_LENS
	.2byte ITEM_AM_SKILL_LINK
	.2byte ITEM_AM_THICK_FAT
	.2byte ITEM_AM_STURDY
	.2byte ITEM_AM_LEVITATE
	.2byte ITEM_AM_UNAWARE
	.2byte ITEM_AM_SERENE_GRACE
	.2byte ITEM_AM_PRANKSTER
	.2byte ITEM_AM_POISON_HEAL
	.2byte ITEM_AM_MULTISCALE
	.2byte ITEM_AM_MAGIC_GUARD
	.2byte ITEM_AM_REGENERATOR
	.2byte ITEM_AM_SPEED_BOOST
	.2byte ITEM_AM_MAGIC_BOUNCE
	@ Round 115: evolution goods for lines that otherwise need a trade or a stone
	@ WoT never places (Golem, Conkeldurr, Electivire, Magmortar, Milotic,
	@ Poliwrath, Shiftry, Whimsicott). The held ones work from the bag because
	@ I_USE_EVO_HELD_ITEMS_FROM_BAG is TRUE.
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_PRISM_SCALE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_SUN_STONE
	pokemartlistend

ShinTokyo_EventScript_BlackMarketPaw::
	lock
	faceplayer
	message ShinTokyo_Text_BlackMarketPaw
	waitmessage
	pokemart ShinTokyo_Pokemart_BlackMarketPaws
	msgbox ShinTokyo_Text_BlackMarketBye, MSGBOX_DEFAULT
	release
	end

	.align 2
ShinTokyo_Pokemart_BlackMarketPaws:
	.2byte ITEM_MANKEYS_PAW
	.2byte ITEM_PRIMEAPES_PAW
	.2byte ITEM_ANNIHILAPES_PAW
	pokemartlistend

ShinTokyo_EventScript_BlackMarketBalls::
	lock
	faceplayer
	message ShinTokyo_Text_BlackMarketBalls
	waitmessage
	pokemart ShinTokyo_Pokemart_BlackMarketBalls
	msgbox ShinTokyo_Text_BlackMarketBye, MSGBOX_DEFAULT
	release
	end

	.align 2
ShinTokyo_Pokemart_BlackMarketBalls:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_DUSK_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_QUICK_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_FAST_BALL
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_DREAM_BALL
	.2byte ITEM_SAFARI_BALL
	.2byte ITEM_SPORT_BALL
	.2byte ITEM_BEAST_BALL
	.2byte ITEM_SNAG_BALL
	.2byte ITEM_CHERISH_BALL
	pokemartlistend

@ --- hidden valuables -------------------------------------------------------
ShinTokyo_EventScript_ItemAlley::
	finditem ITEM_BIG_NUGGET
	end

ShinTokyo_EventScript_ItemPlaza::
	finditem ITEM_PEARL_STRING
	end

ShinTokyo_Text_BlackMarketAM::
	.string "{JPN}とくせいカプセル。 けんきゅうじょ ひんしつ。\n"
	.string "ミュートリッドの ゆそうたいから おちてきた。\p"
	.string "へんぴん なし。 りょうしゅうしょ なし。\n"
	.string "しつもん なし。$"

ShinTokyo_Text_BlackMarketPaw::
	.string "{JPN}これの あつかいには きを つけな。\p"
	.string "さるのては ねがった とおりの ものを\n"
	.string "あたえる。 そこが もんだいなのさ。$"

ShinTokyo_Text_BlackMarketBalls::
	.string "{JPN}ありとあらゆる ボールが あるよ。\n"
	.string "ミュートリッドは ほかくを きんしした からね。$"

ShinTokyo_Text_BlackMarketBye::
	.string "{JPN}あんたは ここに こなかった。$"

@ --- the jumbotron objects (sign interactions reuse the screen texts) -------
ShinTokyo_EventScript_LeaderScreen::
	msgbox ShinTokyo_Text_PropagandaScreen, MSGBOX_SIGN
	end

ShinTokyo_EventScript_WantedScreen::
	msgbox ShinTokyo_Text_BountyScreen, MSGBOX_SIGN
	end

@ --- THE MINISTER (in the flesh, east side) ---------------------------------
ShinTokyo_EventScript_Minister::
	lock
	faceplayer
	setspeaker SP_NAME_MINISTER
	questmenu QUEST_MENU_CHECK_ACTIVE, SIDE_QUEST_MINISTERS_FAVOR
	goto_if_eq VAR_RESULT, TRUE, ShinTokyo_EventScript_MinisterSettle
	@ Favor settled: he trades in rumors now -- the Ryuden Island lead.
	questmenu QUEST_MENU_CHECK_COMPLETE, SIDE_QUEST_MINISTERS_FAVOR
	goto_if_eq VAR_RESULT, TRUE, ShinTokyo_EventScript_MinisterRyuden
	msgbox ShinTokyo_Text_MinisterIdle, MSGBOX_DEFAULT
	goto ShinTokyo_EventScript_MinisterMegaTrade
	end

ShinTokyo_EventScript_MinisterRyuden::
	msgbox ShinTokyo_Text_MinisterRyuden, MSGBOX_DEFAULT
	goto ShinTokyo_EventScript_MinisterMegaTrade
	end

ShinTokyo_EventScript_MinisterSettle::
	goto_if_unset FLAG_ACT3_MIKMANC_FREED, ShinTokyo_EventScript_MinisterWaiting
	msgbox ShinTokyo_Text_MinisterSettle, MSGBOX_DEFAULT
	closemessage
	completequest SIDE_QUEST_MINISTERS_FAVOR
	giveitem ITEM_SNAG_BALL, 15
	giveitem ITEM_CATCHING_CHARM
	msgbox ShinTokyo_Text_MinisterAfter, MSGBOX_DEFAULT
	goto ShinTokyo_EventScript_MinisterMegaTrade
	end

ShinTokyo_EventScript_MinisterWaiting::
	msgbox ShinTokyo_Text_MinisterWaiting, MSGBOX_DEFAULT
	goto ShinTokyo_EventScript_MinisterMegaTrade
	end

@ --- THE MINISTER'S MEGA STONE TRADE ----------------------------------------
@ Reached by falling through from EVERY one of his quest branches above, so his
@ story lines always play first and this is offered afterwards.
@
@ He deals in the stone for whatever is at the FRONT of the party, priced at a
@ flat 10,000. WotGetPartyLeaderMegaStone looks the stone up in that species'
@ own form-change table, so a species with no Mega simply has nothing to sell
@ and he says so -- the sale can never go through for a Pokemon that cannot
@ Mega Evolve. Doing it this way puts every Mega Stone in the build behind one
@ NPC instead of scattering them across the world.

ShinTokyo_EventScript_MinisterMegaTrade::
	@ Resolve what the lead Pokemon can use. The special buffers STR_VAR_1 with
	@ its name and STR_VAR_2/3 with the stone names, returns the stone selected
	@ by VAR_0x8004, and reports how many exist in VAR_0x8006.
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, WotGetPartyLeaderMegaStone
	copyvar VAR_TEMP_1, VAR_RESULT
	copyvar VAR_TEMP_2, VAR_0x8006
	goto_if_eq VAR_TEMP_1, ITEM_NONE, ShinTokyo_EventScript_MinisterMegaNoStone
	@ Six species (Charizard/Raichu/Mewtwo X-Y, and the Z stones for Absol,
	@ Garchomp and Lucario) have two. Let the player pick rather than quietly
	@ handing over the first -- otherwise those six stones are unobtainable.
	goto_if_ge VAR_TEMP_2, 2, ShinTokyo_EventScript_MinisterMegaTwoStones
	@ Buffer the name HERE too. The two-stone path already did this and read
	@ correctly; this one leaned on the C helper alone and showed a blank.
	bufferitemname STR_VAR_2, VAR_TEMP_1
	msgbox ShinTokyo_Text_MinisterMegaOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShinTokyo_EventScript_MinisterMegaDeclined
	goto ShinTokyo_EventScript_MinisterMegaBuy
	end

ShinTokyo_EventScript_MinisterMegaTwoStones::
	message ShinTokyo_Text_MinisterMegaChoose
	waitmessage
	@ The rows are {STR_VAR_2}/{STR_VAR_3} placeholders -- dynmultichoice runs
	@ StringExpandPlaceholders over each row, so they resolve to the two stone
	@ names the special just buffered.
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, ShinTokyo_Text_MinisterMegaStoneA, ShinTokyo_Text_MinisterMegaStoneB, ShinTokyo_Text_MinisterMegaStoneNone
	switch VAR_RESULT
	case 0, ShinTokyo_EventScript_MinisterMegaPickA
	case 1, ShinTokyo_EventScript_MinisterMegaPickB
	case 2, ShinTokyo_EventScript_MinisterMegaDeclined
	case MULTI_B_PRESSED, ShinTokyo_EventScript_MinisterMegaDeclined
	end

ShinTokyo_EventScript_MinisterMegaPickA::
	setvar VAR_0x8004, 0
	goto ShinTokyo_EventScript_MinisterMegaReselect
	end

ShinTokyo_EventScript_MinisterMegaPickB::
	setvar VAR_0x8004, 1
	goto ShinTokyo_EventScript_MinisterMegaReselect
	end

ShinTokyo_EventScript_MinisterMegaReselect::
	specialvar VAR_RESULT, WotGetPartyLeaderMegaStone
	copyvar VAR_TEMP_1, VAR_RESULT
	bufferitemname STR_VAR_2, VAR_TEMP_1
	msgbox ShinTokyo_Text_MinisterMegaOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShinTokyo_EventScript_MinisterMegaDeclined
	goto ShinTokyo_EventScript_MinisterMegaBuy
	end

@ Common purchase path. VAR_TEMP_1 holds the chosen stone by the time we arrive.
ShinTokyo_EventScript_MinisterMegaBuy::
	@ Last line of defence: VAR_TEMP_1 is about to be handed to additem,
	@ and additem with an id outside the item table is a hard crash. If
	@ anything upstream failed to resolve a stone, say so instead.
	goto_if_eq VAR_TEMP_1, ITEM_NONE, ShinTokyo_EventScript_MinisterMegaNoStone
	checkmoney MINISTER_MEGA_STONE_PRICE
	goto_if_eq VAR_RESULT, FALSE, ShinTokyo_EventScript_MinisterMegaNoMoney
	@ The bag work happens in C, where the id is checked before anything
	@ touches the item table. `additem VAR_TEMP_1, 1` could not check it and
	@ took the game down on a bad id.
	copyvar VAR_0x8005, VAR_TEMP_1
	specialvar VAR_RESULT, WotBuyLeaderMegaStone
	goto_if_eq VAR_RESULT, FALSE, ShinTokyo_EventScript_MinisterMegaNoRoom
	removemoney MINISTER_MEGA_STONE_PRICE
	playfanfare MUS_OBTAIN_ITEM
	message ShinTokyo_Text_MinisterMegaSold
	waitmessage
	waitfanfare
	msgbox ShinTokyo_Text_MinisterMegaThanks, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_MinisterMegaNoStone::
	msgbox ShinTokyo_Text_MinisterMegaNoStone, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_MinisterMegaNoMoney::
	msgbox ShinTokyo_Text_MinisterMegaNoMoney, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_MinisterMegaNoRoom::
	call Common_EventScript_BagIsFull
	release
	end

ShinTokyo_EventScript_MinisterMegaDeclined::
	msgbox ShinTokyo_Text_MinisterMegaDeclined, MSGBOX_DEFAULT
	release
	end

@ --- city Pokemon ------------------------------------------------------------
ShinTokyo_EventScript_MonWeezing::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WEEZING_GALAR, CRY_MODE_NORMAL
	waitmoncry
	msgbox ShinTokyo_Text_MonWeezing, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_MonKoffing::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KOFFING, CRY_MODE_NORMAL
	waitmoncry
	msgbox ShinTokyo_Text_MonKoffing, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_MonGrimer::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GRIMER, CRY_MODE_NORMAL
	waitmoncry
	msgbox ShinTokyo_Text_MonGrimer, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_MonRevavroom::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REVAVROOM, CRY_MODE_NORMAL
	waitmoncry
	msgbox ShinTokyo_Text_MonRevavroom, MSGBOX_DEFAULT
	release
	end

ShinTokyo_EventScript_SmallPoster::
	msgbox ShinTokyo_Text_SmallPoster, MSGBOX_SIGN
	end

ShinTokyo_Text_MinisterIdle::
	.string "{JPN}おや きみか。\p"
	.string "まちを たのしむと いい。 まちは\n"
	.string "きみが たのしんだ ものを すべて かぞえている。$"

ShinTokyo_Text_MinisterSettle::
	.string "{JPN}おんは わすれない たちでね\n"
	.string "{ENG}{PLAYER}{JPN}。\p"
	.string "これで ふたりとも おたずねものだ。\n"
	.string "なかなか イカしてるだろ？$"

ShinTokyo_Text_MinisterAfter::
	.string "{JPN}あしもとに きを つけて あるけ。\p"
	.string "オニは うらぎりを\n"
	.string "ゆるさない。\p"
	.string "(だいじんは タバコを\n"
	.string "ふみけした)$"

ShinTokyo_Text_MinisterRyuden::
	.string "{JPN}よしみで ひとつ うわさを。\p"
	.string "ここから はるか ひがしに りゅうでんじま\n"
	.string "が ある。 りゅうの ばんにんたちの\l"
	.string "やしろだ。\p"
	.string "なみのりで みなみへ いき しまじまを\n"
	.string "ぬける うみのみちを たどれ。\p"
	.string "ちずが とぎれる さきへ すすめ。$"

ShinTokyo_Text_MonWeezing::
	.string "{JPN}マタドガスが こうじょうの はいきこうから\n"
	.string "すいこんでいる。\p"
	.string "この とおりの だれよりも\n"
	.string "げんきそうに みえる。$"

ShinTokyo_Text_MonKoffing::
	.string "{JPN}ドガースが ろじを ふわふわと ただよい\n"
	.string "すっかり くつろいでいる。$"

ShinTokyo_Text_MonGrimer::
	.string "{JPN}ベトベターが あまみずの はいすいこうから\n"
	.string "にじみでてきた。\p"
	.string "てを ふっている。 ていねいに。$"

ShinTokyo_Text_MonRevavroom::
	.string "{JPN}ブロロロームが みちばたで アイドリングし\n"
	.string "とおる くるまに エンジンを ふかしている。\p"
	.string "うんてんしゅは いない。\n"
	.string "うんてんしゅなど いらない。$"

ShinTokyo_Text_SmallPoster::
	.string "{JPN}しめいてはい: テロリスト\n"
	.string "「{ENG}{PLAYER}{JPN}」。\p"
	.string "けんしょうきん: 1000000円。\n"
	.string "せっしょくには ちゅういせよ。$"

ShinTokyo_Text_MinisterWaiting::
	.string "{JPN}おれが あけた ろうやには まだ\n"
	.string "ひとが いるぞ {ENG}{PLAYER}{JPN}。\p"
	.string "しごとを かたづけろ。$"

ShinTokyo_Text_MinisterMegaOffer::
	.string "{JPN}てもちの せんとうに いる {ENG}{STR_VAR_1}{JPN}…\n"
	.string "そいつだよ。\p"
	.string "そいつ むけの\n"
	.string "{ENG}{STR_VAR_2}{JPN}を 10000円で ゆずるぜ。\p"
	.string "しつもん なし しょるい なし。\n"
	.string "どうだい？$"

ShinTokyo_Text_MinisterMegaSold::
	.string "{JPN}{ENG}{PLAYER}{JPN}は おかねを わたして\n"
	.string "{ENG}{STR_VAR_2}{JPN}を うけとった！$"

ShinTokyo_Text_MinisterMegaThanks::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}に もたせておけば\n"
	.string "あとは かってに うまくいく。\p"
	.string "また せんとうに べつのを つれてくれば\n"
	.string "そのときに はなそう。$"

ShinTokyo_Text_MinisterMegaNoStone::
	.string "{JPN}おれが あつかうのは メガストーンだ。\p"
	.string "てもちの せんとうの そいつには\n"
	.string "メガシンカの すがたが ない。 そいつ\l"
	.string "むけの いしは この よに ない。\p"
	.string "べつの やつを せんとうに して\n"
	.string "また きな。$"

ShinTokyo_Text_MinisterMegaNoMoney::
	.string "{JPN}10000円。 1円も まけない。\p"
	.string "もちあわせが できたら きな。$"

ShinTokyo_Text_MinisterMegaDeclined::
	.string "{JPN}すきに しな。\p"
	.string "はなしは いつでも うけるぜ。$"

ShinTokyo_Text_MinisterMegaChoose::
	.string "{JPN}けずった いしが 2つ ある。\n"
	.string "どちらも {ENG}{STR_VAR_1}{JPN}むけだ。 えらびな。$"

ShinTokyo_Text_MinisterMegaStoneA::
	.string "{JPN}{ENG}{STR_VAR_2}{JPN}$"

ShinTokyo_Text_MinisterMegaStoneB::
	.string "{JPN}{ENG}{STR_VAR_3}{JPN}$"

ShinTokyo_Text_MinisterMegaStoneNone::
	.string "{JPN}どちらも いらない$"

