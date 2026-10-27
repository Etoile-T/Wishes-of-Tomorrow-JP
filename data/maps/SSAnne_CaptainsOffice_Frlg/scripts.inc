SSAnne_CaptainsOffice_Frlg_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_GOT_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	call EventScript_RestorePrevTextColor
	delay 50
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	giveitem_msg SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain, ITEM_HM01, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_GOT_HM01
	setvar VAR_MAP_SCENE_VERMILION_CITY, 1
	release
	end

@ Unused
SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_SS_ANNE_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
	.string "{JPN}せんちょう: うおぇ…\n"
	.string "き きもちわるい…\l"
	.string "うっぷ! ふなよいが…$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
	.string "{JPN}{ENG}{PLAYER}{JPN}は せんちょうの\n"
	.string "せなかを さすった!\p"
	.string "さすり さすり…\n"
	.string "さすり さすり…$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
	.string "{JPN}せんちょう: ふう! ありがとう!\n"
	.string "だいぶ らくに なったよ。\p"
	.string "わしの ひでんの いあいぎりを\n"
	.string "みたい だって?\p"
	.string "こんなに ぐあいが わるくなければ\n"
	.string "じまんの いあいぎりを みせるのだが…\p"
	.string "そうだ! これを あげよう!\n"
	.string "この ひでんマシンだ!\p"
	.string "ポケモンに いあいぎりを おぼえさせれば\n"
	.string "いつでも いあいぎりが みられるぞ!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
	.string "{JPN}{ENG}{PLAYER}{JPN}は せんちょうから\n"
	.string "ひでんマシン01を もらった!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
	.string "{JPN}いあいぎりを つかえば ほそい きを\n"
	.string "きりたおせる。\p"
	.string "クチバシティの まわりの きで\n"
	.string "ためして みては どうかな?$"

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
	.string "{JPN}せんちょう: …ふう!\p"
	.string "ふなよいも なおった ことだし\n"
	.string "そろそろ じかんだな。\p"
	.string "サント・アンヌごうは まもなく しゅっこうだ!\p"
	.string "また クチバシティに もどる ひまで\n"
	.string "さらばだ!$"

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
	.string "{JPN}おや!\n"
	.string "もちものが いっぱいだね!$"

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
	.string "{JPN}うえっ!\n"
	.string "みなきゃ よかった!$"

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
	.string "{JPN}『ふなよいを こくふく するには』…\n"
	.string "せんちょうが よんでる ほんだ!$"

