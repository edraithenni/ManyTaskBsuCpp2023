#include <cstddef>
#include <exception>
#include <helpers/image_io.h>
#include <image.h>
#include <iostream>
#include <matrix.h>
#include <vector>

Matrix<float> CreateGaussianKernel(size_t size) {
    std::vector<float> binoms;
    float current = 1.F / static_cast<float>(1U << (size - 1));
    binoms.push_back(current);
    for (size_t i = 1; i <= size; ++i) {
        current *= static_cast<float>(size - i);
        current /= static_cast<float>(i);
        binoms.push_back(current);
    }

    Matrix<float> result(size, size);
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            result(i, j) = binoms[i] * binoms[j];
        }
    }
    return result;
}

int main() {
    try {
        const auto image1 = ReadImageFromFile("../05_classes_begin/images/static/einstein.png");
        const auto image2 = ReadImageFromFile("../05_classes_begin/images/static/tomate.png");
        // DrawImage(image1);
        // DrawImage(image2);
        DrawImage(RotateClockwise(ToGray(image1)));
        DrawImage(FlipHorizontally(image2));
        DrawImage(Blend(image1, image2));
        DrawImage(MixChannels(image2, Matrix<float>({{0, 1, 0}, {0, 0, 1}, {1, 0, 0}})));
        DrawImage(MixChannels(image1, Matrix<float>({{1, -0.2, 0.2}, {0, 1, 0}, {0.1, 0.2, 0.9}})));

        // sharpen
        DrawImage(Convolve(image1, Matrix<float>({{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}})));

        const auto kernel = CreateGaussianKernel(5);
        auto blurred = image1;
        for (int i = 0; i < 3; ++i) {
            blurred = Convolve(blurred, kernel);
        }
        DrawImage(blurred);
        SaveImageToFile(blurred, "blurred.png");
    } catch (std::exception& ex) {
        std::cout << ex.what() << '\n';
        return 1;
    }
    return 0;
}
