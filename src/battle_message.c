#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_util.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_special.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "trainer_slide.h"
#include "trainer_tower.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    union {
        struct {
            DEPRECATED("Use color.background instead") u8 bgColor;
            DEPRECATED("Use color.foreground instead") u8 fgColor;
            DEPRECATED("Use color.shadow instead") u8 shadowColor;
            DEPRECATED("Use color.accent instead") u8 accentColor;
        };
        union TextColor color;
    };
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
};

#if TESTING
EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#else
static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#endif
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_EmptyString4[] = _("");

const u8 gText_PkmnShroudedInMist[] = _("{JPN}{ENG}{B_ATK_TEAM1}{JPN}の ポケモンたちは しろい きりに つつまれた！{ENG}");
const u8 gText_PkmnGettingPumped[] = _("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は はりきっている！{ENG}");
const u8 gText_PkmnsXPreventsSwitching[] = _("{JPN}{ENG}{B_BUFF1}{JPN}の {ENG}{B_LAST_ABILITY}{JPN}で いれかえが できない！\p{ENG}");
const u8 gText_StatSharply[] = _("{JPN}ぐーんと {ENG}");
const u8 gText_StatRose[] = _("{JPN}あがった！{ENG}");
const u8 gText_StatFell[] = _("{JPN}さがった！{ENG}");
const u8 gText_DefendersStatRose[] = _("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}あがった！{ENG}");
static const u8 sText_GotAwaySafely[] = _("{JPN}{PLAY_SE SE_FLEE}うまく にげきれた！\p{ENG}");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}との しょうぶに かった！{ENG}");
static const u8 sText_TwoLinkTrainersDefeated[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}と {ENG}{B_LINK_OPPONENT2_NAME}{JPN}との しょうぶに かった！{ENG}");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}との しょうぶに まけた！{ENG}");
static const u8 sText_PlayerLostToTwo[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}と {ENG}{B_LINK_OPPONENT2_NAME}{JPN}との しょうぶに まけた！{ENG}");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}との しょうぶは ひきわけ！{ENG}");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}と {ENG}{B_LINK_OPPONENT2_NAME}{JPN}との しょうぶは ひきわけ！{ENG}");
static const u8 sText_WildFled[] = _("{JPN}{PLAY_SE SE_FLEE}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}は にげだした！{ENG}"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_TwoWildFled[] = _("{JPN}{PLAY_SE SE_FLEE}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}と {ENG}{B_LINK_OPPONENT2_NAME}{JPN}は にげだした！{ENG}"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}との しょうぶに かった！\p{ENG}");
static const u8 sText_OpponentMon1Appeared[] = _("{JPN}{ENG}{B_OPPONENT_MON1_NAME}{JPN}が あらわれた！\p{ENG}");
static const u8 sText_WildPkmnAppeared[] = _("{JPN}あっ！ やせいの {ENG}{B_OPPONENT_MON1_NAME}{JPN}が とびだしてきた！\p{ENG}");
static const u8 sText_LegendaryPkmnAppeared[] = _("{JPN}あっ！ やせいの {ENG}{B_OPPONENT_MON1_NAME}{JPN}が とびだしてきた！\p{ENG}");
static const u8 sText_WildPkmnAppearedPause[] = _("{JPN}あっ！ やせいの {ENG}{B_OPPONENT_MON1_NAME}{JPN}が とびだしてきた！{PAUSE 127}{ENG}");
static const u8 sText_TwoWildPkmnAppeared[] = _("{JPN}あっ！ やせいの {ENG}{B_OPPONENT_MON1_NAME}{JPN}と {ENG}{B_OPPONENT_MON2_NAME}{JPN}が とびだしてきた！\p{ENG}");
static const u8 sText_GhostAppearedCantId[] = _("{JPN}ゆうれいが あらわれた！\pくそっ！\nゆうれいの しょうたいが わからない！\p{ENG}");
static const u8 sText_TheGhostAppeared[] = _("{JPN}ゆうれいが あらわれた！\p{ENG}");
static const u8 sText_Trainer1WantsToBattle[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}が しょうぶを しかけてきた！\p{ENG}");
static const u8 sText_LinkTrainerWantsToBattle[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}が しょうぶを しかけてきた！{ENG}");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}と {ENG}{B_LINK_OPPONENT2_NAME}{JPN}が しょうぶを しかけてきた！{ENG}");
static const u8 sText_Trainer1SentOutPkmn[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}と {ENG}{B_OPPONENT_MON2_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_Trainer1SentOutPkmn2[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}は {ENG}{B_BUFF1}{JPN}を くりだした！{ENG}");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_LinkTrainer2SentOutPkmn2[] = _("{JPN}{ENG}{B_LINK_OPPONENT2_NAME}{JPN}は {ENG}{B_OPPONENT_MON2_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}と {ENG}{B_OPPONENT_MON2_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}は {ENG}{B_LINK_OPPONENT_MON1_NAME}{JPN}を くりだした！ {ENG}{B_LINK_OPPONENT2_NAME}{JPN}は {ENG}{B_LINK_OPPONENT_MON2_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}は {ENG}{B_BUFF1}{JPN}を くりだした！{ENG}");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{JPN}{ENG}{B_LINK_SCR_TRAINER_NAME}{JPN}は {ENG}{B_BUFF1}{JPN}を くりだした！{ENG}");
static const u8 sText_GoPkmn[] = _("{JPN}ゆけっ！ {ENG}{B_PLAYER_MON1_NAME}{JPN}！{ENG}");
static const u8 sText_GoTwoPkmn[] = _("{JPN}ゆけっ！ {ENG}{B_PLAYER_MON1_NAME}{JPN}！ {ENG}{B_PLAYER_MON2_NAME}{JPN}！{ENG}");
static const u8 sText_GoPkmn2[] = _("{JPN}ゆけっ！ {ENG}{B_BUFF1}{JPN}！{ENG}");
static const u8 sText_DoItPkmn[] = _("{JPN}まかせたぞ！ {ENG}{B_BUFF1}{JPN}！{ENG}");
static const u8 sText_GoForItPkmn[] = _("{JPN}いってこい！ {ENG}{B_BUFF1}{JPN}！{ENG}");
static const u8 sText_JustALittleMorePkmn[] = _("{JPN}あと すこしだ！ がんばれ {ENG}{B_BUFF1}{JPN}！{ENG}"); //currently unused, will require code changes
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("{JPN}あいてが よわってる！ チャンスだ {ENG}{B_BUFF1}{JPN}！{ENG}");
static const u8 sText_LinkPartnerSentOutPkmn1GoPkmn[] = _("{JPN}{ENG}{B_LINK_PARTNER_NAME}{JPN}は {ENG}{B_LINK_PLAYER_MON1_NAME}{JPN}を くりだした！ ゆけっ！ {ENG}{B_LINK_PLAYER_MON2_NAME}{JPN}！{ENG}");
static const u8 sText_LinkPartnerSentOutPkmn2GoPkmn[] = _("{JPN}{ENG}{B_LINK_PARTNER_NAME}{JPN}は {ENG}{B_LINK_PLAYER_MON2_NAME}{JPN}を くりだした！ ゆけっ！ {ENG}{B_LINK_PLAYER_MON1_NAME}{JPN}！{ENG}");
static const u8 sText_LinkPartnerSentOutPkmn1[] = _("{JPN}{ENG}{B_LINK_PARTNER_NAME}{JPN}は {ENG}{B_LINK_PLAYER_MON1_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_LinkPartnerSentOutPkmn2[] = _("{JPN}{ENG}{B_LINK_PARTNER_NAME}{JPN}は {ENG}{B_LINK_PLAYER_MON2_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_LinkPartnerWithdrewPkmn1[] = _("{JPN}{ENG}{B_LINK_PARTNER_NAME}{JPN}は {ENG}{B_LINK_PLAYER_MON1_NAME}{JPN}を ひっこめた！{ENG}");
static const u8 sText_LinkPartnerWithdrewPkmn2[] = _("{JPN}{ENG}{B_LINK_PARTNER_NAME}{JPN}は {ENG}{B_LINK_PLAYER_MON2_NAME}{JPN}を ひっこめた！{ENG}");
static const u8 sText_PkmnSwitchOut[] = _("{JPN}{ENG}{B_BUFF1}{JPN} こうたいだ！ もどれ！{ENG}"); //currently unused, I believe its used for when you switch on a pokemon in shift mode
static const u8 sText_PkmnThatsEnough[] = _("{JPN}{ENG}{B_BUFF1}{JPN} もういい！ もどれ！{ENG}");
static const u8 sText_PkmnComeBack[] = _("{JPN}{ENG}{B_BUFF1}{JPN} もどれ！{ENG}");
static const u8 sText_PkmnOkComeBack[] = _("{JPN}よし {ENG}{B_BUFF1}{JPN}！ もどれ！{ENG}");
static const u8 sText_PkmnGoodComeBack[] = _("{JPN}よくやった {ENG}{B_BUFF1}{JPN}！ もどれ！{ENG}");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}は {ENG}{B_BUFF1}{JPN}を ひっこめた！{ENG}");
static const u8 sText_Trainer2WithdrewPkmn[] = _("{JPN}{ENG}{B_TRAINER2_NAME_WITH_CLASS}{JPN}は {ENG}{B_BUFF1}{JPN}を ひっこめた！{ENG}");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}は {ENG}{B_BUFF1}{JPN}を ひっこめた！{ENG}");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{JPN}{ENG}{B_LINK_OPPONENT2_NAME}{JPN}は {ENG}{B_BUFF1}{JPN}を ひっこめた！{ENG}");
static const u8 sText_WildPkmnPrefix[] = _("{JPN}やせいの {ENG}");
static const u8 sText_FoePkmnPrefix[] = _("{JPN}あいての {ENG}");
static const u8 sText_WildPkmnPrefixLower[] = _("{JPN}やせいの {ENG}");
static const u8 sText_FoePkmnPrefixLower[] = _("{JPN}あいての {ENG}");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("{JPN}あいての{ENG}");
static const u8 sText_AllyPkmnPrefix[] = _("{JPN}みかたの{ENG}");
static const u8 sText_FoePkmnPrefix3[] = _("{JPN}あいての{ENG}");
static const u8 sText_AllyPkmnPrefix2[] = _("{JPN}みかたの{ENG}");
static const u8 sText_FoePkmnPrefix4[] = _("{JPN}あいての{ENG}");
static const u8 sText_AllyPkmnPrefix3[] = _("{JPN}みかたの{ENG}");
static const u8 sText_AttackerUsedX[] = _("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF3}{JPN}！{ENG}");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP[] = _("{JPN}HP{ENG}");
static const u8 sText_Attack[] = _("{JPN}こうげき{ENG}");
static const u8 sText_Defense[] = _("{JPN}ぼうぎょ{ENG}");
static const u8 sText_Speed[] = _("{JPN}すばやさ{ENG}");
static const u8 sText_SpAttack[] = _("{JPN}とくこう{ENG}");
static const u8 sText_SpDefense[] = _("{JPN}とくぼう{ENG}");
static const u8 sText_Accuracy[] = _("{JPN}めいちゅうりつ{ENG}");
static const u8 sText_Evasiveness[] = _("{JPN}かいひりつ{ENG}");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP,
    [STAT_ATK]     = sText_Attack,
    [STAT_DEF]     = sText_Defense,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAttack,
    [STAT_SPDEF]   = sText_SpDefense,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};
const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = COMPOUND_STRING("{JPN}からすぎた！{ENG}"),
    [FLAVOR_DRY]    = COMPOUND_STRING("{JPN}しぶすぎた！{ENG}"),
    [FLAVOR_SWEET]  = COMPOUND_STRING("{JPN}あますぎた！{ENG}"),
    [FLAVOR_BITTER] = COMPOUND_STRING("{JPN}にがすぎた！{ENG}"),
    [FLAVOR_SOUR]   = COMPOUND_STRING("{JPN}すっぱすぎた！{ENG}"),
};

static const u8 sText_Someones[] = _("{JPN}だれかさん{ENG}");
static const u8 sText_Lanettes[] = _("{JPN}マユミ{ENG}"); //no decapitalize until it is everywhere
static const u8 sText_Bills[] = _("{JPN}マサキ{ENG}");
static const u8 sText_EnigmaBerry[] = _("{JPN}ナゾのみ{ENG}"); //no decapitalize until it is everywhere
static const u8 sText_BerrySuffix[] = _("{JPN}のみ{ENG}"); //no decapitalize until it is everywhere
const u8 gText_EmptyString3[] = _("");

static const u8 sText_TwoInGameTrainersDefeated[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}と {ENG}{B_TRAINER2_NAME_WITH_CLASS}{JPN}との しょうぶに かった！\p{ENG}");

// New battle strings.
const u8 gText_drastically[] = _("{JPN}ぐぐーんと {ENG}");
const u8 gText_severely[] = _("{JPN}がくーんと {ENG}");
static const u8 sText_TerrainReturnedToNormal[] = _("{JPN}あしもとが もとに もどった！{ENG}"); // Unused

