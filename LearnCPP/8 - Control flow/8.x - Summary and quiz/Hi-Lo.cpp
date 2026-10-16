#include <iostream>
#include <limits>
#include <cstddef>
#include "Random.hpp"


void HiLo() {
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";

    constexpr int min { 1 };
    constexpr int max { 100 };
    const int randomNumber { Random::get(min, max) };
    constexpr int maxTries { 7 };
    int guess {};

    for (int tries { 1 }; tries <= maxTries; ++tries) {
        bool validGuess { false };

        while (!validGuess) {
            std::cout << "Guess #" << tries << ": ";
            std::cin >> guess;
            if (std::cin.fail()) {
                std::cout << "Invalid guess. Enter numbers from 1 - 100 only.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                validGuess = true;
            }
        }

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
    // bool play { true };
    char keepPlaying { 'y' };

    while (keepPlaying == 'y') {
        HiLo();
        bool validInput { false }; 

        while (!validInput) {
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> keepPlaying;
            if (std::cin.fail() || (keepPlaying != 'y' && keepPlaying != 'n')) {
                std::cout << "Invalid input. Enter y (yes) and n (no) only.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                validInput = true;
            }
        }
    }
    std::cout << "Thank you for playing.\n";
}
