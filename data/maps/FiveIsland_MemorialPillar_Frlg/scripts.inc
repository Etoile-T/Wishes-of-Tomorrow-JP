FiveIsland_MemorialPillar_Frlg_MapScripts::
	.byte 0

FiveIsland_MemorialPillar_EventScript_MemorialMan::
	lock
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_ReturnedForTM42
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrub
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_FacePlayer
	waitmovement 0
	delay 45
	msgbox FiveIsland_MemorialPillar_Text_YourMonsLookHealthy
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix
	release
	end

FiveIsland_MemorialPillar_EventScript_AlreadyGotTM42::
	msgbox FiveIsland_MemorialPillar_Text_ScrubScrubTectonix
	release
	end

FiveIsland_MemorialPillar_EventScript_ReturnedForTM42::
	msgbox FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	release
	end

FiveIsland_MemorialPillar_EventScript_Memorial::
	lockall
	goto_if_set FLAG_GOT_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	goto_if_set FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR, FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering
	checkitem ITEM_LEMONADE
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_AskPlaceLemonade::
	msgbox FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FiveIsland_MemorialPillar_EventScript_PlaceLemonade
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_PlaceLemonade::
	removeitem ITEM_LEMONADE
	msgbox FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade
	closemessage
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 45
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis
	giveitem ITEM_TM42
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_MemorialPillar_EventScript_NoRoomForTM42
	call FiveIsland_MemorialPillar_EventScript_ReceivedTM42
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_ReceivedTM42::
	msgbox FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo
	applymovement LOCALID_MEMORIAL_MAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_GOT_TM42_AT_MEMORIAL_PILLAR
	return

FiveIsland_MemorialPillar_EventScript_NoRoomForTM42::
	setflag FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR
	msgbox FiveIsland_MemorialPillar_Text_DontHaveRoomForIt
	releaseall
	end

FiveIsland_MemorialPillar_EventScript_MemorialLemonadeAlreadyPlaced::
	msgbox FiveIsland_MemorialPillar_Text_HereLiesTectonix
	releaseall
	end

FiveIsland_MemorialPillar_Text_MiloIntro::
	.string "{JPN}ぼくは とり きょうだいの\n"
	.string "ちょうなん!\p"
	.string "とりの いちばんの みりょく…\n"
	.string "それは くちばしだ!$"

FiveIsland_MemorialPillar_Text_MiloDefeat::
	.string "{JPN}うわ するどい!$"

FiveIsland_MemorialPillar_Text_MiloPostBattle::
	.string "{JPN}ここから 4のしまへ\n"
	.string "そらを とんで いけるよ。$"

FiveIsland_MemorialPillar_Text_ChazIntro::
	.string "{JPN}ぼくは とり きょうだいの\n"
	.string "まんなか!\p"
	.string "とりの いちばんの みりょく…\n"
	.string "それは つばさだ!$"

FiveIsland_MemorialPillar_Text_ChazDefeat::
	.string "{JPN}パタパタ!$"

FiveIsland_MemorialPillar_Text_ChazPostBattle::
	.string "{JPN}あっちに すごく しずんだ かおの\n"
	.string "ひとが いたよ。$"

FiveIsland_MemorialPillar_Text_HaroldIntro::
	.string "{JPN}ぼくは とり きょうだいの\n"
	.string "すえっこ!\p"
	.string "とりの いちばんの みりょく…\n"
	.string "それは うもうだ!$"

FiveIsland_MemorialPillar_Text_HaroldDefeat::
	.string "{JPN}うもうって ふかふか…\n"
	.string "ねむく なっちゃう…$"

FiveIsland_MemorialPillar_Text_HaroldPostBattle::
	.string "{JPN}とりポケモンが あまえて くると\n"
	.string "しあわせな きもちに なるんだ…$"

FiveIsland_MemorialPillar_Text_ScrubScrub::
	.string "{JPN}ゴシゴシ…$"

FiveIsland_MemorialPillar_Text_YourMonsLookHealthy::
	.string "{JPN}こんにちは…\n"
	.string "あなたの ポケモン げんきそうですね…$"

FiveIsland_MemorialPillar_Text_ThisIsWhereIBuriedMyOnix::
	.string "{JPN}ここに わたしの イワークを うめたんです…\n"
	.string "テクトニクスと いう なまえでした…$"

FiveIsland_MemorialPillar_Text_HereLiesTectonixLemonadeOffering::
	.string "{JPN}いわに「テクトニクス ここに ねむる」と\n"
	.string "きざまれている。\p"
	.string "はかの まえには ミックスオレが\n"
	.string "そなえられている。$"

FiveIsland_MemorialPillar_Text_LeaveAnotherLemonadeOffering::
	.string "{JPN}ミックスオレを もうひとつ\n"
	.string "そなえますか?$"

FiveIsland_MemorialPillar_Text_PlacedCanOfLemonade::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ミックスオレを\n"
	.string "はかの まえに そなえた。$"

FiveIsland_MemorialPillar_Text_ThankYouPleaseTakeThis::
	.string "{JPN}あ ありがとう…\p"
	.string "それは テクトニクスの だいすきな\n"
	.string "のみもの でした…\p"
	.string "みしらぬ かたなのに あなたの\n"
	.string "やさしい おこないに…\p"
	.string "すこし げんきが でました。\p"
	.string "おれいに これを うけとって\n"
	.string "くれませんか?$"

FiveIsland_MemorialPillar_Text_BeGoodToYourMonsToo::
	.string "{JPN}あなたも ポケモンを\n"
	.string "たいせつに してあげてください。$"

FiveIsland_MemorialPillar_Text_DontHaveRoomForIt::
	.string "{JPN}もちきれないなら\n"
	.string "つぎまで あずかって おきますね。$"

FiveIsland_MemorialPillar_Text_StillHaveThingAsMyThanks::
	.string "{JPN}ああ あのときの…\p"
	.string "おれいに あげたかった ものを\n"
	.string "まだ もっていますよ。$"

FiveIsland_MemorialPillar_Text_ScrubScrubTectonix::
	.string "{JPN}ゴシゴシ…\p"
	.string "… … …\n"
	.string "テクトニクス…$"

FiveIsland_MemorialPillar_Text_HereLiesTectonix::
	.string "{JPN}いわや いしが きれいに\n"
	.string "つみあげられて いる。\p"
	.string "いわに「テクトニクス ここに ねむる」と\n"
	.string "きざまれている。$"

