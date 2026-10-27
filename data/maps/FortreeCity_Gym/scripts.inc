FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}よう げんきか?\n"
	.string "チャンピオンを めざす {ENG}{PLAYER}{JPN}!\p"
	.string "ヒワマキジムの リーダー ナギは\n"
	.string "ひこうタイプ ポケモンの つかいてだ!\p"
	.string "かのじょは この ジムの おく\n"
	.string "かいてんとびらの むこうで まっている\p"
	.string "はばたこうと する\n"
	.string "あらたな チャレンジャーを まってるぞ!\p"
	.string "よし がんばってこい!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}やったな!\n"
	.string "みごとに とびたったぞ!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "{JPN}とりポケモンの かれいな たたかいを\n"
	.string "みせて やるぜっ!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "{JPN}きみ……\n"
	.string "つよいな……$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "{JPN}トレーナーは あたまが よくないと\n"
	.string "よそうがいの てんかいに ついていけない\p"
	.string "きみに リーダーまで たどりつく\n"
	.string "あたまが あるかな?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "{JPN}とりポケモンを あいする ものは\n"
	.string "この ジムに はいるのが ゆめなんだ!\p"
	.string "ヒワマキジムの いちいん として\n"
	.string "まける わけには いかないんだ!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "{JPN}ぼくには にが\n"
	.string "おもすぎた……$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "{JPN}せかいは ひろくて つよい トレーナーが\n"
	.string "かぞえきれないほど いる\p"
	.string "ここで しゅぎょうを つづけて\n"
	.string "もっと つよく なってみせるよ$"

FortreeCity_Gym_Text_FlintIntro:
	.string "{JPN}ジムリーダーの ナギさんが\n"
	.string "でるまでも ない!\p"
	.string "きみの あいては オレで じゅうぶんだ!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "{JPN}ナギさん オレ……\n"
	.string "まけちゃいました!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "{JPN}ナギさんは かわいくて つよい\n"
	.string "さいこうの リーダーだよ!\p"
	.string "……ポッ$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "{JPN}ナギさんに じきじきに おそわったのよ!\n"
	.string "そう かんたんには まけないわ!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "{JPN}まけちゃった……$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "{JPN}ナギさんの おかげで ヒワマキの ひとは\n"
	.string "あんしんして くらせるの$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "{JPN}たたかう ときの ナギさまの かおは\n"
	.string "うつくしい けついに かがやく……\p"
	.string "あの すてきな すがたを きみには\n"
	.string "みせて やらない!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "{JPN}うう!\n"
	.string "おれでは とめられ なかった$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "{JPN}きを つけるんだな!\n"
	.string "ナギさまに みとれていると\l"
	.string "まっさかさまに ついらく するぞ!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "{JPN}ひこうタイプの ポケモンにも\n"
	.string "いろんな しゅるいが いるんだぜ\p"
	.string "それくらい わかってる よな?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "{JPN}なかなか わかってるな!$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "{JPN}たしかに おれは まけたよ\n"
	.string "でも きを つけな! ナギリーダーの\l"
	.string "ポケモンは ほんきで てごわいぞ$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "{JPN}わたしは ナギ……\n"
	.string "ヒワマキ ポケモンジムの リーダーです\p"
	.string "とりポケモンと こころを かよわせ\n"
	.string "いっしょに おおぞらを まい……\p"
	.string "どんな くるしい しょうぶも\n"
	.string "ゆうがに かちぬいて きました……\p"
	.string "さあ わたしと とりポケモンが おりなす\n"
	.string "かれいな まいを ごらんなさい!$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "{JPN}わたしより ゆうがに\n"
	.string "ポケモンを あやつる トレーナーには\l"
	.string "はじめて であいました……\p"
	.string "その じつりょくを みとめ\n"
	.string "この ジムバッジを おわたしします$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{JPN}{ENG}{PLAYER}{JPN}は ナギから\n"
	.string "フェザーバッジを もらった!$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "{JPN}フェザーバッジが あれば\n"
	.string "こうかんした ポケモンでも\l"
	.string "レベル70まで いうことを ききます\p"
	.string "それに たたかい いがいで ひでんわざ\n"
	.string "そらをとぶを つかえるように なります\p"
	.string "それと これは……\n"
	.string "わたしからの おくりものです$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "{JPN}わざマシン40は つばめがえし\p"
	.string "その はやさは……\n"
	.string "どんな ポケモンも よけられないはず\p"
	.string "…… …… …… …… …… ……$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "{JPN}ジムリーダー ナギを\n"
	.string "ポケナビに とうろく した!$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "{JPN}あなたには やぶれましたが わたしは\n"
	.string "これからも とりポケモンと あゆみます$"

FortreeCity_Gym_Text_GymStatue:
	.string "{JPN}ヒワマキシティ ポケモンジム$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "{JPN}ヒワマキシティ ポケモンジム\p"
	.string "ナギ にんてい トレーナー\n"
	.string "{ENG}{PLAYER}{JPN}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "{JPN}ナギ: わたしたち にんげんは\n"
	.string "じめんに ひかれる ちからから にげられない\p"
	.string "でも たかみを めざす ことで\n"
	.string "まいあがる ちからを えられるのです!\p"
	.string "あなたは チャンピオンとして\n"
	.string "いただきに のぼりつめました\p"
	.string "どうか あなたの ちからを\n"
	.string "ぞんぶんに みせてください!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "{JPN}やはり あなたの たかさには とどかない……$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "{JPN}ナギ: やぶれは しましたが\n"
	.string "こころの つばさは おれていません\p"
	.string "わたしは なんどでも\n"
	.string "また まいあがれる\p"
	.string "そう かくしん しています!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "{JPN}ナギ: わたしたち にんげんは\n"
	.string "じめんに ひかれる ちからから にげられない\p"
	.string "でも たかみを めざす ことで\n"
	.string "まいあがる ちからを えられるのです!\p"
	.string "あなたは チャンピオンとして\n"
	.string "いただきに のぼりつめました\p"
	.string "どうか あなたの ちからを\n"
	.string "ぞんぶんに みせてください!\p"
	.string "あら…… ポケモンを 1ぴきしか\n"
	.string "つれて いないのですか?\p"
	.string "すくなくとも 2ひきの ポケモンを\n"
	.string "つれて きてください$"
