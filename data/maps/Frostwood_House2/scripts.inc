@ ============================================================================
@  The Frostwood gym leader's family home, AFTER Toasty Time. The girls are
@  home with their AZURILL and everyone's happy. The door into OldaleTown_House2
@  is redirected here once FLAG_MELTINGMILE_PATH_CLEARED is set
@  (WotRedirectWarp in field_control_avatar.c); before that, House2 is used.
@ ============================================================================
Frostwood_House2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Frostwood_House2_OnResume
	.byte 0

@ ON_RESUME, not ON_LOAD: the task needs the objects spawned, and menus reset the
@ task pool, so it is re-armed every time the map resumes (a no-op if running).
Frostwood_House2_OnResume::
	setvar VAR_0x8004, (1 << LOCALID_FW_HOUSE2_MOM) | (1 << LOCALID_FW_HOUSE2_GIRL_1) | (1 << LOCALID_FW_HOUSE2_GIRL_2) | (1 << LOCALID_FW_HOUSE2_AZURILL_1) | (1 << LOCALID_FW_HOUSE2_AZURILL_2)
	setvar VAR_0x8005, (1 << LOCALID_FW_HOUSE2_AZURILL_1) | (1 << LOCALID_FW_HOUSE2_AZURILL_2)
	special WotStartFamilyHearts
	end

Frostwood_House2_EventScript_Mom::
	lock
	faceplayer
	msgbox Frostwood_House2_Text_Mom, MSGBOX_DEFAULT
	release
	end

Frostwood_House2_EventScript_Dad::
	lock
	faceplayer
	goto_if_set FLAG_TOASTY_TIME_RARE_CANDY, Frostwood_House2_EventScript_DadAfter
	msgbox Frostwood_House2_Text_DadThanks, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	@ giveitem clobbers VAR_RESULT; its success flag is VAR_0x8007, and it
	@ already printed the bag-full message if there was no room.
	goto_if_eq VAR_0x8007, FALSE, Frostwood_House2_EventScript_DadBagFull
	setflag FLAG_TOASTY_TIME_RARE_CANDY
	msgbox Frostwood_House2_Text_DadAfterGift, MSGBOX_DEFAULT
Frostwood_House2_EventScript_DadBagFull::
	release
	end

Frostwood_House2_EventScript_DadAfter::
	msgbox Frostwood_House2_Text_DadAfter, MSGBOX_DEFAULT
	release
	end

Frostwood_House2_EventScript_Girl1::
	lock
	faceplayer
	msgbox Frostwood_House2_Text_Girl1, MSGBOX_DEFAULT
	release
	end

Frostwood_House2_EventScript_Girl2::
	lock
	faceplayer
	msgbox Frostwood_House2_Text_Girl2, MSGBOX_DEFAULT
	release
	end

Frostwood_House2_Text_Mom:
	.string "{JPN}むすめ ふたりが かえってきて ごはんも\n"
	.string "たべて ルリリも ずっと はねまわってるわ！\p"
	.string "あの こたちを つれもどしてくれて\n"
	.string "ありがとう。$"

Frostwood_House2_Text_DadThanks:
	.string "{JPN}おお きたか！ あの ふたりを\n"
	.string "ほんとうに ゆきの なかから つれもどすとは。\p"
	.string "ばんごはんも まだ あたたかかったよ！\n"
	.string "てつだって くれて ありがとう。\p"
	.string "ほら ほんの おれいだ。\n"
	.string "うけとってくれ。$"

Frostwood_House2_Text_DadAfterGift:
	.string "{JPN}じまんの ポケモンに もたせてやって くれ。\n"
	.string "うちの むすめたちも きょうは じまんだったよ。$"

Frostwood_House2_Text_DadAfter:
	.string "{JPN}にぎやかな いえと あたたかい ばんごはん。\n"
	.string "これいじょうの しあわせは ないね。$"

Frostwood_House2_Text_Girl1:
	.string "{JPN}ココア さくせん だいせいこう。 いつも きくの。\p"
	.string "トレーニングは\n"
	.string "また あしたね！$"

Frostwood_House2_Text_Girl2:
	.string "{JPN}ルリリたち あったかくなって\n"
	.string "すごく うれしそう！\p"
	.string "いつか あたしたちも おにいちゃんみたいに\n"
	.string "つよく なるんだ。$"
