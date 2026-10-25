NewMapInn_MapScripts::
	.byte 0

@ ============================================================================
@  PILGRIM'S REST -- free bed before the climb. Heals + sets respawn.
@  NOTE: HealPlayerParty is synchronous -- do NOT follow with waitstate.
@ ============================================================================
NewMapInn_EventScript_Innkeeper::
	lock
	faceplayer
	msgbox NewMapInn_Text_Greeting, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq NewMapInn_EventScript_Decline
	closemessage
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	setrespawn HEAL_LOCATION_NEW_MAP_INN
	msgbox NewMapInn_Text_Rested, MSGBOX_DEFAULT
	release
	end

NewMapInn_EventScript_Decline::
	msgbox NewMapInn_Text_Decline, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@  Text
@ ============================================================================
NewMapInn_Text_Greeting::
	.string "{JPN}じゅんれいしゃの やどへ ようこそ。\p"
	.string "むかしは のぼる まえの ばんには\n"
	.string "ベッドが ぜんぶ うまったものさ。 みんな\l"
	.string "あけの かねを まつ じゅんれいしゃでね。\p"
	.string "いまじゃ からっぽの ベッドと わたしだけ。\p"
	.string "こごえそうな かおを してるね。\n"
	.string "すこし やすんで いくかい？$"

NewMapInn_Text_Rested::
	.string "{JPN}ほら。 みんな あったまったね。\p"
	.string "もし やまに おいかえされたら\n"
	.string "まっすぐ ここへ おいで。 いいね？\p"
	.string "この とびらに かぎは かけないよ。\n"
	.string "おりてくる ひとには だれにもね。$"

NewMapInn_Text_Decline::
	.string "{JPN}すきに おし。\p"
	.string "やかんは あたたかく ベッドは\n"
	.string "ととのえておく。 それくらいは できるからね。$"
