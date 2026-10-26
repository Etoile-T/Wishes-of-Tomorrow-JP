	.equ LOCALID_ARENA_ANNOUNCER, 1
	.equ LOCALID_ARENA_DOORMAN, 9
	.equ LOCALID_ARENA_LOSER, 13
	.equ LOCALID_ARENA_VOLTEN, 15
	.equ LOCALID_ARENA_CHALLENGER_1, 16
	.equ LOCALID_ARENA_CHALLENGER_2, 17

UndergroundArena_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundArena_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, UndergroundArena_OnFrame
	.byte 0

@ ============================================================================
@  THE UNDERGROUND ARENA -- Shin-Tokyo's illegal fight circuit, and the only
@  place left in the city where trainers still battle. Mutrid outlawed it
@  above ground, so the whole scene moved into the tunnels.
@  Beating the three-bout tournament (two challengers, then the champion
@  VOLTEN) awards the UNDERGROUND BADGE -- which IS FLAG_BADGE06_GET, so it
@  also unlocks FLY in the field (IsFieldMoveUnlocked_Fly keys on that badge)
@  -- plus the LIFE ORB. The gauntlet is one locked scene: no healing between
@  bouts. All dialogue PLACEHOLDER (Joe).
@ ============================================================================

UndergroundArena_OnTransition::
	@ The two gauntlet challengers are scene-only.
	setflag FLAG_HIDE_ARENA_CHALLENGERS
	@ Sprites for the map's VAR_0 / VAR_1 objects: the champion in the ring
	@ and the fighter he just beat. Swap these two ids to change their look
	@ -- no script edits needed.
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WATTSON
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_CAMPER
	end

UndergroundArena_OnFrame:
	map_script_2 VAR_TEMP_1, 0, UndergroundArena_EventScript_TitleBout
	.2byte 0

@ --- Entry cutscene: a title bout, live ------------------------------------
UndergroundArena_EventScript_TitleBout::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_WOT_ARENA_INTRO_SEEN, UndergroundArena_EventScript_TitleBoutDone
	setflag FLAG_WOT_ARENA_INTRO_SEEN
	delay 20
	@ mid-battle: the crowd is already screaming
	playse SE_M_SWAGGER
	applymovement LOCALID_ARENA_VOLTEN, UndergroundArena_Movement_FaceLeft
	waitmovement LOCALID_ARENA_VOLTEN
	msgbox UndergroundArena_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_M_THUNDERBOLT
	applymovement LOCALID_ARENA_LOSER, UndergroundArena_Movement_LoserReels
	waitmovement LOCALID_ARENA_LOSER
	delay 20
	applymovement LOCALID_ARENA_LOSER, UndergroundArena_Movement_LoserOut
	waitmovement LOCALID_ARENA_LOSER
	removeobject LOCALID_ARENA_LOSER
	@ the announcer calls it
	applymovement LOCALID_ARENA_ANNOUNCER, UndergroundArena_Movement_Emote
	waitmovement LOCALID_ARENA_ANNOUNCER
	msgbox UndergroundArena_Text_Intro2, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	delay 30
	msgbox UndergroundArena_Text_Intro3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARENA_VOLTEN, UndergroundArena_Movement_FaceDown
	waitmovement LOCALID_ARENA_VOLTEN
UndergroundArena_EventScript_TitleBoutDone::
	releaseall
	end

@ --- The announcer: sign-up desk -------------------------------------------
UndergroundArena_EventScript_Announcer::
	lock
	faceplayer
	goto_if_set FLAG_WOT_ARENA_WON, UndergroundArena_EventScript_AnnouncerChamp
	goto_if_set FLAG_WOT_ARENA_ENTERED, UndergroundArena_EventScript_AnnouncerWaiting
	msgbox UndergroundArena_Text_AnnouncerOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UndergroundArena_EventScript_AnnouncerDecline
	closemessage
	@ "WAIT -- we have a last-minute entry!"
	applymovement LOCALID_ARENA_ANNOUNCER, UndergroundArena_Movement_Emote
	waitmovement LOCALID_ARENA_ANNOUNCER
	msgbox UndergroundArena_Text_AnnouncerEntry, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	delay 60
	setflag FLAG_WOT_ARENA_ENTERED
	msgbox UndergroundArena_Text_AnnouncerToRing, MSGBOX_DEFAULT
	release
	end

UndergroundArena_EventScript_AnnouncerDecline::
	msgbox UndergroundArena_Text_AnnouncerDecline, MSGBOX_DEFAULT
	release
	end

