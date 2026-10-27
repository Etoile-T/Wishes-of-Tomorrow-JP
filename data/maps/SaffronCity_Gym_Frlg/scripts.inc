SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
	.string "{JPN}あなたが くることは みえていたわ。\p"
	.string "わたしは こどもの ころから\n"
	.string "エスパーの ちからを もっていた。\p"
	.string "なにげなく なげた スプーンが\n"
	.string "まがったのが はじまりだった。\p"
	.string "たたかいは すきじゃないけど\n"
	.string "のぞむなら ちからを みせてあげる!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

SaffronCity_Gym_Text_SabrinaDefeat::
	.string "{JPN}まけるなんて… ショックだわ!\n"
	.string "でも まけは まけ。\p"
	.string "かつための どりょくが\n"
	.string "たりなかったと みとめるわ。\p"
	.string "あなたの しょうりの あかしに\n"
	.string "ゴールドバッジを あげる。$"

SaffronCity_Gym_Text_SabrinaPostBattle::
	.string "{JPN}エスパーの ちからは ごく いちぶの\n"
	.string "ひとだけの ものじゃ ないわ。\p"
	.string "だれでも エスパーの ちからを もっている。\n"
	.string "ただ きづいて いないだけ。$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
	.string "{JPN}ゴールドバッジが あれば レベル70\n"
	.string "までの ポケモンが いうことを きく。\p"
	.string "それより つよい ポケモンは\n"
	.string "しょうぶで めいれいを きかなくなる。\p"
	.string "そう ならないように ポケモンを\n"
	.string "そだてすぎない ことね。\p"
	.string "まって この わざマシンも もっていって。$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ナツメから\n"
	.string "わざマシン04を もらった!$"

SaffronCity_Gym_Text_ExplainTM04::
	.string "{JPN}わざマシン04は めいそう。\p"
	.string "ポケモンが せいしんを しゅうちゅうして\n"
	.string "とくこうと とくぼうを あげるの。$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
	.string "{JPN}バッグが ほかの どうぐで いっぱいね。$"

SaffronCity_Gym_Text_AmandaIntro::
	.string "{JPN}ナツメは わたしより ずっと わかいけど\n"
	.string "わたしは かのじょを そんけい してるの。$"

SaffronCity_Gym_Text_AmandaDefeat::
	.string "{JPN}まだ たりないのね!$"

SaffronCity_Gym_Text_AmandaPostBattle::
	.string "{JPN}ごかくの しょうぶ では\n"
	.string "いしの つよい ほうが かつの。\p"
	.string "ナツメに かちたいなら しゅうちゅうして\n"
	.string "しょうりを つよく ねんじなさい。$"

SaffronCity_Gym_Text_JohanIntro::
	.string "{JPN}めに みえない ちからが こわいかい?$"

SaffronCity_Gym_Text_JohanDefeat::
	.string "{JPN}こんなの よちして なかった!$"

SaffronCity_Gym_Text_JohanPostBattle::
	.string "{JPN}エスパー ポケモンが おそれるのは\n"
	.string "ゴーストと むし だけさ!$"

SaffronCity_Gym_Text_StacyIntro::
	.string "{JPN}ポケモンは トレーナーに\n"
	.string "にて くるものよ。\p"
	.string "だったら あなたの ポケモンは つよそうね!$"

SaffronCity_Gym_Text_StacyDefeat::
	.string "{JPN}やっぱりね!$"

SaffronCity_Gym_Text_StacyPostBattle::
	.string "{JPN}まだまだ まなぶことが おおいわ…\p"
	.string "サイコキネシスを きわめて\n"
	.string "ポケモンに おしえなくちゃ…$"

SaffronCity_Gym_Text_TyronIntro::
	.string "{JPN}きみなら わかるよね?\p"
	.string "ポケモンの せかいでは ちからだけじゃ\n"
	.string "かてないって ことが?$"

SaffronCity_Gym_Text_TyronDefeat::
	.string "{JPN}しんじられない!$"

SaffronCity_Gym_Text_TyronPostBattle::
	.string "{JPN}ナツメは となりの カラテだいおうを\n"
	.string "こてんぱんに したんだ。$"

SaffronCity_Gym_Text_TashaIntro::
	.string "{JPN}あなたと わたし ポケモンで\n"
	.string "しょうぶよ!$"

SaffronCity_Gym_Text_TashaDefeat::
	.string "{JPN}やっぱり まけたわ!$"

SaffronCity_Gym_Text_TashaPostBattle::
	.string "{JPN}こうなる ことは\n"
	.string "わかって いたの。$"

SaffronCity_Gym_Text_CameronIntro::
	.string "{JPN}ナツメは わかいけど うでの たつ\n"
	.string "わたしたちの リーダーだ。\p"
	.string "かんたんには たどりつけないぞ!$"

SaffronCity_Gym_Text_CameronDefeat::
	.string "{JPN}いてっ!\n"
	.string "ノックアウトだ!$"

SaffronCity_Gym_Text_CameronPostBattle::
	.string "{JPN}むかし ヤマブキには ポケモンジムが\n"
	.string "ふたつ あったんだ。\p"
	.string "でも となりの かくとう どうじょうは\n"
	.string "ジムの しかくを うしなった。\p"
	.string "ジムを ひとつに きめるとき\n"
	.string "わたしたちが こてんぱんに したのさ。$"

SaffronCity_Gym_Text_PrestonIntro::
	.string "{JPN}ヤマブキジムは エスパーを\n"
	.string "そだてる ことで ゆうめいなんだ。\p"
	.string "きみ ナツメに あいたいんだろ?\n"
	.string "わかるんだよ!$"

SaffronCity_Gym_Text_PrestonDefeat::
	.string "{JPN}ぐわあああ!$"

SaffronCity_Gym_Text_PrestonPostBattle::
	.string "{JPN}そうさ! テレパシーで きみの\n"
	.string "こころを よんだのさ!$"

SaffronCity_Gym_Text_GymGuyAdvice::
	.string "{JPN}よう!\n"
	.string "みらいの チャンピオン!\p"
	.string "ナツメの ポケモンは ちからでなく\n"
	.string "エスパーの ちからで たたかう。\p"
	.string "かくとう ポケモンは エスパー\n"
	.string "ポケモンに とくに よわいんだ。\p"
	.string "パンチを くりだす まえに\n"
	.string "やられちまうぞ!$"

SaffronCity_Gym_Text_GymGuyPostVictory::
	.string "{JPN}エスパーの ちからか…\p"
	.string "おれに そんな ちからが あったら\n"
	.string "スロットで おおもうけ するのにな!$"

SaffronCity_Gym_Text_GymStatue::
	.string "{JPN}ヤマブキ ポケモンジム\n"
	.string "ジムリーダー: ナツメ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "{JPN}ヤマブキ ポケモンジム\n"
	.string "ジムリーダー: ナツメ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN} {ENG}{PLAYER}{JPN}$"

