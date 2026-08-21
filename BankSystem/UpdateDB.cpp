#include <string>
#include <fstream>
#include "Details.hpp"
#include "Person.hpp"

// get the account number and pass the address of the db
// rewrite the whole csv file with the changes (expensive approach)
void UpdateDB(Database& db, Person& person) {
    std::ofstream file("database.csv");
    auto it = db.begin();

    while(it != db.end()) {
        if (!file.is_open()) {
                std::cout << "File cannote be accessed.\n";
        } else if (it->second.accountNum == person.getAccNum()) {
            file << person.getAccNum() << ','
                    << person.getLName() << ','
                    << person.getFName() << ','
                    << person.getMName() << ','
                    << person.getPin() << ','
                    << person.getBal() << '\n';
        } else {
            file << it->second.accountNum << ','
                    << it->second.lName << ','
                    << it->second.fName << ','
                    << it->second.mName << ','
                    << it->second.pin << ','
                    << it->second.bal << '\n';
        }
        it++;
    }
    file.close();
}
