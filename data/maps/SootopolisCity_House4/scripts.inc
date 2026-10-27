SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "{JPN}よく きけよ いいことを\n"
	.string "おしえてやる。\p"
	.string "この あたりの うみには こだいの\n"
	.string "いせきが あるらしいんだ。\p"
	.string "うみの そこで おたからが\n"
	.string "みつけられるのを まってるかもな。$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "{JPN}こだいの おたから……\p"
	.string "あったら すてき だけど\n"
	.string "なかったとしても ポケモンと\l"
	.string "うみの なかを さんぽ するのは\l"
	.string "きっと とても きれいでしょうね。$"

SootopolisCity_House4_Text_Azumarill:
	.string "{JPN}マリルリ: マルリー。$"

