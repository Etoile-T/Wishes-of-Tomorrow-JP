MunenTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MunenTunnel_OnTransition
	.byte 0

@ Whiteouts in the tunnel respawn at the NewMap inn; Escape Rope / Dig
@ surface at the tunnel mouth on NewMap (warp 10).
MunenTunnel_OnTransition::
	setrespawn HEAL_LOCATION_NEW_MAP_INN
	setescapewarp MAP_NEW_MAP, 10, 0, 0
	end

@ ============================================================================
@  MUNEN TUNNEL -- old burial tunnel of the mountain dead, desecrated by the
@  oni group as a staging camp before their climb. Optional lore dungeon.
@  Front half: tomb (graves, Dusclops warden). Left room: abandoned camp.
@  Top room: deepest chamber -- straggler grunt + the apprentice's carved mask.
@ ============================================================================

@ --------------------------------------------------------------------------
@  Item balls
@ --------------------------------------------------------------------------
MunenTunnel_EventScript_ItemNugget::
	finditem ITEM_NUGGET
	end

MunenTunnel_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER
	end

MunenTunnel_EventScript_ItemTMShadowBall::
	finditem ITEM_TM30
	end

MunenTunnel_EventScript_ItemTMThunderbolt::
	finditem ITEM_TM24
	end

@ The mask stays out of reach while Captain McCormick holds the chamber.
MunenTunnel_EventScript_ItemCarvedMask::
	goto_if_unset FLAG_POMPEII_GENERAL_RETREATED, MunenTunnel_EventScript_MaskGuarded
	finditem ITEM_CARVED_MASK
	end

MunenTunnel_EventScript_MaskGuarded::
	msgbox MunenTunnel_Text_MaskGuarded, MSGBOX_SIGN
	end

@ --------------------------------------------------------------------------
@  The tunnel gauntlet -- Master Gen's quest. Two goons hold the halls and
@  CAPTAIN McCORMICK holds the mask chamber. Basic teams, Lv16-20.
@ --------------------------------------------------------------------------
MunenTunnel_EventScript_GoonA::
	trainerbattle_single TRAINER_TUNNEL_GOON_A, MunenTunnel_Text_GoonAIntro, MunenTunnel_Text_GoonADefeat
	msgbox MunenTunnel_Text_GoonAPost, MSGBOX_AUTOCLOSE
	end

MunenTunnel_EventScript_GoonB::
	trainerbattle_single TRAINER_TUNNEL_GOON_B, MunenTunnel_Text_GoonBIntro, MunenTunnel_Text_GoonBDefeat
	msgbox MunenTunnel_Text_GoonBPost, MSGBOX_AUTOCLOSE
	end

MunenTunnel_EventScript_General::
	trainerbattle_single TRAINER_TUNNEL_CAPTAIN, MunenTunnel_Text_GeneralIntro, MunenTunnel_Text_GeneralDefeat, MunenTunnel_EventScript_GeneralRetreat
	end

MunenTunnel_EventScript_GeneralRetreat::
	lockall
	setspeaker SP_NAME_TUNNEL_CAPTAIN
	msgbox MunenTunnel_Text_GeneralRetreat, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	removeobject VAR_LAST_TALKED
	setflag FLAG_POMPEII_GENERAL_RETREATED
	releaseall
	end

@ --------------------------------------------------------------------------
@  Dusclops -- the tomb's warden. It does not attack. It only watches.
@ --------------------------------------------------------------------------
MunenTunnel_EventScript_Houndoom::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HOUNDOOM, CRY_MODE_NORMAL
	msgbox MunenTunnel_Text_Houndoom, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MunenTunnel_EventScript_Sableye::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SABLEYE, CRY_MODE_NORMAL
	msgbox MunenTunnel_Text_Sableye, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MunenTunnel_EventScript_Mightyena::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MIGHTYENA, CRY_MODE_NORMAL
	msgbox MunenTunnel_Text_Mightyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MunenTunnel_EventScript_Shuppet::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
	msgbox MunenTunnel_Text_Shuppet, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ --------------------------------------------------------------------------
