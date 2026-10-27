@ ============================================================================
@  CATALPA BOW -- GENGAR GHOST-ROADS (Act 2)
@  After the Distortion World scene, using the Catalpa Bow anywhere in the
@  field opens Gengar-Clarkson's travel menu from the very first use:
@  the Distortion World or Clarkson's Lab. The Lab road stays shut until the
@  player holds all four badges (EMBER/FLINT/LANTERN/DISTORTION).
@  There is deliberately NO direct
@  ride to Munen Village -- occupied Munen is only reached by walking out of
@  the lab, and the lab's exit gate holds until Draco is beaten and the
@  research choice is made.
@  Entry points are dispatched from ItemUseOutOfBattle_CatalpaBow
@  (src/item_use.c): Ferry when Gengar is in the party, NoGengar otherwise.
@ ============================================================================
EventScript_CatalpaBowGengarFerry::
	lockall
	waitse
	playmoncry SPECIES_GENGAR, CRY_MODE_NORMAL
	waitmoncry
	setspeaker SP_NAME_GENGAR
	msgbox Text_GengarTravelMenu, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_CATALPA_DESTINATIONS, FALSE
	switch VAR_RESULT
	case 0, EventScript_CatalpaBowToDistortion
	case 1, EventScript_CatalpaBowLabCheck
	@ CANCEL / B button
	goto EventScript_CatalpaBowFerryDecline

@ The lab road only opens once the player holds all four badges:
@ EMBER (01), FLINT (03), LANTERN, DISTORTION (05).
EventScript_CatalpaBowLabCheck::
	goto_if_unset FLAG_BADGE01_GET, EventScript_CatalpaBowLabLocked
	goto_if_unset FLAG_BADGE03_GET, EventScript_CatalpaBowLabLocked
	goto_if_unset FLAG_BADGE_LANTERN, EventScript_CatalpaBowLabLocked
	goto_if_unset FLAG_BADGE05_GET, EventScript_CatalpaBowLabLocked
	goto EventScript_CatalpaBowToLab

EventScript_CatalpaBowLabLocked::
	msgbox Text_GengarLabLocked, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CatalpaBowToLab::
	@ Crossing to occupied Munen commits the story (the road only runs one
	@ way), so warn before setting FLAG_ACT2_CROSSED_TO_MUNEN. Declining
	@ reuses the standard ferry-decline farewell.
	msgbox Text_GengarLabPointOfNoReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CatalpaBowFerryDecline
	setflag FLAG_ACT2_CROSSED_TO_MUNEN
	closemessage
	playse SE_WARP_IN
	fadescreen FADE_TO_BLACK
	delay 20
	@ Land one tile ABOVE the exit-gate trigger row (y=11): coord triggers only
	@ fire on stepping onto a tile, so arriving on the row itself would let the
	@ player slip out the door without the gate ever firing.
	warp MAP_MUNEN_LAB_ACT2, 6, 10
	waitstate
	releaseall
	end

EventScript_CatalpaBowToDistortion::
	closemessage
	@ Reality warps: mosaic pulse + camera wobble (field_specials.c) ramps in,
	@ the white fade dissolves the distorted world, and cleanup happens while
	@ the screen is blank.
	playse SE_M_SUPERSONIC
	special StartRiftDistortion
	delay 48
	playse SE_WARP_IN
	fadescreen FADE_TO_WHITE
	special EndRiftDistortion
	delay 20
	@ Ferry-era trips land in DistortionWorld_2 -- the reformed room where the
	@ island has risen across the x25 void (first arrival plays the reveal;
	@ see DistortionWorld_2/scripts.inc). The original MAP_DISTORTION_WORLD is
	@ only ever seen once, during the Gengar-Clarkson scene.
	warp MAP_DISTORTION_WORLD_2, 15, 24
	waitstate
	releaseall
	end

EventScript_CatalpaBowFerryDecline::
	msgbox Text_GengarFerryDecline, MSGBOX_DEFAULT
	releaseall
	end

