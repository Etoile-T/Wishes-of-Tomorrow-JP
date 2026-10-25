MunenLabAct2_MapScripts::
	.byte 0

@ ============================================================================
@  CLARKSON'S LABORATORY -- ACT 2 (occupied Munen)
@  Per Gengar-Clarkson's guidance, the player comes here to destroy the
@  research. DRACO got here first (local ID 1, top center, guarding the
@  desk). Battle him (starter-based variant, like Torii; earlyrival battle:
@  WIN OR LOSE the story continues, party is healed after) -- either way he
@  has already memorized the research and flees to SHIN-TOKYO to sell it to
@  the Dark Lord.
@  The ORIGINAL document remains: the desk offers a physical choice --
@  Keep the Research (ITEM_SHADOW_DOSSIER, readable from the bag) or
@  Destroy the Research (no item; the lore is learned along the way, so
@  nothing is missable). B on the menu defers the choice.
@ ============================================================================

@ Trigger row (y=8, VAR_TEMP_1 == 0). Also guards against refire after flee.
MunenLabAct2_EventScript_DracoTrigger::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_ACT2_LAB_DRACO_FLED, MunenLabAct2_EventScript_TriggerDone
	lockall
	playbgm MUS_DP_VS_GALACTIC, FALSE
	playse SE_PIN
	applymovement 1, MunenLabAct2_Movement_Exclaim
	waitmovement 0
	@ Pan the camera up to Draco at the desk (player is on the y=8 trigger row).
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, MunenLabAct2_Movement_CameraPanUp
	waitmovement 0
	setspeaker SP_NAME_DRACO
	msgbox MunenLabAct2_Text_DracoIntro1, MSGBOX_DEFAULT
	msgbox MunenLabAct2_Text_DracoIntro2, MSGBOX_DEFAULT
	closemessage
	@ Pan back to the player before the battle (never remove a panned camera!).
	applymovement LOCALID_CAMERA, MunenLabAct2_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	goto_if_eq VAR_STARTER_CHOICE, 1, MunenLabAct2_EventScript_BattleAurorus
	goto_if_eq VAR_STARTER_CHOICE, 2, MunenLabAct2_EventScript_BattleArmaldo
	goto MunenLabAct2_EventScript_BattleTyrantrum

MunenLabAct2_EventScript_TriggerDone::
	end

MunenLabAct2_EventScript_BattleAurorus::
	trainerbattle_earlyrival TRAINER_DRACO_LAB_AURORUS, RIVAL_BATTLE_HEAL_AFTER, MunenLabAct2_Text_DracoDefeat, MunenLabAct2_Text_DracoVictory
	goto MunenLabAct2_EventScript_DracoFlees

MunenLabAct2_EventScript_BattleArmaldo::
	trainerbattle_earlyrival TRAINER_DRACO_LAB_ARMALDO, RIVAL_BATTLE_HEAL_AFTER, MunenLabAct2_Text_DracoDefeat, MunenLabAct2_Text_DracoVictory
	goto MunenLabAct2_EventScript_DracoFlees

MunenLabAct2_EventScript_BattleTyrantrum::
	trainerbattle_earlyrival TRAINER_DRACO_LAB_TYRANTRUM, RIVAL_BATTLE_HEAL_AFTER, MunenLabAct2_Text_DracoDefeat, MunenLabAct2_Text_DracoVictory
	goto MunenLabAct2_EventScript_DracoFlees

MunenLabAct2_EventScript_DracoFlees::
	setspeaker SP_NAME_DRACO
	msgbox MunenLabAct2_Text_DracoFlee, MSGBOX_DEFAULT
	closemessage
	applymovement 1, MunenLabAct2_Movement_DracoFlee
	waitmovement 0
	playse SE_EXIT
	removeobject 1
	setflag FLAG_ACT2_LAB_DRACO_FLED
	fadedefaultbgm
	msgbox MunenLabAct2_Text_AfterFlee, MSGBOX_DEFAULT
	@ Gengar-Clarkson insists the research be dealt with before leaving.
	@ While FLAG_ACT2_RESEARCH_RESOLVED is unset, the exit row (y=11) is gated.
	setspeaker SP_NAME_GENGAR
	showportrait PORTRAIT_CLARKSON_GENGAR
	msgbox MunenLabAct2_Text_GengarGate, MSGBOX_DEFAULT
	closemessage
	hideportrait
	releaseall
	end