@  Straggler grunt -- left behind to guard the deepest chamber.
@  Local ID 5. Flees after losing; hidden by FLAG_HIDE_MUNEN_TUNNEL_GRUNT.
@ --------------------------------------------------------------------------
MunenTunnel_EventScript_Grunt::
	trainerbattle_single TRAINER_MUNEN_TUNNEL_GRUNT, MunenTunnel_Text_GruntIntro, MunenTunnel_Text_GruntDefeat, MunenTunnel_EventScript_GruntFlee
	end

MunenTunnel_EventScript_GruntFlee::
	lockall
	msgbox MunenTunnel_Text_GruntFlee, MSGBOX_DEFAULT
	closemessage
	applymovement 5, MunenTunnel_Movement_GruntFlee
	waitmovement 0
	removeobject 5
	setflag FLAG_HIDE_MUNEN_TUNNEL_GRUNT
	releaseall
	end

@ Down first, then east. From (94,32) the fourth step east lands on the wall
@ at x=98. Column 94 is clear down to y=35, row 35 runs east to x=96, and
@ column 96 continues down to y=38 -- which is well past the bottom of the
@ screen, so he is gone before removeobject.
MunenTunnel_Movement_GruntFlee:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

@ --------------------------------------------------------------------------
@  Tomb reading material
@ --------------------------------------------------------------------------
MunenTunnel_EventScript_GraveDefaced::
	msgbox MunenTunnel_Text_GraveDefaced, MSGBOX_SIGN
	end

MunenTunnel_EventScript_GraveOfferings::
	msgbox MunenTunnel_Text_GraveOfferings, MSGBOX_SIGN
	end

MunenTunnel_EventScript_WallInscription::
	msgbox MunenTunnel_Text_WallInscription, MSGBOX_SIGN
	end

MunenTunnel_EventScript_CampOrders::
	msgbox MunenTunnel_Text_CampOrders, MSGBOX_SIGN
	end

MunenTunnel_EventScript_UnsentLetter::
	msgbox MunenTunnel_Text_UnsentLetter, MSGBOX_SIGN
	end

@ ============================================================================
@  Text
@ ============================================================================
MunenTunnel_Text_Houndoom::
	.string "{JPN}ヘルガーが けを さかだてて\n"
	.string "はかの あいだを うろついている。\p"
	.string "その めが たいまつの ひかりを とらえた…\n"
	.string "こちらを みかえしている。$"

MunenTunnel_Text_MaskGuarded::
	.string "{JPN}ほりこまれた めんが つちぼこりの なかに ある。\p"
	.string "だが たいちょうの ブーツが\n"
	.string "その すぐ そばに ふみしめられ その めは\l"
	.string "こちらを ぴたりと とらえている。$"

MunenTunnel_Text_GoonAIntro::
	.string "{JPN}おい！ はかばは へいさ ちゅうだ。\n"
	.string "ひきかえせ。\p"
	.string "…ひきかえす きは ねえってか。$"

MunenTunnel_Text_GoonADefeat::
	.string "{JPN}たいちょうに めんを とりあげられちまう\n"
	.string "…$"

MunenTunnel_Text_GoonAPost::
	.string "{JPN}いけよ。 おくの どうくつは\n"
	.string "たいちょうの しごとだ。 おれの じゃねえ。$"

MunenTunnel_Text_GoonBIntro::
	.string "{JPN}もんばんを たおしたって？ はっ。\p"
	.string "あいつは よわい ほうだ。$"

MunenTunnel_Text_GoonBDefeat::
	.string "{JPN}わかった わかった！ おれもだよ！$"

MunenTunnel_Text_GoonBPost::
	.string "{JPN}たいちょうは まけねえ。 おまえも\n"
	.string "ここの はかの じゅうにんと いっしょに\l"
	.string "うめられるぜ。$"

MunenTunnel_Text_GeneralIntro::
	.string "{JPN}とまれ。\p"
	.string "わたしは マコーミックたいちょう。 ねがいが\n"
	.string "てに はいるまで この はかを まもる。\p"
	.string "ぶかを ふたりも やられたか。 こうこがくしゃ\n"
	.string "きどりの こどもに。\p"
	.string "でしの ちいさな めんか？\n"
	.string "あれは やつが すてた つちの なかに\l"
	.string "のこる。 おまえも おなじだ。$"

