#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <memory>
#include <fstream>
#include "Person.hpp"
#include "Hasher.hpp"

// class Person {
// private:
//     std::string name;
//     int age;
// public:
//     Person(std::string n, int a) : name(std::move(n)), age(std::move(a)) {}
//     Person() {};
    
//     std::string getName() { return name; }
//     int getAge() { return age; }

//     void setName(std::string val) { name = std::move(val); }
//     void setAge(int val) { age = val; }
// };



// std::string getName(std::string&& name, std::string text) {
    
    // while (true) {
    //     std::cout << "Enter " << name << ": ";
    //     std::getline(std::cin, text);
    //     if (text == " " || text.size() == 0) {
    //         std::cout << name << " must not be empty\n";
    //         continue;
    //     }
    //     break;
    // }
int main() {

    Person emman {"Emman", "olamags", "d", "2332", "332-2332"};
    std::cout << emman.getBal();

    return 0;
}
