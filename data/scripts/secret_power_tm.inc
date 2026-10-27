Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "{JPN}ん? なに?\n"
	.string "なにを してるのかって?\p"
	.string "ポケモンの わざを つかって ここに\n"
	.string "じぶんの へやを つくろうと おもってるの。\p"
	.string "そうだ! この わざマシンを あげる。\n"
	.string "これで あなたも へやを つくってみない?$"

Route111_Text_ExplainSecretPower:
	.string "{JPN}つるが たれさがってきそうな\n"
	.string "おおきな きを さがしてね。\p"
	.string "その きの まえで ひみつのちからを つかうの。\n"
	.string "つるが ほどけて たれさがってくるから\l"
	.string "きに のぼれるように なるわ。\p"
	.string "なかには すきな ものを おける\n"
	.string "ひろい スペースが あるのよ。\p"
	.string "じぶんだけの ひみつの へや…\n"
	.string "ひみつきち!\p"
	.string "あなたも つくってみてね。\p"
	.string "それと ひみつきちは きの うえに\n"
	.string "つくるとは かぎらないの。\p"
	.string "ちいさな くぼみの ある いわかべに\n"
	.string "ひみつのちからを つかってみて。\p"
	.string "わたしも ほかの ばしょを さがしてみる。\n"
	.string "じゃあ またね!$"

Route111_Text_DontWantThis:
	.string "{JPN}あら いらないの?\n"
	.string "きが かわったら いってね?$"

Route111_Text_DontHaveAnyRoom:
	.string "{JPN}あら これを いれる ばしょが ないみたい。\p"
	.string "あずかっておくから また こんど\n"
	.string "とりにきてね?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
