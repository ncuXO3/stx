#ifndef STX_COMMON_HPP_
#define STX_COMMON_HPP_

#include <stx/common/static_constant.hpp>

#if __cplusplus >= 201103L
#define STX_CPP11 1
#else
#define STX_CPP11 0
#endif

#ifndef __has_builtin
#   define __has_builtin(x) 0
#endif

#ifndef __has_attribute
#   define __has_attribute(x) 0
#endif

#if defined(__GNUC__) || __has_attribute(always_inline)
#   define STX_ALWAYS_INLINE inline __attribute__((always_inline))
#else
#   define STX_ALWAYS_INLINE
#endif

#define STX_STRINGIZE_IMPL_0(x) #x
#define STX_STRINGIZE_IMPL_1(x) STX_STRINGIZE_IMPL_0 x
#define STX_STRINGIZE(x) STX_STRINGIZE_IMPL_1((x))

#define STX_WSTRINGIZE_IMPL_0(x) L ## x
#define STX_WSTRINGIZE_IMPL_1(x) STX_WSTRINGIZE_IMPL_0(#x)
#define STX_WSTRINGIZE(x) STX_WSTRINGIZE_IMPL_1(x)

#include <iostream>
#define STX_LOG_SOURCE_STR " (" __FILE__ ":" STX_STRINGIZE(__LINE__) ")"

#define STX_LOG_IMPL(descr, x) std::cout << descr << x << STX_LOG_SOURCE_STR << std::endl;
#define STX_LOG_TRACE(x) STX_LOG_IMPL("TRACE: ", x)
#define STX_LOG_DEBUG(x) STX_LOG_IMPL("DEBUG: ", x)
#define STX_LOG_INFO(x)  STX_LOG_IMPL("INFO:  ", x)
#define STX_LOG_WARN(x)  STX_LOG_IMPL("WARN:  ", x)
#define STX_LOG_ERROR(x) STX_LOG_IMPL("ERROR: ", x)
#define STX_LOG_FATAL(x) STX_LOG_IMPL("FATAL: ", x)

#define STX_STATIC_ASSERT(x) \
    typedef char __static_assert_ ## __LINE__ [(x) ? 1 : -1]; \
    (void) sizeof(__static_assert_ ## __LINE__);

#include <stdlib.h>
#include <string.h>

#include <stddef.h>
//  size_t
//  ptrdiff_t

#include <limits.h>
#include <float.h>

#include <stdint.h>
//  intmax_t
//  uintmax_t

//  These types are OPTIONAL according to C/C++ standard
//  and may not be provided by the platform:
//
//  intptr_t
//  uintptr_t
//  int8_t
//  uint8_t
//  int16_t
//  uint16_t
//  int32_t
//  uint32_t
//  int64_t
//  uint64_t

namespace stx {

typedef int_least8_t       int8l;
typedef uint_least8_t      uint8l;
typedef int_least16_t      int16l;
typedef uint_least16_t     uint16l;
typedef int_least32_t      int32l;
typedef uint_least32_t     uint32l;
typedef int_least64_t      int64l;
typedef uint_least64_t     uint64l;

typedef int_fast8_t        int8f;
typedef uint_fast8_t       uint8f;
typedef int_fast16_t       int16f;
typedef uint_fast16_t      uint16f;
typedef int_fast32_t       int32f;
typedef uint_fast32_t      uint32f;
typedef int_fast64_t       int64f;
typedef uint_fast64_t      uint64f;

typedef signed char        schar;
typedef unsigned char      uchar;
typedef unsigned short     ushort;
typedef unsigned int       uint;
typedef unsigned long      ulong;
typedef long double        ldouble;
typedef long long          llong;
typedef unsigned long long ullong;

} // namespace stx

#endif // STX_COMMON_HPP_
