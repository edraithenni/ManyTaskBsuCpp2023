#pragma once

#include <stdexcept>
#include <vector>

template <class T>
class Matrix {
   public:
    Matrix() = delete;

    Matrix(size_t n, size_t m, const T& value = T()) : data_(n) {
        if (n == 0 || m == 0) {
            throw std::runtime_error("zero matrix size");
        }
        for (auto& i : data_) {
            i.resize(m);
        }
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                data_[i][j] = value;
            }
        }
    }

    explicit Matrix(size_t n) : data_(n) {
        if (n == 0) {
            throw std::runtime_error("zero matrix size");
        }
        for (auto& i : data_) {
            i.resize(n);
        }
    }

    explicit Matrix(const std::vector<std::vector<T>>& v) : data_(v) {
        if (Rows() == 0 || Columns() == 0) {
            throw std::runtime_error("zero vector size");
        }
        for (size_t i = 1; i < data_.size(); i++) {
            if (data_[i].size() != data_[i - 1].size()) {
                throw std::runtime_error("inconsistent matrix size");
            }
        }
    }

    static Matrix Identity(size_t n) {
        Matrix a(n, n, 0);
        for (size_t i = 0; i < a.Rows(); i++) {
            a(i, i) = 1;
        }
        return a;
    }

    T& operator()(size_t i, size_t j) {
        if (Rows() <= i || Columns() <= j) {
            throw std::runtime_error("no such element");
        }
        return data_[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        if (Rows() <= i || Columns() <= j) {
            throw std::runtime_error("no such element");
        }
        return data_[i][j];
    }

    [[nodiscard]] Matrix Transpose() const {
        const size_t u = Rows();
        const size_t v = Columns();
        Matrix a(v, u);
        for (size_t i = 0; i < u; i++) {
            for (size_t j = 0; j < v; j++) {
                a.data_[j][i] = data_[i][j];
            }
        }
        return a;
    }

    Matrix& operator+=(const Matrix& rhs) {
        if (rhs.Columns() != Columns() || rhs.Rows() != Rows()) {
            throw std::runtime_error("inconsistent matrix sizes");
        }
        for (size_t i = 0; i < Rows(); i++) {
            for (size_t j = 0; j < Columns(); j++) {
                data_[i][j] += rhs.data_[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& rhs) const {
        Matrix a(*this);
        a += rhs;
        return a;
    }

    Matrix& operator-=(const Matrix& rhs) {
        if (rhs.Columns() != Columns() || rhs.Rows() != Rows()) {
            throw std::runtime_error("inconsistent matrix sizes");
        }
        for (size_t i = 0; i < Rows(); i++) {
            for (size_t j = 0; j < Columns(); j++) {
                data_[i][j] -= rhs.data_[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& rhs) const {
        Matrix a(*this);
        a -= rhs;
        return a;
    }

    Matrix operator*(const Matrix& rhs) const {
        if (rhs.Rows() != Columns()) {
            throw std::runtime_error("inconsistent matrix sizes");
        }
        Matrix a(Rows(), rhs.Columns(), 0);
        for (size_t row = 0; row < a.Rows(); row++) {
            for (size_t col = 0; col < rhs.Columns(); col++) {
                for (size_t inner = 0; inner < rhs.Rows(); inner++) {
                    a.data_[row][col] += (data_[row][inner]) * (rhs.data_[inner][col]);
                }
            }
        }
        return a;
    }

    Matrix& operator*=(const Matrix& rhs) {
        *this = (*this) * rhs;
        return *this;
    }

    bool operator==(const Matrix& rhs) const {
        return (data_ == rhs.data_);
    }

    bool operator!=(const Matrix& rhs) const {
        return !(*this == rhs);
    }

    [[nodiscard]] size_t Rows() const {
        return data_.size();
    }

    [[nodiscard]] size_t Columns() const {
        return data_[0].size();
    }

    [[nodiscard]] const std::vector<std::vector<T>>& Data() const {
        return data_;
    }

   private:
    std::vector<std::vector<T>> data_;
};

template <class T>
Matrix<T> Transpose(const Matrix<T>& a) {
    return a.Transpose();
}
