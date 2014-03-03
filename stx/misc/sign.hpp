#ifndef STX_MISC_SIGN_HPP_
#define STX_MISC_SIGN_HPP_

#include <stx/common.hpp>

namespace stx {

template <class T>
inline int sign(const T& x)
{
    return (x < 0 ? -1 : 1);
}

template <class T>
inline int sign_or_zero(const T& x)
{
    return (x < 0 ? -1 : (x == 0 ? 0 : 1));
}

} // namespace stx

#endif // STX_MISC_SIGN_HPP_