const u8 *const gBattleStringsTable[STRINGID_COUNT] =
{
    [STRINGID_TRAINER1LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER1_LOSE_TEXT}"),
    [STRINGID_PKMNGAINEDEXP]                        = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は{ENG}{B_BUFF2}{JPN} {ENG}{B_BUFF3}{JPN}けいけんちを もらった！\p{ENG}"),
    [STRINGID_PKMNGREWTOLV]                         = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は レベル{ENG}{B_BUFF2}{JPN}に あがった！{WAIT_SE}\p{ENG}"),
    [STRINGID_PKMNLEARNEDMOVE]                      = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は あたらしく {ENG}{B_BUFF2}{JPN}を おぼえた！{WAIT_SE}\p{ENG}"),
    [STRINGID_TRYTOLEARNMOVE1]                      = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は あたらしく {ENG}{B_BUFF2}{JPN}を おぼえたい…\p{ENG}"),
    [STRINGID_TRYTOLEARNMOVE2]                      = COMPOUND_STRING("{JPN}しかし {ENG}{B_BUFF1}{JPN}は わざを 4つ おぼえるので せいいっぱいだ！\p{ENG}"),
    [STRINGID_TRYTOLEARNMOVE3]                      = COMPOUND_STRING("{JPN}{ENG}{B_BUFF2}{JPN}の かわりに ほかの わざを わすれさせますか？{ENG}"),
    [STRINGID_PKMNFORGOTMOVE]                       = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は {ENG}{B_BUFF2}{JPN}の つかいかたを きれいに わすれた！\p{ENG}"),
    [STRINGID_STOPLEARNINGMOVE]                     = COMPOUND_STRING("{JPN}{PAUSE 32}{ENG}{B_BUFF1}{JPN}に {ENG}{B_BUFF2}{JPN}を おぼえさせるのを あきらめますか？{ENG}"),
    [STRINGID_DIDNOTLEARNMOVE]                      = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は {ENG}{B_BUFF2}{JPN}を おぼえずに おわった！\p{ENG}"),
    [STRINGID_PKMNLEARNEDMOVE2]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}を おぼえた！{ENG}"),
    [STRINGID_ATTACKMISSED]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の こうげきは はずれた！{ENG}"),
    [STRINGID_PKMNPROTECTEDITSELF]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は まもりの たいせいに はいった！{ENG}"),
    [STRINGID_STATSWONTINCREASE2]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の のうりょくは もう あがらない！{ENG}"),
    [STRINGID_ITDOESNTAFFECT]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}には こうかが ないようだ…{ENG}"),
    [STRINGID_SCR_ITDOESNTAFFECT]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}には こうかが ないようだ…{ENG}"),
    [STRINGID_BATTLERFAINTED]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は たおれた！\p{ENG}"),
    [STRINGID_PLAYERGOTMONEY]                       = COMPOUND_STRING("{JPN}しょうきんとして {ENG}{B_BUFF1}{JPN}円 てにいれた！\p{ENG}"),
    [STRINGID_PLAYERWHITEOUT]                       = COMPOUND_STRING("{JPN}たたかえる ポケモンが もう いない！\p{ENG}"),
    [STRINGID_PLAYERWHITEOUT2_WILD]                 = COMPOUND_STRING("{JPN}あわてて {ENG}{B_BUFF1}{JPN}円 おとしてしまった…{ENG}"),
    [STRINGID_PLAYERWHITEOUT2_TRAINER]              = COMPOUND_STRING("{JPN}しょうきんとして {ENG}{B_BUFF1}{JPN}円 わたした…{ENG}"),
    [STRINGID_PLAYERWHITEOUT3]                      = COMPOUND_STRING("{JPN}めのまえが まっくらに なった！{ENG}"),
    [STRINGID_PREVENTSESCAPE]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で にげられない！\p{ENG}"),
    [STRINGID_HITXTIMES]                            = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}かい あたった！{ENG}"), //SV has dynamic plural here
    [STRINGID_PKMNFELLASLEEP]                       = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は ねむって しまった！{ENG}"),
    [STRINGID_PKMNMADESLEEP]                        = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}で {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}は ねむって しまった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYASLEEP]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は すでに ねむっている！{ENG}"),
    [STRINGID_PKMNALREADYASLEEP2]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は すでに ねむっている！{ENG}"),
    [STRINGID_PKMNWASPOISONED]                      = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は どくを あびた！{ENG}"),
    [STRINGID_PKMNPOISONEDBY]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_BUFF1}{JPN}で {ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は どくを あびた！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYPOISON]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は どくの ダメージを うけている！{ENG}"),
    [STRINGID_PKMNALREADYPOISONED]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は すでに どくを うけている！{ENG}"),
    [STRINGID_PKMNBADLYPOISONED]                    = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は もうどくを あびた！{ENG}"),
    [STRINGID_PKMNENERGYDRAINED]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}から たいりょくを すいとった！{ENG}"),
    [STRINGID_PKMNWASBURNED]                        = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は やけどを おった！{ENG}"),
    [STRINGID_PKMNBURNEDBY]                         = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}で {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}は やけどを おった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYBURN]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は やけどの ダメージを うけている！{ENG}"),
    [STRINGID_PKMNWASFROZEN]                        = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は こおりついた！{ENG}"),
    [STRINGID_PKMNFROZENBY]                         = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}で {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}は こおりついた！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNISFROZEN]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は こおってしまって うごかない！{ENG}"),
    [STRINGID_PKMNWASDEFROSTED]                     = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の こおりが とけた！{ENG}"),
    [STRINGID_PKMNWASDEFROSTEDBY]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_CURRENT_MOVE}{JPN}で こおりが とけた！{ENG}"),
    [STRINGID_PKMNWASPARALYZED]                     = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は まひして わざが でにくくなった！{ENG}"),
    [STRINGID_PKMNWASPARALYZEDBY]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}で {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}は まひして わざが でにくくなった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNISPARALYZED]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は からだが しびれて うごけない！{ENG}"),
    [STRINGID_PKMNISALREADYPARALYZED]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は すでに まひしている！{ENG}"),
    [STRINGID_PKMNHEALEDPARALYSIS]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の まひが なおった！{ENG}"),
    [STRINGID_STATSWONTINCREASE]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}は もう あがらない！{ENG}"),
    [STRINGID_STATSWONTDECREASE]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}は もう さがらない！{ENG}"),
    [STRINGID_PKMNISCONFUSED]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は こんらん している！{ENG}"),
    [STRINGID_PKMNHEALEDCONFUSION]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の こんらんが とけた！{ENG}"),
    [STRINGID_PKMNWASCONFUSED]                      = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は こんらんした！{ENG}"),
    [STRINGID_PKMNALREADYCONFUSED]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は すでに こんらん している！{ENG}"),
    [STRINGID_PKMNFELLINLOVE]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は メロメロに なった！{ENG}"),
    [STRINGID_PKMNINLOVE]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}に メロメロだ！{ENG}"),
    [STRINGID_PKMNIMMOBILIZEDBYLOVE]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は メロメロで わざが だせなかった！{ENG}"),
    [STRINGID_PKMNCHANGEDTYPE]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}タイプに なった！{ENG}"),
    [STRINGID_PKMNFLINCHED]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ひるんで わざが だせない！{ENG}"),
    [STRINGID_PKMNREGAINEDHEALTH]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の たいりょくが かいふくした。{ENG}"),
    [STRINGID_PKMNHPFULL]                           = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の HPは まんたんだ！{ENG}"),
    [STRINGID_PKMNRAISEDSPDEF]                      = COMPOUND_STRING("{JPN}ひかりのかべで {ENG}{B_ATK_TEAM2}{JPN}は とくしゅこうげきに つよくなった！{ENG}"),
    [STRINGID_PKMNRAISEDDEF]                        = COMPOUND_STRING("{JPN}リフレクターで {ENG}{B_ATK_TEAM2}{JPN}は ぶつりこうげきに つよくなった！{ENG}"),
    [STRINGID_PKMNCOVEREDBYVEIL]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM1}{JPN}の ポケモンたちは しんぴの ベールに つつまれた！{ENG}"),
    [STRINGID_PKMNUSEDSAFEGUARD]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は しんぴの まもりに まもられている！{ENG}"),
    [STRINGID_PKMNSAFEGUARDEXPIRED]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM1}{JPN}の しんぴの まもりの こうかが きれた！{ENG}"),
    [STRINGID_PKMNWENTTOSLEEP]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ねむりはじめた！{ENG}"), //not in gen 5+
    [STRINGID_PKMNSLEPTHEALTHY]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ねむって げんきに なった！{ENG}"),
    [STRINGID_PKMNWHIPPEDWHIRLWIND]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の まわりで くうきが うずまく！{ENG}"),
    [STRINGID_PKMNTOOKSUNLIGHT]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ひかりを きゅうしゅうした！{ENG}"),
    [STRINGID_PKMNLOWEREDHEAD]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は くびを ひっこめた！{ENG}"),
    [STRINGID_PKMNISGLOWING]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は はげしい ひかりに つつまれた！{ENG}"),
    [STRINGID_PKMNFLEWHIGH]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は そらたかく とびあがった！{ENG}"),
    [STRINGID_PKMNDUGHOLE]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は じめんに もぐった！{ENG}"),
    [STRINGID_PKMNSQUEEZEDBYBIND]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}に しめつけられた！{ENG}"),
    [STRINGID_PKMNTRAPPEDINVORTEX]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は うずの なかに とじこめられた！{ENG}"),
    [STRINGID_PKMNWRAPPEDBY]                        = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}に まきつかれた！{ENG}"),
    [STRINGID_PKMNCLAMPED]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}を からに はさんだ！{ENG}"),
    [STRINGID_PKMNHURTBY]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}の ダメージを うけている！{ENG}"),
    [STRINGID_PKMNFREEDFROM]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}から かいほうされた！{ENG}"),
    [STRINGID_PKMNCRASHED]                          = COMPOUND_STRING("{JPN}いきおいあまって {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は じめんに ぶつかった！{ENG}"),
    [STRINGID_PKMNSHROUDEDINMIST]                   = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は しろいきりに まもられている！{ENG}"),
    [STRINGID_PKMNGETTINGPUMPED]                    = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は はんどうに よる ダメージを うけた！{ENG}"),
    [STRINGID_PKMNPROTECTEDITSELF2]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は まもりの たいせいに はいった！{ENG}"),
    [STRINGID_PKMNBUFFETEDBYSANDSTORM]              = COMPOUND_STRING("{JPN}すなあらしが {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}を おそう！{ENG}"),
    [STRINGID_PKMNPELTEDBYHAIL]                     = COMPOUND_STRING("{JPN}あられが {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}を おそう！{ENG}"),
    [STRINGID_PKMNSEEDED]                           = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}に たねを うえつけた！{ENG}"),
    [STRINGID_PKMNEVADEDATTACK]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は こうげきを かわした！{ENG}"),
    [STRINGID_PKMNSAPPEDBYLEECHSEED]                = COMPOUND_STRING("{JPN}やどりぎが {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の たいりょくを うばう！{ENG}"),
    [STRINGID_PKMNFASTASLEEP]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ぐうぐう ねむっている。{ENG}"),
    [STRINGID_PKMNWOKEUP]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は めを さました！{ENG}"),
    [STRINGID_PKMNWOKEUPINUPROAR]                   = COMPOUND_STRING("{JPN}さわぐ おとで {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}は めを さました！{ENG}"),
    [STRINGID_PKMNCAUSEDUPROAR]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は さわぎだした！{ENG}"),
    [STRINGID_PKMNMAKINGUPROAR]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は さわいでいる！{ENG}"),
    [STRINGID_PKMNCALMEDDOWN]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は おとなしく なった。{ENG}"),
    [STRINGID_PKMNSTOCKPILED]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}つ たくわえた！{ENG}"),
    [STRINGID_PKMNCANTSLEEPINUPROAR2]               = COMPOUND_STRING("{JPN}しかし {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}は さわがしくて ねむれない！{ENG}"),
    [STRINGID_UPROARKEPTPKMNAWAKE]                  = COMPOUND_STRING("{JPN}しかし さわぎで {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}は ねむれない！{ENG}"),
    [STRINGID_PKMNSTAYEDAWAKEUSING]                 = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で ねむらなかった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSTORINGENERGY]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は がまんを している！{ENG}"),
    [STRINGID_PKMNUNLEASHEDENERGY]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の がまんが とかれた！{ENG}"),
    [STRINGID_PKMNFATIGUECONFUSION]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は つかれはてて こんらんした！{ENG}"),
    [STRINGID_PLAYERPICKEDUPMONEY]                  = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}円 ひろった！\p{ENG}"),
    [STRINGID_PKMNUNAFFECTED]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}には こうかが なかった！{ENG}"),
    [STRINGID_PKMNTRANSFORMEDINTO]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}に へんしんした！{ENG}"),
    [STRINGID_PKMNMADESUBSTITUTE]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の ぶんしんが あらわれた！{ENG}"),
    [STRINGID_PKMNHASSUBSTITUTE]                    = COMPOUND_STRING("{JPN}しかし {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の ぶんしんは すでに でていた！{ENG}"),
    [STRINGID_SUBSTITUTEDAMAGED]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}に かわって ぶんしんが こうげきを うけた！\p{ENG}"),
    [STRINGID_PKMNSUBSTITUTEFADED]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の ぶんしんは きえてしまった！\p{ENG}"),
    [STRINGID_PKMNMUSTRECHARGE]                     = COMPOUND_STRING("{JPN}こうげきの はんどうで {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は うごけない！{ENG}"),
    [STRINGID_PKMNRAGEBUILDING]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の いかりの ボルテージが あがっていく！{ENG}"),
    [STRINGID_PKMNMOVEWASDISABLED]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}を ふうじこめた！{ENG}"),
    [STRINGID_PKMNMOVEISDISABLED]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は かなしばりで {ENG}{B_CURRENT_MOVE}{JPN}が だせない！\p{ENG}"),
    [STRINGID_PKMNMOVEDISABLEDNOMORE]               = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の かなしばりが とけた！{ENG}"),
    [STRINGID_PKMNGOTENCORE]                        = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は アンコールを うけた！{ENG}"),
    [STRINGID_PKMNGOTENCOREDMOVE]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_CURRENT_MOVE}{JPN}しか だせない！\p{ENG}"),
    [STRINGID_PKMNENCOREENDED]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の アンコールが とけた！{ENG}"),
    [STRINGID_PKMNTOOKAIM]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}に ねらいを さだめた！{ENG}"),
    [STRINGID_PKMNSKETCHEDMOVE]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}を スケッチした！{ENG}"),
    [STRINGID_PKMNTRYINGTOTAKEFOE]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてを みちづれに しようとしている！{ENG}"),
    [STRINGID_PKMNTOOKFOE]                          = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は あいてを みちづれに した！{ENG}"),
    [STRINGID_PKMNREDUCEDPP]                        = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}の PPを {ENG}{B_BUFF2}{JPN}けずった！{ENG}"),
    [STRINGID_PKMNSTOLEITEM]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}から {ENG}{B_LAST_ITEM}{JPN}を うばいとった！{ENG}"),
    [STRINGID_TARGETCANTESCAPENOW]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は もう にげられない！{ENG}"),
    [STRINGID_PKMNFELLINTONIGHTMARE]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は あくむを みはじめた！{ENG}"),
    [STRINGID_PKMNLOCKEDINNIGHTMARE]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あくむに うなされている！{ENG}"),
    [STRINGID_PKMNLAIDCURSE]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は じぶんの たいりょくを けずって {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}に のろいを かけた！{ENG}"),
    [STRINGID_PKMNAFFLICTEDBYCURSE]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は のろわれている！{ENG}"),
    [STRINGID_SPIKESSCATTERED]                      = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM2}{JPN}の あしもとに まきびしが ちらばった！{ENG}"),
    [STRINGID_PKMNHURTBYSPIKES]                     = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は まきびしの ダメージを うけた！{ENG}"),
    [STRINGID_PKMNIDENTIFIED]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の しょうたいを みやぶった！{ENG}"),
    [STRINGID_PKMNPERISHCOUNTFELL]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の ほろびの カウントが {ENG}{B_BUFF1}{JPN}に なった！{ENG}"),
    [STRINGID_PKMNBRACEDITSELF]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は こらえる たいせいに はいった！{ENG}"),
    [STRINGID_PKMNENDUREDHIT]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は こうげきを こらえた！{ENG}"),
    [STRINGID_MAGNITUDESTRENGTH]                    = COMPOUND_STRING("{JPN}マグニチュード {ENG}{B_BUFF1}{JPN}！{ENG}"),
    [STRINGID_PKMNCUTHPMAXEDATTACK]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は たいりょくを けずって パワーぜんかい！{ENG}"),
    [STRINGID_PKMNCOPIEDSTATCHANGES]                = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}の のうりょくへんかを コピーした！{ENG}"),
    [STRINGID_PKMNGOTFREE]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_BUFF1}{JPN}から ぬけだした！{ENG}"), //not in gen 5+, generic rapid spin?
    [STRINGID_PKMNSHEDLEECHSEED]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は やどりぎのタネを ふりはらった！{ENG}"), //not in gen 5+, generic rapid spin?
    [STRINGID_PKMNBLEWAWAYSPIKES]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は まきびしを ふきとばした！{ENG}"), //not in gen 5+, generic rapid spin?
    [STRINGID_PKMNFLEDFROMBATTLE]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は せんとうから にげだした！{ENG}"),
    [STRINGID_PKMNFORESAWATTACK]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は みらいに こうげきを よちした！{ENG}"),
    [STRINGID_PKMNTOOKATTACK]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}の こうげきを うけた！{ENG}"),
    [STRINGID_PKMNATTACK]                           = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}の こうげき！{ENG}"), //not in gen 5+
    [STRINGID_PKMNCENTERATTENTION]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ちゅうもくの まとに なった！{ENG}"),
    [STRINGID_PKMNCHARGINGPOWER]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は じゅうでんを はじめた！{ENG}"),
    [STRINGID_NATUREPOWERTURNEDINTO]                = COMPOUND_STRING("{JPN}しぜんのちからは {ENG}{B_CURRENT_MOVE}{JPN}に なった！{ENG}"),
    [STRINGID_PKMNSTATUSNORMAL]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の じょうたいが もとに もどった！{ENG}"),
    [STRINGID_PKMNHASNOMOVESLEFT]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}には だせる わざが ない！\p{ENG}"),
    [STRINGID_PKMNSUBJECTEDTOTORMENT]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は いちゃもんを つけられた！{ENG}"),
    [STRINGID_PKMNCANTUSEMOVETORMENT]               = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は いちゃもんを つけられて おなじ わざを つづけて だせない！\p{ENG}"),
    [STRINGID_PKMNTIGHTENINGFOCUS]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は せいしんを とういつ している！{ENG}"),
    [STRINGID_PKMNFELLFORTAUNT]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ちょうはつに のってしまった！{ENG}"),
    [STRINGID_PKMNCANTUSEMOVETAUNT]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ちょうはつされて {ENG}{B_CURRENT_MOVE}{JPN}が だせない！\p{ENG}"),
    [STRINGID_PKMNREADYTOHELP]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}を てだすけ しようとしている！{ENG}"),
    [STRINGID_PKMNSWITCHEDITEMS]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてと どうぐを いれかえた！{ENG}"),
    [STRINGID_PKMNCOPIEDFOE]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の とくせいを コピーした！{ENG}"),
    [STRINGID_PKMNWISHCAMETRUE]                     = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}の ねがいごとが かなった！{ENG}"),
    [STRINGID_PKMNPLANTEDROOTS]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ねを はった！{ENG}"),
    [STRINGID_PKMNABSORBEDNUTRIENTS]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ねから ようぶんを すいとった！{ENG}"),
    [STRINGID_PKMNANCHOREDITSELF]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ねを はって うごかない！{ENG}"),
    [STRINGID_PKMNWASMADEDROWSY]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の ねむけを さそった！{ENG}"),
    [STRINGID_PKMNKNOCKEDOFF]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_LAST_ITEM}{JPN}を はたきおとした！{ENG}"),
    [STRINGID_PKMNSWAPPEDABILITIES]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてと とくせいを いれかえた！{ENG}"),
    [STRINGID_PKMNSEALEDOPPONENTMOVE]               = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてと おなじ わざを ふういんした！{ENG}"),
    [STRINGID_PKMNCANTUSEMOVESEALED]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ふういんされた {ENG}{B_CURRENT_MOVE}{JPN}が だせない！\p{ENG}"),
    [STRINGID_PKMNWANTSGRUDGE]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてに おんねんを かけようとしている！{ENG}"),
    [STRINGID_PKMNLOSTPPGRUDGE]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}は おんねんで PPが 0に なった！{ENG}"),
    [STRINGID_PKMNSHROUDEDITSELF]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は マジックコートで みを つつんだ！{ENG}"),
    [STRINGID_PKMNMOVEBOUNCED]                      = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_CURRENT_MOVE}{JPN}を はねかえした！{ENG}"),
    [STRINGID_PKMNWAITSFORTARGET]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいての でかたを うかがっている！{ENG}"),
    [STRINGID_PKMNSNATCHEDMOVE]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の わざを よこどりした！{ENG}"),
    [STRINGID_PKMNMADEITRAIN]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で あめが ふりだした！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNPROTECTEDBY]                      = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で まもられた！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSUSAGE]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_DEF_ABILITY}{JPN}で {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}は {ENG}{B_CURRENT_MOVE}{JPN}が だせない！{ENG}"), //I don't see this in SV text
    [STRINGID_PKMNRESTOREDHPUSING]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_SCR_ABILITY}{JPN}で たいりょくを かいふくした！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNCHANGEDTYPEWITH]                  = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_EFF_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}タイプに なった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSROMANCEWITH]              = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_DEF_ABILITY}{JPN}で メロメロに ならない！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSCONFUSIONWITH]            = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で こんらんしない！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNRAISEDFIREPOWERWITH]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で ほのおタイプの わざの いりょくが あがった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNANCHORSITSELFWITH]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で その ばに ふみとどまった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNCUTSATTACKWITH]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の こうげきが さがった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNPREVENTSSTATLOSSWITH]             = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で のうりょくは さがらない！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTSWITH]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_BUFF1}{JPN}で きずついた！{ENG}"),
    [STRINGID_PKMNTRACED]                           = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}の {ENG}{B_BUFF2}{JPN}を トレースした！{ENG}"),
    [STRINGID_STATSHARPLY]                          = gText_StatSharply,
    [STRINGID_STATHARSHLY]                          = COMPOUND_STRING("{JPN}がくっと {ENG}"),
    [STRINGID_ATTACKERSSTATROSE]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}あがった！{ENG}"),
    [STRINGID_DEFENDERSSTATROSE]                    = gText_DefendersStatRose,
    [STRINGID_SCRIPTINGSTATROSE]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}あがった！{ENG}"),
    [STRINGID_ATTACKERSSTATFELL]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}さがった！{ENG}"),
    [STRINGID_DEFENDERSSTATFELL]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}さがった！{ENG}"),
    [STRINGID_CRITICALHIT]                          = COMPOUND_STRING("{JPN}きゅうしょに あたった！{ENG}"),
    [STRINGID_ONEHITKO]                             = COMPOUND_STRING("{JPN}いちげき ひっさつ！{ENG}"),
    [STRINGID_123POOF]                              = COMPOUND_STRING("{JPN}1 {PAUSE 10}2の…{PAUSE 10}…{PAUSE 10}{PAUSE 20}{PLAY_SE SE_BALL_BOUNCE_1}ポカン！\p{ENG}"),
    [STRINGID_ANDELLIPSIS]                          = COMPOUND_STRING("{JPN}そして…\p{ENG}"),
    [STRINGID_NOTVERYEFFECTIVE]                     = COMPOUND_STRING("{JPN}こうかは いまひとつの ようだ…{ENG}"),
    [STRINGID_SUPEREFFECTIVE]                       = COMPOUND_STRING("{JPN}こうかは ばつぐんだ！{ENG}"),
    [STRINGID_GOTAWAYSAFELY]                        = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED]                         = COMPOUND_STRING("{JPN}{PLAY_SE SE_FLEE}やせいの {ENG}{B_BUFF1}{JPN}は にげだした！{ENG}"),
    [STRINGID_NORUNNINGFROMTRAINERS]                = COMPOUND_STRING("{JPN}だめだ！ トレーナーとの しょうぶから にげることは できない！\p{ENG}"),
    [STRINGID_CANTESCAPE]                           = COMPOUND_STRING("{JPN}にげられない！\p{ENG}"),
    [STRINGID_DONTLEAVEBIRCH]                       = COMPOUND_STRING("{JPN}オダマキはかせ: おいおい！ おいていかないでくれ！\p{ENG}"), //no decapitalize until it is everywhere
    [STRINGID_BUTNOTHINGHAPPENED]                   = COMPOUND_STRING("{JPN}しかし なにも おこらなかった！{ENG}"),
    [STRINGID_BUTITFAILED]                          = COMPOUND_STRING("{JPN}しかし うまく きまらなかった！{ENG}"),
    [STRINGID_ITHURTCONFUSION]                      = COMPOUND_STRING("{JPN}わけも わからず じぶんを こうげきした！{ENG}"),
    [STRINGID_STARTEDTORAIN]                        = COMPOUND_STRING("{JPN}あめが ふりだした！{ENG}"),
    [STRINGID_DOWNPOURSTARTED]                      = COMPOUND_STRING("{JPN}おおあめが ふりだした！{ENG}"), // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
    [STRINGID_RAINCONTINUES]                        = COMPOUND_STRING("{JPN}あめが ふりつづいている。{ENG}"), //not in gen 5+
    [STRINGID_DOWNPOURCONTINUES]                    = COMPOUND_STRING("{JPN}おおあめが ふりつづいている。{ENG}"), // unused
    [STRINGID_RAINSTOPPED]                          = COMPOUND_STRING("{JPN}あめが やんだ。{ENG}"),
    [STRINGID_SANDSTORMBREWED]                      = COMPOUND_STRING("{JPN}すなあらしが ふきあれた！{ENG}"),
    [STRINGID_SANDSTORMRAGES]                       = COMPOUND_STRING("{JPN}すなあらしが ふきあれている。{ENG}"),
    [STRINGID_SANDSTORMSUBSIDED]                    = COMPOUND_STRING("{JPN}すなあらしが おさまった。{ENG}"),
    [STRINGID_SUNLIGHTGOTBRIGHT]                    = COMPOUND_STRING("{JPN}ひざしが つよくなった！{ENG}"),
    [STRINGID_SUNLIGHTSTRONG]                       = COMPOUND_STRING("{JPN}ひざしが つよい。{ENG}"), //not in gen 5+
    [STRINGID_SUNLIGHTFADED]                        = COMPOUND_STRING("{JPN}ひざしが もとに もどった。{ENG}"),
    [STRINGID_STARTEDHAIL]                          = COMPOUND_STRING("{JPN}あられが ふりはじめた！{ENG}"),
    [STRINGID_HAILCONTINUES]                        = COMPOUND_STRING("{JPN}あられが ふりつづいている。{ENG}"),
    [STRINGID_HAILSTOPPED]                          = COMPOUND_STRING("{JPN}あられが やんだ。{ENG}"),
    [STRINGID_STATCHANGESGONE]                      = COMPOUND_STRING("{JPN}すべての のうりょくへんかが もとに もどった！{ENG}"),
    [STRINGID_COINSSCATTERED]                       = COMPOUND_STRING("{JPN}こばんが あたりに ちらばった！{ENG}"),
    [STRINGID_TOOWEAKFORSUBSTITUTE]                 = COMPOUND_STRING("{JPN}しかし ぶんしんを だす たいりょくが たりなかった！{ENG}"),
    [STRINGID_SHAREDPAIN]                           = COMPOUND_STRING("{JPN}おたがいの いたみを わかちあった！{ENG}"),
    [STRINGID_BELLCHIMED]                           = COMPOUND_STRING("{JPN}すずの ねが ひびきわたった！{ENG}"),
    [STRINGID_FAINTINTHREE]                         = COMPOUND_STRING("{JPN}ほろびのうたを きいた ポケモンは 3ターンご に ほろびてしまう！{ENG}"),
    [STRINGID_NOPPLEFT]                             = COMPOUND_STRING("{JPN}わざの のこり ポイントが ない！\p{ENG}"), //not in gen 5+
    [STRINGID_BUTNOPPLEFT]                          = COMPOUND_STRING("{JPN}しかし わざの のこり ポイントが なかった！{ENG}"),
    [STRINGID_PLAYERUSEDITEM]                       = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}を つかった！{ENG}"),
    [STRINGID_WALLYUSEDITEM]                        = COMPOUND_STRING("{JPN}ミツルは {ENG}{B_LAST_ITEM}{JPN}を つかった！{ENG}"), //no decapitalize until it is everywhere
    [STRINGID_TRAINERBLOCKEDBALL]                   = COMPOUND_STRING("{JPN}トレーナーが ボールを はじいた！{ENG}"),
    [STRINGID_DONTBEATHIEF]                         = COMPOUND_STRING("{JPN}ひとの ものを とったら どろぼう！{ENG}"),
    [STRINGID_ITDODGEDBALL]                         = COMPOUND_STRING("{JPN}ボールを よけられた！ この ポケモンは つかまえられない！{ENG}"),
    [STRINGID_PKMNBROKEFREE]                        = COMPOUND_STRING("{JPN}ダメだ！ ポケモンが ボールから でてしまった！{ENG}"),
    [STRINGID_ITAPPEAREDCAUGHT]                     = COMPOUND_STRING("{JPN}ああ！ つかまえたと おもったのに！{ENG}"),
    [STRINGID_AARGHALMOSTHADIT]                     = COMPOUND_STRING("{JPN}ああっ！ もうすこしで つかまえられたのに！{ENG}"),
    [STRINGID_SHOOTSOCLOSE]                         = COMPOUND_STRING("{JPN}くっ！ おしかった！{ENG}"),
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("{JPN}やったー！ {ENG}{B_DEF_NAME}{JPN}を つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p{ENG}"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("{JPN}やったー！ {ENG}{B_DEF_NAME}{JPN}を つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}{ENG}"),
    [STRINGID_GIVENICKNAMECAPTURED]                 = COMPOUND_STRING("{JPN}つかまえた {ENG}{B_DEF_NAME}{JPN}に ニックネームを つけますか？{ENG}"),
    [STRINGID_PKMNDATAADDEDTODEX]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME}{JPN}の データが あたらしく ポケモンずかんに とうろく されます！\p{ENG}"),
    [STRINGID_ITISRAINING]                          = COMPOUND_STRING("{JPN}あめが ふっている！{ENG}"),
    [STRINGID_SANDSTORMISRAGING]                    = COMPOUND_STRING("{JPN}すなあらしが ふきあれている！{ENG}"),
    [STRINGID_CANTESCAPE2]                          = COMPOUND_STRING("{JPN}にげきれなかった！\p{ENG}"),
    [STRINGID_PKMNIGNORESASLEEP]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は いうことを きかずに ねむりつづけている！{ENG}"),
    [STRINGID_PKMNIGNOREDORDERS]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は いうことを きかない！{ENG}"),
    [STRINGID_PKMNBEGANTONAP]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ひるねを はじめた！{ENG}"),
    [STRINGID_PKMNLOAFING]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は なまけている！{ENG}"),
    [STRINGID_PKMNWONTOBEY]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は いうことを きかない！{ENG}"),
    [STRINGID_PKMNTURNEDAWAY]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は そっぽを むいた！{ENG}"),
    [STRINGID_PKMNPRETENDNOTNOTICE]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しらんぷりを した！{ENG}"),
    [STRINGID_ENEMYABOUTTOSWITCHPKMN]               = COMPOUND_STRING("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}は {ENG}{B_BUFF2}{JPN}を くりだそうと している。\pポケモンを いれかえますか？{ENG}"),
    [STRINGID_CREPTCLOSER]                          = COMPOUND_STRING("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}に ちかづいた！{ENG}"), //safari
    [STRINGID_CANTGETCLOSER]                        = COMPOUND_STRING("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は これいじょう ちかづけない！{ENG}"), //safari
    [STRINGID_PKMNWATCHINGCAREFULLY]                = COMPOUND_STRING("{JPN}{ENG}{B_OPPONENT_MON1_NAME}{JPN}は ようすを うかがっている！{ENG}"), //safari
    [STRINGID_PKMNCURIOUSABOUTX]                    = COMPOUND_STRING("{JPN}{ENG}{B_OPPONENT_MON1_NAME}{JPN}は {ENG}{B_BUFF1}{JPN}に きょうみを しめした！{ENG}"), //safari
    [STRINGID_PKMNENTHRALLEDBYX]                    = COMPOUND_STRING("{JPN}{ENG}{B_OPPONENT_MON1_NAME}{JPN}は {ENG}{B_BUFF1}{JPN}に むちゅうだ！{ENG}"), //safari
    [STRINGID_PKMNIGNOREDX]                         = COMPOUND_STRING("{JPN}{ENG}{B_OPPONENT_MON1_NAME}{JPN}は {ENG}{B_BUFF1}{JPN}を まったく きに しなかった！{ENG}"), //safari
    [STRINGID_THREWPOKEBLOCKATPKMN]                 = COMPOUND_STRING("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}に {ENG}{POKEBLOCK}{JPN}を なげた！{ENG}"), //safari
    [STRINGID_OUTOFSAFARIBALLS]                     = COMPOUND_STRING("{JPN}{PLAY_SE SE_DING_DONG}アナウンス: サファリボールが なくなりました！ しゅうりょうです！\p{ENG}"), //safari
    [STRINGID_PKMNSITEMCUREDPARALYSIS]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で まひが なおった！{ENG}"),
    [STRINGID_PKMNSITEMCUREDPOISON]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で どくが なおった！{ENG}"),
    [STRINGID_PKMNSITEMHEALEDBURN]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で やけどが なおった！{ENG}"),
    [STRINGID_PKMNSITEMDEFROSTEDIT]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で こおりが とけた！{ENG}"),
    [STRINGID_PKMNSITEMWOKEIT]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で めを さました！{ENG}"),
    [STRINGID_PKMNSITEMSNAPPEDOUT]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で こんらんが とけた！{ENG}"),
    [STRINGID_PKMNSITEMCUREDPROBLEM]                = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で {ENG}{B_BUFF1}{JPN}が なおった！{ENG}"),
    [STRINGID_PKMNSITEMRESTOREDHEALTH]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で たいりょくを かいふくした！{ENG}"),
    [STRINGID_PKMNSITEMRESTOREDPP]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で {ENG}{B_BUFF1}{JPN}の PPを かいふくした！{ENG}"),
    [STRINGID_PKMNSITEMRESTOREDSTATUS]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で のうりょくへんかを もとに もどした！{ENG}"),
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE]           = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で すこし たいりょくを かいふくした！{ENG}"),
    [STRINGID_ITEMALLOWSONLYYMOVE]                  = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}の こうかで {ENG}{B_CURRENT_MOVE}{JPN}しか だせない！\p{ENG}"),
    [STRINGID_PKMNHUNGONWITHX]                      = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で もちこたえた！{ENG}"),
    [STRINGID_EMPTYSTRING3]                         = gText_EmptyString3,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2]             = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_ABILITY}{JPN}で すこし たいりょくを かいふくした！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM]             = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で すなあらしが おきた！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSYLOSS]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}は さがらない！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXINFATUATEDY]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_DEF_ABILITY}{JPN}で {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}は メロメロに なった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXMADEYINEFFECTIVE]               = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_CURRENT_MOVE}{JPN}は きかなかった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXCUREDYPROBLEM]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}が なおった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_ITSUCKEDLIQUIDOOZE]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ヘドロえきを すいとった！{ENG}"),
    [STRINGID_PKMNTRANSFORMED]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は へんしんした！{ENG}"),
    [STRINGID_ELECTRICITYWEAKENED]                  = COMPOUND_STRING("{JPN}でんきの いりょくが よわまった！{ENG}"),
    [STRINGID_FIREWEAKENED]                         = COMPOUND_STRING("{JPN}ほのおの いりょくが よわまった！{ENG}"),
    [STRINGID_PKMNHIDUNDERWATER]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は すいちゅうに みを ひそめた！{ENG}"),
    [STRINGID_PKMNSPRANGUP]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は とびあがった！{ENG}"),
    [STRINGID_HMMOVESCANTBEFORGOTTEN]               = COMPOUND_STRING("{JPN}ひでんわざは いまは わすれさせられない。\p{ENG}"),
    [STRINGID_XFOUNDONEY]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を ひろってきた！{ENG}"),
    [STRINGID_PLAYERDEFEATEDTRAINER1]               = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA]                        = COMPOUND_STRING("{JPN}ここちよい かおりが ひろがった！{ENG}"),
    [STRINGID_ITEMSCANTBEUSEDNOW]                   = COMPOUND_STRING("{JPN}いまは どうぐを つかえない。{PAUSE 64}{ENG}"), //not in gen 5+, i think
    [STRINGID_USINGITEMSTATOFPKMNROSE]              = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}を つかったので {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}あがった！{ENG}"), //todo: update this, will require code changes
    [STRINGID_USINGITEMSTATOFPKMNFELL]              = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}を つかったので {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}さがった！{ENG}"),
    [STRINGID_PKMNUSEDXTOGETPUMPED]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を つかって はりきっている！{ENG}"),
    [STRINGID_PKMNSXMADEYUSELESS]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_CURRENT_MOVE}{JPN}は むこうに なった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNTRAPPEDBYSANDTOMB]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ありじごくに とらわれた！{ENG}"),
    [STRINGID_EMPTYSTRING4]                         = COMPOUND_STRING(""),
    [STRINGID_ABOOSTED]                             = COMPOUND_STRING("{JPN} おおめに{ENG}"),
    [STRINGID_PKMNSXINTENSIFIEDSUN]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で ひざしが つよくなった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_YOUTHROWABALLNOWRIGHT]                = COMPOUND_STRING("{JPN}ボールを なげるんだね？ ぼ ぼく がんばる！{ENG}"),
    [STRINGID_PKMNSXTOOKATTACK]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で こうげきを ひきうけた！{ENG}"), //In gen 5+ but without naming the ability
    [STRINGID_PKMNCHOSEXASDESTINY]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は はめつのねがいを みらいに たくした！{ENG}"),
    [STRINGID_PKMNLOSTFOCUS]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しゅうちゅうが みだれて わざが だせない！{ENG}"),
    [STRINGID_USENEXTPKMN]                          = COMPOUND_STRING("{JPN}つぎの ポケモンを つかいますか？{ENG}"),
    [STRINGID_PKMNFLEDUSINGITS]                     = COMPOUND_STRING("{JPN}{PLAY_SE SE_FLEE}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を つかって にげだした！\p{ENG}"),
    [STRINGID_PKMNFLEDUSING]                        = COMPOUND_STRING("{JPN}{PLAY_SE SE_FLEE}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_ABILITY}{JPN}で にげだした！\p{ENG}"), //not in gen 5+
    [STRINGID_PKMNWASDRAGGEDOUT]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ひきずりだされた！\p{ENG}"),
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS]            = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で じょうたいが もとに もどった！{ENG}"),
    [STRINGID_TRAINER1USEDITEM]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TRAINER_NAME_WITH_CLASS}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を つかった！{ENG}"),
    [STRINGID_BOXISFULL]                            = COMPOUND_STRING("{JPN}ボックスが いっぱいで もう つかまえられない！\p{ENG}"),
    [STRINGID_PKMNAVOIDEDATTACK]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は こうげきを かわした！{ENG}"),
    [STRINGID_PKMNSXMADEITINEFFECTIVE]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で こうかが なかった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXPREVENTSFLINCHING]              = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_EFF_ABILITY}{JPN}で ひるまない！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYHASBURN]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は すでに やけどを おっている！{ENG}"),
    [STRINGID_STATSWONTDECREASE2]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の のうりょくは もう さがらない！{ENG}"),
    [STRINGID_PKMNSXBLOCKSY]                        = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_CURRENT_MOVE}{JPN}を ふせいだ！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PKMNSXWOREOFF]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM1}{JPN}の {ENG}{B_BUFF1}{JPN}の こうかが きれた！{ENG}"),
    [STRINGID_THEWALLSHATTERED]                     = COMPOUND_STRING("{JPN}かべが くだけちった！{ENG}"), //not in gen5+, uses "your teams light screen wore off!" etc instead
    [STRINGID_PKMNSXCUREDITSYPROBLEM]               = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}が なおった！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_ATTACKERCANTESCAPE]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は にげられない！{ENG}"),
    [STRINGID_PKMNOBTAINEDX]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}を てにいれた。{ENG}"),
    [STRINGID_PKMNOBTAINEDX2]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF2}{JPN}を てにいれた。{ENG}"),
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}を てにいれた。\p{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF2}{JPN}を てにいれた。{ENG}"),
    [STRINGID_BUTNOEFFECT]                          = COMPOUND_STRING("{JPN}しかし こうかは なかった！{ENG}"),
    [STRINGID_TWOENEMIESDEFEATED]                   = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER2_LOSE_TEXT}"),
    [STRINGID_PKMNINCAPABLEOFPOWER]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ちからを だしきれない ようだ！{ENG}"),
    [STRINGID_GLINTAPPEARSINEYE]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の めが きらりと ひかった！{ENG}"),
    [STRINGID_PKMNGETTINGINTOPOSITION]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は みがまえた！{ENG}"),
    [STRINGID_PKMNBEGANGROWLINGDEEPLY]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ひくく うなりはじめた！{ENG}"),
    [STRINGID_PKMNEAGERFORMORE]                     = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は もっと たたかいたがっている！{ENG}"),
    [STRINGID_DEFEATEDOPPONENTBYREFEREE]            = COMPOUND_STRING("{JPN}しんぱんの はんていで {ENG}{B_PLAYER_MON1_NAME}{JPN}は あいての {ENG}{B_OPPONENT_MON1_NAME}{JPN}に かった！{ENG}"),
    [STRINGID_LOSTTOOPPONENTBYREFEREE]              = COMPOUND_STRING("{JPN}しんぱんの はんていで {ENG}{B_PLAYER_MON1_NAME}{JPN}は あいての {ENG}{B_OPPONENT_MON1_NAME}{JPN}に まけた！{ENG}"),
    [STRINGID_TIEDOPPONENTBYREFEREE]                = COMPOUND_STRING("{JPN}しんぱんの はんていで {ENG}{B_PLAYER_MON1_NAME}{JPN}と あいての {ENG}{B_OPPONENT_MON1_NAME}{JPN}は ひきわけ！{ENG}"),
    [STRINGID_QUESTIONFORFEITMATCH]                 = COMPOUND_STRING("{JPN}しょうぶを すてて やめますか？{ENG}"),
    [STRINGID_FORFEITEDMATCH]                       = COMPOUND_STRING("{JPN}しょうぶを すてた。{ENG}"),
    [STRINGID_PKMNTRANSFERREDSOMEONESPC]            = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC]            = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL]                = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL]                = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT]                      = COMPOUND_STRING("{B_TRAINER1_WIN_TEXT}"),
    [STRINGID_TRAINER2WINTEXT]                      = COMPOUND_STRING("{B_TRAINER2_WIN_TEXT}"),
    [STRINGID_ENDUREDSTURDY]                        = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で こうげきを こらえた！{ENG}"),
    [STRINGID_POWERHERB]                            = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で パワーが みなぎった！{ENG}"),
    [STRINGID_HURTBYITEM]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で ダメージを うけた！{ENG}"),
    [STRINGID_GRAVITYINTENSIFIED]                   = COMPOUND_STRING("{JPN}じゅうりょくが つよくなった！{ENG}"),
    [STRINGID_TARGETWOKEUP]                         = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は めを さました！{ENG}"),
    [STRINGID_TAILWINDBLEW]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の うしろから おいかぜが ふきはじめた！{ENG}"),
    [STRINGID_PKMNWENTBACK]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_TRAINER_NAME}{JPN}の もとへ もどっていく！{ENG}"),
    [STRINGID_PKMNCANTUSEITEMSANYMORE]              = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は どうぐが つかえなく なった！{ENG}"),
    [STRINGID_PKMNFLUNG]                            = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を なげつけた！{ENG}"),
    [STRINGID_PKMNPREVENTEDFROMHEALING]             = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は かいふくを ふうじられた！{ENG}"),
    [STRINGID_PKMNSWITCHEDATKANDDEF]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は こうげきと ぼうぎょを いれかえた！{ENG}"),
    [STRINGID_PKMNSABILITYSUPPRESSED]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の とくせいが きかなくなった！{ENG}"),
    [STRINGID_SHIELDEDFROMCRITICALHITS]             = COMPOUND_STRING("{JPN}おまじないで {ENG}{B_ATK_TEAM2}{JPN}は きゅうしょに あたらなくなった！{ENG}"),
    [STRINGID_PKMNACQUIREDABILITY]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の とくせいが {ENG}{B_DEF_ABILITY}{JPN}に なった！{ENG}"),
    [STRINGID_POISONSPIKESSCATTERED]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM2}{JPN}の あしもとに どくびしが ちらばった！{ENG}"),
    [STRINGID_PKMNSWITCHEDSTATCHANGES]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてと のうりょくへんかを いれかえた！{ENG}"),
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER]        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は みずの リングを まとった！{ENG}"),
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM]      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は でんじりょくで ういた！{ENG}"),
    [STRINGID_PKMNTWISTEDDIMENSIONS]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は じくうを ゆがめた！{ENG}"),
    [STRINGID_POINTEDSTONESFLOAT]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM2}{JPN}の まわりに とがった いわが ただよいはじめた！{ENG}"),
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は マグマの うずに とじこめられた！{ENG}"),
    [STRINGID_VANISHEDINSTANTLY]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の すがたが いっしゅんで きえた！{ENG}"),
    [STRINGID_PROTECTEDTEAM]                        = COMPOUND_STRING("{JPN}{ENG}{B_CURRENT_MOVE}{JPN}が {ENG}{B_ATK_TEAM2}{JPN}を まもった！{ENG}"),
    [STRINGID_SHAREDITSGUARD]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてと ガードを わけあった！{ENG}"),
    [STRINGID_SHAREDITSPOWER]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてと パワーを わけあった！{ENG}"),
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON]         = COMPOUND_STRING("{JPN}ぼうぎょと とくぼうが いれかわる ふしぎな くうかんを つくりだした！{ENG}"),
    [STRINGID_BECAMENIMBLE]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の からだが かるくなった！{ENG}"),
    [STRINGID_HURLEDINTOTHEAIR]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は くうちゅうに うかびあがった！{ENG}"),
    [STRINGID_HELDITEMSLOSEEFFECTS]                 = COMPOUND_STRING("{JPN}もちものの こうかが なくなる ふしぎな くうかんを つくりだした！{ENG}"),
    [STRINGID_FELLSTRAIGHTDOWN]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は うちおとされて じめんに おちた！{ENG}"),
    [STRINGID_TARGETCHANGEDTYPE]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}タイプに なった！{ENG}"),
    [STRINGID_KINDOFFER]                            = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は こうい に あまえた！{ENG}"),
    [STRINGID_RESETSTARGETSSTATLEVELS]              = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の のうりょくへんかが もとに もどった！{ENG}"),
    [STRINGID_ALLYSWITCHPOSITION]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}と {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の いちが いれかわった！{ENG}"),
    [STRINGID_REFLECTTARGETSTYPE]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}と おなじ タイプに なった！{ENG}"),
    [STRINGID_EMBARGOENDS]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は また どうぐが つかえるように なった！{ENG}"),
    [STRINGID_ELECTROMAGNETISM]                     = COMPOUND_STRING("{JPN}でんじふゆう{ENG}"),
    [STRINGID_BUFFERENDS]                           = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}の こうかが きれた！{ENG}"),
    [STRINGID_TELEKINESISENDS]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は テレキネシスから かいほうされた！{ENG}"),
    [STRINGID_TAILWINDENDS]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM1}{JPN}の おいかぜが やんだ！{ENG}"),
    [STRINGID_LUCKYCHANTENDS]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM1}{JPN}の おまじないの こうかが きれた！{ENG}"),
    [STRINGID_TRICKROOMENDS]                        = COMPOUND_STRING("{JPN}ゆがんだ じくうが もとに もどった！{ENG}"),
    [STRINGID_WONDERROOMENDS]                       = COMPOUND_STRING("{JPN}ワンダールームが とけて ぼうぎょと とくぼうが もとに もどった！{ENG}"),
    [STRINGID_MAGICROOMENDS]                        = COMPOUND_STRING("{JPN}マジックルームが とけて もちものの こうかが もとに もどった！{ENG}"),
    [STRINGID_MUDSPORTENDS]                         = COMPOUND_STRING("{JPN}どろあそびの こうかが きれた。{ENG}"),
    [STRINGID_WATERSPORTENDS]                       = COMPOUND_STRING("{JPN}みずあそびの こうかが きれた。{ENG}"),
    [STRINGID_GRAVITYENDS]                          = COMPOUND_STRING("{JPN}じゅうりょくが もとに もどった！{ENG}"),
    [STRINGID_AQUARINGHEAL]                         = COMPOUND_STRING("{JPN}みずの リングが {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}の たいりょくを かいふくした！{ENG}"),
    [STRINGID_ELECTRICTERRAINENDS]                  = COMPOUND_STRING("{JPN}あしもとの でんきが きえた。{ENG}"),
    [STRINGID_MISTYTERRAINENDS]                     = COMPOUND_STRING("{JPN}あしもとの きりが きえた。{ENG}"),
    [STRINGID_PSYCHICTERRAINENDS]                   = COMPOUND_STRING("{JPN}あしもとの ふしぎな かんじが きえた！{ENG}"),
    [STRINGID_GRASSYTERRAINENDS]                    = COMPOUND_STRING("{JPN}あしもとの くさが きえた。{ENG}"),
    [STRINGID_TARGETABILITYSTATRAISE]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}あがった！{ENG}"),
    [STRINGID_TARGETSSTATWASMAXEDOUT]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}が さいだいまで あがった！{ENG}"),
    [STRINGID_ATTACKERABILITYSTATRAISE]             = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}あがった！{ENG}"),
    [STRINGID_POISONHEALHPUP]                       = COMPOUND_STRING("{JPN}どくで {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}は すこし かいふくした！{ENG}"), //don't think this message is displayed anymore
    [STRINGID_BADDREAMSDMG]                         = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は いちゃもんを つけられている！{ENG}"),
    [STRINGID_MOLDBREAKERENTERS]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は かたやぶりだ！{ENG}"),
    [STRINGID_TERAVOLTENTERS]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は はじける オーラを はなっている！{ENG}"),
    [STRINGID_TURBOBLAZEENTERS]                     = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は もえさかる オーラを はなっている！{ENG}"),
    [STRINGID_SLOWSTARTENTERS]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ちょうしが あがらない！{ENG}"),
    [STRINGID_SLOWSTARTEND]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ちょうしを とりもどした！{ENG}"),
    [STRINGID_SOLARPOWERHPDROP]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_ABILITY}{JPN}で ダメージを うけた！{ENG}"), //don't think this message is displayed anymore
    [STRINGID_AFTERMATHDMG]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ダメージを うけた！{ENG}"),
    [STRINGID_ANTICIPATIONACTIVATES]                = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は みぶるいした！{ENG}"),
    [STRINGID_FOREWARNACTIVATES]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}は {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_BUFF1}{JPN}を よみとった！{ENG}"),
    [STRINGID_ICEBODYHPGAIN]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_ABILITY}{JPN}で すこし かいふくした！{ENG}"), //don't think this message is displayed anymore
    [STRINGID_SNOWWARNINGHAIL]                      = COMPOUND_STRING("{JPN}あられが ふりはじめた！{ENG}"),
    [STRINGID_FRISKACTIVATES]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_LAST_ITEM}{JPN}を おみとおしだ！{ENG}"),
    [STRINGID_UNNERVEENTERS]                        = COMPOUND_STRING("{JPN}{ENG}{B_EFF_TEAM1}{JPN}の ポケモンは きんちょうして きのみが たべられなくなった！{ENG}"),
    [STRINGID_HARVESTBERRY]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を しゅうかくした！{ENG}"),
    [STRINGID_PROTEANTYPECHANGE]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}タイプに なった！{ENG}"),
    [STRINGID_SYMBIOSISITEMPASS]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ABILITY}{JPN}で {ENG}{B_EFF_NAME_WITH_PREFIX2}{JPN}に {ENG}{B_LAST_ITEM}{JPN}を わたした！{ENG}"),
    [STRINGID_STEALTHROCKDMG]                       = COMPOUND_STRING("{JPN}とがった いわが {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}に くいこんだ！{ENG}"),
    [STRINGID_TOXICSPIKESABSORBED]                  = COMPOUND_STRING("{JPN}{ENG}{B_EFF_TEAM2}{JPN}の あしもとの どくびしが きえさった！{ENG}"),
    [STRINGID_TOXICSPIKESPOISONED]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は どくを あびた！{ENG}"),
    [STRINGID_TOXICSPIKESBADLYPOISONED]             = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は もうどくを あびた！{ENG}"),
    [STRINGID_STICKYWEBSWITCHIN]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ねばねばネットに ひっかかった！{ENG}"),
    [STRINGID_HEALINGWISHCAMETRUE]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}に いやしのねがいが とどいた！{ENG}"),
    [STRINGID_HEALINGWISHHEALED]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は げんきを とりもどした！{ENG}"),
    [STRINGID_LUNARDANCECAMETRUE]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は しんぴの つきあかりに つつまれた！{ENG}"),
    [STRINGID_CURSEDBODYDISABLED]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_DEF_ABILITY}{JPN}で {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}は ふうじられた！{ENG}"),
    [STRINGID_ATTACKERACQUIREDABILITY]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の とくせいが {ENG}{B_ATK_ABILITY}{JPN}に なった！{ENG}"),
    [STRINGID_TARGETABILITYSTATLOWER]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}さがった！{ENG}"),
    [STRINGID_TARGETSTATWONTGOHIGHER]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}は もう あがらない！{ENG}"),
    [STRINGID_PKMNMOVEBOUNCEDABILITY]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_DEF_ABILITY}{JPN}で {ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_CURRENT_MOVE}{JPN}は はねかえされた！{ENG}"),
    [STRINGID_IMPOSTERTRANSFORM]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ABILITY}{JPN}で {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}に へんしんした！{ENG}"),
    [STRINGID_ASSAULTVESTDOESNTALLOW]               = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}の こうかで へんかわざが だせない！\p{ENG}"),
    [STRINGID_GRAVITYPREVENTSUSAGE]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は じゅうりょくの せいで {ENG}{B_CURRENT_MOVE}{JPN}が だせない！\p{ENG}"),
    [STRINGID_HEALBLOCKPREVENTSUSAGE]               = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は かいふくを ふうじられている！\p{ENG}"),
    [STRINGID_NOTDONEYET]                           = COMPOUND_STRING("{JPN}この わざの こうかは まだ みじっそうです！\p{ENG}"),
    [STRINGID_STICKYWEBUSED]                        = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM2}{JPN}の あしもとに ねばねばネットが ひろがった！{ENG}"),
    [STRINGID_QUASHSUCCESS]                         = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の わざは あとまわしに された！{ENG}"),
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は どくびしを ふきとばした！{ENG}"),
    [STRINGID_PKMNBLEWAWAYSTICKYWEB]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ねばねばネットを ふきとばした！{ENG}"),
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ステルスロックを ふきとばした！{ENG}"),
    [STRINGID_IONDELUGEON]                          = COMPOUND_STRING("{JPN}プラズマの つぶが ふりそそいだ！{ENG}"),
    [STRINGID_TOPSYTURVYSWITCHEDSTATS]              = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の のうりょくへんかが ぎゃくてんした！{ENG}"),
    [STRINGID_TERRAINBECOMESMISTY]                  = COMPOUND_STRING("{JPN}あしもとに きりが たちこめた！{ENG}"),
    [STRINGID_TERRAINBECOMESGRASSY]                 = COMPOUND_STRING("{JPN}あしもとに くさが おいしげった！{ENG}"),
    [STRINGID_TERRAINBECOMESELECTRIC]               = COMPOUND_STRING("{JPN}あしもとに でんきが かけめぐる！{ENG}"),
    [STRINGID_TERRAINBECOMESPSYCHIC]                = COMPOUND_STRING("{JPN}あしもとが へんな かんじに なった！{ENG}"),
    [STRINGID_TARGETELECTRIFIED]                    = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の わざに でんきが やどった！{ENG}"),
    [STRINGID_MEGAEVOREACTING]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_LAST_ITEM}{JPN}と {ENG}{B_ATK_TRAINER_NAME}{JPN}の メガリングが はんのうした！{ENG}"), //actually displays the type of mega ring in inventory, but we didnt implement them :(
    [STRINGID_MEGAEVOEVOLVED]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は メガ{ENG}{B_BUFF1}{JPN}に メガシンカした！{ENG}"),
    [STRINGID_DRASTICALLY]                          = gText_drastically,
    [STRINGID_SEVERELY]                             = gText_severely,
    [STRINGID_INFESTATION]                          = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}に まとわりつかれた！{ENG}"),
    [STRINGID_NOEFFECTONTARGET]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}には こうかが ない！{ENG}"),
    [STRINGID_BURSTINGFLAMESHIT]                    = COMPOUND_STRING("{JPN}はじけた ほのおが {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}に あたった！{ENG}"),
    [STRINGID_BESTOWITEMGIVING]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}から {ENG}{B_LAST_ITEM}{JPN}を もらった！{ENG}"),
    [STRINGID_THIRDTYPEADDED]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}に {ENG}{B_BUFF1}{JPN}タイプが ついかされた！{ENG}"),
    [STRINGID_FELLFORFEINT]                         = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は フェイントに ひっかかった！{ENG}"),
    [STRINGID_POKEMONCANNOTUSEMOVE]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_CURRENT_MOVE}{JPN}が だせない！{ENG}"),
    [STRINGID_COVEREDINPOWDER]                      = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は こなまみれに なった！{ENG}"),
    [STRINGID_POWDEREXPLODES]                       = COMPOUND_STRING("{JPN}ほのおが こなに ひきうつって ばくはつした！{ENG}"),
    [STRINGID_BELCHCANTSELECT]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は きのみを たべていないので ゲップが できない！\p{ENG}"),
    [STRINGID_SPECTRALTHIEFSTEAL]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいての のうりょくアップを うばいとった！{ENG}"),
    [STRINGID_GRAVITYGROUNDING]                     = COMPOUND_STRING("{JPN}じゅうりょくで {ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は そらから おちた！{ENG}"),
    [STRINGID_MISTYTERRAINPREVENTS]                 = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ミストフィールドに まもられている！{ENG}"),
    [STRINGID_GRASSYTERRAINHEALS]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は グラスフィールドで かいふくした！{ENG}"),
    [STRINGID_ELECTRICTERRAINPREVENTS]              = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は エレキフィールドに まもられている！{ENG}"),
    [STRINGID_PSYCHICTERRAINPREVENTS]               = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は サイコフィールドに まもられている！{ENG}"),
    [STRINGID_SAFETYGOGGLESPROTECTED]               = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}の おかげで こうかを うけない！{ENG}"),
    [STRINGID_FLOWERVEILPROTECTED]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は はなの ベールに つつまれた！{ENG}"),
    [STRINGID_AROMAVEILPROTECTED]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は アロマベールで まもられている！{ENG}"),
    [STRINGID_CELEBRATEMESSAGE]                     = COMPOUND_STRING("{JPN}おめでとう {ENG}{B_PLAYER_NAME}{JPN}！{ENG}"),
    [STRINGID_USEDINSTRUCTEDMOVE]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}の さしずに したがった！{ENG}"),
    [STRINGID_THROATCHOPENDS]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は また おとの わざが だせるように なった！{ENG}"),
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP]            = COMPOUND_STRING("{JPN}じごくづきの こうかで {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}は いくつかの わざが だせない！\p{ENG}"),
    [STRINGID_LASERFOCUS]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ふかく しゅうちゅうした！{ENG}"),
    [STRINGID_GEMACTIVATES]                         = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}で {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}の いりょくが あがった！{ENG}"),
    [STRINGID_BERRYDMGREDUCES]                      = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}で {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}への ダメージが へった！{ENG}"),
    [STRINGID_AIRBALLOONFLOAT]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ふうせんで うかんでいる！{ENG}"),
    [STRINGID_AIRBALLOONPOP]                        = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の ふうせんが われた！{ENG}"),
    [STRINGID_INCINERATEBURN]                       = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}の {ENG}{B_LAST_ITEM}{JPN}が もえつきた！{ENG}"),
    [STRINGID_BUGBITE]                              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいての {ENG}{B_LAST_ITEM}{JPN}を うばって たべた！{ENG}"),
    [STRINGID_ILLUSIONWOREOFF]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の イリュージョンが とけた！{ENG}"),
    [STRINGID_ATTACKERCUREDTARGETSTATUS]            = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の じょうたいいじょうを なおした！{ENG}"),
    [STRINGID_ATTACKERLOSTFIRETYPE]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は もえつきた！{ENG}"),
    [STRINGID_HEALERCURE]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の {ENG}{B_LAST_ABILITY}{JPN}で {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の じょうたいいじょうが なおった！{ENG}"),
    [STRINGID_SCRIPTINGABILITYSTATRAISE]            = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_BUFF1}{JPN}が {ENG}{B_BUFF2}{JPN}あがった！{ENG}"),
    [STRINGID_RECEIVERABILITYTAKEOVER]              = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}が うばわれた！{ENG}"),
    [STRINGID_PKNMABSORBINGPOWER]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ちからを たくわえている！{ENG}"),
    [STRINGID_NOONEWILLBEABLETORUNAWAY]             = COMPOUND_STRING("{JPN}つぎの ターン だれも にげられなくなった！{ENG}"),
    [STRINGID_DESTINYKNOTACTIVATES]                 = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で メロメロに なった！{ENG}"),
    [STRINGID_CLOAKEDINAFREEZINGLIGHT]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は つめたい ひかりに つつまれた！{ENG}"),
    [STRINGID_CLEARAMULETWONTLOWERSTATS]            = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_LAST_ITEM}{JPN}の こうかで のうりょくは さがらない！{ENG}"),
    [STRINGID_FERVENTWISHREACHED]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TRAINER_NAME}{JPN}の つよい ねがいが {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}に とどいた！{ENG}"),
    [STRINGID_AIRLOCKACTIVATES]                     = COMPOUND_STRING("{JPN}てんきの えいきょうが なくなった。{ENG}"),
    [STRINGID_PRESSUREENTERS]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は プレッシャーを はなっている！{ENG}"),
    [STRINGID_DARKAURAENTERS]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ダークオーラを はなっている！{ENG}"),
    [STRINGID_FAIRYAURAENTERS]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は フェアリーオーラを はなっている！{ENG}"),
    [STRINGID_AURABREAKENTERS]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ほかの ポケモンの オーラを ぎゃくてんさせた！{ENG}"),
    [STRINGID_COMATOSEENTERS]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は うとうと している！{ENG}"),
    [STRINGID_SCREENCLEANERENTERS]                  = COMPOUND_STRING("{JPN}ばの かべが すべて きえさった！{ENG}"),
    [STRINGID_FETCHEDPOKEBALL]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を みつけた！{ENG}"),
    [STRINGID_ASANDSTORMKICKEDUP]                   = COMPOUND_STRING("{JPN}すなあらしが ふきあれた！{ENG}"),
    [STRINGID_PKMNSWILLPERISHIN3TURNS]              = COMPOUND_STRING("{JPN}2ひきとも 3ターンごに ほろびる！{ENG}"),  //don't think this message is displayed anymore
    [STRINGID_AURAFLAREDTOLIFE]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の オーラが もえあがった！{ENG}"),
    [STRINGID_ASONEENTERS]                          = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は とくせいを 2つ もっている！{ENG}"),
    [STRINGID_CURIOUSMEDICINEENTERS]                = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}の のうりょくへんかが もとに もどった！{ENG}"),
    [STRINGID_CANACTFASTERTHANKSTO]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}で こうどうが はやくなった！{ENG}"),
    [STRINGID_MICLEBERRYACTIVATES]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で つぎの わざの めいちゅうを あげた！{ENG}"),
    [STRINGID_PKMNSHOOKOFFTHETAUNT]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ちょうはつを ふりはらった！{ENG}"),
    [STRINGID_PKMNGOTOVERITSINFATUATION]            = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の メロメロが とけた！{ENG}"),
    [STRINGID_ITEMCANNOTBEREMOVED]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の もちものは はずせない！{ENG}"),
    [STRINGID_STICKYBARBTRANSFER]                   = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}が {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}に くっついた！{ENG}"),
    [STRINGID_PKMNBURNHEALED]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の やけどが なおった！{ENG}"),
    [STRINGID_REDCARDACTIVATE]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}に レッドカードを つきつけた！{ENG}"),
    [STRINGID_EJECTBUTTONACTIVATE]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で いれかわった！{ENG}"),
    [STRINGID_ATKGOTOVERINFATUATION]                = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の メロメロが とけた！{ENG}"),
    [STRINGID_TORMENTEDNOMORE]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の いちゃもんが とけた！{ENG}"),
    [STRINGID_HEALBLOCKEDNOMORE]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の かいふくふうじが とけた！{ENG}"),
    [STRINGID_ATTACKERBECAMEFULLYCHARGED]           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は トレーナーとの きずなで ちからが みなぎった！\p{ENG}"),
    [STRINGID_ATTACKERBECAMEASHSPECIES]             = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は サトシゲッコウガに なった！\p{ENG}"),
    [STRINGID_EXTREMELYHARSHSUNLIGHT]               = COMPOUND_STRING("{JPN}ひざしが とても つよくなった！{ENG}"),
    [STRINGID_EXTREMESUNLIGHTFADED]                 = COMPOUND_STRING("{JPN}ひざしが もとに もどった！{ENG}"),
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT]     = COMPOUND_STRING("{JPN}つよい ひざしで みずタイプの こうげきが じょうはつした！{ENG}"),
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = COMPOUND_STRING("{JPN}つよい ひざしは まったく よわまらない！{ENG}"),
    [STRINGID_HEAVYRAIN]                            = COMPOUND_STRING("{JPN}つよい あめが ふりはじめた！{ENG}"),
    [STRINGID_HEAVYRAINLIFTED]                      = COMPOUND_STRING("{JPN}つよい あめが あがった！{ENG}"),
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN]         = COMPOUND_STRING("{JPN}つよい あめで ほのおタイプの こうげきが きえた！{ENG}"),
    [STRINGID_NORELIEFROMHEAVYRAIN]                 = COMPOUND_STRING("{JPN}つよい あめは まったく やまない！{ENG}"),
    [STRINGID_MYSTERIOUSAIRCURRENT]                 = COMPOUND_STRING("{JPN}なぞの らんきりゅうが ひこうタイプの ポケモンを まもっている！{ENG}"),
    [STRINGID_STRONGWINDSDISSIPATED]                = COMPOUND_STRING("{JPN}なぞの らんきりゅうが おさまった！{ENG}"),
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON]          = COMPOUND_STRING("{JPN}なぞの らんきりゅうは ふきやまない！{ENG}"),
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS]           = COMPOUND_STRING("{JPN}なぞの らんきりゅうが こうげきを よわめた！{ENG}"),
    [STRINGID_STUFFCHEEKSCANTSELECT]                = COMPOUND_STRING("{JPN}きのみが ないので わざが だせない！\p{ENG}"),
    [STRINGID_PKMNREVERTEDTOPRIMAL]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の ゲンシカイキ！ げんしの すがたを とりもどした！{ENG}"),
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE]             = COMPOUND_STRING("{JPN}しかし {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}は わざを だせない！{ENG}"),
    [STRINGID_BUTHOOPACANTUSEIT]                    = COMPOUND_STRING("{JPN}しかし {ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}は いまの すがたでは わざを だせない！{ENG}"),
    [STRINGID_BROKETHROUGHPROTECTION]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の まもりを やぶった！{ENG}"),
    [STRINGID_ABILITYALLOWSONLYMOVE]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_ABILITY}{JPN}の こうかで {ENG}{B_CURRENT_MOVE}{JPN}しか だせない！\p{ENG}"),
    [STRINGID_SWAPPEDABILITIES]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は あいてと とくせいを いれかえた！{ENG}"),
    [STRINGID_PASTELVEILENTERS]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}の どくが なおった！{ENG}"),
    [STRINGID_BATTLERTYPECHANGEDTO]                 = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}タイプに なった！{ENG}"),
    [STRINGID_BOTHCANNOLONGERESCAPE]                = COMPOUND_STRING("{JPN}おたがいの ポケモンは にげられなくなった！{ENG}"),
    [STRINGID_CANTESCAPEDUETOUSEDMOVE]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は はいすいのじんで にげられない！{ENG}"),
    [STRINGID_PKMNBECAMEWEAKERTOFIRE]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ほのおに よわくなった！{ENG}"),
    [STRINGID_ABOUTTOUSEPOLTERGEIST]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}に こうげきされそうに なっている！{ENG}"),
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE]       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は タコがためで にげられない！{ENG}"),
    [STRINGID_NEUTRALIZINGGASENTERS]                = COMPOUND_STRING("{JPN}かがくへんかガスが ひろがった！{ENG}"),
    [STRINGID_NEUTRALIZINGGASOVER]                  = COMPOUND_STRING("{JPN}かがくへんかガスの こうかが きれた！{ENG}"),
    [STRINGID_TARGETTOOHEAVY]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は おもすぎて もちあげられない！{ENG}"),
    [STRINGID_PKMNTOOKTARGETHIGH]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}を そらへ つれさった！{ENG}"),
    [STRINGID_PKMNINSNAPTRAP]                       = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は トラバサミに かかった！{ENG}"),
    [STRINGID_METEORBEAMCHARGING]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}に うちゅうの ちからが あふれだす！{ENG}"),
    [STRINGID_HEATUPBEAK]                           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は くちばしを かねつしはじめた！{ENG}"),
    [STRINGID_COURTCHANGE]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は おたがいの ばの こうかを いれかえた！{ENG}"),
    [STRINGID_ZPOWERSURROUNDS]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は Zパワーを みに まとった！{ENG}"),
    [STRINGID_ZMOVEUNLEASHED]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の ぜんりょくの Zわざ！{ENG}"),
    [STRINGID_ZMOVERESETSSTATS]                     = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は Zパワーで さがった のうりょくを もとに もどした！{ENG}"),
    [STRINGID_ZMOVEALLSTATSUP]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は Zパワーで のうりょくが あがった！{ENG}"),
    [STRINGID_ZMOVEZBOOSTCRIT]                      = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は Zパワーで きゅうしょに あたりやすくなった！{ENG}"),
    [STRINGID_ZMOVERESTOREHP]                       = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は Zパワーで たいりょくを かいふくした！{ENG}"),
    [STRINGID_ZMOVESTATUP]                          = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は Zパワーで のうりょくが あがった！{ENG}"),
    [STRINGID_ZMOVEHPTRAP]                          = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は Zパワーで たいりょくが かいふくした！{ENG}"),
    [STRINGID_ATTACKEREXPELLEDTHEPOISON]            = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しんぱい させまいと どくを なおした！{ENG}"),
    [STRINGID_ATTACKERSHOOKITSELFAWAKE]             = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しんぱい させまいと めを さました！{ENG}"),
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS]        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しんぱい させまいと ちからを ふりしぼって まひを なおした！{ENG}"),
    [STRINGID_ATTACKERHEALEDITSBURN]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しんぱい させまいと きあいで やけどを なおした！{ENG}"),
    [STRINGID_ATTACKERMELTEDTHEICE]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しんぱい させまいと あつい きもちで こおりを とかした！{ENG}"),
    [STRINGID_TARGETTOUGHEDITOUT]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は かなしませまいと もちこたえた！{ENG}"),
    [STRINGID_ATTACKERLOSTELECTRICTYPE]             = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は でんきを つかいきった！{ENG}"),
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET]       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は あいてと {ENG}{B_BUFF1}{JPN}を いれかえた！{ENG}"),
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER]         = COMPOUND_STRING("{JPN}{ENG}{B_CURRENT_MOVE}{JPN}を うけて {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}は ちからが みなぎった！{ENG}"),
    [STRINGID_SUNLIGHTACTIVATEDABILITY]             = COMPOUND_STRING("{JPN}ひざしで {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の こだいかっせいが はつどうした！{ENG}"),
    [STRINGID_STATWASHEIGHTENED]                    = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_BUFF1}{JPN}が たかまった！{ENG}"),
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY]      = COMPOUND_STRING("{JPN}エレキフィールドで {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の クォークチャージが はつどうした！{ENG}"),
    [STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT]   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で まわりの ポケモンの {ENG}{B_BUFF1}{JPN}が よわまった！\p{ENG}"),
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN]  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は たおれた なかまから ちからを うけとった！{ENG}"),
    [STRINGID_PKMNSABILITYPREVENTSABILITY]          = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_SCR_ABILITY}{JPN}で {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_DEF_ABILITY}{JPN}は はたらかない！{ENG}"), //not in gen 5+, ability popup
    [STRINGID_PREPARESHELLTRAP]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は トラップシェルを しかけた！{ENG}"),
    [STRINGID_SHELLTRAPDIDNTWORK]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の トラップシェルは ふはつに おわった！{ENG}"),
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM]            = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の まわりの まきびしが きえさった！{ENG}"),
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の まわりの どくびしが きえさった！{ENG}"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM]         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の まわりの ねばねばネットが きえさった！{ENG}"),
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の まわりの とがった いわが きえさった！{ENG}"),
    [STRINGID_COULDNTFULLYPROTECT]                  = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は まもりきれずに ダメージを うけた！{ENG}"),
    [STRINGID_STOCKPILEDEFFECTWOREOFF]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の たくわえた こうかが きえた！{ENG}"),
    [STRINGID_PKMNREVIVEDREADYTOFIGHT]              = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は ふっかつして ふたたび たたかえるように なった！{ENG}"),
    [STRINGID_ITEMRESTOREDSPECIESHEALTH]            = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}の たいりょくが かいふくした。{ENG}"),
    [STRINGID_ITEMCUREDSPECIESSTATUS]               = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}の じょうたいいじょうが なおった！{ENG}"),
    [STRINGID_ITEMRESTOREDSPECIESPP]                = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}の PPが かいふくした！{ENG}"),
    [STRINGID_THUNDERCAGETRAPPED]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}を とじこめた！{ENG}"),
    [STRINGID_PKMNHURTBYFROSTBITE]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しもやけの ダメージを うけた！{ENG}"),
    [STRINGID_PKMNGOTFROSTBITE]                     = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は しもやけを おった！{ENG}"),
    [STRINGID_PKMNSITEMHEALEDFROSTBITE]             = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}で しもやけが なおった！{ENG}"),
    [STRINGID_ATTACKERHEALEDITSFROSTBITE]           = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しんぱい させまいと きあいで しもやけを なおした！{ENG}"),
    [STRINGID_PKMNFROSTBITEHEALED]                  = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の しもやけが なおった！{ENG}"),
    [STRINGID_PKMNFROSTBITEHEALEDBY]                = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の {ENG}{B_CURRENT_MOVE}{JPN}で しもやけが なおった！{ENG}"),
    [STRINGID_MIRRORHERBCOPIED]                     = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ものまねハーブで あいての のうりょくへんかを まねした！{ENG}"),
    [STRINGID_STARTEDSNOW]                          = COMPOUND_STRING("{JPN}ゆきが ふりはじめた！{ENG}"),
    [STRINGID_SNOWCONTINUES]                        = COMPOUND_STRING("{JPN}ゆきが ふりつづいている。{ENG}"), //not in gen 5+ (lol)
    [STRINGID_SNOWSTOPPED]                          = COMPOUND_STRING("{JPN}ゆきが やんだ。{ENG}"),
    [STRINGID_SNOWWARNINGSNOW]                      = COMPOUND_STRING("{JPN}ゆきが ふりはじめた！{ENG}"),
    [STRINGID_PKMNITEMMELTED]                       = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}の {ENG}{B_LAST_ITEM}{JPN}を ふしょく させた！{ENG}"),
    [STRINGID_ULTRABURSTREACTING]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}から まばゆい ひかりが あふれだそうと している！{ENG}"),
    [STRINGID_ULTRABURSTCOMPLETED]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ウルトラバーストで ほんらいの ちからを とりもどした！{ENG}"),
    [STRINGID_TEAMGAINEDEXP]                        = COMPOUND_STRING("{JPN}ほかの てもちの ポケモンも がくしゅうそうちで けいけんちを もらった！\p{ENG}"),
    [STRINGID_CURRENTMOVECANTSELECT]                = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}は つかえない！\p{ENG}"),
    [STRINGID_TARGETISBEINGSALTCURED]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は しおづけ じょうたいに なった！{ENG}"),
    [STRINGID_TARGETISHURTBYSALTCURE]               = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}の ダメージを うけた！{ENG}"),
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP]      = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は ねばねばの みずあめを かぶった！{ENG}"),
    [STRINGID_SHARPSTEELFLOATS]                     = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM2}{JPN}の ポケモンの まわりに とがった はがねが うかびはじめた！{ENG}"),
    [STRINGID_SHARPSTEELDMG]                        = COMPOUND_STRING("{JPN}とがった はがねが {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}に くいこんだ！{ENG}"),
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL]               = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は とがった はがねを ふきとばした！{ENG}"),
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM]        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の ポケモンの まわりの はがねが きえた！{ENG}"),
    [STRINGID_TEAMTRAPPEDWITHVINES]                 = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM1}{JPN}の ポケモンは つるに からめとられた！{ENG}"),
    [STRINGID_PKMNHURTBYVINES]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は キョダイベンタツの はげしい こうげきで ダメージを うけた！{ENG}"),
    [STRINGID_TEAMCAUGHTINVORTEX]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM1}{JPN}の ポケモンは みずの うずに とらわれた！{ENG}"),
    [STRINGID_PKMNHURTBYVORTEX]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は キョダイホウゲキの うずで ダメージを うけた！{ENG}"),
    [STRINGID_TEAMSURROUNDEDBYFIRE]                 = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM1}{JPN}の ポケモンは ほのおに かこまれた！{ENG}"),
    [STRINGID_PKMNBURNINGUP]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は キョダイゴクエンの ほのおで やかれている！{ENG}"),
    [STRINGID_TEAMSURROUNDEDBYROCKS]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM1}{JPN}の ポケモンは いわに かこまれた！{ENG}"),
    [STRINGID_PKMNHURTBYROCKSTHROWN]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は キョダイフンセキの いわで ダメージを うけた！{ENG}"),
    [STRINGID_MOVEBLOCKEDBYDYNAMAX]                 = COMPOUND_STRING("{JPN}ダイマックスの ちからで わざが ふせがれた！{ENG}"),
    [STRINGID_ZEROTOHEROTRANSFORMATION]             = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は えいゆうへと へんしんした！{ENG}"),
    [STRINGID_THETWOMOVESBECOMEONE]                 = COMPOUND_STRING("{JPN}2つの わざが ひとつに！ これは あわせわざだ！{PAUSE 16}{ENG}"),
    [STRINGID_ARAINBOWAPPEAREDONSIDE]               = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の ばに にじが かかった！{ENG}"),
    [STRINGID_THERAINBOWDISAPPEARED]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の ばの にじが きえた！{ENG}"),
    [STRINGID_WAITINGFORPARTNERSMOVE]               = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_ATK_PARTNER_NAME}{JPN}の わざを まっている…{PAUSE 16}{ENG}"),
    [STRINGID_SEAOFFIREENVELOPEDSIDE]               = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM2}{JPN}の ばが ひのうみに つつまれた！{ENG}"),
    [STRINGID_HURTBYTHESEAOFFIRE]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ひのうみの ダメージを うけた！{ENG}"),
    [STRINGID_THESEAOFFIREDISAPPEARED]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の まわりの ひのうみが きえた！{ENG}"),
    [STRINGID_SWAMPENVELOPEDSIDE]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_TEAM2}{JPN}の ばが しっちに つつまれた！{ENG}"),
    [STRINGID_THESWAMPDISAPPEARED]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_TEAM2}{JPN}の まわりの しっちが きえた！{ENG}"),
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE]        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は さむい ギャグを いおうとしている！{ENG}"),
    [STRINGID_HOSPITALITYRESTORATION]               = COMPOUND_STRING("{JPN}{ENG}{B_EFF_NAME_WITH_PREFIX}{JPN}は {ENG}{B_SCR_NAME_WITH_PREFIX2}{JPN}の たてた まっちゃを のみほした！{ENG}"),
    [STRINGID_ELECTROSHOTCHARGING]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は でんきを きゅうしゅうした！{ENG}"),
    [STRINGID_ITEMWASUSEDUP]                        = COMPOUND_STRING("{JPN}{ENG}{B_LAST_ITEM}{JPN}を つかいきった…{ENG}"),
    [STRINGID_ATTACKERLOSTITSTYPE]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}タイプでは なくなった！{ENG}"),
    [STRINGID_SHEDITSTAIL]                          = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は しっぽを きって みがわりに した！{ENG}"),
    [STRINGID_CLOAKEDINAHARSHLIGHT]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は はげしい ひかりに つつまれた！{ENG}"),
    [STRINGID_SUPERSWEETAROMAWAFTS]                 = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX2}{JPN}を おおう みずあめから あまい かおりが ただよう！{ENG}"),
    [STRINGID_DIMENSIONSWERETWISTED]                = COMPOUND_STRING("{JPN}じくうが ゆがんだ！{ENG}"),
    [STRINGID_BIZARREARENACREATED]                  = COMPOUND_STRING("{JPN}もちものの こうかが なくなる ふしぎな くうかんが できた！{ENG}"),
    [STRINGID_BIZARREAREACREATED]                   = COMPOUND_STRING("{JPN}ぼうぎょと とくぼうが いれかわる ふしぎな くうかんが できた！{ENG}"),
    [STRINGID_TIDYINGUPCOMPLETE]                    = COMPOUND_STRING("{JPN}おかたづけ かんりょう！{ENG}"),
    [STRINGID_PKMNTERASTALLIZEDINTO]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は {ENG}{B_BUFF1}{JPN}タイプに テラスタルした！{ENG}"),
    [STRINGID_BOOSTERENERGYACTIVATES]               = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を つかって {ENG}{B_SCR_ABILITY}{JPN}を はつどうした！{ENG}"),
    [STRINGID_FOGCREPTUP]                           = COMPOUND_STRING("{JPN}こい きりが たちこめた！{ENG}"),
    [STRINGID_FOGISDEEP]                            = COMPOUND_STRING("{JPN}きりが ふかい…{ENG}"),
    [STRINGID_FOGLIFTED]                            = COMPOUND_STRING("{JPN}きりが はれた。{ENG}"),
    [STRINGID_PKMNMADESHELLGLEAM]                   = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX}{JPN}は こうらを かがやかせた！ タイプあいしょうを ゆがめている！{ENG}"),
    [STRINGID_FICKLEBEAMDOUBLED]                    = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は この こうげきに ぜんりょくを そそぐ！{ENG}"),
    [STRINGID_COMMANDERACTIVATES]                   = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ヘイラッシャに のみこまれて しれいとうに なった！{ENG}"),
    [STRINGID_POKEFLUTECATCHY]                      = COMPOUND_STRING("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を ふいた。\pなかなか いい ねいろだ！{ENG}"),
    [STRINGID_POKEFLUTE]                            = COMPOUND_STRING("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は {ENG}{B_LAST_ITEM}{JPN}を ふいた。{ENG}"),
    [STRINGID_MONHEARINGFLUTEAWOKE]                 = COMPOUND_STRING("{JPN}ふえの ねを きいた ポケモンは めを さました！{ENG}"),
    [STRINGID_SUNLIGHTISHARSH]                      = COMPOUND_STRING("{JPN}ひざしが つよい！{ENG}"),
    [STRINGID_ITISHAILING]                          = COMPOUND_STRING("{JPN}あられが ふっている！{ENG}"),
    [STRINGID_ITISSNOWING]                          = COMPOUND_STRING("{JPN}ゆきが ふっている！{ENG}"),
    [STRINGID_ISCOVEREDWITHGRASS]                   = COMPOUND_STRING("{JPN}あしもとに くさが おいしげっている！{ENG}"),
    [STRINGID_MISTSWIRLSAROUND]                     = COMPOUND_STRING("{JPN}あしもとに きりが たちこめている！{ENG}"),
    [STRINGID_ELECTRICCURRENTISRUNNING]             = COMPOUND_STRING("{JPN}あしもとに でんきが かけめぐっている！{ENG}"),
    [STRINGID_SEEMSWEIRD]                           = COMPOUND_STRING("{JPN}あしもとが へんな かんじだ！{ENG}"),
    [STRINGID_WAGGLINGAFINGER]                      = COMPOUND_STRING("{JPN}ゆびを ふって {ENG}{B_CURRENT_MOVE}{JPN}が でた！{ENG}"),
    [STRINGID_BLOCKEDBYSLEEPCLAUSE]                 = COMPOUND_STRING("{JPN}ねむりクローズで {ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}は ねむらなかった！{ENG}"),
    [STRINGID_SUPEREFFECTIVETWOFOES]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}と {ENG}{B_DEF_PARTNER_NAME}{JPN}に こうかは ばつぐんだ！{ENG}"),
    [STRINGID_NOTVERYEFFECTIVETWOFOES]              = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}と {ENG}{B_DEF_PARTNER_NAME}{JPN}に こうかは いまひとつだ！{ENG}"),
    [STRINGID_ITDOESNTAFFECTTWOFOES]                = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME_WITH_PREFIX2}{JPN}と {ENG}{B_DEF_PARTNER_NAME}{JPN}には こうかが ないようだ…{ENG}"),
    [STRINGID_SENDCAUGHTMONPARTYORBOX]              = COMPOUND_STRING("{JPN}{ENG}{B_DEF_NAME}{JPN}を てもちに くわえますか？{ENG}"),
    [STRINGID_PKMNSENTTOPCAFTERCATCH]               = gText_PkmnSentToPCAfterCatch,
    [STRINGID_PKMNDYNAMAXED]                        = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は ダイマックスした！{ENG}"),
    [STRINGID_PKMNGIGANTAMAXED]                     = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は キョダイマックスした！{ENG}"),
    [STRINGID_TIMETODYNAMAX]                        = COMPOUND_STRING("{JPN}ダイマックスの ときだ！{ENG}"),
    [STRINGID_TIMETOGIGANTAMAX]                     = COMPOUND_STRING("{JPN}キョダイマックスの ときだ！{ENG}"),
    [STRINGID_QUESTIONFORFEITBATTLE]                = COMPOUND_STRING("{JPN}しょうぶを あきらめて やめますか？ やめると まけに なります。{ENG}"),
    [STRINGID_POWERCONSTRUCTPRESENCEOFMANY]         = COMPOUND_STRING("{JPN}たくさんの けはいを かんじる！{ENG}"),
    [STRINGID_POWERCONSTRUCTTRANSFORM]              = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は パーフェクトフォルムに へんしんした！{ENG}"),
    [STRINGID_ABILITYSHIELDPROTECTS]                = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}の とくせいは {ENG}{B_LAST_ITEM}{JPN}の こうかで まもられている！{ENG}"),
    [STRINGID_MONTOOSCAREDTOMOVE]                   = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は こわくて うごけない！{ENG}"),
    [STRINGID_GHOSTGETOUTGETOUT]                    = COMPOUND_STRING("{JPN}ゆうれい: でてゆけ…… でてゆけ……{ENG}"),
    [STRINGID_SILPHSCOPEUNVEILED]                   = COMPOUND_STRING("{JPN}シルフスコープで ゆうれいの\nしょうたいを みやぶった！{ENG}"),
    [STRINGID_GHOSTWASMAROWAK]                      = COMPOUND_STRING("{JPN}ゆうれいの しょうたいは ガラガラだった！\p\n{ENG}"),
    [STRINGID_TRAINER1MON1COMEBACK]                 = COMPOUND_STRING("{JPN}{ENG}{B_TRAINER1_NAME}{JPN}: {ENG}{B_OPPONENT_MON1_NAME}{JPN} もどれ！{ENG}"),
    [STRINGID_THREWROCK]                            = COMPOUND_STRING("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}に\nいしを なげた！{ENG}"),
    [STRINGID_THREWBAIT]                            = COMPOUND_STRING("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}に\nエサを なげた！{ENG}"),
    [STRINGID_PKMNANGRY]                            = COMPOUND_STRING("{JPN}{ENG}{B_OPPONENT_MON1_NAME}{JPN}は おこっている！{ENG}"),
    [STRINGID_PKMNEATING]                           = COMPOUND_STRING("{JPN}{ENG}{B_OPPONENT_MON1_NAME}{JPN}は エサを たべている！{ENG}"),
    [STRINGID_PKMNDISGUISEWASBUSTED]                = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}の ばけのかわが はがれた！{ENG}"),
    [STRINGID_ZENMODETRIGGERED]                     = COMPOUND_STRING("{JPN}{ENG}{B_SCR_ABILITY}{JPN}が はつどうした！{ENG}"),
    [STRINGID_ZENMODEENDED]                         = COMPOUND_STRING("{JPN}{ENG}{B_SCR_ABILITY}{JPN}の こうかが きれた！{ENG}"),
    // WoT Shadow system -- snagging. No PLAY_BGM here: unlike a wild catch,
    // the battle keeps going, so the battle theme must keep playing.
    [STRINGID_WOTGOTCHASNAGGED]                     = COMPOUND_STRING("{JPN}やったー！ {ENG}{B_DEF_NAME}{JPN}を スナッチした！\p{ENG}"),
    [STRINGID_WOTHYPERMODE]                         = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は リバースモードに なった！{ENG}"),
    [STRINGID_WOTHYPERSETTLES]                      = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}は おちついた。{ENG}"),
    [STRINGID_WOTWILDMEGAREACTING]                  = COMPOUND_STRING("{JPN}{ENG}{B_ATK_NAME_WITH_PREFIX}{JPN}に メガの ちからが あふれている！{ENG}"),
    [STRINGID_WOTCAUGHTTOPARTY]                     = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}を てもちに くわえた！\p{ENG}"),
    [STRINGID_WOTCAUGHTTOPC]                        = COMPOUND_STRING("{JPN}{ENG}{B_BUFF1}{JPN}を パソコンに おくった！\p{ENG}"),
    [STRINGID_WOTSNAGGEDTOPARTY]                    = COMPOUND_STRING("{JPN}スナッチした {ENG}{B_BUFF1}{JPN}を てもちに くわえた！\p{ENG}"),
    [STRINGID_WOTSNAGGEDTOPC]                       = COMPOUND_STRING("{JPN}スナッチした {ENG}{B_BUFF1}{JPN}を パソコンに おくった！\p{ENG}"),
    [STRINGID_WOTSHADOWAURA]                        = COMPOUND_STRING("{JPN}{ENG}{B_SCR_NAME_WITH_PREFIX}{JPN}は ダークオーラに つつまれた！\pちからが みなぎる！{ENG}"),
    [STRINGID_WOTSNAGNICKNAMEQ]                     = COMPOUND_STRING("{JPN}スナッチした {ENG}{B_BUFF1}{JPN}に ニックネームを つけますか？{ENG}"),
};

