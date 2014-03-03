#ifndef STX_TYPE_TRAITS_IS_VOLATILE_HPP_
#define STX_TYPE_TRAITS_IS_VOLATILE_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template<class T> struct is_volatile: false_type {};
template<class T> struct is_volatile<volatile T>: true_type {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_VOLATILE_HPP_
