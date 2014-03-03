#ifndef STX_TYPE_TRAITS_IS_COMPOUND_HPP_
#define STX_TYPE_TRAITS_IS_COMPOUND_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/is_fundamental.hpp>

namespace stx {

template <class T>
struct is_compound: integral_constant<bool, !is_fundamental<T>::value> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_COMPOUND_HPP_
