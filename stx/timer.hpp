#ifndef STX_TIMER_HPP_
#define STX_TIMER_HPP_

#include <time.h>

#ifdef CLOCK_REALTIME

namespace stx {

template <clockid_t clock_id>
class basic_timer
{
public:
    basic_timer() { reset(); }
    basic_timer(const basic_timer& t) { t_ = t.t_; }
    basic_timer& operator =(const basic_timer& t) { t_ = t.t_; return *this; }
    void reset() { clock_gettime(clock_id, &t_); }
    double elapsed() const
    {
        struct timespec current_time;
        (void) clock_gettime(clock_id, &current_time);
        return (double) (current_time.tv_sec - t_.tv_sec)
            + 1.0e-9*((double) current_time.tv_nsec - t_.tv_nsec);
    }

private:
    struct timespec t_;
};

typedef basic_timer<CLOCK_REALTIME> timer;

} // namespace stx

#else

namespace stx {

class timer {
public:
    timer() { reset(); }
    timer(const timer& t) { t_ = t.t_; }
    timer& operator =(const timer& t) { t_ = t.t_; return *this; }
    void reset() { t_ = clock(); }
    double elapsed() const
    { return (double) (clock() - t_)/CLOCKS_PER_SEC; }

private:
    clock_t t_;
};

} // namespace stx

#endif

#endif // STX_TIMER_HPP_
