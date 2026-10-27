CeruleanCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 1
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
	.string "{JPN}あの マサキって やつ!\p"
	.string "めずらしい ポケモンの ためなら\n"
	.string "なんでも するらしいぜ。\p"
	.string "いろんな ことを へいきで\n"
	.string "やるって うわさだ。$"

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
	.string "{JPN}マサキの こと しってる?\p"
	.string "みんな かれを ポケモンマニアって よぶの!\p"
	.string "でも みんな マサキが\n"
	.string "うらやましい だけだと おもうな。\p"
	.string "じぶんの ポケモンを じまん したく\n"
	.string "ない ひとなんて いないでしょ?$"

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
	.string "{JPN}マサキは ポケモンを たくさん もってる!\n"
	.string "めずらしいのも あつめてるんだ!$"

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
	.string "{JPN}2かいへ いって ともだちと\n"
	.string "ポケモンを こうかん してみたら?\p"
	.string "こうかんで いろんな ポケモンが\n"
	.string "あつまるよ。\p"
	.string "こうかんで もらった ポケモンは\n"
	.string "そだつのも はやいんだ。$"

