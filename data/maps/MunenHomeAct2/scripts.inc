@ ============================================================================
@  THE PLAYER'S HOME -- ACT 2 (occupied Munen)
@  Entry cutscene (ON_FRAME, once): two Mutrid goons are trying to arrest
@  Mom. She fights BOTH off (ladle-fu), they flee -- then she sees the
@  player, alive, and after healing the party she leads them to the
@  safehouse (MAP_DOJO), clearing FLAG_HIDE_DOJO_REBELS on the way.
@  Local IDs: 1 = Mom, 2 = Goon A (M), 3 = Goon B (F).
@  All three objects are hidden by FLAG_ACT2_HOME_CUTSCENE_DONE afterward;
@  revisiting shows the empty, wrecked kitchen.
@ ============================================================================
MunenHomeAct2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MunenHomeAct2_OnFrame
	.byte 0

MunenHomeAct2_OnFrame:
	map_script_2 VAR_TEMP_0, 0, MunenHomeAct2_EventScript_Cutscene
	.2byte 0

MunenHomeAct2_EventScript_Cutscene::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_ACT2_HOME_CUTSCENE_DONE, MunenHomeAct2_EventScript_CutsceneEnd
	lockall
	playbgm MUS_DP_VS_GALACTIC, FALSE
	@ Pan the camera up-left so Mom and the goons are in frame
	@ (player enters at the door, 8,8; the scuffle is around 5,3).
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, MunenHomeAct2_Movement_CameraPanUp
	waitmovement 0
	setspeaker SP_NAME_GOON
	msgbox MunenHomeAct2_Text_GoonThreat, MSGBOX_DEFAULT
	setspeaker SP_NAME_MOM
	msgbox MunenHomeAct2_Text_MomRefuse, MSGBOX_DEFAULT
	setspeaker SP_NAME_GOON
	msgbox MunenHomeAct2_Text_GoonGrabHer, MSGBOX_DEFAULT
	closemessage
	applymovement 2, MunenHomeAct2_Movement_GoonLunge
	applymovement 3, MunenHomeAct2_Movement_GoonLunge
	waitmovement 0
	playse SE_M_DOUBLE_SLAP
	applymovement 1, MunenHomeAct2_Movement_MomSwing
	applymovement 2, MunenHomeAct2_Movement_GoonReel
	waitmovement 0
	playse SE_M_DOUBLE_SLAP
	applymovement 1, MunenHomeAct2_Movement_MomSwing
	applymovement 3, MunenHomeAct2_Movement_GoonReel
	waitmovement 0
	msgbox MunenHomeAct2_Text_Wham, MSGBOX_DEFAULT
	setspeaker SP_NAME_GOON
	msgbox MunenHomeAct2_Text_GoonFlee, MSGBOX_DEFAULT
	closemessage
	applymovement 2, MunenHomeAct2_Movement_GoonAFlee
	applymovement 3, MunenHomeAct2_Movement_GoonBFlee
	waitmovement 0
	playse SE_EXIT
	removeobject 2
	removeobject 3
	fadedefaultbgm
	delay 30
	@ Pan back to the player before removing the camera.
	applymovement LOCALID_CAMERA, MunenHomeAct2_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	applymovement 1, MunenHomeAct2_Movement_MomNotice
	waitmovement 0
	setspeaker SP_NAME_MOM
	msgbox MunenHomeAct2_Text_MomGasp, MSGBOX_DEFAULT
	closemessage
	applymovement 1, MunenHomeAct2_Movement_MomApproach
	applymovement LOCALID_PLAYER, MunenHomeAct2_Movement_PlayerFaceUp
	waitmovement 0
	setspeaker SP_NAME_MOM
	msgbox MunenHomeAct2_Text_MomReunion, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	setspeaker SP_NAME_MOM
	msgbox MunenHomeAct2_Text_MomSafehouse, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ACT2_HOME_CUTSCENE_DONE
	clearflag FLAG_HIDE_DOJO_REBELS
	fadescreen FADE_TO_BLACK
	delay 20
	@ the foot of the Dojo path; Dojo_EventScript_Arrival takes it from here
	warp MAP_DOJO, 14, 25
	waitstate
	releaseall
	end

MunenHomeAct2_EventScript_CutsceneEnd::
	end

