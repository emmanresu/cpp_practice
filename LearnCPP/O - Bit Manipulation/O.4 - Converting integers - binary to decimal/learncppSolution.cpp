#ifndef LEARNCPPSOLUTION_CPP
#define LEARNCPPSOLUTION_CPP

#include <iostream>
#include "learncppSolution.hpp"

void printBit(int x, int pow)
{
    std::cout << ((x / pow) % 2);
}

void print8BitBinary(int x)
{
    printBit(x, 128);
    printBit(x, 64);
    printBit(x, 32);
    printBit(x, 16);

    std::cout << ' ';

    printBit(x, 8);
    printBit(x, 4);
    printBit(x, 2);
    printBit(x, 1);
}

void learncppSolution() {
    std::cout << "Enter an integer between 0 and 255: ";
    int x{};
    std::cin >> x;

    print8BitBinary(x);

    std::cout << '\n';

}

#endif
