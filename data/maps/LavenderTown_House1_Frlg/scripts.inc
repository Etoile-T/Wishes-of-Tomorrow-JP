LavenderTown_House1_Frlg_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
	.string "{JPN}カラカラ: キャルゴー!$"

LavenderTown_House1_Text_RocketsKilledCubonesMother::
	.string "{JPN}あの ひどい ロケットだん!\n"
	.string "ゆるせないわ!\p"
	.string "かわいそうな カラカラの おかあさん……\p"
	.string "ロケットだんから にげようとして\n"
	.string "ころされて しまったの。$"

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
	.string "{JPN}ポケモンタワーの ゆうれいが\n"
	.string "いなくなった!\p"
	.string "だれかが さまよう たましいを\n"
	.string "しずめて くれたのね!$"

