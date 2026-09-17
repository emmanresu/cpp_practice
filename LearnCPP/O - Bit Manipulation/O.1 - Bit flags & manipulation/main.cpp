#include <iostream>
#include <bitset>

int main() {
    [[maybe_unused]] constexpr int isHungry     {0};
    [[maybe_unused]] constexpr int isSad        {1};
    [[maybe_unused]] constexpr int isMad        {2};
    [[maybe_unused]] constexpr int isHappy      {3};
    [[maybe_unused]] constexpr int isLaughing   {4};
    [[maybe_unused]] constexpr int isAsleep     {5};
    [[maybe_unused]] constexpr int isDead       {6};
    [[maybe_unused]] constexpr int isCrying     {7};

    std::bitset<8> me { 0b0000'0101 };
    me.set(isHappy);
    me.flip(isLaughing);
    me.reset(isLaughing);

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(isHappy) << '\n';
    std::cout << "I am laughing: " << me.test(isLaughing) << '\n';

    return 0;
}
