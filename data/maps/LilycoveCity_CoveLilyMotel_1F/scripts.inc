LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "{JPN}ほう ポケモンを めだまにして\n"
	.string "おきゃくが ばいに なったのか?\p"
	.string "ふむ うちの やどにも かわいい\n"
	.string "ポケモンの マスコットを おこうかな。\p"
	.string "そうすれば とまりにくる おきゃくが\n"
	.string "ふえるかねえ?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "{JPN}おっと すまん すまん!\n"
	.string "テレビに むちゅうに なってたよ!\p"
	.string "アクアだんが このまちに きてから\n"
	.string "かんこうきゃくが とおのいて しまってね。$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "{JPN}おい まえの ひと しゃがんでくれ!\n"
	.string "テレビが みえないよ!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "{JPN}すごいな! ポケモンが だれかの\n"
	.string "おとしものを みつけたって?\p"
	.string "たいしたもんだ。そんな かしこい\n"
	.string "ポケモンが うちにも いれば…\p"
	.string "おきゃくが なくした ものを\n"
	.string "なんでも みつけられるのになあ…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "{JPN}おっと すまん すまん!\n"
	.string "テレビに むちゅうに なってたよ!\p"
	.string "だれかが アクアだんの アジトを\n"
	.string "つぶしたそうだね。\p"
	.string "おかげで たったいま\n"
	.string "だんたいきゃくの よやくが はいったよ。\p"
	.string "かいしゃの なまえは… ええと…\n"
	.string "ゲームなんとか だったな…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "{JPN}すごいな! るすばんの ポケモンが\n"
	.string "どろぼうを つかまえたって?\p"
	.string "たいしたもんだ。つよい ポケモンに\n"
	.string "けいびを してもらえば…\p"
	.string "おきゃくに もっと あんしんして\n"
	.string "とまって もらえるんだな。$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "{JPN}おっと すまん すまん!\n"
	.string "テレビに むちゅうに なってたよ。\p"
	.string "そうそう すこしまえに\n"
	.string "だんたいの おきゃくが ついてね。\p"
	.string "ゲームフリークって なまえだったから\n"
	.string "ゲームを つくってるんだろうね。\p"
	.string "おっと いけない。みんなの ゆうしょくを\n"
	.string "つくりはじめなきゃ!$"

