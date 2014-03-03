#ifndef STX_TYPE_TRAITS_REMOVE_ALL_EXTENTS_HPP_
#define STX_TYPE_TRAITS_REMOVE_ALL_EXTENTS_HPP_

namespace stx {

template <class T>
struct remove_all_extents { typedef T type; };
 
template <class T>
struct remove_all_extents<T[]> {
    typedef typename remove_all_extents<T>::type type;
};
 
template <class T, size_t N>
struct remove_all_extents<T[N]> {
    typedef typename remove_all_extents<T>::type type;
};

} // namespace stx

#endif // STX_TYPE_TRAITS_REMOVE_ALL_EXTENTS_HPP_
