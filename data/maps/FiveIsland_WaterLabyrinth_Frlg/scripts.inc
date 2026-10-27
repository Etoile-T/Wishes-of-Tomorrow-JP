FiveIsland_WaterLabyrinth_Frlg_MapScripts::
	.byte 0

FiveIsland_WaterLabyrinth_EventScript_EggGentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	goto_if_set FLAG_NO_ROOM_FOR_TOGEPI_EGG, FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg
	msgbox FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons
	specialvar VAR_RESULT, GetLeadMonFriendship
	goto_if_eq VAR_RESULT, 6, FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship
	msgbox FiveIsland_WaterLabyrinth_Text_HmmISeeIsee
	release
	end

FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment::
	famechecker FAMECHECKER_DAISY, 2
	msgbox FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy
	release
	end

FiveIsland_WaterLabyrinth_EventScript_LeadMonMaxFriendship::
	msgbox FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg
	setflag FLAG_GOT_TOGEPI_EGG
	giveegg SPECIES_TOGEPI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan
	waitfanfare
	waitmessage
	call EventScript_RestorePrevTextColor
	goto FiveIsland_WaterLabyrinth_EventScript_PostEggComment
	end

@ If the player has a Togepi/Togetic from this game (assumed to be the one the man gave you) then comment on it
@ Otherwise make normal comment
FiveIsland_WaterLabyrinth_EventScript_PostEggComment::
	bufferspeciesname STR_VAR_2, SPECIES_TOGEPI
	setvar VAR_0x8004, SPECIES_TOGEPI
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	bufferspeciesname STR_VAR_2, SPECIES_TOGETIC
	setvar VAR_0x8004, SPECIES_TOGETIC
	specialvar VAR_RESULT, PlayerPartyContainsSpeciesWithPlayerID
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_WaterLabyrinth_EventScript_MonDaisyComment
	msgbox FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou
	release
	end

FiveIsland_WaterLabyrinth_EventScript_NoRoomForEgg::
	setflag FLAG_NO_ROOM_FOR_TOGEPI_EGG
	msgbox FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty
	release
	end

FiveIsland_WaterLabyrinth_EventScript_ReturnForEgg::
	goto FiveIsland_WaterLabyrinth_EventScript_TryGiveEgg
	end

FiveIsland_WaterLabyrinth_Text_LetMeTakeLookAtMons::
	.string "{JPN}きみは あちこち たびを\n"
	.string "しているんだね?\p"
	.string "ポケモンに むりを させて\n"
	.string "いないかい?\p"
	.string "ちょっと みせて ごらん。\n"
	.string "… … …   … … …$"

FiveIsland_WaterLabyrinth_Text_HmmISeeIsee::
	.string "{JPN}ふむ ふむ…\n"
	.string "なるほど なるほど…$"

FiveIsland_WaterLabyrinth_Text_TreatMonRightHaveThis::
	.string "{JPN}おお りっぱだ。\n"
	.string "ポケモンを だいじに しているね。\p"
	.string "きみになら\n"
	.string "これを まかせられそうだ。\p"
	.string "どうか これを もらって ほしい。$"

FiveIsland_WaterLabyrinth_Text_ReceivedEggFromMan::
	.string "{JPN}{ENG}{PLAYER}{JPN}は おとこのひとから\n"
	.string "タマゴを もらった!$"

FiveIsland_WaterLabyrinth_Text_DontHaveSpaceInYourParty::
	.string "{JPN}…ざんねんだけど てもちに\n"
	.string "これを いれる あきが ないね。\p"
	.string "また こんど とりに きて\n"
	.string "おくれ。$"

@ Unused
FiveIsland_WaterLabyrinth_Text_YouveComeBackForTheEgg::
	.string "{JPN}やあ\n"
	.string "タマゴを もらいに\l"
	.string "きて くれたんだね$"

FiveIsland_WaterLabyrinth_Text_GladIMetSomeoneLikeYou::
	.string "{JPN}あの タマゴは たびの とちゅうで\n"
	.string "もらった ものなんだ。\p"
	.string "きみの ような ひとに あえて よかったよ。$"

FiveIsland_WaterLabyrinth_Text_CuteMonRemindsMeOfDaisy::
	.string "{JPN}やあ こんにちは。\n"
	.string "かわいい {ENG}{STR_VAR_2}{JPN}だね。\p"
	.string "みていると たびさきで あった\n"
	.string "やさしい おんなのこを おもいだすよ。\p"
	.string "やさしく ポケモンの けづくろいを してた…\n"
	.string "まるで てんしの ような こだった。\p"
	.string "その おんなのこの なまえは…\n"
	.string "たしか ナナミ だったかな。$"

FiveIsland_WaterLabyrinth_Text_AlizeIntro::
	.string "{JPN}ここは ポケモンを そだてるのに\n"
	.string "さいこうの かんきょうよ。$"

FiveIsland_WaterLabyrinth_Text_AlizeDefeat::
	.string "{JPN}あなたの ポケモン りっぱに\n"
	.string "そだってるわね!$"

FiveIsland_WaterLabyrinth_Text_AlizePostBattle::
	.string "{JPN}あなたには いい ブリーダーに\n"
	.string "なれる さいのうが あると おもうわ。$"
