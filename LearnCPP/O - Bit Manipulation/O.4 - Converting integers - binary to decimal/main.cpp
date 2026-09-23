#include <iostream>
#include <bitset>
#include <cstdint>
#include <string>
#include "learncppSolution.hpp"

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

    convert(bits, &refs[0], input);

    std::cout << "Decimal: " << input << '\n'
            << "Binary:  " << bits;
}

int main() {
    mySolution();

    return 0;
}
