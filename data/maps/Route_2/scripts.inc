	.equ LOCALID_ROUTE2_ALLISON, 6
	.equ ALLISON_SEA_X, 10
	.equ ALLISON_SEA_Y, 27
	.equ ALLISON_SURF_X, 13

Route_2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route_2_OnTransition
	.byte 0

Route_2_OnTransition::
	@ Siren Allison spawns out in the sea, so her template graphic has to be
	@ the swimming sprite every time the map loads. It is a VAR graphic purely
	@ so the approach scene can swap in the walking sprite when she comes
	@ ashore; this puts it back.
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SWIMMER_ALLISON
	@ The approach scene moves her template with setobjectxyperm to respawn her
	@ on the walking sprite. Templates live in the save block, so put her back
	@ out at sea here rather than letting her creep towards the beach a little
	@ further with every encounter.
	setobjectxyperm LOCALID_ROUTE2_ALLISON, ALLISON_SEA_X, ALLISON_SEA_Y
	end

@ -- Route 2 grinding trainers (weak, pre-Gym-1) --

Route_2_EventScript_Fisherman::
	trainerbattle_single TRAINER_ROUTE2_FISHERMAN, Route_2_Text_FishermanIntro, Route_2_Text_FishermanDefeat
	msgbox Route_2_Text_FishermanPost, MSGBOX_AUTOCLOSE
	end

Route_2_EventScript_Hiker::
	trainerbattle_single TRAINER_ROUTE2_HIKER, Route_2_Text_HikerIntro, Route_2_Text_HikerDefeat
	msgbox Route_2_Text_HikerPost, MSGBOX_AUTOCLOSE
	end

Route_2_EventScript_Camper::
	trainerbattle_single TRAINER_ROUTE2_CAMPER, Route_2_Text_CamperIntro, Route_2_Text_CamperDefeat
	msgbox Route_2_Text_CamperPost, MSGBOX_AUTOCLOSE
	end

Route_2_Text_FishermanIntro:
	.string "{JPN}きょうは さっぱり つれねえ…\n"
	.string "おまえなら くいついて くれるか？$"

Route_2_Text_FishermanDefeat:
	.string "{JPN}つりあげられて リリースされちまった…$"

Route_2_Text_FishermanPost:
	.string "{JPN}おおものは センネンせんの さきの\n"
	.string "ほうに いるんだ。 また でんしゃが\l"
	.string "うごけば の はなしだがな。$"

Route_2_Text_HikerIntro:
	.string "{JPN}この さかで きたえてから\n"
	.string "フロストウッドの ジムに いどむんだな！$"

Route_2_Text_HikerDefeat:
	.string "{JPN}ふう！ いい あしこしを してるな！$"

Route_2_Text_HikerPost:
	.string "{JPN}ここで しっかり きたえておけ。 あそこの\n"
	.string "ジムリーダーは しんまいにも てかげん しないぞ。$"

Route_2_Text_CamperIntro:
	.string "{JPN}テントを はってる ところを みつかったか。\n"
	.string "ひっさつわざを くらえ！$"

Route_2_Text_CamperDefeat:
	.string "{JPN}あああ まいったあ！$"

Route_2_Text_CamperPost:
	.string "{JPN}レベルを あげたいなら この あたりには\n"
	.string "やせいの ポケモンが たくさん いるよ。$"

@ -- Ambient wandering wild POKéMON (cry on talk, no battle) --

Route_2_EventScript_WildZigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox Route_2_Text_WildZigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route_2_EventScript_WildPoochyena::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, 0
	msgbox Route_2_Text_WildPoochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route_2_EventScript_WildWingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox Route_2_Text_WildWingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route_2_EventScript_WildPsyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, 0
	msgbox Route_2_Text_WildPsyduck, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route_2_Text_WildZigzagoon:
	.string "{JPN}ジグザグマが しげみの なかを\n"
	.string "ジグザグに すすんでいる！$"

Route_2_Text_WildPoochyena:
	.string "{JPN}ポチエナは こちらを けいかいして みつめ\n"
	.string "みちの むこうへ かけていった。$"

Route_2_Text_WildWingull:
	.string "{JPN}キャモメが そらを まわり ないて\n"
	.string "ちかくに おりたった！$"

Route_2_Text_WildPsyduck:
	.string "{JPN}コダァァァ\n"
	.string "ックゥゥ$"

