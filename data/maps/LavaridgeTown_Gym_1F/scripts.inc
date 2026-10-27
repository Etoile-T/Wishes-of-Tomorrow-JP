LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_COLE, TRAINER_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_AXLE, TRAINER_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_KEEGAN, TRAINER_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_DANIELLE, TRAINER_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_GERALD, TRAINER_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JACE, TRAINER_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_JEFF, TRAINER_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, LOCALID_ELI, TRAINER_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript, OBJ_ID_NONE, TRAINER_NONE, NULL, NULL, NULL, NULL, NULL, FALSE, TRUE, FALSE, FALSE
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "{JPN}よう! ちょうしは どうだい?\n"
	.string "チャンピオンを めざす {ENG}{PLAYER}{JPN}!\p"
	.string "フエンの ジムリーダー アスナは\n"
	.string "ほのおタイプの ポケモンの つかいてだ!\p"
	.string "ポケモンに たいする じょうねつは\n"
	.string "かざん よりも はげしく あちィ!\p"
	.string "ちかづきすぎると やけど するぜ!\n"
	.string "みずで ひやしてから\l"
	.string "いどんで いけ!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "{JPN}いやあー あちィ たたかい だった!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "{JPN}あちちちちちっ!\n"
	.string "うひゃー あつい!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "{JPN}あせが めに しみて みえねえ……$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "{JPN}あつい すなに うまると\n"
	.string "けっこうが よくなるんだ。\p"
	.string "ふしぶしの いたみにも\n"
	.string "よく きくんだぜ。$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "{JPN}ストレスを かいしょう してるんだ。\n"
	.string "オレに ストレスを ためさせるなーっ!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "{JPN}アスナさんに こがされちまえーっ!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "{JPN}はあ ふう……\p"
	.string "あつい すなに ながく うまっていると\n"
	.string "けっこう つかれちゃう もんだよ……$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "{JPN}そろそろ つかれて きた ころだろう。\n"
	.string "あつい すなで やすみたい\l"
	.string "だろう?\p"
	.string "だが きりょくを たもつことは\n"
	.string "すべての トレーナーに とって\l"
	.string "たいせつな のうりょく なのだ。$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "{JPN}ひあそびは けがのもと だったか……$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "{JPN}おまえの うでは ほんもの だ……\n"
	.string "だが リーダーの アスナさんは つよい。\p"
	.string "ゆだん すると ひどい\n"
	.string "やけどを するぞ。$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "{JPN}おまえの ポケモン\n"
	.string "200どの あつさに たえられるかよ!?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "{JPN}もえかたが たりなかったか……$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "{JPN}マグマの おんどは\n"
	.string "200ど なんだ。\p"
	.string "おまえの ポケモン おれに かてたんだから\n"
	.string "マグマの なかでも へいき だろうな!$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "{JPN}えーっと……\n"
	.string "じゃあ しょうぶ しますね。$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "{JPN}あーん つよすぎます。$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "{JPN}あたしも アスナさん みたいな\n"
	.string "きれいで つよい トレーナーに なるんだ!$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "{JPN}ほら ほらっ! のってこいよ!\n"
	.string "きもちが さめない うちに いくぜっ!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "{JPN}こんなに あついのに\n"
	.string "おれの こころは こおりついた……$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "{JPN}それほど とうしを もやしてるなら\n"
	.string "うちの リーダーにも かてる\l"
	.string "かもしれないな。$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "{JPN}みよ この もえさかる ほのおを!\n"
	.string "オレの しょうりを よげんして いるのだ!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "{JPN}なにかが おかしいぞ。$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "{JPN}だから なんだ! だから なんだってんだ!\n"
	.string "あつい すみの うえを はだしで あるけるぜ!\p"
	.string "……まね するなよ!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "{JPN}やまは だいすき でして\n"
	.string "なかでも かざんが だいすき でして……$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "{JPN}なにも できないまま\n"
	.string "まけちまった わけでして……$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "{JPN}アスナさんの パワーの ファンに なって\n"
	.string "ここに いるわけでして。\p"
	.string "へへへへへ。$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "{JPN}ようこそ…… じゃなくて!\p"
	.string "ひよっこ トレーナー! よくぞ\n"
	.string "ここまで たどりついたわね!\p"
	.string "あたしは この ジムを まかされた……\n"
	.string "じゃなくて!\p"
	.string "あたしは アスナ! ここの\n"
	.string "ジムリーダーよ!\p"
	.string "えっと……\n"
	.string "リーダーに なって まだ まもない けど\l"
	.string "あまく みないでよね!\p"
	.string "おじいちゃん ゆずりの わざで\n"
	.string "この とちで みがいた ホットな わざを\l"
	.string "その…… みせて あげるわ!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "{JPN}あ……\n"
	.string "ちょっと はりきりすぎちゃった かも……\p"
	.string "あたし…… ジムリーダーに なったの\n"
	.string "つい さいきん なの。\p"
	.string "むりして じぶんじゃない だれかに\n"
	.string "なろうと してた。\p"
	.string "あたしらしく やらなきゃ だめね。\n"
	.string "じゃないと ポケモンも こまっちゃう。\p"
	.string "それを おしえてくれて ありがとう。\n"
	.string "あなたには これを うけとる しかくが ある!$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{JPN}{ENG}{PLAYER}{JPN}は アスナから\n"
	.string "ヒートバッジを もらった!$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "{JPN}ヒートバッジが あれば レベル50 までの\n"
	.string "ポケモンなら ひとと こうかんした\l"
	.string "ポケモンでも かならず\l"
	.string "いうことを きいて くれるの!\p"
	.string "それに ひでんわざの かいりきを\n"
	.string "たたかい いがいでも つかえるように なるわ!\p"
	.string "これは かんしゃの きもち。\n"
	.string "えんりょ せずに もらって!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "{JPN}その わざマシン50は オーバーヒート。\p"
	.string "あいてに おおきな ダメージを\n"
	.string "あたえる わざよ。\p"
	.string "でも つかった ポケモンの とくこうが\n"
	.string "がくっと さがるから ながい\l"
	.string "たたかいには むかない かもね。$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "{JPN}ジムリーダーの アスナを\n"
	.string "ポケナビに とうろく した!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "{JPN}あなたの つよさ だれかに にてる……\p"
	.string "あ! わかった! トウカの ジムリーダー\n"
	.string "センリさんの たたかいかた みたい!$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "{JPN}フエンタウン ポケモンジム$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "{JPN}フエンタウン ポケモンジム\p"
	.string "アスナ にんてい トレーナー:\n"
	.string "{ENG}{PLAYER}{JPN}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "{JPN}アスナ: しょうぶに まけた ぐらいで\n"
	.string "あたしは へこたれたり しない!\p"
	.string "ポケモンが すき。\n"
	.string "しょうぶが すき。\l"
	.string "それに…… この ジムが すき!\p"
	.string "さあ もういちど いっしょに\n"
	.string "ホットな わざを ぶつけあいましょう!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "{JPN}ふうっ!\n"
	.string "ふんかする ところ だったわ!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "{JPN}アスナ: しょうぶには まけたけど\n"
	.string "すっごく まんぞく してるの。\p"
	.string "こんなに あつい しょうぶが できる\n"
	.string "ことって なかなか ないもの。\p"
	.string "また いつか こんな しょうぶ\n"
	.string "しましょうね!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "{JPN}アスナ: しょうぶに まけた ぐらいで\n"
	.string "あたしは へこたれたり しない!\p"
	.string "ポケモンが すき。\n"
	.string "しょうぶが すき。\l"
	.string "それに…… この ジムが すき!\p"
	.string "さあ もういちど いっしょに\n"
	.string "ホットな わざを ぶつけあいましょう!\p"
	.string "……あら? たたかえる ポケモンを\n"
	.string "1ぴきしか もって いないの?\p"
	.string "わるいけど あたしの ところへは\n"
	.string "2ひき いじょう つれて きてね。$"
