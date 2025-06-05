#pragma once

#include <cstddef>
#include <vector>

class RingBuffer {
   public:
    explicit RingBuffer(size_t capacity) : q_(capacity) {
    }

    [[nodiscard]] size_t Size() const {
        return ((rear_ > front_ || Empty()) ? 0 : q_.size()) + rear_ - front_;
    }

    [[nodiscard]] bool Full() const {
        return (front_ == rear_ && !empty_);
    }

    [[nodiscard]] bool Empty() const {
        return empty_;
    }

    bool TryPush(int element) {
        if (Full()) {
            return false;
        }
        q_[rear_] = element;
        if (rear_ == q_.size() - 1) {
            rear_ = 0;
        } else {
            rear_++;
        }
        empty_ = false;
        return true;
    }

    bool TryPop(int* element) {
        if (Empty()) {
            return false;
        }
        *element = q_[front_];
        if (front_ == q_.size() - 1) {
            front_ = 0;
        } else {
            front_++;
        }
        empty_ = (rear_ == front_);
        return true;
    }

   private:
    std::vector<int> q_;
    size_t front_{0};
    size_t rear_{0};
    bool empty_{true};
};