@ ===========================================================================
@ SIREN ALLISON -- the approach.
@
@ Her trainer sight only ever worked on a surfing player, and that is
@ structural rather than a mistake: CheckPathBetweenTrainerAndPlayer walks
@ every tile between trainer and player and refuses the sighting on the first
@ collision, and a water-bound object is blocked the moment that path steps up
@ onto the sand. So sight still handles players out on the water, and the
@ shore trigger at (16,27) handles players wading in from the beach -- she
@ notices, swims in, stands up in the surf and walks the last two tiles.
@
@ Geometry of row 27: x<=15 is OCEAN_WATER, x>=16 is the SHALLOW_WATER band
@ the player is standing in when the trigger fires. So she swims 10 -> 13,
@ changes to her walking sprite there, and wades 13 -> 15, finishing right in
@ front of the player. Scripted applymovement never collision-checks, which is
@ what lets her cross the waterline at all.
@
@ ALLISON_SEA_X/Y must match her object in map.json, because OnTransition
@ stamps them back onto her (save-block) template every time the map loads.
@ ===========================================================================

Route_2_EventScript_AllisonNotice::
	goto_if_defeated TRAINER_ROUTE2_SWIMMER_ALLISON, Route_2_EventScript_AllisonNoticeDone
	setvar VAR_TEMP_1, 1
	lockall
	@ The trigger can be walked onto from the beach or from either side, so
	@ point the player out to sea before she is worth looking at.
	applymovement OBJ_EVENT_ID_PLAYER, Route_2_Movement_PlayerLooksOut
	waitmovement 0
	applymovement LOCALID_ROUTE2_ALLISON, Route_2_Movement_AllisonSpot
	waitmovement 0
	delay 20
	@ Three strokes in, a splash on each -- one long SE would be over before
	@ she arrived, so the wash is retriggered per tile as she closes.
	playse SE_M_SURF
	applymovement LOCALID_ROUTE2_ALLISON, Route_2_Movement_AllisonStroke
	waitmovement 0
	playse SE_M_SURF
	applymovement LOCALID_ROUTE2_ALLISON, Route_2_Movement_AllisonStroke
	waitmovement 0
	playse SE_M_SURF
	applymovement LOCALID_ROUTE2_ALLISON, Route_2_Movement_AllisonStroke
	waitmovement 0
	@ Out of the water. An object cannot be handed a new graphic in place, so
	@ she is respawned on the tile she swam to: remove -> setobjectxyperm (the
	@ template, not the live object) -> add. She stands up in the surf on the
	@ walking sprite and then wades the last two tiles up to the player.
	playse SE_M_DIVE
	removeobject LOCALID_ROUTE2_ALLISON
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WOT_ALLISON_LAND
	setobjectxyperm LOCALID_ROUTE2_ALLISON, ALLISON_SURF_X, ALLISON_SEA_Y
	addobject LOCALID_ROUTE2_ALLISON
	delay 20
	playse SE_PUDDLE
	applymovement LOCALID_ROUTE2_ALLISON, Route_2_Movement_AllisonWade
	waitmovement 0
	playse SE_PUDDLE
	applymovement LOCALID_ROUTE2_ALLISON, Route_2_Movement_AllisonWade
	waitmovement 0
	delay 16
	goto Route_2_EventScript_AllisonChallenge
	end

Route_2_EventScript_AllisonNoticeDone::
	end

@ She has four openers, three taunts on the way down and three parting lines,
@ rolled independently, so the fight does not read the same way twice.
Route_2_EventScript_AllisonChallenge::
	setspeaker SP_NAME_ALLISON
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route_2_EventScript_AllisonIntro0
	call_if_eq VAR_0x8008, 1, Route_2_EventScript_AllisonIntro1
	call_if_eq VAR_0x8008, 2, Route_2_EventScript_AllisonIntro2
	call_if_eq VAR_0x8008, 3, Route_2_EventScript_AllisonIntro3
	closemessage
	@ Flush every SE player before the card. Her banner's shimmer (SE_M_DETECT)
	@ shares the SE channels with the splashes that just played, and the same
	@ collision is what made Edwards' card sound cut out until his scene was
	@ made to clear the bed first.
	special WotSuppressWeatherSE
	special WotStopSceneSE
	bossintro BOSS_INTRO_ALLISON
	@ The defeat line belongs to the battle command, so each variant is its own
	@ trainerbattle_no_intro.
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 1, Route_2_EventScript_AllisonBattle1
	goto_if_eq VAR_0x8008, 2, Route_2_EventScript_AllisonBattle2
	trainerbattle_no_intro TRAINER_ROUTE2_SWIMMER_ALLISON, Route_2_Text_AllisonDefeat0
	goto Route_2_EventScript_AllisonBeaten

