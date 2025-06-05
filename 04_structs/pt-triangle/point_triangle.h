#pragma once

#include <stdexcept>

struct Point {
    int x, y;
};

struct Triangle {
    Point a, b, c;
};

inline bool IsPointInTriangle(const Triangle& t, const Point& pt) {
    const int64_t a1 =
        (static_cast<int64_t>(t.a.x) - static_cast<int64_t>(pt.x)) *
            (static_cast<int64_t>(t.b.y) - static_cast<int64_t>(t.a.y)) -
        (static_cast<int64_t>(t.b.x) - static_cast<int64_t>(t.a.x)) *
            (static_cast<int64_t>(t.a.y) - static_cast<int64_t>(pt.y));
    const int64_t b1 =
        (static_cast<int64_t>(t.b.x) - static_cast<int64_t>(pt.x)) *
            (static_cast<int64_t>(t.c.y) - static_cast<int64_t>(t.b.y)) -
        (static_cast<int64_t>(t.c.x) - static_cast<int64_t>(t.b.x)) *
            (static_cast<int64_t>(t.b.y) - static_cast<int64_t>(pt.y));
    const int64_t c1 =
        (static_cast<int64_t>(t.c.x) - static_cast<int64_t>(pt.x)) *
            (static_cast<int64_t>(t.a.y) - static_cast<int64_t>(t.c.y)) -
        (static_cast<int64_t>(t.a.x) - static_cast<int64_t>(t.c.x)) *
            (static_cast<int64_t>(t.c.y) - static_cast<int64_t>(pt.y));
    return ((a1 >= 0 && b1 >= 0 && c1 >= 0) || (a1 <= 0 && b1 <= 0 && c1 <= 0));
}
