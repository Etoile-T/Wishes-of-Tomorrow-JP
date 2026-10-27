FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "{JPN}だれも しんじて くれないけど\n"
	.string "そらに きょだいな ポケモンを みたんだ\p"
	.string "くねくね しながら 131ばんすいどうの\n"
	.string "ほうへ とんでいったよ\p"
	.string "ところで…… クンクン……\n"
	.string "あの…… きみ…… こげくさいね\p"
	.string "かざんにでも いってたの?$"

FortreeCity_Text_SomethingBlockingGym:
	.string "{JPN}ポケモンジムに いきたいのに\n"
	.string "なにかが みちを ふさいでいるのよ!\p"
	.string "せっかく くろうして\n"
	.string "120ばんどうろで しゅぎょう したのに……$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "{JPN}あたしの じまんの ポケモンが\n"
	.string "いっしょよ こんどこそ ナギに かつわ!$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "{JPN}あめが じめんに すいこまれて\n"
	.string "その みずを すって きが そだつ……\p"
	.string "みずと つちが りょうほう あるから\n"
	.string "この ヒワマキシティも あるのよね$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "{JPN}このまちは きのうえに いえを たてて\n"
	.string "できているのです\p"
	.string "そんな くらしの せいか\n"
	.string "みんな げんきで イキイキ しています\p"
	.string "わしも なんだか\n"
	.string "30ねんほど わかがえった きぶんです$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "{JPN}きのうえで くらすのは いいんだけど\p"
	.string "ときどき まどから むしポケモンが\n"
	.string "はいって くるんだよね\l"
	.string "ほんと びっくり しちゃうよ$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "{JPN}こうかん すると しんか する\n"
	.string "ポケモンが いるんだって! きいたんだ$"

FortreeCity_Text_SomethingUnseeable:
	.string "{JPN}みえない なにかが いるようだ$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "{JPN}みえない なにかが いるようだ\p"
	.string "デボンスコープを つかいますか?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{JPN}{ENG}{PLAYER}{JPN}は デボンスコープを つかった!\p"
	.string "みえない ポケモンが すっかり\n"
	.string "すがたを あらわした!\p"
	.string "おどろいた ポケモンは にげだした!$"

FortreeCity_Text_CitySign:
	.string "{JPN}ここは ヒワマキシティ\n"
	.string "「しぜんと たわむれる\l"
	.string "きのうえの まち」$"

FortreeCity_Text_GymSign:
	.string "{JPN}ヒワマキシティ ポケモンジム\n"
	.string "リーダー ナギ\p"
	.string "「せかいへ はばたく\n"
	.string "とりつかい」$"

