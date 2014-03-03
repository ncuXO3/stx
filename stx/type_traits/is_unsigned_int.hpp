#ifndef STX_TYPE_TRAITS_IS_UNSIGNED_INT_HPP_
#define STX_TYPE_TRAITS_IS_UNSIGNED_INT_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/enable_if.hpp>
#include <stx/type_traits/is_integral.hpp>

namespace stx {

template <class T, class Enable = void>
struct is_unsigned_int_helper { typedef int type; };

template <class T>
struct is_unsigned_int_helper<T,
    typename enable_if<is_integral<T>::value>::type> { typedef T type; };

template <class T>
struct is_unsigned_int: integral_constant<bool,
    (typename is_unsigned_int_helper<T>::type) -1 >= 0 ? true : false> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_UNSIGNED_INT_HPP_
