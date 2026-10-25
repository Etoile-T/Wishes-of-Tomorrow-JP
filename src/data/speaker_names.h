const u8 *const gSpeakerNamesTable[SP_NAME_COUNT] =
{
    [SP_NAME_MOM]             = COMPOUND_STRING("{JPN}ママ{ENG}"),
    [SP_NAME_PLAYER]          = COMPOUND_STRING("{PLAYER}"),
    // Wishes of Tomorrow cast. Trainer spellings match src/data/trainers.party
    // so scripted plates look identical to auto-named battle plates.
    [SP_NAME_CLARKSON]        = COMPOUND_STRING("{JPN}クラークソンはかせ{ENG}"),
    [SP_NAME_HARU]            = COMPOUND_STRING("{JPN}ハル{ENG}"),
    [SP_NAME_MASTER_GEN]      = COMPOUND_STRING("{JPN}ゲンししょう{ENG}"),
    [SP_NAME_MADAM_TSUJI]     = COMPOUND_STRING("{JPN}ツジふじん{ENG}"),
    [SP_NAME_MUTRID_LEADER]   = COMPOUND_STRING("{JPN}???リーダー{ENG}"),
    [SP_NAME_RED_FATALITY]    = COMPOUND_STRING("RedFatality"),
    [SP_NAME_DRACO]           = COMPOUND_STRING("{JPN}ドラコ{ENG}"),
    [SP_NAME_COBRA]           = COMPOUND_STRING("{JPN}コブラ{ENG}"),
    [SP_NAME_MIKMANC]         = COMPOUND_STRING("{JPN}ミクマンク{ENG}"),
    [SP_NAME_MINISTER]        = COMPOUND_STRING("{JPN}だいじん{ENG}"),
    [SP_NAME_YIFFER]          = COMPOUND_STRING("Yiffer"),
    [SP_NAME_TUNNEL_CAPTAIN]  = COMPOUND_STRING("{JPN}マコーミックたいちょう{ENG}"),
    [SP_NAME_GOON]            = COMPOUND_STRING("{JPN}したっぱ{ENG}"),
    [SP_NAME_ORACLE]          = COMPOUND_STRING("{JPN}よげんしゃ{ENG}"),
    [SP_NAME_OLD_WOMAN]       = COMPOUND_STRING("{JPN}おばあさん{ENG}"),
    [SP_NAME_ALLISON]         = COMPOUND_STRING("{JPN}セイレーンのアリソン{ENG}"),
    [SP_NAME_GENGAR]          = COMPOUND_STRING("{JPN}ゲンガー{ENG}"),
    [SP_NAME_RYOKO]           = COMPOUND_STRING("{JPN}リョウコたいちょう{ENG}"),
    [SP_NAME_MUTRID_CAPTAIN]  = COMPOUND_STRING("{JPN}ミュートリッドアルファ{ENG}"),
    [SP_NAME_OPERATIVE]       = COMPOUND_STRING("{JPN}ネッサ{ENG}"),
    [SP_NAME_THE_ONI]         = COMPOUND_STRING("{JPN}オニ{ENG}"),
    [SP_NAME_DEFECTOR]        = COMPOUND_STRING("{JPN}はかせの じょしゅ{ENG}"),
    [SP_NAME_EDWARDS]         = COMPOUND_STRING("{JPN}エドワーズしょうぐん{ENG}"),
    [SP_NAME_LIDA]            = COMPOUND_STRING("{JPN}リダ{ENG}"),
    [SP_NAME_CANARI]          = COMPOUND_STRING("{JPN}カナリィ{ENG}"),
    [SP_NAME_EMMA]            = COMPOUND_STRING("{JPN}エマ{ENG}"),
    [SP_NAME_TAUNIE]          = COMPOUND_STRING("{JPN}トーニー{ENG}"),
    [SP_NAME_TULIP]           = COMPOUND_STRING("{JPN}チューリップ{ENG}"),
    [SP_NAME_JACINTHE]        = COMPOUND_STRING("{JPN}ジャサント{ENG}"),
    [SP_NAME_MABLE]           = COMPOUND_STRING("{JPN}けんきゅういんモミジ{ENG}"),
};

// Name color tier per speaker (see enum SpeakerNameTier). Anyone not listed
// here - including all auto-named trainers - renders with the default colors.
// Red is reserved for Team Mutrid; quest givers are green.
const u8 gSpeakerNameTiers[SP_NAME_COUNT] =
{
    [SP_NAME_MASTER_GEN]    = SPEAKER_TIER_QUEST,
    [SP_NAME_ALLISON]       = SPEAKER_TIER_QUEST,
    [SP_NAME_MUTRID_LEADER] = SPEAKER_TIER_VILLAIN,
    [SP_NAME_DRACO]         = SPEAKER_TIER_VILLAIN,
    [SP_NAME_GOON]          = SPEAKER_TIER_VILLAIN,
    [SP_NAME_GENGAR]        = SPEAKER_TIER_GHOST,
    [SP_NAME_RYOKO]         = SPEAKER_TIER_VILLAIN,
    [SP_NAME_TUNNEL_CAPTAIN] = SPEAKER_TIER_VILLAIN,
    [SP_NAME_THE_ONI]       = SPEAKER_TIER_VILLAIN,
    [SP_NAME_DEFECTOR]      = SPEAKER_TIER_QUEST,
    [SP_NAME_MUTRID_CAPTAIN] = SPEAKER_TIER_VILLAIN,
    // The Legends Z-A cast: dark blue plates (their own class).
    [SP_NAME_LIDA]          = SPEAKER_TIER_ZA_BLUE,
    [SP_NAME_CANARI]        = SPEAKER_TIER_ZA_YELLOW,
    [SP_NAME_EMMA]          = SPEAKER_TIER_ZA,
    [SP_NAME_TAUNIE]        = SPEAKER_TIER_ZA,
    [SP_NAME_TULIP]         = SPEAKER_TIER_ZA,
    [SP_NAME_JACINTHE]      = SPEAKER_TIER_ZA_PURPLE,
    [SP_NAME_MABLE]         = SPEAKER_TIER_ZA_GREEN,  // green: who to report back to
};