Route_2_EventScript_AllisonBattle1::
	trainerbattle_no_intro TRAINER_ROUTE2_SWIMMER_ALLISON, Route_2_Text_AllisonDefeat1
	goto Route_2_EventScript_AllisonBeaten

Route_2_EventScript_AllisonBattle2::
	trainerbattle_no_intro TRAINER_ROUTE2_SWIMMER_ALLISON, Route_2_Text_AllisonDefeat2
	goto Route_2_EventScript_AllisonBeaten

Route_2_EventScript_AllisonBeaten::
	setspeaker SP_NAME_ALLISON
	call Route_2_EventScript_AllisonSayPost
	releaseall
	end

Route_2_EventScript_AllisonSayPost::
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, Route_2_EventScript_AllisonPost0
	call_if_eq VAR_0x8008, 1, Route_2_EventScript_AllisonPost1
	call_if_eq VAR_0x8008, 2, Route_2_EventScript_AllisonPost2
	return

Route_2_EventScript_AllisonIntro0::
	msgbox Route_2_Text_AllisonIntro0, MSGBOX_DEFAULT
	return

Route_2_EventScript_AllisonIntro1::
	msgbox Route_2_Text_AllisonIntro1, MSGBOX_DEFAULT
	return

Route_2_EventScript_AllisonIntro2::
	msgbox Route_2_Text_AllisonIntro2, MSGBOX_DEFAULT
	return

Route_2_EventScript_AllisonIntro3::
	msgbox Route_2_Text_AllisonIntro3, MSGBOX_DEFAULT
	return

Route_2_EventScript_AllisonPost0::
	msgbox Route_2_Text_AllisonPost0, MSGBOX_DEFAULT
	return

Route_2_EventScript_AllisonPost1::
	msgbox Route_2_Text_AllisonPost1, MSGBOX_DEFAULT
	return

Route_2_EventScript_AllisonPost2::
	msgbox Route_2_Text_AllisonPost2, MSGBOX_DEFAULT
	return

Route_2_Movement_PlayerLooksOut:
	face_left
	step_end

Route_2_Movement_AllisonSpot:
	emote_exclamation_mark
	delay_16
	step_end

Route_2_Movement_AllisonStroke:
	walk_right
	step_end

Route_2_Movement_AllisonWade:
	walk_slow_right
	step_end

@ Talking to her out on the water (her trainer sight, or a surfing player)
@ skips the approach and goes straight to the challenge.
Route_2_EventScript_SwimmerAllison::
	goto_if_defeated TRAINER_ROUTE2_SWIMMER_ALLISON, Route_2_EventScript_AllisonAfter
	lockall
	goto Route_2_EventScript_AllisonChallenge
	end

Route_2_EventScript_AllisonAfter::
	lock
	faceplayer
	setspeaker SP_NAME_ALLISON
	call Route_2_EventScript_AllisonSayPost
	release
	end

Route_2_Text_AllisonIntro0:
	.string "{JPN}しがいせんしすう 9…\n"
	.string "なのに あなた ひざしを さえぎってる。$"

Route_2_Text_AllisonIntro1:
	.string "{JPN}あら わたしの ために わざわざ\n"
	.string "みずべまで おりてきたの？\p"
	.string "かわいいわね。\n"
	.string "かんちがい だけど かわいいわ。$"

Route_2_Text_AllisonIntro2:
	.string "{JPN}きを つけてね かわいこちゃん。\p"
	.string "この ビーチの きれいな ものは みんな\n"
	.string "とげが あるのよ。$"

Route_2_Text_AllisonIntro3:
	.string "{JPN}かたせて あげても いいけど…\p"
	.string "だめ。 やっぱり むりだわ。$"

Route_2_Text_AllisonDefeat0:
	.string "{JPN}ころっと まいっちゃった… たっても\n"
	.string "いないのにね！$"

Route_2_Text_AllisonDefeat1:
	.string "{JPN}わかったわよ！ あなたの かち！\p"
	.string "しおみずが めに しみただけ。\n"
	.string "ただ それだけよ。$"

Route_2_Text_AllisonDefeat2:
	.string "{JPN}もう… かってる ときの あなたって\n"
	.string "ぜんぜん かわいくない。$"

Route_2_Text_AllisonPost0:
	.string "{JPN}わたしの ラブカス あなたを みたら\n"
	.string "およぎかたを わすれちゃった。 わたしもよ。$"

