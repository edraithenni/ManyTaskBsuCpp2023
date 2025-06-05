#pragma once

#include <format>
#include <image.h>
#include <ostream>
#include <tuple>

const Rgb kBlack{0, 0, 0};
const Rgb kGray{128, 128, 128};
const Rgb kLightgray{85, 85, 85};
const Rgb kWhite{255, 255, 255};
const Rgb kRed{255, 0, 0};
const Rgb kGreen{0, 255, 0};
const Rgb kBlue{0, 0, 255};
const Rgb kYellow{255, 255, 0};
const Rgb kCyan{0, 255, 255};
const Rgb kPurple{255, 0, 255};

inline bool operator==(const Rgb& lhs, const Rgb& rhs) {
    return std::tuple(lhs.r, lhs.g, lhs.b) == std::tuple(rhs.r, rhs.g, rhs.b);
}

inline std::ostream& operator<<(std::ostream& os, const Rgb& color) {
    os << std::format("#{:02x}{:02x}{:02x}", color.r, color.g, color.b);
    return os;
}
