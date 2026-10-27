Aide_EventScript_HaventCaughtEnough::
	msgbox Aide_Text_HaventCaughtEnoughMonsForItem
	release
	end

Aide_EventScript_NoRoomForItem::
	msgbox Aide_Text_DontHaveAnyRoomForItem
	release
	end

Aide_EventScript_DeclineCheckMons::
	msgbox Aide_Text_GetEnoughMonsComeBackForItem
	release
	end

Aide_Text_HaventCaughtEnoughMonsForItem::
	.string "{JPN}どれどれ…\n"
	.string "あれれ! つかまえた ポケモンは\l"
	.string "まだ {ENG}{STR_VAR_3}{JPN}しゅるい だけ!\p"
	.string "{ENG}{STR_VAR_1}{JPN}しゅるい つかまえないと\n"
	.string "{ENG}{STR_VAR_2}{JPN}は あげられません。$"

Aide_Text_GetEnoughMonsComeBackForItem::
	.string "{JPN}…そうですか。\p"
	.string "ポケモンが {ENG}{STR_VAR_1}{JPN}しゅるいに なったら\n"
	.string "{ENG}{STR_VAR_2}{JPN}を とりに きてください。$"

Aide_Text_DontHaveAnyRoomForItem::
	.string "{JPN}おや! バッグが いっぱいの ようですね。\n"
	.string "{ENG}{STR_VAR_2}{JPN}が はいりません。$"
