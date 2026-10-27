MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "{JPN}かわいかった エネコとの おもいで……\n"
	.string "おもいだすだけで なみだが あふれる……$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "{JPN}いたた…… ここ あちこちに\n"
	.string "あなが あいてるんだ\p"
	.string "きづかずに うえの かいから\n"
	.string "おっこちちゃった$"

MtPyre_2F_Text_MarkIntro:
	.string "{JPN}おい! おまえも ポケモン さがしか?\n"
	.string "あとから きた くせに なまいきだ!$"

MtPyre_2F_Text_MarkDefeat:
	.string "{JPN}ふええええええっ!\n"
	.string "ごめんなさい ゆるして くださいーっ!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "{JPN}めったに ひとが こない ところ だから\n"
	.string "めずらしい ポケモンが いると おもってさ$"

MtPyre_2F_Text_LukeIntro:
	.string "{JPN}ルーク: きもだめしに きてるんだ\p"
	.string "へへっ かっこいい ところを みせたら\n"
	.string "かのじょ ぼくに メロメロ だよ!\p"
	.string "そうだ! きみを やっつけて\n"
	.string "かっこいい ところを みせよう!$"

MtPyre_2F_Text_LukeDefeat:
	.string "{JPN}ルーク: あっちゃー!$"

MtPyre_2F_Text_LukePostBattle:
	.string "{JPN}ルーク: まけちゃったけど だいじょうぶ!\n"
	.string "ぼくが そばに いるからさ\l"
	.string "きもだめし なんて へっちゃら だよ!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "{JPN}ルーク: ぼくと しょうぶ するなら\n"
	.string "もっと ポケモン つれてきなよ!\p"
	.string "そうでないと かのじょの まえで\n"
	.string "いいところ みせられない じゃないか!$"

MtPyre_2F_Text_DezIntro:
	.string "{JPN}デズ: かれしと いっしょに\n"
	.string "きもだめしに きたの\p"
	.string "すっごく こわいけど かれしが いるから\n"
	.string "へいきなの\p"
	.string "そうだ! あなたに かって\n"
	.string "かれしを かっこよく みせちゃお!$"

MtPyre_2F_Text_DezDefeat:
	.string "{JPN}デズ: あーん こわーい!$"

MtPyre_2F_Text_DezPostBattle:
	.string "{JPN}デズ: あたしたち ラブラブだから\n"
	.string "まけても へいき なんだもん!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "{JPN}デズ: あたしたちと たたかいたいなら\n"
	.string "せめて 2ひきは ポケモン いないと\p"
	.string "あたしの かれし つよいんだから\n"
	.string "いっぴきじゃ はなしに ならないわ$"

MtPyre_2F_Text_LeahIntro:
	.string "{JPN}みかけぬ かおね……\n"
	.string "なにも おきない うちに かえりなさい!$"

MtPyre_2F_Text_LeahDefeat:
	.string "{JPN}ふむ……\n"
	.string "しぶといわね$"

MtPyre_2F_Text_LeahPostBattle:
	.string "{JPN}わたしの いえは ひいおばあさまの\n"
	.string "ころから ここの トレーナーなの……\p"
	.string "この やまを まもるのが\n"
	.string "わたしの つとめ……$"

MtPyre_2F_Text_ZanderIntro:
	.string "{JPN}ぎっ ぎゃああああっ!\n"
	.string "こわいよおおおっ!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "{JPN}いやだああああ!\n"
	.string "あたまが まっしろだ!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "{JPN}なにかが うごくのを みるたびに\n"
	.string "びびっちゃうんだ……\p"
	.string "ここで しゅぎょう なんて しなきゃ よかった……$"

