SixIsland_PatternBush_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PatternBush_OnTransition
	.byte 0

SixIsland_PatternBush_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, SixIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, SixIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

SixIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 64, 10
	return

SixIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 45, 10
	return

SixIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, SixIsland_PatternBush_Text_BethanyIntro, SixIsland_PatternBush_Text_BethanyDefeat
	msgbox SixIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, SixIsland_PatternBush_Text_AllisonIntro, SixIsland_PatternBush_Text_AllisonDefeat
	msgbox SixIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, SixIsland_PatternBush_Text_GarretIntro, SixIsland_PatternBush_Text_GarretDefeat
	msgbox SixIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, SixIsland_PatternBush_Text_JonahIntro, SixIsland_PatternBush_Text_JonahDefeat
	msgbox SixIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, SixIsland_PatternBush_Text_VanceIntro, SixIsland_PatternBush_Text_VanceDefeat
	msgbox SixIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, SixIsland_PatternBush_Text_NashIntro, SixIsland_PatternBush_Text_NashDefeat
	msgbox SixIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, SixIsland_PatternBush_Text_CordellIntro, SixIsland_PatternBush_Text_CordellDefeat
	msgbox SixIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, SixIsland_PatternBush_Text_DaliaIntro, SixIsland_PatternBush_Text_DaliaDefeat
	msgbox SixIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, SixIsland_PatternBush_Text_JoanaIntro, SixIsland_PatternBush_Text_JoanaDefeat
	msgbox SixIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, SixIsland_PatternBush_Text_RileyIntro, SixIsland_PatternBush_Text_RileyDefeat
	msgbox SixIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, SixIsland_PatternBush_Text_MarcyIntro, SixIsland_PatternBush_Text_MarcyDefeat
	msgbox SixIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, SixIsland_PatternBush_Text_LaytonIntro, SixIsland_PatternBush_Text_LaytonDefeat
	msgbox SixIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_Text_BethanyIntro::
	.string "{JPN}ねえ あなたは どうやって\n"
	.string "ポケモンを そだててるの?$"

SixIsland_PatternBush_Text_BethanyDefeat::
	.string "{JPN}あなたは ポケモンを\n"
	.string "あいじょう たっぷりに そだててるのね!$"

SixIsland_PatternBush_Text_BethanyPostBattle::
	.string "{JPN}おかあさんが あなたを あいじょう\n"
	.string "たっぷりに そだてたように\l"
	.string "ポケモンも そだてて あげてね$"

SixIsland_PatternBush_Text_AllisonIntro::
	.string "{JPN}わたしは ここの ポケモンの\n"
	.string "しぜんの せいたいを まもってるの$"

SixIsland_PatternBush_Text_AllisonDefeat::
	.string "{JPN}まあ わかいのに\n"
	.string "たいしたものね!$"

SixIsland_PatternBush_Text_AllisonPostBattle::
	.string "{JPN}ポケモンを つかまえるなって\n"
	.string "いってるんじゃ ないのよ\p"
	.string "せきにんを もって ポケモンを\n"
	.string "そだててほしいだけなの$"

SixIsland_PatternBush_Text_GarretIntro::
	.string "{JPN}この あたりにしか いない\n"
	.string "むしポケモンを つかまえたんだ!$"

SixIsland_PatternBush_Text_GarretDefeat::
	.string "{JPN}へへへ…\n"
	.string "ぼくの ポケモン すごいでしょ?$"

SixIsland_PatternBush_Text_GarretPostBattle::
	.string "{JPN}しげみの ちかくに トレーナーの\n"
	.string "ヘラクロスを はかる おんなのこが いるよ$"

SixIsland_PatternBush_Text_JonahIntro::
	.string "{JPN}やっぱり むしポケモンを\n"
	.string "つかわないと しっくり こないんだ$"

SixIsland_PatternBush_Text_JonahDefeat::
	.string "{JPN}いいんだ まけるのも ポケモンの\n"
	.string "みりょくの ひとつ だからね$"

SixIsland_PatternBush_Text_JonahPostBattle::
	.string "{JPN}ところで 「みりょく」って\n"
	.string "かんがえると へんな ことばだよね\p"
	.string "「みりょく」の 「み」は みかんの み?\n"
	.string "それとも ミルクの み?$"

