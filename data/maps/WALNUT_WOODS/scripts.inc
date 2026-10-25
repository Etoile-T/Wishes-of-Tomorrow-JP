WALNUT_WOODS_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, WALNUT_WOODS_OnLoad
	.byte 0

@ Restore already-collected items / already-cut bushes to snow on map load.
WALNUT_WOODS_OnLoad::
	call_if_set FLAG_ITEM_WALNUT_WOODS_TM_BLIZZARD, WALNUT_WOODS_EventScript_SetBlizzardSnow
	call_if_set FLAG_ITEM_WALNUT_WOODS_TM_PROTECT, WALNUT_WOODS_EventScript_SetProtectSnow
	call_if_set FLAG_WALNUT_WOODS_CUT_BUSH_1, WALNUT_WOODS_EventScript_SetBush1Snow
	call_if_set FLAG_WALNUT_WOODS_CUT_BUSH_2, WALNUT_WOODS_EventScript_SetBush2Snow
	call_if_set FLAG_ITEM_WALNUT_WOODS_HM06, WALNUT_WOODS_EventScript_SetHM06Snow
	end

@ setmetatile helpers. Coordinates re-read off the map after the 2026-09-13
@ repaint: the previous set was four ROWS stale (27,21 for a ball now at
@ 27,25), so every swap would have landed on the wrong tile. All five sit
@ on the same snow layer, 0x05E.
WALNUT_WOODS_EventScript_SetBlizzardSnow::
	setmetatile 27, 25, 0x05E, FALSE
	return

WALNUT_WOODS_EventScript_SetProtectSnow::
	setmetatile 18, 17, 0x05E, FALSE
	return

WALNUT_WOODS_EventScript_SetBush1Snow::
	setmetatile 20, 28, 0x05E, FALSE
	return

WALNUT_WOODS_EventScript_SetBush2Snow::
	setmetatile 43, 28, 0x05E, FALSE
	return

WALNUT_WOODS_EventScript_SetHM06Snow::
	setmetatile 45, 28, 0x05E, FALSE
	return

@ ===========================================================================
@ Professor Clarkson - pep talk, then runs off to the east (gone for good).
@ ===========================================================================
WALNUT_WOODS_EventScript_Clarkson::
	lock
	faceplayer
	setspeaker SP_NAME_CLARKSON
	showportrait PORTRAIT_CLARKSON_GENGAR
	msgbox WALNUT_WOODS_Text_Clarkson1, MSGBOX_DEFAULT
	closemessage
	delay 45
	setspeaker SP_NAME_CLARKSON
	msgbox WALNUT_WOODS_Text_Clarkson2, MSGBOX_DEFAULT
	closemessage
	hideportrait
	applymovement VAR_LAST_TALKED, WALNUT_WOODS_Movement_ClarksonRunOff
	waitmovement 0
	setflag FLAG_HIDE_WALNUT_CLARKSON
	removeobject VAR_LAST_TALKED
	release
	end

@ ===========================================================================
@ Porygon - opens the Pokemon Storage System (move/withdraw/deposit).
@ ===========================================================================
WALNUT_WOODS_EventScript_Porygon::
	lock
	faceplayer
	playse SE_PC_ON
	msgbox WALNUT_WOODS_Text_Porygon, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	special ShowPokemonStorageSystemPC
	release
	end

@ ===========================================================================
@ Chansey - full heal like a Pokemon Center, and sets the whiteout respawn.
@ ===========================================================================
WALNUT_WOODS_EventScript_Blissey::
	lock
	faceplayer
	msgbox WALNUT_WOODS_Text_ChanseyOffer, MSGBOX_DEFAULT
	closemessage
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	setrespawn HEAL_LOCATION_WALNUT_WOODS
	msgbox WALNUT_WOODS_Text_ChanseyDone, MSGBOX_DEFAULT
	release
	end

@ ===========================================================================
@ Item pickups - the pokeball is a TILE in the map; grabbing it turns the
@ tile into snow (no sprite object).
@ ===========================================================================
WALNUT_WOODS_EventScript_TMBlizzard::
	lockall
	goto_if_set FLAG_ITEM_WALNUT_WOODS_TM_BLIZZARD, WALNUT_WOODS_EventScript_NothingHere
	giveitem ITEM_TM_BLIZZARD
	setflag FLAG_ITEM_WALNUT_WOODS_TM_BLIZZARD
	call WALNUT_WOODS_EventScript_SetBlizzardSnow
	special DrawWholeMapView
	releaseall
	end

WALNUT_WOODS_EventScript_TMProtect::
	lockall
	goto_if_set FLAG_ITEM_WALNUT_WOODS_TM_PROTECT, WALNUT_WOODS_EventScript_NothingHere
	giveitem ITEM_TM_PROTECT
	setflag FLAG_ITEM_WALNUT_WOODS_TM_PROTECT
	call WALNUT_WOODS_EventScript_SetProtectSnow
	special DrawWholeMapView
	releaseall
	end

