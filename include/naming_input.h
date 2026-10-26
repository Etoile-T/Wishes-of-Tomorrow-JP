#ifndef GUARD_NAMING_INPUT_H
#define GUARD_NAMING_INPUT_H
#include "constants/characters.h"

// Save fields are unchanged. The editor stores glyphs, not editable controls.
static inline bool8 NamingInputHasKana(const u8 *text, u8 length)
{
    u8 i;
    for (i = 0; i < length && text[i] != EOS; i++)
        if ((text[i] > CHAR_SPACE && text[i] <= 0xA0) || text[i] == 0xF1)
            return TRUE;
    return FALSE;
}

static inline bool8 NamingInputSafeWithKana(u8 ch)
{
    return !(ch >= CHAR_DBL_QUOTE_LEFT && ch <= CHAR_SGL_QUOTE_RIGHT)
        && ch != CHAR_CURRENCY && ch != CHAR_COMMA;
}

static inline bool8 NamingInputEncode(u8 *dest, u8 capacity, const u8 *glyphs, u8 length)
{
    u8 i, pos = 0;
    bool8 japanese = NamingInputHasKana(glyphs, length);
    if ((u16)length + (japanese ? 4 : 0) + 1 > capacity)
        return FALSE;
    if (japanese)
    {
        for (i = 0; i < length; i++)
            if (!NamingInputSafeWithKana(glyphs[i]))
                return FALSE;
        dest[pos++] = EXT_CTRL_CODE_BEGIN;
        dest[pos++] = EXT_CTRL_CODE_JPN;
    }
    for (i = 0; i < length; i++)
        dest[pos++] = glyphs[i];
    if (japanese)
    {
        dest[pos++] = EXT_CTRL_CODE_BEGIN;
        dest[pos++] = EXT_CTRL_CODE_ENG;
    }
    dest[pos] = EOS;
    return TRUE;
}
#endif
