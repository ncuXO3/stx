#ifndef STX_TYPE_TRAITS_IS_SIGNED_HPP_
#define STX_TYPE_TRAITS_IS_SIGNED_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/is_signed_int.hpp>

namespace stx {

template <class T, class Enable = void>
struct is_signed: false_type {};

template <class T>
struct is_signed<T,
    typename enable_if<
        is_signed_int<T>::value ||
        is_same<T, float>::value ||
        is_same<T, double>::value ||
        is_same<T, long double>::value
    >::type>: true_type
{};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_SIGNED_HPP_
