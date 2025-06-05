#pragma once

#include <stdexcept>
#include <string>
#include <unordered_map>

inline std::unordered_map<int, std::string> ReverseMap(
    const std::unordered_map<std::string, int>& map) {
    std::unordered_map<int, std::string> map1;

    for (const auto& x : map) {
        map1[x.second] = x.first;
    }

    return map1;
}
