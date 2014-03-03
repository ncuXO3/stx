#ifndef STX_TYPE_TRAITS_SAME_SIZE_INT_HPP_
#define STX_TYPE_TRAITS_SAME_SIZE_INT_HPP_

#include <stx/type_traits/exact_size_int.hpp>

namespace stx {

template <class T>
struct same_size_int: exact_size_int<sizeof(T)> {};

template <class T>
struct same_size_uint: exact_size_uint<sizeof(T)> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_SAME_SIZE_INT_HPP_
