#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "Person.hpp"


struct Details {
    std::string accountNum;
    std::string lName, fName, mName;
    std::string pin;
    double bal;
};

using Database = std::unordered_map<std::string, Details>;

Database LoadDatabase() {
    Database accountList;

    std::ifstream data("database.csv", std::ifstream::in);
    if (!data.is_open()) {
        throw std::runtime_error("Cannot open file\n");
    }
    std::string accountNum, lName, fName, mName, pin, bal;
    while (std::getline(data, accountNum, ',') &&
            std::getline(data, lName, ',') &&
            std::getline(data, fName, ',') &&
            std::getline(data, mName, ',') &&
            std::getline(data, pin, ',') &&
            std::getline(data, bal, '\n')) {
        const double balance = std::stod(bal);

        accountList[accountNum] = { accountNum, lName, fName, mName, pin, balance };
    }
    return accountList;
}

bool verifyAccNum(std::string& anInput, Database& database) {
    if (database.contains(anInput)) {
        return true;
    } else {
        return false;
    }
}

bool verifyPin(std::string& pinInput, std::string& anInput, Database& database) {
    if (hash(pinInput) == database[anInput].pin) {
        return true;
    } else {
        return false;
    }
}

Person Account() {
    Database db = LoadDatabase();
    std::string acc;
    bool active = true;
    while (active) {
        std::string anInput;
        std::cout << "Enter account number: ";
        std::cin >> anInput;
        bool accNum = verifyAccNum(anInput, db);
        if (!accNum) {
            std::cout << "Account number does not exist.\n";
            continue;
        }

        std::string pinInput;
        std::cout << "Enter pin: ";
        std::cin >> pinInput;
        bool pin = verifyPin(pinInput, anInput, db);
        if (!pin) {
            std::cout << "Incorrect pin. Try again.\n";
            continue;
        }
        acc = anInput;
        std::cout << "Login success.\n";
        active = false;
    }
    Person person { db[acc].accountNum, db[acc].lName, 
                        db[acc].fName, db[acc].mName, 
                        db[acc].pin, db[acc].bal };
    return person;
}
