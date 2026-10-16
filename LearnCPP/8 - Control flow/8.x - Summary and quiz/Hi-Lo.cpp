#include <iostream>
#include "Random.hpp"
#include <cstddef>

void HiLo() {
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

    int randomNumber { Random::get(1, 100) };
    int guess {};

    for (int tries { 1 }; tries <= 7; ++tries) {
        std::cout << "Guess #" << tries << ": ";
        std::cin >> guess;

        if (guess == randomNumber) {
            std::cout << "Correct! You win!\n";
            return;
        } else if (guess > randomNumber) {
            std::cout << "Your guess is too high.\n";
        } else {
            std::cout << "Your guess it too low.\n";
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << randomNumber << ".\n";
}

void Q3() {
    char play { 'y' };

    while (play == 'y') {
        HiLo();
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> play;
    }
    
}
