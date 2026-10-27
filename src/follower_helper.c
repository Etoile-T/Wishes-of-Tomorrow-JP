#include "global.h"
#include "data.h"
#include "event_scripts.h"
#include "follower_helper.h"
#include "overworld.h"
#include "rtc.h"
#include "constants/battle.h"
#include "constants/followers.h"
#include "constants/metatile_behaviors.h"
#include "constants/pokemon.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/weather.h"

#define TYPE_NOT_TYPE1 NUMBER_OF_MON_TYPES

// difficult conditional messages follow
static const u8 sCondMsg00[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は たのしそうに おどった。{ENG}");
static const u8 sCondMsg01[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は うつくしく おどった。{ENG}");
static const u8* const sCelebiTexts[] = {sCondMsg00, sCondMsg01, NULL};
static const u8 sCondMsg02[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は ひを ふいて さけんだ。{ENG}");
static const u8 sCondMsg03[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は いきおいよく\nほのおを だしている!{ENG}");
static const u8 sCondMsg04[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は ひを はいた!{ENG}");
static const u8 sCondMsg05[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は いきおいよく\nほのおを ふいている!{ENG}");
static const u8* const sFireTexts[] = {sCondMsg02, sCondMsg03, sCondMsg04, sCondMsg05, NULL};
static const u8 sCondMsg06[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は ポケモンリーグを\nじっと みつめている。{ENG}");
static const u8 sCondMsg07[] = _("{JPN}ポケモンは やまの ちょうじょうを\nじっと みつめている。{ENG}");
static const u8 sCondMsg08[] = _("{JPN}くんくん なにか いい においが する!{ENG}");
static const u8 sCondMsg09[] = _("{JPN}ポケモンは おちつかない ようすで\nたなを みまわしている。{ENG}");
static const u8 sCondMsg10[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は たなを\nじっと みつめている。{ENG}");
static const u8* const sShopTexts[] = {sCondMsg09, sCondMsg10, NULL};
static const u8 sCondMsg11[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は するどい めつきで\nしゅうちゅう している!{ENG}");
static const u8 sCondMsg12[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は じてんしゃに\nとても きょうみが あるようだ。{ENG}");
static const u8 sCondMsg13[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は きかいに\nさわってみたい ようだ!{ENG}");
static const u8 sCondMsg14[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は ふねと いっしょに\nゆれている!{ENG}");
static const u8 sCondMsg15[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は ふねの ゆれに\nあわせて おどっている。{ENG}");
static const u8 sCondMsg16[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は まだ ふねから\nおりたくない ようだ!{ENG}");
static const u8* const sBoatTexts[] = {sCondMsg14, sCondMsg15, sCondMsg16, NULL};
static const u8 sCondMsg17[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は きかいの おとに\nみみを すましている。{ENG}");
static const u8* const sMachineTexts[] = {sCondMsg13, sCondMsg17, NULL};
static const u8 sCondMsg18[] = _("{JPN}わっ! ポケモンが いきなり\nみずを はねあげた!{ENG}");
static const u8 sCondMsg19[] = _("{JPN}ポケモンが すなを\nまいあげている!{ENG}");
static const u8 sCondMsg20[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は くさを むしって\nあそんでいる。{ENG}");
static const u8 sCondMsg21[] = _("{JPN}ポケモンは うれしそうに\nあしあとを みている!{ENG}");
static const u8 sCondMsg22[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は きんちょうして\nすこし いきぐるしそうだ。{ENG}");
static const u8 sCondMsg23[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は せまい ばしょを\nけいかい している!{ENG}");
static const u8* const sElevatorTexts[] = {sCondMsg22, sCondMsg23, NULL};
static const u8 sCondMsg24[] = _("{JPN}とつぜん つめたい かぜが ふいた!{ENG}");
static const u8 sCondMsg25[] = _("{JPN}ポケモンが すべって\nころびそうに なった!{ENG}");
static const u8 sCondMsg26[] = _("{JPN}ポケモンは こおりに さわって\nおどろいている ようだ。{ENG}");
static const u8* const sColdTexts[] = {sCondMsg24, sCondMsg25, sCondMsg26, NULL};
static const u8 sCondMsg27[] = _("{JPN}ポケモンの かおに\nはなびらが ついている!{ENG}");
static const u8 sCondMsg28[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は ちいさく うなっている。{ENG}");
static const u8 sCondMsg29[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は こわくて ふるえている。{ENG}");
static const u8 sCondMsg30[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は なんだか かなしそう…{ENG}");
static const u8* const sFearTexts[] = {sCondMsg29, sCondMsg30, NULL};
static const u8 sCondMsg31[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は くさむらで\nあまやどり している。{ENG}");
static const u8 sCondMsg32[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は とても さむそうだ。{ENG}");
static const u8 sCondMsg33[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は うみを みつめている。{ENG}");
static const u8 sCondMsg34[] = _("{JPN}ポケモンは うみを\nじっと みつめている!{ENG}");
static const u8 sCondMsg35[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は あれくるう\nうみを みている。{ENG}");
static const u8* const sSeaTexts[] = {sCondMsg33, sCondMsg34, sCondMsg35, NULL};
static const u8 sCondMsg36[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は たきの おとに\nみみを すましている。{ENG}");
static const u8 sCondMsg37[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は あめが\nうれしい ようだ!{ENG}");
static const u8 sCondMsg38[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は みずに うつった\nじぶんの すがたを みている。{ENG}");
static const u8 sCondMsg39[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は はっぱの ざわめきを\nきいて くつろいでいる ようだ…{ENG}");
static const u8 sCondMsg40[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は こおりを かじっている。{ENG}");
static const u8 sCondMsg41[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は こおりに さわっている。{ENG}");
static const u8* const sIceTexts[] = {sCondMsg26, sCondMsg40, sCondMsg41, NULL};
static const u8 sCondMsg42[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}の やけどが いたそうだ!{ENG}");
static const u8 sCondMsg43[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は そとの けしきを\nみて うれしそうだ!{ENG}");
static const u8 sCondMsg44[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は そらを\nみあげている。{ENG}");
static const u8* const sDayTexts[] = {sCondMsg43, sCondMsg44, NULL};
static const u8 sCondMsg45[] = _("{JPN}ポケモンは よぞらに\nみとれている!{ENG}");
static const u8 sCondMsg46[] = _("{JPN}ポケモンは うれしそうに\nきれいな ほしぞらを ながめている!{ENG}");
static const u8* const sNightTexts[] = {sCondMsg45, sCondMsg46, NULL};
static const u8 sCondMsg50[] = _("{JPN}{ENG}{STR_VAR_1}{JPN}は いじょうな てんきに\nおびえている!{ENG}");

// See the struct definition in follower_helper.h for more info
const struct FollowerMsgInfoExtended gFollowerConditionalMessages[COND_MSG_COUNT] =
{
    [COND_MSG_CELEBI] =
    {
        .text = (u8*)sCelebiTexts,
        .textSpread = 1,
        .script = EventScript_FollowerDance,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_SPECIES(SPECIES_CELEBI),
        },
    },
    [COND_MSG_FIRE] =
    {
        .text = (u8*)sFireTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_TYPES(TYPE_FIRE, TYPE_FIRE),
        },
    },
    [COND_MSG_EVER_GRANDE] =
    {
        .text = sCondMsg06,
        .script = EventScript_FollowerFaceUp,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            MATCH_MAP(MAP_EVER_GRANDE_CITY),
        },
    },
    [COND_MSG_ROUTE_112] =
    {
        .text = sCondMsg07,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE112),
        },
    },
    [COND_MSG_DAY_CARE] =
    {
        .text = sCondMsg08,
        .script = EventScript_FollowerNostalgia,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE117_POKEMON_DAY_CARE)
        },
    },
    [COND_MSG_MART] =
    {
        .text = (u8*)sShopTexts,
        .textSpread = 1,
        .script = EventScript_FollowerLookAround,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_MUSIC(MUS_POKE_MART)
        },
    },
    [COND_MSG_VICTORY_ROAD] =
    {
        .text = sCondMsg11,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MUSIC(MUS_VICTORY_ROAD)
        },
    },
    [COND_MSG_BIKE_SHOP] =
    {
        .text = sCondMsg12,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MAP(MAP_MAUVILLE_CITY_BIKE_SHOP)
        },
    },
    [COND_MSG_MACHINES] =
    {
        .text = (u8*)sMachineTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .orFlag = 1, // match any of these maps
        .conditions =
        {
            MATCH_MAP(MAP_NEW_MAUVILLE_INSIDE),
            MATCH_MAP(MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F),
            MATCH_MAP(MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F),
        },
    },
    [COND_MSG_SAILING] =
    {
        .text = (u8*)sBoatTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .script = EventScript_FollowerLookAround,
        .conditions =
        {
            MATCH_MUSIC(MUS_SAILING),
        },
    },
    [COND_MSG_PUDDLE] =
    {
        .text = sCondMsg18,
        .script = EventScript_FollowerHopping,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SHALLOW_WATER, MB_PUDDLE),
        },
    },
    [COND_MSG_SAND] =
    {
        .text = sCondMsg19,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_DEEP_SAND),
        },
    },
    [COND_MSG_GRASS] =
    {
        .text = sCondMsg20,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_TALL_GRASS, MB_LONG_GRASS),
        },
    },
    [COND_MSG_FOOTPRINTS] =
    {
        .text = sCondMsg21,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_FOOTPRINTS),
        },
    },
    [COND_MSG_ELEVATOR] =
    {
        .text = (u8*)sElevatorTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR),
        },
    },
    [COND_MSG_ICE_ROOM] =
    {
        .text = (u8*)sColdTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        },
    },
    [COND_MSG_ROUTE_117] =
    {
        .text = sCondMsg27,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE117),
        },
    },
    [COND_MSG_DRAGON_GROWL] =
    {
        .text = sCondMsg28,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TYPE_DRAGON, TYPE_DRAGON),
            MATCH_MAPSEC(MAPSEC_SKY_PILLAR),
        },
    },
    [COND_MSG_FEAR] =
    {
        .text = (u8*)sFearTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_NOT_TYPES(TYPE_GHOST, TYPE_GHOST),
            MATCH_MAPSEC(MAPSEC_MT_PYRE),
            MATCH_MUSIC(MUS_MT_PYRE),
        },
    },
    [COND_MSG_FIRE_RAIN] =
    {
        .text = sCondMsg31,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TYPE_FIRE, TYPE_FIRE),
            MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM),
        },
    },
    [COND_MSG_FROZEN] =
    {
        .text = sCondMsg32,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
           MATCH_STATUS(STATUS1_FREEZE),
        },
    },
    [COND_MSG_SEASIDE] =
    {
        .text = (u8*)sSeaTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_OCEAN_WATER, 5),
        },
    },
    [COND_MSG_WATERFALL] =
    {
        .text = sCondMsg36,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_WATERFALL, 5),
        },
    },
    [COND_MSG_RAIN] =
    {
        .text = sCondMsg37,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
        MATCH_NOT_TYPES(TYPE_FIRE, TYPE_FIRE),
        MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM)
    }
    },
    [COND_MSG_REFLECTION] =
    {
        .text = sCondMsg38,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_POND_WATER, 1),
        },
    },
    [COND_MSG_LEAVES] =
    {
        .text = sCondMsg39,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MAPSEC(MAPSEC_PETALBURG_WOODS),
        },
    },
    [COND_MSG_ICE] =
    {
        .text = (u8*)sIceTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_ICE, 1),
        },
    },
    [COND_MSG_BURN] =
    {
        .text = sCondMsg42,
        .emotion = FOLLOWER_EMOTION_SAD,
        .conditions =
        {
            MATCH_STATUS(STATUS1_BURN),
        },
    },
    [COND_MSG_DAY] =
    {
        .text = (u8*)sDayTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_TIME_OF_DAY(TIME_DAY),
        },
    },
    [COND_MSG_NIGHT] =
    {
        .text = (u8*)sNightTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_TIME_OF_DAY(TIME_NIGHT),
        },
    },
    [COND_MSG_ABNORMAL_WEATHER] =
    {
        .text = sCondMsg50,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MUSIC(MUS_ABNORMAL_WEATHER),
            MATCH_NOT_SPECIES(SPECIES_KYOGRE),
            MATCH_NOT_SPECIES(SPECIES_GROUDON),
            MATCH_NOT_SPECIES(SPECIES_RAYQUAZA),
        }
    },
};

