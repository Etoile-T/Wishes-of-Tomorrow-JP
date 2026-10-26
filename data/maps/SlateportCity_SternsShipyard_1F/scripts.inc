SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "{JPN}ええと… これが ここで\n"
	.string "あれが むこうだと すると…\p"
	.string "この ぶひんは どこだっけ?\n"
	.string "あの よくわからない やつは?\p"
	.string "ああっ! なにが なんだか\n"
	.string "さっぱり わからないよ!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "{JPN}ん?\n"
	.string "やあ ツガだよ。\p"
	.string "クスノキかんちょうに たのまれて\n"
	.string "れんらくせんの せっけいを しているんだ。\p"
	.string "おや! それは…\n"
	.string "デボンのにもつ じゃないか?\p"
	.string "でも うーん…\n"
	.string "こまったなあ…\p"
	.string "クスノキかんちょうは どこかへ でかけたよ。\n"
	.string "しごとが あるって いってね。\p"
	.string "クスノキかんちょうを さがして\n"
	.string "それを とどけて くれないか?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "{JPN}ツガ: クスノキかんちょう\n"
	.string "どこに いっちゃったのかな?\p"
	.string "わるいけど きみ クスノキかんちょう\n"
	.string "さがして にもつを わたしてあげてよ!$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "{JPN}ツガ: ふねづくりは げいじゅつだよ。\p"
	.string "けいさん するだけでは わからないことが\n"
	.string "たくさん あるんだ。\p"
	.string "うみを よく しる ベテランに\n"
	.string "じょげんを もらえたらなあ…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "{JPN}ツガ: やあ! ハギろうじんが\n"
	.string "てつだいに くわわって くれたんだ。\p"
	.string "ベテランの ふなのりの おかげで\n"
	.string "れんらくせんは ちゃくちゃくと できているよ。$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "{JPN}ツガ: ついに ふねは かんせいしたよ!\p"
	.string "あたらしい タイドリップごうは\n"
	.string "まさに ぎじゅつの けっしょうだ!\p"
	.string "だけど もっと いいものが できそうな……\n"
	.string "そんな きも するんだよ\p"
	.string "そう……\n"
	.string "ぎじゅつの しんぽに おわりは ないのさ!$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "{JPN}ハギ: おお! {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "ひさしぶり じゃのう!\p"
	.string "きみに であってから この おいぼれも\n"
	.string "ふなのりとして げんきが わいてきてのう!\p"
	.string "ツガくんの れんらくせん づくりを\n"
	.string "てつだうことに したんじゃ!\p"
	.string "れんらくせんが できると おおくの\n"
	.string "ひとを はこべるように なるからのう\p"
	.string "しかし…… ふむう……\n"
	.string "ツガくんは すごいのう……\p"
	.string "かれの ぎじゅつと わしの けいけんを\n"
	.string "あわせれば きっと わしらは\l"
	.string "すばらしい ふねを つくれるはずじゃ!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "{JPN}きせつ てんき そらに みえる\n"
	.string "つきの いち…\p"
	.string "そうした いろいろな じょうけんで\n"
	.string "うみは ひょうじょうを かえるんだ。\p"
	.string "そうさ!\n"
	.string "うみは いきものの ようなものだ!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "{JPN}すぐに ふなよい してしまうから\n"
	.string "かわりに ここで てつだっているんだ。$"

