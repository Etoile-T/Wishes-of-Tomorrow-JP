@ ============================================================================
@  WISHES OF TOMORROW -- THE MEGA DIMENSION
@
@  The portals (on source maps, each spot hidden by its FLAG_HIDE_MEGA_PORTAL_*),
@  the shared map scripts of every dimension map, the Mega encounter and the
@  collapse. The logic lives in src/wot_mega_dimension.c.
@ ============================================================================

@ --- the portal in the normal world ------------------------------------------
@ A portal stays open until its dimension collapses; going back in finds the
@ same place (shinies re-rolled) for 5 seconds off its clock.
MegaDim_EventScript_Portal::
	lock
	playse SE_M_SUPERSONIC
	special WotMegaDim_CheckPortal
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_PortalFizzles
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_PortalReenter
	msgbox MegaDim_Text_PortalPrompt, MSGBOX_YESNO
	goto MegaDim_EventScript_PortalAnswer

MegaDim_EventScript_PortalReenter::
	msgbox MegaDim_Text_PortalReenterPrompt, MSGBOX_YESNO
MegaDim_EventScript_PortalAnswer::
	goto_if_eq VAR_RESULT, NO, MegaDim_EventScript_PortalDecline
	closemessage
	playse SE_M_TELEPORT
	special StartRiftDistortion
	delay 48
	playse SE_WARP_IN
	fadescreen FADE_TO_WHITE
	special EndRiftDistortion
	delay 20
	special WotMegaDim_EnterPortal
	release
	end

MegaDim_EventScript_PortalDecline::
	release
	end

@ Too little time left to go back in: it collapses (WotMegaDim_CheckPortal
@ already freed it).
MegaDim_EventScript_PortalFizzles::
	msgbox MegaDim_Text_PortalFizzles, MSGBOX_DEFAULT
	closemessage
	playse SE_WARP_IN
	removeobject VAR_LAST_TALKED
	release
	end

@ --- shared map scripts of every dimension map ---------------------------------
MegaDim_OnTransition::
	special WotMegaDim_SetMegaGfx
	end

MegaDim_OnResume::
	special WotMegaDim_StartHud
	end

@ WotMegaDim_Tick raises VAR_TEMP_1 when the countdown hits zero. ON_FRAME
@ only runs while the player is free, so a battle in progress finishes first.
MegaDim_OnFrame::
	map_script_2 VAR_TEMP_1, 1, MegaDim_EventScript_Collapse
	.2byte 0

@ --- the Mega ------------------------------------------------------------------
MegaDim_EventScript_Mega::
	lock
	faceplayer
	special WotMegaDim_GetMega
	waitse
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	waitmoncry
	bufferspeciesname STR_VAR_1, VAR_0x8006
	call_if_eq VAR_0x8007, FALSE, MegaDim_EventScript_MegaRadiates
	call_if_eq VAR_0x8007, TRUE, MegaDim_EventScript_LegendRadiates
	closemessage
	special WotMegaDim_SetupMegaBattle
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	special WotMegaDim_EndMegaBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MegaDim_EventScript_MegaCaught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MegaDim_EventScript_MegaDefeated
	@ Ran away (or teleported): the Mega is still there.
	release
	end

MegaDim_EventScript_MegaRadiates::
	msgbox MegaDim_Text_MegaRadiates, MSGBOX_DEFAULT
	return

MegaDim_EventScript_LegendRadiates::
	msgbox MegaDim_Text_LegendRadiates, MSGBOX_DEFAULT
	return

MegaDim_EventScript_MegaCaught::
	removeobject VAR_LAST_TALKED
	special WotMegaDim_GetMega
	goto_if_eq VAR_0x8007, TRUE, MegaDim_EventScript_LegendCaught
	bufferspeciesname STR_VAR_1, VAR_0x8006
	bufferitemname STR_VAR_2, VAR_0x8005
	msgbox MegaDim_Text_CaughtWithStone, MSGBOX_DEFAULT
	special WotMegaDim_MarkClaimed
	goto MegaDim_EventScript_MegaGoneCollapse

