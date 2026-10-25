FrostwoodTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FrostwoodTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FrostwoodTown_OnFrame
	.byte 0

@ Arm the Clarkson call when the player walks out of the GYM holding the EMBER
@ BADGE for the first time. Map-level (not tile-level) so it fires no matter
@ which tile the gym exit drops the player onto.
FrostwoodTown_OnTransition::
	@ Whiteout respawn: being in town makes Frostwood the last heal location, so
	@ fainting near here no longer throws the player back to an Act 1 spawn.
	setrespawn HEAL_LOCATION_FROSTWOOD_TOWN
	@ Clarkson's post-Ember-Badge call. (Route 2 now sits between Frostwood and Sennen,
	@ so Frostwood's north exit is a plain warp to Route_2 -- the old dynamic Sennen warp
	@ is gone; the train swap is handled at Sennen instead.)
	goto_if_unset FLAG_DEFEATED_RUSTBORO_GYM, FrostwoodTown_OnTransition_Done
	goto_if_set FLAG_GOT_CLARKSON_MTMUNEN_CALL, FrostwoodTown_OnTransition_Done
	setvar VAR_FROSTWOOD_STATE, 1
FrostwoodTown_OnTransition_Done:
	end

FrostwoodTown_OnFrame:
	map_script_2 VAR_FROSTWOOD_STATE, 1, FrostwoodTown_EventScript_ClarksonCall
	.2byte 0

FrostwoodTown_EventScript_ClarksonCall::
	lockall
	delay 20
	playse SE_PIN
	pokenavcall FrostwoodTown_Text_ClarksonCall
	waitmessage
	closemessage
	setspeaker SP_NAME_CLARKSON
	msgbox FrostwoodTown_Text_ClarksonReminder, MSGBOX_DEFAULT
	setflag FLAG_GOT_CLARKSON_MTMUNEN_CALL
	setvar VAR_FROSTWOOD_STATE, 0
	releaseall
	end

FrostwoodTown_EventScript_OldMan::
	lock
	faceplayer
	msgbox FrostwoodText_OldMan, MSGBOX_DEFAULT
	release
	end

FrostwoodTown_EventScript_GymWoman::
	lock
	faceplayer
	msgbox FrostwoodText_GymWoman, MSGBOX_DEFAULT
	release
	end

FrostwoodTown_EventScript_Kid::
	lock
	faceplayer
	msgbox FrostwoodText_Kid, MSGBOX_DEFAULT
	release
	end

FrostwoodTown_EventScript_Worried::
	lock
	faceplayer
	msgbox FrostwoodText_Worried, MSGBOX_DEFAULT
	release
	end

FrostwoodTown_EventScript_MartLady::
	lock
	faceplayer
	msgbox FrostwoodText_MartLady, MSGBOX_DEFAULT
	release
	end

FrostwoodText_OldMan:
	.string "{JPN}フロストウッドタウンへ ようこそ たびのかた。\p"
	.string "この もりは せんねんの ふゆの あいだ\nずっと おなじ しろい ころもを きてきた。\p"
	.string "だが いま もりを あるけば しずくの\nおとが する。 しもが とけだしたのだ。\p"
	.string "あれほど ふるい ゆきが とけては ならん。\nムネンの ものたちも そう いっておる。$"

FrostwoodText_GymWoman:
	.string "{JPN}ゆきが つもった やねの おおきな たてもの\nみえる？ あれが まちの ポケモンジムよ。\p"
	.string "かけだしなら ここからが ほんばん。\nはじめての バッジよ。\p"
	.string "まずは ポケモンセンターで あたたまって。\nジムリーダーは てかげん しないから。$"

FrostwoodText_Kid:
	.string "{JPN}さっき トレーナーが さきに いったよ！\nツンツン あたまで すっごい えらそうなの。\p"
	.string "ドラコって なのってた。 だれよりも さきに\nジムバッジを とるって いばってたよ。\p"
	.string "あいつと きょうそう するの？ しなよ！$"

FrostwoodText_Worried:
	.string "{JPN}あなたも かんじるでしょう。 さむさが\nやわらいで きているの。\p"
	.string "おばあちゃんが よく はなしてくれた。 やまに\nねがいが ふういんされていて ふゆは それを\lねむらせておく ために ここに あるのだと。\p"
	.string "もし ふゆが おわったら… なにが\nめざめるのか かんがえたくも ないわ。$"

FrostwoodText_MartLady:
	.string "{JPN}フレンドリィショップに キズぐすりと\nモンスターボールが はいった ところよ。\p"
	.string "やまみちに いくまえに かいそろえて おいて。\nあそこで きらしたら\lたいへんよ。$"

