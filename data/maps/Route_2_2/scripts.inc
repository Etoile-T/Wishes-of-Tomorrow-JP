Route_2_2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route_2_2_OnResume
	.byte 0

Route_2_2_OnResume::
	@ Named ids, not object numbers: the numbers drifted when objects were added
	@ and put the "!" on Gible, Porygon and Blissey. The Eevee breeder is no
	@ longer on the map, so SIDE_QUEST_EIGHT_WAYS has no indicator here.
	questindicator LOCALID_PARK_METAL_COAT_GUY, SIDE_QUEST_HEAVY_METAL @ Scyther collector
	flagindicator LOCALID_PARK_CUT_TUTOR, FLAG_NATIONAL_PARK_CUT_GIVEN @ Cut tutor
	end

@ ===========================================================================
@ Park guide - welcomes the player and describes the wildlife
@ ===========================================================================
Route_2_2_EventScript_ParkGuide::
	lockall
	@ Keep the follower Pokemon out of the camera choreography: without this,
	@ every applymovement on the camera also force-hides the follower and every
	@ `waitmovement 0` waits on the follower's enter-ball movement too -- which
	@ can hang the script (permanent black screen / stuck controls) at the end
	@ of the tour. Same guard the engine's std sign scripts use.
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	faceplayer
	goto_if_set FLAG_NATIONAL_PARK_TOUR_DONE, Route_2_2_EventScript_ParkGuideAgain
	msgbox Route_2_2_Text_GuideWelcome, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	@ Cut to shot 1: pan east along y54 (x25 -> x35)
	fadescreen FADE_TO_BLACK
	applymovement LOCALID_CAMERA, Route_2_2_Movement_CamToShot1
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_CAMERA, Route_2_2_Movement_PanEast
	msgbox Route_2_2_Text_GuideShot1, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	@ Jump cut to shot 2: pan south along x51 (y51 -> y61)
	fadescreen FADE_TO_BLACK
	applymovement LOCALID_CAMERA, Route_2_2_Movement_CamToShot2
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_CAMERA, Route_2_2_Movement_PanSouth
	msgbox Route_2_2_Text_GuideShot2, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	@ Cut to final still at (47,19)
	fadescreen FADE_TO_BLACK
	applymovement LOCALID_CAMERA, Route_2_2_Movement_CamToShot3
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	msgbox Route_2_2_Text_GuideShot3, MSGBOX_DEFAULT
	closemessage
	@ Return control to the player
	fadescreen FADE_TO_BLACK
	@ Walk the camera back onto the player BEFORE removing it, or the player is
	@ left steering the camera. (net forward pan was east 18 / north 47)
	applymovement LOCALID_CAMERA, Route_2_2_Movement_CamReturn
	waitmovement 0
	special RemoveCameraObject
	fadescreen FADE_FROM_BLACK
	setflag FLAG_NATIONAL_PARK_TOUR_DONE
	msgbox Route_2_2_Text_GuideExitNorth, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

@ After the first tour she just gives a short greeting (no camera demo).
Route_2_2_EventScript_ParkGuideAgain::
	msgbox Route_2_2_Text_GuideAgain, MSGBOX_DEFAULT
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

@ Camera spawns on the player (29,66). Hidden moves use walk_faster (under a
@ fade); visible pans use walk_slow for a cinematic feel.
Route_2_2_Movement_CamToShot1:        @ 29,66 -> 25,54  (west 4, north 12)
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route_2_2_Movement_PanEast:           @ 25,54 -> 41,54  (east 16)
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

Route_2_2_Movement_CamToShot2:        @ 41,54 -> 51,51  (east 10, north 3)
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

Route_2_2_Movement_PanSouth:          @ 51,51 -> 51,69  (south 18)
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

Route_2_2_Movement_CamToShot3:        @ 51,69 -> 47,19  (west 4, north 50)
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

