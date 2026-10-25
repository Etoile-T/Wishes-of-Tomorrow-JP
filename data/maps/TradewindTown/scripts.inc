TradewindTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TradewindTown_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TradewindTown_OnLoad
	.byte 0

@ Whiteout respawn: Tradewind has no Pokemon Center, so without this a faint
@ here sent the player all the way back to a pre-Star-Summit Act 1 spawn. Making
@ the town its own heal location keeps the playthrough local.
@ Hotel Z's door (23,17) stays shut until the Mega Doomsday intro has played
@ (the metatile keeps its collision on the map; this clears it).
TradewindTown_OnLoad::
	call_if_set FLAG_WOT_MEGA_DOOMSDAY_INTRO, TradewindTown_EventScript_OpenHotelZDoor
	end

TradewindTown_EventScript_OpenHotelZDoor::
	setmetatile 23, 17, 0x7A, FALSE
	return

TradewindTown_OnTransition::
	setrespawn HEAL_LOCATION_TRADEWIND_TOWN
	@ Lida and Canari only exist inside the Mega Doomsday intro (addobject).
	setflag FLAG_HIDE_TRADEWIND_LIDA_CANARI
	@ So does the rift they come through (the daily portals have their own).
	setflag FLAG_HIDE_TRADEWIND_INTRO_PORTAL
	end

@ ============================================================================
@  B1 - Curio Merchant "Curios of the Crossing"
@  RESTORED (Joe, 2026-08-10): the stall sells the seven impossible-goods
@  CURIO ITEMS again (1,000 each, plain pokemart) -- the Pawnbroker (below,
@  post-Lantern-Badge) exchanges each curio for its Mega Stone. The V3
@  direct-mega-stone menu is retired; FLAG_CURIO_* / MULTI_TRADEWIND_CURIOS
@  stay defined but unused.
@ ============================================================================
Tradewind_EventScript_CurioMerchant::
	lock
	faceplayer
	message Tradewind_Text_CurioGreeting
	waitmessage
	pokemart Tradewind_CurioMart
	msgbox Tradewind_Text_CurioFarewell, MSGBOX_DEFAULT
	release
	end

	.align 2
Tradewind_CurioMart:
	.2byte ITEM_BOTTLED_WARMTH
	.2byte ITEM_BORROWED_YEARS
	.2byte ITEM_UNSPOKEN_LAST_WORDS
	.2byte ITEM_A_STRANGERS_NAME
	.2byte ITEM_FOLDED_GOODBYE
	.2byte ITEM_ONE_GOOD_DREAM
	.2byte ITEM_THE_LONG_WAY_HOME
	pokemartlistend

@ ============================================================================
@  B2 - The Pawnbroker of Bonds (Mega-stone exchange)
@  Hidden until the Lantern Badge. Transmutes a curio into its Mega Stone.
@ ============================================================================
Tradewind_EventScript_Pawnbroker::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE_LANTERN, Tradewind_EventScript_PawnbrokerClosed
	msgbox Tradewind_Text_PawnbrokerOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Tradewind_EventScript_PawnDone
	checkitem ITEM_BOTTLED_WARMTH
	goto_if_eq VAR_RESULT, TRUE, Tradewind_EventScript_PawnBottledWarmth
	checkitem ITEM_BORROWED_YEARS
	goto_if_eq VAR_RESULT, TRUE, Tradewind_EventScript_PawnBorrowedYears
	checkitem ITEM_UNSPOKEN_LAST_WORDS
	goto_if_eq VAR_RESULT, TRUE, Tradewind_EventScript_PawnUnspoken
	checkitem ITEM_A_STRANGERS_NAME
	goto_if_eq VAR_RESULT, TRUE, Tradewind_EventScript_PawnStranger
	checkitem ITEM_FOLDED_GOODBYE
	goto_if_eq VAR_RESULT, TRUE, Tradewind_EventScript_PawnFolded
	checkitem ITEM_ONE_GOOD_DREAM
	goto_if_eq VAR_RESULT, TRUE, Tradewind_EventScript_PawnDream
	checkitem ITEM_THE_LONG_WAY_HOME
	goto_if_eq VAR_RESULT, TRUE, Tradewind_EventScript_PawnLongWay
	msgbox Tradewind_Text_PawnNoCurio, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_PawnBottledWarmth::
	removeitem ITEM_BOTTLED_WARMTH
	giveitem ITEM_HOUNDOOMINITE
	goto Tradewind_EventScript_PawnRevealed
