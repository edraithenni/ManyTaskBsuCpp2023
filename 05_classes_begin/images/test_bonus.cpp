#include <catch.hpp>
#include <image.h>
#include <matrix.h>
#include <test_utils.h>
#include <vector>

using RgbVector = std::vector<std::vector<Rgb>>;
using FloatVector = std::vector<std::vector<float>>;

TEST_CASE("Convolve") {
    const Image image({
      {kRed, kGreen, kRed, kGreen},
      {kGreen, kBlue, kBlue, kGreen},
      {kBlack, kWhite, kBlack, kWhite},
      {kWhite, kRed, kRed, kWhite},
    });

    CHECK(
        Convolve(image, Matrix<float>({{0, 0}, {0, 1}})).Data() ==
        RgbVector{
          {kBlue, kBlue, kGreen},
          {kWhite, kBlack, kWhite},
          {kRed, kRed, kWhite},
        });
    CHECK(
        Convolve(image, Matrix<float>(FloatVector{{1}, {1}})).Data() ==
        RgbVector{
          {kYellow, kCyan, kPurple, kGreen},
          {kGreen, kWhite, kBlue, kWhite},
          {kWhite, kWhite, kRed, kWhite},
        });
    CHECK(
        Convolve(image, Matrix<float>(FloatVector{{1}, {-1}})).Data() ==
        RgbVector{
          {kRed, kGreen, kRed, kBlack},
          {kGreen, kBlack, kBlue, kBlack},
          {kBlack, kCyan, kBlack, kBlack},
        });
    CHECK(
        Convolve(image, Matrix<float>({{0.2, 0.4}, {0, 0.6}})).Data() ==
        RgbVector{
          {Rgb{51, 102, 153}, Rgb{102, 51, 153}, Rgb{51, 255, 0}},
          {Rgb{153, 204, 255}, Rgb{0, 0, 153}, Rgb{153, 255, 204}},
          {Rgb{255, 102, 102}, Rgb{204, 51, 51}, kWhite},
        });
    CHECK(
        Convolve(
            image, Matrix<float>({
                     {0.4, 0, -50, 0},
                     {0, 0, -1. / 255, -0.8},
                     {0, 1, -20, 0},
                     {0, 50, -0.8, 0},
                   }))
            .Data() == RgbVector{{Rgb{153, 51, 254}}});
}
