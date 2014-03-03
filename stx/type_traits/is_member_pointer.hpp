#ifndef STX_TYPE_TRAITS_IS_MEMBER_POINTER_HPP_
#define STX_TYPE_TRAITS_IS_MEMBER_POINTER_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/remove_cv.hpp>

namespace stx {

template <class T>
struct is_member_pointer_helper: false_type {};

template <class T, class U>
struct is_member_pointer_helper<T U::*>: true_type {};

template <class T>
struct is_member_pointer: is_member_pointer_helper<typename remove_cv<T>::type> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_MEMBER_POINTER_HPP_
