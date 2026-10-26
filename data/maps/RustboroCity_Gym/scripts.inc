RustboroCity_Gym_MapScripts::
	.byte 0

@ The Ember Badge fight. Split out of trainerbattle_single so the boss card
@ can sit between his challenge and the battle; the badge ceremony that the
@ old form ran as its "defeated" script is reached by goto instead.
RustboroCity_Gym_EventScript_Roxanne::
	goto_if_defeated TRAINER_ROXANNE_1, RustboroCity_Gym_EventScript_RoxanneAfter
	lockall
	setspeaker SP_NAME_RED_FATALITY
	msgbox RustboroCity_Gym_Text_RoxanneIntro, MSGBOX_DEFAULT
	closemessage
	@ clear the SE bed first, or the card's shimmer loses its channel
	special WotSuppressWeatherSE
	special WotStopSceneSE
	bossintro BOSS_INTRO_RED_FATALITY
	trainerbattle_no_intro TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneDefeat
	goto RustboroCity_Gym_EventScript_RoxanneDefeated
	end

RustboroCity_Gym_EventScript_RoxanneAfter::
	lock
	faceplayer
	setspeaker SP_NAME_RED_FATALITY
	goto_if_set FLAG_HIDE_SHINKANSEN_GOON, RustboroCity_Gym_EventScript_PostBattleKnowsTrain
	msgbox RustboroCity_Gym_Text_PostBattleNorth, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_PostBattleKnowsTrain::
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

@ Badge ceremony hook: if the player already boarded the SHINKANSEN and beat the
@ goon (FLAG_HIDE_SHINKANSEN_GOON), RedFatality acknowledges the frozen train and
@ vows to thaw it. Otherwise he just points the player north past the SHINKANSEN
@ toward the mountain. (The track-clear itself is gated on FLAG_BADGE01_GET only.)
RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedEmberBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setspeaker SP_NAME_RED_FATALITY
	msgbox RustboroCity_Gym_Text_EmberBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	call_if_quest_active SIDE_QUEST_FROZEN_TRACKS, RustboroCity_Gym_EventScript_CompleteFrozenTracks
	setspeaker SP_NAME_RED_FATALITY
	goto_if_set FLAG_HIDE_SHINKANSEN_GOON, RustboroCity_Gym_EventScript_KnownTrainHook
	msgbox RustboroCity_Gym_Text_HeadNorthHook, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_CompleteFrozenTracks::
	completequest SIDE_QUEST_FROZEN_TRACKS
	return

RustboroCity_Gym_EventScript_KnownTrainHook::
	msgbox RustboroCity_Gym_Text_FrozenTrainHook, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	setspeaker SP_NAME_MIKMANC
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	setspeaker SP_NAME_MINISTER
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	setspeaker SP_NAME_YIFFER
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "{JPN}よう チャレンジャー! ここの さむさは\n"
	.string "じゅうぶん あじわったかい？\p"
	.string "フロストウッドジムへ ようこそ。\n"
	.string "リーダー RedFatalityは\l"
	.string "こおりタイプを とことん きわめた おとこさ。\p"
	.string "こおりポケモンは ほのお・かくとう・\n"
	.string "いわ・はがねタイプの わざが にがてだ。\l"
	.string "しっかり じゅんびを しておいで!\p"
	.string "もうひとつ… RedFatalityは\n"
	.string "めずらしい ポケモンに めがないんだ。\p"
	.string "あいてのことが ぜんぶ わかったなんて\n"
	.string "おもいこまないようにな。\p"
	.string "さあ エンバーバッジを かちとってこい!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "{JPN}おお! RedFatalityを たおしたのか!\p"
	.string "その エンバーバッジは\n"
	.string "まちがいなく ほんものだ。\p"
	.string "ちょうてんへ むけて おおきな いっぽを\n"
	.string "ふみだしたな。 いいきぶんだろ チャンプ？$"

RustboroCity_Gym_Text_JoshIntro:
	.string "{JPN}じめんに ゆきが つもっているからって\n"
	.string "なにもかも こおりついているわけじゃ ない!\p"
	.string "ぼくの ポケモンは きびしい さむさでも\n"
	.string "つよく そだつんだ!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "{JPN}ぼくの ちいさな にわには\n"
	.string "もっと ひざしが ひつようかな…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "{JPN}もしかして かんぜんに みおとり してた？$"

RustboroCity_Gym_Text_TommyIntro:
	.string "{JPN}ゆきどけの せいで\n"
	.string "フロストウッドでは ながいあいだ\l"
	.string "みなかった ポケモンが あらわれているんだ!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "{JPN}くそっ! つよいな。$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "{JPN}こおりが とけはじめてから\n"
	.string "へんな タイプの ポケモンが つぎつぎ でてくる。\p"
	.string "とんでもない じだいだよな？$"