const u16 gTrainerUsedItemStringIds[] =
{
    STRINGID_PLAYERUSEDITEM, STRINGID_TRAINER1USEDITEM
};

const u16 gZEffectStringIds[] =
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_BUFFERENDS,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
};

const u16 gStartingStatusStringIds[B_MSG_STARTING_STATUS_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_SET_TRICK_ROOM]       = STRINGID_DIMENSIONSWERETWISTED,
    [B_MSG_SET_MAGIC_ROOM]       = STRINGID_BIZARREARENACREATED,
    [B_MSG_SET_WONDER_ROOM]      = STRINGID_BIZARREAREACREATED,
    [B_MSG_SET_TAILWIND]         = STRINGID_TAILWINDBLEW,
    [B_MSG_SET_RAINBOW]          = STRINGID_ARAINBOWAPPEAREDONSIDE,
    [B_MSG_SET_SEA_OF_FIRE]      = STRINGID_SEAOFFIREENVELOPEDSIDE,
    [B_MSG_SET_SWAMP]            = STRINGID_SWAMPENVELOPEDSIDE,
    [B_MSG_SET_SPIKES]           = STRINGID_SPIKESSCATTERED,
    [B_MSG_SET_POISON_SPIKES]    = STRINGID_POISONSPIKESSCATTERED,
    [B_MSG_SET_STICKY_WEB]       = STRINGID_STICKYWEBUSED,
    [B_MSG_SET_STEALTH_ROCK]     = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SET_SHARP_STEEL]      = STRINGID_SHARPSTEELFLOATS,
};

