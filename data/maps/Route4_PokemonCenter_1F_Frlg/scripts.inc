.equ MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE4
	end

Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Gentleman::
	lock
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
	release
	end

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_MAGIKARP, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
	showmoneybox 0, 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale
	goto_if_eq VAR_RESULT, FEMALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale::
	msgbox Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale::
	msgbox Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp::
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
	checkmoney MAGIKARP_PRICE
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
	textcolor NPC_TEXT_COLOR_NEUTRAL
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	call Common_EventScript_GetGiftMonPartySlot
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	lock
	faceplayer
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp::
	hidemoneybox
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
	setflag FLAG_BOUGHT_MAGIKARP
	release
	end

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
	removemoney MAGIKARP_PRICE
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds
	release
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Newspaper::
	lock
	msgbox Route4_PokemonCenter_1F_Text_ItsANewspaper
	release
	end

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
	.string "{JPN}よし ベルトに モンスターボールを\n"
	.string "6こ セットして……\p"
	.string "うん これで いい。 てもちに できる\n"
	.string "ポケモンは 6ぴきまで なんだ。$"

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
	.string "{JPN}ロケットだん ハナダの しみんを\n"
	.string "おそう……\p"
	.string "ロケットだんの ニュースが\n"
	.string "ない ひは ないな。$"

Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500::
	.string "{JPN}おとこ: やあ ぼうや!\n"
	.string "きみに とっておきの はなしが あるんだ!\p"
	.string "ひみつの ポケモン コイキングを\n"
	.string "たったの 500円で ゆずってあげよう!\p"
	.string "もちろん かうよね?$"

Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500::
	.string "{JPN}おとこ: やあ おじょうちゃん!\n"
	.string "きみに とっておきの はなしが あるんだ!\p"
	.string "ひみつの ポケモン コイキングを\n"
	.string "たったの 500円で ゆずってあげよう!\p"
	.string "もちろん かうよね?$"

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
	.string "{JPN}{ENG}{PLAYER}{JPN}は 500円も はらって\n"
	.string "コイキングを かった……$"

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
	.string "{JPN}いらない? いらないって? きみの ために\n"
	.string "いってあげてるのに!$"

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
	.string "{JPN}もう ポケモンを もてる よゆうが\n"
	.string "ないみたいだね。$"

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
	.string "{JPN}おかねが たりないよ!$"

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
	.string "{JPN}おとこ: へんぴんは うけつけないよ。\n"
	.string "わかってて かったんだろ!$"

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
	.string "{JPN}てもちの ポケモンが いっぱいで\n"
	.string "もう ふやせない ことも ある。\p"
	.string "そういう ときは パソコンで\n"
	.string "すこし あずけると いいよ。$"

Route4_PokemonCenter_1F_Text_ItsANewspaper::
	.string "{JPN}しんぶんだ。$"

