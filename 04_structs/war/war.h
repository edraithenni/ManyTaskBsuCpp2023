#pragma once

#include <array>
#include <queue>
#include <stdexcept>

enum class Winner { kFirst, kSecond, kNone };

struct GameResult {
    Winner winner;
    int64_t turn;
};

inline GameResult SimulateWarGame(
    const std::array<int, 6>& first_deck, const std::array<int, 6>& second_deck) {
    GameResult res{};
    std::queue<int> first;
    std::queue<int> second;
    int64_t turns = 0;
    for (auto i : first_deck) {
        first.push(i);
    }
    for (auto j : second_deck) {
        second.push(j);
    }
    while (!first.empty() && !second.empty() && turns != 1'000'000) {
        if ((first.front() == 0 && second.front() == 11) ||
            ((first.front() != 11 || second.front() != 0) && first.front() > second.front())) {
            first.push(first.front());
            first.push(second.front());
        } else {
            second.push(first.front());
            second.push(second.front());
        }
        second.pop();
        first.pop();
        turns++;
    }
    if (first.empty()) {
        res.winner = Winner::kSecond;
        res.turn = turns;
    } else if (second.empty()) {
        res.winner = Winner::kFirst;
        res.turn = turns;
    } else {
        res.winner = Winner::kNone;
    }
    return res;
}