@ A KO leaves the stone behind -- the first time only. Rematches (every Mega
@ already claimed) pay nothing extra. The battle may have used the special
@ vars and string buffers, so ask again.
MegaDim_EventScript_MegaDefeated::
	removeobject VAR_LAST_TALKED
	special WotMegaDim_GetMega
	bufferspeciesname STR_VAR_1, VAR_0x8006
	goto_if_eq VAR_0x8007, TRUE, MegaDim_EventScript_LegendRetreats
	goto_if_eq VAR_RESULT, TRUE, MegaDim_EventScript_MegaFaded
	msgbox MegaDim_Text_StoneLeftBehind, MSGBOX_DEFAULT
	giveitem VAR_0x8005
	special WotMegaDim_MarkClaimed
	goto MegaDim_EventScript_MegaGoneCollapse

MegaDim_EventScript_MegaFaded::
	msgbox MegaDim_Text_MegaFaded, MSGBOX_DEFAULT
	goto MegaDim_EventScript_MegaGoneCollapse

@ --- Mable's legends (Primal Groudon/Kyogre, Mega Rayquaza) ----------------------
@ Only a catch counts. Knocked out, it retreats deeper into the rift and
@ turns up again in a later portal; the portal collapses either way.
MegaDim_EventScript_LegendCaught::
	special WotMegaDim_MarkClaimed
	goto_if_unset FLAG_WOT_CAUGHT_MEGA_RAYQUAZA, MegaDim_EventScript_MegaGoneCollapse
	goto_if_quest_complete QUEST_SKY_HIGH_MEGA, MegaDim_EventScript_MegaGoneCollapse
	completequest QUEST_SKY_HIGH_MEGA
	goto MegaDim_EventScript_MegaGoneCollapse

MegaDim_EventScript_LegendRetreats::
	msgbox MegaDim_Text_LegendRetreats, MSGBOX_DEFAULT
	goto MegaDim_EventScript_MegaGoneCollapse

@ --- calls (WotMegaDim TryStartFieldCall, once the player is free) --------------
@ Lida, when the 8:00 portals open: the towns they opened in (one per line).
MegaDim_EventScript_PortalAlert::
	lockall
	special WotMegaDim_BufferPortalAlert
	goto_if_eq VAR_RESULT, 0, MegaDim_EventScript_CallEnd
	playse SE_POKENAV_CALL
	waitse
	setspeaker SP_NAME_LIDA
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_PortalAlert1
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_PortalAlert2
	msgbox MegaDim_Text_PortalAlert3, MSGBOX_DEFAULT
	goto MegaDim_EventScript_CallEnd

MegaDim_EventScript_PortalAlert1::
	msgbox MegaDim_Text_PortalAlert1, MSGBOX_DEFAULT
	goto MegaDim_EventScript_CallEnd

MegaDim_EventScript_PortalAlert2::
	msgbox MegaDim_Text_PortalAlert2, MSGBOX_DEFAULT
	goto MegaDim_EventScript_CallEnd

@ Mable, the day after her tests start: Primal Signatures.
MegaDim_EventScript_MablePrimalCall::
	lockall
	playse SE_POKENAV_CALL
	waitse
	setspeaker SP_NAME_MABLE
	msgbox MegaDim_Text_MablePrimalCall, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	special WotMegaDim_StartLegendQuest
	startquest QUEST_PRIMAL_SIGNATURES
	releaseall
	end

@ Mable, once both Primals are caught: Sky-High Mega.
MegaDim_EventScript_MableRayquazaCall::
	lockall
	playse SE_POKENAV_CALL
	waitse
	setspeaker SP_NAME_MABLE
	msgbox MegaDim_Text_MableRayquazaCall, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	special WotMegaDim_StartLegendQuest
	completequest QUEST_PRIMAL_SIGNATURES
	startquest QUEST_SKY_HIGH_MEGA
	releaseall
	end

