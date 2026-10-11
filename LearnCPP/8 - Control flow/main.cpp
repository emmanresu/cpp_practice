#include <iostream>

void Q1() {
    for (int i {1}; i <= 20; ++i) {
        std::cout << i << '\n';
    }
}

int sumTo(int number) {
    int sum {};
    for (int i {1}; i <= number; ++i) {
        sum += i;
    }

    return sum;
}

void Q2() {
    std::cout << "enter sum up to: ";
    int input {};
    std::cin >> input;

    std::cout << sumTo(input) << '\n';
}

void fizzBuzz(int number) {
    for (int i {1}; i <= number; ++i) {
        if (i % 3 == 0) {
            std::cout << "fizz";
        }
        if (i % 5 == 0) {
            std::cout << "buzz";
        }
        if (i % 7 == 0) {
            std::cout << "pop";
        }
        if ((i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0)) {
            std::cout << i;
        }
        std::cout << '\n';
    }
}

void Q3() {
    std::cout << "enter a number: ";
    int input {};
    std::cin >> input;

    fizzBuzz(input);
}

int main() {
    Q3();

    return 0;
}
