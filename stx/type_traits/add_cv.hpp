#ifndef STX_TYPE_TRAITS_ADD_CV_HPP_
#define STX_TYPE_TRAITS_ADD_CV_HPP_

namespace stx {

template <class T> struct add_const { typedef const T type; };
 
template <class T> struct add_volatile { typedef volatile T type; };

template <class T>
struct add_cv {
    typedef typename add_volatile<typename add_const<T>::type>::type type;
};

} // namespace stx

#endif // STX_TYPE_TRAITS_ADD_CV_HPP_
