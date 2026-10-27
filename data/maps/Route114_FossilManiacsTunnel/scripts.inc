Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "{JPN}ぼく カセキマニア……\n"
	.string "カセキ だいすき ナイスガイ さ……\p"
	.string "きみも カセキが ほしいの?\p"
	.string "でも この あたりの カセキは\n"
	.string "ぜんぶ ぼくの もの…… あげないよ……\p"
	.string "どうしても カセキが\n"
	.string "ほしいなら カセキが うまってそうな\l"
	.string "いわや すなの ある さばくでも\l"
	.string "さがして みなよ……$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "{JPN}カセキを みつけたんだね?\n"
	.string "いいなあ…… うっとり しちゃう……\p"
	.string "その カセキ\n"
	.string "どうするの?\p"
	.string "きいた はなしだと デボンが\n"
	.string "カセキから ポケモンを ふっかつさせる\l"
	.string "けんきゅうを しているんだって……\p"
	.string "ぼくは カセキが すきだから\n"
	.string "そんなこと ぜったい しないけど……$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "{JPN}カセキって…… すてき……\n"
	.string "うっとり しちゃうよ……$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "{JPN}あ……\n"
	.string "そっちは あぶないよ……\p"
	.string "ぼくが ほりすすめて いたら……\n"
	.string "かべが まるごと くずれて……\p"
	.string "いまは したに おおきな どうくつが\n"
	.string "あるみたい……\p"
	.string "でも カセキは なさそうだから\n"
	.string "ほうって あるんだ……$"

