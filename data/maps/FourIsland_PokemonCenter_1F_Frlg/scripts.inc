FourIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FourIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FOUR_ISLAND
	end

FourIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FourIsland_PokemonCenter_1F_EventScript_Man::
	msgbox FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Woman::
	msgbox FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore, MSGBOX_NPC
	end

FourIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived, MSGBOX_NPC
	end

@ The 5 texts below are supposed to be in FourIsland_House1
Text_BodySlamTeach::
	.string "{JPN}いくぞ!\n"
	.string "ぼよーん!\p"
	.string "どっちが さきに ネをあげるか\n"
	.string "のしかかり しょうぶ してるんだ。\p"
	.string "きみが まざったら むしみたいに\n"
	.string "ぺしゃんこに なっちゃうけどね……\p"
	.string "かわりに きみの ポケモンに\n"
	.string "のしかかりを おしえて あげようか?$"

Text_BodySlamDeclined::
	.string "{JPN}また きてね!\n"
	.string "ぼよーん!$"

Text_BodySlamWhichMon::
	.string "{JPN}どの ポケモンに\n"
	.string "のしかかりを おぼえさせる?$"

Text_BodySlamTaught::
	.string "{JPN}ぼよよーん!$"

FourIsland_House1_Text_FatMan::
	.string "{JPN}それ ぼよーん!\n"
	.string "おまえ おもいなあー!$"

FourIsland_PokemonCenter_1F_Text_RareIceMonsInCave::
	.string "{JPN}この どうくつには めずらしい\n"
	.string "こおりタイプの ポケモンが いるんだ。\p"
	.string "その ポケモンを みたくて\n"
	.string "たくさんの ひとが やってくるよ。$"

FourIsland_PokemonCenter_1F_Text_DayCarePeopleFoundEggBefore::
	.string "{JPN}え? ポケモンの タマゴ?\n"
	.string "……さあ わからないな。\p"
	.string "……あ まてよ。 まちの そだてやの\n"
	.string "ひとたちが なにか いってたな。\p"
	.string "まえにも しきちで タマゴを\n"
	.string "みつけた ことが あるって。$"

FourIsland_PokemonCenter_1F_Text_NewPokemonJournalHasntArrived::
	.string "{JPN}なんだって?\p"
	.string "この しまには ポケモンジャーナルの\n"
	.string "さいしんごうが まだ とどいてない?$"

