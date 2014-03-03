#ifndef STX_TYPE_TRAITS_IS_UNSIGNED_HPP_
#define STX_TYPE_TRAITS_IS_UNSIGNED_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/is_unsigned_int.hpp>

namespace stx {

template <class T, class Enable = void>
struct is_unsigned: false_type {};

template <class T>
struct is_unsigned<T,
    typename enable_if<
        is_unsigned_int<T>::value
    >::type>: true_type
{};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_UNSIGNED_HPP_
