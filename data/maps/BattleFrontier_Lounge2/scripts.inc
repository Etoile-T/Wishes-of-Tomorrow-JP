BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "{JPN}やあ! バトルフロンティアの\n"
	.string "じょうほうなら ぼくが いちばんさ!\p"
	.string "ぼくの ことは\n"
	.string "フロンティアマニアと よんでくれ!\p"
	.string "ねんのため きくけど きみは\n"
	.string "トレーナー だよね?\p"
	.string "ぼくが あつめた バトルフロンティアの\n"
	.string "とっておきの じょうほうを おしえるよ!$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "{JPN}やあやあ また ぼくの じょうほうを\n"
	.string "ききに きたんだね! しかたないなー!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "{JPN}どう? どう? どう?\p"
	.string "ぼくの じょうほうは もちろん\n"
	.string "すごーく さんこうに なってるだろ?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "{JPN}そうだねぇ……\p"
	.string "いまは {ENG}{STR_VAR_1}{JPN}が\n"
	.string "アッつい みたいだね!$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "{JPN}そうだねぇ……\p"
	.string "いまは バトルタワーの\n"
	.string "{ENG}{STR_VAR_1}{JPN}が アッつい みたいだね!$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "{JPN}これは しらなかったろう!\p"
	.string "エニシダさんが フロンティアブレーンと\n"
	.string "よぶ トップトレーナーが そこに いるんだ。\p"
	.string "そこを しきっているのは サロンメイデンと\n"
	.string "よばれる なぞの トレーナーなんだ。$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "{JPN}サロンメイデンとは たたかった?\p"
	.string "あいての じつりょくを はかるとき\n"
	.string "かのじょは この ポケモンを つかうらしい。\p"
	.string "エスパータイプの ねんりきポケモン\n"
	.string "ほのおタイプの かざんポケモン\l"
	.string "そして ノーマルタイプの いねむりポケモン!$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "{JPN}ほんきの サロンメイデンとは\n"
	.string "たたかった?\p"
	.string "ぜんりょくで たたかうとき\n"
	.string "かのじょは この ポケモンを つかうらしい。\p"
	.string "ドラゴンと エスパーの むげんポケモン\n"
	.string "でんきタイプの いかずちポケモン\l"
	.string "そして ノーマルタイプの いねむりポケモン!$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "{JPN}これは しらなかったろう!\p"
	.string "エニシダさんが フロンティアブレーンと\n"
	.string "よぶ トップトレーナーが そこに いるんだ。\p"
	.string "そこを しきっているのは ドームエースと\n"
	.string "よばれる はでな トレーナーなんだ。$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "{JPN}ドームエースとは たたかった?\p"
	.string "あいてを かるく あしらうとき\n"
	.string "かれは この 3びきを つかうんだ。\p"
	.string "ドラゴンと ひこうの ドラゴンポケモン\n"
	.string "みずと じめんの ぬまうおポケモン\l"
	.string "そして ほのおと ひこうの かえんポケモン!$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "{JPN}ほんきの ドームエースとは\n"
	.string "たたかった?\p"
	.string "さくせんを みせつけるとき\n"
	.string "かれは この 3びきを つかうんだ。\p"
	.string "ドラゴンと ひこうの むげんポケモン\n"
	.string "みずと じめんの ぬまうおポケモン\l"
	.string "そして はがねと エスパータイプの\l"
	.string "てつあしポケモン!$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "{JPN}これは しらなかったろう!\p"
	.string "エニシダさんが フロンティアブレーンと\n"
	.string "よぶ トップトレーナーが そこに いるんだ。\p"
	.string "そこを しきっているのは へんな\n"
	.string "ファクトリーヘッドと よばれる トレーナーさ。$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "{JPN}ファクトリーヘッドとは もう\n"
	.string "たたかった?\p"
	.string "えーと…… かれは たたかうとき\n"
	.string "レンタルポケモンを 3びき もらうだけ。\p"
	.string "きみと ほとんど おなじ じょうけんで\n"
	.string "たたかって いるんだ。$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "{JPN}ほんきの ファクトリーヘッドとは\n"
	.string "たたかった?\p"
	.string "ほんきで たたかうときも\n"
	.string "やっぱり レンタルポケモンを 3びき もらうんだ。\p"
	.string "きみと ほぼ まったく おなじ じょうけんで\n"
	.string "たたかって いるんだ。$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "{JPN}これは しらなかったろう!\p"
	.string "エニシダさんが フロンティアブレーンと\n"
	.string "よぶ トップトレーナーが そこに いるんだ。\p"
	.string "そこを しきっているのは こわい\n"
	.string "チューブクイーンと よばれる トレーナーさ。$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "{JPN}チューブクイーンとは\n"
	.string "たたかったこと ある?\p"
	.string "きげんが いいとき かのじょは\n"
	.string "この 3びきを つかうって はなしだ。\p"
	.string "どくタイプの きばへびポケモン\n"
	.string "むしと いわの はっこうポケモン\l"
	.string "そして みずタイプの いつくしみポケモン!$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "{JPN}ほんきの チューブクイーンとは\n"
	.string "たたかった?\p"
	.string "ほんきで おこったとき かのじょは\n"
	.string "この 3びきを つかうって はなしだ。\p"
	.string "どくタイプの きばへびポケモン\n"
	.string "はがねと じめんの てつへびポケモン\l"
	.string "そして みずと ひこうタイプの\l"
	.string "きょうあくポケモン!$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "{JPN}これは しらなかったろう!\p"
	.string "エニシダさんが フロンティアブレーンと\n"
	.string "よぶ トップトレーナーが そこに いるんだ。\p"
	.string "そこを しきっているのは かわいい\n"
	.string "アリーナタイクーンと よばれる トレーナーさ。$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "{JPN}アリーナタイクーンとは\n"
	.string "たたかったこと ある?\p"
	.string "あいての じつりょくを みきわめるとき\n"
	.string "かのじょは この ポケモンを つかうらしい。\p"
	.string "むしと かくとうの 1ぽんヅノポケモン\n"
	.string "あくタイプの げっこうポケモン\l"
	.string "そして むしと ゴーストの ぬけがらポケモン!$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "{JPN}ほんきの アリーナタイクーンとは\n"
	.string "たたかった?\p"
	.string "ほんきで しょうぶするとき\n"
	.string "かのじょは この ポケモンを つかうらしい。\p"
	.string "あくタイプの げっこうポケモン\n"
	.string "ゴーストと どくの シャドーポケモン\l"
	.string "そして くさと かくとうタイプの\l"
	.string "きのこポケモン!$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "{JPN}これは しらなかったろう!\p"
	.string "エニシダさんが フロンティアブレーンと\n"
	.string "よぶ トップトレーナーが そこに いるんだ。\p"
	.string "そこを しきっているのは あやしい\n"
	.string "パレスガーディアンと よばれる トレーナーさ。$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "{JPN}パレスガーディアンとは\n"
	.string "たたかったこと ある?\p"
	.string "あいての こころを ためすとき\n"
	.string "かれは この ポケモンを つかうそうだ。\p"
	.string "どくと ひこうタイプの こうもりポケモン\n"
	.string "ノーマルタイプの ものぐさポケモン\l"
	.string "そして みずと こおりの のりものポケモン!$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "{JPN}ほんきの パレスガーディアンとは\n"
	.string "たたかった?\p"
	.string "ぜんりょくを こめて たたかうとき\n"
	.string "かれは この ポケモンを つかうそうだ。\p"
	.string "ほのおタイプの でんせつポケモン\n"
	.string "ノーマルタイプの ものぐさポケモン\l"
	.string "そして みずタイプの オーロラポケモン!$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "{JPN}これは しらなかったろう!\p"
	.string "エニシダさんが フロンティアブレーンと\n"
	.string "よぶ トップトレーナーが そこに いるんだ。\p"
	.string "そこを しきっているのは あつくるしい\n"
	.string "ピラミッドキングと よばれる トレーナーさ。$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "{JPN}ピラミッドキングとは\n"
	.string "たたかったこと ある?\p"
	.string "あいての ちからを たしかめるとき\n"
	.string "かれは この ポケモンを つかうらしい。\p"
	.string "いわタイプの いわやまポケモン\n"
	.string "こおりタイプの ひょうざんポケモン\l"
	.string "そして はがねタイプの くろがねポケモン!$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "{JPN}ほんきの ピラミッドキングとは\n"
	.string "たたかった?\p"
	.string "あつい パワーが みなぎってるとき\n"
	.string "かれは この ポケモンを つかうらしい。\p"
	.string "こおりと ひこうの れいとうポケモン\n"
	.string "でんきと ひこうの でんげきポケモン\l"
	.string "そして ほのおと ひこうタイプの\l"
	.string "かえんポケモン!$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "{JPN}ダブルバトルが できる ばしょは\n"
	.string "いくつか あるけどさ。\p"
	.string "バトルタワーの ダブルバトルルームは\n"
	.string "きほん ちゅうの きほん だよ!\p"
	.string "バトルフロンティアでの ダブルバトルの\n"
	.string "たたかいかたは そこで\l"
	.string "まなぶと いいよ。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "{JPN}ここでの たたかいには きをつけな。\p"
	.string "ダブルバトル せんようの さくせんを\n"
	.string "あみだした トレーナーも\l"
	.string "いるって はなしだ。$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "{JPN}ここの たたかいで\n"
	.string "ダブルバトルに じしんが ついたら\l"
	.string "ほかの ダブルバトルが できる ばしょに\l"
	.string "チャレンジ してみると いいかもな!$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "{JPN}バトルサロンには\n"
	.string "いろんな トレーナーが あつまるんだぜ!\p"
	.string "もしかしたら きみの ともだちや\n"
	.string "でしにも あえるかも しれないな!\l"
	.string "よーく さがして みると いいぜ!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "{JPN}ともだちと いっしょなら\n"
	.string "リンクマルチバトルルームへ いこう!\p"
	.string "つよい ともだちと くめば\n"
	.string "てごわい あいてが でてくるぞ!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "{JPN}すっげえ じょうほうりょくー!!\n"
	.string "やっぱ センパイは ちがうっすよー$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "{JPN}すっげえ かんさつりょくー!!\n"
	.string "やっぱ センパイは ちがうっすわー$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "{JPN}すっげえ せっとくりょくー!!\n"
	.string "やっぱ センパイは ちがうっすねー$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "{JPN}なによ ここ……\n"
	.string "ちょっと こわい……$"

