#pragma once

#include <cctype>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_set>

inline size_t DifferentWordsCount(const std::string& text) {
    std::unordered_set<std::string> words;
    std::string word;

    for (auto c : text) {
        if (std::isalpha(c) != 0) {
            word += c;
        } else if (!word.empty()) {
            std::string upperword;

            for (auto x : word) {
                upperword += static_cast<char>(std::toupper(x));
            }

            words.insert(upperword);
            word.clear();
        }
    }

    if (!word.empty()) {
        std::string upperword;

        for (auto x : word) {
            upperword += static_cast<char>(std::toupper(x));
        }

        words.insert(upperword);
    }

    return words.size();
}
