NewMapApprenticeHouse_MapScripts::
	.byte 0

@ ============================================================================
@  ITSUKI'S HOUSE -- boarded up until FLAG_NEWMAP_APPRENTICE_DOOR_OPEN is set
@  (Master Gen clears the crates after the mask is returned).
@  Optional epilogue lore: WHY a village boy joins the oni climb.
@ ============================================================================
NewMapApprenticeHouse_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

NewMapApprenticeHouse_EventScript_Diary::
	msgbox NewMapApprenticeHouse_Text_Diary, MSGBOX_SIGN
	end

NewMapApprenticeHouse_EventScript_Worktable::
	msgbox NewMapApprenticeHouse_Text_Worktable, MSGBOX_SIGN
	end

NewMapApprenticeHouse_EventScript_Hearth::
	msgbox NewMapApprenticeHouse_Text_Hearth, MSGBOX_SIGN
	end

@ ============================================================================
@  Text
@ ============================================================================
NewMapApprenticeHouse_Text_Diary::
	.string "{JPN}つくえの うえに ひらいたままの にっきだ。\p"
	.string "「…また きたかぜに のって きこえた。\n"
	.string "とうさんの こえ。 むかしの よびかたで\l"
	.string "ぼくの なまえを よんでいた。\p"
	.string "「ゲンししょうは かなしみは みみを\n"
	.string "ふえのように ならすと いう。 そうかもね。\p"
	.string "「…こんや ふるい はかの そばで\n"
	.string "つのの ある めんの おとこが まっていた。\l"
	.string "その ひとは ぼくを わらわなかった。\p"
	.string "「やまは わたしたちが くやむものを\n"
	.string "しまっておくと いった。 どんな こえも\l"
	.string "どんな かおも。 きえずに しまわれていると。\p"
	.string "「めんを つけた ものは のぼれる。\n"
	.string "サミットゲートは かえしてくれる と。\p"
	.string "「あした かねが 2ど なる」\p"
	.string "あとの ページは まっしろだ。$"

NewMapApprenticeHouse_Text_Worktable::
	.string "{JPN}ちいさな さぎょうだいが\n"
	.string "かんなくずで おおわれている。\p"
	.string "その うえには れんしゅうようの めんが\n"
	.string "ずらりと ならぶ。 ひとつ ごとに うまくなり\l"
	.string "40こ いじょうも ある。\p"
	.string "さいごの かけくぎは からっぽだ。$"

NewMapApprenticeHouse_Text_Hearth::
	.string "{JPN}いろりは つめたい。\p"
	.string "たなの うえに がくに はいった\n"
	.string "しゃしんが ある。 にっこり わらう\l"
	.string "りょうしが ちいさな おとこのこの\l"
	.string "あたまに てを のせている。\p"
	.string "ガラスの ほこりは ふきとられている。\n"
	.string "つい さいきん。 なんども。$"
