#ifndef STX_TYPE_TRAITS_IS_SIGNED_INT_HPP_
#define STX_TYPE_TRAITS_IS_SIGNED_INT_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/enable_if.hpp>

namespace stx {

template <class T, class Enable = void>
struct is_signed_int_helper: false_type { typedef unsigned type; };

template <class T>
struct is_signed_int_helper<T,
    typename enable_if<is_integral<T>::value>::type>: true_type
{ typedef T type; };

template <class T>
struct is_signed_int: integral_constant<bool,
    (typename is_signed_int_helper<T>::type) -1 < 0 ? true: false>
{};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_SIGNED_INT_HPP_
