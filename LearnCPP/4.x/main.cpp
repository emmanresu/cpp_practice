#include <iostream>

void Question2() {
    double x {};
    double y {};
    char operation {};

    std::cout << "Enter a double value: ";
    std::cin >> x;

    std::cout << "Enter a double value: ";
    std::cin >> y;

    std::cout << "Enter +, -, *, or /: ";
    std::cin >> operation;

    switch(operation) {
        case '+': {
            std::cout << x << " + " << y << " = " << x + y;
            break;
        }
        case '-': {
            std::cout << x << " - " << y << " = " << x - y;
            break;
        }
        case '*': {
            std::cout << x << " * " << y << " = " << x * y;
            break;
        }
        case '/': {
            std::cout << x << " / " << y << " = " << x / y;
            break;
        }
    }
}

void Question3() {
    float gravity { 9.8 };
    int height {};

    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> height;

    int seconds {0};
    double distance {};
    while(true) {
        std::cout << "At " << seconds << " seconds, the ball is at height: "
                << height - distance << " meters\n";

        distance = gravity * (++seconds*seconds) / 2;

        if (distance > height) {
            std::cout << "At " << seconds << " seconds, the ball is on the ground.";
            break;
        }
    }
}

int main() {
    Question3();

    return 0;
}
