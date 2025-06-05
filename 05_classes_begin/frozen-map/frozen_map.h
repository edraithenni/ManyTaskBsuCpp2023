#pragma once

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

class FrozenMap {
   public:
    explicit FrozenMap(const std::vector<std::pair<std::string, std::string>>& items)
        : compare_(), v_(items) {
        std::ranges::sort(v_, compare_);
    }

    bool Find(const std::string& key, std::string* value) const {
        std::pair<std::string, std::string> o;
        o.first = key;
        auto s = std::ranges::lower_bound(v_, o, compare_);
        if (s != v_.end() && key == s->first) {
            *value = s->second;
            return true;
        }
        return false;
    }

   private:
    struct {
        bool operator()(
            const std::pair<std::string, std::string>& a,
            const std::pair<std::string, std::string>& b) const {
            return (a.first < b.first);
        }
    } compare_;

    std::vector<std::pair<std::string, std::string>> v_;
};
