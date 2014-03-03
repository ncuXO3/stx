#ifndef STX_TYPE_TRAITS_IS_FLOATING_POINT_HPP_
#define STX_TYPE_TRAITS_IS_FLOATING_POINT_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/remove_cv.hpp>

namespace stx {

template <class T>
struct is_floating_point: integral_constant<
    bool,
    is_same<float,       typename remove_cv<T>::type>::value ||
    is_same<double,      typename remove_cv<T>::type>::value ||
    is_same<long double, typename remove_cv<T>::type>::value>
{};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_FLOATING_POINT_HPP_
