#include <iostream>
#include <bitset>
#include <cstdint>
#include <string>
#include <array>
#include "learncppSolution.hpp"
#include <chrono>

void convert(std::array<std::uint8_t, 8>& binary, std::uint8_t* refs, int numberInput) {
    for (auto i = binary.begin(); i != binary.end(); ++i) {
        if (numberInput >= *refs) {
            *i = 1;
            numberInput -= *refs;
        }
        ++refs; 
    }
}

void mySolution() {
    std::uint8_t refs[8] { 128, 64, 32, 16, 8, 4, 2, 1 };
    // std::string bits { "0000 0000" };
    std::array<std::uint8_t, 8> bits { 0, 0, 0, 0, 0, 0, 0, 0 };
    
    std::cout << "Enter number from 0 to 255: ";
    int input {};
    std::cin >> input;

    auto start { std::chrono::steady_clock::now() };
    convert(bits, &refs[0], input);
    auto end { std::chrono::steady_clock::now() };
    auto elapsed { std::chrono::duration_cast<std::chrono::nanoseconds>(end - start) };

    std::cout << "Decimal: " << input << '\n'
            << "Binary:  " << static_cast<int>(bits[0]) 
                        << static_cast<int>(bits[1])
                        << static_cast<int>(bits[2])
                        << static_cast<int>(bits [3])
                        << ' '
                        << static_cast<int>(bits[4])
                        << static_cast<int>(bits[5])
                        << static_cast<int>(bits[6])
                        << static_cast<int>(bits[7]) 
                        << '\n';
    std::cout << "time elapsed: " << elapsed.count() << " nanos";
}

int main() {
    mySolution();
     
    // learncppSolution();

    return 0;
}