Tradewind_EventScript_PawnBorrowedYears::
	removeitem ITEM_BORROWED_YEARS
	giveitem ITEM_BANETTITE
	goto Tradewind_EventScript_PawnRevealed
Tradewind_EventScript_PawnUnspoken::
	removeitem ITEM_UNSPOKEN_LAST_WORDS
	giveitem ITEM_SABLENITE
	goto Tradewind_EventScript_PawnRevealed
Tradewind_EventScript_PawnStranger::
	removeitem ITEM_A_STRANGERS_NAME
	giveitem ITEM_ABSOLITE
	goto Tradewind_EventScript_PawnRevealed
Tradewind_EventScript_PawnFolded::
	removeitem ITEM_FOLDED_GOODBYE
	giveitem ITEM_GARDEVOIRITE
	goto Tradewind_EventScript_PawnRevealed
Tradewind_EventScript_PawnDream::
	removeitem ITEM_ONE_GOOD_DREAM
	giveitem ITEM_MAWILITE
	goto Tradewind_EventScript_PawnRevealed
Tradewind_EventScript_PawnLongWay::
	removeitem ITEM_THE_LONG_WAY_HOME
	giveitem ITEM_BLAZIKENITE
	goto Tradewind_EventScript_PawnRevealed

Tradewind_EventScript_PawnRevealed::
	msgbox Tradewind_Text_StoneRevealed, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_PawnbrokerClosed::
	msgbox Tradewind_Text_PawnbrokerClosed, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_PawnDone::
	msgbox Tradewind_Text_PawnFarewell, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  G - The Lantern Gym (open-air, optional)
@  Three gym trainers, then Madam Tsuji. Victory = Lantern Badge + Mega Ring
@  + Gengarite, and the Pawnbroker stall opens (curio -> Mega Stone trade).
@ ============================================================================
Tradewind_EventScript_GymGoro::
	lock
	faceplayer
	goto_if_defeated TRAINER_TRADEWIND_GORO, Tradewind_EventScript_GoroDefeated
	trainerbattle_no_intro TRAINER_TRADEWIND_GORO, Tradewind_Text_GoroDefeat
	msgbox Tradewind_Text_GoroPostBattle, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GoroDefeated::
	msgbox Tradewind_Text_GoroPostBattle, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GymLanternBearer::
	lock
	faceplayer
	goto_if_defeated TRAINER_TRADEWIND_LANTERN_BEARER, Tradewind_EventScript_LanternBearerDefeated
	trainerbattle_no_intro TRAINER_TRADEWIND_LANTERN_BEARER, Tradewind_Text_LanternBearerDefeat
	msgbox Tradewind_Text_LanternBearerPostBattle, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_LanternBearerDefeated::
	msgbox Tradewind_Text_LanternBearerPostBattle, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GymApprentice::
	lock
	faceplayer
	goto_if_defeated TRAINER_TSUJI_APPRENTICE, Tradewind_EventScript_ApprenticeDefeated
	trainerbattle_no_intro TRAINER_TSUJI_APPRENTICE, Tradewind_Text_ApprenticeDefeat
	msgbox Tradewind_Text_ApprenticePostBattle, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_ApprenticeDefeated::
	msgbox Tradewind_Text_ApprenticePostBattle, MSGBOX_DEFAULT
	release
	end

@ --- Madam Tsuji -------------------------------------------------------------
Tradewind_EventScript_MadamTsuji::
	lock
	faceplayer
	goto_if_set FLAG_BADGE_LANTERN, Tradewind_EventScript_TsujiPostBadge
	goto_if_not_defeated TRAINER_TRADEWIND_GORO, Tradewind_EventScript_TsujiNotReady
	goto_if_not_defeated TRAINER_TRADEWIND_LANTERN_BEARER, Tradewind_EventScript_TsujiNotReady
	goto_if_not_defeated TRAINER_TSUJI_APPRENTICE, Tradewind_EventScript_TsujiNotReady
	setspeaker SP_NAME_MADAM_TSUJI
	msgbox Tradewind_Text_TsujiMegaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MADAM_TSUJI, Tradewind_Text_TsujiDefeat
	setspeaker SP_NAME_MADAM_TSUJI
	msgbox Tradewind_Text_TsujiBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE_LANTERN
	setspeaker SP_NAME_NONE
	giveitem ITEM_MEGA_RING
	giveitem ITEM_GENGARITE
	clearflag FLAG_HIDE_TRADEWIND_PAWNBROKER
	setspeaker SP_NAME_MADAM_TSUJI
	msgbox Tradewind_Text_TsujiPawnbrokerHint, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_TsujiNotReady::
	setspeaker SP_NAME_MADAM_TSUJI
	msgbox Tradewind_Text_TsujiNotReady, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_TsujiPostBadge::
	setspeaker SP_NAME_MADAM_TSUJI
	msgbox Tradewind_Text_TsujiPostBadge, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  A - Ambiance spirits (dialogue-only veil-market flavor)
