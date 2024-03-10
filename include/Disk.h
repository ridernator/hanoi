#pragma once

#include <cstdint>

class Disk {
    public:
        Disk(std::uint64_t width);

        std::uint64_t getWidth();

    private:
        std::uint64_t width;
};
