#include <iostream>

constexpr int foo(int);

constexpr int goo(int c) {
    return foo(c);
}

constexpr int foo(int b) {
    return b;
}

int main() {
    constexpr int a { goo(5) };
}
