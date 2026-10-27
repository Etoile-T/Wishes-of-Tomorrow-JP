BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "{JPN}ここは バトルタワー!\n"
	.string "れんしょうを つづけ\l"
	.string "さいきょうの トレーナーで あれ!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "{JPN}ここは バトルパレス!\n"
	.string "みまもれ! ポケモンバトル!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "{JPN}ここは バトルアリーナ!\n"
	.string "つどえ! さいきょう チーム!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "{JPN}ここは バトルピラミッド!\n"
	.string "すすめ! バトルアドベンチャー!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "{JPN}バトルフロンティア ランキングホール\n"
	.string "めざせ! あたらしい きろく!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "{JPN}バトルポイント こうかんサービス\n"
	.string "こうかんしよう! バトルポイント!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "{JPN}うわあ!\n"
	.string "でっかい!\p"
	.string "バトルタワーって とくべつな かんじ\n"
	.string "ほかの しせつとは ちがうね$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "{JPN}わたしの おおいなる やぼうは\n"
	.string "バトルフロンティアと ポケモンリーグ\l"
	.string "りょうほうを せいはする ことだ!\p"
	.string "そして もし ゆめが かなったら……\p"
	.string "とっ となりの いえの ミミちゃんに\n"
	.string "おともだちに なってって いうぞ!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "{JPN}バトルピラミッドは きびしすぎる!\n"
	.string "どうしても ちょうじょうまで いけん!\p"
	.string "もう てが ないから いっそ\n"
	.string "そとがわを のぼって やろうかしら……$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "{JPN}くらやみで いきいき する わたし……\n"
	.string "そう…… わたしに ふさわしい のは?\l"
	.string "ほかでもない バトルピラミッド……\p"
	.string "ネ…… あなたも くらやみの なかを\n"
	.string "ぜつぼうして さまよって みない?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "{JPN}1しゅうかん ねないで\n"
	.string "さいきょうの チームを つくったぞ!\p"
	.string "まける きが しない! マジで!\n"
	.string "バトルアリーナに のりこむぞ!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "{JPN}あなたも エニシダさんに つれてこられたの?\n"
	.string "あの ひと なんなのかしら?\p"
	.string "さいのうの ある トレーナーを\n"
	.string "みぬく めは ほんもの らしいけど……\p"
	.string "あの ひとが バトルしてるのは\n"
	.string "いちども みたことが ないわ$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "{JPN}ジグ!\n"
	.string "しんじてるよ ちびすけ!\p"
	.string "かったら ジグの すきな おいしい\n"
	.string "ごちそう なんでも つくって あげる!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "{JPN}ジグザグマは ぼんやり してる……$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "{JPN}おせっかいって いわれるけど\n"
	.string "どうしても きに なっちゃうの\p"
	.string "ぼうしが まがってるわよ!\n"
	.string "あら やだ ゴミが おちてる!\l"
	.string "いけない もうすぐ ばんごはん!\p"
	.string "バトルパレスで みまもる だけなんて\n"
	.string "わたしに たえられる かしら……$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "{JPN}いまは たいしたこと なさそうに みえるが\n"
	.string "むかし ジムリーダーに かったんだ\p"
	.string "もしかしたら もういちど えいこうを\n"
	.string "めざして みるべき かもな$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "{JPN}おれは じてんしゃが はやいけど\n"
	.string "バトルも はやいんだ\p"
	.string "まばたき する まに\n"
	.string "しょうぶを きめちゃうぜ!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "{JPN}わたしのほうがねえー パパより\n"
	.string "ポケモン つよいんだよ!$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "{JPN}いっておいで かわいい わがこよ!\n"
	.string "パパの ために かちまくって おいで!\p"
	.string "おまえは ママに そっくり だから\n"
	.string "きっと あっとうできるぞ!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "{JPN}ここまで くるのは たいへん だったけど\n"
	.string "バトルアリーナに すっごい\l"
	.string "かわいこちゃんが いるって きいてさ\p"
	.string "でも かわりに なにが いたと\n"
	.string "おもう?\p"
	.string "あせくさくて むさくるしい やせいてきな\n"
	.string "かくとうか たちが うじゃうじゃ だよ!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "{JPN}ときどき すごく えらそうな\n"
	.string "おじいさんが あそこに はいって いくの\p"
	.string "すっごい ポケモンを もってるんだ\n"
	.string "でも すごく やさしそう なんだよ$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "{JPN}きみは しって いるか!?\n"
	.string "バトルピラミッドの でんせつを!!\p"
	.string "じしんに みちた トレーナーが\n"
	.string "きんいろの いただきを めざすとき\l"
	.string "おとこの なかの おとこ あらわれる!\p"
	.string "……どうだ? しらないだろー!\n"
	.string "そりゃ そうだ!\l"
	.string "さっき おれが かんがえたんだもん!\p"
	.string "なに? どういう いみ かって?\n"
	.string "それは おしえられないな!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "{JPN}くっそー! ちくしょー!\n"
	.string "いちども まけた ことなかったのに!\p"
	.string "ても あしも でずに\n"
	.string "こてんぱんに やられた!\p"
	.string "しかも さいのうが ないって\n"
	.string "いわれたんだぞ?! くっそー!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "{JPN}こいつ バトルタワーの ちょうせんで\n"
	.string "とんでもなく つよい トレーナーに\l"
	.string "でくわしたんだ\p"
	.string "みてよ いまの こいつ……\p"
	.string "バトルタワーに いくなら\n"
	.string "きを つけたほうが いいよ$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "{JPN}やった!\n"
	.string "やっと バトルポイントが たまった!\p"
	.string "また おおきな ぬいぐるみの ドールと\n"
	.string "こうかん しようっと!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "{JPN}おほほほーいっ!\n"
	.string "ここが ランキングホール っスねー!\p"
	.string "わしも スーパーチャンプとして\n"
	.string "れきしに なを のこして ここに\l"
	.string "きろく されたい っスよ!$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "{JPN}きみが いれば なんだって できるさ$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "{JPN}ああ ダーリン あなたって すてき!\p"
	.string "ああ もう まちきれないわ!\p"
	.string "いますぐ マルチバトルルームへ\n"
	.string "いきましょう!\p"
	.string "バトルサロンで ふたり くめば\n"
	.string "あいの ちからで どんな あいても\l"
	.string "たおせちゃうわ!\p"
	.string "ダーリン わたしたちの まえでは\n"
	.string "みんな ドミノたおし みたいに たおれるのよ!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "{JPN}バトルフロンティアは つよい トレーナー\n"
	.string "だけの ものでは ない\p"
	.string "とくべつな のうりょくを もつ ひとも\n"
	.string "おおぜい まねかれて いる らしい\p"
	.string "あの エニシダという おとこ……\p"
	.string "もっと おおきな もくてきの ために\n"
	.string "ここを つくったの かもしれん……$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "{JPN}もしもし わかい おかた\n"
	.string "めは いいほう ですかい?\p"
	.string "このさきに へんな きが あって\n"
	.string "あたしの めには ぷるぷる みえるんですわ$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "{JPN}もしもし わかい おかた\n"
	.string "ものおぼえは いいほう ですかい?\p"
	.string "このさきに むかし へんな きが\n"
	.string "あった ような きが するんですわ…$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "{JPN}み……\n"
	.string "みちゃった!\p"
	.string "この さきに ねばねば した かんじの\n"
	.string "しっぽの ながい ポケモンが いたの!\p"
	.string "おおきな いわの したに かくれて\n"
	.string "ずっと こっちを みてたの!$"