@ Was a red ITEM_BALL object sitting on top of the painted ball; now a tile
@ pickup like the two TMs.
WALNUT_WOODS_EventScript_HM06::
	lockall
	goto_if_set FLAG_ITEM_WALNUT_WOODS_HM06, WALNUT_WOODS_EventScript_NothingHere
	giveitem ITEM_HM06
	setflag FLAG_ITEM_WALNUT_WOODS_HM06
	call WALNUT_WOODS_EventScript_SetHM06Snow
	special DrawWholeMapView
	releaseall
	end

WALNUT_WOODS_EventScript_NothingHere::
	releaseall
	end

@ ===========================================================================
@ Cuttable bushes - the bush is a TILE in the map; cutting it turns the tile
@ into snow (no sprite object).
@ ===========================================================================
WALNUT_WOODS_EventScript_CutBush1::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, WALNUT_WOODS_EventScript_BushCantCut
	msgbox WALNUT_WOODS_Text_CutBush, MSGBOX_DEFAULT
	closemessage
	waitse
	playse SE_M_CUT
	delay 20
	setflag FLAG_WALNUT_WOODS_CUT_BUSH_1
	call WALNUT_WOODS_EventScript_SetBush1Snow
	special DrawWholeMapView
	releaseall
	end

WALNUT_WOODS_EventScript_CutBush2::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, WALNUT_WOODS_EventScript_BushCantCut
	msgbox WALNUT_WOODS_Text_CutBush, MSGBOX_DEFAULT
	closemessage
	waitse
	playse SE_M_CUT
	delay 20
	setflag FLAG_WALNUT_WOODS_CUT_BUSH_2
	call WALNUT_WOODS_EventScript_SetBush2Snow
	special DrawWholeMapView
	releaseall
	end

WALNUT_WOODS_EventScript_BushCantCut::
	msgbox WALNUT_WOODS_Text_BushCantCut, MSGBOX_DEFAULT
	releaseall
	end

@ ===========================================================================
@ Signs
@ ===========================================================================
WALNUT_WOODS_EventScript_SignWest::
	msgbox WALNUT_WOODS_Text_SignWest, MSGBOX_SIGN
	end

WALNUT_WOODS_EventScript_SignEast::
	msgbox WALNUT_WOODS_Text_SignEast, MSGBOX_SIGN
	end

@ ===========================================================================
@ Movement
@ ===========================================================================
@ Down one, THEN east. He starts at (30,25) and row 25 is walled at x=31, 33,
@ 34 and 35 -- running straight east put him through the pots and the trees,
@ because applymovement never collision-checks. Row 26 is clear from x=28 to
@ x=43, so the single step down is what makes the exit legal.
@ Ten steps east reaches x=40; the screen's right edge sits around x=37 with
@ the player where they'd be standing, so he is gone before removeobject.
WALNUT_WOODS_Movement_ClarksonRunOff:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

@ ===========================================================================
@ Text
@ ===========================================================================
WALNUT_WOODS_Text_Clarkson1:
	.string "{JPN}こんな ところで\n"
	.string "しゅぎょうしているとは かんしん かんしん！\p"
	.string "むかしは よく この のはらで\n"
	.string "むすこと バトルしたものだ…\p"
	.string "あいつが よからぬ なかまと\n"
	.string "つきあう ように なる まえはな。\p"
	.string "そうだな… おまえは あいつに にている。$"

WALNUT_WOODS_Text_Clarkson2:
	.string "{JPN}…\p"
	.string "むかしの ことを くよくよ しても はじまらん！\p"
	.string "きを つけてな {ENG}{PLAYER}{JPN}！$"

WALNUT_WOODS_Text_Porygon:
	.string "{JPN}ポリゴンが ブーンと うなって\n"
	.string "ポケモン あずかりシステムを たちあげた。$"

WALNUT_WOODS_Text_ChanseyOffer:
	.string "{JPN}ラッキー: ハピナス！\p"
	.string "つかれた ポケモンの てあてを\n"
	.string "してくれるようだ。$"

WALNUT_WOODS_Text_ChanseyDone:
	.string "{JPN}ハピ ハピナス！\p"
	.string "ポケモンたちは すっかり\n"
	.string "げんきに なった！$"

WALNUT_WOODS_Text_CutBush:
	.string "{JPN}ゆきの つもった しげみが\n"
	.string "みちを ふさいでいる。\p"
	.string "{ENG}{PLAYER}{JPN}は いあいぎりを つかった！$"

WALNUT_WOODS_Text_BushCantCut:
	.string "{JPN}ゆきの つもった ぶあつい しげみだ。\p"
	.string "ちょうどいい わざなら\n"
	.string "きりたおせそうだ。$"

WALNUT_WOODS_Text_SignWest:
	.string "{JPN}クルミのもり\n"
	.string "{RIGHT_ARROW} フロストウッドタウン$"

WALNUT_WOODS_Text_SignEast:
	.string "{JPN}フロストウッドタウン {RIGHT_ARROW} クルミのもり\n"
	.string "{RIGHT_ARROW} メルティングマイル$"
