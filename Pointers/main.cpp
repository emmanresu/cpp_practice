#include <iostream>

void func() {
    int* ptr = new int(10);

    std::cout << *ptr;
    delete ptr;
}


int main() {
    func();
    return 0;
}