UndergroundArena_EventScript_AnnouncerWaiting::
	msgbox UndergroundArena_Text_AnnouncerToRing, MSGBOX_DEFAULT
	release
	end

UndergroundArena_EventScript_AnnouncerChamp::
	msgbox UndergroundArena_Text_AnnouncerChamp, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  THE TOURNAMENT (ring trigger at 4,6)
@  One unbroken locked scene: each challenger walks to (13,6), fights, and is
@  replaced immediately -- the player never regains control, so there is no
@  healing between bouts. Losing whites out and the run resets.
@ ============================================================================
UndergroundArena_EventScript_Tournament::
	lockall
	setvar VAR_TEMP_2, 1
	goto_if_unset FLAG_WOT_ARENA_ENTERED, UndergroundArena_EventScript_TournamentSkip
	goto_if_set FLAG_WOT_ARENA_WON, UndergroundArena_EventScript_TournamentSkip
	@ Repeat runs must start clean (a loss leaves the defeat flags set).
	cleartrainerflag TRAINER_DUDLEY
	cleartrainerflag TRAINER_KAYLEE
	cleartrainerflag TRAINER_TERRY
	applymovement OBJ_EVENT_ID_PLAYER, UndergroundArena_Movement_FaceRight
	waitmovement 0
	msgbox UndergroundArena_Text_RoundOne, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	delay 40
	@ -- BOUT 1 --
	addobject LOCALID_ARENA_CHALLENGER_1
	applymovement LOCALID_ARENA_CHALLENGER_1, UndergroundArena_Movement_ChallengerIn
	waitmovement LOCALID_ARENA_CHALLENGER_1
	msgbox UndergroundArena_Text_Challenger1, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_DUDLEY, UndergroundArena_Text_Challenger1Lose
	removeobject LOCALID_ARENA_CHALLENGER_1
	msgbox UndergroundArena_Text_RoundTwo, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	delay 40
	@ -- BOUT 2 --
	addobject LOCALID_ARENA_CHALLENGER_2
	applymovement LOCALID_ARENA_CHALLENGER_2, UndergroundArena_Movement_ChallengerIn
	waitmovement LOCALID_ARENA_CHALLENGER_2
	msgbox UndergroundArena_Text_Challenger2, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KAYLEE, UndergroundArena_Text_Challenger2Lose
	removeobject LOCALID_ARENA_CHALLENGER_2
	msgbox UndergroundArena_Text_FinalRound, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	delay 50
	@ -- THE CHAMPION --
	applymovement LOCALID_ARENA_VOLTEN, UndergroundArena_Movement_VoltenToRing
	waitmovement LOCALID_ARENA_VOLTEN
	msgbox UndergroundArena_Text_VoltenIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_TERRY, UndergroundArena_Text_VoltenLose
	msgbox UndergroundArena_Text_VoltenBeaten, MSGBOX_DEFAULT
	closemessage
	playse SE_APPLAUSE
	delay 40
	msgbox UndergroundArena_Text_NewChamp, MSGBOX_DEFAULT
	closemessage
	@ -- the badge --
	setflag FLAG_WOT_ARENA_WON
	playfanfare MUS_OBTAIN_BADGE
	msgbox UndergroundArena_Text_ReceivedBadge, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_BADGE06_GET
	msgbox UndergroundArena_Text_VoltenFly, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_LIFE_ORB
	msgbox UndergroundArena_Text_VoltenAfter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARENA_VOLTEN, UndergroundArena_Movement_VoltenBack
	waitmovement LOCALID_ARENA_VOLTEN
UndergroundArena_EventScript_TournamentSkip::
	setvar VAR_TEMP_2, 0
	releaseall
	end

@ --- Volten, off the clock --------------------------------------------------
UndergroundArena_EventScript_Volten::
	lock
	faceplayer
	goto_if_set FLAG_WOT_ARENA_WON, UndergroundArena_EventScript_VoltenPost
	msgbox UndergroundArena_Text_VoltenIdle, MSGBOX_DEFAULT
	release
	end

UndergroundArena_EventScript_VoltenPost::
	msgbox UndergroundArena_Text_VoltenPost, MSGBOX_DEFAULT
	release
	end

@ --- The crowd --------------------------------------------------------------
UndergroundArena_EventScript_CrowdBanned::
	msgbox UndergroundArena_Text_CrowdBanned, MSGBOX_NPC
	end

UndergroundArena_EventScript_CrowdFightClub::
	msgbox UndergroundArena_Text_CrowdFightClub, MSGBOX_NPC
	end

