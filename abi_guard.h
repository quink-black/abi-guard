/* static ABI check
 * Copyright (C) 2021 Zhao Zhili
 */

#ifndef STATIC_ABI_GUARD_H
#define STATIC_ABI_GUARD_H

#include "abi_guard_key.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#define STATIC_ABI_GUARD_IMPORT __declspec(dllimport)
#define STATIC_ABI_GUARD_EXPORT __declspec(dllexport)
#else
#if defined(__GNUC__) && (__GNUC__ >= 4)
#define STATIC_ABI_GUARD_IMPORT
#define STATIC_ABI_GUARD_EXPORT __attribute__((visibility("default")))
#else
#define STATIC_ABI_GUARD_IMPORT
#define STATIC_ABI_GUARD_EXPORT
#endif
#endif

#ifdef STATIC_ABI_GUARDAPI_IMPORTS
#define STATIC_ABI_GUARD_API STATIC_ABI_GUARD_IMPORT
#else
#ifdef STATIC_ABI_GUARDAPI_EXPORTS
#define STATIC_ABI_GUARD_API STATIC_ABI_GUARD_EXPORT
#else
#define STATIC_ABI_GUARD_API
#endif
#endif

#ifndef API_PREFIX
#define API_PREFIX
#endif

#define static_abi_guard_glue(prefix, guard, key) \
    static_abi_guard_glue2(prefix, guard, key)

#define static_abi_guard_glue2(prefix, guard, key) \
    prefix##guard##key

#define static_abi_guard_check \
    static_abi_guard_glue(API_PREFIX, abi_guard_, STATIC_ABI_GUARD_KEY)

STATIC_ABI_GUARD_API
const char *static_abi_guard_check(void);

#ifdef STATIC_ABI_GUARD_IMPL

const char *static_abi_guard_check() {
    return __func__;
}

#endif// STATIC_ABI_GUARD_IMPL

#ifdef __cplusplus
}// extern "C"
#endif

#endif// STATIC_ABI_GUARD_H