@ ============================================================================
Tradewind_EventScript_DontEatHere::
	lock
	faceplayer
	msgbox Tradewind_Text_DontEatHere, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_FaeTouchedHint::
	lock
	faceplayer
	msgbox Tradewind_Text_FaeTouchedHint, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_AfterlifeRealtor::
	lock
	faceplayer
	msgbox Tradewind_Text_AfterlifeRealtor, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_SpiritShopper1::
	lock
	faceplayer
	msgbox Tradewind_Text_SpiritShopper1, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_SpiritShopper2::
	lock
	faceplayer
	msgbox Tradewind_Text_SpiritShopper2, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_MaskedMerchant::
	lock
	faceplayer
	msgbox Tradewind_Text_MaskedMerchant, MSGBOX_DEFAULT
	release
	end

@ Locked doors (bg_event signs on the shut storefronts)
Tradewind_EventScript_LockedDoor::
	msgbox Tradewind_Text_LockedDoor, MSGBOX_SIGN
	end

@ Hotel Z's door (23,17): locked until the Mega Doomsday intro. After it,
@ walking into the door warps in; reading it says nothing.
Tradewind_EventScript_HotelZDoor::
	goto_if_set FLAG_WOT_MEGA_DOOMSDAY_INTRO, Tradewind_EventScript_HotelZDoorOpen
	msgbox Tradewind_Text_LockedDoor, MSGBOX_SIGN
Tradewind_EventScript_HotelZDoorOpen::
	end

@ Dev-only wall on the far-west edge (coord triggers x=3, y=17-22): shows the
@ note and pushes the player back east.
Tradewind_EventScript_DevWall::
	lockall
	msgbox Tradewind_Text_DevWall, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Tradewind_Movement_DevWallBack
	waitmovement 0
	releaseall
	end

Tradewind_Movement_DevWallBack:
	walk_right
	step_end

@ Foreshadows Tsuji's Mega Ring + Gengarite reward
Tradewind_EventScript_MegaHint::
	lock
	faceplayer
	msgbox Tradewind_Text_MegaHint, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  Ghosts of the night market -- wild spirits drifting the stalls and the
@  black mirror-water on the town's east edge, plus two human(?) residents.
@ ============================================================================
Tradewind_EventScript_GhostDrifloon::
	lock
	faceplayer
	playmoncry SPECIES_DRIFLOON, CRY_MODE_NORMAL
	waitmoncry
	msgbox Tradewind_Text_GhostDrifloon, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostLampent::
	lock
	faceplayer
	playmoncry SPECIES_LAMPENT, CRY_MODE_NORMAL
	waitmoncry
	msgbox Tradewind_Text_GhostLampent, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostGastly::
	lock
	faceplayer
	playmoncry SPECIES_GASTLY, CRY_MODE_NORMAL
	waitmoncry
	msgbox Tradewind_Text_GhostGastly, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostDuskull::
	lock
	faceplayer
	playmoncry SPECIES_DUSKULL, CRY_MODE_NORMAL
	waitmoncry
	msgbox Tradewind_Text_GhostDuskull, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostLitwick::
	lock
	faceplayer
	playmoncry SPECIES_LITWICK, CRY_MODE_NORMAL
	waitmoncry
	msgbox Tradewind_Text_GhostLitwick, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostShuppet::
	lock
	faceplayer
	playmoncry SPECIES_SHUPPET, CRY_MODE_NORMAL
	waitmoncry
	msgbox Tradewind_Text_GhostShuppet, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostMisdreavus::
	lock
	faceplayer
	playmoncry SPECIES_MISDREAVUS, CRY_MODE_NORMAL
	waitmoncry
	msgbox Tradewind_Text_GhostMisdreavus, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostChanneler::
	lock
	faceplayer
	msgbox Tradewind_Text_GhostChanneler, MSGBOX_DEFAULT
	release
	end

