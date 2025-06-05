#pragma once

#include <stdexcept>
#include <string>
#include <vector>

inline std::vector<std::string> Split(const std::string& string, const std::string& delimiter) {
    if (string.empty()) {
        return {};
    }
    std::vector<std::string> newstrings;
    size_t pos = 0;
    size_t pos1 = 0;
    const size_t s = delimiter.length();

    while ((pos = string.find(delimiter, pos1)) != std::string::npos) {
        newstrings.push_back(string.substr(pos1, pos - pos1));
        pos1 = pos + s;
    }
    newstrings.push_back(string.substr(pos1));
    return newstrings;
}
