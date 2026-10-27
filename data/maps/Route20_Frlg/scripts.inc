Route20_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_BarryIntro::
	.string "{JPN}ここは あさせだから\n"
	.string "およいでる ひとが たくさん いるんだ。$"

Route20_Text_BarryDefeat::
	.string "{JPN}バシャッ!$"

Route20_Text_BarryPostBattle::
	.string "{JPN}ぼくも ポケモンに のれたらなあ。\n"
	.string "きみは つかれて ないんだろうね。$"

Route20_Text_ShirleyIntro::
	.string "{JPN}ふたごじまは しずかな かくれが。\n"
	.string "ここで バカンス ちゅうなの。$"

Route20_Text_ShirleyDefeat::
	.string "{JPN}もう やめて!$"

Route20_Text_ShirleyPostBattle::
	.string "{JPN}この しまの したには\n"
	.string "おおきな どうくつが あるのよ。$"

Route20_Text_TiffanyIntro::
	.string "{JPN}なみに ゆられて さかなたちと\n"
	.string "ぷかぷか うかぶのが すきなの。$"

Route20_Text_TiffanyDefeat::
	.string "{JPN}いたーい!$"

Route20_Text_TiffanyPostBattle::
	.string "{JPN}いっしょに ぷかぷか うかばない?$"

Route20_Text_IreneIntro::
	.string "{JPN}あなたも バカンス ちゅう?$"

Route20_Text_IreneDefeat::
	.string "{JPN}ようしゃ なさすぎ!$"

Route20_Text_IrenePostBattle::
	.string "{JPN}ふたごじまは とおい むかし\n"
	.string "ひとつの しま だったのよ。$"

Route20_Text_DeanIntro::
	.string "{JPN}おれの きたえた にくたいを みろ!$"

Route20_Text_DeanDefeat::
	.string "{JPN}ひよわだ!$"

Route20_Text_DeanPostBattle::
	.string "{JPN}おれじゃなくて ポケモンを\n"
	.string "きたえるべき だった!$"

Route20_Text_DarrinIntro::
	.string "{JPN}なんで ポケモンに のってるんだ?\n"
	.string "およげないのか?$"

Route20_Text_DarrinDefeat::
	.string "{JPN}いてっ!\n"
	.string "ぎょらいを くらった!$"

Route20_Text_DarrinPostBattle::
	.string "{JPN}ポケモンに のるのも たのしそうだな!$"

Route20_Text_RogerIntro::
	.string "{JPN}とりポケモンに のって きたんだ。$"

Route20_Text_RogerDefeat::
	.string "{JPN}しまった!\n"
	.string "これから どうしよう?$"

Route20_Text_RogerPostBattle::
	.string "{JPN}とりたちが へとへとだ。\n"
	.string "これじゃ そらをとぶで かえれない!$"

Route20_Text_NoraIntro::
	.string "{JPN}かれしに おおきな しんじゅを もらったの。$"

Route20_Text_NoraDefeat::
	.string "{JPN}いやーん!\n"
	.string "しんじゅは あの なかに いれてたのに!$"

Route20_Text_NoraPostBattle::
	.string "{JPN}パルシェンの なかで しんじゅは\n"
	.string "おおきく なるかしら?$"

Route20_Text_MissyIntro::
	.string "{JPN}グレンじまから およいできたの。\n"
	.string "ほんとうに たいへん だったんだから。$"

Route20_Text_MissyDefeat::
	.string "{JPN}がっかり!$"

Route20_Text_MissyPostBattle::
	.string "{JPN}グレンの あきやしきに\n"
	.string "ポケモンが すみついちゃったの。\p"
	.string "いまでは ポケモンやしきって\n"
	.string "よばれてるわ。$"

Route20_Text_MelissaIntro::
	.string "{JPN}にしの グレンじまには ポケモンの\n"
	.string "けんきゅうじょが あるの。\p"
	.string "わたしの パパが はたらいてるのよ。$"

Route20_Text_MelissaDefeat::
	.string "{JPN}まって!\n"
	.string "まってって いってるのに!$"

Route20_Text_MelissaPostBattle::
	.string "{JPN}グレンじまは かざんの しまなの。\p"
	.string "かざんが ふんかして うみから\n"
	.string "うまれたって きいたわ。$"

Route20_Text_SeafoamIslands::
	.string "{JPN}ふたごじま$"

Route20_Text_MistyTrainsHere::
	.string "{JPN}この あたりでは つよい トレーナーや\n"
	.string "みずポケモンを よく みかける。\p"
	.string "ハナダジムの カスミも ここで\n"
	.string "しゅぎょう してるらしい。$"
