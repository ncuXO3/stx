#ifndef STX_TYPE_TRAITS_REMOVE_CV_HPP_
#define STX_TYPE_TRAITS_REMOVE_CV_HPP_

namespace stx {

template <class T> struct remove_const          { typedef T type; };
template <class T> struct remove_const<const T> { typedef T type; };

template <class T> struct remove_volatile             { typedef T type; };
template <class T> struct remove_volatile<volatile T> { typedef T type; };

template <class T>
struct remove_cv {
    typedef typename remove_volatile<typename remove_const<T>::type>::type type;
};

} // namespace stx

#endif // STX_TYPE_TRAITS_REMOVE_CV_HPP_
