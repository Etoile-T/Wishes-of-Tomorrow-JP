PrototypeLab_MapScripts::
	.byte 0

@ ============================================================================
@  THE FLOODED LAB (under Prototype Island). Mutrid's abandoned first
@  facility: a drowned hall crossed by Surf, research logs on the way down,
@  and the failed "perfect form" prototype -- a SHADOW DEOXYS -- waiting in
@  the cracked containment ring at the bottom.
@  Encounter rules: Lv50 wild Shadow (WotMakeEventMonShadow); defeating it or
@  fleeing leaves it here (it sinks back into the dark); only CATCHING it
@  clears the object (FLAG_WOT_DEOXYS_CAUGHT). Canon note: it is meant to
@  "resist purification longest" -- special-case at the shrine is a later
@  co-director call; for now it purifies normally.
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================

PrototypeLab_EventScript_ExitToIsland::
	lockall
	warp MAP_PROTOTYPE_ISLAND, 8, 5
	waitstate
	releaseall
	end

PrototypeLab_EventScript_Deoxys::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	msgbox PrototypeLab_Text_DeoxysStirs, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_DEOXYS, 50
	special WotMakeEventMonShadow
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PrototypeLab_EventScript_DeoxysDown
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PrototypeLab_EventScript_DeoxysDown
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PrototypeLab_EventScript_DeoxysDown
	@ -- caught: the prototype leaves with you --
	setflag FLAG_WOT_DEOXYS_CAUGHT
	removeobject VAR_LAST_TALKED
	release
	end

PrototypeLab_EventScript_DeoxysDown::
	msgbox PrototypeLab_Text_DeoxysSinks, MSGBOX_DEFAULT
	release
	end

@ --- Research logs (all PLACEHOLDER (Joe)) ----------------------------------
PrototypeLab_EventScript_LogA::
	msgbox PrototypeLab_Text_LogA, MSGBOX_SIGN
	end

PrototypeLab_EventScript_LogB::
	msgbox PrototypeLab_Text_LogB, MSGBOX_SIGN
	end

PrototypeLab_EventScript_LogC::
	msgbox PrototypeLab_Text_LogC, MSGBOX_SIGN
	end

@ The other two terminals on this floor. The prototype was never the only
@ thing down here that stopped doing as it was told.
PrototypeLab_EventScript_LogD::
	msgbox PrototypeLab_Text_LogD, MSGBOX_SIGN
	end

PrototypeLab_EventScript_LogE::
	msgbox PrototypeLab_Text_LogE, MSGBOX_SIGN
	end

PrototypeLab_Text_LogA::
	.string "{JPN}みずびたしの たんまつが\n"
	.string "まだ かすかに うごいている。\p"
	.string "「4にちめ。 しょちょうは これを\n"
	.string "かんぜんけいたいけいかくと よぶ。\p"
	.string "「じぶんの たましいを もたない うつわ。\n"
	.string "ふうじるものも なければ\l"
	.string "われわれに さからうものも ない。」$"

PrototypeLab_Text_LogB::
	.string "{JPN}「61にちめ。 きょう あれは\n"
	.string "じぶんの うでを つくりなおした。\p"
	.string "「われわれが そだてた かたちではない。\n"
	.string "あれ じしんが このんだ かたちに。\p"
	.string "「しょちょうは こうふんしている。\n"
	.string "ほかの ものは もう\l"
	.string "ここで ねむらなくなった。」$"

PrototypeLab_Text_LogC::
	.string "{JPN}「77にちめ。 かくりそうちに ひびが。\n"
	.string "あれは おこっていない。\p"
	.string "「それが なにより おそろしい。 ただ\n"
	.string "われわれを みつめて すがたを かえる。\p"
	.string "「こんや たてあなを すいぼつさせる。\n"
	.string "われわれを… わたしを ゆるしてくれ。」$"

PrototypeLab_Text_LogD::
	.string "{JPN}この たんまつは かわいている。\n"
	.string "だれかが かわいたままに していた。\p"
	.string "「52にちめ。 だれも かいていない じっけんが\n"
	.string "けんきゅうじょの システムに とうろくされた。\p"
	.string "「おこなう まえに けっかが きろくされた。\n"
	.string "けっかは いっちした。\p"
	.string "「もはや だれが じっけんの どうぐなのか\n"
	.string "われわれにも わからない。」$"

PrototypeLab_Text_LogE::
	.string "{JPN}がめんが ひとりでに\n"
	.string "スクロールしている。\p"
	.string "「71にちめ。 せつぞくばこで\n"
	.string "システムの つうしんかいせんを きった。\p"
	.string "「それでも あれの ために ドアは ひらき\n"
	.string "あかりも あれに こたえる。\p"
	.string "「あれは この きろくの さいごに\n"
	.string "われわれの なまえを かきはじめた。\p"
	.string "「てつだっているのだと いう。」$"

PrototypeLab_Text_DeoxysStirs::
	.string "{JPN}リングの まわりの みずが\n"
	.string "かんぜんに しずまった。\p"
	.string "ひびわれた ガラスから\n"
	.string "なにかが ほどけるように はいだし…\p"
	.string "あなたに むきなおるように すこしずつ\n"
	.string "じぶんの からだを くみなおしていく。$"

PrototypeLab_Text_DeoxysSinks::
	.string "{JPN}しさくたいは からだを おりたたみ\n"
	.string "くらい みずに もどっていった。\p"
	.string "あせらず。 みかんせいのまま。\n"
	.string "まちつづけている。$"