UndergroundArena_EventScript_CrowdVolten::
	msgbox UndergroundArena_Text_CrowdVolten, MSGBOX_NPC
	end

UndergroundArena_EventScript_CrowdBetting::
	msgbox UndergroundArena_Text_CrowdBetting, MSGBOX_NPC
	end

UndergroundArena_EventScript_CrowdKid::
	msgbox UndergroundArena_Text_CrowdKid, MSGBOX_NPC
	end

UndergroundArena_EventScript_CrowdNoisy::
	msgbox UndergroundArena_Text_CrowdNoisy, MSGBOX_NPC
	end

UndergroundArena_EventScript_Doorman::
	lock
	faceplayer
	msgbox UndergroundArena_Text_Doorman, MSGBOX_DEFAULT
	release
	end

@ --- Movement ---------------------------------------------------------------
UndergroundArena_Movement_FaceLeft:
	face_left
	step_end

UndergroundArena_Movement_FaceRight:
	face_right
	step_end

UndergroundArena_Movement_FaceDown:
	face_down
	step_end

UndergroundArena_Movement_Emote:
	emote_exclamation_mark
	delay_16
	step_end

UndergroundArena_Movement_LoserReels:
	face_right
	delay_16
	walk_left
	emote_x
	delay_16
	step_end

UndergroundArena_Movement_LoserOut:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

@ Challengers come in from the right-hand tunnel to the mark at (13,6).
UndergroundArena_Movement_ChallengerIn:
	walk_left
	walk_left
	walk_left
	walk_left
	face_left
	step_end

UndergroundArena_Movement_VoltenToRing:
	walk_right
	walk_right
	face_left
	step_end

UndergroundArena_Movement_VoltenBack:
	walk_left
	walk_left
	face_down
	step_end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
UndergroundArena_Text_Intro1::
	.string "{JPN}トンネルを ぬけると どよめきが ひびいた。\p"
	.string "したでは ぬすんだ しょうめいの わに かこまれ\n"
	.string "2にんの トレーナーが\l"
	.string "まだ たたかいつづけている。$"

UndergroundArena_Text_Intro2::
	.string "{JPN}じっきょう: …ここで\n"
	.string "しあい しゅうりょう!\p"
	.string "ちょうせんしゃ ダウンです!\n"
	.string "みなさん! みごとな たたかいぶりでした!$"

UndergroundArena_Text_Intro3::
	.string "{JPN}じっきょう: ちかとうぎじょうの\n"
	.string "ぜったいおうじゃは\l"
	.string "やはり この おとこ…\p"
	.string "ボ ル テ ン !\p"
	.string "トンネルが ゆれる。 はるか うえの\n"
	.string "ミュートリッドには なにも きこえない。$"

UndergroundArena_Text_AnnouncerOffer::
	.string "{JPN}みにきた わけじゃ ないんだろ。\n"
	.string "その かおを みれば わかる。\p"
	.string "3れんせんだ。 あいだに きゅうけいも\n"
	.string "キズぐすりも なし…\l"
	.string "いまの てもちで たたかいぬく。\p"
	.string "でるかい?$"

UndergroundArena_Text_AnnouncerDecline::
	.string "{JPN}けんめいだ。 てもちの じゅんびが\n"
	.string "できたら また きな。$"

UndergroundArena_Text_AnnouncerEntry::
	.string "{JPN}じっきょう: まった! まった…\p"
	.string "とびいりの ちょうせんしゃが とうじょう!\p"
	.string "{ENG}{PLAYER}{JPN}!!$"

UndergroundArena_Text_AnnouncerToRing::
	.string "{JPN}かんきゃくは そうだちだ。\p"
	.string "じゅんびが できたら しるしの うえへ。\n"
	.string "リングは きみの ものだ。$"

UndergroundArena_Text_AnnouncerChamp::
	.string "{JPN}みなさん。\n"
	.string "チャンピオンの おでましです。\p"
	.string "かれは あなたに ウインクした。$"

UndergroundArena_Text_RoundOne::
	.string "{JPN}じっきょう: だい1せん!\p"
	.string "ちょうせんしゃに はくしゅを!$"

UndergroundArena_Text_Challenger1::
	.string "{JPN}ぜんりょくで きな。$"

UndergroundArena_Text_Challenger1Lose::
	.string "{JPN}…ほんとに ぜんりょくだったね。$"

UndergroundArena_Text_RoundTwo::
	.string "{JPN}じっきょう: だい2せん! きゅうけいなしが\n"
	.string "ちかの ルールだ!$"

