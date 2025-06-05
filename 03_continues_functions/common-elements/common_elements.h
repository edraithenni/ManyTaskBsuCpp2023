#pragma once

#include <stdexcept>
#include <vector>

inline int NumberOfCommonElements(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < static_cast<int>(lhs.size()) && j < static_cast<int>(rhs.size())) {
        if (lhs[i] == rhs[j]) {
            res++;
            i++;
            j++;
        } else if (lhs[i] < rhs[j]) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}