@ Talking to Mom directly mid-scene isn't possible (cutscene runs on entry);
@ this is a safety fallback.
MunenHomeAct2_EventScript_Mom::
	lock
	faceplayer
	msgbox MunenHomeAct2_Text_MomSafehouse, MSGBOX_DEFAULT
	release
	end

MunenHomeAct2_EventScript_OverturnedTable::
	msgbox MunenHomeAct2_Text_OverturnedTable, MSGBOX_SIGN
	end

@ --------------------------------------------------------------------------
@  Movement
@ --------------------------------------------------------------------------
MunenHomeAct2_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

MunenHomeAct2_Movement_CameraPanDown:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MunenHomeAct2_Movement_GoonLunge:
	walk_in_place_fast_up
	delay_8
	step_end

MunenHomeAct2_Movement_MomSwing:
	walk_in_place_fast_down
	delay_4
	step_end

MunenHomeAct2_Movement_GoonReel:
	walk_fast_down
	emote_exclamation_mark
	step_end

MunenHomeAct2_Movement_GoonAFlee:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MunenHomeAct2_Movement_GoonBFlee:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MunenHomeAct2_Movement_MomNotice:
	emote_exclamation_mark
	delay_16
	step_end

MunenHomeAct2_Movement_MomApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end

MunenHomeAct2_Movement_PlayerFaceUp:
	face_up
	step_end

@ ============================================================================
@  Text
@ ============================================================================
MunenHomeAct2_Text_GoonThreat::
	.string "{JPN}したっぱ: これが さいごだ おばさん。 ムネンの\n"
	.string "いえは ぜんぶ ちょうぼに サインするか\l"
	.string "ぜんぶ もえるかだ。\p"
	.string "いっしょに きてもらうぞ。$"

MunenHomeAct2_Text_MomRefuse::
	.string "{JPN}ママ: ここは わたしの だいどころよ。\p"
	.string "わたしの だいどころで めんなんか\n"
	.string "つけて きれいな ゆかに しずくを\l"
	.string "たらしてるのよ あなたたち。\p"
	.string "でていきなさい。$"

MunenHomeAct2_Text_GoonGrabHer::
	.string "{JPN}したっぱ: …つかまえろ。$"

MunenHomeAct2_Text_Wham::
	.string "{JPN}バシッ！ ゴツン！\p"
	.string "ママの おたまは したっぱたちの\n"
	.string "めにも とまらない はやさだった。$"

MunenHomeAct2_Text_GoonFlee::
	.string "{JPN}したっぱ: なんだ この おばさん！ ねがいでも\n"
	.string "こんなの わりに あわねえ！$"

MunenHomeAct2_Text_MomGasp::
	.string "{JPN}ママ: にどと こないで！\p"
	.string "まったく なんて ずうずうしい…\p"
	.string "…\p"
	.string "ママ: …{ENG}{PLAYER}{JPN}？$"

MunenHomeAct2_Text_MomReunion::
	.string "{JPN}ママ: {ENG}{PLAYER}{JPN}！！ ああ… よく かおを\n"
	.string "みせて。 よく みせて。\p"
	.string "あの やまから おりてきた ひとは いないって\n"
	.string "いわれたの。 あの ひとたち げんかんに\l"
	.string "たって わたしの こどもは もう\l"
	.string "いないって いったのよ。\p"
	.string "…やせたわね。 それに\n"
	.string "たたかってきたのね。\p"
	.string "いまは なにも いわないで。 ここでは だめ。\n"
	.string "いまは かべにも めんが ついてるの。\p"
	.string "まずは ポケモンたちよ。 みんな\n"
	.string "こっちへ いらっしゃい。$"

MunenHomeAct2_Text_MomSafehouse::
	.string "{JPN}ママ: ムネンには まだ くっしていない\n"
	.string "ひとたちが いるの。\p"
	.string "ミュートリッドの めが とどかない ところで\n"
	.string "あつまっているの。 ふるい どうじょうよ。\p"
	.string "わたしの そばを はなれないで。 フードを かぶって\n"
	.string "たいくつそうに あるくのよ。\p"
	.string "さあ いそいで。$"

MunenHomeAct2_Text_OverturnedTable::
	.string "{JPN}だいどころの テーブルが ひっくりかえっている。\p"
	.string "とっくに さめた ひとりぶんの ゆうしょくが\n"
	.string "ゆかいたに ちらばっている。\p"
	.string "それでも かのじょは しょくたくを ととのえた。\n"
	.string "いつも そうしてきたのだ。$"
