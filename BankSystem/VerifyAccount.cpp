#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include "Person.hpp"
#include "LoadDatabase.hpp"

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

Person Account(Database& db) {
    // Database db = LoadDatabase();
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
