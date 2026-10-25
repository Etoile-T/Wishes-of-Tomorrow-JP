NationalParkAct2_MapScripts::
	.byte 0

@ ============================================================================
@  NATIONAL PARK -- ACT 2 (occupied)
@  The oni group holds the park. Fog, empty beach, ghosts loose near the
@  grave. Goons seal every land exit; only the gravesite is left open --
@  "the master said the grave stays open."
@  Entry/exit: the silent boatman ferries to/from Tradewind Town.
@  The gravesite is a thin place: with the CATALPA BOW it crosses to the
@  Distortion World (Prof. Clarkson).
@  Blocker goons reuse OniMask_EventScript_GoonNod (mask-aware).
@  Trainer goons use the Carved Mask disguise pattern (checkitem first).
@ ============================================================================

@ --------------------------------------------------------------------------
@  Silent boatman (return trip). He never speaks.
@ --------------------------------------------------------------------------
NationalParkAct2_EventScript_Boatman::
	lock
	faceplayer
	msgbox NationalParkAct2_Text_BoatmanOffer, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NationalParkAct2_EventScript_BoatmanStay
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SHIP
	delay 30
	warp MAP_TRADEWIND_TOWN, 67, 27
	waitstate
	release
	end

NationalParkAct2_EventScript_BoatmanStay::
	msgbox NationalParkAct2_Text_BoatmanStay, MSGBOX_DEFAULT
	release
	end

@ --------------------------------------------------------------------------
@  Gravesite -- the thin place. The sign is flavor + a hint; the CROSSING
@  happens when the player USES the CATALPA BOW from the bag nearby
@  (ItemUseOutOfBattle_CatalpaBow in src/item_use.c runs
@   NationalParkAct2_EventScript_CatalpaBowCrossing).
@ --------------------------------------------------------------------------
NationalParkAct2_EventScript_Gravesite::
	lockall
	goto_if_set FLAG_ACT2_MET_CLARKSON_DISTORTION, NationalParkAct2_EventScript_GraveSealed
	checkitem ITEM_CATALPA_BOW
	goto_if_eq VAR_RESULT, FALSE, NationalParkAct2_EventScript_GraveNoBow
	msgbox NationalParkAct2_Text_GraveHasBow, MSGBOX_DEFAULT
	releaseall
	end

NationalParkAct2_EventScript_GraveNoBow::
	msgbox NationalParkAct2_Text_GraveNoBow, MSGBOX_DEFAULT
	releaseall
	end

NationalParkAct2_EventScript_GraveSealed::
	msgbox NationalParkAct2_Text_GraveSealed, MSGBOX_DEFAULT
	releaseall
	end

@ Entry point for USING the Catalpa Bow near the grave (src/item_use.c).
NationalParkAct2_EventScript_CatalpaBowCrossing::
	lockall
	goto_if_set FLAG_ACT2_MET_CLARKSON_DISTORTION, NationalParkAct2_EventScript_BowQuiet
	goto_if_set FLAG_ACT2_GRAVE_PORTAL_OPENED, NationalParkAct2_EventScript_BowCrossQuick
	msgbox NationalParkAct2_Text_GraveFirstCrossing, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ACT2_GRAVE_PORTAL_OPENED
	compare VAR_QUEST_FATHERS_WISH, 3
	goto_if_ne NationalParkAct2_EventScript_BowDoCross
	setvar VAR_QUEST_FATHERS_WISH, 100
	completequest QUEST_GRANDFATHERS_WISH
	closemessage
	goto NationalParkAct2_EventScript_BowDoCross

NationalParkAct2_EventScript_BowCrossQuick::
	msgbox NationalParkAct2_Text_GraveQuickCrossing, MSGBOX_DEFAULT
	closemessage
	goto NationalParkAct2_EventScript_BowDoCross

NationalParkAct2_EventScript_BowDoCross::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	@ Reality warps: the double flash shows the world mid-distortion before it
	@ dissolves for good (see field_specials.c).
	playse SE_M_SUPERSONIC
	special StartRiftDistortion
	delay 48
	playse SE_WARP_IN
	fadescreen FADE_TO_WHITE
	delay 16
	fadescreen FADE_FROM_WHITE
	delay 8
	fadescreen FADE_TO_WHITE
	delay 16
	special EndRiftDistortion
	warp MAP_DISTORTION_WORLD, 15, 24
	waitstate
	releaseall
	end