RustboroCity_Gym_Text_MarcIntro:
	.string "{JPN}イフ イフ!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "{JPN}イフ…$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "{JPN}イフ イフ…$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "{JPN}フロストウッドジムへ ようこそ。\p"
	.string "そうだ おれが RedFatalityだ。\p"
	.string "ああ うわさは ほんとうさ。\n"
	.string "Halo 3の MLGプロ だったんだ。\p"
	.string "ほかの やつらみたいに こおりタイプだけを\n"
	.string "つかまえてきたのなら\p"
	.string "いたいめを みるぞ ちょうせんしゃ。\p"
	.string "さあ おまえの ちからを みせてみろ!$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "{JPN}…へっ。\p"
	.string "おれの きりふだまで ひきずりだして\n"
	.string "それでも かちきったんだな。\p"
	.string "そんな トレーナーは めったに いない。\p"
	.string "おまえには これを わたそう。$"

RustboroCity_Gym_Text_ReceivedEmberBadge:
	.string "{JPN}{ENG}{PLAYER}{JPN}は エンバーバッジを\n"
	.string "RedFatalityから もらった。$"

RustboroCity_Gym_Text_EmberBadgeInfo:
	.string "{JPN}エンバーバッジは ポケモンの\n"
	.string "こうげきの ちからを あげる。\p"
	.string "ほこりを もって つけていろ。$"

RustboroCity_Gym_Text_FrozenTrainHook:
	.string "{JPN}いくまえに もうひとつ。\p"
	.string "まちの きたはずれに ある センネンせんを\n"
	.string "しっているか？\p"
	.string "ゆきどけが とちゅうで とまって\n"
	.string "れっしゃが まるごと かたい こおりに\l"
	.string "とじこめられている。 だれも とおれない。\p"
	.string "よし こうしよう。\p"
	.string "おれと ウインディで むかって\n"
	.string "じぶんたちの ほのおで とかしてやる。\p"
	.string "せんろが あけば\n"
	.string "おまえの いくみちも ひらけるさ。\p"
	.string "さあ いけ チャレンジャー。\n"
	.string "この ちほうが おまえを まっているぞ。$"

RustboroCity_Gym_Text_HeadNorthHook:
	.string "{JPN}いくまえに もうひとつ。\p"
	.string "このさきは きただ。 センネンせんに とまる\n"
	.string "こうそくれっしゃ しんかんせんを\l"
	.string "こえていけ。\p"
	.string "せんろの むこうには やまが そびえ\n"
	.string "その うえで チャレンジャーたちが\l"
	.string "おまえを まっている。\p"
	.string "せんろに じゃまな ものが あれば\n"
	.string "おれと ウインディが やきはらってやる。\p"
	.string "さあ いけ チャレンジャー。\n"
	.string "この ちほうが おまえを まっているぞ。$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "{JPN}いまも れっしゃの こおりは とけている。\p"
	.string "そのまま のぼっていけ。 もし じっかに\n"
	.string "よることが あったら おふくろに\l"
	.string "めしは ちゃんと くっていると つたえてくれ。$"

RustboroCity_Gym_Text_PostBattleNorth:
	.string "{JPN}センネンの きたの せんろは\n"
	.string "もう とおれるはずだ。\p"
	.string "そのまま のぼっていけ。 もし じっかに\n"
	.string "よることが あったら おふくろに\l"
	.string "めしは ちゃんと くっていると つたえてくれ。$"

RustboroCity_Gym_Text_GymStatue:
	.string "{JPN}フロストウッド ポケモンジム$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "{JPN}フロストウッド ポケモンジム\p"
	.string "RedFatalityの こうにんトレーナー:\n"
	.string "{ENG}{PLAYER}{JPN}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "{JPN}… … … … … …\n"
	.string "… … … … … ピッ!\p"
	.string "RedFatality: よう {ENG}{PLAYER}{JPN}!\n"
	.string "フロストウッドの RedFatalityだ。\p"
	.string "すごい いきおいで じゅんいを\n"
	.string "あげているらしいじゃないか。\p"
	.string "また いつでも ちょうせん できるよう\n"
	.string "おれの ジムも きたえておくよ。\p"
	.string "たのしみに しているぞ!\p"
	.string "… … … … … …\n"
	.string "… … … … … ツー!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "{JPN}ジムリーダー RedFatalityを\n"
	.string "ポケナビに とうろくした。$"
