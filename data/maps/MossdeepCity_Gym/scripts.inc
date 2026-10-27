MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}よう ちょうしは どうだい\n"
	.string "チャンピオンを めざす {ENG}{PLAYER}{JPN}!\p"
	.string "ここの ジムリーダーたちは\n"
	.string "エスパータイプの ポケモンを つかう。\p"
	.string "かくとうや どくタイプの\n"
	.string "ポケモンで いどむと\l"
	.string "ひどい ダメージを うけるぞ!\p"
	.string "しかも すばらしい\n"
	.string "コンビネーションで せめてくる。\p"
	.string "かちたいなら きみと ポケモンの\n"
	.string "きずなの つよさを\l"
	.string "みせつけて やれ! がんばれよ!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}こりゃあ たまげた!\n"
	.string "きみは すごい トレーナーだ!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "{JPN}しょうぶは こころの つよさで きまる!\n"
	.string "こころ よわき ものは かてない!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "{JPN}まけたか!\n"
	.string "こころを きたえ なおさねば!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "{JPN}まよった ほうが まける。\n"
	.string "オレからの ちゅうこくだ。$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "{JPN}キミの さいのうを みせて もらおうか!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "{JPN}すばらしい さいのうの もちぬしだ!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "{JPN}よのなかに てんさいが いるならば\n"
	.string "ここの ジムリーダーこそ そうだ!\p"
	.string "だが もしかすると キミの ほうが\n"
	.string "さいのうは うえかも しれない……$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "{JPN}ふっふっふ…… ねんりきで モンスター\n"
	.string "ボールを うかせて みせよう!\p"
	.string "うおおおおおおおーっ!\n"
	.string "… … … … … … …\p"
	.string "たまに ちょうしが わるくて……$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "{JPN}ポケモン しょうぶも\n"
	.string "ちょうし わりーっ!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "{JPN}モンスターボールは おもすぎて\n"
	.string "うかせられなかった。 でも この ほこりなら……\p"
	.string "ふぅおおおおおおおおーっ!\n"
	.string "… … … … … …\p"
	.string "ちがう! ズルなんか してない!\n"
	.string "いきで ふいたり してないって! ほんとに!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "{JPN}あなたが アタシに まけても\n"
	.string "おちこまない ことね。\p"
	.string "あなたが よわいんじゃ なくて\n"
	.string "アタシが つよすぎる だけよ!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "{JPN}あなたが つよすぎた!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "{JPN}まけたって おちこんだり しないわ。\n"
	.string "もっと きたえれば いいだけ。\p"
	.string "まえむきな ところが\n"
	.string "アタシの とりえ なのよ!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "{JPN}みえる……\n"
	.string "あなたの みらいが みえる……\p"
	.string "わたくしに かてたら\n"
	.string "あなたの みらいを おしえて あげる!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "{JPN}まいりました……!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "{JPN}あなたは ジムリーダーさまと\n"
	.string "ものすごく はげしい しょうぶを する……\p"
	.string "けっかは……\n"
	.string "わたくしの くちからは いえない!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "{JPN}あなたが あゆんできた みち……\n"
	.string "あなたが けいけん したこと……\p"
	.string "まなんだ すべてを ぶつけて\n"
	.string "きなさい!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "{JPN}すばらしい みちのり だわ……!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "{JPN}こつこつ どりょくした ものには\n"
	.string "あかるい みらいが まっている。\p"
	.string "なまけていた ものには\n"
	.string "さいごに ぜつぼう だけが のこる。\p"
	.string "じぶんの したことは かえってくるのよ……$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "{JPN}いのちを けずって でも\n"
	.string "この しょうぶ かってみせるわ!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "{JPN}あなたの することは……\n"
	.string "おそろしい……$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "{JPN}よくも わたしを まかしたわね……\p"
	.string "あなたに おそろしい ことが おきても\n"
	.string "わたしの せいじゃ ないわよ……$"

