#include "Peg.h"
#include <cstdint>

Peg::Peg() {

}

Peg::~Peg() {
    for (auto disk : disks) {
        delete disk;
    }
}

void Peg::addDisk(Disk* disk) {
    disks.push_back(disk);
}

std::uint64_t Peg::getTopWidth() {
    std::uint64_t returnVal = 99999;

    if (!disks.empty()) {
        returnVal = disks.back()->getWidth();
    }

    return returnVal;
}

Disk* Peg::removeDisk() {
    Disk* returnVal = disks.back();

    disks.pop_back();

    return returnVal;
}

bool Peg::empty() {
    return disks.empty();
}
