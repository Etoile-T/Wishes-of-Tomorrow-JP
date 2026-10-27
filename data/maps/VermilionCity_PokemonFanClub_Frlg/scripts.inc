.set SPOKE_TO_WOMAN_LAST,   FLAG_TEMP_2
.set SPOKE_TO_FAT_MAN_LAST, FLAG_TEMP_3

VermilionCity_PokemonFanClub_Frlg_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	release
	end

VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	giveitem_msg VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, ITEM_BIKE_VOUCHER, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForThis
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	famechecker FAMECHECKER_DAISY, 1
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_set SPOKE_TO_FAT_MAN_LAST, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set SPOKE_TO_WOMAN_LAST, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag SPOKE_TO_FAT_MAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_POKEMON_FAN_CLUB_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag SPOKE_TO_WOMAN_LAST
	release
	end

VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
	.string "{JPN}わたしの ピカチュウの かわいい\n"
	.string "しっぽを みて くれない?$"

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
	.string "{JPN}ふん!\p"
	.string "わたしの ピカチュウの ほうが\n"
	.string "その こより 2ばい かわいいわ!$"

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
	.string "{JPN}わたしの パウワウ だいすき!\n"
	.string "とっても かわいいの!\p"
	.string "だきしめると 「キュー」って\n"
	.string "なくのよ!$"

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
	.string "{JPN}あら まあ!\p"
	.string "わたしの パウワウの ほうが ずっと\n"
	.string "すてきよ。 2ばいは ね。$"

VermilionCity_PokemonFanClub_Text_Pikachu::
	.string "{JPN}ピカチュウ: チュッ! ピカチュウ!$"

VermilionCity_PokemonFanClub_Text_Seel::
	.string "{JPN}パウワウ: キュオー!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
	.string "{JPN}わしが だいすきクラブの かいちょうじゃ!\p"
	.string "ポケモンを 100ぴき いじょう\n"
	.string "そだてて おる!\p"
	.string "ポケモンの ことには うるさいぞ!\n"
	.string "ほんとうに うるさいぞ!\p"
	.string "それで…\p"
	.string "わしの ポケモンの はなしを\n"
	.string "ききに きたのかね?$"

VermilionCity_PokemonFanClub_Text_ChairmansStory::
	.string "{JPN}よろしい!\n"
	.string "では よく きけ!\p"
	.string "わしの おきにいりの ギャロップは…\p"
	.string "かわいくて…すてきで…かしこくて…\n"
	.string "それに…すごい…そう おもわんか?…\l"
	.string "そうじゃ…それは…みごとで…\l"
	.string "やさしい…だいすき!\p"
	.string "だっこ…ねてる…とき…あたたかくて\n"
	.string "ふわふわ…すばらしい…\l"
	.string "うっとり…\l"
	.string "…おっと! もう こんな じかんか!\l"
	.string "ひきとめて しまったな!\p"
	.string "きいてくれて ありがとう!\n"
	.string "これを うけとって くれ!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
	.string "{JPN}{ENG}{PLAYER}{JPN}は かいちょうから\n"
	.string "ひきかえけんを もらった!$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
	.string "{JPN}その ひきかえけんを ハナダシティの\n"
	.string "じてんしゃやに もっていくと\p"
	.string "ただで じてんしゃと\n"
	.string "こうかん してくれるぞ!\p"
	.string "しんぱい いらん。 わしは おきにいりの\n"
	.string "オニドリルで どこへでも とんでいける。\p"
	.string "だから じてんしゃは いらんのじゃ。\p"
	.string "サイクリングを たのしんで くれ!$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
	.string "{JPN}そうか。 わしの はなしを ききたく\n"
	.string "なったら また きなさい!$"

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
	.string "{JPN}おお {ENG}{PLAYER}{JPN}!\p"
	.string "また わしの ポケモンの はなしを\n"
	.string "ききに きたのかね?\p"
	.string "ちがう?\n"
	.string "ざんねんじゃ!$"

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
	.string "{JPN}もちものを へらして きなさい!$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
	.string "{JPN}うちの かいちょうは ポケモンの\n"
	.string "ことに なると よく しゃべるの。$"

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
	.string "{JPN}ほかの トレーナーの はなしは\n"
	.string "ぎょうぎよく ききましょう!$"

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
	.string "{JPN}じまん されたら じまんし かえせ!$"

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
	.string "{JPN}うちの かいちょうは ほんとうに\n"
	.string "ポケモンを かわいがってるわ。\p"
	.string "でも ポケモンに いちばん すかれてる\n"
	.string "ひとは ナナミさんだと おもうの。$"
