BattleFrontier_Lounge7_MapScripts::
	.byte 0

@special ChooseMonForMoveTutor
BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_SOFT_BOILED
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SEISMIC_TOSS
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_DREAM_EATER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MEGA_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_MEGA_KICK
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_BODY_SLAM
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ROCK_SLIDE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_COUNTER
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_WAVE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	setvar VAR_0x8005, MOVE_DEFENSE_CURL
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SNORE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_MUD_SLAP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_SWIFT
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_ICY_WIND
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ENDURE
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_PSYCH_UP
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_ICE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_THUNDER_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	setvar VAR_0x8005, MOVE_FIRE_PUNCH
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end


BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	chooseboxmon SELECT_PC_MON_MOVE_TUTOR
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "{JPN}ブハハハ!\p"
	.string "いまじゃ そうは みえない だろうけど\n"
	.string "むかしは つよい トレーナー だったんだよ。\p"
	.string "このへんじゃ いちばん つよい\n"
	.string "おとなのおねえさんと いわれたもんさ!\p"
	.string "… … … … … …\p"
	.string "なんだい?\n"
	.string "しんじて ないね?\p"
	.string "あたしゃ むこうの ほらふき おんなとは\n"
	.string "ちがうよ! ほんとに じつりょくが あるんだ!\p"
	.string "しょうこを みせて やろう。\n"
	.string "あんたの ポケモンに とくべつで\l"
	.string "かわいい わざを おしえて やるよ。\p"
	.string "ただし ただじゃ ないよ。\n"
	.string "おしえる わざの おだいは\l"
	.string "バトルポイントを ちょいと いただくよ。$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "{JPN}ブハハハ!\p"
	.string "また とくべつで かわいい\n"
	.string "ポケモンの わざを おぼえに きたのかい?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "{JPN}よしよし みてごらん!\n"
	.string "どの わざを おしえて ほしいんだい?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "{JPN}{ENG}{STR_VAR_1}{JPN} が ええのんか!\n"
	.string "{ENG}{STR_VAR_2}{JPN}BP じゃが ええんじゃの!?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "{JPN}ほいじゃあ わざを おぼえさせる\n"
	.string "ポケモンを きめて おくれ!$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "{JPN}なんじゃ……\n"
	.string "あんた バトルポイントが たりんぞ!$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "{JPN}あたしゃの すごさが わかったかいっ!!\n"
	.string "じゃあ バトルポイントは いただくぞぃ!$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "{JPN}なんだって?\n"
	.string "いらない だって……\p"
	.string "あたしの うでまえが みたく なったら\n"
	.string "いつでも おいで!$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "{JPN}イヒヒヒ!\p"
	.string "いまは そうは みえない だろうけど\n"
	.string "むかしは すごい トレーナー だったのさ。\p"
	.string "このへんじゃ いちばん むてきの\n"
	.string "ビキニのおねえさんと いわれたもんさ!\p"
	.string "… … … … … …\p"
	.string "どうしたんだい?\n"
	.string "しんじて ないね?\p"
	.string "あたしゃ むこうの まぬけな おんなとは\n"
	.string "ちがうよ! ほんとに けいけんが あるんだ!\p"
	.string "しょうこを みせて やれるよ。\n"
	.string "あんたの ポケモンに つよくて\l"
	.string "きれいな わざを おしえて やろう。\p"
	.string "ただし ただじゃ ないよ。\n"
	.string "おしえる わざの おだいは\l"
	.string "バトルポイントを ちょいと いただくよ。$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "{JPN}イヒヒヒ!\p"
	.string "つよくて きれいな ポケモンの わざを\n"
	.string "おぼえに きたのかい?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "{JPN}あの ふたりって おたがいの\n"
	.string "わるぐち いい あってる から\l"
	.string "なかが わるいとか おもって ないか?\p"
	.string "でも ほんとに そう だったら いっしょに\n"
	.string "こんなところに いたり しないよな$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "{JPN}おれが まだ たんパンこぞう だったころ\n"
	.string "あの ふたりは つよくて うつくしかった。\p"
	.string "トレーナーたちの あこがれ だったんだ。\p"
	.string "いまでも としを とって\n"
	.string "うでが おちた なんてことは ない。\p"
	.string "それどころか ポケモンの わざは\n"
	.string "もっと みがきが かかっている。\p"
	.string "でも…… なぜだか こう\n"
	.string "おもわずには いられないんだ……\p"
	.string "じかんって ざんこくだな……$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "{JPN}キズついた からだを\n"
	.string "たいりょくの\n"
	.string "はんぶん かいふく$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "{JPN}いんりょくを りよう\n"
	.string "レベル ぶんの\n"
	.string "ダメージを あたえる$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "{JPN}ねている てきに\n"
	.string "あたえた ダメージの\n"
	.string "はんぶんを かいふく$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "{JPN}ものすごい ちからを\n"
	.string "こめた パンチで\n"
	.string "てきを こうげき$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "{JPN}ものすごい ちからを\n"
	.string "こめた キックで\n"
	.string "てきを こうげき$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "{JPN}たおれこみ こうげき\n"
	.string "てきを まひ させる\n"
	.string "ことが ある$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "{JPN}いわで こうげき\n"
	.string "てきを ひるませる\n"
	.string "ことが ある$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "{JPN}ぶつりこうげきの\n"
	.string "ダメージを\n"
	.string "ばいにして かえす$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "{JPN}よわい でんげきを\n"
	.string "ぶつけて あいてを\n"
	.string "まひ させる$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "{JPN}たたかいの おどりで\n"
	.string "こうげきを グーンと\n"
	.string "あげる$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "{JPN}からだを まるめて\n"
	.string "ぼうぎょを\n"
	.string "あげる$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "{JPN}ねている とき だけ\n"
	.string "つかえる わざ\n"
	.string "いびきで こうげき$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "{JPN}ドロを かけて\n"
	.string "めいちゅうりつを\n"
	.string "さげる$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "{JPN}だれも よけることの\n"
	.string "できない ほしがたの\n"
	.string "こうせんで こうげき$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "{JPN}すごい れいきで\n"
	.string "こうげき\n"
	.string "すばやさを さげる$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "{JPN}そのターンで\n"
	.string "こうげき されても\n"
	.string "たいりょくが1のこる$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "{JPN}あいての\n"
	.string "ほじょこうかを\n"
	.string "じぶんに コピーする$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "{JPN}つめたい パンチで\n"
	.string "てきを こおらせる\n"
	.string "ことが ある$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "{JPN}でんげき パンチで\n"
	.string "てきを まひさせる\n"
	.string "ことが ある$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "{JPN}ほのおの パンチで\n"
	.string "てきを やけどさせる\n"
	.string "ことが ある$"
