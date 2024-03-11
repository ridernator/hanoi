#pragma once

#include <cstdint>
#include <deque>

class Hanoi {
    public:
        Hanoi(std::uint64_t numDisks);

        ~Hanoi();

        void solve();

        bool isSovled();

        void print();

        bool swap(std::deque<std::uint64_t>& first,
                  std::deque<std::uint64_t>& second);

    private:
        std::uint64_t numDisks;

        std::deque<std::uint64_t> a;
        std::deque<std::uint64_t> b;
        std::deque<std::uint64_t> c;

        std::uint64_t numSteps;
};

