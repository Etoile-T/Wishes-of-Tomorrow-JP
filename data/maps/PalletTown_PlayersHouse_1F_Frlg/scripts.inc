PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
	.string "{JPN}ママ: ……そうね。\n"
	.string "おとこのこは いつか たびに でるものよ。\l"
	.string "テレビで そう いってたわ。\p"
	.string "そうそう となりの オーキドはかせが\n"
	.string "あなたを さがしてたわよ。$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
	.string "{JPN}ママ: ……そうね。\n"
	.string "おんなのこは みんな たびに あこがれるの。\l"
	.string "テレビで そう いってたわ。\p"
	.string "そうそう となりの オーキドはかせが\n"
	.string "あなたを さがしてたわよ。$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
	.string "{JPN}ママ: {ENG}{PLAYER}{JPN}!\n"
	.string "すこし やすんで いきなさい。$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
	.string "{JPN}ママ: あら よかった! あなたも\n"
	.string "ポケモンも げんき いっぱいね。\l"
	.string "きを つけて いってらっしゃい!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
	.string "{JPN}テレビで えいがを やっている。\n"
	.string "4にんの おとこのこが せんろを\l"
	.string "あるいている。\p"
	.string "……ぼくも いかなくちゃ。$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
	.string "{JPN}テレビで えいがを やっている。\n"
	.string "おさげがみの おんなのこが\l"
	.string "レンガの みちを あるいている。\p"
	.string "……わたしも いかなくちゃ。$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
	.string "{JPN}おっと うらがわだった……$"
