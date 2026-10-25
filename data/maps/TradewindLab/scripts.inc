@ Tradewind secret basement laboratory -- beneath the "empty" east apartment.
@ Reached via the hidden floor hatch at (1,2) of TradewindApartment_2; the
@ stairs at (17,1) lead back up.
TradewindLab_MapScripts::
	.byte 0

TradewindLab_EventScript_Scientist::
	lock
	faceplayer
	msgbox TradewindLab_Text_Scientist, MSGBOX_DEFAULT
	release
	end

@ Shady dealer -- slips you the three Kanto-starter Mega Stones, once.
TradewindLab_EventScript_ShadyDealer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TRADEWIND_MEGA_STONES, TradewindLab_EventScript_ShadyDealerDone
	msgbox TradewindLab_Text_ShadyDealer, MSGBOX_DEFAULT
	giveitem ITEM_VENUSAURITE
	giveitem ITEM_CHARIZARDITE_X
	giveitem ITEM_BLASTOISINITE
	setflag FLAG_GOT_TRADEWIND_MEGA_STONES
	msgbox TradewindLab_Text_ShadyDealerAfter, MSGBOX_DEFAULT
	release
	end

TradewindLab_EventScript_ShadyDealerDone::
	msgbox TradewindLab_Text_ShadyDealerDone, MSGBOX_DEFAULT
	release
	end

TradewindLab_Text_Scientist::
	.string "{JPN}…どうやって あの とびらを みつけた?\p"
	.string "まあいい。 きみは ここに いる。 けいきは\n"
	.string "だれが よみとるかなんて\l"
	.string "きにしないからね。\p"
	.string "あのよとの さかいを はかっているんだ。\n"
	.string "うえの いちばでは まいとし\l"
	.string "すこしずつ うすくなっている。\p"
	.string "うえの まちは ゆうれいに とりつかれて\n"
	.string "いるんじゃない。\p"
	.string "あのよに なりつつ あるんだ。$"

TradewindLab_Text_ShadyDealer::
	.string "{JPN}おい。 そくていデータが めあてかい?\n"
	.string "それとも ほんものの しなものか?\p"
	.string "カントーの さいこうきゅうひん。 べつせかいの\n"
	.string "トラックから おちたのさ。 せんさくは なし。\p"
	.string "ほら… もっていきな。 おごりだ。\n"
	.string "さいしょは いつでも タダなのさ。$"

TradewindLab_Text_ShadyDealerAfter::
	.string "{JPN}リザードンに カメックスに フシギバナ。\n"
	.string "リングを みつけて めざめさせな。\p"
	.string "ここに きたことは わすれな。$"

TradewindLab_Text_ShadyDealerDone::
	.string "{JPN}タダの おためしは これで おしまい。\n"
	.string "さっさと いきな。$"