Tradewind_EventScript_GhostDancer::
	lock
	faceplayer
	msgbox Tradewind_Text_GhostDancer, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  Street trainers (eerie night-market, <=Lv20)
@ ============================================================================
Tradewind_EventScript_TrainerSable::
	trainerbattle_single TRAINER_TRADEWIND_SABLE, Tradewind_Text_SableIntro, Tradewind_Text_SableDefeat
	msgbox Tradewind_Text_SablePostBattle, MSGBOX_AUTOCLOSE
	end

Tradewind_EventScript_TrainerRoshan::
	trainerbattle_single TRAINER_TRADEWIND_ROSHAN, Tradewind_Text_RoshanIntro, Tradewind_Text_RoshanDefeat
	msgbox Tradewind_Text_RoshanPostBattle, MSGBOX_AUTOCLOSE
	end

Tradewind_EventScript_TrainerPiper::
	trainerbattle_single TRAINER_TRADEWIND_PIPER, Tradewind_Text_PiperIntro, Tradewind_Text_PiperDefeat
	msgbox Tradewind_Text_PiperPostBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@  Text
@ ============================================================================
Tradewind_Text_CurioGreeting::
	.string "{JPN}あのよへの わたりばの めずらしなだよ。\n"
	.string "1つ 1000円。\p"
	.string "しきものを ながめて\n"
	.string "こころを ひかれたものを どうぞ。$"

Tradewind_Text_CurioFarewell::
	.string "{JPN}わたりばには きまった じかんが ある。\n"
	.string "また いつでも おいで。$"

Tradewind_Text_PawnbrokerOffer::
	.string "{JPN}ほう。 めずらしなと それを つかうための\n"
	.string "バッジを もっているな。\p"
	.string "1つ よこしな。 ほんとうの すがたが…\n"
	.string "いま はじめて みえるのさ。$"

Tradewind_Text_StoneRevealed::
	.string "{JPN}ほら。 きずなが かたちに なった。\n"
	.string "ずっと このまま まっていたんだ。$"

Tradewind_Text_PawnNoCurio::
	.string "{JPN}めずらしなが なけりゃ こうかんは なし。\n"
	.string "めずらしなうりなら\l"
	.string "このさきに いるよ。$"

Tradewind_Text_PawnbrokerClosed::
	.string "{JPN}この みせの あかりは あんたのためじゃない。\n"
	.string "まだな。 まずは ランタンを てにいれな。\l"
	.string "はなしは それからだ。$"

Tradewind_Text_PawnFarewell::
	.string "{JPN}きずなは のこる。 1つ てばなす\n"
	.string "きに なったら また おいで。$"

Tradewind_Text_GoroDefeat::
	.string "{JPN}ぐああ! はらは いっぱいなのに\n"
	.string "しょうりは からっぽ…$"

Tradewind_Text_GoroPostBattle::
	.string "{JPN}いちばの おきて その1。\n"
	.string "だされたものを たべるな。\p"
	.string "その2。 はらぺこで\n"
	.string "ツジふじんに いどむな。$"

Tradewind_Text_LanternBearerDefeat::
	.string "{JPN}きつねびが…\n"
	.string "きえていく…$"

Tradewind_Text_LanternBearerPostBattle::
	.string "{JPN}この いちばで ランタンを おえば\n"
	.string "あさまで おなじ ところを\l"
	.string "ぐるぐる あるくことに なる。\p"
	.string "ツジふじんは じぶんで あかりを ともす。$"

Tradewind_Text_ApprenticeDefeat::
	.string "{JPN}しなさだめを されて… おとされた。\n"
	.string "あなたじゃなくて わたしがね。$"

Tradewind_Text_ApprenticePostBattle::
	.string "{JPN}この いちばを とおるものを みきわめる。\n"
	.string "がらくたか たからか\l"
	.string "わたしには わかるんだ。\p"
	.string "あなたは たからだ。 ツジふじんも\n"
	.string "あいたがるだろう。$"

Tradewind_Text_TsujiNotReady::
	.string "{JPN}ツジふじんは ちからを しめさぬものには\n"
	.string "あってくださらない。\p"
	.string "この いちばを まもる なかまは 3にん。\n"
	.string "まずは かれらを たおせ。\l"
	.string "はなしは それからだ。$"

