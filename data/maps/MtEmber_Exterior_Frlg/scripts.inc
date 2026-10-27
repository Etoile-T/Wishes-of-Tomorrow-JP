MtEmber_Exterior_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_Exterior_OnLoad
	.byte 0

MtEmber_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
	call_if_eq VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2, MtEmber_Exterior_EventScript_RocketsFaceDown
	end

MtEmber_Exterior_EventScript_RocketsFaceDown::
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT2, MOVEMENT_TYPE_FACE_DOWN
	return

MtEmber_Exterior_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_OpenCave
	end

MtEmber_Exterior_EventScript_OpenCave::
	setmetatile 42, 39, METATILE_MtEmber_CaveEntrance, 0
	return

MtEmber_Exterior_EventScript_Grunt1::
	lock
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_Grunt1Defeated
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt1
	msgbox MtEmber_Exterior_Text_WellTryDiggingHere
	release
	end

MtEmber_Exterior_EventScript_Grunt1Defeated::
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt1::
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt1Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_Text_Grunt1Defeat
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_DefeatedBothGrunts::
	msgbox MtEmber_Exterior_Text_WellRegroupDontStepInsideThere
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_EMBER_GRUNT1
	removeobject LOCALID_MT_EMBER_GRUNT2
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtEmber_Exterior_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedGrunt2
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt2
	msgbox MtEmber_Exterior_Text_YoureInTheWayGetLost
	closemessage
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MtEmber_Exterior_EventScript_DefeatedGrunt2::
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt2::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt2Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_Text_Grunt2Defeat
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_RocketPasswordScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtEmber_Exterior_Text_PunchedThroughAtLast
	message MtEmber_Exterior_Text_WhatsPasswordAgain
	waitmessage
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_QuestionMark
	waitmovement 0
	waitbuttonpress
	msgbox MtEmber_Exterior_Text_FirstPasswordGoldeen
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	call MtEmber_Exterior_EventScript_RocketsFaceDown
	msgbox MtEmber_Exterior_Text_SnoopsBeenListeningIn
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	releaseall
	end

MtEmber_Exterior_EventScript_Logan::
	trainerbattle_single TRAINER_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganIntro, MtEmber_Exterior_Text_LoganDefeat
	msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth::
	trainerbattle_single TRAINER_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethIntro, MtEmber_Exterior_Text_BethDefeat
	msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Jocelyn::
	trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynIntro, MtEmber_Exterior_Text_JocelynDefeat
	msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

Text_ExplosionTeach::
	.string "{JPN}そうぞう できる?\n"
	.string "この かざんが ふんか したら?\p"
	.string "その ばくはつで わたしたちは\n"
	.string "おしまい。 なんて おそろしいの?\p"
	.string "こわがってる ついでに\n"
	.string "だいばくはつを おしえてあげようか?$"

Text_ExplosionDeclined::
	.string "{JPN}そうよね。\n"
	.string "こわすぎるわよね。$"

Text_ExplosionWhichMon::
	.string "{JPN}すごく ゆうきが あるのね!\p"
	.string "どの ポケモンに だいばくはつを\n"
	.string "おしえる?$"

Text_ExplosionTaught::
	.string "{JPN}この かざんの うえで\n"
	.string "だいばくはつを つかうなんて……\p"
	.string "なんて おそろしい スリル!$"

MtEmber_Exterior_Text_WellTryDiggingHere::
	.string "{JPN}こっちだ。\n"
	.string "ここを ほってみるぞ。\p"
	.string "かんぶたちが はなしていた おたからは\n"
	.string "ここに あるはずだ。$"

MtEmber_Exterior_Text_YoureInTheWayGetLost::
	.string "{JPN}なんだ……?\n"
	.string "じゃまだ。 きえな。$"

MtEmber_Exterior_Text_PunchedThroughAtLast::
	.string "{JPN}ふう やっと ほりぬけたぜ。\n"
	.string "おたから さがしに いこうぜ!$"

