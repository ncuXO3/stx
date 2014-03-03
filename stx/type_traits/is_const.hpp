#ifndef STX_TYPE_TRAITS_IS_CONST_HPP_
#define STX_TYPE_TRAITS_IS_CONST_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <class T> struct is_const:          false_type {};
template <class T> struct is_const<const T>: true_type {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_CONST_HPP_
