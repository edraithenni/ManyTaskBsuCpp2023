#include <catch.hpp>
#include <least_missing_digit.h>

TEST_CASE("Simple") {
    CHECK(LeastMissingDigit(120) == 3);
    CHECK(LeastMissingDigit(0) == 1);
}
