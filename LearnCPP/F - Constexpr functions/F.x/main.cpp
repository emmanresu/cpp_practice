#include <iostream>
#include <array>
#include "learncppSolution.hpp"

// we can just pre-calculate the distance fallen at compile time
// values are stored in an array and we just move the pointer forward when (it) does not go to zero
void ballHeight(double gravity, double towerHeight) {
    int seconds { 0 };
    double currentBallHeight { towerHeight };
    while (true) {
        double distanceFallen { (gravity * (seconds * seconds)) / 2.0 };
        currentBallHeight = towerHeight - distanceFallen;

        if (currentBallHeight > 0) {
            std::cout << "At " << seconds << " seconds, the ball is at height: " << currentBallHeight << " meters\n";
            ++seconds;
        } else {
            std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
            break;
        }   
    }
}

// logic can be optimized (exact number of array size should be declared, we have excess allocation)
// pre-calculate the distance traveled of ball using array and consteval
constexpr double maximumHeight { 385'000'000 };
consteval std::array<double, 1000> heightReference(double gravity) {
    std::array<double, 1000> height {};
    int seconds { 0 };
    double currentHeight { maximumHeight };
    for (auto itHeight { height.begin() }; currentHeight > 0; ++itHeight) {
        double distanceFallen { (gravity * (seconds * seconds)) / 2.0 };
        currentHeight -= distanceFallen;

        *itHeight = maximumHeight - currentHeight;
        ++seconds;
    }

    return height;
}

int main() {
    const double towerHeight { getTowerHeight() };
    ballHeight(9.8, towerHeight);

    // learncppSolution();
    
    return 0;
}
