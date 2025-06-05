#include <catch.hpp>
#include <point_triangle.h>

TEST_CASE("Your test") {
    IsPointInTriangle(Triangle{Point{0, 0}, Point{0, 0}, Point{0, 0}}, Point{0, 0});
}
