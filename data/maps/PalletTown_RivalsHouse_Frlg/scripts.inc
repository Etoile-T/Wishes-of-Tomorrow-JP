.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap::
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
	.string "{JPN}ナナミ: あら {ENG}{PLAYER}{JPN}!\p"
	.string "おとうとの {ENG}{RIVAL}{JPN}なら\n"
	.string "おじいちゃんの けんきゅうじょよ。$"

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
	.string "{JPN}ナナミ: {ENG}{PLAYER}{JPN} あなた\n"
	.string "{ENG}{RIVAL}{JPN}と バトル したんですって?\p"
	.string "わたしも みたかったわ!$"

PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp::
	.string "{JPN}おじいちゃんに おつかいを\n"
	.string "たのまれたの?\p"
	.string "まあ ものぐさ なんだから。\n"
	.string "はい これが あると べんりよ。$"

PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ナナミから\n"
	.string "タウンマップを もらった。$"

PalletTown_RivalsHouse_Text_DontHaveSpaceForThis::
	.string "{JPN}バッグに これを いれる\n"
	.string "すきまが ないわね。$"

PalletTown_RivalsHouse_Text_ExplainTownMap::
	.string "{JPN}タウンマップを つかえば いまいる\n"
	.string "ばしょを しらべたり ちめいを\l"
	.string "たしかめたり できるのよ。$"

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
	.string "{JPN}ナナミ: ポケモンも ひとと おなじ\n"
	.string "いきもの なのよ。\p"
	.string "つかれたら やすませて\n"
	.string "あげてね。$"

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
	.string "{JPN}カントーちほうの おおきな ちずだ。\n"
	.string "これは べんりそう!$"

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
	.string "{JPN}ほんだなには ポケモンの ほんが\n"
	.string "ぎっしり つまっている。$"

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
	.string "{JPN}ナナミ: あら {ENG}{PLAYER}{JPN}!\n"
	.string "ちょうど よかった。\p"
	.string "いま おちゃに するところなの。\n"
	.string "いっしょに どう?\p"
	.string "あら でも みて。\n"
	.string "あなたの ポケモン ちょっと よごれてるわ。\p"
	.string "けづくろい してあげましょうか?$"

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
	.string "{JPN}けづくろいは いらないの?\n"
	.string "じゃあ おちゃだけ にしましょ。$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
	.string "{JPN}どの こを けづくろい する?$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
	.string "{JPN}ナナミ: じゃあ すぐに\n"
	.string "きれいに してあげるわね。$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
#ifdef BUGFIX @ The localizers missed what should be a textcolor change in the localizations.
	.string "{JPN}{COLOR DARK_GRAY}{ENG}{STR_VAR_1}{JPN}は うっとり している……\p"
	.string "{COLOR RED}ナナミ: はい できあがり!\n"
#else @ In the JP games, gender-based text used a different font instead of different colors.
	.string "{JPN}{FONT_NORMAL}{ENG}{STR_VAR_1}{JPN}は うっとり している……\p"
	.string "{FONT_FEMALE}ナナミ: はい できあがり!\n"
#endif
	.string "{JPN}ほら きれいに なったでしょ?\p"
	.string "うふふ……\n"
	.string "ほんとに かわいい ポケモンね。$"

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
	.string "{JPN}あら ごめんなさい。 タマゴは\n"
	.string "さすがに けづくろい できないわ。$"

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
	.string "{JPN}ナナミ: あいじょうを こめて そだてれば\n"
	.string "ポケモンも あなたを すきに なるわ。\p"
	.string "たとえば {ENG}{PLAYER}{JPN} あなたの\n"
	.string "さいしょの ポケモンを みせて?$"

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
	.string "{JPN}これいじょう ないくらい\n"
	.string "あなたに なついてるわ。\p"
	.string "あなたの ポケモン ことばに\n"
	.string "できないくらい しあわせそう。$"

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
	.string "{JPN}とても しあわせそうね。\p"
	.string "{ENG}{RIVAL}{JPN}にも これを みて\n"
	.string "すこしは みならって ほしいわ。$"

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
	.string "{JPN}あなたに とても なついてるわ。\n"
	.string "これからも だいじに してね!$"

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
	.string "{JPN}あなたに なついて きてるわね。\n"
	.string "しんらいが そだってるのね。$"

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
	.string "{JPN}まだ あなたに あまり\n"
	.string "なれて いないみたい。\p"
	.string "ポケモンは みんな さいしょは\n"
	.string "けいかい してるものなのよ。$"

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
	.string "{JPN}{ENG}{PLAYER}{JPN} その こ あなたを\n"
	.string "にらんでる みたいで いやだわ。\p"
	.string "もうすこし やさしく してあげて\n"
	.string "くれない?$"

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
	.string "{JPN}……あの とても いいにくいん\n"
	.string "だけど……\p"
	.string "あなたの ポケモンが そんなに あなたを\n"
	.string "きらう りゆうでも あるの?$"

PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy::
	.string "{JPN}「かわいくて やさしい\n"
	.string "ピッピ」$"

