ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("{JPN}もういちど さいしょから やりなおして ください。{ENG}");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("{JPN}ワイヤレスつうしんの\nけんさくを ちゅうし しました。{ENG}");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("{JPN}ほかの プレイヤーからの\nれんらくを まっています。{ENG}"); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}! ほかの プレイヤー\nからの れんらくを まっています。{ENG}");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}! れんらくまち!\nそろったら STARTを おしてね。{ENG}");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("{JPN}あと 1にん\nひつようです。{ENG}");
static const u8 sText_2PlayersNeeded[] = _("{JPN}あと 2にん\nひつようです。{ENG}");
static const u8 sText_3PlayersNeeded[] = _("{JPN}あと 3にん\nひつようです。{ENG}");
static const u8 sText_4PlayersNeeded[] = _("{JPN}あと 4にん\nひつようです。{ENG}");
static const u8 sText_2PlayerMode[] = _("{JPN}2にん\nモード{ENG}");
static const u8 sText_3PlayerMode[] = _("{JPN}3にん\nモード{ENG}");
static const u8 sText_4PlayerMode[] = _("{JPN}4にん\nモード{ENG}");
static const u8 sText_5PlayerMode[] = _("{JPN}5にん\nモード{ENG}");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{JPN}{ENG}{B_BUTTON}{JPN}やめる{ENG}");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{JPN}{ENG}{STR_VAR_2}{JPN}から れんらくあり!\n{ENG}{STR_VAR_1}{JPN}を しますか?{ENG}");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{JPN}{ENG}{STR_VAR_2}{JPN}から れんらくあり!\n{ENG}{STR_VAR_1}{JPN}を くばりますか?{ENG}");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{JPN}{ENG}{STR_VAR_2}{JPN}から れんらくあり!\nメンバーに いれますか?{ENG}");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}!\nこの メンバーで いいですか?{ENG}");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("{JPN}この メンバーで {ENG}{STR_VAR_1}{JPN}モードを\nやめますか?{ENG}");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}に OKの\nへんじを おくりました。{ENG}");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("{JPN}あいての トレーナーは いま\nつごうが わるい みたいです…\p{ENG}");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("{JPN}とおすぎる トレーナーとは\nつうしん できません。\p{ENG}");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("{JPN}あいての トレーナーの\nじゅんびが まだ できていません。\p{ENG}");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("{JPN}この メンバーでの {ENG}{STR_VAR_1}{JPN}モードを\nちゅうし します。{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("{JPN}つごうが わるくなってしまった\nメンバーが います。\p{ENG}");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("{JPN}あいての トレーナーは\nつうしん できないようです…\p{ENG}");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}から OKの へんじが きた!{ENG}");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}から メンバーとうろく\nOKの れんらくが きました!{ENG}");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}の へんじは 「ダメ…」\p{ENG}");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}!\nほかの メンバーを まっています!{ENG}");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("{JPN}メンバーから ぬけますか?{ENG}");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("{JPN}メンバーから ぬけました。\p{ENG}");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("{JPN}ワイヤレスつうしんが\nつながりました。{ENG}");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("{JPN}ワイヤレスつうしんが\nきれました…{ENG}");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("{JPN}ともだちとの つうしんが\nきれました…{ENG}");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}の へんじは 「ダメ…」{ENG}");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("{JPN}{ENG}{STR_VAR_2}{JPN}モードに\nしますか?{ENG}");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("{JPN}{ENG}{STR_VAR_2}{JPN}モードに\nしますか?{ENG}");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("{JPN}つうしんちゅう…\nおまちください。{ENG}"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}からの こうかんの\nへんじを まっています…{ENG}");
ALIGNED(4) static const u8 sText_Communicating[] = _("{JPN}つうしんちゅう{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・\n{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{ENG}");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}と つうしんちゅう{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・\n{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{ENG}");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("{JPN}しばらく おまちください{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・\n{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{PAUSE 15}・{ENG}");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("{JPN}やあ! なにか\nしたいことは あるかい?{ENG}");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("{JPN}こんにちは!\nなにか する?{ENG}");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}: やあ また あったね!\nこんどは なにを する?{ENG}");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}: あ! {ENG}{PLAYER}{JPN}!\nこんにちは! なにか する?{ENG}");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("{JPN}なにか するかい?{ENG}");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("{JPN}なにか する?{ENG}");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}: こんどは なにを\nする?{ENG}");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}: ほかにも なにか する?{ENG}"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("{JPN}だれかが はなしかけて きました。{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}が はなしかけて きました。{PAUSE 60}{ENG}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("{JPN}あいての トレーナーの\nへんじを まっています…{ENG}");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}の へんじを\nまっています…{ENG}");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("{JPN}あいての トレーナーが\nトレーナーカードを みせてきた。\pこちらも トレーナーカードを\nみせますか?{ENG}");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("{JPN}あいての トレーナーが\nたいせんを もうしこんできた。\pたいせんの もうしこみを\nうけますか?{ENG}");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("{JPN}あいての トレーナーが\nチャットに さそってきた。\pチャットの さそいを\nうけますか?{ENG}");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("{JPN}とうろくした Lv.{DYNAMIC 0} {DYNAMIC 1}と\nこうかんで\pLv.{DYNAMIC 2} {DYNAMIC 3}を\nだすという もうしこみが あります。\pこの こうかんの もうしこみを\nうけますか?{ENG}");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("{JPN}とうろくした タマゴへの\nこうかんの もうしこみが あります。\lこの もうしこみを うけますか?{ENG}");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("{JPN}チャットが きれました。\p{ENG}");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("{JPN}もうしこみを ことわりました。\p{ENG}");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("{JPN}さそいを ことわりました。\p{ENG}");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("{JPN}チャットを おわりました。\p{ENG}");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("{JPN}お! いま チャットちゅう なんだ!\nいっしょに どう?{ENG}");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}: やあ {ENG}{PLAYER}{JPN}!\nいま チャットちゅう なんだ!\lいっしょに どう?{ENG}");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("{JPN}あ! いま チャット してるの!\nよかったら いっしょに しない?{ENG}");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}: あ! {ENG}{PLAYER}{JPN}!\nいま チャット してるの!\lよかったら いっしょに しない?{ENG}");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("{JPN}……\nトレーナーは いそがしい ようだ…\p{ENG}");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("{JPN}たいせんだね?\nよし ちょっと まってて!{ENG}");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("{JPN}チャットしたいんだね?\nいいよ ちょっと まってて!{ENG}");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("{JPN}いいよ! 「あいさつ」がわりに\nトレーナーカードを みせるね!{ENG}");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("{JPN}たいせん? もちろん! でも\nじゅんびする じかんを ちょうだい。{ENG}");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("{JPN}チャットしたいの?\nいいわ でも ちょっと まってね。{ENG}");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("{JPN}じこしょうかい がわりに\nトレーナーカードを みせるわね。{ENG}");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("{JPN}チャットしたいんだね?\nいいよ ちょっと まってて!{ENG}"); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("{JPN}またせたね!\nさあ たいせんを はじめよう!{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("{JPN}よし!\nチャット しよう!{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("{JPN}おまたせ!\nさあ はじめましょう!{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("{JPN}おまたせ!\nチャット しましょう。{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("{JPN}こうかんを はじめます。{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("{JPN}たいせんを はじめます。{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("{JPN}チャットに はいります…{PAUSE 60}{ENG}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("{JPN}ごめん! いま ポケモンの\nちょうしが わるい みたいなんだ。\lまた こんど たいせん しよう。\p{ENG}");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("{JPN}ほんとに ごめんなさい! ポケモンの\nちょうしが わるい みたいなの…\pまた こんど たいせん しましょう。\p{ENG}");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("{JPN}あれ? トレーナーカード…\nどこ いったんだ?\lごめん! また こんど みせるよ!\p{ENG}");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("{JPN}あら? トレーナーカード\nどこに おいたかしら?…\lごめん! あとで みせるね!\p{ENG}");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("{JPN}なにか したくなったら\nいつでも こえを かけてくれよ!\p{ENG}");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("{JPN}なにか したくなったら\nえんりょ しないでね。\p{ENG}");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("{JPN}おっと! ごめん ほかに\nやることが あるんだ。\lまた こんどね?\p{ENG}");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("{JPN}たいせん するには\nLv.30より ひくい ポケモンが\l2ひき ひつよう だよ。\p{ENG}");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("{JPN}たいせんには Lv.30より ひくい\nポケモンが 2ひき ひつようです。\p{ENG}");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("{JPN}そっか。\nいつでも あいに きてよ!\p{ENG}");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("{JPN}そう…\nいつでも きてね。\p{ENG}");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("{JPN}あっ ごめん!\nいまは ちょっと むりなんだ。\lまた こんど チャット しよう。\p{ENG}");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("{JPN}ごめんなさい。\nいまは やることが いっぱいなの。\lまた こんど チャット しましょ。\p{ENG}");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("{JPN}おお!\nなかなか てごわいな!\p{ENG}");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("{JPN}その わざを つかうとは!\nいい さくせんだ!\p{ENG}");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("{JPN}やるな!\nめから ウロコだったよ!\p{ENG}");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("{JPN}えっ! あの ばめんで その\nポケモンを だすなんて!\p{ENG}");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("{JPN}その ポケモン…\nすごく よく そだてられてる!\p{ENG}");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("{JPN}それよ!\nいまは この わざよ!\p{ENG}");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("{JPN}すごい!\nそんな たたかいかたも あるの?\p{ENG}");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("{JPN}ポケモン いれかえの タイミングが\nぜつみょうね!\p{ENG}");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("{JPN}なるほど!\nこれは べんきょうに なるね!\p{ENG}");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("{JPN}もう おかしなこと いうなよ!\nわらいすぎて おなかが いたい!\p{ENG}");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("{JPN}へえ?\nそんなことが あったんだ。\p{ENG}");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("{JPN}ふんふん… え?\nつまり こういうこと?\p{ENG}");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("{JPN}そうなの?\nしらなかったわ。\p{ENG}");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("{JPN}あはは!\nなに それ!\p{ENG}");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("{JPN}そう まさに それよ!\nそれが いいたかったの。\p{ENG}");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("{JPN}つまりね…\nうん! そうそう!\p{ENG}");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("{JPN}あいさつ がわりに トレーナー\nカードを みせてるんだ。\p{ENG}");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("{JPN}これからも よろしくな!\p{ENG}");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("{JPN}なかよく なるために トレーナー\nカードを みせあってるの。\p{ENG}");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("{JPN}あえて うれしいわ。\nこれからも よろしくね!\p{ENG}");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("{JPN}やったー!\nこの ポケモン ほしかったんだ!\p{ENG}");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("{JPN}ずっと ほしかった ポケモンを\nやっと こうかんで てにいれた!\p{ENG}");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("{JPN}いま ポケモンを こうかんしてるの。\p{ENG}");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("{JPN}ほしかった ポケモンを やっと\nこうかんで てにいれたわ!\p{ENG}");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は\nこうかんけいじばんを みた!\p{ENG}");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("{JPN}こうかんけいじばんへ ようこそ。\pじぶんの ポケモンを とうろくして\nこうかんに だすことが できます。\pポケモンを とうろく\nしますか?{ENG}");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("{JPN}この こうかんけいじばんは\nポケモンを こうかんに だす ばしょです。\pポケモンを こうかんようとして\nとうろく するだけで OKです。\pほかの トレーナーが てもちの\nポケモンと こうかんを もうしでます。\pぜひ ポケモンを とうろくして\nたくさんの ほかの\lトレーナーと こうかんしてください。\pポケモンを とうろく\nしますか?{ENG}");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("{JPN}あなたの ポケモンを こうかん\nけいじばんに とうろく しました。\pごりよう ありがとう ございました!\p{ENG}"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("{JPN}こうかんけいじばんに だれも\nポケモンを とうろく していません。\p\n{ENG}"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("{JPN}こうかんで ほしい ポケモンの\nタイプを えらんで ください。\n{ENG}");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("{JPN}てもちの どの ポケモンを\nこうかんに だしますか?\p{ENG}");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("{JPN}とうろくを ちゅうし しました。\p{ENG}");
ALIGNED(4) static const u8 sText_RegistrationCompleted[] = _("{JPN}とうろくが かんりょう しました。\p{ENG}");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("{JPN}こうかんを キャンセル しました。\p{ENG}");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("{JPN}とうろくした Lv.{ENG}{STR_VAR_2}{JPN}\n{ENG}{STR_VAR_1}{JPN}を かいじょ しますか?{ENG}");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("{JPN}とうろくしている タマゴを\nかいじょ しますか?{ENG}");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("{JPN}とうろくを かいじょ しました。\p{ENG}");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("{JPN}こうかんを きぼうする トレーナーを\nひょうじします。{ENG}"); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("{JPN}ポケモンを こうかんしたい\nトレーナーを えらんで ください。{ENG}"); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}に こうかんを\nもうしこみますか?{ENG}");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("{JPN}あいての トレーナーの\nへんじを まっています…{ENG}"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("{JPN}こうかんに だす ポケモンが\nとうろく されていません。\p{ENG}"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}の ほしがっている\n{ENG}{STR_VAR_2}{JPN}タイプの ポケモンが いません。\p{ENG}");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}の ほしがっている\nタマゴを もっていません。\p{ENG}");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は いま あなたの\nポケモンと こうかんできません。\p{ENG}");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}の ポケモンとは\nいま こうかんできません。\p{ENG}");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("{JPN}こうかんを ことわられました。\p{ENG}");
ALIGNED(4) static const u8 sText_EggTrade[] = _("{JPN}タマゴこうかん{ENG}");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{JPN}{DPAD_UPDOWN}えらぶ  {A_BUTTON}さんか  {ENG}{B_BUTTON}{JPN}やめる{ENG}");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("{JPN}トレーナーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("{JPN}シングルバトルの あいてを\nえらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("{JPN}ダブルバトルの あいてを\nえらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("{JPN}マルチバトルの\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("{JPN}こうかんする トレーナーを\nえらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("{JPN}ふしぎなカードを くばっている\nトレーナーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("{JPN}ふしぎなニュースを くばっている\nトレーナーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("{JPN}ミニポケモンで ジャンプ!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("{JPN}きのみクラッシュ!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("{JPN}ドードリオの きのみどり!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("{JPN}きのみブレンダー!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("{JPN}レコードコーナー!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("{JPN}かっこよさコンテスト!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("{JPN}うつくしさコンテスト!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("{JPN}かわいさコンテスト!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("{JPN}かしこさコンテスト!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("{JPN}たくましさコンテスト!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("{JPN}バトルタワー レベル50!\nリーダーを えらんでください。{ENG}");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("{JPN}バトルタワー オープンレベル!\nリーダーを えらんでください。{ENG}");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("{JPN}ワイヤレスつうしんを\nけんさくちゅう… おまちください…{ENG}");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("{JPN}ダブルバトルには ポケモンが\n2ひき いじょう ひつようです。\p{ENG}"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}からの へんじまち…{ENG}");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}に メンバーとうろくを\nたのみました。 おまちください。{ENG}");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("{JPN}ワイヤレスつうしんからの\nへんじを まっています。{ENG}");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("{JPN}ほかの トレーナーが\nあつまるまで おまちください。{ENG}"); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("{JPN}いま くばられている\nカードは ないようです。{ENG}");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("{JPN}いま くばられている\nニュースは ないようです。{ENG}");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("{JPN}バトル{ENG}");
ALIGNED(4) static const u8 sText_Chat2[] = _("{JPN}チャット{ENG}");
ALIGNED(4) static const u8 sText_Greetings[] = _("{JPN}あいさつ{ENG}");
ALIGNED(4) static const u8 sText_Exit[] = _("{JPN}でる{ENG}");
ALIGNED(4) static const u8 sText_Exit2[] = _("{JPN}でる{ENG}");
ALIGNED(4) static const u8 sText_Info[] = _("{JPN}せつめい{ENG}");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("{JPN}なまえ{CLEAR_TO 60}ほしい{CLEAR_TO 110}だす{CLEAR_TO 198}Lv.{ENG}");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("{JPN}シングルバトル{ENG}");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("{JPN}ダブルバトル{ENG}");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("{JPN}マルチバトル{ENG}");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("{JPN}ポケモンこうかん{ENG}");
ALIGNED(4) static const u8 sText_Chat[] = _("{JPN}チャット{ENG}");
ALIGNED(4) static const u8 sText_Cards[] = _("{JPN}カード{ENG}");
ALIGNED(4) static const u8 sText_WonderCards[] = _("{JPN}ふしぎなカード{ENG}");
ALIGNED(4) static const u8 sText_WonderNews[] = _("{JPN}ふしぎなニュース{ENG}");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("{JPN}ポケモンジャンプ{ENG}");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("{JPN}きのみクラッシュ{ENG}");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("{JPN}きのみどり{ENG}");
ALIGNED(4) static const u8 sText_Search[] = _("{JPN}さがす{ENG}");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("{JPN}きのみブレンダー{ENG}");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("{JPN}レコードコーナー{ENG}");
ALIGNED(4) static const u8 sText_CoolContest[] = _("{JPN}かっこよさ{ENG}");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("{JPN}うつくしさコンテスト{ENG}");
ALIGNED(4) static const u8 sText_CuteContest[] = _("{JPN}かわいさコンテスト{ENG}");
ALIGNED(4) static const u8 sText_SmartContest[] = _("{JPN}かしこさコンテスト{ENG}");
ALIGNED(4) static const u8 sText_ToughContest[] = _("{JPN}たくましさ{ENG}");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("{JPN}バトルタワー Lv.50{ENG}");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("{JPN}バトルタワー オープンレベル{ENG}");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("{JPN}ノーマルカードです。{ENG}");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("{JPN}ブロンズカードです!{ENG}");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("{JPN}カッパーカードです!{ENG}");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("{JPN}シルバーカードです!{ENG}");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("{JPN}ゴールドカードです!{ENG}");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("{JPN}{DYNAMIC 0} {DYNAMIC 1}の\nトレーナーカード…\l{DYNAMIC 2}\pずかん: {DYNAMIC 3}\nプレイじかん: {DYNAMIC 4}:{DYNAMIC 5}\p{ENG}");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("{JPN}バトル: かち {DYNAMIC 0}  まけ {DYNAMIC 2}\nこうかん: {DYNAMIC 3}\p「{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}」\p{ENG}");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{JPN}{DYNAMIC 1}: あえて よかった!{PAUSE 60}{ENG}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{JPN}{DYNAMIC 1}: よろしくね!{PAUSE 60}{ENG}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("{JPN}{DYNAMIC 1}の\nトレーナーカードを みおわりました。{PAUSE 60}{ENG}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

// Subtract two from the total type count to handle in-battle types not for display
static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES - 2] = {
    { gTypesInfo[TYPE_NORMAL].name,   TYPE_NORMAL         },
    { gTypesInfo[TYPE_FIRE].name,     TYPE_FIRE           },
    { gTypesInfo[TYPE_WATER].name,    TYPE_WATER          },
    { gTypesInfo[TYPE_ELECTRIC].name, TYPE_ELECTRIC       },
    { gTypesInfo[TYPE_GRASS].name,    TYPE_GRASS          },
    { gTypesInfo[TYPE_ICE].name,      TYPE_ICE            },
    { gTypesInfo[TYPE_GROUND].name,   TYPE_GROUND         },
    { gTypesInfo[TYPE_ROCK].name,     TYPE_ROCK           },
    { gTypesInfo[TYPE_FLYING].name,   TYPE_FLYING         },
    { gTypesInfo[TYPE_PSYCHIC].name,  TYPE_PSYCHIC        },
    { gTypesInfo[TYPE_FIGHTING].name, TYPE_FIGHTING       },
    { gTypesInfo[TYPE_POISON].name,   TYPE_POISON         },
    { gTypesInfo[TYPE_BUG].name,      TYPE_BUG            },
    { gTypesInfo[TYPE_GHOST].name,    TYPE_GHOST          },
    { gTypesInfo[TYPE_DRAGON].name,   TYPE_DRAGON         },
    { gTypesInfo[TYPE_STEEL].name,    TYPE_STEEL          },
    { gTypesInfo[TYPE_DARK].name,     TYPE_DARK           },
    { gTypesInfo[TYPE_FAIRY].name,    TYPE_FAIRY          },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
