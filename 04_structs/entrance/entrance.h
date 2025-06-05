#pragma once

#include <map>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

struct StudentName {
    std::string name, surname;
};

struct Date {
    int year{}, month{}, day{};
};

struct Abiturient {
    StudentName fio;
    Date born;
    int points{};
    std::vector<std::string> prefs;
};

const struct {
    bool operator()(const Abiturient& a, const Abiturient& b) const {
        return (a.points > b.points) ||
               ((a.points == b.points) &&
                ((a.born.year < b.born.year) ||
                 ((a.born.year == b.born.year) &&
                  ((a.born.month < b.born.month) ||
                   ((a.born.month == b.born.month) &&
                    ((a.born.day < b.born.day) ||
                     ((a.born.day == b.born.day) &&
                      ((a.fio.surname < b.fio.surname) ||
                       ((a.fio.surname == b.fio.surname) && (a.fio.name < b.fio.name))))))))));
    }
} kCompareStudents;

const struct {
    bool operator()(const StudentName& a, const StudentName& b) const {
        return (a.surname < b.surname) || (a.surname == b.surname && a.name < b.name);
    }
} kCompareStudents2;

inline std::map<std::string, std::vector<StudentName>> GetStudents(
    const std::vector<std::pair<std::string, int>>& universities_info,
    const std::vector<std::tuple<StudentName, Date, int, std::vector<std::string>>>&
        students_info) {
    std::vector<Abiturient> studs;
    for (auto i : students_info) {
        Abiturient a;
        a.fio = std::get<0>(i);
        a.born = std::get<1>(i);
        a.points = std::get<2>(i);
        a.prefs = std::get<3>(i);
        studs.push_back(a);
    }

    std::ranges::sort(studs, kCompareStudents);

    std::map<std::string, std::vector<StudentName>> places_taken;
    for (const auto& l : universities_info) {
        places_taken[l.first] = {};
    }

    for (const auto& i : studs) {
        for (const auto& k : i.prefs) {
            bool pushed = false;
            for (const auto& j : universities_info) {
                if (k == j.first && places_taken[j.first].size() < static_cast<size_t>(j.second)) {
                    places_taken[j.first].push_back(i.fio);
                    pushed = true;
                    break;
                }
            }
            if (pushed) {
                break;
            }
        }
    }
    for (auto& i : places_taken) {
        std::ranges::sort(i.second, kCompareStudents2);
    }
    return places_taken;
}
