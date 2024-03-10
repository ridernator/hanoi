#pragma once

#include <cstdint>
#include <vector>

#include "Peg.h"

class Hanoi {
    public:
        Hanoi(std::uint64_t numPegs,
              std::uint64_t numDisks);

        ~Hanoi();

        void solve();

        bool isSovled();

        void print();

    private:
        std::uint64_t numPegs;
        std::uint64_t numDisks;

        std::vector<Peg*> pegs;

        std::uint64_t numSteps;
};

