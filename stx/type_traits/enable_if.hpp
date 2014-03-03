#ifndef STX_TYPE_TRAITS_ENABLE_IF_HPP_
#define STX_TYPE_TRAITS_ENABLE_IF_HPP_

namespace stx {

template <bool B, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> { typedef T type; };

} // namespace stx

#endif // STX_TYPE_TRAITS_ENABLE_IF_HPP_
