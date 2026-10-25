MunenVillageAct2_MapScripts::
	.byte 0

@ ============================================================================
@  MUNEN VILLAGE -- ACT 2 (overrun by Team Mutrid)
@  Reached ONLY via the Gengar ferry (Catalpa Bow, post-Distortion scene).
@  This is the point of no return: house doors are barred by Mutrid, EXCEPT
@  Clarkson's LABORATORY at (38,18) -> MAP_MUNEN_LAB_ACT2 (warp 0), where
@  Draco waits with the stolen research. Arrival point is (9,14).
@  Still to come: arrival cutscene, villager fates, boss encounter.
@ ============================================================================

MunenVillageAct2_EventScript_GoonSquare::
	lock
	faceplayer
	setspeaker SP_NAME_GOON
	goto_if_set FLAG_ONI_MASK_WORN, OniMask_EventScript_GoonMasked
	msgbox MunenVillageAct2_Text_GoonSquare, MSGBOX_DEFAULT
	release
	end

MunenVillageAct2_EventScript_GoonSquareMasked::
	msgbox MunenVillageAct2_Text_GoonSquareMasked, MSGBOX_DEFAULT
	release
	end

MunenVillageAct2_EventScript_GoonPatrol::
	lock
	faceplayer
	setspeaker SP_NAME_GOON
	goto_if_set FLAG_ONI_MASK_WORN, OniMask_EventScript_GoonMasked
	msgbox MunenVillageAct2_Text_GoonPatrol, MSGBOX_DEFAULT
	release
	end

MunenVillageAct2_EventScript_OccupationNotice::
	msgbox MunenVillageAct2_Text_OccupationNotice, MSGBOX_SIGN
	end

@ ============================================================================
@  Text
@ ============================================================================
MunenVillageAct2_Text_GoonSquare::
	.string "{JPN}この むらは いまは ミュートリッドの かんりかだ。\n"
	.string "とびらは とざし じゅうみんは\l"
	.string "いえから でない。 そして おまえは…\p"
	.string "…まて。 どうやって はいってきた？\n"
	.string "みちは ぜんぶ ふさいだはずだ！$"

MunenVillageAct2_Text_GoonSquareMasked::
	.string "{JPN}したっぱは こしの ほりものの めんを\n"
	.string "ちらりと みて せすじを\l"
	.string "のばした。\p"
	.string "「けんさ ですか？ ここは なにも もんだい\n"
	.string "ありません。 とびらは とざし\l"
	.string "じゅうみんも おとなしい。 ほんとうです」$"

MunenVillageAct2_Text_GoonPatrol::
	.string "{JPN}へんな むらだよな。 どの やねにも ゆき\n"
	.string "どの とびらにも すず。\p"
	.string "マスターは ここで そだったんだって。\n"
	.string "ふつうなら すこしは なつかしく\l"
	.string "おもいそうな もんだがな。\p"
	.string "…ふつうならな。$"

MunenVillageAct2_Text_OccupationNotice::
	.string "{JPN}ふるい むらの かんばんの うえに\n"
	.string "インクも かわかない はりがみが ある:\p"
	.string "「ミュートリッドだんの めいにより…\p"
	.string "「この むらと むらが おぼえている すべては\n"
	.string "これより ねがいに つかえる。\p"
	.string "「いえから でるな。 やまは おうべき\n"
	.string "ものを うけとるだろう」$"
