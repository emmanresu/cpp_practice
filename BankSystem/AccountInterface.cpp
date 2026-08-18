#include <iostream>
#include "LoadDatabase.hpp"
#include "Person.hpp"
#include "VerifyAccount.hpp"

void AccountInterface() {
    Database db = LoadDatabase();
    std::cout << "--------------------------------------\n"
                << "\tLOGIN TO ACCOUNT\n";
    Person person = Account(db);

    std::cout << "--------------------------------------\n"
                    << "Welcome " << person.getLName() << ", "
                    << person.getFName() << '\n'
                << "--------------------------------------\n";
    bool active = true;
    while (active) {
        std::cout << "Enter command:\n" << "1 - Deposit cash\n"
                    << "2 - Withdraw cash\n" << "3 - View balance\n"
                    << "4 - Log out\n";
        int command{};
        std::cin >> command;
        switch (command) {
            case 1: {
              break;  
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                std::cout << "--------------------------------------\n"
                            << "LOGGED OUT SUCCESSFULLY\n";
                active = false;
                break;
            }
        }
    }
}
