PokemonTower_3F_Frlg_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
	.string "{JPN}うう… あわわ…\n"
	.string "ふふ… ぐおお…$"

PokemonTower_3F_Text_HopeDefeat::
	.string "{JPN}はっ!\n"
	.string "たすかった!$"

PokemonTower_3F_Text_HopePostBattle::
	.string "{JPN}ゆうれいの しょうたいは\n"
	.string "シルフスコープで みやぶれる。$"

PokemonTower_3F_Text_CarlyIntro::
	.string "{JPN}ケケケ…\n"
	.string "キエーッ!$"

PokemonTower_3F_Text_CarlyDefeat::
	.string "{JPN}ん?\n"
	.string "わたし なにを してるの?$"

PokemonTower_3F_Text_CarlyPostBattle::
	.string "{JPN}ごめんなさい!\n"
	.string "とりつかれて いたの!$"

PokemonTower_3F_Text_PatriciaIntro::
	.string "{JPN}たちされ!\n"
	.string "あくりょうよ!$"

PokemonTower_3F_Text_PatriciaDefeat::
	.string "{JPN}ふう!\n"
	.string "れいが はなれた!$"

PokemonTower_3F_Text_PatriciaPostBattle::
	.string "{JPN}うえに いる ほかの ひとたち…\n"
	.string "きっと とりつかれて いるのね。$"

