PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "{JPN}パソコンで つかえる\n"
	.string "ポケモン あずかり システム……\p"
	.string "つくった やつは\n"
	.string "すげー かがくに くわしいんだろうな!$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "{JPN}ポケモンに オレンのみを たべさせたら\n"
	.string "HPが かいふく したんだぜ!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "{JPN}ポケモンには いろんな タイプが あるの\p"
	.string "どの タイプにも ほかの タイプに\n"
	.string "たいする とくいと にがてが あるわ\p"
	.string "ポケモンの タイプ しだいで\n"
	.string "しょうぶは らくにも きびしくも なるのよ$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "{JPN}たとえば あなたの キモリは\n"
	.string "くさタイプ\p"
	.string "みずタイプと じめんタイプに\n"
	.string "つよいの\p"
	.string "でも ほのおタイプの ポケモンには\n"
	.string "よわいのよ$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "{JPN}たとえば あなたの アチャモは\n"
	.string "ほのおタイプ\p"
	.string "くさタイプと むしタイプに\n"
	.string "つよいの\p"
	.string "でも みずタイプの ポケモンには\n"
	.string "よわいのよ$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "{JPN}たとえば あなたの ミズゴロウは\n"
	.string "みずタイプ\p"
	.string "ほのおタイプに つよいの\p"
	.string "でも くさタイプと でんきタイプの\n"
	.string "ポケモンには よわいのよ$"

