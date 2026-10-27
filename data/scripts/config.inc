Debug_FlagsAndVarNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsAndVarNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end

Debug_FlagsAndVarNotSetBattleConfigMessage_Text:
	.string "{JPN}この きのうは つかえません! つかえる\n"
	.string "フラグと へんすうを ていぎしてください:\l"
	.string "include/config/battle.h$"
