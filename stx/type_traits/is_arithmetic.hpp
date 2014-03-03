#ifndef STX_TYPE_TRAITS_IS_ARITHMETIC_HPP_
#define STX_TYPE_TRAITS_IS_ARITHMETIC_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/is_integral.hpp>
#include <stx/type_traits/is_floating_point.hpp>

namespace stx {

template <class T>
struct is_arithmetic: integral_constant<
    bool, is_integral<T>::value || is_floating_point<T>::value> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_ARITHMETIC_HPP_
