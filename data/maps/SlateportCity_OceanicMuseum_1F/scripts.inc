SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "{JPN}うみの かがく はくぶつかんへ ようこそ。\p"
	.string "にゅうかんりょうは 50円です。\n"
	.string "にゅうかん なさいますか?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "{JPN}ごゆっくり どうぞ!$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "{JPN}あら? もうしわけ ありませんが\n"
	.string "おかねが たりないようです。$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "{JPN}あら? さきほど はいった\n"
	.string "だんたいの おなかまですか?\p"
	.string "おくれたのは あなただけですよ。\n"
	.string "はやく おいついたほうが いいですよ!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "{JPN}みんなの ために\n"
	.string "われわれ アクアだんは そんざいする!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "{JPN}ここに あつまれと いわれて\n"
	.string "やってきたのは いいけど…\p"
	.string "かんじんの ボスが いないんだ。$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "{JPN}ここに おいてある もの\n"
	.string "かっぱらうと もうかるかな?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "{JPN}ここで まなんだことは\n"
	.string "わるだくみに やくだてられるな…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "{JPN}なかまが カナズミで ドジらなければ\n"
	.string "ここに こなくて すんだのによ!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "{JPN}50円が なくて\n"
	.string "うけつけで すごい じかん かかったよ……$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "{JPN}うみのことを べんきょうして\n"
	.string "しょうぶに やくだてたいんだ。$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "{JPN}うみを みると わくわくして\n"
	.string "うっとり しちゃうんだ!\p"
	.string "クスノキかんちょうこそ\n"
	.string "いちばんの あこがれの ひとだよ!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "{JPN}うみは はてしなく ひろく\n"
	.string "どこまでも ふかい……\p"
	.string "われわれが しらない ポケモンが\n"
	.string "きっと たくさん いるはずだ。$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "{JPN}うみの ポケモンが ほしいな。\p"
	.string "だきしめたら ひんやりして\n"
	.string "きもちが よさそうだもの。$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "{JPN}ひえええっ!\n"
	.string "おまえ こんなところで なにしてるんだ?\p"
	.string "おれだよ! アクアだんの いちいんだ!\n"
	.string "まえに おまえに やられたんだよ!\l"
	.string "カナシダトンネルで! おぼえてるだろ?\p"
	.string "ほら これを うけとってくれ!\n"
	.string "おねがいだから ゆるしてくれよ!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "{JPN}その わざマシンは おれより\n"
	.string "おまえの ほうが にあってるよ。\p"
	.string "もう にどと あいたくないぜ!\n"
	.string "わははは!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "{JPN}たのむよ!\n"
	.string "これを うけとって おれを みのがしてくれ!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "{JPN}ガラスの うつわの なかで\n"
	.string "あおい えきたいが うずを まいている。\p"
	.string "「これは かぜを つかって じんこうてきに\n"
	.string "うずしおを おこす じっけんです。」$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "{JPN}ガラスの うつわの なかで\n"
	.string "あかい ボールが うきしずみ している。\p"
	.string "「これは ボールの ふりょくを つかって\n"
	.string "たきを さいげんする じっけんです。」$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "{JPN}うみの そこから とってきた\n"
	.string "つちの みほんだ。\p"
	.string "「ながい としつきを かけて\n"
	.string "いきものの なきがらが うみの そこに たまり\l"
	.string "いくつもの ちそうを つくります。\p"
	.string "この ちそうを ぶんせきすると\n"
	.string "おおむかしの ようすが わかります。」$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "{JPN}うみべの すなの みほんだ!\p"
	.string "「やまの いしは かわに ながされ\n"
	.string "かわを くだる あいだに\l"
	.string "くだかれたり けずれたり していきます。\p"
	.string "ちいさな つぶに なった いしは\n"
	.string "やがて うみべの すなと なるのです。」$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "{JPN}「うみの まめちしき その1\n"
	.string "なぜ うみの みずは あおいの?\p"
	.string "ひかりは たくさんの いろで できています。\p"
	.string "ひかりが みずを とおると\n"
	.string "ほとんどの ひかりは いろを うしないます。\p"
	.string "しかし あおい ひかりは いろを たもつので\n"
	.string "うみは あおく みえるのです。」$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "{JPN}「うみの まめちしき その2\n"
	.string "なぜ うみは しょっぱいの?\p"
	.string "かいすいには ナトリウムイオンと\n"
	.string "えんそイオンの かたちで しおが とけています。\p"
	.string "これらの イオンは いわから しみだし\n"
	.string "あめに はこばれて うみへ やってきます。\p"
	.string "この とけた しおの こさが\n"
	.string "うみを しょっぱく しているのです。」$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "{JPN}「うみの まめちしき その3\n"
	.string " うみと りくは どちらが ひろいの?」\p"
	.string "「うみは ちきゅうの やく70パーセントを\n"
	.string "おおい のこりは りくちです。\p"
	.string "つまり うみは りくちの 2ばいよりも\n"
	.string "さらに ひろいのです。」$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "{JPN}なみのような でこぼこの ある かせきだ。\p"
	.string "「うみの そこの つちは\n"
	.string "しおの ながれで けずられます。\p"
	.string "かいすいの ながれが つちに\n"
	.string "ちいさな やまや たにを きざみます。\p"
	.string "この つちが かせきに なったものを\n"
	.string "リップルマークと よびます。」$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "{JPN}ガラスの ドームの なかで\n"
	.string "ふしぎな きかいが まわっている。\p"
	.string "なにかの ふかさを\n"
	.string "はかるための ものだろうか…$"

