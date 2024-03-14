#pragma once

#include <cstdint>
#include <sys/types.h>

class Hanoi {
    public:
        Hanoi(std::uint_fast8_t numDisks);

        void solve();

        bool swap(std::uint_fast8_t* first,
                  std::uint_fast8_t* second,
                  ssize_t& firstTop,
                  ssize_t& secondTop);

        void print();
    private:
        std::uint64_t numDisks;

        std::uint_fast8_t a[100];
        std::uint_fast8_t b[100];
        std::uint_fast8_t c[100];

        ssize_t aTop;
        ssize_t bTop;
        ssize_t cTop;

        std::uint64_t numSteps;
};

