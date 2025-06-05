#pragma once

#include <stdexcept>
#include <vector>

inline void FilterArray(std::vector<int>& array) {
    array.erase(std::remove(array.begin(), array.end(), 0), array.end());
}
