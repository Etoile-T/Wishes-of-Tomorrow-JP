PrototypeIsland_MapScripts::
	.byte 0

@ ============================================================================
@  PROTOTYPE ISLAND (WoT_Act3_Canon.md archipelago table): the half-sunk
@  remains of Mutrid's FIRST laboratory -- before Munen, before the tower.
@  A lone hermit tells the lore and warns against going below; the flooded
@  lab (MAP_PROTOTYPE_LAB) waits underneath with the failed "perfect form"
@  prototype. Surf-hop wiring: Celebi Island west edge <-> here (east edge).
@  All dialogue PLACEHOLDER (Joe).
@ ============================================================================

PrototypeIsland_EventScript_Hermit::
	lock
	faceplayer
	msgbox PrototypeIsland_Text_Hermit1, MSGBOX_DEFAULT
	msgbox PrototypeIsland_Text_Hermit2, MSGBOX_DEFAULT
	msgbox PrototypeIsland_Text_Hermit3, MSGBOX_DEFAULT
	release
	end

@ The dark doorway down into the flooded lab.
PrototypeIsland_EventScript_EnterLab::
	lockall
	msgbox PrototypeIsland_Text_Doorway, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	warp MAP_PROTOTYPE_LAB, 13, 3
	waitstate
	releaseall
	end

@ The archipelago chain, north to south:
@   Ryuden Island <-> Route 130 <-> PROTOTYPE ISLAND <-> Celebi Island
@ (and Celebi Island <-> Route 129 <-> Shin-Tokyo below that).
@ NOTE: the old south trigger row sat at y=28 on a 28-tall map -- out of
@ bounds, so surfing south did nothing. It lives on y=27 now.
PrototypeIsland_EventScript_SurfToCelebi::
	lockall
	warp MAP_CELEBI_ISLAND, 25, 1
	waitstate
	releaseall
	end

PrototypeIsland_EventScript_SurfToRoute130::
	lockall
	@ the open channel; (42,31) fell outside the water after Route 130 was
	@ repainted, which put the player off the map
	warp MAP_ROUTE130, 54, 12
	waitstate
	releaseall
	end

@ --- Text (all PLACEHOLDER (Joe)) -------------------------------------------
PrototypeIsland_Text_Hermit1::
	.string "{JPN}ほう? きゃくか。 しおも\n"
	.string "きまえが よかったと みえる。\p"
	.string "おぬしが たっているのは さいしょの\n"
	.string "けんきゅうじょの やねじゃよ。\p"
	.string "ムネンよりも タワーよりも まえ。\n"
	.string "ミュートリッドは ここで はじまった。$"

PrototypeIsland_Text_Hermit2::
	.string "{JPN}やつらは 「かんぜんな すがた」を もとめた。\p"
	.string "いちから つくりあげた ポケモン…\n"
	.string "ふうじる たましいも なければ\l"
	.string "やつらに さからうものも ない。\p"
	.string "あの したで めざめたものは\n"
	.string "かんぜんでは なかった。\p"
	.string "まちがっておったのじゃ。$"

PrototypeIsland_Text_Hermit3::
	.string "{JPN}やつらは ひとばんで たてあなを みずで みたし\n"
	.string "にげだした。\p"
	.string "したへ いくでない。 ほんきじゃぞ。\p"
	.string "みずでは あれは しななかった。$"

PrototypeIsland_Text_Doorway::
	.string "{JPN}かいだんが くろい みずの なかへ\n"
	.string "つづいている。\p"
	.string "はるか したで なにかが\n"
	.string "あふれる みずに あらがうように うなっている。$"
