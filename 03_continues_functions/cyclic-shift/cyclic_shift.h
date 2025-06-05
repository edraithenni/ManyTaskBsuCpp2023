#pragma once

#include <stdexcept>
#include <vector>

inline void CyclicShift(std::vector<int>& array, int n) {
    for (int i = 0; i < n; i++) {
        array.push_back(array[i]);
    }
    array.erase(array.begin(), array.begin() + n);
}