@ ===========================================================================
@ Item ball - TM Earthquake
@ ===========================================================================
Route_2_2_EventScript_TMEarthquake::
	lockall
	giveitem ITEM_TM_EARTHQUAKE
	setflag FLAG_ITEM_NATIONAL_PARK_TM_EARTHQUAKE
	removeobject VAR_LAST_TALKED
	releaseall
	end

@ ===========================================================================
@ Trainers (reuse existing parties, park-themed dialogue)
@ ===========================================================================
@ SIREN ALLISON: one-liner through the plate/portrait, boss card, battle.
@ The trainer flag is shared across acts, so the card fires exactly once --
@ at whichever of her encounters the player reaches first.
Route_2_2_EventScript_SwimmerAllison::
	goto_if_defeated TRAINER_ROUTE2_SWIMMER_ALLISON, Route_2_2_EventScript_AllisonAfter
	lockall
	setspeaker SP_NAME_ALLISON
	msgbox Route_2_2_Text_AllisonIntro, MSGBOX_DEFAULT
	closemessage
	@ Clear the SE bed so the banner shimmer is not fighting the surf.
	special WotSuppressWeatherSE
	special WotStopSceneSE
	bossintro BOSS_INTRO_ALLISON
	trainerbattle_no_intro TRAINER_ROUTE2_SWIMMER_ALLISON, Route_2_2_Text_AllisonDefeat
	setspeaker SP_NAME_ALLISON
	msgbox Route_2_2_Text_AllisonPost, MSGBOX_DEFAULT
	releaseall
	end

Route_2_2_EventScript_AllisonAfter::
	lock
	faceplayer
	setspeaker SP_NAME_ALLISON
	msgbox Route_2_2_Text_AllisonPost, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_SwimmerMarina::
	trainerbattle_single TRAINER_ROUTE2_SWIMMER_MARINA, Route_2_2_Text_MarinaIntro, Route_2_2_Text_MarinaDefeat
	msgbox Route_2_2_Text_MarinaPost, MSGBOX_AUTOCLOSE
	end

@ ===========================================================================
@ Friendly beachgoers
@ ===========================================================================
Route_2_2_EventScript_BeachGoer1::
	lock
	faceplayer
	msgbox Route_2_2_Text_BeachGoer1, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_BeachGoer2::
	lock
	faceplayer
	msgbox Route_2_2_Text_BeachGoer2, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_Picnicker::
	lock
	faceplayer
	msgbox Route_2_2_Text_Picnicker, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_Tuber::
	lock
	faceplayer
	msgbox Route_2_2_Text_Tuber, MSGBOX_DEFAULT
	release
	end

@ Eevee breeder - sells a (secretly shiny) baby Eevee for 10,000, one time
Route_2_2_EventScript_Beauty::
Route_2_2_EventScript_EeveeBreeder::
	lock
	faceplayer
	goto_if_set FLAG_NATIONAL_PARK_EEVEE_BREEDER, Route_2_2_EventScript_BreederAfter
	msgbox Route_2_2_Text_BreederIntro, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_UNLOCKED, SIDE_QUEST_EIGHT_WAYS
	call_if_eq VAR_RESULT, FALSE, Route_2_2_EventScript_StartEightWaysQuest
	msgbox Route_2_2_Text_BreederOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route_2_2_EventScript_BreederDecline
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, Route_2_2_EventScript_BreederNoMoney
	removemoney 10000
	givemon SPECIES_EEVEE, 5, shinyMode=SHINY_MODE_ALWAYS
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route_2_2_EventScript_BreederNoRoom
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route_2_2_Text_BreederGive, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_NATIONAL_PARK_EEVEE_BREEDER
	completequest SIDE_QUEST_EIGHT_WAYS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route_2_2_EventScript_BreederToPC
	release
	end

Route_2_2_EventScript_StartEightWaysQuest::
	startquest SIDE_QUEST_EIGHT_WAYS
	return

