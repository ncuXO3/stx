#ifndef STX_MISC_ROUND_TO_POW_2_HPP_
#define STX_MISC_ROUND_TO_POW_2_HPP_

#include <stx/common.hpp>

namespace stx {

inline uint32_t round_to_next_pow_2(uint32_t x)
{
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    ++x;
    return x;
}

inline int32_t round_to_next_pow_2(int32_t x)
{
    return round_to_next_pow_2((uint32_t) x);
}

inline uint64_t round_to_next_pow_2(uint64_t x)
{
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    ++x;
    return x;
}

inline int64_t round_to_next_pow_2(int64_t x)
{
    return round_to_next_pow_2((uint64_t) x);
}

inline uint32_t round_to_prev_pow_2(uint32_t x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x - (x >> 1);
}

inline int32_t round_to_prev_pow_2(int32_t x)
{
    return round_to_prev_pow_2((uint32_t) x);
}

inline uint64_t round_to_prev_pow_2(uint64_t x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    return x - (x >> 1);
}

inline int64_t round_to_prev_pow_2(int64_t x)
{
    return round_to_prev_pow_2((uint64_t) x);
}

} // namespace stx

#endif // STX_MISC_ROUND_TO_POW_2_HPP_
