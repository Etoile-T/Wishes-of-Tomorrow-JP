SaffronCity_CopycatsHouse_2F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, EventScript_MimicTutor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, FEMALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
	.string "{JPN}{ENG}{PLAYER}{JPN}: やあ!\n"
	.string "ポケモン すき?\p"
	.string "{ENG}{PLAYER}{JPN}: いや きいたのは こっちだよ。\p"
	.string "{ENG}{PLAYER}{JPN}: え?\n"
	.string "へんなの!\p"
	.string "ものまねむすめ: え? まねを やめろ?\n"
	.string "だって これが いちばんの しゅみなの!$"

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
	.string "{JPN}{ENG}{PLAYER}{JPN}: こんにちは。\n"
	.string "ポケモンが すきなのね。\p"
	.string "{ENG}{PLAYER}{JPN}: ちがうわ わたしじゃない。\n"
	.string "あなたに きいたの。\p"
	.string "{ENG}{PLAYER}{JPN}: なあに?\n"
	.string "へんな こ!\l"
	.string " \l"
	.string "ものまねむすめ: え? まねを やめろ?\l"
	.string "だって これが いちばんの しゅみなの!$"

Text_MimicTeach::
	.string "{JPN}わあ!\n"
	.string "ピッピにんぎょう!\p"
	.string "わたしに?\n"
	.string "ありがとう!\p"
	.string "そうだ!\n"
	.string "ものまねって わざを おしえて あげる。$"

Text_MimicDeclined::
	.string "{JPN}ものまねは きらい?$"

Text_MimicWhichMon::
	.string "{JPN}わたし ものまねが だいすき!\n"
	.string "だれに おぼえさせる?$"

Text_MimicTaughtMale::
	.string "{JPN}{ENG}{PLAYER}{JPN}: やあ!\n"
	.string "さっきは ありがとう!\p"
	.string "{ENG}{PLAYER}{JPN}: え?\p"
	.string "{ENG}{PLAYER}{JPN}: ぼくの まねを するのが\n"
	.string "そんなに たのしいの?\p"
	.string "ものまねむすめ: もちろん!\n"
	.string "すっごく おもしろいわ!$"

Text_MimicTaughtFemale::
	.string "{JPN}{ENG}{PLAYER}{JPN}: こんにちは!\n"
	.string "この あいだは ありがとう。\p"
	.string "{ENG}{PLAYER}{JPN}: なあに?\p"
	.string "{ENG}{PLAYER}{JPN}: わたしの まねを するのが\n"
	.string "ほんとうに そんなに たのしいの?\p"
	.string "ものまねむすめ: もちろん!\n"
	.string "すっごく おもしろいわ!$"

SaffronCity_CopycatsHouse_2F_Text_Doduo::
	.string "{JPN}ドードー: ギーッ!\p"
	.string "かがみよ かがみ わたしを みて\n"
	.string "わたしって こんなに きれい?$"

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
	.string "{JPN}これは めずらしい ポケモンだ!\n"
	.string "あれ? ただの にんぎょうだ!$"

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
	.string "{JPN}マリオが バケツを かぶってる\n"
	.string "ゲームだ!$"

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
	.string "{JPN}…\p"
	.string "わたしの ひみつ!\p"
	.string "とくぎ: ものまね!\n"
	.string "しゅみ: にんぎょう あつめ!\l"
	.string "すきな ポケモン: ピッピ!$"

