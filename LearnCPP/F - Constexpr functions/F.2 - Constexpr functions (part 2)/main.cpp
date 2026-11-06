#include <iostream>
#include "constexpr_funcs.hpp"

int getValue(int x) {
    return x;
}

// constexpr int foo(int x) {
//     if (x < 0) {
//         return 0;
//     }
//     return getValue(x);
// }

consteval int goo(int c) {
    return c;
}

constexpr int foo(int b) {
    constexpr int b2 { 3 };

    return goo(b2);
}


int main() {
    // int x { foo(5) };
    // constexpr int y { foo(-2) };

    // std::cout << x << '\n';
    // std::cout << y << '\n';

    constexpr int a { 5 };
    std::cout << foo(a) << '\n';
    constexpr int testValue { 10 };
    std::cout << plusTen(testValue);

    return 0;
}
