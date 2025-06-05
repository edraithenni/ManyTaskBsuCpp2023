#pragma once

#include <stdexcept>
#include <vector>

inline std::vector<int> Unique(const std::vector<int>& data) {
    std::vector<int> uniquevector;

    for (size_t i = 0; i < data.size(); i++) {
        if (i == 0 || data[i] != data[i - 1]) {
            uniquevector.push_back(data[i]);
        }
    }

    return uniquevector;
}
