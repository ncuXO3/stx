#ifndef STX_BIT_CAST_HPP_
#define STX_BIT_CAST_HPP_

#include <stx/common.hpp>
#include <string.h>

namespace stx {

template <class T, class U>
STX_ALWAYS_INLINE void bit_cast(T& dst, const U& src)
{
    STX_STATIC_ASSERT(sizeof(U) == sizeof(T));
    (void) memcpy(&dst, &src, sizeof(dst));
}

} // namespace stx

#endif // STX_BIT_CAST_HPP_
