PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "{JPN}キナギと カイナの あいだの うみは\n"
	.string "しおの ながれが とても はやいの。\p"
	.string "なみのり したら おもわぬ ところへ\n"
	.string "ながされちゃう かもしれないわ。$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "{JPN}ね! すごいでしょ!\n"
	.string "みずの うえに おうちが たってるの!\p"
	.string "ここで うまれたんだよ!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "{JPN}そらのはしら?\p"
	.string "……ああ すこし おきにある\n"
	.string "あの たかーい とうの ことね。\p"
	.string "わたしなら のぼらないわ。\n"
	.string "あんなに たかいと こわすぎるもの。\p"
	.string "キナギで うみと おなじ たかさで\n"
	.string "くらすのが わたしには ちょうど いいの。$"

PacifidlogTown_Text_TownSign:
	.string "{JPN}キナギタウン\p"
	.string "「あさひが うみに\n"
	.string "ほほえむ まち」$"