Route_2_2_EventScript_BreederToPC::
	msgbox Route_2_2_Text_BreederPC, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_BreederNoRoom::
	addmoney 10000
	msgbox Route_2_2_Text_BreederNoRoom, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_BreederNoMoney::
	msgbox Route_2_2_Text_BreederNoMoney, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_BreederDecline::
	msgbox Route_2_2_Text_BreederDecline, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_BreederAfter::
	msgbox Route_2_2_Text_BreederAfter, MSGBOX_DEFAULT
	release
	end

@ ===========================================================================
@ Ghosts drifting near the graves
@ ===========================================================================
Route_2_2_EventScript_Misdreavus::
	lock
	faceplayer
	msgbox Route_2_2_Text_Misdreavus, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_Haunter::
	lock
	faceplayer
	msgbox Route_2_2_Text_Haunter, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_Gastly::
	lock
	faceplayer
	msgbox Route_2_2_Text_Gastly, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_Duskull::
	lock
	faceplayer
	msgbox Route_2_2_Text_Duskull, MSGBOX_DEFAULT
	release
	end

@ ===========================================================================
@ Cute companion Pokemon wandering the park
@ ===========================================================================
Route_2_2_EventScript_PetMarill::
	lock
	faceplayer
	msgbox Route_2_2_Text_PetMarill, MSGBOX_DEFAULT
	release
	end

@ Frolicking Gible (object at 34,49). Dual label so it works whether the map
@ event points at the old or new name.
Route_2_2_EventScript_PetPikachu::
Route_2_2_EventScript_Gible::
	lock
	faceplayer
	msgbox Route_2_2_Text_Gible, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_PetEevee::
	lock
	faceplayer
	msgbox Route_2_2_Text_PetEevee, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_Wingull::
	lock
	faceplayer
	msgbox Route_2_2_Text_Wingull, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_Psyduck::
Route_2_2_EventScript_Sandile::
	lock
	faceplayer
	msgbox Route_2_2_Text_Sandile, MSGBOX_DEFAULT
	release
	end

@ ===========================================================================
@ Text
@ ===========================================================================
Route_2_2_Text_GuideWelcome:
	.string "{JPN}しぜんこうえんへ ようこそ！\p"
	.string "はじめて？ わたしたちの ちいさな らくえんを\n"
	.string "ごあんない しますね。$"

Route_2_2_Text_GuideShot1:
	.string "{JPN}にしの ひあたりの いい そうげんには\n"
	.string "いろんな かたちや いろの くさタイプの\l"
	.string "ポケモンが たくさん いますよ。$"

Route_2_2_Text_GuideShot2:
	.string "{JPN}みちを くだって ひがしの はまべへ いくと\n"
	.string "みずタイプの ポケモンが あさせで\l"
	.string "しぶきを あげて あそんでいます。$"

Route_2_2_Text_GuideShot3:
	.string "{JPN}そして きたには ふるい\n"
	.string "いれいひが…\p"
	.string "いまも やさしい たましいが はかの\n"
	.string "あいだを ただよって いるそうです。 いくなら\l"
	.string "しずかに おまいり してくださいね。$"

Route_2_2_Text_GuideExitNorth:
	.string "{JPN}あ もうひとつ！\p"
	.string "さきへ すすむ みちは こうえんの\n"
	.string "きたの はずれから でています。\p"
	.string "その みちは やまへと\n"
	.string "のぼっています。 あしもとに きを つけて。$"

Route_2_2_Text_GuideAgain:
	.string "{JPN}しぜんこうえんを たのしんで！\p"
	.string "にしは くさタイプ ひがしは みずと\n"
	.string "はまべですよ。$"

Route_2_2_Text_AllisonIntro:
	.string "{JPN}わたしの うさぎチームと\n"
	.string "しょうぶよ！$"

Route_2_2_Text_AllisonDefeat:
	.string "{JPN}まあ ひやけ できたし いっか！$"

Route_2_2_Text_AllisonPost:
	.string "{JPN}もっと うさぎを つかまえなきゃ！$"

Route_2_2_Text_MarinaIntro:
	.string "{JPN}わたしの ポケモンが うずうず してるの。\n"
	.string "あいては あなたよ！$"

