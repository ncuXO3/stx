#ifndef STX_TYPE_TRAITS_EXTENT_HPP_
#define STX_TYPE_TRAITS_EXTENT_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <class T, unsigned N = 0>
struct extent: integral_constant<size_t, 0> {};
 
template <class T>
struct extent<T[], 0>: integral_constant<size_t, 0> {};
 
template <class T, unsigned N>
struct extent<T[], N>: integral_constant<size_t, extent<T, N-1>::value> {};
 
template <class T, size_t N>
struct extent<T[N], 0>: integral_constant<size_t, N> {};
 
template <class T, size_t I, unsigned N>
struct extent<T[I], N>: integral_constant<size_t, extent<T, N-1>::value> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_EXTENT_HPP_
