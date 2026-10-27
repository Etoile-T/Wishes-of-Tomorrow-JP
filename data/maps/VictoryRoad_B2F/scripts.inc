VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "{JPN}かぞく ぜんいんで いっしょに\n"
	.string "ポケモンの しゅぎょうを してたんだ!\l"
	.string "だれにも まけないぜ!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "{JPN}おれの かぞく より つよい!?\n"
	.string "そんなことって あるのか!?$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "{JPN}かぞくの だれよりも つよかった おれ……\n"
	.string "いままで まけたこと なかったのに……\p"
	.string "じしん なくしちゃったよ……\n"
	.string "いえに かえろうかなあ……$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "{JPN}つよい ちびっこが いるって きいたぞ!\n"
	.string "それって きみの ことかい?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "{JPN}ちびっこの くせに つよい!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "{JPN}ウワサの つよい ちびっこは\n"
	.string "トウカシティ から きたらしい。$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "{JPN}そろそろ へばって きたかしら?$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "{JPN}ぜんぜん へばってないわ!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "{JPN}この チャンピオンロードも\n"
	.string "ポケモンリーグも ながく きびしいわ。\l"
	.string "つかれには ちゅうい してね!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "{JPN}ジムバッジを たくさん もってるからって\n"
	.string "ゆだん しちゃ だめよ。\p"
	.string "うえには いつだって\n"
	.string "うえが いるんだから!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "{JPN}あなたの ほうが うえね!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "{JPN}あつめた ジムバッジを みて\n"
	.string "たたかった トレーナーを おもいだすのよ。$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "{JPN}ここまで きたけど きんちょうで\n"
	.string "おなかが ものすごく いたいんです……$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "{JPN}ああ……\n"
	.string "いたい……$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "{JPN}ポケモンリーグが ちかいと おもうと\n"
	.string "どうしても きんちょう しちゃうんです。\p"
	.string "へいきな ふりを するので せいいっぱいです。$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "{JPN}この どうくつには えりぬきの なかの\n"
	.string "えりぬきが あつまるのよ。\p"
	.string "あなたは どう かんじるかしら?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "{JPN}ぜんぜん どうじて いないわ……!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "{JPN}あなた どきょうが あるのね! きにいったわ!\n"
	.string "その ちょうしで がんばって!$"

