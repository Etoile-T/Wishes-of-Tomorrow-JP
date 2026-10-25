	.set LOCALID_TORII_RIVAL, 7
	.set LOCALID_TORII_ORACLE, 8

Torii_MapScripts::
	.byte 0

@ Return south to Munen Village. Same deal as the Munen exit: the painted bottom
@ edge has no warp-behavior metatile, so we warp from the script. Land at (24,2)
@ -- just inside Munen's north gap, one row BELOW the ExitNorth trigger (y=1) so
@ the player doesn't immediately bounce back to Torii.
Torii_EventScript_ReturnToMunen::
	warp MAP_MUNEN_VILLAGE, 35, 5
	waitstate
	end

@==============================================================================
@ THE ORACLE (old woman from the start, now with a man) -- forced DOUBLE battle.
@ 4 ghosts (2 "hers" + 2 "his"). Sight-based; she warns, then attacks.
@==============================================================================
Torii_EventScript_Oracle::
	trainerbattle_double TRAINER_TORII_ORACLE, Torii_Text_OracleIntro, Torii_Text_OracleDefeat, Torii_Text_OracleNotEnough, Torii_EventScript_OracleVanish
	end

@ After the battle the Oracle speaks her parting riddle and VANISHES (as she did
@ at the start of the game). Hide flag set before removeobject so she stays gone.
Torii_EventScript_OracleVanish::
	setspeaker SP_NAME_ORACLE
	msgbox Torii_Text_OraclePost, MSGBOX_DEFAULT
	closemessage
	delay 10
	playse SE_M_TELEPORT
	setflag FLAG_HIDE_TORII_ORACLE
	removeobject LOCALID_TORII_ORACLE
	delay 20
	release
	end

@ The man beside The Oracle. Once she's gone, he plays dumb -- "who's the Oracle?"
Torii_EventScript_OracleMan::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TORII_ORACLE, Torii_EventScript_OracleManConfused
	msgbox Torii_Text_OracleMan, MSGBOX_DEFAULT
	release
	end

Torii_EventScript_OracleManConfused::
	msgbox Torii_Text_OracleManConfused, MSGBOX_DEFAULT
	release
	end

@==============================================================================
@ HIKER -- 3 grass/poison types.
@==============================================================================
Torii_EventScript_Hiker::
	trainerbattle_single TRAINER_TORII_HIKER, Torii_Text_HikerIntro, Torii_Text_HikerDefeat
	msgbox Torii_Text_HikerPost, MSGBOX_AUTOCLOSE
	end

@==============================================================================
@ BLACK BELT -- 3 fighting types (incl. MACHOKE).
@==============================================================================
Torii_EventScript_Blackbelt::
	trainerbattle_single TRAINER_TORII_BLACKBELT, Torii_Text_BlackbeltIntro, Torii_Text_BlackbeltDefeat, Torii_EventScript_BlackbeltHealOffer
	end

@ Runs after his battle AND on every re-talk (a free rest stop before the summit):
@ he OFFERS to heal. NOTE: HealPlayerParty is synchronous -- do NOT follow it with
@ `waitstate` (nothing signals it -> the game froze).
Torii_EventScript_BlackbeltHealOffer::
	msgbox Torii_Text_BlackbeltHealOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Torii_EventScript_BlackbeltDecline
	closemessage
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	setrespawn HEAL_LOCATION_TORII
	msgbox Torii_Text_BlackbeltGoodLuck, MSGBOX_DEFAULT
	release
	end

Torii_EventScript_BlackbeltDecline::
	msgbox Torii_Text_BlackbeltDecline, MSGBOX_DEFAULT
	release
	end

