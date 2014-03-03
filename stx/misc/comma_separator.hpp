#ifndef STX_MISC_COMMA_SEPARATOR_HPP_
#define STX_MISC_COMMA_SEPARATOR_HPP_

#include <locale>

namespace stx {

//  Usage: std::cout.imbue(std::locale(std::locale(""), new comma_separator<char>));

template <typename T>
struct comma_separator: std::numpunct<T>
{
    typename std::numpunct<T>::char_type do_decimal_point() const
    {
        return ',';
    }
};

} // namespace stx

#endif // STX_MISC_COMMA_SEPARATOR_HPP_
