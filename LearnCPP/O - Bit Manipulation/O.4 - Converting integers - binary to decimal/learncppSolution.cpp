#ifndef LEARNCPPSOLUTION_CPP
#define LEARNCPPSOLUTION_CPP

#include <chrono>
#include <iostream>
#include <vector>
#include "learncppSolution.hpp"

static std::vector<long long> elapsedVector {}; 

void printBit(int x, int pow)
{
    auto start { std::chrono::steady_clock::now() };

    int res { (x / pow) % 2 };

    auto end { std::chrono::steady_clock::now() };
    auto elapsed { std::chrono::duration_cast<std::chrono::nanoseconds>(end - start) };
    elapsedVector.emplace_back(elapsed.count());
    
    std::cout << res;
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

    // auto start { std::chrono::steady_clock::now() };
    std::cout << "binary equivalent: ";
    print8BitBinary(x);
    // auto end { std::chrono::steady_clock::now() };
    // auto elapsed { std::chrono::duration_cast<std::chrono::nanoseconds>(end - start) };

    std::cout << "\n\nTime Elapsed:\n";
    for (auto e : elapsedVector) {
        std::cout << e << " nanos\n";
    }
    // std::cout << "\ntime elapsed: " << elapsed.count() << " nanos";

    std::cout << '\n';

}


#endif
