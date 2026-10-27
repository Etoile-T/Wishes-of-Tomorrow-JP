PokemonMansion_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_2F_OnLoad
	.byte 0

PokemonMansion_2F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_2F
	end

PokemonMansion_2F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 1
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_1F_Text_ChristenedDiscoveredMonMew, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_BURGLAR_ARNIE, PokemonMansion_1F_Text_ArnieIntro, PokemonMansion_1F_Text_ArnieDefeat
	msgbox PokemonMansion_1F_Text_ArniePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_Text_PressSecretSwitch::
	.string "{JPN}ひみつの スイッチだ!\p"
	.string "おしますか?$"

PokemonMansion_Text_WhoWouldnt::
	.string "{JPN}おすに きまってる!$"

PokemonMansion_Text_NotQuiteYet::
	.string "{JPN}まだ やめておこう!$"

PokemonMansion_1F_Text_ArnieIntro::
	.string "{JPN}でられない!\n"
	.string "この ふるい やしきは まるで パズルだ。$"

PokemonMansion_1F_Text_ArnieDefeat::
	.string "{JPN}しまった!\n"
	.string "おたからの ふくろが!$"

PokemonMansion_1F_Text_ArniePostBattle::
	.string "{JPN}ここの スイッチは ドアを\n"
	.string "こうごに あけたり しめたり するんだ。$"

PokemonMansion_1F_Text_NewMonDiscoveredInGuyanaJungle::
	.string "{JPN}にっし 7がつ 5か\n"
	.string "みなみアメリカ ギアナ\p"
	.string "ジャングルの おくちで あたらしい\n"
	.string "ポケモンが はっけん された。$"

PokemonMansion_1F_Text_ChristenedDiscoveredMonMew::
	.string "{JPN}にっし 7がつ 10か\n"
	.string "あたらしく はっけん された ポケモンを\l"
	.string "ミュウと めいめい した。$"