Route_2_2_Text_MarinaDefeat:
	.string "{JPN}たのしかった！ いい しょうぶだったわ。$"

Route_2_2_Text_MarinaPost:
	.string "{JPN}はまべから つりを すると\n"
	.string "いろんな ポケモンが つれるわよ。$"

Route_2_2_Text_BeachGoer1:
	.string "{JPN}ごご ずっと うかんで すごしたよ。\n"
	.string "この こうえんは らくえんだね！$"

Route_2_2_Text_BeachGoer2:
	.string "{JPN}なかまと くるまで ポケモンを すなはまで\n"
	.string "あそばせに きたんだ。$"

Route_2_2_Text_Picnicker:
	.string "{JPN}この カニカニバーガー たべきりたいけど\n"
	.string "もう クソ おなか いっぱい…\n"
	.string "まあ いっか。$"

Route_2_2_Text_Tuber:
	.string "{JPN}みて みて！ マリルが しっぽで\n"
	.string "うかぶように なったの！ かわいい！$"

Route_2_2_Text_BreederIntro:
	.string "{JPN}あら こんにちは！ ずいぶん\n"
	.string "おぎょうぎの いい トレーナーさんね。\p"
	.string "わたし ここで イーブイを そだてているの。\n"
	.string "けなみが かがやくまで ブラシを かけてね。\p"
	.string "ほんとうの うつくしさは ていねいな\n"
	.string "おていれから はじまるのよ。$"

Route_2_2_Text_BreederOffer:
	.string "{JPN}うちの イーブイに とっても かわいい\n"
	.string "こどもたちが うまれたの。\p"
	.string "あなたみたいな やさしい トレーナーさんになら\n"
	.string "1ぴき ゆずっても いいわ…\p"
	.string "そうね 10000円で どうかしら？$"

Route_2_2_Text_BreederGive:
	.string "{JPN}すてき！ はい あなたの おちびさんよ。\p"
	.string "まいにち ブラシを かけてあげれば\n"
	.string "とっても きれいに そだつわ！$"

Route_2_2_Text_BreederPC:
	.string "{JPN}あら てもちが いっぱい だから\n"
	.string "イーブイちゃんは パソコンに おくったわ。$"

Route_2_2_Text_BreederNoMoney:
	.string "{JPN}あらあら すこし たりないわね。\p"
	.string "10000円 たまったら\n"
	.string "また きてね。$"

Route_2_2_Text_BreederNoRoom:
	.string "{JPN}まあ てもちにも パソコンにも\n"
	.string "あきが ないじゃないの！\p"
	.string "おかねは おかえしするわ。 また\n"
	.string "きてちょうだいね。$"

Route_2_2_Text_BreederDecline:
	.string "{JPN}いらない？ ぜんぜん かまわないわ。\p"
	.string "イーブイは ほんとうに ほしい ひとの\n"
	.string "ところへ いくべき だもの。$"

Route_2_2_Text_BreederAfter:
	.string "{JPN}イーブイちゃんは げんき？\p"
	.string "けなみを ととのえて おけば\n"
	.string "ほしみたいに かがやくわよ！$"

Route_2_2_Text_Misdreavus:
	.string "{JPN}ムウマ: ムゥゥ…\p"
	.string "くすくす わらって ちかよってきたかと おもうと\n"
	.string "きりの なかへ さっと きえていった。$"

Route_2_2_Text_Haunter:
	.string "{JPN}ゴーストが はかの うえに うかび\n"
	.string "にたにた わらいながら こちらを みている。$"

Route_2_2_Text_Gastly:
	.string "{JPN}ゴースが むらさきの もやを まといながら\n"
	.string "すぎていった。 せすじが\l"
	.string "ぞくっとした。$"

Route_2_2_Text_Duskull:
	.string "{JPN}ヨマワルが はかいしの あいだに\n"
	.string "みはりの ように しずかに うかんでいる。$"

