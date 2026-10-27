SaffronCity_Dojo_Frlg_MapScripts::
	.byte 0

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleeBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONLEE, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONCHAN, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon::
	hidemonpic
	givemon VAR_TEMP_1, 25
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_EndGiveMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_EndGiveMon::
	release
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
	release
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	release
	end

SaffronCity_Dojo_Text_MasterKoichiIntro::
	.string "{JPN}おす!\p"
	.string "わしは カラテだいおう!\n"
	.string "ここの リーダー じゃ!\p"
	.string "わしらに いどむ つもりか?\n"
	.string "ようしゃは せんぞ!\p"
	.string "ちぇすとー!$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
	.string "{JPN}ハッ!\n"
	.string "ぐおお! まけた!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
	.string "{JPN}まさしく わしの まけじゃ!\p"
	.string "だが たのむ! どうじょうの かんばんだけは\n"
	.string "もっていかんで くれ!\p"
	.string "かわりに たいせつな かくとうタイプの\n"
	.string "ポケモンを ゆずろう!\p"
	.string "すきな ほうを えらぶが よい!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
	.string "{JPN}おす!\n"
	.string "わしらと カラテの しゅぎょうを していけ!$"

SaffronCity_Dojo_Text_MikeIntro::
	.string "{JPN}ぬおお!\n"
	.string "くつを ぬげ!$"

SaffronCity_Dojo_Text_MikeDefeat::
	.string "{JPN}まいった!$"

SaffronCity_Dojo_Text_MikePostBattle::
	.string "{JPN}しはんに あったら おどろくぞ!\n"
	.string "おれなんか しはんに くらべたら ザコだ!$"

SaffronCity_Dojo_Text_HidekiIntro::
	.string "{JPN}つよいらしいな!\n"
	.string "みせて もらおう!$"

SaffronCity_Dojo_Text_HidekiDefeat::
	.string "{JPN}しんぱん!\n"
	.string "いっぽん!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
	.string "{JPN}しはんは プロの かくとうか だ。\n"
	.string "まける かくごを しておけ!$"

SaffronCity_Dojo_Text_AaronIntro::
	.string "{JPN}ハイヤッ!\n"
	.string "てごわい あいてなど こわくない!\p"
	.string "まいにち しゅぎょうで\n"
	.string "いわを くだいて いるのだ!$"

SaffronCity_Dojo_Text_AaronDefeat::
	.string "{JPN}いてっ!\n"
	.string "つきゆびだ!$"

SaffronCity_Dojo_Text_AaronPostBattle::
	.string "{JPN}おれたちが おそれるのは\n"
	.string "エスパーの ちから だけだ!$"

SaffronCity_Dojo_Text_HitoshiIntro::
	.string "{JPN}ハアッ!\p"
	.string "かってに はいるな! ここは\n"
	.string "かくとう どうじょう だぞ!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
	.string "{JPN}ぐふっ!\n"
	.string "まいった!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
	.string "{JPN}ぜんこくの いちりゅうの かくとうかが\n"
	.string "ここで しゅぎょう しているのだ。$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
	.string "{JPN}キックの するどい\n"
	.string "サワムラーに するか?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
	.string "{JPN}{ENG}{PLAYER}{JPN}は {ENG}{STR_VAR_1}{JPN}を\n"
	.string "カラテだいおうから もらった!$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
	.string "{JPN}ピストン パンチの\n"
	.string "エビワラーに するか?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster2::
	.string "{JPN}{ENG}{PLAYER}{JPN}は カラテだいおうから\n"
	.string "{ENG}{STR_VAR_1}{JPN}を もらった!$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
	.string "{JPN}よくばりは いかんぞ…$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
	.string "{JPN}しちにんの てき あり!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
	.string "{JPN}いんがおうほう!$"

SaffronCity_Dojo_Text_FightingDojo::
	.string "{JPN}かくとう どうじょう$"

