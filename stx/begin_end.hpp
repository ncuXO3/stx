#ifndef STX_BEGIN_END_HPP_
#define STX_BEGIN_END_HPP_

namespace stx {

//  TODO: rbegin, rend, crbegin, crend

template <class Container>
inline typename Container::iterator begin(Container& v)
{ return v.begin(); }

template <class Container>
inline typename Container::const_iterator begin(const Container& v)
{ return v.begin(); }

template <class T, size_t N>
T* begin(T (&arr)[N])
{ return &arr[0]; }

template <class Container>
inline typename Container::const_iterator cbegin(const Container& v)
{ return begin(v); }

template <class T, size_t N>
const T* cbegin(T (&arr)[N])
{ return &arr[0]; }

template <class Container>
inline typename Container::iterator end(Container& v)
{ return v.end(); }

template <class Container>
inline typename Container::const_iterator end(const Container& v)
{ return v.end(); }

template <class T, size_t N>
T* end(T (&arr)[N])
{ return &arr[N]; }

template <class Container>
inline typename Container::const_iterator cend(const Container& v)
{ return end(v); }

template <class T, size_t N>
const T* cend(T (&arr)[N])
{ return &arr[N]; }

} // namespace stx

#endif // STX_BEGIN_END_HPP_
