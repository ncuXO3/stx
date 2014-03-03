#ifndef STX_ORDERED_UNSIGNED_HPP_
#define STX_ORDERED_UNSIGNED_HPP_

#include <stx/common.hpp>
#include <stx/type_traits.hpp>
#include <limits>

namespace stx {

template <class T, class U>
STX_ALWAYS_INLINE typename enable_if<is_unsigned_int<T>::value>::type
to_ordered_unsigned(const T& src, U& dst)
{
    dst = src;
}

template <class T, class U>
STX_ALWAYS_INLINE typename enable_if<is_unsigned_int<T>::value>::type
from_ordered_unsigned(T& dst, const U& src)
{
    dst = src;
}

template <class T, class U>
STX_ALWAYS_INLINE typename enable_if<is_signed_int<T>::value>::type
to_ordered_unsigned(const T& src, U& dst)
{
    dst = (*(U*) &src) + std::numeric_limits<T>::min();
}

template <class T, class U>
STX_ALWAYS_INLINE typename enable_if<is_signed_int<T>::value>::type
from_ordered_unsigned(T& dst, const U& src)
{
    dst = (T) (src + std::numeric_limits<T>::min());
}

STX_ALWAYS_INLINE typename enable_if<std::numeric_limits<float>::is_iec559>::type
to_ordered_unsigned(const float& src, uint32_t& dst)
{
    uint32_t x, mask;
    bit_cast(x, src);
    mask = ((-(int32_t) (x >> 31)) | (((uint32_t) 1) << 31));
    dst = x ^ mask;
}

STX_ALWAYS_INLINE typename enable_if<std::numeric_limits<float>::is_iec559>::type
from_ordered_unsigned(float& dst, const uint32_t& src)
{
    uint32_t x, mask;
    mask = ((src >> 31) - 1) | (((uint32_t) 1) << 31);
    x = src ^ mask;
    bit_cast(dst, x);
}

STX_ALWAYS_INLINE typename enable_if<std::numeric_limits<float>::is_iec559>::type
to_ordered_unsigned(const double& src, uint64_t& dst)
{
    uint64_t x, mask;
    bit_cast(x, src);
    mask = (-(uint64_t) (x >> 63)) | (((uint64_t) 1) << 63);
    dst = x ^ mask;
}

STX_ALWAYS_INLINE typename enable_if<std::numeric_limits<float>::is_iec559>::type
from_ordered_unsigned(double& dst, const uint64_t& src)
{
    uint64_t x, mask;
    mask = ((src >> 63) - 1) | (((uint64_t) 1) << 63);
    x = src ^ mask;
    bit_cast(dst, x);
}

} // namespace stx

#endif // STX_ORDERED_UNSIGNED_HPP_
