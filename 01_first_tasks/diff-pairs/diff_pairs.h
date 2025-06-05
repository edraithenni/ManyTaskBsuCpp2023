#pragma once

#include <map>
#include <stdexcept>
#include <vector>

inline size_t CountPairs(const std::vector<int>& data, int x) {
    std::map<int64_t, size_t> m;
    size_t counter = 0;

    for (auto e : data) {
        auto it = m.find(static_cast<int64_t>(x) - static_cast<int64_t>(e));
        if (it != m.end()) {
            counter += it->second;
        }

        it = m.find(static_cast<int64_t>(e));
        if (it != m.end()) {
            ++(it->second);
        } else {
            m[static_cast<int64_t>(e)] = 1;
        }
    }

    return counter;
}