MunenTunnel_Text_GeneralDefeat::
	.string "{JPN}…ぶたい てっしゅう。$"

MunenTunnel_Text_GeneralRetreat::
	.string "{JPN}はかばは いのちを かけるに あたいしない。\p"
	.string "しんだ おとこの おもちゃは もっていけ。\n"
	.string "うえの やまは すでに われらの ものだ。\l"
	.string "そして リーダーは\l"
	.string "しりぞかない。$"

MunenTunnel_Text_GruntIntro::
	.string "{JPN}ん？ むらの やつか？\p"
	.string "いや… どうでもいい。 ぎしきは もう\n"
	.string "はじまった。 ほかの やつらは みんな のぼった。\p"
	.string "おれの めいれいは かんたんだ。 ここに\n"
	.string "おいていった ものには だれも てを だすな！$"

MunenTunnel_Text_GruntDefeat::
	.string "{JPN}うぐっ！ おれが ここに のこされたのは\n"
	.string "つよいから じゃ なかったのか…$"

MunenTunnel_Text_GruntFlee::
	.string "{JPN}わかって ねえな！ サミットゲートは\n"
	.string "めんを つけた ものにしか ひらかねえ！\p"
	.string "やまは ひとの こうかいを\n"
	.string "しまいこんでる。 マスターは それを\l"
	.string "ぜんぶ かえして くれるんだ！\p"
	.string "わらいたきゃ わらえ！ いまに わかる！\n"
	.string "てっぺんで… みんな わかるさ！$"

MunenTunnel_Text_GraveDefaced::
	.string "{JPN}ふるい はかいしだ。 なまえは\n"
	.string "なんだいも まえに すりきれている。\p"
	.string "いしには あたらしい のみの あとが ある。\n"
	.string "だれかが ここに つのの ある かおを\l"
	.string "ほった。 それも つい さいきんだ。$"

MunenTunnel_Text_GraveOfferings::
	.string "{JPN}この がけからは ひょいっと とびおりて OK。\n"
	.string "わざわざ もどらなくて いいよ。$"

MunenTunnel_Text_WallInscription::
	.string "{JPN}さくせん: ねがい\p"
	.string "だい1だんかい: しにゆく ねがい\n"
	.string "ジラーチを てにいれる。\p"
	.string "だい2だんかい: \p"
	.string "(くろぬり)$"
MunenTunnel_Text_CampOrders::
	.string "{JPN}ねぶくろ つめたい はい からの はこ…\n"
	.string "いしの したに かみきれが\l"
	.string "はさんである。\p"
	.string "こうどうは よるのみ。 むらの ものに\n"
	.string "こちらの かずを さとられるな。\p"
	.string "めんは はずすな。 サミットゲートは\n"
	.string "すがおの ものには ひらかない。\p"
	.string "かねが 2ど なったら この キャンプを\n"
	.string "もやして のぼれ。 M たいちょう$"

MunenTunnel_Text_UnsentLetter::
	.string "{JPN}ていねいに おりたたまれた てがみだ。\n"
	.string "だされることは なかった。\p"
	.string "「ゲンししょう…\p"
	.string "「めんの こと ごめんなさい。 わたしが\n"
	.string "もっていって いい ものじゃ なかった。\p"
	.string "「でも オニの かおを した おとこが\n"
	.string "サミットゲートの むこうで とうさんが\l"
	.string "まってるって いうんです。\p"
	.string "「ねがいは わたしたちの\n"
	.string "こうかいで マスターなら それを\l"
	.string "かえして くれるって。\p"
	.string "「もう いちどだけ とうさんに あいたい。\n"
	.string "いちどで いい。 どうか おわないで ください。\p"
	.string "「リョウコより」$"

MunenTunnel_Text_Sableye::
	.string "{JPN}ヤミラミが はかの かべを\n"
	.string "ひっかいて ほうせきを かじりとっている。\p"
	.string "ほうせきの めが いちど ひかり…\n"
	.string "にやりと わらった。$"

