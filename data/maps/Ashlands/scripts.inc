Ashlands_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Ashlands_OnResume
	.byte 0

@ Persistent "!" over the dying old man (local id 3) until he gets the
@ FENTANYL -- his hide flag fires at the same beat, so the marker's lifetime
@ matches his. flagindicator (not questindicator): the quest menu entry only
@ unlocks at the bow pickup, long after the giver beat.
Ashlands_OnResume::
	flagindicator 3, FLAG_FENTANYL_GIVEN
	end

@==============================================================================
@ THE DYING OLD MAN (lying in the ash) -- fetch quest for FENTANYL. Bring it and
@ he reveals who burned the world: TEAM MUTRID, and what they did with JIRACHI.
@==============================================================================
Ashlands_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_FENTANYL_GIVEN, Ashlands_EventScript_OldManAfter
	checkitem ITEM_FENTANYL
	compare VAR_RESULT, TRUE
	goto_if_eq Ashlands_EventScript_OldManReceive
	msgbox Ashlands_Text_OldManQuest, MSGBOX_DEFAULT
	compare VAR_QUEST_FATHERS_WISH, 0
	goto_if_ne Ashlands_EventScript_OldManQuestKnown
	closemessage
	setvar VAR_QUEST_FATHERS_WISH, 1
	bufferstring STR_VAR_1, Quest_Text_FathersFinalWishTitle
	call Quest_EventScript_NotifyStarted
Ashlands_EventScript_OldManQuestKnown::
	release
	end

@ Local ID 3 = the old man. After the lore he vanishes into ash
@ (FLAG_HIDE_ASHLANDS_OLD_MAN), unblocking the door to his house,
@ where the CATALPA BOW waits.
Ashlands_EventScript_OldManReceive::
	msgbox Ashlands_Text_OldManTakeItem, MSGBOX_DEFAULT
	removeitem ITEM_FENTANYL
	setflag FLAG_FENTANYL_GIVEN
	msgbox Ashlands_Text_OldManLore, MSGBOX_DEFAULT
	msgbox Ashlands_Text_OldManBequest, MSGBOX_DEFAULT
	closemessage
	playse SE_WARP_IN
	fadescreen FADE_TO_BLACK
	removeobject 3
	setflag FLAG_HIDE_ASHLANDS_OLD_MAN
	fadescreen FADE_FROM_BLACK
	msgbox Ashlands_Text_OldManGone, MSGBOX_DEFAULT
	closemessage
	setvar VAR_QUEST_FATHERS_WISH, 2
	bufferstring STR_VAR_1, Quest_Text_FathersFinalWishTitle
	call Quest_EventScript_NotifyUpdated
	release
	end

Ashlands_EventScript_OldManAfter::
	msgbox Ashlands_Text_OldManAfter, MSGBOX_DEFAULT
	release
	end

@==============================================================================
@ THE SAGE -- raving about the prophecy. Clearly lost his mind.
@==============================================================================
Ashlands_EventScript_Sage::
	lock
	faceplayer
	msgbox Ashlands_Text_Sage, MSGBOX_DEFAULT
	release
	end

@==============================================================================
@ TEXT
@==============================================================================
Ashlands_Text_OldManQuest:
	.string "{JPN}…はぁ… そこの… いきている ものよ。\p"
	.string "からだが もう もたん。 なんにちも まえに\n"
	.string "はいが むねに はいりこんでな。\p"
	.string "ここから にしの ふるい ほきゅうようの\n"
	.string "ボールに くすりが ある。 フェンタニルじゃ。\p"
	.string "それを もってきて くれたら… わしらを\n"
	.string "こうした ものの ことを はなそう。$"

Ashlands_Text_OldManTakeItem:
	.string "{JPN}{ENG}{PLAYER}{JPN}は フェンタニルを わたした。\p"
	.string "…ああ。 いたみが… ひいていく。\n"
	.string "ありがたい。$"

Ashlands_Text_OldManLore::
	.string "{JPN}はなせる うちに きいてくれ。\p"
	.string "ミュートリッドだんは はめつを あがめておる。\n"
	.string "その リーダーは わしの まごじゃ。\p"
	.string "わしは あいつに この やまの\n"
	.string "ぎしきを おしえた。 あいつの ちちにもな。\p"
	.string "わしの むすこ クラークソンはかせは\n"
	.string "ジラーチを しらべるために のぼった。\p"
	.string "その むすこは ジラーチを うばいに きた。\n"
	.string "ふめつの ねがいを。\p"
	.string "あいつの のぞみは ただ ひとつ。\nすべてを もやすこと。\p"
	.string "おまえも みたはずじゃ。 あいつが じぶんの\n"
	.string "ちちを ほのおに なげこむのを。\p"
	.string "それを した あの てに\n"
	.string "ぎしきを ひとつのこらず おしえたのは わしじゃ。\p"
	.string "この はいは あいつの ねがいが\nかたちに なったものじゃ。\p"
	.string "わしの いちぞくを とめられるのは\n"
	.string "おまえが さいごかも しれん。$"

