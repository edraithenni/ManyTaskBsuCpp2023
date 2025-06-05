#pragma once

#include <stdexcept>

inline bool IsValidCreditCardNumber(int64_t n) {
    int64_t sum = 0;
    bool r = true;

    for (int64_t i = n, j = 0; j < 16; i /= 10, j++) {
        const int64_t raz = i % 10;
        if (r) {
            sum += raz;
            r = false;
        } else {
            const int64_t raz2 = raz * 2;
            if (raz2 > 9) {
                sum += raz2 - 9;
            } else {
                sum += raz2;
            }
            r = true;
        }
    }

    return (sum % 10 == 0);
}
