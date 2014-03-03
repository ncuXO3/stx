#ifndef STX_MISC_PRINT_MAP_HPP_
#define STX_MISC_PRINT_MAP_HPP_

#include <map>
#include <stddef.h>
#include <iostream>

#if __cplusplus >= 201103L
#include <unordered_map>
#endif

namespace stx {

template <class Ostream, class Iterator>
inline Ostream& print_map(Ostream& os, Iterator first, Iterator last)
{
    os << "{";
    while (first != last) {
        os << first->first << ": " << first->second;
        ++first;
        if (first != last) {
            os << ", ";
        }
    }
    os << "}";
    return os;
}

template <class Ostream, class Key, class T, class Compare, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::map<Key, T, Compare, Allocator>& x)
{
    return print_map(os, x.begin(), x.end());
}

template <class Ostream, class Key, class T, class Compare, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::multimap<Key, T, Compare, Allocator>& x)
{
    return print_map(os, x.begin(), x.end());
}

#if __cplusplus >= 201103L

template <class Ostream, class Key, class T, class Hash, class Pred, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::unordered_map<Key, T, Hash, Pred, Allocator>& x)
{
    return print_map(os, x.begin(), x.end());
}

template <class Ostream, class Key, class T, class Hash, class Pred, class Allocator>
inline Ostream& operator <<(Ostream& os, const std::unordered_multimap<Key, T, Hash, Pred, Allocator>& x)
{
    return print_map(os, x.begin(), x.end());
}

#endif

} // namespace stx

#endif // STX_MISC_PRINT_MAP_HPP_