@ Talking to Draco directly (before stepping on the trigger row).
MunenLabAct2_EventScript_Draco::
	lock
	faceplayer
	setvar VAR_TEMP_1, 1
	playbgm MUS_DP_VS_GALACTIC, FALSE
	setspeaker SP_NAME_DRACO
	msgbox MunenLabAct2_Text_DracoIntro1, MSGBOX_DEFAULT
	msgbox MunenLabAct2_Text_DracoIntro2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_STARTER_CHOICE, 1, MunenLabAct2_EventScript_BattleAurorus
	goto_if_eq VAR_STARTER_CHOICE, 2, MunenLabAct2_EventScript_BattleArmaldo
	goto MunenLabAct2_EventScript_BattleTyrantrum

@ --------------------------------------------------------------------------
@  The desk: the physical choice.
@ --------------------------------------------------------------------------
MunenLabAct2_EventScript_ResearchDesk::
	lockall
	goto_if_set FLAG_ACT2_RESEARCH_RESOLVED, MunenLabAct2_EventScript_DeskResolved
	goto_if_unset FLAG_ACT2_LAB_DRACO_FLED, MunenLabAct2_EventScript_DeskBlocked
	msgbox MunenLabAct2_Text_DeskChoice, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_KEEP_DESTROY_RESEARCH, FALSE
	switch VAR_RESULT
	case 0, MunenLabAct2_EventScript_KeepResearch
	case 1, MunenLabAct2_EventScript_DestroyResearch
	@ B button: decide later
	msgbox MunenLabAct2_Text_DeskDeferred, MSGBOX_DEFAULT
	releaseall
	end

MunenLabAct2_EventScript_KeepResearch::
	giveitem ITEM_SHADOW_DOSSIER
	setflag FLAG_ACT2_RESEARCH_RESOLVED
	msgbox MunenLabAct2_Text_KeptResearch, MSGBOX_DEFAULT
	releaseall
	end

MunenLabAct2_EventScript_DestroyResearch::
	msgbox MunenLabAct2_Text_DestroyResearch1, MSGBOX_DEFAULT
	closemessage
	playse SE_M_FLAME_WHEEL
	fadescreen FADE_TO_WHITE
	delay 20
	fadescreen FADE_FROM_WHITE
	setflag FLAG_ACT2_RESEARCH_RESOLVED
	msgbox MunenLabAct2_Text_DestroyResearch2, MSGBOX_DEFAULT
	releaseall
	end

MunenLabAct2_EventScript_DeskBlocked::
	msgbox MunenLabAct2_Text_DeskBlocked, MSGBOX_DEFAULT
	releaseall
	end

MunenLabAct2_EventScript_DeskResolved::
	checkitem ITEM_SHADOW_DOSSIER
	goto_if_eq VAR_RESULT, TRUE, MunenLabAct2_EventScript_DeskEmptyKept
	msgbox MunenLabAct2_Text_DeskAshes, MSGBOX_DEFAULT
	releaseall
	end

MunenLabAct2_EventScript_DeskEmptyKept::
	msgbox MunenLabAct2_Text_DeskEmptyKept, MSGBOX_DEFAULT
	releaseall
	end

