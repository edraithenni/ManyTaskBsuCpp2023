#pragma once

#include <stdexcept>

inline void Swap(int* a, int* b) {
    const int c = *a;
    *a = *b;
    *b = c;
}

inline void Sort3(int* a, int* b, int* c) {
    if (*a > *b) {
        Swap(a, b);
    }
    if (*b > *c) {
        Swap(b, c);
    }
    if (*a > *b) {
        Swap(a, b);
    }
}
