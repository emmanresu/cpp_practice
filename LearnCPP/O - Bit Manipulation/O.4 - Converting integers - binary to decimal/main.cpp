#include <iostream>
#include <bitset>
#include <cstdint>
#include <string>
#include "learncppSolution.hpp"
#include <chrono>

void convert(std::string& binary, std::uint8_t* refs, int numberInput) {
    for (auto i = binary.begin(); i != binary.end(); ++i) {
        if (*i == ' ') {
            continue;
        }
        if (numberInput >= *refs) {
            *i = '1';
            numberInput -= *refs;
        }
        ++refs; 
    }
}

void mySolution() {
    std::uint8_t refs[8] { 128, 64, 32, 16, 8, 4, 2, 1 };
    std::string bits { "0000 0000" };
    
    std::cout << "Enter number from 0 to 255: ";
    int input {};
    std::cin >> input;

    auto start { std::chrono::steady_clock::now() };
    convert(bits, &refs[0], input);
    auto end { std::chrono::steady_clock::now() };
    auto elapsed { std::chrono::duration_cast<std::chrono::nanoseconds>(end - start) };

    std::cout << "Decimal: " << input << '\n'
            << "Binary:  " << bits << '\n';
    std::cout << "time elapsed: " << elapsed.count() << " nanos";
}

int main() {
    mySolution();
     
    // learncppSolution();

    return 0;
}
