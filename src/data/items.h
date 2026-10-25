#if I_USE_EVO_HELD_ITEMS_FROM_BAG == TRUE
    #define EVO_HELD_ITEM_TYPE ITEM_USE_PARTY_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_EvolutionStone
#else
    #define EVO_HELD_ITEM_TYPE ITEM_USE_BAG_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_CannotUse
#endif

#define GEM_BOOST_PARAM ((I_GEM_BOOST_POWER >= GEN_6) ? 30 : 50)
#define TYPE_BOOST_PARAM ((I_TYPE_BOOST_POWER >= GEN_4) ? 20 : 10) // For non Pokémon-specific type-boosting held items.
#define POWER_ITEM_BOOST ((I_POWER_ITEM_BOOST >= GEN_7) ? 8 : 4)

#define X_ITEM_STAGES ((B_X_ITEMS_BUFF >= GEN_7) ? 2 : 1)

#define TREASURE_FACTOR ((I_SELL_VALUE_FRACTION >= GEN_9) ? 2 : 1)

#define ITEM_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_LENGTH)
#define ITEM_PLURAL_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_PLURAL_LENGTH)

// Shared Item Description entries

static const u8 sFullHealDesc[]       = _("{JPN}じょうたい いじょうを\n{JPN}すべて かいふくする{ENG}");

static const u8 sPokeDollDesc[]       = _("{JPN}そうぐうした やせいの\n{JPN}ポケモンから かならず\n{JPN}にげることが できる{ENG}");

static const u8 sMaxReviveDesc[]      = _("{JPN}ひんし じょうたいから\n{JPN}たいりょくを\n{JPN}ぜんかいふくする{ENG}");

static const u8 sHealthFeatherDesc[]  = _("{JPN}たいりょくの\n{JPN}きそポイントを\n{JPN}ちょっと あげる{ENG}");

static const u8 sMuscleFeatherDesc[]  = _("{JPN}こうげきの\n{JPN}きそポイントを\n{JPN}ちょっと あげる{ENG}");

static const u8 sResistFeatherDesc[]  = _("{JPN}ぼうぎょの\n{JPN}きそポイントを\n{JPN}ちょっと あげる{ENG}");

static const u8 sGeniusFeatherDesc[]  = _("{JPN}とくこうの\n{JPN}きそポイントを\n{JPN}ちょっと あげる{ENG}");

static const u8 sCleverFeatherDesc[]  = _("{JPN}とくぼうの\n{JPN}きそポイントを\n{JPN}ちょっと あげる{ENG}");

static const u8 sSwiftFeatherDesc[]   = _("{JPN}すばやさの\n{JPN}きそポイントを\n{JPN}ちょっと あげる{ENG}");

static const u8 sBigMushroomDesc[]    = _("{JPN}めずらしい キノコ\n{JPN}たかく うれる{ENG}");

static const u8 sShardsDesc[]         = _("{JPN}むかしに つくられた\n{JPN}どうぐの かけら らしい\n{JPN}やすく うれる{ENG}");

static const u8 sRootFossilDesc[]     = _("{JPN}おおむかし かいていで\n{JPN}くらしていた ポケモンの\n{JPN}カセキと いわれている{ENG}");

static const u8 sFossilizedFishDesc[] = _("{JPN}おおむかし うみに\n{JPN}すんでいた ポケモンの\n{JPN}カセキの いちぶ{ENG}");

static const u8 sBeadMailDesc[]       = _("{JPN}もたせた ポケモンの\n{JPN}にがおえがでる びんせん{ENG}");

static const u8 sEvolutionStoneDesc[] = _("{JPN}とくていの ポケモンを\n{JPN}しんかさせる{ENG}");

static const u8 sNectarDesc[]         = _("{JPN}はなのミツ\n{JPN}とくていの ポケモンの\n{JPN}すがたを かえる{ENG}");

static const u8 sCharizarditeDesc[]   = _("{JPN}リザードンに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}");

static const u8 sMewtwoniteDesc[]     = _("{JPN}ミュウツーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}");

static const u8 sRaichuniteDesc[]     = _("{JPN}ライチュウに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}");

static const u8 sAbsoliteDesc[]       = _("{JPN}アブソルに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}");

static const u8 sGarchompiteDesc[]    = _("{JPN}ガブリアスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}");

static const u8 sLucarioniteDesc[]    = _("{JPN}ルカリオに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}");

static const u8 sSeaIncenseDesc[]     = _("{JPN}もたせると\n{JPN}みずタイプの わざの\n{JPN}いりょくが あがる{ENG}");

static const u8 sOddIncenseDesc[]     = _("{JPN}もたせると\n{JPN}エスパータイプの わざの\n{JPN}いりょくが あがる{ENG}");

static const u8 sRockIncenseDesc[]    = _("{JPN}もたせると\n{JPN}いわタイプの わざの\n{JPN}いりょくが あがる{ENG}");

static const u8 sFullIncenseDesc[]    = _("{JPN}もたせた ポケモンは\n{JPN}いつもより こうどうが\n{JPN}おそくなる{ENG}");

static const u8 sRoseIncenseDesc[]    = _("{JPN}もたせると\n{JPN}くさタイプの わざの\n{JPN}いりょくが あがる{ENG}");

static const u8 sLuckIncenseDesc[]    = _("{JPN}もたせた ポケモンが\n{JPN}せんとうに でると\n{JPN}おかねが 2ばいもらえる{ENG}");

static const u8 sPureIncenseDesc[]    = _("{JPN}もたせると\n{JPN}やせいポケモンが\n{JPN}でて きにくくなる{ENG}");

static const u8 sKingsRockDesc[]      = _("{JPN}ポケモンに もたせると\n{JPN}ダメージを うけた\n{JPN}あいてが たまに ひるむ{ENG}");

static const u8 sFigyBerryDesc[]      = _("{JPN}もたせると たいりょくを\n{JPN}かいふく できるが\n{JPN}こんらんする ことがある{ENG}");

const u8 gQuestionMarksItemName[] = _("????????");

static const u8 sQuestionMarksDesc[]  = _("?????");

static const u8 sKeyToRoomDesc[]      = _("{JPN}すてられぶねの へやに\n{JPN}はいる ための カギ{ENG}");

static const u8 sTeraShardDesc[]      = _("{JPN}テラスタルポケモンが\n{JPN}たおれたとき くだけた\n{JPN}テラスタルジュエル{ENG}");

static const u8 sGenericMulchDesc[]   = _("{JPN}ふかふかのつちに\n{JPN}まいて つかう{ENG}");

