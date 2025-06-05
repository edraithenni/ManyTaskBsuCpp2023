#pragma once

#include <cstdint>
#include <stdexcept>

inline int32_t BinPow(int32_t a, int64_t b, int32_t c) {
    if (b == 0) {
        return 1 % c;
    }

    int64_t a2 = 1;
    int64_t aa = a;
    int64_t bb = b;
    const int64_t cc = c;

    while (bb != 0) {
        if (bb % 2 == 0) {
            bb /= 2;
            aa *= aa;
            aa %= cc;
        } else {
            bb--;
            a2 *= aa;
            a2 %= cc;
        }
    }

    return static_cast<int32_t>(a2);
}