Route_2_2_Text_PetMarill:
	.string "{JPN}マリルが みずぎわを たのしそうに\n"
	.string "はねている。$"

Route_2_2_Text_Gible:
	.string "{JPN}フカマルが たかい くさの なかを はしりまわり\n"
	.string "まいおちる はなびらに\l"
	.string "じゃれついている。$"

Route_2_2_Text_PetEevee:
	.string "{JPN}イーブイが あたたかい すなの うえを ころがり\n"
	.string "こちらを みあげて まばたきした。$"

Route_2_2_Text_Wingull:
	.string "{JPN}キャモメが うみかぜに のって\n"
	.string "あたまの うえを まわっている。$"

Route_2_2_Text_Sandile:
	.string "{JPN}メグロコが あたたかい すなに うもれて\n"
	.string "めだけを だして のんびりしている。$"

@ ===========================================================================
@ Added beachgoer trainers (Eddie, Finn) + Metal Coat trade NPC
@ ===========================================================================
Route_2_2_EventScript_TuberEddie::
	trainerbattle_single TRAINER_NATIONAL_PARK_TUBER_EDDIE, Route_2_2_Text_EddieIntro, Route_2_2_Text_EddieDefeat
	msgbox Route_2_2_Text_EddiePost, MSGBOX_AUTOCLOSE
	end

Route_2_2_EventScript_SwimmerFinn::
	trainerbattle_single TRAINER_NATIONAL_PARK_SWIMMER_FINN, Route_2_2_Text_FinnIntro, Route_2_2_Text_FinnDefeat
	msgbox Route_2_2_Text_FinnPost, MSGBOX_AUTOCLOSE
	end

@ Repeatable: he takes any Scyther brought to him, every time. The starter is
@ given BEFORE the Scyther is taken so a full party+boxes can never eat the
@ player's Scyther without a reward. Every one of the three is a GUARANTEED
@ shiny -- a Scyther is a steep price, and the little buddy should show it.
Route_2_2_EventScript_MetalCoatGuy::
	lock
	faceplayer
	msgbox Route_2_2_Text_MetalCoatIntro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route_2_2_EventScript_MetalCoatDecline
	setvar VAR_0x8004, SPECIES_SCYTHER
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	compare VAR_RESULT, FALSE
	goto_if_eq Route_2_2_EventScript_MetalCoatNoScyther
	random 3
	compare VAR_RESULT, 0
	goto_if_eq Route_2_2_EventScript_MetalCoatBulbasaur
	compare VAR_RESULT, 1
	goto_if_eq Route_2_2_EventScript_MetalCoatCharmander
	goto Route_2_2_EventScript_MetalCoatSquirtle

Route_2_2_EventScript_MetalCoatBulbasaur::
	givemon SPECIES_BULBASAUR, 5, shinyMode=SHINY_MODE_ALWAYS
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq Route_2_2_EventScript_MetalCoatNoRoom
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	goto Route_2_2_EventScript_MetalCoatGrant

Route_2_2_EventScript_MetalCoatCharmander::
	givemon SPECIES_CHARMANDER, 5, shinyMode=SHINY_MODE_ALWAYS
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq Route_2_2_EventScript_MetalCoatNoRoom
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	goto Route_2_2_EventScript_MetalCoatGrant

Route_2_2_EventScript_MetalCoatSquirtle::
	givemon SPECIES_SQUIRTLE, 5, shinyMode=SHINY_MODE_ALWAYS
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq Route_2_2_EventScript_MetalCoatNoRoom
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	goto Route_2_2_EventScript_MetalCoatGrant

Route_2_2_EventScript_MetalCoatGrant::
	setvar VAR_0x8004, SPECIES_SCYTHER
	special TakeFirstMonOfSpecies
	msgbox Route_2_2_Text_MetalCoatThanks, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_COMPLETE, SIDE_QUEST_HEAVY_METAL
	call_if_eq VAR_RESULT, FALSE, Route_2_2_EventScript_CompleteHeavyMetalQuest
	release
	end

