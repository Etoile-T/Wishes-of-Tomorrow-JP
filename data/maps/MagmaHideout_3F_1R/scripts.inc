MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "{JPN}なんで オレが こんなところの\n"
	.string "みはり なんだよ!\p"
	.string "ひだりのみみ が あつい じゃねーか!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "{JPN}あつくて ヘロヘロ……$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "{JPN}こんな マグマだらけの かざんの なかで\n"
	.string "フードを かぶってる オレたち へん?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "{JPN}わたしたちは リーダーの すばらしい\n"
	.string "りそうを かなえるために はいったの。\p"
	.string "あなたが アクアだん でも\n"
	.string "とおりすがりの こども でも かんけいない。\p"
	.string "わたしたちの ジャマを して\n"
	.string "ただで すむと おもわないで!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "{JPN}そんな!\n"
	.string "あなた まったく ゆだん できないわ!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "{JPN}よく ききなさい。\n"
	.string "マグマだんが ただしいの!\p"
	.string "アクアだんの いうことを きいちゃだめ。\n"
	.string "あいつらの うそを しんじないで!$"

