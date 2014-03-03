#ifndef STX_TYPE_TRAITS_IS_REFERENCE_HPP_
#define STX_TYPE_TRAITS_IS_REFERENCE_HPP_

#include <stx/common.hpp>
#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <class T> struct is_reference: false_type {};
template <class T> struct is_reference<T&>: true_type {};
#if STX_CPP11
template <class T> struct is_reference<T&&>: true_type {};
#endif

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_REFERENCE_HPP_
