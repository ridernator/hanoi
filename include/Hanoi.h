#pragma once

#include <cstdint>
#include <vector>

class Hanoi {
    public:
        Hanoi(std::uint_fast8_t numDisks);

        void solve();

        bool swap(std::vector<std::uint_fast8_t>* first,
                  std::vector<std::uint_fast8_t>* second);

        void print();
    private:
        std::uint64_t numDisks;

        std::vector<std::uint_fast8_t> a;
        std::vector<std::uint_fast8_t> b;
        std::vector<std::uint_fast8_t> c;

        std::uint64_t numSteps;
};