const u16 gTerrainStringIds[B_MSG_TERRAIN_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY] = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC] = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY] = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_TERRAIN_END_MISTY] = STRINGID_MISTYTERRAINENDS,
    [B_MSG_TERRAIN_END_ELECTRIC] = STRINGID_ELECTRICTERRAINENDS,
    [B_MSG_TERRAIN_END_PSYCHIC] = STRINGID_PSYCHICTERRAINENDS,
    [B_MSG_TERRAIN_END_GRASSY] = STRINGID_GRASSYTERRAINENDS,
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE,
    STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PASTELVEILENTERS,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_FOG]       = STRINGID_FOGCREPTUP, // Unused, can use for custom moves that set fog
};

const u16 gAbilityWeatherChangeStringId[] =
{
    [B_MSG_STARTED_DRIZZLE]        = STRINGID_PKMNMADEITRAIN,
    [B_MSG_STARTED_SAND_STREAM]    = STRINGID_PKMNSXWHIPPEDUPSANDSTORM,
    [B_MSG_STARTED_DROUGHT]        = STRINGID_PKMNSXINTENSIFIEDSUN,
    [B_MSG_STARTED_HAIL_WARNING]   = STRINGID_SNOWWARNINGHAIL,
    [B_MSG_STARTED_SNOW_WARNING]   = STRINGID_SNOWWARNINGSNOW,
    [B_MSG_STARTED_DESOLATE_LAND]  = STRINGID_EXTREMELYHARSHSUNLIGHT,
    [B_MSG_STARTED_PRIMORDIAL_SEA] = STRINGID_HEAVYRAIN,
    [B_MSG_STARTED_STRONG_WINDS]   = STRINGID_MYSTERIOUSAIRCURRENT,
};

