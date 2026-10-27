VictoryRoad_B1F_MapScripts::
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "{JPN}ポケモンリーグが ちかづいてると\n"
	.string "おもうと……\p"
	.string "あがって きちゃったよ……$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "{JPN}なにも できなかった……$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "{JPN}ポケモンリーグが また とおのいたよ……\n"
	.string "なんだか がっかり するな……$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "{JPN}ポケモンリーグを かちぬくには\n"
	.string "ポケモンからの しんらいが\l"
	.string "ひつようなのよ。$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "{JPN}あなたたちは かたい しんらいで\n"
	.string "むすばれているのね。$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "{JPN}いつも いっしょに いることで ポケモンと\n"
	.string "トレーナーの しんらいは そだつのよ。$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "{JPN}ここは ゴール じゃないの。\n"
	.string "ポケモンリーグへの つうかてん よ!$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "{JPN}その ちょうし!$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "{JPN}あなたなら だいじょうぶよ きっと!\n"
	.string "ポケモンも やるき まんまん だしね!$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "{JPN}わたしの ポケモンは うちゅうてきに\n"
	.string "すばらしいのです!$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "{JPN}あなたの ような ひとは はじめてです。$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "{JPN}しょうぶ じゃなくても あなたと\n"
	.string "あなたの ポケモンから すごい\l"
	.string "パワーを かんじます。$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "{JPN}オーケイ そんなに かまえないで!\n"
	.string "リラックス して いきましょ!$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "{JPN}わお!\n"
	.string "すてき!$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "{JPN}たしかに ここは チャンピオンロード。\p"
	.string "でも いままで あるいてきた みちと\n"
	.string "そんなに かわらないわ。\p"
	.string "のこりの みちも たのしんで\n"
	.string "いってね!$"

