#ifndef STX_TYPE_TRAITS_ADD_POINTER_HPP_
#define STX_TYPE_TRAITS_ADD_POINTER_HPP_

#include <stx/type_traits/remove_reference.hpp>

namespace stx {

template <class T>
struct add_pointer {
    typedef typename remove_reference<T>::type* type;
};

} // namespace stx

#endif // STX_TYPE_TRAITS_ADD_POINTER_HPP_
