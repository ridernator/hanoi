#include "Disk.h"

Disk::Disk(std::uint64_t width) : width(width) {

}

std::uint64_t Disk::getWidth() {
    return width;
}