Tradewind_Text_TsujiMegaIntro::
	.string "{JPN}なるほど。 うちの 3にんでも\n"
	.string "とめられなかったのね。\p"
	.string "わたしは ツジ。 きずなを あつかうの。\n"
	.string "トレーナーと ポケモンの あいだに\l"
	.string "むすばれる きずなをね。\p"
	.string "きずなを かたく よりあわせれば\n"
	.string "いしに なる。 たたかいの なかで\l"
	.string "その いしを うてば\l"
	.string "しんかを こえた ちからに かわる。\p"
	.string "ひとは それを メガシンカと よぶの。\n"
	.string "よく ごらんなさい。 その だいしょうは\l"
	.string "あなたの はいぼくだけれど。$"

Tradewind_Text_TsujiDefeat::
	.string "{JPN}…こんどは きずなが わたしに みかたした。\n"
	.string "なんて ふしぎなのかしら。$"

Tradewind_Text_TsujiBadgeSpeech::
	.string "{JPN}ランタンバッジを うけとりなさい。\n"
	.string "その あかりに ふさわしい ひとよ。\p"
	.string "それと メガリングも。 はじめの 1つに\n"
	.string "この いしを あげるわ。\p"
	.string "きずなを かたく よりあわせれば\n"
	.string "いしに なる。 これからは\l"
	.string "あなた じしんで その ひばなを\l"
	.string "おこせるのよ。$"

Tradewind_Text_TsujiPawnbrokerHint::
	.string "{JPN}もう 1つ。 しちやの みせに\n"
	.string "ともる あかりは もう\l"
	.string "あなたを むかえてくれるわ。\p"
	.string "いちばで うっている めずらしなを\n"
	.string "1つ もっていって\l"
	.string "ほんとうの すがたを たしかめなさい。$"

Tradewind_Text_TsujiPostBadge::
	.string "{JPN}ランタンバッジが\n"
	.string "にあっているわ。\p"
	.string "めずらしなを しちやに わたしなさい。\n"
	.string "どんな きずなも\l"
	.string "しってもらいたいと ねがうものよ。$"

Tradewind_Text_DontEatHere::
	.string "{JPN}たべるな。 なにが あっても\n"
	.string "ここで たべちゃ いけない。\p"
	.string "にどと おなかは すかない…\n"
	.string "そして でていけなくなる。$"

Tradewind_Text_FaeTouchedHint::
	.string "{JPN}うえでは きをつけな。 ここでは\n"
	.string "ようせいの ちからを やどすものだけが\l"
	.string "ほんとうの いちげきを あてられる。\p"
	.string "ようせいの ちからを もたずに きたら\n"
	.string "なにも もってこなかったのと おなじさ。$"

Tradewind_Text_AfterlifeRealtor::
	.string "{JPN}はかちだよ! いい はかちだよ!\n"
	.string "えいえんの やすらぎに うみの ながめ…\p"
	.string "ジムまで あるいて すぐ。 はやいものがち。\n"
	.string "いつまでも あるものなど ないからね。$"

Tradewind_Text_SpiritShopper1::
	.string "{JPN}…つめたい て。 あたたかい スープ。\n"
	.string "つめたい て…$"

Tradewind_Text_SpiritShopper2::
	.string "{JPN}たった 1つのものを かいに きただけ。\n"
	.string "なんだったか わすれたけど。$"

Tradewind_Text_MaskedMerchant::
	.string "{JPN}おめんの した? また おめんさ。\n"
	.string "えがおを かわないか。\l"
	.string "ちょっとしか つかってないよ。$"

@ ============================================================================
@  THE SILENT BOATMAN (Act 2) -- ferries to the occupied National Park.
@  He never speaks. Object: OBJ_EVENT_GFX_SAILOR at the waterline (18,28),
@  Landing on the park side: (16,38), in front of the return boatman (16,37).
@  best-guess coords -- nudge in Porymap. Arrival back from the park lands
@  at (18,27), directly above him.
@  NOT story-gated yet: he ferries whenever asked. Gate with an Act 2 flag
@  (object "flag" field or a goto_if_unset) once the act transition exists.
@ ============================================================================
Tradewind_EventScript_Boatman::
	lock
	faceplayer
	msgbox Tradewind_Text_BoatmanOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Tradewind_EventScript_BoatmanStay
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SHIP
	delay 30
	warp MAP_NATIONAL_PARK_ACT2, 16, 38
	waitstate
	release
	end

Tradewind_EventScript_BoatmanStay::
	msgbox Tradewind_Text_BoatmanStay, MSGBOX_DEFAULT
	release
	end

Tradewind_Text_BoatmanOffer::
	.string "{JPN}あのよとの さかいを わたるかい?$"

