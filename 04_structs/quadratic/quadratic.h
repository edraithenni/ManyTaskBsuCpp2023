#pragma once

#include <algorithm>
#include <stdexcept>

enum class RootCount { kZero, kOne, kTwo, kInf };

struct Roots {
    RootCount count;
    double first;
    double second;
};

inline Roots SolveQuadratic(int a, int b, int c) {
    Roots x{};
    const int64_t disc = b * b - 4 * a * c;
    if (a == 0 && b != 0) {
        x.count = RootCount::kOne;
        x.first = static_cast<double>(-c) / static_cast<double>(b);
    } else if (a == 0 && b == 0 && c == 0) {
        x.count = RootCount::kInf;
    } else if ((a == 0 && b == 0 && c != 0) || (disc < 0)) {
        x.count = RootCount::kZero;
    } else if (disc == 0) {
        x.count = RootCount::kOne;
        x.first = static_cast<double>(-b) / static_cast<double>(2 * a);
    } else {
        x.count = RootCount::kTwo;
        const double x1 = (-b + sqrt(static_cast<double>(disc))) / (2 * a);
        const double x2 = (-b - sqrt(static_cast<double>(disc))) / (2 * a);
        x.first = std::min(x1, x2);
        x.second = std::max(x1, x2);
    }
    return x;
}
