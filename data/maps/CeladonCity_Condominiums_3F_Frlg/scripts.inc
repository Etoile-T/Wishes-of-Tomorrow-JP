CeladonCity_Condominiums_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special Special_ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
	.string "{JPN}ぼく?\n"
	.string "ぼくは プログラマー!$"

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
	.string "{JPN}わたしは グラフィック たんとう!\n"
	.string "あなたを かいたのよ!$"

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
	.string "{JPN}ぼくは シナリオを かいたんだ!\n"
	.string "エリカって かわいいだろ?\p"
	.string "カスミも だいすき!\n"
	.string "あっ それから ナツメも すきだな!$"

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
	.string "{JPN}そうなのか?\p"
	.string "わたしは ゲームデザイナー!\p"
	.string "ポケモンずかんを うめるのは\n"
	.string "たいへんだけど あきらめないで!\p"
	.string "かんせいしたら おしえに きてね!$"

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
	.string "{JPN}すごい! すばらしい!\n"
	.string "ポケモンずかんを かんせいさせたね!\l"
	.string "おめでとう!\l"
	.string "…$"

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
	.string "{JPN}ゲームの プログラムだ! いじると\n"
	.string "ゲームが バグって しまうかも!$"

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
	.string "{JPN}しごとを しないで ゲームを\n"
	.string "あそんでる ひとが いる!$"

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
	.string "{JPN}シナリオだ!\n"
	.string "エンディングは みないで おこう!$"

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
	.string "{JPN}ゲームフリーク かいはつしつ$"

