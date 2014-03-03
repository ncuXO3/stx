#ifndef STX_TYPE_TRAITS_EXACT_SIZE_INT_HPP_
#define STX_TYPE_TRAITS_EXACT_SIZE_INT_HPP_

#include <stx/common.hpp>

namespace stx {

template <size_t size> struct exact_size_int;
template <> struct exact_size_int<1> { typedef int8_t  type; };
template <> struct exact_size_int<2> { typedef int16_t type; };
template <> struct exact_size_int<4> { typedef int32_t type; };
template <> struct exact_size_int<8> { typedef int64_t type; };

template <size_t size> struct exact_size_uint;
template <> struct exact_size_uint<1> { typedef uint8_t  type; };
template <> struct exact_size_uint<2> { typedef uint16_t type; };
template <> struct exact_size_uint<4> { typedef uint32_t type; };
template <> struct exact_size_uint<8> { typedef uint64_t type; };

} // namespace stx

#endif // STX_TYPE_TRAITS_EXACT_SIZE_INT_HPP_
