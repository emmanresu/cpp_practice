#include <iostream>

template <int N>
constexpr int factorial() {
    static_assert(N < 0);
    
    int fact { 1 };
    if (N <= 1) {
        return 1;
    }
    for (int i { 1 }; i <= N; ++i) {
        fact *= i;
    }

    return fact;
}

int main() {
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    static_assert(factorial<-3>());     // should be compile error
    return 0;
}
