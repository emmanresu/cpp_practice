#include <string>
#include <vector>
#include <iostream>
#include "hasher.hpp"

#ifndef PERSON_HPP
#define PERSON_HPP

class Person {
private:
    std::string accountNum;
    std::string lName, fName, mName;
    // std::vector<std::string> transac;
    std::string pin;
    double bal;
    
public:
    // Person(std::string lastName, std::string firstName, std::string midName, 
    //         std::string pass, std::string accNum) : lName(std::move(lastName)), 
    //         fName(std::move(firstName)), mName(std::move(midName)), 
    //         pin(std::move(hash(pass))), accountNum(std::move(accNum)) {}

    Person(std::string an, std::string ln, std::string fn,
            std::string mn, std::string pin, double bal) : accountNum(an), lName(ln),
            fName(fn), mName(mn), pin(hash(pin)), bal(bal) {}

    Person() {}

    bool deposit(double value) {
        if(value < 0) {
            return 0;
        } else {
            bal += value;
            return 1; 
        }
    }
    bool withdraw(double value) {
        if (value <= bal || value < 0) {
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
    std::string getLName() const { return lName; }
    std::string getFName() const { return fName; }
    std::string getMName() const { return mName; }
    std::string getAccNum() const { return accountNum; }
    std::string getPin() const { return pin; }
    double getBal() const { return bal; }
    // void viewTransaction() const {
    //     for (auto t : transac) {
    //         std::cout << t << '\n';
    //     }
    // }
};

#endif
