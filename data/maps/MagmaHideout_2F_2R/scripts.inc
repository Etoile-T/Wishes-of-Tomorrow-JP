MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "{JPN}あなたに うらみは ないけど\n"
	.string "これも めいれい だからね!$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "{JPN}わたしは まけたけど……$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "{JPN}とんでもないものを ほりだした!\n"
	.string "あいいろのたまも てにいれた!\p"
	.string "あとは リーダーが……\n"
	.string "ふふふ…… ふはははは!$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "{JPN}あついのは にがて なんだ。 アクアだんに\n"
	.string "はいれば よかった かも……$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "{JPN}やっぱり オレ\n"
	.string "マグマだんには むいてないかも……$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "{JPN}こんなところに いると\n"
	.string "うみが こいしく なったり しないか?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "{JPN}ここは ときどき じひびきが するんだ。\p"
	.string "かざんが ゆれてるのか?\n"
	.string "それとも グラー……\p"
	.string "おっと!\n"
	.string "なんでもない なんでもない!$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "{JPN}うーむ はげしい たたかいぶりだ。\n"
	.string "まるで かざんの ようだ!$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "{JPN}こんかいは たまたま かった だけだ。\n"
	.string "だが そんなことは どうでもいい。\p"
	.string "マグマだんの もくてきは もうすぐ\n"
	.string "たっせい されるのだ!$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "{JPN}マグマのしるしを なくしたって\n"
	.string "おおさわぎ してる やつが いたけど……\p"
	.string "……まてよ!\n"
	.string "それ ひろったの おまえか?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "{JPN}うーん しんじられねえ……$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "{JPN}なんか…… オレたちの けいかく\n"
	.string "しっぱい するような きが してきたよ。$"

