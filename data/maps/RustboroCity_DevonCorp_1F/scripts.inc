RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "{JPN}いらっしゃいませ!\n"
	.string "デボン コーポレーション です!\p"
	.string "みなさまの せいかつに やくだつ\n"
	.string "どうぐや くすりを おつくりしてます!$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "{JPN}ドジな けんきゅういんが\n"
	.string "だいじな にもつを とられちゃって……$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "{JPN}おっ その ランニングシューズ!\n"
	.string "うちの せいひん ですよ!\p"
	.string "じぶんたちが つくった ものを\n"
	.string "つかって もらえると うれしいなあ$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "{JPN}ぬすまれた にもつ……\p"
	.string "たしかに だいじな ものだけど\n"
	.string "だれにでも つかえる ものじゃ ないのよ\p"
	.string "わたしの みたてでは あの どろぼう\n"
	.string "あんまり かしこく ないわね$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "{JPN}どうやら ぬすまれた\n"
	.string "デボンの にもつが もどってきた らしいね$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "{JPN}もうしわけ ありません かんけいしゃ\n"
	.string "いがいの かたは はいれません$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "{JPN}ドジにも ほどが ある!\n"
	.string "どうして ぬすまれたり するんだ?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "{JPN}やあ!\n"
	.string "きみなら いつでも だいかんげい だよ!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "{JPN}いしや きんぞくの サンプルが\n"
	.string "ガラスケースの なかに ならんでいる\p"
	.string "パネルに なにか かいてある……\n"
	.string "よんでみよう……\p"
	.string "「デボン コーポレーションは もともと\n"
	.string "やまから いしを きりだす かいしゃでした\p"
	.string "「また すなの なかの さてつから\n"
	.string "てつも つくっていました\p"
	.string "「ざいりょうを つくる ちいさな かいしゃ\n"
	.string "から デボンは はってん しました\p"
	.string "「いまでは デボンは はばひろい\n"
	.string "こうぎょう せいひんを つくっています」$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "{JPN}しさくひんや テストせいひんが\n"
	.string "ガラスケースに ぎっしり ならんでいる\p"
	.string "せつめいの パネルが ある……\p"
	.string "「こうぎょう せいひんの ほかにも\n"
	.string "デボンは くらしを ゆたかにする\l"
	.string "ざっかや いやくひんを はんばい しています\p"
	.string "「さいきんでは モンスターボールや\n"
	.string "ポケナビなど ポケモントレーナー\l"
	.string "むけの どうぐも はんばい しています」$"

