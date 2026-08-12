#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>

class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(std::move(n)), age(std::move(a)) {}
    Person() {};
    
    std::string getName() { return name; }
    int getAge() { return age; }

    void setName(std::string val) { name = std::move(val); }
    void setAge(int val) { age = val; }
};



std::string getName(std::string&& name, std::string text) {
    
    while (true) {
        std::cout << "Enter " << name << ": ";
        std::getline(std::cin, text);
        if (text == " " || text.size() == 0) {
            std::cout << name << " must not be empty\n";
            continue;
        }
        break;
    }
    return text;
}


int main() {
    // Person emman;
    // emman.setName("Emman");
    // emman.setAge(23);
    // std::string text{};
    // std::ofstream file("test.csv");

    // if (!file.is_open()) {
    //     std::cerr << "Error. Could not open or create file.\n";
    //     return 1;
    // } else {
    //     file << "name,age\n";

    //     file << emman.getName() << ',' << emman.getAge() << '\n';

    // }
    // std::cout << emman.getName() << ',' << emman.getAge();
    std::ofstream file("test.csv", std::ios::app);
    if (!file.is_open()) {
        std::cout << "file cannot be opened.\n";
    } else {
        file << "helo\n";
    }
    file.close();

    
}
