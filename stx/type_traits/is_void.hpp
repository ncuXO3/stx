#ifndef STX_TYPE_TRAITS_IS_VOID_HPP_
#define STX_TYPE_TRAITS_IS_VOID_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <class T>
struct is_void: integral_constant<bool,
    is_same<void, typename remove_cv<T>::type>::value> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_VOID_HPP_
