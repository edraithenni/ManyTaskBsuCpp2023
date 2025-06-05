#pragma once

#include <image.h>
#include <string>

Image ReadImageFromFile(const std::string& filename);

template <class Color>
void SaveImageToFile(const Matrix<Color>& image, const std::string& filename);

template <class Color>
void DrawImage(const Matrix<Color>& image);
