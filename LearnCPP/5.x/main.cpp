#include <iostream>
#include <cstdint>
#include <string>

void Q1() {
    std::cout << "How old are you?\n";

    std::uint16_t age {};                                   // uint16_t above (uint32_t, int, ...) is preferred
    std::cin >> age;                                        // uint8_t is considered as a char type (ex. input is 12,
                                                            //      only 1 is assigned to age leaving 2 in the buffer)

    std::cout << "Allowed to drive a car in Texas: ";

    if (age >= 16) {                                        // as much as possible, avoid using magic numbers, prefer
        std::cout << "Yes.\n";                              //      constexpr instead
    } else {
        std::cout << "No.\n";
    }
}

std::string_view displayVal(std::string_view val) {
    return val;
}

void Q4() {
    std::cout << "Enter name of person #1: ";
    std::string person1 {};
    std::getline(std::cin >> std::ws, person1);

    uint16_t age1 {};
    std::cout << "Enter age of " << displayVal(person1) << ": ";
    std::cin >> age1;

    std::cout << "Enter name of person #2: ";
    std::string person2 {};
    std::getline(std::cin >> std::ws, person2);

    uint16_t age2 {};
    std::cout << "Enter age of " << displayVal(person2) << ": ";
    std::cin >> age2;

    if (age1 > age2) {
        std::cout << person1 << " (age " << age1 << ") is older than " 
                << person2 << " (age " << age2 << ").\n"; 
    } else {
        std::cout << person2 << " (age " << age2 << ") is older than " 
                << person1 << " (age " << age1 << ").\n";
    }
}

int main() {
    Q1();

    return 0;
}
