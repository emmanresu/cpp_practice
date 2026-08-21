#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cctype>
#include <algorithm>
#include "CreateAccount.hpp"
#include "Person.hpp"

bool isLettersAndSpaces(const std::string& val) {
    if (val.empty()) {
        return false;
    }
    return std::all_of(val.begin(), val.end(), [](unsigned char c){
        return std::isalpha(c) || std::isspace(c);
    });
}

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string getName(std::string&& nameType) {
    std::string text{};
    while (true) {
        std::cout << "Enter " << nameType << ": ";
        std::getline(std::cin, text);
        if (!isLettersAndSpaces(text) || text == "") {
            std::cout << nameType << " must not be empty. Try again\n";
            continue;
        }
        break;
    }
    return text;
}

std::string createPin() {
    std::string pin{};
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

// account number collision / same account number can occur
std::string createAccNum() {
    std::string num{};
    while (true) {
        std::cout << "Enter account number: ";
        std::cin >> num;
        if (num.size() != 7) {
            std::cout << "Invalid account number. Try again\n";
            continue;
        }
        break;
    }
    return num;
}

void CreateAccount() {
    // this can be improved
    clearInputBuffer();
    std::string firstName = getName("First name");
    std::string lastName = getName("Last name");
    std::string midName = getName("Middle name");
    std::string pin = createPin();
    std::string accountNumber = createAccNum();
    double bal = 0;

    Person person { accountNumber, lastName, firstName, midName, pin, bal };

    // push this to the database

    // std::ios::app ensures append at end 
    // std::ofstream default applies std::ios::trunc which deletes data in the file when opening alongside std::ios::out
    std::ofstream file("database.csv", std::ios::app); 
    if (!file.is_open()) {
        std::cout << "File cannot be accessed.\n";
    } else {
        file << person.getAccNum() << ',' << person.getLName() << ','
                << person.getFName() << ',' << person.getMName() << ','
                << person.getPin() << ','<< person.getBal() << '\n';
    }
    file.close();
}