Route_2_2_EventScript_CompleteHeavyMetalQuest::
	completequest SIDE_QUEST_HEAVY_METAL
	return

Route_2_2_EventScript_MetalCoatNoRoom::
	msgbox Route_2_2_Text_MetalCoatNoRoom, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_MetalCoatNoScyther::
	msgbox Route_2_2_Text_MetalCoatNoScyther, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_UNLOCKED, SIDE_QUEST_HEAVY_METAL
	call_if_eq VAR_RESULT, FALSE, Route_2_2_EventScript_StartHeavyMetalQuest
	release
	end

Route_2_2_EventScript_MetalCoatDecline::
	msgbox Route_2_2_Text_MetalCoatDeclineMsg, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_UNLOCKED, SIDE_QUEST_HEAVY_METAL
	call_if_eq VAR_RESULT, FALSE, Route_2_2_EventScript_StartHeavyMetalQuest
	release
	end

Route_2_2_EventScript_StartHeavyMetalQuest::
	startquest SIDE_QUEST_HEAVY_METAL
	return

Route_2_2_EventScript_MetalCoatDone::
	msgbox Route_2_2_Text_MetalCoatAfter, MSGBOX_DEFAULT
	release
	end

Route_2_2_Text_EddieIntro:
	.string "{JPN}せかいいち おおきな すなのしろを つくったら\n"
	.string "なにかが すみついちゃった！$"

Route_2_2_Text_EddieDefeat:
	.string "{JPN}あーあ すなのしろチームが まけちゃった！$"

Route_2_2_Text_EddiePost:
	.string "{JPN}ぼくの スナバァが この はまを まもってるんだ。\n"
	.string "ひきずりこまれないように きを つけてね！$"

Route_2_2_Text_FinnIntro:
	.string "{JPN}この あたりの いそだまりには\n"
	.string "ふしぎな いきものが かくれてるんだ！$"

Route_2_2_Text_FinnDefeat:
	.string "{JPN}うみの いきものに くわしいんだね！$"

Route_2_2_Text_FinnPost:
	.string "{JPN}ヒドイデは おもいがけない ところに\n"
	.string "かくれてるよ。 あしもとに きを つけて！$"

Route_2_2_Text_MetalCoatIntro:
	.string "{JPN}みてよ すなの なかから ぴかぴかの\n"
	.string "メタルコートを ほりだしたんだ！\p"
	.string "ストライクに もたせると すがたが かわるって\n"
	.string "いうんだ… みてみたいなあ。\p"
	.string "ストライクを ゆずって くれない？\n"
	.string "かわりに ちいさな あいぼうを あげるよ！$"

Route_2_2_Text_MetalCoatDeclineMsg:
	.string "{JPN}だめ？ いいよ。 きが かわったら\n"
	.string "また きてね！$"

Route_2_2_Text_MetalCoatNoScyther:
	.string "{JPN}うーん いまは ストライクを もってないね。\n"
	.string "つれてきたら おしえて！$"

Route_2_2_Text_MetalCoatThanks:
	.string "{JPN}うわあ ほんものの ストライク！ すごい！\p"
	.string "はい おれいに この こを あげる。\n"
	.string "だれかは おたのしみ！\p"
	.string "{ENG}{STR_VAR_1}{JPN}を もらった！$"

Route_2_2_Text_MetalCoatNoRoom:
	.string "{JPN}わわっ てもちも ボックスも\n"
	.string "ぎっしり いっぱいだよ！\p"
	.string "おれいの プレゼントが はいる あきを つくって\n"
	.string "また きてね。$"

Route_2_2_Text_MetalCoatAfter:
	.string "{JPN}あの ストライクと メタルコート\n"
	.string "いい なかまに なるよ。 ありがとう！$"

