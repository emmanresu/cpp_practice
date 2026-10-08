#include <iostream>
#include "constants.hpp"



int accumulate(int x) {
    static int g_x {};
    return g_x += x;
}

void Q1() {
    std::cout << "Enter a positive number: ";
    int num {};
    std::cin >> num;

    if (num < 0) {                                                         // added block
        std::cout << "Negative number entered. Making positive.\n";
        num = -num;
    }

    std::cout << "You entered: " << num;
}

void Q2() {
    std::cout << "How many students are in your class? ";
    int students {};
    std::cin >> students;

    if (students > Constants::maxClassSize)
        std::cout << "There are too many students in this class.\n";
    else
        std::cout << "The class isn't too large.\n";
}

void Q3() {
    std::cout << accumulate(4) << '\n';     // should print 4
    std::cout << accumulate(3) << '\n';     // should print 7
    std::cout << accumulate(2) << '\n';     // should print 9
    std::cout << accumulate(1) << '\n';     // should print 10
}


int main() {
    Q3();

    return 0;
}
