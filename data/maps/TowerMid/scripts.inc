TowerMid_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TowerMid_OnTransition
	.byte 0

@ Any loss inside the tower sends the player back to the Rebel Hideout: the
@ tower has no healing of its own and the district below it is hostile.
TowerMid_OnTransition::
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	end

@ ============================================================================
@  MUTRID TOWER -- UPPER FLOORS (shell). One gatekeeper: SUZAKU, the vermilion
@  bird of the tower's guardian-beast duelists (Lv49-51, Shadow HO-OH ace).
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================

TowerMid_EventScript_StairsDown::
	lockall
	warp MAP_TOWER_STREET, 4, 4
	waitstate
	releaseall
	end

@ The stairwell gate only releases once the floor's guardian is down.
TowerMid_EventScript_StairsUp::
	lockall
	goto_if_not_defeated TRAINER_SYLVIA, TowerMid_EventScript_StairsSealed
	warp MAP_TOWER_COMMAND, 7, 12
	waitstate
	releaseall
	end

TowerMid_EventScript_StairsSealed::
	msgbox TowerMid_Text_StairsSealed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TowerMid_Movement_StepBack
	waitmovement 0
	setvar VAR_TEMP_8, 0
	releaseall
	end

TowerMid_Movement_StepBack:
	walk_down
	step_end

TowerMid_EventScript_Suzaku::
	trainerbattle_single TRAINER_SYLVIA, TowerMid_Text_SuzakuIntro, TowerMid_Text_SuzakuDefeat
	msgbox TowerMid_Text_SuzakuPost, MSGBOX_AUTOCLOSE
	call Wot_EventScript_SnagProgress
	end

TowerMid_Text_SuzakuIntro::
	.string "{JPN}ビャッコの つめが おれたか。\p"
	.string "わたしは スザク。 この タワーの\n"
	.string "つばさは みな わたしの よびかけに こたえる…\p"
	.string "そらから ひきずりおろされ やみに\n"
	.string "ふういんされた にじいろの\l"
	.string "つばさでさえも。\p"
	.string "ともに もえつきよ。$"

TowerMid_Text_SuzakuDefeat::
	.string "{JPN}…にじいろさえ…\n"
	.string "きえて しまった…$"

TowerMid_Text_SuzakuPost::
	.string "{JPN}うえの フロアは ミュートリッドアルファが\n"
	.string "まもっている。 あれほど かたい まもりは ない。\p"
	.string "いけ。 わたしの はねは はいに なった。$"

TowerMid_Text_StairsSealed::
	.string "{JPN}かいだんの ゲートは フロアの\n"
	.string "セキュリティで ロックされている。\p"
	.string "この フロアの ばんにんが\n"
	.string "まだ たっている。$"
