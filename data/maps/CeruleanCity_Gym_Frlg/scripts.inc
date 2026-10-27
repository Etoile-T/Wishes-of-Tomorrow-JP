CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
	.string "{JPN}あら みない かおね!\p"
	.string "ポケモンに たいして ポリシーを もつ\n"
	.string "トレーナーだけが プロに なれるの。\p"
	.string "あなたは どんな かんがえで\n"
	.string "ポケモンを つかまえて そだててる?\p"
	.string "わたしの ポリシーは みずタイプで\n"
	.string "ぜんりょく こうげき よ!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_ExplainTM03::
	.string "{JPN}わざマシン03は みずのはどう。\p"
	.string "みずの ポケモンに つかってね!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
	.string "{JPN}ブルーバッジが あれば レベル30\n"
	.string "までの ポケモンが いうことを きくわ。\p"
	.string "こうかんで もらった\n"
	.string "ポケモンでもね。\p"
	.string "それだけじゃ ないわ。 いあいぎりを\n"
	.string "せんとう いがいでも つかえるの。\p"
	.string "ちいさな きを いあいぎりで きって\n"
	.string "あたらしい みちを ひらけるわ。\p"
	.string "わたしの おきにいりの わざマシンも あげる。$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
	.string "{JPN}{ENG}{PLAYER}{JPN}は カスミから\n"
	.string "わざマシン03を もらった!$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
	.string "{JPN}これを もつ よゆうを つくりなさいよ!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "{JPN}うそ!\n"
	.string "あなた つよすぎ!\p"
	.string "わかったわ!\p"
	.string "わたしに かった しるしに\n"
	.string "ブルーバッジを あげる。$"

CeruleanCity_Gym_Text_DianaIntro::
	.string "{JPN}なに? あなたが?\n"
	.string "あなたの あいては わたしで じゅうぶん!\p"
	.string "カスミさんの てを わずらわせる までも ないわ。$"

CeruleanCity_Gym_Text_DianaDefeat::
	.string "{JPN}あっとうされたわ!$"

CeruleanCity_Gym_Text_DianaPostBattle::
	.string "{JPN}じぶんの ほんとうの じつりょくは\n"
	.string "ほかの トレーナーと たたかって わかるのよ。$"

CeruleanCity_Gym_Text_LuisIntro::
	.string "{JPN}バシャッ!\p"
	.string "おれが いちばんてだ!\n"
	.string "いくぞ!$"

CeruleanCity_Gym_Text_LuisDefeat::
	.string "{JPN}そんな ばかな!$"

CeruleanCity_Gym_Text_LuisPostBattle::
	.string "{JPN}カスミさんは これからも\n"
	.string "つよく なっていく トレーナーさ。\p"
	.string "きみなんかには まけないよ!$"

CeruleanCity_Gym_Text_GymGuyAdvice::
	.string "{JPN}よう!\n"
	.string "みらいの チャンピオン!\p"
	.string "アドバイスを してやろう!\p"
	.string "リーダーの カスミは みずタイプの\n"
	.string "ポケモンを つかう プロだ。\p"
	.string "くさタイプの ポケモンなら\n"
	.string "みずを すいつくして やれるぞ。\p"
	.string "それか でんきタイプの ポケモンで\n"
	.string "しびれさせて やるんだ!$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
	.string "{JPN}カスミに かったな!\n"
	.string "ほら いった とおりだろ?\p"
	.string "おれたち なかなか いい\n"
	.string "コンビじゃないか!$"

CeruleanCity_Gym_Text_GymStatue::
	.string "{JPN}ハナダ ポケモンジム\n"
	.string "リーダー: カスミ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
	.string "{JPN}ハナダ ポケモンジム\n"
	.string "リーダー: カスミ\p"
	.string "しょうりした トレーナー:\n"
	.string "{ENG}{RIVAL}{JPN}・{ENG}{PLAYER}{JPN}$"

