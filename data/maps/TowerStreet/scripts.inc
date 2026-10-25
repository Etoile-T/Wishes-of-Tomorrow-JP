TowerStreet_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TowerStreet_OnTransition
	.byte 0

@ Any loss inside the tower sends the player back to the Rebel Hideout: the
@ tower has no healing of its own and the district below it is hostile.
TowerStreet_OnTransition::
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	end

@ ============================================================================
@  MUTRID TOWER -- STREET LEVEL (shell). One gatekeeper: THE WHITE TIGER,
@  first of the tower's guardian-beast duelists (Lv44-46, Shadow RAIKOU ace).
@  Ascent: district door (24,4) -> here -> Mid -> Command (Badge 8) -> Top.
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================

TowerStreet_EventScript_ExitToDistrict::
	lockall
	@ (24,5) was the PRE-repaint district door; the tower door now sits at
	@ (10,39) -- land one tile south of it.
	warp MAP_SHIN_TOKYO, 10, 40
	waitstate
	releaseall
	end

@ The stairwell gate only releases once the floor's guardian is down.
TowerStreet_EventScript_StairsUp::
	lockall
	goto_if_not_defeated TRAINER_BLAKE, TowerStreet_EventScript_StairsSealed
	warp MAP_TOWER_MID, 6, 10
	waitstate
	releaseall
	end

TowerStreet_EventScript_StairsSealed::
	msgbox TowerStreet_Text_StairsSealed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TowerStreet_Movement_StepBack
	waitmovement 0
	setvar VAR_TEMP_8, 0
	releaseall
	end

TowerStreet_Movement_StepBack:
	walk_down
	step_end

@ SIGHT RADIUS IS 2, NOT 4, AND MUST STAY <= 2.
@ The player arrives from Shin-Tokyo at (4,8); the White Tiger stands at (4,5)
@ on the same column with a clear line between. At radius 4 he sighted the
@ player on the frame the warp landed, firing a trainer battle while the map
@ was still coming up. Radius 2 stops his cone one tile short of the door, so
@ the player has to step in before he reacts -- the ambush survives, the
@ arrival is quiet. TowerMid gets away with radius 4 only because its door is
@ five tiles from its guard.
@
@ The return trip from TowerMid lands at (4,4), one tile from him, but the
@ stairs are sealed until he is beaten, so by then he no longer sights.
TowerStreet_EventScript_WhiteTiger::
	trainerbattle_single TRAINER_BLAKE, TowerStreet_Text_WhiteTigerIntro, TowerStreet_Text_WhiteTigerDefeat
	msgbox TowerStreet_Text_WhiteTigerPost, MSGBOX_AUTOCLOSE
	call Wot_EventScript_SnagProgress
	end

TowerStreet_Text_WhiteTigerIntro::
	.string "{JPN}タワーには 4たいの けものが いる。\p"
	.string "わたしは ビャッコ。 その\n"
	.string "あしもとの つめだ。\p"
	.string "わが てもちの いかずちは さけびながら\n"
	.string "ふういんされた。 それでも\l"
	.string "わたしの ために たたかう。\p"
	.string "こい。 ひきさいてやる。$"

TowerStreet_Text_WhiteTigerDefeat::
	.string "{JPN}…つめが… おれた。$"

TowerStreet_Text_WhiteTigerPost::
	.string "{JPN}かいだんを のぼれ。\p"
	.string "うえの とりは わたしの うなりより\n"
	.string "うつくしく うたう。 ほのおも\l"
	.string "もっと あつい。$"

TowerStreet_Text_StairsSealed::
	.string "{JPN}かいだんの ゲートは フロアの\n"
	.string "セキュリティで ロックされている。\p"
	.string "この フロアの ばんにんが\n"
	.string "まだ たっている。$"
