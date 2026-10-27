FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "{JPN}なにか おきてるみたいで\n"
	.string "いやな かんじだよ!\p"
	.string "あやしい やつらが ソライシはかせの\n"
	.string "いえに でたり はいったり してたんだ…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "{JPN}ここいら いったいは\n"
	.string "むかしから いんせきが おおくてな\p"
	.string "りゅうせいのたきも いんせきが おちて\n"
	.string "できたとか そう いわれておる$"

FallarborTown_Text_MyPreciousAzurill:
	.string "{JPN}ほら! みてちょうだい!\n"
	.string "わたしの たいせつな ルリリ!\p"
	.string "ツヤツヤの ナデナデの フカフカよ!$"

FallarborTown_Text_Azurill:
	.string "{JPN}ルリリ: るーりーるー$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "{JPN}フエンジムの リーダー アスナには\n"
	.string "もう ちょうせん したかい?\p"
	.string "あのこの おじいさんは ゆうめいでね。\n"
	.string "かつては ポケモンリーグの\l"
	.string "してんのうの ひとりだったんだ。\p"
	.string "アスナが じぶんの ちからで\n"
	.string "すごい トレーナーに なったって\l"
	.string "おどろかないよ。$"

FallarborTown_Text_BattleTentSign:
	.string "{JPN}バトルテント ハジツゲタウン かいじょう\n"
	.string "つどえ! さいきょう チーム$"

FallarborTown_Text_TownSign:
	.string "{JPN}ここは ハジツゲ タウン\n"
	.string "ちいさな はたけが ある のうそん$"

FallarborTown_Text_MoveTutorSign:
	.string "{JPN}「わざおしえマニアの いえ」\n"
	.string "ポケモンに あたらしい わざを おしえます。$"

