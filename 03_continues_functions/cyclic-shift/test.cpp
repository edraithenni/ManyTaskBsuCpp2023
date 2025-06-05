#include <catch.hpp>
#include <cyclic_shift.h>
#include <vector>

TEST_CASE("Simple") {
    std::vector<int> array{1, 2, 3, 4, 5, 6};
    CyclicShift(array, 2);
    CHECK(array == std::vector<int>{3, 4, 5, 6, 1, 2});
}
