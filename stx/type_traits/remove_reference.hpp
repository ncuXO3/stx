#ifndef STX_TYPE_TRAITS_REMOVE_REFERENCE_HPP_
#define STX_TYPE_TRAITS_REMOVE_REFERENCE_HPP_

#include <stx/common.hpp>

namespace stx {

template <class T> struct remove_reference      { typedef T type; };
template <class T> struct remove_reference<T&>  { typedef T type; };
#if STX_CPP11
template <class T> struct remove_reference<T&&> { typedef T type; };
#endif

} // namespace stx

#endif // STX_TYPE_TRAITS_REMOVE_REFERENCE_HPP_
