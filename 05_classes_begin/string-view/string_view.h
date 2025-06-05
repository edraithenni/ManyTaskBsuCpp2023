#pragma once
#include <iterator>
#include <stdexcept>
#include <string>

class StringView {
   public:
    StringView() : begin_(nullptr), size_(0) {
    }

    StringView(const StringView& a) : begin_(a.begin_), size_(a.size_) {
    }

    StringView(const std::string& data) : begin_(&(*data.begin())), size_(data.size()) {
    }

    StringView(const std::string& data, size_t s) : begin_(&(*data.begin())), size_(s) {
    }

    StringView(const char* a) : begin_(a), size_(std::strlen(a)) {
    }

    StringView(const char* a, size_t s) : begin_(a), size_(s) {
    }

    template <std::random_access_iterator Iter>
    StringView(Iter first, Iter last) : begin_(&(*first)), size_(std::distance(first, last)) {
    }

    StringView(std::nullptr_t) = delete;

    StringView& operator=(const StringView& a) {
        begin_ = a.begin_;
        size_ = a.size_;
        return *this;
    }

    const char& operator[](size_t i) const {
        return begin_[i];
    }

    StringView Substr(size_t pos = 0, size_t num = std::string::npos) {
        size_t ns = size_ - pos;
        if (num < ns) {
            ns = num;
        }
        return StringView(begin_ + pos, ns);
    }

    const char* Data() const {
        return begin_;
    }

    size_t Size() const {
        return size_;
    }

    const char& At(size_t i) const {
        if (i >= size_) {
            throw std::out_of_range("out of range");
        }
        return begin_[i];
    }

    bool Empty() const {
        return (size_ == 0);
    }

    const char& Front() const {
        return begin_[0];
    }

    const char& Back() const {
        return begin_[size_ - 1];
    }

   private:
    const char* begin_;
    size_t size_;
};
