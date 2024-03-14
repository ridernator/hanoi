#include "Hanoi.h"

#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#define PRINT

Hanoi::Hanoi(std::uint_fast8_t numDisks) : numDisks(numDisks),
                                           aTop(numDisks - 1),
                                           bTop(-1),
                                           cTop(-1),
                                           numSteps(0) {
    // Populate first peg
    ssize_t index = -1;
    for (auto disk = numDisks; disk != 0; --disk) {
        *(a + ++index) = disk;
    }
}

void Hanoi::solve() {
    auto* peg1 = a;
    auto* peg2 = b;
    auto* peg3 = c;
    auto* peg1Top = &aTop;
    auto* peg2Top = &bTop;
    auto* peg3Top = &cTop;

    if (numDisks % 2 != 0) {
        peg2 = c;
        peg3 = b;

        peg2Top = &cTop;
        peg3Top = &bTop;
    }

    print();

    while (true) {
        // 1 <--> 2
        if (!swap(peg1, peg2, *peg1Top, *peg2Top)) {
            break;
        }

        print();

        // 1 <--> 3
        if (!swap(peg1, peg3, *peg1Top, *peg3Top)) {
            break;
        }

        print();

        // 2 <--> 3
        if (!swap(peg2, peg3, *peg2Top, *peg3Top)) {
            break;
        }

        print();
    }

    std::cout << "Took " << numSteps << " steps" << std::endl;
}

bool Hanoi::swap(std::uint_fast8_t* first,
                 std::uint_fast8_t* second,
                 ssize_t& firstTop,
                 ssize_t& secondTop) {
    if ((firstTop == -1) && (secondTop == -1)) {
        return false;
    }

    if (firstTop == -1) {
        *(first + ++firstTop) = *(second + secondTop--);
    } else if (secondTop == -1) {
        *(second + ++secondTop) = *(first + firstTop--);
    } else {
        if (*(first + firstTop) < *(second + secondTop)) {
            *(second + ++secondTop) = *(first + firstTop--);
        } else {
            *(first + ++firstTop) = *(second + secondTop--);
        }
    }

    ++numSteps;

    return true;
}

void Hanoi::print() {
#ifdef PRINT
    std::cout << "--------------------" << std::endl;

    for (ssize_t index = numDisks; index >= 0; --index) {
        if (index > aTop) {
            std::cout << "     ";
        } else {
            std::cout << std::setfill(' ') << std::setw(5) << (int) *(a + index);
        }

        if (index > bTop) {
            std::cout << "     ";
        } else {
            std::cout << std::setfill(' ') << std::setw(5) << (int) *(b + index);
        }

        if (index > cTop) {
            std::cout << "     ";
        } else {
            std::cout << std::setfill(' ') << std::setw(5) << (int) *(c + index);
        }

        std::cout << std::endl;
    }
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
