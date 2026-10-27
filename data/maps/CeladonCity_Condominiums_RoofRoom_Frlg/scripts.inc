CeladonCity_Condominiums_RoofRoom_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_RoofRoom_EventScript_BlackBelt::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow, MSGBOX_NPC
	end

CeladonCity_Condominiums_RoofRoom_EventScript_EeveeBall::
	lock
	faceplayer
	setvar VAR_TEMP_1, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 25
	goto_if_eq VAR_RESULT, 0, CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty
	goto_if_eq VAR_RESULT, 1, CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveeParty::
	removeobject LOCALID_EEVEE_POKEBALL
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	end

CeladonCity_Condominiums_RoofRoom_EventScript_GetEeveePC::
	removeobject LOCALID_EEVEE_POKEBALL
	playfanfare MUS_LEVEL_UP
	message CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC
	end

CeladonCity_Condominiums_RoofRoom_EventScript_TransferEeveeToPC::
	call Common_EventScript_TransferredToPC
	goto CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee
	end

CeladonCity_Condominiums_RoofRoom_EventScript_SetGotEevee::
	setflag FLAG_GOT_EEVEE
	release
	end

CeladonCity_Condominiums_RoofRoom_EventScript_TMsPamphlet::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs, MSGBOX_SIGN
	end

CeladonCity_Condominiums_RoofRoom_EventScript_Blackboard::
	lockall
	msgbox CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture
	message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
	waitmessage
	setvar VAR_0x8004, 4
	multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
	case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
	case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
	case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	end

CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading::
	message CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading
	waitmessage
	multichoice 0, 0, MULTI_LINKED_DIRECT_UNION, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub
	case 1, CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner
	case 2, CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom
	case 3, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	case 127, CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard
	end

CeladonCity_Condominiums_RoofRoom_EventScript_WirelessClub::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_DirectCorner::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_UnionRoom::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom
	goto CeladonCity_Condominiums_RoofRoom_EventScript_ReadAnotherHeading
	end

CeladonCity_Condominiums_RoofRoom_EventScript_ExitBlackboard::
	releaseall
	end

CeladonCity_Condominiums_RoofRoom_Text_TheresNothingIDontKnow::
	.string "{JPN}こくばんに かいたとおり わしに\n"
	.string "しらないことは なにも ない!\p"
	.string "きみの ゲームボーイアドバンスの\n"
	.string "ポケモンの せかいも しっておる!\p"
	.string "ともだちと あつまって\n"
	.string "ポケモンこうかんを たのしもう!$"

CeladonCity_Condominiums_RoofRoom_Text_ObtainedAnEevee::
	.string "{JPN}{ENG}{PLAYER}{JPN}は イーブイを もらった!$"

CeladonCity_Condominiums_RoofRoom_Text_BoxIsFull::
	.string "{JPN}ポケモンが いっぱいだ\n"
	.string "ボックスを かえて きなさい$"

CeladonCity_Condominiums_RoofRoom_Text_WirelessAdapterLecture::
	.string "{JPN}ポケモン こうざ\p"
	.string "ワイヤレスアダプタで あそぼう$"

CeladonCity_Condominiums_RoofRoom_Text_ReadWhichHeading::
	.string "{JPN}どの こうもくを よみますか?$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainWirelessClub::
	.string "{JPN}ポケモン ワイヤレスクラブは\n"
	.string "どの ポケモンセンターでも 2かい。\p"
	.string "ワイヤレスアダプタを つかって\n"
	.string "ともだちと つうしん しよう。$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainDirectCorner::
	.string "{JPN}ともだちとだけ つうしん するなら\n"
	.string "ダイレクトコーナーへ。\p"
	.string "ポケモン ワイヤレスクラブの\n"
	.string "みぎがわの カウンターです。\p"
	.string "ともだちと いっしょに トレード\n"
	.string "コーナーか コロシアムに はいろう。$"

CeladonCity_Condominiums_RoofRoom_Text_ExplainUnionRoom::
	.string "{JPN}だれとでも つうしんして はなすなら\n"
	.string "ユニオンルームへ。\p"
	.string "ポケモン ワイヤレスクラブの\n"
	.string "ひだりがわの カウンターです。\p"
	.string "ユニオンルームで ほかの トレーナー\n"
	.string "との であいを たのしもう。$"

CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs::
	.string "{JPN}わざマシンの パンフレットだ。\p"
	.string "… …\p"
	.string "わざマシンは ぜんぶで 50しゅるい。\p"
	.string "ほかに なんどでも つかえる\n"
	.string "ひでんマシンが 7しゅるい ある。\p"
	.string "シルフカンパニー$"

