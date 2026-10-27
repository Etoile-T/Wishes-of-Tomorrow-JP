CeruleanCity_House1_Frlg_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BadgeGuy::
	lock
	faceplayer
	msgbox CeruleanCity_House1_Text_BadgesHaveAmazingSecrets
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeAnotherBadge::
	message CeruleanCity_House1_Text_DescribeWhichBadge
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BADGES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House1_EventScript_DescribeBoulderBadge
	case 1, CeruleanCity_House1_EventScript_DescribeCascadeBadge
	case 2, CeruleanCity_House1_EventScript_DescribeThunderBadge
	case 3, CeruleanCity_House1_EventScript_DescribeRainbowBadge
	case 4, CeruleanCity_House1_EventScript_DescribeSoulBadge
	case 5, CeruleanCity_House1_EventScript_DescribeMarshBadge
	case 6, CeruleanCity_House1_EventScript_DescribeVolcanoBadge
	case 7, CeruleanCity_House1_EventScript_DescribeEarthBadge
	case 8, CeruleanCity_House1_EventScript_StopDescribingBadges
	case 127, CeruleanCity_House1_EventScript_StopDescribingBadges
	end

CeruleanCity_House1_EventScript_DescribeBoulderBadge::
	msgbox CeruleanCity_House1_Text_AttackStatFlash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeCascadeBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv30Cut
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeThunderBadge::
	msgbox CeruleanCity_House1_Text_SpeedStatFly
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeRainbowBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv50Strength
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeSoulBadge::
	msgbox CeruleanCity_House1_Text_DefenseStatSurf
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeMarshBadge::
	msgbox CeruleanCity_House1_Text_ObeyLv70RockSmash
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeVolcanoBadge::
	msgbox CeruleanCity_House1_Text_SpStatsWaterfall
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_DescribeEarthBadge::
	msgbox CeruleanCity_House1_Text_AllMonsWillObeyYou
	goto CeruleanCity_House1_EventScript_DescribeAnotherBadge
	end

CeruleanCity_House1_EventScript_StopDescribingBadges::
	msgbox CeruleanCity_House1_Text_ComeVisitAnytime
	release
	end

CeruleanCity_House1_Text_BadgesHaveAmazingSecrets::
	.string "{JPN}ポケモンバッジを あつめられるのは\n"
	.string "うでの いい トレーナーだけじゃ。\p"
	.string "おまえさんは ひとつは もっとるようじゃな。\p"
	.string "バッジには すごい ひみつが あるんじゃ\n"
	.string "しっとったかね?$"

CeruleanCity_House1_Text_DescribeWhichBadge::
	.string "{JPN}さてと…\p"
	.string "8つの バッジの うち どれを\n"
	.string "せつめい しようかの?$"

CeruleanCity_House1_Text_ComeVisitAnytime::
	.string "{JPN}いつでも あそびに おいで。$"

CeruleanCity_House1_Text_AttackStatFlash::
	.string "{JPN}てもちの ポケモン ぜんいんの\n"
	.string "こうげきが すこし あがる。\p"
	.string "それに せんとう いがいで\n"
	.string "フラッシュが つかえるように なる。$"

CeruleanCity_House1_Text_ObeyLv30Cut::
	.string "{JPN}レベル30 までの ポケモンが\n"
	.string "いうことを きく。\p"
	.string "こうかんで てに いれた\n"
	.string "ポケモンでも じゃ。\p"
	.string "ただし それより レベルが たかいと\n"
	.string "せんとうで いうことを きかんぞ。\p"
	.string "それに せんとう いがいで\n"
	.string "いあいぎりが つかえるように なる。$"

CeruleanCity_House1_Text_SpeedStatFly::
	.string "{JPN}てもちの ポケモン ぜんいんの\n"
	.string "すばやさが すこし あがる。\p"
	.string "それに せんとう いがいで\n"
	.string "そらをとぶが つかえるように なる。$"

CeruleanCity_House1_Text_ObeyLv50Strength::
	.string "{JPN}レベル50 までの ポケモンが\n"
	.string "いうことを きく。\p"
	.string "こうかんで てに いれた\n"
	.string "ポケモンでも じゃ。\p"
	.string "ただし それより レベルが たかいと\n"
	.string "せんとうで いうことを きかんぞ。\p"
	.string "それに せんとう いがいで\n"
	.string "かいりきが つかえるように なる。$"

CeruleanCity_House1_Text_DefenseStatSurf::
	.string "{JPN}てもちの ポケモン ぜんいんの\n"
	.string "ぼうぎょが すこし あがる。\p"
	.string "それに せんとう いがいで\n"
	.string "なみのりが つかえるように なる。$"

CeruleanCity_House1_Text_ObeyLv70RockSmash::
	.string "{JPN}レベル70 までの ポケモンが\n"
	.string "いうことを きく。\p"
	.string "こうかんで てに いれた\n"
	.string "ポケモンでも じゃ。\p"
	.string "ただし それより レベルが たかいと\n"
	.string "せんとうで いうことを きかんぞ。\p"
	.string "それに せんとう いがいで\n"
	.string "いわくだきが つかえるように なる。$"

CeruleanCity_House1_Text_SpStatsWaterfall::
	.string "{JPN}てもちの ポケモン ぜんいんの\n"
	.string "とくこうと とくぼうが すこし あがる。\p"
	.string "それに せんとう いがいで\n"
	.string "たきのぼりが つかえるように なる。$"

CeruleanCity_House1_Text_AllMonsWillObeyYou::
	.string "{JPN}すべての ポケモンが いうことを きく!$"

