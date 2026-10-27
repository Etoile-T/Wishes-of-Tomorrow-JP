AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "{JPN}わたしは クスノキかんちょうに たのまれて\n"
	.string "この ふねを しらべているんだ。\p"
	.string "たんちきも さがしてくれと\n"
	.string "いわれたけど みつからなくて……$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "{JPN}おっ! それは たんちきだね!\p"
	.string "ねえ それを クスノキかんちょうに\n"
	.string "とどけて もらえないかな?\p"
	.string "わたしは もうすこし この ふねを\n"
	.string "しらべたいんだ。$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "{JPN}この ふねは カクタスごうと いってね\n"
	.string "ちょいと むかしの ふね らしいんだ$"

