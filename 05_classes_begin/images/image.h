#pragma once

#include <cstdint>
#include <matrix.h>
#include <stdexcept>

struct Rgb {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

using Image = Matrix<Rgb>;
using GrayscaleImage = Matrix<uint8_t>;

template <class T>
inline Matrix<T> FlipHorizontally(const Matrix<T>& a) {
    Matrix<T> b(a.Rows(), a.Columns());
    const size_t cols = a.Columns();
    for (size_t i = 0; i < b.Rows(); i++) {
        for (size_t j = 0; j < cols; j++) {
            b(i, j) = a(i, cols - j - 1);
        }
    }
    return b;
}

inline GrayscaleImage ToGray(const Image& a) {
    GrayscaleImage b(a.Rows(), a.Columns());
    for (size_t i = 0; i < a.Rows(); i++) {
        for (size_t j = 0; j < a.Columns(); j++) {
            b(i, j) = static_cast<uint8_t>(
                (static_cast<uint32_t>(a(i, j).r) + static_cast<uint32_t>(a(i, j).g) +
                 static_cast<uint32_t>(a(i, j).b)) /
                3);
        }
    }
    return b;
}

inline Image Blend(const Image& a, const Image& b) {
    Image c = a;
    const size_t cols = a.Columns();
    for (size_t i = 0; i < a.Rows(); i++) {
        for (size_t j = 0; j < a.Columns(); j++) {
            c(i, j).r = static_cast<uint8_t>(
                (((cols - j - 1) * static_cast<size_t>(a(i, j).r)) +
                 (j * static_cast<size_t>(b(i, j).r))) /
                (cols - 1));
            c(i, j).g = static_cast<uint8_t>(
                (((cols - j - 1) * static_cast<size_t>(a(i, j).g)) +
                 (j * static_cast<size_t>(b(i, j).g))) /
                (cols - 1));
            c(i, j).b = static_cast<uint8_t>(
                (((cols - j - 1) * static_cast<size_t>(a(i, j).b)) +
                 (j * static_cast<size_t>(b(i, j).b))) /
                (cols - 1));
        }
    }
    return c;
}

template <class T>
inline Matrix<T> RotateClockwise(const Matrix<T>& a) {
    return FlipHorizontally(Transpose(a));
}

inline uint8_t Check(int a) {
    if (a < 0) {
        return 0;
    }
    if (a > 255) {
        return 255;
    }
    return a;
}

inline Image MixChannels(const Image& image, const Matrix<float>& filter) {
    Image mixed(image.Rows(), image.Columns());
    for (size_t i = 0; i < image.Rows(); i++) {
        for (size_t j = 0; j < image.Columns(); j++) {
            Matrix<float> a(3, 1);
            const Rgb& p = image(i, j);
            a(0, 0) = p.r;
            a(1, 0) = p.g;
            a(2, 0) = p.b;
            auto newrgb = filter * a;
            mixed(i, j).r = Check(static_cast<int>(newrgb(0, 0)));
            mixed(i, j).g = Check(static_cast<int>(newrgb(1, 0)));
            mixed(i, j).b = Check(static_cast<int>(newrgb(2, 0)));
        }
    }
    return mixed;
}

inline Image Convolve(const Image& image, const Matrix<float>& kernel) {
    Image res(image.Rows() - kernel.Rows() + 1, image.Columns() - kernel.Columns() + 1);
    for (size_t i = 0; i < res.Rows(); i++) {
        for (size_t j = 0; j < res.Columns(); j++) {
            float ar = 0;
            float ag = 0;
            float ab = 0;
            for (size_t ki = 0; ki < kernel.Rows(); ki++) {
                for (size_t kj = 0; kj < kernel.Columns(); kj++) {
                    ar += kernel(ki, kj) * static_cast<float>(image(i + ki, j + kj).r);
                    ag += kernel(ki, kj) * static_cast<float>(image(i + ki, j + kj).g);
                    ab += kernel(ki, kj) * static_cast<float>(image(i + ki, j + kj).b);
                }
            }
            res(i, j).r = Check(static_cast<int>(ar));
            res(i, j).g = Check(static_cast<int>(ag));
            res(i, j).b = Check(static_cast<int>(ab));
        }
    }
    return res;
}
