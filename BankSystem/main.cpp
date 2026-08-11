#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include "Person.hpp"
#include "Hasher.hpp"

int main() {
    std::vector<Person> database;
    std::vector<int> commands {1, 2, 3};

    while (true) {
        std::cout << "--------------------------------------\n"
                    << "\tBANK ACCOUNT SYSTEM\n"
                    << "Enter command:\n"
                    << "1 - Enter name and pin\n"
                    << "2 - Create account\n"
                    << "3 - Exit\n"
                    << "--------------------------------------\n"
                    << "Command: ";

        int option{};
        std::cin >> option;
        auto it = find(commands.begin(), commands.end(), option);
        if (it == commands.end()) {
            std::cout << "UNKOWN COMMAND. TRY AGAIN\n\n";
            // std::cin.clear();
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
                    break;
                    
                }
                case 3: {
                    break;
                }

            }
        }
    }
}
