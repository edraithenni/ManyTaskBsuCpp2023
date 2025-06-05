#pragma once

#include <cstdint>
#include <stdexcept>
#include <vector>

inline std::vector<std::vector<int32_t>> MultiplyMatrices(
    const std::vector<std::vector<int32_t>>& lhs, const std::vector<std::vector<int32_t>>& rhs) {
    std::vector<std::vector<int32_t>> v;
    v.reserve(lhs.size());
    size_t cols = 0;
    for (const auto& r : rhs) {
        if (r.size() > cols) {
            cols = r.size();
        }
    }
    for (const auto& lh : lhs) {
        std::vector<int32_t> v1;
        v1.reserve(cols);
        for (size_t col = 0; col < cols; col++) {
            int64_t res = 0;
            for (size_t inner = 0; inner < lh.size(); inner++) {
                if (inner < rhs.size() && col < rhs[inner].size()) {
                    res += static_cast<int64_t>(lh[inner]) * static_cast<int64_t>(rhs[inner][col]);
                }
            }
            v1.push_back(static_cast<int32_t>(res));
        }
        v.push_back(v1);
    }
    return v;
}
