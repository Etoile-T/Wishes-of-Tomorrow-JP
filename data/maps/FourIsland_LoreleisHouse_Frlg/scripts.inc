FourIsland_LoreleisHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_LoreleisHouse_OnTransition
	.byte 0

FourIsland_LoreleisHouse_OnTransition::
	special UpdateLoreleiDollCollection
	end

FourIsland_LoreleisHouse_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei3
	goto_if_set FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE, FourIsland_LoreleisHouse_EventScript_Lorelei2
	msgbox FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei2::
	setflag FLAG_TALKED_TO_LORELEI_AFTER_WAREHOUSE
	msgbox FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile
	release
	end

FourIsland_LoreleisHouse_EventScript_Lorelei3::
	msgbox FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow
	release
	end

FourIsland_LoreleisHouse_EventScript_Doll::
	lock
	msgbox FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore
	release
	end

FourIsland_LoreleisHouse_Text_IfAnythingWereToHappenToIsland::
	.string "{JPN}カンナ: ずっと こころに\n"
	.string "ひっかかって いることが あるの。\p"
	.string "もし わたしの うまれた しまで\n"
	.string "なにか おきたとしても……\p"
	.string "ポケモンリーグに いたら\n"
	.string "きっと きづけないわ。\p"
	.string "それって ふるさとに たいして\n"
	.string "むせきにん なのかしら……$"

FourIsland_LoreleisHouse_Text_IllReturnToLeagueInShortWhile::
	.string "{JPN}カンナ: それじゃ ここの もんだいは\n"
	.string "ぜんぶ かいけつ したのね?\p"
	.string "すばらしいわ。\p"
	.string "それなら わたしが ずっと ここに\n"
	.string "いる りゆうも なくなったわね。\p"
	.string "ありがとう……\p"
	.string "わたしは もうすこししたら\n"
	.string "ポケモンリーグに もどるわ。$"

FourIsland_LoreleisHouse_Text_WillDoWhatICanHereAndNow::
	.string "{JPN}この さき どうなるかは\n"
	.string "わからない けれど……\p"
	.string "いま ここで できることを するわ。\n"
	.string "わたしに できるのは それだけ。$"

FourIsland_LoreleisHouse_Text_StuffedMonDollsGalore::
	.string "{JPN}ポケモンの ぬいぐるみが いっぱい!$"

