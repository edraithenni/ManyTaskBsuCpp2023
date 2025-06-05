#pragma once

#include <cstdint>

inline int64_t F(int64_t n) {
    auto u = static_cast<uint64_t>(n);
    return static_cast<int64_t>(u ^ (u << 1U));
}