@ Using the bow anywhere INSIDE the Distortion World (dispatched from
@ ItemUseOutOfBattle_CatalpaBow when the map section is
@ MAPSEC_DISTORTION_WORLD): the ghost-roads only lead OUT. Quick eject to
@ the gravesite -- no collapse cutscene, rift depth untouched, so the next
@ ferry trip resumes exactly where the player left off.
EventScript_CatalpaBowLeaveRift::
	lockall
	waitse
	playmoncry SPECIES_GENGAR, CRY_MODE_NORMAL
	waitmoncry
	setspeaker SP_NAME_GENGAR
	msgbox Text_GengarLeaveRift, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CatalpaBowStayInRift
	closemessage
	playse SE_M_SUPERSONIC
	special StartRiftDistortion
	delay 48
	playse SE_WARP_IN
	fadescreen FADE_TO_WHITE
	special EndRiftDistortion
	delay 20
	warp MAP_NATIONAL_PARK_ACT2, 47, 19
	waitstate
	releaseall
	end

EventScript_CatalpaBowStayInRift::
	msgbox Text_GengarStayInRift, MSGBOX_DEFAULT
	releaseall
	end

@ Scene done, but Gengar-Clarkson was left in the PC.
EventScript_CatalpaBowNoGengar::
	lockall
	msgbox Text_CatalpaBowNoGengar, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@  Text
@ ============================================================================
Text_GengarTravelMenu::
	.string "{JPN}ゲンガーが モンスターボールから\n"
	.string "けむりのように あふれでた。\p"
	.string "ゆうれいのみちは ひらいておるぞ\n"
	.string "{ENG}{PLAYER}{JPN}。 どこへ ゆく?$"

Text_GengarLabPointOfNoReturn::
	.string "{JPN}ひとつ いっておくぞ {ENG}{PLAYER}{JPN}。\p"
	.string "この ゆうれいのみちは かたみちじゃ。\n"
	.string "せんりょうされた ムネンへ\l"
	.string "わたったら もう もどれん。\p"
	.string "ここから さきは あともどり できんぞ。\n"
	.string "すすむか?$"

Text_GengarLabLocked::
	.string "{JPN}まだじゃ {ENG}{PLAYER}{JPN}。\p"
	.string "わしの けんきゅうじょへの みちは\n"
	.string "この ちほうが おまえに もとめる\l"
	.string "すべてを こえた さきに ある。\p"
	.string "エンバー。 フリント。 ランタン。\n"
	.string "ディストーション。\p"
	.string "4つの バッジを すべて もってこい。\n"
	.string "そうすれば ゆうれいのみちが はこんでくれる。$"

Text_GengarLeaveRift::
	.string "{JPN}ここでは みちが みょうに\n"
	.string "ねじれておる {ENG}{PLAYER}{JPN}。\p"
	.string "さけめの なかからでは みちは\n"
	.string "そとへしか つうじておらん。\p"
	.string "いきている ものの せかいへ\n"
	.string "はこんで やろうか?$"

Text_GengarStayInRift::
	.string "{JPN}ケケケ。 では あしもとに きをつけよ。$"

Text_GengarFerryDecline::
	.string "{JPN}ケケケ。 かしこいのう。 まずは\n"
	.string "ぜんぶ みがいておけ。\p"
	.string "ゆみは わしの いばしょを しっておる。\n"
	.string "じゅんびが できたら よぶがよい。\p"
	.string "ゲンガーは モンスターボールへ\n"
	.string "しみこむように もどっていった。$"

Text_CatalpaBowNoGengar::
	.string "{JPN}{ENG}{PLAYER}{JPN}は アズサユミを かかげた。\p"
	.string "つるが うなる… うなりつづける…\n"
	.string "だが なにも こたえない。\p"
	.string "よびだすべき ゆうれいは どこかの\n"
	.string "パソコンの ボックスに しまわれて\l"
	.string "すねているようだ。$"