Route_2_Text_AllisonPost1:
	.string "{JPN}リベンジ？ いいわよ。\p"
	.string "ひやけと おひるねと ふくしゅうの\n"
	.string "けいかくが すんだらね。$"

Route_2_Text_AllisonPost2:
	.string "{JPN}こやの おとこのこたちに いってあげて。\n"
	.string "セイレーンが とおして くれたって。\p"
	.string "ぜったい しんじて もらえないわよ。$"

Route_2_EventScript_SwimmerSkye::
	trainerbattle_single TRAINER_ROUTE2_SWIMMER_SKYE, Route_2_Text_SkyeIntro, Route_2_Text_SkyeDefeat
	msgbox Route_2_Text_SkyePost, MSGBOX_AUTOCLOSE
	end

Route_2_EventScript_SwimmerRosa::
	trainerbattle_single TRAINER_ROUTE2_SWIMMER_ROSA, Route_2_Text_RosaIntro, Route_2_Text_RosaDefeat
	msgbox Route_2_Text_RosaPost, MSGBOX_AUTOCLOSE
	end

Route_2_EventScript_SwimmerMarina::
	trainerbattle_single TRAINER_ROUTE2_SWIMMER_MARINA, Route_2_Text_MarinaIntro, Route_2_Text_MarinaDefeat
	msgbox Route_2_Text_MarinaPost, MSGBOX_AUTOCLOSE
	end

Route_2_Text_SkyeIntro:
	.string "{JPN}ながれぼしを まって ここで\n"
	.string "うかんでたの… あなたで いいわ！$"

Route_2_Text_SkyeDefeat:
	.string "{JPN}あなたに おちるのは かんたん だったわ！$"

Route_2_Text_SkyePost:
	.string "{JPN}センネンせんが また うごいてるって。\n"
	.string "いつか あたたかい ところへ つれてって？$"

Route_2_Text_RosaIntro:
	.string "{JPN}せんねん こおってた こおりを とかすのが\n"
	.string "あなた だなんて！ ずるい！$"

Route_2_Text_RosaDefeat:
	.string "{JPN}おちついて わたしの サニーゴハート！$"

Route_2_Text_RosaPost:
	.string "{JPN}スターサミットに のぼるなら わたしの ぶんも\n"
	.string "ねがって くれる？ ちょっとだけで いいから。$"

Route_2_Text_MarinaIntro:
	.string "{JPN}きを つけて かわいこちゃん。 ながれは\n"
	.string "はやいし わたしも つよいわよ！$"

Route_2_Text_MarinaDefeat:
	.string "{JPN}うっ… さくせんが まるごと しずんじゃった！$"

Route_2_Text_MarinaPost:
	.string "{JPN}つよくて すてき？ はかせは\n"
	.string "あなたが いて しあわせものね。$"

@ ---------------------------------------------------------------------------
@  Beach crowd -- the blizzard is one town south; here it is towel weather.
@ ---------------------------------------------------------------------------
Route_2_EventScript_YachtSign::
	lockall
	msgbox Route_2_Text_YachtSign, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route_2_EventScript_YachtSignDone
	@ The joke finally pays off: the fisherman's key starts her.
	checkitem ITEM_YACHT_KEY
	goto_if_eq VAR_RESULT, TRUE, Route_2_EventScript_YachtBoard
	msgbox Route_2_Text_YachtFailed, MSGBOX_DEFAULT
Route_2_EventScript_YachtSignDone::
	releaseall
	end

Route_2_EventScript_YachtBoard::
	msgbox Route_2_Text_YachtStarts, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	fadescreen FADE_TO_BLACK
	warp MAP_YACHT_INTERIOR, 0
	waitstate
	releaseall
	end

@ Walking up the gangway at (40,17) without the key. The gangway is an arrow
@ warp; WotGetLockedDoorScript (field_control_avatar.c) runs this in place of
@ it, as the Frostwood Gym door does. Same exchange as reading the sign, then
@ a step back so a held UP doesn't run it again.
Route_2_EventScript_YachtLocked::
	lockall
	msgbox Route_2_Text_YachtSign, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route_2_EventScript_YachtStepBack
	msgbox Route_2_Text_YachtFailed, MSGBOX_DEFAULT
Route_2_EventScript_YachtStepBack::
	closemessage
	applymovement LOCALID_PLAYER, Route_2_Movement_StepBackFromYacht
	waitmovement 0
	releaseall
	end

