#pragma once

#include <stdexcept>

inline int LeastMissingDigit(int n) {
    const std::string s = std::to_string(n);
    std::vector<int> v;
    for (auto i : s) {
        v.push_back(i - '0');
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    const size_t si = v.size();
    if (v[0] != 0) {
        return 0;
    }
    if (v[0] == 0 && v.size() == 1) {
        return 1;
    }
    for (int i = 1; i < static_cast<int>(si); i++) {
        if (v[i] - 1 != v[i - 1]) {
            return v[i - 1] + 1;
        }
    }
    return v[si - 1] + 1;
}