const struct ItemInfo gItemsInfo[] =
{
    [ITEM_NONE] =
    {
        .name = gQuestionMarksItemName,
        .price = 0,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_UNCATEGORIZED,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

// Poké Balls

    [ITEM_STRANGE_BALL] =
    {
        .name = ITEM_NAME("{JPN}ストレンジボール{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}じかんと くうかんを\n{JPN}こえて やってきた\n{JPN}かわった ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_STRANGE,
        .iconPic = gItemIcon_StrangeBall,
        .iconPalette = gItemIconPalette_StrangeBall,
    },

    [ITEM_POKE_BALL] =
    {
        .name = ITEM_NAME("{JPN}モンスターボール{ENG}"),
        .price = 200,
        .description = COMPOUND_STRING(
            "{JPN}やせい ポケモンを\n{JPN}つかまえるための どうぐ{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_POKE,
        .iconPic = gItemIcon_PokeBall,
        .iconPalette = gItemIconPalette_PokeBall,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = ITEM_NAME("{JPN}スーパーボール{ENG}"),
        .price = 600,
        .description = COMPOUND_STRING(
            "{JPN}モンスターボール より\n{JPN}つかまえ やすくなった\n{JPN}こうせいのうの ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_GREAT,
        .iconPic = gItemIcon_GreatBall,
        .iconPalette = gItemIconPalette_GreatBall,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = ITEM_NAME("{JPN}ハイパーボール{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 800 : 1200,
        .description = COMPOUND_STRING(
            "{JPN}スーパーボール より\n{JPN}つかまえ やすくなった\n{JPN}とても すごい ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_ULTRA,
        .iconPic = gItemIcon_UltraBall,
        .iconPalette = gItemIconPalette_UltraBall,
    },

    [ITEM_MASTER_BALL] =
    {
        .name = ITEM_NAME("{JPN}マスターボール{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンを かならず\n{JPN}つかまえることが できる\n{JPN}さいこうの ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MASTER,
        .iconPic = gItemIcon_MasterBall,
        .iconPalette = gItemIconPalette_MasterBall,
    },

    // ===== Wishes of Tomorrow: Ability Machines =====
    [ITEM_AM_INTIMIDATE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・いかく{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}とうじょうじにあいてのこう\nげきをさげる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_INTIMIDATE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_NormalTMHM,
    },

    [ITEM_AM_GUTS] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・こんじょう{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}じょうたいいじょうになると\nこうげきがあがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_GUTS,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_NormalTMHM,
    },

    [ITEM_AM_TECHNICIAN] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・テクニシャン{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}いりょく60いかのわざがつ\nよくなる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_TECHNICIAN,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_NormalTMHM,
    },

    [ITEM_AM_MOXIE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・じしんかじょう{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}あいてをたおすとこうげきが\nあがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_MOXIE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_NormalTMHM,
    },

    [ITEM_AM_ADAPTABILITY] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・てきおうりょく{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}じぶんとおなじタイプのわざ\nがさらにあがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_ADAPTABILITY,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_SHEER_FORCE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・ちからずく{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}ついかこうかのあるわざのい\nりょくがあがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_SHEER_FORCE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_TOUGH_CLAWS] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・かたいツメ{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}せっしょくするわざのいりょ\nくがあがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_TOUGH_CLAWS,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_IRON_FIST] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・てつのこぶし{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}パンチのわざのいりょくがあ\nがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_IRON_FIST,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_TINTED_LENS] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・いろめがね{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}こうかがいまひとつのわざの\nいりょくが2ばい。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_TINTED_LENS,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_SKILL_LINK] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・スキルリンク{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}れんぞくわざがかならずさい\nだいかいすうあたる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_SKILL_LINK,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_THICK_FAT] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・あついしぼう{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}ほのおとこおりのわざのダメ\nージがはんぶん。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_THICK_FAT,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_STURDY] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・がんじょう{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}HPまんたんならいちげきで\nはたおされない。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_STURDY,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_LEVITATE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・ふゆう{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}じめんタイプのわざをうけな\nくなる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_LEVITATE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_WaterTMHM,
    },

    [ITEM_AM_UNAWARE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・てんねん{ENG}"),
        .price = 12000,
        .description = COMPOUND_STRING(
            "{JPN}あいてののうりょくへんかを\nむしする。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_UNAWARE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_PsychicTMHM,
    },

    [ITEM_AM_SERENE_GRACE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・てんのめぐみ{ENG}"),
        .price = 12000,
        .description = COMPOUND_STRING(
            "{JPN}わざのついかこうかがでるか\nくりつが2ばい。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_SERENE_GRACE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_PsychicTMHM,
    },

    [ITEM_AM_PRANKSTER] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・いたずらごころ{ENG}"),
        .price = 12000,
        .description = COMPOUND_STRING(
            "{JPN}へんかわざをさきにだせる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_PRANKSTER,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_PsychicTMHM,
    },

    [ITEM_AM_POISON_HEAL] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・ポイズンヒール{ENG}"),
        .price = 12000,
        .description = COMPOUND_STRING(
            "{JPN}どくのダメージのかわりにH\nPがかいふくする。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_POISON_HEAL,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_PsychicTMHM,
    },

    [ITEM_AM_MULTISCALE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・マルチスケイル{ENG}"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "{JPN}HPまんたんならうけるダメ\nージがはんぶん。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_MULTISCALE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_DragonTMHM,
    },

    [ITEM_AM_MAGIC_GUARD] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・マジックガード{ENG}"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "{JPN}ちょくせつのこうげきいがい\nでダメージをうけない。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_MAGIC_GUARD,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_DragonTMHM,
    },

    [ITEM_AM_REGENERATOR] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・さいせいりょく{ENG}"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "{JPN}ひっこむとHPがすこしかい\nふくする。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_REGENERATOR,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_DragonTMHM,
    },

    [ITEM_AM_SPEED_BOOST] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・かそく{ENG}"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "{JPN}まいターンすばやさがあがる\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_SPEED_BOOST,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_DragonTMHM,
    },

    [ITEM_AM_MAGIC_BOUNCE] =
    {
        .name = ITEM_NAME("{JPN}とくせいマシン・マジックミラー{ENG}"),
        .price = 20000,
        .description = COMPOUND_STRING(
            "{JPN}へんかわざをつかったあいて\nにはねかえす。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityMachine,
        .secondaryId = ABILITY_MAGIC_BOUNCE,
        .iconPic = gItemIcon_TM,
        .iconPalette = gItemIconPalette_DragonTMHM,
    },

    // ===== Wishes of Tomorrow: the Paws =====
    [ITEM_MANKEYS_PAW] =
    {
        .name = ITEM_NAME("{JPN}マンキーのて{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}ねがいでのうりょく1つが1\nだんかいあがりのろいでべつ\nの1つが1だんかいさがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Paw,
        .secondaryId = 1,
        .iconPic = gItemIcon_QuickClaw,
        .iconPalette = gItemIconPalette_QuickClaw,
    },

    [ITEM_PRIMEAPES_PAW] =
    {
        .name = ITEM_NAME("{JPN}オコリザルのて{ENG}"),
        .price = 4000,
        .description = COMPOUND_STRING(
            "{JPN}ねがいでのうりょく1つが2\nだんかいあがりのろいでべつ\nの1つが2だんかいさがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Paw,
        .secondaryId = 2,
        .iconPic = gItemIcon_QuickClaw,
        .iconPalette = gItemIconPalette_QuickClaw,
    },

    [ITEM_ANNIHILAPES_PAW] =
    {
        .name = ITEM_NAME("{JPN}コノヨザルのて{ENG}"),
        .price = 6000,
        .description = COMPOUND_STRING(
            "{JPN}ねがいでのうりょく1つが3\nだんかいあがりのろいでべつ\nの1つが3だんかいさがる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Paw,
        .secondaryId = 3,
        .iconPic = gItemIcon_QuickClaw,
        .iconPalette = gItemIconPalette_QuickClaw,
    },

    [ITEM_SNAG_BALL] =
    {
        .name = ITEM_NAME("{JPN}スナッチボール{ENG}"),
        .price = 800,
        .description = COMPOUND_STRING(
            "{JPN}ダークポケモンのはどうにあ\nわせたボール。ダークにはつ\nかまえるちからが4ばい。{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SNAG,
        .iconPic = gItemIcon_SnagBall,
        .iconPalette = gItemIconPalette_SnagBall,
    },


    [ITEM_PREMIER_BALL] =
    {
        .name = ITEM_NAME("{JPN}プレミアボール{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "{JPN}なにかの きねんに\n{JPN}つくられた めずらしい\n{JPN}モンスターボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PREMIER,
        .iconPic = gItemIcon_PremierBall,
        .iconPalette = gItemIconPalette_PremierBall,
    },

    [ITEM_HEAL_BALL] =
    {
        .name = ITEM_NAME("{JPN}ヒールボール{ENG}"),
        .price = 300,
        .description = COMPOUND_STRING(
            "{JPN}つかまえた ポケモンの\n{JPN}HPを かいふくする\n{JPN}やさしい ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAL,
        .iconPic = gItemIcon_HealBall,
        .iconPalette = gItemIconPalette_HealBall,
    },

    [ITEM_NET_BALL] =
    {
        .name = ITEM_NAME("{JPN}ネットボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}みずと むしタイプの\n{JPN}ポケモンが つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NET,
        .iconPic = gItemIcon_NetBall,
        .iconPalette = gItemIconPalette_NetBall,
    },

    [ITEM_NEST_BALL] =
    {
        .name = ITEM_NAME("{JPN}ネストボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}つかまえる ポケモンが\n{JPN}よわいほど つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NEST,
        .iconPic = gItemIcon_NestBall,
        .iconPalette = gItemIconPalette_NestBall,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = ITEM_NAME("{JPN}ダイブボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}かいていに いる\n{JPN}ポケモンが つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DIVE,
        .iconPic = gItemIcon_DiveBall,
        .iconPalette = gItemIconPalette_DiveBall,
    },

    [ITEM_DUSK_BALL] =
    {
        .name = ITEM_NAME("{JPN}ダークボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}くらい ところで\n{JPN}ポケモンが つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DUSK,
        .iconPic = gItemIcon_DuskBall,
        .iconPalette = gItemIconPalette_DuskBall,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = ITEM_NAME("{JPN}タイマーボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}ターンすうが かかれば\n{JPN}かかるほど つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_TIMER,
        .iconPic = gItemIcon_TimerBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_QUICK_BALL] =
    {
        .name = ITEM_NAME("{JPN}クイックボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}せんとうが はじまって\n{JPN}すぐ つかうと つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_QUICK,
        .iconPic = gItemIcon_QuickBall,
        .iconPalette = gItemIconPalette_QuickBall,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = ITEM_NAME("{JPN}リピートボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}つかまえた ことが ある\n{JPN}ポケモンが つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_REPEAT,
        .iconPic = gItemIcon_RepeatBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = ITEM_NAME("{JPN}ゴージャスボール{ENG}"),
        .price = (I_PRICE >= GEN_8) ? 3000 : 1000,
        .description = COMPOUND_STRING(
            "{JPN}つかまえた ポケモンが\n{JPN}なつき やすくなる\n{JPN}いごこちの いい ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LUXURY,
        .iconPic = gItemIcon_LuxuryBall,
        .iconPalette = gItemIconPalette_LuxuryBall,
    },

    [ITEM_LEVEL_BALL] =
    {
        .name = ITEM_NAME("{JPN}レベルボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンの レベルが\n{JPN}ひくいほど つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LEVEL,
        .iconPic = gItemIcon_LevelBall,
        .iconPalette = gItemIconPalette_LevelBall,
    },

    [ITEM_LURE_BALL] =
    {
        .name = ITEM_NAME("{JPN}ルアーボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}つりざおで つりあげた\n{JPN}ポケモンを つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LURE,
        .iconPic = gItemIcon_LureBall,
        .iconPalette = gItemIconPalette_LureBall,
    },

    [ITEM_MOON_BALL] =
    {
        .name = ITEM_NAME("{JPN}ムーンボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}つきのいしで しんかする\n{JPN}ポケモンが つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MOON,
        .iconPic = gItemIcon_MoonBall,
        .iconPalette = gItemIconPalette_MoonBall,
    },

    [ITEM_FRIEND_BALL] =
    {
        .name = ITEM_NAME("{JPN}フレンドボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}つかまえた ポケモンが\n{JPN}すぐに なついて\n{JPN}くれる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FRIEND,
        .iconPic = gItemIcon_FriendBall,
        .iconPalette = gItemIconPalette_FriendBall,
    },

    [ITEM_LOVE_BALL] =
    {
        .name = ITEM_NAME("{JPN}ラブラブボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}せいべつが ちがう\n{JPN}ポケモンを つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LOVE,
        .iconPic = gItemIcon_LoveBall,
        .iconPalette = gItemIconPalette_LoveBall,
    },

    [ITEM_FAST_BALL] =
    {
        .name = ITEM_NAME("{JPN}スピードボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}すばやさの たかい\n{JPN}ポケモンが つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FAST,
        .iconPic = gItemIcon_FastBall,
        .iconPalette = gItemIconPalette_FastBall,
    },

    [ITEM_HEAVY_BALL] =
    {
        .name = ITEM_NAME("{JPN}ヘビーボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}たいじゅうの おもい\n{JPN}ポケモンを つかまえ\n{JPN}やすくなる ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAVY,
        .iconPic = gItemIcon_HeavyBall,
        .iconPalette = gItemIconPalette_HeavyBall,
    },

    [ITEM_DREAM_BALL] =
    {
        .name = ITEM_NAME("{JPN}ドリームボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
        #if B_DREAM_BALL_MODIFIER >= GEN_8
            "A Ball that works\n"
            "well on sleeping\n"
            "Pokémon."),
        #else
            "A Poké Ball used in\n"
            "the Entree Forest."),
        #endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DREAM,
        .iconPic = gItemIcon_DreamBall,
        .iconPalette = gItemIconPalette_DreamBall,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = ITEM_NAME("{JPN}サファリボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}サファリゾーンで のみ\n{JPN}つかうことが できる\n{JPN}とくしゅな ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SAFARI,
        .iconPic = gItemIcon_SafariBall,
        .iconPalette = gItemIconPalette_SafariBall,
    },

    [ITEM_SPORT_BALL] =
    {
        .name = ITEM_NAME("{JPN}コンペボール{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}むしとりたいかいの\n{JPN}なかで つかう\n{JPN}とくべつな ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SPORT,
        .iconPic = gItemIcon_SportBall,
        .iconPalette = gItemIconPalette_SportBall,
    },

    [ITEM_PARK_BALL] =
    {
        .name = ITEM_NAME("{JPN}パークボール{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}パルパークの\n{JPN}なかで つかう\n{JPN}とくべつな ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PARK,
        .iconPic = gItemIcon_ParkBall,
        .iconPalette = gItemIconPalette_ParkBall,
    },

    [ITEM_BEAST_BALL] =
    {
        .name = ITEM_NAME("{JPN}ウルトラボール{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}ウルトラビーストを\n{JPN}つかまえる ために\n{JPN}つくられた ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_BEAST,
        .iconPic = gItemIcon_BeastBall,
        .iconPalette = gItemIconPalette_BeastBall,
    },

    [ITEM_CHERISH_BALL] =
    {
        .name = ITEM_NAME("{JPN}プレシャスボール{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}なにかの きねんの\n{JPN}しなとして つくられた\n{JPN}かなり めずらしい ボール{ENG}"),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_CHERISH,
        .iconPic = gItemIcon_CherishBall,
        .iconPalette = gItemIconPalette_CherishBall,
    },

// Medicine

    [ITEM_POTION] =
    {
        .name = ITEM_NAME("{JPN}キズぐすり{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 200 : 300,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンの たいりょくを\n{JPN}20 かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_Potion,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = ITEM_NAME("{JPN}いいキズぐすり{ENG}"),
        .price = 700,
        .holdEffectParam = 60,
        .description = COMPOUND_STRING(
            "Restores the HP of\n"
            "a Pokémon by\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "60 points."),
        #else
            "50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_SuperPotion,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = ITEM_NAME("{JPN}すごいキズぐすり{ENG}"),
        .price = (I_PRICE >= GEN_2 && I_PRICE <= GEN_6) ? 1200 : 1500,
        .holdEffectParam = 120,
        .description = COMPOUND_STRING(
            "Restores the HP of\n"
            "a Pokémon by\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "120 points."),
        #else
            "200 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_HyperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_HyperPotion,
    },

    [ITEM_MAX_POTION] =
    {
        .name = ITEM_NAME("{JPN}まんたんのくすり{ENG}"),
        .price = 2500,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンの たいりょくを\n{JPN}ぜんかいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MaxPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_MaxPotion,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = ITEM_NAME("{JPN}かいふくのくすり{ENG}"),
        .price = 3000,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンの たいりょくと\n{JPN}じょうたい いじょうを\n{JPN}ぜんかいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_HEAL_AND_CURE_STATUS,
        .effect = gItemEffect_FullRestore,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_FullRestore,
    },

    [ITEM_REVIVE] =
    {
        .name = ITEM_NAME("{JPN}げんきのかけら{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 1500,
        .description = COMPOUND_STRING(
            "{JPN}ひんし じょうたいから\n{JPN}たいりょく はんぶんまで\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_Revive,
        .flingPower = 30,
        .iconPic = gItemIcon_Revive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = ITEM_NAME("{JPN}げんきのかたまり{ENG}"),
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxRevive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = ITEM_NAME("{JPN}おいしいみず{ENG}"),
        .price = 200,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "A mineral water\n"
            "that restores HP\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 30 points."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FreshWater,
        .flingPower = 30,
        .iconPic = gItemIcon_FreshWater,
        .iconPalette = gItemIconPalette_FreshWater,
    },

    [ITEM_SODA_POP] =
    {
        .name = ITEM_NAME("{JPN}サイコソーダ{ENG}"),
        .price = 300,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "A fizzy soda drink\n"
            "that restores HP\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 50 points."),
        #else
            "by 60 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SodaPop,
        .flingPower = 30,
        .iconPic = gItemIcon_SodaPop,
        .iconPalette = gItemIconPalette_SodaPop,
    },

    [ITEM_LEMONADE] =
    {
        .name = ITEM_NAME("{JPN}ミックスオレ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 70,
        .description = COMPOUND_STRING(
            "A very sweet drink\n"
            "that restores HP\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 70 points."),
        #else
            "by 80 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Lemonade,
        .flingPower = 30,
        .iconPic = gItemIcon_Lemonade,
        .iconPalette = gItemIconPalette_Lemonade,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = ITEM_NAME("{JPN}モーモーミルク{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 600 : 500,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "{JPN}えいよう まんてん\n{JPN}ポケモンの たいりょくを\n{JPN}100 かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MoomooMilk,
        .flingPower = 30,
        .iconPic = gItemIcon_MoomooMilk,
        .iconPalette = gItemIconPalette_MoomooMilk,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = ITEM_NAME("{JPN}ちからのこな{ENG}"),
        .price = 500,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that restores HP\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 60 points."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_EnergyPowder,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = ITEM_NAME("{JPN}ちからのねっこ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1200 : 800,
        .description = COMPOUND_STRING(
            "A bitter root\n"
            "that restores HP\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 120 points."),
        #else
            "by 200 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyRoot,
        .flingPower = 30,
        .iconPic = gItemIcon_EnergyRoot,
        .iconPalette = gItemIconPalette_EnergyRoot,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = ITEM_NAME("{JPN}ばんのうごな{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 300 : 450,
        .description = COMPOUND_STRING(
            "{JPN}すごく にがい こな\n{JPN}じょうたい いじょうを\n{JPN}すべて かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_HealPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_HealPowder,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = ITEM_NAME("{JPN}ふっかつそう{ENG}"),
        .price = 2800,
        .description = COMPOUND_STRING(
            "{JPN}とても にがい くさ\n{JPN}ひんし じょうたいから\n{JPN}ふっかつする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_RevivalHerb,
        .flingPower = 30,
        .iconPic = gItemIcon_RevivalHerb,
        .iconPalette = gItemIconPalette_RevivalHerb,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = ITEM_NAME("{JPN}どくけし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 200 : 100,
        .description = COMPOUND_STRING(
            "{JPN}どく じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Antidote,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = ITEM_NAME("{JPN}まひなおし{ENG}"),
        .price = (I_PRICE == GEN_7) ? 300 : 200,
        .description = COMPOUND_STRING(
            "{JPN}まひ じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_ParalyzeHeal,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = ITEM_NAME("{JPN}やけどなおし{ENG}"),
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}やけど じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_BurnHeal,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = ITEM_NAME("{JPN}こおりなおし{ENG}"),
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}こおり じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_IceHeal,
    },

    [ITEM_AWAKENING] =
    {
        .name = ITEM_NAME("{JPN}ねむけざまし{ENG}"),
    #if (I_PRICE >= GEN_8 || I_PRICE == GEN_1)
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}ねむり じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Awakening,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = ITEM_NAME("{JPN}なんでもなおし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 400 : 600,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_FullHeal,
        .iconPalette = gItemIconPalette_FullHeal,
    },

    [ITEM_ETHER] =
    {
        .name = ITEM_NAME("{JPN}ピーピーエイド{ENG}"),
        .price = (I_PRICE >= GEN_2) ? 1200 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}1つの わざの\n{JPN}わざポイントを\n{JPN}10 かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Ether,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Ether,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = ITEM_NAME("{JPN}ピーピーリカバー{ENG}"),
        .price = (I_PRICE >= GEN_2) ? 2000 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "{JPN}1つの わざの\n{JPN}わざポイントを\n{JPN}ぜんかいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxEther,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxEther,
    },

    [ITEM_ELIXIR] =
    {
        .name = ITEM_NAME("{JPN}ピーピーエイダー{ENG}"),
        .price = (I_PRICE >= GEN_2) ? 3000 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}すべての わざの\n{JPN}わざポイントを\n{JPN}10 かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Elixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Elixir,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = ITEM_NAME("{JPN}ピーピーマックス{ENG}"),
        .price = (I_PRICE >= GEN_2) ? 4500 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
            "{JPN}ポケモン 1ぴきの\n{JPN}すべての わざポイントを\n{JPN}ぜんかいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxElixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxElixir,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = ITEM_NAME("{JPN}きのみジュース{ENG}"),
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}きのみ 100パーセント\n{JPN}ポケモンの たいりょくを\n{JPN}20 かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_BerryJuice,
        .iconPalette = gItemIconPalette_BerryJuice,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = ITEM_NAME("{JPN}せいなるはい{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}せいなるはい{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 50000 : 200,
        .description = COMPOUND_STRING(
            "{JPN}ひんししている ポケモン\n{JPN}すべてを せいじょうな\n{JPN}じょうたいに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
        .effect = gItemEffect_SacredAsh,
        .flingPower = 30,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_SacredAsh,
    },

    [ITEM_SWEET_HEART] =
    {
        .name = ITEM_NAME("{JPN}ハートスイーツ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 100,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}あまい チョコレート\n{JPN}ポケモンの たいりょくを\n{JPN}20 かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetHeart,
        .iconPalette = gItemIconPalette_SweetHeart,
    },

    [ITEM_MAX_HONEY] =
    {
        .name = ITEM_NAME("{JPN}ダイミツ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ダイミツ{ENG}"),
        .price = 8000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxHoney,
        .iconPalette = gItemIconPalette_MaxHoney,
    },

// Regional Specialties

    [ITEM_PEWTER_CRUNCHIES] =
    {
        .name = ITEM_NAME("{JPN}ニビあられ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ニビあられ{ENG}"),
        .price = 250,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_PewterCrunchies,
        .iconPalette = gItemIconPalette_PewterCrunchies,
    },

    [ITEM_RAGE_CANDY_BAR] =
    {
        .name = ITEM_NAME("{JPN}いかりまんじゅう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 350 : 300,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_RageCandyBar,
        .iconPalette = gItemIconPalette_RageCandyBar,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = ITEM_NAME("{JPN}フエンせんべい{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
            "{JPN}フエンの めいぶつ\n{JPN}じょうたい いじょうを\n{JPN}すべて かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LavaCookie,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_OLD_GATEAU] =
    {
        .name = ITEM_NAME("{JPN}もりのヨウカン{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}もりのヨウカン{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_OldGateau,
        .iconPalette = gItemIconPalette_OldGateau,
    },

    [ITEM_CASTELIACONE] =
    {
        .name = ITEM_NAME("{JPN}ヒウンアイス{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 350 : 100,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_Casteliacone,
        .iconPalette = gItemIconPalette_Casteliacone,
    },

    [ITEM_LUMIOSE_GALETTE] =
    {
        .name = ITEM_NAME("{JPN}ミアレガレット{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LumioseGalette,
        .iconPalette = gItemIconPalette_LumioseGalette,
    },

    [ITEM_SHALOUR_SABLE] =
    {
        .name = ITEM_NAME("{JPN}シャラサブレ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_ShalourSable,
        .iconPalette = gItemIconPalette_ShalourSable,
    },

    [ITEM_BIG_MALASADA] =
    {
        .name = ITEM_NAME("{JPN}おおきいマラサダ{ENG}"),
        .price = 350,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMalasada,
        .iconPalette = gItemIconPalette_BigMalasada,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = ITEM_NAME("{JPN}マックスアップ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "{JPN}たいりょくの\n{JPN}きそポイントを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_HPUp,
        .iconPalette = gItemIconPalette_HPUp,
    },

    [ITEM_PROTEIN] =
    {
        .name = ITEM_NAME("{JPN}タウリン{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "{JPN}こうげきの\n{JPN}きそポイントを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Protein,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Protein,
    },

    [ITEM_IRON] =
    {
        .name = ITEM_NAME("{JPN}ブロムヘキシン{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "{JPN}ぼうぎょの\n{JPN}きそポイントを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Iron,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Iron,
    },

    [ITEM_CALCIUM] =
    {
        .name = ITEM_NAME("{JPN}リゾチウム{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "{JPN}とくこうの\n{JPN}きそポイントを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Calcium,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Calcium,
    },

    [ITEM_ZINC] =
    {
        .name = ITEM_NAME("{JPN}キトサン{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "{JPN}とくぼうの\n{JPN}きそポイントを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Zinc,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Zinc,
    },

    [ITEM_CARBOS] =
    {
        .name = ITEM_NAME("{JPN}インドメタシン{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}インドメタシン{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "{JPN}すばやさの\n{JPN}きそポイントを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Carbos,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Carbos,
    },

    [ITEM_PP_UP] =
    {
        .name = ITEM_NAME("{JPN}ポイントアップ{ENG}"),
    #if I_PRICE >= GEN_7
        .price = 10000,
    #elif I_PRICE >= GEN_2
        .price = 9800,
    #else
        .price = 1,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}わざポイントの\n{JPN}さいだいちが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_PPUp,
        .iconPalette = gItemIconPalette_PPUp,
    },

    [ITEM_PP_MAX] =
    {
        .name = ITEM_NAME("{JPN}ポイントマックス{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ポイントマックス{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
            "{JPN}わざポイントを\n{JPN}さいだいちまで あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPMax,
        .flingPower = 30,
        .iconPic = gItemIcon_PPMax,
        .iconPalette = gItemIconPalette_PPMax,
    },

// EV Feathers

    [ITEM_HEALTH_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}たいりょくのハネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_HealthFeather,
    },

    [ITEM_MUSCLE_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}きんりょくのハネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_MuscleFeather,
    },

    [ITEM_RESIST_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}ていこうのハネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_ResistFeather,
    },

    [ITEM_GENIUS_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}ちりょくのハネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_GeniusFeather,
    },

    [ITEM_CLEVER_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}せいしんのハネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_CleverFeather,
    },

    [ITEM_SWIFT_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}しゅんぱつのハネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_SwiftFeather,
    },

// Ability Modifiers

    [ITEM_ABILITY_CAPSULE] =
    {
        .name = ITEM_NAME("{JPN}とくせいカプセル{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 1000,
    #endif
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに つかうと\n{JPN}ちがう とくせいに\n{JPN}かえられる カプセル{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,
        .iconPic = gItemIcon_AbilityCapsule,
        .iconPalette = gItemIconPalette_AbilityCapsule,
    },

    [ITEM_ABILITY_PATCH] =
    {
        .name = ITEM_NAME("{JPN}とくせいパッチ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}とくせいパッチ{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 250000 : 20,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに つかうと\n{JPN}めずらしい とくせいに\n{JPN}かえられる パッチ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityPatch,
        .iconPic = gItemIcon_AbilityPatch,
        .iconPalette = gItemIconPalette_AbilityPatch,
    },

// Mints

    [ITEM_LONELY_MINT] =
    {
        .name = ITEM_NAME("{JPN}さみしがりミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}こうげきが あがって\n{JPN}ぼうぎょが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LONELY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_ADAMANT_MINT] =
    {
        .name = ITEM_NAME("{JPN}いじっぱりミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}こうげきが あがって\n{JPN}とくこうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_ADAMANT,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_NAUGHTY_MINT] =
    {
        .name = ITEM_NAME("{JPN}やんちゃミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}こうげきが あがって\n{JPN}とくぼうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAUGHTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BRAVE_MINT] =
    {
        .name = ITEM_NAME("{JPN}ゆうかんミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}こうげきが あがって\n{JPN}すばやさが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BRAVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BOLD_MINT] =
    {
        .name = ITEM_NAME("{JPN}ずぶといミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}ぼうぎょが あがって\n{JPN}こうげきが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BOLD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_IMPISH_MINT] =
    {
        .name = ITEM_NAME("{JPN}わんぱくミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}ぼうぎょが あがって\n{JPN}とくこうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_IMPISH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_LAX_MINT] =
    {
        .name = ITEM_NAME("{JPN}のうてんきミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}ぼうぎょが あがって\n{JPN}とくぼうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LAX,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_RELAXED_MINT] =
    {
        .name = ITEM_NAME("{JPN}のんきミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}ぼうぎょが あがって\n{JPN}すばやさが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RELAXED,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_MODEST_MINT] =
    {
        .name = ITEM_NAME("{JPN}ひかえめミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくこうが あがって\n{JPN}こうげきが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MODEST,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_MILD_MINT] =
    {
        .name = ITEM_NAME("{JPN}おっとりミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくこうが あがって\n{JPN}ぼうぎょが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MILD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_RASH_MINT] =
    {
        .name = ITEM_NAME("{JPN}うっかりやミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくこうが あがって\n{JPN}とくぼうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RASH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_QUIET_MINT] =
    {
        .name = ITEM_NAME("{JPN}れいせいミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくこうが あがって\n{JPN}すばやさが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_QUIET,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_CALM_MINT] =
    {
        .name = ITEM_NAME("{JPN}おだやかミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくぼうが あがって\n{JPN}こうげきが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CALM,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_GENTLE_MINT] =
    {
        .name = ITEM_NAME("{JPN}おとなしいミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくぼうが あがって\n{JPN}ぼうぎょが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_GENTLE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_CAREFUL_MINT] =
    {
        .name = ITEM_NAME("{JPN}しんちょうミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくぼうが あがって\n{JPN}とくこうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CAREFUL,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_SASSY_MINT] =
    {
        .name = ITEM_NAME("{JPN}なまいきミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}とくぼうが あがって\n{JPN}すばやさが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SASSY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_TIMID_MINT] =
    {
        .name = ITEM_NAME("{JPN}おくびょうミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}すばやさが あがって\n{JPN}こうげきが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_TIMID,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_HASTY_MINT] =
    {
        .name = ITEM_NAME("{JPN}せっかちミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}すばやさが あがって\n{JPN}ぼうぎょが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_HASTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_JOLLY_MINT] =
    {
        .name = ITEM_NAME("{JPN}ようきミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}すばやさが あがって\n{JPN}とくこうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_JOLLY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_NAIVE_MINT] =
    {
        .name = ITEM_NAME("{JPN}むじゃきミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}すばやさが あがって\n{JPN}とくぼうが さがるミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAIVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_SERIOUS_MINT] =
    {
        .name = ITEM_NAME("{JPN}まじめミント{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに かがせると\n{JPN}まんべなく そだつ\n{JPN}ミント{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SERIOUS,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_YellowMint,
    },

// Candy

    [ITEM_RARE_CANDY] =
    {
        .name = ITEM_NAME("{JPN}ふしぎなアメ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ふしぎなアメ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 4800,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンの レベルを\n{JPN}1 あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_RareCandy,
        .iconPalette = gItemIconPalette_RareCandy,
    },

    [ITEM_EXP_CANDY_XS] =
    {
        .name = ITEM_NAME("{JPN}けいけんアメXS{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}けいけんアメXS{ENG}"),
        .price = 20,
        .holdEffectParam = EXP_100,
        .description = COMPOUND_STRING(
            "{JPN}あたえると ポケモン\n{JPN}1ひきの けいけんちが\n{JPN}ほんのすこし ふえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_S] =
    {
        .name = ITEM_NAME("{JPN}けいけんアメS{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}けいけんアメS{ENG}"),
        .price = 240,
        .holdEffectParam = EXP_800,
        .description = COMPOUND_STRING(
            "{JPN}あたえると ポケモン\n{JPN}1ひきの けいけんちが\n{JPN}すこし ふえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_M] =
    {
        .name = ITEM_NAME("{JPN}けいけんアメM{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}けいけんアメM{ENG}"),
        .price = 1000,
        .holdEffectParam = EXP_3000,
        .description = COMPOUND_STRING(
            "{JPN}あたえると ポケモン\n{JPN}1ひきの けいけんちが\n{JPN}ふえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyM,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_L] =
    {
        .name = ITEM_NAME("{JPN}けいけんアメL{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}けいけんアメL{ENG}"),
        .price = 3000,
        .holdEffectParam = EXP_10000,
        .description = COMPOUND_STRING(
            "{JPN}あたえると ポケモン\n{JPN}1ひきの けいけんちが\n{JPN}かなり ふえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_XL] =
    {
        .name = ITEM_NAME("{JPN}けいけんアメXL{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}けいけんアメXL{ENG}"),
        .price = 10000,
        .holdEffectParam = EXP_30000,
        .description = COMPOUND_STRING(
            "{JPN}あたえると ポケモン\n{JPN}1ひきの けいけんちが\n{JPN}とても ふえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_DYNAMAX_CANDY] =
    {
        .name = ITEM_NAME("{JPN}ダイマックスアメ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ダイマックスアメ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}あたえると ダイマックス\n{JPN}レベルが 1あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_DynamaxCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_DynamaxCandy,
        .iconPalette = gItemIconPalette_DynamaxCandy,
    },

// Medicinal Flutes

    [ITEM_BLUE_FLUTE] =
    {
        .name = ITEM_NAME("{JPN}あおいビードロ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 20 : 100,
        .description = COMPOUND_STRING(
            "{JPN}ガラスで できた ふえ\n{JPN}ねむり じょうたいを\n{JPN}かいふくする{ENG}"),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlueFlute,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = ITEM_NAME("{JPN}きいろビードロ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 20 : 300,
        .description = COMPOUND_STRING(
            "{JPN}ガラスで できた ふえ\n{JPN}こんらん じょうたいを\n{JPN}かいふくする{ENG}"),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_YellowFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_YellowFlute,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = ITEM_NAME("{JPN}あかいビードロ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
            "{JPN}ガラスで できた ふえ\n{JPN}メロメロ じょうたいを\n{JPN}かいふくする{ENG}"),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_RedFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_RedFlute,
    },

// Encounter-modifying Flutes

    [ITEM_BLACK_FLUTE] =
    {
        .name = ITEM_NAME("{JPN}くろいビードロ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 20 : 400,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "{JPN}ガラスで できた ふえ\n{JPN}やせい ポケモンと\n{JPN}そうぐう しにくくなる{ENG}"),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlackFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = ITEM_NAME("{JPN}しろいビードロ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 20 : 500,
        .holdEffectParam = 150,
        .description = COMPOUND_STRING(
            "{JPN}ガラスで できた ふえ\n{JPN}やせい ポケモンと\n{JPN}そうぐう しやすくなる{ENG}"),
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_WhiteFlute,
    },

// Encounter Modifiers

    [ITEM_REPEL] =
    {
        .name = ITEM_NAME("{JPN}むしよけスプレー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "{JPN}100ぽ すすむ あいだ\n{JPN}よわい ポケモンと\n{JPN}そうぐう しなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_Repel,
    },

    [ITEM_SUPER_REPEL] =
    {
        .name = ITEM_NAME("{JPN}シルバースプレー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 700 : 500,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "{JPN}200ぽ すすむ あいだ\n{JPN}よわい ポケモンと\n{JPN}そうぐう しなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_SuperRepel,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = ITEM_NAME("{JPN}ゴールドスプレー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 900 : 700,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "{JPN}250ぽ すすむ あいだ\n{JPN}よわい ポケモンと\n{JPN}そうぐう しなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_MaxRepel,
    },

    [ITEM_LURE] =
    {
        .name = ITEM_NAME("{JPN}むしよせコロン{ENG}"),
        .price = 400,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
            "{JPN}100ぽ すすむ あいだ\n{JPN}めずらしい ポケモンが\n{JPN}でて きやすく なる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_Lure,
    },

    [ITEM_SUPER_LURE] =
    {
        .name = ITEM_NAME("{JPN}シルバーコロン{ENG}"),
        .price = 700,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
            "{JPN}200ぽ すすむ あいだ\n{JPN}めずらしい ポケモンが\n{JPN}でて きやすく なる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_SuperLure,
    },

    [ITEM_MAX_LURE] =
    {
        .name = ITEM_NAME("{JPN}ゴールドコロン{ENG}"),
        .price = 900,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
            "{JPN}250ぽ すすむ あいだ\n{JPN}めずらしい ポケモンが\n{JPN}でて きやすく なる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_MaxLure,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = ITEM_NAME("{JPN}あなぬけのヒモ{ENG}"),
        .description = COMPOUND_STRING(
            "{JPN}どうくつや ダンジョンを\n{JPN}ぬけだせる{ENG}"),
    #if I_KEY_ESCAPE_ROPE >= GEN_8
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #else
        .price = (I_PRICE >= GEN_7) ? 1000 : 550,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
    #endif
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
        .flingPower = 30,
        .iconPic = gItemIcon_EscapeRope,
        .iconPalette = gItemIconPalette_EscapeRope,
    },

// X Items

    [ITEM_X_ATTACK] =
    {
        .name = ITEM_NAME("{JPN}プラスパワー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises stat\n"
            "Attack during\n"
            "one battle."),
        #else
            "Raises the stat\n"
            "Attack during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAttack,
    },

    [ITEM_X_DEFENSE] =
    {
        .name = ITEM_NAME("{JPN}ディフェンダー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 550,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises stat\n"
            "Defense during\n"
            "one battle."),
        #else
            "Raises the stat\n"
            "Defense during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XDefend,
    },

    [ITEM_X_SP_ATK] =
    {
        .name = ITEM_NAME("{JPN}スペシャルアップ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises stat\n"
            "Sp. Atk during\n"
            "one battle."),
        #else
            "Raises the stat\n"
            "Sp. Atk during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecial,
    },

    [ITEM_X_SP_DEF] =
    {
        .name = ITEM_NAME("{JPN}スペシャルガード{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises stat\n"
            "Sp. Def during\n"
            "one battle."),
        #else
            "Raises the stat\n"
            "Sp. Def during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecialDefense,
    },

    [ITEM_X_SPEED] =
    {
        .name = ITEM_NAME("{JPN}スピーダー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises stat\n"
            "Speed during\n"
            "one battle."),
        #else
            "Raises the stat\n"
            "Speed during one\n"
            "battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpeed,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpeed,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = ITEM_NAME("{JPN}ヨクアタール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ヨクアタール{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 950,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises move\n"
            "accuracy during\n"
            "one battle."),
        #else
            "Raises accuracy\n"
            "of attack moves\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAccuracy,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAccuracy,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = ITEM_NAME("{JPN}クリティカッター{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 650,
        .description = COMPOUND_STRING(
            "{JPN}つかった せんとうちゅう\n{JPN}あいての きゅうしょに\n{JPN}あたりやすくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_FOCUS_ENERGY,
        .effect = gItemEffect_DireHit,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_DireHit,
    },

    [ITEM_GUARD_SPEC] =
    {
        .name = ITEM_NAME("{JPN}エフェクトガード{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}エフェクトガード{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1500 : 700,
        .description = COMPOUND_STRING(
            "{JPN}せんとうで つかうと\n{JPN}みかたの のうりょくを\n{JPN}さげられなくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_MIST,
        .effect = gItemEffect_GuardSpec,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_GuardSpec,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = ITEM_NAME("{JPN}ピッピにんぎょう{ENG}"),
    #if I_PRICE >= GEN_8
        .price = 300,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 1000,
    #endif
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeDoll,
        .iconPalette = gItemIconPalette_PokeDoll,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = ITEM_NAME("{JPN}エネコのシッポ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_FluffyTail,
        .iconPalette = gItemIconPalette_FluffyTail,
    },

    [ITEM_POKE_TOY] =
    {
        .name = ITEM_NAME("{JPN}ポケじゃらし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeToy,
        .iconPalette = gItemIconPalette_PokeToy,
    },

    [ITEM_MAX_MUSHROOMS] =
    {
        .name = ITEM_NAME("{JPN}ダイキノコ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ダイキノコ{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}せんとうちゅう\n{JPN}ポケモンの すべての\n{JPN}のうりょくを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_ALL_STATS,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxMushrooms,
        .iconPalette = gItemIconPalette_MaxMushrooms,
    },

// Treasures

    [ITEM_BOTTLE_CAP] =
    {
        .name = ITEM_NAME("{JPN}ぎんのおうかん{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 5000,
        .description = COMPOUND_STRING(
            "{JPN}ぎんいろの きれいな\n{JPN}おうかん よろこぶ\n{JPN}ひともいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_BottleCap,
    },

    [ITEM_GOLD_BOTTLE_CAP] =
    {
        .name = ITEM_NAME("{JPN}きんのおうかん{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 60000 : 10000,
        .description = COMPOUND_STRING(
            "{JPN}きんいろの きれいな\n{JPN}おうかん よろこぶ\n{JPN}ひともいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_GoldBottleCap,
    },

    [ITEM_NUGGET] =
    {
        .name = ITEM_NAME("{JPN}きんのたま{ENG}"),
        .price = 10000 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}じゅんきん せい\n{JPN}たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Nugget,
        .iconPalette = gItemIconPalette_Nugget,
    },

    [ITEM_BIG_NUGGET] =
    {
        .name = ITEM_NAME("{JPN}でかいきんのたま{ENG}"),
    #if I_PRICE >= GEN_7
        .price = 40000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 20000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}じゅんきん せいの \n{JPN}おおきな たま\n{JPN}たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = B_UPDATED_MOVE_DATA >= GEN_8 ? 130 : 80,
        .iconPic = gItemIcon_BigNugget,
        .iconPalette = gItemIconPalette_BigNugget,
    },

    [ITEM_TINY_MUSHROOM] =
    {
        .name = ITEM_NAME("{JPN}ちいさなキノコ{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}ふつうの キノコ\n{JPN}やすく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = ITEM_NAME("{JPN}おおきなキノコ{ENG}"),
        .price = 5000 * TREASURE_FACTOR,
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BALM_MUSHROOM] =
    {
        .name = ITEM_NAME("{JPN}かおるキノコ{ENG}"),
    #if I_PRICE >= GEN_7
        .price = 15000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 12500,
    #else
        .price = 0,
    #endif
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BalmMushroom,
        .iconPalette = gItemIconPalette_BalmMushroom,
    },

    [ITEM_PEARL] =
    {
        .name = ITEM_NAME("{JPN}しんじゅ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR: 1400,
        .description = COMPOUND_STRING(
            "{JPN}きれいな しんじゅ\n{JPN}やすく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Pearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = ITEM_NAME("{JPN}おおきなしんじゅ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 8000 * TREASURE_FACTOR: 7500,
        .description = COMPOUND_STRING(
            "{JPN}とても きれいな\n{JPN}おおつぶの しんじゅ\n{JPN}たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigPearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_PEARL_STRING] =
    {
        .name = ITEM_NAME("{JPN}おだんごしんじゅ{ENG}"),
    #if I_PRICE >= GEN_8
        .price = 20000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 30000,
    #elif I_PRICE == GEN_6
        .price = 15000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}ぎんいろに ひかる\n{JPN}おおつぶの しんじゅ\n{JPN}とても たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PearlString,
        .iconPalette = gItemIconPalette_PearlString,
    },

    [ITEM_STARDUST] =
    {
        .name = ITEM_NAME("{JPN}ほしのすな{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 * TREASURE_FACTOR: 2000,
        .description = COMPOUND_STRING(
            "{JPN}あかくて きれいな すな\n{JPN}たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = ITEM_NAME("{JPN}ほしのかけら{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 12000 * TREASURE_FACTOR: 9800,
        .description = COMPOUND_STRING(
            "{JPN}あかくて きれいな\n{JPN}ほうせきの かけら\n{JPN}とても たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_COMET_SHARD] =
    {
        .name = ITEM_NAME("{JPN}すいせいのかけら{ENG}"),
    #if I_PRICE >= GEN_8
        .price = 25000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 60000,
    #elif I_PRICE == GEN_6
        .price = 30000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}すいせいが ちひょうに\n{JPN}おちた かけら\n{JPN}とても たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_CometShard,
    },

    [ITEM_SHOAL_SALT] =
    {
        .name = ITEM_NAME("{JPN}あさせのしお{ENG}"),
        .price = 20,
        .description = COMPOUND_STRING(
            "{JPN}あさせのほらあなで\n{JPN}みつけた しお{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_ShoalSalt,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = ITEM_NAME("{JPN}あさせのかいがら{ENG}"),
        .price = 20,
        .description = COMPOUND_STRING(
            "{JPN}あさせのほらあなで\n{JPN}みつけた かいがら{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShoalShell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_RED_SHARD] =
    {
        .name = ITEM_NAME("{JPN}あかいかけら{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_RedShard,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = ITEM_NAME("{JPN}あおいかけら{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_BlueShard,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = ITEM_NAME("{JPN}きいろいかけら{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_YellowShard,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = ITEM_NAME("{JPN}みどりのかけら{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_GreenShard,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = ITEM_NAME("{JPN}ハートのウロコ{ENG}"),
        .price = 100,
        .description = COMPOUND_STRING(
            "{JPN}きれいな ウロコ\n{JPN}マニアの あいだで\n{JPN}にんきが たかい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_HeartScale,
        .iconPalette = gItemIconPalette_HeartScale,
    },

    [ITEM_HONEY] =
    {
        .name = ITEM_NAME("{JPN}あまいミツ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}あまいミツ{ENG}"),
    #if I_PRICE >= GEN_8
        .price = 900,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 100,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}あまい においで\n{JPN}やせい ポケモンが\n{JPN}あらわれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Honey,
        .flingPower = 30,
        .iconPic = gItemIcon_Honey,
        .iconPalette = gItemIconPalette_Honey,
    },

    [ITEM_RARE_BONE] =
    {
        .name = ITEM_NAME("{JPN}きちょうなホネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 5000 * TREASURE_FACTOR: 10000,
        .description = COMPOUND_STRING(
            "{JPN}こうこがくの うえで\n{JPN}とても きちょうな ホネ\n{JPN}たかく うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_ODD_KEYSTONE] =
    {
        .name = ITEM_NAME("{JPN}かなめいし{ENG}"),
        .price = 2100,
        .description = COMPOUND_STRING(
            "{JPN}だいじないし\n{JPN}ときどき いしから\n{JPN}こえがきこえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_OddKeystone,
        .iconPalette = gItemIconPalette_OddKeystone,
    },

    [ITEM_PRETTY_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}きれいなハネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 * TREASURE_FACTOR: 200,
        .description = COMPOUND_STRING(
            "{JPN}きれいなだけで\n{JPN}なんの こうかもない\n{JPN}ふつうの ハネ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 20,
        .iconPic = gItemIcon_PrettyFeather,
        .iconPalette = gItemIconPalette_PrettyFeather,
    },

    [ITEM_RELIC_COPPER] =
    {
        .name = ITEM_NAME("{JPN}こだいのどうか{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしにつかわれたどう\nか。たかいねだんでうれる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicCopper,
    },

    [ITEM_RELIC_SILVER] =
    {
        .name = ITEM_NAME("{JPN}こだいのぎんか{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしにつかわれたぎん\nか。たかいねだんでうれる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicSilver,
    },

    [ITEM_RELIC_GOLD] =
    {
        .name = ITEM_NAME("{JPN}こだいのきんか{ENG}"),
        .price = (I_PRICE >= GEN_6) ? 60000 : 0,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしにつかわれたきん\nか。たかいねだんでうれる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicGold,
    },

    [ITEM_RELIC_VASE] =
    {
        .name = ITEM_NAME("{JPN}こだいのツボ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしにつくられたツボ\n。たかいねだんでうれる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicVase,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_BAND] =
    {
        .name = ITEM_NAME("{JPN}こだいのうでわ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしにつくられたうで\nわ。たかいねだんでうれる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicBand,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_STATUE] =
    {
        .name = ITEM_NAME("{JPN}こだいのせきぞう{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしにつくられたせき\nぞう。たかいねだんでうれる\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicStatue,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_CROWN] =
    {
        .name = ITEM_NAME("{JPN}こだいのおうかん{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしにつくられたおう\nかん。たかいねだんでうれる\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCrown,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_STRANGE_SOUVENIR] =
    {
        .name = ITEM_NAME("{JPN}ふしぎなおきもの{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 10,
        .description = COMPOUND_STRING(
            "{JPN}アローラの まもりがみと\n{JPN}される ポケモンを\n{JPN}かたどった おきもの{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

// Fossils

    [ITEM_HELIX_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}かいのカセキ{ENG}"),
        .description = COMPOUND_STRING(
            "{JPN}おおむかし うみに\n{JPN}すんでいた ポケモンの\n{JPN}かいがらの いちぶ{ENG}"),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_HelixFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}こうらのカセキ{ENG}"),
        .description = COMPOUND_STRING(
            "{JPN}おおむかし うみに\n{JPN}すんでいた ポケモンの\n{JPN}こうらの いちぶ{ENG}"),
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_DomeFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = ITEM_NAME("{JPN}ひみつのコハク{ENG}"),
        .description = COMPOUND_STRING(
            "{JPN}こだい ポケモンの\n{JPN}いでんし じょうほうが\n{JPN}とじこめられている いし{ENG}"),
    #if I_KEY_FOSSILS >= GEN_4
        .price = 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_OldAmber,
        .iconPalette = gItemIconPalette_OldAmber,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}ねっこのカセキ{ENG}"),
        .description = sRootFossilDesc,
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RootFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}ツメのカセキ{ENG}"),
        .description = sRootFossilDesc,
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ClawFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_ARMOR_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}たてのカセキ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "{JPN}おおむかし ちじょうで\n{JPN}くらしていた ポケモンの\n{JPN}えりかざりの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ArmorFossil,
        .iconPalette = gItemIconPalette_ArmorFossil,
    },

    [ITEM_SKULL_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}ずがいのカセキ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "{JPN}おおむかし ちじょうで\n{JPN}くらしていた ポケモンの\n{JPN}あたまの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SkullFossil,
        .iconPalette = gItemIconPalette_SkullFossil,
    },

    [ITEM_COVER_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}ふたのカセキ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "{JPN}おおむかし うみに\n{JPN}すんでいた ポケモンの\n{JPN}せなかの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_CoverFossil,
        .iconPalette = gItemIconPalette_CoverFossil,
    },

    [ITEM_PLUME_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}はねのカセキ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "{JPN}とり ポケモンの\n{JPN}そせんの\n{JPN}つばさの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_PlumeFossil,
        .iconPalette = gItemIconPalette_PlumeFossil,
    },

    [ITEM_JAW_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}アゴのカセキ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "{JPN}おおむかし ちじょうで\n{JPN}くらしていた ポケモンの\n{JPN}アゴの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_JawFossil,
        .iconPalette = gItemIconPalette_JawFossil,
    },

    [ITEM_SAIL_FOSSIL] =
    {
        .name = ITEM_NAME("{JPN}ヒレのカセキ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
            "{JPN}おおむかし ちじょうで\n{JPN}くらしていた ポケモンの\n{JPN}ヒレの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SailFossil,
        .iconPalette = gItemIconPalette_SailFossil,
    },

    [ITEM_FOSSILIZED_BIRD] =
    {
        .name = ITEM_NAME("{JPN}カセキのトリ{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}おおむかし そらを\n{JPN}とんでいた ポケモンの\n{JPN}カセキの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedBird,
        .iconPalette = gItemIconPalette_FossilizedBird,
    },

    [ITEM_FOSSILIZED_FISH] =
    {
        .name = ITEM_NAME("{JPN}カセキのサカナ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}カセキのサカナ{ENG}"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedFish,
        .iconPalette = gItemIconPalette_FossilizedFish,
    },

    [ITEM_FOSSILIZED_DRAKE] =
    {
        .name = ITEM_NAME("{JPN}カセキのリュウ{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}おおむかし りくに\n{JPN}すんでいた ポケモンの\n{JPN}カセキの いちぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDrake,
        .iconPalette = gItemIconPalette_FossilizedDrake,
    },

    [ITEM_FOSSILIZED_DINO] =
    {
        .name = ITEM_NAME("{JPN}カセキのクビナガ{ENG}"),
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDino,
        .iconPalette = gItemIconPalette_FossilizedDino,
    },

// Mulch

    [ITEM_GROWTH_MULCH] =
    {
        .name = ITEM_NAME("{JPN}すくすくこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}すくすくこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}きのみのせいちょうをはやめ\nるひりょう。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GROWTH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GrowthMulch,
    },

    [ITEM_DAMP_MULCH] =
    {
        .name = ITEM_NAME("{JPN}じめじめこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}じめじめこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}きのみのせいちょうをおそく\nするひりょう。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_DAMP_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_DampMulch,
    },

    [ITEM_STABLE_MULCH] =
    {
        .name = ITEM_NAME("{JPN}ながながこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ながながこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}きのみのきがかれにくくなる\nひりょう。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_STABLE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_StableMulch,
        .iconPalette = gItemIconPalette_StableMulch,
    },

    [ITEM_GOOEY_MULCH] =
    {
        .name = ITEM_NAME("{JPN}ねばねばこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ねばねばこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}きのみがおちたあとまたそだ\nつかいすうをふやすひりょう\n。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GOOEY_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GooeyMulch,
    },

    [ITEM_RICH_MULCH] =
    {
        .name = ITEM_NAME("{JPN}たわわこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}たわわこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}しゅうかくできるきのみのか\nずをふやすひりょう。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_RICH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_RichMulch,
    },

    [ITEM_SURPRISE_MULCH] =
    {
        .name = ITEM_NAME("{JPN}びっくりこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}びっくりこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}きのみのとつぜんへんいがお\nきやすくなるひりょう。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_SURPRISE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_SurpriseMulch,
    },

    [ITEM_BOOST_MULCH] =
    {
        .name = ITEM_NAME("{JPN}ぐんぐんこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ぐんぐんこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}やわらかいつちがはやくかわ\nくひりょう。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_BOOST_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_BoostMulch,
    },

    [ITEM_AMAZE_MULCH] =
    {
        .name = ITEM_NAME("{JPN}とんでもこやし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}とんでもこやし{ENG}"),
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
            "{JPN}たわわ・びっくり・ぐんぐん\nのこうかをあわせもつひりょ\nう。{ENG}"),
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_AMAZE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_AmazeMulch,
    },

// Apricorns
    #if (I_PRICE >= GEN_8 || I_PRICE <= GEN_2)
        #define APRICORN_PRICE 200
    #elif I_PRICE >= GEN_5
        #define APRICORN_PRICE 20
    #else
        #define APRICORN_PRICE 0
    #endif

    [ITEM_RED_APRICORN] =
    {
        .name = ITEM_NAME("{JPN}あかぼんぐり{ENG}"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "{JPN}あかいろの ぼんぐり\n{JPN}つーんと はなにくる\n{JPN}かおりがする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_RedApricorn,
    },

    [ITEM_BLUE_APRICORN] =
    {
        .name = ITEM_NAME("{JPN}あおぼんぐり{ENG}"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "{JPN}あおいろの ぼんぐり\n{JPN}すこし あおくさい\n{JPN}かおりがする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlueApricorn,
    },

    [ITEM_YELLOW_APRICORN] =
    {
        .name = ITEM_NAME("{JPN}きぼんぐり{ENG}"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "{JPN}きいろの ぼんぐり\n{JPN}さわやかな かおりがする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_YellowApricorn,
    },

    [ITEM_GREEN_APRICORN] =
    {
        .name = ITEM_NAME("{JPN}みどぼんぐり{ENG}"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "{JPN}みどりいろの ぼんぐり\n{JPN}ふしぎと こうばしい\n{JPN}かおりがする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_GreenApricorn,
    },

    [ITEM_PINK_APRICORN] =
    {
        .name = ITEM_NAME("{JPN}ももぼんぐり{ENG}"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "{JPN}ももいろの ぼんぐり\n{JPN}あまそうな いい\n{JPN}かおりがする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_PinkApricorn,
    },

    [ITEM_WHITE_APRICORN] =
    {
        .name = ITEM_NAME("{JPN}しろぼんぐり{ENG}"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "{JPN}しろいろの ぼんぐり\n{JPN}なんの かおりも しない{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_WhiteApricorn,
    },

    [ITEM_BLACK_APRICORN] =
    {
        .name = ITEM_NAME("{JPN}くろぼんぐり{ENG}"),
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
            "{JPN}くろいろの ぼんぐり\n{JPN}なんとも いえない\n{JPN}かおりがする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlackApricorn,
    },

    [ITEM_WISHING_PIECE] =
    {
        .name = ITEM_NAME("{JPN}ねがいのかたまり{ENG}"),
        .price = 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{PKMN}{JPN}のすあなにいれるとダイ\nマックスポケモンがくる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .flingPower = 50,
        .iconPic = gItemIcon_WishingPiece,
        .iconPalette = gItemIconPalette_WishingPiece,
    },

    [ITEM_GALARICA_TWIG] =
    {
        .name = ITEM_NAME("{JPN}ガラナツのえだ{ENG}"),
        .price = 20 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}ガラルちほうの いちぶに\n{JPN}はえる ガラナツという\n{JPN}きの えだ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaTwig,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_ARMORITE_ORE] =
    {
        .name = ITEM_NAME("{JPN}ヨロイこうせき{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ヨロイこうせき{ENG}"),
        .price = 20,
        .description = COMPOUND_STRING(
            "{JPN}ヨロイじまで とれる\n{JPN}めずらしい いし{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ArmoriteOre,
        .iconPalette = gItemIconPalette_ArmoriteOre,
    },

    [ITEM_DYNITE_ORE] =
    {
        .name = ITEM_NAME("{JPN}マックスこうせき{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}マックスこうせき{ENG}"),
        .price = 20,
        .description = COMPOUND_STRING(
            "{JPN}マックスダイすあなで\n{JPN}とれる\n{JPN}なぞの いし{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_DyniteOre,
        .iconPalette = gItemIconPalette_DyniteOre,
    },

// Mail

    [ITEM_ORANGE_MAIL] =
    {
        .name = ITEM_NAME("{JPN}オレンジメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}オレンジメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}ジグザグマの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
        .iconPic = gItemIcon_OrangeMail,
        .iconPalette = gItemIconPalette_OrangeMail,
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = ITEM_NAME("{JPN}ハーバーメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ハーバーメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}キャモメの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
        .iconPic = gItemIcon_HarborMail,
        .iconPalette = gItemIconPalette_HarborMail,
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = ITEM_NAME("{JPN}キラキラメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}キラキラメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}ピカチュウの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
        .iconPic = gItemIcon_GlitterMail,
        .iconPalette = gItemIconPalette_GlitterMail,
    },

    [ITEM_MECH_MAIL] =
    {
        .name = ITEM_NAME("{JPN}メカニカルメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}メカニカルメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}コイルの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
        .iconPic = gItemIcon_MechMail,
        .iconPalette = gItemIconPalette_MechMail,
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = ITEM_NAME("{JPN}ウッディメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ウッディメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}ナマケロの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
        .iconPic = gItemIcon_WoodMail,
        .iconPalette = gItemIconPalette_WoodMail,
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = ITEM_NAME("{JPN}クロスメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}クロスメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}ホエルコの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
        .iconPic = gItemIcon_WaveMail,
        .iconPalette = gItemIconPalette_WaveMail,
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = ITEM_NAME("{JPN}トレジャーメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}トレジャーメール{ENG}"),
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
        .iconPic = gItemIcon_BeadMail,
        .iconPalette = gItemIconPalette_BeadMail,
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = ITEM_NAME("{JPN}シャドーメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}シャドーメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}ヨマワルの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
        .iconPic = gItemIcon_ShadowMail,
        .iconPalette = gItemIconPalette_ShadowMail,
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = ITEM_NAME("{JPN}トロピカルメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}トロピカルメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}キレイハナの すがたが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
        .iconPic = gItemIcon_TropicMail,
        .iconPalette = gItemIconPalette_TropicMail,
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = ITEM_NAME("{JPN}ドリームメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ドリームメール{ENG}"),
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
        .iconPic = gItemIcon_DreamMail,
        .iconPalette = gItemIconPalette_DreamMail,
    },

    [ITEM_FAB_MAIL] =
    {
        .name = ITEM_NAME("{JPN}ミラクルメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ミラクルメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}ごうかな もようが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
        .iconPic = gItemIcon_FabMail,
        .iconPalette = gItemIconPalette_FabMail,
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = ITEM_NAME("{JPN}レトロメール{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}レトロメール{ENG}"),
        .price = 50,
        .description = COMPOUND_STRING(
            "{JPN}3ひきの ポケモンが\n{JPN}プリントされた びんせん\n{JPN}ポケモンに もたせる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
        .iconPic = gItemIcon_RetroMail,
        .iconPalette = gItemIconPalette_RetroMail,
    },

// Evolution Items

    [ITEM_FIRE_STONE] =
    {
        .name = ITEM_NAME("{JPN}ほのおのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_FireStone,
        .iconPalette = gItemIconPalette_FireStone,
    },

    [ITEM_WATER_STONE] =
    {
        .name = ITEM_NAME("{JPN}みずのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_WaterStone,
        .iconPalette = gItemIconPalette_WaterStone,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = ITEM_NAME("{JPN}かみなりのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ThunderStone,
        .iconPalette = gItemIconPalette_ThunderStone,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = ITEM_NAME("{JPN}リーフのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LeafStone,
        .iconPalette = gItemIconPalette_LeafStone,
    },

    [ITEM_ICE_STONE] =
    {
        .name = ITEM_NAME("{JPN}こおりのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_IceStone,
        .iconPalette = gItemIconPalette_IceStone,
    },

    [ITEM_SUN_STONE] =
    {
        .name = ITEM_NAME("{JPN}たいようのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SunStone,
        .iconPalette = gItemIconPalette_SunStone,
    },

    [ITEM_MOON_STONE] =
    {
        .name = ITEM_NAME("{JPN}つきのいし{ENG}"),
    #if I_PRICE >= GEN_7
        .price = 3000,
    #elif I_PRICE >= GEN_4
        .price = 2100,
    #elif I_PRICE == GEN_3
        .price = 0,
    #else
        .price = 1,
    #endif
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MoonStone,
        .iconPalette = gItemIconPalette_MoonStone,
    },

    [ITEM_SHINY_STONE] =
    {
        .name = ITEM_NAME("{JPN}ひかりのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ShinyStone,
        .iconPalette = gItemIconPalette_ShinyStone,
    },

    [ITEM_DUSK_STONE] =
    {
        .name = ITEM_NAME("{JPN}やみのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DuskStone,
        .iconPalette = gItemIconPalette_DuskStone,
    },

    [ITEM_DAWN_STONE] =
    {
        .name = ITEM_NAME("{JPN}めざめいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 2100,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DawnStone,
        .iconPalette = gItemIconPalette_DawnStone,
    },

    [ITEM_SWEET_APPLE] =
    {
        .name = ITEM_NAME("{JPN}あまーいりんご{ENG}"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}あまい りんご{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetApple,
        .iconPalette = gItemIconPalette_SweetApple,
    },

    [ITEM_TART_APPLE] =
    {
        .name = ITEM_NAME("{JPN}すっぱいりんご{ENG}"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}すっぱい りんご{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_TartApple,
        .iconPalette = gItemIconPalette_TartApple,
    },

    [ITEM_CRACKED_POT] =
    {
        .name = ITEM_NAME("{JPN}われたポット{ENG}"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}われた ポット{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_CrackedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_CHIPPED_POT] =
    {
        .name = ITEM_NAME("{JPN}かけたポット{ENG}"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}かけた ポット{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_ChippedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_GALARICA_CUFF] =
    {
        .name = ITEM_NAME("{JPN}ガラナツブレス{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 3000 : 6000,
        .description = COMPOUND_STRING(
            "{JPN}ガラナツのえだを\n{JPN}あみこんだ ブレスレット\n{JPN}ガラルヤドンが よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaCuff,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_GALARICA_WREATH] =
    {
        .name = ITEM_NAME("{JPN}ガラナツリース{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 3000 : 6000,
        .description = COMPOUND_STRING(
            "{JPN}ガラナツのえだを\n{JPN}あみこんだ かんむり\n{JPN}ガラルヤドンが よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaWreath,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = ITEM_NAME("{JPN}りゅうのウロコ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}ドラゴンタイプの\n{JPN}ポケモンが もっている\n{JPN}ふしぎな ウロコ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DragonScale,
        .iconPalette = gItemIconPalette_DragonScale,
    },

    [ITEM_UPGRADE] =
    {
        .name = ITEM_NAME("{JPN}アップグレード{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}ふしぎな はこ\n{JPN}シルフ カンパニーせい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_Upgrade,
        .iconPalette = gItemIconPalette_Upgrade,
    },

    [ITEM_PROTECTOR] =
    {
        .name = ITEM_NAME("{JPN}プロテクター{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}とても かたくて おもい\n{JPN}ある ポケモンが\n{JPN}このんでいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Protector,
        .iconPalette = gItemIconPalette_Protector,
    },

    [ITEM_ELECTIRIZER] =
    {
        .name = ITEM_NAME("{JPN}エレキブースター{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}でんきの エネルギーが {JPN}た\nくわえられている はこ {JPN}あ\nるポケモンが このんでいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Electirizer,
        .iconPalette = gItemIconPalette_Electirizer,
    },

    [ITEM_MAGMARIZER] =
    {
        .name = ITEM_NAME("{JPN}マグマブースター{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}マグマの エネルギーが {JPN}た\nくわえられている はこ {JPN}あ\nるポケモンが このんでいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Magmarizer,
        .iconPalette = gItemIconPalette_Magmarizer,
    },

    [ITEM_DUBIOUS_DISC] =
    {
        .name = ITEM_NAME("{JPN}あやしいパッチ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}なかに あやしい\n{JPN}じょうほうが つまった\n{JPN}とうめいな きかい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 50,
        .iconPic = gItemIcon_DubiousDisc,
        .iconPalette = gItemIconPalette_DubiousDisc,
    },

    [ITEM_REAPER_CLOTH] =
    {
        .name = ITEM_NAME("{JPN}れいかいのぬの{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}つよい れいりょくが {JPN}こめ\nられている ぬの {JPN}あるポケ\nモンが このんでいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 10,
        .iconPic = gItemIcon_ReaperCloth,
        .iconPalette = gItemIconPalette_ReaperCloth,
    },

    [ITEM_PRISM_SCALE] =
    {
        .name = ITEM_NAME("{JPN}きれいなウロコ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 2000,
    #else
        .price = 500,
    #endif
        .description = COMPOUND_STRING(
            "{JPN}ある とくていの\n{JPN}ポケモンを しんかさせる\n{JPN}ふしぎな ウロコ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PrismScale,
        .iconPalette = gItemIconPalette_PrismScale,
    },

    [ITEM_WHIPPED_DREAM] =
    {
        .name = ITEM_NAME("{JPN}ホイップポップ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}ほんのり あまいクリーム\n{JPN}ある ポケモンが\n{JPN}このんでいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_WhippedDream,
        .iconPalette = gItemIconPalette_WhippedDream,
    },

    [ITEM_SACHET] =
    {
        .name = ITEM_NAME("{JPN}においぶくろ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
            "{JPN}きつめの かおりのふくろ\n{JPN}ある ポケモンが\n{JPN}このんでいる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Sachet,
        .iconPalette = gItemIconPalette_Sachet,
    },

    [ITEM_OVAL_STONE] =
    {
        .name = ITEM_NAME("{JPN}まんまるいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 2100,
        .description = COMPOUND_STRING(
            "{JPN}ある とくていの\n{JPN}ポケモンを しんかさせる\n{JPN}ふしぎな いし{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_OvalStone,
        .iconPalette = gItemIconPalette_OvalStone,
    },

    [ITEM_STRAWBERRY_SWEET] =
    {
        .name = ITEM_NAME("{JPN}いちごアメざいく{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}いちごの アメざいく {JPN}マホ\nミルに もたせると {JPN}くるく\nる まわって よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StrawberrySweet,
        .iconPalette = gItemIconPalette_StrawberrySweet,
    },

    [ITEM_LOVE_SWEET] =
    {
        .name = ITEM_NAME("{JPN}ハートアメざいく{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}ハートの アメざいく {JPN}マホ\nミルに もたせると {JPN}くるく\nる まわって よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LoveSweet,
        .iconPalette = gItemIconPalette_LoveSweet,
    },

    [ITEM_BERRY_SWEET] =
    {
        .name = ITEM_NAME("{JPN}ベリーアメざいく{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}ベリーの アメざいく {JPN}マホ\nミルに もたせると {JPN}くるく\nる まわって よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerrySweet,
        .iconPalette = gItemIconPalette_BerrySweet,
    },

    [ITEM_CLOVER_SWEET] =
    {
        .name = ITEM_NAME("{JPN}よつばアメざいく{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}よつばの アメざいく {JPN}マホ\nミルに もたせると {JPN}くるく\nる まわって よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CloverSweet,
        .iconPalette = gItemIconPalette_CloverSweet,
    },

    [ITEM_FLOWER_SWEET] =
    {
        .name = ITEM_NAME("{JPN}おはなアメざいく{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}おはなの アメざいく {JPN}マホ\nミルに もたせると {JPN}くるく\nる まわって よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FlowerSweet,
        .iconPalette = gItemIconPalette_FlowerSweet,
    },

    [ITEM_STAR_SWEET] =
    {
        .name = ITEM_NAME("{JPN}スターアメざいく{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}スターの アメざいく {JPN}マホ\nミルに もたせると {JPN}くるく\nる まわって よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarSweet,
        .iconPalette = gItemIconPalette_StarSweet,
    },

    [ITEM_RIBBON_SWEET] =
    {
        .name = ITEM_NAME("{JPN}リボンアメざいく{ENG}"),
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
            "{JPN}リボンの アメざいく {JPN}マホ\nミルに もたせると {JPN}くるく\nる まわって よろこぶ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RibbonSweet,
        .iconPalette = gItemIconPalette_RibbonSweet,
    },

    [ITEM_EVERSTONE] =
    {
        .name = ITEM_NAME("{JPN}かわらずのいし{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 3000 : 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンが\n{JPN}しんか しなくなる\n{JPN}ふしぎな いし{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Everstone,
        .iconPalette = gItemIconPalette_Everstone,
    },

// Nectars

    [ITEM_RED_NECTAR] =
    {
        .name = ITEM_NAME("{JPN}くれないのミツ{ENG}"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_RedNectar,
    },

    [ITEM_YELLOW_NECTAR] =
    {
        .name = ITEM_NAME("{JPN}やまぶきのミツ{ENG}"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_YellowNectar,
    },

    [ITEM_PINK_NECTAR] =
    {
        .name = ITEM_NAME("{JPN}うすもものミツ{ENG}"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PinkNectar,
    },

    [ITEM_PURPLE_NECTAR] =
    {
        .name = ITEM_NAME("{JPN}むらさきのミツ{ENG}"),
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PurpleNectar,
    },

// Plates

    [ITEM_FLAME_PLATE] =
    {
        .name = ITEM_NAME("{JPN}ひのたまプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ほのおの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FlamePlate,
    },

    [ITEM_SPLASH_PLATE] =
    {
        .name = ITEM_NAME("{JPN}しずくプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると みずの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SplashPlate,
    },

    [ITEM_ZAP_PLATE] =
    {
        .name = ITEM_NAME("{JPN}いかずちプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると でんきの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ZapPlate,
    },

    [ITEM_MEADOW_PLATE] =
    {
        .name = ITEM_NAME("{JPN}みどりのプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると くさの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MeadowPlate,
    },

    [ITEM_ICICLE_PLATE] =
    {
        .name = ITEM_NAME("{JPN}つららのプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こおりの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IciclePlate,
    },

    [ITEM_FIST_PLATE] =
    {
        .name = ITEM_NAME("{JPN}こぶしのプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると かくとうの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FistPlate,
    },

    [ITEM_TOXIC_PLATE] =
    {
        .name = ITEM_NAME("{JPN}もうどくプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると どくの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ToxicPlate,
    },

    [ITEM_EARTH_PLATE] =
    {
        .name = ITEM_NAME("{JPN}だいちのプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じめんの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_EarthPlate,
    },

    [ITEM_SKY_PLATE] =
    {
        .name = ITEM_NAME("{JPN}あおぞらプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ひこうの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SkyPlate,
    },

    [ITEM_MIND_PLATE] =
    {
        .name = ITEM_NAME("{JPN}ふしぎのプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると エスパーの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MindPlate,
    },

    [ITEM_INSECT_PLATE] =
    {
        .name = ITEM_NAME("{JPN}たまむしプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると むしの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_InsectPlate,
    },

    [ITEM_STONE_PLATE] =
    {
        .name = ITEM_NAME("{JPN}がんせきプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いわの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_StonePlate,
    },

    [ITEM_SPOOKY_PLATE] =
    {
        .name = ITEM_NAME("{JPN}もののけプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ゴーストの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SpookyPlate,
    },

    [ITEM_DRACO_PLATE] =
    {
        .name = ITEM_NAME("{JPN}りゅうのプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ドラゴンの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DracoPlate,
    },

    [ITEM_DREAD_PLATE] =
    {
        .name = ITEM_NAME("{JPN}こわもてプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると あくの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DreadPlate,
    },

    [ITEM_IRON_PLATE] =
    {
        .name = ITEM_NAME("{JPN}こうてつプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると はがねの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IronPlate,
    },

    [ITEM_PIXIE_PLATE] =
    {
        .name = ITEM_NAME("{JPN}せいれいプレート{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}もたせると フェアリーの\n{JPN}わざの いりょくが\n{JPN}つよまる せきばん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_PixiePlate,
    },

// Drives

    [ITEM_DOUSE_DRIVE] =
    {
        .name = ITEM_NAME("{JPN}アクアカセット{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "{JPN}テクノバスターが\n{JPN}みずタイプに なる\n{JPN}カセット{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_DouseDrive,
    },

    [ITEM_SHOCK_DRIVE] =
    {
        .name = ITEM_NAME("{JPN}イナズマカセット{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "{JPN}テクノバスターが\n{JPN}でんきタイプに なる\n{JPN}カセット{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ShockDrive,
    },

    [ITEM_BURN_DRIVE] =
    {
        .name = ITEM_NAME("{JPN}ブレイズカセット{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "{JPN}テクノバスターが\n{JPN}ほのおタイプに なる\n{JPN}カセット{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_BurnDrive,
    },

    [ITEM_CHILL_DRIVE] =
    {
        .name = ITEM_NAME("{JPN}フリーズカセット{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
            "{JPN}テクノバスターが\n{JPN}こおりタイプに なる\n{JPN}カセット{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ChillDrive,
    },

// Memories

    [ITEM_FIRE_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ファイヤーメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ファイヤーメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}ほのおに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 50,
        .iconPic = gItemIcon_FireMemory,
        .iconPalette = gItemIconPalette_FireMemory,
    },

    [ITEM_WATER_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ウオーターメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ウオーターメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}みずに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 50,
        .iconPic = gItemIcon_WaterMemory,
        .iconPalette = gItemIconPalette_WaterMemory,
    },

    [ITEM_ELECTRIC_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}エレクトロメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}エレクトロメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}でんきに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 50,
        .iconPic = gItemIcon_ElectricMemory,
        .iconPalette = gItemIconPalette_ElectricMemory,
    },

    [ITEM_GRASS_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}グラスメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}グラスメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}くさに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 50,
        .iconPic = gItemIcon_GrassMemory,
        .iconPalette = gItemIconPalette_GrassMemory,
    },

    [ITEM_ICE_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}アイスメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}アイスメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}こおりに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 50,
        .iconPic = gItemIcon_IceMemory,
        .iconPalette = gItemIconPalette_IceMemory,
    },

    [ITEM_FIGHTING_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ファイトメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ファイトメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}かくとうに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 50,
        .iconPic = gItemIcon_FightingMemory,
        .iconPalette = gItemIconPalette_FightingMemory,
    },

    [ITEM_POISON_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ポイズンメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ポイズンメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}どくに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 50,
        .iconPic = gItemIcon_PoisonMemory,
        .iconPalette = gItemIconPalette_PoisonMemory,
    },

    [ITEM_GROUND_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}グラウンドメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}グラウンドメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}じめんに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 50,
        .iconPic = gItemIcon_GroundMemory,
        .iconPalette = gItemIconPalette_GroundMemory,
    },

    [ITEM_FLYING_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}フライングメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}フライングメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}ひこうに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_FlyingMemory,
        .iconPalette = gItemIconPalette_FlyingMemory,
    },

    [ITEM_PSYCHIC_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}サイキックメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}サイキックメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}エスパーに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 50,
        .iconPic = gItemIcon_PsychicMemory,
        .iconPalette = gItemIconPalette_PsychicMemory,
    },

    [ITEM_BUG_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}バグメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}バグメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}むしに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 50,
        .iconPic = gItemIcon_BugMemory,
        .iconPalette = gItemIconPalette_BugMemory,
    },

    [ITEM_ROCK_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ロックメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ロックメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}いわに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 50,
        .iconPic = gItemIcon_RockMemory,
        .iconPalette = gItemIconPalette_RockMemory,
    },

    [ITEM_GHOST_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ゴーストメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ゴーストメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}ゴーストに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 50,
        .iconPic = gItemIcon_GhostMemory,
        .iconPalette = gItemIconPalette_GhostMemory,
    },

    [ITEM_DRAGON_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ドラゴンメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ドラゴンメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}ドラゴンに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 50,
        .iconPic = gItemIcon_DragonMemory,
        .iconPalette = gItemIconPalette_DragonMemory,
    },

    [ITEM_DARK_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}ダークメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ダークメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}あくに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 50,
        .iconPic = gItemIcon_DarkMemory,
        .iconPalette = gItemIconPalette_DarkMemory,
    },

    [ITEM_STEEL_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}スチールメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}スチールメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}はがねに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 50,
        .iconPic = gItemIcon_SteelMemory,
        .iconPalette = gItemIconPalette_SteelMemory,
    },

    [ITEM_FAIRY_MEMORY] =
    {
        .name = ITEM_NAME("{JPN}フェアリーメモリ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}フェアリーメモリ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}シルヴァディの タイプを\n{JPN}フェアリーに かえる\n{JPN}データメモリ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 50,
        .iconPic = gItemIcon_FairyMemory,
        .iconPalette = gItemIconPalette_FairyMemory,
    },

    [ITEM_RUSTED_SWORD] =
    {
        .name = ITEM_NAME("{JPN}くちたけん{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}えいゆうが さいやくを\n{JPN}うちはらったと\n{JPN}つたえられる けん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedSword,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

    [ITEM_RUSTED_SHIELD] =
    {
        .name = ITEM_NAME("{JPN}くちたたて{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}えいゆうが さいやくを\n{JPN}うちはらったと\n{JPN}つたえられる たて{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedShield,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

// Colored Orbs

    [ITEM_RED_ORB] =
    {
        .name = ITEM_NAME("{JPN}べにいろのたま{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしの ちからが\n{JPN}こめられている という\n{JPN}あかく かがやく たま{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RedOrb,
        .iconPalette = gItemIconPalette_RedOrb,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = ITEM_NAME("{JPN}あいいろのたま{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしの ちからが\n{JPN}こめられている という\n{JPN}あおく かがやく たま{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BlueOrb,
        .iconPalette = gItemIconPalette_BlueOrb,
    },

// Mega Stones

    [ITEM_VENUSAURITE] =
    {
        .name = ITEM_NAME("{JPN}フシギバナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}フシギバナに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Venusaurite,
        .iconPalette = gItemIconPalette_Venusaurite,
    },

    [ITEM_CHARIZARDITE_X] =
    {
        .name = ITEM_NAME("{JPN}リザードナイトX{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeX,
        .iconPalette = gItemIconPalette_CharizarditeX,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
        .name = ITEM_NAME("{JPN}リザードナイトY{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeY,
        .iconPalette = gItemIconPalette_CharizarditeY,
    },

    [ITEM_BLASTOISINITE] =
    {
        .name = ITEM_NAME("{JPN}カメックスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}カメックスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blastoisinite,
        .iconPalette = gItemIconPalette_Blastoisinite,
    },

    [ITEM_BEEDRILLITE] =
    {
        .name = ITEM_NAME("{JPN}スピアナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}スピアーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Beedrillite,
        .iconPalette = gItemIconPalette_Beedrillite,
    },

    [ITEM_PIDGEOTITE] =
    {
        .name = ITEM_NAME("{JPN}ピジョットナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ピジョットに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pidgeotite,
        .iconPalette = gItemIconPalette_Pidgeotite,
    },

    [ITEM_ALAKAZITE] =
    {
        .name = ITEM_NAME("{JPN}フーディナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}フーディンに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Alakazite,
        .iconPalette = gItemIconPalette_Alakazite,
    },

    [ITEM_SLOWBRONITE] =
    {
        .name = ITEM_NAME("{JPN}ヤドランナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ヤドランに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Slowbronite,
        .iconPalette = gItemIconPalette_Slowbronite,
    },

    [ITEM_GENGARITE] =
    {
        .name = ITEM_NAME("{JPN}ゲンガナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ゲンガーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gengarite,
        .iconPalette = gItemIconPalette_Gengarite,
    },

    [ITEM_KANGASKHANITE] =
    {
        .name = ITEM_NAME("{JPN}ガルーラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ガルーラに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Kangaskhanite,
        .iconPalette = gItemIconPalette_Kangaskhanite,
    },

    [ITEM_PINSIRITE] =
    {
        .name = ITEM_NAME("{JPN}カイロスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}カイロスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pinsirite,
        .iconPalette = gItemIconPalette_Pinsirite,
    },

    [ITEM_GYARADOSITE] =
    {
        .name = ITEM_NAME("{JPN}ギャラドスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ギャラドスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gyaradosite,
        .iconPalette = gItemIconPalette_Gyaradosite,
    },

    [ITEM_AERODACTYLITE] =
    {
        .name = ITEM_NAME("{JPN}プテラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}プテラに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aerodactylite,
        .iconPalette = gItemIconPalette_Aerodactylite,
    },

    [ITEM_MEWTWONITE_X] =
    {
        .name = ITEM_NAME("{JPN}ミュウツナイトX{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteX,
        .iconPalette = gItemIconPalette_MewtwoniteX,
    },

    [ITEM_MEWTWONITE_Y] =
    {
        .name = ITEM_NAME("{JPN}ミュウツナイトY{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteY,
        .iconPalette = gItemIconPalette_MewtwoniteY,
    },

    [ITEM_AMPHAROSITE] =
    {
        .name = ITEM_NAME("{JPN}デンリュウナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}デンリュウに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Ampharosite,
        .iconPalette = gItemIconPalette_Ampharosite,
    },

    [ITEM_STEELIXITE] =
    {
        .name = ITEM_NAME("{JPN}ハガネールナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ハガネールに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Steelixite,
        .iconPalette = gItemIconPalette_Steelixite,
    },

    [ITEM_SCIZORITE] =
    {
        .name = ITEM_NAME("{JPN}ハッサムナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ハッサムに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scizorite,
        .iconPalette = gItemIconPalette_Scizorite,
    },

    [ITEM_HERACRONITE] =
    {
        .name = ITEM_NAME("{JPN}ヘラクロスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ヘラクロスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heracronite,
        .iconPalette = gItemIconPalette_Heracronite,
    },

    [ITEM_HOUNDOOMINITE] =
    {
        .name = ITEM_NAME("{JPN}ヘルガナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ヘルガーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Houndoominite,
        .iconPalette = gItemIconPalette_Houndoominite,
    },

    [ITEM_TYRANITARITE] =
    {
        .name = ITEM_NAME("{JPN}バンギラスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}バンギラスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tyranitarite,
        .iconPalette = gItemIconPalette_Tyranitarite,
    },

    [ITEM_SCEPTILITE] =
    {
        .name = ITEM_NAME("{JPN}ジュカインナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ジュカインに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sceptilite,
        .iconPalette = gItemIconPalette_Sceptilite,
    },

    [ITEM_BLAZIKENITE] =
    {
        .name = ITEM_NAME("{JPN}バシャーモナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}バシャーモに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blazikenite,
        .iconPalette = gItemIconPalette_Blazikenite,
    },

    [ITEM_SWAMPERTITE] =
    {
        .name = ITEM_NAME("{JPN}ラグラージナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ラグラージに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Swampertite,
        .iconPalette = gItemIconPalette_Swampertite,
    },

    [ITEM_GARDEVOIRITE] =
    {
        .name = ITEM_NAME("{JPN}サーナイトナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}サーナイトに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gardevoirite,
        .iconPalette = gItemIconPalette_Gardevoirite,
    },

    [ITEM_SABLENITE] =
    {
        .name = ITEM_NAME("{JPN}ヤミラミナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ヤミラミに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sablenite,
        .iconPalette = gItemIconPalette_Sablenite,
    },

    [ITEM_MAWILITE] =
    {
        .name = ITEM_NAME("{JPN}クチートナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}クチートに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Mawilite,
        .iconPalette = gItemIconPalette_Mawilite,
    },

    [ITEM_AGGRONITE] =
    {
        .name = ITEM_NAME("{JPN}ボスゴドラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ボスゴドラに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aggronite,
        .iconPalette = gItemIconPalette_Aggronite,
    },

    [ITEM_MEDICHAMITE] =
    {
        .name = ITEM_NAME("{JPN}チャーレムナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}チャーレムに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Medichamite,
        .iconPalette = gItemIconPalette_Medichamite,
    },

    [ITEM_MANECTITE] =
    {
        .name = ITEM_NAME("{JPN}ライボルトナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ライボルトに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Manectite,
        .iconPalette = gItemIconPalette_Manectite,
    },

    [ITEM_SHARPEDONITE] =
    {
        .name = ITEM_NAME("{JPN}サメハダナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}サメハダーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sharpedonite,
        .iconPalette = gItemIconPalette_Sharpedonite,
    },

    [ITEM_CAMERUPTITE] =
    {
        .name = ITEM_NAME("{JPN}バクーダナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}バクーダに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Cameruptite,
        .iconPalette = gItemIconPalette_Cameruptite,
    },

    [ITEM_ALTARIANITE] =
    {
        .name = ITEM_NAME("{JPN}チルタリスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}チルタリスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Altarianite,
        .iconPalette = gItemIconPalette_Altarianite,
    },

    [ITEM_BANETTITE] =
    {
        .name = ITEM_NAME("{JPN}ジュペッタナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ジュペッタに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Banettite,
        .iconPalette = gItemIconPalette_Banettite,
    },

    [ITEM_ABSOLITE] =
    {
        .name = ITEM_NAME("{JPN}アブソルナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbsoliteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Absolite,
        .iconPalette = gItemIconPalette_Absolite,
    },

    [ITEM_GLALITITE] =
    {
        .name = ITEM_NAME("{JPN}オニゴーリナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}オニゴーリに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glalitite,
        .iconPalette = gItemIconPalette_Glalitite,
    },

    [ITEM_SALAMENCITE] =
    {
        .name = ITEM_NAME("{JPN}ボーマンダナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ボーマンダに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Salamencite,
        .iconPalette = gItemIconPalette_Salamencite,
    },

    [ITEM_METAGROSSITE] =
    {
        .name = ITEM_NAME("{JPN}メタグロスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}メタグロスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Metagrossite,
        .iconPalette = gItemIconPalette_Metagrossite,
    },

    [ITEM_LATIASITE] =
    {
        .name = ITEM_NAME("{JPN}ラティアスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ラティアスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiasite,
        .iconPalette = gItemIconPalette_Latiasite,
    },

    [ITEM_LATIOSITE] =
    {
        .name = ITEM_NAME("{JPN}ラティオスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ラティオスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiosite,
        .iconPalette = gItemIconPalette_Latiosite,
    },

    [ITEM_LOPUNNITE] =
    {
        .name = ITEM_NAME("{JPN}ミミロップナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ミミロップに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lopunnite,
        .iconPalette = gItemIconPalette_Lopunnite,
    },

    [ITEM_GARCHOMPITE] =
    {
        .name = ITEM_NAME("{JPN}ガブリアスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGarchompiteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Garchompite,
        .iconPalette = gItemIconPalette_Garchompite,
    },

    [ITEM_LUCARIONITE] =
    {
        .name = ITEM_NAME("{JPN}ルカリオナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLucarioniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lucarionite,
        .iconPalette = gItemIconPalette_Lucarionite,
    },

    [ITEM_ABOMASITE] =
    {
        .name = ITEM_NAME("{JPN}ユキノオナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ユキノオーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Abomasite,
        .iconPalette = gItemIconPalette_Abomasite,
    },

    [ITEM_GALLADITE] =
    {
        .name = ITEM_NAME("{JPN}エルレイドナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}エルレイドに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Galladite,
        .iconPalette = gItemIconPalette_Galladite,
    },

    [ITEM_AUDINITE] =
    {
        .name = ITEM_NAME("{JPN}タブンネナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}タブンネに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Audinite,
        .iconPalette = gItemIconPalette_Audinite,
    },

    [ITEM_DIANCITE] =
    {
        .name = ITEM_NAME("{JPN}ディアンシナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ディアンシーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Diancite,
        .iconPalette = gItemIconPalette_Diancite,
    },

    [ITEM_CLEFABLITE] =
    {
        .name = ITEM_NAME("{JPN}ピクシナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ピクシーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Clefablite,
        .iconPalette = gItemIconPalette_Clefablite,
    },

    [ITEM_VICTREEBELITE] =
    {
        .name = ITEM_NAME("{JPN}ウツボットナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ウツボットに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Victreebelite,
        .iconPalette = gItemIconPalette_Victreebelite,
    },

    [ITEM_STARMINITE] =
    {
        .name = ITEM_NAME("{JPN}スターミナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}スターミーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Starminite,
        .iconPalette = gItemIconPalette_Starminite,
    },

    [ITEM_DRAGONINITE] =
    {
        .name = ITEM_NAME("{JPN}カイリュナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}カイリューに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragoninite,
        .iconPalette = gItemIconPalette_Dragoninite,
    },

    [ITEM_MEGANIUMITE] =
    {
        .name = ITEM_NAME("{JPN}メガニウムナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}メガニウムに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meganiumite,
        .iconPalette = gItemIconPalette_Meganiumite,
    },

    [ITEM_FERALIGITE] =
    {
        .name = ITEM_NAME("{JPN}オーダイルナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}オーダイルに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Feraligite,
        .iconPalette = gItemIconPalette_Feraligite,
    },

    [ITEM_SKARMORITE] =
    {
        .name = ITEM_NAME("{JPN}エアームドナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}エアームドに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Skarmorite,
        .iconPalette = gItemIconPalette_Skarmorite,
    },

    [ITEM_FROSLASSITE] =
    {
        .name = ITEM_NAME("{JPN}ユキメノコナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ユキメノコに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Froslassite,
        .iconPalette = gItemIconPalette_Froslassite,
    },

    [ITEM_EMBOARITE] =
    {
        .name = ITEM_NAME("{JPN}エンブオナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}エンブオーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Emboarite,
        .iconPalette = gItemIconPalette_Emboarite,
    },

    [ITEM_EXCADRITE] =
    {
        .name = ITEM_NAME("{JPN}ドリュウズナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ドリュウズに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Excadrite,
        .iconPalette = gItemIconPalette_Excadrite,
    },

    [ITEM_SCOLIPITE] =
    {
        .name = ITEM_NAME("{JPN}ペンドラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ペンドラーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scolipite,
        .iconPalette = gItemIconPalette_Scolipite,
    },

    [ITEM_SCRAFTINITE] =
    {
        .name = ITEM_NAME("{JPN}ズルズキナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ズルズキンに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scraftinite,
        .iconPalette = gItemIconPalette_Scraftinite,
    },

    [ITEM_EELEKTROSSITE] =
    {
        .name = ITEM_NAME("{JPN}シビルドナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}シビルドンに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Eelektrossite,
        .iconPalette = gItemIconPalette_Eelektrossite,
    },

    [ITEM_CHANDELURITE] =
    {
        .name = ITEM_NAME("{JPN}シャンデラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}シャンデラに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chandelurite,
        .iconPalette = gItemIconPalette_Chandelurite,
    },

    [ITEM_CHESNAUGHTITE] =
    {
        .name = ITEM_NAME("{JPN}ブリガロナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ブリガロンに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chesnaughtite,
        .iconPalette = gItemIconPalette_Chesnaughtite,
    },

    [ITEM_DELPHOXITE] =
    {
        .name = ITEM_NAME("{JPN}マフォクシナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}マフォクシーに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Delphoxite,
        .iconPalette = gItemIconPalette_Delphoxite,
    },

    [ITEM_GRENINJITE] =
    {
        .name = ITEM_NAME("{JPN}ゲッコウガナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ゲッコウガに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Greninjite,
        .iconPalette = gItemIconPalette_Greninjite,
    },

    [ITEM_PYROARITE] =
    {
        .name = ITEM_NAME("{JPN}カエンジシナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}カエンジシに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pyroarite,
        .iconPalette = gItemIconPalette_Pyroarite,
    },

    [ITEM_FLOETTITE] =
    {
        .name = ITEM_NAME("{JPN}フラエッテナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}フラエッテに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Floettite,
        .iconPalette = gItemIconPalette_Floettite,
    },

    [ITEM_MALAMARITE] =
    {
        .name = ITEM_NAME("{JPN}カラマネロナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}カラマネロに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Malamarite,
        .iconPalette = gItemIconPalette_Malamarite,
    },

    [ITEM_BARBARACITE] =
    {
        .name = ITEM_NAME("{JPN}ガメノデスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ガメノデスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Barbaracite,
        .iconPalette = gItemIconPalette_Barbaracite,
    },

    [ITEM_DRAGALGITE] =
    {
        .name = ITEM_NAME("{JPN}ドラミドナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ドラミドロに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragalgite,
        .iconPalette = gItemIconPalette_Dragalgite,
    },

    [ITEM_HAWLUCHANITE] =
    {
        .name = ITEM_NAME("{JPN}ルチャブルナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ルチャブルに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Hawluchanite,
        .iconPalette = gItemIconPalette_Hawluchanite,
    },

    [ITEM_ZYGARDITE] =
    {
        .name = ITEM_NAME("{JPN}ジガルデナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ジガルデに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zygardite,
        .iconPalette = gItemIconPalette_Zygardite,
    },

    [ITEM_DRAMPANITE] =
    {
        .name = ITEM_NAME("{JPN}ジジーロナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ジジーロンに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Drampanite,
        .iconPalette = gItemIconPalette_Drampanite,
    },

    [ITEM_FALINKSITE] =
    {
        .name = ITEM_NAME("{JPN}タイレーツナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}タイレーツに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Falinksite,
        .iconPalette = gItemIconPalette_Falinksite,
    },

    [ITEM_HEATRANITE] =
    {
        .name = ITEM_NAME("{JPN}ヒードラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ヒードランに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heatranite,
        .iconPalette = gItemIconPalette_Heatranite,
    },

    [ITEM_DARKRANITE] =
    {
        .name = ITEM_NAME("{JPN}ダークライナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ダークライに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Darkranite,
        .iconPalette = gItemIconPalette_Darkranite,
    },

    [ITEM_ZERAORITE] =
    {
        .name = ITEM_NAME("{JPN}ゼラオラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ゼラオラに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zeraorite,
        .iconPalette = gItemIconPalette_Zeraorite,
    },

    [ITEM_RAICHUNITE_X] =
    {
        .name = ITEM_NAME("{JPN}ライチュウナイトX{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sRaichuniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteX,
        .iconPalette = gItemIconPalette_RaichuniteX,
    },

    [ITEM_RAICHUNITE_Y] =
    {
        .name = ITEM_NAME("{JPN}ライチュウナイトY{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sRaichuniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteY,
        .iconPalette = gItemIconPalette_RaichuniteY,
    },

    [ITEM_CHIMECHITE] =
    {
        .name = ITEM_NAME("{JPN}チリーンナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}チリーンに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chimechite,
        .iconPalette = gItemIconPalette_Chimechite,
    },

    [ITEM_ABSOLITE_Z] =
    {
        .name = ITEM_NAME("{JPN}アブソルナイトZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbsoliteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AbsoliteZ,
        .iconPalette = gItemIconPalette_AbsoliteZ,
    },

    [ITEM_STARAPTITE] =
    {
        .name = ITEM_NAME("{JPN}ムクホークナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ムクホークに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Staraptite,
        .iconPalette = gItemIconPalette_Staraptite,
    },

    [ITEM_GARCHOMPITE_Z] =
    {
        .name = ITEM_NAME("{JPN}ガブリアスナイトZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGarchompiteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_GarchompiteZ,
        .iconPalette = gItemIconPalette_GarchompiteZ,
    },

    [ITEM_LUCARIONITE_Z] =
    {
        .name = ITEM_NAME("{JPN}ルカリオナイトZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLucarioniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_LucarioniteZ,
        .iconPalette = gItemIconPalette_LucarioniteZ,
    },

    [ITEM_GOLURKITE] =
    {
        .name = ITEM_NAME("{JPN}ゴルーグナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ゴルーグに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golurkite,
        .iconPalette = gItemIconPalette_Golurkite,
    },

    [ITEM_MEOWSTICITE] =
    {
        .name = ITEM_NAME("{JPN}ニャオニクスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ニャオニクスに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meowsticite,
        .iconPalette = gItemIconPalette_Meowsticite,
    },

    [ITEM_CRABOMINITE] =
    {
        .name = ITEM_NAME("{JPN}ケケンカニナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ケケンカニに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Crabominite,
        .iconPalette = gItemIconPalette_Crabominite,
    },

    [ITEM_GOLISOPITE] =
    {
        .name = ITEM_NAME("{JPN}グソクムシャナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}グソクムシャに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golisopite,
        .iconPalette = gItemIconPalette_Golisopite,
    },

    [ITEM_MAGEARNITE] =
    {
        .name = ITEM_NAME("{JPN}マギアナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}マギアナに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Magearnite,
        .iconPalette = gItemIconPalette_Magearnite,
    },

    [ITEM_SCOVILLAINITE] =
    {
        .name = ITEM_NAME("{JPN}スコヴィラナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}スコヴィランに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scovillainite,
        .iconPalette = gItemIconPalette_Scovillainite,
    },

    [ITEM_BAXCALIBRITE] =
    {
        .name = ITEM_NAME("{JPN}セグレイブナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}セグレイブに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Baxcalibrite,
        .iconPalette = gItemIconPalette_Baxcalibrite,
    },

    [ITEM_TATSUGIRINITE] =
    {
        .name = ITEM_NAME("{JPN}シャリタツナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}シャリタツに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tatsugirinite,
        .iconPalette = gItemIconPalette_Tatsugirinite,
    },

    [ITEM_GLIMMORANITE] =
    {
        .name = ITEM_NAME("{JPN}キラフロルナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}キラフロルに もたせると\n{JPN}せんとうちゅうに\n{JPN}メガシンカ できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glimmoranite,
        .iconPalette = gItemIconPalette_Glimmoranite,
    },

// Gems
    #if I_PRICE >= GEN_9
        #define GEM_PRICE 15000
    #elif I_PRICE >= GEN_7
        #define GEM_PRICE 4000
    #else
        #define GEM_PRICE 200
    #endif

    [ITEM_NORMAL_GEM] =
    {
        .name = ITEM_NAME("{JPN}ノーマルジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}ノーマルの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_NormalGem,
    },

    [ITEM_FIRE_GEM] =
    {
        .name = ITEM_NAME("{JPN}ほのおのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}ほのおの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FireGem,
    },

    [ITEM_WATER_GEM] =
    {
        .name = ITEM_NAME("{JPN}みずのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}みずの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_WaterGem,
    },

    [ITEM_ELECTRIC_GEM] =
    {
        .name = ITEM_NAME("{JPN}でんきのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}でんきの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_ElectricGem,
    },

    [ITEM_GRASS_GEM] =
    {
        .name = ITEM_NAME("{JPN}くさのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}くさの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GrassGem,
    },

    [ITEM_ICE_GEM] =
    {
        .name = ITEM_NAME("{JPN}こおりのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}こおりの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_IceGem,
    },

    [ITEM_FIGHTING_GEM] =
    {
        .name = ITEM_NAME("{JPN}かくとうジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}かくとうの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FightingGem,
    },

    [ITEM_POISON_GEM] =
    {
        .name = ITEM_NAME("{JPN}どくのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}どくの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PoisonGem,
    },

    [ITEM_GROUND_GEM] =
    {
        .name = ITEM_NAME("{JPN}じめんのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}じめんの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GroundGem,
    },

    [ITEM_FLYING_GEM] =
    {
        .name = ITEM_NAME("{JPN}ひこうのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}ひこうの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FlyingGem,
    },

    [ITEM_PSYCHIC_GEM] =
    {
        .name = ITEM_NAME("{JPN}エスパージュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}エスパーの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PsychicGem,
    },

    [ITEM_BUG_GEM] =
    {
        .name = ITEM_NAME("{JPN}むしのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}むしの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_BugGem,
    },

    [ITEM_ROCK_GEM] =
    {
        .name = ITEM_NAME("{JPN}いわのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}いわの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_RockGem,
    },

    [ITEM_GHOST_GEM] =
    {
        .name = ITEM_NAME("{JPN}ゴーストジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}ゴーストの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GhostGem,
    },

    [ITEM_DRAGON_GEM] =
    {
        .name = ITEM_NAME("{JPN}ドラゴンジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}ドラゴンの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DragonGem,
    },

    [ITEM_DARK_GEM] =
    {
        .name = ITEM_NAME("{JPN}あくのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}あくの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DarkGem,
    },

    [ITEM_STEEL_GEM] =
    {
        .name = ITEM_NAME("{JPN}はがねのジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}はがねの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_SteelGem,
    },

    [ITEM_FAIRY_GEM] =
    {
        .name = ITEM_NAME("{JPN}ようせいジュエル{ENG}"),
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}もたせると いちどだけ\n{JPN}フェアリーの わざの\n{JPN}いりょくが つよまる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FairyGem,
    },

// Z-Crystals

    [ITEM_NORMALIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ノーマルZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ノーマルタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_NormaliumZ,
        .iconPalette = gItemIconPalette_NormaliumZ,
    },

    [ITEM_FIRIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ホノオZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ほのおタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_FiriumZ,
        .iconPalette = gItemIconPalette_FiriumZ,
    },

    [ITEM_WATERIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ミズZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}みずタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_WateriumZ,
        .iconPalette = gItemIconPalette_WateriumZ,
    },

    [ITEM_ELECTRIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}デンキZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}でんきタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_ElectriumZ,
        .iconPalette = gItemIconPalette_ElectriumZ,
    },

    [ITEM_GRASSIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}クサZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}くさタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_GrassiumZ,
        .iconPalette = gItemIconPalette_GrassiumZ,
    },

    [ITEM_ICIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}コオリZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}こおりタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_IciumZ,
        .iconPalette = gItemIconPalette_IciumZ,
    },

    [ITEM_FIGHTINIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}カクトウZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}かくとうタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_FightiniumZ,
        .iconPalette = gItemIconPalette_FightiniumZ,
    },

    [ITEM_POISONIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ドクZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}どくタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_PoisoniumZ,
        .iconPalette = gItemIconPalette_PoisoniumZ,
    },

    [ITEM_GROUNDIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ジメンZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}じめんタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_GroundiumZ,
        .iconPalette = gItemIconPalette_GroundiumZ,
    },

    [ITEM_FLYINIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ヒコウZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ひこうタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_FlyiniumZ,
        .iconPalette = gItemIconPalette_FlyiniumZ,
    },

    [ITEM_PSYCHIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}エスパーZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}エスパータイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_PsychiumZ,
        .iconPalette = gItemIconPalette_PsychiumZ,
    },

    [ITEM_BUGINIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ムシZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}むしタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_BuginiumZ,
        .iconPalette = gItemIconPalette_BuginiumZ,
    },

    [ITEM_ROCKIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}イワZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}いわタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_RockiumZ,
        .iconPalette = gItemIconPalette_RockiumZ,
    },

    [ITEM_GHOSTIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ゴーストZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ゴーストタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_GhostiumZ,
        .iconPalette = gItemIconPalette_GhostiumZ,
    },

    [ITEM_DRAGONIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ドラゴンZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ドラゴンタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_DragoniumZ,
        .iconPalette = gItemIconPalette_DragoniumZ,
    },

    [ITEM_DARKINIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}アクZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}あくタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_DarkiniumZ,
        .iconPalette = gItemIconPalette_DarkiniumZ,
    },

    [ITEM_STEELIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ハガネZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}はがねタイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_SteeliumZ,
        .iconPalette = gItemIconPalette_SteeliumZ,
    },

    [ITEM_FAIRIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}フェアリーZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}フェアリータイプの\n{JPN}わざを Zワザに\n{JPN}グレードアップする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_FairiumZ,
        .iconPalette = gItemIconPalette_FairiumZ,
    },

    [ITEM_PIKANIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ピカチュウZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ピカチュウの\n{JPN}ボルテッカーを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikaniumZ,
        .iconPalette = gItemIconPalette_PikaniumZ,
    },

    [ITEM_EEVIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}イーブイZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}イーブイの\n{JPN}とっておきを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_EeviumZ,
        .iconPalette = gItemIconPalette_EeviumZ,
    },

    [ITEM_SNORLIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}カビゴンZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}カビゴンの\n{JPN}ギガインパクトを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SnorliumZ,
        .iconPalette = gItemIconPalette_SnorliumZ,
    },

    [ITEM_MEWNIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ミュウZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ミュウの\n{JPN}サイコキネシスを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MewniumZ,
        .iconPalette = gItemIconPalette_MewniumZ,
    },

    [ITEM_DECIDIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ジュナイパーZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ジュナイパーの\n{JPN}かげぬいを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_DecidiumZ,
        .iconPalette = gItemIconPalette_DecidiumZ,
    },

    [ITEM_INCINIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ガオガエンZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ガオガエンの\n{JPN}DDラリアットを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_InciniumZ,
        .iconPalette = gItemIconPalette_InciniumZ,
    },

    [ITEM_PRIMARIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}アシレーヌZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}アシレーヌの\n{JPN}うたかたのアリアを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PrimariumZ,
        .iconPalette = gItemIconPalette_PrimariumZ,
    },

    [ITEM_LYCANIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ルガルガンZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ルガルガンの\n{JPN}ストーンエッジを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LycaniumZ,
        .iconPalette = gItemIconPalette_LycaniumZ,
    },

    [ITEM_MIMIKIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ミミッキュZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ミミッキュの\n{JPN}じゃれつくを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MimikiumZ,
        .iconPalette = gItemIconPalette_MimikiumZ,
    },

    [ITEM_KOMMONIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ジャラランガZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ジャラランガの\n{JPN}スケイルノイズを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_KommoniumZ,
        .iconPalette = gItemIconPalette_KommoniumZ,
    },

    [ITEM_TAPUNIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}カプZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}カプたちの\n{JPN}しぜんのいかりを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  //signature z move
        .iconPic = gItemIcon_TapuniumZ,
        .iconPalette = gItemIconPalette_TapuniumZ,
    },

    [ITEM_SOLGANIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ソルガレオZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ソルガレオの\n{JPN}メテオドライブを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SolganiumZ,
        .iconPalette = gItemIconPalette_SolganiumZ,
    },

    [ITEM_LUNALIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ルナアーラZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}ルナアーラの\n{JPN}シャドーレイを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LunaliumZ,
        .iconPalette = gItemIconPalette_LunaliumZ,
    },

    [ITEM_MARSHADIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}マーシャドーZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}マーシャドーの\n{JPN}シャドースチールを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MarshadiumZ,
        .iconPalette = gItemIconPalette_MarshadiumZ,
    },

    [ITEM_ALORAICHIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}アロライZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}アローラ ライチュウの\n{JPN}10まんボルトを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_AloraichiumZ,
        .iconPalette = gItemIconPalette_AloraichiumZ,
    },

    [ITEM_PIKASHUNIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}サトピカZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}サトシの ピカチュウの\n{JPN}10まんボルトを\n{JPN}Zワザに する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikashuniumZ,
        .iconPalette = gItemIconPalette_PikashuniumZ,
    },

    [ITEM_ULTRANECROZIUM_Z] =
    {
        .name = ITEM_NAME("{JPN}ウルトラネクロZ{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
            "{JPN}がったいした\n{JPN}ネクロズマを あらたな\n{JPN}すがたにする けっしょう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255, //signature z move
        .iconPic = gItemIcon_UltranecroziumZ,
        .iconPalette = gItemIconPalette_UltranecroziumZ,
    },

// Species-specific Held Items

    [ITEM_LIGHT_BALL] =
    {
        .name = ITEM_NAME("{JPN}でんきだま{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = COMPOUND_STRING(
            "{JPN}ピカチュウに もたせると\n{JPN}こうげきと とくこうが\n{JPN}あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightBall,
        .iconPalette = gItemIconPalette_LightBall,
    },

    [ITEM_LEEK] =
    {
        .name = ITEM_NAME("{JPN}ながねぎ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .holdEffect = HOLD_EFFECT_LEEK,
        .description = COMPOUND_STRING(
            "{JPN}カモネギに もたせると\n{JPN}きゅうしょに\n{JPN}あたりやすくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_Leek,
        .iconPalette = gItemIconPalette_Leek,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = ITEM_NAME("{JPN}ふといホネ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = COMPOUND_STRING(
            "{JPN}カラカラや ガラガラに\n{JPN}もたせると こうげきの\n{JPN}いりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = ITEM_NAME("{JPN}ラッキーパンチ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ラッキーパンチ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = COMPOUND_STRING(
            "{JPN}ラッキーに もたせると\n{JPN}きゅうしょに\n{JPN}あたりやすくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_LuckyPunch,
        .iconPalette = gItemIconPalette_LuckyPunch,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = ITEM_NAME("{JPN}メタルパウダー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = COMPOUND_STRING(
            "{JPN}メタモンに もたせると\n{JPN}ぼうぎょが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_MetalPowder,
    },

    [ITEM_QUICK_POWDER] =
    {
        .name = ITEM_NAME("{JPN}スピードパウダー{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = COMPOUND_STRING(
            "{JPN}メタモンに もたせると\n{JPN}すばやさが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_QuickPowder,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = ITEM_NAME("{JPN}しんかいのウロコ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = COMPOUND_STRING(
            "{JPN}にぶく ひかる ウロコ\n{JPN}パールルに もたせると\n{JPN}とくぼうが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DeepSeaScale,
        .iconPalette = gItemIconPalette_DeepSeaScale,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = ITEM_NAME("{JPN}しんかいのキバ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}しんかいのキバ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = COMPOUND_STRING(
            "{JPN}するどく ひかる キバ\n{JPN}パールルに もたせると\n{JPN}とくこうが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 90,
        .iconPic = gItemIcon_DeepSeaTooth,
        .iconPalette = gItemIconPalette_DeepSeaTooth,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = ITEM_NAME("{JPN}こころのしずく{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .holdEffectParam = B_SOUL_DEW_BOOST >= GEN_7 ? 20 : 50,
        .description = COMPOUND_STRING(
        #if B_SOUL_DEW_BOOST >= GEN_7
            "Powers up Latios' &\n"
            "Latias' Psychic and\n"
            "Dragon-type moves."),
        #else
            "Hold item: raises\n"
            "Sp. Atk & Sp. Def of\n"
            "Latios & Latias."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SoulDew,
        .iconPalette = gItemIconPalette_SoulDew,
    },

    [ITEM_ADAMANT_ORB] =
    {
        .name = ITEM_NAME("{JPN}こんごうだま{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}ディアルガに もたせると\n{JPN}ドラゴンと はがねの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantOrb,
        .iconPalette = gItemIconPalette_AdamantOrb,
    },

    [ITEM_LUSTROUS_ORB] =
    {
        .name = ITEM_NAME("{JPN}しらたま{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}パルキアに もたせると\n{JPN}ドラゴンと みずの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousOrb,
        .iconPalette = gItemIconPalette_LustrousOrb,
    },

    [ITEM_GRISEOUS_ORB] =
    {
        .name = ITEM_NAME("{JPN}はっきんだま{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}ギラティナに もたせると\n{JPN}ドラゴンと ゴーストの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousOrb,
        .iconPalette = gItemIconPalette_GriseousOrb,
    },

// Incenses

    [ITEM_SEA_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}うしおのおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = I_TYPE_BOOST_POWER >= GEN_4 ? 20 : 5,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_SeaIncense,
        .iconPalette = gItemIconPalette_SeaIncense,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}のんきのおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
    #if I_LAX_INCENSE_BOOST >= GEN_4
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}てきの わざが\n{JPN}めいちゅう しにくくなる{ENG}"),
    #else
        .holdEffectParam = 5,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせるとt\n{JPN}てきの めいちゅうりつを\n{JPN}すこしだけ さげる{ENG}"),
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaxIncense,
        .iconPalette = gItemIconPalette_LaxIncense,
    },

    [ITEM_ODD_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}あやしいおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 10,
        .iconPic = gItemIcon_OddIncense,
        .iconPalette = gItemIconPalette_OddIncense,
    },

    [ITEM_ROCK_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}がんせきおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 10,
        .iconPic = gItemIcon_RockIncense,
        .iconPalette = gItemIconPalette_RockIncense,
    },

    [ITEM_FULL_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}まんぷくおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .holdEffectParam = 5,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FullIncense,
        .iconPalette = gItemIconPalette_FullIncense,
    },

    [ITEM_WAVE_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}さざなみのおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_WaveIncense,
        .iconPalette = gItemIconPalette_WaveIncense,
    },

    [ITEM_ROSE_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}おはなのおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseIncense,
        .iconPalette = gItemIconPalette_RoseIncense,
    },

    [ITEM_LUCK_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}こううんのおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 11000 : 9600,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LuckIncense,
        .iconPalette = gItemIconPalette_LuckIncense,
    },

    [ITEM_PURE_INCENSE] =
    {
        .name = ITEM_NAME("{JPN}きよめのおこう{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 6000 : 9600,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PureIncense,
        .iconPalette = gItemIconPalette_PureIncense,
    },

// Contest Scarves

    [ITEM_RED_SCARF] =
    {
        .name = ITEM_NAME("{JPN}あかいバンダナ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}あかいバンダナ{ENG}"),
        .price = 100,
        .description = COMPOUND_STRING(
            "{JPN}もたせて コンテストに\n{JPN}さんかすると いつもより\n{JPN}かっこよく みられる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_RedScarf,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = ITEM_NAME("{JPN}あおいバンダナ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}あおいバンダナ{ENG}"),
        .price = 100,
        .description = COMPOUND_STRING(
            "{JPN}もたせて コンテストに\n{JPN}さんかすると いつもより\n{JPN}うつくしく みられる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_BlueScarf,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = ITEM_NAME("{JPN}ピンクのバンダナ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ピンクのバンダナ{ENG}"),
        .price = 100,
        .description = COMPOUND_STRING(
            "{JPN}もたせて コンテストに\n{JPN}さんかすると いつもより\n{JPN}かわいく みられる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_PinkScarf,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = ITEM_NAME("{JPN}みどりのバンダナ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}みどりのバンダナ{ENG}"),
        .price = 100,
        .description = COMPOUND_STRING(
            "{JPN}もたせて コンテストに\n{JPN}さんかすると いつもより\n{JPN}かしこく みられる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_GreenScarf,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = ITEM_NAME("{JPN}きいろのバンダナ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}きいろのバンダナ{ENG}"),
        .price = 100,
        .description = COMPOUND_STRING(
            "{JPN}もたせて コンテストに\n{JPN}さんかすると いつもより\n{JPN}たくましく みられる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_YellowScarf,
    },

// EV Gain Modifiers

    [ITEM_MACHO_BRACE] =
    {
        .name = ITEM_NAME("{JPN}きょうせいギプス{ENG}"),
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}すばやさが さがるが\n{JPN}つよく そだつ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_MachoBrace,
        .iconPalette = gItemIconPalette_MachoBrace,
    },

    [ITEM_POWER_WEIGHT] =
    {
        .name = ITEM_NAME("{JPN}パワーウエイト{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "{JPN}もたせると すばやさが\n{JPN}さがるが ポケモンの\n{JPN}HPが そだちやすい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_HP,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerWeight,
        .iconPalette = gItemIconPalette_PowerWeight,
    },

    [ITEM_POWER_BRACER] =
    {
        .name = ITEM_NAME("{JPN}パワーリスト{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "{JPN}もたせると すばやさが\n{JPN}さがるが ポケモンの\n{JPN}こうげきが そだちやすい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_ATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBracer,
        .iconPalette = gItemIconPalette_PowerBracer,
    },

    [ITEM_POWER_BELT] =
    {
        .name = ITEM_NAME("{JPN}パワーベルト{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "{JPN}もたせると すばやさが\n{JPN}さがるが ポケモンの\n{JPN}ぼうぎょが そだちやすい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_DEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBelt,
        .iconPalette = gItemIconPalette_PowerBelt,
    },

    [ITEM_POWER_LENS] =
    {
        .name = ITEM_NAME("{JPN}パワーレンズ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}パワーレンズ{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "{JPN}もたせると すばやさが\n{JPN}さがるが ポケモンの\n{JPN}とくこうが そだちやすい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerLens,
        .iconPalette = gItemIconPalette_PowerLens,
    },

    [ITEM_POWER_BAND] =
    {
        .name = ITEM_NAME("{JPN}パワーバンド{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "{JPN}もたせると すばやさが\n{JPN}さがるが ポケモンの\n{JPN}とくぼうが そだちやすい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPDEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBand,
        .iconPalette = gItemIconPalette_PowerBand,
    },

    [ITEM_POWER_ANKLET] =
    {
        .name = ITEM_NAME("{JPN}パワーアンクル{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
            "{JPN}もたせると すばやさが\n{JPN}さがるが ポケモンの\n{JPN}すばやさが そだちやすい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPEED,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerAnklet,
        .iconPalette = gItemIconPalette_PowerAnklet,
    },

// Type-boosting Held Items
    #if I_PRICE >= GEN_9
        #define TYPE_BOOSTING_PRICE 3000
    #elif I_PRICE >= GEN_7
        #define TYPE_BOOSTING_PRICE 1000
    #else
        #define TYPE_BOOSTING_PRICE 100
    #endif

    [ITEM_SILK_SCARF] =
    {
        .name = ITEM_NAME("{JPN}シルクのスカーフ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}シルクのスカーフ{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}ノーマルタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .flingPower = 10,
        .iconPic = gItemIcon_SilkScarf,
        .iconPalette = gItemIconPalette_SilkScarf,
    },

    [ITEM_CHARCOAL] =
    {
        .name = ITEM_NAME("{JPN}もくたん{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 1000,
    #else
        .price = 9800,
    #endif
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}ほのおタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 30,
        .iconPic = gItemIcon_Charcoal,
        .iconPalette = gItemIconPalette_Charcoal,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = ITEM_NAME("{JPN}しんぴのしずく{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}みずタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 30,
        .iconPic = gItemIcon_MysticWater,
        .iconPalette = gItemIconPalette_MysticWater,
    },

    [ITEM_MAGNET] =
    {
        .name = ITEM_NAME("{JPN}じしゃく{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}でんきタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 30,
        .iconPic = gItemIcon_Magnet,
        .iconPalette = gItemIconPalette_Magnet,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = ITEM_NAME("{JPN}きせきのタネ{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 30,
        .iconPic = gItemIcon_MiracleSeed,
        .iconPalette = gItemIconPalette_MiracleSeed,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = ITEM_NAME("{JPN}とけないこおり{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}こおりタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 30,
        .iconPic = gItemIcon_NeverMeltIce,
        .iconPalette = gItemIconPalette_NeverMeltIce,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = ITEM_NAME("{JPN}くろおび{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}かくとうタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackBelt,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_POISON_BARB] =
    {
        .name = ITEM_NAME("{JPN}どくバリ{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}どくタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 70,
        .iconPic = gItemIcon_PoisonBarb,
        .iconPalette = gItemIconPalette_PoisonBarb,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = ITEM_NAME("{JPN}やわらかいすな{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}やわらかいすな{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}じめんタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 10,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_SoftSand,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = ITEM_NAME("{JPN}するどいくちばし{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}ひこうタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_SharpBeak,
        .iconPalette = gItemIconPalette_SharpBeak,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = ITEM_NAME("{JPN}まがったスプーン{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 30,
        .iconPic = gItemIcon_TwistedSpoon,
        .iconPalette = gItemIconPalette_TwistedSpoon,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = ITEM_NAME("{JPN}ぎんのこな{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}むしタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 10,
        .iconPic = gItemIcon_SilverPowder,
        .iconPalette = gItemIconPalette_SilverPowder,
    },

    [ITEM_HARD_STONE] =
    {
        .name = ITEM_NAME("{JPN}かたいいし{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 100,
        .iconPic = gItemIcon_HardStone,
        .iconPalette = gItemIconPalette_HardStone,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = ITEM_NAME("{JPN}のろいのおふだ{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}ゴーストタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 30,
        .iconPic = gItemIcon_SpellTag,
        .iconPalette = gItemIconPalette_SpellTag,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = ITEM_NAME("{JPN}りゅうのキバ{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}ドラゴンタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 70,
        .iconPic = gItemIcon_DragonFang,
        .iconPalette = gItemIconPalette_DragonFang,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = ITEM_NAME("{JPN}くろいメガネ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}くろいメガネ{ENG}"),
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}あくタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackGlasses,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_METAL_COAT] =
    {
        .name = ITEM_NAME("{JPN}メタルコート{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 2000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}はがねタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .secondaryId = TYPE_STEEL,
        .flingPower = 30,
        .iconPic = gItemIcon_MetalCoat,
        .iconPalette = gItemIconPalette_MetalCoat,
    },

// Choice Items

    [ITEM_CHOICE_BAND] =
    {
        .name = ITEM_NAME("{JPN}こだわりハチマキ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = COMPOUND_STRING(
            "{JPN}こうげきの いりょくが\n{JPN}あがるが おなじ\n{JPN}わざしか だせなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceBand,
        .iconPalette = gItemIconPalette_ChoiceBand,
    },

    [ITEM_CHOICE_SPECS] =
    {
        .name = ITEM_NAME("{JPN}こだわりメガネ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}こだわりメガネ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = COMPOUND_STRING(
            "{JPN}とくこうの いりょくが\n{JPN}あがるが おなじ\n{JPN}わざしか だせなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceSpecs,
        .iconPalette = gItemIconPalette_ChoiceSpecs,
    },

    [ITEM_CHOICE_SCARF] =
    {
        .name = ITEM_NAME("{JPN}こだわりスカーフ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}こだわりスカーフ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = COMPOUND_STRING(
            "{JPN}もたせると すばやさは\n{JPN}あがるが おなじ\n{JPN}わざしか だせなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceScarf,
        .iconPalette = gItemIconPalette_ChoiceScarf,
    },

// Status Orbs

    [ITEM_FLAME_ORB] =
    {
        .name = ITEM_NAME("{JPN}かえんだま{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = COMPOUND_STRING(
            "{JPN}もたせると\n{JPN}せんとうちゅうに やけど\n{JPN}じょうたいに なる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FlameOrb,
        .iconPalette = gItemIconPalette_FlameOrb,
    },

    [ITEM_TOXIC_ORB] =
    {
        .name = ITEM_NAME("{JPN}どくどくだま{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = COMPOUND_STRING(
            "{JPN}もたせると\n{JPN}せんとうちゅうに もうどく\n{JPN}じょうたいに なる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ToxicOrb,
        .iconPalette = gItemIconPalette_ToxicOrb,
    },

// Weather Rocks

    [ITEM_DAMP_ROCK] =
    {
        .name = ITEM_NAME("{JPN}しめったいわ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンが\n{JPN}あまごいを つかうと\n{JPN}じかんが ながくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_DampRock,
        .iconPalette = gItemIconPalette_DampRock,
    },

    [ITEM_HEAT_ROCK] =
    {
        .name = ITEM_NAME("{JPN}あついいわ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンが\n{JPN}にほんばれを つかうと\n{JPN}じかんが ながくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_HeatRock,
        .iconPalette = gItemIconPalette_HeatRock,
    },

    [ITEM_SMOOTH_ROCK] =
    {
        .name = ITEM_NAME("{JPN}さらさらいわ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンが\n{JPN}すなあらしを つかうと\n{JPN}じかんが ながくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SmoothRock,
        .iconPalette = gItemIconPalette_SmoothRock,
    },

    [ITEM_ICY_ROCK] =
    {
        .name = ITEM_NAME("{JPN}つめたいいわ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
    #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンが\n{JPN}あられを つかうと\n{JPN}じかんが ながくなる{ENG}"),
    #elif B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンが\n{JPN}ゆきげしきを つかうと\n{JPN}じかんが ながくなる{ENG}"),
    #else
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンが\n{JPN}てんきを ゆきにすると\n{JPN}じかんが ながくなる{ENG}"),
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_IcyRock,
        .iconPalette = gItemIconPalette_IcyRock,
    },

// Terrain Seeds

    [ITEM_ELECTRIC_SEED] =
    {
        .name = ITEM_NAME("{JPN}エレキシード{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}エレキフィールドの ときに\n{JPN}つかって ぼうぎょアップ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_ElectricSeed,
    },

    [ITEM_PSYCHIC_SEED] =
    {
        .name = ITEM_NAME("{JPN}サイコシード{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}サイコフィールドの ときに\n{JPN}つかって とくぼうアップ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_PsychicSeed,
    },

    [ITEM_MISTY_SEED] =
    {
        .name = ITEM_NAME("{JPN}ミストシード{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_MISTY_TERRAIN,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}ミストフィールドの ときに\n{JPN}つかって とくぼうアップ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_MistySeed,
    },

    [ITEM_GRASSY_SEED] =
    {
        .name = ITEM_NAME("{JPN}グラスシード{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_GRASSY_TERRAIN,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}グラスフィールドの ときに\n{JPN}つかって ぼうぎょアップ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_GrassySeed,
    },

// Type-activated Stat Modifiers

    [ITEM_ABSORB_BULB] =
    {
        .name = ITEM_NAME("{JPN}きゅうこん{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ABSORB_BULB,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}もたせて みずの\n{JPN}わざを うけると\n{JPN}とくこうが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbsorbBulb,
        .iconPalette = gItemIconPalette_AbsorbBulb,
    },

    [ITEM_CELL_BATTERY] =
    {
        .name = ITEM_NAME("{JPN}じゅうでんち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}じゅうでんち{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CELL_BATTERY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}もたせて でんきの\n{JPN}わざを うけると\n{JPN}こうげきが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CellBattery,
        .iconPalette = gItemIconPalette_CellBattery,
    },

    [ITEM_LUMINOUS_MOSS] =
    {
        .name = ITEM_NAME("{JPN}ひかりごけ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ひかりごけ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}もたせて みずの\n{JPN}わざを うけると\n{JPN}とくぼうが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuminousMoss,
        .iconPalette = gItemIconPalette_LuminousMoss,
    },

    [ITEM_SNOWBALL] =
    {
        .name = ITEM_NAME("{JPN}ゆきだま{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SNOWBALL,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}もたせて こおりの\n{JPN}わざを うけると\n{JPN}こうげきが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Snowball,
        .iconPalette = gItemIconPalette_Snowball,
    },

// Misc. Held Items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = ITEM_NAME("{JPN}ひかりのこな{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 10,
    #endif
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ひかりが\n{JPN}あいてを まどわして\n{JPN}めいちゅうりつを さげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BrightPowder,
        .iconPalette = gItemIconPalette_BrightPowder,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = ITEM_NAME("{JPN}しろいハーブ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_WHITE_HERB,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}さがった のうりょくを\n{JPN}もとにもどす{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_WhiteHerb,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = ITEM_NAME("{JPN}がくしゅうそうち{ENG}"),
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
    #if I_EXP_SHARE_ITEM >= GEN_6
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}てもちのほかのポケモンにも\nけいけんちをあたえるそうち\n。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
    #else
        .price = (I_PRICE == GEN_1) ? 1 : 3000,
        .description = COMPOUND_STRING(
            "{JPN}もたせるとせんとうのけいけ\nんちをもらえる。{ENG}"),
        .pocket = POCKET_ITEMS,
    #endif
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_ExpShare,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpShare,
        .iconPalette = gItemIconPalette_ExpShare,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = ITEM_NAME("{JPN}せんせいのツメ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}せんせい こうげきが\n{JPN}たまに できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_QuickClaw,
        .iconPalette = gItemIconPalette_QuickClaw,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = ITEM_NAME("{JPN}やすらぎのすず{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ポケモンが\n{JPN}とっても やすらいで\n{JPN}なつき やすくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SootheBell,
        .iconPalette = gItemIconPalette_SootheBell,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = ITEM_NAME("{JPN}メンタルハーブ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_MENTAL_HERB,
        .description = COMPOUND_STRING(
        #if B_MENTAL_HERB >= GEN_5
            "Snaps Pokémon out\n"
            "of move-binding\n"
            "effects."),
        #else
            "A hold item that\n"
            "snaps Pokémon out\n"
            "of infatuation."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_MentalHerb,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = ITEM_NAME("{JPN}おうじゃのしるし{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_KingsRock,
        .iconPalette = gItemIconPalette_KingsRock,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = ITEM_NAME("{JPN}おまもりこばん{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AmuletCoin,
        .iconPalette = gItemIconPalette_AmuletCoin,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = ITEM_NAME("{JPN}きよめのおふだ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 5000 : 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CleanseTag,
        .iconPalette = gItemIconPalette_CleanseTag,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = ITEM_NAME("{JPN}けむりだま{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = COMPOUND_STRING(
            "{JPN}そうぐうした やせいの\n{JPN}ポケモンから かならず\n{JPN}にげられる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SmokeBall,
        .iconPalette = gItemIconPalette_SmokeBall,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = ITEM_NAME("{JPN}きあいのハチマキ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}たまに ひんしを\n{JPN}ふせぐことが できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusBand,
        .iconPalette = gItemIconPalette_FocusBand,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = ITEM_NAME("{JPN}しあわせタマゴ{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 10000 : 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンの\n{JPN}けいけんちが いつもより\n{JPN}おおめに もらえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuckyEgg,
        .iconPalette = gItemIconPalette_LuckyEgg,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = ITEM_NAME("{JPN}ピントレンズ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ピントレンズ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}きゅうしょに\n{JPN}あたり やすくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ScopeLens,
        .iconPalette = gItemIconPalette_ScopeLens,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = ITEM_NAME("{JPN}たべのこし{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}たべのこし{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}もたせると たいりょくが\n{JPN}せんとうの あいだ\n{JPN}すこしずつ かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Leftovers,
        .iconPalette = gItemIconPalette_Leftovers,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = ITEM_NAME("{JPN}かいがらのすず{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING(
            "{JPN}もたせると てきに\n{JPN}ダメージを あたえたとき\n{JPN}たいりょくが かいふく{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShellBell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_WIDE_LENS] =
    {
        .name = ITEM_NAME("{JPN}こうかくレンズ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}こうかくレンズ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}もたせると\n{JPN}わざの めいちゅうりつが\n{JPN}すこし あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WideLens,
        .iconPalette = gItemIconPalette_WideLens,
    },

    [ITEM_MUSCLE_BAND] =
    {
        .name = ITEM_NAME("{JPN}ちからのハチマキ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}ぶつりわざの\n{JPN}いりょくが すこし\n{JPN}あがる メガネ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MuscleBand,
        .iconPalette = gItemIconPalette_MuscleBand,
    },

    [ITEM_WISE_GLASSES] =
    {
        .name = ITEM_NAME("{JPN}ものしりメガネ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ものしりメガネ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}とくしゅわざの\n{JPN}いりょくが すこし\n{JPN}あがる メガネ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WiseGlasses,
        .iconPalette = gItemIconPalette_WiseGlasses,
    },

    [ITEM_EXPERT_BELT] =
    {
        .name = ITEM_NAME("{JPN}たつじんのおび{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}こうかばつぐんの\n{JPN}ときの いりょくが\n{JPN}すこし あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ExpertBelt,
        .iconPalette = gItemIconPalette_ExpertBelt,
    },

    [ITEM_LIGHT_CLAY] =
    {
        .name = ITEM_NAME("{JPN}ひかりのねんど{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = COMPOUND_STRING(
            "{JPN}ひかりのかべや\n{JPN}リフレクターの こうかを\n{JPN}いつもより ながく する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightClay,
        .iconPalette = gItemIconPalette_LightClay,
    },

    [ITEM_LIFE_ORB] =
    {
        .name = ITEM_NAME("{JPN}いのちのたま{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = COMPOUND_STRING(
            "{JPN}こうげきする たびに\n{JPN}HPが へってしまうが\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LifeOrb,
        .iconPalette = gItemIconPalette_LifeOrb,
    },

    [ITEM_POWER_HERB] =
    {
        .name = ITEM_NAME("{JPN}パワフルハーブ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = COMPOUND_STRING(
            "{JPN}いちどだけ 1ターンめに\n{JPN}ちからを ためるわざを\n{JPN}すぐに つかえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PowerHerb,
        .iconPalette = gItemIconPalette_PowerHerb,
    },

    [ITEM_FOCUS_SASH] =
    {
        .name = ITEM_NAME("{JPN}きあいのタスキ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}きあいのタスキ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = COMPOUND_STRING(
            "{JPN}HPまんたんならひんしにな\nるわざもうけてもHP1でた\nえる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusSash,
        .iconPalette = gItemIconPalette_FocusSash,
    },

    [ITEM_ZOOM_LENS] =
    {
        .name = ITEM_NAME("{JPN}フォーカスレンズ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}フォーカスレンズ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}てきよりも こうどうが\n{JPN}おそいとき わざが\n{JPN}めいちゅう しやすくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ZoomLens,
        .iconPalette = gItemIconPalette_ZoomLens,
    },

    [ITEM_METRONOME] =
    {
        .name = ITEM_NAME("{JPN}メトロノーム{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}おなじわざを れんぞくで\n{JPN}つかったとき いりょくが\n{JPN}あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Metronome,
        .iconPalette = gItemIconPalette_Metronome,
    },

    [ITEM_IRON_BALL] =
    {
        .name = ITEM_NAME("{JPN}くろいてっきゅう{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = COMPOUND_STRING(
            "{JPN}すばやさが さがり\n{JPN}じめんわざが\n{JPN}あたって しまう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 130,
        .iconPic = gItemIcon_IronBall,
        .iconPalette = gItemIconPalette_IronBall,
    },

    [ITEM_LAGGING_TAIL] =
    {
        .name = ITEM_NAME("{JPN}こうこうのしっぽ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaggingTail,
        .iconPalette = gItemIconPalette_LaggingTail,
    },

    [ITEM_DESTINY_KNOT] =
    {
        .name = ITEM_NAME("{JPN}あかいいと{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = COMPOUND_STRING(
            "{JPN}もたせると メロメロに\n{JPN}なったとき あいても\n{JPN}メロメロに できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DestinyKnot,
        .iconPalette = gItemIconPalette_DestinyKnot,
    },

    [ITEM_BLACK_SLUDGE] =
    {
        .name = ITEM_NAME("{JPN}くろいヘドロ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = COMPOUND_STRING(
            "{JPN}もたせると どくタイプの\n{JPN}ポケモンは すこしずつ\n{JPN}HPを かいふくする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackSludge,
        .iconPalette = gItemIconPalette_BlackSludge,
    },

    [ITEM_GRIP_CLAW] =
    {
        .name = ITEM_NAME("{JPN}ねばりのかぎづめ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ダメージを\n{JPN}あたえつづける わざの\n{JPN}ターンすうが ふえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_GripClaw,
        .iconPalette = gItemIconPalette_GripClaw,
    },

    [ITEM_STICKY_BARB] =
    {
        .name = ITEM_NAME("{JPN}くっつきバリ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = COMPOUND_STRING(
            "{JPN}まいターン ダメージを\n{JPN}うける じぶんにふれた\n{JPN}あいてに くっつく{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_StickyBarb,
        .iconPalette = gItemIconPalette_StickyBarb,
    },

    [ITEM_SHED_SHELL] =
    {
        .name = ITEM_NAME("{JPN}きれいなぬけがら{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンは\n{JPN}ひかえの ポケモンと\n{JPN}かならず いれかわれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShedShell,
        .iconPalette = gItemIconPalette_ShedShell,
    },

    [ITEM_BIG_ROOT] =
    {
        .name = ITEM_NAME("{JPN}おおきなねっこ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "{JPN}HPを すいとる わざで\n{JPN}いつもより おおく\n{JPN}HPを かいふくできる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BigRoot,
        .iconPalette = gItemIconPalette_BigRoot,
    },

    [ITEM_RAZOR_CLAW] =
    {
        .name = ITEM_NAME("{JPN}するどいツメ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
            "{JPN}もたせると\n{JPN}わざが きゅうしょに\n{JPN}あたりやすくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_RazorClaw,
        .iconPalette = gItemIconPalette_RazorClaw,
    },

    [ITEM_RAZOR_FANG] =
    {
        .name = ITEM_NAME("{JPN}するどいキバ{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_RazorFang,
        .iconPalette = gItemIconPalette_RazorFang,
    },

    [ITEM_EVIOLITE] =
    {
        .name = ITEM_NAME("{JPN}しんかのきせき{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "{JPN}もたせると しんかまえ\n{JPN}ポケモンの ぼうぎょと\n{JPN}とくぼうが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_Eviolite,
        .iconPalette = gItemIconPalette_Eviolite,
    },

    [ITEM_FLOAT_STONE] =
    {
        .name = ITEM_NAME("{JPN}かるいし{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = COMPOUND_STRING(
            "{JPN}もたせると\n{JPN}ポケモンの たいじゅうが\n{JPN}かるくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FloatStone,
        .iconPalette = gItemIconPalette_FloatStone,
    },

    [ITEM_ROCKY_HELMET] =
    {
        .name = ITEM_NAME("{JPN}ゴツゴツメット{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}だげきわざを\n{JPN}うけたとき あいてにも\n{JPN}ダメージを あたえる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_RockyHelmet,
        .iconPalette = gItemIconPalette_RockyHelmet,
    },

    [ITEM_AIR_BALLOON] =
    {
        .name = ITEM_NAME("{JPN}ふうせん{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_AIR_BALLOON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが ちゅうにうく\n{JPN}こうげきを うけると\n{JPN}われてしまう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AirBalloon,
        .iconPalette = gItemIconPalette_AirBalloon,
    },

    [ITEM_RED_CARD] =
    {
        .name = ITEM_NAME("{JPN}レッドカード{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RED_CARD,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}わざをつかってきた\n{JPN}あいてを たいじょう\n{JPN}させることが できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RedCard,
        .iconPalette = gItemIconPalette_RedCard,
    },

    [ITEM_RING_TARGET] =
    {
        .name = ITEM_NAME("{JPN}ねらいのまと{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RING_TARGET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}タイプあいしょうで\n{JPN}むこう だった わざが\n{JPN}あたってしまう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RingTarget,
        .iconPalette = gItemIconPalette_RingTarget,
    },

    [ITEM_BINDING_BAND] =
    {
        .name = ITEM_NAME("{JPN}しめつけバンド{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = COMPOUND_STRING(
            "{JPN}もたせると しめつける\n{JPN}わざの いりょくが\n{JPN}つよく なる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BindingBand,
        .iconPalette = gItemIconPalette_BindingBand,
    },

    [ITEM_EJECT_BUTTON] =
    {
        .name = ITEM_NAME("{JPN}だっしゅつボタン{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}わざを うけると {JPN}せんとう\nから だっしゅつして {JPN}ても\nちと いれかわる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_EjectButton,
        .iconPalette = gItemIconPalette_EjectButton,
    },

    [ITEM_WEAKNESS_POLICY] =
    {
        .name = ITEM_NAME("{JPN}じゃくてんほけん{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}じゃくてんほけん{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
            "{JPN}じゃくてんを つかれると\n{JPN}こうげきと とくこうが\n{JPN}それぞれ ぐーんと あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_WeaknessPolicy,
        .iconPalette = gItemIconPalette_WeaknessPolicy,
    },

    [ITEM_ASSAULT_VEST] =
    {
        .name = ITEM_NAME("{JPN}とつげきチョッキ{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
            "{JPN}もたせると\n{JPN}とくぼうが あがるが\n{JPN}へんかわざを だせなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AssaultVest,
        .iconPalette = gItemIconPalette_AssaultVest,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
        .name = ITEM_NAME("{JPN}ぼうじんゴーグル{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ぼうじんゴーグル{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_SAFETY_GOGGLES,
        .description = COMPOUND_STRING(
            "{JPN}てんこうダメージだけでなく\n{JPN}こなをだす わざの\n{JPN}こうかも ふせぐ ゴーグル{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_SafetyGoggles,
        .iconPalette = gItemIconPalette_SafetyGoggles,
    },

    [ITEM_ADRENALINE_ORB] =
    {
        .name = ITEM_NAME("{JPN}ビビリだま{ENG}"),
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE == GEN_8
        .price = 4000,
    #else
        .price = 300,
    #endif
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = COMPOUND_STRING(
            "{JPN}もたせると\n{JPN}いかくを うけたとき\n{JPN}すばやさが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AdrenalineOrb,
        .iconPalette = gItemIconPalette_AdrenalineOrb,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
        .name = ITEM_NAME("{JPN}グランドコート{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = COMPOUND_STRING(
            "{JPN}フィールドを\n{JPN}はったとき いつもよりも\n{JPN}ながく のこる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_TerrainExtender,
        .iconPalette = gItemIconPalette_TerrainExtender,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
        .name = ITEM_NAME("{JPN}ぼうごパット{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ぼうごパット{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = COMPOUND_STRING(
            "{JPN}こうげき する てきに\n{JPN}さわってうける こうかを\n{JPN}うけないように する{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ProtectivePads,
        .iconPalette = gItemIconPalette_ProtectivePads,
    },

    [ITEM_THROAT_SPRAY] =
    {
        .name = ITEM_NAME("{JPN}のどスプレー{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_THROAT_SPRAY,
        .description = COMPOUND_STRING(
            "{JPN}おとに かんする\n{JPN}わざを つかうと\n{JPN}とくこうが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ThroatSpray,
        .iconPalette = gItemIconPalette_ThroatSpray,
    },

    [ITEM_EJECT_PACK] =
    {
        .name = ITEM_NAME("{JPN}だっしゅつパック{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_EJECT_PACK,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンの\n{JPN}のうりょくが さがると\n{JPN}てもちと いれかわる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
        .iconPic = gItemIcon_EjectPack,
        .iconPalette = gItemIconPalette_EjectPack,
    },

    [ITEM_HEAVY_DUTY_BOOTS] =
    {
        .name = ITEM_NAME("{JPN}あつぞこブーツ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}あつぞこブーツ{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_HEAVY_DUTY_BOOTS,
        .description = COMPOUND_STRING(
            "{JPN}あしばに しかけられた\n{JPN}わななどの えいきょうを\n{JPN}うけなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_HeavyDutyBoots,
        .iconPalette = gItemIconPalette_HeavyDutyBoots,
    },

    [ITEM_BLUNDER_POLICY] =
    {
        .name = ITEM_NAME("{JPN}からぶりほけん{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}からぶりほけん{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_BLUNDER_POLICY,
        .description = COMPOUND_STRING(
            "{JPN}めいちゅうりつに よって {JPN}\nわざが はずれたとき {JPN}すば\nやさが ぐーんと あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_BlunderPolicy,
        .iconPalette = gItemIconPalette_BlunderPolicy,
    },

    [ITEM_ROOM_SERVICE] =
    {
        .name = ITEM_NAME("{JPN}ルームサービス{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_ROOM_SERVICE,
        .description = COMPOUND_STRING(
            "{JPN}めいちゅうりつに よって \n{JPN}わざが はずれたとき\n{JPN}すばやさが ぐーんとあがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RoomService,
        .iconPalette = gItemIconPalette_RoomService,
    },

    [ITEM_UTILITY_UMBRELLA] =
    {
        .name = ITEM_NAME("{JPN}ばんのうがさ{ENG}"),
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_UTILITY_UMBRELLA,
        .description = COMPOUND_STRING(
            "{JPN}もたせた ポケモンは\n{JPN}あめと にほんばれの\n{JPN}えいきょうを うけなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_UtilityUmbrella,
        .iconPalette = gItemIconPalette_UtilityUmbrella,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = ITEM_NAME("{JPN}クラボのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}クラボのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}まひ じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_CheriBerry,
        .iconPalette = gItemIconPalette_CheriBerry,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = ITEM_NAME("{JPN}カゴのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}カゴのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}ねむり じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 10,
        .iconPic = gItemIcon_ChestoBerry,
        .iconPalette = gItemIconPalette_ChestoBerry,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}モモンのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}モモンのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}どく じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 10,
        .iconPic = gItemIcon_PechaBerry,
        .iconPalette = gItemIconPalette_PechaBerry,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = ITEM_NAME("{JPN}チーゴのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}チーゴのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}やけど じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_RawstBerry,
        .iconPalette = gItemIconPalette_RawstBerry,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ナナシのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ナナシのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}こおり じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_AspearBerry,
        .iconPalette = gItemIconPalette_AspearBerry,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ヒメリのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ヒメリのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}わざポイントを\n{JPN}10 かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_LeppaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_LeppaBerry,
        .iconPalette = gItemIconPalette_LeppaBerry,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = ITEM_NAME("{JPN}オレンのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}オレンのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}たいりょくを\n{JPN}10 かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_OranBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_OranBerry,
        .iconPalette = gItemIconPalette_OranBerry,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = ITEM_NAME("{JPN}キーのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}キーのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}こんらん じょうたいを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_PersimBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PersimBerry,
        .iconPalette = gItemIconPalette_PersimBerry,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ラムのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ラムのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}じょうたいを いじょうを\n{JPN}かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_LumBerry,
        .iconPalette = gItemIconPalette_LumBerry,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = ITEM_NAME("{JPN}オボンのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}オボンのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
    #if I_SITRUS_BERRY_HEAL >= GEN_4
        .holdEffect = HOLD_EFFECT_RESTORE_PCT_HP,
        .holdEffectParam = 25,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}たいりょくを\n{JPN}すこしだけ かいふくする{ENG}"),
    #else
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
            "{JPN}もたせると じぶんで\n{JPN}たいりょくを\n{JPN}30 かいふくする{ENG}"),
    #endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SitrusBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_SitrusBerry,
        .iconPalette = gItemIconPalette_SitrusBerry,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = ITEM_NAME("{JPN}フィラのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}フィラのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FigyBerry,
        .iconPalette = gItemIconPalette_FigyBerry,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ウイのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ウイのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WikiBerry,
        .iconPalette = gItemIconPalette_WikiBerry,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = ITEM_NAME("{JPN}マゴのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}マゴのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagoBerry,
        .iconPalette = gItemIconPalette_MagoBerry,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = ITEM_NAME("{JPN}バンジのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}バンジのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AguavBerry,
        .iconPalette = gItemIconPalette_AguavBerry,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}イアのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}イアのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_IapapaBerry,
        .iconPalette = gItemIconPalette_IapapaBerry,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ズリのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ズリのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとズリのみがそだ\nつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RazzBerry,
        .iconPalette = gItemIconPalette_RazzBerry,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ブリーのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ブリーのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとブリーのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BlukBerry,
        .iconPalette = gItemIconPalette_BlukBerry,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ナナのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ナナのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとナナのみがそだ\nつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NanabBerry,
        .iconPalette = gItemIconPalette_NanabBerry,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = ITEM_NAME("{JPN}セシナのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}セシナのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとセシナのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WepearBerry,
        .iconPalette = gItemIconPalette_WepearBerry,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = ITEM_NAME("{JPN}パイルのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}パイルのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとパイルのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PinapBerry,
        .iconPalette = gItemIconPalette_PinapBerry,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ザロクのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ザロクのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが ちょっと\n{JPN}なつくが HPの\n{JPN}きそポイントが さがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_PomegBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PomegBerry,
        .iconPalette = gItemIconPalette_PomegBerry,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ネコブのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ネコブのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが ちょっと\n{JPN}なつくが こうげきの\n{JPN}きそポイントが さがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_KelpsyBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_KelpsyBerry,
        .iconPalette = gItemIconPalette_KelpsyBerry,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = ITEM_NAME("{JPN}タポルのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}タポルのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが ちょっと\n{JPN}なつくが ぼうぎょの\n{JPN}きそポイントが さがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_QualotBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_QualotBerry,
        .iconPalette = gItemIconPalette_QualotBerry,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ロメのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ロメのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが ちょっと\n{JPN}なつくが とくこうの\n{JPN}きそポイントが さがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_HondewBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_HondewBerry,
        .iconPalette = gItemIconPalette_HondewBerry,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ウブのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ウブのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが ちょっと\n{JPN}なつくが とくぼうの\n{JPN}きそポイントが さがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_GrepaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_GrepaBerry,
        .iconPalette = gItemIconPalette_GrepaBerry,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = ITEM_NAME("{JPN}マトマのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}マトマのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが ちょっと\n{JPN}なつくが すばやさの\n{JPN}きそポイントが さがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_TamatoBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_TamatoBerry,
        .iconPalette = gItemIconPalette_TamatoBerry,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = ITEM_NAME("{JPN}モコシのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}モコシのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとモコシのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CornnBerry,
        .iconPalette = gItemIconPalette_CornnBerry,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ゴスのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ゴスのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとゴスのみがそだ\nつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagostBerry,
        .iconPalette = gItemIconPalette_MagostBerry,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ラブタのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ラブタのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとラブタのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RabutaBerry,
        .iconPalette = gItemIconPalette_RabutaBerry,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ノメルのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ノメルのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとノメルのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NomelBerry,
        .iconPalette = gItemIconPalette_NomelBerry,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ノワキのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ノワキのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとノワキのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SpelonBerry,
        .iconPalette = gItemIconPalette_SpelonBerry,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = ITEM_NAME("{JPN}シーヤのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}シーヤのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとシーヤのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PamtreBerry,
        .iconPalette = gItemIconPalette_PamtreBerry,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = ITEM_NAME("{JPN}カイスのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}カイスのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとカイスのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WatmelBerry,
        .iconPalette = gItemIconPalette_WatmelBerry,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ドリのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ドリのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとドリのみがそだ\nつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DurinBerry,
        .iconPalette = gItemIconPalette_DurinBerry,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ベリブのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ベリブのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとベリブのみがそ\nだつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BelueBerry,
        .iconPalette = gItemIconPalette_BelueBerry,
    },

    [ITEM_CHILAN_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ホズのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ホズのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_NORMAL,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ノーマル\n{JPN}わざを うけたとき\n{JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChilanBerry,
        .iconPalette = gItemIconPalette_ChilanBerry,
    },

    [ITEM_OCCA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}オッカのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}オッカのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIRE,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}ほのおわざを うけたと\nき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_OccaBerry,
        .iconPalette = gItemIconPalette_OccaBerry,
    },

    [ITEM_PASSHO_BERRY] =
    {
        .name = ITEM_NAME("{JPN}イトケのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}イトケのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_WATER,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}みずわざを うけたとき\n{JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PasshoBerry,
        .iconPalette = gItemIconPalette_PasshoBerry,
    },

    [ITEM_WACAN_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ソクノのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ソクノのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ELECTRIC,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}でんきわざを うけたと\nき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WacanBerry,
        .iconPalette = gItemIconPalette_WacanBerry,
    },

    [ITEM_RINDO_BERRY] =
    {
        .name = ITEM_NAME("{JPN}リンドのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}リンドのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GRASS,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}くさわざを うけたとき\n{JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RindoBerry,
        .iconPalette = gItemIconPalette_RindoBerry,
    },

    [ITEM_YACHE_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ヤチェのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ヤチェのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ICE,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}こおりわざを うけたと\nき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_YacheBerry,
        .iconPalette = gItemIconPalette_YacheBerry,
    },

    [ITEM_CHOPLE_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ヨプのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ヨプのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}かくとうわざを うけた\nとき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChopleBerry,
        .iconPalette = gItemIconPalette_ChopleBerry,
    },

    [ITEM_KEBIA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ビアーのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ビアーのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_POISON,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}どくわざを うけたとき\n{JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KebiaBerry,
        .iconPalette = gItemIconPalette_KebiaBerry,
    },

    [ITEM_SHUCA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}シュカのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}シュカのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GROUND,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}じめんわざを うけたと\nき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShucaBerry,
        .iconPalette = gItemIconPalette_ShucaBerry,
    },

    [ITEM_COBA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}バコウのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}バコウのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FLYING,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}ひこうわざを うけたと\nき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CobaBerry,
        .iconPalette = gItemIconPalette_CobaBerry,
    },

    [ITEM_PAYAPA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ウタンのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ウタンのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_PSYCHIC,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}エスパーわざを うけた\nとき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PayapaBerry,
        .iconPalette = gItemIconPalette_PayapaBerry,
    },

    [ITEM_TANGA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}タンガのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}タンガのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_BUG,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}むしわざを うけたとき\n{JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TangaBerry,
        .iconPalette = gItemIconPalette_TangaBerry,
    },

    [ITEM_CHARTI_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ヨロギのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ヨロギのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ROCK,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}いわわざを うけたとき\n{JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChartiBerry,
        .iconPalette = gItemIconPalette_ChartiBerry,
    },

    [ITEM_KASIB_BERRY] =
    {
        .name = ITEM_NAME("{JPN}カシブのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}カシブのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GHOST,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}ゴーストわざを うけた\nとき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KasibBerry,
        .iconPalette = gItemIconPalette_KasibBerry,
    },

    [ITEM_HABAN_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ハバンのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ハバンのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DRAGON,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}ドラゴンわざを うけた\nとき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_HabanBerry,
        .iconPalette = gItemIconPalette_HabanBerry,
    },

    [ITEM_COLBUR_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ナモのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ナモのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DARK,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}あくわざを うけたとき\n{JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ColburBerry,
        .iconPalette = gItemIconPalette_ColburBerry,
    },

    [ITEM_BABIRI_BERRY] =
    {
        .name = ITEM_NAME("{JPN}リリバのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}リリバのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_STEEL,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}はがねわざを うけたと\nき {JPN}いりょくが よわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BabiriBerry,
        .iconPalette = gItemIconPalette_BabiriBerry,
    },

    [ITEM_ROSELI_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ロゼルのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ロゼルのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FAIRY,
        .description = COMPOUND_STRING(
            "{JPN}もたせるとこうかばつぐんの{JPN}\nフェアリーわざをうけたとき{JPN}\nいりょくがよわまる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseliBerry,
        .iconPalette = gItemIconPalette_RoseliBerry,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = ITEM_NAME("{JPN}チイラのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}チイラのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}こうげきりょくが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LiechiBerry,
        .iconPalette = gItemIconPalette_LiechiBerry,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = ITEM_NAME("{JPN}リュガのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}リュガのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}ぼうぎょりょくが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_GanlonBerry,
        .iconPalette = gItemIconPalette_GanlonBerry,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = ITEM_NAME("{JPN}カムラのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}カムラのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}すばやさが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SalacBerry,
        .iconPalette = gItemIconPalette_SalacBerry,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ヤタピのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ヤタピのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}とくこうが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PetayaBerry,
        .iconPalette = gItemIconPalette_PetayaBerry,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ズアのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ズアのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}とくぼうが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ApicotBerry,
        .iconPalette = gItemIconPalette_ApicotBerry,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = ITEM_NAME("{JPN}サンのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}サンのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}てきの きゅうしょに\n{JPN}あたり やすくなる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LansatBerry,
        .iconPalette = gItemIconPalette_LansatBerry,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = ITEM_NAME("{JPN}スターのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}スターのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}のうりょくの どれか\n{JPN}1つが ぐーんと あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarfBerry,
        .iconPalette = gItemIconPalette_StarfBerry,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ナゾのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ナゾのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ENIGMA_BERRY,
        .description = COMPOUND_STRING(
            "{JPN}もたせると こうかばつぐん\nの {JPN}わざを うけたとき {JPN}H\nPを かいふくする{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

    [ITEM_MICLE_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ミクルのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ミクルのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MICLE_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}いちどだけ わざの\n{JPN}めいちゅうりつが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MicleBerry,
        .iconPalette = gItemIconPalette_MicleBerry,
    },

    [ITEM_CUSTAP_BERRY] =
    {
        .name = ITEM_NAME("{JPN}イバンのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}イバンのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CUSTAP_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
            "{JPN}もたせると ピンチのとき\n{JPN}いちどだけ こうどうが\n{JPN}はやくなる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CustapBerry,
        .iconPalette = gItemIconPalette_CustapBerry,
    },

    [ITEM_JABOCA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}ジャポのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ジャポのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_JABOCA_BERRY,
        .description = COMPOUND_STRING(
            "{JPN}もたせて ぶつりわざを\n{JPN}うけたとき あいてにも\n{JPN}ダメージを あたえる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_JabocaBerry,
        .iconPalette = gItemIconPalette_JabocaBerry,
    },

    [ITEM_ROWAP_BERRY] =
    {
        .name = ITEM_NAME("{JPN}レンブのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}レンブのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ROWAP_BERRY,
        .description = COMPOUND_STRING(
            "{JPN}もたせて とくしゅわざを\n{JPN}うけたとき あいてにも\n{JPN}ダメージを あたえる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RowapBerry,
        .iconPalette = gItemIconPalette_RowapBerry,
    },

    [ITEM_KEE_BERRY] =
    {
        .name = ITEM_NAME("{JPN}アッキのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}アッキのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_KEE_BERRY,
        .description = COMPOUND_STRING(
            "{JPN}もたせて ぶつりわざを\n{JPN}うけたとき じぶんの\n{JPN}ぼうぎょが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KeeBerry,
        .iconPalette = gItemIconPalette_KeeBerry,
    },

    [ITEM_MARANGA_BERRY] =
    {
        .name = ITEM_NAME("{JPN}タラプのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}タラプのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MARANGA_BERRY,
        .description = COMPOUND_STRING(
            "{JPN}もたせて とくしゅわざを\n{JPN}うけたとき じぶんの\n{JPN}とくぼうが あがる{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MarangaBerry,
        .iconPalette = gItemIconPalette_MarangaBerry,
    },

    [ITEM_ENIGMA_BERRY_E_READER] =
    {
        .name = ITEM_NAME("{JPN}ナゾのみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ナゾのみ{ENG}"),
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{POKEBLOCK}{JPN}のざいりょう。つ\nちにうえるとなぞのみがそだ\nつ。{ENG}"),
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = EFFECT_ITEM_ENIGMA_BERRY_EREADER,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

// TMs/HMs. They don't have a set flingPower, as that's handled by GetFlingPowerFromItemId.

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = ITEM_NAME("{JPN}わざマシン01{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}てきに だいダメージを\n{JPN}あたえるが こうげきを\n{JPN}うけると ひるんでしまう{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = ITEM_NAME("{JPN}わざマシン02{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ながく するどい ツメで\n{JPN}てきを ひっかけて\n{JPN}こうげきする{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = ITEM_NAME("{JPN}わざマシン03{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ちょうおんぱ こうげきで\n{JPN}てきを こんらんさせる\n{JPN}ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = ITEM_NAME("{JPN}わざマシン04{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}せいしんを しゅうちゅう\n{JPN}させて とくこうと\n{JPN}とくぼうを あげる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROAR] =
    {
        .name = ITEM_NAME("{JPN}わざマシン05{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}ほえて てきを にがす\n{JPN}てきが にげると\n{JPN}せんとうは おわる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = ITEM_NAME("{JPN}わざマシン06{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}じょじょに ダメージが\n{JPN}ふえる もうどくを\n{JPN}てきに あたえる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HAIL] =
    {
        .name = ITEM_NAME("{JPN}わざマシン07{ENG}"),
        .price = 3000,
    #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
            "{JPN}こおりタイプの{ENG}{PKMN}{JPN}のぼうぎ\nょを5ターンあげる。{ENG}"),
    #else
        .description = COMPOUND_STRING(
            "{JPN}あられをふらせこおりタイプ\nいがいにダメージをあたえる\n。{ENG}"),
    #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = ITEM_NAME("{JPN}わざマシン08{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}からだを きたえて\n{JPN}こうげきと ぼうぎょの\n{JPN}ちからを あげる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = ITEM_NAME("{JPN}わざマシン09{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}タネを 2ー5かい\n{JPN}れんぞくで はっしゃして\n{JPN}てきを こうげきする{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = ITEM_NAME("{JPN}わざマシン10{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンによって てきに\n{JPN}あたえる ダメージの\n{JPN}りょうが へんかする{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = ITEM_NAME("{JPN}わざマシン11{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}5ターンの あいだ\n{JPN}ほのおタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = ITEM_NAME("{JPN}わざマシン12{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}あいてを おこらせて\n{JPN}こうげきわざ しか\n{JPN}だせない ように する{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = ITEM_NAME("{JPN}わざマシン13{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "Fires an icy cold\n"
            "beam that may\n"
        #if B_USE_FROSTBITE == TRUE
            "inflict frostbite."),
        #else
            "freeze the foe."),
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = ITEM_NAME("{JPN}わざマシン14{ENG}"),
        .price = 5500,
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
            "A snow-and-wind\n"
            "attack that may\n"
            "inflict frostbite."),
        #else
            "A brutal snow-and-\n"
            "wind attack that\n"
            "may freeze the foe."),
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = ITEM_NAME("{JPN}わざマシン15{ENG}"),
        .price = 7500,
        .description = COMPOUND_STRING(
            "{JPN}ダメージは おおきいが\n{JPN}つかうと つぎのターン\n{JPN}うごけなく なってしまう{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = ITEM_NAME("{JPN}わざマシン16{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ひかりのかべを つくり\n{JPN}とくこうの ダメージを\n{JPN}よわめる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = ITEM_NAME("{JPN}わざマシン17{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}そのターンの こうげきを\n{JPN}うけないが れんぞくして\n{JPN}だすと しっぱいしやすい{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = ITEM_NAME("{JPN}わざマシン18{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}5ターンの あいだ\n{JPN}みずタイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = ITEM_NAME("{JPN}わざマシン19{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}あたえた ダメージの\n{JPN}はんぶんの たいりょくを\n{JPN}かいふく できる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = ITEM_NAME("{JPN}わざマシン20{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ふしぎな ちからに\n{JPN}まもられて とくしゅ\n{JPN}じょうたいに ならない{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = ITEM_NAME("{JPN}わざマシン21{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが なついて\n{JPN}いないほど あたえる\n{JPN}ダメージが あがる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = ITEM_NAME("{JPN}わざマシン22{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}1ターンめで ひかりを\n{JPN}きゅうしゅうして つぎの\n{JPN}ターンに こうげきする{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = ITEM_NAME("{JPN}わざマシン23{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}かたいシッポで こうげき\n{JPN}てきの ぼうぎょを\n{JPN}さげる ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = ITEM_NAME("{JPN}わざマシン24{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}でんげきを あびせる\n{JPN}あたった てきを\n{JPN}まひさせる ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = ITEM_NAME("{JPN}わざマシン25{ENG}"),
        .price = 5500,
        .description = COMPOUND_STRING(
            "{JPN}かみなりを おとす\n{JPN}あたった てきを\n{JPN}まひさせる ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = ITEM_NAME("{JPN}わざマシン26{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}じめんを つよく ゆらす\n{JPN}とんでいる てきいがいに\n{JPN}だいダメージを あたえる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RETURN] =
    {
        .name = ITEM_NAME("{JPN}わざマシン27{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが なついて\n{JPN}いるほど あたえる\n{JPN}ダメージが あがる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DIG] =
    {
        .name = ITEM_NAME("{JPN}わざマシン28{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}1ターンめで じめんに\n{JPN}もぐり つぎのターンに\n{JPN}てきを こうげきする{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = ITEM_NAME("{JPN}わざマシン29{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}つよい ねんりきを だす\n{JPN}てきの とくぼうを\n{JPN}さげる ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = ITEM_NAME("{JPN}わざマシン30{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}くろいかたまりを なげる\n{JPN}てきの とくぼうを\n{JPN}さげる ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = ITEM_NAME("{JPN}わざマシン31{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ひかりのかべ などを\n{JPN}こわして てきに\n{JPN}ダメージを あたえられる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = ITEM_NAME("{JPN}わざマシン32{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}ぶんしんを つくって\n{JPN}てきを まどわせて\n{JPN}かいひりつを あげる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = ITEM_NAME("{JPN}わざマシン33{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ひかりのかべを つくり\n{JPN}ぶつり こうげきの\n{JPN}ダメージを よわめる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = ITEM_NAME("{JPN}わざマシン34{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ぜったいに よけられない\n{JPN}すばやさで てきに\n{JPN}でんげきを あびせる.{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = ITEM_NAME("{JPN}わざマシン35{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}ほのおを まきちらす\n{JPN}あたった てきを\n{JPN}やけどさせる ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = ITEM_NAME("{JPN}わざマシン36{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}ヘドロを なげつける\n{JPN}あたった てきに どくを\n{JPN}あたえることが ある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = ITEM_NAME("{JPN}わざマシン37{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}すなあらしを おこして\n{JPN}まいターン てきに\n{JPN}ダメージを あたえる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = ITEM_NAME("{JPN}わざマシン38{ENG}"),
        .price = 5500,
        .description = COMPOUND_STRING(
            "{JPN}だいの もじで すべてを\n{JPN}やきつくす こうげき\n{JPN}やけどさせる ことがある{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = ITEM_NAME("{JPN}わざマシン39{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}いわで てきの うごきを\n{JPN}ふうじて こうげき\n{JPN}すばやさを さげられる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = ITEM_NAME("{JPN}わざマシン40{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}すばやい うごきで\n{JPN}ぜったいに よけられない\n{JPN}こうげきを する{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = ITEM_NAME("{JPN}わざマシン41{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}てきが おなじわざを\n{JPN}れんぞくで だせない\n{JPN}ようにする{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FACADE] =
    {
        .name = ITEM_NAME("{JPN}わざマシン42{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}どく まひ やけどのとき\n{JPN}こうげきの ちからを\n{JPN}あげる ことが できる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = ITEM_NAME("{JPN}わざマシン43{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}たたかう ばしょに より\n{JPN}てきに あたえる\n{JPN}ついか こうかが かわる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REST] =
    {
        .name = ITEM_NAME("{JPN}わざマシン44{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}2ターンねむり からだの\n{JPN}いじょうと たいりょくを\n{JPN}ぜんかいふく する{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = ITEM_NAME("{JPN}わざマシン45{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}オスなら メスに\n{JPN}メスなら オスに\n{JPN}わざが だしにくくなる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THIEF] =
    {
        .name = ITEM_NAME("{JPN}わざマシン46{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}こうげきちゅうに すきを\n{JPN}みて てきが もっている\n{JPN}どうぐを ぬすむ{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = ITEM_NAME("{JPN}わざマシン47{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}かたいつばさを おおきく\n{JPN}ひろげて そのまま\n{JPN}てきに たいあたりする{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = ITEM_NAME("{JPN}わざマシン48{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}わざを だした ターンに\n{JPN}じぶんと てきの\n{JPN}とくせいを いれかえる{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = ITEM_NAME("{JPN}わざマシン49{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}てきが つかおうとした\n{JPN}わざを うばって\n{JPN}じぶんに つかう{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = ITEM_NAME("{JPN}わざマシン50{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}フルパワーで こうげき\n{JPN}できるが とくこうが\n{JPN}ガクッと さがってしまう{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM51] =
    {
        .name = ITEM_NAME("{JPN}わざマシン51{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}いんせきでこうげき。じぶん\nのとくこうががくっとさがる\n。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM52] =
    {
        .name = ITEM_NAME("{JPN}わざマシン52{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}せっきんしてこうげき。じぶ\nんのぼうぎょととくぼうがさ\nがる。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM53] =
    {
        .name = ITEM_NAME("{JPN}わざマシン53{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}うろこをはっしゃ。すばやさ\nがあがりぼうぎょがさがる。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM54] =
    {
        .name = ITEM_NAME("{JPN}わざマシン54{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}じゃれついてこうげき。あい\nてのこうげきをさげることが\nある。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM55] =
    {
        .name = ITEM_NAME("{JPN}わざマシン55{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}はげしくおどりじぶんのこう\nげきをぐーんとあげる。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM56] =
    {
        .name = ITEM_NAME("{JPN}わざマシン56{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}わるいことをかんがえてのう\nをかっせいかさせる。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM57] =
    {
        .name = ITEM_NAME("{JPN}わざマシン57{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}あついすなをなげる。やけど\nにすることがある。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM58] =
    {
        .name = ITEM_NAME("{JPN}わざマシン58{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}じめんをふきあげる。あいて\nのとくぼうをさげることがあ\nる。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM59] =
    {
        .name = ITEM_NAME("{JPN}わざマシン59{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}あいてのもちものをはたきお\nとしてつかえなくする。{ENG}"),
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM60] =
    {
        .name = ITEM_NAME("{JPN}わざマシン60{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM61] =
    {
        .name = ITEM_NAME("{JPN}わざマシン61{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM62] =
    {
        .name = ITEM_NAME("{JPN}わざマシン62{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM63] =
    {
        .name = ITEM_NAME("{JPN}わざマシン63{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM64] =
    {
        .name = ITEM_NAME("{JPN}わざマシン64{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM65] =
    {
        .name = ITEM_NAME("{JPN}わざマシン65{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM66] =
    {
        .name = ITEM_NAME("{JPN}わざマシン66{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM67] =
    {
        .name = ITEM_NAME("{JPN}わざマシン67{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM68] =
    {
        .name = ITEM_NAME("{JPN}わざマシン68{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM69] =
    {
        .name = ITEM_NAME("{JPN}わざマシン69{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM70] =
    {
        .name = ITEM_NAME("{JPN}わざマシン70{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM71] =
    {
        .name = ITEM_NAME("{JPN}わざマシン71{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM72] =
    {
        .name = ITEM_NAME("{JPN}わざマシン72{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM73] =
    {
        .name = ITEM_NAME("{JPN}わざマシン73{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM74] =
    {
        .name = ITEM_NAME("{JPN}わざマシン74{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM75] =
    {
        .name = ITEM_NAME("{JPN}わざマシン75{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM76] =
    {
        .name = ITEM_NAME("{JPN}わざマシン76{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM77] =
    {
        .name = ITEM_NAME("{JPN}わざマシン77{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM78] =
    {
        .name = ITEM_NAME("{JPN}わざマシン78{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM79] =
    {
        .name = ITEM_NAME("{JPN}わざマシン79{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM80] =
    {
        .name = ITEM_NAME("{JPN}わざマシン80{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM81] =
    {
        .name = ITEM_NAME("{JPN}わざマシン81{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM82] =
    {
        .name = ITEM_NAME("{JPN}わざマシン82{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM83] =
    {
        .name = ITEM_NAME("{JPN}わざマシン83{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM84] =
    {
        .name = ITEM_NAME("{JPN}わざマシン84{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM85] =
    {
        .name = ITEM_NAME("{JPN}わざマシン85{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM86] =
    {
        .name = ITEM_NAME("{JPN}わざマシン86{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM87] =
    {
        .name = ITEM_NAME("{JPN}わざマシン87{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM88] =
    {
        .name = ITEM_NAME("{JPN}わざマシン88{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM89] =
    {
        .name = ITEM_NAME("{JPN}わざマシン89{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM90] =
    {
        .name = ITEM_NAME("{JPN}わざマシン90{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM91] =
    {
        .name = ITEM_NAME("{JPN}わざマシン91{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM92] =
    {
        .name = ITEM_NAME("{JPN}わざマシン92{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM93] =
    {
        .name = ITEM_NAME("{JPN}わざマシン93{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM94] =
    {
        .name = ITEM_NAME("{JPN}わざマシン94{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM95] =
    {
        .name = ITEM_NAME("{JPN}わざマシン95{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM96] =
    {
        .name = ITEM_NAME("{JPN}わざマシン96{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM97] =
    {
        .name = ITEM_NAME("{JPN}わざマシン97{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM98] =
    {
        .name = ITEM_NAME("{JPN}わざマシン98{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM99] =
    {
        .name = ITEM_NAME("{JPN}わざマシン99{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM100] =
    {
        .name = ITEM_NAME("{JPN}わざマシン100{ENG}"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_CUT] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン01{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}カマや ツメなどの\n{JPN}するどいもので てきを\n{JPN}きりつけて こうげきする{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLY] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン02{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}1ターンめで そらへとび\n{JPN}つぎの ターンに てきを\n{JPN}こうげきする{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_SURF] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン03{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}みずに なみを おこし\n{JPN}それを ものすごい\n{JPN}ちからで たたきつける{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_STRENGTH] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン04{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ぜんしんに ものすごい\n{JPN}ちからを ためこみ\n{JPN}てきを こうげきする{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLASH] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン05{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}つよい ひかりで めを\n{JPN}くらませて てきの\n{JPN}めいちゅうりつを さげる{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン06{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}いわをもくだく ちからで\n{JPN}てきの ぼうぎょを\n{JPN}さげる ことがある{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_WATERFALL] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン07{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}たきを さかのぼるような\n{JPN}いきおいで てきに\n{JPN}とっしんする{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_DIVE] =
    {
        .name = ITEM_NAME("{JPN}ひでんマシン08{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}1ターンめで みずに\n{JPN}もぐり つぎのターンで\n{JPN}てきを こうげきする{ENG}"),
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },


// Charms

    [ITEM_OVAL_CHARM] =
    {
        .name = ITEM_NAME("{JPN}まるいおまもり{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}もっていると ポケモン\n{JPN}そだてやさんで タマゴが\n{JPN}はっけん されやすくなる{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OvalCharm,
        .iconPalette = gItemIconPalette_OvalCharm,
    },

    [ITEM_SHINY_CHARM] =
    {
        .name = ITEM_NAME("{JPN}ひかるおまもり{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}もっていると いろちがいの\n{JPN}ポケモンと であいやすくな\nる{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ShinyCharm,
        .iconPalette = gItemIconPalette_ShinyCharm,
    },

    [ITEM_CATCHING_CHARM] =
    {
        .name = ITEM_NAME("{JPN}ゆれないおまもり{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}もっていると\n{JPN}ほかくクリティカルが\n{JPN}はっせい しやすくなる{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CatchingCharm,
        .iconPalette = gItemIconPalette_CatchingCharm,
    },

    [ITEM_EXP_CHARM] =
    {
        .name = ITEM_NAME("{JPN}けいけんおまもり{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}もっていると ポケモンが\n{JPN}えられる けいけんちが\n{JPN}ふえる おまもり{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ExpCharm,
        .iconPalette = gItemIconPalette_ExpCharm,
    },

// Form-changing Key Items

    [ITEM_ROTOM_CATALOG] =
    {
        .name = ITEM_NAME("{JPN}ロトムのカタログ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}カタログを つかうことで\n{JPN}ロトムを かでんに\n{JPN}だしいれ できる{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RotomCatalog,
        .iconPic = gItemIcon_RotomCatalog,
        .iconPalette = gItemIconPalette_RotomCatalog,
    },

    [ITEM_GRACIDEA] =
    {
        .name = ITEM_NAME("{JPN}グラシデアのはな{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}かんしゃの きもちを\n{JPN}つたえるため ブーケにして\n{JPN}おくることが ある{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Gracidea,
        .iconPalette = gItemIconPalette_Gracidea,
    },

    [ITEM_REVEAL_GLASS] =
    {
        .name = ITEM_NAME("{JPN}うつしかがみ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}うつしかがみ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンを ほんらいの\n{JPN}すがたに かえてしまう\n{JPN}ふしぎな かがみ{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_RevealGlass,
        .iconPalette = gItemIconPalette_RevealGlass,
    },

    [ITEM_DNA_SPLICERS] =
    {
        .name = ITEM_NAME("{JPN}いでんしのくさび{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}いでんしのくさび{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}キュレムと あるポケモンを\n{JPN}がったいさせる\n{JPN}いっついの くさび{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_DNASplicers,
        .iconPalette = gItemIconPalette_DNASplicers,
    },

    [ITEM_ZYGARDE_CUBE] =
    {
        .name = ITEM_NAME("{JPN}ジガルデキューブ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ポケモン ジガルデの\n{JPN}コアと セルを\n{JPN}あつめるための どうぐ{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ZygardeCube,
        .iconPic = gItemIcon_ZygardeCube,
        .iconPalette = gItemIconPalette_ZygardeCube,
    },

    [ITEM_PRISON_BOTTLE] =
    {
        .name = ITEM_NAME("{JPN}いましめのツボ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}おおむかしに とある\n{JPN}ポケモンの ふうじこめたと\n{JPN}される ツボ{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_PrisonBottle,
        .iconPalette = gItemIconPalette_PrisonBottle,
    },

    [ITEM_N_SOLARIZER] =
    {
        .name = ITEM_NAME("{JPN}ネクロプラスソル{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ひかりを ひつようと する\n{JPN}ネクロズマと ソルガレオを\n{JPN}がったい させる マシン{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NSolarizer,
    },

    [ITEM_N_LUNARIZER] =
    {
        .name = ITEM_NAME("{JPN}ネクロプラスルナ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ひかりを ひつようと する\n{JPN}ネクロズマと ルナアーラを\n{JPN}がったい させる マシン{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NLunarizer,
    },

    [ITEM_REINS_OF_UNITY] =
    {
        .name = ITEM_NAME("{JPN}キズナのタヅナ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}キズナのタヅナ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ちからを ぞうふくし\n{JPN}バドレックスと あいばを\n{JPN}がったい させる{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_ReinsOfUnity,
        .iconPalette = gItemIconPalette_ReinsOfUnity,
    },

// Battle Mechanic Key Items

    [ITEM_MEGA_RING] =
    {
        .name = ITEM_NAME("{JPN}メガリング{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}メガストーンをもつ{ENG}{PKMN}{JPN}がメ\nガシンカできる。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MegaRing,
        .iconPalette = gItemIconPalette_MegaRing,
    },

    [ITEM_Z_POWER_RING] =
    {
        .name = ITEM_NAME("{JPN}Zパワーリング{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンが Zパワーを\n{JPN}はなてるようにする\n{JPN}ふしぎなうでわ{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ZPowerRing,
        .iconPalette = gItemIconPalette_ZPowerRing,
    },

    [ITEM_DYNAMAX_BAND] =
    {
        .name = ITEM_NAME("{JPN}ダイマックスB{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ねがいぼしが\n{JPN}ひかりだして ポケモンを\n{JPN}ダイマックス させる{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DynamaxBand,
        .iconPalette = gItemIconPalette_DynamaxBand,
    },

// Misc. Key Items

    [ITEM_BICYCLE] =
    {
        .name = ITEM_NAME("{JPN}じてんしゃ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おりたたみの じてんしゃ\n{JPN}ランニングシューズより\n{JPN}はやく はしる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = STANDARD_BIKE,
        .iconPic = gItemIcon_Bicycle,
        .iconPalette = gItemIconPalette_Bicycle,
    },

    [ITEM_MACH_BIKE] =
    {
        .name = ITEM_NAME("{JPN}マッハじてんしゃ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}2ばい いじょうの\n{JPN}はやさで いどう できる\n{JPN}おりたたみの じてんしゃ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
        .iconPic = gItemIcon_MachBike,
        .iconPalette = gItemIconPalette_MachBike,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = ITEM_NAME("{JPN}ダートじてんしゃ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ジャンプや ウイリーの\n{JPN}アクションが できる\n{JPN}おりたたみの じてんしゃ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
        .iconPic = gItemIcon_AcroBike,
        .iconPalette = gItemIconPalette_AcroBike,
    },

    [ITEM_OLD_ROD] =
    {
        .name = ITEM_NAME("{JPN}ボロのつりざお{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンを つるどうぐ\n{JPN}みずべで つかうと\n{JPN}ポケモンが つれる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
        .iconPic = gItemIcon_OldRod,
        .iconPalette = gItemIconPalette_OldRod,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = ITEM_NAME("{JPN}いいつりざお{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンを つるどうぐ\n{JPN}なかなかの つりざおと\n{JPN}いわれている{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
        .iconPic = gItemIcon_GoodRod,
        .iconPalette = gItemIconPalette_GoodRod,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = ITEM_NAME("{JPN}すごいつりざお{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンを つるどうぐ\n{JPN}さいこうの つりざおと\n{JPN}いわれている{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
        .iconPic = gItemIcon_SuperRod,
        .iconPalette = gItemIconPalette_SuperRod,
    },

    [ITEM_DOWSING_MACHINE] =
    {
        .name = ITEM_NAME("{JPN}ダウジングマシン{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}みえない どうぐに\n{JPN}はんのうして\n{JPN}おとで おしえて くれる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
        .iconPic = gItemIcon_DowsingMachine,
        .iconPalette = gItemIconPalette_DowsingMachine,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = ITEM_NAME("{JPN}タウンマップ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}いつでも みることが\n{JPN}できる べんりな ちず\n{JPN}じぶんの いちも わかる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TownMap,
        .iconPic = gItemIcon_TownMap,
        .iconPalette = gItemIconPalette_TownMap,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = ITEM_NAME("{JPN}バトルサーチャー{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}たたかえる トレーナーを\n{JPN}おしえてくれる きかい\n{JPN}じゅうでんして つかう{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
    #if I_VS_SEEKER_CHARGING != 0
        .fieldUseFunc = FieldUseFunc_VsSeeker,
    #else
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    #endif
        .iconPic = gItemIcon_VsSeeker,
        .iconPalette = gItemIconPalette_VsSeeker,
    },

    [ITEM_TM_CASE] =
    {
        .name = ITEM_NAME("{JPN}わざマシンケース{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}わざマシンを ほかんする\n{JPN}べんりな いれもの{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TMCase,
        .iconPalette = gItemIconPalette_TMCase,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = ITEM_NAME("{JPN}きのみぶくろ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}きのみぶくろ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}きのみを ほぞんする\n{JPN}べんりな いれもの{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BerryPouch,
        .iconPalette = gItemIconPalette_BerryPouch,
    },

    [ITEM_POKEMON_BOX_LINK] =
    {
        .name = ITEM_NAME("{ENG}{PKMN}{JPN}ボックスリンク{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}{ENG}{PKMN}{JPN}をあずけるシステムにつ\nなげるそうち。{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_PokemonBoxLink,
        .iconPic = gItemIcon_PokemonBoxLink,
        .iconPalette = gItemIconPalette_PokemonBoxLink,
    },

    [ITEM_COIN_CASE] =
    {
        .name = ITEM_NAME("{JPN}コインケース{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}コインをさいだい9,999\nまいまでいれられるケース。{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
        .iconPic = gItemIcon_CoinCase,
        .iconPalette = gItemIconPalette_CoinCase,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = ITEM_NAME("{JPN}こないれ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}きのみクラッシュで\n{JPN}できた きのみの こなを\n{JPN}ほぞんする いれもの{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
        .iconPic = gItemIcon_PowderJar,
        .iconPalette = gItemIconPalette_PowderJar,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = ITEM_NAME("{JPN}ホエルコじょうろ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}みずを かける どうぐ\n{JPN}つちに うめた きのみを\n{JPN}すくすく そだてる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
        .iconPic = gItemIcon_WailmerPail,
        .iconPalette = gItemIconPalette_WailmerPail,
    },

    [ITEM_POKE_RADAR] =
    {
        .name = ITEM_NAME("{JPN}ポケトレ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}くさむらに かくれている\n{JPN}ポケモンを さがしだせる\n{JPN}どうぐ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .iconPic = gItemIcon_PokeRadar,
        .iconPalette = gItemIconPalette_PokeRadar,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = ITEM_NAME("{ENG}{POKEBLOCK}{JPN}ケース{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}きのみブレンダーでつくった{ENG}\n{POKEBLOCK}{JPN}をいれるケース。{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
        .iconPic = gItemIcon_PokeblockCase,
        .iconPalette = gItemIconPalette_PokeblockCase,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = ITEM_NAME("{JPN}はいぶくろ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}つもった かざんばいを\n{JPN}あつめるための ふくろ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SootSack,
        .iconPalette = gItemIconPalette_SootSack,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = ITEM_NAME("{JPN}ポケモンのふえ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}きれいな ねいろの ふえ\n{JPN}ねている ポケモンが\n{JPN}きくと とびおきる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeFlute,
        .battleUsage = EFFECT_ITEM_USE_POKE_FLUTE,
        .iconPic = gItemIcon_PokeFlute,
        .iconPalette = gItemIconPalette_PokeFlute,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = ITEM_NAME("{JPN}ボイスチェッカー{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ゆうめいな じんぶつの\n{JPN}じょうほうを いつでも\n{JPN}みなおすことが できる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_FameChecker,
        .iconPalette = gItemIconPalette_FameChecker,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = ITEM_NAME("{JPN}おしえテレビ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}トレーナーの やくにたつ\n{JPN}ばんぐみを みることが\n{JPN}できる テレビ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeachyTV,
        .iconPalette = gItemIconPalette_TeachyTV,
    },

// Story Key Items

    [ITEM_SS_TICKET] =
    {
        .name = ITEM_NAME("{JPN}ふねのチケット{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}れんらくせんに\n{JPN}のるとき ひつよう{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SSTicket,
        .iconPalette = gItemIconPalette_SSTicket,
    },

    [ITEM_HOT_COCOA] =
    {
        .name = ITEM_NAME("{JPN}ホットココア{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}あたたかいココアのすいとう\n。ゆきにかこまれたしまいの\nこうぶつ。{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MoomooMilk,
        .iconPalette = gItemIconPalette_MoomooMilk,
    },

    [ITEM_FENTANYL] =
    {
        .name = ITEM_NAME("{JPN}フェンタニル{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}つよいくすりのこびん。アッ\nシュランドのしにかけたおと\nこにひつよう。{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_FullHeal,
        .iconPalette = gItemIconPalette_FullHeal,
    },

    // Tradewind Town curios (borrowed icons that fit each curio)
    [ITEM_BOTTLED_WARMTH] =
    {
        .name = ITEM_NAME("{JPN}びんづめのぬくもり{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}さわるとあたたかいびん。け\nっしてさめずふたもあかない\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Honey,
        .iconPalette = gItemIconPalette_Honey,
    },

    [ITEM_BORROWED_YEARS] =
    {
        .name = ITEM_NAME("{JPN}かりたとしつき{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}だれかのものだったじかん。\nみためよりおもい。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OldAmber,
        .iconPalette = gItemIconPalette_OldAmber,
    },

    [ITEM_UNSPOKEN_LAST_WORDS] =
    {
        .name = ITEM_NAME("{JPN}つたえなかったことば{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}だれもいえなかったさよなら\n。もつとかすかにうなる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SootheBell,
        .iconPalette = gItemIconPalette_SootheBell,
    },

    [ITEM_A_STRANGERS_NAME] =
    {
        .name = ITEM_NAME("{JPN}しらないひとのなまえ{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}もちぬしのかおさえのこって\nいないなまえ。おもいだせそ\nうなのに。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SpellTag,
        .iconPalette = gItemIconPalette_SpellTag,
    },

    [ITEM_FOLDED_GOODBYE] =
    {
        .name = ITEM_NAME("{JPN}おりたたんださよなら{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}なんどもおりたたまれもうに\nどとひらけなくなったてがみ\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Letter,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_ONE_GOOD_DREAM] =
    {
        .name = ITEM_NAME("{JPN}ひとつのよいゆめ{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}けっしてわすれぬようたいせ\nつにしまわれたひとつのよい\nゆめ。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_THE_LONG_WAY_HOME] =
    {
        .name = ITEM_NAME("{JPN}とおいかえりみち{ENG}"),
        .price = 1000,
        .description = COMPOUND_STRING(
            "{JPN}かならずいえへつながるみち\n。どれほどかかるかはだれも\nかたらない。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OldSeaMap,
        .iconPalette = gItemIconPalette_OldSeaMap,
    },

    [ITEM_CARVED_MASK] =
    {
        .name = ITEM_NAME("{JPN}ほりもののめん{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}イツキのまつりのめん。まご\nころをこめてほられたまよけ\nのかお。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_OniMask,
        .iconPic = gItemIcon_CornerstoneMask,
        .iconPalette = gItemIconPalette_CornerstoneMask,
    },

    [ITEM_CATALPA_BOW] =
    {
        .name = ITEM_NAME("{JPN}アズサユミ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}れいをよぶアズサユミ。つる\nをはらずにうたいはざまをひ\nらく。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CatalpaBow,
        .iconPic = gItemIcon_CatalpaBow,
        .iconPalette = gItemIconPalette_CatalpaBow,
    },

    [ITEM_SHADOW_DOSSIER] =
    {
        .name = ITEM_NAME("{JPN}ダークちょうさしりょう{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}クラークソンのけんきゅうげ\nんぽん。いろいろないみでお\nもい。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_ShadowDossier,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

    [ITEM_QUEST_LOG] =
    {
        .name = ITEM_NAME("{JPN}クエストにっし{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ちかったこととはたしたこと\nをすべてきろくするにっし。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_QuestLog,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

    [ITEM_YACHT_KEY] =
    {
        .name = ITEM_NAME("{JPN}ヨットのカギ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}2ばんどうろのさんばしにつ\nながれたヨットをうごかすカ\nギ。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_YachtKey,
        .iconPalette = gItemIconPalette_YachtKey,
    },

    // Wishes of Tomorrow: RedFatality's lift ticket (Route 2). Generic ticket icon
    // (the S.S. Ticket's) until there's art.
    [ITEM_EPIC_PASS] =
    {
        .name = ITEM_NAME("{JPN}リフトのシーズンパス{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}さんちょうへのリフトにのり\nほうだいのシーズンパス。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SSTicket,
        .iconPalette = gItemIconPalette_SSTicket,
    },

    // Wishes of Tomorrow: the Frostwood bar's drinks. Same effect, price and
    // battle use as the Potion / Super Potion they stand in for.
    [ITEM_DOMESTIC] =
    {
        .name = ITEM_NAME("{JPN}こくさんビール{ENG}"),
        .price = (I_PRICE >= GEN_7) ? 200 : 300,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}よくひえたラガービール。ポ\nケモンのHPを20かいふく\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_Domestic,
        .iconPalette = gItemIconPalette_Domestic,
    },

    [ITEM_CRAFT] =
    {
        .name = ITEM_NAME("{JPN}クラフトビール{ENG}"),
        .price = 700,
        .holdEffectParam = 60,
        .description = COMPOUND_STRING(
            "A local microbrew.\n"
            "Restores the HP of\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "a Pokémon by 60."),
        #else
            "a Pokémon by 50."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Craft,
        .iconPalette = gItemIconPalette_Craft,
    },

    // Wishes of Tomorrow: a Rare Candy that is never used up. Same field
    // use and effect table as the Rare Candy; ItemUseCB_RareCandy simply
    // doesn't take it out of the bag. A key item, so it can't be tossed,
    // sold or held, and it can be registered to SELECT.
    [ITEM_INFINITE_CANDY] =
    {
        .name = ITEM_NAME("{JPN}むげんのアメ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンのレベルを1あげる\n。なんどでもつかえる。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .iconPic = gItemIcon_RareCandy,
        .iconPalette = gItemIconPalette_InfiniteCandy,
    },

    [ITEM_SNAG_MACHINE] =
    {
        .name = ITEM_NAME("{JPN}スナッチマシン{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}ダークポケモンにたいしてボ\nールをスナッチボールにかえ\nる。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SnagMachine,
        .iconPalette = gItemIconPalette_SnagMachine,
    },

    [ITEM_SHINKANSEN_KEY] =
    {
        .name = ITEM_NAME("{JPN}しんかんせんのカギ{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}しんかんせんのうんてんしつ\nのカードキー。ひがしへのか\nたみち。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

    // Distortion World rift-layer relics. Names/descriptions PLACEHOLDER (Joe).
    [ITEM_RIFT_SHARD] =
    {
        .name = ITEM_NAME("{JPN}さけめのかけら{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}さけめのかけら。ためこまれ\nたじかんでかすかにうなる。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

    [ITEM_RIFT_CORE] =
    {
        .name = ITEM_NAME("{JPN}さけめのかく{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}さけめがこくむすばれたかた\nまり。かためんだけつめたい\n。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

    [ITEM_RIFT_HEART] =
    {
        .name = ITEM_NAME("{JPN}さけめのしんぞう{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}いちばんおくにしまわれたも\nの。とてもゆっくりみゃくう\nつ。{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

    // Tradewind department-store scam item: Master Ball's icon and description
    // verbatim, 5,000 on the shelf -- but it goes to the ITEMS pocket and can't
    // be used for anything at all. The shelf tag really does say "Waster Ball".
    [ITEM_WASTER_BALL] =
    {
        .name = ITEM_NAME("{JPN}ウェイスターボール{ENG}"),
        .price = 5000,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンをかならずつかまえ\nるさいこうのボール。{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MasterBall,
        .iconPalette = gItemIconPalette_MasterBall,
    },

    [ITEM_EON_TICKET] =
    {
        .name = ITEM_NAME("{JPN}むげんのチケット{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}みなみのことうへ いく\n{JPN}ふねの チケット{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
        .iconPic = gItemIcon_EonTicket,
        .iconPalette = gItemIconPalette_EonTicket,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = ITEM_NAME("{JPN}しんぴのチケット{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}へそのいわへ\n{JPN}いくために ひつような\n{JPN}ふねの チケット{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MysticTicket,
        .iconPalette = gItemIconPalette_MysticTicket,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = ITEM_NAME("{JPN}オーロラチケット{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}たんじょうのしまへ\n{JPN}いくために ひつような\n{JPN}ふねの チケット{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_AuroraTicket,
        .iconPalette = gItemIconPalette_AuroraTicket,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = ITEM_NAME("{JPN}ふるびたかいず{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ある しまへの かいろを\n{JPN}しるして ある\n{JPN}ふるぼけた うみの ちず{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OldSeaMap,
        .iconPalette = gItemIconPalette_OldSeaMap,
    },

    [ITEM_LETTER] =
    {
        .name = ITEM_NAME("{JPN}ダイゴへのてがみ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}デボンしゃちょう から\n{JPN}あずかった てがみ{ENG}"),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Letter,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_DEVON_PARTS] =
    {
        .name = ITEM_NAME("{JPN}デボンのにもつ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}デボンのにもつ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}デボンで つくられた\n{JPN}なにかの パーツが\n{JPN}はいっている にもつ{ENG}"),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonParts,
        .iconPalette = gItemIconPalette_DevonParts,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = ITEM_NAME("{JPN}ゴーゴーゴーグル{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ゴーゴーゴーグル{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}さばくの すなあらしから\n{JPN}めを まもってくれる\n{JPN}すてきな ゴーグル{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoGoggles,
        .iconPalette = gItemIconPalette_GoGoggles,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = ITEM_NAME("{JPN}デボンスコープ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}みえない ポケモンに\n{JPN}はんのうして おとをだす\n{JPN}デボンの とくせいひん{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonScope,
        .iconPalette = gItemIconPalette_DevonScope,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = ITEM_NAME("{JPN}ちかのカギ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}キンセツの ちかにある\n{JPN}ニューキンセツに\n{JPN}はいる ための カギ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BasementKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_SCANNER] =
    {
        .name = ITEM_NAME("{JPN}たんちき{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}すてられぶねの なかで\n{JPN}みつけた どうぐ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Scanner,
        .iconPalette = gItemIconPalette_Scanner,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = ITEM_NAME("{JPN}そうこのカギ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}すてられぶねの そうこに\n{JPN}はいる ための カギ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StorageKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_KEY_TO_ROOM_1] =
    {
        .name = ITEM_NAME("{JPN}1ごうしつのカギ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}1ごうしつのカギ{ENG}"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom1,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_2] =
    {
        .name = ITEM_NAME("{JPN}2ごうしつのカギ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}2ごうしつのカギ{ENG}"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom2,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_4] =
    {
        .name = ITEM_NAME("{JPN}4ごうしつのカギ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}4ごうしつのカギ{ENG}"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom4,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_6] =
    {
        .name = ITEM_NAME("{JPN}6ごうしつのカギ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}6ごうしつのカギ{ENG}"),
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom6,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_METEORITE] =
    {
        .name = ITEM_NAME("{JPN}いんせき{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}りゅうせいのたきに\n{JPN}おちていた いんせき{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Meteorite,
        .iconPalette = gItemIconPalette_Meteorite,
    },

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = ITEM_NAME("{JPN}マグマのしるし{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}マグマだんの マークと\n{JPN}おなじ かたちを した\n{JPN}おなじ かたちを した{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MagmaEmblem,
        .iconPalette = gItemIconPalette_MagmaEmblem,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = ITEM_NAME("{JPN}コンテストパス{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}コンテストパス{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンコンテストに\n{JPN}さんかする ことができる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ContestPass,
        .iconPalette = gItemIconPalette_ContestPass,
    },

    [ITEM_PARCEL] =
    {
        .name = ITEM_NAME("{JPN}おとどけもの{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ショップの てんいんから\n{JPN}たのまれた おとどけもの\n{JPN}オーキドはかせに わたす{ENG}"),
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Parcel,
        .iconPalette = gItemIconPalette_Parcel,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = ITEM_NAME("{JPN}ひみつのカギ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}グレンじま ジムの\n{JPN}いりぐちを あける カギ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SecretKey,
        .iconPalette = gItemIconPalette_SecretKey,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = ITEM_NAME("{JPN}ひきかえけん{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ミラクル・サイクルで\n{JPN}おりたたみ じてんしゃと\n{JPN}こうかん できる かみ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BikeVoucher,
        .iconPalette = gItemIconPalette_BikeVoucher,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = ITEM_NAME("{JPN}きんのいれば{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}きんのいれば{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}サファリゾーンの\n{JPN}えんちょうが おとした\n{JPN}きんいろの いれば{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoldTeeth,
        .iconPalette = gItemIconPalette_GoldTeeth,
    },

    [ITEM_CARD_KEY] =
    {
        .name = ITEM_NAME("{JPN}カードキー{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}カードで できた カギ\n{JPN}シルフカンパニー ビルの\n{JPN}ドアロックを はずせる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CardKey,
        .iconPalette = gItemIconPalette_CardKey,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = ITEM_NAME("{JPN}エレベータのカギ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}ロケットだん アジトの\n{JPN}エレベーターを うごかす\n{JPN}ことが できる カギ{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LiftKey,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = ITEM_NAME("{JPN}シルフスコープ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}めに みえない ものを\n{JPN}みられる スコープ\n{JPN}シルフ カンパニーせい{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SilphScope,
        .iconPalette = gItemIconPalette_SilphScope,
    },

    [ITEM_TRI_PASS] =
    {
        .name = ITEM_NAME("{JPN}トライパス{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}トライパス{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}1のしまと 2のしまと\n{JPN}3のしまを いどうする\n{JPN}ふねに のれる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TriPass,
        .iconPalette = gItemIconPalette_TriPass,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = ITEM_NAME("{JPN}レインボーパス{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}レインボーパス{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}クチバシティと\n{JPN}ななしまを いどうする\n{JPN}ふねに のれる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RainbowPass,
        .iconPalette = gItemIconPalette_RainbowPass,
    },

    [ITEM_TEA] =
    {
        .name = ITEM_NAME("{JPN}おちゃ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}おちゃ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}おばあさんが いれた\n{JPN}おいしい おちゃ\n{JPN}かわきを うるおす{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Tea,
        .iconPalette = gItemIconPalette_Tea,
    },

    [ITEM_RUBY] =
    {
        .name = ITEM_NAME("{JPN}ルビー{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ルビー{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}じょうねつを あらわす\n{JPN}うつくしい ほうせき\n{JPN}あかく ひかり かがやく{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Ruby,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = ITEM_NAME("{JPN}サファイア{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}せいじつを あらわす\n{JPN}うつくしい ほうせき\n{JPN}あおく ひかり かがやく{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Sapphire,
    },

    [ITEM_ABILITY_SHIELD] =
    {
        .name = ITEM_NAME("{JPN}とくせいガード{ENG}"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_ABILITY_SHIELD,
        .description = COMPOUND_STRING(
            "{JPN}こせいてきな たて\n{JPN}もたせると あいてに\n{JPN}とくせいを かえられない{ENG}"),
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbilityShield,
        .iconPalette = gItemIconPalette_AbilityShield,
    },

// GEN 9 ITEMS

    [ITEM_CLEAR_AMULET] =
    {
        .name = ITEM_NAME("{JPN}クリアチャーム{ENG}"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_CLEAR_AMULET,
        .description = COMPOUND_STRING(
            "{JPN}もたせると あいての\n{JPN}わざや とくせいで\n{JPN}のうりょくが さがらない{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ClearAmulet,
        .iconPalette = gItemIconPalette_ClearAmulet,
    },

    [ITEM_PUNCHING_GLOVE] =
    {
        .name = ITEM_NAME("{JPN}パンチグローブ{ENG}"),
        .price = 15000,
        .holdEffect = HOLD_EFFECT_PUNCHING_GLOVE,
        .description = COMPOUND_STRING(
            "{JPN}パンチわざの いりょくが\n{JPN}あがり あいてに\n{JPN}ふれてないパンチに なる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PunchingGlove,
        .iconPalette = gItemIconPalette_PunchingGlove,
    },

    [ITEM_COVERT_CLOAK] =
    {
        .name = ITEM_NAME("{JPN}おんみつマント{ENG}"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_COVERT_CLOAK,
        .description = COMPOUND_STRING(
            "{JPN}もたせると わざの\n{JPN}ついかこうかを\n{JPN}うけなくなる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CovertCloak,
        .iconPalette = gItemIconPalette_CovertCloak,
    },

    [ITEM_LOADED_DICE] =
    {
        .name = ITEM_NAME("{JPN}いかさまダイス{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}いかさまダイス{ENG}"),
        .price = 20000,
        .holdEffect = HOLD_EFFECT_LOADED_DICE,
        .description = COMPOUND_STRING(
            "{JPN}もたせて れんぞくわざを\n{JPN}つかうと おおめに\n{JPN}わざを だすことが できる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LoadedDice,
        .iconPalette = gItemIconPalette_LoadedDice,
    },

    [ITEM_AUSPICIOUS_ARMOR] =
    {
        .name = ITEM_NAME("{JPN}イワイノヨロイ{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}いわいの よろい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_AuspiciousArmor,
        .iconPalette = gItemIconPalette_AuspiciousArmor,
    },

    [ITEM_BOOSTER_ENERGY] =
    {
        .name = ITEM_NAME("{JPN}ブーストエナジー{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ブーストエナジー{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_BOOSTER_ENERGY,
        .description = COMPOUND_STRING(
            "{JPN}あるとくせいを もつ\n{JPN}ポケモンに もたせると\n{JPN}ちからが ブーストする{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BoosterEnergy,
        .iconPalette = gItemIconPalette_BoosterEnergy,
    },

    [ITEM_BIG_BAMBOO_SHOOT] =
    {
        .name = ITEM_NAME("{JPN}おおきなタケノコ{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}おおきな めずらしい\n{JPN}タケノコ グルメには\n{JPN}とてもにんきが ある{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigBambooShoot,
        .iconPalette = gItemIconPalette_BigBambooShoot,
    },

    [ITEM_GIMMIGHOUL_COIN] =
    {
        .name = ITEM_NAME("{JPN}コレクレーのコイン{ENG}"),
        .price = 400,
        .description = COMPOUND_STRING(
            "{JPN}コレクレーが\n{JPN}だいじそうに\n{JPN}あつめている{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GimmighoulCoin,
        .iconPalette = gItemIconPalette_GimmighoulCoin,
    },

    [ITEM_LEADERS_CREST] =
    {
        .name = ITEM_NAME("{JPN}かしらのしるし{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}むれを ひきいる\n{JPN}キリキザンだけが\n{JPN}もっている{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LeadersCrest,
        .iconPalette = gItemIconPalette_LeadersCrest,
    },

    [ITEM_MALICIOUS_ARMOR] =
    {
        .name = ITEM_NAME("{JPN}ノロイノヨロイ{ENG}"),
        .price = 3000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}のろいの よろい{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MaliciousArmor,
        .iconPalette = gItemIconPalette_MaliciousArmor,
    },

    [ITEM_MIRROR_HERB] =
    {
        .name = ITEM_NAME("{JPN}ものまねハーブ{ENG}"),
        .price = 30000,
        .holdEffect = HOLD_EFFECT_MIRROR_HERB,
        .description = COMPOUND_STRING(
            "{JPN}あいての のうりょくが\n{JPN}あがったとき おじように\n{JPN}のうりょくを あげる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_MirrorHerb,
        .iconPalette = gItemIconPalette_MirrorHerb,
    },

    [ITEM_SCROLL_OF_DARKNESS] =
    {
        .name = ITEM_NAME("{JPN}あくのかけじく{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}あくのかけじく{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}あくのごくいの かけじく{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfDarkness,
        .iconPalette = gItemIconPalette_ScrollOfDarkness,
    },

    [ITEM_SCROLL_OF_WATERS] =
    {
        .name = ITEM_NAME("{JPN}みずのかけじく{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}みずのかけじく{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}みずのごくいの かけじく{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfWaters,
        .iconPalette = gItemIconPalette_ScrollOfWaters,
    },

    [ITEM_TERA_ORB] =
    {
        .name = ITEM_NAME("{JPN}テラスタルオーブ{ENG}"),
        .price = 0,
        .description = COMPOUND_STRING(
            "{JPN}エネルギーが チャージ\n{JPN}されていると ポケモンを\n{JPN}テラスタル させる{ENG}"),
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraOrb,
        .iconPalette = gItemIconPalette_TeraOrb,
    },

    [ITEM_TINY_BAMBOO_SHOOT] =
    {
        .name = ITEM_NAME("{JPN}ちいさなタケノコ{ENG}"),
        .price = 750,
        .description = COMPOUND_STRING(
            "{JPN}ちいさな めずらしい\n{JPN}タケノコ グルメには\n{JPN}とてもにんきが ある{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyBambooShoot,
        .iconPalette = gItemIconPalette_TinyBambooShoot,
    },

    [ITEM_BUG_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースむし{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_BugTeraShard,
    },

    [ITEM_DARK_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースあく{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DarkTeraShard,
    },

    [ITEM_DRAGON_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースドラゴン{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DragonTeraShard,
    },

    [ITEM_ELECTRIC_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースでんき{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_ElectricTeraShard,
    },

    [ITEM_FAIRY_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースフェアリー{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FairyTeraShard,
    },

    [ITEM_FIGHTING_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースかくとう{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FightingTeraShard,
    },

    [ITEM_FIRE_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースほのお{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FireTeraShard,
    },

    [ITEM_FLYING_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースひこう{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FlyingTeraShard,
    },

    [ITEM_GHOST_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースゴースト{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GhostTeraShard,
    },

    [ITEM_GRASS_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースくさ{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GrassTeraShard,
    },

    [ITEM_GROUND_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースじめん{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GroundTeraShard,
    },

    [ITEM_ICE_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースこおり{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_IceTeraShard,
    },

    [ITEM_NORMAL_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースノーマル{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_NormalTeraShard,
    },

    [ITEM_POISON_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースどく{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PoisonTeraShard,
    },

    [ITEM_PSYCHIC_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースエスパー{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PsychicTeraShard,
    },

    [ITEM_ROCK_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースいわ{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_RockTeraShard,
    },

    [ITEM_STEEL_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースはがね{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_SteelTeraShard,
    },

    [ITEM_WATER_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}テラピースみず{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_WaterTeraShard,
    },

    [ITEM_ADAMANT_CRYSTAL] =
    {
        .name = ITEM_NAME("{JPN}だいこんごうだま{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}ディアルガに もたせると\n{JPN}ちからが みなぎり\n{JPN}すがたが かわる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantCrystal,
        .iconPalette = gItemIconPalette_AdamantCrystal,
    },

    [ITEM_GRISEOUS_CORE] =
    {
        .name = ITEM_NAME("{JPN}だいはっきんだま{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}ギラティナに もたせると\n{JPN}ちからが みなぎり\n{JPN}すがたが かわる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousCore,
        .iconPalette = gItemIconPalette_GriseousCore,
    },

    [ITEM_LUSTROUS_GLOBE] =
    {
        .name = ITEM_NAME("{JPN}だいしらたま{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}パルキアに もたせると\n{JPN}ちからが みなぎり\n{JPN}すがたが かわる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousGlobe,
        .iconPalette = gItemIconPalette_LustrousGlobe,
    },

    [ITEM_BLACK_AUGURITE] =
    {
        .name = ITEM_NAME("{JPN}くろのきせき{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}するどい くろい いし{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackAugurite,
        .iconPalette = gItemIconPalette_BlackAugurite,
    },

    [ITEM_LINKING_CORD] =
    {
        .name = ITEM_NAME("{JPN} つながりのヒモ{ENG}"),
        .price = 8000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}ふしぎな ヒモ{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LinkingCord,
        .iconPalette = gItemIconPalette_LinkingCord,
    },

    [ITEM_PEAT_BLOCK] =
    {
        .name = ITEM_NAME("{JPN}ピートブロック{ENG}"),
        .price = 10000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}せきたんの かたまり{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PeatBlock,
        .iconPalette = gItemIconPalette_PeatBlock,
    },

    [ITEM_BERSERK_GENE] =
    {
        .name = ITEM_NAME("{JPN}はかいのいでんし{ENG}"),
        .price = 20,
        .holdEffect = HOLD_EFFECT_BERSERK_GENE,
        .description = COMPOUND_STRING(
            "{JPN}こうげきりょくが ぐーんと\n{JPN}あがるが こんらん\n{JPN}じょうたいに なってしまう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerserkGene,
        .iconPalette = gItemIconPalette_BerserkGene,
    },

    [ITEM_FAIRY_FEATHER] =
    {
        .name = ITEM_NAME("{JPN}ようせいのハネ{ENG}"),
        .price = 1000,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンに もたせると\n{JPN}フェアリータイプの\n{JPN}わざのいりょくが あがる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 10,
        .iconPic = gItemIcon_FairyFeather,
        .iconPalette = gItemIconPalette_FairyFeather,
    },

    [ITEM_SYRUPY_APPLE] =
    {
        .name = ITEM_NAME("{JPN}みついりりんご{ENG}"),
        .price = 2200,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}みついり りんご{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SyrupyApple,
        .iconPalette = gItemIconPalette_SyrupyApple,
    },

    [ITEM_UNREMARKABLE_TEACUP] =
    {
        .name = ITEM_NAME("{JPN}ボンサクのちゃわん{ENG}"),
        .price = 1600,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}われている ちゃわん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_UnremarkableTeacup,
        .iconPalette = gItemIconPalette_UnremarkableTeacup,
    },

    [ITEM_MASTERPIECE_TEACUP] =
    {
        .name = ITEM_NAME("{JPN}ケッサクのちゃわん{ENG}"),
        .price = 38000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}かけている ちゃわん{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_MasterpieceTeacup,
        .iconPalette = gItemIconPalette_MasterpieceTeacup,
    },

    [ITEM_CORNERSTONE_MASK] =
    {
        .name = ITEM_NAME("{JPN}いしずえのめん{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}オーガポンに もたせると\n{JPN}いわタイプを まとい\n{JPN}たたかう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CornerstoneMask,
        .iconPalette = gItemIconPalette_CornerstoneMask,
    },

    [ITEM_WELLSPRING_MASK] =
    {
        .name = ITEM_NAME("{JPN}いどのめん{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}オーガポンに もたせると\n{JPN}みずタイプを まとい\n{JPN}たたかう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_WellspringMask,
        .iconPalette = gItemIconPalette_WellspringMask,
    },

    [ITEM_HEARTHFLAME_MASK] =
    {
        .name = ITEM_NAME("{JPN}かまどのめん{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
            "{JPN}オーガポンに もたせると\n{JPN}ほのおタイプを まとい\n{JPN}たたかう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HearthflameMask,
        .iconPalette = gItemIconPalette_HearthflameMask,
    },

    [ITEM_HEALTH_MOCHI] =
    {
        .name = ITEM_NAME("{JPN}たいりょくのもち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}たいりょくのもち{ENG}"),
        .price = 500,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_HealthMochi,
    },

    [ITEM_MUSCLE_MOCHI] =
    {
        .name = ITEM_NAME("{JPN}きんりょくのもち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}きんりょくのもち{ENG}"),
        .price = 500,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_MuscleMochi,
    },

    [ITEM_RESIST_MOCHI] =
    {
        .name = ITEM_NAME("{JPN}ていこうのもち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ていこうのもち{ENG}"),
        .price = 500,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_ResistMochi,
    },

    [ITEM_GENIUS_MOCHI] =
    {
        .name = ITEM_NAME("{JPN}ちりょくのもち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}ちりょくのもち{ENG}"),
        .price = 500,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_GeniusMochi,
    },

    [ITEM_CLEVER_MOCHI] =
    {
        .name = ITEM_NAME("{JPN}せいしんのもち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}せいしんのもち{ENG}"),
        .price = 500,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_CleverMochi,
    },

    [ITEM_SWIFT_MOCHI] =
    {
        .name = ITEM_NAME("{JPN}しゅんぱつのもち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}しゅんぱつのもち{ENG}"),
        .price = 500,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_SwiftMochi,
    },

    [ITEM_FRESH_START_MOCHI] =
    {
        .name = ITEM_NAME("{JPN}まっさらもち{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}まっさらもち{ENG}"),
        .price = 300,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンの\n{JPN}きそポイントが\n{JPN}すべて なくなってしまう{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ResetEVs,
        .effect = gItemEffect_ResetMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_FreshStartMochi,
    },

    [ITEM_GLIMMERING_CHARM] =
    {
        .name = ITEM_NAME("{JPN}きらめくおまもり{ENG}"),
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
            "{JPN}テラレイドバトルで\n{JPN}もらえる テラピースが\n{JPN}ふえる{ENG}"),
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GlimmeringCharm,
        .iconPalette = gItemIconPalette_GlimmeringCharm,
    },

    [ITEM_METAL_ALLOY] =
    {
        .name = ITEM_NAME("{JPN}ふくごうきんぞく{ENG}"),
        .price = 6000,
        .description = COMPOUND_STRING(
            "{JPN}とくていの ポケモンを\n{JPN}しんかさせる\n{JPN}ふしぎな きんぞく{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_MetalAlloy,
        .iconPalette = gItemIconPalette_MetalAlloy,
    },

    [ITEM_STELLAR_TERA_SHARD] =
    {
        .name = ITEM_NAME("{JPN}ステラテラピース{ENG}"),
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StellarTeraShard,
        .iconPalette = gItemIconPalette_StellarTeraShard,
    },

    [ITEM_JUBILIFE_MUFFIN] =
    {
        .name = ITEM_NAME("{JPN}コトブキマフィン{ENG}"),
        .price = 250,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_JubilifeMuffin,
        .iconPalette = gItemIconPalette_JubilifeMuffin,
    },

    [ITEM_REMEDY] =
    {
        .name = ITEM_NAME("{JPN}カンポーやく{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}カンポーやく{ENG}"),
        .price = 150,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンの たいりょくを\n{JPN}20 かいふくする\n{JPN}とても にがい こな{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Remedy,
        .flingPower = 30,
        .iconPic = gItemIcon_Remedy,
        .iconPalette = gItemIconPalette_Remedy,
    },

    [ITEM_FINE_REMEDY] =
    {
        .name = ITEM_NAME("{JPN}いいカンポーやく{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}いいカンポーやく{ENG}"),
        .price = 150,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that restores HP\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 60 points."),
        #else
            "by 50 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FineRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_FineRemedy,
        .iconPalette = gItemIconPalette_FineRemedy,
    },

    [ITEM_SUPERB_REMEDY] =
    {
        .name = ITEM_NAME("{JPN}すごいカンポーやく{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}すごいカンポーやく{ENG}"),
        .price = 750,
        .description = COMPOUND_STRING(
            "A bitter powder\n"
            "that restores HP\n"
        #if I_HEALTH_RECOVERY >= GEN_7
            "by 120 points."),
        #else
            "by 200 points."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperbRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_SuperbRemedy,
        .iconPalette = gItemIconPalette_SuperbRemedy,
    },

    [ITEM_AUX_EVASION] =
    {
        .name = ITEM_NAME("{JPN}ヨクアタラーヌ{ENG}"),
        .price = 800,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises\n"
            "evasiveness during\n"
            "one battle."),
        #else
            "Raises evasiveness\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxEvasion,
    },

    [ITEM_AUX_GUARD] =
    {
        .name = ITEM_NAME("{JPN}ガードアップ{ENG}"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises\n"
            "defenses during\n"
            "one battle."),
        #else
            "Raises defenses\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxGuard,
    },

    [ITEM_AUX_POWER] =
    {
        .name = ITEM_NAME("{JPN}パワーアップ{ENG}"),
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises\n"
            "offenses during\n"
            "one battle."),
        #else
            "Raises offenses\n"
            "during one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxPower,
    },

    [ITEM_AUX_POWERGUARD] =
    {
        .name = ITEM_NAME("{JPN}マルチアップ{ENG}"),
        .price = 1200,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
            "Sharply raises\n"
            "offense & defense\n"
            "during one battle."),
        #else
            "Raises offense\n"
            "and defense during\n"
            "one battle."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxPowerguard,
        .iconPalette = gItemIconPalette_AuxPowerguard,
    },

    [ITEM_CHOICE_DUMPLING] =
    {
        .name = ITEM_NAME("{JPN}こだわりちまき{ENG}"),
        .price = 1200,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_ChoiceDumpling,
        .iconPalette = gItemIconPalette_ChoiceDumpling,
    },

    [ITEM_SWAP_SNACK] =
    {
        .name = ITEM_NAME("{JPN}あべこべやき{ENG}"),
        .price = 1200,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_SwapSnack,
        .iconPalette = gItemIconPalette_SwapSnack,
    },

    [ITEM_TWICE_SPICED_RADISH] =
    {
        .name = ITEM_NAME("{JPN}にばいづけ{ENG}"),
        .pluralName = ITEM_PLURAL_NAME("{JPN}にばいづけ{ENG}"),
        .price = 1600,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_TwiceSpicedRadish,
        .iconPalette = gItemIconPalette_TwiceSpicedRadish,
    },

    [ITEM_POKESHI_DOLL] =
    {
        .name = ITEM_NAME("{JPN}ポケモンこけし{ENG}"),
        .price = 2000,
        .description = COMPOUND_STRING(
            "{JPN}ポケモンを かたどった\n{JPN}もくせいの おもちゃ\n{JPN}おみせで うれる{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_PokeshiDoll,
        .iconPalette = gItemIconPalette_PokeshiDoll,
    },

    // Wishes of Tomorrow: Mega Stones for the custom Megas (round 112)
    [ITEM_AMOONGUSSITE] =
    {
        .name = ITEM_NAME("{JPN}モロバレルナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}モロバレルにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Amoongussite,
        .iconPalette = gItemIconPalette_Amoongussite,
    },

    [ITEM_AZUMARILLITE] =
    {
        .name = ITEM_NAME("{JPN}マリルリナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}マリルリにもたせるとせんと\nうちゅうにメガシンカできる\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Azumarillite,
        .iconPalette = gItemIconPalette_Azumarillite,
    },

    [ITEM_BUTTERFRITE] =
    {
        .name = ITEM_NAME("{JPN}バタフリーナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}バタフリーにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Butterfrite,
        .iconPalette = gItemIconPalette_Butterfrite,
    },

    [ITEM_CONKELDURRITE] =
    {
        .name = ITEM_NAME("{JPN}ローブシンナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ローブシンにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Conkeldurrite,
        .iconPalette = gItemIconPalette_Conkeldurrite,
    },

    [ITEM_DUGTRIONITE] =
    {
        .name = ITEM_NAME("{JPN}ダグトリオナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ダグトリオにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dugtrionite,
        .iconPalette = gItemIconPalette_Dugtrionite,
    },

    [ITEM_ELECTIVIRITE] =
    {
        .name = ITEM_NAME("{JPN}エレキブルナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}エレキブルにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Electivirite,
        .iconPalette = gItemIconPalette_Electivirite,
    },

    [ITEM_FLYGONITE] =
    {
        .name = ITEM_NAME("{JPN}フライゴナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}フライゴンにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Flygonite,
        .iconPalette = gItemIconPalette_Flygonite,
    },

    [ITEM_GOLEMITE] =
    {
        .name = ITEM_NAME("{JPN}ゴローニャナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ゴローニャにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golemite,
        .iconPalette = gItemIconPalette_Golemite,
    },

    [ITEM_JUMPLUFFITE] =
    {
        .name = ITEM_NAME("{JPN}ワタッコナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ワタッコにもたせるとせんと\nうちゅうにメガシンカできる\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Jumpluffite,
        .iconPalette = gItemIconPalette_Jumpluffite,
    },

    [ITEM_KABUTOPSITE] =
    {
        .name = ITEM_NAME("{JPN}カブトプスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}カブトプスにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Kabutopsite,
        .iconPalette = gItemIconPalette_Kabutopsite,
    },

    [ITEM_MAGMORTARITE] =
    {
        .name = ITEM_NAME("{JPN}ブーバーナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ブーバーンにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Magmortarite,
        .iconPalette = gItemIconPalette_Magmortarite,
    },

    [ITEM_MILOTICITE] =
    {
        .name = ITEM_NAME("{JPN}ミロカロスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ミロカロスにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Miloticite,
        .iconPalette = gItemIconPalette_Miloticite,
    },

    [ITEM_OMASTARITE] =
    {
        .name = ITEM_NAME("{JPN}オムスターナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}オムスターにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Omastarite,
        .iconPalette = gItemIconPalette_Omastarite,
    },

    [ITEM_POLIWRATHITE] =
    {
        .name = ITEM_NAME("{JPN}ニョロボンナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ニョロボンにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Poliwrathite,
        .iconPalette = gItemIconPalette_Poliwrathite,
    },

    [ITEM_SHIFTRITE] =
    {
        .name = ITEM_NAME("{JPN}ダーテングナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}ダーテングにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Shiftrite,
        .iconPalette = gItemIconPalette_Shiftrite,
    },

    [ITEM_SNORLAXITE] =
    {
        .name = ITEM_NAME("{JPN}カビゴンナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}カビゴンにもたせるとせんと\nうちゅうにメガシンカできる\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Snorlaxite,
        .iconPalette = gItemIconPalette_Snorlaxite,
    },

    [ITEM_TORKOALITE] =
    {
        .name = ITEM_NAME("{JPN}コータスナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}コータスにもたせるとせんと\nうちゅうにメガシンカできる\n。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Torkoalite,
        .iconPalette = gItemIconPalette_Torkoalite,
    },

    [ITEM_TYPHLOSIONITE] =
    {
        .name = ITEM_NAME("{JPN}バクフーンナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}バクフーンにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Typhlosionite,
        .iconPalette = gItemIconPalette_Typhlosionite,
    },

    [ITEM_WHIMSICOTTITE] =
    {
        .name = ITEM_NAME("{JPN}エルフーンナイト{ENG}"),
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
            "{JPN}エルフーンにもたせるとせん\nとうちゅうにメガシンカでき\nる。{ENG}"),
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Whimsicottite,
        .iconPalette = gItemIconPalette_Whimsicottite,
    },
};

#undef ITEM_NAME
#undef ITEM_PLURAL_NAME
