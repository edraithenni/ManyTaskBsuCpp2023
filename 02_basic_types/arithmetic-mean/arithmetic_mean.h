#pragma once

#include <cmath>
#include <cstdint>
#include <limits>
#include <numeric>
#include <stdexcept>

inline int64_t ArithmeticMean(int64_t a, int64_t b) {
    return std::midpoint(a, b);
}