const u16 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN]         = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SUN]          = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_SANDSTORM]    = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_HAIL]         = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_SNOW]         = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG]          = STRINGID_FOGLIFTED,
    [B_MSG_WEATHER_END_STRONG_WINDS] = STRINGID_STRONGWINDSDISSIPATED,
};

const u16 gWeatherTurnStringIds[] =
{
    [B_MSG_WEATHER_TURN_RAIN]         = STRINGID_RAINCONTINUES,
    [B_MSG_WEATHER_TURN_DOWNPOUR]     = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_WEATHER_TURN_SUN]          = STRINGID_SUNLIGHTSTRONG,
    [B_MSG_WEATHER_TURN_SANDSTORM]    = STRINGID_SANDSTORMRAGES,
    [B_MSG_WEATHER_TURN_HAIL]         = STRINGID_HAILCONTINUES,
    [B_MSG_WEATHER_TURN_SNOW]         = STRINGID_SNOWCONTINUES,
    [B_MSG_WEATHER_TURN_FOG]          = STRINGID_FOGISDEEP,
    [B_MSG_WEATHER_TURN_STRONG_WINDS] = STRINGID_MYSTERIOUSAIRCURRENTBLOWSON,
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_CHANGED] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_CHANGED] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_CHANGE]      = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_CHANGE_EMPTY]     = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]         = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_CHANGED] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_CHANGED] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_CHANGE]      = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_CHANGE_EMPTY]     = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]     = STRINGID_USINGITEMSTATOFPKMNFELL,
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,     // MOVE_THUNDER_CAGE
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNGOTFROSTBITE,
};

