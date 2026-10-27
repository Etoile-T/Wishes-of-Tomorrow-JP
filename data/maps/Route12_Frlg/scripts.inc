Route12_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	end

Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_MonSprawledOutInSlumber::
	.string "{JPN}ポケモンが ねそべって\n"
	.string "きもちよさそうに ぐっすり ねている$"

Text_SnorlaxWokeUp::
	.string "{JPN}カビゴンが めを さました!\p"
	.string "ねおきが わるくて おそってきた!$"

Text_SnorlaxReturnedToMountains::
	.string "{JPN}カビゴンは おとなしくなった\n"
	.string "おおきな あくびを して…\l"
	.string "やまへ かえって いった$"

Text_WantToUsePokeFlute::
	.string "{JPN}ポケモンのふえを つかいますか?$"

Text_PlayedPokeFlute::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ポケモンのふえを ふいた$"

Route12_Text_NedIntro::
	.string "{JPN}よし!\n"
	.string "あたりが きたぞ!$"

Route12_Text_NedDefeat::
	.string "{JPN}ちぇっ!\n"
	.string "ざこか…$"

Route12_Text_NedPostBattle::
	.string "{JPN}まってくれ!\n"
	.string "いとが ひっかかった!$"

Route12_Text_ChipIntro::
	.string "{JPN}あせるな\n"
	.string "つりは まつのが しょうぶさ$"

Route12_Text_ChipDefeat::
	.string "{JPN}にげられた!$"

Route12_Text_ChipPostBattle::
	.string "{JPN}もっと いい つりざおなら\n"
	.string "いい ポケモンが つれるのに…$"

Route12_Text_JustinIntro::
	.string "{JPN}つきのいしを さがしてるんだ\n"
	.string "みつけた こと ある?$"

Route12_Text_JustinDefeat::
	.string "{JPN}いてっ!$"

Route12_Text_JustinPostBattle::
	.string "{JPN}つきのいしが あれば ぼくの\n"
	.string "ポケモンを しんか させられたのに\p"
	.string "そしたら きっと かってたよ$"

Route12_Text_LucaIntro::
	.string "{JPN}でんきは おれの せんもんだ\p"
	.string "でも うみの ポケモンの ことは\n"
	.string "なにも しらないんだ$"

Route12_Text_LucaDefeat::
	.string "{JPN}でんげん ぬけた!$"

Route12_Text_LucaPostBattle::
	.string "{JPN}みずは でんきを とおすから うみの\n"
	.string "ポケモンには でんきで せめろよ$"

Route12_Text_HankIntro::
	.string "{JPN}つりバカ たい ポケモン\n"
	.string "こぞう!$"

Route12_Text_HankDefeat::
	.string "{JPN}さわりすぎた!$"

Route12_Text_HankPostBattle::
	.string "{JPN}すきこそ ものの\n"
	.string "じょうずなれ だな\p"
	.string "ポケモンでは まけたが\n"
	.string "つりでは まけないぞ$"

Route12_Text_ElliotIntro::
	.string "{JPN}つりは だいすきだ ごかいするなよ\p"
	.string "でも もうすこし しごとも あれば\n"
	.string "いいんだがな$"

Route12_Text_ElliotDefeat::
	.string "{JPN}らくじゃ ないな…$"

Route12_Text_ElliotPostBattle::
	.string "{JPN}いいんだ\n"
	.string "もう まけても きに ならない$"

Route12_Text_AndrewIntro::
	.string "{JPN}なにが つれるかな?\p"
	.string "なにが つれるかは\n"
	.string "わからないぞ!$"

Route12_Text_AndrewDefeat::
	.string "{JPN}にがした!$"

Route12_Text_AndrewPostBattle::
	.string "{JPN}なに コイキング?\p"
	.string "ああ しょっちゅう つれるよ\n"
	.string "でも ほんとに よわっちいんだよな$"

Route12_Text_RouteSign::
	.string "{JPN}12ばんどうろ \n"
	.string "きた シオンタウン$"

Route12_Text_SportfishingArea::
	.string "{JPN}つりの めいしょ$"

Route12_Text_JesIntro::
	.string "{JPN}ジェス: かったら ジアに\n"
	.string "プロポーズ するんだ$"

Route12_Text_JesDefeat::
	.string "{JPN}ジェス: ああ どうして かたせて\n"
	.string "くれなかったんだ?$"

Route12_Text_JesPostBattle::
	.string "{JPN}ジェス: ああ ジア ゆるしてくれ\n"
	.string "あいする きみよ!$"

Route12_Text_JesNotEnoughMons::
	.string "{JPN}ジェス: ジアと ぼくは\n"
	.string "ずっと いっしょなんだ\p"
	.string "きみが ポケモンを 2ひき もってないと\n"
	.string "しょうぶ しないよ$"

Route12_Text_GiaIntro::
	.string "{JPN}ジア: ねえ ジェス…\p"
	.string "かったら けっこん してあげる!$"

Route12_Text_GiaDefeat::
	.string "{JPN}ジア: そんな どうして?$"

Route12_Text_GiaPostBattle::
	.string "{JPN}ジア: ジェスの ばか!\n"
	.string "だいなしじゃない!$"

Route12_Text_GiaNotEnoughMons::
	.string "{JPN}ジア: ジェスが いないと\n"
	.string "たたかえないわ!\p"
	.string "ポケモン もう 1ぴき いないの?$"
