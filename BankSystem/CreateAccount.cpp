#include <iostream>
#include <string>
#include "CreateAccount.hpp"
#include "Person.hpp"
#include "Hasher.hpp"

void CreateAccount() {
    std::string value{};
    std::string firstName = std::move(getName("First name", value));
    std::string lastName = std::move(getName("Last name", value));
    std::string midName = std::move(getName("Middle name", value));
    std::string pin = std::move(createPin(value));
    std::string accountNumber = std::move(createAccNum(value));

    Person person { firstName, lastName, midName, pin, accountNumber };

    // push this to the database
}

std::string getName(std::string&& nameType, std::string text) {
    while (true) {
        std::cout << "Enter " << nameType << ": ";
        std::getline(std::cin, text);
        if (text == " " || text.size() == 0) {
            std::cout << nameType << " must not be empty. Try again\n";
            continue;
        }
        break;
    }
    return text;
}

std::string createPin(std::string pin) {
    while (true) {
        std::cout << "Enter 4 digit pin: ";
        std::cin >> pin;
        if (pin.size() != 4) {
            std::cout << "Invalid pin. Try again\n";
            continue;
        }
        break;
    }
    return pin;
}

std::string createAccNum(std::string num) {
    while (true) {
        std::cout << "Enter account number: ";
        if (num.size() != 7) {
            std::cout << "Invalid account number. Try again\n";
            continue;
        }
        break;
    }
    return num;
}
