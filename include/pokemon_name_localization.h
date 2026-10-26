#ifndef GUARD_POKEMON_NAME_LOCALIZATION_H
#define GUARD_POKEMON_NAME_LOCALIZATION_H
#include "constants/characters.h"

// Match all twelve bytes of the old default, not just its ten-byte prefix.
// Callers also check species. No saved nickname is rewritten.
static inline bool8 IsLegacyArmoredMewtwoName(const u8 *firstTen, u8 eleventh, u8 twelfth)
{
    static const u8 oldName[10] = {
        CHAR_A, CHAR_r, CHAR_m, CHAR_o, CHAR_r, CHAR_SPACE,
        CHAR_M, CHAR_e, CHAR_w, CHAR_t
    };
    u8 i;
    for (i = 0; i < 10; i++)
        if (firstTen[i] != oldName[i])
            return FALSE;
    return eleventh == CHAR_w && twelfth == CHAR_o;
}
// Recognize only exact previous/current defaults, never arbitrary nicknames.
static inline bool8 IsArmoredDefaultName(const u8 *firstTen, u8 eleventh, u8 twelfth)
{
    static const u8 japanese[12] = {0xfc, 0x26, 0x51, 0xae, 0x6f, 0xae, 0x95, 0x70, 0x85, 0x53, 0x62, 0xae};
    static const u8 abbreviated[10] = {0xbb, 0xcc, 0xfc, 0x21, 0x70, 0x85, 0x53, 0x62, 0xae, 0xff};
    u8 i;
    bool8 full = TRUE, brief = TRUE;
    if (IsLegacyArmoredMewtwoName(firstTen, eleventh, twelfth))
        return TRUE;
    for (i = 0; i < 10; i++)
    {
        if (firstTen[i] != japanese[i]) full = FALSE;
        if (firstTen[i] != abbreviated[i]) brief = FALSE;
    }
    return brief || (full && eleventh == japanese[10] && twelfth == japanese[11]);
}
#endif
