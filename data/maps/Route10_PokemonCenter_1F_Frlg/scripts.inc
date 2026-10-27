.equ REQUIRED_OWNED_MONS, 20

Route10_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE10
	end

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_EventScript_Aide::
	lock
	faceplayer
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE, Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone
	msgbox Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_OWNED_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route10_PokemonCenter_1F_Text_GreatHereYouGo
	checkitemspace ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide, ITEM_EVERSTONE
	setflag FLAG_GOT_EVERSTONE_FROM_OAKS_AIDE
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_AlreadyGotEverstone::
	msgbox Route10_PokemonCenter_1F_Text_ExplainEverstone
	release
	end

Route10_PokemonCenter_1F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_OWNED_MONS
	bufferitemname STR_VAR_2, ITEM_EVERSTONE
	return

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
	.string "{JPN}ポケモンの タイプには\n"
	.string "それぞれ あいしょうが あるんだ\p"
	.string "どの タイプも ある タイプには\n"
	.string "つよく ある タイプには よわいのさ$"

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
	.string "{JPN}きんのたまなんて なんの やくにも\n"
	.string "たたないから 5000円で うったよ$"

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
	.string "{JPN}シオンタウンには ゆうれいが\n"
	.string "でるって きいたよ$"

Route10_PokemonCenter_1F_Text_GiveEverstoneIfCaught20Mons::
	.string "{JPN}あっ… {ENG}{PLAYER}{JPN}さん!\n"
	.string "さがしていたんですよ!\p"
	.string "わたしです どこにでも いる\n"
	.string "オーキドはかせの じょしゅです\p"
	.string "ずかんに 20しゅるいの データが\n"
	.string "そろっていたら はかせから\l"
	.string "ごほうびを わたす ことに なってます\p"
	.string "はかせから この かわらずのいしを\n"
	.string "あずかっているんです\p"
	.string "では {ENG}{PLAYER}{JPN}さん おききします\p"
	.string "ポケモンを すくなくとも\n"
	.string "20しゅるい しらべましたか?$"

Route10_PokemonCenter_1F_Text_GreatHereYouGo::
	.string "{JPN}すばらしい! つかまえたり てにいれた\n"
	.string "ポケモンは {ENG}{STR_VAR_3}{JPN}しゅるいですね!\p"
	.string "おめでとう ございます!\n"
	.string "どうぞ!$"

Route10_PokemonCenter_1F_Text_ReceivedEverstoneFromAide::
	.string "{JPN}{ENG}{PLAYER}{JPN}は じょしゅから\n"
	.string "かわらずのいしを もらった!$"

Route10_PokemonCenter_1F_Text_ExplainEverstone::
	.string "{JPN}ポケモンを しんかさせれば たしかに\n"
	.string "ずかんは うまります\p"
	.string "でも ときには ある ポケモンを\n"
	.string "しんか させたくない ことも あるでしょう\p"
	.string "そんな ときは かわらずのいしを\n"
	.string "その ポケモンに もたせて ください\p"
	.string "はかせの おはなしでは しんかを\n"
	.string "ふせいで くれるそうです$"

