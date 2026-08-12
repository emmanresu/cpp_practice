#include <iostream>
#include "CreateAccount.hpp"

void CreateAccountInterface() {
    std::cout << "--------------------------------------\n"
                << "\tCREATE ACCOUNT\n";
    CreateAccount();
    std::cout << "--------------------------------------\n"
                << "ACCOUNT CREATED SUCCESSFULLY\n";
}
