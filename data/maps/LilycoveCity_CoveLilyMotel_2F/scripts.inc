LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "{JPN}わたしは ゲームデザイナーです。\p"
	.string "へえ そうなんですか。\n"
	.string "ポケモンずかんを つくってるんですね?\p"
	.string "かんせいさせるのは たいへんですが\n"
	.string "あきらめないで くださいね。\p"
	.string "かんせいしたら ぜひ\n"
	.string "わたしに みせに きてください。$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "{JPN}うわあ! すごい!\n"
	.string "ほんとうに すばらしい!\p"
	.string "この ずかんは ぜんぶ うまってますね!\n"
	.string "ポケモンが だいすきなんですね!\p"
	.string "かんどう しました!\p"
	.string "この りっぱな せいかを たたえて\n"
	.string "おくりものを させてください!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "{JPN}え? わたしに はなしかけてるの?\n"
	.string "わたしは プログラマーです。\p"
	.string "ここの スロットって\n"
	.string "どんな かんじなのかなあ。$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "{JPN}グラフィックデザイナーです! ホウエンの\n"
	.string "ポケモンって おもしろいでしょ?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "{JPN}うきわガールって かわいいよね。\n"
	.string "かわいい うきわガールと しょうぶ…\p"
	.string "うひゃー さいこう!\p"
	.string "ふたごちゃんも かわいいよね?\n"
	.string "ふたごちゃんと 2たい2の しょうぶ…\p"
	.string "うひゃー たまらなく たのしい!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "{JPN}しおかぜが こころを くすぐる。\n"
	.string "ここは きもちが いいねえ!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "{JPN}いつ どこで しょうぶを いどまれるか\n"
	.string "わからないからね。\p"
	.string "いえを でるときは かならず\n"
	.string "ゲームボーイアドバンスを もっていくんだ。$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "{JPN}エニシダ: … … … … …\n"
	.string "… … … … … ぐう…\p"
	.string "… … … … … はっ?!\n"
	.string "ああ すまん すまん! いねむりしてたよ!\p"
	.string "この ポケモンコンテストって やつを\n"
	.string "みに きたんだ。\p"
	.string "たしかに なかなか たのしそうだ。\n"
	.string "だが…\p"
	.string "わたしは こだわりが あってね。\n"
	.string "バトルと つよい トレーナーが すきなんだ。\p"
	.string "まあ わたしはって だけだが。\p"
	.string "{ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}には ジムも コンテストも\n"
	.string "バトルテントも なにもかも\l"
	.string "たのしんで もらいたいね!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "{JPN}エニシダ: コンテストで かつにも\n"
	.string "さくせんが いると おもうんだ。\p"
	.string "コンテストの さくせんを ねるのも\n"
	.string "トレーナーとして うでを あげる みちだね。$"