Route_2_Movement_StepBackFromYacht:
	walk_down
	step_end

Route_2_EventScript_TuberSandy::
	trainerbattle_single TRAINER_CINDY_2, Route_2_Text_SandyIntro, Route_2_Text_SandyDefeat
	msgbox Route_2_Text_SandyPost, MSGBOX_AUTOCLOSE
	end

Route_2_EventScript_TuberCoco::
	trainerbattle_single TRAINER_LUCAS_2, Route_2_Text_CocoIntro, Route_2_Text_CocoDefeat
	msgbox Route_2_Text_CocoPost, MSGBOX_AUTOCLOSE
	end

Route_2_EventScript_ExpertPete::
	trainerbattle_single TRAINER_MIKE_1, Route_2_Text_PeteIntro, Route_2_Text_PeteDefeat
	msgbox Route_2_Text_PetePost, MSGBOX_AUTOCLOSE
	end

Route_2_EventScript_BeachBeauty::
	lock
	faceplayer
	msgbox Route_2_Text_BeachBeauty, MSGBOX_DEFAULT
	release
	end

Route_2_EventScript_BeachSailor::
	lock
	faceplayer
	msgbox Route_2_Text_BeachSailor, MSGBOX_DEFAULT
	release
	end

Route_2_EventScript_BeachOldMan::
	lock
	faceplayer
	msgbox Route_2_Text_BeachOldMan, MSGBOX_DEFAULT
	release
	end

Route_2_Text_YachtSign::
	.string "{JPN}ぴかぴかの ヨットが さんばしで\n"
	.string "ゆれている。 キーは さしたままだ。\p"
	.string "ヨットを ぬすむ？$"

Route_2_Text_YachtFailed::
	.string "{JPN}しっぱい！$"

Route_2_Text_YachtStarts::
	.string "{JPN}つりびとの カギを ためしてみた。\p"
	.string "ひとまわしで エンジンが\n"
	.string "かかった。\p"
	.string "…だれも かけつけて こない。$"

Route_2_Text_SandyIntro::
	.string "{JPN}ひとつ みなみの まちは\n"
	.string "まっしろな ふぶきなんだって。$"

Route_2_Text_SandyDefeat::
	.string "{JPN}どうでもいいよ この へなちょこ！$"

Route_2_Text_SandyPost::
	.string "{JPN}ゆきだるまか すなのしろか\n"
	.string "きめられない！$"

Route_2_Text_CocoIntro::
	.string "{JPN}まいにち さいこうの ビーチびより！\n"
	.string "こんなの ずるくない？$"

Route_2_Text_CocoDefeat::
	.string "{JPN}ワイプアウト…$"

Route_2_Text_CocoPost::
	.string "{JPN}みなみの さくから あらしの かべが\n"
	.string "みえるんだって。 ぶるぶる。$"

Route_2_Text_PeteIntro::
	.string "{JPN}わたしは さむい ほうが すきです。$"

Route_2_Text_PeteDefeat::
	.string "{JPN}あせを かいています。 はじめての けいけんです。$"

Route_2_Text_PetePost::
	.string "{JPN}おかねが たまったら すぐに\n"
	.string "フロストウッドへ ひっこします。$"

Route_2_Text_BeachBeauty::
	.string "{JPN}ひだりうでには ひやけどめ\n"
	.string "みぎうでには しもやけの くすり。$"

Route_2_Text_BeachSailor::
	.string "{JPN}あの こ みてみろよ！ いい しり してるぜ！\n"
	.string "アルセウスさま おたすけを！$"

Route_2_Text_BeachOldMan::
	.string "{JPN}きこうへんどう だと いう ものも おるが\n"
	.string "でんせつでは ジラーチが\p"
	.string "ふたたび めざめると いう。$"

Route_2_EventScript_TwinsReinaVanessa::
	trainerbattle_double TRAINER_RED, Route_2_Text_TwinsIntro, Route_2_Text_TwinsDefeat, Route_2_Text_TwinsNotEnough
	msgbox Route_2_Text_TwinsPost, MSGBOX_AUTOCLOSE
	end

Route_2_Text_TwinsIntro::
	.string "{JPN}レイナ: わたしたち なんでも\n"
	.string "ふたりで やるの！\p"
	.string "バネッサ: ナミイルカも\n"
	.string "おそろい！ ダブルバトルよ！$"

Route_2_Text_TwinsDefeat::
	.string "{JPN}ぴったり そろえた はねるも\n"
	.string "だめだった！$"

