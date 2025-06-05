#include <catch.hpp>
#include <reverse_array.h>
#include <vector>

TEST_CASE("Simple") {
    std::vector<int> array{0, 1, 2, 3};
    ReverseArray(array);
    CHECK(array == std::vector<int>{3, 2, 1, 0});
}
