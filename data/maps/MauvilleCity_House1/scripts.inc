MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "{JPN}うっほー!\p"
	.string "いわくだきの やつって よばれるんだが\n"
	.string "それじゃ ちょっと みくだされてるよな。\p"
	.string "もうすこし うやまわれても いいと おもう。\n"
	.string "いわくだきの アニキ とかさ。\p"
	.string "うっほー!\p"
	.string "それは そうと きみの ポケモン\n"
	.string "なかなか つよそうだね。\p"
	.string "きにいった!\n"
	.string "ほら この ひでんマシンを あげよう!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "{JPN}それは ひでんマシン「いわくだき」!\p"
	.string "きみの いくてを ふさぐ\n"
	.string "じゃまな おおいわが あっても\p"
	.string "その ひでんを つかうことで\n"
	.string "くだいて しまえるのだ!\p"
	.string "そうとも! いわなんて くだいてしまえ!\n"
	.string "うっほー!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "{JPN}そうそう いわを くだくと かくれていた\n"
	.string "ポケモンが とびだすことが あるよ。\p"
	.string "うっほー!$"