Route_2_Text_TwinsNotEnough::
	.string "{JPN}ポケモンが 1ぴき しか いないの？\n"
	.string "2ひき つれて きてね！$"

Route_2_Text_TwinsPost::
	.string "{JPN}おそろいの あいぼう おそろいの\n"
	.string "まけ… それでも かわいいでしょ！$"

@ Outside the gondola station: rode down expecting Frostwood's slopes.
Route_2_EventScript_LostSnowboarder::
	lock
	faceplayer
	msgbox Route_2_Text_LostSnowboarder, MSGBOX_DEFAULT
	release
	end

Route_2_Text_LostSnowboarder::
	.string "{JPN}ここ いったい どこだよ？\p"
	.string "ゲレンデは ここだと\n"
	.string "おもったのに！$"

@ RedFatality, Frostwood's GYM LEADER, stuck at the bottom of the lift with no ticket.
@ Giving him the EPIC PASS (Sennen Village item ball, placeholder) sends him bolting
@ back up north and sets FLAG_REDFATALITY_HAS_EPIC_PASS, which hides this object and
@ unlocks the Frostwood Gym door (WotGetLockedDoorScript in field_control_avatar.c).
Route_2_EventScript_RedFatality::
	lock
	faceplayer
	setspeaker SP_NAME_RED_FATALITY
	msgbox Route_2_Text_RedFatalityIntro, MSGBOX_DEFAULT
	checkitem ITEM_EPIC_PASS
	goto_if_eq VAR_RESULT, FALSE, Route_2_EventScript_RedFatalityDone
	setspeaker SP_NAME_NONE
	msgbox Route_2_Text_GiveEpicPass, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route_2_EventScript_RedFatalityKeepPass
	removeitem ITEM_EPIC_PASS
	msgbox Route_2_Text_HandedOverEpicPass, MSGBOX_DEFAULT
	setspeaker SP_NAME_RED_FATALITY
	msgbox Route_2_Text_RedFatalitySick, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_REDFATALITY_HAS_EPIC_PASS
	@ Up column 28 is clear to the top of the beach; if the player is standing
	@ right above him he sidesteps into column 29 instead of running through them.
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ne VAR_0x8004, 28, Route_2_EventScript_RedFatalityBoltStraight
	goto_if_ne VAR_0x8005, 31, Route_2_EventScript_RedFatalityBoltStraight
	applymovement LOCALID_ROUTE2_REDFATALITY, Route_2_Movement_RedFatalityBoltAround
	goto Route_2_EventScript_RedFatalityGone

Route_2_EventScript_RedFatalityBoltStraight::
	applymovement LOCALID_ROUTE2_REDFATALITY, Route_2_Movement_RedFatalityBolt
Route_2_EventScript_RedFatalityGone::
	waitmovement 0
	removeobject LOCALID_ROUTE2_REDFATALITY
	release
	end

Route_2_EventScript_RedFatalityKeepPass::
	setspeaker SP_NAME_RED_FATALITY
	msgbox Route_2_Text_RedFatalityNoWorries, MSGBOX_DEFAULT
Route_2_EventScript_RedFatalityDone::
	release
	end

Route_2_Movement_RedFatalityBolt:
	jump_in_place_up
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

Route_2_Movement_RedFatalityBoltAround:
	jump_in_place_up
	walk_faster_right
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

Route_2_Text_RedFatalityIntro::
	.string "{JPN}よう！ おれは RedFatality。\n"
	.string "フロストウッドの ジムリーダーだ。\p"
	.string "リフトの チケットが ないと\n"
	.string "やまの うえに もどれなくてさ。\p"
	.string "ちょっと ついてないけど もんくは\n"
	.string "いえないな。 だって この けしき だぜ。$"

Route_2_Text_GiveEpicPass::
	.string "{JPN}RedFatalityに\nリフトのシーズンパスを わたす？$"

Route_2_Text_HandedOverEpicPass::
	.string "{JPN}{ENG}{PLAYER}{JPN}は リフトのシーズンパスを わたした。$"

Route_2_Text_RedFatalitySick::
	.string "{JPN}さいこう！$"

Route_2_Text_RedFatalityNoWorries::
	.string "{JPN}だいじょうぶ。 おれは ここで\n"
	.string "のんびり してるからさ。$"

Route_2_EventScript_SennenStationSign::
	msgbox Route_2_Text_SennenStationSign, MSGBOX_SIGN
	end

Route_2_Text_SennenStationSign::
	.string "{JPN}{UP_ARROW} きた: センネンえき$"
