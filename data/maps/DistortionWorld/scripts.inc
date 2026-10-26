DistortionWorld_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DistortionWorld_OnTransition
	.byte 0

@ Whiting out anywhere in the Distortion World respawns at the National Park
@ (Act 2) spawn point, 41,18. Every layer sets it on entry.
DistortionWorld_OnTransition::
	setrespawn HEAL_LOCATION_NATIONAL_PARK_ACT2
	end

@ ============================================================================
@  DISTORTION WORLD -- the far side of the gravesite seam.
@  Where the mountain KEEPS what people cannot let go.
@  CANON: Prof. Clarkson DIED at Star Summit. His spirit lives on inside a
@  wild GENGAR ("ghosts collect ghosts"). The Catalpa Bow is the one string
@  that sounds on both sides of the veil -- it lets the living hear him.
@  The NPC here is the GENGAR (local ID 1, drawn as a shiny Mega Gengar),
@  speaking as Clarkson. The gift is a plain shiny Gengar: Megas only last a battle.
@  Scene: full confession -> Gengar JOINS THE PARTY -> the Distortion World
@  collapses (screen shake) -> player is thrown back in front of the
@  gravesite (47,19). Afterward the seam is closed for good
@  (FLAG_ACT2_MET_CLARKSON_DISTORTION; also sets FLAG_NATIONAL_PARK_GRAVE_SECRET
@  so the Act 1 gravesite reveals his note).
@  If the party AND boxes are full, the scene politely refuses and can be
@  retried (nothing is set).
@ ============================================================================
DistortionWorld_EventScript_Clarkson::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GENGAR_MEGA, CRY_MODE_NORMAL
	waitmoncry
	setspeaker SP_NAME_GENGAR
	showportrait PORTRAIT_CLARKSON_GENGAR
	msgbox DistortionWorld_Text_GengarClarkson1, MSGBOX_DEFAULT
	msgbox DistortionWorld_Text_GengarClarkson2, MSGBOX_DEFAULT
	msgbox DistortionWorld_Text_GengarClarkson3, MSGBOX_DEFAULT
	closemessage
	hideportrait
	givemon SPECIES_GENGAR, 40, shinyMode=SHINY_MODE_ALWAYS
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq DistortionWorld_EventScript_NoRoom
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq DistortionWorld_EventScript_JoinedPC
	msgbox DistortionWorld_Text_GengarJoined, MSGBOX_DEFAULT
	goto DistortionWorld_EventScript_Collapse

DistortionWorld_EventScript_JoinedPC::
	msgbox DistortionWorld_Text_GengarJoinedPC, MSGBOX_DEFAULT
	goto DistortionWorld_EventScript_Collapse

DistortionWorld_EventScript_Collapse::
	closemessage
	@ Gengar offers to send the player home before he fades and the world
	@ collapses (the warp back to National Park below IS that teleport).
	setspeaker SP_NAME_GENGAR
	showportrait PORTRAIT_CLARKSON_GENGAR
	msgbox DistortionWorld_Text_GengarTeleportHome, MSGBOX_DEFAULT
	closemessage
	hideportrait
	setflag FLAG_ACT2_MET_CLARKSON_DISTORTION
	setflag FLAG_NATIONAL_PARK_GRAVE_SECRET
	removeobject 1
	playse SE_THUNDER
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 10 @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	msgbox DistortionWorld_Text_Collapse1, MSGBOX_DEFAULT
	closemessage
	playse SE_THUNDER2
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 16 @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	msgbox DistortionWorld_Text_Collapse2, MSGBOX_DEFAULT
	closemessage
	playse SE_WARP_IN
	fadescreen FADE_TO_WHITE
	delay 40
	warp MAP_NATIONAL_PARK_ACT2, 47, 19
	waitstate
	release
	end

DistortionWorld_EventScript_NoRoom::
	msgbox DistortionWorld_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DistortionWorld_EventScript_Rift::
	lockall
	msgbox DistortionWorld_Text_Rift, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq DistortionWorld_EventScript_RiftStay
	closemessage
	playse SE_WARP_IN
	fadescreen FADE_TO_BLACK
	delay 30
	warp MAP_NATIONAL_PARK_ACT2, 47, 19
	waitstate
	releaseall
	end

DistortionWorld_EventScript_RiftStay::
	closemessage
	releaseall
	end

DistortionWorld_EventScript_FloatingStones::
	msgbox DistortionWorld_Text_FloatingStones, MSGBOX_SIGN
	end

DistortionWorld_EventScript_KeptThings::
	msgbox DistortionWorld_Text_KeptThings, MSGBOX_SIGN
	end

@ ----------------------------------------------------------------------------
@  Floating-rock crossing at x25: lower island (y13) <-> rock (y10) <-> cave
@  island (y7). The gaps are 2 tiles, beyond a vanilla ledge hop, so facing
@  the gap and pressing A skips the player across in two quick arcs
@  (bg_events at (25,8/9/11/12) gate on facing direction).
@ ----------------------------------------------------------------------------
DistortionWorld_EventScript_HopNorth::
	lockall
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, DistortionWorld_Movement_HopNorth
	waitmovement 0
	releaseall
	end

