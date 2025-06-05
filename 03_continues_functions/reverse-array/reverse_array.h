#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

inline void ReverseArray(std::vector<int>& array) {
    std::reverse(array.begin(), array.end());
}
