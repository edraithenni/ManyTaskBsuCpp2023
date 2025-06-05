#pragma once

#include <stdexcept>
#include <vector>

inline bool GetNextLexicographicOrder(std::vector<int>& currperm) {
    const size_t len = currperm.size();
    size_t i = len - 1;
    while (i > 0 && currperm[i - 1] >= currperm[i]) {
        i--;
    }

    if (i == 0) {
        return false;
    }
    size_t j = len;
    while (j > i && currperm[j - 1] <= currperm[i - 1]) {
        j--;
    }
    std::swap(currperm[i - 1], currperm[j - 1]);
    i++;
    j = len;
    while (i < j) {
        std::swap(currperm[i - 1], currperm[j - 1]);
        i++;
        j--;
    }

    return true;
}

inline std::vector<std::vector<int>> GeneratePermutations(size_t len) {
    std::vector<std::vector<int>> perms;
    std::vector<int> set;
    for (size_t i = 0; i < len; i++) {
        set.push_back(static_cast<int>(i));
    }
    perms.push_back(set);
    while (GetNextLexicographicOrder(set)) {
        perms.push_back(set);
    }

    return perms;
}