UndergroundArena_Text_Challenger2::
	.string "{JPN}まだ たってるの?\p"
	.string "それじゃ たおれてもらおうか。$"

UndergroundArena_Text_Challenger2Lose::
	.string "{JPN}ちっ。 まだ たってる。$"

UndergroundArena_Text_FinalRound::
	.string "{JPN}じっきょう: さいしゅうせん!\p"
	.string "つぎが だれか わかってるよな。\n"
	.string "みんな はじめから わかってたはずだ!$"

UndergroundArena_Text_VoltenIntro::
	.string "{JPN}きゅうけいも なしに 2にん たおしたか。\p"
	.string "やつらは ジムを とじた。\n"
	.string "バッジも あかりも うばった。\p"
	.string "だから あなを ほって\n"
	.string "その なかで たたかいつづけた。\p"
	.string "ほった かいが あったと おもわせてくれ。$"

UndergroundArena_Text_VoltenLose::
	.string "{JPN}ははっ! それだ!$"

UndergroundArena_Text_VoltenBeaten::
	.string "{JPN}こんな ちかで まけちまった。\n"
	.string "しかも かおに しょうきんの ついた こにな。\p"
	.string "この あなが できてから さいこうの よるだ。$"

UndergroundArena_Text_NewChamp::
	.string "{JPN}じっきょう: しんチャンピオン!\n"
	.string "しんチャンピオンだ!!\p"
	.string "トンネルが\n"
	.string "すさまじい ねっきに つつまれた。$"

UndergroundArena_Text_ReceivedBadge::
	.string "{JPN}{ENG}{PLAYER}{JPN}は\n"
	.string "ちかバッジを てにいれた!$"

UndergroundArena_Text_VoltenFly::
	.string "{JPN}その バッジは こうしきじゃない。\p"
	.string "それ いじょうさ。 レジスタンスの とびては\n"
	.string "みんな その バッジに こたえる。\p"
	.string "どこでも くちぶえを ふけば\n"
	.string "むかえにきて のせてくれる。$"

UndergroundArena_Text_VoltenAfter::
	.string "{JPN}これも もっていけ。\p"
	.string "いのちのたまだ。 おもい いちげきを\n"
	.string "くりだすには だいしょうが いる。\p"
	.string "ここでは なんでも そうさ。$"

UndergroundArena_Text_VoltenIdle::
	.string "{JPN}じめんに ほった あなの\n"
	.string "チャンピオンか。\p"
	.string "それでも チャンピオンだ。$"

UndergroundArena_Text_VoltenPost::
	.string "{JPN}いつでも リングに もどってきな。\n"
	.string "チャンピオン。\p"
	.string "ここに いるさ。 だれかが\n"
	.string "あかりを ともしつづけないとな。$"

UndergroundArena_Text_CrowdBanned::
	.string "{JPN}ミュートリッドが シントウキョウじゅうで\n"
	.string "ポケモンしょうぶを きんしした。\p"
	.string "「ひせいさんてき」なんだと。\p"
	.string "だから かわりに この ちかで\n"
	.string "たいかいを ひらいているんだ。$"

UndergroundArena_Text_CrowdFightClub::
	.string "{JPN}ファイトクラブの おきて その1。\n"
	.string "ファイトクラブについて\l"
	.string "はなしては いけない。\p"
	.string "…その2。 その1を まもるのは\n"
	.string "むかしから にがてだ。$"

UndergroundArena_Text_CrowdVolten::
	.string "{JPN}ボルテンは 200ばんも\n"
	.string "あの リングを まもってる。\p"
	.string "さいごの 1ぴきまで おいつめた やつさえ\n"
	.string "いないんだ。$"

UndergroundArena_Text_CrowdBetting::
	.string "{JPN}チャンピオンに 3しゅうかんぶんの\n"
	.string "はいきゅうしょくを かけてるんだ。\p"
	.string "よけいなことは するなよ。$"

UndergroundArena_Text_CrowdKid::
	.string "{JPN}おおきくなったら リングで\n"
	.string "たたかうんだ!\p"
	.string "ママは リングは いほうだって。\n"
	.string "でも その ママも ここに いるんだよ。$"

UndergroundArena_Text_CrowdNoisy::
	.string "{JPN}うえでは こえを おさえろ。\p"
	.string "ここでは? さけべ。$"

UndergroundArena_Text_Doorman::
	.string "{JPN}あいことばは こんしゅうだけで\n"
	.string "2かい かわった。\p"
	.string "はいれたってことは きみを きにいった\n"
	.string "だれかが いるんだろうね。$"