@==============================================================================
@ RIVAL DRACO -- summit gate. Triggered just below the top exits to STAR SUMMIT.
@ He taunts, battles with his fully-evolved starter + 2 others (counter-pick by
@ the player's starter), then runs up the mountain and clears the path.
@==============================================================================
Torii_EventScript_RivalTrigger::
	lockall
	goto_if_set FLAG_HIDE_TORII_RIVAL, Torii_EventScript_RivalTriggerDone
	applymovement LOCALID_TORII_RIVAL, Torii_Movement_RivalConfront
	waitmovement 0
	setspeaker SP_NAME_DRACO
	msgbox Torii_Text_RivalTaunt, MSGBOX_DEFAULT
	closemessage
	compare VAR_STARTER_CHOICE, 1
	goto_if_eq Torii_EventScript_RivalBattleAurorus
	compare VAR_STARTER_CHOICE, 2
	goto_if_eq Torii_EventScript_RivalBattleArmaldo
	compare VAR_STARTER_CHOICE, 3
	goto_if_eq Torii_EventScript_RivalBattleTyrantrum
	goto Torii_EventScript_RivalAfter

@ Player chose Pawniard -> Draco's DEINO has evolved into ZWEILOUS.
Torii_EventScript_RivalBattleAurorus::
	trainerbattle_no_intro TRAINER_DRACO_TORII_AURORUS, Torii_Text_RivalDefeat
	goto Torii_EventScript_RivalAfter

@ Player chose Impidimp -> Draco's PAWNIARD has evolved into BISHARP.
Torii_EventScript_RivalBattleArmaldo::
	trainerbattle_no_intro TRAINER_DRACO_TORII_ARMALDO, Torii_Text_RivalDefeat
	goto Torii_EventScript_RivalAfter

@ Player chose Deino -> Draco's IMPIDIMP has evolved into MORGREM.
Torii_EventScript_RivalBattleTyrantrum::
	trainerbattle_no_intro TRAINER_DRACO_TORII_TYRANTRUM, Torii_Text_RivalDefeat
	goto Torii_EventScript_RivalAfter

Torii_EventScript_RivalAfter::
	setspeaker SP_NAME_DRACO
	msgbox Torii_Text_RivalRunoff, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TORII_RIVAL, Torii_Movement_RivalRunUp
	waitmovement 0
	setflag FLAG_HIDE_TORII_RIVAL
	removeobject LOCALID_TORII_RIVAL
	releaseall
	end

Torii_EventScript_RivalTriggerDone::
	releaseall
	end

Torii_Movement_RivalConfront:
	walk_in_place_fast_down
	step_end

Torii_Movement_RivalRunUp:
	walk_in_place_fast_up
	delay_8
	step_end

@==============================================================================
@ TEXT
@==============================================================================
Torii_Text_OracleIntro:
	.string "{JPN}ひきかえせ たにの こよ…\p"
	.string "やまは いきている ものの\n"
	.string "ばしょでは ない。 しにびとが さかを あるく。\p"
	.string "わたしは よげんしゃ。 おまえを\n"
	.string "はめつへ すすませは しない！$"

Torii_Text_OracleDefeat:
	.string "{JPN}…そうか。 おまえの うんめいの いとは\n"
	.string "わたしの みたてより つよかったか。$"

Torii_Text_OracleNotEnough:
	.string "{JPN}うえで まつ ものに たちむかうには\n"
	.string "ポケモンが 2ひき ひつようだ…$"

Torii_Text_OraclePost:
	.string "{JPN}では ゆけ。 だが きいておけ…\n"
	.string "うえで ねむる ものは ゆるしは しない。$"

Torii_Text_OracleMan:
	.string "{JPN}よげんしゃさまには ひとに みえない\nものが みえる。\p"
	.string "あの かたが ひきかえせと いうなら…\n"
	.string "きいたほうが いいぞ。$"

Torii_Text_OracleManConfused:
	.string "{JPN}よげんしゃ？ だれだ それ？\p"
	.string "きみ\n"
	.string "きの せいじゃ ないか？$"

Torii_Text_HikerIntro:
	.string "{JPN}この みちは くさと いばらだらけだ！\n"
	.string "おれを つきぬけて みろ！$"

Torii_Text_HikerDefeat:
	.string "{JPN}ぐわっ！ からまって たおされた！$"

Torii_Text_HikerPost:
	.string "{JPN}しげみの やせいの ポケモンに\n"
	.string "きを つけろ。 かみつくぞ。$"

Torii_Text_BlackbeltIntro:
	.string "{JPN}この やまを のぼれるのは つよい ものだけ！\n"
	.string "こぶしで しめして みよ ちょうせんしゃ！$"

Torii_Text_BlackbeltDefeat:
	.string "{JPN}むう！ その きはく… みごとだ。$"

Torii_Text_BlackbeltPost:
	.string "{JPN}からだも ポケモンも きたえよ。\n"
	.string "さんちょうは その りょうほうを ためす。$"

Torii_Text_BlackbeltHealOffer:
	.string "{JPN}ほんものの とうしが あるな。\p"
	.string "だが この さきの さんちょうは きびしいぞ。\n"
	.string "てもちを かいふく してやろうか？$"

Torii_Text_BlackbeltGoodLuck:
	.string "{JPN}よし げんきに なったぞ。\n"
	.string "うえでも がんばれよ ちょうせんしゃ！$"

Torii_Text_BlackbeltDecline:
	.string "{JPN}すきに しろ。\n"
	.string "うえでは ゆだんするなよ。$"

Torii_Text_RivalTaunt:
	.string "{JPN}ドラコ: へっ。 ここを はいずり\n"
	.string "のぼってると おもったぜ。\p"
	.string "おまえなんかが てっぺんに\n"
	.string "たどりつけると おもってんのか？ なさけねえ。\p"
	.string "おれたちの さが どれだけ あるか\n"
	.string "おしえてやるよ！$"

Torii_Text_RivalDefeat:
	.string "{JPN}ドラコ: …ちっ。 まぐれだ。 ただの\n"
	.string "まぐれだよ。$"

Torii_Text_RivalRunoff:
	.string "{JPN}ドラコ: ちょうしに のるなよ。\n"
	.string "さんちょうは おれの ものだ。\p"
	.string "うえで まってるぜ。 つぎは\n"
	.string "てかげん しねえからな。$"
