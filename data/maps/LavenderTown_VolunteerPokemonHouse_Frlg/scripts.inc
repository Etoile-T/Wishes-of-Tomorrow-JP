LavenderTown_VolunteerPokemonHouse_Frlg_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	setflag FLAG_GOT_POKE_FLUTE
	giveitem_msg LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji, ITEM_POKE_FLUTE, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_MRFUJI, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	lockall
	famechecker FAMECHECKER_MRFUJI, 2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped
	releaseall
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
	.string "{JPN}さいきん この まちに ひっこして きたの。\p"
	.string "フジろうじんも もともとは\n"
	.string "この あたりの ひとじゃ ないらしいわ。$"

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
	.string "{JPN}あれ? フジろうじんが いない。\n"
	.string "どこへ いったんだろう?$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
	.string "{JPN}フジろうじんは カラカラの おかあさんの\n"
	.string "ために ひとりで いのって いたんだ。$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
	.string "{JPN}ここは フジろうじんの いえなの。\p"
	.string "とても やさしい ひとなのよ。\p"
	.string "すてられたり おやを なくしたりした\n"
	.string "ポケモンの せわを してるの。$"

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
	.string "{JPN}あったかーい!\n"
	.string "ポケモンって だっこすると きもちいい。$"

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
	.string "{JPN}ニドリーノ: ギャオー!$"

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
	.string "{JPN}コダック: グワッパ!$"

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
	.string "{JPN}フジろうじん: {ENG}{PLAYER}{JPN}……\p"
	.string "ポケモンずかんを かんせい させるには\n"
	.string "つよい いしが ひつようじゃ。\p"
	.string "ポケモンへの ふかい あいじょうが\n"
	.string "なければ きっと うまくいかん。\p"
	.string "やくに たつか わからんが\n"
	.string "これを うけとって ほしい。$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
	.string "{JPN}{ENG}{PLAYER}{JPN}は フジろうじんから\n"
	.string "ポケモンのふえを もらった!$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
	.string "{JPN}ポケモンのふえを きけば\n"
	.string "ねむっている ポケモンも とびおきる。\p"
	.string "みちを ふさいで ねている ポケモンに\n"
	.string "つかって みなさい。$"

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
	.string "{JPN}にもつを あけて おきなさい!$"

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
	.string "{JPN}フジろうじん: ポケモンのふえは\n"
	.string "やくに たって おるかね?$"

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
	.string "{JPN}ポケモン ファン マガジン\n"
	.string "まいつき だいプレゼント ちゅうせんかい!\p"
	.string "おうぼようしは……\p"
	.string "ない! きりとられている。\n"
	.string "だれかが もう おうぼ したらしい。$"

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
	.string "{JPN}たなに ポケモンの ざっしが ならんでいる。\p"
	.string "ポケモン インサイダー……\p"
	.string "ポケモン ファン……$"

