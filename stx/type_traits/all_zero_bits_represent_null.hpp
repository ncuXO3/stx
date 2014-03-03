#ifndef STX_TYPE_TRAITS_ALL_ZERO_BITS_REPRESENT_NULL_HPP_
#define STX_TYPE_TRAITS_ALL_ZERO_BITS_REPRESENT_NULL_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/is_integral.hpp>
#include <stx/type_traits/is_pointer.hpp>
#include <limits>

namespace stx {

template <class T, class Enable = void>
struct all_zero_bits_represent_null: false_type {};

template <class T>
struct all_zero_bits_represent_null<T,
    typename enable_if<
        is_integral<T>::value ||
        std::numeric_limits<T>::is_iec559 ||
        is_pointer<T>::value // May be false for pointers on some platforms.
    >::type
>: true_type {};

} // namespace stx

#endif // STX_TYPE_TRAITS_ALL_ZERO_BITS_REPRESENT_NULL_HPP_
