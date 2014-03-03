#ifndef STX_MISC_COUNT_LEADING_ZERO_BITS_HPP_
#define STX_MISC_COUNT_LEADING_ZERO_BITS_HPP_

#include <stx/common.hpp>

namespace stx {

inline unsigned count_leading_zero_bits_assume_not_all_zeros(uint32_t x)
{
#   if defined(__GNUC__) || __has_builtin(__builtin_clz)
    //  __builtin_clz()
    //  Returns the number of leading 0-bits in x,
    //  starting at the most significant bit position.
    //  If x is 0, the result is undefined.
    return __builtin_clz(x); 
    
#   elif defined(_MSC_VER)
    unsigned long index;
    //  _BitScanReverse()
    //  Search the mask data from most significant bit (MSB)
    //  to least significant bit (LSB) for a set bit (1).
    //  Returns: 0 if the mask is zero; nonzero otherwise.
    _BitScanReverse(&index, x);
    return index;

#   else
    const unsigned num_bits = sizeof(x)*CHAR_BIT;
    unsigned num_zeroes = 0;
    const unsigned mask = 1 << (num_bits - 1);
    for (unsigned i = 0; i < num_bits; ++i) {
        if (((x << i) & mask) == 0) {
            ++num_zeroes;
        } else {
            break;
        }
    }
    return num_zeroes;
    
#   endif
}

inline unsigned count_leading_zero_bits(uint32_t x)
{
    const unsigned num_bits = sizeof(x)*CHAR_BIT;
    if (x == 0) return num_bits;
    return count_leading_zero_bits_assume_not_all_zeros(x);
}

inline unsigned count_leading_zero_bits(uint64_t x)
{
    const uint32_t z = x >> 32;
    unsigned n;
    if (z != 0) {
        n = count_leading_zero_bits_assume_not_all_zeros(z);
    } else {
        n = 32 + count_leading_zero_bits((uint32_t) (x & 0xffffffff));
    }
    return n;
}

} // namespace stx

#endif // STX_MISC_COUNT_LEADING_ZERO_BITS_HPP_
