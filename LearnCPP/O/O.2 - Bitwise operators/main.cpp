#include <iostream>
#include <bitset>

void example() {
    std::bitset<4> b4{ 0b100 }; // b4 is 0100
    std::bitset<8> b8{ 0b100 }; // b8 is 0000 0100

    std::cout << "Initial values:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << "\n\n";

    b4 = ~b4; // flip b4 to 1011
    b8 = ~b8; // flip b8 to 1111 1011

    std::cout << "After bitwise NOT:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << '\n';
}

//  rotl using test and set
// std::bitset<4> rotl(std::bitset<4> bits) {
//     int leftMost    {3};
//     int rightMost   {0};

//     if (bits.test(leftMost)) {
//         bits <<= 1;
//         return bits.set(rightMost);
//     }
//
//     return bits << 1;
// }

//  rotl using bitwise operators
std::bitset<4> rotl(std::bitset<4> bits) {
    std::bitset<4> copyShifted { bits >> 3 };

    return (bits <<= 1) | copyShifted;          // can just be "return (bits << 1) | (bits >> 3)" [from learncpp solutions]
}

int main() {
    std::bitset<4> bits1 { 0b0001 };    // output: 0010
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2 { 0b1001 };    // output: 0011
    std::cout << rotl(bits2) << '\n';

    return 0;
}
