#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include "Person.hpp"
#include "Hasher.hpp"
#include "CreateAccountInterface.hpp"
#include "AccountInterface.hpp"

int main() {
    std::vector<Person> database;
    std::vector<int> commands {1, 2, 3};
    bool systemOnline = true;
    int option{};
    while (systemOnline) {
        std::cout << "--------------------------------------\n"
                    << "\tBANK ACCOUNT SYSTEM\n"
                    << "Enter command:\n"
                    << "1 - Login\n"
                    << "2 - Create account\n"
                    << "3 - Exit\n"
                    << "--------------------------------------\n"
                    << "Command: ";

        std::cin >> option;
        char nextChar = std::cin.peek();
        if (nextChar != '\n') {
            std::cout << "UKNOWN COMMAND. TRY AGAIN\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        auto it = find(commands.begin(), commands.end(), option);
        if (it == commands.end()) {
            std::cout << "UNKNOWN COMMAND. TRY AGAIN\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch (option) {
                case 1: {
                    AccountInterface();
                    break;
                }
                case 2: {
                    CreateAccountInterface();
                    break;
                }
                case 3: {
                    std::cout << "Console terminated.\n";
                    systemOnline = false;
                    break;
                }

            }
        }
    }
}
