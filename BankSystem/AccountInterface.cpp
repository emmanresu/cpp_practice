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
        std::cout << "Enter command:\n" 
                    << "1 - Deposit cash\n"
                    << "2 - Withdraw cash\n" 
                    << "3 - View balance\n"
                    << "4 - Log out\n"
                    << "--------------------------------------\n"
                    << "Command: ";
        int command{};
        double amount{};
        std::cin >> command;
        switch (command) {
            case 1: {
                std::cout << "--------------------------------------\n"
                            << "\tDEPOSIT SAVINGS\n"
                            << "Current balance: "
                            << person.getBal() << '\n'
                            << "Deposit amount: ";
                std::cin >> amount;
                if (!person.deposit(amount)) {
                    std::cout << "Invalid amount.";
                } else {
                    // person.deposit(amount);
                    std::cout << "\n--------------------------------------\n"
                                "DEPOSIT SUCCESS.\n"
                                << "Current balance: "
                                << person.getBal();          
                }
                std::cout << "\n--------------------------------------\n";
                break;  
            }
            case 2: {
                std::cout << "--------------------------------------\n"
                            << "\tWITHDRAW SAVINGS\n"
                            << "Current balance: "
                            << person.getBal()
                            << '\n'
                            << "Withdraw amount: ";
                std::cin >> amount;
                if (!person.withdraw(amount)) {
                    std::cout << "Invalid amount.";
                } else {
                    std::cout << "--------------------------------------\n"
                                << "WITHDRAW SUCCESS.\n"
                                << "Current balance: "
                                << person.getBal();
                }
                std::cout << "\n--------------------------------------\n";
                break;
            }
            case 3: {
                std::cout << "--------------------------------------\n"
                            << "Current balance: " << person.getBal()
                            << "\n--------------------------------------\n";
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