SixIsland_PatternBush_Text_VanceIntro::
	.string "{JPN}やった やった やったー!\n"
	.string "むしポケモンが いっぱいだ!$"

SixIsland_PatternBush_Text_VanceDefeat::
	.string "{JPN}よろこんでる さいちゅうに\n"
	.string "まけちゃった!$"

SixIsland_PatternBush_Text_VancePostBattle::
	.string "{JPN}こんどは おとうとを ここに\n"
	.string "つれてくるんだ$"

SixIsland_PatternBush_Text_NashIntro::
	.string "{JPN}みて みて! じめんに\n"
	.string "へんな もようが あるよ$"

SixIsland_PatternBush_Text_NashDefeat::
	.string "{JPN}すっごーい!$"

SixIsland_PatternBush_Text_NashPostBattle::
	.string "{JPN}じめんの へんな もよう…\p"
	.string "おじいちゃんの ふくの もように\n"
	.string "にてるんだ$"

SixIsland_PatternBush_Text_CordellIntro::
	.string "{JPN}おれのこと ただの おっさんだと\n"
	.string "おもってんだろ? ええ?$"

SixIsland_PatternBush_Text_CordellDefeat::
	.string "{JPN}おれのこと よわいと\n"
	.string "おもってんだろ? ええ?$"

SixIsland_PatternBush_Text_CordellPostBattle::
	.string "{JPN}まったく まちの もんは そんな\n"
	.string "はでな ぼうし かぶって めかしこんで…\p"
	.string "それ おれに くれねえか?$"

SixIsland_PatternBush_Text_DaliaIntro::
	.string "{JPN}おおきく いきを すって\n"
	.string "くうきが おいしいでしょ?$"

SixIsland_PatternBush_Text_DaliaDefeat::
	.string "{JPN}よかったら ただしい こきゅうの\n"
	.string "しかたを おしえて あげるわ$"

SixIsland_PatternBush_Text_DaliaPostBattle::
	.string "{JPN}まず いきを はいて\n"
	.string "ぜんぶ はききるの\p"
	.string "もう はけなくなったら\n"
	.string "きれいな くうきを すいこむ!\p"
	.string "すっきり するでしょ?$"

SixIsland_PatternBush_Text_JoanaIntro::
	.string "{JPN}むしポケモンが だいすきなの\n"
	.string "だから いつも ここに いるのよ\p"
	.string "こんな おんなのこって わたしだけ?$"

SixIsland_PatternBush_Text_JoanaDefeat::
	.string "{JPN}まけたけど まだ わらってる\n"
	.string "こんな おんなのこって わたしだけ?$"

SixIsland_PatternBush_Text_JoanaPostBattle::
	.string "{JPN}これからも むしポケモンを\n"
	.string "あつめつづけるわ\p"
	.string "こんな おんなのこって わたしだけ?$"

SixIsland_PatternBush_Text_RileyIntro::
	.string "{JPN}ここは いい ばしょだ\n"
	.string "ここに テントを はろう$"

SixIsland_PatternBush_Text_RileyDefeat::
	.string "{JPN}へこたれた…$"

SixIsland_PatternBush_Text_RileyPostBattle::
	.string "{JPN}ここで よるの そらを\n"
	.string "かんさつ するんだ$"

SixIsland_PatternBush_Text_MarcyIntro::
	.string "{JPN}うわっ やだ!\n"
	.string "むしに さされたみたい!$"

SixIsland_PatternBush_Text_MarcyDefeat::
	.string "{JPN}むしじゃ なかった\n"
	.string "くさで すねを きっただけ$"

SixIsland_PatternBush_Text_MarcyPostBattle::
	.string "{JPN}これくらいの きずなら…\n"
	.string "つばでも つけとけば なおるわ!$"

SixIsland_PatternBush_Text_LaytonIntro::
	.string "{JPN}この あたりで なにか へんな ことに\n"
	.string "きづかなかったかい?$"

SixIsland_PatternBush_Text_LaytonDefeat::
	.string "{JPN}じぶんの あしもとを よーく\n"
	.string "みてみたかい?$"

SixIsland_PatternBush_Text_LaytonPostBattle::
	.string "{JPN}ここ もようのしげみには\n"
	.string "くさが はえない ばしょが あるんだ\p"
	.string "いったい なにが げんいんで\n"
	.string "そんな ことが おきるんだろう?$"

