#include <iostream>
#include <bitset>

namespace control {
    [[maybe_unused]] constexpr int forward      {0};
    [[maybe_unused]] constexpr int backward     {1};
    [[maybe_unused]] constexpr int left         {2};
    [[maybe_unused]] constexpr int right        {3};
}

int main() {
    std::bitset<8> me { 0b0000 };

    std::cout << "All the bits: " << me << '\n';

    bool isActive { true };
    char key {};
    while (isActive) {
        std::cout << "control: ";
        std::cin >> key;

        switch(key) {
            case('w'): {
                me.set(control::forward);
                break;
            }
            case('s'): {
                me.set(control::backward);
                break;
            }
            case('a'): {
                me.set(control::left);
                break;
            }
            case('d'): {
                me.set(control::right);
                break;
            }
        }

        if (me.test(control::forward)) {
            std::cout << "going forward\n";
        } else if (me.test(control::backward)) {
            std::cout << "going backward\n";
        } else if (me.test(control::left)) {
            std::cout << "going left\n";
        } else if (me.test(control::right)) {
            std::cout << "going right\n";
        } else {
            std::cout << "stopped\n";
            isActive = false;
        }

        me.reset();
    }
    // me.set(control::forward);

    // std::cout << me.test(emotion::isHungry) << '\n';

    // std::cout << "All the bits: " << me << '\n';

    return 0;
}
