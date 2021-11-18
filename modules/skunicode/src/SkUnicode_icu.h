/*
 * Copyright 2021 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkUnicode_icu_DEFINED
#define SkUnicode_icu_DEFINED

#include <unicode/ubidi.h>
#include <unicode/ubrk.h>
#include <unicode/uscript.h>
#include <unicode/ustring.h>
#include <unicode/utext.h>
#include <unicode/utypes.h>

#include <ICU4XCodePointMapData16.h>
#include <ICU4XCodePointMapData16Response.h>

#include "include/private/SkTemplates.h"

#define SKICU_EMIT_FUNCS              \
    SKICU_FUNC(u_errorName)           \
    SKICU_FUNC(u_getIntPropertyValue) \
    SKICU_FUNC(u_iscntrl)             \
    SKICU_FUNC(u_isspace)             \
    SKICU_FUNC(u_isWhitespace)        \
    SKICU_FUNC(u_strToUpper)          \
    SKICU_FUNC(ubidi_close)           \
    SKICU_FUNC(ubidi_getLength)       \
    SKICU_FUNC(ubidi_getLevelAt)      \
    SKICU_FUNC(ubidi_openSized)       \
    SKICU_FUNC(ubidi_reorderVisual)   \
    SKICU_FUNC(ubidi_setPara)         \
    SKICU_FUNC(ubrk_close)            \
    SKICU_FUNC(ubrk_current)          \
    SKICU_FUNC(ubrk_first)            \
    SKICU_FUNC(ubrk_following)        \
    SKICU_FUNC(ubrk_getRuleStatus)    \
    SKICU_FUNC(ubrk_next)             \
    SKICU_FUNC(ubrk_open)             \
    SKICU_FUNC(ubrk_preceding)        \
    SKICU_FUNC(ubrk_setText)          \
    SKICU_FUNC(ubrk_setUText)         \
    SKICU_FUNC(uloc_getDefault)       \
    SKICU_FUNC(uscript_getScript)     \
    SKICU_FUNC(utext_close)           \
    SKICU_FUNC(utext_openUChars)      \
    SKICU_FUNC(utext_openUTF8)        \

#define SKICU_FUNC(funcname) decltype(funcname)* f_##funcname;
struct SkICULib {
    SKICU_EMIT_FUNCS

    // ubrk_clone added as draft in ICU69 and Android API 31 (first ICU NDK).
    // ubrk_safeClone deprecated in ICU69 and not exposed by Android.
    UBreakIterator* (*f_ubrk_clone_)(const UBreakIterator*, UErrorCode*);
    UBreakIterator* (*f_ubrk_safeClone_)(const UBreakIterator*, void*, int32_t*, UErrorCode*);
};
#undef SKICU_FUNC

// Platform/config specific ICU factory.
std::unique_ptr<SkICULib> SkLoadICULib();

#endif // SkUnicode_icu_DEFINED
