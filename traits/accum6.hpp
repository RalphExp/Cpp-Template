#ifndef ACCUM6_HPP_
#define ACCUM6_HPP_

#include "accumtraits4.hpp"
#include "sumpolicy1.hpp"

template<typename T, typename Policy = SumPolicy, typename Traits = AccumulationTraits<T>>
auto accum (T const* beg, T const* end) {
    using AccT = typename Traits::AccT;
    AccT total = Traits::zero();

    while (beg != end) {
        Policy::accumulate(total, *beg);
        ++beg;
    }
    return total;
}

#endif
