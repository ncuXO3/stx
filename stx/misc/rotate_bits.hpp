#ifndef STX_MISC_ROTATE_BITS_HPP_
#define STX_MISC_ROTATE_BITS_HPP_

#include <stx/common.hpp>

namespace stx {

template <class UnsignedInteger>
inline UnsignedInteger rotate_bits_left(UnsignedInteger value, unsigned shift)
{
    return (value << shift) | (value >> (sizeof(value)*CHAR_BIT - shift));
}
 
template <class UnsignedInteger>
inline UnsignedInteger rotate_bits_right(UnsignedInteger value, unsigned shift)
{
    return (value >> shift) | (value << (sizeof(value)*CHAR_BIT - shift));
}

} // namespace stx

#endif // STX_MISC_ROTATE_BITS_HPP_
