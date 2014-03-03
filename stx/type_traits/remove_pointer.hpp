#ifndef STX_TYPE_TRAITS_REMOVE_POINTER_HPP_
#define STX_TYPE_TRAITS_REMOVE_POINTER_HPP_

namespace stx {

template <class T> struct remove_pointer                    { typedef T type; };
template <class T> struct remove_pointer<T*>                { typedef T type; };
template <class T> struct remove_pointer<T* const>          { typedef T type; };
template <class T> struct remove_pointer<T* volatile>       { typedef T type; };
template <class T> struct remove_pointer<T* const volatile> { typedef T type; };

} // namespace stx

#endif // STX_TYPE_TRAITS_REMOVE_POINTER_HPP_
