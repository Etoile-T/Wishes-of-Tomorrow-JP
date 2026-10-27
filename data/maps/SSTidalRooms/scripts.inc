SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_COLTON, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_Text_TakeRestOnBed:
	.string "{JPN}ベッドが ある……\n"
	.string "やすんでいこう。$"

SSTidalRooms_Text_ColtonIntro:
	.string "{JPN}ミナモシティには よく いくんだ。\p"
	.string "コンテストの けんがくが\n"
	.string "わたしの たのしみ なんだよ。$"

SSTidalRooms_Text_ColtonDefeat:
	.string "{JPN}たのしい しょうぶ だったよ!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "{JPN}つぎの コンテストには\n"
	.string "どんな ポケモンが でるのか\l"
	.string "そうぞう するだけで ワクワク するよ!$"

SSTidalRooms_Text_MicahIntro:
	.string "{JPN}きみの ともだちは つよいのかね?$"

SSTidalRooms_Text_MicahDefeat:
	.string "{JPN}たしかに つよい ともだち だね。$"

SSTidalRooms_Text_MicahPostBattle:
	.string "{JPN}ともだちは にんげんで なくても いい。\n"
	.string "わたしには ポケモンが だいじな ともだちだ!$"

SSTidalRooms_Text_ThomasIntro:
	.string "{JPN}きみ……\n"
	.string "ノックは したかね?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "{JPN}まけても\n"
	.string "あわてず さわがず。$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "{JPN}どんな ときでも とりみださないのが\n"
	.string "ジェントルマンの たしなみ だよ。$"

SSTidalRooms_Text_JedIntro:
	.string "{JPN}ジェド: ちょっと はずかしいけど……\n"
	.string "ぼくたちの ラブラブ パワー みせてあげる!$"

SSTidalRooms_Text_JedDefeat:
	.string "{JPN}ジェド: はぁ……$"

SSTidalRooms_Text_JedPostBattle:
	.string "{JPN}ジェド: ぼくたちの ラブラブ パワーが\n"
	.string "かてないのは はじめて だよ!\l"
	.string "きみは すごい トレーナー なんだね!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "{JPN}ジェド: ポケモン 1ぴきだけ?\n"
	.string "それって さみしすぎない?$"

SSTidalRooms_Text_LeaIntro:
	.string "{JPN}レア: ちょっと てれくさいけど……\n"
	.string "ふたりの ラブラブ パワー みせてあげる!$"

SSTidalRooms_Text_LeaDefeat:
	.string "{JPN}レア: やん!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "{JPN}レア: しんじられない!\n"
	.string "ふたりの ラブラブ パワーが まけるなんて……\l"
	.string "あなた すごい トレーナー なのね!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "{JPN}レア: しょうぶ したかったのに……\n"
	.string "ポケモン 2ひきも いないのね……$"

SSTidalRooms_Text_GarretIntro:
	.string "{JPN}やあ ちょうど いいところに きたね。\p"
	.string "ボク たいくつ してるんだ。\n"
	.string "ボクを たのしませて くれたまえ。$"

SSTidalRooms_Text_GarretDefeat:
	.string "{JPN}……もう いいよ。$"

SSTidalRooms_Text_GarretPostBattle:
	.string "{JPN}パパに たのんで ボク せんようの\n"
	.string "ヨットを かってもらおうかな。\l"
	.string "ボクと ポケモンの ための ヨット!$"

SSTidalRooms_Text_NaomiIntro:
	.string "{JPN}あら かわいい トレーナーさん。\n"
	.string "おちゃに なさる?\l"
	.string "それとも しょうぶ かしら?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "{JPN}なるほど。\n"
	.string "かっぱつな かた なのね。$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "{JPN}ごうかきゃくせんで せかい いっしゅうも\n"
	.string "たしかに すてき ですけど……\p"
	.string "れんらくせんで ホウエンを めぐるのも\n"
	.string "なかなか よい ものですわね。$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "{JPN}あ…… どうも! あ あやしく ないです!\n"
	.string "こ これ あげます! タダです!\p"
	.string "べ べつに だれかから よこどりした\n"
	.string "ものじゃ ないです! そんなこと しません!\l"
	.string "きれいな ものです! つかって ください!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "{JPN}よこどりは あいてや みかたが\n"
	.string "つかおうとした わざの いいこうかを\l"
	.string "さきに うばって しまう わざです!$"

