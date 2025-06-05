#pragma once

#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

inline std::vector<std::pair<int64_t, int>> Factorize(int64_t x) {
    std::vector<std::pair<int64_t, int>> p;
    if (x == 1) {
        p.emplace_back(1, 1);
        return p;
    }
    int64_t i = 2;
    while (x > 1 && i <= static_cast<int64_t>(sqrt(static_cast<double>(x)))) {
        int counter = 0;
        while (x % i == 0) {
            x /= i;
            counter++;
        }
        if (counter != 0) {
            p.emplace_back(i, counter);
        }
        if (i == 2) {
            i++;
        } else {
            i += 2;
        }
    }
    if (x != 1) {
        p.emplace_back(x, 1);
    }
    return p;
}
