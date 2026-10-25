NewMapMaskMaker_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMapMaskMaker_OnResume
	.byte 0

NewMapMaskMaker_OnResume::
	questindicator 1, SIDE_QUEST_SAVE_FACE  @ Master Gen, until Save Face is picked up
	end

@ ============================================================================
@  MASTER GEN, THE MASK-MAKER -- quest giver for the Munen Tunnel.
@  His apprentice Itsuki stole a festival mask and joined the oni group.
@  States:
@    1. First talk          -> sets FLAG_NEWMAP_TUNNEL_RUMOR (quest open)
@    2. Quest open, no mask -> reminder
@    3. Player has mask     -> reward, sets FLAG_NEWMAP_MASK_RETURNED and
@                              FLAG_NEWMAP_APPRENTICE_DOOR_OPEN (clears the
@                              crates from Itsuki's door). Player KEEPS the
@                              mask -- in Act 2 it works as a DISGUISE: oni
@                              goons take a masked player for one of their
@                              own and skip the battle (see
@                              data/scripts/oni_mask_disguise.inc).
@    4. Done                -> closing words
@ ============================================================================
NewMapMaskMaker_EventScript_Gen::
	lock
	faceplayer
	setspeaker SP_NAME_MASTER_GEN
	goto_if_set FLAG_NEWMAP_MASK_RETURNED, NewMapMaskMaker_EventScript_GenAfter
	checkitem ITEM_CARVED_MASK
	goto_if_eq VAR_RESULT, TRUE, NewMapMaskMaker_EventScript_GenMaskFound
	goto_if_set FLAG_NEWMAP_TUNNEL_RUMOR, NewMapMaskMaker_EventScript_GenReminder
	msgbox NewMapMaskMaker_Text_GenIntro, MSGBOX_DEFAULT
	setflag FLAG_NEWMAP_TUNNEL_RUMOR
	@ Gen has the slab hauled off the tunnel mouth (the rock object in town
	@ hides once this is set).
	setflag FLAG_POMPEII_TUNNEL_ROCK_CLEARED
	startquest SIDE_QUEST_SAVE_FACE
	release
	end

NewMapMaskMaker_EventScript_GenReminder::
	msgbox NewMapMaskMaker_Text_GenReminder, MSGBOX_DEFAULT
	release
	end

NewMapMaskMaker_EventScript_GenMaskFound::
	msgbox NewMapMaskMaker_Text_GenMaskFound, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message NewMapMaskMaker_Text_ReceivedFlintBadge
	waitmessage
	waitfanfare
	setflag FLAG_BADGE03_GET
	msgbox NewMapMaskMaker_Text_GenBadgeWords, MSGBOX_DEFAULT
	msgbox NewMapMaskMaker_Text_GenKeepIt, MSGBOX_DEFAULT
	setflag FLAG_NEWMAP_MASK_RETURNED
	setflag FLAG_NEWMAP_APPRENTICE_DOOR_OPEN
	@ completequest also unlocks the quest for players who found the mask
	@ before ever hearing Gen's request.
	completequest SIDE_QUEST_SAVE_FACE
	release
	end

NewMapMaskMaker_EventScript_GenAfter::
	msgbox NewMapMaskMaker_Text_GenAfter, MSGBOX_DEFAULT
	release
	end

@ --------------------------------------------------------------------------
@  Furniture
@ --------------------------------------------------------------------------
NewMapMaskMaker_EventScript_MaskWall::
	msgbox NewMapMaskMaker_Text_MaskWall, MSGBOX_SIGN
	end

NewMapMaskMaker_EventScript_Workbench::
	msgbox NewMapMaskMaker_Text_Workbench, MSGBOX_SIGN
	end

@ ============================================================================
@  Text
@ ============================================================================
NewMapMaskMaker_Text_GenIntro::
	.string "{JPN}…オニの めんは まよけの かおじゃ。\n"
	.string "これを つければ しにびとは おまえを\l"
	.string "なかまと おもいこみ しずかに\l"
	.string "とおして くれる。\p"
	.string "わしの めんを つけて のぼった れんちゅうは\n"
	.string "それを べつの ものに ねじまげて\l"
	.string "しまった。 うえた なにかに。\p"
	.string "そして でしの リョウコも ついていった。\p"
	.string "ことしの まつりの ために ほった\n"
	.string "めんを もってな。\p"
	.string "やつらが むらの きたの はずれの\n"
	.string "ふるい はかばに はいるのを みた。\p"
	.string "わしは もう としで はいれん。\n"
	.string "もし あいつの ものが まだ そこに\l"
	.string "のこって おったら… もってきて くれんか？$"

NewMapMaskMaker_Text_GenReminder::
	.string "{JPN}ふるい はかばの トンネルは むらの きたがわ\n"
	.string "けいこくの かんばんの さきじゃ。\p"
	.string "とびらの ふうは もう やぶられておる。\p"
	.string "リョウコが あそこに なにを\n"
	.string "のこしていても… わしには わかる。\l"
	.string "わしが おしえたのじゃからな。$"

NewMapMaskMaker_Text_GenMaskFound::
	.string "{JPN}その めんは… みせてくれ。\n"
	.string "あかりの したで みたい。\p"
	.string "…うむ。 あいつの ほりかたじゃ。\n"
	.string "これの ために やつらの したっぱを\l"
	.string "たおして きたのか。\p"
	.string "ならば わしが さぎょうだいの ひきだしに\n"
	.string "40ねん しまって おいた ものを\l"
	.string "うけとる しかくが ある。$"

NewMapMaskMaker_Text_ReceivedFlintBadge::
	.string "{JPN}{ENG}{PLAYER}{JPN}は ゲンししょうから\n"
	.string "フリントバッジを もらった！$"

NewMapMaskMaker_Text_GenBadgeWords::
	.string "{JPN}フリントバッジじゃ。 この てが めんを\n"
	.string "ほるように なる まえ リーグに いた\l"
	.string "ころの ものじゃよ。\p"
	.string "いわくだきを おぼえた ポケモンが\n"
	.string "フィールドで つかえるように なる。\p"
	.string "やまへの みちは がれきで\n"
	.string "ふさがっておる。 ひつように\l"
	.string "なるじゃろう。$"

NewMapMaskMaker_Text_GenKeepIt::
	.string "{JPN}それと めんは もっておけ。 ほんきじゃぞ。\p"
	.string "やつらに みつかる まえに つければ\n"
	.string "オニは おまえを なかまの ひとりと\l"
	.string "おもうじゃろう。\p"
	.string "おお そうじゃ リョウコの いえの とびらから\n"
	.string "はこを どけておいた。 あいつの いえを\l"
	.string "みてまわって かまわん。 おまえの ほうが\l"
	.string "わしより あいつを わかって やれるかもしれん。$"

NewMapMaskMaker_Text_GenAfter::
	.string "{JPN}はめつの ひの まえに\n"
	.string "あけの かねが 2ど なる。$"

NewMapMaskMaker_Text_MaskWall::
	.string "{JPN}まつりの めんが かべに ならんでいる。\n"
	.string "きつね。 つる。 つきの うさぎ。 かみなりねこ。\p"
	.string "まんなかには からっぽの かけくぎが ひとつ。$"

NewMapMaskMaker_Text_Workbench::
	.string "{JPN}40ねんの てしごとで すりへり\n"
	.string "なめらかに なった さぎょうだいだ。$"
