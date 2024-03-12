#pragma once

#include <cstdint>
#include <vector>
#include <stack>

class Hanoi {
    public:
        Hanoi(std::uint64_t numDisks);

        ~Hanoi();

        void solve();

        bool isSovled();

        void print();

        bool swap(std::stack<std::uint64_t, std::vector<std::uint64_t>>& first,
                  std::stack<std::uint64_t, std::vector<std::uint64_t>>& second);

    private:
        std::uint64_t numDisks;

        std::stack<std::uint64_t, std::vector<std::uint64_t>> a;
        std::stack<std::uint64_t, std::vector<std::uint64_t>> b;
        std::stack<std::uint64_t, std::vector<std::uint64_t>> c;

        std::uint64_t numSteps;
};

