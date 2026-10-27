MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "{JPN}この おくりびやま には\n"
	.string "いろんな ものが さまよっておる……\p"
	.string "なにが おきるか わからん\n"
	.string "ねんのため これを もっていきなされ$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "{JPN}その きよめのおふだを\n"
	.string "ポケモンに もたせなされ\p"
	.string "やせいの ポケモンを よせつけにくく なるぞ$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "{JPN}なくなった ポケモンたちの たましいに\n"
	.string "おまいりに きたのですか?\p"
	.string "ポケモンを とても たいせつに しているのね$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "{JPN}ここには たいせつに していた\n"
	.string "ジグザグマが やすらかに ねむってる……$"

