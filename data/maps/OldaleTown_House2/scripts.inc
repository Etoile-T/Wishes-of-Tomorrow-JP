OldaleTown_House2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, OldaleTown_House2_OnResume
	.byte 0

@ OnResume (not OnLoad): OnLoad runs before ResumeMap's ResetSpriteData,
@ which would wipe the indicator sprite before it renders.
OldaleTown_House2_OnResume::
	questindicator 2, SIDE_QUEST_TOASTY_TIME  @ Dad, until the cocoa quest is picked up
	end

@ Frostwood Town gym leader's family home (reuses the OldaleTown_House2 interior).
@ Woman = proud mother of the GYM LEADER. Man = father who sends the player to fetch
@ the two daughters (the AZURILL trainers blocking the lake path on MeltingMile) for
@ dinner, handing over the HOT COCOA that lures them home.
OldaleTown_House2_EventScript_Woman::
	lock
	faceplayer
	msgbox OldaleTown_House2_Text_MomProud, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HOT_COCOA, OldaleTown_House2_EventScript_DadReminder
	msgbox OldaleTown_House2_Text_DadAsk, MSGBOX_DEFAULT
	giveitem ITEM_HOT_COCOA
	setflag FLAG_GOT_HOT_COCOA
	startquest SIDE_QUEST_TOASTY_TIME
	msgbox OldaleTown_House2_Text_DadAfterGive, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_EventScript_DadReminder::
	msgbox OldaleTown_House2_Text_DadReminder, MSGBOX_DEFAULT
	release
	end

OldaleTown_House2_Text_MomProud:
	.string "{JPN}この フロストウッドの ジムを やっているのは\n"
	.string "うちの むすこ! りっぱな ジムリーダーよ!\p"
	.string "あのこなら やれるって おもっていたわ。\n"
	.string "いもうとたちも すっかり あこがれていてね。\p"
	.string "まいにち やまみちで\n"
	.string "ルリリを きたえているの。 いつか\l"
	.string "おにいちゃんみたいに つよくなるんだって。$"

OldaleTown_House2_Text_DadAsk:
	.string "{JPN}おや! おきゃくさんか。 ちょうど よかった。\n"
	.string "この としよりを てつだってくれないかね。\p"
	.string "うちの むすめたちが また ふたりで\n"
	.string "みずうみへの みちで はねるを れんしゅうして\l"
	.string "ばんごはんも すっかり さめそうだよ。\p"
	.string "ほら この ホットココアを とどけておくれ。\n"
	.string "これが なければ あの ふたりは\l"
	.string "ゆきの なかから かえってこないんだ。$"

OldaleTown_House2_Text_DadAfterGive:
	.string "{JPN}おとうさんが かえって ごはんを たべなさいって\n"
	.string "いってたと つたえておくれ。 ぶつぶつ いうが\l"
	.string "いつも ココアには かなわんのさ。$"

OldaleTown_House2_Text_DadReminder:
	.string "{JPN}あの ふたり まだ そとで こごえているよ。\p"
	.string "ホットココアを とどけておくれ。\n"
	.string "きっと きみに ついて かえってくるさ。$"