@ --------------------------------------------------------------------------
@  Exit gate: Gengar won't let the player walk out into occupied Munen until
@  the research choice is made -- and the desk is blocked until Draco is
@  beaten, so the battle is mandatory before the village opens up. Trigger
@  row at y=11 (in front of the y=12 warps), fires on VAR_TEMP_2 == 0 every
@  step; inert once the research is resolved, so it never re-arms.
@ --------------------------------------------------------------------------
MunenLabAct2_EventScript_ExitGate::
	goto_if_set FLAG_ACT2_RESEARCH_RESOLVED, MunenLabAct2_EventScript_ExitGateInert
	lockall
	setspeaker SP_NAME_GENGAR
	showportrait PORTRAIT_CLARKSON_GENGAR
	msgbox MunenLabAct2_Text_GengarGateNudge, MSGBOX_DEFAULT
	closemessage
	hideportrait
	applymovement OBJ_EVENT_ID_PLAYER, MunenLabAct2_Movement_GateStepBack
	waitmovement 0
	releaseall
	end

MunenLabAct2_EventScript_ExitGateInert::
	end

MunenLabAct2_Movement_GateStepBack:
	walk_up
	step_end

@ Using the kept dossier from the bag (dispatched from src/item_use.c):
@ Read (repeatable) / Destroy (confirmed, removes the item) / Cancel.
@ Destroying leaves the canonical Act 3 state -- FLAG_ACT2_RESEARCH_RESOLVED
@ set, ITEM_SHADOW_DOSSIER absent -- identical to destroying it at the desk.
MunenLabAct2_EventScript_DossierBagMenu::
	lockall
	multichoice 20, 6, MULTI_READ_DESTROY_RESEARCH, FALSE
	switch VAR_RESULT
	case 0, MunenLabAct2_EventScript_ReadDossier
	case 1, MunenLabAct2_EventScript_BagDestroyConfirm
	releaseall
	end

MunenLabAct2_EventScript_BagDestroyConfirm::
	msgbox MunenLabAct2_Text_BagDestroyConfirm, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_ne MunenLabAct2_EventScript_BagDestroyDeclined
	closemessage
	playse SE_M_FLAME_WHEEL
	fadescreen FADE_TO_WHITE
	delay 20
	fadescreen FADE_FROM_WHITE
	removeitem ITEM_SHADOW_DOSSIER
	msgbox MunenLabAct2_Text_BagDestroyed, MSGBOX_DEFAULT
	releaseall
	end

MunenLabAct2_EventScript_BagDestroyDeclined::
	msgbox MunenLabAct2_Text_BagDestroyDeclined, MSGBOX_DEFAULT
	releaseall
	end

@ Reading the kept dossier (from the bag menu above).
MunenLabAct2_EventScript_ReadDossier::
	lockall
	msgbox MunenLabAct2_Text_Dossier1, MSGBOX_DEFAULT
	msgbox MunenLabAct2_Text_Dossier2, MSGBOX_DEFAULT
	msgbox MunenLabAct2_Text_Dossier3, MSGBOX_DEFAULT
	releaseall
	end

@ --------------------------------------------------------------------------
@  Flavor
@ --------------------------------------------------------------------------
MunenLabAct2_EventScript_RansackedShelves::
	msgbox MunenLabAct2_Text_RansackedShelves, MSGBOX_SIGN
	end

MunenLabAct2_EventScript_DeadMachines::
	msgbox MunenLabAct2_Text_DeadMachines, MSGBOX_SIGN
	end

MunenLabAct2_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MunenLabAct2_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MunenLabAct2_Movement_Exclaim:
	emote_exclamation_mark
	delay_16
	step_end

@ Draco bolts NORTH out the top of the lab (he starts at 6,2; three fast
@ steps put him past the map edge before removeobject).
@ OUT THE DOOR, not through the north wall. He starts at (6,2) and every tile
@ on rows 0 and 1 is solid -- "three fast steps put him past the map edge" put
@ him through the lab's back wall instead. The lab's only exit is the warp pair
@ at (6,12)/(7,12), and column 6 is clear the whole way down to it, so he now
@ bolts for the door he actually came in by.
MunenLabAct2_Movement_DracoFlee:
	face_down
	delay_8
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

