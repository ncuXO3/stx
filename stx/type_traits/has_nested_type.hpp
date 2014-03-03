#ifndef STX_TYPE_TRAITS_HAS_NESTED_TYPE_HPP_
#define STX_TYPE_TRAITS_HAS_NESTED_TYPE_HPP_

#include <stx/type_traits/integral_constant.hpp>
#include <stx/type_traits/remove_reference.hpp>

namespace stx {

#define STX_HAS_NESTED_TYPE_IMPL0(Name, NestedType)                           \
    template <class T>                                                        \
    class Name ## _impl                                                       \
    {                                                                         \
        typedef char                      yes;                                \
        typedef struct { char array[2]; } no;                                 \
                                                                              \
        template <class U>                                                    \
        static yes test(                                                      \
            remove_reference<typename U::NestedType>*) { return yes(); }      \
                                                                              \
        template <class U>                                                    \
        static no test(...) { return no(); }                                  \
                                                                              \
    public:                                                                   \
        typedef integral_constant<bool,                                       \
            sizeof(test<T>(0)) == sizeof(yes)> bool_type;                     \
        typedef T type;                                                       \
    };                                                                        \
                                                                              \
    template <class T>                                                        \
    struct Name: public Name ## _impl<T>::bool_type {};

#define STX_HAS_NESTED_TYPE_IMPL(NestedType) \
    STX_HAS_NESTED_TYPE_IMPL0(has_ ## NestedType, NestedType)

STX_HAS_NESTED_TYPE_IMPL(value_type)
STX_HAS_NESTED_TYPE_IMPL(size_type)
STX_HAS_NESTED_TYPE_IMPL(difference_type)
STX_HAS_NESTED_TYPE_IMPL(pointer)
STX_HAS_NESTED_TYPE_IMPL(const_pointer)
STX_HAS_NESTED_TYPE_IMPL(reference)
STX_HAS_NESTED_TYPE_IMPL(const_reference)
STX_HAS_NESTED_TYPE_IMPL(iterator)
STX_HAS_NESTED_TYPE_IMPL(const_iterator)
STX_HAS_NESTED_TYPE_IMPL(reverse_iterator)
STX_HAS_NESTED_TYPE_IMPL(const_reverse_iterator)
STX_HAS_NESTED_TYPE_IMPL(allocator_type)

} // namespace stx

#endif // STX_TYPE_TRAITS_HAS_NESTED_TYPE_HPP_