Tradewind_Text_BoatmanStay::
	.string "{JPN}わたしもりは ふたたび\n"
	.string "みなもに めを むけた。\p"
	.string "ランタンは ともったまま。\n"
	.string "いまも のせてくれる ようだ。$"

Tradewind_Text_LockedDoor::
	.string "{JPN}かぎが かかっている…$"

Tradewind_Text_DevWall::
	.string "{JPN}(かいはつしゃ せんようエリア。\n"
	.string "とくべつな けんげんが ひつようです。)$"

Tradewind_Text_GhostDrifloon::
	.string "{JPN}フワンテが かぜに さからって ただよい\n"
	.string "さそうように ひもを たらしている。\p"
	.string "その てを とっては いけない。$"

Tradewind_Text_GhostLampent::
	.string "{JPN}ランプラーは くろい みなもの うえで\n"
	.string "ぴくりとも うごかない。\p"
	.string "なにひとつ うつらない はずの ところに\n"
	.string "その ほのおが うつっている。$"

Tradewind_Text_GhostGastly::
	.string "{JPN}ゴースは あなたではなく みなもの あなたに\n"
	.string "にやりと わらいかけている。$"

Tradewind_Text_GhostDuskull::
	.string "{JPN}ヨマワルの ひとつめが\n"
	.string "めの くぼみから くぼみへ うごく…\p"
	.string "かいものきゃくを かぞえている。\n"
	.string "かずが 1にん おおい。$"

Tradewind_Text_GhostLitwick::
	.string "{JPN}ヒトモシの ほのおが てまねきする ゆびのように\n"
	.string "こちらに かたむく。\p"
	.string "いちばの ランタンも いっしょに かたむく。$"

Tradewind_Text_GhostShuppet::
	.string "{JPN}カゲボウズは みせさきの おめんに\n"
	.string "まぎれこんでいる。\p"
	.string "おめんの 1つが いきを している。$"

Tradewind_Text_GhostMisdreavus::
	.string "{JPN}ムウマが こもりうたを くちずさむ。\p"
	.string "まえにも きいた。 どこだったか\n"
	.string "おもいだせない。 ムウマは わらっている。$"

Tradewind_Text_GhostChanneler::
	.string "{JPN}ここでは ししゃも いきた ひとも とりひきする。\n"
	.string "うたがうなら みせの ひとの\l"
	.string "あしを みるといい。\p"
	.string "じめんに あしが ついているのが\n"
	.string "おきゃくさんだ。$"

Tradewind_Text_GhostDancer::
	.string "{JPN}この いちばで はじめて ランタンを ともしたとき\n"
	.string "わたしは おどったの。\p"
	.string "あれは… そうね\n"
	.string "140ねん まえだったわ。\p"
	.string "…どうして そんな めで\n"
	.string "みるの?$"

Tradewind_Text_MegaHint::
	.string "{JPN}ツジふじんの ゆびわは みた?\n"
	.string "はまってる いしは ほうせきじゃないの。\p"
	.string "ランタンの ひが よわると\n"
	.string "あの いしに ふれるんだって。 すると\l"
	.string "パートナーが ちがうものに なるの。\p"
	.string "メガシンカって としよりは よぶわ。\n"
	.string "しらない ひとには ぜったい\l"
	.string "みせてくれないけど。\p"
	.string "でも バッジを てにいれたら…\n"
	.string "なにを さずけてくれるかしらね。$"

Tradewind_Text_SableIntro::
	.string "{JPN}ランタンが うちの かわいい こたちに\n"
	.string "ささやくの。 いまは\l"
	.string "あなたの はなしを しているわ。$"

Tradewind_Text_SableDefeat::
	.string "{JPN}しっ… しずかに なっちゃった。$"

Tradewind_Text_SablePostBattle::
	.string "{JPN}うちの こたちは きにいった いきた ひととしか\n"
	.string "あそばないの。 こうえいに おもってね。$"

Tradewind_Text_RoshanIntro::
	.string "{JPN}この いちばの きゃくの はんぶんには\n"
	.string "かげが ない。 あなたが どちらの はんぶんか\l"
	.string "あててみるかい?$"

Tradewind_Text_RoshanDefeat::
	.string "{JPN}ああ。 やりかえしてくる ほうだったか。$"

Tradewind_Text_RoshanPostBattle::
	.string "{JPN}つめたい しょうにんの しなは かわないこと。\n"
	.string "あの おつりは いつも\l"
	.string "すこし ふるすぎるんだ。$"

