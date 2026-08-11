#include <iostream>
#include <vector>
#include <utility>
#include <string>

class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(std::move(n)), age(std::move(a)) {}
    Person() {};
    
    std::string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
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
    std::string text{};
    
    std::string firstName = getName("first name", text);
    std::string lastName = getName("last name", text);
    std::string midName =  getName("middle name", text);

    std::cout << firstName << ' ' << lastName << ' ' << midName;

}