DistortionWorld_EventScript_HopSouth::
	lockall
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, DistortionWorld_Movement_HopSouth
	waitmovement 0
	releaseall
	end

DistortionWorld_Movement_HopNorth:
	jump_2_up
	jump_up
	step_end

DistortionWorld_Movement_HopSouth:
	jump_2_down
	jump_down
	step_end

@ ============================================================================
@  Text
@ ============================================================================
DistortionWorld_Text_GengarClarkson1::
	.string "{JPN}ケケケ… まだ モンスターボールを\n"
	.string "とるでないぞ。 {ENG}{PLAYER}{JPN}。\p"
	.string "わし… わしの なごりじゃ。 "
	.string "はっきり いおう。\n"
	.string "クラークソンはかせは "
	.string "スターサミットで しんだ。\p"
	.string "ようがんに おちたのは わしじゃ。\n"
	.string "わしの すべてじゃ。$"

DistortionWorld_Text_GengarClarkson2::
	.string "{JPN}はざまを ただよっていた わしの たましいを\n"
	.string "ゲンガーが みつけてくれた。\p"
	.string "この かおには なれが ひつようじゃった。\n"
	.string "わしの ことばは その ゆみが あればこそ"
	.string "じゃ。\p"
	.string "あずさの き。 あのよと このよの\n"
	.string "どちらにも ひびく\l"
	.string "ただ 1ぽんの つるじゃ。$"

DistortionWorld_Text_GengarClarkson3::
	.string "{JPN}よいか。 いつまでも この さけめを\n"
	.string "ひらいては おけん。\p"
	.string "けんきゅうは まだ けんきゅうじょに ある。\n"
	.string "ジラーチと ダークポケモンについての\l"
	.string "わしの きろくじゃ。\p"
	.string "{ENG}{PLAYER}{JPN}… あれを\n"
	.string "ミュートリッドだんに みつけさせるな。\p"
	.string "わしの けんきゅうを はきするのじゃ。\n"
	.string "1ページ のこらず やくのじゃ。\p"
	.string "ともに さいごまで みとどけねば。\p"
	.string "わしらを つれていってくれ。 {ENG}{PLAYER}{JPN}。$"

DistortionWorld_Text_GengarJoined::
	.string "{JPN}ゲンガーと その なかに やどる すべてが\n"
	.string "なかまに くわわった!$"

DistortionWorld_Text_GengarJoinedPC::
	.string "{JPN}ゲンガー: なかに やどる すべてと ともに\n"
	.string "パソコンに おくられたわい。\p"
	.string "ボックスの てつづきか。 しんでも\n"
	.string "しょるいしごとは あるんじゃな。 ケケケ。$"

DistortionWorld_Text_NoRoom::
	.string "{JPN}…てもちも ボックスも いっぱいじゃな。\n"
	.string "{ENG}{PLAYER}{JPN}。\p"
	.string "「ゆうれいにも せきが いるわい。\p"
	.string "あきを つくって むかえに きてくれ。\n"
	.string "ここまで まっておったんじゃ。$"

DistortionWorld_Text_GengarTeleportHome::
	.string "{JPN}ここも もう ながくは もたぬ。\n"
	.string "わしも そうじゃ。\p"
	.string "じゃが さいごに もう 1つ げいを\n"
	.string "みせるくらいの ちからは ある。\p"
	.string "おぬしを かえそう。 {ENG}{PLAYER}{JPN}。\n"
	.string "おぬしが いるべき\l"
	.string "いきたものの せかいへ。$"

DistortionWorld_Text_Collapse1::
	.string "{JPN}ああ。 そういうことか。\p"
	.string "わしが この へやを とじておく くぎ\n"
	.string "だったようじゃな。 {ENG}{PLAYER}{JPN}。\p"
	.string "わしに つかまれ!$"

DistortionWorld_Text_Collapse2::
	.string "{JPN}うかぶ いしが くだけてゆく\p"
	.string "やぶれたせかいが\n"
	.string "うちがわへ おりたたまれてゆく…$"

DistortionWorld_Text_Rift::
	.string "{JPN}くうちゅうに はざまが うかんでいる。\n"
	.string "きりの なかの ほそく ひかる きず。\p"
	.string "その むこうには はかと こうえん。\n"
	.string "つめたい いつもの せかいが みえる。\p"
	.string "くぐって もどりますか?$"

DistortionWorld_Text_FloatingStones::
	.string "{JPN}はかいしが じめんを はなれ ただよっている。\n"
	.string "ゆっくりと たてに かいてんしながら。\p"
	.string "きざまれた なまえは どれも\n"
	.string "はっきりと よめる。\p"
	.string "そのせいで なおさら おそろしい。$"

DistortionWorld_Text_KeptThings::
	.string "{JPN}うかぶ いしの くぼみに\n"
	.string "ちいさなものが あつめられている。\p"
	.string "こどもの くつ。 かわいた ふで。\n"
	.string "なんども おられ もう ひらけなくなった\l"
	.string "てがみ。\p"
	.string "のこされたもの。 どれも\n"
	.string "だれかの くいだ。$"
