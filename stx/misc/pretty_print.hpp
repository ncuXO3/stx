#ifndef STX_MISC_PRETTY_PRINT_HPP_
#define STX_MISC_PRETTY_PRINT_HPP_

#include <stx/begin_end.hpp>
#include <stx/type_traits.hpp>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <utility>

#if __cplusplus >= 201103L
#include <array>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#endif

namespace stx {

enum {
    STX_CONTAINER_TYPE_UNKNOWN,
    STX_CONTAINER_TYPE_SEQUENCE,
    STX_CONTAINER_TYPE_SET,
    STX_CONTAINER_TYPE_MAP
};

template <class T>
inline int container_type(const T& x)
{ return STX_CONTAINER_TYPE_UNKNOWN; }

template <class T, class A>
inline int container_type(const std::vector<T, A>& x)
{ return STX_CONTAINER_TYPE_SEQUENCE; }

template <class T, class A>
inline int container_type(const std::deque<T, A>& x)
{ return STX_CONTAINER_TYPE_SEQUENCE; }

template <class T, class A>
inline int container_type(const std::list<T, A>& x)
{ return STX_CONTAINER_TYPE_SEQUENCE; }

template <class T, class C, class A>
inline int container_type(const std::set<T, C, A>& x)
{ return STX_CONTAINER_TYPE_SET; }

template <class T, class C, class A>
inline int container_type(const std::multiset<T, C, A>& x)
{ return STX_CONTAINER_TYPE_SET; }

template <class K, class T, class C, class A>
inline int container_type(const std::map<K, T, C, A>& x)
{ return STX_CONTAINER_TYPE_MAP; }

template <class K, class T, class C, class A>
inline int container_type(const std::multimap<K, T, C, A>& x)
{ return STX_CONTAINER_TYPE_MAP; }

#if __cplusplus >= 201103L

template <class T, size_t N>
inline int container_type(const std::array<T, N>& x)
{ return STX_CONTAINER_TYPE_SEQUENCE; }

template <class T, class A>
inline int container_type(const std::forward_list<T, A>& x)
{ return STX_CONTAINER_TYPE_SEQUENCE; }

template <class T, class C, class A>
inline int container_type(const std::unordered_set<T, C, A>& x)
{ return STX_CONTAINER_TYPE_SET; }

template <class T, class C, class A>
inline int container_type(const std::unordered_multiset<T, C, A>& x)
{ return STX_CONTAINER_TYPE_SET; }

template <class K, class T, class H, class P, class A>
inline int container_type(const std::unordered_map<K, T, H, P, A>& x)
{ return STX_CONTAINER_TYPE_MAP; }

template <class K, class T, class H, class P, class A>
inline int container_type(const std::unordered_multimap<K, T, H, P, A>& x)
{ return STX_CONTAINER_TYPE_MAP; }

#endif

template <class Ostream, class T1, class T2>
inline Ostream& operator <<(Ostream& out, const std::pair<T1, T2>& x)
{
    out << "(" << x.first << ", " << x.second << ")";
    return out;
}

template <class Ostream, class T>
inline Ostream& print_container_element(Ostream& out, const T& x, int _container_type)
{
    out << x;
    return out;
}

template <class Ostream, class T1, class T2>
inline Ostream& print_container_element(Ostream& out, const std::pair<T1, T2>& x, int _container_type)
{
    if (_container_type == STX_CONTAINER_TYPE_MAP) {
        out << x.first << ": " << x.second;
    } else {
        out << x;
    }
    return out;
}

template <class Ostream, class Container>
inline Ostream& print_container(Ostream& out, const Container& x)
{
    typename Container::const_iterator first = stx::begin(x);
    typename Container::const_iterator last = stx::end(x);

    const char* open_str = "[";
    const char* close_str = "]";
    const char* delimiter_str = ", ";

    int type = container_type(x);
    switch (type) {
    case STX_CONTAINER_TYPE_SEQUENCE:
        open_str = "[";
        close_str = "]";
        break;
    case STX_CONTAINER_TYPE_SET:
    case STX_CONTAINER_TYPE_MAP:
        open_str = "{";
        close_str = "}";
        break;
    }

    out << open_str;
    while (first != last) {
        print_container_element(out, *first, type);
        ++first;
        if (first != last) {
            out << delimiter_str;
        }
    }
    out << close_str;

    return out;
}

template <class Ostream, class Container>
inline Ostream& print(Ostream& out, const Container& x, true_type)
{
    return print_container(out, x);
}

template <class Ostream, class Container>
inline Ostream& print(Ostream& out, const Container& x, false_type)
{
    out << x;
    return out;
}

template <class Ostream, class Container>
inline Ostream& operator <<(Ostream& out, const Container& x)
{
    return print(out, x, typename is_container<Container>::type());
}

#if __cplusplus >= 201103L

template<class Ostream, class Type, unsigned N, unsigned Last>
struct tuple_printer
{
    static void print(Ostream& out, const Type& value)
    {
        out << std::get<N>(value) << ", ";
        tuple_printer<Ostream, Type, N + 1, Last>::print(out, value);
    }
};

template<class Ostream, class Type, unsigned N>
struct tuple_printer<Ostream, Type, N, N>
{
    static void print(Ostream& out, const Type& value)
    {
        out << std::get<N>(value);
    }
};

template<class Ostream>
Ostream& operator <<(Ostream& out, const std::tuple<>& value)
{
    out << "()";
    return out;
}

template<class Ostream, class... Types>
Ostream& operator <<(Ostream& out, const std::tuple<Types...>& value)
{
    out << "(";
    tuple_printer<Ostream, std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    out << ")";
    return out;
}

#endif

} // namespace stx

#endif // STX_MISC_PRETTY_PRINT_HPP_