MegaDim_EventScript_CallEnd::
	closemessage
	setspeaker SP_NAME_NONE
	releaseall
	end

@ --- visible wild Pokemon ----------------------------------------------------------
@ Placed each visit by WotMegaDim SetupWildMons (species + shininess are in the
@ object's graphics id). Talk to one: its cry, then a battle with exactly that
@ Pokemon. Beaten or caught, it's gone for as long as the portal is open
@ (WotMegaDim_MarkWildGone); run away and it's still there.
MegaDim_EventScript_WildMon::
	lock
	faceplayer
	special WotMegaDim_BufferTalkedMon
	waitse
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	waitmoncry
	special WotMegaDim_StartOverworldMonBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MegaDim_EventScript_WildMonGone
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MegaDim_EventScript_WildMonGone
	release
	end

MegaDim_EventScript_WildMonGone::
	special WotMegaDim_MarkWildGone
	removeobject VAR_LAST_TALKED
	release
	end

@ --- the rivals ------------------------------------------------------------------
@ About one portal in five (WotMegaDim OpenPortal) a Legends Z-A character beat
@ the player to the Mega: they stand on its slot with it in their party (the
@ 5th slot is rewritten to the portal's Mega, WotMegaDim_AdjustRivalParty).
@ Fightable every trip in, with one of three openers (and its matching defeat
@ line) at random; a win hands over the stone the first time (same rule as a
@ KO) and collapses the portal, a loss whites out back to it (also a collapse).
MegaDim_EventScript_Rival::
	lock
	faceplayer
	special WotMegaDim_GetRival
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_RivalCanari
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_RivalLida
	goto_if_eq VAR_RESULT, 3, MegaDim_EventScript_RivalEmma
	goto_if_eq VAR_RESULT, 4, MegaDim_EventScript_RivalTaunie
	goto_if_eq VAR_RESULT, 5, MegaDim_EventScript_RivalTulip
	goto_if_eq VAR_RESULT, 6, MegaDim_EventScript_RivalJacinthe
	release
	end

MegaDim_EventScript_RivalCanari::
	cleartrainerflag TRAINER_MEGADIM_CANARI
	setspeaker SP_NAME_CANARI
	random 3
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_RivalCanari2
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_RivalCanari3
	msgbox MegaDim_Text_CanariIntro1, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_CANARI, MegaDim_Text_CanariDefeat1
	goto MegaDim_EventScript_RivalCanariAfter

MegaDim_EventScript_RivalCanari2::
	msgbox MegaDim_Text_CanariIntro2, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_CANARI, MegaDim_Text_CanariDefeat2
	goto MegaDim_EventScript_RivalCanariAfter

MegaDim_EventScript_RivalCanari3::
	msgbox MegaDim_Text_CanariIntro3, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_CANARI, MegaDim_Text_CanariDefeat3
	goto MegaDim_EventScript_RivalCanariAfter

MegaDim_EventScript_RivalCanariAfter::
	setspeaker SP_NAME_CANARI
	msgbox MegaDim_Text_CanariPost, MSGBOX_DEFAULT
	goto MegaDim_EventScript_RivalBeaten

MegaDim_EventScript_RivalLida::
	cleartrainerflag TRAINER_MEGADIM_LIDA
	setspeaker SP_NAME_LIDA
	random 3
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_RivalLida2
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_RivalLida3
	msgbox MegaDim_Text_LidaIntro1, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_LIDA, MegaDim_Text_LidaDefeat1
	goto MegaDim_EventScript_RivalLidaAfter

MegaDim_EventScript_RivalLida2::
	msgbox MegaDim_Text_LidaIntro2, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_LIDA, MegaDim_Text_LidaDefeat2
	goto MegaDim_EventScript_RivalLidaAfter

MegaDim_EventScript_RivalLida3::
	msgbox MegaDim_Text_LidaIntro3, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_LIDA, MegaDim_Text_LidaDefeat3
	goto MegaDim_EventScript_RivalLidaAfter

MegaDim_EventScript_RivalLidaAfter::
	setspeaker SP_NAME_LIDA
	msgbox MegaDim_Text_LidaPost, MSGBOX_DEFAULT
	goto MegaDim_EventScript_RivalBeaten

MegaDim_EventScript_RivalEmma::
	cleartrainerflag TRAINER_MEGADIM_EMMA
	setspeaker SP_NAME_EMMA
	random 3
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_RivalEmma2
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_RivalEmma3
	msgbox MegaDim_Text_EmmaIntro1, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_EMMA, MegaDim_Text_EmmaDefeat1
	goto MegaDim_EventScript_RivalEmmaAfter

MegaDim_EventScript_RivalEmma2::
	msgbox MegaDim_Text_EmmaIntro2, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_EMMA, MegaDim_Text_EmmaDefeat2
	goto MegaDim_EventScript_RivalEmmaAfter

MegaDim_EventScript_RivalEmma3::
	msgbox MegaDim_Text_EmmaIntro3, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_EMMA, MegaDim_Text_EmmaDefeat3
	goto MegaDim_EventScript_RivalEmmaAfter

MegaDim_EventScript_RivalEmmaAfter::
	setspeaker SP_NAME_EMMA
	msgbox MegaDim_Text_EmmaPost, MSGBOX_DEFAULT
	goto MegaDim_EventScript_RivalBeaten

MegaDim_EventScript_RivalTaunie::
	cleartrainerflag TRAINER_MEGADIM_TAUNIE
	setspeaker SP_NAME_TAUNIE
	random 3
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_RivalTaunie2
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_RivalTaunie3
	msgbox MegaDim_Text_TaunieIntro1, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_TAUNIE, MegaDim_Text_TaunieDefeat1
	goto MegaDim_EventScript_RivalTaunieAfter

MegaDim_EventScript_RivalTaunie2::
	msgbox MegaDim_Text_TaunieIntro2, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_TAUNIE, MegaDim_Text_TaunieDefeat2
	goto MegaDim_EventScript_RivalTaunieAfter

MegaDim_EventScript_RivalTaunie3::
	msgbox MegaDim_Text_TaunieIntro3, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_TAUNIE, MegaDim_Text_TaunieDefeat3
	goto MegaDim_EventScript_RivalTaunieAfter

MegaDim_EventScript_RivalTaunieAfter::
	setspeaker SP_NAME_TAUNIE
	msgbox MegaDim_Text_TauniePost, MSGBOX_DEFAULT
	goto MegaDim_EventScript_RivalBeaten

MegaDim_EventScript_RivalTulip::
	cleartrainerflag TRAINER_MEGADIM_TULIP
	setspeaker SP_NAME_TULIP
	random 3
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_RivalTulip2
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_RivalTulip3
	msgbox MegaDim_Text_TulipIntro1, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_TULIP, MegaDim_Text_TulipDefeat1
	goto MegaDim_EventScript_RivalTulipAfter

MegaDim_EventScript_RivalTulip2::
	msgbox MegaDim_Text_TulipIntro2, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_TULIP, MegaDim_Text_TulipDefeat2
	goto MegaDim_EventScript_RivalTulipAfter

MegaDim_EventScript_RivalTulip3::
	msgbox MegaDim_Text_TulipIntro3, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_TULIP, MegaDim_Text_TulipDefeat3
	goto MegaDim_EventScript_RivalTulipAfter

MegaDim_EventScript_RivalTulipAfter::
	setspeaker SP_NAME_TULIP
	msgbox MegaDim_Text_TulipPost, MSGBOX_DEFAULT
	goto MegaDim_EventScript_RivalBeaten

MegaDim_EventScript_RivalJacinthe::
	cleartrainerflag TRAINER_MEGADIM_JACINTHE
	setspeaker SP_NAME_JACINTHE
	random 3
	goto_if_eq VAR_RESULT, 1, MegaDim_EventScript_RivalJacinthe2
	goto_if_eq VAR_RESULT, 2, MegaDim_EventScript_RivalJacinthe3
	msgbox MegaDim_Text_JacintheIntro1, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_JACINTHE, MegaDim_Text_JacintheDefeat1
	goto MegaDim_EventScript_RivalJacintheAfter

MegaDim_EventScript_RivalJacinthe2::
	msgbox MegaDim_Text_JacintheIntro2, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_JACINTHE, MegaDim_Text_JacintheDefeat2
	goto MegaDim_EventScript_RivalJacintheAfter

MegaDim_EventScript_RivalJacinthe3::
	msgbox MegaDim_Text_JacintheIntro3, MSGBOX_DEFAULT
	closemessage
	setspeaker SP_NAME_NONE
	trainerbattle_no_intro TRAINER_MEGADIM_JACINTHE, MegaDim_Text_JacintheDefeat3
	goto MegaDim_EventScript_RivalJacintheAfter

MegaDim_EventScript_RivalJacintheAfter::
	setspeaker SP_NAME_JACINTHE
	msgbox MegaDim_Text_JacinthePost, MSGBOX_DEFAULT
	goto MegaDim_EventScript_RivalBeaten

MegaDim_EventScript_RivalBeaten::
	special WotMegaDim_GetMega
	goto_if_eq VAR_RESULT, TRUE, MegaDim_EventScript_RivalLeaves
	msgbox MegaDim_Text_RivalHandsStone, MSGBOX_DEFAULT
	setspeaker SP_NAME_NONE
	giveitem VAR_0x8005
	special WotMegaDim_MarkClaimed
MegaDim_EventScript_RivalLeaves::
	closemessage
	setspeaker SP_NAME_NONE
	playse SE_WARP_OUT
	removeobject VAR_LAST_TALKED
	goto MegaDim_EventScript_MegaGoneCollapse

MegaDim_Text_RivalHandsStone:
	.string "{JPN}ほら。 やくそくは やくそくだ。$"

MegaDim_Text_CanariIntro1:
	.string "{JPN}へへっ おさきに! いくよ\n"
	.string "DYN4MO! この メガは\p"
	.string "このまま はいしん いきっ!\n"
	.string "ファンの みんな みてる?!$"

MegaDim_Text_CanariDefeat1:
	.string "{JPN}うわー いまの シーンは\n"
	.string "カットだね… でも GG!$"

MegaDim_Text_CanariIntro2:
	.string "{JPN}コメントの よそうどおり!\n"
	.string "やっぱり 30びょう おそかった!\p"
	.string "うばいに くる? えんりょ\n"
	.string "しないで! ファンは タイマン すき!$"

MegaDim_Text_CanariDefeat2:
	.string "{JPN}ファンが きみの なまえで\n"
	.string "コメント うめつくしてる。 ひどい。$"

MegaDim_Text_CanariIntro3:
	.string "{JPN}あっ やっほー! アンコールに\n"
	.string "ちょうど まにあったね! いくよ\p"
	.string "DYN4MO! なまで 1しょうぶ!\n"
	.string "かったほうが いしを もらう!$"

MegaDim_Text_CanariDefeat3:
	.string "{JPN}はいしん しゅうりょう!\n"
	.string "…はいはい こんかいは きみの かち。$"

MegaDim_Text_CanariPost:
	.string "{JPN}グッドボタンと チャンネル\n"
	.string "とうろく よろしく! …なに? くせ。$"

MegaDim_Text_LidaIntro1:
	.string "{JPN}へへっ おさきに! チームMZは\n"
	.string "いつだって いちばんのり。\p"
	.string "それでも ほしい? なら しょうめいして!$"

MegaDim_Text_LidaDefeat1:
	.string "{JPN}わかった わかった きみの ものだよ。$"

MegaDim_Text_LidaIntro2:
	.string "{JPN}はやいね {ENG}{PLAYER}{JPN}… でも\n"
	.string "チームMZほどじゃ ないかな。\p"
	.string "この メガは こっちの もの。\n"
	.string "それとも きみが うばってみる?$"

MegaDim_Text_LidaDefeat2:
	.string "{JPN}すごい。 モミジが きいたら\n"
	.string "くわしく ききたがるだろうな。$"

MegaDim_Text_LidaIntro3:
	.string "{JPN}へへっ! さけめが ひかりおわる\n"
	.string "まえに つかまえちゃった!\p"
	.string "ほら 1かいだけ。 おたのしみで。\n"
	.string "あと いしを かけて。$"

MegaDim_Text_LidaDefeat3:
	.string "{JPN}うん たのしかったし\n"
	.string "はずかしかった。 やるね。$"

MegaDim_Text_LidaPost:
	.string "{JPN}チームMZに きみみたいな ひと\n"
	.string "いると いいな。 なんてね!$"

MegaDim_Text_EmmaIntro1:
	.string "{JPN}ふふ おさきに。 この はんのうは\n"
	.string "なんじかんも まえに おってたの。\p"
	.string "いしが ほしい? なら わたしを よみきって。$"

MegaDim_Text_EmmaDefeat1:
	.string "{JPN}じけん かいけつ… あなたの かちで。$"

MegaDim_Text_EmmaIntro2:
	.string "{JPN}てがかりは みえみえ だったわ。\n"
	.string "みる ばしょさえ わかればね。\p"
	.string "どちらが この なぞを といたか\n"
	.string "はっきり させましょうか?$"

MegaDim_Text_EmmaDefeat2:
	.string "{JPN}てがかりを みおとした。 どこかで。\n"
	.string "おみごとね。$"

MegaDim_Text_EmmaIntro3:
	.string "{JPN}わたしと おなじ さけめを\n"
	.string "たどってきたのね。 かしこいわ。\p"
	.string "でも はんにんは もう\n"
	.string "たいほ ずみ。 いぎを もうしたてる?$"

MegaDim_Text_EmmaDefeat3:
	.string "{JPN}しょうこは くつがえされたわ。\n"
	.string "いしは あなたの ものよ。$"

MegaDim_Text_EmmaPost:
	.string "{JPN}さけめは かならず あとを のこす。\n"
	.string "つぎは わたしが さきに みつけるわ。$"

MegaDim_Text_TaunieIntro1:
	.string "{JPN}へへっ おさきに!\n"
	.string "でも フェアに いこう。\p"
	.string "しょうぶして とってみて!$"

MegaDim_Text_TaunieDefeat1:
	.string "{JPN}うわっ つよいね!$"

MegaDim_Text_TaunieIntro2:
	.string "{JPN}あっ! きみも これを ねらって きたの?\n"
	.string "こんかいは ラッキー だったんだ。\p"
	.string "その うんが バトルでも\n"
	.string "つづくか ためしてみよう!$"

MegaDim_Text_TaunieDefeat2:
	.string "{JPN}だめだ! うんぎれ!$"

MegaDim_Text_TaunieIntro3:
	.string "{JPN}いま つかまえたの! すごく\n"
	.string "ない? …まって きみも ほしいの?\p"
	.string "わかった わかった! かったほうが\n"
	.string "いしを もらう それでいい?$"

MegaDim_Text_TaunieDefeat3:
	.string "{JPN}やくそくは やくそく…\n"
	.string "でも つかまえたのは じまんだよ!$"

MegaDim_Text_TauniePost:
	.string "{JPN}つぎの さけめまで きょうそうね!\n"
	.string "2かいは まけないから!$"

MegaDim_Text_TulipIntro1:
	.string "{JPN}あら おさきに いただいたわ。\n"
	.string "どちらが この メガを\p"
	.string "うつくしく まとえるかしら?$"

MegaDim_Text_TulipDefeat1:
	.string "{JPN}みごとな できばえね。$"

MegaDim_Text_TulipIntro2:
	.string "{JPN}はぐれメガ… あらけずりな びしさ。\n"
	.string "てに いれずには いられなかったの。\p"
	.string "でも うばいたければ どうぞ\n"
	.string "ためしてみて あなた。$"

MegaDim_Text_TulipDefeat2:
	.string "{JPN}かんぺきね。 わたしでも\n"
	.string "その わざには けちを つけられない。$"

MegaDim_Text_TulipIntro3:
	.string "{JPN}ここの ひかりは まるで\n"
	.string "だめ。 でも メガは? かんぺきよ。\p"
	.string "この こに ショーを みせて\n"
	.string "あげましょうか あなた?$"

MegaDim_Text_TulipDefeat3:
	.string "{JPN}あなた かがやいていたわ。\n"
	.string "ほんとうに。$"

MegaDim_Text_TulipPost:
	.string "{JPN}うつくしさは うつろうもの。\n"
	.string "でも あの つよさは きえないわ。$"

MegaDim_Text_JacintheIntro1:
	.string "{JPN}ふふ おさきに。 これほど めずらしい\n"
	.string "メガは ふさわしいのよ\p"
	.string "センスの ある ものにこそ…\n"
	.string "あなたが そうだと しめさないかぎり。$"

MegaDim_Text_JacintheDefeat1:
	.string "{JPN}ふん。 いいでしょう。$"

MegaDim_Text_JacintheIntro2:
	.string "{JPN}おそいわね。 なんて\n"
	.string "ありきたりな こと。\p"
	.string "まあ 1どだけ チャンスを\n"
	.string "あげる。 せいぜい たのしませて。$"

MegaDim_Text_JacintheDefeat2:
	.string "{JPN}…みごとね。\n"
	.string "ちょうしに のらないことね。$"

MegaDim_Text_JacintheIntro3:
	.string "{JPN}この メガには ふさわしい\n"
	.string "もちぬしが ひつよう。 わたしよ。\p"
	.string "それとも あなた じぶんの ことを\n"
	.string "べんめい してみる?$"

MegaDim_Text_JacintheDefeat3:
	.string "{JPN}せっとくりょくの ある べんめいね。\n"
	.string "いさぎよく ゆずるわ。$"

MegaDim_Text_JacinthePost:
	.string "{JPN}つぎは こんなに かんだいには\n"
	.string "ならないわよ。 ごきげんよう。$"

@ --- leaving -------------------------------------------------------------------
@ The exit portal: home, and the portal there stays open.
MegaDim_EventScript_ExitPortal::
	lock
	msgbox MegaDim_Text_ExitPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MegaDim_EventScript_PortalDecline
	closemessage
	call MegaDim_EventScript_RiftOut
	special WotMegaDim_LeaveOut
	release
	end

@ The clock ran out (ON_FRAME, VAR_TEMP_1 = 1): the portal collapses.
MegaDim_EventScript_Collapse::
	lockall
	setvar VAR_TEMP_1, 2
	call MegaDim_EventScript_CollapseShake
	call MegaDim_EventScript_RiftOut
	special WotMegaDim_CollapseOut
	releaseall
	end

@ The rogue Mega was caught or KO'd, or the rival holding it beaten: the
@ portal collapses too. VAR_TEMP_1 = 2 so the clock's collapse can't follow.
MegaDim_EventScript_MegaGoneCollapse::
	closemessage
	setvar VAR_TEMP_1, 2
	call MegaDim_EventScript_CollapseShake
	call MegaDim_EventScript_RiftOut
	special WotMegaDim_CollapseOut
	release
	end

MegaDim_EventScript_CollapseShake::
	playse SE_THUNDER
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 10 @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	msgbox MegaDim_Text_Collapsing, MSGBOX_DEFAULT
	closemessage
	playse SE_THUNDER2
	setvar VAR_0x8004, 3  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 16 @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	return

MegaDim_EventScript_RiftOut::
	playse SE_M_SUPERSONIC
	special StartRiftDistortion
	delay 48
	playse SE_WARP_IN
	fadescreen FADE_TO_WHITE
	special EndRiftDistortion
	delay 20
	return

@ --- text ----------------------------------------------------------------------
MegaDim_Text_PortalPrompt:
	.string "{JPN}さけめが ふしぎな エネルギーで\n"
	.string "パチパチ いっている。 その さきの\l"
	.string "せかいは いろが ぬけおちている…\p"
	.string "なかに はいる?$"

MegaDim_Text_PortalReenterPrompt:
	.string "{JPN}さけめは まだ ひらいているが\n"
	.string "きえかけている: のこり {ENG}{STR_VAR_1}{JPN}\p"
	.string "もういちど はいると 5びょう へる。\n"
	.string "なかに はいる?$"

MegaDim_Text_PortalFizzles:
	.string "{JPN}さけめが ゆらめいて…\n"
	.string "しゅっと きえてしまった。$"

MegaDim_Text_ExitPrompt:
	.string "{JPN}もとの せかいへの さけめは まだ\n"
	.string "ひらいている。 あいだは もどれる。\p"
	.string "メガじげんを でる?$"

MegaDim_Text_MegaRadiates:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}から\n"
	.string "メガの ちからが あふれている!$"

MegaDim_Text_StoneLeftBehind:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}は きえていった…\n"
	.string "なにかを のこしていった!$"

