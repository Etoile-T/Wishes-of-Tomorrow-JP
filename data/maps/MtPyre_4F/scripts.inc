MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "{JPN}おししょうさま……\n"
	.string "わたしの せいちょうを みまもって ください!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "{JPN}おししょうさま……\n"
	.string "すんません……!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "{JPN}わたしが せいちょう しないかぎり ここに ねむる\n"
	.string "おししょうさまは やすらかに ねむれない……$"

