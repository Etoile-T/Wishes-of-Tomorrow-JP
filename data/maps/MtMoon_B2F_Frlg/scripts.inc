MtMoon_B2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	call_if_unset FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_ShowFossils
	end

MtMoon_B2F_EventScript_ShowFossils::
	clearflag FLAG_HIDE_DOME_FOSSIL
	clearflag FLAG_HIDE_HELIX_FOSSIL
	return

MtMoon_B2F_EventScript_MiguelTrigger::
	lockall
	applymovement LOCALID_MIGUEL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call MtMoon_B2F_EventScript_BattleMiguel
	releaseall
	end

MtMoon_B2F_EventScript_Miguel::
	lock
	faceplayer
	goto_if_set FLAG_GOT_FOSSIL_FROM_MT_MOON, MtMoon_B2F_EventScript_MiguelFossilPicked
	goto_if_defeated TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_EventScript_MiguelGoPickFossil
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

MtMoon_B2F_EventScript_BattleMiguel::
	textcolor NPC_TEXT_COLOR_MALE
	message MtMoon_B2F_Text_MiguelIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setvar VAR_LAST_TALKED, LOCALID_MIGUEL
	trainerbattle_no_intro TRAINER_SUPER_NERD_MIGUEL, MtMoon_B2F_Text_MiguelDefeat
	setvar VAR_MAP_SCENE_MT_MOON_B2F, 1
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	return

MtMoon_B2F_EventScript_MiguelFossilPicked::
	msgbox MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils
	release
	end

MtMoon_B2F_EventScript_MiguelGoPickFossil::
	msgbox MtMoon_B2F_Text_WellEachTakeAFossil
	release
	end

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_DOME_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedDomeFossil, ITEM_DOME_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToHelixFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_MIGUEL
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_HELIX_FOSSIL
	setflag FLAG_GOT_DOME_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_Movement_MiguelToHelixFossil::
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	removeobject LOCALID_HELIX_FOSSIL
	giveitem_msg MtMoon_B2F_Text_ObtainedHelixFossil, ITEM_HELIX_FOSSIL, 1, MUS_RG_OBTAIN_KEY_ITEM
	closemessage
	delay 10
	applymovement LOCALID_MIGUEL, MtMoon_B2F_Movement_MiguelToDomeFossil
	waitmovement 0
	copyobjectxytoperm LOCALID_MIGUEL
	textcolor NPC_TEXT_COLOR_MALE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message MtMoon_B2F_Text_ThenThisFossilIsMine
	waitmessage
	waitfanfare
	removeobject LOCALID_DOME_FOSSIL
	setflag FLAG_GOT_HELIX_FOSSIL
	setflag FLAG_GOT_FOSSIL_FROM_MT_MOON
	release
	end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_Movement_MiguelToDomeFossil::
	walk_up
	walk_up
	walk_up
	step_end

MtMoon_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT, MtMoon_B2F_Text_Grunt1Intro, MtMoon_B2F_Text_Grunt1Defeat
	msgbox MtMoon_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_2, MtMoon_B2F_Text_Grunt2Intro, MtMoon_B2F_Text_Grunt2Defeat
	msgbox MtMoon_B2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_3, MtMoon_B2F_Text_Grunt3Intro, MtMoon_B2F_Text_Grunt3Defeat
	msgbox MtMoon_B2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_4, MtMoon_B2F_Text_Grunt4Intro, MtMoon_B2F_Text_Grunt4Defeat
	msgbox MtMoon_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtMoon_B2F_Text_MiguelIntro::
	.string "{JPN}おい まて!\p"
	.string "この かせきは おれが みつけたんだ!\n"
	.string "ふたつとも おれの もんだ!$"

MtMoon_B2F_Text_MiguelDefeat::
	.string "{JPN}わかった!\n"
	.string "わけて やるよ!$"

MtMoon_B2F_Text_WellEachTakeAFossil::
	.string "{JPN}かせきは ひとり ひとつずつだ!\n"
	.string "よくばるなよ!$"

MtMoon_B2F_Text_ThenThisFossilIsMine::
	.string "{JPN}わかった。\n"
	.string "じゃあ こっちの かせきは おれのだ!$"

MtMoon_B2F_Text_LabOnCinnabarRegeneratesFossils::
	.string "{JPN}ずっと とおくの グレンじまに\n"
	.string "ポケモン けんきゅうじょが あるんだ。\p"
	.string "そこでは かせきを よみがえらせる\n"
	.string "けんきゅうを してるんだよ。$"

MtMoon_B2F_Text_Grunt1Intro::
	.string "{JPN}われら ロケットだんが\n"
	.string "かせきを いただく!\p"
	.string "かせきから ポケモンを よみがえらせて\n"
	.string "おおもうけ するのだ!$"

MtMoon_B2F_Text_Grunt1Defeat::
	.string "{JPN}ぐっ!\n"
	.string "あたまに きたぞ!$"

MtMoon_B2F_Text_Grunt1PostBattle::
	.string "{JPN}よくも おこらせたな!\n"
	.string "ロケットだんの ブラックリスト いりだ!$"

MtMoon_B2F_Text_Grunt2Intro::
	.string "{JPN}われら ロケットだんは\n"
	.string "ポケモン ギャングだ!\l"
	.string "ちからで きょうふを あたえるのだ!$"

MtMoon_B2F_Text_Grunt2Defeat::
	.string "{JPN}しくじった!$"

MtMoon_B2F_Text_Grunt2PostBattle::
	.string "{JPN}ちくしょう!\n"
	.string "なかまが だまって ないぞ!$"

MtMoon_B2F_Text_Grunt3Intro::
	.string "{JPN}ここで でかい しごとを してるんだ!\n"
	.string "きえな ガキ!$"

MtMoon_B2F_Text_Grunt3Defeat::
	.string "{JPN}なるほど つよいな……$"

MtMoon_B2F_Text_Grunt3PostBattle::
	.string "{JPN}かせきを みつけたら おれに よこして\n"
	.string "とっとと きえな!$"

MtMoon_B2F_Text_Grunt4Intro::
	.string "{JPN}ちいさい ガキが おとなの じゃまを\n"
	.string "するもんじゃ ないぜ!\p"
	.string "ろくな ことに ならないぞ!$"

MtMoon_B2F_Text_Grunt4Defeat::
	.string "{JPN}はらが たつ!$"

MtMoon_B2F_Text_Grunt4PostBattle::
	.string "{JPN}ひとが くる ずっと まえから\n"
	.string "ここには ポケモンが すんでいたんだ。$"

MtMoon_B2F_Text_YouWantDomeFossil::
	.string "{JPN}こうらのカセキに する?$"

MtMoon_B2F_Text_YouWantHelixFossil::
	.string "{JPN}かいのカセキに する?$"

MtMoon_B2F_Text_ObtainedHelixFossil::
	.string "{JPN}かいのカセキを てに いれた!$"

MtMoon_B2F_Text_ObtainedDomeFossil::
	.string "{JPN}こうらのカセキを てに いれた!$"