const u16 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = (B_OVERWORLD_SNOW >= GEN_9 ? STRINGID_ITISSNOWING : STRINGID_ITISHAILING),
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_FOGISDEEP,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_FOGISDEEP,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTISHARSH,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gTerrainStartsStringIds[] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_MISTSWIRLSAROUND,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_ELECTRICCURRENTISRUNNING,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_SEEMSWEIRD,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_ISCOVEREDWITHGRASS,
};

const u16 gPrimalWeatherBlocksStringIds[] =
{
    [B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN]      = STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN,
    [B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN]    = STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT,
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariReactionStringIds[NUM_SAFARI_REACTIONS] =
{
    [B_MSG_MON_WATCHING] = STRINGID_PKMNWATCHINGCAREFULLY,
    [B_MSG_MON_ANGRY]    = STRINGID_PKMNANGRY,
    [B_MSG_MON_EATING]   = STRINGID_PKMNEATING
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 CureStatusBerryEffectStringID[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_PKMNSITEMCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_PKMNSITEMHEALEDBURN,
    [B_MSG_CURED_FREEEZE] = STRINGID_PKMNSITEMDEFROSTEDIT,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PKMNSITEMHEALEDFROSTBITE,
    [B_MSG_CURED_SLEEP] = STRINGID_PKMNSITEMWOKEIT,
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]   = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]   = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL]  = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL]  = STRINGID_PKMNBOXLANETTESPCFULL,
    [B_MSG_SWAPPED_INTO_PARTY] = STRINGID_PKMNSENTTOPCAFTERCATCH,
};

