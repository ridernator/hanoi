#include "Hanoi.h"

#include <cstdint>
#include <cstdlib>
#include <iostream>

// #define PRINT

Hanoi::Hanoi(std::uint_fast8_t numDisks) : numDisks(numDisks),
                                           numSteps(0) {
    // Populate first peg
    for (auto disk = numDisks; disk != 0; --disk) {
        a.push_back(disk);
    }
}

void Hanoi::solve() {
    auto* peg1 = &a;
    auto* peg2 = &b;
    auto* peg3 = &c;

    if (numDisks % 2 != 0) {
        peg2 = &c;
        peg3 = &b;
    }

    print();

    while (true) {
        // 1 <--> 2
        if (!swap(peg1, peg2)) {
            break;
        }

        print();

        // 1 <--> 3
        if (!swap(peg1, peg3)) {
            break;
        }

        print();

        // 2 <--> 3
        if (!swap(peg2, peg3)) {
            break;
        }

        print();
    }

    std::cout << "Took " << numSteps << " steps" << std::endl;
}

bool Hanoi::swap(std::vector<std::uint_fast8_t>* first,
                 std::vector<std::uint_fast8_t>* second) {
    if ((first->empty()) && (second->empty())) {
        return false;
    }

    if (first->empty()) {
        first->push_back(second->back());
        second->pop_back();
    } else if (second->empty()) {
        second->push_back(first->back());
        first->pop_back();
    } else {
        if (first->back() < second->back()) {
            second->push_back(first->back());
            first->pop_back();
        } else {
            first->push_back(second->back());
            second->pop_back();
        }
    }

    ++numSteps;

    return true;
}

void Hanoi::print() {
#ifdef PRINT
    std::cout << "--------------------" << std::endl;

    for (const auto& disk : a) {
        std::cout << (int) disk << "|";
    }
    std::cout << std::endl;

    for (const auto& disk : b) {
        std::cout << (int) disk << "|";
    }
    std::cout << std::endl;

    for (const auto& disk : c) {
        std::cout << (int) disk << "|";
    }
    std::cout << std::endl;

#endif
}

int main(const int    argc,
         const char** argv) {
    if (argc != 2) {
        std::cerr << "Usage hanoi <numberOfDisks>" << std::endl;

        std::exit(EXIT_FAILURE);
    }

    Hanoi hanoi(std::stoi(*(argv + 1)));

    hanoi.solve();
}
