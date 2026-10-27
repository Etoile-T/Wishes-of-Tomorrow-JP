JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "{JPN}えんとつやまの デコボコさんどう……\p"
	.string "これこそ おれが やまに\n"
	.string "もとめていた ものだ!\p"
	.string "この ゴツゴツした デコボコ……\n"
	.string "たましいが ゆさぶられるぜ!$"

JaggedPass_Text_EricDefeat:
	.string "{JPN}まけて くやしいぞ!$"

JaggedPass_Text_EricPostBattle:
	.string "{JPN}たしかに ポケモンでは まけた……\p"
	.string "だが やまを あいする きもちなら\n"
	.string "おれの ほうが うえだ!$"

JaggedPass_Text_DianaIntro:
	.string "{JPN}ここは きがるな ハイキングとは ちがうわ。\n"
	.string "ピクニックむき じゃないわね。$"

JaggedPass_Text_DianaDefeat:
	.string "{JPN}あーん もう!\n"
	.string "じめんが デコボコ すぎるのよ……$"

JaggedPass_Text_DianaPostBattle:
	.string "{JPN}しってた?\p"
	.string "この ひどい デコボコみちを じょうずに\n"
	.string "じてんしゃで のぼっていく ひとも いるのよ。$"

JaggedPass_Text_DianaRegister:
	.string "{JPN}また この あたりに くることって ある?\n"
	.string "そしたら また しょうぶしてね!$"

JaggedPass_Text_DianaRematchIntro:
	.string "{JPN}ピクニックは どこでも たのしい!\n"
	.string "ポケモンと おなじね!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "{JPN}まけたのは じめんが\n"
	.string "デコボコ すぎる せいよ!$"

JaggedPass_Text_DianaPostRematch:
	.string "{JPN}まけたことは わすれて\n"
	.string "この デコボコハイキングを たのしもっと!$"

JaggedPass_Text_EthanIntro:
	.string "{JPN}デコボコさんどうは あるきにくい!\n"
	.string "トレーニングには もってこいだよ!$"

JaggedPass_Text_EthanDefeat:
	.string "{JPN}あしばを さがしてる うちに\n"
	.string "おわっちゃった……$"

JaggedPass_Text_EthanPostBattle:
	.string "{JPN}ダートじてんしゃが あれば\n"
	.string "だんさを とびこえられるのにな。$"

JaggedPass_Text_EthanRegister:
	.string "{JPN}この デコボコに もっと なれたら\n"
	.string "ぜったい かってみせる!\p"
	.string "ポケナビに とうろく してくれる?$"

JaggedPass_Text_EthanRematchIntro:
	.string "{JPN}この デコボコにも なれちゃった。\n"
	.string "いまじゃ うたいながら のぼってるよ。$"

JaggedPass_Text_EthanRematchDefeat:
	.string "{JPN}やっぱり この デコボコの うえだと\n"
	.string "たたかいにくいよ……$"

JaggedPass_Text_EthanPostRematch:
	.string "{JPN}キンセツシティの カゼノさんから\n"
	.string "ダートじてんしゃ もらおうかな……$"

JaggedPass_Text_GruntIntro:
	.string "{JPN}うわっ!\n"
	.string "こんな ところで なにしてる!\p"
	.string "オレが ここで なにしてるか だと?\p"
	.string "おまえに かんけい ないだろ!$"

JaggedPass_Text_GruntDefeat:
	.string "{JPN}ぐぬぬ……\p"
	.string "さっさと アジトに\n"
	.string "にげこんで おけば よかった……$"

JaggedPass_Text_GoWhereverYouWant:
	.string "{JPN}わかった わかった!\n"
	.string "キミが つよいのは みとめて やるよ!\p"
	.string "オレのことは きにするな。\n"
	.string "すきな ところへ いきな!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "{JPN}おや! マグマのしるしに はんのうして\n"
	.string "いわが ゆれている!$"

JaggedPass_Text_JulioIntro:
	.string "{JPN}ひいいっ! いっきに やまを\n"
	.string "おりて くると こわいぃぃ!$"

JaggedPass_Text_JulioDefeat:
	.string "{JPN}からだが バラバラに なりそう……$"

JaggedPass_Text_JulioPostBattle:
	.string "{JPN}じてんしゃが バウンド しすぎて\n"
	.string "おしりが イタイ……$"

JaggedPass_Text_AutumnIntro:
	.string "{JPN}まいにち この さかを のぼってるの。\n"
	.string "パワーには じしん あるんだから!$"

JaggedPass_Text_AutumnDefeat:
	.string "{JPN}うーん……\n"
	.string "なにが いけなかったの?$"

JaggedPass_Text_AutumnPostBattle:
	.string "{JPN}すこし のぼった ところにある\n"
	.string "おかしな いわの でっぱりは なにかしら?$"

