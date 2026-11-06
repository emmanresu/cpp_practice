#include <iostream>

consteval auto CONSTEVAL(auto value) {
    return value;
}

constexpr int greater(int x, int y) {
    if (std::is_constant_evaluated()) {
        return (x > y ? x : y);
    } else {
        return (x < y ? x : y);
    }
}

// consteval int greater(int x, int y) {
//     return (x > y ? x : y);
// }


// constexpr int greater(int x, int y) {
//     return (x > y ? x : y);
// }

int main() {
    constexpr int g { greater(5, 6) };
    std::cout << g << '\n';

    std::cout << CONSTEVAL(greater(5, 6)) << " is greater\n";

    int x { 5 };
    // std::cout << greater(x, 6) << " is greater\n";

    return 0;
}
