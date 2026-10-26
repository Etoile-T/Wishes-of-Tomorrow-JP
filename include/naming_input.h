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

// Japanese names match the Japanese ROM: at most five glyphs, stored behind one
// two-byte EXT_CTRL_CODE_JPN_NAME_n span so they fit the unchanged save fields.
#define NAMING_INPUT_KANA_MAX 5

static inline u8 NamingInputKanaLimit(u8 maxChars)
{
    return maxChars - 2 < NAMING_INPUT_KANA_MAX ? maxChars - 2 : NAMING_INPUT_KANA_MAX;
}

// Copy a saved name into the editor as plain glyphs. Strips span codes and the
// older {JPN}...{ENG} wrapping; capacity includes the EOS.
static inline void NamingInputDecode(u8 *dest, u8 capacity, const u8 *src)
{
    u8 pos = 0;
    while (*src != EOS && pos + 1 < capacity)
    {
        if (src[0] == EXT_CTRL_CODE_BEGIN
         && (src[1] == EXT_CTRL_CODE_JPN || src[1] == EXT_CTRL_CODE_ENG
          || (src[1] >= EXT_CTRL_CODE_JPN_NAME_1 && src[1] <= EXT_CTRL_CODE_JPN_NAME_10)))
        {
            src += 2;
            continue;
        }
        dest[pos++] = *src++;
    }
    dest[pos] = EOS;
}

static inline bool8 NamingInputEncode(u8 *dest, u8 capacity, const u8 *glyphs, u8 length)
{
    u8 i, pos = 0;
    bool8 japanese = NamingInputHasKana(glyphs, length);
    if ((u16)length + (japanese ? 2 : 0) + 1 > capacity || (japanese && length > NAMING_INPUT_KANA_MAX))
        return FALSE;
    if (japanese)
    {
        for (i = 0; i < length; i++)
            if (!NamingInputSafeWithKana(glyphs[i]))
                return FALSE;
        dest[pos++] = EXT_CTRL_CODE_BEGIN;
        dest[pos++] = EXT_CTRL_CODE_JPN_NAME_1 + length - 1;
    }
    for (i = 0; i < length; i++)
        dest[pos++] = glyphs[i];
    dest[pos] = EOS;
    return TRUE;
}
// Legacy ten-byte nickname consumers must not leave a longer span active after
// truncating its final glyphs. The extended twelve-byte save field is unchanged.
static inline void NamingInputFitSpan(u8 *name, u8 bytes)
{
    u8 count;
    if (bytes < 3 || name[0] != EXT_CTRL_CODE_BEGIN
     || name[1] < EXT_CTRL_CODE_JPN_NAME_1 || name[1] > EXT_CTRL_CODE_JPN_NAME_10)
        return;
    count = bytes - 2;
    if (name[1] - EXT_CTRL_CODE_JPN_NAME_1 + 1 > count)
        name[1] = EXT_CTRL_CODE_JPN_NAME_1 + count - 1;
}
#endif
