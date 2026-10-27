DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "{JPN}これを よーく みてくれよ!\p"
	.string "シルクのスカーフ だぜ! いま\n"
	.string "さいせんたんの ファッション なんだ!\p"
	.string "おっ きみの め かがやいてるね!\n"
	.string "おれの まぶしい センスが わかるんだ!\p"
	.string "いやあ うれしいね!\n"
	.string "ほら きみに これを あげるよ!$"

DewfordTown_House2_Text_NoRoom:
	.string "{JPN}おや もう もてないのか?\p"
	.string "いいかい この スカーフは ぜったい\n"
	.string "ひつようだ! おれなら どうぐを ぜんぶ\l"
	.string "うってでも てに いれるね!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "{JPN}シルクのスカーフは ノーマルタイプの\n"
	.string "わざの いりょくを あげてくれる!\p"
	.string "ほとんどの ポケモンに にあう\n"
	.string "すてきな スカーフ ってことだぜ!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "{JPN}へえ! きみ うみを こえて\n"
	.string "わざわざ ムロまで きたの!\p"
	.string "もしかして トウキさんの うわさを\n"
	.string "きいて きたんじゃない?\p"
	.string "トウキさん かっこよくて……\n"
	.string "みんなが あこがれてるんだ$"