Tradewind_Text_PiperIntro::
	.string "{JPN}おばあちゃんが よるの いちばで\n"
	.string "くちぶえを ふいちゃ だめって。\p"
	.string "いつだって ふいちゃうけどね!$"

Tradewind_Text_PiperDefeat::
	.string "{JPN}ひゃっ! くちぶえが かえってきた!$"

Tradewind_Text_PiperPostBattle::
	.string "{JPN}ほうせきの みせから ヤミラミが ついてきたの。\n"
	.string "それとも ヤミラミの いえに ついていったのかな。\l"
	.string "よく おぼえてないや。$"

@ ============================================================================
@  MEGA DOOMSDAY -- the Mega Dimension's opening scene (first time the player
@  comes down the arrival corridor from the Ashlands). The camera pans to the
@  portal, Lida and Canari step out of it, it collapses behind them, they
@  notice the player, introduce themselves and head off; the quest starts and
@  the daily portals unlock (FLAG_WOT_MEGA_DOOMSDAY_INTRO, no Mega Ring needed).
@  Trigger row: y=10, x=28-32 (VAR_TEMP_1 = 0). The player is first stepped to
@  column 30 so every movement below is fixed.
@ ============================================================================
TradewindTown_EventScript_MegaDoomsdayIntro::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_WOT_MEGA_DOOMSDAY_INTRO, TradewindTown_EventScript_MegaDoomsdayIntroDone
	playbgm MUS_ENCOUNTER_SUSPICIOUS, FALSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8004, 28, TradewindTown_EventScript_IntroStepRight2
	call_if_eq VAR_0x8004, 29, TradewindTown_EventScript_IntroStepRight1
	call_if_eq VAR_0x8004, 31, TradewindTown_EventScript_IntroStepLeft1
	call_if_eq VAR_0x8004, 32, TradewindTown_EventScript_IntroStepLeft2
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	@ The camera drifts down the corridor to a crackling rift.
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, TradewindTown_Movement_CameraToPortal
	waitmovement 0
	clearflag FLAG_HIDE_TRADEWIND_INTRO_PORTAL
	addobject LOCALID_TRADEWIND_MEGA_PORTAL
	playse SE_M_TELEPORT
	special StartRiftDistortion
	delay 40
	@ Lida and Canari step out of it.
	setobjectxyperm LOCALID_TRADEWIND_LIDA, 30, 14
	setobjectxyperm LOCALID_TRADEWIND_CANARI, 30, 14
	clearflag FLAG_HIDE_TRADEWIND_LIDA_CANARI
	addobject LOCALID_TRADEWIND_LIDA
	addobject LOCALID_TRADEWIND_CANARI
	playse SE_WARP_OUT
	applymovement LOCALID_TRADEWIND_LIDA, TradewindTown_Movement_LidaStepsOut
	applymovement LOCALID_TRADEWIND_CANARI, TradewindTown_Movement_CanariStepsOut
	waitmovement LOCALID_TRADEWIND_LIDA
	waitmovement LOCALID_TRADEWIND_CANARI
	@ They're through: the shaking stops, the portal stays open behind them.
	special EndRiftDistortion
	applymovement LOCALID_TRADEWIND_LIDA, Common_Movement_FaceRight
	applymovement LOCALID_TRADEWIND_CANARI, Common_Movement_FaceLeft
	waitmovement 0
	setspeaker SP_NAME_LIDA
	msgbox TradewindTown_Text_LidaEnoughResearch, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	@ The portal lingers until Lida's said her piece, then closes.
	playse SE_WARP_IN
	removeobject LOCALID_TRADEWIND_MEGA_PORTAL
	delay 30
	setspeaker SP_NAME_CANARI
	msgbox TradewindTown_Text_CanariBattery, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	@ They notice the player.
	applymovement LOCALID_TRADEWIND_LIDA, TradewindTown_Movement_NoticeUp
	applymovement LOCALID_TRADEWIND_CANARI, TradewindTown_Movement_NoticeUp
	waitmovement LOCALID_TRADEWIND_LIDA
	waitmovement LOCALID_TRADEWIND_CANARI
	applymovement LOCALID_CAMERA, TradewindTown_Movement_CameraToPlayer
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_TRADEWIND_LIDA, TradewindTown_Movement_LidaApproach
	applymovement LOCALID_TRADEWIND_CANARI, TradewindTown_Movement_CanariApproach
	waitmovement LOCALID_TRADEWIND_LIDA
	waitmovement LOCALID_TRADEWIND_CANARI
	setspeaker SP_NAME_LIDA
	msgbox TradewindTown_Text_LidaAreYou, MSGBOX_DEFAULT
	msgbox TradewindTown_Text_LidaIntro, MSGBOX_DEFAULT
	setspeaker SP_NAME_CANARI
	msgbox TradewindTown_Text_CanariHelp, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	@ Off they go, south down the corridor and into Hotel Z (23,17).
	setmetatile 23, 17, 0x7A, FALSE
	applymovement LOCALID_TRADEWIND_LIDA, TradewindTown_Movement_LidaLeaves
	applymovement LOCALID_TRADEWIND_CANARI, TradewindTown_Movement_CanariLeaves
	waitmovement LOCALID_TRADEWIND_LIDA
	playse SE_EXIT
	removeobject LOCALID_TRADEWIND_LIDA
	waitmovement LOCALID_TRADEWIND_CANARI
	playse SE_EXIT
	removeobject LOCALID_TRADEWIND_CANARI
	setflag FLAG_HIDE_TRADEWIND_LIDA_CANARI
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setflag FLAG_WOT_MEGA_DOOMSDAY_INTRO
	@ Today's rift just collapsed; the first real portals open tomorrow at 8:00.
	special WotMegaDim_CloseTodaysPortal
	startquest QUEST_MEGA_DOOMSDAY
	fadedefaultbgm
	releaseall
	end

