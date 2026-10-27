const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("{JPN}とくせい なし{ENG}"),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("{JPN}あくしゅう{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてをひるませることがある{ENG}"),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("{JPN}あめふらし{ENG}"),
        .description = COMPOUND_STRING("{JPN}せんとうに でると あめを ふらす{ENG}"),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("{JPN}かそく{ENG}"),
        .description = COMPOUND_STRING("{JPN}ちょっとずつ すばやく なっていく{ENG}"),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("{JPN}カブトアーマー{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざを きゅうしょに うけない{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("{JPN}がんじょう{ENG}"),
        .description = COMPOUND_STRING("{JPN}いちげきひっさつがきかない{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("{JPN}しめりけ{ENG}"),
        .description = COMPOUND_STRING("{JPN}だれも じばくが できなくなる{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("{JPN}じゅうなん{ENG}"),
        .description = COMPOUND_STRING("{JPN}まひ じょうたいに ならない{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("{JPN}すながくれ{ENG}"),
        .description = COMPOUND_STRING("{JPN}すなあらしで かいひりつが あがる{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("{JPN}せいでんき{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわった あいてを まひさせる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("{JPN}ちくでん{ENG}"),
        .description = COMPOUND_STRING("{JPN}でんきを うけると かいふくする{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("{JPN}ちょすい{ENG}"),
        .description = COMPOUND_STRING("{JPN}みずを うけると かいふくする{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("{JPN}どんかん{ENG}"),
        .description = COMPOUND_STRING("{JPN}メロメロ じょうたいに ならない{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("{JPN}ノーてんき{ENG}"),
        .description = COMPOUND_STRING("{JPN}てんきの えいきょうが なくなる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("{JPN}ふくがん{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざの めいちゅうりつが あがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("{JPN}ふみん{ENG}"),
        .description = COMPOUND_STRING("{JPN}ねむり じょうたいに ならない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("{JPN}へんしょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}うけた わざの タイプに へんかする{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("{JPN}めんえき{ENG}"),
        .description = COMPOUND_STRING("{JPN}どく じょうたいに ならない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("{JPN}もらいび{ENG}"),
        .description = COMPOUND_STRING("{JPN}ほのおを うけると つよくなる{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("{JPN}りんぷん{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざの ついかこうかを うけない{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("{JPN}マイペース{ENG}"),
        .description = COMPOUND_STRING("{JPN}こんらん じょうたいに ならない{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("{JPN}きゅうばん{ENG}"),
        .description = COMPOUND_STRING("{JPN}きゅうばんで じめんに はりつく{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("{JPN}いかく{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての こうげきを さげる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("{JPN}かげふみ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてを にげられなくする{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("{JPN}さめはだ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわった あいてを キズつける{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("{JPN}ふしぎなまもり{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうか ばつぐん しか あたらない{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("{JPN}ふゆう{ENG}"),
        .description = COMPOUND_STRING("{JPN}じめんタイプの わざを うけない{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("{JPN}ほうし{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわった あいてに ほうしがつく{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("{JPN}シンクロ{ENG}"),
        .description = COMPOUND_STRING("{JPN}どく まひ やけどを あいてにうつす{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("{JPN}クリアボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてに のうりょくを さげられない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("{JPN}しぜんかいふく{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひっこむと いじょうが なおる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("{JPN}ひらいしん{ENG}"),
        .description = COMPOUND_STRING("{JPN}でんきタイプの わざが じぶんにくる{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("{JPN}てんのめぐみ{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざの ついかこうかが でやすい{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("{JPN}すいすい{ENG}"),
        .description = COMPOUND_STRING("{JPN}あめのとき すばやさが はやくなる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("{JPN}ようりょくそ{ENG}"),
        .description = COMPOUND_STRING("{JPN}はれのとき すばやさが はやくなる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("{JPN}はっこう{ENG}"),
        .description = COMPOUND_STRING("{JPN}ポケモンに そうぐう しやすくなる{ENG}"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("{JPN}トレース{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてと おなじ とくせいになる{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("{JPN}ちからもち{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきりょくが たかい{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("{JPN}どくのトゲ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわったあいてに どくをあたえる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("{JPN}せいしんりょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひるまない{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("{JPN}マグマのよろい{ENG}"),
        .description = COMPOUND_STRING("{JPN}こおり じょうたいに ならない{ENG}"),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("{JPN}みずのベール{ENG}"),
        .description = COMPOUND_STRING("{JPN}やけど じょうたいに ならない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("{JPN}じりょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}はがねタイプが にげられなくなる{ENG}"),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("{JPN}ぼうおん{ENG}"),
        .description = COMPOUND_STRING("{JPN}おとの わざを うけない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("{JPN}あめうけざら{ENG}"),
        .description = COMPOUND_STRING("{JPN}あめのとき すこしずつ かいふく{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("{JPN}すなおこし{ENG}"),
        .description = COMPOUND_STRING("{JPN}せんとうで すなあらしを おこす{ENG}"),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("{JPN}プレッシャー{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての PPが へりやすくなる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("{JPN}あついしぼう{ENG}"),
        .description = COMPOUND_STRING("{JPN}ほのお こおりに つよい{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("{JPN}はやおき{ENG}"),
        .description = COMPOUND_STRING("{JPN}おきるのが はやくなる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("{JPN}ほのおのからだ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわった あいてを やけど させる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("{JPN}にげあし{ENG}"),
        .description = COMPOUND_STRING("{JPN}せんとうから にげやすい{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("{JPN}するどいめ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてに めいちゅうを さげられない{ENG}"),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("{JPN}かいりきバサミ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてに こうげきを さげられない{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("{JPN}ものひろい{ENG}"),
        .description = COMPOUND_STRING("{JPN}どうぐを ひろってくる ことがある{ENG}"),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("{JPN}なまけ{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきが れんぞくで だせない{ENG}"),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("{JPN}はりきり{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきは たかいが はずれやすい{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("{JPN}メロメロボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわった あいてを メロメロにする{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("{JPN}プラス{ENG}"),
        .description = COMPOUND_STRING("{JPN}マイナスが いると つよくなる{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("{JPN}マイナス{ENG}"),
        .description = COMPOUND_STRING("{JPN}プラスが いると つよくなる{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("{JPN}てんきや{ENG}"),
        .description = COMPOUND_STRING("{JPN}てんきで ポワルンが へんかする{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("{JPN}ねんちゃく{ENG}"),
        .description = COMPOUND_STRING("{JPN}どうぐを とられない{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("{JPN}だっぴ{ENG}"),
        .description = COMPOUND_STRING("{JPN}だっぴして からだを なおす{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("{JPN}こんじょう{ENG}"),
        .description = COMPOUND_STRING("{JPN}いじょうのとき こうげきが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("{JPN}ふしぎなうろこ{ENG}"),
        .description = COMPOUND_STRING("{JPN}いじょうのとき ぼうぎょが あがる{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("{JPN}ヘドロえき{ENG}"),
        .description = COMPOUND_STRING("{JPN}すいとると たいりょくが へる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("{JPN}しんりょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}ピンチに くさの いりょくが あがる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("{JPN}もうか{ENG}"),
        .description = COMPOUND_STRING("{JPN}ピンチに ほのおが つよくなる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("{JPN}げきりゅう{ENG}"),
        .description = COMPOUND_STRING("{JPN}ピンチに みずの いりょくが あがる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("{JPN}むしのしらせ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ピンチに むしの いりょくが あがる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("{JPN}いしあたま{ENG}"),
        .description = COMPOUND_STRING("{JPN}ぶつかっても はんどうを うけない{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("{JPN}ひでり{ENG}"),
        .description = COMPOUND_STRING("{JPN}せんとうで ひざしを つよくする{ENG}"),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("{JPN}ありじごく{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてを にげられなくする{ENG}"),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("{JPN}やるき{ENG}"),
        .description = COMPOUND_STRING("{JPN}ねむらない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("{JPN}しろいけむり{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてに のうりょくを さげられない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("{JPN}ヨガパワー{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきりょくが たかい{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("{JPN}シェルアーマー{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざを きゅうしょに うけない{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("{JPN}エアロック{ENG}"),
        .description = COMPOUND_STRING("{JPN}てんきの えいきょうが なくなる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("{JPN}ちどりあし{ENG}"),
        .description = COMPOUND_STRING("{JPN}こんらんのとき かいひりつが あがる{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("{JPN}でんきエンジン{ENG}"),
        .description = COMPOUND_STRING("{JPN}でんきをうけるとすばやさがあがる{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("{JPN}とうそうしん{ENG}"),
        .description = COMPOUND_STRING("{JPN}せいべつが おなじだと つよくなる{ENG}"),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("{JPN}ふくつのこころ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひるむ たびに すばやさが あがる{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("{JPN}ゆきがくれ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あられやゆきでかいひりつアップ{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("{JPN}くいしんぼう{ENG}"),
        .description = COMPOUND_STRING("{JPN}きのみを いつもより はやく つかう{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("{JPN}いかりのつぼ{ENG}"),
        .description = COMPOUND_STRING("{JPN}きゅうしょをうけるとこうげきがあがる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("{JPN}かるわざ{ENG}"),
        .description = COMPOUND_STRING("{JPN}どうぐがなくなるとすばやさがあがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("{JPN}たいねつ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ほのおとやけどのダメージをへらす{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("{JPN}たんじゅん{ENG}"),
        .description = COMPOUND_STRING("{JPN}のうりょく へんかが ばいになる{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("{JPN}かんそうはだ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あつさに よわいが みずで かいふく{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("{JPN}ダウンロード{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてによってのうりょくをかえる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("{JPN}てつのこぶし{ENG}"),
        .description = COMPOUND_STRING("{JPN}パンチの わざの いりょくが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("{JPN}ポイズンヒール{ENG}"),
        .description = COMPOUND_STRING("{JPN}どくで HPを かいふくする{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("{JPN}てきおうりょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんのタイプのいりょくがあがる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("{JPN}スキルリンク{ENG}"),
        .description = COMPOUND_STRING("{JPN}れんぞくわざが5かいあたる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("{JPN}うるおいボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あめのときじょうたいいじょうをなおす{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("{JPN}サンパワー{ENG}"),
        .description = COMPOUND_STRING("{JPN}はれでHPがへるがとくこうがあがる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("{JPN}はやあし{ENG}"),
        .description = COMPOUND_STRING("{JPN}じょうたいいじょうですばやさがあがる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("{JPN}ノーマルスキン{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざがすべてノーマルタイプになる{ENG}"),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("{JPN}スナイパー{ENG}"),
        .description = COMPOUND_STRING("{JPN}きゅうしょであたえるダメージがふえる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("{JPN}マジックガード{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきいがいでダメージをうけない{ENG}"),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("{JPN}ノーガード{ENG}"),
        .description = COMPOUND_STRING("{JPN}おたがいの わざが かならず あたる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("{JPN}あとだし{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてより こうどうが おそくなる{ENG}"),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("{JPN}テクニシャン{ENG}"),
        .description = COMPOUND_STRING("{JPN}よわい わざの いりょくが あがる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("{JPN}リーフガード{ENG}"),
        .description = COMPOUND_STRING("{JPN}はれで じょうたいいじょうを ふせぐ{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("{JPN}ぶきよう{ENG}"),
        .description = COMPOUND_STRING("{JPN}もっている どうぐを つかえない{ENG}"),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("{JPN}かたやぶり{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての とくせいを むしする{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("{JPN}きょううん{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざがきゅうしょにあたりやすくなる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("{JPN}ゆうばく{ENG}"),
        .description = COMPOUND_STRING("{JPN}たおされるとふれたあいてにダメージ{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("{JPN}きけんよち{ENG}"),
        .description = COMPOUND_STRING("{JPN}きけんな わざを さっちする{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("{JPN}よちむ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての わざを ひとつ よみとる{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("{JPN}てんねん{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてののうりょくへんかをむしする{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("{JPN}いろめがね{ENG}"),
        .description = COMPOUND_STRING("{JPN}いまひとつであたえるダメージがふえる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("{JPN}フィルター{ENG}"),
        .description = COMPOUND_STRING("{JPN}ばつぐんで うける ダメージが へる{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("{JPN}スロースタート{ENG}"),
        .description = COMPOUND_STRING("{JPN}しばらくこうげきとすばやさがさがる{ENG}"),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("{JPN}きもったま{ENG}"),
        .description = COMPOUND_STRING("{JPN}ゴーストタイプに わざが あたる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("{JPN}よびみず{ENG}"),
        .description = COMPOUND_STRING("{JPN}みずタイプの わざが じぶんにくる{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("{JPN}アイスボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あられやゆきでHPかいふく{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("{JPN}ハードロック{ENG}"),
        .description = COMPOUND_STRING("{JPN}ばつぐんで うける ダメージが へる{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("{JPN}ゆきふらし{ENG}"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("{JPN}せんとうに でると ゆきを ふらす{ENG}"),
    #else
        .description = COMPOUND_STRING("{JPN}せんとうに でると あられを ふらす{ENG}"),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("{JPN}みつあつめ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あまいミツをひろってくることがある{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("{JPN}おみとおし{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての もちものを みとおす{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("{JPN}すてみ{ENG}"),
        .description = COMPOUND_STRING("{JPN}はんどうを うけるわざが つよくなる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("{JPN}マルチタイプ{ENG}"),
        .description = COMPOUND_STRING("{JPN}もっているプレートでタイプがかわる{ENG}"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("{JPN}フラワーギフト{ENG}"),
        .description = COMPOUND_STRING("{JPN}はれのとき みかたがわが つよくなる{ENG}"),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("{JPN}ナイトメア{ENG}"),
        .description = COMPOUND_STRING("{JPN}ねむっている あいてに ダメージ{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("{JPN}わるいてぐせ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわられるとあいてのどうぐをぬすむ{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("{JPN}ちからずく{ENG}"),
        .description = COMPOUND_STRING("{JPN}ついかこうかをなくしてわざをつよめる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("{JPN}あまのじゃく{ENG}"),
        .description = COMPOUND_STRING("{JPN}のうりょく へんかが ぎゃくになる{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("{JPN}きんちょうかん{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてが きのみを たべられなくなる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("{JPN}まけんき{ENG}"),
        .description = COMPOUND_STRING("{JPN}のうりょくがさがるとこうげきをあげる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("{JPN}よわき{ENG}"),
        .description = COMPOUND_STRING("{JPN}ピンチで こうげき とくこうがさがる{ENG}"),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("{JPN}のろわれボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}うけた わざを ふうじる ことがある{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("{JPN}いやしのこころ{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたのじょうたいいじょうをなおす{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("{JPN}フレンドガード{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの うける ダメージを へらす{ENG}"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("{JPN}くだけるよろい{ENG}"),
        .description = COMPOUND_STRING("{JPN}ぶつりでぼうぎょがさがるがはやくなる{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("{JPN}ヘヴィメタル{ENG}"),
        .description = COMPOUND_STRING("{JPN}たいじゅうが2ばいになる{ENG}"),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("{JPN}ライトメタル{ENG}"),
        .description = COMPOUND_STRING("{JPN}たいじゅうがはんぶんになる{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("{JPN}マルチスケイル{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPまんたんでダメージはんげん{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("{JPN}どくぼうそう{ENG}"),
        .description = COMPOUND_STRING("{JPN}どくのとき こうげきが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("{JPN}ねつぼうそう{ENG}"),
        .description = COMPOUND_STRING("{JPN}やけどのとき とくこうが あがる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("{JPN}しゅうかく{ENG}"),
        .description = COMPOUND_STRING("{JPN}つかった きのみを ふっかつさせる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("{JPN}テレパシー{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの こうげきが あたらない{ENG}"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("{JPN}ムラっけ{ENG}"),
        .description = COMPOUND_STRING("{JPN}のうりょくが ランダムに かわる{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("{JPN}ぼうじん{ENG}"),
        .description = COMPOUND_STRING("{JPN}こなと てんきの ダメージを ふせぐ{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("{JPN}どくしゅ{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきした あいてを どくにする{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("{JPN}さいせいりょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひっこむと HPが かいふくする{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("{JPN}はとむね{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてに ぼうぎょを さげられない{ENG}"),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("{JPN}すなかき{ENG}"),
        .description = COMPOUND_STRING("{JPN}すなあらしのときすばやさがはやくなる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("{JPN}ミラクルスキン{ENG}"),
        .description = COMPOUND_STRING("{JPN}へんかわざを うけにくい{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("{JPN}アナライズ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さいごに わざをだすと つよくなる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("{JPN}イリュージョン{ENG}"),
        .description = COMPOUND_STRING("{JPN}てもちの ポケモンに ばける{ENG}"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("{JPN}かわりもの{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての ポケモンに へんしんする{ENG}"),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("{JPN}すりぬけ{ENG}"),
        .description = COMPOUND_STRING("{JPN}かべやみがわりのえいきょうをうけない{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("{JPN}ミイラ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ふれられるととくせいをミイラにする{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("{JPN}じしんかじょう{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてをたおすとこうげきがあがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("{JPN}せいぎのこころ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あくわざをうけるとこうげきがあがる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("{JPN}びびり{ENG}"),
        .description = COMPOUND_STRING("{JPN}ゴーストむしあくですばやさがあがる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("{JPN}マジックミラー{ENG}"),
        .description = COMPOUND_STRING("{JPN}へんかわざを はねかえす{ENG}"),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("{JPN}そうしょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}くさわざをうけるとこうげきがあがる{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("{JPN}いたずらごころ{ENG}"),
        .description = COMPOUND_STRING("{JPN}へんかわざが はやく だせる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("{JPN}すなのちから{ENG}"),
        .description = COMPOUND_STRING("{JPN}すなでじめんいわはがねがつよくなる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("{JPN}てつのトゲ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さわった あいてを キズつける{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("{JPN}ダルマモード{ENG}"),
        .description = COMPOUND_STRING("{JPN}ピンチに なると すがたが かわる{ENG}"),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("{JPN}しょうりのほし{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたがわのめいちゅうりつがあがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("{JPN}ターボブレイズ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての とくせいを むしする{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("{JPN}テラボルテージ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての とくせいを むしする{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("{JPN}アロマベール{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたがわの メンタルわざを ふせぐ{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("{JPN}フラワーベール{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの くさの へんかを ふせぐ{ENG}"),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("{JPN}ほおぶくろ{ENG}"),
        .description = COMPOUND_STRING("{JPN}きのみをたべるとHPもかいふくする{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("{JPN}へんげんじざい{ENG}"),
        .description = COMPOUND_STRING("{JPN}つかったわざの タイプに へんかする{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("{JPN}ファーコート{ENG}"),
        .description = COMPOUND_STRING("{JPN}ぶつりわざの ダメージを へらす{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("{JPN}マジシャン{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきをあてたときどうぐをうばう{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("{JPN}ぼうだん{ENG}"),
        .description = COMPOUND_STRING("{JPN}たまや ばくだんの わざを うけない{ENG}"),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("{JPN}かちき{ENG}"),
        .description = COMPOUND_STRING("{JPN}のうりょくがさがるととくこうをあげる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("{JPN}がんじょうあご{ENG}"),
        .description = COMPOUND_STRING("{JPN}キバの わざの いりょくが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("{JPN}フリーズスキン{ENG}"),
        .description = COMPOUND_STRING("{JPN}ノーマルわざがこおりになりつよくなる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("{JPN}スイートベール{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんと みかたが ねむらない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("{JPN}バトルスイッチ{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきじに すがたが かわる{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("{JPN}はやてのつばさ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひこうわざを さきに だせる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("{JPN}メガランチャー{ENG}"),
        .description = COMPOUND_STRING("{JPN}はどうの わざの いりょくが あがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("{JPN}くさのけがわ{ENG}"),
        .description = COMPOUND_STRING("{JPN}くさむらで ぼうぎょが あがる{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("{JPN}きょうせい{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたに どうぐを わたす{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("{JPN}かたいツメ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ちょくせつ こうげきが つよくなる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("{JPN}フェアリースキン{ENG}"),
        .description = COMPOUND_STRING("{JPN}ノーマルわざがフェアリーになりつよい{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("{JPN}ぬめぬめ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ふれた あいての すばやさを さげる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("{JPN}スカイスキン{ENG}"),
        .description = COMPOUND_STRING("{JPN}ノーマルわざがひこうになりつよくなる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("{JPN}おやこあい{ENG}"),
        .description = COMPOUND_STRING("{JPN}おやこで 2かい こうげきする{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("{JPN}ダークオーラ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ぜんいんの あくわざが つよくなる{ENG}"),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("{JPN}フェアリーオーラ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ぜんいんのフェアリーわざがつよくなる{ENG}"),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("{JPN}オーラブレイク{ENG}"),
        .description = COMPOUND_STRING("{JPN}オーラの こうかを ぎゃくにする{ENG}"),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("{JPN}はじまりのうみ{ENG}"),
        .description = COMPOUND_STRING("{JPN}てんきを つよいあめに する{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("{JPN}おわりのだいち{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひざしを とても つよくする{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("{JPN}デルタストリーム{ENG}"),
        .description = COMPOUND_STRING("{JPN}てんきを らんきりゅうに する{ENG}"),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("{JPN}じきゅうりょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきをうけるとぼうぎょがあがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("{JPN}にげごし{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPが はんぶんに なると にげだす{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("{JPN}ききかいひ{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPが はんぶんに なると にげだす{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("{JPN}みずがため{ENG}"),
        .description = COMPOUND_STRING("{JPN}みずで ぼうぎょが ぐーんと あがる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("{JPN}ひとでなし{ENG}"),
        .description = COMPOUND_STRING("{JPN}どくのあいてにはきゅうしょになる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("{JPN}リミットシールド{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPが はんぶんに なると こわれる{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("{JPN}はりこみ{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうたいした てきに ダメージ2ばい{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("{JPN}すいほう{ENG}"),
        .description = COMPOUND_STRING("{JPN}ほのおややけどからみをまもる{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("{JPN}はがねつかい{ENG}"),
        .description = COMPOUND_STRING("{JPN}はがねの わざの いりょくが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("{JPN}ぎゃくじょう{ENG}"),
        .description = COMPOUND_STRING("{JPN}ピンチでとくこうがあがる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("{JPN}ゆきかき{ENG}"),
        .description = COMPOUND_STRING("{JPN}あられやゆきですばやさアップ{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("{JPN}えんかく{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざを せっしょく しないで だす{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("{JPN}うるおいボイス{ENG}"),
        .description = COMPOUND_STRING("{JPN}おとわざが みずタイプに なる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("{JPN}ヒーリングシフト{ENG}"),
        .description = COMPOUND_STRING("{JPN}かいふくわざを せんせい できる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("{JPN}エレキスキン{ENG}"),
        .description = COMPOUND_STRING("{JPN}ノーマルわざがでんきになりつよくなる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("{JPN}サーフテール{ENG}"),
        .description = COMPOUND_STRING("{JPN}エレキフィールドで はやくなる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("{JPN}ぎょぐん{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPが おおいと つよい{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("{JPN}ばけのかわ{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきを 1どだけ ふせぐ{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("{JPN}きずなへんげ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてを たおすと へんげする{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("{JPN}スワームチェンジ{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPがはんぶんになるとすがたをかえる{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("{JPN}ふしょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}だれでも どくに することが できる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("{JPN}ぜったいねむり{ENG}"),
        .description = COMPOUND_STRING("{JPN}ゆめうつつで ぜったいに めざめない{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("{JPN}じょおうのいげん{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいては せんせいわざを だせない{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("{JPN}とびだすなかみ{ENG}"),
        .description = COMPOUND_STRING("{JPN}たおされたとき ダメージを あたえる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("{JPN}おどりこ{ENG}"),
        .description = COMPOUND_STRING("{JPN}おどりわざに つづいて おどりだす{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("{JPN}バッテリー{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたのとくしゅのいりょくをあげる{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("{JPN}もふもふ{ENG}"),
        .description = COMPOUND_STRING("{JPN}せっしょくにつよくほのおによわい{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("{JPN}ビビッドボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいては せんせいわざを だせない{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("{JPN}ソウルハート{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひんしになるたびにとくこうがあがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("{JPN}カーリーヘアー{ENG}"),
        .description = COMPOUND_STRING("{JPN}ふれた あいての すばやさを さげる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("{JPN}レシーバー{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの とくせいを うけつぐ{ENG}"),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("{JPN}かがくのちから{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの とくせいを うけつぐ{ENG}"),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("{JPN}ビーストブースト{ENG}"),
        .description = COMPOUND_STRING("{JPN}たおすとさいこうののうりょくアップ{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("{JPN}ARシステム{ENG}"),
        .description = COMPOUND_STRING("{JPN}メモリで じぶんの タイプが かわる{ENG}"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("{JPN}エレキメイカー{ENG}"),
        .description = COMPOUND_STRING("{JPN}エレキフィールドを はりめぐらせる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("{JPN}サイコメイカー{ENG}"),
        .description = COMPOUND_STRING("{JPN}サイコフィールドを はりめぐらせる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("{JPN}ミストメイカー{ENG}"),
        .description = COMPOUND_STRING("{JPN}ミストフィールドを はりめぐらせる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("{JPN}グラスメイカー{ENG}"),
        .description = COMPOUND_STRING("{JPN}グラスフィールドを はりめぐらせる{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("{JPN}メタルプロテクト{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてに のうりょくを さげられない{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("{JPN}ファントムガード{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPまんたんでダメージはんげん{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("{JPN}プリズムアーマー{ENG}"),
        .description = COMPOUND_STRING("{JPN}ばつぐんになる わざを よわめる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("{JPN}ブレインフォース{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうかばつぐんで いりょくが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("{JPN}ふとうのけん{ENG}"),
        .description = COMPOUND_STRING("{JPN}とうじょうじに こうげきが あがる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("{JPN}ふくつのたて{ENG}"),
        .description = COMPOUND_STRING("{JPN}とうじょうじに ぼうぎょが あがる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("{JPN}リベロ{ENG}"),
        .description = COMPOUND_STRING("{JPN}つかったわざの タイプに へんかする{ENG}"),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("{JPN}たまひろい{ENG}"),
        .description = COMPOUND_STRING("{JPN}しっぱいした ボールを ひろってくる{ENG}"),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("{JPN}わたげ{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきをうけるとみんなをおそくする{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("{JPN}スクリューおびれ{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざをひきうけるこうかをむしする{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("{JPN}ミラーアーマー{ENG}"),
        .description = COMPOUND_STRING("{JPN}のうりょくダウンのこうかをはねかえす{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("{JPN}うのミサイル{ENG}"),
        .description = COMPOUND_STRING("{JPN}うみのえものをひだんじにはく{ENG}"),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("{JPN}すじがねいり{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざをひきうけるこうかをむしする{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("{JPN}じょうききかん{ENG}"),
        .description = COMPOUND_STRING("{JPN}みずかほのおをうけるとすばやくなる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("{JPN}パンクロック{ENG}"),
        .description = COMPOUND_STRING("{JPN}おとわざにつよくいりょくもアップ{ENG}"),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("{JPN}すなはき{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきをうけるとすなあらしをおこす{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("{JPN}こおりのりんぷん{ENG}"),
        .description = COMPOUND_STRING("{JPN}とくしゅこうげきを はんげん する{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("{JPN}じゅくせい{ENG}"),
        .description = COMPOUND_STRING("{JPN}きのみの こうかが ばいに なる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("{JPN}アイスフェイス{ENG}"),
        .description = COMPOUND_STRING("{JPN}あられやゆきでみがわりさいせい{ENG}"),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("{JPN}パワースポット{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたのわざがつよくなる{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("{JPN}ぎたい{ENG}"),
        .description = COMPOUND_STRING("{JPN}フィールドによってタイプがかわる{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("{JPN}バリアフリー{ENG}"),
        .description = COMPOUND_STRING("{JPN}すべての バリアを けしさる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("{JPN}はがねのせいしん{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたのはがねこうげきがつよくなる{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("{JPN}ほろびのボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ふれると3ターンごおたがいひんし{ENG}"),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("{JPN}さまようたましい{ENG}"),
        .description = COMPOUND_STRING("{JPN}せっしょくするととくせいをいれかえる{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("{JPN}ごりむちゅう{ENG}"),
        .description = COMPOUND_STRING("{JPN}つよくなるがおなじわざしかだせない{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("{JPN}かがくへんかガス{ENG}"),
        .description = COMPOUND_STRING("{JPN}すべてのとくせいのこうかがきえる{ENG}"),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("{JPN}パステルベール{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんも みかたも どくに ならない{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("{JPN}はらぺこスイッチ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ターンのおわりに すがたを かえる{ENG}"),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("{JPN}クイックドロウ{ENG}"),
        .description = COMPOUND_STRING("{JPN}さきに こうどう できることが ある{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("{JPN}ふかしのこぶし{ENG}"),
        .description = COMPOUND_STRING("{JPN}せっしょくわざがまもりをむしする{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("{JPN}きみょうなくすり{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの のうりょくを もとにもどす{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("{JPN}トランジスタ{ENG}"),
        .description = COMPOUND_STRING("{JPN}でんきの わざの いりょくが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("{JPN}りゅうのあぎと{ENG}"),
        .description = COMPOUND_STRING("{JPN}ドラゴンのわざのいりょくがあがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("{JPN}しろのいななき{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてをたおすとこうげきがあがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("{JPN}くろのいななき{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいてをたおすととくこうがあがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("{JPN}じんばいったい{ENG}"),
        .description = COMPOUND_STRING("{JPN}きんちょうかんとしろのいななき{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("{JPN}じんばいったい{ENG}"),
        .description = COMPOUND_STRING("{JPN}きんちょうかんとくろのいななき{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("{JPN}とれないにおい{ENG}"),
        .description = COMPOUND_STRING("{JPN}とれないにおいが あいてに うつる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("{JPN}こぼれダネ{ENG}"),
        .description = COMPOUND_STRING("{JPN}わざをうけるとグラスフィールドになる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("{JPN}ねつこうかん{ENG}"),
        .description = COMPOUND_STRING("{JPN}ほのおのわざをうけるとつよくなる{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("{JPN}いかりのこうら{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPがはんぶんになるとつよくなる{ENG}"),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("{JPN}きよめのしお{ENG}"),
        .description = COMPOUND_STRING("{JPN}じょうたいいじょうに ならない{ENG}"),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("{JPN}こんがりボディ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ほのおの わざで ぼうぎょが あがる{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("{JPN}かぜのり{ENG}"),
        .description = COMPOUND_STRING("{JPN}かぜで こうげきが あがる{ENG}"),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("{JPN}ばんけん{ENG}"),
        .description = COMPOUND_STRING("{JPN}いかく されると つよくなる{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("{JPN}いわはこび{ENG}"),
        .description = COMPOUND_STRING("{JPN}いわの わざの いりょくが あがる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("{JPN}ふうりょくでんき{ENG}"),
        .description = COMPOUND_STRING("{JPN}かぜで じゅうでん する{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("{JPN}マイティチェンジ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ひっこむと マイティチェンジ する{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("{JPN}しれいとう{ENG}"),
        .description = COMPOUND_STRING("{JPN}ヘイラッシャがいるとしれいをだす{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("{JPN}でんきにかえる{ENG}"),
        .description = COMPOUND_STRING("{JPN}ダメージをうけるとじゅうでんする{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("{JPN}こだいかっせい{ENG}"),
        .description = COMPOUND_STRING("{JPN}はれでさいこうののうりょくアップ{ENG}"),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("{JPN}クォークチャージ{ENG}"),
        .description = COMPOUND_STRING("{JPN}エレキばでさいだいのうりょくUP{ENG}"),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("{JPN}おうごんのからだ{ENG}"),
        .description = COMPOUND_STRING("{JPN}へんかわざを むこうか する{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("{JPN}わざわいのうつわ{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんいがいの とくこうが さがる{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("{JPN}わざわいのつるぎ{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんいがいの ぼうぎょが さがる{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("{JPN}わざわいのおふだ{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんいがいの こうげきが さがる{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("{JPN}わざわいのたま{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんいがいの とくぼうが さがる{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("{JPN}ひひいろのこどう{ENG}"),
        .description = COMPOUND_STRING("{JPN}せんとうで ひざしを つよくする{ENG}"),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("{JPN}ハドロンエンジン{ENG}"),
        .description = COMPOUND_STRING("{JPN}エレキフィールドを はりめぐらせる{ENG}"),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("{JPN}びんじょう{ENG}"),
        .description = COMPOUND_STRING("{JPN}のうりょくがあがるとじぶんもあがる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("{JPN}はんすう{ENG}"),
        .description = COMPOUND_STRING("{JPN}きのみを もう1かい だけ たべる{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("{JPN}きれあじ{ENG}"),
        .description = COMPOUND_STRING("{JPN}きるわざの いりょくが あがる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("{JPN}そうだいしょう{ENG}"),
        .description = COMPOUND_STRING("{JPN}たおされたみかたのかずでつよくなる{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("{JPN}きょうえん{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの のうりょくを コピーする{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("{JPN}どくげしょう{ENG}"),
        .description = COMPOUND_STRING("{JPN}こうげきをうけるとどくびしをばらまく{ENG}"),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("{JPN}テイルアーマー{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいては せんせいわざを だせない{ENG}"),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("{JPN}どしょく{ENG}"),
        .description = COMPOUND_STRING("{JPN}じめんを うけると かいふくする{ENG}"),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("{JPN}きんしのちから{ENG}"),
        .description = COMPOUND_STRING("{JPN}へんかわざを しっぱい しない{ENG}"),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("{JPN}おもてなし{ENG}"),
        .description = COMPOUND_STRING("{JPN}みかたの HPを すこし かいふく{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("{JPN}しんがん{ENG}"),
        .description = COMPOUND_STRING("{JPN}するどいめときもったま{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("{JPN}おもかげやどし{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんの すばやさを あげる{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("{JPN}おもかげやどし{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんの こうげきを あげる{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("{JPN}おもかげやどし{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんの とくぼうを あげる{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("{JPN}おもかげやどし{ENG}"),
        .description = COMPOUND_STRING("{JPN}じぶんの ぼうぎょを あげる{ENG}"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("{JPN}どくのくさり{ENG}"),
        .description = COMPOUND_STRING("{JPN}もうどくに することが ある{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("{JPN}かんろなミツ{ENG}"),
        .description = COMPOUND_STRING("{JPN}あいての かいひりつを さげる{ENG}"),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("{JPN}テラスチェンジ{ENG}"),
        .description = COMPOUND_STRING("{JPN}とうじょうじにテラスタルする{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("{JPN}テラスシェル{ENG}"),
        .description = COMPOUND_STRING("{JPN}HPがまんたんのときダメージがへる{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("{JPN}ゼロフォーミング{ENG}"),
        .description = COMPOUND_STRING("{JPN}てんきとフィールドをすべてゼロにする{ENG}"),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("{JPN}どくくぐつ{ENG}"),
        .description = COMPOUND_STRING("{JPN}どくになったあいてはこんらんする{ENG}"),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    // Wishes of Tomorrow: Z-A / Champions Mega abilities ported from expansion 1.16-1.17.
    // Text matches upstream; aiRatings follow the closest existing ability (upstream has none yet).
    [ABILITY_PIERCING_DRILL] =
    {
        .name = _("{JPN}かんつうドリル{ENG}"),
        .description = COMPOUND_STRING("{JPN}せっしょくわざがまもりをむしする{ENG}"),
        .aiRating = 6,
    },

    [ABILITY_DRAGONIZE] =
    {
        .name = _("{JPN}ドラゴンスキン{ENG}"),
        .description = COMPOUND_STRING("{JPN}ノーマルわざがドラゴンになりつよい{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_EELEVATE] =
    {
        .name = _("{JPN}うなぎのぼり{ENG}"),
        .description = COMPOUND_STRING("{JPN}たおすと のうりょくあがる ういてる{ENG}"),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_314] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("{JPN}とくせい なし{ENG}"),
    },

    [ABILITY_MEGA_SOL] =
    {
        .name = _("{JPN}メガソーラー{ENG}"),
        .description = COMPOUND_STRING("{JPN}にほんばれのじょうたいでわざをつかう{ENG}"),
        .aiRating = 8,
    },

    [ABILITY_FIRE_MANE] =
    {
        .name = _("{JPN}ほのおのたてがみ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ほのおわざが つよくなる{ENG}"),
        .aiRating = 7,
    },

    [ABILITY_317] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("{JPN}とくせい なし{ENG}"),
    },

    [ABILITY_SPICY_SPRAY] =
    {
        .name = _("{JPN}とびだすハバネロ{ENG}"),
        .description = COMPOUND_STRING("{JPN}ダメージをうけたときやけどさせる{ENG}"),
        .aiRating = 5,
    },

    // Not implemented upstream yet either; no species uses it in WoT.
    [ABILITY_AURA_GUARD] =
    {
        .name = _("{JPN}オーラガード{ENG}"),
        .description = COMPOUND_STRING("{JPN}まだ じっそうされていない{ENG}"),
    },
};
