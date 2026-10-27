const struct ContestEffect gContestEffects[] =
{
    [CONTEST_EFFECT_HIGHLY_APPEALING] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}かなり アピール できる わざ{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}とても アピール できる わざ{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 40,
        .jam = 0,
        .function = ContestEffect_HighlyAppealing,
    },
    [CONTEST_EFFECT_USER_MORE_EASILY_STARTLED] =
    {
        .description = COMPOUND_STRING("{JPN}この わざの あと\nびっくり しやすく なってしまう{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 60,
        .jam = 0,
        .function = ContestEffect_UserMoreEasilyStartled,
    },
    [CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES] =
    {
        .description = COMPOUND_STRING("{JPN}すごいアピールに なるが このあと\nさいごまで なにも できなくなる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 80,
        .jam = 0,
        .function = ContestEffect_GreatAppealButNoMoreMoves,
    },
    [CONTEST_EFFECT_REPETITION_NOT_BORING] =
    {
        .description = COMPOUND_STRING("{JPN}つづけて だしても しんさいんに\nあきられずに アピール できる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_APPEAL,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_RepetitionNotBoring,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_ONCE] =
    {
        .description = COMPOUND_STRING("{JPN}ほかの ポケモンに おどかされても\n1ど くらいは がまんできる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_AvoidStartleOnce,
    },
    [CONTEST_EFFECT_AVOID_STARTLE] =
    {
        .description = COMPOUND_STRING("{JPN}ほかの ポケモンに おどかされても\nがまんできる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AvoidStartle,
    },
    [CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY] =
    {
        .description = COMPOUND_STRING("{JPN}ほかの ポケモンに おどかされても\nすこし くらいなら がまんできる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_AvoidStartleSlightly,
    },
    [CONTEST_EFFECT_USER_LESS_EASILY_STARTLED] =
    {
        .description = COMPOUND_STRING("{JPN}この わざを だした あとは\nあまり びっくり しなくなる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_AVOID_STARTLE,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_UserLessEasilyStartled,
    },
    [CONTEST_EFFECT_STARTLE_FRONT_MON] =
    {
        .description = COMPOUND_STRING("{JPN}じぶんの まえに アピールした\nポケモンを ちょっと おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS] =
    {
        .description = COMPOUND_STRING("{JPN}アピールが おわっている ポケモン\nみんなを ちょっと おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}じぶんの まえに アピールした\nポケモンを おどろかす{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}じぶんの まえに アピールした\nポケモンを おどろかす{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 20,
        .jam = 30,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}じぶんより まえに アピールした\nポケモン みんなを おどろかす{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}アピールが おわっている ポケモン\nみんなを おどろかす{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 20,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON] =
    {
        .description = COMPOUND_STRING("{JPN}じぶんの まえに アピールした\nポケモンを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 10,
        .jam = 40,
        .function = ContestEffect_StartleFrontMon,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS] =
    {
        .description = COMPOUND_STRING("{JPN}アピールが おわっている ポケモン\nみんなを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 10,
        .jam = 30,
        .function = ContestEffect_StartlePrevMons,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MON_2] =
    {
        .description = COMPOUND_STRING("{JPN}じぶんの まえに アピールした\nポケモンを おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MON,
        .appeal = 30,
        .jam = 20,
        .function = ContestEffect_StartlePrevMon2,
    },
    [CONTEST_EFFECT_STARTLE_PREV_MONS_2] =
    {
        .description = COMPOUND_STRING("{JPN}アピールが おわっている ポケモン\nみんなを おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_StartlePrevMons2,
    },
    [CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}かんきゃくが ほかの ポケモンに\nあまり きたい しなくなる{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}しんさいんの ほかの ポケモンへの\nちゅうもくを そらすことが できる{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_ShiftJudgeAttention,
    },
    [CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION] =
    {
        .description = COMPOUND_STRING("{JPN}しんさいんに ちゅうもく されている\nポケモンを とくに おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonWithJudgesAttention,
    },
    [CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN] =
    {
        .description = COMPOUND_STRING("{JPN}みんなの じゃまを しまくって\nつぎの アピールは さんか しない{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 40,
        .jam = 40,
        .function = ContestEffect_JamsOthersButMissOneTurn,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL] =
    {
        .description = COMPOUND_STRING("{JPN}おなじ タイプの アピールを した\nポケモンを とくに おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsSameTypeAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL] =
    {
        .description = COMPOUND_STRING("{JPN}かっこいい アピールを した\nポケモンを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsCoolAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL] =
    {
        .description = COMPOUND_STRING("{JPN}うつくしい アピールを した\nポケモンを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsBeautyAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL] =
    {
        .description = COMPOUND_STRING("{JPN}かわいい アピールを した\nポケモンを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsCuteAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL] =
    {
        .description = COMPOUND_STRING("{JPN}かしこい アピールを した\nポケモンを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsSmartAppeal,
    },
    [CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL] =
    {
        .description = COMPOUND_STRING("{JPN}たくましい アピールを した\nポケモンを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_StartleMonsToughAppeal,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS] =
    {
        .description = COMPOUND_STRING("{JPN}このあと アピールする ポケモン\n1ぴきを きんちょう させる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_MakeFollowingMonNervous,
    },
    [CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}このあと アピールする ポケモン\nみんなを きんちょう させる{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}このあと アピールする ポケモン\nみんなを きんちょう させる{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_MakeFollowingMonsNervous,
    },
    [CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS] =
    {
        .description = COMPOUND_STRING("{JPN}アピールが おわった ポケモンの\nちょうしを さげる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_WorsenConditionOfPrevMons,
    },
    [CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION] =
    {
        .description = COMPOUND_STRING("{JPN}ちょうしの いい ポケモン\nみんなを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 30,
        .jam = 10,
        .function = ContestEffect_BadlyStartlesMonsInGoodCondition,
    },
    [CONTEST_EFFECT_BETTER_IF_FIRST] =
    {
        .description = COMPOUND_STRING("{JPN}1ばん はじめに アピールすると\nアピールが すごく うまくいく{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfFirst,
    },
    [CONTEST_EFFECT_BETTER_IF_LAST] =
    {
        .description = COMPOUND_STRING("{JPN}1ばん さいごに アピールすると\nアピールが すごく うまくいく{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfLast,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES] =
    {
        .description = COMPOUND_STRING("{JPN}それまでの ポケモンの アピールと\nおなじくらいの アピールに みせる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AppealAsGoodAsPrevOnes,
    },
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE] =
    {
        .description = COMPOUND_STRING("{JPN}1つまえの ポケモンの アピールと\nおなじくらい うまく できる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_AppealAsGoodAsPrevOne,
    },
    [CONTEST_EFFECT_BETTER_WHEN_LATER] =
    {
        .description = COMPOUND_STRING("{JPN}みんなの あとで アピールするほど\nすごい アピールに みせられる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWhenLater,
    },
    [CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}だすときに よって アピールの\nできぐあいが いろいろと かわる{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}だすときに よって アピールの\nできぐあいが いろいろと かわる{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_QualityDependsOnTiming,
    },
    [CONTEST_EFFECT_BETTER_IF_SAME_TYPE] =
    {
        .description = COMPOUND_STRING("{JPN}1つまえの ポケモンの アピールと\nタイプが おなじなら きにいられる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfSameType,
    },
    [CONTEST_EFFECT_BETTER_IF_DIFF_TYPE] =
    {
        .description = COMPOUND_STRING("{JPN}1つまえの ポケモンの アピールと\nタイプが ちがうなら きにいられる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 20,
        .jam = 0,
        .function = ContestEffect_BetterIfDiffType,
    },
    [CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}1つまえの ポケモンの アピールの\nうまさに えいきょう される{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}1つまえの ポケモンの アピールの\nうまさに えいきょう される{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_AffectedByPrevAppeal,
    },
    [CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS] =
    {
        .description = COMPOUND_STRING("{JPN}アピールの ちょうしが あがる\nきんちょうも しにくくなる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_ImproveConditionPreventNervousness,
    },
    [CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION] =
    {
        .description = COMPOUND_STRING("{JPN}ちょうしが いいときに だすと\nアピールが とても うまくいく{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWithGoodCondition,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_EARLIER] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}このつぎの アピールを\nはじめの ほうに だすことが できる{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}このつぎの アピールを\nはじめの ほうに だすことが できる{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_NextAppealEarlier,
    },
    [CONTEST_EFFECT_NEXT_APPEAL_LATER] =
    {
        #if C_UPDATED_MOVE_EFFECTS >= GEN_6
        .description = COMPOUND_STRING("{JPN}このつぎの アピールを\nおわりの ほうに だすことが できる{ENG}"),
        #else
        .description = COMPOUND_STRING("{JPN}このつぎの アピールを\nおわりの ほうに だすことが できる{ENG}"),
        #endif
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_NextAppealLater,
    },
    [CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER] =
    {
        .description = COMPOUND_STRING("{JPN}このつぎの アピールの\nじゅんばんが かわりやすく なる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_MakeScramblingTurnOrderEasier,
    },
    [CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER] =
    {
        .description = COMPOUND_STRING("{JPN}このつぎの アピールの\nじゅんばんを めちゃくちゃに する{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_TURN_ORDER,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_ScrambleNextTurnOrder,
    },
    [CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST] =
    {
        .description = COMPOUND_STRING("{JPN}どの コンテストで みせても\nかならず もりあがる アピール{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = C_UPDATED_MOVE_EFFECTS >= GEN_6 ? 20 : 10,
        .jam = 0,
        .function = ContestEffect_ExciteAudienceInAnyContest,
    },
    [CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS] =
    {
        .description = COMPOUND_STRING("{JPN}アピールが うまくいった ポケモン\nみんなを かなり おどろかす{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_STARTLE_MONS,
        .appeal = 20,
        .jam = 10,
        .function = ContestEffect_BadlyStartleMonsWithGoodAppeals,
    },
    [CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED] =
    {
        .description = COMPOUND_STRING("{JPN}かいじょうが もりあがっている ほど\nアピールが きにいられる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_SPECIAL_APPEAL,
        .appeal = 10,
        .jam = 0,
        .function = ContestEffect_BetterWhenAudienceExcited,
    },
    [CONTEST_EFFECT_DONT_EXCITE_AUDIENCE] =
    {
        .description = COMPOUND_STRING("{JPN}このアピールのあと かいじょうが\nしばらく もりあがらなく なる{ENG}"),
        .effectType = CONTEST_EFFECT_TYPE_WORSEN,
        .appeal = 30,
        .jam = 0,
        .function = ContestEffect_DontExciteAudience,
    },
};
