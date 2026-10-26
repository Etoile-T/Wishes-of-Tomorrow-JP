#ifndef GUARD_STORAGE_NAME_LOCALIZATION_H
#define GUARD_STORAGE_NAME_LOCALIZATION_H
#include "constants/characters.h"

// Repair only the exact overlong localized default, within the existing field.
// Other names retain their eight data bytes. No save-layout changes.
static inline void NormalizeStorageBoxName(u8 *name, u8 boxId)
{
    static const u8 legacy[8] = {0xfc, 0x15, 0x9a, 0xa0, 0x58, 0x5d, 0xfc, 0x16};
    u8 i;
    bool8 matches = TRUE;
    for (i = 0; i < 8; i++)
        if (name[i] != legacy[i]) matches = FALSE;
    if (matches)
    {
        u8 number = boxId + 1;
        name[0] = EXT_CTRL_CODE_BEGIN;
        name[1] = EXT_CTRL_CODE_JPN_NAME_4;
        for (i = 2; i < 6; i++) name[i] = legacy[i];
        i = 6;
        if (number >= 10) name[i++] = CHAR_0 + number / 10;
        name[i++] = CHAR_0 + number % 10;
        name[i] = EOS;
    }
    // Bound all reads, including already stored unterminated legacy names.
    name[8] = EOS;
}
#endif
