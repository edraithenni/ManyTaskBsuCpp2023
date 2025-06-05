#include <catch.hpp>
#include <sort_students.h>
#include <vector>

TEST_CASE("Your test") {
    std::vector<Student> data;
    SortStudents(&data, SortType::kByDate);
}
