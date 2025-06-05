#pragma once

#include <stdexcept>

inline std::vector<int> Range(int from, int to, int step) {
    std::vector<int> vect;
    const bool less = (from < to);

    if ((less && step > 0) || (from > to && step < 0)) {
        int64_t from1 = from;
        const int64_t to1 = to;
        for (; less ? (from1 < to1) : (from1 > to1); from1 += step) {
            vect.push_back(static_cast<int>(from1));
        }
    }

    return vect;
}