TradewindTown_EventScript_MegaDoomsdayIntroDone::
	releaseall
	end

TradewindTown_EventScript_IntroStepRight2::
	applymovement LOCALID_PLAYER, TradewindTown_Movement_StepRight2
	waitmovement 0
	return

TradewindTown_EventScript_IntroStepRight1::
	applymovement LOCALID_PLAYER, TradewindTown_Movement_StepRight1
	waitmovement 0
	return

TradewindTown_EventScript_IntroStepLeft1::
	applymovement LOCALID_PLAYER, TradewindTown_Movement_StepLeft1
	waitmovement 0
	return

TradewindTown_EventScript_IntroStepLeft2::
	applymovement LOCALID_PLAYER, TradewindTown_Movement_StepLeft2
	waitmovement 0
	return

TradewindTown_Movement_StepRight2:
	walk_right
	walk_right
	step_end

TradewindTown_Movement_StepRight1:
	walk_right
	step_end

TradewindTown_Movement_StepLeft1:
	walk_left
	step_end

TradewindTown_Movement_StepLeft2:
	walk_left
	walk_left
	step_end

@ Player at (30,10); the portal is at (30,14).
TradewindTown_Movement_CameraToPortal:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

TradewindTown_Movement_CameraToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Out of the rift at (30,14): Lida to (29,14), Canari to (31,14).
TradewindTown_Movement_LidaStepsOut:
	walk_left
	step_end

TradewindTown_Movement_CanariStepsOut:
	walk_right
	step_end

TradewindTown_Movement_NoticeUp:
	face_up
	emote_exclamation_mark
	delay_16
	step_end

@ Up the corridor to stand just below the player: Lida (30,11), Canari (31,11).
TradewindTown_Movement_LidaApproach:
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

TradewindTown_Movement_CanariApproach:
	walk_up
	walk_up
	walk_up
	step_end

@ South down the corridor to the open road at y=18, then west until they're
@ out of sight (the camera sits on the player at (30,10)).
TradewindTown_Movement_LidaLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

TradewindTown_Movement_CanariLeaves:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

TradewindTown_Text_LidaEnoughResearch:
	.string "{JPN}ふう… きょうの ちょうさは これくらいね。\n"
	.string "ホテルZへ もどりましょう。$"

TradewindTown_Text_CanariBattery:
	.string "{JPN}さんせい。 バッテリーは のこり 2パーセント。\n"
	.string "あたしもね。$"

TradewindTown_Text_LidaAreYou:
	.string "{JPN}まって… あなたが {ENG}{PLAYER}{JPN}?\p"
	.string "スターサミットでの はなしは\n"
	.string "きいたわ。\p"
	.string "オニに いどむなんて\n"
	.string "ずいぶん どきょうが あるのね。$"

TradewindTown_Text_LidaIntro:
	.string "{JPN}わたしは リダ。 こっちは カナリィ。$"

TradewindTown_Text_CanariHelp:
	.string "{JPN}あんたの ちからが ひつようなんだ。\n"
	.string "じかんが できたら ホテルZに きてね!$"