@ ===========================================================================
@ Cut tutor - gives HM01 (Cut) and points to the Walnut Woods shortcut
@ ===========================================================================
Route_2_2_EventScript_CutTutor::
	lock
	faceplayer
	goto_if_set FLAG_NATIONAL_PARK_CUT_GIVEN, Route_2_2_EventScript_CutTutorAfter
	msgbox Route_2_2_Text_CutTutorIntro, MSGBOX_DEFAULT
	giveitem ITEM_HM01
	goto_if_eq VAR_RESULT, FALSE, Route_2_2_EventScript_CutTutorBagFull
	setflag FLAG_NATIONAL_PARK_CUT_GIVEN
	msgbox Route_2_2_Text_CutTutorShortcut, MSGBOX_DEFAULT
	release
	end

Route_2_2_EventScript_CutTutorBagFull::
	release
	end

Route_2_2_EventScript_CutTutorAfter::
	msgbox Route_2_2_Text_CutTutorAfter, MSGBOX_DEFAULT
	release
	end

Route_2_2_Text_CutTutorIntro:
	.string "{JPN}クルミのもりへ いくの？ ちかくに\n"
	.string "ちかみちが あるけど おおきな きが\l"
	.string "みちを ふさいでるんだ。\p"
	.string "ほら これを あげる！$"

Route_2_2_Text_CutTutorShortcut:
	.string "{JPN}てもちの だれかに いあいぎりを おぼえさせて\n"
	.string "あの きを きりたおすと いい。\p"
	.string "クルミのもりへ まっすぐ もどれる\n"
	.string "ちかみちだよ。 ためして\l"
	.string "みてね！$"

Route_2_2_Text_CutTutorAfter:
	.string "{JPN}あの きを きりたおせば クルミのもりへの\n"
	.string "ちかみちに なるよ。$"

@ ===========================================================================
@ Trail signs - the north path out of the park climbs to Mount Munen
@ ===========================================================================
Route_2_2_EventScript_MountMunenSign1::
	msgbox Route_2_2_Text_MountMunenSign1, MSGBOX_SIGN
	end

Route_2_2_EventScript_MountMunenSign2::
	msgbox Route_2_2_Text_MountMunenSign2, MSGBOX_SIGN
	end

Route_2_2_Text_MountMunenSign1:
	.string "{JPN}しぜんこうえん とざんぐち\p"
	.string "{UP_ARROW} きた: ムネンやま\n"
	.string "けわしい みち。 あたたかい ふくそうで。$"

Route_2_2_Text_MountMunenSign2:
	.string "{JPN}{UP_ARROW} きた: ムネンやま\n"
	.string "やまみち けいゆで ムネンむら$"

@ ===========================================================================
@ Gravesite - foreshadows the summit now; hidden Prof. Clarkson note after flag
@ ===========================================================================
Route_2_2_EventScript_Gravesite::
	lockall
	goto_if_set FLAG_NATIONAL_PARK_GRAVE_SECRET, Route_2_2_EventScript_GravesiteSecret
	msgbox Route_2_2_Text_Gravesite, MSGBOX_DEFAULT
	releaseall
	end

Route_2_2_EventScript_GravesiteSecret::
	msgbox Route_2_2_Text_GravesiteClarkson, MSGBOX_DEFAULT
	releaseall
	end

Route_2_2_Text_Gravesite:
	.string "{JPN}おごそかな はかいしが\n"
	.string "とおくの さんちょうを むいている。\p"
	.string "「のぼりて かえらぬ ものたちへ。\n"
	.string "やまは\l"
	.string "おぼえている」\p"
	.string "つめたい かぜが いただきから\n"
	.string "ふきおろしてくる。$"

Route_2_2_Text_GravesiteClarkson:
	.string "{JPN}はかいしの うしろに たたんだばかりの\n"
	.string "メモが はさまっている。\p"
	.string "「これを よんでいるなら わしは\n"
	.string "いきて おりられたと いうことだ。\p"
	.string "さんちょうで みたものを しんじるな。\n"
	.string "のぼりつづけろ。\p"
	.string "ー クラークソンはかせ」$"

Route_2_2_Movement_CamReturn:         @ ghosts (47,19) -> player spawn  (west 18, south 47)
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end
