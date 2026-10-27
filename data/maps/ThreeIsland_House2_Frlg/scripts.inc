ThreeIsland_House2_Frlg_MapScripts::
	.byte 0

ThreeIsland_House2_EventScript_Man::
	lock
	faceplayer
	famechecker FAMECHECKER_SABRINA, 1
	msgbox ThreeIsland_House2_Text_IAdmireSabrina
	release
	end

ThreeIsland_House2_EventScript_Rocker::
	msgbox ThreeIsland_House2_Text_CantMakeThisSpoonBend, MSGBOX_NPC
	end

ThreeIsland_House2_Text_CantMakeThisSpoonBend::
	.string "{JPN}うぬぬぬぬぬぬ…\n"
	.string "くわーっ!\p"
	.string "…だめだ! ちょうのうりょくで\n"
	.string "スプーンが まげられない\p"
	.string "ぼくには やっぱり ちょうのうりょくなんて\n"
	.string "ないのかなあ$"

ThreeIsland_House2_Text_IAdmireSabrina::
	.string "{JPN}ヤマブキシティの おんなの\n"
	.string "ジムリーダー しってる?\p"
	.string "エスパータイプの ポケモンを\n"
	.string "つかうんだよね?\p"
	.string "ほんとに あこがれちゃう\p"
	.string "すごく クールで しかも\n"
	.string "きれいな ひとなんだって$"