@ ============================================================================
@  Text
@ ============================================================================
MunenLabAct2_Text_DracoIntro1::
	.string "{JPN}むらじゅうの とびらを くぎづけにして\n"
	.string "みちも ぜんぶ ふさいだ…\p"
	.string "…それでも おまえは あらわれる。\n"
	.string "そりゃ そうだよな {ENG}{PLAYER}{JPN}。$"

MunenLabAct2_Text_DracoIntro2::
	.string "{JPN}これが なにか わかるか？\p"
	.string "クラークソンの しょうこだ。 やまは\n"
	.string "きかいで きかいなら じぶんの ものに\l"
	.string "できる。\p"
	.string "シントウキョウの やみの きみは こういう\n"
	.string "ちしきに たいかを はらう。 おまえには\l"
	.string "そうぞうも つかない かたちでな。\p"
	.string "はかせの しりょうが ほしいか？\n"
	.string "だったら おれから うばってみろ。$"

MunenLabAct2_Text_DracoDefeat::
	.string "{JPN}ちっ…！ もういい。 もう たくさんだ！$"

MunenLabAct2_Text_DracoVictory::
	.string "{JPN}あいかわらず あまいな {ENG}{PLAYER}{JPN}。\n"
	.string "やみの きみに いきたまま くわれるぞ。$"

MunenLabAct2_Text_DracoFlee::
	.string "{JPN}どうでも いいんだよ。\p"
	.string "ページは もう ぜんぶ\l"
	.string "よんだ。 なかみは もう おれの もの…\l"
	.string "そして すぐに あの かたの ものに なる。\p"
	.string "シントウキョウの あかりが よんでるぜ\n"
	.string "{ENG}{PLAYER}{JPN}。 ついてこれるもんならな…$"

MunenLabAct2_Text_AfterFlee::
	.string "{JPN}つくえの うえに クラークソンの けんきゅうの\n"
	.string "げんぽんが おかれた ままに なっている。$"

MunenLabAct2_Text_GengarGate::
	.string "{JPN}まって… その けんきゅうを\n"
	.string "はきしなきゃ だめだ$"

MunenLabAct2_Text_GengarGateNudge::
	.string "{JPN}まって… その けんきゅうを\n"
	.string "はきしなきゃ だめだ$"

MunenLabAct2_Text_DeskBlocked::
	.string "{JPN}つくえは しりょうと きぐで\n"
	.string "うもれている。\p"
	.string "ドラコが その まえに\n"
	.string "たちはだかっている。$"

MunenLabAct2_Text_DeskChoice::
	.string "{JPN}つくえに クラークソンの けんきゅうが ある。\n"
	.string "なんねんぶんもの しごと。 ある ゆうれいの\l"
	.string "さいごの こうかい。\p"
	.string "かれは あなたに はきを たのんだ。\n"
	.string "だが きめるのは あなただ。$"

MunenLabAct2_Text_KeptResearch::
	.string "{JPN}{ENG}{PLAYER}{JPN}は けんきゅうを しまいこんだ。\p"
	.string "たいせつなもの ポケットから\n"
	.string "よむことが できる…$"

MunenLabAct2_Text_DestroyResearch1::
	.string "{JPN}{ENG}{PLAYER}{JPN}は すべての ページを あつめ\n"
	.string "けんきゅうじょの ふるい バーナーに いれた…\p"
	.string "…そして ひを つけた。$"

MunenLabAct2_Text_DestroyResearch2::
	.string "{JPN}ページは すぐに もえあがった。\p"
	.string "ひとりの しょうがいの しごとが ひかりに\n"
	.string "なり ぬくもりに なり はいに なった。\p"
	.string "どこかで… バッグの なかかも しれない…\n"
	.string "なにかが にやりと わらい\l"
	.string "ながい あいだ こらえていた いきを はいた。$"

MunenLabAct2_Text_DeskDeferred::
	.string "{JPN}けんきゅうは つくえの うえで まっている。\p"
	.string "どこにも いきは しない。\n"
	.string "そこが もんだいなのだ。$"

