IndigoPlateau_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckBlockDoor::
	goto_if_set FLAG_IS_CHAMPION, Common_EventScript_NopReturn
	setobjectxyperm LOCALID_LEAGUE_DOOR_GUARD, 4, 2
	return

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
	lock
	faceplayer
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_CheckSeviiIslandComplete::
	goto_if_set FLAG_IS_CHAMPION, IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete
	msgbox IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SeviiIslandComplete::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
	.string "{JPN}よう!\n"
	.string "みらいの チャンピオン!\p"
	.string "ポケモンリーグでは してんのうと\n"
	.string "つづけて たたかうことに なる。\p"
	.string "まけたら また さいしょから\n"
	.string "やりなおし なんだ!\p"
	.string "いよいよだな!\n"
	.string "がんばれよ!$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck::
	.string "{JPN}ここから さきは してんのうと\n"
	.string "ひとりずつ たたかって いただきます。\p"
	.string "かてば つぎの トレーナーへの\n"
	.string "とびらが ひらきます。 ごぶうんを!$"

IndigoPlateau_PokemonCenter_1F_Text_LoreleiIsAbsentClosedForTimeBeing::
	.string "{JPN}たいへん もうしわけ ありませんが\n"
	.string "せっかく きていただいたのに……\p"
	.string "じつは してんのうの カンナが\n"
	.string "ふざい なのです。\p"
	.string "そのため ポケモンリーグは\n"
	.string "とうぶんの あいだ おやすみです。$"

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
	.string "{JPN}キクコの ゴーストタイプ ポケモンは\n"
	.string "おそろしいほど てごわいんだ。\p"
	.string "おれは かくとうタイプの ポケモンを\n"
	.string "とことん きたえあげた。\p"
	.string "じしんまんまんで キクコに いどんだら\n"
	.string "こてんぱんに やられたよ。\p"
	.string "あの ばあさんは おまけに\n"
	.string "すごく おこりっぽいんだ。\p"
	.string "ちょっとした ことで\n"
	.string "あの こわい ばあさんは どなりだすぜ。$"

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
	.string "{JPN}してんのうに なれるかは\n"
	.string "ちすじ なのかもな。\p"
	.string "きいた はなしじゃ ワタルには\n"
	.string "ジムリーダーを してる いとこが\l"
	.string "どこか とおくに いるらしい。$"

