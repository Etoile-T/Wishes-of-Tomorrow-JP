PewterCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PewterCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_Jigglypuff::
	lock
	faceplayer
	fadeoutbgm 0
	playbgm MUS_RG_JIGGLYPUFF, 0
	message PewterCity_PokemonCenter_1F_Text_Jigglypuff
	waitmessage
	delay 455
	playbgm MUS_POKE_CENTER, 1
	release
	end

PewterCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid1::
	lock
	msgbox PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu
	release
	end

PewterCity_PokemonCenter_1F_EventScript_GBAKid2::
	msgbox PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid, MSGBOX_NPC
	end

PewterCity_PokemonCenter_1F_Text_TeamRocketMtMoonImOnPhone::
	.string "{JPN}なんだと!?\p"
	.string "ロケットだんが おつきみやまに?\n"
	.string "ん?\p"
	.string "でんわちゅう なんだ!\n"
	.string "あっち いけ!$"

PewterCity_PokemonCenter_1F_Text_Jigglypuff::
	.string "{JPN}プリン: ぷうぷぷう!$"

PewterCity_PokemonCenter_1F_Text_WhenJiggylypuffSingsMonsGetDrowsy::
	.string "{JPN}ふわぁ…!\p"
	.string "プリンが うたうと ポケモンは\n"
	.string "ねむく なる…\p"
	.string "…わたしも…\n"
	.string "ぐうぐう…$"

PewterCity_PokemonCenter_1F_Text_TradingMyClefairyForPikachu::
	.string "{JPN}どうしても ピカチュウが ほしいから\n"
	.string "ピッピと こうかん するんだ。$"

PewterCity_PokemonCenter_1F_Text_TradingPikachuWithKid::
	.string "{JPN}あそこの こと ポケモンを\n"
	.string "こうかん するんだ。\p"
	.string "ピカチュウが 2ひき いたから\n"
	.string "1ぴき こうかん しようと おもって。$"

