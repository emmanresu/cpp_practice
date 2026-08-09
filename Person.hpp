#include <string>
#include <vector>
#include <iostream>
#include "hasher.hpp"

class Person {
private:
    std::string accountNum;
    std::string lName, fName, mName;
    std::vector<std::string> transac;
    std::string pin;
    double bal = 0;
    
public:

    Person(std::string lastName, std::string firstName, std::string midName, std::string pass) : 
            lName(lastName), fName(firstName), mName(midName), pin(pass) {}

    Person() : lName("unknown"), fName("unknown"), mName("unknown") {}

    void deposit(double value) {
        bal += value;
    }
    bool withdraw(double value) {
        if (value <= bal) {
            bal -= value;
            return 1;
        } else {
            return 0;
        }
    }
    bool matchPin(std::string& val) {
        if (hash(val) != pin) {
            return false;
        } else {
            return true;
        }
    }
    void viewTransaction() const {
        for (auto t : transac) {
            std::cout << t << '\n';
        }
    }

    std::string getLName() const {
        return lName;
    }
    std::string getFName() const {
        return fName;
    }
    std::string getMName() const {
        return mName;
    }
    double getBal() const {
        return bal;
    }
};