FrostwoodTown_Text_ClarksonCall:
	.string "{JPN}………………\n"
	.string "…………… プルルルル！\p"
	.string "クラークソン: {ENG}{PLAYER}{JPN}！ わしだ\n"
	.string "クラークソンだ。 ここでは うわさが はやくてな\l"
	.string "きいたぞ もう\l"
	.string "エンバーバッジを てにいれたそうじゃないか！\p"
	.string "はっは！ はじめて あった ときから\n"
	.string "おまえには なにかが あると おもっておった。\p"
	.string "これほど はやく せいちょうする\n"
	.string "トレーナーは ひさしぶりに みる…\l"
	.string "だからこそ でんわ したのだ。\p"
	.string "だいじな ことでなければ たのまんが\n"
	.string "いまは おまえにしか できないことで\l"
	.string "ちからを かしてほしい。\p"
	.string "ムネンやまの てっぺんまで のぼって\n"
	.string "さんちょうで わしと あってくれ。\p"
	.string "そこで おまえに じかに みせなければ\n"
	.string "ならない ものが ある。 でんわでは\l"
	.string "つたえられん。 みれば\l"
	.string "わかるはずだ。\p"
	.string "まっておるぞ。 としよりを さむい ところで\n"
	.string "あまり またせんでくれよ！\p"
	.string "………………\n"
	.string "…………… ガチャ！$"

FrostwoodTown_Text_ClarksonReminder:
	.string "{JPN}はかせは ムネンやまの\n"
	.string "さんちょうで あいたいと いっていた。\p"
	.string "タウンマップで そこへの\n"
	.string "のぼりかたを しらべよう。$"

@ ---------------------------------------------------------------------------
@ Gondola down to the valley station (Route112_CableCarStation, whose door opens
@ onto Route_2). The station's two door tiles (45,9)/(46,9) are coord triggers,
@ not warps, so walking in asks first; the ride back from the valley warps onto
@ (45,9), and the non-animated door steps the player out onto (45,10).
FrostwoodTown_EventScript_GondolaDoor::
	lockall
	msgbox FrostwoodTown_Text_TakeGondola, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FrostwoodTown_EventScript_GondolaDecline
	closemessage
	hidefollower
	playse SE_EXIT
	applymovement LOCALID_PLAYER, FrostwoodTown_Movement_BoardGondola
	waitmovement 0
	delay 16
	@ From the door the car hangs half off the right edge of the screen, so pan over.
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, FrostwoodTown_Movement_CameraToGondola
	waitmovement 0
	playbgm MUS_CABLE_CAR, FALSE
	delay 30
	@ Slides down the cable until it is off screen (waits for it).
	setvar VAR_0x8004, LOCALID_FROSTWOOD_GONDOLA
	special WotGondolaDepart
	delay 20
	fadescreen FADE_TO_BLACK
	special RemoveCameraObject
	setvar VAR_CABLE_CAR_STATION_STATE, 2
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	warpsilent MAP_ROUTE112_CABLE_CAR_STATION, 6, 4
	waitstate
	releaseall
	end

FrostwoodTown_EventScript_GondolaDecline::
	closemessage
	applymovement LOCALID_PLAYER, FrostwoodTown_Movement_StepOffGondolaDoor
	waitmovement 0
	releaseall
	end

FrostwoodTown_Movement_BoardGondola:
	set_invisible
	step_end

FrostwoodTown_Movement_CameraToGondola:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

FrostwoodTown_Movement_StepOffGondolaDoor:
	walk_down
	step_end

FrostwoodTown_Text_TakeGondola:
	.string "{JPN}ゴンドラに のりますか？$"

@ ---------------------------------------------------------------------------
@ Frostwood Gym is locked until RedFatality gets his EPIC PASS on Route 2
@ (FLAG_REDFATALITY_HAS_EPIC_PASS). The door is an animated door, so there is no
@ tile event to catch: WotGetLockedDoorScript (field_control_avatar.c) runs
@ GymLocked in place of the door warp. The note itself is a bg_event on (41,9).
FrostwoodTown_EventScript_GymLocked::
	lockall
	playse SE_WALL_HIT
	msgbox FrostwoodTown_Text_GymNote, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, FrostwoodTown_Movement_StepBackFromGym
	waitmovement 0
	releaseall
	end

FrostwoodTown_EventScript_GymNote::
	goto_if_set FLAG_REDFATALITY_HAS_EPIC_PASS, FrostwoodTown_EventScript_GymNoteGone
	msgbox FrostwoodTown_Text_GymNote, MSGBOX_SIGN
FrostwoodTown_EventScript_GymNoteGone::
	end

FrostwoodTown_Movement_StepBackFromGym:
	walk_down
	step_end

FrostwoodTown_Text_GymNote:
	.string "{JPN}とびらに はりがみが ある。\p"
	.string "「フロストウッドジムの ジムリーダーは\n"
	.string "ゆうきゅうきゅうか ちゅうです」$"
