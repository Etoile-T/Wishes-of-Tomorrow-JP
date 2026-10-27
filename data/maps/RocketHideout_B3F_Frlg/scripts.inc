RocketHideout_B3F_Frlg_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
	.string "{JPN}ロケットだんの じゃまを するな!\n"
	.string "さもないと…!$"

RocketHideout_B3F_Text_Grunt1Defeat::
	.string "{JPN}うっ!\n"
	.string "やられた!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
	.string "{JPN}シルフスコープ?\n"
	.string "ああ ボスが ぬすんだ きかいか\p"
	.string "どこかに あるはずだぜ$"

RocketHideout_B3F_Text_Grunt2Intro::
	.string "{JPN}おまえが くることは\n"
	.string "うえから れんらくが あったぞ!$"

RocketHideout_B3F_Text_Grunt2Defeat::
	.string "{JPN}なに?\n"
	.string "まけた? そんな!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
	.string "{JPN}さきへ いけば いいさ!\p"
	.string "でも エレベータのカギが ないと\n"
	.string "エレベーターは うごかせないぜ$"