Ashlands_Text_OldManAfter::
	.string "{JPN}ゆけ… すくえる ものが\n"
	.string "なくなって しまう まえに。$"

Ashlands_Text_OldManBequest::
	.string "{JPN}くすりで かせげたのは なんふんかじゃ。\n"
	.string "なんねんでは ない。 だいじに つかわせて くれ。\p"
	.string "わしの いえに いのりの ひもを はった\n"
	.string "アズサユミが かけてある。\p"
	.string "ぎしきでな。 はかで それを ならせば\n"
	.string "しんだ ものが ひとりきりに ならずに すむ。\p"
	.string "むすこは みずの むこうの\n"
	.string "こうえんで ねむっておる。\p"
	.string "あいつの ために ぎしきを してやってくれ…\n"
	.string "あいつの ちを ひく ものは けっして せん。\p"
	.string "そして はかいしに つたえてくれ…\p"
	.string "いまなら ちちは おまえを しんじておると。$"
Ashlands_Text_OldManGone:
	.string "{JPN}…\p"
	.string "ろうじんが よこたわっていた ところには\n"
	.string "こまかい はいが つもっている だけで\l"
	.string "もう かぜに ちらされはじめている。\p"
	.string "ろうじんの いえの とびらは\n"
	.string "かぎが はずれている。$"

Ashlands_Text_Sage:
	.string "{JPN}かなった！ よげんが\n"
	.string "かなったのだ！\p"
	.string "ほしが おち ねがいが となえられ\n"
	.string "そらは はいに かわった！ はははは！\p"
	.string "わからんのか？ われらが のぞんだのだ。\n"
	.string "われらを おわらせろと ねがいに すがったのだ。\p"
	.string "…おまえは ゆめを みる ものか ゆめそのものか？\n"
	.string "もう わしには みわけが つかん。\p"
	.string "はいは したの うえで ゆきの あじがする。\n"
	.string "うつくしいと おもわんか？$"

@ ----------------------------------------------------------------------------
@  West seam -> Ashlands_2. This boundary CANNOT be a map connection: Ashlands
@  uses the General primary tileset and Ashlands_2 uses NightMarket, and
@  connection crossings never reload the primary tileset or its animation
@  callback (only the secondary), so General's tiles + animations bleed into
@  every NightMarket map in the chain ("skewed textures"). A warp does a full
@  load, which swaps the primary cleanly.
@ ----------------------------------------------------------------------------
Ashlands_EventScript_SeamWest8::
	warp MAP_ASHLANDS_2, 24, 8
	waitstate
	end

@ ============================================================================
@  MAIN-QUEST GATE -- the west exit to Ashlands_Desert is blocked until the
@  CATALPA BOW is in hand (VAR_QUEST_FATHERS_WISH >= 3). Trigger column at
@  x=0, y=5-8 (the only walkable west-edge tiles) on VAR_TEMP_2.
@ ============================================================================
Ashlands_EventScript_WestGate::
	lockall
	@ Gate on the BOW ITSELF, not the quest stage -- the bow can be grabbed
	@ before the fentanyl delivery, which left the stage behind and walled
	@ off a player who already held it.
	checkitem ITEM_CATALPA_BOW
	goto_if_eq VAR_RESULT, TRUE, Ashlands_EventScript_WestGateOpen
	goto_if_eq VAR_QUEST_FATHERS_WISH, 2, Ashlands_EventScript_WestGateBow
	msgbox Ashlands_Text_OldManCallsOut, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Ashlands_Movement_TurnBack
	waitmovement 0
	releaseall
	end

Ashlands_EventScript_WestGateBow::
	msgbox Ashlands_Text_WestGateBow, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Ashlands_Movement_TurnBack
	waitmovement 0
	releaseall
	end

Ashlands_EventScript_WestGateOpen::
	setvar VAR_TEMP_2, 1
	releaseall
	end

Ashlands_Movement_TurnBack:
	walk_right
	step_end

Ashlands_Text_OldManCallsOut::
	.string "{JPN}ろうじん: たすけて… ゴホッ… たのむ\n"
	.string "たすけが ひつようなんじゃ。$"

Ashlands_Text_WestGateBow::
	.string "{JPN}ろうじんの さいごの ねがいが\n"
	.string "こころに のしかかる。\p"
	.string "ひがしの いえで アズサユミが\n"
	.string "まだ まっている。$"