MegaDim_Text_CaughtWithStone:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}は\n"
	.string "{ENG}{STR_VAR_2}{JPN}を もっている!$"

MegaDim_Text_MegaFaded:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}は きえていった…$"

MegaDim_Text_LegendRadiates:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}から\n"
	.string "とてつもない ちからを かんじる!$"

MegaDim_Text_LegendRetreats:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}は さけめの\n"
	.string "おくへ にげていった…\p"
	.string "また どこかに あらわれるだろう。$"

MegaDim_Text_PortalAlert1:
	.string "{JPN}{ENG}{PLAYER}{JPN} きいて! あたらしい\n"
	.string "さけめが ひらいたよ:\p"
	.string "{ENG}{STR_VAR_1}{JPN}!\p"
	.string "なかは 2ふん。 いそいで いそいで!$"

MegaDim_Text_PortalAlert2:
	.string "{JPN}{ENG}{PLAYER}{JPN} きいて! あたらしい\n"
	.string "さけめが ひらいたよ:\p"
	.string "{ENG}{STR_VAR_1}{JPN}\n"
	.string "と {ENG}{STR_VAR_2}{JPN}!\p"
	.string "なかは 2ふん。 いそいで いそいで!$"

MegaDim_Text_PortalAlert3:
	.string "{JPN}{ENG}{PLAYER}{JPN} きいて! あたらしい\n"
	.string "さけめが ひらいたよ:\p"
	.string "{ENG}{STR_VAR_1}{JPN}\n"
	.string "{ENG}{STR_VAR_2}{JPN}\l"
	.string "と {ENG}{STR_VAR_3}{JPN}!\p"
	.string "なかは 2ふん。 いそいで いそいで!$"

MegaDim_Text_MablePrimalCall:
	.string "{JPN}{ENG}{PLAYER}{JPN} モミジよ。 19この\n"
	.string "いし すべての けんさが おわったわ。\p"
	.string "それと べつの ものも みつけたの。\n"
	.string "さけめの なかに けたはずれの\l"
	.string "ちからの はんのうが 2つ。\p"
	.string "ゲンシの ポケモン。 グラードンと\n"
	.string "カイオーガの いにしえの すがたよ。\p"
	.string "いま さけめの なかに いるわ。\n"
	.string "2ひき とも つかまえて。 しんちょうにね。$"

MegaDim_Text_MableRayquazaCall:
	.string "{JPN}{ENG}{PLAYER}{JPN}! モミジよ。 ゲンシを\n"
	.string "2ひきとも つかまえたのね。 おみごと。\p"
	.string "でも なにかが その ちからを\n"
	.string "おって さけめを うごいているの。\p"
	.string "メガレックウザよ。 もう さけめの\n"
	.string "なかに いるわ。\p"
	.string "さけめを こじあけられる まえに\n"
	.string "つかまえて。$"

MegaDim_Text_Collapsing:
	.string "{JPN}メガじげんが くずれはじめた!$"
