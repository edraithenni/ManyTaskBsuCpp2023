#pragma once

#include <stdexcept>
#include <string>
#include <vector>

inline std::string LongSum(const std::string& a, const std::string& b) {
    std::string a1 = a;
    std::string b1 = b;

    const size_t size = std::max(a1.length(), b1.length());

    std::reverse(b1.begin(), b1.end());
    std::reverse(a1.begin(), a1.end());

    if (a1.size() > b1.size()) {
        const size_t oldsize = b1.size();
        b1.resize(size);

        for (size_t i = oldsize; i < b1.size(); i++) {
            b1[i] = '0';
        }
    } else if (a1.size() < b1.size()) {
        const size_t oldsize = a1.size();
        a1.resize(size);

        for (size_t i = oldsize; i < a1.size(); i++) {
            a1[i] = '0';
        }
    }

    a1.resize(size + 1);

    char dob = 0;
    for (size_t i = 0; i < b1.size(); i++) {
        a1[i] = static_cast<char>((a1[i] - '0') + (b1[i] - '0') + dob + '0');
        if (a1[i] > '9') {
            a1[i] -= 10;
            dob = 1;
        } else {
            dob = 0;
        }
    }

    if (dob == 1) {
        a1[a1.size() - 1] = '1';
    } else {
        a1.resize(size);
    }

    std::reverse(a1.begin(), a1.end());

    return a1;
}