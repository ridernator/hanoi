#include "Hanoi.h"
#include <iostream>
#include <string>

Hanoi::Hanoi(std::uint64_t numDisks) : numDisks(numDisks),
                                       numSteps(0) {

    // Populate first peg
    for (std::uint64_t disk = numDisks; disk != 0; --disk) {
        a.push_back(disk);
    }
}

Hanoi::~Hanoi() {
}

void Hanoi::solve() {
    print();

    while (!isSovled()) {
        if (numDisks % 2 == 1) {
            // A <--> C
            if (!swap(a, c)) {
                break;
            }

            print();

            // A <--> B
            if (!swap(a, b)) {
                break;
            }

            print();

            // B <--> C
            if (!swap(b, c)) {
                break;
            }

            print();
        } else {
            // A <--> B
            if (!swap(a, b)) {
                break;
            }

            print();

            // A <--> C
            if (!swap(a, c)) {
                break;
            }

            print();

            // B <--> C
            if (!swap(b, c)) {
                break;
            }

            print();
        }
    }

    std::cout << "Took " << numSteps << " steps" << std::endl;
}

bool Hanoi::isSovled() {
    return (a.empty() && b.empty());
}

bool Hanoi::swap(std::deque<std::uint64_t>& first,
                 std::deque<std::uint64_t>& second) {
    if ((first.empty()) && (second.empty())) {
        return false;
    }

    if (isSovled()) {
        return false;
    }

    if (first.empty()) {
        first.push_back(second.back());
        second.pop_back();
    } else if (second.empty()) {
        second.push_back(first.back());
        first.pop_back();
    } else {
        if (first.back() < second.back()) {
            second.push_back(first.back());
            first.pop_back();
        } else {
            first.push_back(second.back());
            second.pop_back();
        }
    }

    ++numSteps;

    return true;
}

void Hanoi::print() {
    // std::cout << "-----------------------------" << std::endl;
    //
    // for (std::uint64_t disk : a) {
    //     std::cout << disk << "-";
    // }
    // std::cout << std::endl;
    //
    // for (std::uint64_t disk : b) {
    //     std::cout << disk << "-";
    // }
    // std::cout << std::endl;
    //
    // for (std::uint64_t disk : c) {
    //     std::cout << disk << "-";
    // }
    // std::cout << std::endl;
}

int main(const int,
         const char** argc) {
    Hanoi hanoi(std::stoi(*(argc + 1)));

    hanoi.solve();
}
