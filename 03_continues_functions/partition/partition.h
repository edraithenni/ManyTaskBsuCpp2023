#pragma once

#include <stdexcept>
#include <vector>

inline void PartitionBySign(std::vector<int>& array) {
    const int n = static_cast<int>(array.size()) - 1;
    for (int i = 0; i <= n; i++) {
        if (array[i] < 0) {
            array.push_back(array[i]);
        }
    }
    for (int i = 0; i <= n; i++) {
        if (array[i] == 0) {
            array.push_back(array[i]);
        }
    }
    for (int i = 0; i <= n; i++) {
        if (array[i] > 0) {
            array.push_back(array[i]);
        }
    }
    array.erase(array.begin(), array.end() - n - 1);
}