// Pool of "unconditional" follower messages
const struct FollowerMessagePool gFollowerBasicMessages[FOLLOWER_EMOTION_LENGTH] =
{
    [FOLLOWER_EMOTION_HAPPY]    = {gFollowerHappyMessages,    EventScript_FollowerGeneric, FOLLOWER_HAPPY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_NEUTRAL]  = {gFollowerNeutralMessages,  EventScript_FollowerGeneric, FOLLOWER_NEUTRAL_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SAD]      = {gFollowerSadMessages,      EventScript_FollowerGeneric, FOLLOWER_SAD_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_UPSET]    = {gFollowerUpsetMessages,    EventScript_FollowerGeneric, FOLLOWER_UPSET_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_ANGRY]    = {gFollowerAngryMessages,    EventScript_FollowerGeneric, FOLLOWER_ANGRY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_PENSIVE]  = {gFollowerPensiveMessages,  EventScript_FollowerGeneric, FOLLOWER_PENSIVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_LOVE]     = {gFollowerLoveMessages,     EventScript_FollowerGeneric, FOLLOWER_LOVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SURPRISE] = {gFollowerSurpriseMessages, EventScript_FollowerGeneric, FOLLOWER_SURPRISE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_CURIOUS]  = {gFollowerCuriousMessages,  EventScript_FollowerGeneric, FOLLOWER_CURIOUS_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_MUSIC]    = {gFollowerMusicMessages,    EventScript_FollowerGeneric, FOLLOWER_MUSIC_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_POISONED] = {gFollowerPoisonedMessages, EventScript_FollowerGeneric, FOLLOWER_POISONED_MESSAGE_COUNT},
};
