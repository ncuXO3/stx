#ifndef STX_MISC_PRINT_VECTOR_HPP_
#define STX_MISC_PRINT_VECTOR_HPP_

#include <vector>
#include <deque>
#include <list>
#include <stddef.h>
#include <iostream>

#if __cplusplus >= 201103L
#include <array>
#include <forward_list>
#endif

namespace stx {

template <class Ostream, class Iterator>
inline Ostream& print_sequence(Ostream& os, Iterator first, Iterator last)
{
    os << "[";
    while (first != last) {
        os << *first;
        ++first;
        if (first != last) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <class Ostream, class T, class A>
inline Ostream& operator <<(Ostream& os, const std::vector<T, A>& x)
{
    return print_sequence(os, x.begin(), x.end());
}

template <class Ostream, class T, class A>
inline Ostream& operator <<(Ostream& os, const std::deque<T, A>& x)
{
    return print_sequence(os, x.begin(), x.end());
}

template <class Ostream, class T, class A>
inline Ostream& operator <<(Ostream& os, const std::list<T, A>& x)
{
    return print_sequence(os, x.begin(), x.end());
}

#if __cplusplus >= 201103L

template <class Ostream, class T, size_t N>
inline Ostream& operator <<(Ostream& os, const std::array<T, N>& x)
{
    return print_sequence(os, x.begin(), x.end());
}

template <class Ostream, class T, class A>
inline Ostream& operator <<(Ostream& os, const std::forward_list<T, A>& x)
{
    return print_sequence(os, x.begin(), x.end());
}

#endif

} // namespace stx

#endif // STX_MISC_PRINT_VECTOR_HPP_
