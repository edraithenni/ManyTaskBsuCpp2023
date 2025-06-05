#include <catch.hpp>
#include <cstdint>
#include <image.h>
#include <matrix.h>
#include <test_utils.h>
#include <vector>

using RgbVector = std::vector<std::vector<Rgb>>;

TEST_CASE("FlipHorizontally") {
    const Image a({{kBlack, kWhite}, {kRed, kGreen}});
    CHECK(FlipHorizontally(a).Data() == RgbVector{{kWhite, kBlack}, {kGreen, kRed}});
}

TEST_CASE("ToGray") {
    const Image a({{{0, 255, 129}, {0, 0, 2}, {255, 255, 255}, {127, 128, 129}}});
    CHECK(ToGray(a).Data() == std::vector<std::vector<uint8_t>>{{128, 0, 255, 128}});
}

TEST_CASE("Blend") {
    const Image a({
      {kBlack, kBlack, kBlack},
      {kRed, kRed, kRed},
      {kWhite, kWhite, kWhite},
      {kGray, kGray, kGray},
    });
    const Image b({
      {kWhite, kYellow, kWhite},
      {kWhite, kYellow, kRed},
      {kWhite, kYellow, kWhite},
      {kWhite, kYellow, kBlack},
    });
    CHECK(
        Blend(a, b).Data() ==
        RgbVector{
          {kBlack, Rgb{127, 127, 0}, kWhite},
          {kRed, Rgb{255, 127, 0}, kRed},
          {kWhite, Rgb{255, 255, 127}, kWhite},
          {kGray, Rgb{191, 191, 64}, kBlack}});
}

TEST_CASE("Rotate") {
    const Image a({{kBlack, kWhite}, {kRed, kGreen}, {kBlue, kYellow}});
    CHECK(RotateClockwise(a).Data() == RgbVector{{kBlue, kRed, kBlack}, {kYellow, kGreen, kWhite}});
}

TEST_CASE("MixChannels") {
    const Image a({{kWhite, kGray, kBlack, kRed, kGreen, kBlue, kYellow}});

    const Matrix<float> to_gray(
        {{1. / 3, 1. / 3, 1. / 3}, {1. / 3, 1. / 3, 1. / 3}, {1. / 3, 1. / 3, 1. / 3}});
    CHECK(
        MixChannels(a, to_gray).Data() ==
        RgbVector{{kWhite, kGray, kBlack, kLightgray, kLightgray, kLightgray, Rgb{170, 170, 170}}});

    const Matrix<float> swap_channels({{0, 1, 0}, {0, 0, 1}, {1, 0, 0}});
    CHECK(
        MixChannels(a, swap_channels).Data() ==
        RgbVector{{kWhite, kGray, kBlack, kBlue, kRed, kGreen, Rgb{255, 0, 255}}});

    const Matrix<float> darken({{0.5, 0, 0}, {0, 0.5, 0}, {0, 0, 0.5}});
    CHECK(
        MixChannels(a, darken).Data() ==
        RgbVector{
          {Rgb{127, 127, 127}, Rgb{64, 64, 64}, kBlack, Rgb{127, 0, 0}, Rgb{0, 127, 0},
           Rgb{0, 0, 127}, Rgb{127, 127, 0}}});
}
