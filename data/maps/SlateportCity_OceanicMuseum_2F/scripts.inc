SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_PARTS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "{JPN}はい? クスノキを おさがしなら\n"
	.string "わたしだが。\p"
	.string "おお! それは デボンの ツワブキさんに\n"
	.string "たのんでおいた パーツだね!\p"
	.string "ありがとう! たすかったよ!\n"
	.string "これで たんさの じゅんびが できる。$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "{JPN}へへへ まちな!\n"
	.string "その パーツは おれたちが いただくぜ!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "{JPN}クスノキ: な なんだ?\n"
	.string "きみたちは いったい だれだ?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "{JPN}おれたち アクアだん!\p"
	.string "リーダーが そのパーツを ほしがってるんだ!\n"
	.string "だまって とっとと よこせ!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "{JPN}うわー!\n"
	.string "こどもに やられちまった!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "{JPN}やばい……\n"
	.string "ボスが かんかんに なるぞ…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "{JPN}ふん! めそめそする いくじなしめ!\n"
	.string "ここは おれに まかせてもらうぜ!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "{JPN}なんだと!\n"
	.string "おれも まけてしまった!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "{JPN}どうする? パーツを てにいれないと\n"
	.string "ただじゃ すまないぞ!\p"
	.string "くそっ こんな おせっかいな こどもに\n"
	.string "じゃまされる なんて おもわなかったぜ!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "{JPN}パーツを うばうのが おそいから\n"
	.string "みにきてみれば…\l"
	.string "おろかものどもが こどもに とめられたのか?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "{JPN}われわれは アクアだん。\n"
	.string "うみを あいする ものたちだ!\p"
	.string "そして おれが アクアだんの リーダー\n"
	.string "アオギリだ!\p"
	.string "なぜ われわれの じゃまを する?\p"
	.string "…いや! まさか!\n"
	.string "おまえ マグマだんの なかまか?\p"
	.string "まて それは おかしいな。\n"
	.string "マグマだんの ふくでは ないな。\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "ポケモンも ひとも… すべての いのちは\n"
	.string "うみに ささえられている。\p"
	.string "だから アクアだんは\n"
	.string "うみを ひろげることに ちからを そそぐのだ。\p"
	.string "そうは おもわないか? われわれの かつどうは\n"
	.string "すばらしい じぎょうなのだ。\p"
	.string "まあ いい…\n"
	.string "おまえは まだ わかすぎて\l"
	.string "われわれの とうとい もくてきが わかるまい。\p"
	.string "だが ちゅうこく しておく。にどと\n"
	.string "われわれの けいかくの じゃまなど かんがえるな。\p"
	.string "もし じゃますれば\n"
	.string "たかい だいしょうを はらうことに なるぞ!\p"
	.string "それだけは わすれるな!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "{JPN}クスノキ: きみは…\n"
	.string "ああ {ENG}{PLAYER}{JPN}{ENG}{KUN}{JPN}と いうのか…\p"
	.string "それにしても あぶない ところだった!\n"
	.string "たすけてくれて ありがとう!\p"
	.string "おっと あやうく わすれるところだった。\n"
	.string "デボンの パーツも もってきてくれたんだね!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "{JPN}クスノキ: おっと!\n"
	.string "こうしちゃ いられない!\p"
	.string "かいてい たんさには\n"
	.string "もうすぐ しゅっぱつ しなくては。\p"
	.string "かさねがさね ありがとう。\n"
	.string "だが もう いかなくては!\p"
	.string "きみは じゆうに あるいて\n"
	.string "しせつを みて いってくれて いいよ。$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "{JPN}ここで ふねの もけいを みたんだ。\p"
	.string "ムロタウンの ちかくに ある\n"
	.string "すてられぶねを おもいだしたよ…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "{JPN}はくぶつかんの なかを\n"
	.string "はしり まわるんじゃ ありませんよッ!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "{JPN}せんすいてい かっこいー!\n"
	.string "のって みたいな!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "{JPN}「すいしつ サンプル 1」\n"
	.string "と かかれた ラベルが はってある!\p"
	.string "うみは みんな つながって いるのに\n"
	.string "ちいきに よって みずは ちがうようだ。$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "{JPN}「すいしつ サンプル 2」\n"
	.string "と かかれた ラベルが はってある!\p"
	.string "ちいきが ちがえば うみの みずの\n"
	.string "しょっぱさも ちがったり するのかな?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "{JPN}ゴムの ボールが ふくらんだり\n"
	.string "しぼんだり している。\p"
	.string "「うみでは みず そのものの おもさで\n"
	.string "あつりょくが かかります。\p"
	.string "あさい みずの なかでは\n"
	.string "あつりょくは それほど つよく ありません。\p"
	.string "しかし とても ふかい みずの なかでは\n"
	.string "ちいさな めんせきに なんまんトンもの\l"
	.string "あつりょくが かかることも あります。」$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "{JPN}「ホウエンちほうの もけい」\p"
	.string "ホウエンちほうを ちいさく した\n"
	.string "ジオラマだ。\p"
	.string "ミシロタウンは どこだろう?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "{JPN}かいすいの ながれに ついての てんじだ!\p"
	.string "「うみの そこに ちかい ところ では\n"
	.string "みずの おんどや えんぶんの こさの ちがいで\l"
	.string "うみの みずが ながれて いきます。」$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "{JPN}かいすいの ながれに ついての てんじだ。\p"
	.string "「ひょうめん ちかくの かいすいは\n"
	.string "かぜの ちからで かいりゅうと なります。」$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "{JPN}「れんらくせん タイドリップごう」\p"
	.string "クスノキ ぞうせんじょで けんぞうちゅうの\n"
	.string "ふねを しゅくしょうした もけいです。$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "{JPN}「せんすいてい かいえん 1ごう」\p"
	.string "うみの そこを ちょうさ するための\n"
	.string "こうせいのう せんすいていの もけい です!$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "{JPN}「せんすい ポッド」\p"
	.string "かいてい たんさに つかう\n"
	.string "むじん こがたポッドの もけい です!$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "{JPN}「サント・アンヌ ごう」\p"
	.string "せかいを いっしゅう している\n"
	.string "ごうか きゃくせんの もけい です!$"
