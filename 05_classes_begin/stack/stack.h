#pragma once

#include <cstddef>
#include <vector>

class Stack {
   public:
    void Push(int x) {
        sta_.push_back(x);
    }

    bool Pop() {
        if (sta_.empty()) {
            return false;
        }
        sta_.pop_back();
        return true;
    }

    [[nodiscard]] int Top() const {
        return sta_.back();
    }

    [[nodiscard]] bool Empty() const {
        return sta_.empty();
    }

    [[nodiscard]] size_t Size() const {
        return sta_.size();
    }

   private:
    std::vector<int> sta_;
};
