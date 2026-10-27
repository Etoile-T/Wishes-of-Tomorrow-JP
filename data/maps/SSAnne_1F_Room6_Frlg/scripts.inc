SSAnne_1F_Room6_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHeal::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHealMale::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
	release
	end

SSAnne_1F_Room6_Text_TakeAShortRest::
	.string "{JPN}つかれてる みたいね。\n"
	.string "すこし やすんで いく?$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
	.string "{JPN}みんな すっかり げんきに なって\n"
	.string "よかったわ。$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother::
	.string "{JPN}あら おせっかい やいて ごめんね。\n"
	.string "おとうとに にてる ものだから…$"

SSAnne_1F_Room6_Text_SorryYouLookLikeMySister::
	.string "{JPN}あら おせっかい やいて ごめんね。\n"
	.string "いもうとに にてる ものだから…$"

