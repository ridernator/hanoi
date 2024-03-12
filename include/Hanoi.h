#pragma once

#include <cstdint>
#include <vector>
#include <stack>

class Hanoi {
    public:
        Hanoi(std::uint_fast8_t numDisks);

        void solve();

        bool isSovled();

        void print();

        bool swap(std::stack<std::uint_fast8_t, std::vector<std::uint_fast8_t>>& first,
                  std::stack<std::uint_fast8_t, std::vector<std::uint_fast8_t>>& second);

    private:
        std::uint64_t numDisks;

        std::stack<std::uint_fast8_t, std::vector<std::uint_fast8_t>> a;
        std::stack<std::uint_fast8_t, std::vector<std::uint_fast8_t>> b;
        std::stack<std::uint_fast8_t, std::vector<std::uint_fast8_t>> c;

        std::uint64_t numSteps;
};

