AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "{JPN}なんだ なんだ? アクアだんに\n"
	.string "なんの ようだ?\p"
	.string "リーダーは いないぞ! だいじな ものを\n"
	.string "うばいに でかけたんだ!\p"
	.string "…… ……\n"
	.string "どこへ いったかって?\p"
	.string "ワハハ! そんな だいじなこと\n"
	.string "おしえると おもうか?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "{JPN}なんだ なんだ?\n"
	.string "おまえ マグマだんの したっぱか?\p"
	.string "マグマだんは アジトで すごい\n"
	.string "ポケモンを めざめさせようと\l"
	.string "してるらしいな\p"
	.string "でも やつらの アジトって どこだ?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "{JPN}なんだ なんだ? アクアだんに\n"
	.string "なんの ようだ?\p"
	.string "リーダーは いないぞ!\n"
	.string "せんすいかんを うばいに いったんだ!\p"
	.string "…… ……\n"
	.string "どこへ いったかって?\p"
	.string "ワハハ! そんな だいじなこと\n"
	.string "おしえると おもうか?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "{JPN}なんだ なんだ? アクアだんに\n"
	.string "なんの ようだ?\p"
	.string "リーダーは いないぞ! 122ばん どうろの\n"
	.string "おくりびやまへ むかってるんだ!\p"
	.string "…… ……\n"
	.string "なにしに いったかって?\p"
	.string "ワハハ! そんな だいじなこと\n"
	.string "おしえると おもうか?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "{JPN}なんだ なんだ?\n"
	.string "おまえ マグマだんの したっぱか?\p"
	.string "マグマだんは えんとつやまで\n"
	.string "すごい ポケモンを ねらってるらしい\p"
	.string "でも それって どんな ポケモンだ?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "{JPN}なんだ なんだ? アクアだんに\n"
	.string "なんの ようだ?\p"
	.string "リーダーは いないぞ!\n"
	.string "カイナシティへ むかってるんだ!\p"
	.string "…… ……\n"
	.string "なにしに いったかって?\p"
	.string "ワハハ! そんな だいじなこと\n"
	.string "おしえると おもうか?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "{JPN}ややや!\n"
	.string "あやしい じんぶつを はっけーん!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "{JPN}ぐぬぬぬ……\n"
	.string "まけちまった!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "{JPN}チームの ために まけたが\n"
	.string "おれは やくめを はたしたのだ……$"

