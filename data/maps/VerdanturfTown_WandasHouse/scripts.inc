VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "{JPN}ミツル: {ENG}{PLAYER}{JPN}に まけたけど\n"
	.string "ぼくは もう おちこんで いないよ。\p"
	.string "いきる もくひょうが できたんだ。\n"
	.string "ラルトスと いっしょに\l"
	.string "ポケモンジムに ちょうせんして\l"
	.string "すごい トレーナーに なるんだ。\p"
	.string "{ENG}{PLAYER}{JPN} みててね。\n"
	.string "ぼく きみより つよくなるよ。\p"
	.string "そうしたら また きみに\n"
	.string "しょうぶを もうしこむからね。$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "{JPN}ミツル: {ENG}{PLAYER}{JPN} みててね。\n"
	.string "ぼく きみより つよくなるよ。\p"
	.string "そうしたら また きみに\n"
	.string "しょうぶを もうしこむからね。$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "{JPN}おじさん: おお {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}!\n"
	.string "ミツルなら となりの へやだよ。\p"
	.string "ところで きみに\n"
	.string "つたえたい ことが あるんだ。\p"
	.string "ここの しぜんの おかげで ミツルが\n"
	.string "ずいぶん げんきに なってね。\p"
	.string "でも しぜんだけじゃ ないのかもね。\n"
	.string "ポケモンが ミツルに きぼうを\l"
	.string "あたえて くれているのかも しれない。$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "{JPN}ミツルくんが でていっちゃった…\n"
	.string "ひとりで こっそり…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "{JPN}おじさん: そうかい?\n"
	.string "ミツルは そんな とおくまで\l"
	.string "ひとりで いったのか…\p"
	.string "たいした ものだ。\n"
	.string "さすが わたしの おとうとの むすこだよ。$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "{JPN}ミチル: あなたは?\n"
	.string "ああ そうなの! わかったわ!\p"
	.string "あなたが {ENG}{PLAYER}{JPN}さんね。\n"
	.string "ミツルくんから はなしを きいてるわ。\p"
	.string "わたしは ミツルくんの いとこなの。\n"
	.string "よろしくね!\p"
	.string "ミツルくんは ここに きてから ずっと\n"
	.string "げんきで あかるく なったと おもうわ。$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "{JPN}ミチル: ミツルくんの ことなら\n"
	.string "だいじょうぶ! しんぱい ないわよ!\p"
	.string "いとこの あのこなら よく しってるし\n"
	.string "ポケモンも いっしょ ですもの。$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "{JPN}きみの おかげで\n"
	.string "まいにち かのじょに あえて\l"
	.string "ハッピーかって? もちろんさ!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "{JPN}うちの むすめの こいびとは\n"
	.string "いちずで じょうねつてきな ひとでね。\p"
	.string "むすめに あうため だけに\n"
	.string "やすまず トンネルを ほっているんだよ。\p"
	.string "むすめも すこし しんぱい していて\n"
	.string "よく トンネルへ いくんだよ。$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "{JPN}なんと! むすめの こいびと ときたら\n"
	.string "てで トンネルを ほっていたんだよ!\p"
	.string "そりゃあ たまげた もんだ!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "{JPN}ミツルくんに もしものことが あったら\n"
	.string "あたしゃ トウカにいる ごりょうしんに\l"
	.string "あわせる かおが ないよ……$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "{JPN}ミツルくんが サイユウに いたって!?\p"
	.string "そりゃ トウカの ごりょうしんも\n"
	.string "びっくり するだろうねぇ$"

