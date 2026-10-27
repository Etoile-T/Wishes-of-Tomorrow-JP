RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "{JPN}わしの ポケモンは むじゃき で\n"
	.string "ともだちの ポケモンは ようき なんだよ\p"
	.string "ポケモンにも せいかくが ある というのは\n"
	.string "なかなか おもしろい もんだねー!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "{JPN}ひとと おなじように ポケモンにも\n"
	.string "オスと メスが いるのよ\p"
	.string "でも どう ちがうのかは\n"
	.string "だれにも わからない みたい$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "{JPN}となりの おじさんが ひでんマシンを くれたんだ!\p"
	.string "それで ポケモンに ほそい きを\n"
	.string "いあいぎりで きる わざを おぼえさせたよ$"

