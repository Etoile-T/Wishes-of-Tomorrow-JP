PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "{JPN}うーん……\n"
	.string "いないなあ……$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "{JPN}ねえ きみきみ このあたりで\n"
	.string "キノココって ポケモン みなかった?\p"
	.string "おじさん あの ポケモン だいすき なのよね$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "{JPN}まちぶせ してやろうと おもったのに\n"
	.string "トウカのもりで いつまでも\l"
	.string "もたもた しやがって!\p"
	.string "まちくたびれて でてきて やったぜ!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "{JPN}やい! デボンの けんきゅういん!\p"
	.string "その しょるいを こっちに よこしやがれ!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "{JPN}ひやー!\p"
	.string "きみ ポケモントレーナー だよね\n"
	.string "おじさんを たすけてよぉ!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "{JPN}ああん? なにを するつもりだ?\n"
	.string "なんだ そいつを かばうってのか?\p"
	.string "アクアだんに たてつく やつは\n"
	.string "ガキだろうと ようしゃ しねえ!\p"
	.string "さあ しょうぶ しろ!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "{JPN}うそだろ! つ つよい じゃねーか!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "{JPN}むむむ…… アクアだんの\n"
	.string "じゃまを するとは なんて やつ!\l"
	.string "もう いっかい しょうぶ しろ!\p"
	.string "……と いいたい ところ だが\n"
	.string "もう てもちの ポケモンは いない……\p"
	.string "それに カナズミ シティにも アクアだんが\n"
	.string "ねらっている ものが あるからな!\p"
	.string "きょうは これぐらいに しといてやらぁ!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "{JPN}……ふぅ\n"
	.string "あぶない ところ だった!\p"
	.string "きみの おかげで だいじな しょるいを\n"
	.string "うばわれないで すんだよ!\p"
	.string "……そうだ! おれいに\n"
	.string "スーパーボールを あげちゃおう!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "{JPN}……そういえば さっき アクアだんの やつ\n"
	.string "「カナズミにも ねらっている ものがある」\l"
	.string "とか いってたよね……?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "{JPN}たいへんだ!!\n"
	.string "こうしちゃ いられない!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "{JPN}どうぐが いっぱいで\n"
	.string "スーパーボール あげられないね$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "{JPN}ポケモン いっぱい つかまえた!\p"
	.string "そら いけ!\n"
	.string "むしポケモン チーム!$"

PetalburgWoods_Text_ICouldntWin:
	.string "{JPN}こんなに ポケモン いるのに\n"
	.string "かてなかった……$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "{JPN}たくさん ポケモン つかまえたら\n"
	.string "モンスターボール なくなっちゃったよ$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "{JPN}むしポケモンを がっこうに もっていくと\n"
	.string "それだけで にんきもの なんだ!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "{JPN}まけると にんきものに なれないや$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "{JPN}でかい むしポケモン もってると\n"
	.string "それだけで そんけー されるんだ$"

PetalburgWoods_Text_IWantRematch1:
	.string "{JPN}むしポケモンが そだったら\n"
	.string "また しょうぶ してよ!\p"
	.string "ポケナビに とうろく しとくね!$"

PetalburgWoods_Text_IWantRematch2:
	.string "{JPN}むしポケモンが そだったら\n"
	.string "また しょうぶ してよ!\p"
	.string "ポケナビに とうろく しとくね!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "{JPN}むしポケモンが そだったぞ!\n"
	.string "これで また にんきもの だ!$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "{JPN}まけると にんきものに なれないや$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "{JPN}つよい ポケモン もってると\n"
	.string "にんきものに なれるだろ?\l"
	.string "だから がんばって そだててるのさ!$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "{JPN}よう!\n"
	.string "ポケモンの ちょうしは どうだい?\p"
	.string "ポケモンが よわくて しょうぶを\n"
	.string "さけたいなら たかい くさむらには\l"
	.string "はいらない ほうが いいぞ$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "{JPN}めに みえなくても じめんに\n"
	.string "なにか おちてる ことが あるんだ\p"
	.string "だから いつも あしもとを\n"
	.string "しらべながら あるいてるのさ$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "{JPN}あら すてき!\n"
	.string "それ カナズミジムの バッジね!\p"
	.string "あなた トレーナーなのね\n"
	.string "この どうぐを つかってみて$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "{JPN}それは きせきのタネ\n"
	.string "ポケモンに もたせてあげると\l"
	.string "くさタイプの わざが つよく なるのよ\p"
	.string "きせきのタネの ほかにも\n"
	.string "ポケモンに もたせると べんりな\l"
	.string "どうぐが あるらしいわね$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "{JPN}おとくな けいじばん!!\p"
	.string "しょうぶに 1かいでも でた ポケモンは\n"
	.string "けいけんちを もらえます\p"
	.string "よわい ポケモンを そだてるなら\n"
	.string "てもちの いちばん ひだりに おきましょう\p"
	.string "しょうぶが はじまったら すぐに\n"
	.string "いれかえれば きずつく ことなく\l"
	.string "けいけんちが もらえます!$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "{JPN}おとくな けいじばん!!\p"
	.string "ポケモンには ヒットポイント(HP)の ほかに\n"
	.string "わざを くりだす ための\l"
	.string "パワーポイント(PP)が あります\p"
	.string "PPが なくなったら\n"
	.string "ポケモンセンターに つれていきましょう$"

