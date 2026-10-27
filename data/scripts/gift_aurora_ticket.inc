MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございます。\p"
	.string "{ENG}{PLAYER}{JPN}さま ですね。\n"
	.string "チケットが とどいて おります。$"

sText_AuroraTicketUseAtPort:
	.string "{JPN}どうやら ミナモシティの\n"
	.string "みなとで つかう もののようです。\p"
	.string "どんな ものか ためしに\n"
	.string "いってみては いかがですか?$"

sText_AuroraTicketThankYou:
	.string "{JPN}ふしぎな おくりものを ごりよう\n"
	.string "いただき ありがとう ございました。$"

sText_AuroraTicketBagFull:
	.string "{JPN}もうしわけ ありません {ENG}{PLAYER}{JPN}さま。\n"
	.string "バッグの たいせつなものポケットが いっぱいです。\p"
	.string "なにかを パソコンに あずけてから\n"
	.string "また おこしください。$"
