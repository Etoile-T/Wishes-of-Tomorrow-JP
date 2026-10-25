@ ============================================================================
@  THE HIJACKED YACHT (Route 2 pier)
@  Reward for the fisherman's questline: he hands over the YACHT KEY, which
@  finally turns the Route 2 "Hijack the yacht?" sign from a joke into a door.
@  Below deck the owner -- the person designing the next generation of
@  POKEMON -- left a field-test case with three prototypes: BROWT, POMBON and
@  GECQUA, each previewed with its sprite the way the Munen starters are. The
@  player may take exactly ONE (FLAG_WOT_YACHT_STARTER_TAKEN hides all three
@  the moment one is claimed). Their notes on the desk sketch where the three
@  evolve: sky, caves, deep sea.
@
@  In and out are ordinary warps. Aboard: Route 2's warp 2 on the gangway
@  (40,17), an arrow warp -- stand on it and press UP -- which lands on
@  the hatch here at (5,7). It is locked without the YACHT KEY by
@  WotGetLockedDoorScript (field_control_avatar.c). Ashore: the hatch tiles
@  (5,7)/(6,7) are south arrow warps back to that gangway.
@ ============================================================================

YachtInterior_MapScripts::
	.byte 0

@ The owner's working notes, on the desk at (1,4).
YachtInterior_EventScript_DeskNotes::
	msgbox YachtInterior_Text_DeskNotes, MSGBOX_SIGN
	end

@ VAR_0x8004 carries the chosen ball's local id to _Took, so that ball leaves
@ its cradle the moment it is taken and the other two go when the lid shuts.
@ It is set after givemon, so nothing between here and _Took can clobber it.
YachtInterior_EventScript_BallBrowt::
	lockall
	showmonpic SPECIES_BROWT, 10, 3
	msgbox YachtInterior_Text_BallBrowt, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, YachtInterior_EventScript_LeaveIt
	bufferspeciesname STR_VAR_1, SPECIES_BROWT
	givemon SPECIES_BROWT, 5
	setvar VAR_0x8004, LOCALID_YACHT_BALL_BROWT
	goto YachtInterior_EventScript_Took

YachtInterior_EventScript_BallPombon::
	lockall
	showmonpic SPECIES_POMBON, 10, 3
	msgbox YachtInterior_Text_BallPombon, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, YachtInterior_EventScript_LeaveIt
	bufferspeciesname STR_VAR_1, SPECIES_POMBON
	givemon SPECIES_POMBON, 5
	setvar VAR_0x8004, LOCALID_YACHT_BALL_POMBON
	goto YachtInterior_EventScript_Took

YachtInterior_EventScript_BallGecqua::
	lockall
	showmonpic SPECIES_GECQUA, 10, 3
	msgbox YachtInterior_Text_BallGecqua, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, YachtInterior_EventScript_LeaveIt
	bufferspeciesname STR_VAR_1, SPECIES_GECQUA
	givemon SPECIES_GECQUA, 5
	setvar VAR_0x8004, LOCALID_YACHT_BALL_GECQUA
	goto YachtInterior_EventScript_Took

@ One only. The flag goes on first so the other two can never be claimed.
@ The chosen ball leaves with the player; the note under it explains why the
@ other two stay, and they vanish as the lid goes down.
YachtInterior_EventScript_Took::
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, YachtInterior_EventScript_NoRoom
	setflag FLAG_WOT_YACHT_STARTER_TAKEN
	removeobject VAR_0x8004
	playfanfare MUS_OBTAIN_ITEM
	message YachtInterior_Text_Took
	waitmessage
	waitfanfare
	msgbox YachtInterior_Text_AfterTook, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	removeobject LOCALID_YACHT_BALL_BROWT
	removeobject LOCALID_YACHT_BALL_POMBON
	removeobject LOCALID_YACHT_BALL_GECQUA
	waitse
	releaseall
	end

YachtInterior_EventScript_NoRoom::
	msgbox YachtInterior_Text_NoRoom, MSGBOX_DEFAULT
	releaseall
	end

YachtInterior_EventScript_LeaveIt::
	msgbox YachtInterior_Text_LeaveIt, MSGBOX_DEFAULT
	releaseall
	end

@ --- Text ------------------------------------------------------------------
YachtInterior_Text_BallBrowt::
	.string "{JPN}この ボールには てがきの タグが\n"
	.string "はってある。\p"
	.string "「ブラウト。 へやの なかだと おちつかない。\n"
	.string "まどを すこし あけてあげて」\p"
	.string "ブラウトを つれていく？$"

YachtInterior_Text_BallPombon::
	.string "{JPN}この ボールの タグは ふちが\n"
	.string "こげている。\p"
	.string "「ポンボン。 たいおんが たかい。\n"
	.string "もう ちずの うえで ひるねさせないこと」\p"
	.string "ポンボンを つれていく？$"

YachtInterior_Text_BallGecqua::
	.string "{JPN}この タグの インクは みずが\n"
	.string "かかったように にじんでいる。\p"
	.string "「ゲックア。 まいにち みずが ひつよう。\n"
	.string "わすれると すねる」\p"
	.string "ゲックアを つれていく？$"

YachtInterior_Text_Took::
	.string "{JPN}{ENG}{PLAYER}{JPN}は {ENG}{STR_VAR_1}{JPN}を もらった！$"

YachtInterior_Text_AfterTook::
	.string "{JPN}ふたの うらに ふせんが\n"
	.string "はってある。\p"
	.string "「フィールドテストよう。 トレーナー\n"
	.string "1にんに 1ぴきまで！ のこりは よやくずみ」\p"
	.string "のこりの 2つの うえで ふたを しめた。$"

YachtInterior_Text_NoRoom::
	.string "{JPN}てもちも ボックスも\n"
	.string "いっぱいだ。\p"
	.string "ボールを もとに もどした。$"

YachtInterior_Text_LeaveIt::
	.string "{JPN}ボールを だいの うえに\n"
	.string "もどした。$"

YachtInterior_Text_DeskNotes::
	.string "{JPN}つくえの うえは どれも おなじ\n"
	.string "こまかい てがきの かみで いっぱいだ。\p"
	.string "「だい10せだい ごさんけ\n"
	.string "しんか メモ だい11こう。\p"
	.string "「ケースの 3びきは とても げんき。\n"
	.string "デザインした ほんにんより げんき。\p"
	.string "「こんかいの せだいの テーマは\n"
	.string "さらに さきへ。 うえへ したへ\l"
	.string "その おくへ。 ならば ごさんけ\l"
	.string "そのものが たんけんたい だったら？\p"
	.string "「ブラウト: そら。 さいしゅうけいたいは\n"
	.string "だれも いけない うすい くうきの\l"
	.string "なかを とぶ はず。 いまでも\l"
	.string "いちにちじゅう くもを ながめている。\p"
	.string "「ポンボン: どうくつ。 ほのおは\n"
	.string "ランタンに なる。 さきに もぐって\l"
	.string "みんなの みちを てらす。\p"
	.string "「ゲックア: しんかい。 すいあつに\n"
	.string "たえる ほんものの ダイバー。 ひかりが\l"
	.string "とどかない ところで もようが\l"
	.string "ひかる。\p"
	.string "「さいごの タイプが きまらない。\n"
	.string "まずは フィールドテスト それから。\p"
	.string "「…そろそろ ちゃんと\n"
	.string "ねないと」$"
