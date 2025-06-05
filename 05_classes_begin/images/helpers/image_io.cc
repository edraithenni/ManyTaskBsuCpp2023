#include <CImg.h>
#include <cassert>
#include <helpers/image_io.h>

using cimg_library::CImg;

namespace {

CImg<uint8_t> ToCImg(const Image& image) {
    const auto height = image.Rows();
    const auto width = image.Columns();
    const auto& matrix = image.Data();
    CImg<uint8_t> img(width, height, 1, 3);
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < height; ++j) {
            img(i, j, 0) = matrix[j][i].r;
            img(i, j, 1) = matrix[j][i].g;
            img(i, j, 2) = matrix[j][i].b;
        }
    }
    return img;
}

CImg<uint8_t> ToCImg(const GrayscaleImage& image) {
    const auto height = image.Rows();
    const auto width = image.Columns();
    const auto& matrix = image.Data();
    CImg<uint8_t> img(width, height, 1, 1);
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < height; ++j) {
            img(i, j) = matrix[j][i];
        }
    }
    return img;
}

}  // anonymous namespace

Image ReadImageFromFile(const std::string& filename) {
    const auto img = CImg<uint8_t>::get_load(filename.c_str());
    const auto width = img.width();
    const auto height = img.height();
    assert(img.depth() == 1);
    assert(img.spectrum() == 3);

    std::vector<std::vector<Rgb>> matrix(height, std::vector<Rgb>(width));
    for (auto i = 0; i < width; ++i) {
        for (auto j = 0; j < height; ++j) {
            const auto r = img(i, j, 0);
            const auto g = img(i, j, 1);
            const auto b = img(i, j, 2);
            matrix[j][i] = Rgb{r, g, b};
        }
    }
    return Image(matrix);
}

template <class Color>
void SaveImageToFile(const Matrix<Color>& image, const std::string& filename) {
    const auto img = ToCImg(image);
    img.save(filename.c_str());
}

template <class Color>
void DrawImage(const Matrix<Color>& image) {
    const auto img = ToCImg(image);
    img.display();
}

template void SaveImageToFile(const Image&, const std::string&);
template void SaveImageToFile(const GrayscaleImage&, const std::string&);
template void DrawImage(const Image&);
template void DrawImage(const GrayscaleImage&);
