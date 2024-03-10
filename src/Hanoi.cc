#include "Hanoi.h"
#include <iostream>
#include <string>

Hanoi::Hanoi(std::uint64_t numPegs,
             std::uint64_t numDisks) : numPegs(numPegs),
                                       numDisks(numDisks),
                                       numSteps(0) {

    // Create pegs
    for (std::uint64_t index = 0; index < numPegs; ++index) {
        pegs.push_back(new Peg());
    }

    // Populate first peg
    for (std::uint64_t disk = numDisks; disk != 0; --disk) {
        pegs[0]->addDisk(new Disk(disk));
    }
}

Hanoi::~Hanoi() {
    for (auto peg : pegs) {
        delete peg;
    }
}

void Hanoi::solve() {
    while (!isSovled()) {
        // A <--> B
        if (pegs[0]->getTopWidth() < pegs[1]->getTopWidth()) {
            pegs[1]->addDisk(pegs[0]->removeDisk());
        } else {
            pegs[0]->addDisk(pegs[1]->removeDisk());
        }

        // A <--> C
        if (pegs[0]->getTopWidth() < pegs[2]->getTopWidth()) {
            pegs[2]->addDisk(pegs[0]->removeDisk());
        } else {
            pegs[0]->addDisk(pegs[2]->removeDisk());
        }

        // B <--> C
        if (pegs[1]->getTopWidth() < pegs[2]->getTopWidth()) {
            pegs[2]->addDisk(pegs[1]->removeDisk());
        } else {
            pegs[1]->addDisk(pegs[2]->removeDisk());
        }

        numSteps += 3;

        print();
    }

    std::cout << "Took " << numSteps << " steps" << std::endl;
}

bool Hanoi::isSovled() {
    return (pegs[0]->empty() && pegs[1]->empty());
}

void Hanoi::print() {

}

int main(const int,
         const char** argc) {
    Hanoi hanoi(3, std::stoi(*(argc + 1)));

    hanoi.solve();
}