MunenLabAct2_Text_DeskAshes::
	.string "{JPN}つくえの うえには まだ ほのかに あたたかい\n"
	.string "はいだけが のこっている。\p"
	.string "けんきゅうじょの くうきが かるく なった。$"

MunenLabAct2_Text_DeskEmptyKept::
	.string "{JPN}つくえの うえは からっぽだ。\p"
	.string "けんきゅうは いま バッグの なかに ある。\n"
	.string "こらえた いきのように おもたい。$"

MunenLabAct2_Text_BagDestroyConfirm::
	.string "{JPN}クラークソンの けんきゅうを はきしますか？\p"
	.string "とりけすことは できません。$"

@ PLACEHOLDER (Joe): aftermath of destroying the research from the bag.
MunenLabAct2_Text_BagDestroyed::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ちいさな ひを たいて\n"
	.string "ページを ていねいに くべた。\p"
	.string "ひとりの しょうがいの しごとが ひかりに\n"
	.string "なり ぬくもりに なり はいに なった。\p"
	.string "すぐ そばで なにかが にやりと わらい\n"
	.string "ながい あいだ こらえていた\l"
	.string "いきを はいた。$"

MunenLabAct2_Text_BagDestroyDeclined::
	.string "{JPN}{ENG}{PLAYER}{JPN}は けんきゅうを また\n"
	.string "しまいこんだ。$"

MunenLabAct2_Text_Dossier1::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ダークちょうさしりょうを\n"
	.string "ひらいた…\p"
	.string "「フィールドノート だい9かん さいしゅう。\n"
	.string "E・クラークソン\p"
	.string "「やまは かみでは ない。 しくみだ。\n"
	.string "かなしみが てばなせない ものを しまいこみ\l"
	.string "しまわれた ものは かたちを\l"
	.string "かえる ことが できる。$"

MunenLabAct2_Text_Dossier2::
	.string "{JPN}「こころは とびらのように\n"
	.string "とざす ことが できる。\p"
	.string "「わたしは サンプルを みた。\n"
	.string "ありのままに よぼう。\l"
	.string "ダークポケモン。 こころを\l"
	.string "とざされた ポケモンだ…\l"
	.string "じんいてきに。 いとてきに。\p"
	.string "「そして ジラーチ… ふめつの ねがいは\n"
	.string "かたちの ない ちからだ。 サミットゲートを\l"
	.string "とおして かたちを あたえれば ひとつの ねがいで\l"
	.string "いちまんの こころを いちどに\l"
	.string "とざせる。\p"
	.string "「なにも かんじない ぐんたいが\n"
	.string "ひとばんで ねがいから うまれるのだ。$"

MunenLabAct2_Text_Dossier3::
	.string "{JPN}「たいこうさくは ある。 まだ しょうめい\n"
	.string "できないが わたしは そう\l"
	.string "しんじている。\p"
	.string "「セレビィ。 もりに やどる\n"
	.string "ときの せいれいだ。\p"
	.string "「ときの なかで とざされた ものは ときに よって\n"
	.string "ふたたび ひらける。 リライブに ひつような\l"
	.string "ものは まさに ダークポケモンに\l"
	.string "かけている もの。 じかん。 きおく。 おもいやり。\p"
	.string "「これを だれかが よみ わたしが もう\n"
	.string "いないのなら サミットゲートに\l"
	.string "ねがいを あたえては ならない」$"

MunenLabAct2_Text_RansackedShelves::
	.string "{JPN}たなの ものは ひとなぎで\n"
	.string "すべて はらいおとされている。\p"
	.string "ここを あさった ものは なにを さがしているか\n"
	.string "はっきり わかっていて なにが こわれても\l"
	.string "きに しなかったようだ。$"

MunenLabAct2_Text_DeadMachines::
	.string "{JPN}けんきゅうじょの きかいは まっくらだ。\p"
	.string "ひびの はいった まどから ゆきが ふきこみ\n"
	.string "キーの うえに とけずに\l"
	.string "つもっている。\p"
	.string "この へやを あたためた ひとは\n"
	.string "ながいこと いない。$"
