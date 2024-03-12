#include "Hanoi.h"

#include <cstdint>
#include <cstdlib>
#include <iostream>

Hanoi::Hanoi(std::uint_fast8_t numDisks) : numDisks(numDisks),
                                           numSteps(0) {
    // Populate first peg
    for (auto disk = numDisks; disk != 0; --disk) {
        a.push(disk);
    }
}

void Hanoi::solve() {
    auto& peg1 = a;
    auto& peg2 = b;
    auto& peg3 = c;

    if (numDisks % 2 == 1) {
        peg2 = c;
        peg3 = b;
    }

    while (!isSovled()) {
        // 1 <--> 2
        if (!swap(peg1, peg2)) {
            break;
        }

        // 1 <--> 3
        if (!swap(peg1, peg3)) {
            break;
        }

        // 2 <--> 3
        if (!swap(peg2, peg3)) {
            break;
        }
    }

    std::cout << "Took " << numSteps << " steps" << std::endl;
}

bool Hanoi::isSovled() {
    return (a.empty() && b.empty());
}

bool Hanoi::swap(std::stack<std::uint_fast8_t, std::vector<std::uint_fast8_t>>& first,
                 std::stack<std::uint_fast8_t, std::vector<std::uint_fast8_t>>& second) {
    if ((first.empty()) && (second.empty())) {
        return false;
    }

    if (isSovled()) {
        return false;
    }

    if (first.empty()) {
        first.push(second.top());
        second.pop();
    } else if (second.empty()) {
        second.push(first.top());
        first.pop();
    } else {
        if (first.top() < second.top()) {
            second.push(first.top());
            first.pop();
        } else {
            first.push(second.top());
            second.pop();
        }
    }

    ++numSteps;

    return true;
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
