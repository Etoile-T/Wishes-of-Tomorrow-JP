MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}よう! ちょうしは どうだい?\n"
	.string "みらいの チャンピオン {ENG}{PLAYER}{JPN}!\p"
	.string "キンセツジムの リーダー テッセンは\n"
	.string "でんきタイプの ポケモンを つかう。\p"
	.string "みずタイプの ポケモンで いどむと\n"
	.string "しびれさせられるぞ! ビリビリッ!\p"
	.string "おまけに ジムじゅう スイッチで うごく\n"
	.string "とびらだらけ! かわった ひとだぜ!\p"
	.string "さあ がんばれよ!$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}うおっ きみには しびれたぜ!\n"
	.string "その パワーで とびらも ひらいたな!$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "{JPN}しびれる オレの たましいで\n"
	.string "ゆめごと くだいてやるぜ! イェーイ!$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "{JPN}プラグを さして アンプ ぜんかい!\n"
	.string "ひずむほど しびれる しょうぶだったぜ!$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "{JPN}ポケモンも ロックも ハートが すべて\n"
	.string "いぇーい!$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "{JPN}テッセンさんに きたえられた この オレが\n"
	.string "そう かんたんに まける はずがねえ!$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "{JPN}プラグも ぬけて でんげんオフ…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "{JPN}うちの ジムリーダーの テッセンさんは\n"
	.string "ずっと ずっと むかしから いるんだ。\p"
	.string "きみの パパが うまれる まえから\n"
	.string "たたかってる タフな じいさんさ。$"

MauvilleCity_Gym_Text_BenIntro:
	.string "{JPN}この ジムには しかけが あるんだ!\n"
	.string "たのしいだろ?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "{JPN}まけると たのしくないよ…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "{JPN}テッセンさんは スイッチを つかった\n"
	.string "ちいさな しかけづくりが すきだって。$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "{JPN}あたしの みりょくと\n"
	.string "ポケモンの わざで しびれさせちゃう!$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "{JPN}あなたの つよさに しびれたわ!$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "{JPN}この キンセツシティは\n"
	.string "テッセンさんが つくったって はなし\p"
	.string "わたしたちが トレーナーに なる\n"
	.string "ずっと まえから トレーナーだもの。\l"
	.string "きっと いろんなことを しってるわ!$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "{JPN}ぼく ひかるもの だーいすき なんだ!$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "{JPN}ああ…\n"
	.string "めのまえが チカ チカ$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "{JPN}キンセツジムの テッセンさんの おデコは\n"
	.string "ピカピカ ひかってて うれしいな!$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "{JPN}まちを かいぞうする けいかくは\n"
	.string "もう あきらめたんじゃ。\p"
	.string "それで ジムの とびらの しかけづくりに\n"
	.string "じかんを つかって おるんじゃよ。\p"
	.string "おや? おぬし ここで なにを?\p"
	.string "なんじゃと? わしの とびらの しかけを\n"
	.string "ぜんぶ ぬけてきたと いうのか?\p"
	.string "わっはははは!\n"
	.string "そりゃ おもしろい!\p"
	.string "では キンセツジムの リーダー\n"
	.string "この テッセンが しびれさせて やろう!$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "{JPN}わっはははは!\n"
	.string "よし わしの まけじゃ!\p"
	.string "こっちが しびれさせられて しもうたな!\n"
	.string "この バッジを うけとれい!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{JPN}{ENG}{PLAYER}{JPN}は テッセンから\n"
	.string "ダイナモバッジを もらった!$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "{JPN}ダイナモバッジが あれば ポケモンは\n"
	.string "たたかいの そとで いわくだきが つかえる。\p"
	.string "それに ポケモンの すばやさも\n"
	.string "すこし あがるんじゃ。\p"
	.string "ふむ…\n"
	.string "これも うけとると いい!$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "{JPN}その わざマシン34は でんげきは じゃ。\p"
	.string "けっして はずれない たのもしい わざ!\n"
	.string "たよりに なるぞ!\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "{JPN}ジムリーダー テッセンを\n"
	.string "ポケナビに とうろく した!$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "{JPN}おぬしのような みどころある わかものを\n"
	.string "みると みらいに きぼうが わいてくるわい!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "{JPN}わっはははは!\n"
	.string "わかものよ すすんで はげむんじゃ!$"

MauvilleCity_Gym_Text_GymStatue:
	.string "{JPN}キンセツシティ ポケモンジム$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "{JPN}キンセツシティ ポケモンジム\p"
	.string "テッセン にんてい トレーナー!\n"
	.string "{ENG}{PLAYER}{JPN}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "{JPN}テッセン: おーっと あらわれたな!\n"
	.string "わかっとる! わしと ポケモンの\l"
	.string "しょうぶを したいんじゃろう!?\p"
	.string "わっはははは!\p"
	.string "ひばな バチバチ いわせて やるから\n"
	.string "かくご するんじゃぞ!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "{JPN}ううっ…\n"
	.string "わしらの でんちが きれたか…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "{JPN}テッセン: また でんちを\n"
	.string "じゅうでん せねば ならんな。\p"
	.string "まんたんに じゅうでん できたら\n"
	.string "よろこんで ちょうせんを うけるぞ。\p"
	.string "だから また いつか\n"
	.string "きてくれるじゃろう?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "{JPN}テッセン: おーっと あらわれたな!\n"
	.string "わかっとる! わしと ポケモンの\l"
	.string "しょうぶを したいんじゃろう!?\p"
	.string "わっはははは!\p"
	.string "おっと まつんじゃ! ポケモンを\n"
	.string "1ひきしか つれておらんな!\p"
	.string "2ひき いじょうの ポケモンを\n"
	.string "つれて あいに きておくれ!$"