// WoT Shadow system: battle-end snag delivery (chooser 0 = party, 1 = PC).
const u16 gWotSnagDeliveryStringIds[] =
{
    STRINGID_WOTSNAGGEDTOPARTY,
    STRINGID_WOTSNAGGEDTOPC,
};

// WoT: mid-battle catch delivery in wild doubles (chooser 0 = party, 1 = PC).
const u16 gWotCatchDeliveryStringIds[] =
{
    STRINGID_WOTCAUGHTTOPARTY,
    STRINGID_WOTCAUGHTTOPC,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u16 gDamageNonTypesStartStringIds[] =
{
    [B_MSG_TRAPPED_WITH_VINES]  = STRINGID_TEAMTRAPPEDWITHVINES,
    [B_MSG_CAUGHT_IN_VORTEX]    = STRINGID_TEAMCAUGHTINVORTEX,
    [B_MSG_SURROUNDED_BY_FIRE]  = STRINGID_TEAMSURROUNDEDBYFIRE,
    [B_MSG_SURROUNDED_BY_ROCKS] = STRINGID_TEAMSURROUNDEDBYROCKS,
};

const u16 gDamageNonTypesDmgStringIds[] =
{
    [B_MSG_HURT_BY_VINES]        = STRINGID_PKMNHURTBYVINES,
    [B_MSG_HURT_BY_VORTEX]       = STRINGID_PKMNHURTBYVORTEX,
    [B_MSG_BURNING_UP]           = STRINGID_PKMNBURNINGUP,
    [B_MSG_HURT_BY_ROCKS_THROWN] = STRINGID_PKMNHURTBYROCKSTHROWN,
};

const u16 gDefogHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_SPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STICKY_WEB] = STRINGID_STICKYWEBDISAPPEAREDFROMTEAM,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STEALTH_ROCK] = STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM,
    [HAZARDS_STEELSURGE] = STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM,
};

const u16 gSpinHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_PKMNBLEWAWAYSPIKES,
    [HAZARDS_STICKY_WEB] = STRINGID_PKMNBLEWAWAYSTICKYWEB,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_PKMNBLEWAWAYTOXICSPIKES,
    [HAZARDS_STEALTH_ROCK] = STRINGID_PKMNBLEWAWAYSTEALTHROCK,
    [HAZARDS_STEELSURGE] = STRINGID_PKMNBLEWAWAYSHARPSTEEL,
};

const u16 gZenModeStringIds[] =
{
    [B_MSG_ZEN_MODE_TRIGGERED] = STRINGID_ZENMODETRIGGERED,
    [B_MSG_ZEN_MODE_ENDED] = STRINGID_ZENMODEENDED
};

const u8 gText_PkmnIsEvolving[] = _("{JPN}おや！？\n{ENG}{STR_VAR_1}{JPN}の ようすが……！{ENG}");
const u8 gText_CongratsPkmnEvolved[] = _("{JPN}おめでとう！ {ENG}{STR_VAR_1}{JPN}は\n{ENG}{STR_VAR_2}{JPN}に しんかした！{WAIT_SE}\p{ENG}");
const u8 gText_PkmnStoppedEvolving[] = _("{JPN}あれ……？ {ENG}{STR_VAR_1}{JPN}の\nへんかが とまった！\p{ENG}");
const u8 gText_EllipsisQuestionMark[] = _("{JPN}……？\p{ENG}");
const u8 gText_WhatWillPkmnDo[] = _("{JPN}{ENG}{B_BUFF1}{JPN}は\nどうする？{ENG}");
const u8 gText_WhatWillPkmnDo2[] = _("{JPN}{ENG}{B_PLAYER_NAME}{JPN}は\nどうする？{ENG}");
const u8 gText_WhatWillWallyDo[] = _("{JPN}ミツルは\nどうする？{ENG}");
const u8 gText_LinkStandby[] = _("{JPN}{PAUSE 16}つうしん たいきちゅう…{ENG}");
const u8 gText_BattleMenu[] = _("{JPN}たたかう{CLEAR_TO 56}バッグ\nポケモン{CLEAR_TO 56}にげる{ENG}");
const u8 gText_SafariZoneMenu[] = _("{JPN}ボール{CLEAR_TO 56}{ENG}{POKEBLOCK}{JPN}\nちかづく{CLEAR_TO 56}にげる{ENG}");
const u8 gText_SafariZoneMenuFrlg[] = _("{JPN}{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW 13 14 15}ボール{CLEAR_TO 56}エサ\nいし{CLEAR_TO 56}にげる{ENG}");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("{JPN}タイプ/{ENG}");
const u8 gText_MoveInterfacePpType[] = _("{JPN}{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}PP\nタイプ/{ENG}");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_WhichMoveToForget4[] = _("{JPN}{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}どの わざを\nわすれさせる？{ENG}");
const u8 gText_BattleYesNoChoice[] = _("{JPN}{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}はい\nいいえ{ENG}");
const u8 gText_BattleSwitchWhich[] = _("{JPN}{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}どれと\nいれかえる？{ENG}");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{BACKGROUND DYNAMIC_COLOR5}{TEXT_COLORS DYNAMIC_COLOR4 DYNAMIC_COLOR6 DYNAMIC_COLOR5}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");
const u8 gText_SafariBalls[] = _("{JPN}サファリボール{ENG}");
const u8 gText_SafariBallLeft[] = _("{JPN}のこり: ${ENG}");
const u8 gText_Sleep[] = _("{JPN}ねむり{ENG}");
const u8 gText_Poison[] = _("{JPN}どく{ENG}");
const u8 gText_Burn[] = _("{JPN}やけど{ENG}");
const u8 gText_Paralysis[] = _("{JPN}まひ{ENG}");
const u8 gText_Ice[] = _("{JPN}こおり{ENG}");
const u8 gText_Confusion[] = _("{JPN}こんらん{ENG}");
const u8 gText_Love[] = _("{JPN}メロメロ{ENG}");
const u8 gText_SpaceAndSpace[] = _("{JPN}と{ENG}");
const u8 gText_CommaSpace[] = _("{JPN}と{ENG}");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("are");
const u8 gText_Are2[] = _("are");
const u8 gText_BadEgg[] = _("{JPN}ダメタマゴ{ENG}");
const u8 gText_BattleWallyName[] = _("{JPN}ミツル{ENG}");
const u8 gText_Win[] = _("{JPN}{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}かち{ENG}");
const u8 gText_Loss[] = _("{JPN}{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}まけ{ENG}");
const u8 gText_Draw[] = _("{JPN}{BACKGROUND TRANSPARENT}{ACCENT TRANSPARENT}ひきわけ{ENG}");
static const u8 sText_SpaceIs[] = _(" is");
static const u8 sText_ApostropheS[] = _("'s");
const u8 gText_BattleTourney[] = _("{JPN}バトルトーナメント{ENG}");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = COMPOUND_STRING("{JPN}1かいせん{ENG}"),
    [DOME_ROUND2]    = COMPOUND_STRING("{JPN}2かいせん{ENG}"),
    [DOME_SEMIFINAL] = COMPOUND_STRING("{JPN}じゅんけっしょう{ENG}"),
    [DOME_FINAL]     = COMPOUND_STRING("{JPN}けっしょう{ENG}"),
};

const u8 gText_TheGreatNewHope[] = _("{JPN}きたいの しんじん！\p{ENG}");
const u8 gText_WillChampionshipDreamComeTrue[] = _("{JPN}ゆうしょうの ゆめは かなうのか！？\p{ENG}");
const u8 gText_AFormerChampion[] = _("{JPN}もと チャンピオン！\p{ENG}");
const u8 gText_ThePreviousChampion[] = _("{JPN}ぜんかいの チャンピオン！\p{ENG}");
const u8 gText_TheUnbeatenChampion[] = _("{JPN}むはいの チャンピオン！\p{ENG}");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("{JPN}こころ{ENG}");
const u8 gText_Skill[] = _("{JPN}わざ{ENG}");
const u8 gText_Body[] = _("{JPN}からだ{ENG}");
const u8 gText_Judgment[] = _("{JPN}{ENG}{B_BUFF1}{JPN}{CLEAR 13}はんてい{CLEAR 13}{ENG}{B_BUFF2}{JPN}{ENG}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}は {ENG}{B_OPPONENT_MON1_NAME}{JPN}を くりだした！\p{ENG}{B_TRAINER2_NAME_WITH_CLASS}{JPN}は {ENG}{B_OPPONENT_MON2_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_Trainer2SentOutPkmn[] = _("{JPN}{ENG}{B_TRAINER2_NAME_WITH_CLASS}{JPN}は {ENG}{B_BUFF1}{JPN}を くりだした！{ENG}");
static const u8 sText_TwoTrainersWantToBattle[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}と {ENG}{B_TRAINER2_NAME_WITH_CLASS}{JPN}が しょうぶを しかけてきた！\p{ENG}");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{JPN}{ENG}{B_PARTNER_NAME_WITH_CLASS}{JPN}は {ENG}{B_PLAYER_MON2_NAME}{JPN}を くりだした！ ゆけっ！ {ENG}{B_PLAYER_MON1_NAME}{JPN}！{ENG}");
static const u8 sText_InGamePartnerSentOutNGoZ[] = _("{JPN}{ENG}{B_PARTNER_NAME_WITH_CLASS}{JPN}は {ENG}{B_PLAYER_MON1_NAME}{JPN}を くりだした！ ゆけっ！ {ENG}{B_PLAYER_MON2_NAME}{JPN}！{ENG}");
static const u8 sText_InGamePartnerSentOutPkmn1[] = _("{JPN}{ENG}{B_PARTNER_NAME_WITH_CLASS}{JPN}は {ENG}{B_PLAYER_MON1_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_InGamePartnerSentOutPkmn2[] = _("{JPN}{ENG}{B_PARTNER_NAME_WITH_CLASS}{JPN}は {ENG}{B_PLAYER_MON2_NAME}{JPN}を くりだした！{ENG}");
static const u8 sText_InGamePartnerWithdrewPkmn1[] = _("{JPN}{ENG}{B_PARTNER_NAME_WITH_CLASS}{JPN}は {ENG}{B_PLAYER_MON1_NAME}{JPN}を ひっこめた！{ENG}");
static const u8 sText_InGamePartnerWithdrewPkmn2[] = _("{JPN}{ENG}{B_PARTNER_NAME_WITH_CLASS}{JPN}は {ENG}{B_PLAYER_MON2_NAME}{JPN}を ひっこめた！{ENG}");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = COMPOUND_STRING("{JPN}しんぱん: 3ターンで けっちゃくが つかなければ はんていに なります！{ENG}"),
    [B_MSG_REF_THATS_IT]           = COMPOUND_STRING("{JPN}しんぱん: そこまで！ はんていで しょうしゃを きめます！{ENG}"),
    [B_MSG_REF_JUDGE_MIND]         = COMPOUND_STRING("{JPN}しんぱん: はんてい こうもく 1 こころ！ いちばん こんじょうを みせた ポケモン！\p{ENG}"),
    [B_MSG_REF_JUDGE_SKILL]        = COMPOUND_STRING("{JPN}しんぱん: はんてい こうもく 2 わざ！ わざを いちばん うまく つかった ポケモン！\p{ENG}"),
    [B_MSG_REF_JUDGE_BODY]         = COMPOUND_STRING("{JPN}しんぱん: はんてい こうもく 3 からだ！ いちばん げんきの ある ポケモン！\p{ENG}"),
    [B_MSG_REF_PLAYER_WON]         = COMPOUND_STRING("{JPN}しんぱん: はんてい {ENG}{B_BUFF1}{JPN} たい {ENG}{B_BUFF2}{JPN}！ しょうしゃは {ENG}{B_PLAYER_NAME}{JPN}の {ENG}{B_PLAYER_MON1_NAME}{JPN}！\p{ENG}"),
    [B_MSG_REF_OPPONENT_WON]       = COMPOUND_STRING("{JPN}しんぱん: はんてい {ENG}{B_BUFF1}{JPN} たい {ENG}{B_BUFF2}{JPN}！ しょうしゃは {ENG}{B_TRAINER1_NAME}{JPN}の {ENG}{B_OPPONENT_MON1_NAME}{JPN}！\p{ENG}"),
    [B_MSG_REF_DRAW]               = COMPOUND_STRING("{JPN}しんぱん: はんてい 3 たい 3！ ひきわけ です！\p{ENG}"),
    [B_MSG_REF_COMMENCE_BATTLE]    = COMPOUND_STRING("{JPN}しんぱん: {ENG}{B_PLAYER_MON1_NAME}{JPN} たい {ENG}{B_OPPONENT_MON1_NAME}{JPN}！ しょうぶ かいし！{ENG}"),
};

