MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature::
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman::
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon:
	.string "{JPN}ムムムッ!\n"
	.string "きみの {ENG}{STR_VAR_1}{JPN}……$"

MossdeepCity_House1_Text_ItLikesXPokeblocks:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN}が すき\n"
	.string "なんじゃ ないかね?\p"
	.string "いや まちがいない! ぜったいに\n"
	.string "{ENG}{STR_VAR_1}{JPN}が すきだ!$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks:
	.string "{JPN}とくに すきな {ENG}{POKEBLOCK}{JPN}も\n"
	.string "きらいな {ENG}{POKEBLOCK}{JPN}も ない みたいだ。$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes:
	.string "{JPN}だんなったら みただけで ポケモンが\n"
	.string "すきな {ENG}{POKEBLOCK}{JPN}が わかるのよ。$"

