#ifndef STX_TYPE_TRAITS_RANK_HPP_
#define STX_TYPE_TRAITS_RANK_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <class T>
struct rank: integral_constant<size_t, 0> {};
 
template <class T>
struct rank<T[]>: public integral_constant<size_t, rank<T>::value + 1> {};
 
template <class T, size_t N>
struct rank<T[N]>: public integral_constant<size_t, rank<T>::value + 1> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_RANK_HPP_
