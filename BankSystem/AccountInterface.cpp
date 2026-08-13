#include <iostream>

#include "Person.hpp"
#include "VerifyAccount.hpp"

void AccountInterface() {
    std::cout << "--------------------------------------\n"
                << "\tLOGIN TO ACCOUNT\n";
    Person person = Account();

    std::cout << "--------------------------------------\n"
                    << "Welcome " << person.getLName() << ", "
                    << person.getFName() << '\n'
                << "--------------------------------------\n";
    bool active = true;
    while (active) {
        std::cout << "Enter command:\n" << "1 - Deposit cash\n"
                    << "2 - Withdraw cash\n" << "3 - View balance\n"
                    << "4 - Exit\n";
        std::string command;
        std::cin >> command;
    }
}