MunenTunnel_Text_Mightyena::
	.string "{JPN}グラエナが はなを ひくく して\n"
	.string "くらやみを ぐるぐる まわっている。\p"
	.string "ひくい うなりごえが しずかに\n"
	.string "しんぼうづよく もれてくる。$"

MunenTunnel_Text_Shuppet::
	.string "{JPN}カゲボウズが つめたい くうきを ひいて\n"
	.string "てんじょうを ただよっている。\p"
	.string "ふりむきも しないのに\n"
	.string "いつのまにか こちらを むいていた。$"

@ --------------------------------------------------------------------------
@  Yiffer (WOT_ALDO sprite) -- Frostwood Gym trainer, out plugging his dojo.
@  A boss fight with a card (same treatment as Siren Allison), then HM
@  STRENGTH once. The HM is also what lets Strength work outside battle:
@  FieldMove_Strength (src/field_move.c) accepts FLAG_RECEIVED_HM_STRENGTH
@  as well as the badge.
@
@  Trainer id: TRAINER_GRUNT_SEAFLOOR_CAVERN_5 (567), REPURPOSED. Raising
@  MAX_TRAINERS_COUNT would shift SYSTEM_FLAGS and break saves, so a new
@  trainer has to reuse an id. This one's only placement is Seafloor Cavern
@  Room 3, which nothing reaches: the cavern's entrance is now the dead-end
@  cave off Munen Lake and has no warp into the rooms. If those rooms are
@  ever wired back up, that grunt will field Yiffer's team.
@
@  Guarded on the HM flag, so a save that already has STRENGTH never fights
@  him, and a loss (normal whiteout) lets the player come back and retry.
@ --------------------------------------------------------------------------
MunenTunnel_EventScript_Yiffer::
	lockall
	faceplayer
	setspeaker SP_NAME_YIFFER
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, MunenTunnel_EventScript_YifferAfter
	msgbox MunenTunnel_Text_YifferPlug, MSGBOX_DEFAULT
	closemessage
	@ Flush the SE bed first, or the card's shimmer can cut out (Edwards).
	special WotStopSceneSE
	bossintro BOSS_INTRO_YIFFER
	trainerbattle_no_intro TRAINER_GRUNT_SEAFLOOR_CAVERN_5, MunenTunnel_Text_YifferDefeat
	setspeaker SP_NAME_YIFFER
	msgbox MunenTunnel_Text_YifferSample, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
	setspeaker SP_NAME_YIFFER
	msgbox MunenTunnel_Text_YifferStrength, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	msgbox MunenTunnel_Text_CanUseStrength, MSGBOX_DEFAULT
	releaseall
	end

MunenTunnel_EventScript_YifferAfter::
	msgbox MunenTunnel_Text_YifferAfter, MSGBOX_DEFAULT
	releaseall
	end

MunenTunnel_Text_YifferPlug:
	.string "{JPN}せんでん させて くれ！ けんかの\n"
	.string "しかたを おぼえるなら BKキックボクシング！\l"
	.string "ぶっとばし かた おしえます…\p"
	.string "…できなきゃ ぜんがく へんきん！\n"
	.string "ほしょう つき！\p"
	.string "ハイィィ ヤーーッ！\p"
	.string "むりょう たいけんレッスン いまから だ！\n"
	.string "いきのこれたら サンプルは きみの ものだ！$"

MunenTunnel_Text_YifferDefeat:
	.string "{JPN}ぐはっ！ おかねを はらう おきゃくさん\n"
	.string "なみの パンチだ！$"

MunenTunnel_Text_YifferSample:
	.string "{JPN}やくそくは やくそくだ。\n"
	.string "むりょう サンプルを どうぞ。$"

MunenTunnel_Text_CanUseStrength:
	.string "{JPN}{ENG}{PLAYER}{JPN}は せんとう いがいでも\n"
	.string "かいりきが つかえるように なった！$"

MunenTunnel_Text_YifferStrength:
	.string "{JPN}それが かいりきだ。 ここの いわを\n"
	.string "ほんきで おしまくれ！$"

MunenTunnel_Text_YifferAfter:
	.string "{JPN}BKキックボクシング。 はつかいは おごりだ。\n"
	.string "ハイィィ ヤーーッ！$"
