CeladonCity_Gym_Frlg_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
	famechecker FAMECHECKER_ERIKA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
	famechecker FAMECHECKER_ERIKA, 4
	msgbox CeladonCity_Gym_Text_ErikaPostBattle
	release
	end

CeladonCity_Gym_EventScript_DefeatedErika::
	famechecker FAMECHECKER_ERIKA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_DEFEATED_ERIKA
	setflag FLAG_BADGE04_GET
	set_gym_trainers_frlg 4
	goto CeladonCity_Gym_EventScript_GiveTM19
	end

CeladonCity_Gym_EventScript_GiveTM19::
	msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis
	checkitemspace ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM19
	giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
	setflag FLAG_GOT_TM19_FROM_ERIKA
	msgbox CeladonCity_Gym_Text_ExplainTM19
	release
	end

CeladonCity_Gym_EventScript_NoRoomForTM19::
	msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	famechecker FAMECHECKER_ERIKA, 2
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	famechecker FAMECHECKER_ERIKA, 3
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_ErikaIntro::
	.string "{JPN}こんにちは…\n"
	.string "いい おてんきですわね?\l"
	.string "とても きもちが いいわ…\p"
	.string "…あら…\n"
	.string "いねむり してしまったのね。 ようこそ。\p"
	.string "わたくしは エリカ。\n"
	.string "タマムシジムの リーダーです。\p"
	.string "わたくし いけばなを\n"
	.string "たしなんで おりますの。\p"
	.string "わたくしの ポケモンは すべて\n"
	.string "くさタイプですわ。\p"
	.string "…あら ごめんなさい ちょうせんに\n"
	.string "いらしたとは ぞんじませんでした。\p"
	.string "よろしいですわ。 でも まけませんわよ。{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeladonCity_Gym_Text_ErikaDefeat::
	.string "{JPN}まあ!\n"
	.string "わたくしの まけですわ。\l"
	.string "あなた とても つよいのね。\p"
	.string "あなたに レインボーバッジを\n"
	.string "さしあげなくては なりませんわ。$"

CeladonCity_Gym_Text_ErikaPostBattle::
	.string "{JPN}ポケモンを ずかんに まとめているの?\n"
	.string "かんしん いたしますわ。\p"
	.string "わたくしなら うつくしくない ポケモンは\n"
	.string "けっして あつめませんけれど。$"

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
	.string "{JPN}レインボーバッジが あれば レベル50\n"
	.string "までの ポケモンが いうことを ききます。\p"
	.string "それに せんとうの うちでも そとでも\n"
	.string "かいりきが つかえるように なりますわ。\p"
	.string "こちらも おもちに なって。$"

CeladonCity_Gym_Text_ReceivedTM19FromErika::
	.string "{JPN}{ENG}{PLAYER}{JPN}は エリカから\n"
	.string "わざマシン19を もらった!$"

CeladonCity_Gym_Text_ExplainTM19::
	.string "{JPN}わざマシン19は ギガドレイン。\p"
	.string "あたえた ダメージの はんぶんを すいとり\n"
	.string "じぶんの ポケモンを かいふく しますの。\p"
	.string "すてきな わざだと\n"
	.string "おもいませんこと?$"

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
	.string "{JPN}これを もつ よゆうを つくって くださいな。$"

CeladonCity_Gym_Text_KayIntro::
	.string "{JPN}この ジムの こと おしえてあげる。\p"
	.string "ここに はいれるのは ほんものの\n"
	.string "レディだけ なのよ!$"

CeladonCity_Gym_Text_KayDefeat::
	.string "{JPN}らんぼうすぎるわ!$"

CeladonCity_Gym_Text_KayPostBattle::
	.string "{JPN}べーっだ!\n"
	.string "エリカさまに やっつけられちゃえ!$"

CeladonCity_Gym_Text_BridgetIntro::
	.string "{JPN}あら いらっしゃい。\n"
	.string "たいくつ してたところよ。$"

CeladonCity_Gym_Text_BridgetDefeat::
	.string "{JPN}おけしょうが!$"

CeladonCity_Gym_Text_BridgetPostBattle::
	.string "{JPN}くさタイプの ポケモンは\n"
	.string "みずタイプに つよいの。\p"
	.string "いわタイプや じめんタイプにも\n"
	.string "ゆうりなのよ。$"

CeladonCity_Gym_Text_TinaIntro::
	.string "{JPN}…さっき ここを のぞいて\n"
	.string "いなかった?$"

CeladonCity_Gym_Text_TinaDefeat::
	.string "{JPN}めが さめる おもいだわ!$"

CeladonCity_Gym_Text_TinaPostBattle::
	.string "{JPN}あら エリカさまを みてたのね…\n"
	.string "わたしじゃ なかったんだ…$"

CeladonCity_Gym_Text_TamiaIntro::
	.string "{JPN}みて みて!\n"
	.string "わたしの ポケモン!\p"
	.string "わたし くさタイプが すきなの。\n"
	.string "そだてやすい ところが すき。$"

CeladonCity_Gym_Text_TamiaDefeat::
	.string "{JPN}いやっ!$"

CeladonCity_Gym_Text_TamiaPostBattle::
	.string "{JPN}うちの ジムでは くさタイプの\n"
	.string "ポケモンしか つかわないの。\p"
	.string "なぜかって? いけばなにも\n"
	.string "つかうからよ!$"

CeladonCity_Gym_Text_LisaIntro::
	.string "{JPN}あら ちょっと!\p"
	.string "ここでは むしタイプや ほのおタイプの\n"
	.string "ポケモンは きらわれてるのよ!$"

CeladonCity_Gym_Text_LisaDefeat::
	.string "{JPN}あっ!\n"
	.string "あなたって!$"

CeladonCity_Gym_Text_LisaPostBattle::
	.string "{JPN}リーダーの エリカさまは ものしずか\n"
	.string "だけど この あたりでは ゆうめいなの。$"

CeladonCity_Gym_Text_LoriIntro::
	.string "{JPN}はじめまして。\n"
	.string "しゅみは ポケモンの トレーニングです。$"

CeladonCity_Gym_Text_LoriDefeat::
	.string "{JPN}まあ!\n"
	.string "おみごと!$"

CeladonCity_Gym_Text_LoriPostBattle::
	.string "{JPN}こんど おみあいが あるの。\n"
	.string "れいぎ ただしく しなくちゃ。\l"
	.string "とくに バトルを する ときはね。$"

CeladonCity_Gym_Text_MaryIntro::
	.string "{JPN}タマムシジムへ ようこそ!\p"
	.string "ここの すてきな レディたちを\n"
	.string "あまく みない ほうが いいわよ。$"

CeladonCity_Gym_Text_MaryDefeat::
	.string "{JPN}あら!\n"
	.string "まけちゃった!$"

CeladonCity_Gym_Text_MaryPostBattle::
	.string "{JPN}いちばんの ポケモンを つれて こなかったの。\n"
	.string "つぎは みてなさい!$"

CeladonCity_Gym_Text_GymStatue::
	.string "{JPN}タマムシ ポケモンジム\n"
	.string "リーダー: エリカ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
	.string "{JPN}タマムシ ポケモンジム\n"
	.string "リーダー: エリカ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}・{ENG}{PLAYER}{JPN}$"

