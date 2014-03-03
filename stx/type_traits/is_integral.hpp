#ifndef STX_TYPE_TRAITS_IS_INTEGRAL_HPP_
#define STX_TYPE_TRAITS_IS_INTEGRAL_HPP_

#include <stx/common.hpp>
#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/remove_cv.hpp>

namespace stx {

template <class T>
struct is_integral: integral_constant<
    bool,
    is_same<char,     typename remove_cv<T>::type>::value ||
    is_same<schar,    typename remove_cv<T>::type>::value ||
    is_same<uchar,    typename remove_cv<T>::type>::value ||
    is_same<short,    typename remove_cv<T>::type>::value ||
    is_same<ushort,   typename remove_cv<T>::type>::value ||
    is_same<int,      typename remove_cv<T>::type>::value ||
    is_same<uint,     typename remove_cv<T>::type>::value ||
    is_same<long,     typename remove_cv<T>::type>::value ||
    is_same<ulong,    typename remove_cv<T>::type>::value ||
    is_same<llong,    typename remove_cv<T>::type>::value ||
    is_same<ullong,   typename remove_cv<T>::type>::value ||
    is_same<bool,     typename remove_cv<T>::type>::value ||
    is_same<wchar_t,  typename remove_cv<T>::type>::value
#if STX_CPP11
    || is_same<char16_t, typename remove_cv<T>::type>::value
    || is_same<char32_t, typename remove_cv<T>::type>::value
#endif
> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_INTEGRAL_HPP_
