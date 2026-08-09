#include <iostream>
#include <vector>
#include <string>
#include "Person.hpp"
#include "hasher.hpp"

int main() {
    std::vector<Person> database;
    while (true) {
        std::cout << "\tBank account system\n";
        std::cout << "Enter command:\n";
        std::cout << "1 - Enter name and pin\n";
        std::cout << "2 - Create account\n";
        std::cout << "3 - Exit\n";

        int option;
        std::cin >> option;
        if (option < 1 && option > 3) {
            std::cout << "unknown command\n\n";
        } else {
            switch (option) {
                case 1: {
                    std::cout << "last name:\t";
                    std::string lName;
                    std::cin >> lName;

                    std::cout << "pin:\t";
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
                    
                }

            }
        }
    }
}
