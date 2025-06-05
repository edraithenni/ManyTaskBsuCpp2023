#pragma once

#include <cstdint>
#include <optional>

inline std::optional<int64_t> IterationsToConverge(int64_t n) {
    int64_t n1 = n;
    int64_t iter = 0;
    if (n >= 0) {
        while (iter <= 100'000) {
            if (n1 == 1) {
                return iter;
            }
            if (n1 % 2 == 0) {
                n1 /= 2;
            } else {
                n1 = 3 * n1 + 1;
            }
            iter++;
        }
    }

    return std::nullopt;
}
