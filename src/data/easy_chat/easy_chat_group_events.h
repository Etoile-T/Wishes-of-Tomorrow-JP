const u8 gEasyChatWord_Appeal[] = _("{JPN}アピール{ENG}");
const u8 gEasyChatWord_Events[] = _("{JPN}イベント{ENG}");
const u8 gEasyChatWord_StayAtHome[] = _("{JPN}おるすばん{ENG}");
const u8 gEasyChatWord_Berry[] = _("{JPN}きのみ{ENG}");
const u8 gEasyChatWord_Contest[] = _("{JPN}コンテスト{ENG}");
const u8 gEasyChatWord_Mc[] = _("{JPN}しかいしゃ{ENG}");
const u8 gEasyChatWord_Judge[] = _("{JPN}しんさいん{ENG}");
const u8 gEasyChatWord_Super[] = _("{JPN}スーパー{ENG}");
const u8 gEasyChatWord_Stage[] = _("{JPN}ステージ{ENG}");
const u8 gEasyChatWord_HallOfFame[] = _("{JPN}でんどういり{ENG}");
const u8 gEasyChatWord_Evolution[] = _("{JPN}しんか{ENG}");
const u8 gEasyChatWord_Hyper[] = _("{JPN}ハイパー{ENG}");
const u8 gEasyChatWord_BattleTower[] = _("{JPN}バトルタワー{ENG}");
const u8 gEasyChatWord_Leaders[] = _("{JPN}バトルリーダー{ENG}");
const u8 gEasyChatWord_BattleRoom[] = _("{JPN}バトルルーム{ENG}");
const u8 gEasyChatWord_Hidden[] = _("{JPN}ひでん{ENG}");
const u8 gEasyChatWord_SecretBase[] = _("{JPN}ひみつきち{ENG}");
const u8 gEasyChatWord_Blend[] = _("{JPN}ブレンド{ENG}");
const u8 gEasyChatWord_POKEBLOCK[] = _("{JPN}ポロック{ENG}");
const u8 gEasyChatWord_Master[] = _("{JPN}マスター{ENG}");
const u8 gEasyChatWord_Rank[] = _("{JPN}ランク{ENG}");
const u8 gEasyChatWord_Ribbon[] = _("{JPN}リボン{ENG}");
const u8 gEasyChatWord_Crush[] = _("{JPN}クラッシュ{ENG}");
const u8 gEasyChatWord_Direct[] = _("{JPN}ダイレクト{ENG}");
const u8 gEasyChatWord_Tower[] = _("{JPN}タワー{ENG}");
const u8 gEasyChatWord_Union[] = _("{JPN}ユニオン{ENG}");
const u8 gEasyChatWord_Room[] = _("{JPN}ルーム{ENG}");
const u8 gEasyChatWord_Wireless[] = _("{JPN}ワイヤレス{ENG}");
const u8 gEasyChatWord_Frontier[] = _("{JPN}フロンティア{ENG}");

const struct EasyChatWordInfo gEasyChatGroup_Events[] = {
    [EC_INDEX(EC_WORD_APPEAL)] =
    {
        .text = COMPOUND_STRING("{JPN}アピール{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENTS)] =
    {
        .text = COMPOUND_STRING("{JPN}イベント{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ROOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAY_AT_HOME)] =
    {
        .text = COMPOUND_STRING("{JPN}おるすばん{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_TOWER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BERRY)] =
    {
        .text = COMPOUND_STRING("{JPN}きのみ{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BERRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONTEST)] =
    {
        .text = COMPOUND_STRING("{JPN}コンテスト{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BLEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MC)] =
    {
        .text = COMPOUND_STRING("{JPN}しかいしゃ{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONTEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUDGE)] =
    {
        .text = COMPOUND_STRING("{JPN}しんさいん{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRUSH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUPER)] =
    {
        .text = COMPOUND_STRING("{JPN}スーパー{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIRECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAGE)] =
    {
        .text = COMPOUND_STRING("{JPN}ステージ{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HALL_OF_FAME)] =
    {
        .text = COMPOUND_STRING("{JPN}でんどういり{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLUTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLUTION)] =
    {
        .text = COMPOUND_STRING("{JPN}しんか{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONTIER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HYPER)] =
    {
        .text = COMPOUND_STRING("{JPN}ハイパー{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HALL_OF_FAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_TOWER)] =
    {
        .text = COMPOUND_STRING("{JPN}バトルタワー{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIDDEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADERS)] =
    {
        .text = COMPOUND_STRING("{JPN}バトルリーダー{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HYPER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_ROOM)] =
    {
        .text = COMPOUND_STRING("{JPN}バトルルーム{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUDGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIDDEN)] =
    {
        .text = COMPOUND_STRING("{JPN}ひでん{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET_BASE)] =
    {
        .text = COMPOUND_STRING("{JPN}ひみつきち{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MASTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BLEND)] =
    {
        .text = COMPOUND_STRING("{JPN}ブレンド{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEBLOCK)] =
    {
        .text = COMPOUND_STRING("{JPN}ポロック{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEBLOCK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MASTER)] =
    {
        .text = COMPOUND_STRING("{JPN}マスター{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RANK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RANK)] =
    {
        .text = COMPOUND_STRING("{JPN}ランク{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIBBON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIBBON)] =
    {
        .text = COMPOUND_STRING("{JPN}リボン{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRUSH)] =
    {
        .text = COMPOUND_STRING("{JPN}クラッシュ{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET_BASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIRECT)] =
    {
        .text = COMPOUND_STRING("{JPN}ダイレクト{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOWER)] =
    {
        .text = COMPOUND_STRING("{JPN}タワー{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAY_AT_HOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNION)] =
    {
        .text = COMPOUND_STRING("{JPN}ユニオン{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUPER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROOM)] =
    {
        .text = COMPOUND_STRING("{JPN}ルーム{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOWER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIRELESS)] =
    {
        .text = COMPOUND_STRING("{JPN}ワイヤレス{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONTIER)] =
    {
        .text = COMPOUND_STRING("{JPN}フロンティア{ENG}"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIRELESS),
        .enabled = TRUE,
    },
};
