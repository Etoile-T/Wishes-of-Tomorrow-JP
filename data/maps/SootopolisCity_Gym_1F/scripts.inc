SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "{JPN}よう! げんきかい? チャンピオンを\n"
	.string "めざす {ENG}{PLAYER}{JPN}!\p"
	.string "ルネの ジムリーダー アダンは\n"
	.string "みずタイプの ポケモンの たつじんだ。\p"
	.string "それに アダンの ところまでは\n"
	.string "こおりの ゆかが ゆくてを はばむ……\p"
	.string "わるいけど おれから いえる\n"
	.string "アドバイスは これだけ なんだ。\p"
	.string "ここから さきは じぶんの ちからで\n"
	.string "がんばってくれ!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "{JPN}うおお! ホウエンで いちばん つよいと\n"
	.string "いわれる アダンにまで かったのか!\p"
	.string "よし! トレーナーカードを みてごらん。\p"
	.string "バッジが ぜんぶ そろっていれば\n"
	.string "ポケモンリーグに ちょうせん できるぞ!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "{JPN}ひとつ おたずね しましょう。\n"
	.string "ごぞんじ でしたか?\l"
	.string "おっと もったいぶるのは よしましょう。\p"
	.string "ミクリに ポケモンの すべてを\n"
	.string "おしえたのは この わたし なのです。\p"
	.string "わたしは いちど ジムリーダーの\n"
	.string "ざを しりぞきました。\p"
	.string "そして わたしに かわって\n"
	.string "ミクリに ジムを まかせたのです。\p"
	.string "ですが どうしても ふっきしなければ\n"
	.string "ならない りゆうが できましてね。\p"
	.string "おっと おしゃべりは ここまで。\n"
	.string "さあ しょうぶを はじめましょうか。\p"
	.string "どうぞ ごらんください わたしたちの\n"
	.string "げいじゅつを。\p"
	.string "ポケモンと わたしが えがきだす\n"
	.string "みずの イリュージョンを!$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "{JPN}アハハハ すばらしい!\n"
	.string "いいでしょう あなたの かちです。\p"
	.string "あなたからは すべてを のりこえる\n"
	.string "じつりょくの かがやきを かんじます。\p"
	.string "ですが わたしや ミクリに くらべると\n"
	.string "あなたには エレガントさが たりない。\p"
	.string "わたしの いしょうを おかし\n"
	.string "しましょうか?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "ハハハ じょうだん ですよ!\p"
	.string "いしょう ではなく あなたには\n"
	.string "この レインバッジを さしあげましょう!$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{JPN}{ENG}{PLAYER}{JPN}は アダンから\n"
	.string "レインバッジを もらった!$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "{JPN}レインバッジが あれば あなたの\n"
	.string "ポケモンは すべて あなたの めいれいに\l"
	.string "かならず したがうように なります。\p"
	.string "また レインバッジが あれば ひでんわざ\n"
	.string "たきのぼりで ながれおちる みずの\l"
	.string "かべを のぼれるように なるのです。\p"
	.string "そして わたしたちの しょうぶを\n"
	.string "わすれない ように これを……$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "{JPN}さしあげた わざマシンの なかみは\n"
	.string "みずのはどう です。\p"
	.string "ちょうおんぱで あいてを ときどき\n"
	.string "こんらん させることが あります。\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "{JPN}ジムリーダーの アダンを\n"
	.string "ポケナビに とうろくした!$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "{JPN}ホウエンの ジムバッジを すべて\n"
	.string "あつめた トレーナーは さいごの\l"
	.string "もくてきちを めざすのです。\p"
	.string "そう ポケモンリーグ です。\p"
	.string "ホウエンの はるか ひがしの はて\n"
	.string "サイユウという しまへ むかいなさい。\p"
	.string "そこに ポケモンリーグが\n"
	.string "あります。$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "{JPN}ホウエンで てにいれるべき バッジは\n"
	.string "のこり ひとつ です。\p"
	.string "ポケモンリーグに ちょうせん するなら\n"
	.string "ヒワマキの ジムで さいごの\l"
	.string "バッジを てにいれなさい。$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "{JPN}ルネシティ ポケモンジム$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "{JPN}ルネシティ ポケモンジム\p"
	.string "アダン にんてい トレーナー:\n"
	.string "{ENG}{PLAYER}{JPN}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "{JPN}アダン: ああ この ジムにも\n"
	.string "いつもの しずけさが もどったのに……\p"
	.string "わかき たいふうが ふたたび\n"
	.string "わたしたちを ためしに きましたね!\p"
	.string "ええ ともよ よろこんで!\p"
	.string "なんどでも おのぞみ のままに\n"
	.string "ともに おどりましょう!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "{JPN}アハハハ あなたの かちです!\n"
	.string "また やぶれて しまいました!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "{JPN}アダン: わたしの でしに なれと いっても\n"
	.string "あなたは きっと ことわるでしょう。\p"
	.string "わたしの コートを あなたに\n"
	.string "さしあげたい のですが。\p"
	.string "でも それも ことわるのでしょう。\n"
	.string "わたしには わかります。\p"
	.string "そして ともよ それこそが\n"
	.string "けだかさの あかし なのです!$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "{JPN}アダン: ああ この ジムにも\n"
	.string "いつもの しずけさが もどったのに……\p"
	.string "わかき たいふうが ふたたび\n"
	.string "わたしたちを ためしに きましたね!\p"
	.string "ええ ともよ よろこんで!\n"
	.string "ともに おどりましょう……\p"
	.string "おっと いけません。\n"
	.string "ポケモンが 1ぴき しか いませんね。\p"
	.string "2ひき いじょうの ポケモンを つれて\n"
	.string "また きてください。$"

