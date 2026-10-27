RockTunnel_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RockTunnel_1F_OnTransition
	.byte 0

RockTunnel_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROCK_TUNNEL_1F
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_HIKER_LENNY, RockTunnel_1F_Text_LennyIntro, RockTunnel_1F_Text_LennyDefeat
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_HIKER_OLIVER, RockTunnel_1F_Text_OliverIntro, RockTunnel_1F_Text_OliverDefeat
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_HIKER_LUCAS, RockTunnel_1F_Text_LucasIntro, RockTunnel_1F_Text_LucasDefeat
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonIntro, RockTunnel_1F_Text_AshtonDefeat
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_PICNICKER_LEAH, RockTunnel_1F_Text_LeahIntro, RockTunnel_1F_Text_LeahDefeat
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaIntro, RockTunnel_1F_Text_ArianaDefeat
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_PICNICKER_DANA, RockTunnel_1F_Text_DanaIntro, RockTunnel_1F_Text_DanaDefeat
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_Text_LennyIntro::
	.string "{JPN}この トンネルは ながいぞ!$"

RockTunnel_1F_Text_LennyDefeat::
	.string "{JPN}うっ!\n"
	.string "まけた!$"

RockTunnel_1F_Text_LennyPostBattle::
	.string "{JPN}イワークに きをつけろ。\n"
	.string "たまに しか でて こないけどな。\p"
	.string "レベルが たかいと\n"
	.string "しめつけられるぞ!$"

RockTunnel_1F_Text_OliverIntro::
	.string "{JPN}うーん。\n"
	.string "まよっちゃった かな…$"

RockTunnel_1F_Text_OliverDefeat::
	.string "{JPN}まってくれ!\n"
	.string "おれ なにを してるんだ?\l"
	.string "でぐちは どっちだ?$"

RockTunnel_1F_Text_OliverPostBattle::
	.string "{JPN}12ばんどうろで ねむってる ポケモンの\n"
	.string "せいで まわりみち する はめに なった。$"

RockTunnel_1F_Text_LucasIntro::
	.string "{JPN}よそものは おれに けいいを\n"
	.string "はらうべきだ!$"

RockTunnel_1F_Text_LucasDefeat::
	.string "{JPN}まいった!$"

RockTunnel_1F_Text_LucasPostBattle::
	.string "{JPN}きみなら やまのぼりも いけるぞ!$"

RockTunnel_1F_Text_AshtonIntro::
	.string "{JPN}ポケモン しょうぶ!\n"
	.string "よーい どん!$"

RockTunnel_1F_Text_AshtonDefeat::
	.string "{JPN}ゲームオーバー!$"

RockTunnel_1F_Text_AshtonPostBattle::
	.string "{JPN}まあいいや ズバットでも つかまえよう!$"

RockTunnel_1F_Text_LeahIntro::
	.string "{JPN}きゃっ!\p"
	.string "くらやみで へんな こと\n"
	.string "しないでよ!$"

RockTunnel_1F_Text_LeahDefeat::
	.string "{JPN}くらすぎた…$"

RockTunnel_1F_Text_LeahPostBattle::
	.string "{JPN}この トンネルで ワンリキーを みたわ。$"

RockTunnel_1F_Text_DanaIntro::
	.string "{JPN}やせいの ポケモンを さがして\n"
	.string "ここまで きたの。$"

RockTunnel_1F_Text_DanaDefeat::
	.string "{JPN}ポケモンが もう いない!$"

RockTunnel_1F_Text_DanaPostBattle::
	.string "{JPN}かわいくて よわそうに みえたのに。\n"
	.string "とんだ みこみちがい だったわ!$"

RockTunnel_1F_Text_ArianaIntro::
	.string "{JPN}ポケモン もってるのね!\n"
	.string "はじめましょ!$"

RockTunnel_1F_Text_ArianaDefeat::
	.string "{JPN}てごわいわね!$"

RockTunnel_1F_Text_ArianaPostBattle::
	.string "{JPN}ふう!\n"
	.string "あせ びっしょりだわ。$"

RockTunnel_1F_Text_RouteSign::
	.string "{JPN}イワヤマトンネル\n"
	.string "ハナダシティ - シオンタウン$"

