#ifndef STX_TYPE_TRAITS_IS_CONTAINER_HPP_
#define STX_TYPE_TRAITS_IS_CONTAINER_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/has_nested_type.hpp>

namespace stx {

template <class T>
struct is_container: public integral_constant<bool,
    has_value_type<T>::value &&
    has_size_type<T>::value &&
    has_difference_type<T>::value &&
    has_pointer<T>::value &&
    has_const_pointer<T>::value &&
    has_reference<T>::value &&
    has_const_reference<T>::value &&
    has_iterator<T>::value &&
    has_const_iterator<T>::value &&
    has_reverse_iterator<T>::value &&
    has_const_reverse_iterator<T>::value &&
    has_allocator_type<T>::value/**/
> {};

} // namespace stx

#endif // STX_TYPE_TRAITS_IS_CONTAINER_HPP_
