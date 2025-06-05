#pragma once

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

struct Student {
    std::string name, surname;
    int year{}, month{}, day{};
};

enum class SortType { kByName, kByDate };

inline void SortStudents(std::vector<Student>* students, SortType sort_type) {
    const struct {
        bool operator()(const Student& a, const Student& b) const {
            return (
                a.surname < b.surname || (a.surname == b.surname && a.name < b.name) ||
                ((a.surname == b.surname && a.name == b.name && a.year < b.year) ||
                 (a.surname == b.surname && a.name == b.name && a.year == b.year &&
                  a.month < b.month) ||
                 (a.surname == b.surname && a.name == b.name && a.year == b.year &&
                  a.month == b.month && a.day < b.day)));
        }
    } compare_by_name;

    const struct {
        bool operator()(const Student& a, const Student& b) const {
            return (
                a.year < b.year || (a.year == b.year && a.month < b.month) ||
                (a.year == b.year && a.month == b.month && a.day < b.day) ||
                ((a.year == b.year && a.month == b.month && a.day == b.day) &&
                 (a.surname < b.surname || (a.surname == b.surname && a.name < b.name))));
        }
    } compare_by_date;

    if (sort_type == SortType::kByName) {
        std::ranges::sort(*students, compare_by_name);
    } else {
        std::ranges::sort(*students, compare_by_date);
    }
}
