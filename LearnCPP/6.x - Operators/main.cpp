#include <iostream>
#include <string_view>

std::string_view getQuantityPhrase(int val) {
    if (val < 0) {
        return "negative";
    } else if (val == 0) {
        return "no";
    } else if (val == 1) {
        return "a single";
    } else if (val == 2) {
        return "a couple";
    } else if (val == 3) {
        return "a few";
    } else {
        return "many";
    }
}

std::string_view getApplesPluralized(int val) {
    return (val > 1) ? "apples" : "apple";
}

int main() {
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' '
            << getApplesPluralized(maryApples) << ".\n";
    std::cout << "How many apples do you have: ";
    int numApples {};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' '
            << getApplesPluralized(numApples) << ".\n";

    return 0;
}
