	.equ LOCALID_TOWER_CAPTAIN, 1

TowerCommand_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TowerCommand_OnTransition
	.byte 0

@ Any loss inside the tower sends the player back to the Rebel Hideout: the
@ tower has no healing of its own and the district below it is hostile.
TowerCommand_OnTransition::
	setrespawn HEAL_LOCATION_REBEL_HIDEOUT
	end

@ ============================================================================
@  MUTRID TOWER -- COMMAND FLOOR: the final badge, held by THE CAPTAIN who
@  took the Shadow Dossier at street level (Step 2). Recognizes the player;
@  on the kept-then-stolen path he gives thanks for the research -- his
@  Shadows are its children. Lv54-55 team. Victory: FINAL BADGE
@  (FLAG_BADGE08_GET) + the MASTER BALL (canon: the finale's snag of Shadow
@  Jirachi depends on it). The lift up refuses until the badge is won.
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================

TowerCommand_EventScript_StairsDown::
	lockall
	warp MAP_TOWER_MID, 6, 4
	waitstate
	releaseall
	end

TowerCommand_EventScript_LiftUp::
	lockall
	goto_if_set FLAG_BADGE08_GET, TowerCommand_EventScript_LiftOpen
	msgbox TowerCommand_Text_LiftSealed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TowerCommand_Movement_StepBack
	waitmovement 0
	setvar VAR_TEMP_8, 0
	releaseall
	end

TowerCommand_EventScript_LiftOpen::
	@ (8,11) arrived at the map's south lip -- too low to see THE ONI at the
	@ machine. Land mid-roof; the stairs-down triggers stay as the way back.
	warp MAP_TOWER_TOP, 8, 9
	waitstate
	releaseall
	end

TowerCommand_Movement_StepBack:
	walk_down
	step_end

TowerCommand_EventScript_Captain::
	lock
	faceplayer
	goto_if_defeated TRAINER_KATHLEEN, TowerCommand_EventScript_CaptainPost
	setspeaker SP_NAME_MUTRID_CAPTAIN
	msgbox TowerCommand_Text_Captain1, MSGBOX_DEFAULT
	goto_if_unset FLAG_ACT3_RESEARCH_STOLEN, TowerCommand_EventScript_CaptainNoResearch
	msgbox TowerCommand_Text_CaptainThanks, MSGBOX_DEFAULT
	goto TowerCommand_EventScript_CaptainChallenge
TowerCommand_EventScript_CaptainNoResearch::
	msgbox TowerCommand_Text_CaptainNoResearch, MSGBOX_DEFAULT
TowerCommand_EventScript_CaptainChallenge::
	msgbox TowerCommand_Text_CaptainChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KATHLEEN, TowerCommand_Text_CaptainDefeat
	setspeaker SP_NAME_MUTRID_CAPTAIN
	msgbox TowerCommand_Text_CaptainConcede, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_BADGE
	msgbox TowerCommand_Text_ReceivedBadge, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_BADGE08_GET
	setspeaker SP_NAME_MUTRID_CAPTAIN
	msgbox TowerCommand_Text_CaptainMasterBall, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox TowerCommand_Text_CaptainAfter, MSGBOX_DEFAULT
	release
	end

TowerCommand_EventScript_CaptainPost::
	setspeaker SP_NAME_MUTRID_CAPTAIN
	msgbox TowerCommand_Text_CaptainRematch, MSGBOX_DEFAULT
	release
	end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
TowerCommand_Text_Captain1::
	.string "{JPN}…まちの けんさで おとなしく\n"
	.string "したがった しみんか。\p"
	.string "りょううでを ひろげ バッグを あけ\n"
	.string "じっと うごかなかったな。\p"
	.string "それが いまや めんの かわりに\n"
	.string "しょうきんくびを かかげて わたしの\l"
	.string "フロアに たっている。$"

TowerCommand_Text_CaptainThanks::
	.string "{JPN}れいを いって いなかったな。\p"
	.string "はかせの けんきゅうを…\n"
	.string "この てぶくろに じきじきに とどけてくれた。\p"
	.string "した の フロアで うまれた ダークポケモンは\n"
	.string "みな その けんきゅうの こどもだ。\p"
	.string "おまえが たたかうのは かれの\n"
	.string "しょうがいの しごと。 そして わたしの。$"

TowerCommand_Text_CaptainNoResearch::
	.string "{JPN}おまえは かつて はかせの ひみつを\n"
	.string "われらから まもりぬいた。\p"
	.string "それで ながれは おそくなった。 だが\n"
	.string "かわりは しなかった。$"

TowerCommand_Text_CaptainChallenge::
	.string "{JPN}タワーは わたしに さいごの\n"
	.string "バッジを たくした。\p"
	.string "わたしから うばうか きかいの えさに なるか。\n"
	.string "とびらは その ふたつだ。$"

TowerCommand_Text_CaptainDefeat::
	.string "{JPN}…ならば しょうりの けんりに\n"
	.string "より。$"

TowerCommand_Text_CaptainConcede::
	.string "{JPN}まもりきったか。 みごとに。\p"
	.string "タワーには タワーの おきてが ある。\n"
	.string "まもりてを うちまかした ものが まもる。$"

TowerCommand_Text_ReceivedBadge::
	.string "{JPN}{ENG}{PLAYER}{JPN}は さいごの バッジ\n"
	.string "タワーバッジを てにいれた！$"

TowerCommand_Text_CaptainMasterBall::
	.string "{JPN}…そして これを。 タワーの\n"
	.string "さいごの あんぜんそうち。 けっして\l"
	.string "しっぱいしない ボールだ。\p"
	.string "えいえんに まもれと\n"
	.string "めいじられていた。\p"
	.string "だが おまえが これで なにを するのか\n"
	.string "みてみたい。$"

TowerCommand_Text_CaptainAfter::
	.string "{JPN}リフトは ひらいている。\p"
	.string "あの かたは うえで じぶんの\n"
	.string "きかいの そばで まっている。\p"
	.string "いつだって まっているのだ。$"

TowerCommand_Text_CaptainRematch::
	.string "{JPN}バッジは ほんもの。 リフトは\n"
	.string "ひらいている。\p"
	.string "うえで まつ ものは もはや\n"
	.string "わたしの おきての およばぬ ものだ。$"

TowerCommand_Text_LiftSealed::
	.string "{JPN}かんぶようの リフトは バッジケースを\n"
	.string "よみとり うけつけなかった。\p"
	.string "ミュートリッドアルファの さいごの バッジしか\n"
	.string "かぎとして みとめないようだ。$"
