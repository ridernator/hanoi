#pragma once

#include <cstdint>
#include <deque>

#include "Disk.h"

class Peg {
    public:
        Peg();
        ~Peg();

        void addDisk(Disk* disk);
        Disk* removeDisk();

        std::uint64_t getTopWidth();

        bool empty();

    private:
        std::deque<Disk*> disks;
};
