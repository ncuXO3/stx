#ifndef STX_TYPE_TRAITS_REMOVE_EXTENT_HPP_
#define STX_TYPE_TRAITS_REMOVE_EXTENT_HPP_

namespace stx {

template <class T>
struct remove_extent { typedef T type; };
 
template <class T>
struct remove_extent<T[]> { typedef T type; };
 
template <class T, size_t N>
struct remove_extent<T[N]> { typedef T type; };

} // namespace stx

#endif // STX_TYPE_TRAITS_REMOVE_EXTENT_HPP_
