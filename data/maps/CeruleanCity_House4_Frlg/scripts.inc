.set REWARD_TYPE, VAR_0x8004
.set REWARD_ITEM, VAR_0x8008

CeruleanCity_House4_Frlg_MapScripts::
	.byte 0

CeruleanCity_House4_EventScript_WonderNewsBerryMan::
	lock
	specialvar REWARD_TYPE, WonderNews_GetRewardInfo
	copyvar REWARD_ITEM, VAR_RESULT
	goto_if_eq REWARD_TYPE, NEWS_REWARD_NONE,       CeruleanCity_House4_EventScript_NoNews
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_SMALL, CeruleanCity_House4_EventScript_Reward_RecvSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_BIG,   CeruleanCity_House4_EventScript_Reward_RecvBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_WAITING,    CeruleanCity_House4_EventScript_Waiting
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_SMALL, CeruleanCity_House4_EventScript_Reward_SentSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_BIG,   CeruleanCity_House4_EventScript_Reward_SentBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_AT_MAX,     CeruleanCity_House4_EventScript_AtMax
	end

@ Mystery Gift is not enabled, or the player has no saved Wonder News
CeruleanCity_House4_EventScript_NoNews::
	msgbox CeruleanCity_House4_Text_NothingEntertaining
	release
	end

@ Small reward for receiving Wonder News from friend
CeruleanCity_House4_EventScript_Reward_RecvSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_NewNewsInformativeHaveThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for receiving Wonder News from non-friend source
CeruleanCity_House4_EventScript_Reward_RecvBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_IncredibleNewsHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has not recently sent Wonder News
CeruleanCity_House4_EventScript_Waiting::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_WishCouldShareNewsWithOthers
	release
	end

@ Small reward for sending Wonder News every 1-3 times
CeruleanCity_House4_EventScript_Reward_SentSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for sending Wonder News every 4th time
CeruleanCity_House4_EventScript_Reward_SentBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has hit reward limit and must wait to receive new rewards
CeruleanCity_House4_EventScript_AtMax::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews
	release
	end

CeruleanCity_House4_EventScript_MovementReactionToNews::
	playse SE_PIN
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_Delay48
	waitmovement 0
	return

CeruleanCity_House4_EventScript_NoRoomForBerries::
	msgbox CeruleanCity_House4_Text_YourBerryPouchIsFull
	release
	end

CeruleanCity_House4_Text_NothingEntertaining::
	.string "{JPN}はあ…\n"
	.string "ひまは あるのに することが ない…\p"
	.string "どこかで おもしろい ことは\n"
	.string "おきて おらんかのう?$"

CeruleanCity_House4_Text_NewNewsInformativeHaveThis::
	.string "{JPN}おお!\n"
	.string "あたらしい ニュースじゃな!\p"
	.string "ふむ…\p"
	.string "なるほど!\n"
	.string "じつに ためになったわい!\p"
	.string "わかいのに ニュースに きょうみを\n"
	.string "もつとは えらいもんじゃ。\p"
	.string "ニュースを おしえてくれた おれいに\n"
	.string "これを あげよう。$"

CeruleanCity_House4_Text_IncredibleNewsHaveBerries::
	.string "{JPN}おお おお!\n"
	.string "こ この ニュースは!\p"
	.string "ふむ…\p"
	.string "すごい!\n"
	.string "なんと すばらしい ニュースじゃ!\p"
	.string "こんなに すごい ニュースは\n"
	.string "ひさしく みておらんかった!\p"
	.string "すてきな ニュースを ありがとう。\n"
	.string "きのみを どっさり あげよう!$"

CeruleanCity_House4_Text_WishCouldShareNewsWithOthers::
	.string "{JPN}この ニュースを みなに おしえんのは\n"
	.string "なんとも もったいないのう…\p"
	.string "だれかに はなしたいのう…\n"
	.string "みなに しらせたいのう…$"

CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis::
	.string "{JPN}おお ニュースを ひろめて くれたか?\p"
	.string "よい ニュースは いろんな ひとが\n"
	.string "わかちあってこそ かちが でるもんじゃ。\p"
	.string "ひろめて くれた おれいに\n"
	.string "これを うけとって くれ!$"

CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries::
	.string "{JPN}また ニュースを ひろめて くれたか?\n"
	.string "すばらしい!\p"
	.string "ニュースも そんなに つたえられて\n"
	.string "さぞ よろこんで おるじゃろう。\p"
	.string "うむ うむ!\p"
	.string "わしと ニュースからの\n"
	.string "かんしゃの しるしじゃ。\p"
	.string "いつもより きのみを\n"
	.string "おおめに あげよう。$"

CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews::
	.string "{JPN}いろんな ニュースで\n"
	.string "たのしませて もらって おるよ。\p"
	.string "うむ まんぞくじゃ!\n"
	.string "しばらくは たいくつ せんわい。$"

CeruleanCity_House4_Text_YourBerryPouchIsFull::
	.string "{JPN}ん? きのみぶくろが いっぱいじゃな。\n"
	.string "では おくりものは おあずけじゃ。$"

