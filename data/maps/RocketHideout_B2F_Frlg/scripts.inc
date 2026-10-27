RocketHideout_B2F_Frlg_MapScripts::
	.byte 0

RocketHideout_B2F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_13, RocketHideout_B2F_Text_GruntIntro, RocketHideout_B2F_Text_GruntDefeat
	msgbox RocketHideout_B2F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntIntro::
	.string "{JPN}シルフスコープで ゴーストが みえると\n"
	.string "ボスが いってたぜ!$"

RocketHideout_B2F_Text_GruntDefeat::
	.string "{JPN}こうさんだ!$"

RocketHideout_B2F_Text_GruntPostBattle::
	.string "{JPN}ロケットだんの アジトは\n"
	.string "ちか 4かい まで あるのさ\p"
	.string "ボスの ところまで いけるかな?$"