MossdeepCity_Gym_Text_NateIntro:
	.string "{JPN}ほっほっほ。\p"
	.string "エスパータイプの しぶとさを\n"
	.string "あなたに おしえて さしあげましょう。$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "{JPN}こ これは これは!\n"
	.string "すばらしい たたかいかた ですな!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "{JPN}わ わたくしは どんなに ひどく\n"
	.string "まけても と とりみだしは しませんから。$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "{JPN}さいこうに ひどくて おそろしい\n"
	.string "ひとときを あじわわせて あげる!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "{JPN}い いやあああーっ!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "{JPN}あなたの げんきが うつるわ!\n"
	.string "はやく いっちゃいなさいよ!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "{JPN}としより だからと いって\n"
	.string "あまく みて もらっては こまりますよ。$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "{JPN}おお わかさの ちからに\n"
	.string "あふれて おりますな!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "{JPN}あなたの わかさあふれる げんきには\n"
	.string "かなわなかった ようですな。$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "{JPN}さいごまでは いかせないわよ!\n"
	.string "あたしが いる かぎりね!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "{JPN}どうして そんなに ばかみたいに\n"
	.string "つよいのよ?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "{JPN}ふんっ! つよいかも しれないけど\n"
	.string "エスパータイプには むいてないわ!\p"
	.string "たたかいかたが なんだか らんぼうなのよ!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "{JPN}うおおーっ! おれの スーパーな\n"
	.string "ポケモン ガチバトル パワーを くらえ!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "{JPN}うっ!\n"
	.string "やられた!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "{JPN}よし! つぎは むてきの とくべつな\n"
	.string "ポケモン パワーを あみだすぞ。$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "{JPN}フウ: へへへ…… おどろいた?\p"
	.string "ラン: ふふふ…… おどろいた?\p"
	.string "フウ: ジムリーダーが ふたりも いて?\n"
	.string "ラン: ジムリーダーが ふたりも いて?\p"
	.string "フウ: ぼくたち ふたご!\n"
	.string "ラン: あたしたち ふたご!\p"
	.string "フウ: ことばに しなくても……\n"
	.string "ラン: おたがいの かんがえて いることが……\p"
	.string "フウ: あいての おもいが……\n"
	.string "ラン: あたまの なかに うかぶの!\p"
	.string "フウ: そんな ぼくたちの コンビネーション……\n"
	.string "ラン: きみに やぶれる?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "{JPN}フウ: えっ?! ぼくたちの コンビネーションが……\n"
	.string "ラン: やぶられた!\p"
	.string "フウ: しかたない きみの かちだ……\n"
	.string "ラン: だから みとめて これを あげるヨ!$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{JPN}{ENG}{PLAYER}{JPN}は フウと ランから\n"
	.string "マインドバッジを もらった!$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "{JPN}フウ: マインドバッジが あると ポケモンの\n"
	.string "とくこうと とくぼうが あがるんだ。\p"
	.string "ラン: それに ひでんわざ ダイビングを\n"
	.string "たたかい いがいでも つかえるヨ!\p"
	.string "フウ: これも うけとって ほしいな。$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "{JPN}フウ: その わざマシン04には……\n"
	.string "ラン: めいそうが はいってるヨ!\p"
	.string "フウ: とくこうと……\n"
	.string "ラン: とくぼうを あげるの!\p"
	.string "フウ: ぴったりな わざ なんだ……\n"
	.string "ラン: エスパーポケモンに!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "{JPN}ジムリーダー フウと ランを\n"
	.string "ポケナビに とうろく した!$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "{JPN}フウ: ふたごの ぼくたちの きずな より\n"
	.string "きみと ポケモンの きずなの ほうが\l"
	.string "はるかに つよかった みたいだね。\p"
	.string "ラン: あなたは もっと つよく なれる!\n"
	.string "たたかった あたしたちには わかるの。$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "{JPN}フウ: へへへ…… おどろいた?\p"
	.string "ラン: ジムリーダーが ふたりも いて?\p"
	.string "フウ: あれ たたかえる ポケモンを……\n"
	.string "ラン: 1ぴきしか もってないのね。\p"
	.string "フウ: それじゃ たたかえないよ!\p"
	.string "ラン: あたしたちに いどむなら\n"
	.string "もっと ポケモンを つれてきてね。$"

MossdeepCity_Gym_Text_GymStatue:
	.string "{JPN}トクサネ シティ ポケモンジム$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "{JPN}トクサネ シティ ポケモンジム\p"
	.string "ラン フウ にんてい トレーナー!\n"
	.string "{ENG}{PLAYER}{JPN}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "{JPN}フウ: ポケモンは……\n"
	.string "ラン: ポケモンは……\p"
	.string "フウ: くみあわせを かえると……\n"
	.string "ラン: たたかいかたも かわるよね。\p"
	.string "フウ: でも ぼくは……\n"
	.string "ラン: でも あたしは……\p"
	.string "フウ: いつでも ランと いっしょ!\n"
	.string "ラン: いつでも フウと いっしょ!\p"
	.string "フウ: ぼくたちの コンビネーション……\n"
	.string "ラン: なんどでも みせて あげるわ!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "{JPN}フウ: きみと ポケモンって……\n"
	.string "ラン: まるで きょうだい みたい!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "{JPN}フウ: なんど たおされたって\n"
	.string "また たちあがって みせるからね!\p"
	.string "ラン: だって あたしたち ふたりは\n"
	.string "いつも ささえあってるもの!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "{JPN}フウ: また きてくれたんだね……\n"
	.string "ラン: また きてくれたのね……\p"
	.string "フウ: さいせんを しに。\n"
	.string "ラン: さいせんを しに。\p"
	.string "フウ: でも……\n"
	.string "ラン: あたしたちとの しょうぶに……\p"
	.string "フウ: ポケモンが 1ぴき だけだよ!\n"
	.string "ラン: ポケモンが 1ぴき だけだわ!\p"
	.string "フウ: こんどは すくなくとも……\n"
	.string "ラン: 2ひき つれて きてね。$"