MtEmber_Exterior_Text_WhatsPasswordAgain::
	.string "{JPN}みつけた おたからは ぜんぶ\n"
	.string "そうこに はこぶんだ わかったな?\p"
	.string "……あ それと あいことばは なんだっけ?\n"
	.string "ロケットだんそうこの だよ。$"

MtEmber_Exterior_Text_FirstPasswordGoldeen::
	.string "{JPN}なんだ あいことばを わすれたのか?\n"
	.string "じつは ふたつ あるんだ。\p"
	.string "ひとつめは 「トサキントには\n"
	.string "まるたが いる」。\p"
	.string "そして ふたつめは……$"

MtEmber_Exterior_Text_SnoopsBeenListeningIn::
	.string "{JPN}おい!\n"
	.string "こいつ ぬすみぎき してやがったぞ!$"

MtEmber_Exterior_Text_Grunt1Intro::
	.string "{JPN}おれたちの はなしを\n"
	.string "ぬすみぎき してたな?$"

MtEmber_Exterior_Text_Grunt1Defeat::
	.string "{JPN}え なに?$"

MtEmber_Exterior_Text_Grunt1PostBattle::
	.string "{JPN}なんで かっちまうんだよ?$"

MtEmber_Exterior_Text_Grunt2Intro::
	.string "{JPN}おれたちの おたからを よこどりする きか?\n"
	.string "そうは いかないぞ!$"

MtEmber_Exterior_Text_Grunt2Defeat::
	.string "{JPN}まて!\n"
	.string "なんでだ?$"

MtEmber_Exterior_Text_Grunt2PostBattle::
	.string "{JPN}つごうよく きおくそうしつに なって\n"
	.string "きいたこと ぜんぶ わすれろ!$"

MtEmber_Exterior_Text_WellRegroupDontStepInsideThere::
	.string "{JPN}とんだ じゃまが はいった……\n"
	.string "たてなおし だな。\p"
	.string "おまえ! この なかに はいろう なんて\n"
	.string "かんがえるんじゃ ないぞ!\p"
	.string "みのためを おもうなら\n"
	.string "このことは わすれるんだな!$"

MtEmber_Exterior_Text_LoganIntro::
	.string "{JPN}かつかざんって いうのは ふんかちゅうか\n"
	.string "ふんか しそうな かざんの ことさ。$"

MtEmber_Exterior_Text_LoganDefeat::
	.string "{JPN}ふう…… あつかった!\n"
	.string "あせが ふきだして くるぜ!$"

MtEmber_Exterior_Text_LoganPostBattle::
	.string "{JPN}せかいには 1500いじょうの\n"
	.string "かつかざんが あるんだって。\p"
	.string "かんがえる だけで からだの なかが\n"
	.string "あつく とろけそうに なるぜ!$"

MtEmber_Exterior_Text_BethIntro::
	.string "{JPN}かざんの なかに どうくつが できる\n"
	.string "しくみを しってる?$"

MtEmber_Exterior_Text_BethDefeat::
	.string "{JPN}あちゃー!\n"
	.string "びっくりするほど つよいのね!$"

MtEmber_Exterior_Text_BethPostBattle::
	.string "{JPN}マグマの ひょうめんの ようがんが\n"
	.string "かたまって なかの マグマが ながれでると\l"
	.string "あとに どうくつが のこるのよ。$"

MtEmber_Exterior_Text_JocelynIntro::
	.string "{JPN}しつれんの きずを いやすために\n"
	.string "しゅぎょう してたの……\p"
	.string "おかげで からだだけは\n"
	.string "きたえられたわ! ハイヤー!$"

MtEmber_Exterior_Text_JocelynDefeat::
	.string "{JPN}ちょっと がんばりすぎた みたい……$"

MtEmber_Exterior_Text_JocelynPostBattle::
	.string "{JPN}あなたの たたかいかた わたしを\n"
	.string "ふった おとこを おもいだすわ……$"

