#ifndef STX_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP_
#define STX_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP_

namespace stx {

template <class T, T v>
struct integral_constant
{
    static const T value = v;
    typedef T value_type;
    typedef integral_constant type;
#if STX_CPP11
    constexpr operator value_type() const { return value; }
    constexpr value_type operator()() const { return value; }
#else
    operator value_type() const { return value; }
    value_type operator()() const { return value; }
#endif
};

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

template <class T, class U> struct is_same:       false_type {};
template <class T>          struct is_same<T, T>: true_type {};

} // namespace stx

#endif // STX_TYPE_TRAITS_INTEGRAL_CONSTANT_HPP_
