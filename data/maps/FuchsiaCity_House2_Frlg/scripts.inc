FuchsiaCity_House2_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
	.string "{JPN}わたしは つりめいじんの\n"
	.string "あにだ。\p"
	.string "とにかく つりが だーいすき!\n"
	.string "つりなしでは いられないのだ。\p"
	.string "ところで きみは つりが すきかね?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
	.string "{JPN}すばらしい! きにいったぞ。\n"
	.string "わたしたち いい ともに なれそうだ。\p"
	.string "これで つりを したまえ わかき ともよ!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
	.string "{JPN}{ENG}{PLAYER}{JPN}は つりめいじんの あにから\n"
	.string "いいつりざおを もらった!$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
	.string "{JPN}つりこそ じんせい!\n"
	.string "さいこうの しの ような ものだ。\p"
	.string "ボロのつりざおでは コイキングしか\n"
	.string "つれなかった だろう?\p"
	.string "だが いいつりざおなら\n"
	.string "もっと いい ポケモンが つれるぞ。$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
	.string "{JPN}そうか……\n"
	.string "ざんねん だなあ……$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
	.string "{JPN}やあ {ENG}{PLAYER}{JPN}!\p"
	.string "つりの ちょうしは どうだね?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
	.string "{JPN}おや まあ!\p"
	.string "プレゼントが あったんだが\n"
	.string "にもつが いっぱい じゃないか!$"