NationalParkAct2_EventScript_BowQuiet::
	msgbox NationalParkAct2_Text_BowQuiet, MSGBOX_DEFAULT
	releaseall
	end

@ --------------------------------------------------------------------------
@  Goons
@ --------------------------------------------------------------------------
@ These two are talk-initiated battles (TRAINER_TYPE_NONE in map.json), NOT
@ sight trainers: a sight trainer's script must START with trainerbattle
@ (oni_mask_disguise.inc header rule), which can't be mask-gated. The old
@ sight setup virtually re-ran the mask branch every step and re-approached
@ forever -- the playtest "infinite loop". Gating is on the mask being WORN,
@ not merely owned.
NationalParkAct2_EventScript_GoonEast::
	lock
	faceplayer
	goto_if_set FLAG_ONI_MASK_WORN, OniMask_EventScript_GoonMasked
	trainerbattle_single TRAINER_ACT2_PARK_GOON_EAST, NationalParkAct2_Text_GoonEastIntro, NationalParkAct2_Text_GoonEastDefeat
	msgbox NationalParkAct2_Text_GoonEastPostBattle, MSGBOX_AUTOCLOSE
	end

NationalParkAct2_EventScript_GoonWest::
	lock
	faceplayer
	goto_if_set FLAG_ONI_MASK_WORN, OniMask_EventScript_GoonMasked
	trainerbattle_single TRAINER_ACT2_PARK_GOON_WEST, NationalParkAct2_Text_GoonWestIntro, NationalParkAct2_Text_GoonWestDefeat
	msgbox NationalParkAct2_Text_GoonWestPostBattle, MSGBOX_AUTOCLOSE
	end

NationalParkAct2_EventScript_GraveWatcher::
	lock
	faceplayer
	msgbox NationalParkAct2_Text_GraveWatcher, MSGBOX_DEFAULT
	release
	end

@ --------------------------------------------------------------------------
@  Ghosts -- the park's dead are restless now
@ --------------------------------------------------------------------------
NationalParkAct2_EventScript_Misdreavus::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MISDREAVUS, CRY_MODE_NORMAL
	msgbox NationalParkAct2_Text_Misdreavus, MSGBOX_DEFAULT
	waitmoncry
	release
	end

NationalParkAct2_EventScript_Haunter::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HAUNTER, CRY_MODE_NORMAL
	msgbox NationalParkAct2_Text_Haunter, MSGBOX_DEFAULT
	waitmoncry
	release
	end

NationalParkAct2_EventScript_Duskull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUSKULL, CRY_MODE_NORMAL
	msgbox NationalParkAct2_Text_Duskull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ ============================================================================
@  Text
@ ============================================================================
NationalParkAct2_Text_BoatmanOffer::
	.string "{JPN}せんどうは なにも いわない。\p"
	.string "ただ ランタンを むこうぎしへ\n"
	.string "むけて まっている。\p"
	.string "トレードウィンドタウンへ もどる？$"

NationalParkAct2_Text_BoatmanStay::
	.string "{JPN}せんどうは かじに\n"
	.string "もたれなおした。\p"
	.string "こうえんの ほうは みない。\n"
	.string "いちども みたことが ない。$"

NationalParkAct2_Text_GraveHasBow::
	.string "{JPN}はかいしは いつものように\n"
	.string "とおくの さんちょうを むいている。\p"
	.string "いしの うえの くうきが ゆらいだ…\n"
	.string "こしの アズサユミが ひもを ひっぱるように\l"
	.string "ふるえている。 つかって\l"
	.string "ほしいのだ。$"

NationalParkAct2_Text_GraveSealed::
	.string "{JPN}はかいしは とおくの\n"
	.string "さんちょうを むいている。\p"
	.string "いしの うえの くうきは いまは\n"
	.string "しずかだ。 やすらかな しずけさだ。\p"
	.string "ここで ひらいていた ものは とじ\n"
	.string "あの にやにや わらいも つれていった。$"

NationalParkAct2_Text_BowQuiet::
	.string "{JPN}{ENG}{PLAYER}{JPN}は アズサユミを かかげた…\p"
	.string "ゆみづるは ふるえない。\n"
	.string "さかいめは もう とじたのだ。$"

