FuchsiaCity_House3_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House3_EventScript_MoveDeleter::
	lock
	faceplayer
	msgbox FuchsiaCity_House3_Text_WouldYouLikeToForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter::
	msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, FuchsiaCity_House3_EventScript_CancelForgetMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_House3_EventScript_CantForgetMoveEgg
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_House3_EventScript_CantForgetOnlyMove
	msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ForgetMove
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ForgetMove::
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely
	release
	end

FuchsiaCity_House3_EventScript_CantForgetOnlyMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonOnlyKnowsOneMove
	release
	end

FuchsiaCity_House3_EventScript_CantForgetMoveEgg::
	msgbox FuchsiaCity_House3_Text_NoEggShouldKnowMoves
	release
	end

FuchsiaCity_House3_EventScript_CancelForgetMove::
	msgbox FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves
	release
	end

FuchsiaCity_House3_Text_WouldYouLikeToForgetMove::
	.string "{JPN}えーと……\n"
	.string "そうそう わたしが わすれオヤジだ。\p"
	.string "ポケモンに わざを わすれさせる\n"
	.string "ことが できるんだ。\p"
	.string "わすれさせて みるかね?$"

FuchsiaCity_House3_Text_WhichMonShouldForgetMove::
	.string "{JPN}どの ポケモンに わざを\n"
	.string "わすれさせる?$"

FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten::
	.string "{JPN}どの わざを わすれさせる?$"

FuchsiaCity_House3_Text_MonOnlyKnowsOneMove::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}は わざを ひとつしか\n"
	.string "おぼえて いないようだ……$"

FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten::
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}の {ENG}{STR_VAR_2}{JPN}か?\n"
	.string "その わざを わすれさせるんだね?$"

FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely::
	.string "{JPN}かんぺきに うまくいった!\p"
	.string "{ENG}{STR_VAR_1}{JPN}は\n"
	.string "{ENG}{STR_VAR_2}{JPN}を すっかり わすれた!$"

FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves::
	.string "{JPN}ほかにも わすれさせたい わざが\n"
	.string "あったら また おいで。$"

FuchsiaCity_House3_Text_NoEggShouldKnowMoves::
	.string "{JPN}なに?\n"
	.string "タマゴは わざを おぼえて いないよ。$"

