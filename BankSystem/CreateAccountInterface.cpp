#include <iostream>
#include "CreateAccount.hpp"

void CreateAccountInterface() {
    std::cout << "--------------------------------------\n"
                << "\tCREATE ACCOUNT\n";
    bool created = CreateAccount();

    if (!created) {
        std::cout << "--------------------------------------\n"
                << "EXITING TO MAIN SCREEN\n";
    } else {
        std::cout << "--------------------------------------\n"
                << "ACCOUNT CREATED SUCCESSFULLY\n";
    }
    
}
