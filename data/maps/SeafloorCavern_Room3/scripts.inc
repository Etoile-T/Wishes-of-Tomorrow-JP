SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "{JPN}アハハハハ!\p"
	.string "せんすいていも なしに どうやって\n"
	.string "ここまで きたの?\l"
	.string "たいした こどもね!\p"
	.string "でも… ここで じゃまを されちゃ\n"
	.string "こまるのよ。\p"
	.string "それに てんきけんきゅうじょでの\n"
	.string "おかえしも したいしね……\p"
	.string "ちょっと いたい めに あわせて\n"
	.string "あげるわ! かくごなさい!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "{JPN}アハハハハ!\p"
	.string "いったーい!$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "{JPN}アハハハハ!\n"
	.string "ほんと つよいのね。\p"
	.string "あなたが アクアだんの メンバーじゃ\n"
	.string "ないなんて ざんねんで ならないわ。\p"
	.string "なかまに なっていれば リーダーが\n"
	.string "やくそくしてくれた すてきな せかいを\l"
	.string "いっしょに たのしめたのに……$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "{JPN}おれたちの ゆめを かなえるには\n"
	.string "ポケモンの ちからが ひつようだ。\p"
	.string "なのに おまえみたいな じゃまものが\n"
	.string "ポケモンの ちからで こんな ばしょ\l"
	.string "まで きて じゃまを しやがる!\p"
	.string "せのなかってのは おもいどおりに\n"
	.string "いかねえもんだぜ!$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "{JPN}ぐわっ!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "{JPN}おれたちは リーダーの かんがえに\n"
	.string "ぎもんを もつなんて できねえ。\p"
	.string "なのに ただの ガキの おまえが\n"
	.string "リーダーに たちむかってる。\p"
	.string "もしかして……\n"
	.string "おまえ ただものじゃ ねえのかもな……$"

