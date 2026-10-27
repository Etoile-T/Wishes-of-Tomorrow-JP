BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	chooseboxmon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "{JPN}わしは 70ねん ポケモンを そだててきた!\n"
	.string "みなに あがめられる\l"
	.string "でんせつの トップ ポケモンブリーダー じゃ!\p"
	.string "わしほど けいけんを つめば\n"
	.string "ポケモンの のうりょくなど\l"
	.string "ひとめで わかる ように なるぞ。\p"
	.string "おまえさんも トレーナーじゃろう。\n"
	.string "じぶんの ポケモンの のうりょくに\l"
	.string "きょうみは ないかね?\p"
	.string "ほれ!\n"
	.string "おまえさんの ポケモンを みせてみい!$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "{JPN}…… んー\p"
	.string "こいつは ぜんたいてきに いうと\n"
	.string "へいきんてきな のうりょく じゃな。$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "{JPN}…… んー\p"
	.string "こいつは ぜんたいてきに いうと\n"
	.string "へいきんいじょうの のうりょく じゃな。$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "{JPN}…… んー\p"
	.string "こいつは ぜんたいてきに いうと\n"
	.string "なかなかの のうりょく じゃな!$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "{JPN}…… んー\p"
	.string "こいつは ぜんたいてきに いうと\n"
	.string "すばらしい のうりょく じゃな!$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "{JPN}ちなみに いちばん いいかんじ なのは\n"
	.string "HP かの……$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "{JPN}ちなみに いちばん いいかんじ なのは\n"
	.string "こうげき かの……$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "{JPN}ちなみに いちばん いいかんじ なのは\n"
	.string "ぼうぎょ かの……$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "{JPN}ちなみに いちばん いいかんじ なのは\n"
	.string "とくこう かの……$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "{JPN}ちなみに いちばん いいかんじ なのは\n"
	.string "とくぼう かの……$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "{JPN}ちなみに いちばん いいかんじ なのは\n"
	.string "すばやさ かの……$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "{JPN}まあまあの のうりょくを もっとるぞ……\n"
	.string "……ふむ…… そんな かんじ かのう!$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "{JPN}かなりの ちからを もっとるな!\n"
	.string "……ふむ…… そんな かんじ かのう!$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "{JPN}すばらしい ちからを もっとる!\n"
	.string "……ふむ…… そんな かんじ かのう!$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "{JPN}ばっちりっ! ぱーふぇくと じゃ!\n"
	.string "……ふむ…… そんな かんじ かのう!$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "{JPN}なんじゃい!\n"
	.string "わしの あどばいすは いらんと いうのか!\p"
	.string "じんせいの せんぱいの おしえは\n"
	.string "だまって きく もんじゃぞ!!$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "{JPN}なんじゃー?\p"
	.string "わしも いろいろ いそがしい からのう!\n"
	.string "また こんどに せい!$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "{JPN}おお! わかいの!\n"
	.string "ポケモンの のうりょくが きになるんか?\p"
	.string "ほれほれ!\n"
	.string "わしに ポケモンを みせて みい!$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "{JPN}わしほどの めききでも うまれる まえの\n"
	.string "ポケモンの ことは わからんわい!\p"
	.string "ポケモンを みせて くれ!\n"
	.string "わしが みたいのは ポケモンじゃ!$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "{JPN}ぼくの ポケモン すばらしいって!\n"
	.string "だいじに そだてて きてよかった!$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "{JPN}ポケモン すばらしいって いわれた!\n"
	.string "でも そだてるとき とくべつなことは\l"
	.string "なにも してないん だけど……$"

