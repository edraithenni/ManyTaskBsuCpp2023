#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

inline bool IsPermutation(const std::vector<int>& array) {
    std::vector<int> array2;
    for (int i = 1; i <= static_cast<int>(array.size()); i++) {
        array2.push_back(i);
    }
    return std::is_permutation(array2.begin(), array2.end(), array.begin());
}
