#ifndef STX_TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_HPP_
#define STX_TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/is_scalar.hpp>

namespace stx {

template <class T, class Enable = void>
struct is_trivially_copyable: false_type {};

template <class T>
struct is_trivially_copyable<T, typename enable_if<is_scalar<T>::value>::type>: true_type {};

#define STX_TRIVIALLY_COPYABLE(type) \
    namespace stx { template <> struct is_trivially_copyable<type>: true_type {}; }

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_TRIVIALLY_COPYABLE_HPP_
