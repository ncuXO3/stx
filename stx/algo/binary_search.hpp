#ifndef STX_ALGO_BINARY_SEARCH_HPP_
#define STX_ALGO_BINARY_SEARCH_HPP_

#include <functional>

namespace stx {

template<typename RandomAccessIterator, typename T>
RandomAccessIterator binary_search(RandomAccessIterator begin, RandomAccessIterator end, const T& value)
{
    RandomAccessIterator ret(end), iter, prev_iter(end), left(begin), right(end);
    std::less<T> cmp;
    while (1) {
        iter = left + (right - left)/2;
        if (*iter == value) { ret = iter; break; }
        if (iter == prev_iter) break;
        if (cmp(value, *iter)) right = iter;
        else left = iter;
        prev_iter = iter;
    }
    return ret;
}

} // namespace stx

#endif // STX_ALGO_BINARY_SEARCH_HPP_