NationalParkAct2_Text_GraveNoBow::
	.string "{JPN}はかいしは いつものように\n"
	.string "とおくの さんちょうを むいている。\p"
	.string "「のぼりて かえらぬ ものたちへ。\n"
	.string "やまは おぼえている」\p"
	.string "きりは つめたいのに いしの うえの\n"
	.string "くうきが ねつのように ゆらいでいる。\p"
	.string "ここには なにかが すこしだけ ひらいている…\n"
	.string "だが からっぽの てでは\l"
	.string "さかいめを みつけられない。$"

NationalParkAct2_Text_GraveFirstCrossing::
	.string "{JPN}いしの うえの くうきが ゆらいだ。\p"
	.string "こしの アズサユミが ふるえ… だれも\n"
	.string "ゆみづるに ふれていないのに\l"
	.string "ひくい おとを ひとつ ならした。\p"
	.string "ゆらぎが ひろがった。 きりが\n"
	.string "かぎあなから いきを すいこむように\l"
	.string "すいよせられていく。\p"
	.string "ここと むこうとの さかいめが\n"
	.string "めのまえで ひらいた。$"

NationalParkAct2_Text_QuestComplete::
	.string "{JPN}クエスト たっせい:\n"
	.string "ちちおやの さいごの ねがい！\p"
	.string "かぜの むこうの どこかで ろうじんの\n"
	.string "いきが ようやく おだやかに なった。$"

NationalParkAct2_Text_GraveQuickCrossing::
	.string "{JPN}ゆみが ひくい おとを ひとつ ならした。\n"
	.string "さかいめは あなたを おぼえている。$"

NationalParkAct2_Text_GoonEastIntro::
	.string "{JPN}ビーチは へいさ！ こうえんも\n"
	.string "へいさ！ ぜんぶ へいさだ！\p"
	.string "どうやって はいってきたんだ！？$"

NationalParkAct2_Text_GoonEastDefeat::
	.string "{JPN}ふねが… みずの ほうを\n"
	.string "だれも みはって なかった…$"

NationalParkAct2_Text_GoonEastPostBattle::
	.string "{JPN}いけよ。 きりの なかを さまよってろ。\n"
	.string "どうせ ここは しにびとの\l"
	.string "なわばりだ。$"

NationalParkAct2_Text_GoonWestIntro::
	.string "{JPN}ここから さきは たちいりきんし。\n"
	.string "マスターの めいれいは せいかくだ:\p"
	.string "みちは ぜんぶ ふさげ… はかを のぞいてな。\n"
	.string "おい… おまえ うちの\l"
	.string "ものじゃ ないな！$"

NationalParkAct2_Text_GoonWestDefeat::
	.string "{JPN}わかった！ わかったよ！ もんくは はかの\n"
	.string "むこうで まってる やつに いえ！$"

NationalParkAct2_Text_GoonWestPostBattle::
	.string "{JPN}なんで はかを あけたままに するのかって？\p"
	.string "マスターが いうには むこうがわの\n"
	.string "なにかが マスターに かりが あるんだとさ。$"

NationalParkAct2_Text_GraveWatcher::
	.string "{JPN}…あなたも かんじるのね。\p"
	.string "あの はかいしは ほかの ように きりを\n"
	.string "はきださない。 のみこんでいるの。\p"
	.string "マスターは はかを あけておけと いったわ。\n"
	.string "あの ひとの ために。\p"
	.string "どの あの ひと なのかは きかないけど。$"

NationalParkAct2_Text_Misdreavus::
	.string "{JPN}ムウマが はかの みちを まわりながら\n"
	.string "かなしげに ないている。\p"
	.string "まるで だれかの なまえの ようだ。$"

NationalParkAct2_Text_Haunter::
	.string "{JPN}ゴーストが きりの なかに うかび\n"
	.string "なにも ない ところへ にやにや わらっている。\p"
	.string "なにも わらいかえさない。 たぶん。$"

NationalParkAct2_Text_Duskull::
	.string "{JPN}ヨマワルが はかいしの あいだを\n"
	.string "しずかな よるの ランタンのように\l"
	.string "ゆっくりと ただよっている。\p"
	.string "みちを あけて おいているのだ。\n"
	.string "だれの ために？$"
