#ifndef STX_TYPE_TRAITS_IS_LVALUE_REFERENCE_HPP_
#define STX_TYPE_TRAITS_IS_LVALUE_REFERENCE_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <class T> struct is_lvalue_reference: false_type {};
template <class T> struct is_lvalue_reference<T&>: true_type {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_LVALUE_REFERENCE_HPP_
