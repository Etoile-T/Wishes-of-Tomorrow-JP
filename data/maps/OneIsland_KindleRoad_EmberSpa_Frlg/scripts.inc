OneIsland_KindleRoad_EmberSpa_Frlg_MapScripts::
	.byte 0

OneIsland_KindleRoad_EmberSpa_EventScript_OldMan::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan1::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BaldingMan2::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_OldWoman::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs, MSGBOX_NPC
	end

OneIsland_KindleRoad_EmberSpa_EventScript_BlackBelt::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 3
	msgbox OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_RockSmashMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM06, OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa
	giveitem ITEM_HM06
	setflag FLAG_GOT_HM06
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_AlreadyGotHM06::
	msgbox OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06
	release
	end

OneIsland_KindleRoad_EmberSpa_EventScript_SpaHeal::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed
	setvar VAR_TEMP_1, 1
	releaseall
	end

OneIsland_KindleRoad_EmberSpa_Text_WaterWarmsMeToCore::
	.string "{JPN}ふむ!\n"
	.string "はああああああああああ!\p"
	.string "ああー! ごくらく ごくらく!\n"
	.string "からだの しんまで あったまる!\p"
	.string "きみも はいると いい。\p"
	.string "まんなかに いって のんびりして\n"
	.string "よーく あったまりなさい!$"

OneIsland_KindleRoad_EmberSpa_Text_EnjoyBowlOfChowder::
	.string "{JPN}おふろで いちばん たのしみなのは\n"
	.string "このあと なんだ。\p"
	.string "チャウダーを いっぱい たべて\n"
	.string "からだの なかからも あったまるのさ!$"

OneIsland_KindleRoad_EmberSpa_Text_WaterExquisiteFullyRefreshed::
	.string "{JPN}おゆは ちょうど いい あたたかさ。\n"
	.string "とても きもちいい……\p"
	.string "{ENG}{PLAYER}{JPN}と ポケモンは\n"
	.string "すっかり げんきに なった!$"

OneIsland_KindleRoad_EmberSpa_Text_HotSpringIsTherapeutic::
	.string "{JPN}おんせんに つかると からだに\n"
	.string "いいって みんな いうわね。$"

OneIsland_KindleRoad_EmberSpa_Text_SeeHowSmoothMySkinIs::
	.string "{JPN}わたしの かおを みて。\n"
	.string "おはだ すべすべでしょ?\p"
	.string "おんせんの おかげで おはだが\n"
	.string "としより わかく たもてるの。$"

OneIsland_KindleRoad_EmberSpa_Text_BrunoVisitsSpaOnOccasion::
	.string "{JPN}いちにち まじめに きたえたあとは\n"
	.string "おんせんで のんびり つかるのが\l"
	.string "いちばんだ。\p"
	.string "おれの せんぱいの シバさんも\n"
	.string "ときどき この おんせんに くる。\p"
	.string "じぶんと ポケモンの けがを\n"
	.string "なおしに くるんだ。$"

OneIsland_KindleRoad_EmberSpa_Text_UsedThisToMakeEmberSpa::
	.string "{JPN}おんせんと かざんは\n"
	.string "きっても きれない なかじゃ。\p"
	.string "この ともしびおんせんは のう\n"
	.string "わしが むかし つくったんじゃ。\p"
	.string "でっかい いわを てで けずって\n"
	.string "ゆぶねを ほったんじゃよ。\p"
	.string "そのとき つかったのが これじゃ。\n"
	.string "おまえさんに ゆずっても よかろう。$"

OneIsland_KindleRoad_EmberSpa_Text_ExplainHM06::
	.string "{JPN}それを つかえば いわが まるで\n"
	.string "クラッカーの ように くだけるぞ。$"

