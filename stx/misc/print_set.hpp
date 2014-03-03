#ifndef STX_MISC_PRINT_SET_HPP_
#define STX_MISC_PRINT_SET_HPP_

#include <set>
#include <stddef.h>
#include <iostream>

#if __cplusplus >= 201103L
#include <unordered_set>
#endif

namespace stx {

template <class Ostream, class Iterator>
inline Ostream& print_set(Ostream& os, Iterator first, Iterator last)
{
    os << "{";
    while (first != last) {
        os << *first;
        ++first;
        if (first != last) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

template <class Ostream, class T, class Compare, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::set<T, Compare, Allocator>& x)
{
    return print_set(os, x.begin(), x.end());
}

template <class Ostream, class T, class Compare, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::multiset<T, Compare, Allocator>& x)
{
    return print_set(os, x.begin(), x.end());
}

#if __cplusplus >= 201103L

template <class Ostream, class Key, class Hash, class Pred, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::unordered_set<Key, Hash, Pred, Allocator>& x)
{
    return print_set(os, x.begin(), x.end());
}

template <class Ostream, class Key, class Hash, class Pred, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::unordered_multiset<Key, Hash, Pred, Allocator>& x)
{
    return print_set(os, x.begin(), x.end());
}

#endif

} // namespace stx

#endif // STX_MISC_PRINT_SET_HPP_
