FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES @ Specifically supposed to teach level up moves
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "{JPN}わしは わざおしえマニアじゃ。\p"
	.string "ポケモンが おぼえる わざは\n"
	.string "ひとつ のこらず しっておるし\l"
	.string "ポケモンに おしえることも できる。\p"
	.string "のぞむなら おまえさんの ポケモンに\n"
	.string "わざを おしえて やろう。\p"
	.string "おれいは ハートのウロコ ひとつじゃ。\n"
	.string "いま あつめて おるのでな。$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "{JPN}おお! それじゃ! まぎれもない\n"
	.string "ほんものの ハートのウロコじゃ!\p"
	.string "あててみようか わざを おしえて\n"
	.string "ほしいんじゃな?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "{JPN}どの ポケモンに おしえるんじゃ?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "{JPN}どの わざを おしえるかの?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "{JPN}すまんのう……\p"
	.string "その ポケモンに おしえられる わざは\n"
	.string "ひとつも ないようじゃ。$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{JPN}{ENG}{PLAYER}{JPN}は おれいに\n"
	.string "ハートのウロコを 1まい わたした!$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "{JPN}ポケモンに わざを おぼえさせたく なったら\n"
	.string "ハートのウロコを もって きなされ。$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "{JPN}なんじゃ? タマゴに おしえられる\n"
	.string "わざなど ひとつも ないぞ。$"

