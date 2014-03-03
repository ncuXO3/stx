#ifndef STX_TYPE_TRAITS_CONDITIONAL_HPP_
#define STX_TYPE_TRAITS_CONDITIONAL_HPP_

#include <stx/type_traits/integral_constant.hpp>

namespace stx {

template <bool B, class T, class F>
struct conditional { typedef T type; };
 
template <class T, class F>
struct conditional<false, T, F> { typedef F type; };

} // namespace stx

#endif // STX_TYPE_TRAITS_CONDITIONAL_HPP_
