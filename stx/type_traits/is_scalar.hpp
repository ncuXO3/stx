#ifndef STX_TYPE_TRAITS_IS_SCALAR_HPP_
#define STX_TYPE_TRAITS_IS_SCALAR_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/is_arithmetic.hpp>
#include <stx/type_traits/is_pointer.hpp>
#include <stx/type_traits/is_member_pointer.hpp>
#include <stx/type_traits/remove_cv.hpp>

namespace stx {

template <class T>
struct is_scalar: integral_constant<bool,
    is_arithmetic<T>::value ||
    is_pointer<T>::value ||
    is_member_pointer<T>::value
    /* || is_enum<T>::value
    || is_same<nullptr_t, typename remove_cv<T>::type>::value */
> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_SCALAR_HPP_
