#ifndef STX_MISC_SCOPED_FREE_HPP_
#define STX_MISC_SCOPED_FREE_HPP_

#include <stdlib.h>

namespace stx {

class scoped_free
{
public:
    scoped_free(): p(0) {}
    scoped_free(void *_p): p(_p) {}
    ~scoped_free() { release(); }
    void release() { if (p) free(p); }
    void reset(void *_p) { release(); p = _p; }
    void* get() const { return p; }
    
private:
    scoped_free(const scoped_free&);
    scoped_free& operator =(const scoped_free&);
    void *p;
};

} // namespace stx

#endif // STX_MISC_SCOPED_FREE_HPP_
