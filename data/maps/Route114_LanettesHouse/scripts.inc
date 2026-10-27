Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "{JPN}マユミ: あっ! {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\p"
	.string "ちらかっていて ごめんなさい……\n"
	.string "けんきゅうに むちゅうに なると\l"
	.string "つい こう なっちゃうんです……\p"
	.string "はずかしいから ヒミツに してくださいね\n"
	.string "かわりに これ あげますから……$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "{JPN}わたしの ポケモン あずかりシステムの\n"
	.string "アドバイスを しても いいですか?\p"
	.string "どの ポケモンが はいってるか わかるように\n"
	.string "ボックスを せいり すると いいですよ$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "{JPN}マユミの けんきゅうノートだ\n"
	.string "ボックスに ついて かいてある\p"
	.string "ボックスは 1つに 30ぴき はいるように\p"
	.string "パソコンには トレーナー ひとりにつき\n"
	.string "420ぴき あずけられる ようにする\p"
	.string "つづきを よみますか?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "{JPN}ポケモンを マーキングできるようにして\n"
	.string "せいり しやすく する\p"
	.string "ボックスの なまえと かべがみを\n"
	.string "かえられる ようにして あずけられた\l"
	.string "ポケモンが よろこぶ ようにする\p"
	.string "つづきを よみますか?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "{JPN}ポケモンを あずけるときは\n"
	.string "さいごに みた ボックスに おくる\p"
	.string "その ボックスが いっぱいの ときは\n"
	.string "つぎの ボックスに おくる\p"
	.string "つまり ボックスを みると\n"
	.string "そこが ポケモンを おくる ボックスに\l"
	.string "じどうで えらばれる ようにする$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{JPN}{ENG}{PLAYER}{JPN}は ノートを とじた$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "{JPN}パソコンに だれかからの\n"
	.string "メールが とどいている\p"
	.string "「…… …… …… …… …… …… ……\p"
	.string "「きみの あずかりシステムは\n"
	.string "ぼくのより ずっと べんりや\p"
	.string "「つかいやすい きのうが いっぱいで\n"
	.string "たのしいし やくにも たつ\p"
	.string "「その かいはつに かかわれて\n"
	.string "ほこらしく おもうで\p"
	.string "「これからも あずかりシステムの\n"
	.string "けんきゅう つづけてな\p"
	.string "「マサキより\n"
	.string "…… …… …… …… …… …… …… ……」$"

