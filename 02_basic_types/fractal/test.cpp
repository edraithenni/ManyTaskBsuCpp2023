#include <catch.hpp>
#include <fractal.h>

TEST_CASE("Compare") {
    for (int i = 1; i < 50; ++i) {
        INFO("i == " << i);
        REQUIRE(GenerateAsFunction(i) == GenerateAsSequence(i));
    }
}