static const u8 sText_Trainer1Fled[] = _( "{JPN}{PLAY_SE SE_FLEE}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}は にげだした！{ENG}");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}との しょうぶに まけた！{ENG}");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("{JPN}{ENG}{B_TRAINER1_NAME_WITH_CLASS}{JPN}との しょうぶは ひきわけ！{ENG}");
const u8 gText_RecordBattleToPass[] = _("{JPN}この しょうぶを フロンティアパスに\nきろく しますか？{ENG}");
const u8 gText_BattleRecordedOnPass[] = _("{JPN}{ENG}{B_PLAYER_NAME}{JPN}の しょうぶの けっかを\nフロンティアパスに きろくした。{ENG}");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}が しょうぶを しかけてきた！\p{ENG}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("{JPN}{ENG}{B_LINK_OPPONENT1_NAME}{JPN}と {ENG}{B_LINK_OPPONENT2_NAME}{JPN}が しょうぶを しかけてきた！\p{ENG}");
static const u8 sText_Your1[] = _("{JPN}みかた{ENG}");
static const u8 sText_Opposing1[] = _("{JPN}あいて{ENG}");
static const u8 sText_Your2[] = _("{JPN}みかた{ENG}");
static const u8 sText_Opposing2[] = _("{JPN}あいて{ENG}");
static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_KantoTutorial[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
    [B_WIN_OAK_OLD_MAN] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 15,
        .color.accent = 15,
        .color.shadow = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .color.foreground = 12,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.shadow = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 1,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .color.foreground = 13,
        .color.background = 14,
        .color.accent = 14,
        .color.shadow = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .color.foreground = 2,
        .color.background = 1,
        .color.accent = 1,
        .color.shadow = 3,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .color.foreground = TEXT_DYNAMIC_COLOR_4,
        .color.background = TEXT_DYNAMIC_COLOR_5,
        .color.accent = TEXT_DYNAMIC_COLOR_5,
        .color.shadow = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena,
    [B_WIN_TYPE_KANTO_TUTORIAL] = sTextOnWindowsInfo_KantoTutorial,
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(enum StringID stringID, enum BattlerId battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    {
                        if (TESTING && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        {
                            if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                                stringPtr = sText_Trainer1WantsToBattle;
                            else
                                stringPtr = sText_TwoTrainersWantToBattle;
                        }
                        else if (TESTING && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                        {
                            stringPtr = sText_TwoTrainersWantToBattle;
                        }
                        else if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                        {
                            stringPtr = sText_LinkTrainerWantsToBattlePause;
                        }
                        else
                        {
                            stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                        }
                    }
                    else
                    {
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                    }
                }
                else
                {
                    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_GHOST && IsGhostBattleWithoutScope())
                stringPtr = sText_GhostAppearedCantId;
            else if (gBattleTypeFlags & BATTLE_TYPE_GHOST)
                stringPtr = sText_TheGhostAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))))
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_CATCH_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))
         || BattlerIsWally(battler) || BattlerIsWally(BATTLE_PARTNER(battler)))
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                {
                    if (BattlerIsPlayer(battler)) // Player is battler 0
                        stringPtr = sText_InGamePartnerSentOutZGoN;
                    else // Player is battler 2
                        stringPtr = sText_InGamePartnerSentOutNGoZ;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    stringPtr = sText_GoTwoPkmn;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (BattlerIsPlayer(battler)) // Player is battler 0
                        stringPtr = sText_LinkPartnerSentOutPkmn2GoPkmn;
                    else // Player is battler 2
                        stringPtr = sText_LinkPartnerSentOutPkmn1GoPkmn;
                }
                else
                {
                    stringPtr = sText_GoTwoPkmn;
                }
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler))) // Link Opponent 1 and test opponent
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(BattlerIsLink(battler) || (BattlerIsRecorded(battler) && BattlerIsOpponent(battler))))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if ((GetBattlerPosition(battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(battler) || BattlerIsWally(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler))
            {
                if (BattlerIsLink(battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerWithdrewPkmn1;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerWithdrewPkmn1;
                }
            }
            else if (BattlerIsLink(battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent 1 and test opponent
            {
                stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_PkmnComeBack;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_PkmnOkComeBack;
                else
                    stringPtr = sText_PkmnGoodComeBack;
            }
            else if (BattlerIsPartner(battler))
            {
                if (BattlerIsLink(battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerWithdrewPkmn2;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerWithdrewPkmn2;
                }
            }
            else if (BattlerIsLink(battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || TRAINER_BATTLE_PARAM.opponentB == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2WithdrewPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if ((GetBattlerPosition(gBattleScripting.battler) & BIT_FLANK) == B_FLANK_LEFT) // battler 0 and 1
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                    stringPtr = sText_GoPkmn2;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler))
            {
                if (BattlerIsLink(gBattleScripting.battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerSentOutPkmn1;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerSentOutPkmn1;
                }
            }
            else if (BattlerIsLink(gBattleScripting.battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent 1 and test opponent
            {
                stringPtr = sText_LinkTrainerSentOutPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1SentOutPkmn;
            }
        }
        else // battler 2 and 3
        {
            if (BattlerIsPlayer(gBattleScripting.battler)) // Player
            {
                if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_GoPkmn2;
                else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                    stringPtr = sText_DoItPkmn;
                else if (*(&gBattleStruct->hpScale) == 2)
                    stringPtr = sText_GoForItPkmn;
                else
                    stringPtr = sText_YourFoesWeakGetEmPkmn;
            }
            else if (BattlerIsPartner(gBattleScripting.battler))
            {
                if (BattlerIsLink(gBattleScripting.battler)) // Link Partner
                {
                    stringPtr = sText_LinkPartnerSentOutPkmn2;
                }
                else // In-game Partner
                {
                    stringPtr = sText_InGamePartnerSentOutPkmn2;
                }
            }
            else if (BattlerIsLink(gBattleScripting.battler) || TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT
            || TRAINER_BATTLE_PARAM.opponentB == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK) // Link Opponent B and test opponent
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_LinkTrainer2SentOutPkmn2;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn2;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) // Opponent B
            {
                stringPtr = sText_Trainer2SentOutPkmn;
            }
            else // Opponent A
            {
                stringPtr = sText_Trainer1SentOutPkmn2;
            }
        }
        /*if (IsOnPlayerSide(gBattleScripting.battler))
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && (BattlerIsPartner(gBattleScripting.battler)))
                stringPtr = sText_InGamePartnerSentOutPkmn2;
            else if (*(&gBattleStruct->hpScale) == 0 || IsDoubleBattle())
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (TESTING && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    {
                        if (gBattleScripting.battler == 1)
                        {
                            stringPtr = sText_Trainer1SentOutPkmn;
                        }
                        else
                        {
                            if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                                stringPtr = sText_Trainer2SentOutPkmn;
                            else
                                stringPtr = sText_Trainer1SentOutPkmn2;
                        }
                    }
                    else if (TESTING && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    {
                        if (gBattleScripting.battler == 1)
                            stringPtr = sText_Trainer1SentOutPkmn;
                        else
                            stringPtr = sText_Trainer2SentOutPkmn;
                    }
                    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    {
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    }
                    else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    {
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    }
                    else
                    {
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                    }
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }*/
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
         && !IsZMove(gBattleMsgDataPtr->currentMove)
         && !IsMaxMove(gBattleMsgDataPtr->currentMove))
            StringCopy(gBattleTextBuff3, gTypesInfo[*(&gBattleStruct->stringMoveType)].generic);
        else
            StringCopy(gBattleTextBuff3, GetMoveName(gBattleMsgDataPtr->currentMove));
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (!(BattlerIsPlayer(battler) || BattlerIsPlayer(BATTLE_PARTNER(battler))) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= STRINGID_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
#ifndef NDEBUG
    u32 j, strWidth;
    u32 dstID = BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
    for (j = 1;; j++)
    {
        strWidth = GetStringLineWidth(0, gDisplayedStringBattle, 0, j, sizeof(gDisplayedStringBattle));
        if (strWidth == 0)
            break;
    }
    return dstID;
#else
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
#endif
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(enum BattlerId battler, u8 *dst)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    struct Pokemon *mon = GetBattlerMon(battler);

    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                            \
    if (!IsOnPlayerSide(battler))                                       \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    toCpy = text;

#define HANDLE_NICKNAME_STRING_LOWERCASE(battler)                       \
    if (!IsOnPlayerSide(battler))                       \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefixLower;                           \
        else                                                            \
            toCpy = sText_WildPkmnPrefixLower;                          \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID] = *toCpy;                                        \
            dstID++;                                                    \
            toCpy++;                                                    \
        }                                                               \
    }                                                                   \
    GetBattlerNick(battler, text);                                      \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
    {
        GetTrainerTowerOpponentName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        enum TrainerClassID trainerClass = GetTrainerClassFromId(TRAINER_BATTLE_PARAM.opponentA);

        if (trainerClass == TRAINER_CLASS_RIVAL_EARLY_FRLG || trainerClass == TRAINER_CLASS_RIVAL_LATE_FRLG || trainerClass == TRAINER_CLASS_CHAMPION_FRLG)
            toCpy = GetExpandedPlaceholder(PLACEHOLDER_ID_RIVAL);
        else
            toCpy = GetTrainerNameFromId(trainerId);
    }

    assertf(DoesStringProperlyTerminate(toCpy, TRAINER_NAME_LENGTH + 1),"Opponent needs a valid name")
    {
        return gText_Blank;
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, battler);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, enum BattlerId battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)))
            || gTestRunnerEnabled)
        {
            toCpy = gLinkPlayers[0].name;
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    default:
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, enum BattlerId battler)
{
    if (IsOnPlayerSide(battler))
        return BattleStringGetPlayerName(text, battler);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClasses[GetSecretBaseTrainerClass()].name;
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClasses[GetUnionRoomTrainerClass()].name;
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClasses[GetFrontierBrainTrainerClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClasses[GetFrontierOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
        toCpy = gTrainerClasses[GetTrainerTowerOpponentClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClasses[GetTrainerHillOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClasses[GetEreaderTrainerClassId()].name;
    else
        toCpy = gTrainerClasses[GetTrainerClassFromId(trainerId)].name;

    return toCpy;
}

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 *textStart = &text[0];
    u8 multiplayerId;
    u8 fontId = FONT_NORMAL;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    // Clear destination first
    while (dstID < dstSize)
    {
        dst[dstID] = EOS;
        dstID++;
    }

    dstID = 0;
    while (*src != EOS)
    {
        toCpy = NULL;

        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            u32 classLength = 0;
            u32 nameLength = 0;
            const u8 *classString;
            const u8 *nameString;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                {
                    toCpy = gBattleTextBuff2;
                }
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                {
                    toCpy = gBattleTextBuff3;
                }
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 1, text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 2, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 3, text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_DEF_PARTNER_NAME: // partner target name
                GetBattlerNick(BATTLE_PARTNER(gBattlerTarget), text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->currentMove);
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->originallyUsedMove);
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY_E_READER)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilitiesInfo[gLastUsedAbility].name;
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerAttacker]].name;
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerTarget]].name;
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattleScripting.battler]].name;
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gEffectBattler]].name;
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_TRAINER1_NAME_WITH_CLASS: // trainer1 name with trainer class
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 0);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerWonSpeech();
                }
                break;
            case B_TXT_26: // ?
                if (!IsOnPlayerSide(gBattleScripting.battler))
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                }
                GetMonData(&GetBattlerParty(gBattleScripting.battler)[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = IS_FRLG ? sText_Bills : sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentLoseText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_TOWER && gMapHeader.regionMapSectionId == MAPSEC_TRAINER_TOWER_2)
                {
                    GetTrainerTowerOpponentWinText(gStringVar4, 1);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_PARTNER_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetPlayerName(textStart, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                default:
                    break;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME_WITH_CLASS:
                toCpy = textStart;
                if (GetBattlerPosition(gBattlerAttacker) == B_POSITION_PLAYER_LEFT)
                {
                    textStart = StringCopy(textStart, BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker));
                }
                else
                {
                    classString = NULL;
                    switch (GetBattlerPosition(gBattlerAttacker))
                    {
                    case B_POSITION_PLAYER_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                            classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                        break;
                    case B_POSITION_OPPONENT_LEFT:
                        classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    case B_POSITION_OPPONENT_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                        else
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    default:
                        break;
                    }
                    classLength = 0;
                    nameLength = 0;
                    while (classString[classLength] != EOS)
                    {
                        textStart[classLength] = classString[classLength];
                        classLength++;
                    }
                    textStart[classLength] = CHAR_SPACE;
                    textStart += 1 + classLength;
                    nameString = BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker);
                    if (nameString != textStart)
                    {
                        while (nameString[nameLength] != EOS)
                        {
                            textStart[nameLength] = nameString[nameLength];
                            nameLength++;
                        }
                        textStart[nameLength] = EOS;
                    }
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_EFF_TEAM1:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_EFF_TEAM2:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerTarget)
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattleScripting.battler)
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    // Trainer dialogue is prose, not an indivisible name.
                    // NBSP (0x39) is the kana ぐ while Japanese mode is active.
                    if (*toCpy == CHAR_SPACE
                     && *src != B_TXT_TRAINER1_LOSE_TEXT && *src != B_TXT_TRAINER2_LOSE_TEXT
                     && *src != B_TXT_TRAINER1_WIN_TEXT && *src != B_TXT_TRAINER2_WIN_TEXT)
                        dst[dstID] = CHAR_NBSP;
                    else
                        dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    BreakStringAutomatic(dst, BATTLE_MSG_MAX_WIDTH, BATTLE_MSG_MAX_LINES, fontId, SHOW_SCROLL_PROMPT);

    return dstID;
}

static void IllusionNickHack(enum BattlerId battler, u32 partyId, u8 *dst)
{
    u32 id = PARTY_SIZE;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battler)))
            partnerMon = GetBattlerMon(BATTLE_PARTNER(battler));
        else
            partnerMon = mon;

        id = GetIllusionMonPartyId(gEnemyParty, mon, partnerMon, battler);
    }

    if (id != PARTY_SIZE)
        GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
    else
        GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, GetMoveName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypesInfo[src[srcID + 1]].name);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        case B_BUFF_MON_NICK_WITH_PREFIX_LOWER: // poke nick with lowercase prefix
            if (!IsOnPlayerSide(src[srcID + 1]))
            {
                if (src[srcID] == B_BUFF_MON_NICK_WITH_PREFIX_LOWER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefixLower);
                    else
                        StringAppend(dst, sText_WildPkmnPrefixLower);
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefix);
                    else
                        StringAppend(dst, sText_WildPkmnPrefix);
                }
            }
            GetMonData(&GetBattlerParty(src[srcID + 1])[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                if (IsOnPlayerSide(src[srcID + 1]))
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilitiesInfo[T1_READ_16(&src[srcID + 1])].name);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY_E_READER)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.type = WINDOW_TEXT_PRINTER;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.color = textInfo[windowId].color;

    if (B_WIN_MOVE_NAME_1 <= windowId && windowId <= B_WIN_MOVE_NAME_4)
    {
        // We cannot check the actual width of the window because
        // B_WIN_MOVE_NAME_1 and B_WIN_MOVE_NAME_3 are 16 wide for
        // Z-move details.
        if (gBattleStruct->zmove.viewing && windowId == B_WIN_MOVE_NAME_1)
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 16 * TILE_WIDTH);
        else
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 8 * TILE_WIDTH);
    }

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)) || gTestRunnerEnabled || ((gBattleTypeFlags & BATTLE_TYPE_POKEDUDE) && windowId != B_WIN_OAK_OLD_MAN))
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT || windowId == B_WIN_OAK_OLD_MAN)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(enum BattlerId battler)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var;

    if (!gBattleStruct->zmove.viewing)
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[battler]]);
    else
        var = 3;

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}
