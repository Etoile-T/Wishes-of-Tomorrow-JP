LilycoveCity_DepartmentStore_4F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_4F_EventScript_Gentleman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs:
	.2byte ITEM_TM_FIRE_BLAST
	.2byte ITEM_TM_THUNDER
	.2byte ITEM_TM_BLIZZARD
	.2byte ITEM_TM_HYPER_BEAM
	.2byte ITEM_AM_GUTS
	.2byte ITEM_AM_TECHNICIAN
	.2byte ITEM_AM_MOXIE
	.2byte ITEM_AM_ADAPTABILITY
	.2byte ITEM_AM_SHEER_FORCE
	.2byte ITEM_AM_TOUGH_CLAWS
	.2byte ITEM_AM_IRON_FIST
	.2byte ITEM_AM_TINTED_LENS
	.2byte ITEM_AM_SKILL_LINK
	.2byte ITEM_AM_PRANKSTER
	.2byte ITEM_AM_SPEED_BOOST
	pokemartlistend

LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs:
	.2byte ITEM_TM_PROTECT
	.2byte ITEM_TM_SAFEGUARD
	.2byte ITEM_TM_REFLECT
	.2byte ITEM_TM_LIGHT_SCREEN
	.2byte ITEM_AM_INTIMIDATE
	.2byte ITEM_AM_THICK_FAT
	.2byte ITEM_AM_STURDY
	.2byte ITEM_AM_LEVITATE
	.2byte ITEM_AM_UNAWARE
	.2byte ITEM_AM_SERENE_GRACE
	.2byte ITEM_AM_POISON_HEAL
	.2byte ITEM_AM_MULTISCALE
	.2byte ITEM_AM_MAGIC_GUARD
	.2byte ITEM_AM_REGENERATOR
	.2byte ITEM_AM_MAGIC_BOUNCE
	pokemartlistend

LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM:
	.string "{JPN}うーん…\p"
	.string "こうげきの わざか…\n"
	.string "それとも まもりの わざか…\p"
	.string "ポケモンに どの わざマシンの わざを\n"
	.string "おぼえさせるか きめるのは むずかしい…$"

LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs:
	.string "{JPN}わざマシンの わざって\n"
	.string "いろいろ あるのね。\p"
	.string "カタログで よんだんだけど\n"
	.string "50しゅるいも あるんですって。$"

LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves:
	.string "{JPN}わざマシンを ぜんぶ そろえたいけど\n"
	.string "ポケモンが おぼえる わざは 4つだけ。$"

@ Wishes of Tomorrow: a shopper explains the new ABILITY MACHINE discs.
LilycoveCity_DepartmentStore_4F_EventScript_AMExplainer::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStore_4F_Text_AMExplainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_4F_Text_AMExplainer:
	.string "{JPN}あの AMの ディスクを みたかい?\n"
	.string "てんいんは とくせいマシンと よんでる。\p"
	.string "ポケモンに つかうと その とくせいが\n"
	.string "ディスクに はいっている とくせいに\l"
	.string "かきかえられるんだ。\p"
	.string "ずっと そのままだよ。うまれつきの\n"
	.string "とくせいには もどせないんだ。\p"
	.string "あう ポケモンを えらんで つかえば\n"
	.string "まるで べつの ポケモンに なるよ。$"

