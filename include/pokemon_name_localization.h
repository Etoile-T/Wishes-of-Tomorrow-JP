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
#endif
