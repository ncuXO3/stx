#ifndef STX_TYPE_TRAITS_IS_ARRAY_HPP_
#define STX_TYPE_TRAITS_IS_ARRAY_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <class T>
struct is_array: false_type {};

template <class T>
struct is_array<T[]>: true_type {};

template <class T, size_t N>
struct is_array<T[N]>: true_type {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_ARRAY_HPP_
