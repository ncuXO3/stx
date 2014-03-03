#ifndef STX_MISC_IS_SORTED_HPP_
#define STX_MISC_IS_SORTED_HPP_

#include <stx/common.hpp>
#include <iterator>

namespace stx {

template <class Iterator>
inline bool is_sorted(Iterator first, Iterator last)
{
    using namespace std;
    typedef typename iterator_traits<Iterator>::value_type value_type;
    if (first == last) return false;
    bool _is_sorted = true;
    value_type prev_val = *first;
    ++first;
    for (; first != last; ++first) {
        if (prev_val <= *first) {
            prev_val = *first;
            continue;
        } else {
            _is_sorted = false;
            break;
        }
    }
    return _is_sorted;
}

} // namespace stx

#endif // STX_MISC_IS_SORTED_HPP_
