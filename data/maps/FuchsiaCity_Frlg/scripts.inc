FuchsiaCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0

FuchsiaCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
	call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	famechecker FAMECHECKER_KOGA, 3
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

@ Unused
FuchsiaCity_EventScript_SafariZoneOfficeSign::
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_KOGA, 0
	msgbox FuchsiaCity_Text_GymSign
	releaseall
	end

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_DidYouTrySafariGame::
	.string "{JPN}サファリゲームは やってみた?\p"
	.string "あそこでしか つかまえられない\n"
	.string "めずらしい ポケモンも いるんだよ。$"

FuchsiaCity_Text_SafariZoneZooInFront::
	.string "{JPN}サファリゾーンの いりぐちの まえには\n"
	.string "どうぶつえんが あるんだ。\p"
	.string "おくには ポケモンを つかまえる\n"
	.string "サファリゲームが あるよ。$"

FuchsiaCity_Text_WheresSara::
	.string "{JPN}エリック: サラは どこだ?\n"
	.string "ここで まちあわせ したのに。$"

FuchsiaCity_Text_ItemBallInThere::
	.string "{JPN}あそこの アイテムボール……\n"
	.string "きみも ほしかったの?\p"
	.string "ぼくも!\n"
	.string "……あれ? あれって ポケモン?$"

FuchsiaCity_Text_CitySign::
	.string "{JPN}セキチクシティ\n"
	.string "みよ! これぞ パッション ピンク!$"

FuchsiaCity_Text_SafariZoneSign::
	.string "{JPN}ポケモンの らくえん\n"
	.string "サファリゾーン$"

FuchsiaCity_Text_SafariGameSign::
	.string "{JPN}サファリゲーム\n"
	.string "ポケモン つかまえほうだい!$"

FuchsiaCity_Text_WardensHomeSign::
	.string "{JPN}サファリゾーン\n"
	.string "えんちょうの いえ$"

FuchsiaCity_Text_SafariZoneOfficeSign::
	.string "{JPN}ポケモンの らくえん!\n"
	.string "サファリゾーンへ ようこそ!\l"
	.string "サファリゾーン じむしょ$"

FuchsiaCity_Text_GymSign::
	.string "{JPN}セキチクシティ ポケモンジム\n"
	.string "ジムリーダー キョウ\l"
	.string "どくの にんじゃ マスター$"

FuchsiaCity_Text_ChanseySign::
	.string "{JPN}なまえ: ラッキー\n"
	.string "つかまえられるかは うんしだい。$"

FuchsiaCity_Text_VoltorbSign::
	.string "{JPN}なまえ: ビリリダマ\n"
	.string "モンスターボール そっくりの すがた。$"

FuchsiaCity_Text_KangaskhanSign::
	.string "{JPN}なまえ: ガルーラ\p"
	.string "おなかの ふくろで こどもを\n"
	.string "そだてる ははおやの ポケモン。$"

FuchsiaCity_Text_SlowpokeSign::
	.string "{JPN}なまえ: ヤドン\n"
	.string "ひとなつっこく うごきは とても のろい。$"

FuchsiaCity_Text_LaprasSign::
	.string "{JPN}なまえ: ラプラス\n"
	.string "またの なを うみの おうさま。$"

FuchsiaCity_Text_OmanyteSign::
	.string "{JPN}なまえ: オムナイト\n"
	.string "かせきから よみがえった\l"
	.string "とても めずらしい ポケモン。$"

FuchsiaCity_Text_KabutoSign::
	.string "{JPN}なまえ: カブト\n"
	.string "かせきから よみがえった\l"
	.string "とても めずらしい ポケモン。$"

@ Unused. May have been meant to be the placeholder text for the zoo mons, similar to RB's "!" text
FuchsiaCity_Text_Ellipsis::
	.string "{JPN}……$"

Text_SubstituteTeach::
	.string "{JPN}あーあ ガルーラの あかちゃんに\n"
	.string "なりたいなあ。\p"
	.string "あかちゃんの みがわりに\n"
	.string "なりたいよ……\p"
	.string "そして おかあさん ガルーラの\n"
	.string "おなかの ふくろで ぬくぬく するの。\p"
	.string "でも みがわりの わざは\n"
	.string "ポケモンしか つかえないし……\p"
	.string "きみの ポケモンに みがわりを\n"
	.string "おしえて あげようか?$"

Text_SubstituteDeclined::
	.string "{JPN}え ほんとに?\n"
	.string "みがわり たのしそう なのに……$"

Text_SubstituteWhichMon::
	.string "{JPN}どの ポケモンに\n"
	.string "みがわりを おぼえさせる?$"

Text_SubstituteTaught::
	.string "{JPN}ああ ガルーラの ふくろに\n"
	.string "もぐりこめたら なあ……$"

FuchsiaCity_Text_MyFatherIsGymLeader::
	.string "{JPN}わたしの ちちは この まちの\n"
	.string "ジムリーダー なの。\p"
	.string "わたしも ちちのように どくポケモンを\n"
	.string "つかえるよう しゅぎょう してるの。$"

