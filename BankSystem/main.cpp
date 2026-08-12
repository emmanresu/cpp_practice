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

int main() {
    std::vector<Person> database;
    std::vector<int> commands {1, 2, 3};
    bool systemOnline = true;
    int option{};
    while (systemOnline) {
        std::cout << "--------------------------------------\n"
                    << "\tBANK ACCOUNT SYSTEM\n"
                    << "Enter command:\n"
                    << "1 - Enter name and pin\n"
                    << "2 - Create account\n"
                    << "3 - Exit\n"
                    << "--------------------------------------\n"
                    << "Command: ";

        std::cin >> option;

        auto it = find(commands.begin(), commands.end(), option);
        if (it == commands.end()) {
            std::cout << "UNKNOWN COMMAND. TRY AGAIN\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        } else {
            switch (option) {
                case 1: {
                    std::cout << "last name: ";
                    std::string lName;
                    std::cin >> lName;

                    std::cout << "pin: ";
                    std::string pin;
                    std::cin >> pin;

                    auto it = std::find_if(database.begin(), database.end(), [lName](const Person& p) {
                        return p.getFName() == lName;
                    });

                    if (it != database.end() && it->matchPin(pin)) {
                        std::cout << "Weclome " << it->getLName() << '\n';
                    }
                    break;
                }
                case 2: {
                    CreateAccountInterface();
                    break;
                }
                case 3: {
                    std::cout << "Console terminated.\n";
                    systemOnline = false;
                }

            }
        }
    }
}
