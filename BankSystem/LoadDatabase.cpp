#include <unordered_map>
#include <string>
#include <fstream>
#include "Details.hpp"
#include "LoadDatabase.hpp"

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
